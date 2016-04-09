#pragma once

#include "../BSCore/BSTArray.h"


/*==============================================================================
class BSMaterialObject +0000 (_vtbl=0108D268)
0000: class BSMaterialObject
==============================================================================*/
// 40
class BSMaterialObject
{
	CLASS_SIZE_ASSERT(0x40)

public:
	// 30
	struct Data
	{
		// 0C
		struct Data10
		{
			UInt32	unk0;	// 0 - init'd to 0
			UInt32	unk4;	// 4 - init'd to 0
			float	unk8;	// 8 - init'd to -1
		};

		float	unk00;	// 00 - init'd to 0.4
		float	unk04;	// 04 - init'd to 0.4
		float	unk08;	// 08 - init'd to 512
		float	unk0C;	// 0C - init'd to 512
		Data10	unk10;	// 10
		float	unk1C;	// 1C - init'd to 1
		UInt32	unk20;	// 20
		UInt32	unk24;	// 24
		UInt32	unk28;	// 28
		UInt32	unk2C;	// 2C
	};

	BSMaterialObject();
	virtual ~BSMaterialObject();

	virtual void	Unk_01(void);


	// @members
	//void				** _vtbl;	// 00
	Data				unk04;	// 04
	BSTArray<void *>	unk34;	// 34
};
