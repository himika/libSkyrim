#pragma once

#include "../Memory.h"
#include <new>

/*==============================================================================
class NiRefObject +0000 (_vtbl=0107DA20)
0000: class NiRefObject
==============================================================================*/
// 08
class NiRefObject
{
public:
	NiRefObject();
	virtual ~NiRefObject();				// 00AAFFD0

	virtual void	DeleteThis(void);	// 00AB5360 calls virtual dtor

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

	void	IncRefCount(void);
	void	DecRefCount(void);
	bool	Release(void);

	inline UInt32 GetRefCount(void) const
	{
		return m_uiRefCount;
	}

	static UInt32 GetTotalObjectCount(void);

protected:
	//void			** _vtbl;		// 00 - 0107DA20
	volatile long	m_uiRefCount;	// 04

	static volatile long	& ms_uiObjects;
};
