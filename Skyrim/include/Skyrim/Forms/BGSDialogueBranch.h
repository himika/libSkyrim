#pragma once

#include "TESForm.h"

/*==============================================================================
class BGSDialogueBranch +0000 (_vtbl=010A1FB4)
0000: class BGSDialogueBranch
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 24
class BGSDialogueBranch : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::DialogueBranch };

	UInt32	unk14;		// 14 - init'd to 1
	TESForm	* unk18;	// 18 - init'd to 0, TESQuest
	TESForm	* unk1C;	// 1C - init'd to 0, starting topic (type 4D)
	UInt32	unk20;		// 20 - init'd to 0
};
STATIC_ASSERT(sizeof(BGSDialogueBranch) == 0x24);
