#pragma once

#include "TESBoundObject.h"
#include "../../FormComponents/TESModel.h"
#include "../../FormComponents/TESFullName.h"
#include "../../FormComponents/TESProduceForm.h"

/*==============================================================================
class TESObjectTREE +0000 (_vtbl=010857AC)
0000: class TESObjectTREE
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESModel
0020: |   |   class BaseFormComponent
0034: |   class TESFullName
0034: |   |   class BaseFormComponent
003C: |   class TESProduceForm
003C: |   |   class BaseFormComponent
==============================================================================*/
// 84
class TESObjectTREE : public TESBoundObject,
	public TESModel,			// 20
	public TESFullName,			// 34
	public TESProduceForm		// 3C
{
public:
	enum { kTypeID = (UInt32)FormType::Tree };

	// @members
	struct Data4C
	{
		float	unk00;	// 00 - init'd to 1
		float	unk04;	// 04 - init'd to 1
		float	unk08;	// 08 - init'd to .03
		float	unk0C;	// 0C - init'd to .6
		float	unk10;	// 10 - init'd to .2
		float	unk14;	// 14 - init'd to .4
		float	unk18;	// 18 - init'd to .075
		float	unk1C;	// 1C - init'd to .025
		float	unk20;	// 20 - init'd to .035
		float	unk24;	// 24 - init'd to 1
		float	unk28;	// 28 - init'd to 1
		float	unk2C;	// 2C - init'd to 1
		UInt32	unk30;	// 30
		UInt32	unk34;	// 34 - init'd to 2
	};

	Data4C	unk4C;	// 4C
};
