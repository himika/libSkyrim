#pragma once

#include "BSExtraData.h"

class ExtraFollower : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Follower };

	ExtraFollower();
	virtual ~ExtraFollower();

	UInt32	unk08;		// 08
	UInt32	unk0C;		// 0C
	UInt32	followers;	// 10
};
