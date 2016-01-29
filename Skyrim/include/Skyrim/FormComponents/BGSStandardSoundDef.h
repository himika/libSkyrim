#pragma once

#include "BaseFormComponent.h"
#include "BGSSoundDescriptor.h"
#include "SoundPlaybackCharacteristics.h"

class BGSSoundCategory;


class BGSStandardSoundDef : public BGSSoundDescriptor
{
public:
	virtual ~BGSStandardSoundDef();

	BGSSoundCategory	* soundCategory;
	UInt32				unk08;
	UInt32				unk0C;
	UInt32				unk10;
	UInt32				unk14;
	SoundPlaybackCharacteristics soundCharacteristics;
};
