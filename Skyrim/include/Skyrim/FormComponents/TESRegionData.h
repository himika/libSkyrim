#pragma once

// 08
class TESRegionData
{
public:
	virtual ~TESRegionData();

	virtual void	TESRegionData_Unk_01(void);
	virtual void	TESRegionData_Unk_02(void);
	virtual SInt32	GetType(void); // pure
	virtual void	TESRegionData_Unk_04(void); // pure - Init?
	virtual void	TESRegionData_Unk_05(void); // pure
	virtual void	TESRegionData_Unk_06(void); // pure
	virtual void	TESRegionData_Unk_07(void); // pure

	UInt8	unk04;	// 04
	UInt8	unk05;	// 05
	UInt8	unk06;	// 06
	UInt8	pad07;	// 07
};
