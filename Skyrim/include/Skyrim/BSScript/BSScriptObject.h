#pragma once

#include "../BSCore/BSFixedString.h"
#include "../BSSystem/BSTSmartPointer.h"
#include "BSScriptVariable.h"


namespace BSScript
{
	class BSScriptClass;

	BSSmartPointer(BSScriptObject);

	// the same type as VMIdentifier and VMScriptInstance in skse
	class BSScriptObject : public BSIntrusiveRefCounted
	{
	public:
		typedef BSTSmartPointer<BSScriptObject> SmartPtr;

		~BSScriptObject() {
			dtor();
		}

		VMHandle				GetHandle(void) const;
		BSScriptClass *			GetClass(void)			{ return classInfo; }
		const BSScriptClass *	GetClass(void) const	{ return classInfo; }
		const BSFixedString &	GetState(void) const	{ return currentState; }

	protected:
		SInt32	Lock(void);
		void	Unlock(SInt32 oldLock);

	private:
		BSScriptObject() {}
		DEFINE_MEMBER_FN(dtor, void, 0x00C30E90);

		// @overload BSIntrusiveRefCounted
		void	IncRefCount(void);
		SInt32	DecRefCount(void);

		// @members
		BSScriptClass		* classInfo;	// 04
		BSFixedString		currentState;	// 08
		UInt32				* unk0C;
		volatile VMHandle	handle;			// 10
		volatile long		lock;			// 18

		friend struct BSTSmartPointerIntrusiveRefCount<BSScriptObject>;
	};
}
