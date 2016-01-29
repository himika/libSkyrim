#pragma once

#include "BSTSmartPointer.h"

/*==============================================================================
class IHandlerFunctor<class Actor,class BSFixedStringCI> +0000 (_vtbl=010D5408)
0000: class IHandlerFunctor<class Actor,class BSFixedStringCI>
0004: |   struct BSIntrusiveRefCounted
==============================================================================*/
// 08
template <class TArg1, class TArg2>
class IHandlerFunctor : public BSIntrusiveRefCounted
{
public:
	virtual ~IHandlerFunctor() {}
	virtual bool ExecuteHandler(TArg1 *form, TArg2 *arg2) = 0;
};
