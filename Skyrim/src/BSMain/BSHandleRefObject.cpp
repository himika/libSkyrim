#include "Skyrim/BSMain/BSHandleRefObject.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


BSHandleRefObject::~BSHandleRefObject()
{
	m_uiRefCount &= kMask_RefCount;
	InterlockedDecrement(&ms_uiObjects);
}


void BSHandleRefObject::DecRefCount(void)
{
	if ((InterlockedDecrement(&m_uiRefCount) & kMask_RefCount) == 0)
		DeleteThis();
}
