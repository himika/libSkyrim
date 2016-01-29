#pragma once

#include "BaseFormComponent.h"

class EnchantmentItem;

// C
class TESEnchantableForm : public BaseFormComponent
{
public:
	virtual UInt16	GetUnk08(void);		// return unk08

	EnchantmentItem*	enchantment;	// 04 - init'd to 0
	UInt16				unk08;			// 08 - init'd to 3
	UInt16				maxCharge;
};

