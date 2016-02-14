#pragma once

#include "BaseFormComponent.h"
#include "../BSCore/BSTList.h"

class TESFaction;

// 10
class TESReactionForm : public BaseFormComponent
{
public:
	// 0C
	struct RelationData
	{
		TESFaction	* faction;				// 00
		UInt32		modifier;				// 04
		UInt32		groupCombatReaction;	// 08 - Enemy / Friend / Ally
	};

	// @members
	BSSimpleList<RelationData *>	relations;	// 04
	UInt8							unk0C;		// 0C
	UInt8							pad0D[3];	// 0D
};
STATIC_ASSERT(sizeof(TESReactionForm) == 0x10);
