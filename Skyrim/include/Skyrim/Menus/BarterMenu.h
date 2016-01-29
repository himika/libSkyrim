#pragma once

#include "IMenu.h"

/*==============================================================================
class BarterMenu +0000 (_vtbl=010E3860)
0000: class BarterMenu
0000: |   class IMenu
0000: |   |   class FxDelegateHandler
0000: |   |   |   class GRefCountBase<class FxDelegateHandler,2>
0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   |   |   class GRefCountImpl
0000: |   |   |   |   |   |   class GRefCountImplCore
==============================================================================*/// 68
class BarterMenu : public IMenu
{
	// unk0C - 0
	// Flags - 0xA489
	// unk14 - 3
	GFxValue	* root;		// 1C
							// ...
	UInt8		unk34;		// 34
};
