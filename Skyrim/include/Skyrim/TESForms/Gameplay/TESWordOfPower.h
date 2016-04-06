#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/TESFullName.h"

/*==============================================================================
class TESWordOfPower +0000 (_vtbl=010A19E4)
0000: class TESWordOfPower
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
==============================================================================*/
//20 
class TESWordOfPower : public TESForm,
	public TESFullName				// 14
{
public:
	enum { kTypeID = (UInt32)FormType::WordOfPower };

	// @members
	BSFixedString	word;		// 1C
};
STATIC_ASSERT(sizeof(TESWordOfPower) == 0x20);
