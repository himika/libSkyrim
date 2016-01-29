#pragma once


struct GFxKey
{
public:
	enum Code
	{
		VoidSymbol      = 0,

		A               = 65,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,

		Num0            = 48,
		Num1,
		Num2,
		Num3,
		Num4,
		Num5,
		Num6,
		Num7,
		Num8,
		Num9,

		KP_0            = 96,
		KP_1,
		KP_2,
		KP_3,
		KP_4,
		KP_5,
		KP_6,
		KP_7,
		KP_8,
		KP_9,
		KP_Multiply,
		KP_Add,
		KP_Enter,
		KP_Subtract,
		KP_Decimal,
		KP_Divide,

		F1              = 112,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,
		F13,
		F14,
		F15,

		Backspace       = 8,
		Tab,
		Clear           = 12,
		Return,
		Shift           = 16,
		Control,
		Alt,
		Pause,
		CapsLock        = 20,
		Escape          = 27,
		Space           = 32,
		PageUp,
		PageDown,
		End             = 35,
		Home,
		Left,
		Up,
		Right,
		Down,
		Insert          = 45,
		Delete,
		Help,
		NumLock         = 144,
		ScrollLock      = 145,

		Semicolon       = 186,
		Equal           = 187,
		Comma           = 188,
		Minus           = 189,
		Period          = 190,
		Slash           = 191,
		Bar             = 192,
		BracketLeft     = 219,
		Backslash       = 220,
		BracketRight    = 221,
		Quote           = 222,

		OEM_AX          = 0xE1,
		OEM_102         = 0xE2,
		ICO_HELP        = 0xE3,
		ICO_00          = 0xE4,

		KeyCount
	};
};


// 01
class GFxSpecialKeysState 
{
public:
	enum
	{
		Key_ShiftPressed	= (1 << 0),		// 01
		Key_CtrlPressed		= (1 << 1),		// 02
		Key_AltPressed		= (1 << 2),		// 04
		Key_CapsToggled		= (1 << 3),		// 08
		Key_NumToggled		= (1 << 4),		// 10
		Key_ScrollToggled	= (1 << 5),		// 20
		Initialized_Bit		= (1 << 7),		// 80
		Initialized_Mask	= 0xFF
	};

	GFxSpecialKeysState() : states(0)
	{
	}

	GFxSpecialKeysState(UInt8 st) : states((UInt8)(st | Initialized_Bit))
	{
	}

	void Reset() { states = 0; }

	bool IsShiftPressed() const { return (states & Key_ShiftPressed) != 0; }
	bool IsCtrlPressed() const  { return (states & Key_CtrlPressed) != 0; }
	bool IsAltPressed() const   { return (states & Key_AltPressed) != 0; }
	bool IsCapsToggled() const  { return (states & Key_CapsToggled) != 0; }
	bool IsNumToggled() const   { return (states & Key_NumToggled) != 0; }
	bool IsScrollToggled() const{ return (states & Key_ScrollToggled) != 0; }

	void SetShiftPressed(bool v = true)  { (v) ? states |= Key_ShiftPressed : states &= ~Key_ShiftPressed; }
	void SetCtrlPressed(bool v = true)   { (v) ? states |= Key_CtrlPressed  : states &= ~Key_CtrlPressed; }
	void SetAltPressed(bool v = true)    { (v) ? states |= Key_AltPressed   : states &= ~Key_AltPressed; }
	void SetCapsToggled(bool v = true)   { (v) ? states |= Key_CapsToggled  : states &= ~Key_CapsToggled; }
	void SetNumToggled(bool v = true)    { (v) ? states |= Key_NumToggled   : states &= ~Key_NumToggled; }
	void SetScrollToggled(bool v = true) { (v) ? states |= Key_ScrollToggled: states &= ~Key_ScrollToggled; }

	bool IsInitialized() const { return (states & Initialized_Mask) != 0; }

	// @members
	UInt8   states;
};


// 04
class GFxEvent
{
public:
	enum EventType
	{
		None = 0,			// 0
		MouseMove,
		MouseDown,
		MouseUp,
		MouseWheel,
		KeyDown,
		KeyUp,
		SceneResize,
		SetFocus,
		KillFocus,
		DoShowMouse,
		DoHideMouse,
		DoSetMouseCursor,
		CharEvent,
		IMEEvent
	};

	GFxEvent(EventType a_type = None)
	{
		type = a_type;
	}

	// @members
	EventType type;		// 00
};



// 18
class GFxMouseEvent : public GFxEvent
{
public:
	GFxMouseEvent() : GFxEvent(), x(0.0f), y(0.0f), scrollDelta(0.0f), button(0), mouseIndex(0)
	{
	}

	// @members
	float	x;				// 04
	float	y;				// 08
	float	scrollDelta;	// 0C
	UInt32	button;			// 10
	UInt32	mouseIndex;		// 14
};


// 0C
class GFxMouseCursorEvent : public GFxEvent
{
public:
	enum CursorShapeType
	{
		ARROW = 0,
		HAND = 1,
		IBEAM = 2
	};
	
	GFxMouseCursorEvent() : GFxEvent(GFxEvent::DoSetMouseCursor), cursorShape(HAND), mouseIndex(0)
	{
	}

	// @members
	UInt32	cursorShape;	// 04
	UInt32	mouseIndex;		// 08
};


// 14
class GFxKeyEvent : public GFxEvent
{
public:
	GFxKeyEvent(EventType a_type = None, GFxKey::Code a_keyCode = GFxKey::VoidSymbol, UInt8 a_asciiCode = 0, UInt32 a_wcharCode = 0, UInt8 a_keyboardIndex = 0)
		: GFxEvent(a_type), keyCode(a_keyCode), asciiCode(a_asciiCode), wcharCode(a_wcharCode), keyboardIndex(a_keyboardIndex)
	{
	}

	GFxKeyEvent(EventType a_type, GFxKey::Code a_keyCode, UInt8 a_asciiCode, UInt32 a_wcharCode, GFxSpecialKeysState a_specialKeysState, UInt8 a_keyboardIndex = 0)
		: GFxEvent(a_type), keyCode(a_keyCode), asciiCode(a_asciiCode), wcharCode(a_wcharCode), specialKeysState(a_specialKeysState), keyboardIndex(a_keyboardIndex)
	{
	}

	// @members
	GFxKey::Code			keyCode;			// 04
	UInt8					asciiCode;			// 08 - left for compatibility reasons only
	UInt32					wcharCode;			// 0C - left for compatibility reasons only
	GFxSpecialKeysState		specialKeysState;	// 10
	UInt8					keyboardIndex;		// 11
};


// 0C
class GFxCharEvent : public GFxEvent
{
public:
	GFxCharEvent(UInt32 a_wcharCode, UInt8 a_keyboardIndex = 0) : GFxEvent(CharEvent), wcharCode(a_wcharCode), keyboardIndex(a_keyboardIndex)
	{
	}

	// @members
	UInt32	wcharCode;			// 04
	UInt8	keyboardIndex;		// 08
};
