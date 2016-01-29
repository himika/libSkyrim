#pragma once

#include "TESBoundObject.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/TESModel.h"
#include "../FormComponents/TESEnchantableForm.h"
#include "../FormComponents/BGSPreloadable.h"
#include "../FormComponents/TESImageSpaceModifiableForm.h"

/*==============================================================================
class BGSExplosion +0000 (_vtbl=010813EC)
0000: class BGSExplosion
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESFullName
0020: |   |   class BaseFormComponent
0028: |   class TESModel
0028: |   |   class BaseFormComponent
003C: |   class TESEnchantableForm
003C: |   |   class BaseFormComponent
0048: |   class BGSPreloadable
0048: |   |   class BaseFormComponent
004C: |   class TESImageSpaceModifiableForm
004C: |   |   class BaseFormComponent
==============================================================================*/
// 88
class BGSExplosion : public TESBoundObject,
	public TESFullName,						// 20
	public TESModel,						// 28
	public TESEnchantableForm,				// 3C
	public BGSPreloadable,					// 48
	public TESImageSpaceModifiableForm		// 4C
{
public:
	enum { kTypeID = (UInt32)FormType::Explosion };

	// @override TESForm
	virtual void	Unk_04(void) override;							// 00492050
	virtual bool	LoadForm(TESFile *arg) override;				// 00492630
	virtual void	InitItem(void) override;						// 00492960

	// @override TESBoundObject
	virtual UInt32	Unk_40(UInt32 arg0, UInt32 arg1) override;		// 00492A50
	virtual void	Unk_41(void * arg) override;					// 004921C0
																	
	// @members

	// 34
	struct Data
	{
		UInt32	unk00;	// 00
		UInt32	unk04;	// 04
		UInt32	unk08;	// 08
		UInt32	unk0C;	// 0C
		UInt32	unk10;	// 10
		UInt32	unk14;	// 14
		UInt32	unk18;	// 18
		UInt32	unk1C;	// 1C
		UInt32	unk20;	// 20
		UInt32	unk24;	// 24
		UInt32	unk28;	// 28
		UInt32	unk2C;	// 2C
		UInt32	unk30;	// 30
	};

	Data	data;	// 58
};
STATIC_ASSERT(sizeof(BGSExplosion) == 0x88);
