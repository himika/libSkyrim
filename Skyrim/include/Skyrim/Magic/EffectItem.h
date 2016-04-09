#pragma once

// c:_skyrim\code\tesv\magic\EffectItem.h

#include "../FormComponents/Condition.h"

class EffectSetting;

struct EffectItem
{
	EffectItem() : magnitude(0.0f), area(0), duration(0), mgef(nullptr), cost(0.0f), conditions()
	{
	}

	// @members
	float			magnitude;		// 00
	UInt32			area;			// 04
	UInt32			duration;		// 08
	EffectSetting	* mgef;			// 0C
	float			cost;			// 10 -
	Condition		conditions;		// 14 -


	DEFINE_MEMBER_FN_const(GetMagnitude, float, 0x00402F20);
	DEFINE_MEMBER_FN_const(GetArea, UInt32, 0x00402F50);
	DEFINE_MEMBER_FN_const(GetDuration, UInt32, 0x00402F70);
};
