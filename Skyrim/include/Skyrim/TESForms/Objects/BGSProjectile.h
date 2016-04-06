#pragma once

#include "TESBoundObject.h"
#include "../../FormComponents/TESFullName.h"
#include "../../FormComponents/TESModel.h"
#include "../../FormComponents/BGSPreloadable.h"
#include "../../FormComponents/BGSDestructibleObjectForm.h"


/*==============================================================================
class BGSProjectile +0000 (_vtbl=01081BAC)
0000: class BGSProjectile
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESFullName
0020: |   |   class BaseFormComponent
0028: |   class TESModel
0028: |   |   class BaseFormComponent
003C: |   class BGSPreloadable
003C: |   |   class BaseFormComponent
0040: |   class BGSDestructibleObjectForm
0040: |   |   class BaseFormComponent
==============================================================================*/
// BC
class BGSProjectile : public TESBoundObject,
	public TESFullName,					// 20
	public TESModel,					// 28
	public BGSPreloadable,				// 3C
	public BGSDestructibleObjectForm	// 40
{
public:
	enum { kTypeID = (UInt32)FormType::Projectile };

	// 5C
	struct Data
	{
		UInt32	unk00;				// 00
		UInt32	unk04;				// 04
		float	unk08;				// 08
		float	unk0C;				// 0C
		UInt32	unk10;				// 10
		UInt32	unk14;				// 14
		UInt32	unk18;				// 18
		UInt32	unk1C;				// 1C
		UInt32	unk20;				// 20
		UInt32	unk24;				// 24
		UInt32	unk28;				// 28
		UInt32	unk2C;				// 2C
		float	unk30;				// 30
		UInt32	unk34;				// 34
		UInt32	unk38;				// 38
		UInt32	unk3C;				// 3C
		UInt32	unk40;				// 40
		UInt32	unk44;				// 44
		float	unk48;				// 48
		UInt32	unk4C;				// 4C
		float	relaunchInterval;	// 50
		UInt32	unk54;				// 54
		UInt32	unk58;				// 58
	};


	virtual ~BGSProjectile();				// 00494140

	// @override TESForm
	virtual void	Unk_04(void) override;									// 00493DD0
	virtual void	Unk_05(void) override;									// 00493B60
	virtual bool	LoadForm(TESFile *arg) override;						// 00494170
	virtual void	InitItem(void) override;								// 00494530
	virtual bool	ActivateReference(TESObjectREFR* targetRef, TESObjectREFR* activatorRef, UInt32 arg2, UInt32 arg3, UInt32 arg4) override;	// 004946B0

	// @override TESBoundObject
	virtual UInt32	Unk_40(UInt32 arg0, UInt32 arg1) override;				// 004948A0
	virtual void	Unk_41(void * arg) override;							// 00493E00
	virtual bool	GetCrosshairText(TESObjectREFR *ref, BSString *dst, bool unk) override;	// 004947F0 steal/take string


	// @members
	Data		data;		// 48
	TESModel	modelA4;	// A4
	UInt32		unkB8;		// B8
};
STATIC_ASSERT(sizeof(BGSProjectile) == 0xBC);
