#include "Skyrim/TESForms/Character/BGSPerk.h"

void __declspec(naked) BGSEntryPointPerkEntry::Calculate(BGSEntryPointPerkEntry::EntryPointType, TESObjectREFR *source, ...)
{
	__asm
	{
		mov		eax, 0x0054B400
		jmp		eax
	}
}


// 10
struct UnkEntryPointPerkData
{
	const char *	description;	// 00
	UInt8			numArgs;		// 04
	const char **	argNames;		// 08
	UInt8			functionType;	// 0C - (BGSEntryPointFunctionData::FunctionType - 1)
};

static UnkEntryPointPerkData *s_pEntryData = (UnkEntryPointPerkData*)0x012560D0;
