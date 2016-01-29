#include "Skyrim.h"
#include "Skyrim/ExtraData/ExtraCannotWear.h"


ExtraCannotWear* ExtraCannotWear::Create()
{
	const UInt32 vtbl = 0x010791E8;

	return (ExtraCannotWear*)BSExtraData::Create(sizeof(ExtraCannotWear), vtbl);
}
