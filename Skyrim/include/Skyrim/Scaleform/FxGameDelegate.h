#pragma once

#include "GRefCount.h"
#include "GString.h"
#include "GFxPlayer.h"
#include "GFxLoader.h"

class FxDelegate;
class FxDelegateArgs;


/*==============================================================================
class FxDelegateHandler +0000 (_vtbl=010E42F4)
0000: class FxDelegateHandler
0000: |   class GRefCountBase<class FxDelegateHandler,2>
0000: |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   class GRefCountImpl
0000: |   |   |   |   class GRefCountImplCore
==============================================================================*/
// 04
class FxDelegateHandler : public GRefCountBase<FxDelegateHandler, GStat_Default_Mem>
{
public:
	/*==============================================================================
	class FxDelegateHandler::CallbackProcessor +0000 (_vtbl=0110E7AC)
	0000: class FxDelegateHandler::CallbackProcessor
	==============================================================================*/
	// 04
	class CallbackProcessor
	{
	public:
		typedef void(*Callback)(const FxDelegateArgs& params);

		virtual ~CallbackProcessor() {}
		virtual void Process(const GString& methodName, Callback method) = 0;
	};


	virtual ~FxDelegateHandler() {}
	virtual void Accept(CallbackProcessor* cbreg) = 0;
};


/*==============================================================================
class AddCallbackVisitor +0000 (_vtbl=0110E7C4)
0000: class AddCallbackVisitor
0000: |   class FxDelegateHandler::CallbackProcessor
==============================================================================*/
// ?
class AddCallbackVisitor : public FxDelegateHandler::CallbackProcessor
{
public:
	AddCallbackVisitor();
	virtual ~AddCallbackVisitor();

	FxDelegateHandler	* parent;
	void				* callbackHashTable;
};


class FxDelegateArgs
{
public:
	FxDelegateArgs();
	~FxDelegateArgs();

	GFxValue			responseID;
	FxDelegateHandler	* pThisMenu;
	GFxMovieView		* movie;
	GFxValue			* args;
	UInt32				numArgs;
};



/*==============================================================================
class FxDelegate +0000 (_vtbl=0110E7DC)
0000: class FxDelegate
0000: |   class GFxExternalInterface
0000: |   |   class GFxState
0000: |   |   |   class GRefCountBase<class GFxState,2>
0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   |   |   class GRefCountImpl
0000: |   |   |   |   |   |   class GRefCountImplCore
==============================================================================*/
// 10
class FxDelegate : public GFxExternalInterface
{
public:

	DEFINE_MEMBER_FN(RegisterHandler, void, 0x00A63C10, FxDelegateHandler* callback);

	// @members
	UInt32	unk0C;		// 0C - init'd 0 - hash map of callbacks?
};
