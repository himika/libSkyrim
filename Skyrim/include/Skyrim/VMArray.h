#pragma once

#include "BSSystem/BSTSmartPointer.h"
#include "BSScript/BSScriptVariable.h"
#include "BSScript/BSScriptArray.h"
#include "VMState.h"
#include "SkyrimVM.h"

#include <type_traits>

template <typename T>
class VMArray
{
public:
	typedef std::size_t size_type;
	typedef T value_type;
	typedef T *pointer;
	typedef const T *const_pointer;

	using BSScriptVariable = BSScript::BSScriptVariable;
	using BSScriptArray = BSScript::BSScriptArray;
	using BSScriptArrayPtr = BSScript::BSScriptArrayPtr;

	class const_reference
	{
	public:
		operator value_type() const {
			return ((BSScriptVariable*)this)->Unpack<value_type>();
		}
		bool operator==(value_type rhs) {
			value_type lhs = *this;
			return lhs == rhs;
		}
		bool operator!=(value_type rhs) {
			return !(*this == rhs);
		}
	private:
		const_reference() {}
	};

	class reference : public const_reference
	{
	public:
		reference& operator=(value_type rhs) {
			VMState * state = g_skyrimVM->GetState();
			((BSScriptVariable*)this)->Pack(rhs, state);
			return *this;
		}
	private:
		reference() {}
	};

	VMArray() : ptr() {}
	VMArray(const VMArray &  a_arr) : ptr(a_arr.ptr) {}
	VMArray(const BSTSmartPointer<BSScriptArray> & a_ptr) : ptr(a_ptr) {}
	VMArray(BSTSmartPointer<BSScriptArray> && a_ptr) : ptr(a_ptr) {}
	VMArray(const BSScriptArray * a_ptr) : ptr(a_ptr) {}

	explicit VMArray(size_type size) : ptr() {
		Allocate(size);
	}

	template <class ContainerT,
		class _value_type = typename ContainerT::value_type,
		class _size_type  = typename ContainerT::size_type,
		class _iterator   = typename ContainerT::iterator,
		class _reference  = typename ContainerT::reference,
		class _enabler    = typename std::enable_if<std::is_same<value_type, _value_type>::value>::type>
	VMArray(const ContainerT & cont) : ptr() {
			(*this) = cont;
	}

	template <std::size_t SIZE>
	VMArray(const value_type(&a_array)[SIZE]) : ptr() {
		(*this) = a_array;
	}

	template <class ContainerT,
		class _value_type = typename ContainerT::value_type,
		class _size_type  = typename ContainerT::size_type,
		class _iterator   = typename ContainerT::iterator,
		class _reference  = typename ContainerT::reference,
		class _enabler    = typename std::enable_if<std::is_same<value_type, _value_type>::value>::type>
	operator ContainerT() {
		size_type size = GetSize();
		ContainerT cont(size);

		if (size > 0) {
			size_type idx = 0;
			_iterator it = cont.begin();
			while (it != cont.end()) {
				*it++ = (*this)[idx++];
			}
		}
		return cont;
	}

	explicit operator BSScriptArray*() {
		return ptr;
	}
	explicit operator const BSScriptArray*() const {
		return ptr;
	}

	UInt32 GetSize() const {
		return ptr->GetSize();
	}

	bool GetAt(UInt32 index, value_type &out) const {
		return (index < GetSize()) ? (out = ptr->Get(index).Unpack<value_type>(), true) : false;
	}

	bool SetAt(UInt32 index, value_type &in) {
		VMState * state = g_skyrimVM->GetState();
		return (index < GetSize()) ? (ptr->Get(index).Pack(in, state), true) : false;
	}
	
	reference& operator[](size_type idx) {
		BSScriptVariable* value = &(ptr->Get(idx));
		return *(reference*)value;
	}
	const_reference& operator[](size_type idx) const {
		const BSScriptVariable* value = &(ptr->Get(idx));
		return *(const_reference*)value;
	}

	VMArray& operator=(const VMArray & a_arr) {
		ptr = a_arr.ptr;
		return *this;
	}
	VMArray& operator=(const BSTSmartPointer<BSScriptArray> & a_ptr) {
		ptr = a_ptr;
		return *this;
	}
	VMArray& operator=(BSTSmartPointer<BSScriptArray> && a_ptr) {
		ptr = a_ptr;
		return *this;
	}
	VMArray& operator=(const BSScriptArray* a_ptr) {
		ptr = a_ptr;
		return *this;
	}

	template <class ContainerT,
		class _value_type = typename ContainerT::value_type,
		class _size_type  = typename ContainerT::size_type,
		class _iterator   = typename ContainerT::iterator,
		class _reference  = typename ContainerT::reference,
		class _enabler    = typename std::enable_if<std::is_same<value_type, _value_type>::value>::type>
	VMArray& operator=(const ContainerT& cont) {
		const _size_type size = cont.size();
		if (size != 0 && Allocate(size)) {
			size_type idx = 0;

			//ContainerT::const_iterator it = std::begin(cont);
			//while (it != std::end(cont)) {
			//	(*this)[idx++] = *it++;
			//}
			for (auto el : cont) {
				(*this)[idx++] = el;
			}
		}
		return *this;
	}

	template <std::size_t SIZE>
	VMArray& operator=(const value_type(&a_array)[SIZE]) {
		const size_type size = SIZE;
		if (size != 0 && Allocate(size)) {
			for (size_type i = 0; i < size; i++) {
				(*this)[i] = a_array[i];
			}
		}
		return *this;
	}

	void Swap(size_type i, size_type j) {
		if (i >= GetSize() || j >= GetSize())
			return;

		BSScriptVariable& iVal = ptr->Get(i);
		BSScriptVariable& jVal = ptr->Get(j);

		BSScriptVariable tmp = iVal;
		iVal = jVal;
		jVal = tmp;
	}

	bool Allocate(UInt32 size) {
		ptr.Release();

		VMState * state = g_skyrimVM->GetState();
		UInt32 typeID = BSScript::GetTypeID<value_type>(state);
		return state->AllocateArray(typeID, size, ptr);
	}

private:
	BSScriptArrayPtr ptr;
};
