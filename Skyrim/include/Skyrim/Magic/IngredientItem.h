#pragma once

#include "../Magic/MagicItem.h"
#include "../FormComponents/TESModelTextureSwap.h"
#include "../FormComponents/TESIcon.h"
#include "../FormComponents/TESWeightForm.h"
#include "../FormComponents/BGSEquipType.h"
#include "../FormComponents/BGSDestructibleObjectForm.h"
#include "../FormComponents/BGSPickupPutdownSounds.h"
#include "../FormComponents/TESValueForm.h"

/*==============================================================================
class IngredientItem +0000 (_vtbl=01077B04)
0000: class IngredientItem
0000: |   class MagicItem
0000: |   |   class TESBoundObject
0000: |   |   |   class TESObject
0000: |   |   |   |   class TESForm
0000: |   |   |   |   |   class BaseFormComponent
0020: |   |   class TESFullName
0020: |   |   |   class BaseFormComponent
0028: |   |   class BGSKeywordForm
0028: |   |   |   class BaseFormComponent
0050: |   class TESModelTextureSwap
0050: |   |   class TESModel
0050: |   |   |   class BaseFormComponent
006C: |   class TESIcon
006C: |   |   class TESTexture
006C: |   |   |   class BaseFormComponent
0074: |   class TESWeightForm
0074: |   |   class BaseFormComponent
007C: |   class BGSEquipType
007C: |   |   class BaseFormComponent
0084: |   class BGSDestructibleObjectForm
0084: |   |   class BaseFormComponent
008C: |   class BGSPickupPutdownSounds
008C: |   |   class BaseFormComponent
0098: |   class TESValueForm
0098: |   |   class BaseFormComponent
==============================================================================*/
// AC
class IngredientItem : public MagicItem,
	public TESModelTextureSwap,			// 50
	public TESIcon,						// 6C
	public TESWeightForm,				// 74
	public BGSEquipType,				// 7C
	public BGSDestructibleObjectForm,	// 84
	public BGSPickupPutdownSounds,		// 8C
	public TESValueForm					// 98
{
public:
	enum { kTypeID = (UInt32)FormType::Ingredient };

	// 08
	struct Data
	{
		UInt32 unk00; // 00
		UInt32 unk04; // 04
	};

	// ahzaab 8-25-13
	enum   // type - these are flags
	{
		kType_NoEffect		= 0,
		kType_FirstEffect	= 1 << 0,
		kType_SecondEffect	= 1 << 1,
		kType_ThirdEffect	= 1 << 2,
		kType_FourthEffect	= 1 << 3
	};

	struct DataA9
	{
		UInt8  unk00; // 00
		UInt8  unk01; // 01
		UInt8  unk02; // 02
	};


	virtual ~IngredientItem();							// 00405DF0

	// @override
	virtual UInt32	GetMagicType(void) const override;			// 54 00667E20 { return kType_Ingredient; }
	virtual UInt32	GetCastingType(void) const override;		// 56 00CAC8A0 { return kCastType_FireAndForget; }
	virtual UInt32	GetDeliveryType(void) const override;		// 58 005EADD0 { return kDeliveryType_Self; }
	virtual bool	Unk_5E(void) override;						// 5E 00405CF0 { return (Unk_6D()->unk04 >> 1) & 1; }
	virtual bool	Unk_61(UInt32 arg) override;				// 61 00406070
	virtual UInt32	Unk_66(void) override;						// 66 009048A0 { return 0x04; }
	virtual SInt32	GetActorValueType(void) const override;		// 67 00DA29A0 { return kActorValue_Alchemy; }
	virtual UInt32	GetDataSigniture(void) const override;		// 69 00405A80 { return 'ENIT'; }
	virtual void	CopyData(MagicItem *src) override;			// 6A 00405BA0 { if (formType == src->formType) unkA0 = src->unkA0; }
	virtual void	Unk_6B(TESFile *file, UInt32 subtype);		// 6B 00405E20
	virtual void *	Unk_6D(void) override;						// 6D 00405A90 { return &unkA0; }
	virtual void *	Unk_6E(void) override;						// 6E 00405A90 { return &unkA0; }
	virtual UInt32	GetDataSize(void) const override;			// 6F 00405220 { return sizeof(Data); }
	virtual void	Unk_70(void) override;						// 70 00406040
	

	// @memberes
	Data		data;				// A0 - ENIT
	UInt8		knownEffects;		// A8 - The lower nibble contains the known effects, the upper nibble is unknown
	DataA9		unkA9;				// A9
};
STATIC_ASSERT(offsetof(IngredientItem, unkA9) == 0xA9);
STATIC_ASSERT(sizeof(IngredientItem) == 0xAC);
