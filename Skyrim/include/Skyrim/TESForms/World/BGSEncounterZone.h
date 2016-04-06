#pragma once

#include "../../FormComponents/TESForm.h"

/*==============================================================================
class BGSEncounterZone +0000 (_vtbl=0108631C)
0000: class BGSEncounterZone
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 30
class BGSEncounterZone : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::EncounterZone };

	UInt8	unk14[0x0C];	// 14
	UInt8	unk20[0x10];	// 20

	// +14 - TESForm * owner?
	// +18 - TESForm * location?
};
STATIC_ASSERT(sizeof(BGSEncounterZone) == 0x30);
