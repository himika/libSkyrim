#pragma once

#include "../BSCore/BSTArray.h"

// 30
class BSIMusicType
{
public:
	virtual void	BSIMusicType_Unk_00(void);
	virtual void	BSIMusicType_Unk_01(void);
	virtual void	BSIMusicType_Unk_02(void);
	virtual void	BSIMusicType_Unk_03(void);
	virtual void	BSIMusicType_Unk_04(void);
	virtual void	BSIMusicType_Unk_05(void);
	virtual void	BSIMusicType_Unk_06(void);
	virtual void	BSIMusicType_Unk_07(void);

	//void		** _vtbl;	// 00
	UInt32		unk04;		// 04
	UInt8		unk08;		// 08
	UInt8		unk09;		// 09
	UInt16		unk0A;		// 0A
	float		unk0C;		// 0C
	UInt32		unk10;		// 10
	BSTArray<void*>	unk14;	// 14
	BSTArray<void*>	unk20;	// 20
	UInt32		unk2C;		// 2C
};
