#pragma once

#include "../BSCore/BSTSingleton.h"
#include "../BSCore/BSTArray.h"
#include "../BSCore/BSTHashMap.h"

// 2C
class BSPrecomputedNavmeshInfoPathMap : public BSTSingletonExplicit<BSPrecomputedNavmeshInfoPathMap>
{
public:
	// @members
	BSTArray<BSTArray<void*> *>	unk00;	// 00
	BSTHashMap<UInt32, void *>	unk0C;	// 0C

private:
	DEFINE_MEMBER_FN(ctor, BSPrecomputedNavmeshInfoPathMap *, 0x00B57830)
};
STATIC_ASSERT(sizeof(BSPrecomputedNavmeshInfoPathMap) == 0x2C);
