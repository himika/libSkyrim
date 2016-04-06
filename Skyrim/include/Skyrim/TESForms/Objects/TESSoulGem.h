#pragma once

#include "TESObjectMISC.h"

/*==============================================================================
class TESSoulGem +0000 (_vtbl=0108605C)
0000: class TESSoulGem
0000: |   class TESObjectMISC
0000: |   |   class TESBoundObject
0000: |   |   |   class TESObject
0000: |   |   |   |   class TESForm
0000: |   |   |   |   |   class BaseFormComponent
0020: |   |   class TESFullName
0020: |   |   |   class BaseFormComponent
0028: |   |   class TESModelTextureSwap
0028: |   |   |   class TESModel
0028: |   |   |   |   class BaseFormComponent
0044: |   |   class TESIcon
0044: |   |   |   class TESTexture
0044: |   |   |   |   class BaseFormComponent
004C: |   |   class TESValueForm
004C: |   |   |   class BaseFormComponent
0054: |   |   class TESWeightForm
0054: |   |   |   class BaseFormComponent
005C: |   |   class BGSDestructibleObjectForm
005C: |   |   |   class BaseFormComponent
0064: |   |   class BGSMessageIcon
0064: |   |   |   class BaseFormComponent
0070: |   |   class BGSPickupPutdownSounds
0070: |   |   |   class BaseFormComponent
007C: |   |   class BGSKeywordForm
007C: |   |   |   class BaseFormComponent
==============================================================================*/
// 90
class TESSoulGem : public TESObjectMISC
{
public:
	enum { kTypeID = (UInt32)FormType::SoulGem };

	// @members
	UInt32	unk88;		// 88
	UInt8	soulSize;	// 8C
	UInt8	gemSize;	// 8D
	UInt8	pad8E[2];	// 8E
};
STATIC_ASSERT(sizeof(TESSoulGem) == 0x90);
