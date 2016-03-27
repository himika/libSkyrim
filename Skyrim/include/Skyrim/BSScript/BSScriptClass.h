#pragma once

// c:_skyrim\code\tesv\bsscript\BSScriptClass.h

#include "../BSCore/BSFixedString.h"
#include "../BSSystem/BSTSmartPointer.h"
#include "BSScript.h"

#include <functional>

namespace BSScript
{
	BSSmartPointer(BSScriptClass);

	class IFunction;

	// BSScriptObjectTypeInfo?
	// the same type as VMClassInfo in skse
	// 20
	class BSScriptClass : public BSIntrusiveRefCounted
	{
	public:
		enum Flags
		{
			kFlag_Missing = 2
		};

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
		struct DefaultValueData
		{
			UInt32		index;		// 00
			UInt32		unk04;		// 04 | BSScriptVariable
			UInt32		unk08;		// 08 |
		};

		// 28
		struct PropertyData
		{
			enum
			{
				kFlag_HasSetter = 1,
				kFlag_HasGetter = 2
			};

			BSFixedString	name;				// 00
			BSFixedString	ownerClassName;		// 04
			BSFixedString	name2;				// 08
			VMTypeID		typeID;				// 0C
			UInt32			flags;				// 10
			IFunction		* getter;			// 14
			IFunction		* setter;			// 18
			SInt32			varIndex;			// 1C - setted -1 if this property has setter/getter method.
			bool			isHidden;			// 20
			void			* unk24;			// 24
		};
		
		BSScriptClass() { }
		~BSScriptClass() { dtor(); }

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
			return (IFunction **)(dataPtr
				+ sizeof(FlagData) * numScriptFlags
				+ sizeof(VariableData) * numVariables
				+ sizeof(DefaultValueData) * numDefaultValues
				+ sizeof(PropertyData) * numProperties);
		}

		VariableData * GetVariables() const
		{
			return (VariableData*)(dataPtr + sizeof(FlagData) * numScriptFlags);
		}

		DefaultValueData * GetDefaultValues() const
		{
			return (DefaultValueData *)(dataPtr
				+ sizeof(FlagData) * numScriptFlags
				+ sizeof(VariableData) * numVariables);
		}

		PropertyData * GetProperties() const
		{
			return (PropertyData *)(dataPtr
				+ sizeof(FlagData) * numScriptFlags
				+ sizeof(VariableData) * numVariables
				+ sizeof(DefaultValueData) * numDefaultValues);
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
		DEFINE_MEMBER_FN_const(	GetScriptFlag,		bool,			0x00C33890,	const BSFixedString &name, bool arg2);
		DEFINE_MEMBER_FN_const(	GetVariableIndex,	SInt32,			0x00C33E30,	const BSFixedString &name);
		DEFINE_MEMBER_FN_const(	GetFunctions,		IFunction *,	0x00C36540,	const char *fnName);
		DEFINE_MEMBER_FN_const(	GetMemberFunctions,	IFunction **,	0x00C365A0,	const char *fnName);


	//protected:
		// @members
		const char		* name;					// 04 - always refers to a BSFixedString but is not, because of no destruction in dtor.
		BSScriptClass	* parent;				// 08
		BSFixedString	unk0C;					// 0C

		unsigned int 	flags				: 2;	// 10-00
		unsigned int	numScriptFlags		: 6;	// 10-02
		unsigned int	numVariables		: 10;	// 10-08
		unsigned int						: 14;	// 10-12

		unsigned int	numDefaultValues	: 10;	// 14-00
		unsigned int	numProperties		: 10;	// 14-0A
		unsigned int	numGlobalFuncs		: 9;	// 14-14
		unsigned int						: 3;	// 14-1D

		unsigned int	numMemberFuncs		: 9;	// 18 - bit 0

		UInt32			dataPtr;				// 1C

	private:
		DEFINE_MEMBER_FN(dtor, void, 0x00C34ED0);

		DEFINE_MEMBER_FN(FreeData, void, 0x00C348E0, bool); // called in dtor
	};
	STATIC_ASSERT(sizeof(BSScriptClass) == 0x20);
	STATIC_ASSERT(offsetof(BSScriptClass, dataPtr) == 0x1C);
}
