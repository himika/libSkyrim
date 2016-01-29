#pragma once

#include "TESCameraState.h"

/*==============================================================================
class BleedoutCameraState +0000 (_vtbl=010E3184)
0000: class BleedoutCameraState
0000: |   class ThirdPersonState
0000: |   |   class TESCameraState
0004: |   |   |   struct BSIntrusiveRefCounted
0010: |   |   class PlayerInputHandler
==============================================================================*/
class BleedoutCameraState : public ThirdPersonState
{
public:
	BleedoutCameraState();
	virtual ~BleedoutCameraState();
};
