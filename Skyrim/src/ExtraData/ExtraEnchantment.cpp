#include "Skyrim.h"
#include "Skyrim/ExtraData/ExtraEnchantment.h"

static const UInt32 s_ExtraEnchantmentVtbl = 0x01079318;

ExtraEnchantment* ExtraEnchantment::Create()
{
	ExtraEnchantment* xEnchantment = (ExtraEnchantment*)BSExtraData::Create(sizeof(ExtraEnchantment), s_ExtraEnchantmentVtbl);
	xEnchantment->enchant = nullptr;
	xEnchantment->maxCharge = 0;
	xEnchantment->unk0E = 0;
	return xEnchantment;
}
