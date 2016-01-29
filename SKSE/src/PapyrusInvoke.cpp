#include "SKSE/PapyrusInvoke.h"
#include <Skyrim/BSSystem/BSTSmartPointer.h>

namespace SKSEScript
{
	static BSScript::IFunction* GetFunction(VMState* state, BSScript::BSScriptClass *klass, const char* fnName)
	{
		BSScript::IFunction* result = nullptr;
		BSScript::BSScriptClass* p = klass;
		while (p)
		{
			BSScript::IFunction **func;
			func = p->GetMemberFunction(fnName);
			if (func && *func)
			{
				result = *func;
				break;
			}

			p = p->GetParent();
		}

		return result;
	}

	BSScript::IFunction* GetFunction(VMState* state, UInt32 typeID, const char* fnName)
	{
		BSTSmartPointer<BSScript::BSScriptClass> classInfo;
		if (!state->GetScriptClassByTypeID(typeID, classInfo))
			return nullptr;

		return GetFunction(state, classInfo, fnName);
	}


	BSScript::IFunction* GetFunction(VMState* state, const BSFixedString &className, const BSFixedString &fnName)
	{
		BSTSmartPointer<BSScript::BSScriptClass> classInfo;
		if (!state->GetScriptClassByName(className, classInfo))
			return nullptr;

		return GetFunction(state, classInfo, fnName);
	}
}

