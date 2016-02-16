#pragma once

#include "../../../Animation/BSResponse.h"
#include "../../../Animation/BSAnimationGraphManager.h"
#include "../../../BSCore/BSFixedString.h"
#include "../../../BSCore/BSTList.h"


class TESForm;
class ActiveEffect;
class Actor;
class TESIdleForm;
class TESTopic;
class TESPackage;
class CustomActorPackageData;
class PerkEntryVisitor;
class NiNode;
class ActorKnowledge;
class BGSAIWorldLocationRefRadius;
class PathingCell;
class NavMesh;

typedef BSResponse<class BSFixedStringCI, class Actor, class BSFixedStringCI, DoNothingUnhandledPolicy> BSAnimationResponse;
typedef BSTSmartPointer<BSAnimationResponse> BSAnimationResponsePtr;


class MiddleProcess
{
public:
	struct Data30
	{
		UInt32	unk00;		// 00
		UInt32	unk04;		// 04
		UInt32	unk08;		// 08
		UInt32	unk0C;		// 0C
		UInt32	unk10;		// 10
		UInt32	unk14;		// 14
		UInt32	unk18;		// 18 - (AggroRadius Violated - 14)
	};

	UInt32		unk00;			// 00
	UInt32		unk04;			// 04
	void		* unk08;		// 08 - animation graph channel?
	UInt32		unk0C;			// 0C
	UInt32		unk10;			// 10
	UInt32		unk14;			// 14
	UInt32		unk18;			// 18
	UInt32		unk1C;			// 1C
	UInt32		unk20;			// 20
	UInt32		unk24;			// 24
	UInt32		unk28;			// 28
	float		unk2C;			// 2C
	Data30		* unk30;		// 30
	UInt32		unk34;			// 34
	UInt32		unk38;			// 38
	UInt32		unk3C;			// 3C
	float		unk40;			// 40
	UInt32		unk44;			// 44
	UInt32		unk48;			// 48
	UInt32		unk4C;			// 4C
	UInt32		unk50;			// 50
	UInt32		unk54;			// 54
	UInt32		unk58;			// 58
	UInt32		unk5C;			// 5C
	float		unk60;			// 60
	UInt32		unk64;			// 64
	UInt32		unk68;			// 68
	UInt32		unk6C;			// 6C
	UInt32		unk70;			// 70
	float		unk74;			// 74 - refered by Actor::IMovementState_Unk_06()
	UInt32		unk78;			// 78
	UInt32		unk7C;			// 7C
	UInt32		unk80;			// 80
	float		unk84;			// 84
	float		unk88;			// 88
	float		unk8C;			// 8C
	float		unk90;			// 90
	float		unk94;			// 94
	float		unk98;			// 98
	UInt32		unk9C;			// 9C
	UInt32		unkA0;			// A0
	BSAnimationResponsePtr	response;	// A4
	UInt32		unkA8;			// A8
	UInt32		unkAC;			// AC
	UInt32		unkB0;			// B0
	void		* unkB4;		// B4 - NiNode
	void		* unkB8;		// B8 - NiNode
	void		* unkBC;		// BC - NiNode
	UInt32		unkC0;			// C0
	void		* unkC4;		// C4 - NiNode
	UInt32		unkC8;			// C8
	UInt32		unkCC;			// CC
	UInt32		unkD0;			// D0
	void		* unkD4;		// D4 - NiNode
	void		* unkD8;		// D8 - NiNode
	UInt32		unkDC;			// D8
	void		* unkE0;		// E0 - BSFaceGenNiNode
	void		* unkE4;		// E4
	UInt32		unkE8;			// E8
	UInt32		unkEC;			// EC
	UInt32		unkF0;			// F0
	UInt32		unkF4;			// F4
	BSSimpleList<ActiveEffect*>		* effectList;			// F8
	BSAnimationGraphManagerPtr		animGraphManager;		// FC
	BSTArray<AnimationVariableData>	* animVariables;		// 100
	void		* unk104;		// 104
	UInt32		unk108;			// 108
	UInt32		unk10C;			// 10C
	UInt32		unk110;			// 110
	UInt32		unk114;			// 114
	UInt32		unk118;			// 118
	UInt32		unk11C;			// 11C
	UInt32		unk120;			// 120
	UInt32		unk124;			// 124
	UInt32		unk128;			// 128 - FFFFFFFF
	UInt32		unk12C;			// 12C
	UInt32		unk130;			// 130
	UInt32		unk134;			// 134 - FF7FFFFF
	RefHandle	furnitureHandle;	// 138
	UInt32		unk13C;			// 13C
	UInt32		unk140;			// 140
	UInt32		unk144;			// 144
	TESIdleForm	* currentIdle;	// 148
	UInt32		unk14C;			 // 14C
	UInt32		unk150;			// 150
	UInt32		unk154;			// 154
	UInt32		unk158;			// 158
	void		* unk15C;		// 15C - hkpCharacterProxy?
	void		* unk160;		// 160
	UInt32		unk164;			// 164
	UInt32		unk168;			// 168
	void		* unk16C;		// 16C - QueueFile
	UInt32		unk170;			// 170
	UInt32		unk174;			// 174
	void		* unk178;		// 178 - perk entries
	UInt32		unk17C;			// 17C
	UInt32		unk180;			// 180
	UInt32		unk184;			// 184
	UInt32		unk188;			// 188
	UInt32		unk18C;			// 18C
	UInt32		unk190;			// 190
	float		unk194;			// 194 - refered by Actor::IMovementState_Unk_05
	UInt32		unk198;			// 198
	UInt32		unk19C;			// 19C
	UInt32		unk1A0;			// 1A0
	UInt32		unk1A4;			// 1A4
	float		unk1A8;			// 1A8 - 1.0f
	UInt32		unk1AC;			// 1AC
	UInt32		unk1B0;			// 1B0
	float		actorAlpha;		// 1B4 - 1.0f
	// More?...
};
STATIC_ASSERT(offsetof(MiddleProcess, currentIdle) == 0x148);
STATIC_ASSERT(offsetof(MiddleProcess, furnitureHandle) == 0x138);
STATIC_ASSERT(offsetof(MiddleProcess, actorAlpha) == 0x1B4);


