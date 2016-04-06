#pragma once

#include "TESRegionData.h"

class TESRegionGrassObjectList;

// 0C
class TESRegionDataGrass : public TESRegionData
{
public:
	virtual ~TESRegionDataGrass();								// 0048C2C0

	// @override
	virtual SInt32	GetType(void);								// 00491870 { return 6; }
	virtual void	TESRegionData_Unk_04(void) override;		// 0048C410
	virtual void	TESRegionData_Unk_05(void) override;		// 0048D350
	virtual void	TESRegionData_Unk_06(void) override;		// 0048C450

	// @add
	virtual void	TESRegionDataGrass_Unk_08(void);			// 0048C300
	virtual TESRegionGrassObjectList *	TESRegionDataGrass_Unk_09(void);	// 005E8920 { return grassObjectList; }


	TESRegionGrassObjectList * grassObjectList;	// 08
};
