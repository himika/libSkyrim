#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraObjectHealth +0000 (_vtbl=010793F8)
0000: class ExtraObjectHealth
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraObjectHealth : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::ObjectHealth };

	// @override
	virtual UInt32	GetType(void) const override;				// 004FB7B0 { return 0x00000055; }

	// @members
	UInt32	unk08;			// 08
};
