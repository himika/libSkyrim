#pragma once

#include "../BSCore/BSFixedString.h"


class BSTransformDeltaEvent
{
};


struct BSAnimationGraphEvent
{
	const BSFixedStringCI	* animName;
	void					* unk04;
	BSFixedStringCI			optionString;
};


class bhkCharacterMoveFinishEvent
{
};


struct BGSActorCellEvent
{
	enum
	{
		kFlags_Enter = 0,
		kFlags_Leave = 1
	};

	UInt32	refHandle;
	UInt32	cellID;
	UInt32	flags;
};


struct BGSActorDeathEvent
{
};
