#pragma once

#include "../Magic/MagicItem.h"
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
	virtual UInt32	GetMagicType(void) const override;				// 54 0068ED10 { return this->data->type; }
	virtual UInt32	GetCastingType(void) const override;			// 56 005E22D0 { return this->data->castingType; }
	virtual UInt32	GetDeliveryType(void) const override;			// 57 00409320 { return this->data->deliveryType; }
	virtual float	GetCastDuration(void) const;					// 5A 00409330 { return (GetCastringType() = kCastingType_Concentration) ? duration : 0.0f; }
	virtual float	GetRange(void) const override;					// 5B 004096C0 { return data.range; }
	virtual bool	Unk_5C(void) override;							// 5C 00409C30 { return (((Data *)Unk_6D())->flags >> 0x14) & 1; }
	virtual bool	Unk_5D(void) override;							// 5D 00409C50 { return (((Data *)Unk_6D())->flags >> 0x13) & 1; }
	virtual bool	Unk_5F(void) override;							// 5F 00409C70 { return (((Data *)Unk_6D())->flags >> 0x15) & 1; }
	virtual bool	Unk_60(void) override;							// 60 00409C90 { return (((Data *)Unk_6D())->flags >> 0x17) & 1; }
	virtual bool	Unk_61(UInt32 arg) override;					// 61 004098A0
	virtual void	Unk_64(void *, Actor *actor) override;			// 64 00409840
	virtual float	GetChargeTime(void) const override;				// 65 00409AB0
	virtual SInt32	GetActorValueType(void) const;					// 67 00409980
	virtual bool	Unk_68(void) override;							// 68 004096D0 related with equip slot ?
	virtual UInt32	GetDataSigniture(void) const override;			// 69 00409260 { return 'SPIT'; }
	virtual void	CopyData(MagicItem *src) override;				// 6A 004097D0 { if (this->formType == src->formType) data = src->data; }
	virtual void	Unk_6B(TESFile *file, UInt32 subtype) override;	// 6B 00409D30
	virtual void	Unk_6C(TESFile *file) override;					// 6C 00409660
	virtual void *	Unk_6D(void) override;							// 6D 00409270 { return &this->data; }
	virtual void *	Unk_6E(void) override;							// 6E 00409270 { return &this->data; }
	virtual UInt32	GetDataSize(void) const override;				// 6F 00405220 { return sizeof(Data); }
	virtual void	Unk_70(void) override;							// 70 00409C20 byteswap ?


	UInt32	GetMagickaCost() const { return data.calculations.cost; }


	// 24
	struct Data
	{
		enum Flag
		{
			kFlag_ManualCostCalc			= (1 << 0),		// 00000000
			kFlag_PCStartSpell				= (1 << 17),	// 00020000
			kFlag_AreaEffectIgnoresLOS		= (1 << 19),	// 00080000
			kFlag_IgnoreResistance			= (1 << 20),	// 00100000
			kFlag_NoAbsorbReflect			= (1 << 21),	// 00200000
			kFlag_NoDualCastModification	= (1 << 23),	// 00800000
		};

		struct Calculations
		{
			UInt32	cost;		// 00 (6C) - best cost
			UInt32	flags;		// 04 (70)
		};

		Calculations	calculations;	// 00 (6C)
		UInt32			type;			// 08 (74)
		float			castTime;		// 0C (78)
		UInt32			castingType;	// 10 (7C)
		UInt32			deliveryType;	// 14 (80)
		float			duration;		// 18 (84)
		float			range;			// 1C (88)
		BGSPerk *		spellPerk;		// 20 (8C) - half-const perk
	};

	// @members
	Data	data;	// 6C - SPIT

};
STATIC_ASSERT(sizeof(SpellItem) == 0x90);
