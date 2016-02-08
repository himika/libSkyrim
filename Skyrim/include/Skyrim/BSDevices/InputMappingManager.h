
#include "../BSCore/BSTSingleton.h"
#include "../BSCore/BSFixedString.h"
#include "../BSCore/BSTEvent.h"
#include "../Events/MenuEvent.h"

// 09C+
class InputMappingManager :
	public BSTSingletonSDM<InputMappingManager>,	// 00
	public BSTEventSource<UserEventEnabledEvent>	// 04
{
public:
	enum DeviceType
	{
		kDevice_Keyboard = 0,
		kDevice_Mouse,
		kDevice_Gamepad
	};
	
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
		kContextCount = 17,

		kContext_Invalid = 18
	};


	struct InputMapping
	{
		// 10
		struct Data
		{
			BSFixedString	name;		// 00 - User Event Name
			UInt32			buttonID;	// 04
			UInt32			sortIndex;	// 08
			UInt32			flags;		// 0C - User Event Binary Flag
		};

		// @members
		BSTArray<Data>	keyboardMap;
		BSTArray<Data>	mouseMap;
		BSTArray<Data>	gamepadMap;
	};

	// 14;
	struct UnkData
	{
		BSFixedString	unk00;
		UInt32			unk04;
		UInt32			unk08;
		UInt32			unk0C;
		BSFixedString	unk10;
	};
	STATIC_ASSERT(sizeof(UnkData) == 0x14);

	UInt32 GetMappedKey(const BSFixedString &name, DeviceType deviceType, ContextType contextIdx = kContext_Gameplay) const;
	const BSFixedString & GetUserEventName(UInt32 buttonID, DeviceType deviceType, ContextType contextIdx = kContext_Gameplay) const;

	// @members
	InputMapping		* mappings[kContextCount];		// 34
	BSTArray<UnkData>	unk78;							// 78
	BSTArray<UInt32>	unk84;							// 84
	SInt32				unk90;							// 90 - init'd -1
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
