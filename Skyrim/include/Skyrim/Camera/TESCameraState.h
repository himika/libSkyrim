#pragma once

#include "../BSSystem/BSTSmartPointer.h"

class TESCamera;

/*==============================================================================
class TESCameraState +0000 (_vtbl=0107F5A0)
0000: class TESCameraState
0004: |   struct BSIntrusiveRefCounted
==============================================================================*/
class TESCameraState : public BSIntrusiveRefCounted
{
public:
	typedef BSTSmartPointer<TESCameraState> SmartPtr;

	TESCameraState();
	virtual ~TESCameraState();

	virtual void OnStateStart();	// pure
	virtual void OnStateEnd();		// pure
	virtual void OnUpdate(void * unk1);
	virtual void Unk_04();
	virtual void Unk_05();
	virtual void Unk_06();			// pure
	virtual void Unk_07();			// pure
	virtual void Unk_08();			// pure

	TESCamera				* camera;		// 08
	UInt32					stateId;		// 0C
};
