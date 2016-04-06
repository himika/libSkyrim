#include "Skyrim.h"
#include "Skyrim/ExtraData/ExtraAliasInstanceArray.h"

NiCriticalSection & ExtraAliasInstanceArray::ms_lock = *(NiCriticalSection *)0x012E350C;
