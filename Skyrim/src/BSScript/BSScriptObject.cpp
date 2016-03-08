#include "Skyrim.h"
#include "Skyrim/BSScript/BSScriptObject.h"
#include "Skyrim/BSScript/BSScriptClass.h"
#include "Skyrim/SkyrimScript.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


enum
{
	kLockBit = 0x80000000,
	kFastSpinThreshold = 10000
};


namespace BSScript
{
	VMHandle BSScriptObject::GetHandle(void) const
	{
		VMHandle result = g_objectHandlePolicy->GetInvalidHandle();

		BSScriptObject* unconst_this = const_cast<BSScriptObject*>(this);

		SInt32	oldLock = unconst_this->Lock();
		result = unconst_this->handle;
		unconst_this->Unlock(oldLock);

		return result;
	}

	SInt32 BSScriptObject::Lock(void)	// 00C30720
	{
		UInt32	spinCount = 0;
		SInt32	lockValue;

		while (true)
		{
			lockValue = lock;

			if (lockValue & kLockBit)
			{
				// someone else is holding the lock, sleep
				if (spinCount <= kFastSpinThreshold)
				{
					Sleep(0);
					spinCount++;
				}
				else
				{
					Sleep(1);
				}
			}
			else
			{
				// try to take the lock
				if (InterlockedCompareExchange(&lock, lockValue | kLockBit, lockValue) == lockValue)
					break;
			}
		}

		return lockValue;
	}

	void BSScriptObject::Unlock(SInt32 oldLock)
	{
		lock = oldLock;
	}

	// try to increment the lock
	// on 1 -> 2, call IObjectHandlePolicy::Unk_09(handle) with the lock held
	void BSScriptObject::IncRefCount(void)
	{
		UInt32	spinCount = 0;

		while (true)
		{
			SInt32	lockValue = lock;

			if (lockValue & kLockBit)
			{
				if (spinCount <= kFastSpinThreshold)
				{
					Sleep(0);
					spinCount++;
				}
				else
				{
					Sleep(1);
				}
			}
			else
			{
				if (lockValue == 1)
				{
					if (InterlockedCompareExchange(&lock, lockValue | kLockBit, lockValue) == lockValue)
					{
						g_objectHandlePolicy->AddRef(handle);
						lock = 2;
						break;
					}
				}
				else
				{
					if (InterlockedCompareExchange(&lock, lockValue + 1, lockValue) == lockValue)
						break;
				}
			}
		}
	}

	// try to decrement the lock
	// on 2 -> 1, call IObjectHandlePolicy::Unk_0A(handle) with the lock held
	SInt32 BSScriptObject::DecRefCount(void)
	{
		UInt32	spinCount = 0;

		while (true)
		{
			SInt32	lockValue = lock;

			if (lockValue & kLockBit)
			{
				if (spinCount <= kFastSpinThreshold)
				{
					Sleep(0);
					spinCount++;
				}
				else
				{
					Sleep(1);
				}
			}
			else
			{
				if (lockValue == 2)
				{
					if (InterlockedCompareExchange(&lock, lockValue | kLockBit, lockValue) == lockValue)
					{
						g_objectHandlePolicy->Release(handle);
						lock = 1;
						return 1;
					}
				}
				else
				{
					if (InterlockedCompareExchange(&lock, lockValue - 1, lockValue) == lockValue)
						return lockValue - 1;
				}
			}
		}
	}
}

