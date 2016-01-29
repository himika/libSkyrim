#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraLeveledItem +0000 (_vtbl=01079288)
0000: class ExtraLeveledItem
0000: |   class BSExtraData
==============================================================================*/
class ExtraLeveledItem : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::LeveledItem };

	// @members
	UInt32		index;
};
