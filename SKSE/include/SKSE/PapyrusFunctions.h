#pragma once

#include <Skyrim.h>
#include <Skyrim/BSScript/BSScriptIFunction.h>
#include <Skyrim/BSScript/BSScriptPackUnpack.h>
#include <Skyrim/VMArray.h>
#include <Skyrim/VMState.h>

#include <type_traits>

#define REGISTER_PAPYRUS_FUNCTION(className, funcName, ...)	SKSEScript::RegisterFunction(#className, #funcName, &className::funcName, __VA_ARGS__)

namespace SKSEScript
{
	using BSScript::StackFrame;

	template <class _Base, class _Result, class... _Params>
	class NativeFunction;

	// register class function
	template <class _Base, class _Result, class... _Params>
	void RegisterFunction(const char * className, const char * funcName, _Result(_Base::*func)(_Params...), VMState* state, UInt32 flags = 0)
	{
		BSScript::IFunction* ifunc = new NativeFunction<_Base, _Result, _Params...>(funcName, className, func, state);
		state->RegisterFunction(ifunc);
		if (flags)
		{
			state->SetFunctionFlags(className, funcName, flags);
		}
	}

	// register global function
	template <class _Result, class... _Params>
	void RegisterFunction(const char * className, const char * funcName, _Result(*func)(_Params...), VMState* state, UInt32 flags = 0)
	{
		state->RegisterFunction(new NativeFunction<BSScript::StaticFunctionTag, _Result, _Params...>(funcName, className, func, state));
		if (flags)
		{
			state->SetFunctionFlags(className, funcName, flags);
		}
	}

	//
	template <std::size_t N, class T0, class... T>
	struct type_at : public type_at<N - 1, T...> {};

	template <class T0, class ... T>
	struct type_at<0, T0, T...>
	{
		typedef T0 type;
	};


	//
	template <class _T>
	static inline _T Unpack(StackFrame *frame, UInt32 offset, UInt32 & index)
	{
		BSScript::BSScriptVariable *src = frame->stack->Get(frame, --index, offset);
		return src->Unpack<_T>();
	}

	//
	template <class _Result, class _Base, class... _Params>
	static inline bool NativeCall(_Result(_Base::*callback)(_Params...), BSScript::BSScriptVariable * resultValue, BSScript::BSScriptVariable * baseValue, StackFrame * frame, VMState * state)
	{
		_Base* base = baseValue->Unpack<_Base*>();
		if (!base)
			return false;

		UInt32 offset = frame->stack->GetOffset(frame);
		UInt32 index = sizeof...(_Params);
		_Result result = (base->*callback)(Unpack<_Params>(frame, offset, index)...);
		resultValue->Pack(result, state);

		return true;
	}

	template <class _Base, class..._Params>
	static inline bool NativeCall(void(_Base::*callback)(_Params...), BSScript::BSScriptVariable * resultValue, BSScript::BSScriptVariable * baseValue, StackFrame * frame, VMState * state)
	{
		_Base* base = baseValue->Unpack<_Base*>();
		if (!base)
			return false;

		UInt32 offset = frame->stack->GetOffset(frame);
		UInt32 index = sizeof...(_Params);
		(base->*callback)(Unpack<_Params>(frame, offset, index)...);
		resultValue->SetNone();

		return true;
	}

	template <class _Result, class... _Params>
	static inline bool NativeCall(_Result(*callback)(_Params...), BSScript::BSScriptVariable * resultValue, BSScript::BSScriptVariable * baseValue, StackFrame * frame, VMState * state)
	{
		UInt32 offset = frame->stack->GetOffset(frame);
		UInt32 index = sizeof...(_Params);
		_Result result = (*callback)(Unpack<_Params>(frame, offset, index)...);
		resultValue->Pack(result, state);

		return true;
	}

	template <class... _Params>
	static inline bool NativeCall(void(*callback)(_Params...), BSScript::BSScriptVariable * resultValue, BSScript::BSScriptVariable * baseValue, StackFrame * frame, VMState * state)
	{
		UInt32 offset = frame->stack->GetOffset(frame);
		UInt32 index = sizeof...(_Params);
		(*callback)(Unpack<_Params>(frame, offset, index)...);
		resultValue->SetNone();

		return true;
	}

	// native papyrus function
	template <class _Base, class _Result, class... _Params>
	class NativeFunction : public BSScript::NF_util::NativeFunctionBase
	{
	private:
		const static bool is_static = BSScript::is_static<_Base>::value;

		using CallbackType = typename std::conditional < is_static, _Result(*)(_Params...), _Result(_Base::*)(_Params...) >::type;

		template <std::size_t N = 0>
		typename std::enable_if< (N == sizeof...(_Params)) >::type
		SetParams(VMState* state)
		{
		}

		template <std::size_t N = 0>
		typename std::enable_if< (N < sizeof...(_Params)) >::type
		SetParams(VMState* state)
		{
			m_params.data[N].type = BSScript::GetTypeID< type_at<N, _Params...>::type >(state);
			SetParams<N + 1>(state);
		}

	public:
		NativeFunction(const char* funcName, const char* className, CallbackType callback, VMState* state)
			: BSScript::NF_util::NativeFunctionBase(funcName, className, is_static, sizeof...(_Params)), m_callback(callback)
		{
			SetParams(state);
			m_retnType = BSScript::GetTypeID<_Result>(state);
		}

		virtual ~NativeFunction() {}

		virtual bool HasCallback(void) const override
		{
			return (m_callback != nullptr);
		}

		virtual bool Run(BSScript::BSScriptVariable * baseValue, VMState * state, UInt32 unk2, BSScript::BSScriptVariable * resultValue, StackFrame * frame) override
		{
			return NativeCall(m_callback, resultValue, baseValue, frame, state);
		}

		inline CallbackType GetCallback() const
		{
			return m_callback;
		}

	private:
		// @members
		CallbackType m_callback;		// 2C
	};
}
