#pragma once

#include "TESCameraState.h"

/*==============================================================================
class AutoVanityState +0000 (_vtbl=010E30F0)
0000: class AutoVanityState
0000: |   class TESCameraState
0004: |   |   struct BSIntrusiveRefCounted
==============================================================================*/
class AutoVanityState : public TESCameraState
{
public:
	AutoVanityState();
	virtual ~AutoVanityState();
};
