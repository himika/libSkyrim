#pragma once

#include "TESForm.h"
#include "../BSCore/BSFixedString.h"


/*==============================================================================
class BGSAssociationType +0000 (_vtbl=010A1C64)
0000: class BGSAssociationType
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 28
class BGSAssociationType : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::AssociationType };

	BSFixedString	unk14[4];	// 14
	UInt32			unk28;		// 28
};
STATIC_ASSERT(sizeof(BGSAssociationType) == 0x28);
