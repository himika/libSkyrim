#pragma once


#include "GMemory.h"
#include "GStats.h"

/*==============================================================================
class GRefCountImplCore +0000 (_vtbl=010E4220)
0000: class GRefCountImplCore
==============================================================================*/
// 04
class GRefCountImplCore
{
protected:
	// @members
	//void			** _vtbl;		// 00 - 010E4220
	volatile long	RefCount;		// 04

public:
	FORCE_INLINE GRefCountImplCore() { RefCount = 1; }

	virtual ~GRefCountImplCore();		// 0084C7A0

	SInt32	GetRefCount() const { return RefCount; }

	void operator= (const GRefCountImplCore &) { }
private:
	DEFINE_MEMBER_FN(dtor, void, 0x00924170);		// { _vtbl = 0x010E4220; return; }
};



// 04
class GRefCountImpl : public GRefCountImplCore
{
public:
	void	AddRef();
	void	Release() { Release_Impl(); }

private:
	DEFINE_MEMBER_FN(Release_Impl, void, 0x009241A0);
};


template<class Base, int StatType>
class GRefCountBaseStatImpl : public Base
{
public:
	GRefCountBaseStatImpl() { }

	GFC_MEMORY_REDEFINE_NEW(Base, StatType)
};


/*==============================================================================
class GRefCountBase<class GFxFunctionHandler,2> +0000
0000: class GRefCountBase<class GFxFunctionHandler,2>
0000: |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   class GRefCountImpl
0000: |   |   |   class GRefCountImplCore
==============================================================================*/
template<class Ty, int Stat = GStat_Default_Mem>
class GRefCountBase : public GRefCountBaseStatImpl<GRefCountImpl, Stat>
{
public:
	enum { StatType = Stat };

	FORCE_INLINE GRefCountBase() : GRefCountBaseStatImpl<GRefCountImpl, Stat>()
	{
	}
};



template<class Ty>
class GPtr
{
protected:
	// @members
	Ty   *pObject;

public:
	GPtr() : pObject(0)
	{
	}
	GPtr(Ty &robj)
	{
		pObject = &robj;
	}
	GPtr(Ty *pobj)
	{
		if (pobj) pobj->AddRef();
		pObject = pobj;
	}
	GPtr(const GPtr<Ty> &src)
	{
		if (src.pObject) src.pObject->AddRef();
		pObject = src.pObject;
	}

	template<class R>
	GPtr(GPtr<R> &src)
	{
		if (src) src->AddRef();
		pObject = src;
	}

	~GPtr()
	{
		if (pObject) pObject->Release();
	}

	bool operator == (const GPtr &other) const { return pObject == other.pObject; }
	bool operator != (const GPtr &other) const { return pObject != other.pObject; }
	bool operator == (const Ty *pother) const { return pObject == pother; }
	bool operator != (const Ty *pother) const { return pObject != pother; }
	bool operator == (Ty *pother) const { return pObject == pother; }
	bool operator != (Ty *pother) const { return pObject != pother; }
	bool operator < (const GPtr &other) const { return pObject < other.pObject; }

	template<class R>
	const GPtr<Ty>& operator = (const GPtr<R> &src)
	{
		if (src) src->AddRef();
		if (pObject) pObject->Release();
		pObject = src;
		return *this;
	}
	const GPtr<Ty>& operator = (const GPtr<Ty> &src)
	{
		if (src) src->AddRef();
		if (pObject) pObject->Release();
		pObject = src;
		return *this;
	}
	const GPtr<Ty>& operator = (Ty *psrc)
	{
		if (psrc) psrc->AddRef();
		if (pObject) pObject->Release();
		pObject = psrc;
		return *this;
	}
	const GPtr<Ty>& operator = (Ty &src)
	{
		if (pObject) pObject->Release();
		pObject = &src;
		return *this;
	}

	template<class R>
	GPtr<Ty>& SetPtr(const GPtr<R> &src)
	{
		if (src) src->AddRef();
		if (pObject) pObject->Release();
		pObject = src;
		return *this;
	}
	GPtr<Ty>& SetPtr(const GPtr<Ty> &src)
	{
		if (src) src->AddRef();
		if (pObject) pObject->Release();
		pObject = src;
		return *this;
	}
	GPtr<Ty>& SetPtr(Ty *psrc)
	{
		if (psrc) psrc->AddRef();
		if (pObject) pObject->Release();
		pObject = psrc;
		return *this;
	}
	GPtr<Ty>& SetPtr(Ty &src)
	{
		if (pObject) pObject->Release();
		pObject = &src;
		return *this;
	}

	void NullWithoutRelease()
	{
		pObject = 0;
	}

	void Clear()
	{
		if (pObject) pObject->Release();
		pObject = 0;
	}

	Ty*& GetRawRef() { return pObject; }

	Ty* GetPtr() const { return pObject; }
	Ty& operator * () const { return *pObject; }
	Ty* operator -> ()  const { return pObject; }

	operator Ty* () const { return pObject; }
};
