#pragma once

#include "../NetImmerse/NiExtraData.h"
#include "BSFaceGenKeyframe.h"


/*==============================================================================
class BSFaceGenAnimationData +0000 (_vtbl=010BE01C)
0000: class BSFaceGenAnimationData
0000: |   class NiExtraData
0000: |   |   class NiObject
0000: |   |   |   class NiRefObject
==============================================================================*/
// 1B4
class BSFaceGenAnimationData : public NiExtraData
{
public:
	enum {
		kKeyframeType_Expression = 0,
		kKeyframeType_Unk1,
		kKeyframeType_Modifier,
		kKeyframeType_Phoneme,
		kKeyframeType_Reset = 255,
		kNumKeyframes = 12
	};

	virtual ~BSFaceGenAnimationData();					// 0059E2F0

	// @override
	virtual NiRTTI *	GetRTTI(void) override;			// 0059E010 { return 0x01B1A294; }

	// @members
	UInt32	unk0C;							// 0C
	BSFaceGenKeyframeMultiple	keyFrames[kNumKeyframes];	// 10
	float	unk130;							// 130
	float	unk134;							// 134
	float	unk138;							// 138
	UInt32	unk13C;							// 13C
	UInt32	unk140;							// 140
	UInt32	unk144;							// 144
	UInt32	unk148;							// 148
	float	unk14C;							// 14C
	float	unk150;							// 150
	UInt32	unk154;							// 154
	UInt8	unk158;							// 158
	UInt8	unk159;							// 159
	UInt8	unk15A;							// 15A
	UInt8	unk15B;							// 15B
	UInt32	unk15C;							// 15C
	UInt32	unk160;							// 160
	UInt32	unk164;							// 164
	UInt32	unk168;							// 168
	UInt32	unk16C;							// 16C
	UInt32	unk170;							// 170
	UInt32	unk174;							// 174
	UInt32	unk178;							// 178
	UInt32	unk17C;							// 17C
	UInt32	unk180;							// 180
	UInt32	unk184;							// 184
	UInt32	unk188;							// 188
	float	unk18C;							// 18C
	float	unk190;							// 190
	float	unk194;							// 194
	float	unk198;							// 198
	UInt8	unk19C;							// 19C
	UInt8	unk19D;							// 19D
	UInt8	unk19E;							// 19E
	UInt8	unk19F;							// 19F
	UInt8	unk1A0;							// 1A0
	UInt8	unk1A1;							// 1A1
	UInt8	unk1A2;							// 1A2
	UInt8	unk1A3;							// 1A3
	UInt8	unk1A4;							// 1A4
	UInt8	unk1A5;							// 1A5
	UInt8	overrideFlag;					// 1A6
	UInt8	unk1A7;							// 1A7
	UInt32	unk1A8[(0x1B4 - 0x1A8) >> 2];	// 1A8

	DEFINE_MEMBER_FN(SetExpression, void, 0x0059DB90, UInt32 type, float value);
	DEFINE_MEMBER_FN(SetPhonome, void, 0x005352D0, UInt32 type, float value);
	DEFINE_MEMBER_FN(SetModifier, void, 0x005352A0, UInt32 type, float value);
	DEFINE_MEMBER_FN(SetCustom, void, 0x00535300, UInt32 type, float value);
	DEFINE_MEMBER_FN(Reset, void, 0x0059E320, float value, UInt8 unk1, UInt8 unk2, UInt8 unk3, UInt8 unk4);
};

STATIC_ASSERT(offsetof(BSFaceGenAnimationData, keyFrames) == 0x10);
STATIC_ASSERT(offsetof(BSFaceGenAnimationData, overrideFlag) == 0x1A6);
STATIC_ASSERT(sizeof(BSFaceGenAnimationData) == 0x1B4);
