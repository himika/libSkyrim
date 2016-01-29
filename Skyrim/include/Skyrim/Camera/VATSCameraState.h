#pragma once

#include "TESCameraState.h"


/*==============================================================================
class VATSCameraState +0000 (_vtbl=010E3744)
0000: class VATSCameraState
0000: |   class TESCameraState
0004: |   |   struct BSIntrusiveRefCounted
==============================================================================*/
class VATSCameraState : public TESCameraState
{
public:
	VATSCameraState();
	virtual ~VATSCameraState();

	UInt32	unk10[0x03];	// 10
};
