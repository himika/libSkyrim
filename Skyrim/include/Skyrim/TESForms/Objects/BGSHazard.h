#pragma once

#include "TESBoundObject.h"
#include "../../FormComponents/TESFullName.h"
#include "../../FormComponents/TESModel.h"
#include "../../FormComponents/BGSPreloadable.h"
#include "../../FormComponents/TESImageSpaceModifiableForm.h"

/*==============================================================================
class BGSHazard +0000 (_vtbl=01081604)
0000: class BGSHazard
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
0040: |   class TESImageSpaceModifiableForm
0040: |   |   class BaseFormComponent
==============================================================================*/
// 70
class BGSHazard : public TESBoundObject,
	public TESFullName,						// 20
	public TESModel,						// 28
	public BGSPreloadable,					// 3C
	public TESImageSpaceModifiableForm		// 40
{
public:
	enum { kTypeID = (UInt32)FormType::Hazard };

	// @members

	// 28
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
	};

	Data	unk48;	// 48
};
STATIC_ASSERT(sizeof(BGSHazard) == 0x70);
