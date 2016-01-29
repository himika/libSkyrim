#pragma once

// c:_skyrim\code\tesv\bscore\BSTSingleton.h

//=====================================================
// BSTSingletonExplicit
//=====================================================

// 0
template<class Ty>
struct BSTSingletonExplicit
{
	static Ty *& m_pSingleton;

	inline BSTSingletonExplicit() {
		m_pSingleton = static_cast<Ty*>(this);
	}

	inline ~BSTSingletonExplicit() {
		m_pSingleton = nullptr;
	}

	static Ty * GetSingleton() {
		return m_pSingleton;
	}
};


//=====================================================
// BSTSingletonImplicit
//=====================================================

template<class Ty>
struct BSTSingletonImplicit
{
};


//=====================================================
// BSTSingletonSDM
//=====================================================

template <class> struct BSTSingletonSDMBase;


template <class Ty>
struct BSTSingletonSDMOpStaticBuffer
{
protected:
	static Ty* GetBuffer();
};


template <class Ty, class Alloc = BSTSingletonSDMOpStaticBuffer<Ty>>
struct BSTSDMTraits
{
	typedef Ty Type;
	typedef Alloc Allocator;
};


template <class Traits>
struct BSTSingletonSDMBase : public Traits, public Traits::Allocator
{
	typedef typename Traits::Type Type;
	typedef typename Traits::Allocator Allocator;

	//"BSTSingletonSDMBase isn't initialized yet."
	//"C:\projects\sbailey_buildfarm09\TESV\current\BSCore/BSTSingleton.h"

	static inline Type* GetSingleton() {
		if (!m_pSingleton) {
			Type *buf = Allocator::GetBuffer();
			m_pSingleton = buf->ctor();
		}
		return m_pSingleton;
	}

protected:
	static Type *& m_pSingleton;
};


template <class Ty, template <class> class _SingletonT = BSTSingletonSDMOpStaticBuffer>
struct BSTSingletonSDM : BSTSingletonSDMBase<BSTSDMTraits<Ty, _SingletonT<Ty>>>
{
};


#define DECLARE_BSTSINGLETONSDM_STATIC_INSTANCE(Ty, singletonAddr, bufferAddr)												\
	template <> Ty* BSTSingletonSDMOpStaticBuffer<Ty>::GetBuffer() { return (Ty*)(bufferAddr); }							\
	Ty *& BSTSingletonSDMBase<BSTSDMTraits<Ty, BSTSingletonSDMOpStaticBuffer<Ty>>>::m_pSingleton = *(Ty**)(singletonAddr)
