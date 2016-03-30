#include "Skyrim.h"
#include "Skyrim/BSCore/BSSpinLock.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

enum
{
	kFastSpinThreshold = 10000
};


void BSSpinLock::Lock(void)
{
	long myThreadID = GetCurrentThreadId();
	if (threadID == myThreadID) {
		lockCount++;
		return;
	}

	UInt32 spinCount = 0;
	while (InterlockedCompareExchange(&threadID, myThreadID, 0))
		Sleep(++spinCount > kFastSpinThreshold);

	lockCount = 1;
}

void BSSpinLock::Lock(const char *owner)
{
	long myThreadID = GetCurrentThreadId();
	if (threadID == myThreadID) {
		lockCount++;
		return;
	}

	UInt32 spinCount = 0;
	while (InterlockedCompareExchange(&threadID, myThreadID, 0))
		Sleep(++spinCount > kFastSpinThreshold);

	lockCount = 1;
}

bool BSSpinLock::TryToLock(void)
{
	long myThreadID = GetCurrentThreadId();
	if (threadID == myThreadID) {
		lockCount++;
		return true;
	}

	if (InterlockedCompareExchange(&threadID, myThreadID, 0))
		return false;

	lockCount = 1;
	return true;
}

void BSSpinLock::Unlock(void)
{
	if (--lockCount == 0)
		InterlockedCompareExchange(&threadID, 0, threadID);
}

