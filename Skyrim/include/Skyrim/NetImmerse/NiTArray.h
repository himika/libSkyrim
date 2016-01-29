#pragma once

#include "NiMemory.h"

// 10
template <class T, class TAlloc = NiTMallocInterface<T>>
class NiTArray
{
public:
	NiTArray();
	virtual ~NiTArray();

	// sparse array, can have nullptr entries that should be skipped
	// iterate from 0 to m_emptyRunStart - 1

	inline std::size_t GetSize() const {
		return m_emptyRunStart;
	}
	inline std::size_t GetEffectiveSize() const {
		return m_size;
	}
	inline std::size_t GetAllocatedSize() const {
		return m_arrayBufLen;
	}

	inline T& GetAt(std::size_t index) {
		return m_data[index];
	}
	inline const T& GetAt(std::size_t index) const {
		return m_data[index];
	}

	// @members
	//void	** _vtbl;			// 00
	T		* m_data;			// 04
	UInt16	m_arrayBufLen;		// 08 - max elements storable in m_data
	UInt16	m_emptyRunStart;	// 0A - index of beginning of empty slot run
	UInt16	m_size;				// 0C - number of filled slots
	UInt16	m_growSize;			// 0E - number of slots to grow m_data by
};

template <class T> class NiTObjectArray : public NiTArray<T, NiTNewInterface<T>>
{
public:
	NiTObjectArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1);
};


template <class T>
class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T>>
{
public:
	NiTPrimitiveArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1);
};


// 18
template <typename T, class TAlloc = NiTMallocInterface<T>>
class NiTLargeArray
{
public:
	NiTLargeArray();
	virtual ~NiTLargeArray();

	// fast, doesn't search for empty slots
	void Append(T item)
	{
		if (m_emptyRunStart == m_arrayBufLen)
		{
			// need to expand the array
			Resize(m_arrayBufLen + 1);
		}

		m_data[m_emptyRunStart] = item;
		m_emptyRunStart++;
		m_size++;
	}

	void Resize(UInt32 size)
	{
		// not reclaiming memory yet
		if (size <= m_size) return;

		// obey min grow size
		UInt32	growSize = size - m_size;
		if (growSize < m_growSize)
			growSize = m_growSize;

		size = m_arrayBufLen + growSize;

		// create new array
		T	* newData = (T *)FormHeap_Allocate(sizeof(T) * size);

		for (UInt32 i = 0; i < size; i++)
		{
			new (&newData[i]) T;
			newData[i] = 0;
		}

		// copy over data, compacting as we go
		UInt32	iter = 0;

		for (UInt32 i = 0; i < m_emptyRunStart; i++)
		{
			if (m_data[i])
			{
				newData[iter] = m_data[i];
				iter++;
			}
		}

		// update pointers
		T		* oldData = m_data;
		UInt32	oldDataLen = m_emptyRunStart;

		m_data = newData;
		m_arrayBufLen = size;
		m_emptyRunStart = m_size;

		// delete old array
		if (oldData)
		{
			for (UInt32 i = 0; i < oldDataLen; i++)
				if (oldData[i])
					oldData[i].~T();

			FormHeap_Free(oldData);
		}
	}

	//void	** _vtbl;			// 00
	T		* m_data;			// 04
	UInt32	m_arrayBufLen;		// 08 - max elements storable in m_data
	UInt32	m_emptyRunStart;	// 0C - index of beginning of empty slot run
	UInt32	m_size;				// 10 - number of filled slots
	UInt32	m_growSize;			// 14 - number of slots to grow m_data by
};

template <class T>
class NiTLargePrimitiveArray : public NiTLargeArray<T, NiTMallocInterface<T>>
{
public:
	NiTLargePrimitiveArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1);
};
