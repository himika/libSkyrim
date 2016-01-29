#pragma once

#include "BSExtraData.h"

// 28
class ExtraSayTopicInfo : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::SayTopicInfo };

	ExtraSayTopicInfo();
	virtual ~ExtraSayTopicInfo();

	UInt32	unk08;
	UInt32	unk0C;
	bool	unk10;
	UInt32	unk14;
	UInt32	unk18;
	UInt32	unk1C;
	UInt8	unk20;
	UInt32	unk24;

	DEFINE_MEMBER_FN(ctor1, ExtraSayTopicInfo*, 0x422C80);
	DEFINE_MEMBER_FN(ctor2, ExtraSayTopicInfo*, 0x422CB0, UInt32);
};
