#pragma once

#include "TESForm.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/TESAttackDamageForm.h"
#include "../FormComponents/TESTexture.h"

/*==============================================================================
class TESWaterForm +0000 (_vtbl=01089B1C)
0000: class TESWaterForm
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
001C: |   class TESAttackDamageForm
001C: |   |   class BaseFormComponent
==============================================================================*/
// 1D4
class TESWaterForm : public TESForm,
	public TESFullName,			// 14
	public TESAttackDamageForm	// 1C
{
public:
	enum { kTypeID = (UInt32)FormType::Water };

	virtual ~TESWaterForm();									// 004EE630

	// @override
	virtual bool	GetFlag00020000(void);						// 004ED2F0
	virtual bool	ActivateReference(TESObjectREFR* targetRef, TESObjectREFR* activatorRef, UInt32 arg2, UInt32 arg3, UInt32 arg4);	// 004ED310

	// @members

	// 10
	struct Data2C
	{
		UInt32	unk0;	// 0
		UInt32	unk4;	// 4
		UInt32	unk8;	// 8
		UInt32	unkC;	// C
	};

	// E4
	struct Data80
	{
		float	unk00;		// 00 - init'd to .1
		float	unk04;		// 04 - init'd to 90
		float	unk08;		// 08 - init'd to .5
		float	unk0C;		// 0C - init'd to 1
		float	unk10;		// 10 - init'd to 50
		float	unk14;		// 14 - init'd to .5
		float	unk18;		// 18 - init'd to .025
		UInt32	unk1C;		// 1C - init'd to 0
		UInt32	unk20;		// 20 - init'd to 0
		UInt32	unk24;		// 24 - init'd to 0
		UInt32	unk28;		// 28 - init'd to 00808000
		UInt32	unk2C;		// 2C - init'd to 00190000
		UInt32	unk30;		// 30 - init'd to 00FFFFFF
		UInt8	unk34;		// 34 - init'd to 0
		UInt8	pad35[3];	// 35
		float	unk38;		// 38 - init'd to 0.1
		float	unk3C;		// 3C - init'd to 0.6
		float	unk40;		// 40 - init'd to 0.985
		float	unk44;		// 44 - init'd to 2
		float	unk48;		// 48 - init'd to .01
		float	unk4C;		// 4C - init'd to .4
		float	unk50;		// 50 - init'd to .6
		float	unk54;		// 54 - init'd to .985
		float	unk58;		// 58 - init'd to 10
		float	unk5C;		// 5C - init'd to .05
		float	unk60;		// 60 - init'd to 300
		UInt32	unk64;		// 64 - init'd to 0
		UInt32	unk68;		// 68 - init'd to 0
		UInt32	unk6C;		// 6C - init'd to 0
		UInt32	unk70;		// 70 - init'd to 0
		UInt32	unk74;		// 74 - init'd to 0
		UInt32	unk78;		// 78 - init'd to 0
		float	unk7C;		// 7C - init'd to 300
		float	unk80;		// 80 - init'd to 300
		float	unk84;		// 84 - init'd to 1
		UInt32	unk88;		// 88 - not init'd
		float	unk8C;		// 8C - init'd to 1
		UInt32	unk90;		// 90 - init'd to 0
		float	unk94;		// 94 - init'd to 1000
		float	unk98;		// 98 - init'd to 250
		float	unk9C;		// 9C - init'd to 100
		float	unkA0;		// A0 - init'd to 1
		float	unkA4;		// A4 - init'd to 10000
		float	unkA8;		// A8 - init'd to 1
		float	unkAC;		// AC - init'd to 100
		float	unkB0;		// B0 - init'd to 100
		float	unkB4;		// B4 - init'd to 100
		UInt32	unkB8;		// B8 - init'd to 0
		UInt32	unkBC;		// BC - init'd to 0
		UInt32	unkC0;		// C0 - init'd to 0
		float	unkC4;		// C4 - init'd to 1
		float	unkC8;		// C8 - init'd to 1
		float	unkCC;		// CC - init'd to 1
		float	unkD0;		// D0 - init'd to 1
		float	unkD4;		// D4 - init'd to 1
		float	unkD8;		// D8 - init'd to 1
		float	unkDC;		// DC - init'd to 1
		float	unkE0;		// E0 - init'd to 1
	};

	// C
	struct Data1C8
	{
		UInt32	unk0;	// 0
		UInt32	unk4;	// 4
		UInt32	unk8;	// 8
	};

	UInt8		unk024;		// 024
	UInt8		pad025[3];	// 025
	UInt32		unk028;		// 028
	Data2C		unk02C;		// 02C
	Data2C		unk03C;		// 03C
	Data2C		unk04C;		// 04C
	TESTexture	unk05C;		// 05C
	TESTexture	unk064;		// 064
	TESTexture	unk06C;		// 06C
	UInt8		unk074;		// 074
	UInt8		unk075;		// 075
	UInt8		pad076[2];	// 076
	UInt32		unk078;		// 078
	UInt32		unk07C;		// 07C
	Data80		unk080;		// 080
	UInt32		unk164[3];	// 164
	UInt32		unk170;		// 170
	UInt32		unk174;		// 174
	UInt32		unk178;		// 178
	UInt32		unk17C;		// 17C
	UInt32		unk180;		// 180
	float		unk184;		// 184
	float		unk188;		// 188
	float		unk18C;		// 18C
	float		unk190;		// 190
	UInt32		unk194;		// 194
	UInt32		unk198;		// 198
	UInt32		unk19C;		// 19C
	UInt32		unk1A0;		// 1A0
	UInt32		unk1A4;		// 1A4
	UInt32		unk1A8;		// 1A8
	void		* unk1AC;	// 1AC - refcounted ptr
	UInt32		unk1B0;		// 1B0
	UInt8		unk1B4;		// 1B4
	UInt8		pad1B5[3];	// 1B5
	UInt32		unk1B8;		// 1B8
	Data1C8		unk1BC;		// 1BC
	Data1C8		unk1C8;		// 1C8
};
STATIC_ASSERT(sizeof(TESWaterForm) == 0x1D4);
