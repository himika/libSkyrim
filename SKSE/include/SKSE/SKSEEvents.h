#pragma once

#include <Skyrim.h>
#include <Skyrim/BSCore/BSFixedString.h>

class TESForm;
class TESObjectREFR;
class Actor;
class TESCameraState;

struct SKSEModCallbackEvent
{
	BSFixedString	eventName;
	BSFixedString	strArg;
	float			numArg;
	TESForm *		sender;
};

struct SKSECameraEvent
{
	TESCameraState * oldState;
	TESCameraState * newState;
};

struct SKSECrosshairRefEvent
{
	TESObjectREFR *		crosshairRef;
};

struct SKSEActionEvent
{
	enum {
		kType_WeaponSwing = 0,
		kType_SpellCast = 1,
		kType_SpellFire = 2,
		kType_VoiceCast = 3,
		kType_VoiceFire = 4,
		kType_BowDraw = 5,
		kType_BowRelease = 6,
		kType_BeginDraw = 7,
		kType_EndDraw = 8,
		kType_BeginSheathe = 9,
		kType_EndSheathe = 10
	};
	enum {
		kSlot_Left = 0,
		kSlot_Right = 1,
		kSlot_Voice = 2
	};

	UInt32 type;
	Actor * actor;
	TESForm	* sourceForm;
	UInt32	slot;
};

struct SKSENiNodeUpdateEvent
{
	TESObjectREFR * reference;
};
