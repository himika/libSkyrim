#include "Skyrim.h"
#include "Skyrim/NetImmerse/NiCriticalSection.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

enum
{
	kFastSpinThreshold = 10000
};


void NiCriticalSection::Lock(void)
{
	long myThreadID = GetCurrentThreadId();
	if (m_ownerThreadID == myThreadID) {
		m_lockCount++;
		return;
	}

	UInt32 spinCount = 0;
	while (InterlockedCompareExchange(&m_ownerThreadID, myThreadID, 0))
		Sleep(++spinCount > kFastSpinThreshold);

	m_lockCount = 1;
}

void NiCriticalSection::Unlock(void)
{
	if (--m_lockCount == 0)
		InterlockedCompareExchange(&m_ownerThreadID, 0, m_ownerThreadID);
}
