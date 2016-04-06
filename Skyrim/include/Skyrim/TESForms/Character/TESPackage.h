#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../BSCore/BSTArray.h"

class TESQuest;

/*==============================================================================
class TESPackage +0000 (_vtbl=010C4434)
0000: class TESPackage
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 80
class TESPackage : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::Package };

	enum PackageType
	{
		kPackageType_Find = 0,
		kPackageType_Follow,
		kPackageType_Escort,
		kPackageType_Eat,
		kPackageType_Sleep,
		kPackageType_Wander,
		kPackageType_Travel,
		kPackageType_Accompany,
		kPackageType_UseItemAt,
		kPackageType_Ambush,
		kPackageType_FleeNotCombat,
		kPackageType_CastMagic,
		kPackageType_Sandbox,
		kPackageType_Patrol,
		kPackageType_Guard,
		kPackageType_Dialogue,
		kPackageType_UseWeapon,
		kPackageType_Find2,
		kPackageType_Package,
		kPackageType_PackageTemplate,
		kPackageType_Activate,
		kPackageType_Alarm,
		kPackageType_Flee,
		kPackageType_Trespass,
		kPackageType_Spectator,
		kPackageType_ReactToDead,
		kPackageType_GetUpFromChair,
		kPackageType_DoNothing,
		kPackageType_InGameDialogue,
		kPackageType_Surface,
		kPackageType_SearchForAttacker,
		kPackageType_AvoidPlayer,
		kPackageType_ReactToDestroyedObject,
		kPackageType_ReactToGrenadeOrMine,
		kPackageType_StealWarning,
		kPackageType_PickPocketWarning,
		kPackageType_MovementBlocked,
		kPackageType_Unk37,
		kPackageType_Unk38
	};

	// @override
	virtual void *			Unk_2D(void) override;				// 005E22D0 { return unk7C; }
	virtual const char *	GetTypeString(void) const override;	// 00401AA0 - Find, Follow, Escort, Eat...

	// @add
	virtual bool	Unk_3B(UInt32 arg0, UInt32 arg1, UInt32 arg2, UInt32 arg3);					// 005E35C0
	virtual bool	Unk_3C(UInt32 arg0, UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4);	// 005E31A0
	virtual bool	Unk_3D(UInt32 arg0, UInt32 arg1);											// 005E3980
	virtual bool	Unk_3E(UInt32 arg0, UInt32 arg1);											// 005E3CE0
	virtual bool	Unk_3F(UInt32 arg0);														// 00C8CCA0 { return true; }


	///<summary>Gets the quest that owns this package.</summary>
	TESQuest * GetOwningQuest(void) const
	{
		return quest;
	}

	bool IsExtraType() const;	// 005DEFA0


	// C
	struct Data30
	{
		UInt8	unk00;		// 0
		UInt8	unk01;		// 1
		UInt8	unk02;		// 2
		UInt8	unk03;		// 3
		UInt8	unk04;		// 4
		UInt8	pad05[3];	// 5
		UInt32	unk08;		// 8
	};

	// 10
	struct Data
	{
		UInt32	unk00;	// 00
		UInt32	unk04;	// 04
		UInt32	unk08;	// 08
		UInt32	unk0C;	// 0C
	};


	// @members
	UInt32		packageFlags;	// 14
	UInt8		type;			// 18 - see kPackageType_ enum
	UInt8		unk19;			// 19
	UInt8		unk1A;			// 1A
	UInt8		pad1B;			// 1B
	UInt16		unk1C;			// 1C
	UInt16		unk1E;			// 1E
	UInt32		unk20;			// 20
	UInt32		unk24;			// 24
	UInt32		unk28;			// 28
	UInt32		unk2C;			// 2C
	Data30		unk30;			// 30
	void		* unk3C;		// 3C - linked list
	UInt32		unk40;			// 40
	TESQuest	* quest;		// 44
	Data		unk48;			// 48
	Data		unk58;			// 58
	Data		unk68;			// 68
	UInt32		unk78;			// 78
	UInt32		unk7C;			// 7C - incremented in dtor
};
STATIC_ASSERT(sizeof(TESPackage) == 0x80);


/*==============================================================================
class AlarmPackage +0000 (_vtbl=010D4CA4)
0000: class AlarmPackage
0000: |   class TESPackage
0000: |   |   class TESForm
0000: |   |   |   class BaseFormComponent
==============================================================================*/
// 8C
class AlarmPackage : public TESPackage
{
public:
	UInt32	unk80;		// 80
	UInt32	unk84;		// 84
	UInt8	unk88;		// 88
	UInt8	pad89[3];	// 89
};

/*==============================================================================
class DialoguePackage +0000 (_vtbl=010C453C)
0000: class DialoguePackage
0000: |   class TESPackage
0000: |   |   class TESForm
0000: |   |   |   class BaseFormComponent
==============================================================================*/
// A0
class DialoguePackage : public TESPackage
{
public:
	UInt32	unk80;		// 80
	UInt32	unk84;		// 84
	UInt32	unk88;		// 88
	UInt32	unk8C;		// 8C
	UInt8	unk90;		// 90
	UInt8	unk91;		// 91
	UInt8	pad92[2];	// 92
	UInt32	unk94;		// 94
	UInt32	unk98;		// 98
	UInt8	unk9C;		// 9C
	UInt8	pad9D[3];	// 9D
};

/*==============================================================================
class FleePackage +0000 (_vtbl=010D4E54)
0000: class FleePackage
0000: |   class TESPackage
0000: |   |   class TESForm
0000: |   |   |   class BaseFormComponent
==============================================================================*/
// AC
class FleePackage : public TESPackage
{
public:
	struct Data8C
	{
		UInt32	unk0;	// 0
		UInt32	unk4;	// 4
		UInt32	unk8;	// 8
	};

	BSTArray<void*>	unk80;		// 80
	Data8C			unk8C;		// 8C
	float			unk98;		// 98
	UInt32			unk9C;		// 9C
	UInt32			unkA0;		// A0
	UInt8			unkA4;		// A4
	UInt8			unkA5;		// A5
	UInt8			unkA6;		// A6
	UInt8			unkA7;		// A7
	UInt8			unkA8;		// A8
	UInt8			padA9[3];	// A9
};

/*==============================================================================
class SpectatorPackage +0000 (_vtbl=010D513C)
0000: class SpectatorPackage
0000: |   class TESPackage
0000: |   |   class TESForm
0000: |   |   |   class BaseFormComponent
==============================================================================*/
// B0
class SpectatorPackage : public TESPackage
{
public:
	struct Data94
	{
		UInt32	unk0;	// 0
		UInt32	unk4;	// 4
		UInt32	unk8;	// 8
	};

	UInt32			unk80;		// 80
	UInt32			pad84;		// 84 - not init'd
	UInt32			unk88;		// 88
	UInt32			unk8C;		// 8C
	UInt8			unk90;		// 90
	UInt8			pad91[3];	// 91
	Data94			unk94;		// 94
	BSTArray<void*>	unkA0;	// A0
	UInt32			padAC;		// AC - not init'd
};

/*==============================================================================
class TrespassPackage +0000 (_vtbl=010D5264)
0000: class TrespassPackage
0000: |   class TESPackage
0000: |   |   class TESForm
0000: |   |   |   class BaseFormComponent
==============================================================================*/
// 98
class TrespassPackage : public TESPackage
{
public:
	UInt32	unk80;	// 80
	UInt32	unk84;	// 84
	UInt32	unk88;	// 88
	UInt32	unk8C;	// 8C
	UInt32	unk90;	// 90
	UInt32	unk94;	// 94
};
