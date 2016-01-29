#pragma once

#include "BGSStoryManagerTreeForm.h"

class BGSStoryManagerBranchNode;

/*==============================================================================
class BGSStoryManagerNodeBase +0000 (_vtbl=0107B50C)
0000: class BGSStoryManagerNodeBase
0000: |   class BGSStoryManagerTreeForm
0000: |   |   class TESForm
0000: |   |   |   class BaseFormComponent
==============================================================================*/
// 2C
class BGSStoryManagerNodeBase : public BGSStoryManagerTreeForm
{
public:
	BGSStoryManagerBranchNode	* unk18;	// 18
	BGSStoryManagerNodeBase		* unk1C;	// 1C
	UInt32	unk20;							// 20
	UInt32	unk24;							// 24
	void	* unk28;						// 28 - linked list
};
STATIC_ASSERT(sizeof(BGSStoryManagerNodeBase) == 0x2C);
