#pragma once

#include "TESCameraState.h"
#include "../BSDevices/PlayerInputHandler.h"

/*==============================================================================
class FreeCameraState +0000 (_vtbl=010E31F4)
0000: class FreeCameraState
0000: |   class TESCameraState
0004: |   |   struct BSIntrusiveRefCounted
0010: |   class PlayerInputHandler
==============================================================================*/
class FreeCameraState : public TESCameraState,
	public PlayerInputHandler	// 10
{
public:
	FreeCameraState();
	virtual ~FreeCameraState();

	float					unk18;			// 18
	float					unk1C;			// 1C
	float					unk20;			// 20
	UInt32					unk24[0x04];	// 24
	UInt16					unk34;			// 34
	UInt8					unk36;			// 36
	UInt8					unk37;			// 37
};
