#include "Skyrim.h"
#include "Skyrim/ExtraData/ExtraHealth.h"

static const UInt32 s_ExtraHealthVtbl = 0x010791F8;

ExtraHealth* ExtraHealth::Create()
{
	ExtraHealth* xHealth = (ExtraHealth*)BSExtraData::Create(sizeof(ExtraHealth), s_ExtraHealthVtbl);
	xHealth->health = 1;
	return xHealth;
}
