#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraItemDropper +0000 (_vtbl=01079958)
0000: class ExtraItemDropper
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraItemDropper : BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::ItemDropper };

	// @members
	RefHandle	handle;		// 08
};
