#pragma once

// c:_skyrim\code\tesv\bsstream\BSResourceNiBinaryStream.h

#include "../NetImmerse/NiBinaryStream.h"
#include "BSResourceStreamBase.h"
#include <string>


/*==============================================================================
class BSResourceNiBinaryStream +0000 (_vtbl=011191D8)
0000: class BSResourceNiBinaryStream
0000: |   class NiBinaryStream
==============================================================================*/
// 20
class BSResourceNiBinaryStream : public NiBinaryStream
{
public:
	using StreamBase = BSResource::StreamBase;

	// 30
	struct Buffer
	{
	public:
		// @members
		StreamBase	* m_stream;		// 00
		UInt32		unk04;
		UInt32		unk08;			// 08 - init'd 0
		UInt32		unk0C;			// 0C - init'd 0
		UInt32		unk10;			// 10 - init'd 0
		UInt32		unk14;			// 14 - init'd 0
		UInt32		unk18;			// 18 - init'd 0
		UInt32		unk1C;			// 1C - init'd 0
		UInt32		m_length;		// 20
		void		* m_buffer;		// 24
		UInt32		m_flag;			// 28 - init'd (unk ? 2 : 0)
		UInt32		unk2C;

		void	Read(void *dst, UInt64 offset, UInt64 bufLen, UInt64 &readLen);
		UInt32	Seek(void *&src, UInt32 &srcLen, UInt64 pos);

	private:
		DEFINE_MEMBER_FN(ctor,			Buffer *,	0x00AC6FB0, StreamBase *stream, void *buffer, UInt32 bufLen, bool unk);
		DEFINE_MEMBER_FN(Read_Internal,	void,		0x00A3CDD0, void *dst, UInt64 offset, UInt64 bufLen, UInt64 &readLen);
		DEFINE_MEMBER_FN(Seek_Internal,	UInt32,		0x00AC6C10, void *&src,	UInt32 &srcLen, UInt64 pos);
	};


	BSResourceNiBinaryStream();
	BSResourceNiBinaryStream(const char * path, bool unk1 = false, bool unk2 = false);
	BSResourceNiBinaryStream(StreamBase *& a_stream, bool unk1 = false, bool unk2 = false);
	virtual ~BSResourceNiBinaryStream();					// 00AC6FF0

	virtual operator bool() const override;					// 01 00AC6400
	virtual void	Seek(SInt32 delta) override;			// 02 00AC63B0
	virtual UInt32	GetPosition() const override;			// 03 00AC63A0
	virtual void	CopyFrom(void *arg0) override;			// 04 00AC6510
	virtual void	SetEndianSwap(bool swap) override;		// 05 00AC66E0

	UInt32 Read(void *dst, UInt32 len);
	UInt32 Write(void *src, UInt32 len);
	UInt32 ReadLine(char * dst, UInt32 dstLen, UInt32 terminator = '\n');
	UInt32 ReadLine(wchar_t * dst, UInt32 dstLen, wchar_t terminator);	// length in characters
	UInt32 ReadLine(std::string & str, UInt32 terminator = '\n');

protected:
	DEFINE_MEMBER_FN(		ReadLine_Internal,		UInt32,	0x00AC6710,	char * dst, UInt32 dstLen, UInt32 terminator);
	DEFINE_MEMBER_FN(		Read_Internal,			UInt32,	0x00AC6410,	void * dst, UInt32 len);
	DEFINE_MEMBER_FN(		Write_Internal,			UInt32,	0x00AC6490,	void * src, UInt32 len);

	DEFINE_MEMBER_FN_const(	IsValid_Internal,		bool,	0x00AC6400,	void);
	DEFINE_MEMBER_FN(		Seek_Internal,			void,	0x00AC63B0,	SInt32);
	DEFINE_MEMBER_FN_const(	GetPosition_Internal,	UInt32,	0x009EA560,	void);
	DEFINE_MEMBER_FN(		CopyFrom_Impl,			void,	0x00AC6510,	void*);
	DEFINE_MEMBER_FN(		SetEndianSwap_Internal,	void,	0x00AC66E0,	bool);

	// @members
	//void			** _vtbl		// 00 - 011191D8
	StreamBase		* m_stream;		// 10
	Buffer			* m_buffer;		// 14
	UInt64			m_offset;		// 18

private:
	DEFINE_MEMBER_FN(ctor1, BSResourceNiBinaryStream *, 0x00AC6790, const char * filePath, bool unk1, bool unk2);
	DEFINE_MEMBER_FN(ctor2, BSResourceNiBinaryStream *, 0x00AC6840, StreamBase *& a_stream, bool bMakeBuffer, bool bSetFlag0008);
	DEFINE_MEMBER_FN(dtor, void, 0x00AC69B0);
};
STATIC_ASSERT(sizeof(BSResourceNiBinaryStream) == 0x20);
