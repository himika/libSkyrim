#include <SKSE.h>
#include <SKSE/PluginAPI.h>
#include <SKSE/DebugLog.h>
#include <SKSE/GameRTTI.h>

#include <iomanip>
#include <string>
#include <list>
#include <map>


const UInt32 data_begin = 0x0123B000;
const UInt32 data_end = data_begin + 0x00987000;

const UInt32 rdata_begin = 0x0106B000;
const UInt32 rdata_end = rdata_begin + 0x001D0000;

const UInt32 text_begin = 0x00401000;
const UInt32 text_end = text_begin + 0x00C6A000;


struct TypeHierarchy
{
	struct Node
	{
		TYPE_INFO	* type;
		UInt32		depth;
		UInt32		offset;
	};

	UInt32		* memPtr;	// 00
	UInt32		unk04;		// 04
	UInt32		length;		// 08
	Node		** nodes;	// 0C
};

struct RTTILocator
{
	UInt32			sig;			// 00
	UInt32			offset;			// 04
	UInt32			cdOffset;		// 08
	TYPE_INFO		* type;			// 0C
	TypeHierarchy	* hierarchy;	// 00
};


typedef std::list<UInt32*> VtblList;

static std::map<UInt32, VtblList> vtblMap;	// type_info address, vtblList


class dump_rtti_plugin : public SKSEPlugin
{
public:
	dump_rtti_plugin()
	{
	}

	virtual bool InitInstance()
	{
		SetName("dump_rtti");
		SetVersion(1);

		if (!Requires(kSKSEVersion_1_7_0))
		{
			gLog << "ERROR: your skse version is too old" << std::endl;
			return false;
		}

		return true;
	}

	virtual bool OnLoad()
	{
		const UInt32 type_info_vtbl = 0x0118E204;

		// search vtables
		for (UInt32 i = data_begin; i < data_end; i += sizeof(UInt32)) {
			UInt32 *p = reinterpret_cast<UInt32*>(i);
			if (*p == type_info_vtbl) {
				SearchVTable(i);
			}
		}

		// print
		for (auto &n : vtblMap)
		{
			UInt32 type_addr = n.first;
			VtblList &vtbl = n.second;

			PrintVirtuals(vtbl);
			gLog << std::endl;
		}

		return true;
	}

private:
	static void SearchVTable(UInt32 typeinfo_addr)
	{
		UInt32* vtbl = nullptr;
		const RTTILocator *rtti;

		// type_infoを参照するRTTILocatorを探す
		for (UInt32 i = rdata_begin; i < rdata_end; i += sizeof(UInt32)) {
			UInt32 *p = reinterpret_cast<UInt32*>(i);

			if (*p == typeinfo_addr) {
				rtti = reinterpret_cast<RTTILocator*>(i - 0x0C);

				if (rtti->sig != 0) continue;
				//if (rtti->offset != 0) continue;
				if (rtti->cdOffset != 0) continue;

				// RTTILocatorを発見したので、RTTILocatorを参照するvtblを探す
				UInt32 loc = reinterpret_cast<UInt32>(rtti);
				for (UInt32 i = rdata_begin; i < rdata_end; i += sizeof(UInt32)) {
					UInt32 *p = reinterpret_cast<UInt32*>(i);

					if (*p == loc) {
						// vtblっぽいものを発見したので、ちゃんと仮想関数を指しているか調べる
						vtbl = reinterpret_cast<UInt32*>(p + 1);
						if (text_begin <= vtbl[0] && vtbl[0] < text_end) {
							// ちゃんとvtblだったので処理
							UInt32 addr = (UInt32)rtti->type;
							if (rtti->offset == 0) {
								vtblMap[addr].push_front(vtbl);
							}
							else {
								vtblMap[addr].push_back(vtbl);
							}
						}
					}
				}
			}
		}

		return;
	}

