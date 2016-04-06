#pragma once

#include "TESObjectACTI.h"
#include "../../FormComponents/TESProduceForm.h"

/*==============================================================================
class TESFlora +0000 (_vtbl=01082A34)
0000: class TESFlora
0000: |   class TESObjectACTI
0000: |   |   class TESBoundAnimObject
0000: |   |   |   class TESBoundObject
0000: |   |   |   |   class TESObject
0000: |   |   |   |   |   class TESForm
0000: |   |   |   |   |   |   class BaseFormComponent
0020: |   |   class TESFullName
0020: |   |   |   class BaseFormComponent
0028: |   |   class TESModelTextureSwap
0028: |   |   |   class TESModel
0028: |   |   |   |   class BaseFormComponent
005C: |   |   class TESMagicTargetForm
0044: |   |   class BGSDestructibleObjectForm
0044: |   |   |   class BaseFormComponent
004C: |   |   class BGSOpenCloseForm
0050: |   |   class BGSKeywordForm
0050: |   |   |   class BaseFormComponent
006C: |   class TESProduceForm
006C: |   |   class BaseFormComponent
==============================================================================*/
// 7C
class TESFlora : public TESObjectACTI,
	public TESProduceForm		// 6C
{
public:
	enum { kTypeID = (UInt32)FormType:: Flora };
};
STATIC_ASSERT(sizeof(TESFlora) == 0x7C);