// A0
class ActorProcessManager
{
	CLASS_SIZE_ASSERT(0xA0)

public:
	enum
	{
		kEquippedHand_Left = 0,
		kEquippedHand_Right = 1
	};

	enum
	{
		kFlags_None = 0,
		kFlags_Unk01 = 1,
		kFlags_Unk02 = 2,
		kFlags_Unk03 = 4,
		kFlags_DrawHead = 8,
		kFlags_Mobile = 16,
		kFlags_Reset = 32
	};

	struct Data08
	{
		UInt32		unk000;
		UInt32		unk004;
		SInt32		unk008;							// 08 - (-1)
		UInt32		unk00C[(0x20 - 0x0C) >> 2];		// 0C
		BGSAIWorldLocationRefRadius	* unk20;		// 20
		UInt32		unk024[(0x34 - 0x24) >> 2];		// 24
		BSTHashMap<UInt32, UInt32>	unk034;			// 34
		void		* unk054;						// 54
		UInt32		unk058[1];						// 58
		SInt32		unk05C;							// 5C
		void		* unk060;						// 60
		Actor		* unk064;						// 64
		UInt32		unk068[(0xB4 - 0x68) >> 2];		// 68
		SInt32		unk0B4[12];						// B4
		SInt32		unk0E4[3];						// E4 - refered by Actor::IMovementState_Unk_10()
		UInt32		unk0F0;							// F0
		float		unk0F4;							// F4 - 1.0f
		UInt32		unk0F8[(0x14C - 0x0F8) >> 2];	// F8
		void		* unk14C;
		void		* unk150;
		void		* unk154;
		void		* unk158;
		UInt32		unk15C;
		PathingCell	* unk160;
		UInt32		unk164;
		NavMesh		* unk168;
		UInt32		unk16C;							// 16C
		UInt32		unk170;							// 170
		UInt32		unk174[(0x198 - 0x16C) >> 2];	// 174
		const char	* subtitleText;					// 198
		void		* unk19C;
		// ...
		//			2E4
	};


	DEFINE_MEMBER_FN_const(GetEquippedRightHand, TESForm *, 0x00494EA0);	// { return equippedObject[kEquippedHand_Right]; }
	DEFINE_MEMBER_FN_const(GetEquippedLeftHand, TESForm *, 0x006572F0);		// { return equippedObject[kEquippedHand_Left]; }
	DEFINE_MEMBER_FN_const(GetSubtitleText,	const char *, 0x006FB910);		// { return (unk08) ? unk08->unk198 : nullptr; }

	DEFINE_MEMBER_FN(SetDataFlag,				void, 0x006FD1A0, UInt32 flag);	// { if (unk08) unk08->unk170 = flag; }
	DEFINE_MEMBER_FN(UpdateEquipment,			void, 0x007031A0, Actor *actor);
	DEFINE_MEMBER_FN(CreateDetectionEvent,		void, 0x00702070, Actor *owner, NiPoint3 *point, UInt32 soundLevel, TESObjectREFR *object);
	DEFINE_MEMBER_FN(UpdateAnimationChannel,	void, 0x007022A0, Actor *owner);
	DEFINE_MEMBER_FN(GetActorKnowledge,			ActorKnowledge *, 0x00709A20, Actor *actor, Actor *target);
	DEFINE_MEMBER_FN(GetAnimationVariables,		BSTArray<AnimationVariableData>*, 0x0071F010);
	DEFINE_MEMBER_FN(SetEquipFlag,				void, 0x0071F520, UInt8 flags);			// { if (middleProcess) middleProcess->unk1F5 = flags; }
	DEFINE_MEMBER_FN(GetAnimationGraphManager,	bool, 0x00721F30, BSAnimationGraphManagerPtr &ptr);
	DEFINE_MEMBER_FN(GetAnimationResponse,		bool, 0x00721E70, BSAnimationResponsePtr &ptr);
	DEFINE_MEMBER_FN(VisitPerkEntries,			void, 0x00724660, UInt8 entryType, PerkEntryVisitor &visitor);

	// @members
	UInt32			unk00;								// 00
	MiddleProcess	* middleProcess;					// 04
	Data08			* unk08;							// 08 - related to ActorKnwoledge, DetectionState, FavorState
	TESPackage		* package;							// 0C
	CustomActorPackageData	* customActorPackageData;	// 10
	UInt32			unk0C[(0x54 - 0x14) >> 2];			// 14
	float			timeOfDeath;						// 54 - GetTimeDead = (GameDaysPassed*24) - timeOfDeath
	UInt32			unk58[(0x68 - 0x58) >> 2];			// 58
	TESForm			* equippedObject[2];				// 68
	TESForm			* unk70;							// 70
	UInt32			unk74[(0x90 - 0x74) >> 2];			// 74
	TESTopic		* topic;							// 90
	UInt32			unk94;								// 94
	UInt8			unk98;								// 98
	UInt8			unk9A;								// 9A
	SInt8			unk9B;								// 9B - 0 if actor detected by anyone
	UInt8			unk9C[(0xA0 - 0x9C)];				// 9C
};
STATIC_ASSERT(offsetof(ActorProcessManager, equippedObject) == 0x68);
STATIC_ASSERT(sizeof(ActorProcessManager) == 0xA0);
