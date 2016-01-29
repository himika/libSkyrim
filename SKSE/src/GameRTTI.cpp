#include "SKSE/GameRTTI.h"
#include "SKSE/DebugLog.h"
#include <excpt.h>
#include <sstream>
#include <iomanip>
#include <vector>

namespace {
	struct TypeHierarchy
	{
		struct Node
		{
			TYPE_INFO	* type;
			UInt32		depth;
			UInt32		offset;
		};

		UInt32		* memPtr;
		UInt32		unk04;
		UInt32		length;
		Node		** nodes;
	};

	struct RTTILocator
	{
		UInt32			sig;
		UInt32			offset;
		UInt32			cdOffset;
		TYPE_INFO		* type;
		TypeHierarchy	* hierarchy;
	};
}


const TYPE_INFO* GetObjectTypeInfo(const void * objBase)
{
	const TYPE_INFO* result = nullptr;
	__try
	{
		void		** obj = (void **)objBase;
		RTTILocator	** vtbl = (RTTILocator **)obj[0];
		RTTILocator	* rtti = vtbl[-1];

		if (*(UInt32 *)rtti->type == 0x0118E204)	// type_info vtable
			result = rtti->type;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		// return the default
	}

	return result;
}


const char * GetObjectClassName(const void * objBase)
{
	const TYPE_INFO* type = GetObjectTypeInfo(objBase);
	if (type)
		return type->name();
	else
		return "<no rtti>";
}


static bool GetTypeHierarchyInfo(const void * objBase, const char *& name, UInt32 & offset, TypeHierarchy *& hierarchy)
{
	bool success = false;

	__try
	{
		void		** obj = (void **)objBase;
		RTTILocator	** vtbl = (RTTILocator **)obj[0];
		RTTILocator	* rtti = vtbl[-1];

		if (*(UInt32 *)rtti->type == 0x0118E204)	// type_info vtable
		{
			name = rtti->type->name();
			offset = rtti->offset;
			hierarchy = rtti->hierarchy;

			success = true;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		// return the default
	}

	return success;
}

void DumpObjectClassHierarchy(const void * objBase, bool verbose)
{
	std::stringstream ss;

	const char *name;
	UInt32 offset;
	TypeHierarchy *hierarchy;
	if (!GetTypeHierarchyInfo(objBase, name, offset, hierarchy)) {
		gLog << "<no rtti>" << std::endl;
		gLog.flush();
		return;
	}

	//_MESSAGE("%s +%04X (_vtbl=%08X)", name, offset, *(UInt32*)objBase);
	ss << name;
	ss << " +" << std::hex << std::setfill('0') << std::uppercase << std::setw(4) << std::right << offset;
	ss << " (_vtbl=" << std::setw(8) << *(UInt32*)objBase << ')';
	ss << std::endl;

	std::vector<int> depth(hierarchy->length, 0);

	for (int i = 0; i < hierarchy->length; i++)
	{
		TypeHierarchy::Node * node = hierarchy->nodes[i];

		//_MESSAGE("%04X: ", node->offset);
		ss << std::setw(4) << node->offset << ": ";
		
		// indents
		depth[i] = node->depth + 1;
		for (std::size_t n = 0; n < depth.size(); n++) {
			if (depth[n] > 0) {
				if (n > 0)
					ss << "|   ";
				depth[n]--;
			}
		}

		ss << node->type->name();
		if (verbose) {
			//_MESSAGE(" ... %p", node->type->name(), node->type);
			ss << " ... " << std::setw(8) << (UInt32)node->type;
		}
		ss << std::endl;
	}

	gLog << ss.str();
	gLog.flush();
}
