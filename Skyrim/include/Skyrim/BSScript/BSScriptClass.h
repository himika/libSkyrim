#pragma once

// c:_skyrim\code\tesv\bsscript\BSScriptClass.h

#include "../BSCore/BSFixedString.h"
#include "../BSSystem/BSTSmartPointer.h"
#include "BSScript.h"

#include <functional>

namespace BSScript
{
	BSSmartPointer(BSScriptClass);

	// BSScriptObjectTypeInfo?
	// the same type as VMClassInfo in skse
	// 20
	class BSScriptClass : public BSIntrusiveRefCounted
	{
	public:
		BSScriptClass()		{ }
		~BSScriptClass()	{ dtor(); }

		// 04
		union FlagData
		{
			const char	* name;
			bool		value;
		};

		// 08
		struct VariableData
		{
			const char	* name;
			UInt32		index;
		};

		// 0C
		struct Unk0CData
		{
			UInt32		unk00;
			UInt32		unk04;
			UInt32		unk08;
		};

		// 28
		struct Unk28Data
		{
			UInt32		unk00;
			UInt32		unk04;
			UInt32		unk08;
			UInt32		unk0C;
			UInt32		unk10;
			UInt32		unk14;
			UInt32		unk18;
			UInt32		unk1C;
			UInt32		unk20;
			UInt32		unk24;
		};
		
		const char * GetName() const {
			return name;
		}

		UInt32 GetNumVariables() const
		{
			return numVariables;
		}

		UInt32 GetNumMemberFunctions() const
		{
			return numMemberFuncs;
		}

		UInt32 GetNumGlobalFunctions() const
		{
			return numGlobalFuncs;
		}

		IFunction ** GetFunctions() const
		{
			return (IFunction**)(dataPtr
				+ sizeof(FlagData) * numScriptFlags
				+ sizeof(VariableData) * numVariables
				+ sizeof(Unk0CData) * numUnk0C
				+ sizeof(Unk28Data) * numUnk28);
		}

		VariableData* GetVariables() const
		{
			return (VariableData*)(dataPtr + sizeof(FlagData) * numScriptFlags);
		}

		IFunction* FindFunction(const char * name);

		IFunction* FindFunction(std::function<bool(IFunction *)> pred)
		{
			IFunction ** funcs = GetFunctions();

			const std::size_t num = GetNumGlobalFunctions() + GetNumMemberFunctions();
			for (std::size_t i = 0; i < num; i++)
			{
				IFunction * p = funcs[i];
				if (p && pred(p))
					return p;
			}

			return nullptr;
		}

		bool IsHidden();
		bool IsConditional();

		VMTypeID GetTypeID(void) const {
			return (this) ? reinterpret_cast<VMTypeID>(this) : 1;
		}

		bool IsBaseOf(const BSScriptClass* a_class) const;
		BSScriptClass* GetParent(void) const {
			return parent;
		}

		DEFINE_MEMBER_FN_const(	GetNumAllVariables,	UInt32,			0x00C335F0);	// traverse parent class
		DEFINE_MEMBER_FN_const(	GetScriptFlag,		bool,			0x00C33890,	const BSFixedString & name, bool arg2);
		DEFINE_MEMBER_FN_const(	GetVariableIndex,	SInt32,			0x00C33E30,	const BSFixedString & name);
		DEFINE_MEMBER_FN_const(	GetFunctions,		IFunction *,	0x00C36540,	const char * fnName);
		DEFINE_MEMBER_FN_const(	GetMemberFunctions,	IFunction **,	0x00C365A0,	const char * fnName);

	//protected:
		// @members
		const char		* name;					// 04 - always refers to a BSFixedString but is not, because of no destruction in dtor.
		BSScriptClass	* parent;				// 08
		BSFixedString	unk0C;					// 0C

		unsigned int 	flags			: 2;	// 10 - bit 0
		unsigned int	numScriptFlags	: 6;	// 10 - bit 2
		unsigned int	numVariables	: 10;	// 10 - bit 8
		unsigned int					: 14;	// 10 - bit 12

		unsigned int	numUnk0C		: 10;	// 14 - bit 0
		unsigned int	numUnk28		: 10;	// 14 - bit A
		unsigned int	numGlobalFuncs	: 9;	// 14 - bit 14
		unsigned int					: 3;	// 14 - bit 1D

		unsigned int	numMemberFuncs	: 9;	// 18 - bit 0

		UInt32			dataPtr;				// 1C

	private:
		DEFINE_MEMBER_FN(dtor, void, 0x00C34ED0);

		DEFINE_MEMBER_FN(FreeData, void, 0x00C348E0, bool); // called in dtor
	};
	STATIC_ASSERT(sizeof(BSScriptClass) == 0x20);
	STATIC_ASSERT(offsetof(BSScriptClass, dataPtr) == 0x1C);
}
