#pragma once

#include "../NetImmerse/NiTypes.h"

class NiNode;
class TESCameraState;

class NiCamera;

/*==============================================================================
class TESCamera +0000 (_vtbl=010C87F0)
0000: class TESCamera
==============================================================================*/
// 28
class TESCamera
{
public:
	TESCamera();
	virtual ~TESCamera();						// 00653450

	virtual void SetNode(NiNode * node);		// 00653260
	virtual void Update();						// 00653480

	NiCamera * GetNiCamera() const;

	// @members
	//void			** _vtbl;		// 00 - 010C87F0
	float			rotZ;			// 04
	float			rotX;			// 08
	NiPoint3		pos;			// 0C
	float			zoom;			// 18
	NiNode			* cameraNode;	// 1C - First child is usually NiCamera
	TESCameraState	* cameraState;	// 20
	bool			unk24;			// 24

	DEFINE_MEMBER_FN(SetCameraState, UInt32, 0x006533D0, TESCameraState * cameraState);
};
STATIC_ASSERT(offsetof(TESCamera, cameraNode) == 0x1C);
