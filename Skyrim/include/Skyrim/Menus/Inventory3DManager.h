#pragma once

#include "IMenu.h"
#include "../BSCore/BSTSingleton.h"
#include "../BSDevices/MenuEventHandler.h"

class TESForm;
class TESObjectREFR;

/*==============================================================================
class Inventory3DManager +0000 (_vtbl=010E5868)
0000: class Inventory3DManager
000C: |   struct BSTSingletonSDM<class Inventory3DManager,struct BSTSingletonSDMOpStaticBuffer>
000C: |   |   struct BSTSingletonSDMBase<struct BSTSDMTraits<class Inventory3DManager,struct BSTSingletonSDMOpStaticBuffer<class Inventory3DManager> > >
000C: |   |   |   struct BSTSDMTraits<class Inventory3DManager,struct BSTSingletonSDMOpStaticBuffer<class Inventory3DManager> >
000D: |   |   |   struct BSTSingletonSDMOpStaticBuffer<class Inventory3DManager>
0000: |   class MenuEventHandler
0004: |   |   struct BSIntrusiveRefCounted
==============================================================================*/
// E4
class Inventory3DManager : public BSTSingletonSDM<Inventory3DManager>,
	public MenuEventHandler
{
public:
	virtual ~Inventory3DManager();

	static Inventory3DManager * GetSingleton(void)
	{
		return *((Inventory3DManager **)0x01B2E99C);
	}

	//void			** _vtbl;					// 00 - 010E5868
	float			unk10[(0x30 - 0x10) / 4];
	UInt32			unk30;
	TESObjectREFR	* object;					// 34
	UInt32			unk38;
	UInt32			unk3C;
	UInt32			unk40;

	struct ItemData
	{
		TESForm	* unk04;
		TESForm	* unk08;
		void	* unk0C;
		void	* unk10;
		float	unk14;
	};

	ItemData		unk44[7];
	UInt32			unkD0; // Number of ItemDatas?
	UInt32			unkD4;
	UInt32			unkD8;
	UInt32			unkDC;
	UInt8			unkE0;
	UInt8			unkE1; // Somekind of mode (0 for MagicMenu)
	UInt8			unkE2;
	UInt8			padE3;

	DEFINE_MEMBER_FN(UpdateItem3D, void, 0x00867C00, PlayerCharacter::ObjDesc * objDesc);
	DEFINE_MEMBER_FN(UpdateMagic3D, void, 0x00867930, TESForm * form, UInt32 unk1);
	DEFINE_MEMBER_FN(Clear3D, void, 0x008668C0);
	DEFINE_MEMBER_FN(Render, UInt32, 0x00867730);

	//DEFINE_MEMBER_FN(Unk1, void, 0x008667E0, UInt32 unk1);
	//DEFINE_MEMBER_FN(Unk2, void, 0x00867110);
	//DEFINE_MEMBER_FN(Unk3, bool, 0x008664C0);
	//DEFINE_MEMBER_FN(Unk4, double, 0x008663E0);
	//DEFINE_MEMBER_FN(Unk5, bool, 0x008418D0);
	//DEFINE_MEMBER_FN(Unk6, int, 0x00867730);
};
STATIC_ASSERT(offsetof(Inventory3DManager, unk10) == 0x10);
STATIC_ASSERT(offsetof(Inventory3DManager, object) == 0x34);
STATIC_ASSERT(offsetof(Inventory3DManager, unkE0) == 0xE0);

