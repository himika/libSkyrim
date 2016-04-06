#pragma once

#include "../Character/BGSKeyword.h"

/*==============================================================================
class BGSLocationRefType +0000 (_vtbl=010867DC)
0000: class BGSLocationRefType
0000: |   class BGSKeyword
0000: |   |   class TESForm
0000: |   |   |   class BaseFormComponent
==============================================================================*/
// 1C
class BGSLocationRefType : public BGSKeyword
{
public:
	enum { kTypeID = (UInt32)FormType::LocationRef };
};
STATIC_ASSERT(sizeof(BGSLocationRefType) == 0x1C);
