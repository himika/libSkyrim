#pragma once

#include "SkyObject.h"

/*==============================================================================
class Sun +0000 (_vtbl=010A85A0)
0000: class Sun
0000: |   class SkyObject
==============================================================================*/
class Sun : public SkyObject
{
public:
	virtual ~Sun();											// 00597C30

	// @override class SkyObject : (vtbl=010A85A0)
	virtual void	Unk_02(void) override;					// 00597C60
	virtual void	Unk_03(UInt32, UInt32) override;		// 00596FC0
};
