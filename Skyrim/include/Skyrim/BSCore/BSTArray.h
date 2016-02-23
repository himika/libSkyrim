#pragma once

// c:_skyrim\code\tesv\bscore\BSTArray.h
// c:_skyrim\code\tesv\bscore\BSTSmallSharedArray.h

#include "../Memory.h"
#include <memory.h>
#include <utility>
#include <functional>

// 04
class BSTArrayBase
{
public:
	typedef std::size_t size_type;

	BSTArrayBase() : _M_count(0) {}

	class IAllocatorFunctor
	{
	public:
		IAllocatorFunctor() {}
		/* 00 */	virtual bool	Allocate(size_type num, size_type value_size) = 0;
		/* 01 */	virtual bool	Resize(size_type needNum, size_type copyFrontNum, size_type copySkipNum, size_type copyTailNum, size_type value_size) = 0;
		/* 02 */	virtual void	Free(void * ptr) = 0;
		/* 03 */	virtual ~IAllocatorFunctor() {}		// 004016E0

		TES_FORMHEAP_REDEFINE_NEW();

		// @members
		//void	** _vtbl	// 00 - 010775F0
	};

	bool empty() const {
		return _M_count == 0;
	}

	size_type size() const {
		return _M_count;
	}

protected:
	void _allocate(IAllocatorFunctor& functor, size_type num, size_type value_size) {
		functor.Allocate(num, value_size);
	}
	void _resize(IAllocatorFunctor& functor, size_type num, size_type value_size) {
		functor.Resize(num, _M_count, 0, 0, value_size);
	}
	void _pop(size_type num) {
		_M_count -= num;
	}
	void _clear() {
		_M_count = 0;
	}
	SInt32 _push(IAllocatorFunctor& functor, size_type capacity, size_type value_size) {
		return _push_Impl(functor, capacity, value_size);
	}
	void _move(void * entries, size_type to, size_type from, size_type num, size_type value_size) {
		_move_Impl(entries, to, from, num, value_size);
	}

	// @members
	size_type	_M_count;

private:
	DEFINE_MEMBER_FN(_push_Impl,	SInt32,	0x00A49B80,	IAllocatorFunctor& functor, size_type capacity, size_type value_size);
	DEFINE_MEMBER_FN(_move_Impl,	void,	0x00A4A070,	void * entries, size_type to, size_type from, size_type num, size_type value_size);
};


/*---------------------------------------------------
/ Allocator
/----------------------------------------------------*/
template <class _TAlloc>
class BSTArrayAllocatorFunctor;

// 08
class BSTArrayHeapAllocator
{
public:
	typedef BSTArrayBase::size_type size_type;
	typedef BSTArrayAllocatorFunctor<BSTArrayHeapAllocator> functor_type;

	BSTArrayHeapAllocator() : _M_entries(nullptr), _M_capacity(0) {
	}
	~BSTArrayHeapAllocator() {
		if (_M_entries)
			_Free();
	}

	size_type	capacity() const		{ return _M_capacity; }

protected:
	void		* _GetEntries()			{ return _M_entries; }
	const void	* _GetEntries() const		{ return _M_entries; }

	// @members
	void		* _M_entries;	// 00
	size_type	_M_capacity;	// 04

	friend class BSTArrayAllocatorFunctor<BSTArrayHeapAllocator>; 

	inline bool _Allocate(size_type num, size_type value_size) {
		return _Allocate_Impl(num, value_size);
	}
	inline bool _Resize(size_type needNum, size_type copyFrontNum, size_type copySkipNum, size_type copyTailNum, size_type value_size) {
		return _Resize_Impl(needNum, copyFrontNum, copySkipNum, copyTailNum, value_size);
	}
	inline void _Free() {
		_Free_Impl();
	}

	DEFINE_MEMBER_FN(_Allocate_Impl,	bool,	0x00A49C60, size_type num, size_type value_size);
	DEFINE_MEMBER_FN(_Resize_Impl,		bool,	0x00A49CA0, size_type needNum, size_type copyFrontNum, size_type copySkipNum, size_type copyTailNum, size_type value_size);
	DEFINE_MEMBER_FN(_Free_Impl,		void,	0x00A49D90);
};


template <std::size_t LOCAL_SIZE>
class BSTSmallArrayHeapAllocator
{
public:
	typedef BSTArrayBase::size_type size_type;
	typedef BSTArrayAllocatorFunctor<BSTSmallArrayHeapAllocator> functor_type;

	enum { kLocalAlloc = 0x80000000 };

