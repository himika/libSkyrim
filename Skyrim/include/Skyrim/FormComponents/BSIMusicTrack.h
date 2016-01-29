#pragma once

// 08
class BSIMusicTrack
{
public:
	BSIMusicTrack();
	virtual ~BSIMusicTrack();

	virtual void	BSIMusicTrack_Unk_01(void);
	virtual void	BSIMusicTrack_Unk_02(void);
	virtual void	BSIMusicTrack_Unk_03(void);
	virtual void	BSIMusicTrack_Unk_04(void);
	virtual void	BSIMusicTrack_Unk_05(void);
	virtual void	BSIMusicTrack_Unk_06(void);
	virtual bool	BSIMusicTrack_Unk_07(void);
	virtual UInt32	BSIMusicTrack_Unk_08(void);	// return unk04
	virtual void	BSIMusicTrack_Unk_09(UInt32 arg);
	virtual void	BSIMusicTrack_Unk_0A(void);

	//	void	** _vtbl;	// 00
	UInt32	unk04;		// 04
};

