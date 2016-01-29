#include "Skyrim.h"
#include "Skyrim/ExtraData/ExtraCount.h"

static const UInt32	s_ExtraCountVtbl = 0x010791B8;

ExtraCount* ExtraCount::Create()
{
	ExtraCount* xCount = (ExtraCount*)BSExtraData::Create(sizeof(ExtraCount), s_ExtraCountVtbl);
	return xCount;
}
