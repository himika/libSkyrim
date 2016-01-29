#pragma once


class GString
{
public:
	enum HeapType
	{
		kHeapInfoGlobal = 0,
		kHeapInfoLocal = 1,
		kHeapInfoDynamic = 2,
		kHeapInfoMask = 3
	};

	struct Data
	{
		UInt32			len;
		volatile long	refCount;
		char			data[1];

		void AddRef(void);
		void Release(void);
	};

	GString()
	{
	}
	GString(const char * string)
	{
		ctor(string);
	}

	~GString()
	{
		GetData()->Release();
	}

	operator const char *() const
	{
		return GetData()->data;
	}

	const char * c_str() const
	{
		return GetData()->data;
	}

protected:
	Data *	GetData(void) const
	{
		UInt32 heapInfo = (data.heapInfo & ~(UInt32)kHeapInfoMask);
		return (Data *)heapInfo;
	}

	HeapType GetHeapInfo(void)
	{
		return (HeapType)(data.heapInfo & kHeapInfoMask);
	}

private:
	// @members
	union
	{
		Data	* ptr;		// do not use directly, clear lower 3 bits first
		UInt32	heapInfo;
	} data;

private:
	DEFINE_MEMBER_FN(ctor, GString *, 0x009259D0, const char * string);
};


