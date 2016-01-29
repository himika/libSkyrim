#pragma once

#include "BSExtraData.h"

class ExtraLightData : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::LightData };

	ExtraLightData();
	virtual ~ExtraLightData();

	float	unk08;
	UInt32	unk0C;
	UInt32	unk10;
	float	unk14;
	UInt8	unk18;
	UInt8	pad19[3];
};
