#pragma once

#include "../BSCore/BSSpinLock.h"

namespace BSScript
{
	// 04
	class IMemoryPagePolicy
	{
	public:
		virtual ~IMemoryPagePolicy() { }		// 00B72260

		virtual UInt32	Unk_01(void) = 0;
		virtual UInt32	Unk_02(UInt32 arg1, UInt32 arg2, void **arg3) = 0;
		virtual UInt32	Unk_03(UInt32 arg1) = 0;
		virtual void	Free(void  **arg) = 0;

		// @members
		// void **	_vtbl	// 00 - 01122D2C
	};


	// 24
	class MemoryPagePolicy : public IMemoryPagePolicy
	{
	public:
		MemoryPagePolicy(UInt32 arg1, UInt32 arg2, UInt32 arg3)		// 00C428A0 call from 008D7DCE
			: unk04(arg1), unk08(arg2), unk0C(arg3)
		{
		}

		virtual ~MemoryPagePolicy();												// 00B72260

		virtual UInt32	Unk_01(void) override;										// 00C42890 { return unk8; }
		virtual UInt32	Unk_02(UInt32 arg1, UInt32 arg2, void **arg3) override;		// 00C428E0
		virtual UInt32	Unk_03(UInt32 arg1) override;								// 00C42A10
		virtual void	Free(void **arg) override;									// 00C42B00

		// @members
		// void **	_vtbl		// 00 - 01149B68
		UInt32		unk04;		// 04 - init'd arg1
		UInt32		unk08;		// 08 - init'd arg2
		UInt32		unk0C;		// 0C - init'd arg3
		bool		unk10;		// 10 - init'd false
		BSSpinLock	lock;		// 14
		UInt32		unk1C;		// 1C - init'd 0
		UInt32		unk20;		// 20 - init'd 0
	};
	STATIC_ASSERT(sizeof(MemoryPagePolicy) == 0x24);
}
