#pragma once

#include "../BSCore/BSTHashMap.h"
#include "../BSSystem/IHandlerFunctor.h"

/*==============================================================================
class DoNothingUnhandledPolicy<class BSFixedStringCI> +0000 (_vtbl=010D53BC)
0000: class DoNothingUnhandledPolicy<class BSFixedStringCI>
==============================================================================*/
// 04
template<class Ty>
class DoNothingUnhandledPolicy
{
public:
	virtual ~DoNothingUnhandledPolicy();		// 0077F890 
};


/*==============================================================================
class BSResponse<class BSFixedStringCI,class Actor,class BSFixedStringCI,class DoNothingUnhandledPolicy> +0000 (_vtbl=010D53C4)
0000: class BSResponse<class BSFixedStringCI,class Actor,class BSFixedStringCI,class DoNothingUnhandledPolicy>
0004: |   struct BSIntrusiveRefCounted
0000: |   class DoNothingUnhandledPolicy<class BSFixedStringCI>
==============================================================================*/
// 2C
template<class TKey, class TArg1, class TArg2, template <class> class TPolicy = DoNothingUnhandledPolicy>
class BSResponse :
	public BSIntrusiveRefCounted,	// 04
	public TPolicy<TKey>			// 00
{
public:
	typedef	TPolicy<TKey>						Policy;
	typedef IHandlerFunctor<TArg1, TArg2>		HandlerFunctor;
	typedef BSTSmartPointer<HandlerFunctor>		HandlerFunctorPtr;
	typedef BSTHashMap<TKey, HandlerFunctorPtr>	HandlerMap;
	typedef BSTSmartPointer<BSResponse>			BSResponsePtr;

	virtual ~BSResponse() {
	}

	bool CallHandler(const TKey &key, TArg1 *arg1, TArg2 *arg2, bool &arg3)		// called from Actor::ReceiveEvent<BSAnimationGraphEvent>()
	{
		bool bResult = false;
		HandlerFunctorPtr handler;
		
		if (handlerMap.GetAt(key, handler))
		{
			bResult = handler->ExecuteHandler(arg1, arg2);
		}
		else if (delegateResp)
		{
			bResult = delegateResp->CallHandler(key, arg1, arg2, arg3);
		}
		else {
			arg3 = false;
		}

		return bResult;
	}

	// @members
	HandlerMap		handlerMap;			// 08
	BSResponsePtr	delegateResp;		// 28
};
STATIC_ASSERT(sizeof(BSResponse<BSFixedStringCI, Actor, BSFixedStringCI, DoNothingUnhandledPolicy>) == 0x2C);

template<class TKey, class TArg1, class TArg2, template <class> class TPolicy = DoNothingUnhandledPolicy>
using BSResponsePtr = BSTSmartPointer<BSResponse<TKey, TArg1, TArg2, TPolicy>>;
