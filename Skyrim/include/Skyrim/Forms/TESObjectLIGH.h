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

	enum Flag
	{
		kFlag_Dynamic				= 0x01,
		kFlag_CanBeCarried			= 0x02,
		kFlag_Flicker				= 0x08,
		kFlag_Pulse					= 0x80,
		kFlag_Omnidirectional		= 0x0000,
		kFlag_ShadowSpotlight		= 0x0400,
		kFlag_ShadowHemisphere		= 0x0800,
		kFlag_ShadowOmniDirectional = 0x1000,

		kFlag_PortalStrict			= 0x2000
	};

	// 28
	struct Data78
	{
		SInt32	time;	// 00 - Time
		SInt32	radius;	// 04 - Radius
		UInt8	red;	// 08 - Color - Red
		UInt8	green;	// 09 -       - Green
		UInt8	blue;	// 0A -       - Blue
		UInt8	unk0B;	// 0B -       - Unknown
		UInt32	flags;	// 0C - Flags
		UInt32	unk10;	// 10 - Falloff Exponent
		float	unk14;	// 14 - FOV - 90
		float	unk18;	// 18 - Near Clip - .001
		UInt32	unk1C;	// 1C - Flicker Effect - Period
		UInt32	unk20;	// 20 -                - Intensity Amplitude
		UInt32	unk24;	// 24                  - Movement Amplitude
	};

	struct DataA8
	{
		UInt32	unk0;	// 0
		UInt32	unk4;	// 4
		UInt32	unk8;	// 8
	};

	virtual ~TESObjectLIGH();											// 0049D470

	// @override class TESBoundAnimObject : (vtbl=01083944)
	virtual void	Unk_04(void) override;								// 0049C7C0
	virtual bool	LoadForm(TESFile *mod) override;					// 0049CFF0
	virtual void	SaveBuffer(BGSSaveFormBuffer *buf) override;		// 0049C750
	virtual void	LoadBuffer(BGSLoadFormBuffer *buf) override;		// 0049C770
	virtual void	InitItem(void) override;							// 0049C820
	virtual bool	ActivateReference(TESObjectREFR* targetRef, TESObjectREFR* activatorRef, UInt32 arg2, UInt32 arg3, UInt32 arg4) override;	// 0049CAD0
	// @override class TESObject
	virtual void	Unk_41(void * arg) override;						// 0049CA90
	virtual void *	Unk_48(void) override;								// 0049C9A0
	// @overrride class TESBoundObject
	virtual UInt32	Unk_4B(UInt32 arg) override;						// 0049E1D0

	// @override class BGSEquipType : (vtbl=01083AB8)
	virtual	BGSEquipSlot *	GetEquipSlot(void) override;					// 0054C810
	virtual	void			SetEquipSlot(BGSEquipSlot *type) override;		// 00588F30 { return; }
	
	bool CanBeCarried() const {
		return (unk78.flags & kFlag_CanBeCarried) != 0;
	}

	// @members
	Data78	unk78;		// 78 - DATA
	float	fadeValue;	// A0 - FNAM
	UInt32	unkA4;		// A4 - SNAM - sound?
	DataA8	unkA8;		// A8
};
STATIC_ASSERT(sizeof(TESObjectLIGH) == 0xB4);
