#pragma once

#include "UIManager.h"
#include "../Scaleform/FxGameDelegate.h"
#include "../BSSystem/BSTSmartPointer.h"
#include "../BSCore/BSFixedString.h"


/*==============================================================================
class IMenu +0000 (_vtbl=0110E7E8)
0000: class IMenu
0000: |   class FxDelegateHandler
0000: |   |   class GRefCountBase<class FxDelegateHandler,2>
0000: |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   |   class GRefCountImpl
0000: |   |   |   |   |   class GRefCountImplCore
==============================================================================*/
// 1C
class IMenu : public FxDelegateHandler
{
public:
	enum
	{
		kType_PauseGame				= 0x01,
		kType_DoNotDeleteOnClose	= 0x02,
		kType_ShowCursor			= 0x04,
		kType_Unk0008				= 0x08,
		kType_Modal					= 0x10,
		kType_StopDrawingWorld		= 0x20,
		kType_Open					= 0x40,
		kType_PreventGameLoad		= 0x80,
		kType_Unk0100				= 0x100,
		kType_HideOther				= 0x200,
		kType_Unk0400				= 0x400,
		kType_DoNotPreventGameSave	= 0x800,
		kType_Unk1000				= 0x1000,
		kType_ItemMenu				= 0x2000,
		kType_StopCrosshairUpdate	= 0x4000,
		kType_Unk8000				= 0x8000,
		kType_Unk10000				= 0x10000	// mouse cursor
	};

	IMenu();			// 00A64B70
	virtual ~IMenu();	// 00A64BB0

	// @override
	virtual void	Accept(CallbackProcessor * processor) override;	// 01 00588F30 { return; }

	// @add
	virtual void	OnOpen(void);									// 02 006C50E0 { return; }
	virtual void	Unk_03(void);									// 03 006C50E0 { return; }
	virtual UInt32	ProcessMessage(UIMessage *message);				// 04 00A64940
	virtual void	NextFrame(UInt32 arg0, UInt32 arg1);			// 05 00A64980 { NextFrame_internal(arg0, arg1); }
	virtual void	Render(void);									// 06 00847000 { if (view) view->Display(); }
	virtual void	Unk_07(void);									// 07 00A64760 { return; }
	virtual void	InitMovie(void);								// 08 00A64BA0 { InitMovie_internal(view); }

	GFxMovieView* GetMovieView()
	{
		return view;
	}

	bool LoadMovie(const char *swfPath, GFxMovieView::ScaleModeType mode, float backgroundAlpha = 0.0f);


	// @members
	//void			** _vtbl;		// 00 - 0110E7E8
	GFxMovieView	* view;			// 08 - init'd to nullptr, view->Release() called in dtor
	UInt8			menuDepth;		// 0C - init'd to 3 - movie clip depth ?
									//    - 0x0 0000 ContainerMenu, BarterMenu
									//    - 0x2 0010 HUD Menu
									//    - 0x3 0011 Fader Menu, StatsMenu, MapMenu, FavoritesMenu, Training Menu
									//    - 0x5 0101 Journal Menu
									//    - 0x8 1000 Mist Menu
									//    - 0x9 1001 Loading Menu, Main Menu
									//    - 0xA 1010 Credits Menu
									//    - 0xC 1100 Console
									//    - 0xD 1101 Cursor Menu
	UInt32			flags;			// 10 - init'd to 0	- 0x01 PauseGame, 0x40 Open
									//    -	(HEX)      (NAME)             1 8421:8421 8421 8421
									//    - 0x00000803 Credits Menu        :    :    :    :   *
									//    - 0x00000803 Loading Menu        :    :*   :    :  **
									//    - 0x00004880 Mist Menu           : *  :*   :*   :    
									//    - 0x00008800 Fader Menu          :*   :*   :    :    
									//    - 0x00000004 TitleSequence Menu  :    :    :    : *
									//    - 0x00000585 Main Menu           :    : * *:*   : * *
									//    - 0x00008800 Cursor Menu         :*   :*   :    :    
									//    - 0x00018902 HUD Menu           *:*   :*  *:    :  *
									//    - 0x00000E2D Journal Menu        :    :*** :  * :** *
									//    - 0x0000818D StatsMenu           :*   :   *:*   :** *
									//    - 0x00009005 MapMenu             :*  *:    :    : * *
									//    - 0x0000CC05 TweenMenu           :**  :**  :    : * *
									//    - 0x00000905 Sleep/Wait Menu     :    :*  *:    : * *
									//    - 0x00000415 Tutorial Menu       :    : *  :   *: * *
									//    - 0x0000040D Training Menu       :    : *  :    :** *
									//    - 0x00000807 Console             :    :*   :    : ***
									//    - 0x0000648C Crafting Menu       : ** : *  :*   :**
									//    - 0x00004404 Dialogue Menu       : *  : *  :    : *
									//    - 0x0000A485 InventoryMenu       :* * : *  :*   : * *
									//    - 0x0000A48D ContainerMenu       :* * : *  :*   :** *
									//    - 0x0000A48D BarterMenu          :* * : *  :*   :** *
									//    - 0x0000A48D MagicMenu           :* * : *  :*   :** *
									//    - 0x0000A405 FavoritesMenu       :* * : *  :    : * *
									//    - 0x0000070D RaceSex Menu        :    : ***:    :** *
									//    -	(HEX)      (NAME)             1 8421:8421 8421 8421
									//    -                                  ||  |||  ||||  ||+--0001 Pause
									//    -                                  ||  |||  ||||  |+---0002 Do Not Delete On Close
									//    -                                  ||  |||  ||||  +----0004 Show Cursor Menu
									//    -                                  ||  |||  |||+-------0010 Modal, Prevent Other Menu
									//    -                                  ||  |||  ||+--------0020 Stop Drawing World
									//    -                                  ||  |||  |+---------0040 Open
									//    -                                  ||  |||  +----------0080 Prevent Game Load
									//    -                                  ||  ||+-------------0200 Hide Other Menu
									//    -                                  ||  |+--------------0400 Mouse ?
									//    -                                  ||  +---------------0800 Do Not Prevent Save Game
									//    -                                  |+------------------2000 Item Menu, Prevent Other Item Menu
									//    -                                  +-------------------4000 Stop Updating Crosshair, Disable Journal, Prevent Game Load
	UInt32			context;		// 14 - input context - init'd to 0x12 (kContext_Invalid)
	FxDelegate		* fxDelegate;	// 18 - allocated in SetMovieView

private:
	DEFINE_MEMBER_FN(ctor, void, 0x00A64B70);
	DEFINE_MEMBER_FN(dtor, void, 0x00A64A10);

	DEFINE_MEMBER_FN(InitMovie_internal, void, 0x00A64A50, GFxMovieView* view);
	DEFINE_MEMBER_FN(NextFrame_internal, void, 0x00A64980, UInt32 arg0, UInt32 arg1);
	DEFINE_MEMBER_FN(SetMovieView_Impl, void, 0x00A648B0, GFxMovieView *pView);
};
STATIC_ASSERT(sizeof(IMenu) == 0x1C);
