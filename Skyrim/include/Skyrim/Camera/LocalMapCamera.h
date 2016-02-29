#pragma once

#include "TESCamera.h"
#include "TESCameraState.h"

class NiObject;

/*==============================================================================
class LocalMapCamera +0000 (_vtbl=0107F60C)
0000: class LocalMapCamera
0000: |   class TESCamera
==============================================================================*/
class LocalMapCamera : public TESCamera
{
public:
	LocalMapCamera();
	virtual ~LocalMapCamera();

	class DefaultState : public TESCameraState
	{
	public:
		NiPoint3	someBoundMax;		// 10
		NiPoint3	someBoundMin;		// 1C
		float		zoomPercent;		// 28
		float		minFrustumWidth;	// 2C
		float		minFrustumHeight;	// 30
	};

	NiPoint3	areaBoundsMax;			// 28
	NiPoint3	areaBoundsMin;			// 34
	DefaultState	* defaultState;		// 40
	NiObject	* niCamera;				// 44
	float		northRotation;			// 48

	void SetDefaultStateMinFrustumDimensions(float width, float height);
	void SetAreaBounds(NiPoint3 * maxBound, NiPoint3 * minBound);
	void SetDefaultStateMaxBound(NiPoint3 * maxBound);
	void SetDefaultStateBounds(float x, float y, float z);

	DEFINE_MEMBER_FN(SetNorthRotation, void, 0x00486440, float northRotation);
	DEFINE_MEMBER_FN(ctor, LocalMapCamera*, 0x00487420);
};
STATIC_ASSERT(offsetof(LocalMapCamera, northRotation) == 0x48);

extern const float	* g_mapLocalHeight;
extern const float	* g_localMapMinFrustumWidth;
