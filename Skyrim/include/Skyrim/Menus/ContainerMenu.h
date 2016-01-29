#pragma once

#include "IMenu.h"

/*==============================================================================
class ContainerMenu +0000 (_vtbl=010E4098)
0000: class ContainerMenu
0000: |   class IMenu
0000: |   |   class FxDelegateHandler
0000: |   |   |   class GRefCountBase<class FxDelegateHandler,2>
0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   |   |   class GRefCountImpl
0000: |   |   |   |   |   |   class GRefCountImplCore
==============================================================================*/
class ContainerMenu : public IMenu
{
public:
	virtual ~ContainerMenu();										// 0084A6A0

	// @override
	virtual void	Accept(CallbackProcessor *processor) override;	// 0084C100
	virtual UInt32	ProcessMessage(UIMessage *message) override;	// 0084B970
	virtual void	Render(void) override;							// 00849200
};
