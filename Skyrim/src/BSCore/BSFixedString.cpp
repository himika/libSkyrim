#include "Skyrim.h"
#include "Skyrim/BSCore/BSFixedString.h"
#include "Skyrim/BSCore/BSSpinLock.h"
#include "Skyrim/Memory.h"
#include <string.h>


class StringCache
{
public:
	struct Entry
	{
		Entry	* next;		// 00
		union
		{
			struct
			{
				UInt16	refCount;	// invalid if 0x8000 is set
				UInt16	hash;
			};
			UInt32	refCountAndHash;
		} state;	// 04
		UInt32	length;		// 08
							// data follows
	};

	struct Lock
	{
		BSSpinLock	lock;
	};

	StringCache();
	~StringCache();

	static StringCache *	GetSingleton(void);

	Lock *	GetLock(UInt32 crc16);

private:
	Entry	* table[0x10000];	// crc16
	Lock	locks[0x20];		// crc16 & 0x1F
	UInt8	unk;
};


StringCache * StringCache::GetSingleton(void)
{
	typedef StringCache * (*_GetSingleton)(void);

	return ((_GetSingleton)0x00A50B00)();
}

StringCache::Lock * StringCache::GetLock(UInt32 crc16)
{
	return &locks[crc16 & 0x1F];
}



BSFixedString::BSFixedString(const char * rhs)
{
	impl_ctor(rhs);
}

BSFixedString::BSFixedString(const BSFixedString &rhs)
{
	impl_ctor_copy(rhs);
}

BSFixedString::BSFixedString(BSFixedString &&rhs)
{
	data = rhs.data;
	rhs.data = nullptr;
}

BSFixedString::~BSFixedString()
{
	impl_Release();
}


BSFixedString& BSFixedString::operator=(const char* buf)
{
	if (data && data[0])
		impl_Release();

	return *impl_Set(buf);
}


BSFixedString& BSFixedString::operator=(const BSFixedString& rhs)
{
	if (data && data[0])
		impl_Release();

	/*
	if (rhs.data && rhs.data[0])
	{
	data = rhs.data;
	StringCache::Entry* entry = (StringCache::Entry*)((UInt32)data - sizeof(StringCache::Entry));
	entry->state.refCount++;
	}

	return *this;
	*/
	return *impl_Set_copy(rhs);
}


BSFixedString& BSFixedString::operator=(BSFixedString&& rhs)
{
	data = rhs.data;
	rhs.data = nullptr;

	return *this;
}


bool BSFixedString::operator==(const char* str) const
{
	return (strcmp(data, str) == 0);
}


UInt32 BSFixedString::length(void) const
{
	UInt32 len = 0;
	if (this && data)
	{
		StringCache::Entry* entry = (StringCache::Entry*)((UInt32)data - sizeof(StringCache::Entry));
		len = entry->length & 0x00FFFFFF;
	}
	return len;
}


bool BSFixedStringCI::operator==(const char* str) const
{
	return (_stricmp(data, str) == 0);
}

