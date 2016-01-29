#pragma once

#include "BSExtraData.h"

class ExtraFollowerSwimBreadcrumbs : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::FollowerSwimBreadcrumbs };

	ExtraFollowerSwimBreadcrumbs();
	virtual ~ExtraFollowerSwimBreadcrumbs();

	UInt32	unk08;
	float	unk0C; // Looks like a position?
	float	unk10;
	float	unk14;
};
