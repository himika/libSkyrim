#pragma once

#include "TESForm.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/TESDescription.h"
#include "../FormComponents/TESTexture.h"

/*==============================================================================
class TESClass +0000 (_vtbl=010A4C04)
0000: class TESClass
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
001C: |   class TESDescription
001C: |   |   class BaseFormComponent
0028: |   class TESTexture
0028: |   |   class BaseFormComponent
==============================================================================*/
// 54
class TESClass : public TESForm,
	public TESFullName,			// 14
	public TESDescription,		// 1C
	public TESTexture			// 28
{
public:
	enum { kTypeID = (UInt32)FormType::Class };

	// @members

	// 24
	struct Data30
	{
		UInt8	unk00[0x4];		// 00
		UInt8	trainSkill;		// 04 (AV-6)
		UInt8	maxTrainingLevel;	// 05
		UInt8	oneHanded;		// 06
		UInt8	twoHanded;		// 07
		UInt8	archery;
		UInt8	block;
		UInt8	smithing;
		UInt8	heavyArmor;
		UInt8	lightArmor;
		UInt8	pickPocket;
		UInt8	lockpicking;
		UInt8	sneak;
		UInt8	alchemy;
		UInt8	speech;
		UInt8	alteration;
		UInt8	conjuration;
		UInt8	destruction;
		UInt8	illusion;
		UInt8	restoration;
		UInt8	enchanting;
		float	bleedout;		// 18
		UInt32	voicePoints;	// 1C
		UInt8	health;			// 20
		UInt8	magicka;		// 21
		UInt8	stamina;		// 22
		UInt8	unk23;			// 23
	};

	// 30
	Data30	unk30;				// 30
};
STATIC_ASSERT(sizeof(TESClass) == 0x54);
