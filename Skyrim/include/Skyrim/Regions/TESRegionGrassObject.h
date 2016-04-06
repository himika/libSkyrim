#pragma once

#include "TESRegionObjectBase.h"

// 0C
class TESRegionGrassObject : public TESRegionObjectBase
{
public:
	virtual ~TESRegionGrassObject();

	virtual void TESRegionGrassObject_Unk_03(void);
	virtual void TESRegionGrassObject_Unk_04(void);
	virtual void TESRegionGrassObject_Unk_05(void);
	virtual void TESRegionGrassObject_Unk_06(void);

	UInt32	unk04;	// 04
	UInt32	unk08;	// 08
};
