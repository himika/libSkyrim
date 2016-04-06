#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../BSCore/BSTArray.h"

/*==============================================================================
class BGSOutfit +0000 (_vtbl=01081A44)
0000: class BGSOutfit
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 20
class BGSOutfit : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::Outfit };

	virtual void			Unk_05(void);								// 
	virtual bool			LoadForm(TESFile *mod);						// 
	virtual void			InitItem(void);								// 

	void Calcurate(UInt16 level, BSTArray<TESForm*> &result, bool unk1 = false, bool unk2 = true) const;

	// @members
	BSTArray<TESForm *>	armorOrLeveledItemArray;	// 14
};
STATIC_ASSERT(sizeof(BGSOutfit) == 0x20);
