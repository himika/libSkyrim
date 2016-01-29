#pragma once

#include "../BSCore/BSTEvent.h"
#include "../BSCore/BSFixedString.h"

/*==============================================================================
class InputEvent +0000 (_vtbl=010D44D0)
0000: class InputEvent
==============================================================================*/
class InputEvent
{
public:
	enum
	{
		kEventType_Button = 0,		// 0
		kEventType_MouseMove,		// 1
		kEventType_Char,			// 2
		kEventType_Thumbstick,		// 3
		kEventType_DeviceConnect,	// 4
		kEventType_Kinect			// 5
	};

	virtual	~InputEvent();										// 00A690D0

	virtual bool					IsIDEvent() const;			// 0092D110 { return false; }
	virtual const BSFixedString &	GetControlID() const;		// 00771290 { static BSFixedString str(""); return str; }

	// @members
	//void			** _vtbl;	// 00
	UInt32			deviceType;	// 04
	UInt32			eventType;	// 08
	InputEvent		* next;		// 0C
};


/*==============================================================================
class IDEvent +0000 (_vtbl=????????)
0000: class IDEvent
0000: |   class InputEvent
==============================================================================*/
class IDEvent : public InputEvent
{
public:
	virtual	~IDEvent();												// 0087D8D0

	// @override
	virtual bool					IsIDEvent() const override;		// 009B86F0 { return true; }
	virtual const BSFixedString &	GetControlID() const override;	// 00667000 { return controlID; }

	// @members
	BSFixedString	controlID;	// 10
};


/*==============================================================================
class ButtonEvent +0000 (_vtbl=010D44E0)
0000: class ButtonEvent
0000: |   class IDEvent
0000: |   |   class InputEvent
==============================================================================*/
// 20
class ButtonEvent : public IDEvent
{
public:
	UInt32	keyMask;	// 14
	float	pressure;	// 18
	float	timer;		// 1C (hold duration)

	inline bool IsPressed() const {
		return pressure > 0;
	}

	inline bool IsDown() const {
		return (pressure > 0) && (timer == 0);
	}

	inline bool IsUp() const {
		return (pressure == 0) && (timer > 0);
	}

	DEFINE_MEMBER_FN_const(IsLongTap, bool, 0x00770F00, float timeThreshold);
};

/*==============================================================================
class MouseMoveEvent +0000 (_vtbl=0110E8F4)
0000: class MouseMoveEvent
0000: |   class IDEvent
0000: |   |   class InputEvent
==============================================================================*/
// 20
class MouseMoveEvent : public IDEvent
{
public:
	enum { kInputType_Mouse = 0x0A };

	// members
	UInt32	source;		// 14 - always 0x0A ?
	SInt32	moveX;		// 18
	SInt32	moveY;		// 1C
};


/*==============================================================================
class ThumbstickEvent +0000 (_vtbl=010E73A4)
0000: class ThumbstickEvent
0000: |   class IDEvent
0000: |   |   class InputEvent
==============================================================================*/
class ThumbstickEvent : public IDEvent
{
public:
	enum {									// (himika)
		kInputType_LeftThumbstick  = 0x0B,	//
		kInputType_RightThumbstick = 0x0C	//
	};										//


	bool IsLeft(void) const {
		return keyMask == kInputType_LeftThumbstick;
	}

	bool IsRight(void) const {
		return keyMask == kInputType_RightThumbstick;
	}

	// members
	//void	** _vtbl;	// 00 - 010E73A4
	UInt32	keyMask;	// 14 - b for left stick, c for right stick
	float	x;			// 18
	float	y;			// 1C
};
STATIC_ASSERT(offsetof(ThumbstickEvent, y) == 0x1C);


/*==============================================================================
class KinectEvent +0000 (_vtbl=0110E924)
0000: class KinectEvent
0000: |   class IDEvent
0000: |   |   class InputEvent
==============================================================================*/
class KinectEvent : public IDEvent
{
public:
	virtual ~KinectEvent();		// 00A69100

	UInt32			code;		// 10
	UInt32			unk14;		// 14
	BSFixedString	unk18;		// 18
};

/*==============================================================================
class CharEvent +0000 (_vtbl=0110E904)
0000: class CharEvent
0000: |   class InputEvent
==============================================================================*/
// 14
class CharEvent : public InputEvent
{
public:
	UInt32			keyCode;		// 10 (ascii code)
};

/*==============================================================================
class DeviceConnectEvent +0000 (_vtbl=0110E914)
0000: class DeviceConnectEvent
0000: |   class InputEvent
==============================================================================*/
class DeviceConnectEvent : public InputEvent
{
};
