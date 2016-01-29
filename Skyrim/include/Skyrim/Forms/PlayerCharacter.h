#pragma once

#include "Character.h"
#include "../Events/PositionPlayerEvent.h"
#include "../Events/MenuEvent.h"
#include "../FormComponents/TintMask.h"
#include "../Misc/InventoryChanges.h"

class PlayerSkills
{
public:

	enum {
		kAdvanceableSkillOffset = 6,
		kNumAdvanceableSkills = 18
	};

	struct StatData {
		struct LevelData {
			float level;		// 00
			float points;		// 04
			float pointsMax;	// 08
		};

		float		levelPoints;							// 00
		float		levelPointsMax;							// 04
		LevelData	levelData[kNumAdvanceableSkills];		// 08
		UInt32		legendaryLevel[kNumAdvanceableSkills];	// 90
	};

	SInt32	ResolveAdvanceableSkillId(SInt32 actorValue);

	float	GetSkillPoints(const BSFixedString &actorValue);
	void	SetSkillPoints(const BSFixedString &actorValue, float points);
	SInt32	GetSkillLegendaryLevel(const BSFixedString &actorValue);
	void	SetSkillLegendaryLevel(const BSFixedString &actorValue, UInt32 level);

	DEFINE_MEMBER_FN(GetSkillData, UInt32, 0x00760150, UInt32 actorValue, float * level, float * points, float * pointsMax, UInt32 * unk6);
	DEFINE_MEMBER_FN(IncrementLegendary, UInt32, 0x00760110, UInt32 actorValue);

	// @members
	StatData * data;

};


