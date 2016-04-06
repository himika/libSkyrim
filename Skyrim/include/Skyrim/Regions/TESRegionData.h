#pragma once

/*==============================================================================
class TESRegionData +0000 (_vtbl=01080770)
0000: class TESRegionData
==============================================================================*/
// 08
class TESRegionData
{
public:
	virtual ~TESRegionData();							// 0048C220

	virtual void	TESRegionData_Unk_01(void);			// 0048C250
	virtual void	TESRegionData_Unk_02(void);			// 00588F30 { return; }
	virtual SInt32	GetType(void) = 0;					// pure
	virtual void	TESRegionData_Unk_04(void) = 0;		// pure - Init?
	virtual void	TESRegionData_Unk_05(void) = 0;		// pure
	virtual void	TESRegionData_Unk_06(void) = 0;		// pure
	virtual void	TESRegionData_Unk_07(void) = 0;		// pure

	// @members
	UInt8	unk04;	// 04
	UInt8	unk05;	// 05
	UInt8	unk06;	// 06
	UInt8	pad07;	// 07
};
