#pragma once

#include <Skyrim.h>
#include <Skyrim/BSScript/BSScriptIFunction.h>
#include <Skyrim/BSScript/BSScriptPackUnpack.h>
#include <Skyrim/VMArray.h>
#include <Skyrim/VMState.h>


#define REGISTER_PAPYRUS_FUNCTION(className, funcName, ...)	SKSEScript::RegisterFunction(#className, #funcName, &className::funcName, __VA_ARGS__)

namespace SKSEScript
{
	template <class _Base, class _Result, class... _Params>
	class NativeFunction;

	// register class function
	template <class _Base, class _Result, class... _Params>
	typename std::enable_if<
		BSScript::is_valid_result<_Result>::value
		&& BSScript::is_form<_Base>::value
		&& BSScript::are_packable<_Params...>::value
	>::type
	RegisterFunction(const char *className, const char *funcName, _Result(_Base::*func)(_Params...), VMState *state, UInt32 flags = 0)
	{
		BSScript::IFunction *ifunc = new NativeFunction<_Base, _Result, _Params...>(funcName, className, func, state);
		state->RegisterFunction(ifunc);
		if (flags)
		{
			state->SetFunctionFlags(className, funcName, flags);
		}
	}

	// register global function
	template <class _Result, class... _Params>
	typename std::enable_if<
		BSScript::is_valid_result<_Result>::value
		&& BSScript::are_packable<_Params...>::value
	>::type
	RegisterFunction(const char *className, const char *funcName, _Result(*func)(_Params...), VMState *state, UInt32 flags = 0)
	{
		state->RegisterFunction(new NativeFunction<BSScript::StaticFunctionTag, _Result, _Params...>(funcName, className, func, state));
		if (flags)
		{
			state->SetFunctionFlags(className, funcName, flags);
		}
	}
}


namespace SKSEScript
{
	using BSScript::StackFrame;
	using BSScript::BSScriptVariable;

	//============================
	// helpers
	//============================


	struct NF_helper
	{
		template <std::size_t N, class T0, class... T>
		struct type_at : public type_at<N - 1, T...>
		{
		};

		template <class T0, class ... T>
		struct type_at<0, T0, T...>
		{
			typedef T0 type;
		};
	};

	struct NF_caller
	{
		template <class _T>
		static inline _T Unpack(StackFrame *frame, UInt32 offset, UInt32 &index)
		{
			BSScriptVariable *src = frame->stack->Get(frame, --index, offset);
			return src->Unpack<_T>();
		}

		template <class _Result, class _Base, class... _Params>
		static inline bool Call(_Result(_Base::*callback)(_Params...), BSScriptVariable *ResultVar, BSScriptVariable *baseVar, StackFrame *frame, VMState *state)
		{
			_Base *pBase = baseVar->Unpack<_Base *>();
			if (!pBase)
				return false;

			UInt32 offset = frame->stack->GetOffset(frame);
			UInt32 index = sizeof...(_Params);
			_Result result = (pBase->*callback)(Unpack<_Params>(frame, offset, index)...);
			ResultVar->Pack(result, state);

			return true;
		}

		template <class _Base, class..._Params>
		static inline bool Call(void(_Base::*callback)(_Params...), BSScriptVariable *ResultVar, BSScriptVariable *baseVar, StackFrame *frame, VMState *state)
		{
			_Base *pBase = baseVar->Unpack<_Base *>();
			if (!pBase)
				return false;

			UInt32 offset = frame->stack->GetOffset(frame);
			UInt32 index = sizeof...(_Params);
			(pBase->*callback)(Unpack<_Params>(frame, offset, index)...);
			ResultVar->SetNone();

			return true;
		}

		template <class _Result, class... _Params>
		static inline bool Call(_Result(*callback)(_Params...), BSScriptVariable *ResultVar, BSScriptVariable *baseVar, StackFrame *frame, VMState *state)
		{
			UInt32 offset = frame->stack->GetOffset(frame);
			UInt32 index = sizeof...(_Params);
			_Result result = (*callback)(Unpack<_Params>(frame, offset, index)...);
			ResultVar->Pack(result, state);

			return true;
		}

		template <class... _Params>
		static inline bool Call(void(*callback)(_Params...), BSScriptVariable *ResultVar, BSScriptVariable *baseVar, StackFrame *frame, VMState *state)
		{
			UInt32 offset = frame->stack->GetOffset(frame);
			UInt32 index = sizeof...(_Params);
			(*callback)(Unpack<_Params>(frame, offset, index)...);
			ResultVar->SetNone();

			return true;
		}
	};


	//===============================
	// native papyrus function class
	//===============================

	template <class _Base, class _Result, class... _Params>
	class NativeFunction : public BSScript::NF_util::NativeFunctionBase, protected NF_helper, protected NF_caller
	{
	private:
		const static bool is_static = BSScript::is_static<_Base>::value;

		using CallbackType = typename std::conditional <is_static,
			_Result(*)(_Params...),				// global function
			_Result(_Base::*)(_Params...)		// member function
		>::type;

		template <std::size_t N = 0>
		inline typename std::enable_if< (N == sizeof...(_Params)) >::type
		SetParams(VMState *state)
		{
		}

		template <std::size_t N = 0>
		inline typename std::enable_if< (N < sizeof...(_Params)) >::type
		SetParams(VMState *state)
		{
			m_params.data[N].type = BSScript::GetTypeID< type_at<N, _Params...>::type >(state);
			SetParams<N + 1>(state);
		}

	public:
		NativeFunction(const char *funcName, const char *className, CallbackType callback, VMState *state)
			: BSScript::NF_util::NativeFunctionBase(funcName, className, is_static, sizeof...(_Params)), m_callback(callback)
		{
			SetParams(state);
			m_retnType = BSScript::GetTypeID<_Result>(state);
		}

		virtual bool HasCallback(void) const override
		{
			return (m_callback != nullptr);
		}

		virtual bool Run(BSScriptVariable *baseVar, VMState *state, UInt32 unk2, BSScriptVariable *ResultVar, StackFrame *frame) override
		{
			return Call(m_callback, ResultVar, baseVar, frame, state);
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
