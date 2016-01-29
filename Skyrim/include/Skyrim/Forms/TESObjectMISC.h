#pragma once

#include "TESBoundObject.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/TESModelTextureSwap.h"
#include "../FormComponents/TESIcon.h"
#include "../FormComponents/TESValueForm.h"
#include "../FormComponents/TESWeightForm.h"
#include "../FormComponents/BGSDestructibleObjectForm.h"
#include "../FormComponents/BGSMessageIcon.h"
#include "../FormComponents/BGSPickupPutdownSounds.h"
#include "../FormComponents/BGSKeywordForm.h"

/*==============================================================================
class TESObjectMISC +0000 (_vtbl=010853EC)
0000: class TESObjectMISC
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESFullName
0020: |   |   class BaseFormComponent
0028: |   class TESModelTextureSwap
0028: |   |   class TESModel
0028: |   |   |   class BaseFormComponent
0044: |   class TESIcon
0044: |   |   class TESTexture
0044: |   |   |   class BaseFormComponent
004C: |   class TESValueForm
004C: |   |   class BaseFormComponent
0054: |   class TESWeightForm
0054: |   |   class BaseFormComponent
005C: |   class BGSDestructibleObjectForm
005C: |   |   class BaseFormComponent
0064: |   class BGSMessageIcon
0064: |   |   class BaseFormComponent
0070: |   class BGSPickupPutdownSounds
0070: |   |   class BaseFormComponent
007C: |   class BGSKeywordForm
007C: |   |   class BaseFormComponent
==============================================================================*/
// 88
class TESObjectMISC : public TESBoundObject,
	public TESFullName,						// 20
	public TESModelTextureSwap,				// 28
	public TESIcon,							// 44
	public TESValueForm,					// 4C
	public TESWeightForm,					// 54
	public BGSDestructibleObjectForm,		// 5C
	public BGSMessageIcon,					// 64
	public BGSPickupPutdownSounds,			// 70
	public BGSKeywordForm					// 7C
{
public:
	enum { kTypeID = (UInt32)FormType::Misc };

	virtual void	Unk_54(void);
	virtual void	Unk_55(UInt32 arg0, UInt32 arg1);
	virtual void	Unk_56(void);
};
STATIC_ASSERT(sizeof(TESObjectMISC) == 0x88);
