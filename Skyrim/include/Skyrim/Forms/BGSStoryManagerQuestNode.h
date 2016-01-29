#pragma once

#include "BGSStoryManagerNodeBase.h"
#include "../BSCore/BSTArray.h"

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

	// 20
	struct Data38
	{
		UInt8	data[0x20];	// ###
	};

	// 20
	struct Data58
	{
		UInt8	data[0x20];	// ###
	};

	BSTArray<void*>	unk2C;	// 2C
	Data38			unk38;	// 38
	Data58			unk58;	// 58
	UInt32			unk78;	// 78
	BSTArray<void*>	unk7C;	// 7C
};
STATIC_ASSERT(sizeof(BGSStoryManagerQuestNode) == 0x88);
