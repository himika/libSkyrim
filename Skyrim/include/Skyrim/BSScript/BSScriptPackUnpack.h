#pragma once

#include "BSScriptTypeTraits.h"
#include "BSScriptVariable.h"
#include "BSScriptArray.h"
#include "BSScriptObject.h"

class VMState;
template <class> class VMArray;

#define ENABLE_IF(tp, expr) typename std::enable_if<expr<tp>::value>::type *& = enabler

namespace BSScript
{
	extern void * enabler;
	extern VMTypeID GetTypeIDFromFormTypeID(UInt32 formTypeID, VMState * state);
	extern void PackHandle(BSScriptVariable * dst, const void * src, UInt32 typeID, VMState * state);
	extern void * UnpackHandle(const BSScriptVariable * src, UInt32 typeID);

	//======================
	// GetTypeID
	//======================
	template <class _Ty, ENABLE_IF(_Ty, is_builtin)>
	VMTypeID GetTypeID(VMState * state)
	{
		return typeid_builtin<_Ty>::value;
	}

	template <class _Ty, ENABLE_IF(_Ty, is_form_pointer)>
	VMTypeID GetTypeID(VMState * state)
	{
		typedef typename std::remove_pointer<_Ty>::type FormT;
		return GetTypeIDFromFormTypeID((UInt32)FormT::kTypeID, state);
	}

	template <class _Ty, ENABLE_IF(_Ty, is_array), ENABLE_IF(typename remove_array<_Ty>::type, is_builtin)>
	VMTypeID GetTypeID(VMState * state)
	{
		typedef typename remove_array<_Ty>::type ScalarType;
		return typeid_builtin<ScalarType>::value + 10U;
	}

	template <class _Ty, ENABLE_IF(_Ty, is_array), ENABLE_IF(typename remove_array<_Ty>::type, is_form_pointer)>
	VMTypeID GetTypeID(VMState * state)
	{
		typedef typename remove_array<_Ty>::type ScalarType;
		typedef typename std::remove_pointer<ScalarType>::type FormT;
		return GetTypeIDFromFormTypeID((UInt32)FormT::kTypeID, state) + BSScriptVariable::kType_Object;
	}

	//======================
	// PackValue
	//======================
	template <class _Ty, ENABLE_IF(_Ty, is_builtin)>
	void PackValue(BSScriptVariable & dst, const _Ty & src, VMState * state)
	{
		dst.SetNone();
		dst.type = typeid_builtin<_Ty>::value;
		dst.data = src;
	}

	template <class _Ty, ENABLE_IF(_Ty, is_form_pointer)>
	void PackValue(BSScriptVariable & dst, const _Ty & src, VMState * state)
	{
		typedef typename std::remove_pointer<_Ty>::type FormT;
		PackHandle(&dst, src, FormT::kTypeID, state);
	}

	template <class _Ty, ENABLE_IF(_Ty, is_array), ENABLE_IF(typename remove_array<_Ty>::type, is_builtin)>
	void PackValue(BSScriptVariable & dst, const _Ty & src, VMState * state)
	{
		dst.SetArray((const BSScriptArray*)src, GetTypeID<_Ty>(state));
	}

	template <class _Ty, ENABLE_IF(_Ty, is_array), ENABLE_IF(typename remove_array<_Ty>::type, is_form_pointer)>
	void PackValue(BSScriptVariable & dst, const _Ty & src, VMState * state)
	{
		dst.SetArray((const BSScriptArray*)src, GetTypeID<_Ty>(state));
	}

	//======================
	// UnpackValue
	//======================
	template <class _Ty, ENABLE_IF(_Ty, is_static_pointer)>
	_Ty UnpackValue(const BSScriptVariable& src)
	{
		return (_Ty)nullptr;
	}

	template <class _Ty, ENABLE_IF(_Ty, is_builtin)>
	_Ty UnpackValue(const BSScriptVariable& src)
	{
		return (_Ty)src.data;
	}

	template <class _Ty, ENABLE_IF(_Ty, is_form_pointer)>
	_Ty UnpackValue(const BSScriptVariable& src)
	{
		typedef typename std::remove_pointer<_Ty>::type FormT;
		return (_Ty)UnpackHandle(&src, FormT::kTypeID);
	}

	template <class _Ty, ENABLE_IF(_Ty, is_array), ENABLE_IF(typename remove_array<_Ty>::type, is_builtin)>
	_Ty UnpackValue(const BSScriptVariable& src)
	{
		return src.GetArray();
	}

	template <class _Ty, ENABLE_IF(_Ty, is_array), ENABLE_IF(typename remove_array<_Ty>::type, is_form_pointer)>
	_Ty UnpackValue(const BSScriptVariable& src)
	{
		return src.GetArray();
	}

	template <class _Ty>
	using IsStaticType = is_static<_Ty>;
}

#undef ENABLE_IF
