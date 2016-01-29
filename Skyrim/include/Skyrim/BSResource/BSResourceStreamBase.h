#pragma once

// c:_skyrim\code\tesv\bsstream\BSResourceStreamBase.h

#include "../BSCore/BSFixedString.h"

namespace BSResource
{
	// 04?, no rtti, vtbl 0110CB44
	class StreamBase
	{
	public:
		enum Status
		{
			kStatus_00,
			kStatus_01,
			kStatus_02,
			kStatus_03,
			kStatus_08 = 8
		};

		enum Flags
		{
		};

		virtual ~StreamBase();					// 00A3CDA0

		virtual	Status		Open(void) = 0;													// 01 00F51EE8 pure - called from 008C08C0
		virtual void		Close(void) = 0;													// 02 00F51EE8 pure - called from 008C09A3
		virtual UInt64		GetPosition(void);													// 03 00A3A3B0 { return (UInt64)0; }
		virtual Status		Unk_04(UInt32 arg);													// 04 00A3A3C0 { return (UInt32)8; }
		virtual StreamBase&	Duplicate(StreamBase *& out) = 0;									// 05
		virtual Status		Read(void *buf, UInt32 bufLen, bool unk, UInt32 &readLen) = 0;		// 06
		virtual Status		Unk_07(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt64 &arg4) = 0;	// 07
		virtual Status		Unk_08(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4) = 0;		// 08
		virtual Status		Unk_09(void) = 0;													// 09
		virtual	bool		GetPathFileName(BSFixedString &out) = 0;							// 0A
		virtual UInt32		Unk_0B(UInt32 arg) = 0;												// 0B

		UInt32 GetFileSize() const {
			return m_size;
		}

		bool IsLooseFile() const {
			return (*(UInt32*)this == 0x0110CD68);
		}

		// retirn 0 if success
		static UInt32 Create(const char *fileName, StreamBase *&out, bool unk1, bool unk2 = false) {
			typedef UInt32(*FnPtr)(const char*, StreamBase *&, bool, bool);
			const FnPtr fnCreate = (FnPtr)0x00A3F810;

			return fnCreate(fileName, out, unk1, unk2);
		}

		// @members
		//void			** _vtbl;	// 00 - 0110CB44
		UInt32			m_size;		// 04 - file size?
		UInt32			m_flag;		// 08 - flag ? see 00AC6460, 00

	protected:
		DEFINE_MEMBER_FN(SetFlag1000_Impl, UInt32, 0x00406890);

		DEFINE_MEMBER_FN(GetPosition_Impl, UInt64, 0x00A3A3B0);
		DEFINE_MEMBER_FN(Unk_04_Impl, Status, 0x00A3A3C0, UInt32);
	};

}

