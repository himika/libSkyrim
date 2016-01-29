#pragma once

#include "BSExtraData.h"

class ExtraCollisionData : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::CollisionData };

	ExtraCollisionData();
	virtual ~ExtraCollisionData();

	struct Data
	{
		UInt32	collisionLayer; // LayerId
	};

	Data	* data;
};
