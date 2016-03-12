#include "Skyrim.h"
#include "Skyrim/BSScript/BSScriptObject.h"
#include "Skyrim/BSScript/BSScriptClass.h"
#include "Skyrim/BSScript/BSScriptVariable.h"
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
	SkyrimScript::HandlePolicy *& BSScriptObject::ms_handlePolicy = *(SkyrimScript::HandlePolicy**)0x01BA7008;


	BSScriptObject::BSScriptObject(const BSScriptClassPtr &a_classPtr, SkyrimScript::HandlePolicy *a_handlePolicy, UInt32 a_numProperties)	// 0x00C30DF0
	{
		flags = 4;
		numProperties = a_numProperties;

		classPtr = a_classPtr;

		static BSFixedString defaultState = "";
		currentState = defaultState;

		//unk0C = nullptr;

		handle = a_handlePolicy->GetInvalidHandle();
		
		ms_handlePolicy = a_handlePolicy;
	}

	// called from 00C589E5, 00C58B61
	BSScriptObject::~BSScriptObject()		// 00C30E90
	{
		if (flags & kFlag_HasVariables)
		{
			UInt32 numVars = classPtr->GetNumAllVariables();
			BSScriptVariable *pVar = GetVariables();
			while (numVars)
			{
				pVar->~BSScriptVariable();
				--numVars;
			}
		}

		flags = 0;

		if (unk0C.GetFlag())
		{
			InterlockedDecrement(unk0C);
		}
	}

	VMHandle BSScriptObject::GetHandle(void) const		// 00C307C0
	{
		VMHandle result = ms_handlePolicy->GetInvalidHandle();

		BSScriptObject* pThis = const_cast<BSScriptObject *>(this);

		SInt32	oldLock = pThis->Lock();
		result = pThis->handle;
		pThis->Unlock(oldLock);

		return result;
	}

	void BSScriptObject::SetHandle(VMHandle a_handle)	// 00C307C0
	{
		SInt32	oldLock = Lock();

		ms_handlePolicy->AddRef(a_handle);
		ms_handlePolicy->Release(handle);
		handle = a_handle;

		Unlock(oldLock);
	}

	bool BSScriptObject::IsInvalidHandle() const
	{
		return GetHandle() == ms_handlePolicy->GetInvalidHandle();
	}

	void BSScriptObject::GetClass(BSScriptClassPtr &a_classPtr) const		// 00505F30
	{
		a_classPtr = classPtr;
	}

	void * BSScriptObject::Resolve(UInt32 typeID) const
	{
		void *result = nullptr;
		
		VMHandle handle = GetHandle();
		auto policy = ms_handlePolicy;
		if (policy->IsType(typeID, handle) && policy->IsValidHandle(handle))
			result = policy->Resolve(typeID, handle);

		return result;
	}

	SInt32 BSScriptObject::Lock(void)	// 00C30720
	{
		UInt32	spinCount = 0;
		SInt32	lockValue;

		while (true)
		{
			lockValue = refCount;

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
				if (InterlockedCompareExchange(&refCount, lockValue | kLockBit, lockValue) == lockValue)
					break;
			}
		}

		return lockValue;
	}

	void BSScriptObject::Unlock(SInt32 oldLock)
	{
		refCount = oldLock;
	}

	// try to increment the lock
	// on 1 -> 2, call IObjectHandlePolicy::AddRef(handle) with the lock held
	void BSScriptObject::IncRefCount(void)		// 00C306A0
	{
		UInt32	spinCount = 0;

		while (true)
		{
			SInt32	lockValue = refCount;

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
					if (InterlockedCompareExchange(&refCount, lockValue | kLockBit, lockValue) == lockValue)
					{
						ms_handlePolicy->AddRef(handle);
						refCount = 2;
						break;
					}
				}
				else
				{
					if (InterlockedCompareExchange(&refCount, lockValue + 1, lockValue) == lockValue)
						break;
				}
			}
		}
	}

	// try to decrement the lock
	// on 2 -> 1, call IObjectHandlePolicy::Release(handle) with the lock held
	SInt32 BSScriptObject::DecRefCount(void)		// 00C30720
	{
		UInt32	spinCount = 0;

		while (true)
		{
			SInt32	lockValue = refCount;

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
					if (InterlockedCompareExchange(&refCount, lockValue | kLockBit, lockValue) == lockValue)
					{
						ms_handlePolicy->Release(handle);
						refCount = 1;
						return 1;
					}
				}
				else
				{
					if (InterlockedCompareExchange(&refCount, lockValue - 1, lockValue) == lockValue)
						return lockValue - 1;
				}
			}
		}
	}
}
