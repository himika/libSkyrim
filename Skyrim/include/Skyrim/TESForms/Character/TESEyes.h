#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/TESFullName.h"
#include "../../FormComponents/TESTexture.h"

/*==============================================================================
class TESEyes +0000 (_vtbl=010A4D74)
0000: class TESEyes
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
001C: |   class TESTexture
001C: |   |   class BaseFormComponent
==============================================================================*/
// 28
class TESEyes : public TESForm,
	public TESFullName,		// 14
	public TESTexture		// 1C
{
public:
	enum { kTypeID = (UInt32)FormType::Eyes };

	// @members
	UInt8		unk24;		// 24
	UInt8		pad25[3];	// 25
};
STATIC_ASSERT(sizeof(TESEyes) == 0x28);
