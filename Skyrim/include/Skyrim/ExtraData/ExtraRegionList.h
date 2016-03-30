#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraRegionList +0000 (_vtbl=01079598)
0000: class ExtraRegionList
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraRegionList : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::RegionList };

	// @override
	virtual UInt32	GetType(void) const override;		// 009048A0 { return 0x00000004; }

	// @members
	UInt32	unk08;
};
