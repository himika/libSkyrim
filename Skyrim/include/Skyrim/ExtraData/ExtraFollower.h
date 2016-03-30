#pragma once

#include "BSExtraData.h"
#include "../BSCore/BSTArray.h"

/*==============================================================================
class ExtraFollower +0000 (_vtbl=010799E8)
0000: class ExtraFollower
0000: |   class BSExtraData
==============================================================================*/
// 14
class ExtraFollower : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Follower };

	ExtraFollower();
	virtual ~ExtraFollower();			// 00419230

	// @override
	virtual UInt32	GetType(void) const override;		// 00420B60 { return 0x0000001D; }


	// @members
	BSTArray<RefHandle>	followers;	// 08
};
STATIC_ASSERT(sizeof(ExtraFollower) == 0x14);
