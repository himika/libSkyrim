#pragma once

#include "TESForm.h"

/*==============================================================================
class BGSReferenceEffect +0000 (_vtbl=01086924)
0000: class BGSReferenceEffect
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 20
class BGSReferenceEffect : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::ReferenceEffect };

	// C
	struct Data
	{
		UInt32	unk0;
		UInt32	unk4;
		UInt32	unk8;
	};

	Data	unk14;
};
STATIC_ASSERT(sizeof(BGSReferenceEffect) == 0x20);
