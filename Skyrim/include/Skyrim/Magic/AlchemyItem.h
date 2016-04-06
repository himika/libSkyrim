#pragma once

#include "../Magic/MagicItem.h"
#include "../FormComponents/TESModelTextureSwap.h"
#include "../FormComponents/TESIcon.h"
#include "../FormComponents/BGSMessageIcon.h"
#include "../FormComponents/TESWeightForm.h"
#include "../FormComponents/BGSEquipType.h"
#include "../FormComponents/BGSDestructibleObjectForm.h"
#include "../FormComponents/BGSPickupPutdownSounds.h"

/*==============================================================================
class AlchemyItem +0000 (_vtbl=01076C1C)
0000: class AlchemyItem
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
0074: |   class BGSMessageIcon
0074: |   |   class BaseFormComponent
0080: |   class TESWeightForm
0080: |   |   class BaseFormComponent
0088: |   class BGSEquipType
0088: |   |   class BaseFormComponent
0090: |   class BGSDestructibleObjectForm
0090: |   |   class BaseFormComponent
0098: |   class BGSPickupPutdownSounds
0098: |   |   class BaseFormComponent
==============================================================================*/
// C0
class AlchemyItem : public MagicItem,
	public TESModelTextureSwap,			// 50
	public TESIcon,						// 6C
	public BGSMessageIcon,				// 74
	public TESWeightForm,				// 80
	public BGSEquipType,				// 88
	public BGSDestructibleObjectForm,	// 90
	public BGSPickupPutdownSounds		// 98
{
public:
	enum { kTypeID = (UInt32)FormType::Potion };

	// @override
	virtual UInt32	GetMagicType(void) override;	// 54 005C5580 (void) { return kType_Archemy; }
	virtual UInt32	GetCastType(void) override;		// 56 00CAC8A0 (void) { return 1; }
	virtual UInt32	GetDeliveryType(void) override;	// 58 005EADD0 (void) { return 0; }
	virtual SInt32	Unk_67(void) override;			// 67 00DA29A0 (void) { return 0x10; }
	virtual UInt32	GetSigniture(void) override;	// 69 00405A80 (void) { return 'ENIT'; }
	virtual void *	Unk_6D(void) override;			// 6D 00409270 (void) { return &this->itemData; }
	virtual void *	Unk_6E(void) override;			// 6E 00409270 (void) { return &this->itemData; }
	virtual UInt32	Unk_6F(void) override;			// 6F 009B4600 (void) { return sizeof(Data); }


	// @members
	enum
	{
		kFlag_ManualCalc = 0x00000001,
		kFlag_Food = 0x00000002,
		kFlag_Medicine = 0x00010000,
		kFlag_Poison = 0x00020000,
	};

	// 14
	struct Data
	{
		UInt32	value;	// 00
		UInt32	flags;	// 04
		UInt32	unk08;	// 08 addiction (legacy?)
		UInt32	unk0C;	// 0C addiction chance (legacy?)
		BGSSoundDescriptorForm *	useSound;	// 10
	};

	Data	itemData;	// A4
	TESIcon	unkB8;		// B8

	bool IsFood() const		{ return (itemData.flags & kFlag_Food) != 0; }
	bool IsPoison() const	{ return (itemData.flags & kFlag_Poison) != 0; }
};
