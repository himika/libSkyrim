#pragma once

#include <Skyrim.h>
#include <Skyrim/BSScript/BSScriptPackUnpack.h>
#include <Skyrim/BSScript/BSScriptIFunctionArguments.h>
#include <Skyrim/VMState.h>

#include <tuple>
#include <type_traits>

namespace SKSEScript
{
	template <class... Args>
	class FunctionArguments;

	template <class _T, class...Args>
	void QueueEvent(VMState * state, _T* base, const BSFixedString & eventName, Args... args)
	{
		FunctionArguments<Args...> functor(args...);
		functor(state, base, eventName);
	}

	template <class...Args>
	void QueueEvent(VMState * state, VMHandle handle, const BSFixedString & eventName, Args... args)
	{
		FunctionArguments<Args...> functor(args...);
		functor(state, handle, eventName);
	}

	class FunctionArgumentsBase : public BSScript::IFunctionArguments
	{
	public:
		FunctionArgumentsBase();
		virtual ~FunctionArgumentsBase();

		void operator()(VMState* state, VMHandle handle, const BSFixedString &eventName, bool bBroadcast = false)
		{
			m_state = state;
			QueueEvent(handle, eventName, bBroadcast);
		}

		template <typename Base>
		void operator()(VMState* state, Base* base, const BSFixedString &eventName, bool bBroadcast = true)
		{
			if (bBroadcast)
			{
				bBroadcast = (Base::kTypeID == (UInt32)FormType::Character || Base::kTypeID == (UInt32)FormType::Reference);
			}

			auto policy = state->GetHandlePolicy();
			VMHandle handle = policy->Create(base->kTypeID, base);

			if (handle != policy->GetInvalidHandle())
			{
				m_state = state;
				QueueEvent(handle, eventName, bBroadcast);
			}
		}

	protected:
		static void * enabler;
		
		template <std::size_t N = 0, class Tuple, typename std::enable_if< std::tuple_size<Tuple>::value != N >::type *& = enabler>
		static void PackTuple(VMState * state, Output & dst, Tuple & tp)
		{
			dst[N].Pack(std::get<N>(tp), state);
			PackTuple<N + 1>(state, dst, tp);
		}

		template <std::size_t N = 0, class Tuple, typename std::enable_if< std::tuple_size<Tuple>::value == N >::type *& = enabler>
		static void PackTuple(VMState * state, Output & dst, Tuple & tp)
		{
		}

		void QueueEvent(VMHandle handle, const BSFixedString &eventName, bool bBroadcast);

		VMState	* m_state;
	};
	

	template <class... Args>
	class FunctionArguments : public FunctionArgumentsBase
	{
	public:
		FunctionArguments(Args... args) : m_args(args...)
		{
		}

		virtual ~FunctionArguments()
		{
		}

		virtual bool Copy(Output & dst) override
		{
			dst.Resize(sizeof...(Args));
			PackTuple(m_state, dst, m_args);
			return true;
		}

	private:
		std::tuple<Args...>	m_args;
	};
}
