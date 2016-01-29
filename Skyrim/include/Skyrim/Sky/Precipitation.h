#pragma once

#include "SkyObject.h"

/*==============================================================================
class Precipitation +0000 (_vtbl=010A80DC)
0000: class Precipitation
==============================================================================*/
// 1C
class Precipitation : public SkyObject
{
public:
	virtual ~Precipitation();			// 0058E900

	UInt32	unk08;	// 08
	float	unk0C;	// 0C
	float	unk10;	// 10
	float	unk14;	// 14
	float	unk18;	// 18
};
STATIC_ASSERT(sizeof(Precipitation) == 0x1C);
