#pragma once

#include "BSExtraData.h"

/*==============================================================================
class ExtraTimeLeft +0000 (_vtbl=01079218)
0000: class ExtraTimeLeft
0000: |   class BSExtraData
==============================================================================*/
class ExtraTimeLeft : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::TimeLeft };

	ExtraTimeLeft();
	virtual ~ExtraTimeLeft();

	float time;

	static ExtraTimeLeft* Create(float time = 1.0f);
};
