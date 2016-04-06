#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../BSCore/BSString.h"

/*==============================================================================
class BGSVoiceType +0000 (_vtbl=010A3FD4)
0000: class BGSVoiceType
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 20
class BGSVoiceType : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::VoiceType };

	// @members
	UInt8		unk14;		// 14
	UInt8		pad15[3];	// 15
	BSString	editorId;	// 18
};
STATIC_ASSERT(sizeof(BGSVoiceType) == 0x20);
