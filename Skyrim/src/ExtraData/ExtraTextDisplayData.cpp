#include "Skyrim.h"
#include "Skyrim/ExtraData/ExtraTextDisplayData.h"


ExtraTextDisplayData* ExtraTextDisplayData::Create()
{
	const UInt32 s_ExtraTextDisplayVtbl = 0x01079528;

	ExtraTextDisplayData* xText = (ExtraTextDisplayData*)BSExtraData::Create(sizeof(ExtraTextDisplayData), s_ExtraTextDisplayVtbl);
	xText->unk14 = -1;
	xText->extraHealthValue = 1.0;
	return xText;
}
