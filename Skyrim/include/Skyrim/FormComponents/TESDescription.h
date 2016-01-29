#pragma once

#include "BaseFormComponent.h"

class BSString;
class TESForm;

// 0C
class TESDescription : public BaseFormComponent
{
public:
	DEFINE_MEMBER_FN(Get, void, 0x0044FB70, BSString * out, TESForm * parent, UInt32 fieldType);

	// @members
	UInt32	unk04;	// 04
	UInt32	unk08;	// 08 - init'd to FFFFFFFF
};
