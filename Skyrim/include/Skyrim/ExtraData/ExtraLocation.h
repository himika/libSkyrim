#pragma once

#include "BSExtraData.h"

class BGSLocation;

class ExtraLocation : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Location };

	ExtraLocation(); // Related to protected/essential
	~ExtraLocation();

	BGSLocation* location;
};
