#pragma once

#include "TESForm.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/BGSMenuDisplayObject.h"
#include "../FormComponents/BGSEquipType.h"
#include "../FormComponents/TESDescription.h"

/*==============================================================================
class TESShout +0000 (_vtbl=010A153C)
0000: class TESShout
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
001C: |   class BGSMenuDisplayObject
001C: |   |   class BaseFormComponent
0024: |   class BGSEquipType
0024: |   |   class BaseFormComponent
002C: |   class TESDescription
002C: |   |   class BaseFormComponent
==============================================================================*/
// 5C
class TESShout : public TESForm,
	TESFullName,			//14
	BGSMenuDisplayObject,	// 1C
	BGSEquipType,			// 24
	TESDescription			// 2C
{
public:
	enum { kTypeID = (UInt32)FormType::Shout };

	// @members

	// C
	struct Words
	{
		enum {
			kNumWords = 3
		};
		TESWordOfPower *	word;
		SpellItem *			spell;
		float				recoverytime;
	};

	Words	words[Words::kNumWords];	// 38
};
STATIC_ASSERT(sizeof(TESShout) == 0x5C);
