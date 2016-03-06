#pragma once

#include "TESCamera.h"

/*==============================================================================
class MapCamera +0000 (_vtbl=010E92F4)
0000: class MapCamera
0000: |   class TESCamera
==============================================================================*/
// 60
class MapCamera : public TESCamera
{
public:
	MapCamera();
	virtual ~MapCamera();

private:
	DEFINE_MEMBER_FN(ctor, MapCamera *, 0x0089CA50);
};
