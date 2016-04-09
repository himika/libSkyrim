#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../BSAudio/BSIMusicType.h"
#include "../../BSCore/BSFixedString.h"

/*==============================================================================
class BGSMusicType +0000 (_vtbl=0108DC1C)
0000: class BGSMusicType
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class BSIMusicType
==============================================================================*/
// 4C
class BGSMusicType : public TESForm,
	public BSIMusicType			// 14
{
public:
	enum { kTypeID = (UInt32)FormType::MusicType };

	// @members
	UInt32			pad44;		// 44
	BSFixedString	editorId;	// 48
};
STATIC_ASSERT(sizeof(BGSMusicType) == 0x4C);
