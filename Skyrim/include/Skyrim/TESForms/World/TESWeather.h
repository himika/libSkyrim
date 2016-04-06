#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/TESTexture.h"
#include "../../FormComponents/TESTexture1024.h"
#include "../../FormComponents/TESModel.h"
#include "../../FormComponents/TESAIForm.h"
#include "../../BSCore/BSTArray.h"
#include "BGSLightingTemplate.h"

class TESImageSpace;
class BGSShaderParticleGeometryData;
class BGSReferenceEffect;


/*==============================================================================
class TESWeather +0000 (_vtbl=01089D24)
0000: class TESWeather
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 760
class TESWeather : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::Weather };

	enum { kNumColorTypes = 17 };
	enum { kNumTimeOfDay = 4 };

	enum ColorTypes {
		kColorType_SkyUpper = 0,
		kColorType_FogNear = 1,
		kColorType_Unk = 2,
		kColorType_Ambient = 3,
		kColorType_Sunlight = 4,
		kColorType_Sun = 5,
		kColorType_Stars = 6,
		kColorType_SkyLower = 7,
		kColorType_Horizon = 8,
		kColorType_EffectLighting = 9,
		kColorType_CloudLODDiffuse = 10,
		kColorType_CloudLODAmbient = 11,
		kColorType_FogFar = 12,
		kColorType_SkyStatics = 13,
		kColorType_WaterMultiplier = 14,
		kColorType_SunGlare = 15,
		kColorType_MoonGlare = 16
	};

	enum TimeOfDay {
		kTime_Sunrise = 0,
		kTime_Day = 1,
		kTime_Sunset = 2,
		kTime_Night = 3
	};

	// 110
	struct ColorType
	{
		UInt32	time[kNumTimeOfDay];
	};

	// 13
	struct General
	{
		//UInt8	unk00[0x13];			// 00
		UInt8	unk00[3];
		UInt8	transDelta;				// Div 1000
		UInt8	sunGlare;				// Div 256
		UInt8	sunDamage;				// Div 256
		UInt16	pad06;
		UInt32	unk08;
		UInt32	unk0C;
		UInt8	unk10;
		UInt8	windDirection;			// Div (256/360)
		UInt8	windDirRange;			// Div (256/180)
		UInt8	pad13;
	};

	// 20
	struct FogDistance
	{
		float	nearDay;
		float	farDay;				// 10
		float	nearNight;			// 14
		float	farNight;			// 18
		float	powerDay;			// 1C
		float	powerNight;
		float	maxDay;
		float	maxNight;
	};

	struct CloudAlpha
	{
		float	time[kNumTimeOfDay];
	};

	// @members
	TESTexture1024						texture[0x20];						// 014
	UInt8								unk114[0x20];						// 114 - cleared to 0x7F
	UInt8								unk134[0x20];						// 134 - cleared to 0x7F
	UInt8								unk154[0x200];						// 154
	CloudAlpha							cloudAlpha[0x20];					// 354
	UInt32								unk554;								// 554
	General								general;							// 558
	//UInt8								pad56B;								// 56B
	FogDistance							fogDistance;						// 56C
	ColorType							colorTypes[kNumColorTypes];			// 58C
	TESAIForm::Data						unk69C;								// 69C
	BSTArray<void *>					unk6A4;								// 6A4
	UInt32								pad6B0;								// 6B0 - not init'd
	TESImageSpace						* imageSpaces[kNumTimeOfDay];		// 6B4
	BGSLightingTemplate::Data::Color	directionalAmbient[kNumTimeOfDay];	// 6C4
	TESModel							unk744;								// 744
	BGSShaderParticleGeometryData		* particleShader;					// 758
	BGSReferenceEffect					* referenceEffect;					// 75C - NNAM visual effect
};
STATIC_ASSERT(sizeof(TESWeather) == 0x760);
