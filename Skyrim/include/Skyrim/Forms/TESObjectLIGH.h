#pragma once

#include "TESBoundAnimObject.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/TESModelTextureSwap.h"
#include "../FormComponents/TESIcon.h"
#include "../FormComponents/BGSMessageIcon.h"
#include "../FormComponents/TESWeightForm.h"
#include "../FormComponents/TESValueForm.h"
#include "../FormComponents/BGSDestructibleObjectForm.h"
#include "../FormComponents/BGSEquipType.h"

/*==============================================================================
class TESObjectLIGH +0000 (_vtbl=01083944)
0000: class TESObjectLIGH
0000: |   class TESBoundAnimObject
0000: |   |   class TESBoundObject
0000: |   |   |   class TESObject
0000: |   |   |   |   class TESForm
0000: |   |   |   |   |   class BaseFormComponent
0020: |   class TESFullName
0020: |   |   class BaseFormComponent
0028: |   class TESModelTextureSwap
0028: |   |   class TESModel
0028: |   |   |   class BaseFormComponent
0044: |   class TESIcon
0044: |   |   class TESTexture
0044: |   |   |   class BaseFormComponent
004C: |   class BGSMessageIcon
004C: |   |   class BaseFormComponent
0058: |   class TESWeightForm
0058: |   |   class BaseFormComponent
0060: |   class TESValueForm
0060: |   |   class BaseFormComponent
0068: |   class BGSDestructibleObjectForm
0068: |   |   class BaseFormComponent
0070: |   class BGSEquipType
0070: |   |   class BaseFormComponent
==============================================================================*/
// B4
class TESObjectLIGH : public TESBoundAnimObject,
	public TESFullName,						// 20
	public TESModelTextureSwap,				// 28
	public TESIcon,							// 44
	public BGSMessageIcon,					// 4C
	public TESWeightForm,					// 58
	public TESValueForm,					// 60
	public BGSDestructibleObjectForm,		// 68
	public BGSEquipType						// 70
{
public:
	enum { kTypeID = (UInt32)FormType::Light };

	// @members

	// 28
	struct Data78
	{
		UInt32	unk00;	// 00
		UInt32	unk04;	// 04
		UInt32	unk08;	// 08
		UInt32	unk0C;	// 0C
		UInt32	unk10;	// 10
		float	unk14;	// 14 - 90
		float	unk18;	// 18 - .001
		UInt32	unk1C;	// 1C
		UInt32	unk20;	// 20
		UInt32	unk24;	// 24
	};

	struct DataA8
	{
		UInt32	unk0;	// 0
		UInt32	unk4;	// 4
		UInt32	unk8;	// 8
	};

	Data78	unk78;	// 78
	float	unkA0;	// A0 - 1
	UInt32	unkA4;	// A4
	DataA8	unkA8;	// A8
};
STATIC_ASSERT(sizeof(TESObjectLIGH) == 0xB4);
