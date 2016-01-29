#include "Skyrim.h"

#include "Skyrim/Memory.h"
#include "Skyrim/BSCore/BSTArray.h"

/*

SInt32	BSTArrayBase::_push(IAllocatorFunctor& functor, UInt32 capacity, UInt32 value_size)
{
	if (capacity > _M_count)
	{
		return _M_count++;
	}
	if (capacity == 0)
	{
		if (functor.Allocate(1, value_size))
			return _M_count++;
	}
	else
	{
		if (functor.Resize(_M_count + 1, _M_count, 0, 0, value_size))
			return _M_count++;
	}
	return -1;
}


void BSTArrayBase::_move(void* entries, UInt32 to, UInt32 from, UInt32 num, UInt32 value_size)
{
	void* dest = reinterpret_cast<void*>((UInt32)entries + to * value_size);
	void* src = reinterpret_cast<void*>((UInt32)entries + from * value_size);
	size_t size = num * value_size;
	memcpy_s(dest, size, src, size);
}


bool BSTArrayHeapAllocator::_Allocate(UInt32 num, UInt32 value_size)
{
	if (num < 4)
		num = 4;
	UInt32 memSize = num * value_size;
	_M_entries = FormHeap_Allocate(memSize);

	return ((_M_entries) ? (_M_capacity = num, true) : false);
}


bool BSTArrayHeapAllocator::_Resize(UInt32 needNum, UInt32 copyFrontNum, UInt32 copySkipNum, UInt32 copyTailNum, UInt32 value_size)
{
	UInt32 alloc_num = (needNum > _M_capacity * 2) ? needNum : _M_capacity * 2;

	if (!_M_entries)
	{
		if (alloc_num < 4)
			alloc_num = 4;
		void* pMem = FormHeap_Allocate(alloc_num * value_size);

		return ((pMem) ? (_M_entries = pMem, true) : false);
	}

	void* pMem = FormHeap_Allocate(alloc_num * value_size);
	if (pMem)
	{
		if (copyFrontNum)
		{
			size_t size = copyFrontNum * value_size;
			memcpy_s(pMem, size, _M_entries, size);
		}
		if (copyTailNum)
		{
			size_t size = copyTailNum * value_size;
			void* src = reinterpret_cast<void*>((UInt32)_M_entries + copyFrontNum * value_size);
			void* dst = reinterpret_cast<void*>((UInt32)pMem + (copyFrontNum + copySkipNum) * value_size);
			memcpy_s(dst, size, src, size);
		}
		FormHeap_Free(_M_entries);
		_M_entries = pMem;
	}

	return (pMem != nullptr);
}


void BSTArrayHeapAllocator::_Free()
{
	FormHeap_Free(_M_entries);
	_M_entries = nullptr;
	_M_capacity = 0;
}


bool BSTSmallArrayHeapAllocatorBase::_Allocate(UInt32 num, UInt32 value_size, UInt32 local_size)
{
	if (num < 4)
		num = 4;
	UInt32 memSize = num * value_size;
	_M_entries = FormHeap_Allocate(memSize);

	return ((_M_entries) ? (_M_capacity = num, true) : false);
}


bool BSTSmallArrayHeapAllocatorBase::_Resize(UInt32 needNum, UInt32 copyFrontNum, UInt32 copySkipNum, UInt32 copyTailNum, UInt32 value_size, UInt32 local_size)
{
	UInt32 alloc_num = (needNum > _M_capacity * 2) ? needNum : _M_capacity * 2;

	if (!_M_entries)
	{
		if (alloc_num < 4)
			alloc_num = 4;
		void* pMem = FormHeap_Allocate(alloc_num * value_size);

		return ((pMem) ? (_M_entries = pMem, true) : false);
	}

	void* pMem = FormHeap_Allocate(alloc_num * value_size);
	if (pMem)
	{
		if (copyFrontNum)
		{
			size_t size = copyFrontNum * value_size;
			memcpy_s(pMem, size, _M_entries, size);
		}
		if (copyTailNum)
		{
			size_t size = copyTailNum * value_size;
			void* src = reinterpret_cast<void*>((UInt32)_M_entries + copyFrontNum * value_size);
			void* dst = reinterpret_cast<void*>((UInt32)pMem + (copyFrontNum + copySkipNum) * value_size);
			memcpy_s(dst, size, src, size);
		}
		FormHeap_Free(_M_entries);
		_M_entries = pMem;
	}

	return (pMem != nullptr);
}


void BSTSmallArrayHeapAllocatorBase::_Free()
{
	if (!(capacity & kLocalAlloc))
	{
		FormHeap_Free(_M_entries);
		_M_capacity = kLocalAlloc;
	}
}

*/