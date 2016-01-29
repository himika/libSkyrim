#pragma once

#include "TESForm.h"
#include "../NetImmerse/NiInterpolators.h"
#include "../BSCore/BSString.h"

/*==============================================================================
class TESImageSpaceModifier +0000 (_vtbl=01087484)
0000: class TESImageSpaceModifier
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 72C
class TESImageSpaceModifier : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::ImageSpaceMod };

	// 0F4
	struct Data014
	{
		// 8
		struct Data0CC
		{
			float	unk0;
			float	unk4;
		};

		UInt8	unk000;		// 000
		UInt8	pad001[3];	// 001
		float	unk004;		// 004
		// 008

		UInt8	todo008[0xC8 - 0x08];	// 008

		UInt8	unk0C8;		// 0C8
		UInt8	unk0C9[3];	// 0C9
		Data0CC	unk0CC;		// 0CC
		// 0D4

		UInt8	todo0D4[0xE0 - 0xD4];	// 0D4

		UInt8	unk0E0;		// 0E0
		UInt8	unk0E1;		// 0E1
		UInt8	pad0E2[2];	// 0E2
		// 0E4

		UInt8	todo0E4[0xF4 - 0xE4];	// 0E4
	};

	Data014				unk014;				// 014
	NiFloatInterpolator	unk108[0x15 * 2];	// 108
	NiFloatInterpolator	unk4F8;				// 4F8
	NiFloatInterpolator	unk510;				// 510
	NiColorInterpolator	unk528;				// 528
	NiColorInterpolator	unk54C;				// 54C
	NiFloatInterpolator	unk570;				// 570
	NiFloatInterpolator	unk588;				// 588
	NiFloatInterpolator	unk5A0;				// 5A0
	NiFloatInterpolator	unk5B8;				// 5B8
	NiFloatInterpolator	unk5D0;				// 5D0
	NiFloatInterpolator	unk5E8;				// 5E8
	NiFloatInterpolator	unk600;				// 600
	NiFloatInterpolator	unk618;				// 618
	NiFloatInterpolator	unk630;				// 630
	// 648

	UInt8				todo648[0x724 - 0x648];	// 348

	BSString			unk724;				// 724
};
STATIC_ASSERT(offsetof(TESImageSpaceModifier, unk108) == 0x108);
STATIC_ASSERT(offsetof(TESImageSpaceModifier, unk4F8) == 0x4F8);
STATIC_ASSERT(sizeof(TESImageSpaceModifier) == 0x72C);
