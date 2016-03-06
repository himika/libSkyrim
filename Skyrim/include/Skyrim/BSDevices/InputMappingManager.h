
#include "../BSCore/BSTSingleton.h"
#include "../BSCore/BSFixedString.h"
#include "../BSCore/BSTEvent.h"
#include "../Events/MenuEvent.h"
#include "InputDevice.h"

// 09C+
class InputMappingManager :
	public BSTSingletonSDM<InputMappingManager>,	// 00
	public BSTEventSource<UserEventEnabledEvent>	// 04
{
public:
	enum ContextType
	{
		kContext_Gameplay = 0,
		kContext_MenuMode,
		kContext_Console,
		kContext_ItemMenu,
		kContext_Inventory,
		kContext_DebugText,
		kContext_Favorites,
		kContext_Map,
		kContext_Stats,
		kContext_Cursor,
		kContext_Book,
		kContext_DebugOverlay,
		kContext_Journal,
		kContext_TFCMode,
		kContext_MapDebug,
		kContext_Lockpicking,
		kContext_Favor,
		kContextCount,

		kContext_Invalid		// 0x12
	};

	enum ControlState
	{
		kControlState_Looking	= 0x002,
		kControlState_Flying	= 0x040,
		kControlState_Sneaking	= 0x080,
		kControlState_Menu		= 0x100,
		kControlState_Movement	= 0x401
	};

	struct InputMapping
	{
		// 10
		struct Data
		{
			BSFixedString	name;		// 00 - User Event Name
			UInt16			buttonID;	// 04
			UInt16			modifier;	// 06
			UInt32			sortIndex;	// 08
			UInt32			flags;		// 0C - User Event Binary Flag
		};

		// @members
		BSTArray<Data>	keyboardMap;
		BSTArray<Data>	mouseMap;
		BSTArray<Data>	gamepadMap;
	};

	// 14
	struct UnkData
	{
		BSFixedString	unk00;
		UInt32			unk04;
		UInt32			unk08;
		UInt32			unk0C;
		BSFixedString	unk10;
	};
	STATIC_ASSERT(sizeof(UnkData) == 0x14);

	enum
	{
		kInvalid = 0xFFFFFFFF
	};

	UInt32 GetMappedKey(const BSFixedString &name, BSInputDevice::Type deviceType, ContextType contextIdx = kContext_Gameplay) const;
	const BSFixedString & GetUserEventName(UInt32 buttonID, BSInputDevice::Type deviceType, ContextType contextIdx = kContext_Gameplay) const;

	inline bool IsLookingControlsEnabled() const	{ return (controlState & kControlState_Looking) == kControlState_Looking; }
	inline bool IsFlyingControlsEnabled() const		{ return (controlState & kControlState_Flying) == kControlState_Flying; }
	inline bool IsSneakingControlsEnabled() const	{ return (controlState & kControlState_Sneaking) == kControlState_Sneaking; }
	inline bool IsMenuControlsEnabled() const		{ return (controlState & kControlState_Menu) == kControlState_Menu; }
	inline bool IsMovementControlsEnabled() const	{ return (controlState & kControlState_Movement) == kControlState_Movement; }

	// @members
	InputMapping		* mappings[kContextCount];		// 34
	BSTArray<UnkData>	unk78;							// 78
	BSTArray<UInt32>	unk84;							// 84
	SInt32				controlState;					// 90 - init'd -1
	UInt32				unk94;							// 94 - init'd 0x80000000
	UInt8				unk98;							// 98 - init'd 0
	UInt8				unk99;							// 99 - init'd 0
	UInt8				unk9A;							// 9A - init'd 0

private:
	friend struct BSTSingletonSDMBase<BSTSDMTraits<InputMappingManager>>;
	DEFINE_MEMBER_FN(ctor, InputMappingManager*, 0x00A68770);

	DEFINE_MEMBER_FN(DisableUserEvent, void, 0x00A67A30, UInt32 flags, bool unk1, book unk2);

};
STATIC_ASSERT(offsetof(InputMappingManager, unk78) == 0x78);
STATIC_ASSERT(offsetof(InputMappingManager, unk84) == 0x84);
