#pragma once

#include "../BSCore/BSTSingleton.h"
#include "../BSCore/BSTArray.h"
#include "../BSCore/BSTHashMap.h"

// 4
class BSNavmeshInfoMap : public BSTSingletonExplicit<BSNavmeshInfoMap>
{
public:
	virtual ~BSNavmeshInfoMap();			// 00B582F0

	virtual void	BSNavmeshInfoMap_Unk_01(void) = 0;		// 00F51EE8 (pure)
	virtual void	BSNavmeshInfoMap_Unk_02(void) = 0;		// 00F51EE8 (pure)
	virtual void	BSNavmeshInfoMap_Unk_03(void) = 0;		// 00F51EE8 (pure)
	virtual void	BSNavmeshInfoMap_Unk_04(void) = 0;		// 00F51EE8 (pure)
	virtual void	BSNavmeshInfoMap_Unk_05(void) = 0;		// 00F51EE8 (pure)

	// @members
	//void	** _vtbl;	// 00 - 01121994

private:
	DEFINE_MEMBER_FN(ctor, BSNavmeshInfoMap *, 0x00B57E60)
};
STATIC_ASSERT(sizeof(BSNavmeshInfoMap) == 0x4);


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
