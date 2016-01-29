#pragma once

#include "../BSDevices/InputDevice.h"
#include "../BSCore/BSTSingleton.h"
#include "../Events/InputEvent.h"
#include "../Events/MenuEvent.h"
#include "../Events/ScriptEvent.h"


// 1A0
class InputStringHolder : public BSTSingletonSDM<InputStringHolder>
{
public:
	BSFixedString	forward;			// 004 "Forward"
	BSFixedString	back;				// 008 "Back"
	BSFixedString	strafeLeft;			// 00C "Strafe Left"
	BSFixedString	strafeRight;		// 010 "Strafe Right"
	BSFixedString	move;				// 014 "Move"
	BSFixedString	look;				// 018 "Look"
	BSFixedString	activate;			// 01C "Activate"
	BSFixedString	leftAttack;			// 020 "Left Attack/Block"
	BSFixedString	rightAttack;		// 024 "Right Attack/Block"
	BSFixedString	dualAttack;			// 028 "Dual Attack"
	BSFixedString	forceRelease;		// 02C "ForceRelease"
	BSFixedString	pause;				// 030 "Pause"
	BSFixedString	readyWeapon;		// 034 "Ready Weapon"
	BSFixedString	togglePOV;			// 038 "Toggle POV"
	BSFixedString	jump;				// 03C "Jump"
	BSFixedString	journal;			// 040 "Journal"
	BSFixedString	sprint;				// 044 "Sprint"
	BSFixedString	sneak;				// 048 "Sneak"
	BSFixedString	shout;				// 04C "Shout"
	BSFixedString	kinectShout;		// 050 "KinectShout"
	BSFixedString	grab;				// 054 "Grab"
	BSFixedString	run;				// 058 "Run"
	BSFixedString	toggleRun;			// 05C "Toggle Always Run"
	BSFixedString	autoMove;			// 060 "Auto-Move"
	BSFixedString	quicksave;			// 064 "Quicksave"
	BSFixedString	quickload;			// 068 "Quickload"
	BSFixedString	newSave;			// 06C "NewSave"
	BSFixedString	inventory;			// 070 "Inventory"
	BSFixedString	stats;				// 074 "Stats"
	BSFixedString	map;				// 078 "Map"
	BSFixedString	screenshot;			// 07C "Screenshot"
	BSFixedString	multiScreenshot;	// 080 "Multi-Screenshot"
	BSFixedString	console;			// 084 "Console"
	BSFixedString	cameraPath;			// 088 "CameraPath"
	BSFixedString	tweenMenu;			// 08C "Tween Menu"
	BSFixedString	takeAll;			// 090 "Take All"
	BSFixedString	accept;				// 094 "Accept"
	BSFixedString	cancel;				// 098 "Cancel"
	BSFixedString	up;					// 09C "Up"
	BSFixedString	down;				// 0A0 "Down"
	BSFixedString	left;				// 0A4 "Left"
	BSFixedString	right;				// 0A8 "Right"
	BSFixedString	pageUp;				// 0AC "PageUp"
	BSFixedString	pageDown;			// 0B0 "PageDown"
	BSFixedString	pick;				// 0B4 "Pick"
	BSFixedString	pickNext;			// 0B8 "PickNext"
	BSFixedString	pickPrevious;		// 0BC "PickPrevious"
	BSFixedString	cursor;				// 0C0 "Cursor"
	BSFixedString	kinect;				// 0C4 "Kinect"
	BSFixedString	sprintStart;		// 0C8 "SprintStart"
	BSFixedString	sprintStop;			// 0CC "SprintStop"
	BSFixedString	sneakStart;			// 0D0 "sneakStart"
	BSFixedString	sneakStop;			// 0D4 "sneakStop"
	BSFixedString	blockStart;			// 0D8 "blockStart"
	BSFixedString	blockStop;			// 0DC "blockStop"
	BSFixedString	blockBash;			// 0E0 "blockBash"
	BSFixedString	attackStart;		// 0E4 "attackStart"
	BSFixedString	attackPowerStart;	// 0E8 "attackPowerStart"
	BSFixedString	reverseDirection;	// 0EC "reverseDirection"
	BSFixedString	unequip;			// 0F0 "Unequip"
	BSFixedString	zoomIn;				// 0F4 "Zoom In"
	BSFixedString	zoomOut;			// 0F8 "Zoom Out"
	BSFixedString	rotateItem;			// 0FC "RotateItem"
	BSFixedString	leftStick;			// 100 "Left Stick"
	BSFixedString	prevPage;			// 104 "PrevPage"
	BSFixedString	nextPage;			// 108 "NextPage"
	BSFixedString	prevSubPage;		// 10C "PrevSubPage"
	BSFixedString	nextSubPage;		// 110 "NextSubPage"
	BSFixedString	leftEquip;			// 114 "LeftEquip"
	BSFixedString	rightEquip;			// 118 "RightEquip"
	BSFixedString	toggleFavorite;		// 11C "ToggleFavorite"
	BSFixedString	favorites;			// 120 "Favorites"
	BSFixedString	hotkey1;			// 124 "Hotkey1"
	BSFixedString	hotkey2;			// 128 "Hotkey2"
	BSFixedString	hotkey3;			// 12C "Hotkey3"
	BSFixedString	hotkey4;			// 130 "Hotkey4"
	BSFixedString	hotkey5;			// 134 "Hotkey5"
	BSFixedString	hotkey6;			// 138 "Hotkey6"
	BSFixedString	hotkey7;			// 13C "Hotkey7"
	BSFixedString	hotkey8;			// 140 "Hotkey8"
	BSFixedString	quickInventory;		// 144 "Quick Inventory"
	BSFixedString	quickMagic;			// 148 "Quick Magic"
	BSFixedString	quickStats;			// 14C "Quick Stats"
	BSFixedString	quickMap;			// 150 "Quick Map"
	BSFixedString	toggleCursor;		// 154 "ToggleCursor"
	BSFixedString	wait;				// 158 "Wait"
	BSFixedString	click;				// 15C "Click"
	BSFixedString	mapLookMode;		// 160 "MapLookMode"
	BSFixedString	equip;				// 164 "Equip"
	BSFixedString	dropItem;			// 168 "DropItem"
	BSFixedString	rotate;				// 16C "Rotate"
	BSFixedString	nextFocus;			// 170 "NextFocus"
	BSFixedString	prevFocus;			// 174 "PreviousFocus"
	BSFixedString	setActiveQuest;		// 178 "SetActiveQuest"
	BSFixedString	placePlayerMarker;	// 17C "PlacePlayerMarker"
	BSFixedString	xButton;			// 180 "XButton"
	BSFixedString	yButton;			// 184 "YButton"
	BSFixedString	chargeItem;			// 188 "ChargeItem"
	UInt32			unk18C;				// 18C
	BSFixedString	playerPosition;		// 190 "PlayerPosition"
	BSFixedString	localMap;			// 194 "LocalMap"
	BSFixedString	localMapMoveMode;	// 198 "LocalMapMoveMode"
	BSFixedString	itemZoom;			// 19C "Item Zoom"

private:
	friend struct BSTSingletonSDMBase<BSTSDMTraits<InputStringHolder>>;
	DEFINE_MEMBER_FN(ctor, InputStringHolder*, 0x00A6A0E0);
};
STATIC_ASSERT(sizeof(InputStringHolder) == 0x1A0);


// 44
class InputManager :
	public BSTEventSource<InputEvent *>,
	public BSTSingletonSDM<InputManager>
{
public:
	bool IsGamepadEnabled(void) const	// 00A68E80
	{
		return (gamepad != nullptr) && gamepad->IsEnabled();
	}

	// @members
	BSKeyboardDevice	* keyboard;		// 034 - BSWin32KeyboardDevice
	BSMouseDevice		* mouse;		// 038 - BSWin32MouseDevice
	BSGamepadDevice		* gamepad;		// 03C - BSWin32GamepadDevice
	bool				unk40;			// 040 - init'd true
	bool				unk41;			// 041 - init'd false

private:
	friend struct BSTSingletonSDMBase<BSTSDMTraits<InputManager>>;
	DEFINE_MEMBER_FN(ctor, InputManager*, 0x00A68FA0);
};
STATIC_ASSERT(offsetof(InputManager, keyboard) == 0x34);
STATIC_ASSERT(sizeof(InputManager) == 0x44);
