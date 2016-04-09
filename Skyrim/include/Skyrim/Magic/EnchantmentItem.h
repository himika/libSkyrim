#pragma once

#include "../Magic/MagicItem.h"

/*==============================================================================
class EnchantmentItem +0000 (_vtbl=01077804)
0000: class EnchantmentItem
0000: |   class MagicItem
0000: |   |   class TESBoundObject
0000: |   |   |   class TESObject
0000: |   |   |   |   class TESForm
0000: |   |   |   |   |   class BaseFormComponent
0020: |   |   class TESFullName
0020: |   |   |   class BaseFormComponent
0028: |   |   class BGSKeywordForm
0028: |   |   |   class BaseFormComponent
==============================================================================*/
// 74
class EnchantmentItem : public MagicItem
{
public:
	enum { kTypeID = (UInt32)FormType::Enchantment };

	enum
	{
		kFlag_ManualCalc = 0x00000001,
	};

	// @override
	virtual UInt32	GetMagicType(void) const override;				// 54 00405270 { return data->enchantType; }
	virtual void	SetCastingType(UInt32 castingType) override;	// 55 004051D0 { data->castingType = arg; MagicItem::SetCastingType(arg); }
	virtual UInt32	GetCastingType(void) const override;			// 56 00405280 { return data->castingType; }
	virtual void	SetDeliveryType(UInt32 deliveryType);			// 57 004051E0 { if (Unk_59(arg)) { data->deliveryType = arg1; MagicItem::SetDeliveryType(arg); }
	virtual UInt32	GetDeliveryType(void) const override;			// 58 00405290 { return data->deliveryType; }
	virtual float	GetChargeTime(void) const override;				// 65 00405680
	virtual SInt32	GetActorValueType(void) const override;			// 67 008F8F10 { return kActorValue_Enchanting; }
	virtual UInt32	GetDataSigniture(void) const override;			// 69 00405A80 { return 'ENIT'; }
	virtual void	CopyData(MagicItem *src) override;				// 6A 004052E0
	virtual void *	Unk_6D(void) override;							// 6D 00405210 (void) { return &data; }
	virtual void *	Unk_6E(void) override;							// 6E 00405210 (void) { return &data; }
	virtual UInt32	GetDataSize(void) const override;				// 6F 00405220 (void) { return sizeof(Data); }
	virtual void	Unk_70(void) override;							// 70 00405670 { return data->Unk_00405500(); }


	// 24
	struct Data
	{
		struct Calculations
		{
			UInt32	cost;					// 00 - 50
			UInt32	flags;					// 04 - 54
		};

		Calculations	calculations;		// 00 - 50
		UInt32			castingType;		// 08 - 58
		UInt32			enchantmentAmount;	// 0C - 5C
		UInt32			deliveryType;		// 10 - 60
		UInt32			enchantType;		// 14 - 64 - enchantment (6), staff enchantment (12)
		float			chargeTime;			// 18 - 68
		EnchantmentItem	* baseEnchantment;	// 1C - 6C
		BGSListForm		* restrictions;		// 20 - 70
	};

	// @members
	Data	data;	// 50 - ENIT
};
STATIC_ASSERT(sizeof(EnchantmentItem) == 0x74);
