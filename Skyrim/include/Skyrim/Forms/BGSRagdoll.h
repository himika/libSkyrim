#pragma once

#include "TESForm.h"
#include "../FormComponents/TESModel.h"
#include "../BSCore/BSString.h"
#include "../BSCore/BSTArray.h"

/*==============================================================================
class BGSRagdoll +0000 (_vtbl=010A394C)
0000: class BGSRagdoll
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESModel
0014: |   |   class BaseFormComponent
==============================================================================*/
// 124
class BGSRagdoll : public TESForm,
	public TESModel
{
public:
	enum { kTypeID = (UInt32)FormType::Ragdoll };

	// @members

	// 4C
	struct Data38
	{
		// 3C
		struct Data
		{
			float	unk00;	// 00 - init'd to .9
			float	unk04;	// 04 - init'd to .8
			float	unk08;	// 08 - init'd to .4
			float	unk0C;	// 0C - init'd to .2
			float	unk10;	// 10 - init'd to .1
			float	unk14;	// 14 - init'd to .3
			float	unk18;	// 18 - init'd to 0
			float	unk1C;	// 1C - init'd to 50
			float	unk20;	// 20 - init'd to 50
			float	unk24;	// 24 - init'd to 25
			float	unk28;	// 28 - init'd to 25
			float	unk2C;	// 2C - init'd to 50
			float	unk30;	// 30 - init'd to 50
			UInt32	unk34;	// 34 - init'd to 10000
			UInt32	unk38;	// 38 - init'd to 30000
		};

		UInt8						unk00;		// 00
		UInt8						pad01[3];	// 01
		Data						unk04;		// 04
		BSTArray<void*>				unk40;		// 40
	};

	// 38
	struct Data84
	{
		// 1C
		struct Data
		{
			UInt32	unk00;	// 00
			UInt32	unk04;	// 04
			UInt32	unk08;	// 08
			UInt32	unk0C;	// 0C
			UInt32	unk10;	// 10
			UInt32	unk14;	// 14
			UInt32	unk18;	// 18
		};

		UInt8						unk00;		// 00
		UInt8						pad01[3];	// 01
		Data						unk04;		// 04
		BSTArray<void*>				unk20;		// 20
		BSTArray<void*>				unk2C;		// 2C
	};

	// 1C
	struct DataBC
	{
		UInt8						unk00;		// 00
		UInt8						pad01[3];	// 01
		BSTArray<void*>				unk04;		// 04
		BSTArray<void*>				unk10;		// 10
	};

	// 24
	struct DataF4
	{
		// 18
		struct Data
		{
			UInt16	unk00;	// 00 - init'd to FFFF
			UInt16	unk02;	// 02 - init'd to FFFF
			UInt16	unk04;	// 04 - init'd to FFFF
			UInt8	unk06;	// 06 - init'd to 0
			UInt8	pad07;	// 07
			UInt32	unk08;	// 08 - init'd to 0
			UInt32	unk0C;	// 0C - init'd to 0
			float	unk10;	// 10 - init'd to 0.1
			UInt32	unk14;	// 14 - init'd to 0
		};

		UInt8		unk00;		// 00
		UInt8		pad01[3];	// 01
		BSString	unk04;		// 04
		Data		unk0C;		// 0C
	};

	UInt8	pad28[0x10];	// 028

	Data38	unk38;			// 038
	Data84	unk84;			// 084
	DataBC	unkBC;			// 0BC
	DataBC	unkD8;			// 0D8
	DataF4	unkF4;			// 0F4
	UInt8	pad118[4];		// 118
	UInt32	unk11C;			// 11C
	UInt32	unk120;			// 120
};
STATIC_ASSERT(sizeof(BGSRagdoll) == 0x124);
