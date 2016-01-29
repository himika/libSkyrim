#include <SKSE.h>
#include <SKSE/PluginAPI.h>
#include <SKSE/DebugLog.h>
#include <SKSE/SafeWrite.h>
#include <SKSE/GameRTTI.h>
#include <Skyrim/BSScript/BSScriptNativeFunctions.h>

using BSScript::BSScriptClass;
using BSScript::IFunction;


class VMStateEx
{
public:
	typedef void (VMStateEx::*FnRegisterFunction)(BSScript::IFunction* fn);

	static FnRegisterFunction fnRegisterFunction;

	void RegisterFunction(BSScript::IFunction* fn)
	{
		UInt32 callback = *(UInt32*)((UInt32)fn + 0x2C);
		_MESSAGE("<%s> %s (%08X) callback=%08X", fn->GetScriptName().c_str(), fn->ToString().c_str(), fn, callback);
		DumpObjectClassHierarchy(fn);
		gLog << std::endl;

		(this->*fnRegisterFunction)(fn);
	}

	static void InstallHook()
	{
		fnRegisterFunction = SafeWrite32(0x0114C20C, &VMStateEx::RegisterFunction);
	}
};

VMStateEx::FnRegisterFunction VMStateEx::fnRegisterFunction;


class dump_functions_plugin : public SKSEPlugin
{
public:
	dump_functions_plugin()
	{
	}

	virtual bool InitInstance()
	{
		SetName("dump_functions");
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
		VMStateEx::InstallHook();
		return true;
	}
} thePlugin;
