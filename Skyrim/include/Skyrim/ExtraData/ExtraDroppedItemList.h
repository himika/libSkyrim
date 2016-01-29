#pragma once

#include "BSExtraData.h"
#include "../BSCore/BSTList.h"

/*==============================================================================
class ExtraDroppedItemList +0000 (_vtbl=01079A78)
0000: class ExtraDroppedItemList
0000: |   class BSExtraData
==============================================================================*/
// 10
class ExtraDroppedItemList : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::DroppedItemList };

	virtual ~ExtraDroppedItemList();					// 00416BB0

	// @override
	virtual UInt32	GetType(void) const override;		// 004A1200 { return kExtraTypeID; }

	// @members
	BSSimpleList<RefHandle>	handles;	// 08
private:
};
