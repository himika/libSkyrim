#pragma once

#include "../../FormComponents/BaseFormComponent.h"
#include "../../BSAudio/BGSSoundDescriptor.h"

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
	/*==============================================================================
	struct BGSStandardSoundDef::SoundPlaybackCharacteristics +0000 (_vtbl=0108E450)
	0000: struct BGSStandardSoundDef::SoundPlaybackCharacteristics
	0000: |   struct BSISoundDescriptor::BSIPlaybackCharacteristics
	==============================================================================*/
	struct SoundPlaybackCharacteristics : public BSISoundDescriptor::BSIPlaybackCharacteristics
	{
	public:
		virtual UInt8	GetFrequencyShift(void) override;
		virtual UInt8	GetFrequencyVariance(void) override;
		virtual UInt8	GetPriority(void) override;
		virtual UInt16	GetDBAttenuation(void) override;
		virtual UInt8	GetDBVariance(void) override;

		// @members
		UInt8			frequencyShift;
		UInt8			frequencyVariance;
		UInt8			priority;
		UInt8			dbVariance;
		UInt16			dbAttenuation;			// CK Value * 100
		UInt16			pad1A;
		UInt32			unk20;
		BGSSoundOutput	* soundOutput;
		UInt32			unk28;
		UInt32			unk2C;
	};


	virtual ~BGSStandardSoundDef();


	// @members
	BGSSoundCategory				* soundCategory;		// 04
	UInt32							unk08;					// 08
	UInt32							unk0C;					// 0C
	UInt32							unk10;					// 10
	UInt32							unk14;					// 14
	SoundPlaybackCharacteristics	soundCharacteristics;	// 18
};
