#include "Skyrim/NetImmerse/NiRefObject.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

volatile long& NiRefObject::ms_uiObjects = *(volatile long*)0x01B91294;

NiRefObject::NiRefObject()
{
	m_uiRefCount = 0;
	InterlockedIncrement(&ms_uiObjects);
}

NiRefObject::~NiRefObject()
{
	InterlockedDecrement(&ms_uiObjects);
}

void NiRefObject::DeleteThis(void)
{
	if (this)
	{
		delete this;
	}
}


void NiRefObject::IncRefCount(void)
{
	InterlockedIncrement(&m_uiRefCount);
}

bool NiRefObject::Release(void)
{
	return InterlockedDecrement(&m_uiRefCount) == 0;
}

void NiRefObject::DecRefCount(void)
{
	if (Release())
		DeleteThis();
}

UInt32 NiRefObject::GetTotalObjectCount(void)
{
	return ms_uiObjects;
}
