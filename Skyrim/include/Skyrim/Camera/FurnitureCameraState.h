#pragma once

#include "TESCameraState.h"

/*==============================================================================
class FurnitureCameraState +0000 (_vtbl=010E3140)
0000: class FurnitureCameraState
0000: |   class TESCameraState
0004: |   |   struct BSIntrusiveRefCounted
==============================================================================*/
class FurnitureCameraState : public TESCameraState
{
public:
	FurnitureCameraState();
	virtual ~FurnitureCameraState();

	UInt32	unk10;	// 10
	float	unk14;	// 14
	float	unk18;	// 18
	float	unk1C;	// 1C
	UInt32	unk20;	// 20
	UInt32	unk24;	// 24
	UInt32	unk28;	// 28
	UInt8	unk2C;	// 2C
	UInt8	unk2D;	// 2D
	UInt8	unk2E;	// 2E
	UInt8	pad2F;	// 2F
};
