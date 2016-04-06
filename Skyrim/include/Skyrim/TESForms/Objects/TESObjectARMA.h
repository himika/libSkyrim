#pragma once

#include "TESObject.h"
#include "../../FormComponents/TESRaceForm.h"
#include "../../FormComponents/BGSBipedObjectForm.h"
#include "../../FormComponents/TESModelTextureSwap.h"
#include "../../BSCore/BSTArray.h"

class BGSFootstepSet;
class TESObjectARMO;
class TESObjectREFR;
class TESRace;


/*==============================================================================
class TESObjectARMA +0000 (_vtbl=0108450C)
0000: class TESObjectARMA
0000: |   class TESObject
0000: |   |   class TESForm
0000: |   |   |   class BaseFormComponent
0014: |   class TESRaceForm
0014: |   |   class BaseFormComponent
001C: |   class BGSBipedObjectForm
001C: |   |   class BaseFormComponent
==============================================================================*/
// C8 armor addon
class TESObjectARMA : public TESObject,
		public TESRaceForm,			// 14 - default race
		public BGSBipedObjectForm	// 1C
{
public:
	enum { kTypeID = (UInt32)FormType::ARMA };

	// @override
	virtual void	Unk_04(void) override;				// 004A1130
	virtual void	Unk_05(void) override;				// 004A0F30
	virtual bool	LoadForm(TESFile *arg) override;	// 004A1670
	virtual void	InitItem(void) override;			// 004A1440

	// @members

	// 0C
	struct Data
	{
		UInt8	priority[2];	// 00
		UInt8	unk02;			// 02
		UInt8	unk03;			// 03
		UInt8	unk04;			// 04
		UInt8	unk05;			// 05
		UInt8	unk06;			// 06
		UInt8	pad07;			// 07
		UInt32	unk08;			// 08
	};

	// @members
	Data						data;					// 28
	TESModelTextureSwap			models[2][2];			// 34
	UInt32						unkA4;					// A4
	UInt32						unkA8;					// A8
	UInt32						unkAC;					// AC
	UInt32						unkB0;					// B0
	BSTArray<TESRace *>			additionalRaces;		// B4
	BGSFootstepSet				* footstepSet;			// C0
	UInt32						unkC4;					// C4 - art object?

	TESObjectARMA() {}

	bool IsValidRace(TESRace *race) const;
	void GetNodeName(char *dstBuff, TESObjectREFR *refr, TESObjectARMO *armor, float weightOverride);
};

STATIC_ASSERT(sizeof(TESObjectARMA) == 0xC8);