/*==============================================================================
class PlayerCharacter +0000 (_vtbl=010D201C)
0000: class PlayerCharacter
0000: |   class Character
0000: |   |   class Actor
0000: |   |   |   class TESObjectREFR
0000: |   |   |   |   class TESForm
0000: |   |   |   |   |   class BaseFormComponent
0014: |   |   |   |   class BSHandleRefObject
0014: |   |   |   |   |   class NiRefObject
001C: |   |   |   |   class BSTEventSink<struct BSAnimationGraphEvent>
0020: |   |   |   |   class IAnimationGraphManagerHolder
0054: |   |   |   class MagicTarget
0060: |   |   |   class ActorValueOwner
0064: |   |   |   class ActorState
0064: |   |   |   |   struct IMovementState
0064: |   |   |   |   |   struct IMovementInterface
0070: |   |   |   class BSTEventSink<class BSTransformDeltaEvent>
0074: |   |   |   class BSTEventSink<class bhkCharacterMoveFinishEvent>
0078: |   |   |   class IPostAnimationChannelUpdateFunctor
01A8: |   class BSTEventSource<struct BGSActorCellEvent>
01D8: |   class BSTEventSource<struct BGSActorDeathEvent>
0208: |   class BSTEventSource<struct PositionPlayerEvent>
019C: |   class BSTEventSink<class MenuOpenCloseEvent>
01A0: |   class BSTEventSink<class MenuModeChangeEvent>
01A4: |   class BSTEventSink<class UserEventEnabledEvent>
==============================================================================*/
// 72C
class PlayerCharacter : public Character,
	public BSTEventSink<MenuOpenCloseEvent>,	// 19C
	public BSTEventSink<MenuModeChangeEvent>,	// 1A0
	public BSTEventSink<UserEventEnabledEvent>,	// 1A4
	public BSTEventSource<BGSActorCellEvent>,	// 1A8
	public BSTEventSource<BGSActorDeathEvent>,	// 1D8
	public BSTEventSource<PositionPlayerEvent>	// 208
{
public:
	virtual ~PlayerCharacter();

	// @override
	//virtual ????   Unk_00E(????) override;                           // 0073FB40
	//virtual ????   Unk_00F(????) override;                           // 00748D20
	//virtual ????   Unk_010(????) override;                           // 00735130
	//virtual ????   Unk_011(????) override;                           // 0074FA80
	//virtual ????   Unk_012(????) override;                           // 0074BCF0
	//virtual ????   Unk_046(????) override;                           // 0074E630
	//virtual bool   Unk_047(void) override;                           // 0092D110 { return false; }
	//virtual ????   Unk_055(????) override;                           // 0073CF00
	//virtual ????   Unk_05B(????) override;                           // 0073B140
	//virtual ????   Unk_06A(????) override;                           // 007481F0
	//virtual ????   Unk_06C(????) override;                           // 0073A5A0
	//virtual ????   Unk_06F(????) override;                           // 00735080
	//virtual ????   Unk_070(????) override;                           // 00735050
	//virtual ????   Unk_071(????) override;                           // 0074E620
	//virtual ????   Unk_072(????) override;                           // 0073F660
	//virtual ????   Unk_079(????) override;                           // 00733210
	//virtual ????   Unk_07D(????) override;                           // 00734E80
	//virtual ????   Unk_07E(????) override;                           // 007332F0
	//virtual ????   Unk_07F(????) override;                           // 00736F80
	//virtual ????   Unk_080(????) override;                           // 007332C0
	//virtual ????   Unk_082(????) override;                           // 00737B00
	//virtual ????   Unk_086(????) override;                           // 00736A50
	//virtual ????   Unk_08D(????) override;                           // 007350A0
	//virtual ????   Unk_098(????) override;                           // 00747950
	//virtual ????   Unk_09C(????) override;                           // 0073E150
	//virtual ????   Unk_0A0(????) override;                           // 00750CB0
	//virtual ????   Unk_0A2(????) override;                           // 00733490
	//virtual ????   Unk_0A3(????) override;                           // 007333F0
	//virtual ????   Unk_0A5(????) override;                           // 00750B90
	//virtual ????   Unk_0AA(????) override;                           // 0073A700
	//virtual ????   Unk_0AC(????) override;                           // 0074EF80
	//virtual void   Unk_0AE(UInt32 arg) override;                     // 00588F30 { return; }
	//virtual void   Unk_0AF(void) override;                           // 006C50E0 { return; }
	//virtual ????   Unk_0B1(????) override;                           // 00737AC0
	//virtual bool   Unk_0B2(????) override;                           // 0074E5D0 { return (((UInt8)unk724 >> 5) & 1 ) == 0; }
	//virtual ????   Unk_0B3(????) override;                           // 00733AB0
	//virtual ????   Unk_0B4(????) override;                           // 0074B4F0
	//virtual ????   Unk_0B5(????) override;                           // 00733C20
	//virtual ????   Unk_0B6(????) override;                           // 0074B5B0
	//virtual ????   Unk_0B7(????) override;                           // 00744200
	//virtual ????   Unk_0B8(????) override;                           // 00746750
	//virtual ????   Unk_0B9(????) override;                           // 0074B7E0
	//virtual ????   Unk_0BA(????) override;                           // 007443B0
	//virtual ????   Unk_0BB(????) override;                           // 007339A0
	//virtual ????   Unk_0BD(????) override;                           // 00733970
	//virtual ????   Unk_0BF(????) override;                           // 00740F70
	//virtual ????   Unk_0C0(????) override;                           // 00741170
	//virtual ????   Unk_0C1(????) override;                           // 0073D290
	//virtual ????   Unk_0C2(????) override;                           // 00733590
	//virtual UInt32 Unk_0C5(void) override;                           // 005C8DE0 { return 0x00000002; }
	//virtual ????   Unk_0C8(????) override;                           // 007350D0
	//virtual ????   Unk_0CA(????) override;                           // 0073AC50
	//virtual ????   Unk_0CB(????) override;                           // 007437E0
	//virtual ????   Unk_0CC(????) override;                           // 00750510
	//virtual ????   Unk_0CD(????) override;                           // 00750590
	//virtual ????   Unk_0CE(????) override;                           // 0073CAF0
	//virtual ????   Unk_0CF(????) override;                           // 00733B30
	//virtual bool   Unk_0D0(UInt32 arg) override;                     // 004091A0 { return false; }
	//virtual ????   Unk_0D1(????) override;                           // 00750F70
	//virtual UInt32 Unk_0D3(void) override;                           // 0074E600 { return (UInt32)unk62C; }
	//virtual ????   Unk_0D4(????) override;                           // 0074E610
	//virtual ????   Unk_0D5(????) override;                           // 00750670
	//virtual bool   Unk_0D7(UInt32 arg1, UInt32 arg2, UInt32 arg3) override;    // 00933DE0 { return false; }
	//virtual void   Unk_0D9(void) override;                           // 006C50E0 { return; }
	//virtual void   Unk_0DB(UInt32 arg) override;                     // 00588F30 { return; }
	//virtual ????   Unk_0DD(????) override;                           // 007350E0
	//virtual ????   Unk_0DF(????) override;                           // 007331B0
	//virtual ????   Unk_0E2(????) override;                           // 0074E5F0
	//virtual void   Unk_0E3(void) override;                           // 006C50E0 { return; }
	//virtual ????   Unk_0E4(????) override;                           // 0074E5E0
	//virtual ????   Unk_0EE(????) override;                           // 007445C0
	//virtual void   Unk_0EF(void) override;                           // 006C50E0 { return; }
	//virtual ????   Unk_0F4(????) override;                           // 00733460
	//virtual ????   Unk_0F5(????) override;                           // 00733470
	//virtual ????   Unk_0F6(????) override;                           // 00733230
	//virtual ????   Unk_0F8(????) override;                           // 0073D720
	//virtual ????   Unk_0F9(????) override;                           // 007419E0
	//virtual ????   Unk_0FA(????) override;                           // 00741B10
	//virtual ????   Unk_0FB(????) override;                           // 00733DE0
	//virtual ????   Unk_0FC(????) override;                           // 00741D30
	//virtual ????   Unk_0FD(????) override;                           // 00733E00
	//virtual ????   Unk_100(????) override;                           // 00741DB0
	//virtual ????   Unk_101(????) override;                           // 00733EC0
	//virtual ????   Unk_102(????) override;                           // 00733ED0
	//virtual ????   Unk_104(????) override;                           // 007507B0
	//virtual ????   Unk_108(????) override;                           // 00737870
	//virtual ????   Unk_10D(????) override;                           // 007436C0
	//virtual ????   Unk_10E(????) override;                           // 00737B70
	//virtual ????   Unk_10F(????) override;                           // 00738020
	//virtual ????   Unk_111(????) override;                           // 0073C990
	//virtual ????   Unk_112(????) override;                           // 0074E710
	//virtual ????   Unk_113(????) override;                           // 0074E720
	//virtual ????   Unk_116(????) override;                           // 00735DE0
	//virtual ????   Unk_117(????) override;                           // 00733290
	//virtual ????   Unk_118(????) override;                           // 00741830
	//virtual ????   Unk_119(????) override;                           // 00733D30
	//virtual void   Unk_11A(void) override;                           // 006C50E0 { return; }
	//virtual void   Unk_11B(UInt32 arg) override;                     // 00588F30 { return; }
	//virtual ????   Unk_11C(????) override;                           // 00733180
	//virtual ????   Unk_11E(????) override;                           // 00734BD0
	//virtual ????   Unk_121(????) override;                           // 00733EF0
	//virtual bool   Unk_126(UInt32 arg1, UInt32 arg2) override;       // 009EA550 { return false; }
	//virtual ????   Unk_127(????) override;                           // 0073D750
	//virtual bool   Unk_129(void) override;                           // 0074E640 { return Unk_71(); }

	// @add
	virtual void Unk_12A(void);					// 00744270
	virtual void Unk_12B(void);					// 007442C0
	virtual void Unk_12C(void);					// 0074B460
	virtual void Unk_12D(void);					// 0092D110 { return false; }


	TESObjectREFR * GetGrabbedRef() const;

	// Overlayed tints should be the same as original tints
	// occasionally they can have no type so index matching
	// is required to set anything on the tint
	TintMask * GetOverlayTintMask(TintMask * original);

	DEFINE_MEMBER_FN(GetTintList, BSTArray <TintMask *> *, 0x0055FF90);
	DEFINE_MEMBER_FN(GetNumTints, UInt32, 0x00735F40, UInt32 tintType);
	DEFINE_MEMBER_FN(GetTintMask, TintMask *, 0x00735F00, UInt32 tintType, UInt32 index);
	DEFINE_MEMBER_FN(GetDamage, double, 0x00730810, InventoryEntryData * pEntry);
	DEFINE_MEMBER_FN(GetArmorValue, double, 0x007307E0, InventoryEntryData * pEntry);
	DEFINE_MEMBER_FN(SetAngleX, void, 0x006AE540, float angleX);
	DEFINE_MEMBER_FN(SetAngleZ, void, 0x006A8910, float angleZ);
	DEFINE_MEMBER_FN(StartActivation, void, 0x00743530);
	DEFINE_MEMBER_FN(StartGrabbing, void, 0x0074FE50);
	DEFINE_MEMBER_FN(StopGrabbing, void, 0x0074C580);

	DEFINE_MEMBER_FN(TryToPickpocket, bool, Actor *target, UInt32 unk2, UInt32 unk3, bool unk4);

	DEFINE_MEMBER_FN(PlayPickupEvent, void, 0x0073B020, TESForm *item, TESForm *containerOwner, TESObjectREFR *containerRef, UInt32 soundType);

	DEFINE_MEMBER_FN(OnCrosshairRefChanged, void, 0x00739FD0);		// called from 0074F855
	DEFINE_MEMBER_FN(GetActorInFavorState, Actor*, 0x0073D4B0);


	// @members
	UInt32		pad238[(0x490 - 0x238) >> 2];	// 238
	RefHandle	unk490;							// 490 - Handle
	UInt32		pad494[(0x54C - 0x494) >> 2];	// 494
	RefHandle	doingFavorHandle;				// 54C - Handle
	UInt32		pad550[(0x568 - 0x550) >> 2];	// 550
	RefHandle	playerGrabbedHandle;			// 568 - Handle Game.GetPlayerGrabbedRef()
	UInt32		pad56C[(0x58C - 0x56C) >> 2];	// 56C
	NiNode		* firstPersonSkeleton;			// 58C
	UInt32		pad590[(0x5AC - 0x590) >> 2];
	RefHandle	lastRiddenHorseHandle;			// 5AC - Handle
	UInt32		pad5B0[(0x614 - 0x5B0) >> 2];
	PlayerSkills *	skills;						// 614
	RefHandle	targetHandle;					// 618
	UInt32		unk61C;							// 61C
	UInt32		unk620;							// 620
	UInt32		unk624;							// 624
	UInt32		unk628;							// 628
	UInt32		unk62C;							// 62C
	BSTArray<RefHandle>	hostileHandles;			// 630
	UInt32		unk63C;							// 63C
	UInt32		unk640;							// 640
	TESForm		* tempPoison;					// 644
	UInt32		numTeammates;					// 648
	UInt32		pad64C[(0x6B0 - 0x64C) >> 2];	// 64C
	BGSLocation	* currentLocation;				// 6B0
	UInt32		pad6B4[(0x6D4 - 0x6B4) >> 2];	// 6B4
	UInt32		grabbingState;					// 6D4 0:not grabbing 1:grabbing
	UInt32		unk6D8;
	UInt32		unk6DC;
	UInt8		unk6E0;							// 6E0
	UInt8		numPerkPoints;					// 6E1
	UInt16		unk6E2;							// 6E2 - flags - 0x04 "Your hands are bound."
	UInt32		unk6E4;							// 6E4
	BSTArray<TintMask*>	tintMasks;				// 6E8 - These are the actual tints
	BSTArray<TintMask*>	* overlayTintMasks;		// 6F4 - These apply when overlay head parts is enabled
	UInt32	unk6F8[(0x72C - 0x6F8) >> 2];
};
STATIC_ASSERT(sizeof(PlayerCharacter) == 0x72C);
STATIC_ASSERT(offsetof(PlayerCharacter, numPerkPoints) == 0x6E1);
STATIC_ASSERT(offsetof(PlayerCharacter, tintMasks) == 0x6E8);
STATIC_ASSERT(offsetof(PlayerCharacter, overlayTintMasks) == 0x6F4);
STATIC_ASSERT(offsetof(PlayerCharacter, playerGrabbedHandle) == 0x568);
STATIC_ASSERT(offsetof(PlayerCharacter, lastRiddenHorseHandle) == 0x5AC);
STATIC_ASSERT(offsetof(PlayerCharacter, skills) == 0x614);
STATIC_ASSERT(offsetof(PlayerCharacter, tempPoison) == 0x644);
STATIC_ASSERT(offsetof(PlayerCharacter, hostileHandles) == 0x630);

extern PlayerCharacter *& g_thePlayer;