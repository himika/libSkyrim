#pragma once

#include <Skyrim.h>

UInt8  SafeWrite8(UInt32 addr, UInt8 data);
UInt16 SafeWrite16(UInt32 addr, UInt16 data);
UInt32 SafeWrite32(UInt32 addr, UInt32 data);
void   SafeWriteBuf(UInt32 addr, void * data, UInt32 len, void * dst = nullptr);

// 5 bytes
UInt32 WriteRelJump(UInt32 jumpSrc, UInt32 jumpTgt);
UInt32 WriteRelCall(UInt32 jumpSrc, UInt32 jumpTgt);

// 6 bytes
UInt32 WriteRelJnz(UInt32 jumpSrc, UInt32 jumpTgt);
UInt32 WriteRelJle(UInt32 jumpSrc, UInt32 jumpTgt);

template <class TRet, class... TArg>
inline auto SafeWrite32(UInt32 jumpSrc, TRet(*fn)(TArg...)) -> decltype(fn)
{
	typedef decltype(fn) Fn;
	return (Fn)SafeWrite32(jumpSrc, (UInt32)fn);
}

template <class TRet, class... TArg>
inline auto WriteRelJump(UInt32 jumpSrc, TRet(*fn)(TArg...)) -> decltype(fn)
{
	typedef decltype(fn) Fn;
	return (Fn)WriteRelJump(jumpSrc, (UInt32)fn);
}

template <class TRet, class... TArg>
inline auto WriteRelCall(UInt32 jumpSrc, TRet(*fn)(TArg...)) -> decltype(fn)
{
	typedef decltype(fn) Fn;
	return (Fn)WriteRelCall(jumpSrc, (UInt32)fn);
}

template <class Ty, class TRet, class... TArg>
inline auto SafeWrite32(UInt32 jumpSrc, TRet(Ty::*fn)(TArg...)) -> decltype(fn)
{
	typedef decltype(fn) Fn;
	union
	{
		UInt32	u32;
		Fn		fn;
	} data;
	data.fn = fn;

	data.u32 = SafeWrite32(jumpSrc, data.u32);
	return data.fn;
}

template <class Ty, class TRet, class... TArg>
inline auto WriteRelJump(UInt32 jumpSrc, TRet(Ty::*fn)(TArg...)) -> decltype(fn)
{
	typedef decltype(fn) Fn;
	union
	{
		UInt32	u32;
		Fn		fn;
	} data;
	data.fn = fn;

	data.u32 = WriteRelJump(jumpSrc, data.u32);
	return data.fn;
}

template <class Ty, class TRet, class... TArg>
inline auto WriteRelCall(UInt32 jumpSrc, TRet(Ty::*fn)(TArg...)) -> decltype(fn)
{
	typedef decltype(fn) Fn;
	union
	{
		UInt32	u32;
		Fn		fn;
	} data;
	data.fn = fn;

	data.u32 = WriteRelCall(jumpSrc, data.u32);
	return data.fn;
}
