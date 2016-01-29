#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraAshPileRef +0000 (_vtbl=01079948)
0000: class ExtraAshPileRef
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraAshPileRef : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::AshPileRef };

	// @members
	RefHandle	refHandle;	// 08
};
