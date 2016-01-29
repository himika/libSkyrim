#pragma once

#include "BSExtraData.h"
#include "../BSCore/BSFixedString.h"

class TESForm;
class TESQuest;
class BGSMessage;

class ExtraTextDisplayData : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::TextDisplayData };

	ExtraTextDisplayData();
	virtual ~ExtraTextDisplayData();

	BSFixedString	name;				// 08
	BGSMessage		* message;			// 0C
	TESQuest		* owner;			// 10
	SInt32			unk14;				// 14 -1 default -2 explicit name?
	float			extraHealthValue;	// 18
	UInt16			unk1C;				// 1C
	UInt16			pad1E;				// 1E

	DEFINE_MEMBER_FN(GenerateName, const char*, 0x00428CA0, TESForm * form, float extraHealthValue);
	DEFINE_MEMBER_FN(SetName, void, 0x00423140, const char * name);

	static ExtraTextDisplayData* Create();

};
