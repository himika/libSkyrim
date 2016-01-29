#pragma once

#include "TESForm.h"
#include "../FormComponents/TESModelTextureSwap.h"
#include "../BSCore/BSFixedString.h"

/*==============================================================================
class TESObjectANIO +0000 (_vtbl=01084384)
0000: class TESObjectANIO
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESModelTextureSwap
0014: |   |   class TESModel
0014: |   |   |   class BaseFormComponent
==============================================================================*/
// 38
class TESObjectANIO : public TESForm,
	public TESModelTextureSwap			// 14
{
public:
	enum { kTypeID = (UInt32)FormType::ANIO };

	BSFixedString	unk30;				// 30
	BSFixedString	unk34;				// 34
};
STATIC_ASSERT(sizeof(TESObjectANIO) == 0x38);
