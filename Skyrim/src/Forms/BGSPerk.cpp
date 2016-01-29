#include "Skyrim/Forms/BGSPerk.h"

void __declspec(naked) BGSEntryPointPerkEntry::Calcurate(BGSEntryPointPerkEntry::EntryPointType, TESObjectREFR *source, ...)
{
	__asm
	{
		mov		eax, 0x0054B400
		jmp		eax
	}
}
