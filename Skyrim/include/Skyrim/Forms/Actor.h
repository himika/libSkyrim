#pragma once

#include "TESObjectREFR.h"
#include "../FormComponents/ActorValueOwner.h"
#include "../FormComponents/MagicTarget.h"
#include "../BSPathFinding/MovementTypes.h"
#include "../BSCore/BSTList.h"
#include "Character/Components/ActorState.h"
#include "Character/Components/ActorMagicCaster.h"
#include "Character/Components/MovementControllerAI.h"

// Declare Classes
NiSmartPointer(Actor);

// External Classes
class ActiveEffect;
class ActorProcessManager;
class PerkEntryVisitor;


/*==============================================================================
class Actor +0000 (_vtbl=010CFCBC)
0000: class Actor
0000: |   class TESObjectREFR
0000: |   |   class TESForm
0000: |   |   |   class BaseFormComponent
0014: |   |   class BSHandleRefObject
0014: |   |   |   class NiRefObject
001C: |   |   class BSTEventSink<struct BSAnimationGraphEvent>
0020: |   |   class IAnimationGraphManagerHolder
0054: |   class MagicTarget
0060: |   class ActorValueOwner
0064: |   class ActorState
0064: |   |   struct IMovementState
0064: |   |   |   struct IMovementInterface
0070: |   class BSTEventSink<class BSTransformDeltaEvent>
0074: |   class BSTEventSink<class bhkCharacterMoveFinishEvent>
0078: |   class IPostAnimationChannelUpdateFunctor
==============================================================================*/
// 19C
class Actor : public TESObjectREFR,
	public MagicTarget,									// 054
	public ActorValueOwner,								// 060
	public ActorState,									// 064
	public BSTEventSink<BSTransformDeltaEvent>,			// 070
	public BSTEventSink<bhkCharacterMoveFinishEvent>,	// 074
	public IPostAnimationChannelUpdateFunctor			// 078
{
public:
	enum { kTypeID = (UInt32)FormType::Character };

	using MagicTarget::HasEffectKeyword;

	/*==============================================================================
	class Actor::ForEachSpellVisitor +0000 (_vtbl=010D0920)
	0000: class Actor::ForEachSpellVisitor
	==============================================================================*/
	class ForEachSpellVisitor
	{
	public:
		virtual ~ForEachSpellVisitor();			// 006E8D60
		virtual bool Visit(SpellItem*) = 0;
	};

	virtual ~Actor();

	// @override TESObjectREFR
	// Unk_0E		006DB980	
	// Unk_0F		006DBE00	
	// Unk_10		006CB4F0	
	// Unk_11		006D81C0	
	// Unk_12		006D8C20	
	// InitItem		006CB7D0	
	// SetFlag00000020	006B8BC0	
	// Unk_3B		006BAC90	
	// GetEditorLocation	006C50D0	(void) { return editorLocation; }
	// Unk_3D		006A7250	
	// Unk_3E		006AA2D0	
	// Unk_3F		006A9A10	
	// Unk_40		006C1740	
	// Unk_41		006C0D90	
	// Unk_45		006A9F00	
	// Unk_48		006A9550	
	// Unk_49		006A9E60	
	// Unk_4A		006A9FE0	
	// Unk_4B		006B3C60	
	// Unk_4C		006D3720	
	// Unk_4D		006C5170 (void) { this->unk14C; }
	// Unk_4E		006C5180	
	// Unk_4F		006C1350	
	// Unk_52		006A8B80	
	// Unk_53		006A8BA0	
	// Unk_56		006B9480	
	// Unk_58		006A80A0	
	// Unk_59		006C95F0	
	// Unk_5A		006BCEC0	
	// Unk_5B		006AC540	
	// Unk_5C		006E8E70	
	// Unk_5D		006E8870 { return static_cast<MagicTarget*>(this); }
	// Unk_63		006BEBB0	
	// Unk_65		006A97D0	
	// Unk_66		006CC9B0	
	// Unk_67		006C3F20	
	// Unk_68		006C4110	
	// Unk_69		006BA6A0	
	// Unk_6A		006C54B0	
	// Unk_6C		006C20D0	
	// Unk_72		006C7340	
	// Unk_73		006A9590	
	// Unk_74		006A9630	
	// Unk_75		006E0D50	
	// Unk_78		006A7F40	
	// Unk_79		006C74A0	
	// Unk_7A		0092D110	(){ return false; }
	// Unk_7B		006ABD00	
	// Unk_7C		006ABD30	
	// Unk_7D		006BCB50	
	// Unk_82		006A98F0	
	// Unk_84		006AACA0	
	// Unk_85		006B8C30	
	// Unk_86		006A98B0	
	// Unk_87		006A7330	
	// Unk_89		006AA660	
	// Unk_8A		006BDF60	
	// Unk_8B		006AE000	
	// Unk_8C		006A9380	
	// Unk_90		006AFC10	
	// Unk_91		006B55F0	
	// Unk_92		006B5400	
	// Unk_93		006B5430	
	// Unk_95		006BB5C0	
	// Unk_96		006B10C0	
	// Unk_98		006B3470	
	// Unk_99		006A7430	
	// Unk_9C		006C3710	
	// Unk_9D		006AF990	
	// Unk_9E		006E16C0	
	// Unk_A1		006D5020	
	
	// @override ActorState (vtbl=0x010CFB9C)
	virtual FormID	IMovementState_Unk_01(void) override;			// 006A7CE0 { return formID; }
	virtual void	IMovementState_Unk_02(UInt32 arg) override;		// 006B5B90 { Pathing::GetSingleton()->Unk_00609A40((Actor*)this); .... }
	virtual void	IMovementState_Unk_03(NiPoint3 &pos) override;	// 006A7CF0 { pos = this->pos; }
	virtual void	IMovementState_Unk_04(NiPoint3 &pos) override;	// 006A7D10
	virtual float	IMovementState_Unk_05(void) override;			// 006A7D40 { return this->processManager->Unk_0071F140(); }
	virtual float	IMovementState_Unk_06(void) override;			// 006A7C60 { return this->processManager->Unk_0071F2C0(); }
	virtual void	IMovementState_Unk_07(NiPoint3 &pos) override;	// 006A7D70 { pos = NiPoint3{0f,0f,0f}; }
	virtual bool	IMovementState_Unk_08(UInt32 arg) override;		// 006CE640
	virtual float	IMovementState_Unk_09(void) override;			// 006B1730
	virtual float	IMovementState_Unk_0A(void) override;			// 006B1760
	virtual float	IMovementState_Unk_0B(void) override;			// 006B1790
	virtual float	IMovementState_Unk_0C(void) override;			// 006ABBC0 { return Actor::Unk_006AB410(); }
	virtual float	IMovementState_Unk_0D(void) override;			// 006ABBD0 { return Acotr::Unk_006AB410() * 0.75; }
	virtual bool	IMovementState_Unk_0E(void) override;			// 006B17C0
	virtual MovementParameters *	IMovementState_Unk_0F(void) override;	// 006A7DF0 { return (MovementParameters*)0x01275B88; }
	virtual bool	IMovementState_Unk_10(UInt32 arg) override;		// 006A7DA0
	virtual UInt32	IMovementState_Unk_11(void) override;			// 006ABB80
	virtual bool	IMovementState_Unk_12(void) override;			// 006ABBB0 { Actor::Unk_006A6F20(g_thePlayer)}
	virtual bool	IMovementState_Unk_13(void) override;			// 006A7DD0 { return (byte)rece->data.unk7C & 1; }
	virtual bool	ActorState_Unk_14(UInt32 arg);					// 006C50B0
	virtual bool	ActorState_Unk_15(UInt32 arg);					// 006EBA30

	// @override class IAnimationGraphManagerHolder : (vtbl=010CFC54)
	virtual bool	SendAnimationEvent(const BSFixedString &eventName) override;						// 006A7E30 { return IAnimationGraphManagerHolder::SendAnimationEvent(eventName) override; }
	virtual bool	GetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager> &out) override;	// 006A7E10
	virtual bool	IAnimationGraphManagerHolder_Unk_03(UInt32 arg) = 0;								// 006B18F0
	virtual bool	IAnimationGraphManagerHolder_Unk_05(UInt32 arg) = 0;								// 006B1860 { BSTSmartPointer<Unk_0112509C> &arg = new Unk_0112509C((Actor*)this, ???); }
	virtual bool	IAnimationGraphManagerHolder_Unk_06(void) override;									// 0092D110 { return false; }
	virtual bool	IAnimationGraphManagerHolder_Unk_07(UInt32 arg) override;							// 006BBF30
	virtual bool	IAnimationGraphManagerHolder_Unk_08(UInt32 arg) override;							// 006C73C0 - register event sinks BSTransformDeltaEvent, BSAnimationGraphEvent
	virtual bool	IAnimationGraphManagerHolder_Unk_0A(UInt32 arg) override;							// 006BC2B0
	virtual void	IAnimationGraphManagerHolder_Unk_0B(UInt32 arg) override;							// 006DA560
	virtual void	IAnimationGraphManagerHolder_Unk_0C(void) override;									// 006BC830
	virtual void	IAnimationGraphManagerHolder_Unk_0D(UInt32 arg1, UInt32 arg2) override;				// 006CE6C0
	virtual bool	IAnimationGraphManagerHolder_Unk_0E(void) override;									// 006A7E00
	virtual UInt32	IAnimationGraphManagerHolder_Unk_0F(void) override;									// 006A7E40 { return [01275B50]; }
	virtual bool	GetAnimationVariableFloat(const BSFixedString& variableName, float& out) override;	// 006A7ED0
	virtual bool	GetAnimationVariableInt(const BSFixedString& variableName, SInt32& out) override;	// 006A7E90
	virtual bool	GetAnimationVariableBool(const BSFixedString& variableName, bool& out) override;	// 006A7E50

	// @override MagicTarget (vtbl=0x010CFC20)
	virtual bool	MagicTarget_Unk_01(float arg) override;						// 006ED250
	virtual Actor *	MagicTarget_Unk_02(void) override;							// 006C5160 { return static_cast<Actor*>(this); }
	virtual bool	MagicTarget_Unk_03(void) override;							// 009B86F0 { return true; }
	virtual bool	MagicTarget_Unk_04(void) override;							// 006A9270
	virtual void	MagicTarget_Unk_05(int) override;							// 006E89F0 { if (processManager) processManager->Unk_00724530(arg); }
	virtual bool	MagicTarget_Unk_06(void) override;							// 006E8880
	virtual BSSimpleList<ActiveEffect*> *	GetActiveEffects(void) override;	// 006E9180 { return processManager ? processManager->Unk_0071F120() : nullptr; }
	virtual void	MagicTarget_Unk_08(int) override;							// 006E9300
	virtual void	MagicTarget_Unk_09(int)override;							// 006E88B0
	virtual double	MagicTarget_Unk_0A(int, int, int) override;					// 006E93D0
	virtual bool	MagicTarget_Unk_0B(int, int, int) override;					// 006EC4F0

	// @override BSTEventSink<BSTransformDeltaEvent> (vtbl=010CFB90)
	virtual	EventResult	ReceiveEvent(BSTransformDeltaEvent * evn, BSTEventSource<BSTransformDeltaEvent> * source) override;	// 006B5DB0

	// @override BSTEventSink<class bhkCharacterMoveFinishEvent> (vtbl=010CFB84)
	virtual	EventResult	ReceiveEvent(bhkCharacterMoveFinishEvent * evn, BSTEventSource<bhkCharacterMoveFinishEvent> * source) override;	// 006B9CA0

	// @override class IPostAnimationChannelUpdateFunctor : (vtbl=010CFB78)
	virtual void IPostAnimationChannelUpdateFunctor_Unk_01(void) override;			// 006A7FB0 { if (processManager) { processManager->UpdateAnimationChannel((Actor*)this); }

	// @add
	virtual void	Unk_A2(TESForm *arg1, bool arg2, bool arg3);	// 006B2590 called when inventory changed? - called from 006D2824,006D298D,006D67B9,006D6A99
	virtual float	Unk_A3(UInt32 arg);								// 006A92B0
	virtual void	Unk_A4(UInt32 arg);								// 00588F30 { return; } - called from 0074E217,0074E238,0074864B
	virtual void	DrawSheatheWeapon(bool draw);					// 006B2050
	virtual void	Unk_A6(void);									// 006B8BF0 - called when delete? - called from 006A97EF
	virtual void	Unk_A7(void);									// 006CC930
	virtual void	Unk_A8(void);									// 006AE470 - 00693025,00742C1C
	virtual void	Unk_A9(void);									// 006AC410
	virtual void	Unk_AA(void);									// 006DB0A0
	virtual void	Unk_AB(void);									// 006E7B70
	virtual void	Unk_AC(void);									// 006C7690 - from 0069495C
	virtual void	Unk_AD(void);									// 006A8030
	virtual void	Unk_AE(UInt32 arg);								// 006A79F0 PlayerCharacter={ return; } from 006D648C
	virtual void	Unk_AF(void);									// 006D64D0 PlayerCharacter={ return; } from 006D6498
	virtual void	Unk_B0(void);									// 006B5AF0
	virtual void	Unk_B1(bool arg);								// 006CD7C0 - draw weapon when arg is true. called multiple times when actor dies. - 006EE2E5,0072D618
	virtual bool	Unk_B2(void);									// 009B86F0 { return true; } called when die
	virtual void	Unk_B3(void);									// 006BCAF0
	virtual void	Unk_B4(void);									// 006AECA0
	virtual void	Unk_B5(void);									// 006AECC0
	virtual void	AddCrimeGold(UInt32 mount, bool bViolent, TESFaction *faction);	// 006AECF0
	virtual void	Unk_B7(void);									// 006AED10
	virtual void	Unk_B8(UInt32 arg1, UInt32 arg2, UInt32 arg3);	// 00D62BE0 { return; }
	virtual void	Unk_B9(void);									// 006C50E0 { return; }
	virtual void	Unk_BA(UInt32 arg1, UInt32 arg2, UInt32 arg3);	// 00D62BE0 { return; }
	virtual bool	Unk_BB(void);									// 0092D110 { return false; }
	virtual void	Unk_BC(UInt32 arg);								// 00588F30 { return; }
	virtual bool	Unk_BD(void);									// 0092D110 { return false; } - called 2 times when activate
	virtual void	Unk_BE(UInt32 arg);								// 00588F30 { return; }
	virtual void	Unk_BF(UInt32 arg1, UInt32 arg2);				// 004D43E0 { return; }
	virtual void	Unk_C0(UInt32 arg);								// 00588F30 { return; }
	virtual void	Unk_C1(void);									// 006BEC40 - called when weapon swing, item drop
	virtual void	Unk_C2(void);									// 006E9780
	virtual void	Unk_C3(UInt32 arg);								// 00588F30 { return; }
	virtual bool	Unk_C4(void);									// 009B86F0 { return true; }
	virtual UInt32	Unk_C5(void) = 0;								// 00F51EE8 pure, PlayerCharacter={ return 2; }
	virtual void	Unk_C6(void);									// 0064A3E0
	virtual void	Unk_C7(void);									// 006CF440 - called every frame?
	virtual void	Unk_C8(void);									// 006E8630
	virtual void	Unk_C9(void);									// 006C50E0 { return; }
	virtual void	DropItem(RefHandle *droppedItemHandle, TESForm *akItem, BaseExtraList *extraList, UInt32 count, UInt32 arg5, UInt32 arg6);		// 006BD1A0
	virtual void	PickUpItem(TESObjectREFR *item, UInt32 count, bool arg3, bool playSound);		// 006CE8B0  - called from 0084AA68
	virtual void	Unk_CC(UInt32 arg1);							// 006E3020 - "Arrow%d"
	virtual void	Unk_CD(UInt32 arg1);							// 006E31A0 - "Arrow%d"
	virtual void	Unk_CE(void);									// 006E9140
	virtual void	Unk_CF(UInt32 arg);								// 00588F30 { return; }
	virtual bool	Unk_D0(void);									// 006E0DA0 PlayerCharacter={ return false; }
	virtual void	Unk_D1(void);									// 006E2450
	virtual bool	Unk_D2(void);									// 006E3580 PlayerCharacter={ return false; }
	virtual void	* Unk_D3(void);									// 006E1620 { unk0D8 ? *unk0D8 : nullptr } PlayerCharacter={ return unk62C; }
	virtual void	Unk_D4(void * arg);								// 006E1630 { unk0D8 > *unk0D8 = arg; }
	virtual void	Unk_D5(void);									// 006E1650
	virtual void	Unk_D6(UInt32 arg);								// 004091A0 { return false; }
	virtual bool	Unk_D7(UInt32 arg1, UInt32 arg2, UInt32 arg3);	// 006BEE70 PlayerCharacter={ return false; }
	virtual void	Unk_D8(void);									// 006C1E90
	virtual void	Unk_D9(void);									// 006B7C50 PlayerCharacter={ return; }
	virtual void	Unk_DA(void);									// 006BEE10
	virtual void	Unk_DB(UInt32 arg);								// 00588F30 PlayerCharacter={ return; }
	virtual void	Unk_DC(void);									// 006BDC80
	virtual void	Unk_DD(void);									// 006CB280
	virtual void	Unk_DE(void);									// 006BAEE0
	virtual void	Unk_DF(void);									// 006E9EC0
	virtual void	Unk_E0(void);									// 006E9190
	virtual void	Unk_E1(void);									// 006E8770
	virtual bool	IsInCombat(void);								// 006E1340
	virtual void	Unk_E3(void);									// 006E2BF0 PlayerCharacter={ return; } 
	virtual void	Unk_E4(void);									// 006E5510
	virtual float	Unk_E5(void);									// 0066E8A0 { return 0.0f; }
	virtual float	Unk_E6(void);									// 0066E8A0 { return 0.0f; }
	virtual void	Unk_E7(void);									// 005EADD0 { return 0; }
	virtual void	Unk_E8(void);									// 0092D110 { return false; }
	virtual void	Unk_E9(UInt32 arg);								// 004091A0 { return false; }
	virtual void	Unk_EA(void);									// 006C5FA0
	virtual void	Unk_EB(void);									// 006AB7D0
	virtual void	Unk_EC(void);									// 006AB850
	virtual void	Unk_ED(void);									// 006C5F90
	virtual void	OnWeaponSwing(void);							// 006E3D50
	virtual void	Unk_EF(void);									// 006A8BD0 PlayerCharacter={ return; }
	virtual void	Unk_F0(void);									// 006DC790
	virtual void	Unk_F1(void);									// 006DCEA0
	virtual void	Unk_F2(void);									// 006DD4B0
	virtual void	Unk_F3(void);									// 006DD940
	virtual void	Unk_F4(void);									// 006E1290
	virtual void	Unk_F5(void);									// 006E12A0
	virtual void	AdvanceSkill(UInt32 skillId, float points, UInt32 unk1, UInt32 unk2);	// 00DE8190 { return; }
	virtual void	Unk_F7(void);									// 006ACBD0
	virtual bool	IsInFaction(TESFaction* faction);				// 006A9120
	virtual void	VisitPerks(PerkEntryVisitor &visitor);			// 006AA200 { return baseForm->BGSPerkRankArray::VisitPerkEntry(visitor); } - BGSPerk::FindPerkInRanksVisitor
	virtual void	AddPerk(BGSPerk * perk, UInt32 unk1);			// 004D43E0 { return; }
	virtual void	RemovePerk(BGSPerk * perk);						// 00588F30 { return; }
	virtual void	Unk_FC(UInt32 arg);								// 00588F30 { return; }
	virtual void	Unk_FD(UInt32 arg);								// 00588F30 { return; }
	virtual bool	CanProcessEntryPointPerkEntry(UInt32 entryType);	// 006AA210 
	virtual void	VisitEntryPointPerkEntries(UInt32 entryType, PerkEntryVisitor &visitor);	// 006AA240 { if (processManager) processManager->Unk00724660(arg1, visitor); }
	virtual void	Unk_100(void);									// 006AA260
	virtual void	Unk_101(void);									// 006C50E0 { return; }
	virtual bool	Unk_102(void);									// 0092D110 { return false; }
	virtual void	Unk_103(void);									// 006E4700
	virtual void	Unk_104(void);									// 006E1130
	virtual bool	Unk_105(void);									// 0092D110 { return false; }
	virtual void	Unk_106(void);									// 006C50F0
	virtual void	Unk_107(void);									// 006C5100
	virtual void	Unk_108(void);									// 006B2630
	virtual void	Unk_109(void);									// 006C5120 { return this->unk0E4; }
	virtual void	Unk_10A(UInt32 arg);							// 006C5130 { this->unk0E4 = arg; }
	virtual void	Unk_10B(void);									// 006C5140 { return this->unk0E8; }
	virtual void	Unk_10C(UInt32 arg);							// 006C5150 { this->unk0E8 = arg; }
	virtual void	Unk_10D(void);									// 006D6B30
	virtual void	Unk_10E(void);									// 006EA980
	virtual void	Unk_10F(void);									// 006E8F90
	virtual void	Unk_110(void);									// 006C50E0 { return; }
	virtual void	Unk_111(void);									// 006E8B30
	virtual void	Unk_112(UInt32 arg);							// 00588F30 { return; }
	virtual void	GetLastRiddenHorse(RefHandle &out) const;		// 006C51F0 { out = g_invalidRefHandle; }
	virtual void	Unk_114(void);									// 006B1340
	virtual void	Unk_115(void);									// 006B1290
	virtual void	Unk_116(UInt32 arg);							// 00588F30 { return; }
	virtual void	Unk_117(void);									// 006AA2E0
	virtual void	Unk_118(void);									// 006BBF00
	virtual void	Unk_119(void);									// 006AB8D0
	virtual void	Unk_11A(void);									// 006A79D0 PlayerCharacter={ return; }
	virtual void	Unk_11B(UInt32 arg);							// 006AB920 PlayerCharacter={ return; }
	virtual void	Unk_11C(void);									// 006A7A20
	virtual void	Unk_11D(void);									// 006A7A50
	virtual void	Unk_11E(void);									// 006ABD60
	virtual void	Unk_11F(void);									// 006CC840
	virtual void	Unk_120(void);									// 006B6060
	virtual void	Unk_121(void);									// 006B4C00
	virtual void	Unk_122(void);									// 006CECB0
	virtual void	Unk_123(void);									// 006B6EA0
	virtual void	Unk_124(void);									// 006A8EF0
	virtual void	Unk_125(void);									// 006A8F40
	virtual bool	Unk_126(UInt32 arg1, UInt32 arg2);				// 006B9BF0 PlayerCharacter={ return false; }
	virtual void	Unk_127(void);									// 006DFB30

	TESForm * GetEquippedObject(bool abLeftHand);
	void UpdateSkinColor();
	void UpdateHairColor();
	bool HasLOS(TESObjectREFR* target);

	///<summary>Gets the ActorBase of the actor.</summary>
	TESNPC *	GetActorBase(void) const
	{
		return (TESNPC*)baseForm;
	}

	TESRace *	GetRace() const;

	///<summary>Checks to see if this actor has the given Spell or tesut.</summary>
	bool HasSpell(TESForm * spell) const;

	///<summary>Checks to see if this actor has the given Spell.</summary>
	bool HasSpell(SpellItem * spell) const { return HasSpell_Impl(spell); }

	///<summary>Checks to see if this actor has the given Shout.</summary>
	DEFINE_MEMBER_FN_const(HasShout, bool, 0x006EAF10, TESShout* shout);

	///<summary>Forces the actor to dismount.</summary>
	DEFINE_MEMBER_FN(Dismount, void, 0x006C2EA0);
	
	///<summary>Enables or disables this actor's AI.</summary>
	DEFINE_MEMBER_FN(EnableAI, void, 0x006AA690, bool bEnable);

	///<summary>Obtains this actor's current combat state.</summary>
	DEFINE_MEMBER_FN_const(GetCombatState, void, 0x006E10F0);

	///<summary>Checks to see if this actor has the given Perk.</summary>
	DEFINE_MEMBER_FN_const(HasPerk, bool, 0x006AA190, BGSPerk * perk);

	///<summary>Is this actor being ridden?</summary>
	bool IsBeingRidden() const;		// 008DCAF0

	///<summary>Is this actor commanded by another?</summary>
	bool IsCommandedActor() const	// 008DCB20
	{
		return flags2.commandedActor;
	}

	///<summary>Is this actor currently detected by the other one?</summary>
	bool IsDetectedBy(Actor *actor)		// 008DB830
	{
		return (actor->GetDetectionLevel(this, 3) > 0);
	}

	///<summary>Is this actor essential?</summary>
	bool IsEssensial() const		// 008DCB30
	{
		return flags2.essential;
	}

	///<summary>Obtains whether this actor is a guard or not.</summary>
	bool IsGuard() const			// 008DC020
	{
		return flags2.essential;
	}

	///<summary>Is this actor flagged as a ghost?</summary>
	DEFINE_MEMBER_FN_const(IsGhost, bool, 0x006A8CA0);

	///<summary>Check if this actor is hostile to another actor.</summary>
	DEFINE_MEMBER_FN_const(IsHostileToActor, bool, 0x006D4360, Actor *actor);

	///<summary>Returns whether this actor is in a kill move or not.</summary>
	bool IsInKillMove() const		// 006E16F0
	{
		return flags2.killMove;
	}

	///<summary>Gets this actor's current level.</summary>
	DEFINE_MEMBER_FN_const(GetLevel, UInt16, 0x006A7320);

	///<summary>Returns this actor's current light level.</summary>
	DEFINE_MEMBER_FN_const(GetLightLevel, UInt32, 0x006AE980);

	///<summary>Obtains this actor's faction-based reaction to the other actor.</summary>
	DEFINE_MEMBER_FN_const(GetFactionReaction, UInt32, 0x006D0550, Actor* akOther);

	///<summary>Gets the amount of gold this actor has on his person.</summary>
	DEFINE_MEMBER_FN_const(GetGoldAmount, UInt32, 0x006A8190);

	DEFINE_MEMBER_FN(GetDetectionLevel, SInt32, 0x006AE830, Actor *target, UInt32 flag);	// return -1000 if not detected
	
	///<summary>Checks to see if this actor is currently being affected by a Magic Effect with the given Keyword.</summary>
	bool HasMagicEffectWithKeyword(const BGSKeyword *keyword) const		// 008DA550
	{
		return MagicTarget::HasEffectKeyword(keyword);
	}

	///<summary>Returns whether the actors AI is enabled.</summary>
	bool IsAIEnabled() const		// SKSE
	{
		return flags1.AIEnabled;
	}

	///<summary>Gets if this actor has been intimidated by the player.</summary>
	DEFINE_MEMBER_FN_const(IsIntimidated, bool, 0x006AA3E0);

	///<summary>Is the actor on a mount?</summary>
	bool IsOnMount() const;		// 008DCB40

	///<summary>Returns whether this actor is the horse the player last rode.</summary>
	bool IsPlayersLastRiddenHorse();	// 008DB880

	///<summary>Checks to see if this actor is currently a teammate of the player.</summary>
	bool IsPlayerTeammate() const			// 008DC030
	{
		return flags1.playerTeammate;
	}

	///<summary>Returns whether this actor is current running.</summary>
	DEFINE_MEMBER_FN_const(IsRunning, bool, 0x006AB210);

	///<summary>Is this actor currently sneaking?</summary>
	bool IsSneaking() const;			// 004D9290

	///<summary>Returns whether this actor is currently trespassing or not.</summary>
	bool IsTrespassing() const			// 008DCB74
	{
		return flags2.trespassing;
	}

	DEFINE_MEMBER_FN(VisitSpells, void, 0x006EA380, ForEachSpellVisitor * visitor);
	DEFINE_MEMBER_FN(QueueNiNodeUpdate, void, 0x00730EE0, bool updateWeight);
	DEFINE_MEMBER_FN(SetRace, void, 0x006AF590, TESRace*, bool isPlayer);
	DEFINE_MEMBER_FN(UpdateWeaponAbility, void, 0x006ED980, TESForm*, BaseExtraList * extraData, bool bLeftHand);
	DEFINE_MEMBER_FN(UpdateArmorAbility, void, 0x006E8650, TESForm*, BaseExtraList * extraData);
	DEFINE_MEMBER_FN(SendStealAlerm, void, 0x006CC0D0, TESObjectREFR *refItemOrContainer, TESForm *stolenItem, UInt32 numItems, UInt32 unk1, TESForm *owner, bool unk2);

	struct Flags1
	{
		bool			unk00 : 1;			// 00 0x00000001
		bool			AIEnabled : 1;		// 01 0x00000002
		unsigned char	unk02 : 6;			// 02 0x000000FC
		unsigned char	unk08 : 8;			// 08 0x0000FF00
		unsigned char	unk10 : 8;			// 10 0x00FF0000
		unsigned char	unk18 : 2;			// 18 0x03000000
		bool			playerTeammate : 1;	// 1A 0x04000000
		unsigned char	unk1B : 3;			// 1B 0x38000000
		bool			guard : 1;			// 1E 0x40000000
	};

	struct Flags2
	{
		bool			unk00 : 1;					// 00 0x00000001
		bool			hasInteraction : 1;			// 01 0x00000002
		unsigned char	unk02 : 5;					// 02 0x0000007C
		bool			canDoFavor : 1;				// 07 0x00000080
		unsigned char	unk08 : 4;					// 08 0x00000F00
		bool			trespassing : 1;			// 0C 0x00001000
		bool			unk0C : 1;					// 0D 0x00002000
		bool			killMove : 1;				// 0E 0x00004000
		bool			attackedByAllActors : 1;	// 0F 0x00008000 - see Actor.SetAttackActorOnSight
		bool			commandedActor : 1;			// 10 0x00010000 - see Actor.IsCommandedActor
		bool			unk11 : 1;					// 11 0x00020000
		bool			essential : 1;				// 12 0x00040000
	};

	enum SlotType
	{
		kSlot_LeftHand = 0,
		kSlot_RightHand,
		kSlot_Unknown,
		kSlot_PowerOrShout,

		kNumSlots
	};


	// @members
	Flags1						flags1;								// 07C
	UInt32						unk080;								// 080
	UInt32						unk084;								// 084
	ActorProcessManager			* processManager;					// 088
	UInt32						unk08C;								// 08C | 
	RefHandle					combatTargetRefHandle;				// 090 | (himika)
	UInt32						unk094[(0x0C8 - 0x094) >> 2];		// 094 | 
	BGSLocation					* editorLocation;					// 0C8 |
	UInt32						pad0CC;								// 0CC |
	MovementControllerAI		* movementControllerAI;				// 0D0 |
	UInt32						pad0D4[(0x0FC - 0x0D4) >> 2];		// 0D4 |
	BSTSmallArray<SpellItem *>	addedSpells;						// 0FC
	MagicCaster					* magicCaster[kNumSlots];			// 108 [0] lefthand [1] right hand [2] unknown [3] power/shout
	MagicItem					* equippingMagicItems[kNumSlots];	// 118
	TESForm						* equippedShout;					// 128
	UInt32						unk12C;								// 12C
	TESRace						* race;								// 130
	UInt32						unk134;								// 134
	Flags2						flags2;								// 138
	UInt32						unk13C[(0x19C - 0x13C) >> 2];		// 13C

private:
	DEFINE_MEMBER_FN_const(HasSpell_Impl, bool, 0x006E9130, SpellItem* spell);
};
STATIC_ASSERT(offsetof(Actor, addedSpells) == 0xFC);
STATIC_ASSERT(sizeof(Actor) == 0x19C);
