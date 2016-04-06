#pragma once

#include "TESBoundObject.h"
#include "../../FormComponents/TESLeveledList.h"

/*==============================================================================
class TESLevItem +0000 (_vtbl=01083504)
0000: class TESLevItem
0000: |   class TESBoundObject
0000: |   |   class TESObject
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0020: |   class TESLeveledList
0020: |   |   class BaseFormComponent
==============================================================================*/
// 34
class TESLevItem :
	public TESBoundObject,			// 00
	public TESLeveledList			// 20
{
public:
	enum { kTypeID = (UInt32)FormType::LeveledItem };

	virtual ~TESLevItem();												// 0049BA20

	// @override class TESBoundObject : (vtbl=01083504)
	virtual bool	LoadForm(TESFile *mod) override;					// 0049BB30
	virtual void	SaveBuffer(BGSSaveFormBuffer *buf) override;		// 0049B9F0
	virtual void	LoadBuffer(BGSLoadFormBuffer *buf) override;		// 0049BE40
	virtual void	Unk_12(BGSLoadFormBuffer *buf) override;			// 0049B410
	virtual void	InitItem(void) override;							// 0049BA60

	// @override class TESLeveledList : (vtbl=010834E0)
	virtual SInt32	GetLevDifferenceMax(void) override;					// 0049BA90 { return [012E72C4]; } Gameplay => Setting => fLevItemLevelDifferenceMax
	virtual bool	IsValidLevItem(FormType type) override;				// 0049B9E0 { return IsValidInventoryItem(arg1); } not used ?

	DEFINE_STATIC_FN(IsValidInventoryItem, bool, 0x0044F250, UInt32 arg);	// { return arg == (17, 1A, 1B, 1E, 1F, 20, 21, 29, 2A, 2D, 2E, 30, 31, 34, 35) ? true : false; }

};
STATIC_ASSERT(sizeof(TESLevItem) == 0x34);
