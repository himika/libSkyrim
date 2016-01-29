#pragma once

#include "SkyObject.h"


/*==============================================================================
class Stars +0000 (_vtbl=010A8440)
0000: class Stars
0000: |   class SkyObject
==============================================================================*/
// 10
class Stars : public SkyObject
{
public:
	virtual ~Stars();									// 00596B00
	virtual void	Unk_02(void) override;				// 00596450
	virtual void	Unk_03(UInt32, UInt32) override;	// 00596760

	UInt32	unk08;	// 08
	UInt32	unk0C;	// 0C
};
