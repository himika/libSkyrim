#pragma once

#include "BSExtraData.h"

class ExtraInteraction : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Interaction };
};
