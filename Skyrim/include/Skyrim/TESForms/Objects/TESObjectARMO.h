#pragma once

#include "TESBoundObject.h"
#include "../../FormComponents/TESFullName.h"
#include "../../FormComponents/TESRaceForm.h"
#include "../../FormComponents/TESEnchantableForm.h"
#include "../../FormComponents/TESValueForm.h"
#include "../../FormComponents/TESWeightForm.h"
#include "../../FormComponents/BGSDestructibleObjectForm.h"
#include "../../FormComponents/BGSPickupPutdownSounds.h"
#include "../../FormComponents/TESBipedModelForm.h"
#include "../../FormComponents/BGSEquipType.h"
#include "../../FormComponents/BGSBipedObjectForm.h"
#include "../../FormComponents/BGSBlockBashData.h"
#include "../../FormComponents/BGSKeywordForm.h"
#include "../../FormComponents/TESDescription.h"
#include "../../BSCore/BSTArray.h"

class TESObjectARMA;


/*==============================================================================
class TESObjectARMO +0000 (_vtbl=010847EC)
0000: class TESObjectARMO
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESFullName
0020: |   |   class BaseFormComponent
0028: |   class TESRaceForm
0028: |   |   class BaseFormComponent
0030: |   class TESEnchantableForm
0030: |   |   class BaseFormComponent
003C: |   class TESValueForm
003C: |   |   class BaseFormComponent
0044: |   class TESWeightForm
0044: |   |   class BaseFormComponent
004C: |   class BGSDestructibleObjectForm
004C: |   |   class BaseFormComponent
0054: |   class BGSPickupPutdownSounds
0054: |   |   class BaseFormComponent
0060: |   class TESBipedModelForm
0060: |   |   class BaseFormComponent
00D8: |   class BGSEquipType
00D8: |   |   class BaseFormComponent
00E0: |   class BGSBipedObjectForm
00E0: |   |   class BaseFormComponent
00EC: |   class BGSBlockBashData
00EC: |   |   class BaseFormComponent
00F8: |   class BGSKeywordForm
00F8: |   |   class BaseFormComponent
0104: |   class TESDescription
0104: |   |   class BaseFormComponent
==============================================================================*/
// 124
class TESObjectARMO : public TESBoundObject,
	public TESFullName,					// 020
	public TESRaceForm,					// 028
	public TESEnchantableForm,			// 030
	public TESValueForm,				// 03C
	public TESWeightForm,				// 044
	public BGSDestructibleObjectForm,	// 04C
	public BGSPickupPutdownSounds,		// 054
	public TESBipedModelForm,			// 060
	public BGSEquipType,				// 0D8
	public BGSBipedObjectForm,			// 0E0
	public BGSBlockBashData,			// 0EC
	public BGSKeywordForm,				// 0F8
	public TESDescription				// 104
{
public:
	enum { kTypeID = (UInt32)FormType::Armor };

	// @override
	virtual void	Unk_04(void) override;							// 004A1DC0
	virtual bool	LoadForm(TESFile *arg) override;				// 004A22B0
	virtual void	SaveBuffer(BGSSaveFormBuffer *sav) override;	// 004A1D70
	virtual void	LoadBuffer(BGSLoadFormBuffer *sav) override;	// 004A1D90
	virtual void	InitItem(void) override;						// 004A2C80
	virtual void	Unk_14(void) override;							// 004A1FB0
	virtual void	CopyFrom(TESForm * srcForm) override;			// 004A2E00

public:
	// @members
	// vtbl						0x010847EC			// 000
	UInt32						armorValTimes100;	// 110
	BSTArray<TESObjectARMA *>	armorAddons;		// 114
	UInt32						unk120;				// 120 - enchantment related?
};

STATIC_ASSERT(offsetof(TESObjectARMO, armorValTimes100) == 0x110);
STATIC_ASSERT(sizeof(TESObjectARMO) == 0x124);
