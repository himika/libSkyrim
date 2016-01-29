#define CLASS_NAME __MACRO_JOIN__(NativeFunction, NUM_PARAMS)

#if NUM_PARAMS > 10
#error PapyrusNativeFunctionDef: too many params
#endif

template <typename T_Base, typename T_Result
#if NUM_PARAMS > 0
	, typename T_Arg0
#endif
#if NUM_PARAMS > 1
	, typename T_Arg1
#endif
#if NUM_PARAMS > 2
	, typename T_Arg2
#endif
#if NUM_PARAMS > 3
	, typename T_Arg3
#endif
#if NUM_PARAMS > 4
	, typename T_Arg4
#endif
#if NUM_PARAMS > 5
	, typename T_Arg5
#endif
#if NUM_PARAMS > 6
	, typename T_Arg6
#endif
#if NUM_PARAMS > 7
	, typename T_Arg7
#endif
#if NUM_PARAMS > 8
	, typename T_Arg8
#endif
#if NUM_PARAMS > 9
	, typename T_Arg9
#endif
>
class CLASS_NAME : public NF_util::NativeFunctionBase
{
public:
	typedef T_Result(*CallbackType)(VMState* state, UInt32 stackID, T_Base * base
#if NUM_PARAMS > 0
		, T_Arg0 arg0
#endif
#if NUM_PARAMS > 1
		, T_Arg1 arg1
#endif
#if NUM_PARAMS > 2
		, T_Arg2 arg2
#endif
#if NUM_PARAMS > 3
		, T_Arg3 arg3
#endif
#if NUM_PARAMS > 4
		, T_Arg4 arg4
#endif
#if NUM_PARAMS > 5
		, T_Arg5 arg5
#endif
#if NUM_PARAMS > 6
		, T_Arg6 arg6
#endif
#if NUM_PARAMS > 7
		, T_Arg7 arg7
#endif
#if NUM_PARAMS > 8
		, T_Arg8 arg8
#endif
#if NUM_PARAMS > 9
		, T_Arg9 arg9
#endif
		);

	CLASS_NAME(const char * fnName, const char * className, CallbackType callback, VMState * state)
		: NF_util::NativeFunctionBase(fnName, className, is_static<T_Base>::value, NUM_PARAMS)
	{
		// store callback
		m_callback = callback;

#if NUM_PARAMS > 0
		m_params.data[0].type = GetTypeID <T_Arg0>(state);
#endif
#if NUM_PARAMS > 1
		m_params.data[1].type = GetTypeID <T_Arg1>(state);
#endif
#if NUM_PARAMS > 2
		m_params.data[2].type = GetTypeID <T_Arg2>(state);
#endif
#if NUM_PARAMS > 3
		m_params.data[3].type = GetTypeID <T_Arg3>(state);
#endif
#if NUM_PARAMS > 4
		m_params.data[4].type = GetTypeID <T_Arg4>(state);
#endif
#if NUM_PARAMS > 5
		m_params.data[5].type = GetTypeID <T_Arg5>(state);
#endif
#if NUM_PARAMS > 6
		m_params.data[6].type = GetTypeID <T_Arg6>(state);
#endif
#if NUM_PARAMS > 7
		m_params.data[7].type = GetTypeID <T_Arg7>(state);
#endif
#if NUM_PARAMS > 8
		m_params.data[8].type = GetTypeID <T_Arg8>(state);
#endif
#if NUM_PARAMS > 9
		m_params.data[9].type = GetTypeID <T_Arg9>(state);
#endif

		m_retnType = GetTypeID <void>(state);
	}

	virtual bool HasCallback(void) const override
	{
		return m_callback != nullptr;
	}

	virtual bool Run(BSScriptVariable * baseValue, VMState * state, UInt32 stackID, BSScriptVariable * resultValue, StackFrame * frame) override
	{
		T_Base *base = nullptr;

		// extract base object pointer for non-static types
		if (!is_static<T_Base>::value)
		{
			base = baseValue->Unpack<T_Base *>();
			if (!base)
				return false;
		}

		return _Run(base, state, stackID, resultValue, frame);
	}

