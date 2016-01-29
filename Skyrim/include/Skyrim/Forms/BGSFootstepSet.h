#pragma once

#include "TESForm.h"
#include "../BSCore/BSTArray.h"

/*==============================================================================
class BGSFootstepSet +0000 (_vtbl=0108CCAC)
0000: class BGSFootstepSet
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 50
class BGSFootstepSet : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::FootstepSet };

	BSTArray<void*>		unk14[5];	// 14
};
STATIC_ASSERT(sizeof(BGSFootstepSet) == 0x50);
