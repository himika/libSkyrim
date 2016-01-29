#pragma once

#include "ThirdPersonState.h"

/*==============================================================================
class DragonCameraState +0000 (_vtbl=010E2A4C)
0000: class DragonCameraState
0000: |   class ThirdPersonState
0000: |   |   class TESCameraState
0004: |   |   |   struct BSIntrusiveRefCounted
0010: |   |   class PlayerInputHandler
==============================================================================*/
class DragonCameraState : public ThirdPersonState
{
public:
	DragonCameraState();
	virtual ~DragonCameraState();
};

