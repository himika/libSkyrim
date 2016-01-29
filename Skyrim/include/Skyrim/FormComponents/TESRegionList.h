#pragma once

#include "../BSCore/BSTList.h"

class TESRegion;

// 10
class TESRegionList : public BSSimpleList<TESRegion*>
{
public:
	virtual ~TESRegionList();

	//void	** _vtbl	// 00 - 01080904
	UInt32	unk0C;		// 0C
};


