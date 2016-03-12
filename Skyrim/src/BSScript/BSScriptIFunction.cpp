#include "Skyrim.h"
#include "Skyrim/BSScript/BSScriptIFunction.h"
#include "Skyrim/Memory.h"

namespace BSScript
{
	std::string IFunction::ToString() const
	{
		BSScriptVariable	value;

		std::string declName;
		declName.reserve(128);


		GetReturnType(value.type);
		if (value.type)
		{
			declName = value.GetTypeName();
			declName += ' ';
		}

		declName += (IsEvent()) ? "Event " : "Function ";
		declName += GetName().c_str();

		const UInt32 numParams = GetNumParams();
		declName += "(";

		for (UInt32 i = 0; i < numParams; i++)
		{
			if (i != 0)
				declName += ", ";

			BSFixedString paramName;
			GetParam(i, paramName, value.type);
			declName += value.GetTypeName();
			declName += ' ';
			declName += paramName.c_str();
		}
		declName += ')';

		if (IsStatic())
			declName += " global";
		if (IsNative())
			declName += " native";

		value.type = 0;

		return declName;
	}


	namespace NF_util
	{
		NativeFunctionBase::ParameterInfo::ParameterInfo(UInt32 num, UInt32 margin)
		{
			ParameterInfo::ctor(num, margin);
		}

		NativeFunctionBase::NativeFunctionBase(const char *fnName, const char *className, bool isStatic, UInt32 numParams)
		{
			ctor(fnName, className, isStatic, numParams);
		}

		NativeFunctionBase::~NativeFunctionBase()
		{
			dtor();
		}

		const BSFixedString &	NativeFunctionBase::GetName(void) const 				{ return m_fnName; }
		const BSFixedString &	NativeFunctionBase::GetScriptName(void) const			{ return m_scriptName; }
		const BSFixedString &	NativeFunctionBase::GetStateName(void) const			{ return m_stateName; }
		void					NativeFunctionBase::GetReturnType(VMTypeID & dst) const	{ dst = m_retnType; }
		UInt32					NativeFunctionBase::GetNumParams(void) const			{ return m_params.unk06; }
		VMTypeID &				NativeFunctionBase::GetParam(UInt32 idx, BSFixedString & nameOut, VMTypeID & typeOut) const
		{
			return m_params.GetParam(idx, nameOut, typeOut);
		}
		UInt32					NativeFunctionBase::GetNumParams2(void) const			{ return m_params.unk06; }
		bool					NativeFunctionBase::IsNative(void) const				{ return true; }
		bool					NativeFunctionBase::IsStatic(void) const				{ return m_isStatic; }
		bool					NativeFunctionBase::IsEvent(void) const					{ return false; }
		UInt32					NativeFunctionBase::Unk_0B(void)						{ return 0; }
		UInt32					NativeFunctionBase::GetUnk24(void) const				{ return unk24; }
		const BSFixedString &	NativeFunctionBase::GetStr28(void) const				{ return unk28; }
		void					NativeFunctionBase::Unk_0E(UInt32 unk)					{ }	// always nop?
		UInt32					NativeFunctionBase::Invoke(BSScriptStackPtr & stack, UInt32 unk1, VMState * state, UInt32 unk3)
		{
			return Impl_Invoke(stack, unk1, state, unk3);
		}
		const BSFixedString &	NativeFunctionBase::GetSource(void) const				{ return Impl_GetSource(); }
		bool					NativeFunctionBase::Unk_11(UInt32 unk0, UInt32 * unk1)	{ *unk1 = 0; return false; }
		bool					NativeFunctionBase::GetParamName(UInt32 idx, BSFixedString &out) const
		{
			return Impl_GetParamName(idx, out);
		}
		bool					NativeFunctionBase::GetUnk21(void) const				{ return unk21; }
		void					NativeFunctionBase::SetUnk21(bool arg)					{ unk21 = arg; }
	}
}