	static void *enabler;

private:
	template < typename T = T_Result, typename std::enable_if<is_packable<T>::value>::type *& = enabler >
	inline bool _Run(T_Base * base, VMState * state, UInt32 stackID, BSScriptVariable * resultValue, StackFrame * frame)
	{
		// extract parameters
		BSScriptStack* stack = frame->stack;
		UInt32	offset = stack->GetOffset(frame);
#if NUM_PARAMS > 0
		T_Arg0 arg0 = stack->Get(frame, 0, offset)->Unpack<T_Arg0>();
#endif
#if NUM_PARAMS > 1
		T_Arg1 arg1 = stack->Get(frame, 1, offset)->Unpack<T_Arg1>();
#endif
#if NUM_PARAMS > 2
		T_Arg2 arg2 = stack->Get(frame, 2, offset)->Unpack<T_Arg2>();
#endif
#if NUM_PARAMS > 3
		T_Arg3 arg3 = stack->Get(frame, 3, offset)->Unpack<T_Arg3>();
#endif
#if NUM_PARAMS > 4
		T_Arg4 arg4 = stack->Get(frame, 4, offset)->Unpack<T_Arg4>();
#endif
#if NUM_PARAMS > 5
		T_Arg5 arg5 = stack->Get(frame, 5, offset)->Unpack<T_Arg5>();
#endif
#if NUM_PARAMS > 6
		T_Arg6 arg6 = stack->Get(frame, 6, offset)->Unpack<T_Arg6>();
#endif
#if NUM_PARAMS > 7
		T_Arg7 arg7 = stack->Get(frame, 7, offset)->Unpack<T_Arg7>();
#endif
#if NUM_PARAMS > 8
		T_Arg8 arg8 = stack->Get(frame, 8, offset)->Unpack<T_Arg8>();
#endif
#if NUM_PARAMS > 9
		T_Arg9 arg9 = stack->Get(frame, 9, offset)->Unpack<T_Arg9>();
#endif

		// call the callback
		T result = m_callback(state, stackID, base
#if NUM_PARAMS > 0
			, arg0
#endif
#if NUM_PARAMS > 1
			, arg1
#endif
#if NUM_PARAMS > 2
			, arg2
#endif
#if NUM_PARAMS > 3
			, arg3
#endif
#if NUM_PARAMS > 4
			, arg4
#endif
#if NUM_PARAMS > 5
			, arg5
#endif
#if NUM_PARAMS > 6
			, arg6
#endif
#if NUM_PARAMS > 7
			, arg7
#endif
#if NUM_PARAMS > 8
			, arg8
#endif
#if NUM_PARAMS > 9
			, arg9
#endif
			);
		resultValue->Pack(result, state);
		return true;
	}

