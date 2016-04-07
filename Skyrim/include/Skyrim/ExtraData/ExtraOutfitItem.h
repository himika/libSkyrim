#pragma once

#include "BSExtraData.h"
#include "../TESForms/Objects/BGSOutfit.h"

/*==============================================================================
class ExtraOutfitItem +0000 (_vtbl=01079298)
0000: class ExtraOutfitItem
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraOutfitItem : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::OutfitItem };

	virtual UInt32 GetType(void) const;				 // 00420DC0 { return kExtraTypeID; }

	// @members
	BGSOutfit	* outfit;		// 08;
};
STATIC_ASSERT(sizeof(ExtraOutfitItem) == 0x0C);
