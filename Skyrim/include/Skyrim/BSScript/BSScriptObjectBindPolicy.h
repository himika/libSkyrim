#pragma once

// c:_skyrim\code\tesv\bsscript\BSScriptObjectBindPolicy.h


namespace BSScript
{
	// 04
	class ObjectBindPolicy
	{
	public:
		ObjectBindPolicy();
		virtual ~ObjectBindPolicy();	// 008D5970

		virtual void	Unk_01(UInt64 unk) = 0;
		virtual void	Unk_02(UInt64 unk) = 0;
		virtual void	Unk_03(UInt64 unk) = 0;
		virtual void	Unk_04(void) = 0;
		virtual UInt32	Unk_05(UInt32 unk0, UInt32 unk1) = 0;
		virtual void	Unk_06(UInt32 unk0, UInt32 unk1, UInt32 unk2, UInt32 unk3) = 0;
		virtual void	Unk_07(UInt32 unk0, UInt32 unk1, UInt32 unk2, UInt32 unk3, UInt32 unk4, UInt32 unk5) = 0;
		virtual bool	Unk_08(void) = 0;
		virtual void	Unk_09(UInt32 unk0, UInt32 unk1, UInt32 unk2, UInt32 unk3) = 0;
		virtual void	Unk_0A(UInt32 unk0, UInt32 unk1, UInt32 unk2, UInt32 unk3) = 0;
		virtual void	Unk_0B(UInt32 unk0, UInt32 unk1, UInt32 unk2, UInt32 unk3, UInt32 unk4) = 0;
		virtual void	Unk_0C(UInt32 unk0, UInt32 unk1, UInt32 unk2, UInt32 unk3, UInt32 unk4) = 0;

		//	void	** _vtbl;	// 00
	};
}
