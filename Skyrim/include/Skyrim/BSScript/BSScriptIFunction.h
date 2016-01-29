#pragma once

#include "../BSCore/BSFixedString.h"
#include "BSScriptStack.h"
#include <string>

class VMState;

namespace BSScript
{
	BSSmartPointer(IFunction);

	struct StaticFunctionTag
	{
		enum { kTypeID = 0 };
	};

	// 08
	class IFunction : public BSIntrusiveRefCounted
	{
	public:
		typedef BSTSmartPointer<IFunction> SmartPtr;

		IFunction()				{ }
		virtual ~IFunction()	{ }

		virtual const BSFixedString &	GetName(void) const = 0;
		virtual const BSFixedString &	GetScriptName(void) const = 0;
		virtual const BSFixedString &	GetStateName(void) const = 0;
		virtual void					GetReturnType(VMTypeID& dst) const = 0;
		virtual UInt32					GetNumParams(void) const = 0;
		virtual void					GetParam(UInt32 idx, BSFixedString & nameOut, VMTypeID & typeOut) const = 0;
		virtual UInt32					GetNumParams2(void) const = 0;
		virtual bool					IsNative(void) const = 0;
		virtual bool					IsStatic(void) const = 0;
		virtual bool					IsEvent(void) const = 0;
		virtual UInt32					Unk_0B(void) = 0;				// always return 0 ?
		virtual UInt32					GetUnk24(void) const = 0;		// always return 0 ?
		virtual const BSFixedString &	GetStr28(void) const = 0;		// always nullptr or "" ?
		virtual void					Unk_0E(UInt32 unk) = 0;
		virtual UInt32					Invoke(BSTSmartPointer<BSScriptStack>& stack, UInt32 unk1, VMState * state, UInt32 unk3) = 0;
		virtual const BSFixedString &	GetSource(void) const = 0;
		virtual bool					Unk_11(UInt32 unk0, UInt32 * unk1) = 0;
		virtual bool					GetParamName(UInt32 idx, BSFixedString &out) const = 0;	// param list stuff
		virtual bool					GetUnk21(void) const = 0;
		virtual void					SetUnk21(bool arg) {} // = 0;

		std::string	ToString() const;

		// @members
		//void	** _vtbl;					// 00 - 0114A658
	};
	STATIC_ASSERT(sizeof(IFunction) == 0x08);

	//   vtbl   - type
	// 0114C298 - TemporaryBindingNativeFunction
	// 0114D930 - PapyrusILFunction / PapyrusILEvent

	class TemporaryBindingFunction : public IFunction
	{
	public:
		virtual ~TemporaryBindingFunction();									// 00C5F9D0

		virtual const BSFixedString &	GetName(void) const override;			// 00C3F9A0
		virtual const BSFixedString &	GetScriptName(void) const override;		// 00C3F9B0
		virtual const BSFixedString &	GetStateName(void) const override;		// 00C3F9C0
		// more

		// @members
		//void	** _vtbl;					// 00 - 0114C298
	};

	namespace NF_util
	{
		// 2C
		class NativeFunctionBase : public IFunction
		{
		public:
			NativeFunctionBase(const char * fnName, const char * className, bool isStatic, UInt32 numParams);
			virtual ~NativeFunctionBase();

			// @override
			virtual const BSFixedString &	GetName(void) const override;
			virtual const BSFixedString &	GetScriptName(void) const override;
			virtual const BSFixedString &	GetStateName(void) const override;
			virtual void					GetReturnType(VMTypeID & dst) const override;
			virtual UInt32					GetNumParams(void) const override;
			virtual void					GetParam(UInt32 idx, BSFixedString & nameOut, VMTypeID & typeOut) const override;
			virtual UInt32					GetNumParams2(void) const override;
			virtual bool					IsNative(void) const override;
			virtual bool					IsStatic(void) const override;
			virtual bool					IsEvent(void) const override;
			virtual UInt32					Unk_0B(void) override;
			virtual UInt32					GetUnk24(void) const override;
			virtual const BSFixedString &	GetStr28(void) const override;
			virtual void					Unk_0E(UInt32 unk) override;
			virtual UInt32					Invoke(BSTSmartPointer<BSScriptStack>& stack, UInt32 unk1, VMState * state, UInt32 unk3) override;
			virtual const BSFixedString &	GetSource(void) const override;
			virtual bool					Unk_11(UInt32 unk0, UInt32 * unk1) override;
			virtual bool					GetParamName(UInt32 idx, BSFixedString &out) const override;
			virtual bool					GetUnk21(void) const override;
			virtual void					SetUnk21(bool arg) override;

			// @add
			virtual bool					HasCallback(void) const = 0;
			virtual bool					Run(BSScriptVariable * baseValue, VMState * state, UInt32 stackID, BSScriptVariable * resultValue, StackFrame * stack) = 0;

			bool							IsLatent(void) const	{ return m_isLatent; }

		protected:
			// 08
			struct ParameterInfo
			{
				ParameterInfo() {}
				ParameterInfo(UInt32 num, UInt32 margin);

				// 08
				struct Entry
				{
					BSFixedString	name;	// 00
					UInt32			type;	// 04 VMValue::type
				};

				DEFINE_MEMBER_FN(GetParam, void, 0x00C41AF0, UInt32 idx, BSFixedString * nameOut, UInt32 * typeOut);
				DEFINE_MEMBER_FN(GetParamName, const BSFixedString &, 0x00C3DFA9, UInt32 idx);

				// @members
				Entry	* data;		// 00 length = numParams + unk06
				UInt16	numParams;	// 04
				UInt16	unk06;		// 06

			private:
				DEFINE_MEMBER_FN(ctor, ParameterInfo*, 0x00C661B0, UInt32 numParams, UInt32 margin);
			};

			// @members
			//void			** _vtbl;		// 00 - 0114A6B0
			BSFixedString	m_fnName;		// 08
			BSFixedString	m_scriptName;	// 0C
			BSFixedString	m_stateName;	// 10
			UInt32			m_retnType;		// 14 - return type
			ParameterInfo	m_params;		// 18
			bool			m_isStatic;		// 20
			bool			unk21;			// 21
			bool			m_isLatent;		// 22
			UInt8			pad23;			// 23
			UInt32			unk24;			// 24
			BSFixedString	unk28;			// 28

		private:
			DEFINE_MEMBER_FN(ctor, NativeFunctionBase *, 0x00C46C00, const char * fnName, const char * className, bool isStatic, UInt32 numParams);
			DEFINE_MEMBER_FN(dtor, void, 0x00C46AD0);

			DEFINE_MEMBER_FN_const(Impl_GetParam, UInt32 *, 0x00C46F50, UInt32 idx, const BSFixedString & nameOut, UInt32 & typeOut);
			DEFINE_MEMBER_FN(Impl_Invoke, UInt32, 0x00C46CB0, BSTSmartPointer<BSScriptStack>& stack, UInt32 unk1, VMState * state, UInt32 unk3);
			DEFINE_MEMBER_FN_const(Impl_GetSource, const BSFixedString &, 0x00C46B10);
			DEFINE_MEMBER_FN_const(Impl_GetParamName, bool, 0x00C46F60, UInt32 idx, BSFixedString &out);
		};
		STATIC_ASSERT(sizeof(NativeFunctionBase) == 0x2C);

	}
}
