#pragma once

#include "MagicItem.h"
#include "../FormComponents/BGSEquipType.h"
#include "../FormComponents/BGSMenuDisplayObject.h"
#include "../FormComponents/TESDescription.h"

/*==============================================================================
class SpellItem +0000 (_vtbl=01078D84)
0000: class SpellItem
0000: |   class MagicItem
0000: |   |   class TESBoundObject
0000: |   |   |   class TESObject
0000: |   |   |   |   class TESForm
0000: |   |   |   |   |   class BaseFormComponent
0020: |   |   class TESFullName
0020: |   |   |   class BaseFormComponent
0028: |   |   class BGSKeywordForm
0028: |   |   |   class BaseFormComponent
0050: |   class BGSEquipType
0050: |   |   class BaseFormComponent
0058: |   class BGSMenuDisplayObject
0058: |   |   class BaseFormComponent
0060: |   class TESDescription
0060: |   |   class BaseFormComponent
==============================================================================*/
// 90
class SpellItem : public MagicItem,
	public BGSEquipType,			// 50
	public BGSMenuDisplayObject,	// 58
	public TESDescription			// 60
{
public:
	enum { kTypeID = (UInt32)FormType::Spell };

	// @override
	virtual UInt32	GetMagicType(void) override;	// 0068ED10 (void) { return this->data->type; }
	virtual UInt32	GetCastType(void) override;		// 005E22D0 (void) { return this->data->castType; }
	virtual UInt32	GetDeliveryType(void) override;	// 00409320 (void) { return this->data->deliveryType; }
	virtual UInt32	Unk_69(void) override;			// 00409260 (void) { return 'SPIT'; }
	virtual void *	Unk_6D(void) override;			// 00409270 (void) { return &this->data; }
	virtual void *	Unk_6E(void) override;			// 00409270 (void) { return &this->data; }
	virtual UInt32	Unk_6F(void) override;			// 00405220 (void) { return sizeof(Data); }

	// @members
	enum
	{
		kTypeSpell = 0,
		kTypeDisease,
		kTypePower,
		kTypeLesserPower,
		kTypeAbility,
		kTypePoison,
		kTypeAddition,
		kTypeVoice
	};

	// 24
	struct Data
	{
		struct Calculations
		{
			UInt32	cost;		// 00 - 6C
			UInt32	flags;		// 04 - 70
		};

		Calculations	calculations;	// 00 - 6C
		UInt32			type;			// 08 - 74
		float			castTime;		// 0C - 78
		UInt32			castType;		// 10 - 7C
		UInt32			deliveryType;	// 14 - 80
		UInt32			unk18;			// 18 - 84
		UInt32			unk1C;			// 1C - 88
		BGSPerk *		spellPerk;		// 20 - 8C
	};

	Data	data;	// 6C

	UInt32	GetMagickaCost() { return data.calculations.cost; }
};
STATIC_ASSERT(sizeof(SpellItem) == 0x90);
