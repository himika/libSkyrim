#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../BSCore/BSFixedString.h"

/*==============================================================================
class BGSFootstep +0000 (_vtbl=0108CB2C)
0000: class BGSFootstep
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 1C
class BGSFootstep : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::Footstep };

	// @members
	BSFixedString	unk14;	// 14
	UInt32			unk18;	// 18
};

STATIC_ASSERT(sizeof(BGSFootstep) == 0x1C);
