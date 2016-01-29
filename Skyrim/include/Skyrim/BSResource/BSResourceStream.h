#pragma once

// c:_skyrim\code\tesv\bsstream\Stream.h

#include "BSResourceStreamBase.h"
#include "BSResourceLooseFileLocation.h"


namespace BSResource
{

	// IC, no rtti, vtbl 0110CBB4
	class Stream : public StreamBase
	{
	public:
		virtual ~Stream();																			// 00A3F020

		// @override
		virtual	Status		Open(void) override;													// 01 00A3B590
		virtual void		Close(void) override;													// 02 00A3A720 { if (unk0C.unk50) pathFileName = nullptr; }
		virtual UInt64		GetPosition(void) override;												// 03 00A3B6B0
		virtual StreamBase&	Duplicate(StreamBase *& out) override;									// 05 00A3B530
		virtual Status		Read(void *buf, UInt32 bufLen, bool unk, UInt32 &readLen) override;		// 06 00A3B600 
		virtual Status		Unk_07(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt64 &arg4) override;	// 07 00A3EEE0 { arg4 = 0; return 8; }
		virtual Status		Unk_08(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4) override;	// 08 00A3A490 arg1 is short ?, arg2 is SInt32 ?, arg4 is short* ?
		virtual Status		Unk_09(void) override;													// 09 00667E20 { return 8; }
		virtual	bool		GetPathFileName(BSFixedString &out) override;							// 0A 00A3A550 { out = pathFileName; return pathFileName == nullptr; }
		virtual UInt32		Unk_0B(UInt32 arg) override;											// 0B 00A3AB60

		// @members
		//void			** _vtbl;		// 00 - 0110CBB4
		void			* unk0C;		// 0C - obj ptr - has refcount - non virtual - dtor 00A3E1E0
		UInt32			m_beginPos;		// 10 begin pos
		UInt32			m_curPos;		// 14 current pos
		BSFixedString	pathFileName;	// 18

	protected:
		DEFINE_MEMBER_FN(Open_Impl,			Status,		0x00A3B590);
		DEFINE_MEMBER_FN(Close_Impl,		void,		0x00A3A720);
		DEFINE_MEMBER_FN(GetPosition_Impl,	UInt64,		0x00A3B6B0);
		DEFINE_MEMBER_FN(Dupulicate_Impl,	StreamBase &,	0x00A3B530,	StreamBase *&);
		DEFINE_MEMBER_FN(Read_Impl,			Status,		0x00A3B600,	void *buf, UInt32 bufLen, bool unk, UInt32 &readLen);
		DEFINE_MEMBER_FN(Unk_07_Impl,		Status,		0x00A3EEE0,	UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt64 &arg4);
		DEFINE_MEMBER_FN(Unk_08_Impl,		Status,		0x00A3A490,	UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4);
		DEFINE_MEMBER_FN(Unk_09_Impl,		Status,		0x00667E20);
		DEFINE_MEMBER_FN(Unk_0A_Impl,		bool,		0x00A3A550, BSFixedString &out);
		DEFINE_MEMBER_FN(Unk_0B_Impl,		UInt32,		0x00A3AB60,	UInt32);

	private:
		DEFINE_MEMBER_FN(ctor4, Stream*, 0x00A3B2D0, void *a_unk0C, UInt32 headPos, UInt32 size, const BSFixedString &name);
		DEFINE_MEMBER_FN(ctor5, Stream*, 0x00A3B700, void *a_unk0C, UInt32 headPos, UInt32 size, bool arg4, const BSFixedString &name);
		DEFINE_MEMBER_FN(ctor_copy, Stream*, 0x00A3B320, const Stream &rhs);
		DEFINE_MEMBER_FN(dtor, void, 0x000000);
	};


	// 38, no rtti, vtbl 0110CD68
	class LooseFileStream : public StreamBase
	{
	public:
		virtual ~LooseFileStream();																	// 00A44EB0


		// @override
		virtual	Status		Open(void) override;													// 01 00A44520
		virtual void		Close(void) override;													// 02 00A44E20
		virtual Status		Unk_04(UInt32 arg) override;											// 04 00A440D0 { return this->unk0C.Unk_00A43900(arg); }
		virtual StreamBase&	Duplicate(StreamBase *& out) override;									// 05 00A44AC0
		virtual Status		Read(void *buf, UInt32 bufLen, bool unk, UInt32 &readLen) override;		// 06 00A44B50 
		virtual Status		Unk_07(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt64 &arg4) override;	// 07 00A44C10 called from 00AC6CB8
		virtual Status		Unk_08(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4) override;	// 08 00A43D70
		virtual Status		Unk_09(void) override;													// 09 00A43EA0
		virtual	bool		GetPathFileName(BSFixedString &out) override;							// 0A 00A44070 { char buf[104]; strcpy_s(buf, dataPath); strcat_s(buf, fileName); out = buf; return true; }
		virtual UInt32		Unk_0B(UInt32 arg) override;											// 0B 00A44DF0 { return location.Unk_00A43080(dataPath, fileName, arg1, &arg, unk08); }

		// @members
		//void			** _vtbl;		// 00 - 0110CD68
		BSFixedString	rootPath;		// 0C - arg1
		BSFixedString	dataPath;		// 10 - arg2
		BSFixedString	fileName;		// 14 - arg3

		UInt32			unk18;			// 18 - bool ? - head of unk obj - unk18.Unk_00A580A0(arg1, arg2, arg3, arg4)
		UInt32			unk1C;			// 1C - HANDLE - file handle
		Location		* location;		// 20 - arg6
		UInt32			unk24;			//  
		UInt32			unk28;			// 28 - init'd 0 | UInt64 ?
		UInt32			unk2C;			// 2C - init'd 0 |
		void			* unk30;		// 30 - init'd 0 - obj ptr - unk30->Unk_00A445E0(arg1, unk28, unk2C, arg2, arg3, arg4)
		UInt32			unk34;			// 34

	protected:
		DEFINE_MEMBER_FN(Open_Impl,			Status,			0x00A44520);
		DEFINE_MEMBER_FN(Close_Impl,		void,			0x00A44E20);
		DEFINE_MEMBER_FN(Unk_04_Impl,		Status,			0x00A440D0, UInt32);
		DEFINE_MEMBER_FN(Dupulicate_Impl,	StreamBase &,	0x00A44AC0,	StreamBase *&);
		DEFINE_MEMBER_FN(Read_Impl,			Status,			0x00A44B50,	void *buf, UInt32 bufLen, bool unk, UInt32 &readLen);
		DEFINE_MEMBER_FN(Unk_07_Impl,		Status,			0x00A44C10,	UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt64 &arg4);
		DEFINE_MEMBER_FN(Unk_08_Impl,		Status,			0x00A43D70,	UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4);
		DEFINE_MEMBER_FN(Unk_09_Impl,		Status,			0x00A43EA0);
		DEFINE_MEMBER_FN(Unk_0A_Impl,		bool,			0x00A44070, BSFixedString &out);
		DEFINE_MEMBER_FN(Unk_0B_Impl,		UInt32,			0x00A44DF0,	UInt32);

	private:
		DEFINE_MEMBER_FN(ctor,		LooseFileStream*,	0x00A43BC0, const BSFixedString &rootPath, const BSFixedString &dataPath, const BSFixedString &fileName, UInt32 size, bool unk, Location *location);
		DEFINE_MEMBER_FN(ctor_copy,	LooseFileStream*,	0x00A43FF0, const LooseFileStream &rhs);
		DEFINE_MEMBER_FN(dtor,		void,				0x00A44E50);
	};
}
