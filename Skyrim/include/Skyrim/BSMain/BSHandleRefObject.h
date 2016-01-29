#pragma once

#include "../NetImmerse/NiRefObject.h"

/*==============================================================================
class BSHandleRefObject +0000 (_vtbl=01088C14)
0000: class BSHandleRefObject
0000: |   class NiRefObject
==============================================================================*/
// 08
class BSHandleRefObject : public NiRefObject
{
public:
	virtual ~BSHandleRefObject();		// 004D6D70

	//"BSHandleRefObject - DecRefCount called with refcount already 0."
	//"c:\projects\sbailey_buildfarm09\tesv\current\bsmain\BSHandleRefObject.inl"

	enum
	{
		kMask_RefCount = 0x3FF
	};

	// overload
	void DecRefCount(void);
	inline UInt32 GetRefCount(void) const
	{
		return m_uiRefCount & kMask_RefCount;
	}

	// @members
	//void	** _vtbl;		// 00 - 01088C14
};
