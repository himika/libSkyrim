#pragma once


/*==============================================================================
class BSIMusicTrack +0000 (_vtbl=0108D9BC)
0000: class BSIMusicTrack
==============================================================================*/
// 08
class BSIMusicTrack
{
public:
	BSIMusicTrack();
	virtual ~BSIMusicTrack();

	virtual void	BSIMusicTrack_Unk_01(void) = 0;
	virtual void	BSIMusicTrack_Unk_02(void) = 0;
	virtual void	BSIMusicTrack_Unk_03(void) = 0;
	virtual void	BSIMusicTrack_Unk_04(void) = 0;
	virtual void	BSIMusicTrack_Unk_05(void) = 0;
	virtual void	BSIMusicTrack_Unk_06(void) = 0;
	virtual bool	BSIMusicTrack_Unk_07(void);				// 009B86F0 { return true; }
	virtual UInt32	BSIMusicTrack_Unk_08(void);				// 004F8CA0 { return (UInt32)unk4; }
	virtual void	BSIMusicTrack_Unk_09(UInt32 arg);		// 00588F30 { return; }
	virtual void	BSIMusicTrack_Unk_0A(void);				// 006C50E0 { return; }

	// @members
	//void	** _vtbl;	// 00
	UInt32	unk04;		// 04
};
