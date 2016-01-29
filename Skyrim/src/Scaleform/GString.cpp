#include "Skyrim/Scaleform/GString.h"
#include "Skyrim/Scaleform/GMemory.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

void GString::Data::AddRef(void)
{
	InterlockedExchangeAdd(&refCount, 1);
}

void GString::Data::Release(void)
{
	if (InterlockedExchangeAdd(&refCount, -1) == 1)
	{
		GFREE(this);
	}
}
