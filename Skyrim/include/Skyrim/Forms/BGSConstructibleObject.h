#pragma once

#include "TESForm.h"
#include "../FormComponents/TESContainer.h"

/*==============================================================================
class BGSConstructibleObject +0000 (_vtbl=010810E4)
0000: class BGSConstructibleObject
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 30
class BGSConstructibleObject : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::ConstructibleObject };

	// @members
	TESContainer	container;		// 14 - not inherited
	UInt32			unk20;			// 20 - linked list
	TESForm			*createdObject;	// 24
	BGSKeyword		* wbKeyword;	// 28
	UInt16			quantity;		// 2C
	UInt8			pad2E[2];		// 2E
};
STATIC_ASSERT(sizeof(BGSConstructibleObject) == 0x30);
