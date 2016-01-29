#pragma once

class BSSpinLock
{
public:
	BSSpinLock() : threadID(0), lockCount(0) {}

	void Lock(void);
	void Lock(const char *owner);
	void Unlock(void);

	inline void Release(void) { Unlock(); }

private:
	volatile long	threadID;	// 00
	UInt32			lockCount;	// 04
};


class BSSpinLockGuard
{
private:
	BSSpinLock & m_lock;

	BSSpinLockGuard();

public:
	inline BSSpinLockGuard(BSSpinLock &lock) : m_lock(lock) {
		m_lock.Lock();
	}
	inline BSSpinLockGuard(BSSpinLock &lock, const char *owner) : m_lock(lock) {
		m_lock.Lock(owner);
	}

	inline ~BSSpinLockGuard() {
		m_lock.Unlock();
	}
};