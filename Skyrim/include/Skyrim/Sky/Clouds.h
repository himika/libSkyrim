#pragma once

#include "SkyObject.h"

/*==============================================================================
class Clouds +0000 (_vtbl=010A7FF8)
0000: class Clouds
0000: |   class SkyObject
==============================================================================*/
class Clouds : public SkyObject
{
public:
	virtual ~Clouds();										// 0058D340

	// @override class SkyObject : (vtbl=010A7FF8)
	virtual void	Unk_02(void) override;					// 0058D1A0
	virtual void	Unk_03(UInt32, UInt32) override;		// 0058C7E0
};
