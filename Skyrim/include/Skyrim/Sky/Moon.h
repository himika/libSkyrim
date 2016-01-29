#pragma once

#include "SkyObject.h"

/*==============================================================================
class Moon +0000 (_vtbl=010A8040)
0000: class Moon
0000: |   class SkyObject
==============================================================================*/
class Moon : public SkyObject
{
public:
	virtual ~Moon();										// 0058DC30

	// @override class SkyObject : (vtbl=010A8040)
	virtual void	Unk_02(void) override;					// 0058DF90
	virtual void	Unk_03(UInt32, UInt32) override;		// 0058D6D0
};