	BSTSmallArrayHeapAllocator() : _M_capacity(LOCAL_SIZE | kLocalAlloc) {
		//memset(entries.local, 0, sizeof(Entry));
	}
	~BSTSmallArrayHeapAllocator() {
		if (!_IsLocal() && _M_capacity)
			_Free();
	}

	size_type	capacity() const		{ return (_M_capacity & ~kLocalAlloc); }

protected:
	void		* _GetEntries()			{ return _IsLocal() ? _M_entries.local : _M_entries.heap; }
	const void	* _GetEntries() const	{ return _IsLocal() ? _M_entries.local : _M_entries.heap; }
	bool		_IsLocal() const		{ return (_M_capacity & kLocalAlloc) != 0; }

protected:
	union Entry
	{
		void *	heap;
		char	local[LOCAL_SIZE];
	};

	// @members
	size_type	_M_capacity;	// 00
	Entry		_M_entries;		// 04

private:
	friend class BSTArrayAllocatorFunctor<BSTSmallArrayHeapAllocator>;

	inline bool _Allocate(size_type num, size_type value_size, size_type local_size = LOCAL_SIZE) {
		return _Allocate_Impl(num, value_size, local_size);
	}
	inline bool _Resize(size_type needNum, size_type copyFrontNum, size_type copySkipNum, size_type copyTailNum, size_type value_size, size_type local_size = LOCAL_SIZE) {
		return _Resize_Impl(needNum, copyFrontNum, copySkipNum, copyTailNum, value_size, local_size);
	}
	inline void _Free() {
		_Free_Impl();
	}

	DEFINE_MEMBER_FN(_Allocate_Impl,	bool,	0x00A4A720, size_type num, size_type value_size, size_type local_size);
	DEFINE_MEMBER_FN(_Resize_Impl,		bool,	0x00A4A7A0, size_type needNum, size_type copyFrontNum, size_type copySkipNum, size_type copyTailNum, size_type value_size, size_type local_size);
	DEFINE_MEMBER_FN(_Free_Impl,		void,	0x00A4A8F0);
};



// 08
class BSScrapArrayAllocator
{
public:
	typedef BSTArrayBase::size_type size_type;
	typedef BSTArrayAllocatorFunctor<BSScrapArrayAllocator> functor_type;

	BSScrapArrayAllocator() : _M_allocator(nullptr), _M_entries(nullptr), _M_capacity(0) {
	}
	~BSScrapArrayAllocator() {	// 00A49AF0
		if (_M_entries)
			_Free();
	}

	size_type	capacity() const	{ return _M_capacity; }

protected:
	void		* _GetEntries()	{ return _M_entries; }
	const void	* _GetEntries() const { return _M_entries; }

	// @members
	void		* _M_allocator;	// 00 - memory allocator
	void		* _M_entries;	// 04
	size_type	_M_capacity;	// 08

private:
	friend class BSTArrayAllocatorFunctor<BSScrapArrayAllocator>;

	friend class BSTArrayAllocatorFunctor<BSTArrayHeapAllocator>;

	inline bool _Allocate(size_type num, size_type value_size) {
		return _Allocate_Impl(num, value_size);
	}
	inline bool _Resize(size_type needNum, size_type copyFrontNum, size_type copySkipNum, size_type copyTailNum, size_type value_size) {
		return _Resize_Impl(needNum, copyFrontNum, copySkipNum, copyTailNum, value_size);
	}
	inline void _Free() {
		_Free_Impl();
	}

	DEFINE_MEMBER_FN(_Allocate_Impl,	bool,	0x00A49E00, size_type num, size_type value_size);
	DEFINE_MEMBER_FN(_Resize_Impl,		bool,	0x00A49E50, size_type needNum, size_type copyFrontNum, size_type copySkipNum, size_type copyTailNum, size_type value_size);
	DEFINE_MEMBER_FN(_Free_Impl,		void,	0x00A49AF0);
};


/// AllocatorFunctor
template <class _TAlloc>
class BSTArrayAllocatorFunctor : public BSTArrayBase::IAllocatorFunctor
{
public:
	typedef BSTArrayBase::size_type size_type;
	typedef _TAlloc allocator_type;

	explicit BSTArrayAllocatorFunctor(allocator_type * a_allocator) : m_pAllocator(a_allocator) { }

