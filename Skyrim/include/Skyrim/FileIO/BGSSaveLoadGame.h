#pragma once

#include "../NetImmerse/NiCriticalSection.h"
#include "../BSCore/BSTHashMap.h"
#include "../BSCore/BSTArray.h"
#include "BGSSaveLoadManager.h"

class TESForm;

// 3F8
class BGSSaveLoadGame
{
public:
	typedef BSTHashMap<UInt32, UInt32> UnkHashMap;			// sentinel 01243758
	typedef BSTHashMap<FormID, FormID> UnkFormIDMap;		// sentinel 012723C0
	typedef BSTHashMap<FormID, void *> UnkCellMap;			// sentinel 012724B8
	typedef BSTHashMap<FormID, void *> UnkWorldSpaceMap;	// sentinel 012724BC

	struct FormFlagData
	{
		UInt32	flag1;
		UInt32	flag2;
	};

	class FormFlagMap
	{
	public:
		FormFlagMap() {}

		bool GetAt(FormID formID, FormFlagData &flags);
		bool Exists(FormID formID);
		DEFINE_MEMBER_FN(RemoveAt, bool, 0x00676EA0, FormID formID);
		DEFINE_MEMBER_FN(SetFlag1At, bool, 0x00676EA0, FormID formID, UInt32 flag1);

		// @members
		BSTHashMap<FormID, FormFlagData>	map;		// 00
		NiCriticalSection					lock;		// 20

	private:
		DEFINE_MEMBER_FN(ctor, FormFlagMap, 0x00676F30);
		DEFINE_MEMBER_FN(GetAt_Impl, bool, 0x00676BC0, FormID formID, FormFlagData &flags);
		DEFINE_MEMBER_FN(Exists_Impl, bool, 0x00676DB0, FormID formID);
		DEFINE_MEMBER_FN(MarkChanged_Impl, void, 0x00676FA0, FormID formID, UInt32 flags);
	};
	STATIC_ASSERT(sizeof(FormFlagMap) == 0x28);

	static BGSSaveLoadGame* GetSingleton() {
		return *(BGSSaveLoadGame**)0x01B2E38C;
	}

	DEFINE_MEMBER_FN(MarkChanged, void, TESForm *form, UInt32 flags, bool unk);
	DEFINE_MEMBER_FN(IsGeneratedReference, bool, 0x00678A80, TESForm *form, bool unk);	// called in BGSSaveLoadGame::MarkChanged

	// @members
	char				unk000[0x200];			// 000
	UnkHashMap			unk200;					// 200 - sentinel 01243758 *
	UnkHashMap			unk220;					// 220 - sentinel 01243758 *
	UInt32				unk240;					// 240
	UnkFormIDMap		unk244;					// 244 - sentinel 012723C0
	UnkHashMap			unk264;					// 264 - sentinel 01243758 *
	UnkCellMap			unk284;					// 284 - sentinel 012724B8
	UnkWorldSpaceMap	unk2A4;					// 2A4 - sentinel 012724BC
	UnkHashMap			unk2C4;					// 2C4 - sentinel 01243758 *
	UnkHashMap			unk2E4;					// 2E4 - sentinel 01240258
	UInt32				unk304[10];				// 304
	UnkHashMap			unk32C;					// 32C - sentinel 012726AC @
	UnkHashMap			unk34C;					// 34C - sentinel 012726AC @
	UnkHashMap			unk36C;					// 36C - sentinel 012726AC @
	UnkHashMap			unk38C;					// 38C - sentinel 01243758 *
	UnkHashMap			unk3AC;					// 3AC - sentinel 01243758 *
	UInt32				unk3CC[4];				// 3CC
	BSTArray<BGSLoadFormData*>	unk3DC;			// 3DC
	FormFlagMap			* flagMap;				// 3E8
	UInt32				unk3EC;					// 3EC
	UInt32				unk3F0;					// 3F0
	UInt32				unk3F4;					// 3F4

private:
	DEFINE_MEMBER_FN(ctor, BGSSaveLoadGame, 0x0067AEF0);
	DEFINE_MEMBER_FN(dtor, void, 0x0067B000);

	DEFINE_MEMBER_FN(ClearForm, void, 0x00678DC0, TESForm *form);
	DEFINE_MEMBER_FN(SaveGame, void, 0x00679200, const char *name);
	DEFINE_MEMBER_FN(LoadGame, void, 0x0067B720, const char *name, bool unk);

	DEFINE_MEMBER_FN(ExistsMarkChanged, bool, 0x00677FA0, FormID formID);
};
STATIC_ASSERT(offsetof(BGSSaveLoadGame, flagMap) == 0x3E8);
STATIC_ASSERT(sizeof(BGSSaveLoadGame) == 0x3F8);
