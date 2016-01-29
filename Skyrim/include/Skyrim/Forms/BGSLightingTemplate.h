#pragma once

#include "TESForm.h"

/*==============================================================================
class BGSLightingTemplate +0000 (_vtbl=010864F4)
0000: class BGSLightingTemplate
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 94
class BGSLightingTemplate : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::LightingTemplate };

	// 5C
	struct Data
	{
		// 20 - used elsewhere
		struct Color
		{
			UInt32	x[2];				// 00 - init'd to 00FFFFFF
			UInt32	y[2];
			UInt32	z[2];
			UInt32	specular;			// 18 - init'd to 0
			float	fresnelPower;		// 1C - init'd to 1
		};

		UInt32	unk00;			// 00 - init'd to 0
		UInt32	unk04;			// 04 - init'd to 0
		UInt32	unk08;			// 08 - init'd to 0
		UInt32	unk0C;			// 0C - init'd to 0
		UInt32	unk10;			// 10 - init'd to 0
		UInt32	unk14;			// 14 - init'd to 0
		UInt32	unk18;			// 18 - init'd to 0
		float	unk1C;			// 1C - init'd to 1
		UInt32	unk20;			// 20 - init'd to 0
		float	unk24;			// 24 - init'd to 1
		Color	unk28;			// 28
		UInt32	unk48;			// 48 - init'd to 0
		float	unk4C;			// 4C - init'd to 1
		float	lodStartFade;	// 50 - fLightLODStartFade
		float	lodStopFade;	// 54 - fLightLODStartFade + fLightLODRange
		UInt32	unk58;			// 58 - init'd to 0000079F
	};

	Data			unk14;	// 14
	UInt32			pad70;	// 70
	Data::Color		unk74;	// 74
};
STATIC_ASSERT(sizeof(BGSLightingTemplate) == 0x94);