	// BSTArrayHeapAllocator:		TESV.004016B0
	// BSTSmallArrayHeapAllocator:	TESV.005A7470
	// BSScrapArrayAllocator:		TESV.0042B100
	virtual bool Allocate(size_type num, size_type value_size) override {
		return m_pAllocator->_Allocate(num, value_size);
	}
	// BSTArrayHeapAllocator:		TESV.004016C0
	// BSTSmallArrayHeapAllocator:	TESV.005A7490
	// BSScrapArrayAllocator:		TESV.0042B110
	virtual bool Resize(size_type needNum, size_type copyFrontNum, size_type copySkipNum, size_type copyTailNum, size_type value_size) override {
		return m_pAllocator->_Resize(needNum, copyFrontNum, copySkipNum, copyTailNum, value_size);
	}
	// BSTArrayHeapAllocator:		TESV.004016D0
	// BSTSmallArrayHeapAllocator:	TESV.0040B750
	// BSScrapArrayAllocator:		TESV.0042B120
	virtual void Free(void* ptr) override {
		m_pAllocator->_Free();
	}

protected:
	// @members
	//void			** _vtbl		// 00 - 01077640 (BSTArrayHeapAllocator)
									//      010BE92C (BSTSmallArrayHeapAllocator)
									//      0107A47C (BSScrapArrayAllocator)
	allocator_type	* m_pAllocator;	// 04
};

/*---------------------------------------------------
/ BSTArray
/----------------------------------------------------*/

// the same type as tArray in skse
template <class _Ty, class _TAlloc = BSTArrayHeapAllocator>
class BSTArray : public _TAlloc, public BSTArrayBase
{
public:
	typedef _TAlloc allocator_type;
	typedef BSTArrayAllocatorFunctor<allocator_type> functor_type;
	typedef _Ty value_type;
	typedef _Ty *pointer;
	typedef const _Ty *const_pointer;
	typedef _Ty &reference;
	typedef const _Ty &const_reference;
	typedef BSTArrayBase::size_type size_type;
	typedef std::ptrdiff_t difference_type;

	// compiler hints for GCC
	using _TAlloc::_GetEntries;
	using _TAlloc::capacity;

	TES_FORMHEAP_REDEFINE_NEW();

	class const_iterator
	{
	public:
		typedef const_iterator _iter;
		typedef typename BSTArray::value_type		value_type;
		typedef typename BSTArray::pointer			pointer;
		typedef typename BSTArray::reference		reference;
		typedef typename BSTArray::const_pointer	const_pointer;
		typedef typename BSTArray::const_reference	const_reference;
		typedef typename BSTArray::difference_type	difference_type;

		const_iterator() : m_cur(nullptr) {}
		const_iterator(pointer p) : m_cur(p) {}

		operator const_pointer() const {
			return m_cur;
		}
		const_reference operator*() const {
			return *m_cur;
		}
		const_pointer operator->() const {
			return m_cur;
		}

		_iter& operator++() {
			++m_cur;
			return *this;
		}
		_iter operator++(int) {
			_iter tmp = *this;
			++*this;
			return tmp;
		}
		_iter& operator--() {
			--m_cur;
			return *this;
		}
		_iter operator--(int) {
			_iter tmp = *this;
			--*this;
			return tmp;
		}

		difference_type operator-(const _iter& rhs) const {
			return (m_cur - rhs.m_cur);
		}
		_iter& operator+=(difference_type diff) {
			m_cur += diff;
			return *this;
		}
		_iter operator+(difference_type diff) const {
			_iter tmp = *this;
			return (tmp.operator+=(diff));
		}
		_iter& operator-=(difference_type diff) {
			m_cur -= diff;
			return *this;
		}
		_iter operator-(difference_type diff) const {
			_iter tmp = *this;
			return (tmp.operator-=(diff));
		}

		bool operator==(const _iter& rhs) const {
			return (m_cur == rhs.m_cur);
		}
		bool operator!=(const _iter& rhs) const {
			return (!(*this == rhs));
		}
		bool operator<(const _iter& rhs) const {
			return (m_cur < rhs.m_cur);
		}
		bool operator<=(const _iter& rhs) const {
			return (m_cur <= rhs.m_cur);
		}
		bool operator>(const _iter& rhs) const {
			return (m_cur > rhs.m_cur);
		}
		bool operator>=(const _iter& rhs) const {
			return (m_cur >= rhs.m_cur);
		}
	protected:
		pointer m_cur;

		friend class iterator;
	};

	class iterator : public const_iterator
	{
	public:
		typedef iterator _iter;
		
		// compiler hits for GCC
		using const_iterator::m_cur;

