#pragma once

#include "../BSCore/BSTArray.h"
#include "../BSCore/BSTSingleton.h"

class TESForm;

/*==============================================================================
class MagicFavorites +0000 (_vtbl=010CDFA8)
0000: class MagicFavorites
0004: |   struct BSTSingletonSDM<class MagicFavorites,struct BSTSingletonSDMOpStaticBuffer>
0004: |   |   struct BSTSingletonSDMBase<struct BSTSDMTraits<class MagicFavorites,struct BSTSingletonSDMOpStaticBuffer<class MagicFavorites> > >
0004: |   |   |   struct BSTSDMTraits<class MagicFavorites,struct BSTSingletonSDMOpStaticBuffer<class MagicFavorites> >
0005: |   |   |   struct BSTSingletonSDMOpStaticBuffer<class MagicFavorites>
==============================================================================*/
// 20
class MagicFavorites : public BSTSingletonSDM<MagicFavorites>
{
public:
	virtual	~MagicFavorites();			// 00693C50

	void		SetHotkey(TESForm * form, SInt8 idx);
	void		ClearHotkey(SInt8 idx);
	TESForm	*	GetSpell(SInt8 idx);
	bool		IsFavorited(TESForm * form);

	static MagicFavorites * GetSingleton(void)
	{
		return *((MagicFavorites **)0x01B2E39C);
	}

	// @members
	//void				** _vtbl;	// 00
	BSTArray<TESForm *>	spells;		// 08 - sorted
	BSTArray<TESForm *>	hotkeys;	// 14
};
STATIC_ASSERT(sizeof(MagicFavorites) == 0x20);
