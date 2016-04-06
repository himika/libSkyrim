#pragma once

// 08
class BSSpinLock
{
public:
	BSSpinLock() : threadID(0), lockCount(0) {}

	void Lock(void);				// 00401790
	void Lock(const char *owner);	// 00401710
	bool TryToLock(void);
	void Unlock(void);				// 00401770

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