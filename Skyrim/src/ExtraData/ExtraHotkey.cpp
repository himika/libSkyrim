#include "Skyrim.h"
#include "Skyrim/ExtraData/ExtraHotkey.h"

static const UInt32 s_ExtraHotkeyVtbl = 0x01079258;

ExtraHotkey* ExtraHotkey::Create()
{
	ExtraHotkey* xHotkey = (ExtraHotkey*)BSExtraData::Create(sizeof(ExtraHotkey), s_ExtraHotkeyVtbl);
	xHotkey->hotkey = -1;
	return xHotkey;
}
