#pragma once

#include "../BSCore/BSTList.h"

class TESRegionGrassObject;

// 14
class TESRegionGrassObjectList : public BSSimpleList<TESRegionGrassObject*>
{
public:
	virtual ~TESRegionGrassObjectList();

	UInt32	unk0C;	// 0C
	UInt32	unk10;	// 10
};
