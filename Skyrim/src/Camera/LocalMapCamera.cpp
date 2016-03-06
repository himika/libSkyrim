#include "Skyrim/Camera/LocalMapCamera.h"
#include "Skyrim/BSMain/Setting.h"

const float	* g_mapLocalHeight = *(float **)0x0124166C;
const float	* g_localMapMinFrustumWidth = *(float **)0x012B5B80;


void LocalMapCamera::SetDefaultStateMinFrustumDimensions(float width, float height)
{
	defaultState->minFrustumWidth = width / 2.0;
	defaultState->minFrustumHeight = height / 2.0;
}

void LocalMapCamera::SetAreaBounds(NiPoint3 * maxBound, NiPoint3 * minBound)
{
	areaBoundsMin = *minBound;
	areaBoundsMax = *maxBound;
	areaBoundsMax.z += (*g_mapLocalHeight);
}

void LocalMapCamera::SetDefaultStateMaxBound(NiPoint3 * maxBound)
{
	defaultState->someBoundMax = *maxBound;
	defaultState->someBoundMax.z += (*g_mapLocalHeight);
}

void LocalMapCamera::SetDefaultStateBounds(float x, float y, float z)
{
	defaultState->someBoundMin.x = x - defaultState->someBoundMax.x;
	defaultState->someBoundMin.y = y - defaultState->someBoundMax.y;
	defaultState->someBoundMin.z = z - defaultState->someBoundMax.z;
}
