#pragma once

#include "TESCameraState.h"

/*==============================================================================
class PlayerCameraTransitionState +0000 (_vtbl=010E321C)
0000: class PlayerCameraTransitionState
0000: |   class TESCameraState
0004: |   |   struct BSIntrusiveRefCounted
==============================================================================*/
// 28
class PlayerCameraTransitionState : public TESCameraState
{
public:
	PlayerCameraTransitionState();
	virtual ~PlayerCameraTransitionState();

	UInt32	unk10;			// 10 - init'd 0
	UInt32	unk14;			// 14 - init'd 0
	UInt32	unk18;			// 18 - init'd 0
	UInt32	unk1C;			// 1C - init'd 0
	UInt32	unk20;			// 20 - init'd 0
	UInt8	unk24;			// 24 - init'd 0
	UInt8	unk25;			// 25 - init'd 0
};
