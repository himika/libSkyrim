#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../BSCore/BSFixedString.h"


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

	BSFixedString	labelParentMale;		// 14
	BSFixedString	labelParentFemale;		// 18
	BSFixedString	labelChildMale;			// 1C
	BSFixedString	labelChildFemale;		// 20
	UInt32			unk24;					// 24 - family assosiation ?
};
STATIC_ASSERT(sizeof(BGSAssociationType) == 0x28);
