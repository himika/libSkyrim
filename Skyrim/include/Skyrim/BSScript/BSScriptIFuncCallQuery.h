#pragma once

#include "../BSSystem/BSTSmartPointer.h"
#include "../BSCore/BSTArray.h"
#include "BSScriptClass.h"
#include "BSScriptVariable.h"

namespace BSScript
{
	BSSmartPointer(IFuncCallQuery);

	// 28
	class IFuncCallQuery : public BSIntrusiveRefCounted
	{
	public:
		virtual ~IFuncCallQuery();	// 00C57D10
	
		virtual bool Set(UInt32 arg1, BSScriptClassPtr &classPtr, const BSFixedString &fnName, BSScriptVariable &baseValue, BSScrapArray<BSScriptVariable> &args);	// 00C57C70
	
		// @members
		//void						** _vtbl	// 00 - 0114AB9C
		UInt32						unk08;		// 08 - init'd arg1 - always 0 ?
		BSScriptClassPtr			classPtr;	// 0C
		BSFixedString				funcName;	// 10
		BSScriptVariable			baseValue;	// 14
		BSTArray<BSScriptVariable>	args;		// 1C
	
	private:
		DEFINE_MEMBER_FN(ctor, IFuncCallQuery *, 0x00C57BB0, UInt32 arg1, BSScriptClassPtr &classPtr, const BSFixedString &fnName, BSScriptVariable &baseValue, BSScrapArray<BSScriptVariable> &args);
	};
}
