#pragma once

#include "BSExtraData.h"

class ExtraCharge : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Charge };

	ExtraCharge();
	virtual ~ExtraCharge();

	float charge;

	static ExtraCharge* Create();
};
