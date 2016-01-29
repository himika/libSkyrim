#pragma once

#include "BSExtraData.h"

class BGSEncounterZone;

class ExtraEncounterZone : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::EncounterZone };

	ExtraEncounterZone();
	virtual ~ExtraEncounterZone();

	BGSEncounterZone* encounterZone;
};
