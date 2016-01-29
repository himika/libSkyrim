#pragma once

#include "BSExtraData.h"
#include "../Misc/InventoryChanges.h"

/*==============================================================================
class ExtraContainerChanges +0000 (_vtbl=01079D4C)
0000: class ExtraContainerChanges
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraContainerChanges : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::ContainerChanges };

	explicit ExtraContainerChanges(InventoryChanges *a_changes)
	{
		ctor(a_changes);
	}

	virtual ~ExtraContainerChanges()					// 00423760
	{
		if (changes)
			delete changes;
	}

	// @override
	virtual UInt32 GetType(void) const override;		// 00420CB0 { return kExtraTypeID; }

	// @members;
	//void				** _vtbl;		// 00 - 01079D4C
	InventoryChanges	* changes;		// 08

private:
	DEFINE_MEMBER_FN(ctor, ExtraContainerChanges *, 0x00422670, InventoryChanges *a_changes);
};
