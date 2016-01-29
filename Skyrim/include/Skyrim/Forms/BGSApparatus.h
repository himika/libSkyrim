#pragma once

#include "TESObjectMISC.h"
#include "../FormComponents/TESQualityForm.h"
#include "../FormComponents/TESDescription.h"

/*==============================================================================
class BGSApparatus +0000 (_vtbl=01080CAC)
0000: class BGSApparatus
0000: |   class TESObjectMISC
0000: |   |   class TESBoundObject
0000: |   |   |   class TESObject
0000: |   |   |   |   class TESForm
0000: |   |   |   |   |   class BaseFormComponent
0020: |   |   class TESFullName
0020: |   |   |   class BaseFormComponent
0028: |   |   class TESModelTextureSwap
0028: |   |   |   class TESModel
0028: |   |   |   |   class BaseFormComponent
0044: |   |   class TESIcon
0044: |   |   |   class TESTexture
0044: |   |   |   |   class BaseFormComponent
004C: |   |   class TESValueForm
004C: |   |   |   class BaseFormComponent
0054: |   |   class TESWeightForm
0054: |   |   |   class BaseFormComponent
005C: |   |   class BGSDestructibleObjectForm
005C: |   |   |   class BaseFormComponent
0064: |   |   class BGSMessageIcon
0064: |   |   |   class BaseFormComponent
0070: |   |   class BGSPickupPutdownSounds
0070: |   |   |   class BaseFormComponent
007C: |   |   class BGSKeywordForm
007C: |   |   |   class BaseFormComponent
0088: |   class TESQualityForm
0088: |   |   class BaseFormComponent
0090: |   class TESDescription
0090: |   |   class BaseFormComponent
==============================================================================*/
// 9C
class BGSApparatus : public TESObjectMISC,
	public TESQualityForm,			// 88
	public TESDescription			// 90
{
public:
	enum { kTypeID = (UInt32)FormType::Apparatus };

	// parents
};
STATIC_ASSERT(sizeof(BGSApparatus) == 0x9C);
