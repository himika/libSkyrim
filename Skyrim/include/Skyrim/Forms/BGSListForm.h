#pragma once

#include "TESForm.h"
#include "../BSCore/BSTArray.h"

#include <functional>

/*==============================================================================
class BGSListForm +0000 (_vtbl=0108D12C)
0000: class BGSListForm
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 28
class BGSListForm : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::List };

	UInt32 GetSize() const;
	
	TESForm* Find(std::function<bool(TESForm *)> fn) const;

	DEFINE_MEMBER_FN(AddForm, void, 0x004FB380, TESForm * form);

public:
	// @members
	//void **			_vtbl;		// 00 - 0108D12C
	BSTArray<TESForm*>	forms;		// 14
	BSTArray<UInt32> *	addedForms;	// 20
	UInt32				unk24;		// 24
};
STATIC_ASSERT(sizeof(BGSListForm) == 0x28);