		iterator() { }
		iterator(pointer p) : const_iterator(p) { }

		operator pointer() const {
			return m_cur;
		}
		reference operator*() const {
			return *m_cur;
		}
		pointer operator->() {
			return m_cur;
		}

		_iter& operator++() {
			++m_cur;
			return *this;
		}
		_iter operator++(int) {
			_iter tmp = *this;
			++*this;
			return tmp;
		}
		_iter& operator--() {
			--m_cur;
			return *this;
		}
		_iter operator--(int) {
			_iter tmp = *this;
			--*this;
			return tmp;
		}

		difference_type operator-(const const_iterator& rhs) const {
			return (m_cur - rhs.m_cur);
		}
		_iter& operator+=(difference_type diff) {
			m_cur += diff;
			return *this;
		}
		_iter operator+(difference_type diff) const {
			_iter tmp = *this;
			return (tmp.operator+=(diff));
		}
		_iter& operator-=(difference_type diff) {
			m_cur -= diff;
			return *this;
		}
		_iter operator-(difference_type diff) const {
			_iter tmp = *this;
			return (tmp.operator-=(diff));
		}
	};

protected:
	pointer _head() const {
		return const_cast<pointer>((const_pointer)_GetEntries());
	}
	pointer _tail() const {
		return _head() + size() - 1;
	}
	pointer _last() const {
		return _head() + size();
	}

public:
	BSTArray() {
	}

	BSTArray(const BSTArray &rhs) {
		UInt32 size = rhs.GetSize();
		if (size > 0)
		{
			functor_type pred(this);
			_allocate(pred, size, sizeof(value_type));
			pointer p = rhs->_head();
			pointer last = rhs->_last();
			while (p <= last)
				push_back(*p++);
		}
	}

	explicit BSTArray(std::size_t num) {
		functor_type pred(this);
		_allocate(pred, num, sizeof(value_type));
	}

	~BSTArray() {
		for (std::size_t i = 0; i < size(); ++i) {
			(*this)[i].~value_type();
		}
	}

	iterator begin() {
		return iterator(_head());
	}
	const_iterator cbegin() const {
		return const_iterator(_head());
	}
	const_iterator begin() const {
		return cbegin();
	}

	iterator end() {
		return iterator(_last());
	}
	const_iterator cend() const {
		return const_iterator(_last());
	}
	const_iterator end() const {
		return cend();
	}

	reference front() {
		return *_head();
	}
	const_reference front() const {
		return *_head();
	}
	reference back() {
		return *_tail();
	}
	const_reference back() const {
		return *_tail();
	}

	reference operator[] (size_type index) {
		return *(&front() + index);
	}

	const_reference operator[] (size_type index) const {
		return *(&front() + index);
	}	

	void clear() {
		pointer last = _last();
		for (pointer p = _head(); p < last; ++p)
			p->~value_type();
		_clear();
	}

	void reserve(size_type num) {
		const size_type cap = capacity();
		if (cap >= num)
			return;

		functor_type pred(this);
		if (cap) {
			_resize(pred, num, sizeof(value_type));
		}
		else {
			_allocate(pred, num, sizeof(value_type));
		}
	}

	void push_front(const_reference ref) {
		functor_type pred(this);
		SInt32 index = _push(pred, capacity(), sizeof(value_type));
		if (index >= 0) {
			_move(_head(), 1, 0, index, sizeof(value_type));
			new(_head())value_type(ref);
		}
	}

	// TESV.0043C670
	void push_back(const_reference ref) {
		functor_type pred(this);
		SInt32 index = _push(pred, capacity(), sizeof(value_type));
		if (index >= 0) {
			new(_head() + index)value_type(ref);
		}
	}

	template <class... ValTy>
	void emplace_front(ValTy&&... val) {
		functor_type pred(this);
		SInt32 index = _push(pred, capacity(), sizeof(value_type));
		if (index >= 0) {
			_move(_head(), 1, 0, index, sizeof(value_type));
			new(_head())value_type(std::forward<ValTy>(val)...);
		}
	}

	template <class... ValTy>
	void emplace_back(ValTy&&... val) {
		functor_type pred(this);
		SInt32 index = _push(pred, capacity(), sizeof(value_type));
		if (index >= 0) {
			new(_head() + index)value_type(std::forward<ValTy>(val)...);
		}
	}

	void pop_front() {
		if (size()) {
			_head()->~value_type();
			_move(_head(), 0, size() - 1, 1, sizeof(value_type));
			_pop(1);
		}
	}

