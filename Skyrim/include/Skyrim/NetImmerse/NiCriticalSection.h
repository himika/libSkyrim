#pragma once

class NiCriticalSection
{
public:
	NiCriticalSection() : m_ownerThreadID(0), m_lockCount(0) {}

	void Lock();
	void Unlock();

	UInt32 GetOwningThreadID() const {
		return m_ownerThreadID;
	}
	UInt32 GetCurrentLockCount() const {
		return m_lockCount;
	}

protected:
	unsigned int m_lockCount;
	volatile unsigned long m_ownerThreadID;
};
