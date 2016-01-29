#pragma once

#include "BSExtraData.h"

class ExtraStartingPosition : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::StartingPosition };
	UInt32		unk08;
	UInt32		unk0C;
	UInt32		unk10;
	UInt32		unk14;
	UInt32		unk18;
	UInt32		unk1C;
	UInt32		unk20;

private:
	DEFINE_MEMBER_FN(ctor, void, 0x0040DC50, UInt32 unk);
};