	static void PrintVirtuals(VtblList &vtblList)
	{
		_MESSAGE("/*==============================================================================");
		DumpObjectClassHierarchy(&vtblList.front());
		_MESSAGE("==============================================================================*/");

		for (auto vtbl : vtblList) {
			bool bOverride = false;
			bool bAdd = false;

			UInt32* vtparent = GetParentVtbl(vtbl);

			for (int i = 0; text_begin <= vtbl[i] && vtbl[i] < text_end; i++) {
				if (vtparent)
				{
					if (text_begin <= vtparent[i] && vtparent[i] < text_end)
					{
						if (vtbl[i] == vtparent[i])
							continue;
					}
					else
					{
						vtparent = nullptr;
					}
				}

				char buf[32];
				sprintf_s(buf, "Unk_%03X", i);
				std::string name = buf;

				sprintf_s(buf, "%08X", vtbl[i]);
				std::string offset = buf;

				std::string ret = "????  ";
				std::string params = "????";
				std::string body;

				if (vtbl[i] == 0x00F51EE8)
					body = "(pure)";
				else
					CheckCode(vtbl[i], ret, params, body);

				if (vtparent && !bOverride) {
					bOverride = true;
					gLog << "    // @override " << GetObjectClassName(&vtparent);
					gLog << " : (vtbl=" << std::hex << std::setfill('0') << std::uppercase << std::setw(8) << (UInt32)vtbl << ')' << std::endl;
				}
				if (!vtparent && !bAdd) {
					bAdd = true;
					if (i > 0)
						gLog << "    // @add" << std::endl;
				}

				int numPad = 40;
				numPad -= params.length();
				gLog << "    virtual " << ret << ' ' << name << '(' << params << ')';
				if (vtparent) {
					numPad -= 9;
					gLog << " override";
				}
				gLog << ';';

				if (numPad < 4)
					numPad = 4;
				for (int i = numPad; i > 0; --i)
					gLog << ' ';


				gLog << "// " << offset;
				if (!body.empty()) {
					gLog << ' ' << body;
				}


				gLog << std::endl;
			}
		}
	}

