#include "Skyrim.h"
#include "Skyrim/BSScript/BSScriptClass.h"
#include "Skyrim/BSScript/BSScriptIFunction.h"
#include <string.h>

namespace BSScript
{
	bool BSScriptClass::IsBaseOf(const BSScriptClass* a_cass) const
	{
		const BSScriptClass* p = a_cass;
		while (p)
		{
			if (p == this)
				break;
			p = p->GetParent();
		}

		return (p != nullptr);
	}

	IFunction* BSScriptClass::FindFunction(const char * name)
	{
		IFunction ** funcs = GetFunctions();

		const UInt32 num = GetNumGlobalFunctions() + GetNumMemberFunctions();
		for (UInt32 i = 0; i < num; i++)
		{
			IFunction * p = funcs[i];
			if (p)
			{
				const BSFixedString &funcName = p->GetName();
				if (_stricmp(funcName.c_str(), name) == 0)
				{
					return p;
				}

			}
		}

		return nullptr;
	}

	bool BSScriptClass::IsHidden()
	{
		static BSFixedString hidden = "hidden";
		return GetScriptFlag(hidden, true);
	}

	bool BSScriptClass::IsConditional()
	{
		static BSFixedString conditional = "conditional";
		return GetScriptFlag(conditional, true);
	}
}
