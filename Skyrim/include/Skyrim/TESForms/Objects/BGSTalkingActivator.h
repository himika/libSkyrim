#pragma once

#include "TESObjectACTI.h"

class BGSVoiceType;

/*==============================================================================
class BGSTalkingActivator +0000 (_vtbl=01082024)
0000: class BGSTalkingActivator
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
==============================================================================*/
// 74
class BGSTalkingActivator : public TESObjectACTI
{
public:
	enum { kTypeID = (UInt32)FormType::TalkingActivator };

	// @members
	void			* unk6C;	// 6C
	BGSVoiceType	* unk70;	// 70
};
STATIC_ASSERT(sizeof(BGSTalkingActivator) == 0x74);
