#pragma once

// c:_skyrim\code\tesv\bssystem\BSTSmartPointer.h

#include "../Memory.h"
#include <new>


// 04
struct BSIntrusiveRefCounted
{
public:
	BSIntrusiveRefCounted() : m_refCount(0) { }

	static void * operator new(std::size_t size)
	{ return FormHeap_Allocate(size); }
	static void * operator new(std::size_t size, const std::nothrow_t &)
	{ return FormHeap_Allocate(size); }
	static void * operator new(std::size_t size, void * ptr)
	{ return ptr; }
	static void operator delete(void * ptr)
	{ FormHeap_Free(ptr); }
	static void operator delete(void * ptr, const std::nothrow_t &)
	{ FormHeap_Free(ptr); }
	static void operator delete(void *, void *)
	{ }

protected:
	volatile long	m_refCount;	// 00

	SInt32 IncRefCount(void);
	SInt32 DecRefCount(void);

	template <class Ty>
	friend struct BSTSmartPointerIntrusiveRefCount;
};


template <class Ty>
struct BSTSmartPointerIntrusiveRefCount
{
	typedef Ty *pointer;

	static void Attach(pointer p) {
		p->IncRefCount();
	}
	static void Detach(pointer p) {
		if (p->DecRefCount() == 0) {
			delete p;
		}
	}
};


// 04
template <class Ty, template <class> class RefManager = BSTSmartPointerIntrusiveRefCount>
class BSTSmartPointer
{
public:
	typedef Ty value_type;
	typedef Ty * pointer;
	typedef const Ty *const_pointer;
	typedef RefManager<Ty> reference_manager;
	// typedef Ty &reference;
	// typedef const Ty &const_reference;

	BSTSmartPointer() : ptr(nullptr) {
	}
	BSTSmartPointer(const BSTSmartPointer & a_p) : ptr(nullptr) {
		Attach((const_pointer)a_p);
	}
	BSTSmartPointer(BSTSmartPointer && a_p) {
		ptr = a_p.ptr;
		a_p.ptr = nullptr;
	}
	BSTSmartPointer(const_pointer a_p) : ptr(nullptr) {
		Attach(a_p);
	}

	~BSTSmartPointer() {
		Release();
	}

	operator pointer() {
		return ptr;
	}
	operator const_pointer() const {
		return ptr;
	}

	operator bool() const {
		return ptr != 0;
	}

	BSTSmartPointer & operator=(const pointer a_p) {
		Release();
		Attach(a_p);
		return *this;
	}
	BSTSmartPointer & operator=(const BSTSmartPointer & a_ptr) {
		Release();
		Attach((const_pointer)a_ptr);
		return *this;
	}
	BSTSmartPointer & operator=(BSTSmartPointer && a_p) {
		Release();
		ptr = a_p.ptr;
		a_p.ptr = nullptr;
		return *this;
	}
	pointer Get(void) {
		return ptr;
	}
	const_pointer Get(void) const {
		return ptr;
	}
	pointer operator->() {
		return ptr;
	}
	const_pointer operator->() const {
		return ptr;
	}
	value_type & operator*() {
		return *ptr;
	}
	const value_type & operator*() const {
		return *ptr;
	}
	void Attach(const_pointer a_p) {
		ptr = const_cast<pointer>(a_p);
		if (ptr) {
			reference_manager::Attach(ptr);
		}
	}
	void Release(void) {
		if (ptr) {
			reference_manager::Detach(ptr);
			ptr = nullptr;
		}
	}

protected:
	pointer ptr;
};


#define BSSmartPointer(className)					\
	class className;								\
	typedef BSTSmartPointer<className> className##Ptr;
