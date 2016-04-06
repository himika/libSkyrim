#pragma once

#include "../../FormComponents/BaseFormComponent.h"
#include "../../FormComponents/BGSSoundDescriptor.h"
#include "../../FormComponents/SoundPlaybackCharacteristics.h"

class BGSSoundCategory;

/*==============================================================================
class BGSStandardSoundDef +0000 (_vtbl=0108E46C)
0000: class BGSStandardSoundDef
0000: |   class BGSSoundDescriptor
0000: |   |   class BSISoundDescriptor
==============================================================================*/
class BGSStandardSoundDef : public BGSSoundDescriptor
{
public:
	virtual ~BGSStandardSoundDef();


	// @members
	BGSSoundCategory				* soundCategory;		// 04
	UInt32							unk08;					// 08
	UInt32							unk0C;					// 0C
	UInt32							unk10;					// 10
	UInt32							unk14;					// 14
	SoundPlaybackCharacteristics	soundCharacteristics;	// 18
};
