#pragma once

#include "SkyObject.h"

/*==============================================================================
class Atmosphere +0000 (_vtbl=010A7FC0)
0000: class Atmosphere
0000: |   class SkyObject
==============================================================================*/
// 1C
class Atmosphere : public SkyObject
{
public:
	virtual ~Atmosphere();									// 0058C320

	// @override
	virtual void	Unk_03(UInt32, UInt32) override;		// 0058BF10

	// @add
	virtual void	Unk_04(void);							// 0058C350

	UInt32	unk08;	// 08
	UInt32	unk0C;	// 0C
	UInt32	unk10;	// 10
	UInt32	unk14;	// 14
	UInt32	unk18;	// 18
};
