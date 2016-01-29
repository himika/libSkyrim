#pragma once

#include "GTypes.h"

template<class T> struct GListNode
{
	T* pPrev;
	T* pNext;

	void Remove()
	{
		pPrev->pNext = pNext;
		pNext->pPrev = pPrev;
	}
};


template<class T> class GList
{
public:
	typedef T ValueType;

	GList()
	{
		Root.pNext = Root.pPrev = (ValueType*)&Root;
	}

	void Clear()
	{
		Root.pNext = Root.pPrev = (ValueType*)&Root;
	}

	const ValueType* GetFirst() const { return Root.pNext; }
	const ValueType* GetLast () const { return Root.pPrev; }
		  ValueType* GetFirst()       { return Root.pNext; }
		  ValueType* GetLast ()       { return Root.pPrev; }

	bool IsEmpty()                   const { return Root.pNext == (ValueType*)&Root; }
	bool IsFirst(const ValueType* p) const { return p == Root.pNext; }
	bool IsLast (const ValueType* p) const { return p == Root.pPrev; }
	bool IsNull (const ValueType* p) const { return p == (const ValueType*)&Root; }

	inline static const ValueType* GetPrev(const ValueType* p) { return p->pPrev; }
	inline static const ValueType* GetNext(const ValueType* p) { return p->pNext; }
	inline static       ValueType* GetPrev(      ValueType* p) { return p->pPrev; }
	inline static       ValueType* GetNext(      ValueType* p) { return p->pNext; }

	void PushFront(ValueType* p)
	{
		p->pNext          =  Root.pNext;
		p->pPrev          = (ValueType*)&Root;
		Root.pNext->pPrev =  p;
		Root.pNext        =  p;
	}

	void PushBack(ValueType* p)
	{
		p->pPrev          =  Root.pPrev;
		p->pNext          = (ValueType*)&Root;
		Root.pPrev->pNext =  p;
		Root.pPrev        =  p;
	}

	static void Remove(ValueType* p)
	{
		p->pPrev->pNext = p->pNext;
		p->pNext->pPrev = p->pPrev;
	}

	void BringToFront(ValueType* p)
	{
		Remove(p);
		PushFront(p);
	}

	void SendToBack(ValueType* p)
	{
		Remove(p);
		PushBack(p);
	}

	void PushListToFront(GList<T>& src)
	{
		if (!src.IsEmpty())
		{
			ValueType* pfirst = src.GetFirst();
			ValueType* plast  = src.GetLast();
			src.Clear();
			plast->pNext   = Root.pNext;
			pfirst->pPrev  = (ValueType*)&Root;
			Root.pNext->pPrev = plast;
			Root.pNext        = pfirst;
		}
	}


private:
	GList(const GList<T>&);
	const GList<T>& operator = (const GList<T>&);

	GListNode<ValueType> Root;
};
