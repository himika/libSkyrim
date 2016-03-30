#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraDetachTime +0000 (_vtbl=01079608)
0000: class ExtraDetachTime
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraDetachTime : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::DetachTime };

	// @override
	virtual UInt32	GetType(void) const override;		// 0055BB40 { return 0x0000000A; }

	// @members
	UInt32	unk08;			// 08
};
