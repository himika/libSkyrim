#pragma once

#include "TESCameraState.h"


/*==============================================================================
class IronSightsState +0000 (_vtbl=010E3118)
0000: class IronSightsState
0000: |   class TESCameraState
0004: |   |   struct BSIntrusiveRefCounted
==============================================================================*/
class IronSightsState : public TESCameraState
{
public:
	IronSightsState();
	virtual ~IronSightsState();

	UInt32	unk10;	// 10
};
