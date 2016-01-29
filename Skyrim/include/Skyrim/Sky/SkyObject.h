#pragma once

/*==============================================================================
class SkyObject +0000 (_vtbl=010A8428)
0000: class SkyObject
==============================================================================*/
class SkyObject
{
public:
	virtual ~SkyObject();								// 00596420

	virtual UInt32	Unk_01(void);						// 004F8CA0 { return (UInt32)unk4; }
	virtual void	Unk_02(void);						// 00596390
	virtual void	Unk_03(UInt32, UInt32);				// 004D43E0 { return; }

	// @members
	//void	** _vtbl;	// 00 - 010A8428
	UInt32	unk04;		// 04
};