	template < typename T = T_Result, typename std::enable_if<std::is_void<T>::value>::type *& = enabler >
	inline bool _Run(T_Base * base, VMState * state, UInt32 stackID, BSScriptVariable * resultValue, StackFrame * frame)
	{
		// extract parameters
		BSScriptStack* stack = frame->stack;
		UInt32	offset = stack->GetOffset(frame);
#if NUM_PARAMS > 0
		T_Arg0 arg0 = stack->Get(frame, 0, offset)->Unpack<T_Arg0>();
#endif
#if NUM_PARAMS > 1
		T_Arg1 arg1 = stack->Get(frame, 1, offset)->Unpack<T_Arg1>();
#endif
#if NUM_PARAMS > 2
		T_Arg2 arg2 = stack->Get(frame, 2, offset)->Unpack<T_Arg2>();
#endif
#if NUM_PARAMS > 3
		T_Arg3 arg3 = stack->Get(frame, 3, offset)->Unpack<T_Arg3>();
#endif
#if NUM_PARAMS > 4
		T_Arg4 arg4 = stack->Get(frame, 4, offset)->Unpack<T_Arg4>();
#endif
#if NUM_PARAMS > 5
		T_Arg5 arg5 = stack->Get(frame, 5, offset)->Unpack<T_Arg5>();
#endif
#if NUM_PARAMS > 6
		T_Arg6 arg6 = stack->Get(frame, 6, offset)->Unpack<T_Arg6>();
#endif
#if NUM_PARAMS > 7
		T_Arg7 arg7 = stack->Get(frame, 7, offset)->Unpack<T_Arg7>();
#endif
#if NUM_PARAMS > 8
		T_Arg8 arg8 = stack->Get(frame, 8, offset)->Unpack<T_Arg8>();
#endif
#if NUM_PARAMS > 9
		T_Arg9 arg9 = stack->Get(frame, 9, offset)->Unpack<T_Arg9>();
#endif

		// call the callback
		m_callback(state, stackID, base
#if NUM_PARAMS > 0
			, arg0
#endif
#if NUM_PARAMS > 1
			, arg1
#endif
#if NUM_PARAMS > 2
			, arg2
#endif
#if NUM_PARAMS > 3
			, arg3
#endif
#if NUM_PARAMS > 4
			, arg4
#endif
#if NUM_PARAMS > 5
			, arg5
#endif
#if NUM_PARAMS > 6
			, arg6
#endif
#if NUM_PARAMS > 7
			, arg7
#endif
#if NUM_PARAMS > 8
			, arg8
#endif
#if NUM_PARAMS > 9
			, arg9
#endif
			);
		resultValue->SetNone();
		return true;
	}

	// hide
	CLASS_NAME();

	// @members
	CallbackType m_callback;	// 2C
};

template <typename T_Base, typename T_Result
#if NUM_PARAMS > 0
	, typename T_Arg0
#endif
#if NUM_PARAMS > 1
	, typename T_Arg1
#endif
#if NUM_PARAMS > 2
	, typename T_Arg2
#endif
#if NUM_PARAMS > 3
	, typename T_Arg3
#endif
#if NUM_PARAMS > 4
	, typename T_Arg4
#endif
#if NUM_PARAMS > 5
	, typename T_Arg5
#endif
#if NUM_PARAMS > 6
	, typename T_Arg6
#endif
#if NUM_PARAMS > 7
	, typename T_Arg7
#endif
#if NUM_PARAMS > 8
	, typename T_Arg8
#endif
#if NUM_PARAMS > 9
	, typename T_Arg9
#endif
>
void RegisterFunction(VMState* state, const char* className, const char* fnName, T_Result(*callback)(VMState*, UInt32, T_Base*
#if NUM_PARAMS > 0
	, T_Arg0
#endif
#if NUM_PARAMS > 1
	, T_Arg1
#endif
#if NUM_PARAMS > 2
	, T_Arg2
#endif
#if NUM_PARAMS > 3
	, T_Arg3
#endif
#if NUM_PARAMS > 4
	, T_Arg4
#endif
#if NUM_PARAMS > 5
	, T_Arg5
#endif
#if NUM_PARAMS > 6
	, T_Arg6
#endif
#if NUM_PARAMS > 7
	, T_Arg7
#endif
#if NUM_PARAMS > 8
	, T_Arg8
#endif
#if NUM_PARAMS > 9
	, T_Arg9
#endif
	))
{
	auto fn = new CLASS_NAME<T_Base, T_Result
#if NUM_PARAMS > 0
		, T_Arg0
#endif
#if NUM_PARAMS > 1
		, T_Arg1
#endif
#if NUM_PARAMS > 2
		, T_Arg2
#endif
#if NUM_PARAMS > 3
		, T_Arg3
#endif
#if NUM_PARAMS > 4
		, T_Arg4
#endif
#if NUM_PARAMS > 5
		, T_Arg5
#endif
#if NUM_PARAMS > 6
		, T_Arg6
#endif
#if NUM_PARAMS > 7
		, T_Arg7
#endif
#if NUM_PARAMS > 8
		, T_Arg8
#endif
#if NUM_PARAMS > 9
		, T_Arg9
#endif
	>(fnName, className, callback, state);
	if (fn)
		state->RegisterFunction((IFunction*)fn);
}


#undef CLASS_NAME
#undef NUM_PARAMS
