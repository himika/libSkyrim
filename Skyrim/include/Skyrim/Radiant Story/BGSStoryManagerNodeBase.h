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
	virtual ~BGSStoryManagerNodeBase();						// 0043B990

	virtual void	Unk_04(void) override;					// 0063F280
	virtual void	Unk_05(void) override;					// 0063F400
	virtual bool	LoadForm(TESFile *mod) override;		// 0063F440
	virtual void	InitItem(void) override;				// 0063F2A0
	virtual void *	Unk_3D(void) override;					// 0043B230 { return &unk28; }


	// @members
	BGSStoryManagerBranchNode	* parent;	// 18 - PNAM
	BGSStoryManagerNodeBase		* child;	// 1C - SNAM
	UInt32						unk20;		// 20
	UInt32						unk24;		// 24
	void						* unk28;	// 28 - linked list - ctor 00A88CB0
};
STATIC_ASSERT(sizeof(BGSStoryManagerNodeBase) == 0x2C);
