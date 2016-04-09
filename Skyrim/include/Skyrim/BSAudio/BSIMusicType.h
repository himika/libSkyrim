#pragma once

#include "../BSCore/BSTArray.h"


/*==============================================================================
class BSIMusicType +0000 (_vtbl=0108DBD0)
0000: class BSIMusicType
==============================================================================*/
// 30
class BSIMusicType
{
public:
	virtual void	BSIMusicType_Unk_00(void) = 0;			// 00
	virtual void	BSIMusicType_Unk_01(void) = 0;			// 01
	virtual void	BSIMusicType_Unk_02(void) = 0;			// 02
	virtual void	BSIMusicType_Unk_03(void) = 0;			// 03
	virtual void	BSIMusicType_Unk_04(UInt32 arg);		// 04 00401000 { return; }
	virtual void	BSIMusicType_Unk_05(void);				// 05 00401010 { return; }
	virtual void	BSIMusicType_Unk_06(void);				// 06 00401010 { return; }

	virtual ~BSIMusicType();								// 07 00401150


	// @members
	//void				** _vtbl;	// 00 - 0108DBD0
	UInt32				unk04;		// 04
	UInt8				unk08;		// 08
	UInt8				unk09;		// 09
	UInt16				unk0A;		// 0A
	float				unk0C;		// 0C
	UInt32				unk10;		// 10
	BSTArray<void *>	unk14;		// 14
	BSTArray<void *>	unk20;		// 20
	UInt32				unk2C;		// 2C
};
