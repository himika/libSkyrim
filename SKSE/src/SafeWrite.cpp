#include "SKSE/SafeWrite.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


template<class Ty>
static inline Ty SafeWrite_Impl(std::size_t addr, Ty data)
{
	DWORD	oldProtect = 0;
	Ty		oldVal = 0;

	if (VirtualProtect((void *)addr, 4, PAGE_EXECUTE_READWRITE, &oldProtect))
	{
		Ty *p = (Ty*)addr;
		oldVal = *p;
		*p = data;
		VirtualProtect((void *)addr, 4, oldProtect, &oldProtect);
	}

	return oldVal;
}


UInt8 SafeWrite8(UInt32 addr, UInt8 data)
{
	return SafeWrite_Impl(addr, data);
}


UInt16 SafeWrite16(UInt32 addr, UInt16 data)
{
	return SafeWrite_Impl(addr, data);
}


UInt32 SafeWrite32(UInt32 addr, UInt32 data)
{
	return SafeWrite_Impl(addr, data);
}


void SafeWriteBuf(UInt32 addr, void * data, UInt32 len, void * dst)
{
	DWORD	oldProtect = 0;

	if (VirtualProtect((void *)addr, len, PAGE_EXECUTE_READWRITE, &oldProtect))
	{
		if (dst)
			memcpy(dst, (void *)addr, len);
		memcpy((void *)addr, data, len);
		VirtualProtect((void *)addr, len, oldProtect, &oldProtect);
	}
}


UInt32 WriteRelJump(UInt32 jumpSrc, UInt32 jumpTgt)
{
	// jmp rel32
	SafeWrite8(jumpSrc, 0xE9);
	jumpSrc += 1;
	UInt32 oldTgt = SafeWrite32(jumpSrc, jumpTgt - jumpSrc - 4);
	return jumpSrc + oldTgt + 4;
}


UInt32 WriteRelCall(UInt32 jumpSrc, UInt32 jumpTgt)
{
	// call rel32
	SafeWrite8(jumpSrc, 0xE8);
	jumpSrc += 1;
	UInt32 oldTgt = SafeWrite32(jumpSrc, jumpTgt - jumpSrc - 4);
	return jumpSrc + oldTgt + 4;
}

UInt32 WriteRelJnz(UInt32 jumpSrc, UInt32 jumpTgt)
{
	// jnz rel32
	SafeWrite16(jumpSrc, 0x850F);
	jumpSrc += 2;
	UInt32 oldTgt = SafeWrite32(jumpSrc, jumpTgt - jumpSrc - 4);
	return jumpSrc + oldTgt + 4;
}

UInt32 WriteRelJle(UInt32 jumpSrc, UInt32 jumpTgt)
{
	// jle rel32
	SafeWrite16(jumpSrc, 0x8E0F);
	jumpSrc += 2;
	UInt32 oldTgt = SafeWrite32(jumpSrc, jumpTgt - jumpSrc - 4);
	return jumpSrc + oldTgt + 4;
}
