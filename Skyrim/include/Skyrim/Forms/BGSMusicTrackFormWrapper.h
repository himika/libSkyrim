#pragma once

#include "TESForm.h"
#include "../FormComponents/BSIMusicTrack.h"

/*==============================================================================
class BGSMusicTrackFormWrapper +0000 (_vtbl=0108DA54)
0000: class BGSMusicTrackFormWrapper
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class BSIMusicTrack
==============================================================================*/
// 20
class BGSMusicTrackFormWrapper : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::MusicTrack };

	// parents
	BSIMusicTrack	track;	// 14

	// @members
	UInt32	unk1C;			// 1C
};
STATIC_ASSERT(sizeof(BGSMusicTrackFormWrapper) == 0x20);
