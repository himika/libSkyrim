#pragma once

// c:_skyrim\code\tesv\magic\EffectItem.h

class EffectSetting;

struct EffectItem
{
	// @members
	float			magnitude;		// 00
	UInt32			area;			// 04
	UInt32			duration;		// 08
	EffectSetting	* mgef;			// 0C
	float			cost;			// 10 - ?
	UInt32			unk14;			// 14 - ?


	EffectItem()
	{
		magnitude = 0;
		area = 0;
		duration = 0;
		mgef = nullptr;
		cost = 0.0;
		unk14 = 0;
	}


	DEFINE_MEMBER_FN_const(GetMagnitude, float, 0x00402F20);
	DEFINE_MEMBER_FN_const(GetArea, UInt32, 0x00402F50);
	DEFINE_MEMBER_FN_const(GetDuration, UInt32, 0x00402F70);
};
