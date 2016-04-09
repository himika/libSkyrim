#pragma once

// c:_skyrim\code\tesv\magic\MagicItem.h

#include "../TESForms/Objects/TESBoundObject.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/BGSKeywordForm.h"
#include "../BSCore/BSTArray.h"
#include "EffectItem.h"

class EffectSetting;
class Actor;

/*==============================================================================
class MagicItem +0000 (_vtbl=01077E7C)
0000: class MagicItem
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESFullName
0020: |   |   class BaseFormComponent
0028: |   class BGSKeywordForm
0028: |   |   class BaseFormComponent
==============================================================================*/
// 50
class MagicItem : public TESBoundObject,
	public TESFullName,		// 20
	public BGSKeywordForm	// 28
{
public:
	enum MagicType
	{
		kType_Spell = 0,
		kType_Disease,
		kType_Power,
		kType_LesserPower,
		kType_Ability,
		kType_Poison,
		kType_Enchantment,
		kType_Archemy,
		kType_Ingredient,
		kType_unk09,
		kType_unk10,
		kType_VoicePower,
		kType_StaffEnchantment,
		kType_Scroll
	};

	enum CastingType
	{
		kCastingType_Constant = 0,
		kCastingType_FireAndForget,
		kCastingType_Concentration
	};

	enum DeliveryType
	{
		kDeliveryType_Self = 0,
		kDeliveryType_Contact,
		kDeliveryType_Aimed,
		kDeliveryType_TargetActor,
		kDeliveryType_TargetLocation,
	};

	class PreloadableVisitor
	{
	public:
		virtual ~PreloadableVisitor();
		virtual void Visit(void) = 0;
	};

	
	// @override
	virtual bool	IsMagicItem(void) const override;		// 29 009B86F0 { return true; }

	// @add
	virtual UInt32	GetMagicType(void) const = 0;			// 54 (pure)
	virtual void	SetCastingType(UInt32 castingType);		// 55 00588F30 { return; }
	virtual UInt32	GetCastingType(void) const = 0;			// 56 (pure)
	virtual void	SetDeliveryType(UInt32 deliveryType);	// 57 00588F30 { return; }
	virtual UInt32	GetDeliveryType(void) const = 0;		// 58 (pure)
	virtual bool	Unk_59(UInt32 arg);						// 59 00C8CCA0 { return true; }
	virtual float	GetCastDuration(void) const;			// 5A 0066E8A0 { return 0.0f; }
	virtual float	GetRange(void) const;					// 5B 0066E8A0 { return 0.0f; }
	virtual bool	Unk_5C(void);							// 5C 0092D110 { return false; }
	virtual bool	Unk_5D(void);							// 5D 0092D110 { return false; }
	virtual bool	Unk_5E(void);							// 5E 0092D110 { return false; }
	virtual bool	Unk_5F(void);							// 5F 0092D110 { return false; }
	virtual bool	Unk_60(void);							// 60 0092D110 { return false; }
	virtual bool	Unk_61(UInt32 arg);						// 61 004091A0 { return false; }
	virtual bool	IsPoison(void) const;					// 62 00405250 { return GetMagicType() == kType_Poison } offensive or defensive ?
	virtual bool	Unk_63(void);							// 63 0092D110 { return false; }
	virtual void	Unk_64(void *, Actor *actor);			// 64 004D43E0 { return; } get associated actor value ?
	virtual float	GetChargeTime(void) const;				// 65 0066E8A0 { return 0.0f; }
	virtual UInt32	Unk_66(void);							// 66 005EADD0 { return 0; } IngredientItem=4
	virtual SInt32	GetActorValueType(void) const;			// 67 00407240 { return -1; } used for Actor::AdvanceSkill()
	virtual bool	Unk_68(void);							// 68 0092D110 { return false; }
	virtual UInt32	GetDataSigniture(void) const = 0;		// 69 (pure)
	virtual void	CopyData(MagicItem *src) = 0;			// 6A (pure) copy data if possible?
	virtual void	Unk_6B(TESFile *file, UInt32 subtype);	// 6B 004D43E0 loading-related
	virtual void	Unk_6C(TESFile *file);					// 6C 00588F30 { return; }
	virtual void *	Unk_6D(void) = 0;						// 6D (pure) returns data
	virtual void *	Unk_6E(void) = 0;						// 6E (pure) returns data
	virtual UInt32	GetDataSize(void) const = 0;			// 6F (pure) return size of data, SpellItem=0x24 AlchemyItem=0x14, EnchantmentItem=0x24
	virtual void	Unk_70(void) = 0;						// 70 (pure) byteswap?


	DEFINE_MEMBER_FN(GetCostliestEffectItem, EffectItem *, 0x00407860, int arg1, bool arg2);
	DEFINE_MEMBER_FN(GetEffectiveMagickaCost, double, 0x00406EF0, Actor *caster);


	// @members
	//void					** _vtbl;			// 00 - 01077E7C
	BSTArray<EffectItem *>	effectItemList;		// 34
	UInt32					hostile;			// 40 - init'd 0
	EffectSetting			* unk44;			// 44 - init'd 0
	UInt32					unk48;				// 48 - init'd 0
	void					* unk4C;			// 4C - init'd nullptr - refCount+0008
};
STATIC_ASSERT(sizeof(MagicItem) == 0x50);
