#pragma once

#include "IMenu.h"
#include "../BSCore/BSTSingleton.h"
#include "../BSCore/BSTHashMap.h"
#include "../BSCore/BSTEvent.h"
#include "../Events/MenuEvent.h"

// 11C
class MenuManager :
	public BSTSingletonSDM<MenuManager>,			// 00
	public BSTEventSource<MenuOpenCloseEvent>,		// 04
	public BSTEventSource<MenuModeChangeEvent>,		// 34
	public BSTEventSource<void*>					// 64 - New in 1.6.87.0 - Kinect related?
{
public:
	typedef IMenu * (*FnMenuConstructor)(void);
	//StatsMenu:				0x0088D340
	//FavoritesMenu:			0x0085BF50
	//Journal Menu:				0x008AC1B0
	//ContainerMenu:			0x008497D0
	//Credits Menu:				0x008598A0
	//Main Menu:				0x00876FC0
	//InventoryMenu:			0x0086A3F0
	//LevelUp Menu:				0x0086E8B0
	//TitleSequence Menu:		0x008934B0
	//Tutorial Menu:			0x008945F0
	//Console Native UI Menu:	0x008488C0
	//Lockpicking Menu:			0x00871FD0
	//RaceSex Menu:				0x00885C90
	//SafeZoneMenu:				0x00887980
	//Fader Menu:				0x0085B020
	//Sleep/Wait Menu:			0x00887E60
	//Mist Menu:				0x0087C920
	//Kinect Menu:				0x0086E5E0
	//MessageBoxMenu:			0x0087A7D0
	//Book Menu:				0x00845C60
	//Loading Menu:				0x0086F290
	//Training Menu:			0x00893FC0
	//Crafting Menu:			0x0084ECD0
	//Cursor Menu:				0x00859B70
	//TweenMenu:				0x00895870
	//MapMenu:					0x008A1D90
	//BarterMenu:				0x00842B30
	//Console:					0x00847280
	//GiftMenu:					0x0085D1E0
	//MagicMenu:				0x00873D10
	//Dialogue Menu:			0x0085A2E0
	//HUD Menu:					0x00865F50

	struct MenuTableItem
	{
	public:
		IMenu				* menuInstance;		// 00	0 if the menu is not currently open
		FnMenuConstructor	* menuConstructor;	// 04
	};

	typedef BSTHashMap<BSFixedString, MenuTableItem> MenuTable;

	// 030
	struct Unknown3
	{
		UInt32		freqLow;	// 000 (= Frequency.LowPart)
		UInt32		freqHigh;	// 004 (= Frequency.HighPart)

		UInt32		unk_008;	// 008 (= 0)
		UInt32		unk_00C;	// 00C (= 0)
		UInt32		unk_010;	// 010 (= 0)
		UInt32		unk_014;	// 014 (= 0)
		UInt32		unk_018;	// 018 (= 0)
		UInt32		unk_01C;	// 018 (= frequency related)

		UInt32		unk_020;	// 020
		UInt32		unk_024;	// 024

		UInt32		unk_028;	// 028 (= 0)
		UInt32		unk_02C;	// 02C (= 0)
	};
	STATIC_ASSERT(sizeof(Unknown3) == 0x30);

	typedef IMenu*	(*CreatorFunc)(void);

	BSTEventSource<MenuOpenCloseEvent> * GetMenuOpenCloseEventSource()
	{
		return static_cast<BSTEventSource<MenuOpenCloseEvent> *>(this);
	}


	BSTEventSource<MenuModeChangeEvent> * GetMenuModeChangeEventSource()
	{
		return static_cast<BSTEventSource<MenuModeChangeEvent> *>(this);
	}

	bool			IsMenuOpen(const BSFixedString &menuName) const;
	IMenu *			GetMenu(const BSFixedString &menuName) const;
	GFxMovieView *	GetMovieView(const BSFixedString &menuName) const;
	void			Register(const char *name, CreatorFunc creator);
	void			OpenMenu(const BSFixedString &menuName);
	void			CloseMenu(const BSFixedString &menuName);

	static inline bool IsInMenuMode()
	{
		return ((bool(*)())0x00918D90)();
	}



	// @members
	//BSTSingletonSDM<MenuManager>				singleton;					// 000
	//BSTEventSource<MenuOpenCloseEvent>		menuOpenCloseEventSource;	// 004
	//BSTEventSource<MenuModeChangeEvent>		menuModeChangeEventSource;	// 034
	//BSTEventSource<void*>						unk_064;					// 064 - New in 1.6.87.0 - Kinect related?
	BSTArray<void*>			menuStack;					// 094
	MenuTable				menuTable;					// 0A0
	UInt32					unk_0C0;					// 0C0 (= 0)
	UInt32					unk_0C4;					// 0C4 (= 0)
	UInt32					numPauseGame;				// 0C8 (= 0) += 1 if (imenu->flags & 0x0001)
	UInt32					numItemMenu;				// 0CC (= 0) += 1 if (imenu->flags & 0x2000)
	UInt32					numPreventGameLoad;			// 0D0 (= 0) += 1 if (imenu->flags & 0x0080)
	UInt32					numDoNotPreventSaveGame;	// 0D4 (= 0) += 1 if (imenu->flags & 0x0800)
	UInt32					numStopCrosshairUpdate;		// 0D8 (= 0) += 1 if (imenu->flags & 0x4000)
	UInt32					numFlag8000;				// 0DC (= 0) += 1 if (imenu->flags & 0x8000)
	UInt32					numModal;					// 0E0 (= 0)  = 1 if (imenu->flags & 0x0010)
	UInt32					unk_0E4;					// 0E4
	Unknown3				unk_0E8;					// 0E8
	bool					unk_118;					// 118 (= 0)
	bool					unk_119;					// 119 (= 0)
	char					pad[2];


private:
	DEFINE_MEMBER_FN_const(IsMenuOpen_internal, bool, 0x00A5CE90, const BSFixedString &menuName);
	DEFINE_MEMBER_FN(Register_internal, void, 0x00A5D2A0, const char * name, CreatorFunc creator);

	friend struct BSTSingletonSDMBase<BSTSDMTraits<MenuManager>>;
	DEFINE_MEMBER_FN(ctor, MenuManager*, 0x00A5DE30);
};
STATIC_ASSERT(sizeof(MenuManager) == 0x11C);
