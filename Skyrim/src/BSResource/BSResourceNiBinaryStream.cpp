#include "Skyrim.h"
#include "Skyrim/BSResource/BSResourceNiBinaryStream.h"

BSResourceNiBinaryStream::BSResourceNiBinaryStream()
{
	//
}

BSResourceNiBinaryStream::BSResourceNiBinaryStream(const char * path, bool unk1, bool unk2)
{
	ctor1(path, unk1, unk2);
}

BSResourceNiBinaryStream::BSResourceNiBinaryStream(BSResource::StreamBase *& a_stream, bool unk1, bool unk2)
{
	ctor2(a_stream, unk1, unk2);
}

BSResourceNiBinaryStream::~BSResourceNiBinaryStream()
{
	dtor();
}

BSResourceNiBinaryStream::operator bool() const
{
	return IsValid_Internal();
}

void BSResourceNiBinaryStream::Seek(SInt32 delta)
{
	Seek_Internal(delta);
}

UInt32 BSResourceNiBinaryStream::GetPosition(void) const
{
	return GetPosition_Internal();
}

void BSResourceNiBinaryStream::CopyFrom(void * arg0)
{
	CopyFrom_Impl(arg0);
}

void BSResourceNiBinaryStream::SetEndianSwap(bool swap)
{
	SetEndianSwap_Internal(swap);
}


UInt32 BSResourceNiBinaryStream::Read(void *dst, UInt32 len)
{
	return Read_Internal(dst, len);
}


UInt32 BSResourceNiBinaryStream::Write(void *src, UInt32 len)
{
	return Write_Internal(src, len);
}


UInt32 BSResourceNiBinaryStream::ReadLine(char * dst, UInt32 dstLen, UInt32 terminator)
{
	return ReadLine_Internal(dst, dstLen, terminator);
}


UInt32 BSResourceNiBinaryStream::ReadLine(wchar_t * dst, UInt32 dstLen, wchar_t terminator)
{
	wchar_t	* iter = dst;

	if (dstLen == 0)
		return 0;

	for (UInt32 i = 0; i < dstLen - 1; i++)
	{
		wchar_t	data;

		if (Read(&data, sizeof(data)) != sizeof(data))
			break;

		if (data == terminator)
			break;

		*iter++ = data;
	}

	// null terminate
	*iter = 0;

	return iter - dst;
}


UInt32 BSResourceNiBinaryStream::ReadLine(std::string &str, UInt32 terminator)
{
	std::size_t totalLen = 0;
	char buf[256];
	char *p = buf;
	const char *tail = &buf[sizeof(buf)];

	str.clear();

	while (true)
	{
		int c = 0;
		std::size_t len = Read(&c, 1);
		if (len == 0)
		{
			break;
		}
		if (c == terminator)
		{
			++len;
			break;
		}

		*p++ = c;

		if (p == tail)
		{
			totalLen += sizeof(buf);
			str.append(buf, sizeof(buf));
			p = buf;
		}
	}

	if (p != buf)
	{
		std::size_t len = p - buf;
		str.append(buf, len);
		totalLen += len;
	}

	return totalLen;
}


void BSResourceNiBinaryStream::Buffer::Read(void *buffer, UInt64 offset, UInt64 bufLen, UInt64 &readLen)
{
#if 1
	return Read_Internal(buffer, offset, bufLen, readLen);
#else
	if (this->length == 0)
	{
		readLen = 0;
		return;
	}

	void   * src = nullptr;		// LOCAL.4
	UInt32 srcLen = 0;			// LOCAL.6
	UInt64 length = 0;			// LOCAL.2 & LOCAL.3
	UInt64 unk = 0;				// LOCAL.0 & LOCAL.1
	UInt32 err;					// overwrite Arg.1

	UInt32 err = Seek(&src, &srcLen, offset);

	length = (srcLen < bufLen) ? srcLen : bufLen;

	char *p = (char *)buffer;
	while (err != 0)
	{
		if (length == 0 || bufLen == 0)
			break;
		if (srcLen)
		{
			memcpy_s(p, bufLen, src, srcLen);
			p += length;

			// ...
		}
		// ...
	}

	// ...

#endif
}


UInt32 BSResourceNiBinaryStream::Buffer::Seek(void *&src, UInt32 &srcLen, UInt64 pos)
{
#if 1
	return Seek_Internal(src, srcLen, pos);
#else
#endif
}
