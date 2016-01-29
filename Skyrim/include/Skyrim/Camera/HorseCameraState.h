#pragma once

#include "ThirdPersonState.h"

/*==============================================================================
class HorseCameraState +0000 (_vtbl=010E2F6C)
0000: class HorseCameraState
0000: |   class ThirdPersonState
0000: |   |   class TESCameraState
0004: |   |   |   struct BSIntrusiveRefCounted
0010: |   |   class PlayerInputHandler
==============================================================================*/
class HorseCameraState : public ThirdPersonState
{
public:
	HorseCameraState();
	virtual ~HorseCameraState();
};
