#pragma once

#include "BGSKeyword.h"


/*==============================================================================
class BGSAction +0000 (_vtbl=010A1B24)
0000: class BGSAction
0000: |   class BGSKeyword
0000: |   |   class TESForm
0000: |   |   |   class BaseFormComponent
==============================================================================*/
// 20
class BGSAction : public BGSKeyword
{
public:
	enum { kTypeID = (UInt32)FormType::Action };

	// @members
	UInt32	idx;	// 1C - ctor sets to a unique value
};
STATIC_ASSERT(sizeof(BGSAction) == 0x20);
