#include "Skyrim/Scaleform/GRefCount.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

GRefCountImplCore::~GRefCountImplCore()
{
}

void GRefCountImpl::AddRef()
{
	InterlockedIncrement(&RefCount);
}
