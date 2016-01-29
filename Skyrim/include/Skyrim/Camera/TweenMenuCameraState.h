#pragma once

#include "TESCameraState.h"

/*==============================================================================
class TweenMenuCameraState +0000 (_vtbl=010E368C)
0000: class TweenMenuCameraState
0000: |   class TESCameraState
0004: |   |   struct BSIntrusiveRefCounted
==============================================================================*/
// 40
class TweenMenuCameraState : public TESCameraState
{
public:
	TweenMenuCameraState();
	virtual ~TweenMenuCameraState();

	UInt32	unk10[0x0B];	// 10
	UInt8	unk3C;			// 3C
	UInt8	pad3D;			// 3D
	UInt16	pad3E;			// 3E

private:
	DEFINE_MEMBER_FN(ctor, TweenMenuCameraState*, 0x00840FF0, TESCamera *camera, UInt32 stateId);
};

