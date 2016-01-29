#pragma once

#include "../BSCore/BSTArray.h"
#include "BGSStoryManagerNodeBase.h"

/*==============================================================================
class BGSStoryManagerBranchNode +0000 (_vtbl=0107B66C)
0000: class BGSStoryManagerBranchNode
0000: |   class BGSStoryManagerNodeBase
0000: |   |   class BGSStoryManagerTreeForm
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
==============================================================================*/
// 38
class BGSStoryManagerBranchNode : public BGSStoryManagerNodeBase
{
public:
	enum { kTypeID = (UInt32)FormType::StoryBranchNode };

	virtual UInt32	Unk_3B(void) override;		// 00965780 { return unk2C.size(); }


	BSTArray<void*>	unk2C;	// 2C
};
STATIC_ASSERT(sizeof(BGSStoryManagerBranchNode) == 0x38);