	static void CheckCode(UInt32 addr, std::string &retOut, std::string &paramsOut, std::string &bodyOut)
	{
		std::size_t size = 0;
		UInt8 *code = (UInt8 *)addr;

		std::string ret = "????  ";
		std::string body;

		if (code[0] == 0x32 && code[1] == 0xC0)			// xor al, al
		{
			ret = "bool  ";
			body = "{ return false; }";
			size = 2;
		}
		else if (code[0] == 0xB0)						// mov al, imm
		{
			if (code[1] == 0x00)
			{
				ret = "bool  ";
				body = "{ return false; }";
			}
			else if (code[1] == 0x01)
			{
				ret = "bool  ";
				body = "{ return true; }";
			}
			else {
				char buf[32];
				sprintf_s(buf, "{ return 0x%02X; }", code[1]);
				ret = "UInt8 ";
				body = buf;
			}
			size = 2;
		}
		else if (code[0] == 0x33 && code[1] == 0xC0)	// xor eax, eax
		{
			ret = "UInt32";
			body = "{ return 0; }";
			size = 2;
		}
		else if (code[0] == 0x83 && code[1] == 0xC8 && code[2] == 0xFF)	// or al, ???
		{
			ret = "Sint32";
			body = "{ return -1; }";
			size = 3;
		}
		else if (code[0] == 0x8A)						// mov al, ???
		{
			if (code[1] == 0x41)						// mov al, [ecx+imm8]
			{
				char buf[48];
				sprintf_s(buf, "{ return (UInt8)unk%X; }", (SInt8)code[2]);
				ret = "UInt8 ";
				body = buf;
				size = 3;
			}
			else if (code[1] == 0x81)					// mov al, [ecx+imm32]
			{
				char buf[48];
				sprintf_s(buf, "{ return (UInt8)unk%X; }", *(SInt32*)&code[2]);
				ret = "UInt8 ";
				body = buf;
				size = 6;
			}
		}
		else if (code[0] == 0x8B)						// mov eax, ???
		{
			if (code[1] == 0xC1)						// mov eax. ecx
			{
				ret = "void *";
				body = "{ return this; }";
				size = 2;
			}
			else if (code[1] == 0x41)					// mov eax, [ecx+imm8]
			{
				char buf[48];
				sprintf_s(buf, "{ return (UInt32)unk%X; }", (SInt8)code[2]);
				ret = "UInt32";
				body = buf;
				size = 3;
			}
			else if (code[1] == 0x81)					// mov eax, [ecx+imm32]
			{
				char buf[48];
				sprintf_s(buf, "{ return (UInt32)unk%X; }", *(SInt32*)&code[2]);
				ret = "UInt32";
				body = buf;
				size = 6;
			}
		}
		else if (code[0] == 0x8D)						// lea eax, ???
		{
			if (code[1] == 0x41)						// lea, [ecx+imm8]
			{
				char buf[32];
				sprintf_s(buf, "{ return &unk%X; }", (SInt8)code[2]);
				ret = "void *";
				body = buf;
				size = 3;
			}
			else if (code[1] == 0x81)					// lea eax, [ecx+imm32]
			{
				char buf[32];
				sprintf_s(buf, "{ return &unk%X; }", *(SInt32*)&code[2]);
				ret = "void *";
				body = buf;
				size = 6;
			}
		}
		else if (code[0] == 0xB8)						// mov eax, imm
		{
			void *p = *(void **)&code[1];
			char buf[32];

			const TYPE_INFO* type = GetObjectTypeInfo(p);
			if (type)
			{
				ret = type->name();
				ret += " *";
				body.reserve(ret.length() + 32);
				body = "{ return (";
				body += ret;
				body += ')';
				sprintf_s(buf, "0x%p; }", p);
				body += buf;
			}
			else
			{
				sprintf_s(buf, "{ return 0x%p; }", p);
				ret = "UInt32";
				body = buf;
			}
			size = 5;
		}
		else if (code[0] == 0xD9 && code[1] == 0xEE)
		{
			ret = "float ";
			body = "{ return 0.0f; }";
			size = 2;
		}

		if (size > 0)
			code += size;

		std::string params;
		if (code[0] == 0xC3)			// retn
		{
			params = "void";
		}
		else if (code[0] == 0xC2)		// retn imm
		{
			UInt16 imm = *(UInt16 *)&code[1];
			switch (imm)
			{
			case 4:
				params = "UInt32 arg";
				break;
			case 8:
				params = "UInt32 arg1, UInt32 arg2";
				break;
			case 12:
				params = "UInt32 arg1, UInt32 arg2, UInt32 arg3";
				break;
			case 16:
				params = "UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4";
				break;
			default:
				{
					char buf[32];
					sprintf_s(buf, "UInt32 * %d", imm / 4);
					params = buf;
				}
				break;
			}

		}
		else
			return;

		if (size == 0)
		{
			ret = "void  ";
			body = "{ return; }";
		}

		retOut = ret;
		paramsOut = params;
		bodyOut = body;

		//gLog << ' ' << params << ' ' << body;

	}

	static UInt32* GetParentVtbl(UInt32* vtbl)
	{
		RTTILocator* rtti = *(RTTILocator**)(vtbl - 1);

		if (rtti->hierarchy)
		{
			TypeHierarchy* hierarchy = rtti->hierarchy;
			for (UInt32 i = 1; i < hierarchy->length; i++)
			{
				auto node = hierarchy->nodes[i];
				if (node->offset == rtti->offset)
				{
					auto it = vtblMap.find((UInt32)node->type);
					if (it != vtblMap.cend())
						return it->second.front();
				}
			}
		}

		return nullptr;
	}
} thePlugin;
