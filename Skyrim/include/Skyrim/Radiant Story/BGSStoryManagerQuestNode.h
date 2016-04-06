#pragma once

#include "BGSStoryManagerNodeBase.h"
#include "../BSCore/BSTArray.h"
#include "../BSCore/BSTHashMap.h"

/*==============================================================================
class BGSStoryManagerQuestNode +0000 (_vtbl=010C80DC)
0000: class BGSStoryManagerQuestNode
0000: |   class BGSStoryManagerNodeBase
0000: |   |   class BGSStoryManagerTreeForm
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
==============================================================================*/
// 88
class BGSStoryManagerQuestNode : public BGSStoryManagerNodeBase
{
public:
	enum { kTypeID = (UInt32)FormType::StoryQuestNode };

	// @members
	BSTArray<void *>			unk2C;	// 2C
	BSTHashMap<UInt32, void *>	unk38;	// 38 - sentinel 0126F760
	BSTHashMap<UInt32, void *>	unk58;	// 58 - sentinel 0126F764
	UInt32						unk78;	// 78 - init'd 1
	BSTArray<void *>			unk7C;	// 7C

private:
	DEFINE_MEMBER_FN(ctor, BGSStoryManagerQuestNode*, 0x00640C80);
};
STATIC_ASSERT(sizeof(BGSStoryManagerQuestNode) == 0x88);
