#pragma once

#include <Skyrim.h>
#include <Skyrim/VMState.h>
#include <Skyrim/SkyrimVM.h>
#include <Skyrim/BSScript/BSScriptNativeFunctions.h>

#include "DebugLog.h"

#include <type_traits>


template <class _Base, class _Retn, class..._Params>
class _NativeFunction : public BSScript::NF_util::NativeFunctionBase
{
public:
	typedef _Retn(*CallbackType)(VMState*, UInt32, _Base*, _Params...);

	bool Validate(VMState* state)
	{
		if (IsStatic() != std::is_same<_Base, BSScript::StaticFunctionTag>::value)
			return false;

		if (m_retnType != BSScript::GetTypeID<_Retn>(state))
			return false;

		return ValidateParams<0, _Params...>(state);
	}

	_Retn operator()(VMState* state, UInt32 stackID, _Base* base, _Params... params)
	{
		return m_callback(state, stackID, base, params...);
	}

private:
	template <int n>
	bool ValidateParams(VMState* state)
	{
		return true;
	}

	template <int n, class First, class... Rest>
	bool ValidateParams(VMState* state)
	{
		if (m_params.data[n].type != BSScript::GetTypeID<First>(state))
			return false;

		return ValidateParams< n + 1, Rest...>(state);
	}
public:

	CallbackType m_callback;
};


namespace SKSEScript
{
	BSScript::IFunction* GetFunction(VMState* state, UInt32 typeID, const char* fnName);
	BSScript::IFunction* GetFunction(VMState* state, const BSFixedString &className, const BSFixedString &fnName);

	template <class _Base, class _Retn, class... _Params>
	_NativeFunction<_Base, _Retn, _Params...>* GetFunction(const char* fnName, VMState* state)
	{
		typedef _NativeFunction<_Base, _Retn, _Params...> NativeFunction;

		NativeFunction* func =  (NativeFunction*)GetFunction(_Base::kTypeID, fnName, state);
		if (func && !func->Validate(state))
		{
			func = nullptr;
		}

		return func;
	}

	template <class _Base, class _Retn, class... _Params>
	class NativeFunctionPtr
	{
	public:
		typedef _NativeFunction<_Base, _Retn, _Params...> NativeFunction;

		NativeFunctionPtr(const char* fnName) : m_ptr(nullptr)
		{
			VMState* state = g_skyrimVM->GetState();
			NativeFunction* ptr = (NativeFunction*)SKSEScript::GetFunction(_Base::kTypeID, fnName, state);
			if (ptr && ptr->Validate(state))
			{
				m_ptr = ptr;
			}
		}

		operator bool() const
		{
			return (m_ptr != nullptr);
		}

		NativeFunction* operator*()
		{
			return m_ptr;
		}

		const NativeFunction* operator*() const
		{
			return m_ptr;
		}

		class Functor
		{
		public:
			Functor(_Base* a_base, NativeFunction* a_func) : base(a_base), func(a_func) {}

			_Retn operator()(_Params... params)
			{
				VMState* state = g_skyrimVM->GetState();
				return (*func)(state, 0, base, params...);
			}

		private:
			_Base* base;
			NativeFunction* func;
		};

		Functor GetFunctor(_Base* base)
		{
			return Functor(base, m_ptr);
		}

	private:
		NativeFunction* m_ptr;
	};
}

template <class _Ty, class _Base, class _Retn, class... _Params>
auto operator->*(_Ty* base, SKSEScript::NativeFunctionPtr<_Base, _Retn, _Params...>& ptr) -> decltype(ptr.GetFunctor(static_cast<_Base*>(base)))
{
	return ptr.GetFunctor(static_cast<_Base*>(base));
}
