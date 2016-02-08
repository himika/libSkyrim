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

struct TLSData
{
	UInt32	pad000[(0x2F8 - 0x000) >> 2];	// 000
	UInt8	consoleMode;					// 2F8
	UInt8	pad2F9[3];						// 2F9

	static TLSData * Get()
	{
		const UInt32 TlsIndex = *(UInt32 *)0x01BBEB54;
		TLSData * data = nullptr;

		__asm {
			mov			ecx, [TlsIndex]
			mov			edx, fs:[2Ch]
			mov			eax, [edx + ecx * 4]
			mov[data],	eax
		}

		return data;
	}
};

bool ConsoleManager::IsConsoleMode(void)
{
	return TLSData::Get()->consoleMode != 0;
}
