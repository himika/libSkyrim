#pragma once

#include "TESForm.h"
#include "../FormComponents/TESIcon.h"

/*==============================================================================
class BGSMenuIcon +0000 (_vtbl=0108D504)
0000: class BGSMenuIcon
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESIcon
0014: |   |   class TESTexture
0014: |   |   |   class BaseFormComponent
==============================================================================*/
// 1C
class BGSMenuIcon : public TESForm,
	public TESIcon		// 14
{
public:
	enum { kTypeID = (UInt32)FormType::MenuIcon };

};
STATIC_ASSERT(sizeof(BGSMenuIcon) == 0x1C);
