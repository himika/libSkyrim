#pragma once

#include "IMenu.h"

/*==============================================================================
class MagicItemData +0000 (_vtbl=010E6508)
0000: class MagicItemData
==============================================================================*/
// 20
class MagicItemData
{
public:
	virtual ~MagicItemData();							// 00872DF0

	// @override
	virtual const char *	GetName(void);				// 01 00872CC0
	virtual UInt32			GetCount(void);				// 02 00CAC8A0 { return 0x00000001; }
	virtual UInt32			GetEquipState(void);		// 03 00872CE0
	virtual UInt32			GetFilterFlag(void);		// 04 00873660
	virtual UInt32			GetFavorite(void);			// 05 00873740
	virtual bool			GetEnabled(void);			// 06 00872CD0

	// @members
	//void			** _vtbl;	// 00 - 010E6508
	UInt32			unk04;		// 04 - init'd 0
	UInt16			unk08;		// 08 - init'd 0
	UInt16			unk0A;		// 0A - init'd 0
	TESForm			* form;		// 0C - init'd pForm
#pragma pack(4)
	GFxValue		fxValue;	// 10
#pragma pack()

private:
	DEFINE_MEMBER_FN(ctor, MagicItemData *, 0x00873D70, GFxMovieView ** movieView, TESForm * pForm, int unk);
};
STATIC_ASSERT(sizeof(MagicItemData) == 0x20);
STATIC_ASSERT(offsetof(MagicItemData, form) == 0x0C);
STATIC_ASSERT(offsetof(MagicItemData, fxValue) == 0x10);




/*==============================================================================
class MagicMenu +0000 (_vtbl=010E6594)
0000: class MagicMenu
0000: |   class IMenu
0000: |   |   class FxDelegateHandler
0000: |   |   |   class GRefCountBase<class FxDelegateHandler,2>
0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   |   |   class GRefCountImpl
0000: |   |   |   |   |   |   class GRefCountImplCore
==============================================================================*/
class MagicMenu : public IMenu
{
	// MagicMenu
	// unk0C - 0
	// Flags - 0xA489
	// unk14 - 3
};
