#pragma once

#include <new>

class Heap
{
public:
	// haven't verified alignment vars
	DEFINE_MEMBER_FN(Allocate, void *, 0x00A48D60, UInt32 size, UInt32 alignment, bool aligned);
	DEFINE_MEMBER_FN(Free, void, 0x00A487B0, void * buf, bool aligned);
	
	DEFINE_MEMBER_FN(Unk00A481C0, void, 0x00A481C0);
};

extern Heap * g_formHeap;

void * FormHeap_Allocate(UInt32 size);
void FormHeap_Free(void * ptr);

template<typename T>
inline T* FormHeap_Allocate(void) {
	//return reinterpret_cast<T*>(g_formHeap->Allocate(sizeof(T), alignon(T), true));
	return reinterpret_cast<T*>(FormHeap_Allocate(sizeof(T)));
}

#define TES_FORMHEAP_REDEFINE_NEW()											\
	static void * operator new(std::size_t size)							\
	{ return FormHeap_Allocate(size); }										\
	static void * operator new(std::size_t size, const std::nothrow_t &)	\
	{ return FormHeap_Allocate(size); }										\
	static void * operator new(std::size_t size, void * ptr)				\
	{ return ptr; }															\
	static void operator delete(void * ptr)									\
	{ FormHeap_Free(ptr); }													\
	static void operator delete(void * ptr, const std::nothrow_t &)			\
	{ FormHeap_Free(ptr); }													\
	static void operator delete(void *, void *)								\
	{ }
