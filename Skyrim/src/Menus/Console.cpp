#include "Skyrim/Menus/Console.h"
#include "Skyrim/Forms/TESObjectREFR.h"

RefHandle & Console::pickedRefHandle = *(RefHandle*)0x01B3E6EC;

RefHandle Console::GetPickedRefHandle()
{
	return pickedRefHandle;
}

TESObjectREFR * Console::GetPickedReference()
{
	TESObjectREFR *refr = nullptr;

	if (pickedRefHandle && pickedRefHandle != g_invalidRefHandle)
	{
		TESObjectREFR::LookupByHandle(pickedRefHandle, refr);
	}

	return refr;
}