	void pop_back() {
		std::size_t num = size();
		if (num) {
			pointer p = &front() + (num - 1);
			p->~value_type();
			_pop(1);
		}
	}

	inline iterator erase(iterator it) {
		if (begin() <= it && it < end())
		{
			difference_type index = it - begin();
			iterator::pointer(it)->~value_type();

			difference_type next = index + 1;
			std::size_t num = size() - next;
			if (num > 0)
				_move(_head(), index, next, num, sizeof(value_type));
			_pop(1);
		}
		return it;
	}

	//==================================================

	inline UInt32 GetSize() const {
		return size();
	}

	inline UInt32 GetCapacity() const {
		return capacity();
	}

	inline reference Front() {
		return front();
	}

	inline const_reference Front() const {
		return front();
	}

	inline bool GetAt(size_type index, reference val) const {
		return (index < size()) ? (val = *(_head() + index), true) : false;
	}

	inline bool SetAt(size_type index, const_reference val) {
		return (index < size()) ? (*(_head() + index) = val, true) : false;
	}

	inline bool SetAt(size_type index, value_type &&rval) {
		return (index < size()) ? (*(_head() + index) = rval, true) : false;
	}

	inline bool GetNthItem(size_type index, reference val) const {
		return (index < size()) ? (val = *(_head() + index), true) : false;
	}

	inline void Add(const_reference ref) {
		push_back(ref);
	}

	// near TESV.004FB4C3
	void Remove(const_reference ref) {
		SInt32 index = Find(ref);
		if (index != -1) {
			pointer p = _head() + index;
			p->~value_type();
			
			UInt32 next = index + 1;
			std::size_t num = size() - next;
			if (num > 0)
				_move(_head(), index, next, num, sizeof(value_type));
			_pop(1);
		}
	}

	// TESV.00C55770
	void RemoveAtEndFill(size_type index, size_type num = 1) {
		pointer p = _head() + index;
		for (std::size_t i = 0; i < num; i++) {
			(p++)->~value_type();
		}

		size_type n = size();
		size_type tailNum = n - (index + num);
		if (tailNum > 0) {
			if (tailNum >= num)
				tailNum = num;
			size_type from = n - tailNum;
			size_type to = index;
			_move(_head(), to, from, tailNum, sizeof(value_type));
		}
		_pop(num);
	}

	inline void RemoveEnd() {
		pop_back();
	}

	inline void RemoveAll() {
		clear();
	}

	inline void PopBack() {
		pop_back();
	}

	inline void PopFront() {
		pop_front();
	}

	SInt32 Find(const_reference ref) const {
		//return Find([&ref](const_reference a) -> bool { return (a == ref); });
		const_pointer entries = _head();
		SInt32 index = -1;
		for (size_type i = 0; i < size(); ++i) {
			if (entries[i] == ref) {
				index = i;
				break;
			}
		}
		return index;
	}

	template <class Predicate>
	SInt32 FindIf(Predicate pred) const {
		const_pointer entries = _head();
		SInt32 index = -1;
		for (size_type i = 0; i < size(); ++i) {
			if (pred(entries[i])) {
				index = i;
				break;
			}
		}
		return index;
	}
};


template<class _Ty, std::size_t num = 1>
using BSTSmallArray = BSTArray <_Ty, BSTSmallArrayHeapAllocator<sizeof(_Ty)*num>>;


template <class _Ty>
class BSScrapArray : public BSTArray <_Ty, BSScrapArrayAllocator>
{
public:
	BSScrapArray() : BSTArray() {}
	explicit BSScrapArray(std::size_t size) : BSTArray(size) {}
};


// Returns if/where the element was found, otherwise indexOut can be used as insert position
template <typename Ty>
bool GetSortIndex(const BSTArray<Ty> &sortedArray, const Ty &elem, std::size_t *indexOut)
{
	if (sortedArray.empty())
	{
		*indexOut = 0;
		return false;
	}

	int leftIdx = 0;
	int rightIdx = sortedArray.size() - 1;

	while (true)
	{
		int pivotIdx = leftIdx + ((rightIdx - leftIdx) / 2);

		const Ty &val = sortedArray[pivotIdx];

		if (elem == val)
		{
			*indexOut = pivotIdx;
			return true;
		}
		else if (elem > val)
		{
			leftIdx = pivotIdx + 1;
		}
		else
		{
			rightIdx = pivotIdx - 1;
		}

		if (leftIdx > rightIdx)
		{
			*indexOut = leftIdx;
			return false;
		}
	}
}
