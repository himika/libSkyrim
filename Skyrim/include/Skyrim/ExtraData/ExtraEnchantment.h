#pragma once

#include "BSExtraData.h"

class EnchantmentItem;

class ExtraEnchantment : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Enchantment };

	ExtraEnchantment();
	virtual ~ExtraEnchantment();

	EnchantmentItem*	enchant;		// 08
	UInt16				maxCharge;		// 0C
	UInt8				unk0E;			// 0E - usually 0
	UInt8				pad0F;			// 0F

	static ExtraEnchantment* Create();
};
