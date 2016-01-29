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
		typedef BSTSmartPointer<BSScriptClass> SmartPtr;

		BSScriptClass()		{ }
		~BSScriptClass()	{ dtor(); }

		union FlagData
		{
			const char	* name;
			bool		value;
		};

		struct VariableData
		{
			const char	* name;
			UInt32		index;
		};

		struct Unk0CData
		{
			UInt32		unk00;
			UInt32		unk04;
			UInt32		unk0C;
		};

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
		
		const BSFixedString & GetName() const {
			return name;
		}

		UInt32 GetNumVariables() const
		{
			return nums.numVariables;
		}

		UInt32 GetNumMemberFunctions() const
		{
			return nums.numMemberFuncs;
		}

		UInt32 GetNumGlobalFunctions() const
		{
			return nums.numGlobalFuncs;
		}

		IFunction ** GetFunctions() const
		{
			return (IFunction**)(dataPtr
				+ sizeof(FlagData) * nums.numScriptFlags
				+ sizeof(VariableData) * nums.numVariables
				+ sizeof(Unk0CData) * nums.numUnk0C
				+ sizeof(Unk28Data) * nums.numUnk28);
		}

		VariableData* GetVariables() const
		{
			return (VariableData*)(dataPtr + sizeof(FlagData) * nums.numScriptFlags);
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
			return reinterpret_cast<VMTypeID>(this);
		}

		bool IsBaseOf(const BSScriptClass* a_class) const;
		BSScriptClass* GetParent(void) const {
			return parent;
		}

		DEFINE_MEMBER_FN_const(GetVariableIndex, SInt32, 0x00C33E30, const BSFixedString & name);
		DEFINE_MEMBER_FN_const(GetFunction, BSScript::IFunction*, 0x00C36540, const char * fnName);
		DEFINE_MEMBER_FN_const(GetMemberFunction, BSScript::IFunction**, 0x00C365A0, const char * fnName);
		DEFINE_MEMBER_FN_const(GetScriptFlag, bool, 0x00C33890, const BSFixedString & name, bool arg2);

	//protected:
		// @members
		BSFixedString	name;		// 04
		BSScriptClass	* parent;	// 08
		void			* unk0C;	// 0C

		struct {
			unsigned 	flag			: 2;	// 00
			unsigned	numScriptFlags	: 6;	// 02
			unsigned	numVariables	: 10;	// 08
			unsigned	numPad0_18		: 14;	// 18

			unsigned	numUnk0C		: 10;	// 00
			unsigned	numUnk28		: 10;	// 10
			unsigned	numGlobalFuncs	: 9;	// 20
			unsigned	numPad1_29		: 3;	// 29

			unsigned	numMemberFuncs	: 9;	// 00
		} nums;

		UInt32			dataPtr;	// 1C

	private:
		DEFINE_MEMBER_FN(dtor, void, 0x00C34ED0);
	};
	STATIC_ASSERT(sizeof(BSScriptClass) == 0x20);
}
