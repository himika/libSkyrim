#pragma once

#include <SKSE/SafeWrite.h>

#define HookRelCall(addr, fn)	HookUtil::HookMaker<addr>::Install(fn);
#define HookVTable(vptr, n, fn)	HookUtil::HookMakerVTable<vptr, n>::Install(fn);

template <typename T>
UInt32 GetFnAddr(T src)
{
	union
	{
		UInt32	u32;
		T		t;
	} data;

	data.t = src;

	return data.u32;
}

namespace HookUtil
{
	using Callback = void(*)(std::size_t, std::size_t *);

	template<typename T>
	static void __declspec(naked) HookRelCall_Impl(void)
	{
		__asm
		{
			lea		eax, dword ptr [esp]
			push	ecx
			push	eax
			push	ecx
			call	[T::callback]
			add		esp, 8
			pop		ecx

			jmp		[T::old_addr]
		}
	}


	template<std::size_t ADDR>
	struct HookMaker
	{
		static std::size_t	old_addr;
		static Callback   callback;

		static void Install(Callback fnCallback)
		{
			callback = fnCallback;

			auto hook = &HookRelCall_Impl<HookMaker>;
			old_addr = WriteRelCall(ADDR, reinterpret_cast<UInt32>(hook));
		}
	};

	template<std::size_t ADDR>
	std::size_t HookMaker<ADDR>::old_addr;

	template<std::size_t ADDR>
	Callback HookMaker<ADDR>::callback;


	template<std::size_t VPTR, std::size_t IDX>
	struct HookMakerVTable
	{
		static std::size_t	old_addr;
		static Callback		callback;

		static void Install(Callback fnCallback)
		{
			std::size_t *p = &reinterpret_cast<std::size_t *>(VPTR)[IDX];

			callback = fnCallback;

			auto hook = &HookRelCall_Impl<HookMakerVTable>;
			old_addr = SafeWrite32((UInt32)p, reinterpret_cast<UInt32>(hook));
		}
	};

	template<std::size_t VPTR, std::size_t IDX>
	std::size_t HookMakerVTable<VPTR, IDX>::old_addr;

	template<std::size_t VPTR, std::size_t IDX>
	Callback HookMakerVTable<VPTR, IDX>::callback;
}
