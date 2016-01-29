#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraHealth +0000 (_vtbl=010791F8)
0000: class ExtraHealth
0000: |   class BSExtraData
==============================================================================*/
class ExtraHealth : public BSExtraData // Tempered
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Health };

	ExtraHealth();
	virtual ~ExtraHealth();

	enum { // Multiplier
		kHealthBase = 1
	};

	float health;

	static ExtraHealth* Create();
};
