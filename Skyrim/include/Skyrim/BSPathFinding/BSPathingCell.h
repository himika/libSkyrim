#pragma once

/*==============================================================================
class BSPathingCell +0000 (_vtbl=010C5E6C)
0000: class BSPathingCell
0004: |   struct BSIntrusiveRefCounted
==============================================================================*/
class BSPathingCell
{
	virtual ~BSPathingCell();		// 0060A820
	virtual void *	Unk_01(void) = 0;
	virtual void	Unk_02(UInt32 arg) = 0;
	virtual void	Unk_03(UInt32 arg) = 0;
	virtual void	Unk_04(UInt32 arg) = 0;
	virtual void	Unk_05(UInt32 arg) = 0;
	virtual UInt32	Unk_06(void) = 0;
	virtual bool	Unk_07(void) = 0;
	virtual bool	Unk_08(void) = 0;
	virtual bool	Unk_09(void) = 0;
	virtual bool	Unk_0A(UInt32 arg) = 0;
};
