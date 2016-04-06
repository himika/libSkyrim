#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/TESChildCell.h"

/*==============================================================================
class TESObjectLAND +0000 (_vtbl=010876AC)
0000: class TESObjectLAND
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESChildCell
==============================================================================*/
// 28
class TESObjectLAND : public TESForm,
	public TESChildCell		// 14
{
public:
	enum { kTypeID = (UInt32)FormType::Land };

	// @members
	UInt32		unk18;	// 18
	UInt32		unk1C;	// 1C
	UInt32		unk20;	// 20
	UInt32		unk24;	// 24
};
STATIC_ASSERT(sizeof(TESObjectLAND) == 0x28);
