#pragma once

#include "TESObjectREFR.h"
#include "../../FormComponents/ActorValueOwner.h"
#include "../../FormComponents/MagicTarget.h"
#include "../../BSPathFinding/MovementTypes.h"
#include "../../BSCore/BSTList.h"
#include "Components/ActorProcessmanager.h"
#include "Components/ActorState.h"
#include "Components/ActorMagicCaster.h"
#include "Components/MovementControllerAI.h"

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


	virtual ~Actor();																	// 00 006CE610

	// @override class TESObjectREFR : (vtbl=010CFCBC)
	virtual void			SaveBuffer(BGSSaveFormBuffer *buf) override;				// 0E 006DB980 - called from 006794DC (BGSSaveLoadGame::SaveGame)
	virtual void			LoadBuffer(BGSLoadFormBuffer *buf) override;				// 0F 006DBE00 - called from 0067BE80 (BGSSaveLoadGame::LoadGame)
	virtual void			Unk_10(BGSLoadFormBuffer *buf) override;					// 10 006CB4F0 { return; } called after LoadBuffer
	virtual void			Unk_11(BGSLoadFormBuffer *buf) override;					// 11 006D81C0 { return; } called after Unk_10
	virtual void			Unk_12(BGSLoadFormBuffer *buf) override;					// 12 006D8C20 { return; } revert form? called before LoadBuffer
	virtual void			InitItem(void) override;									// 13 006CB7D0 { return; } called once all dependent forms are loaded
	virtual void			SetFlag00000020(bool set) override;							// 23 006B8BC0
	virtual void			Unk_3B(void) override;										// 006BAC90
	virtual BGSLocation	*	GetEditorLocation(void) override;							// 006C50D0	{ return editorLocation; }
	virtual bool			Unk_3D(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4) override;		// 006A7250
	virtual void			Unk_3E(UInt32 arg) override;								// 006AA2D0
	virtual void			Unk_3F(void) override;										// 006A9A10
	virtual void			Unk_40(void) override;										// 006C1740
	virtual bool			Unk_41(void) override;										// 006C0D90
	virtual UInt32			Unk_45(void) override;										// 006A9F00
	virtual bool			HasKeyword(BGSKeyword* keyword) const;						// 006A9550
	virtual TESPackage *	Unk_49(void) override;										// 006A9E60
	virtual BGSScene *		GetCurrentScene(void) const;								// 006A9FE0
	virtual void			SetCurrentScene(BGSScene *) override;						// 006B3C60
	virtual void			Unk_4C(void) override;										// 006D3720
	virtual UInt32			Unk_4D(void) override;										// 006C5170 { this->unk14C; }
	virtual void			Unk_4E(UInt32 arg) override;								// 006C5180
	virtual void			Unk_4F(void) override;										// 006C1350
	virtual UInt32			Unk_52(UInt32 arg) override;								// 006A8B80
	virtual UInt32			Unk_53(UInt32 arg) override;								// 006A8BA0
	virtual void			RemoveItem(RefHandle *droppedItemHandle, TESForm *akItem, UInt32 aiCount, UInt32 mode, BaseExtraList *extraList, TESObjectREFR *moveToRef, UInt32 unk7, UInt32 unk8) override;	// 006B9480
	virtual void			Unk_58(UInt32 arg) override;								// 006A80A0
	virtual void			Unk_59(UInt32 arg1, UInt32 arg2) override;					// 006C95F0
	virtual void			Unk_5A(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4) override;	// 006BCEC0
	virtual void			GetMarkerPosition(NiPoint3 *pos) override;					// 006AC540
	virtual MagicCaster	*	GetMagicCaster(UInt32 slot) const;							// 006E8E70
	virtual MagicTarget *	GetMagicTarget(void) const;									// 006E8870 { return static_cast<MagicTarget*>(this) override; }
	virtual BSFaceGenAnimationData *	GetFaceGenAnimationData(void) override;			// 006BEBB0
	virtual void			Unk_65(void) override;										// 006A97D0
	virtual void			Unk_66(void) override;										// 006CC9B0
	virtual void			Unk_67(void) override;										// 006C3F20
	virtual void			Unk_68(void) override;										// 006C4110
	virtual void			Unk_69(void) override;										// 006BA6A0
	virtual void			Unk_6A(void) override;										// 006C54B0
	virtual void			Unk_6C(UInt32 unk1, UInt32 unk2) override;					// 006C20D0
	virtual void			Unk_72(void) override;										// 006C7340
	virtual NiPoint3 *		GetBoundLeftFrontBottom(NiPoint3 *) const;					// 006A9590
	virtual NiPoint3 *		GetBoundRightBackTop(NiPoint3 *) const;						// 006A9630
	virtual UInt32			Unk_75(void) override;										// 006E0D50
	virtual void			Unk_78(void) override;										// 006A7F40
	virtual void			Unk_79(UInt32 arg) override;								// 006C74A0
	virtual bool			Unk_7A(void) override;										// 0092D110	{ return false; }
	virtual void			Unk_7B(void) override;										// 006ABD00
	virtual bool			Unk_7C(void) override;										// 006ABD30
	virtual void			Unk_7D(void) override;										// 006BCB50
	virtual void			Unk_82(UInt32 arg) override;								// 006A98F0
	virtual void			Unk_84(UInt32 arg) override;								// 006AACA0
	virtual void			Unk_85(void) override;										// 006B8C30
	virtual void			Unk_86(void) override;										// 006A98B0
	virtual void			Unk_87(UInt32 arg) override;								// 006A7330
	virtual void			ResetInventory(bool unk) override;							// 006AA660
	virtual void			Unk_8A(void) override;										// 006BDF60
	virtual UInt32			Unk_8B(void) override;										// 006AE000
	virtual void			Unk_8C(UInt32 arg) override;								// 006A9380
	virtual bool			Unk_90(UInt32 arg) override;								// 006AFC10
	virtual void			Unk_91(void) override;										// 006B55F0
	virtual void			Unk_92(void) override;										// 006B5400
	virtual bool			Unk_93(void) override;										// 006B5430
	virtual void			Unk_95(void) override;										// 006BB5C0
	virtual void			Unk_96(void) override;										// 006B10C0
	virtual void			Unk_98(void) override;										// 006B3470
	virtual bool			IsDead(bool unk1) const;									// 006A7430
	virtual bool			Unk_9C(UInt32 arg1, UInt32 arg2, UInt32 arg3) override;		// 006C3710
	virtual bool			Unk_9D(UInt32 arg1, UInt32 arg2, UInt32 arg3) override;		// 006AF990
	virtual UInt32			Unk_9E(void) override;										// 006E16C0
	virtual void			Unk_A1(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4) override;	// 006D5020


	// @override class ActorValueOwner : (vtbl=010CFBF8)
	virtual float	GetActorValueCurrent(UInt32 arg) override;									// 01 006DF9C0
	virtual float	GetActorValueMaximum(UInt32 arg) override;									// 02 006DFA90
	virtual float	GetActorValueBase(UInt32 arg) override;										// 03 006DF850
	virtual void	SetActorValueBase(UInt32 arg0, float arg1) override;						// 04 006E06F0
	virtual void	ModActorValueBase(UInt32 arg0, float arg1) override;						// 05 006E0730
	virtual void	ActorValueOwner_Unk_06(UInt32 arg0, UInt32 arg1, UInt32 arg2) override;		// 06 006E08C0


	// @override ActorState (vtbl=0x010CFB9C)
	virtual FormID	IMovementState_Unk_01(void) override;					// 01 006A7CE0 { return formID; }
	virtual void	IMovementState_Unk_02(UInt32 arg) override;				// 02 006B5B90 { Pathing::GetSingleton()->Unk_00609A40((Actor*)this); .... }
	virtual void	GetPosition(NiPoint3 &pos) override;					// 03 006A7CF0 { pos = this->pos; }
	virtual void	GetAngle(NiPoint3 &pos) override;						// 04 006A7D10
	virtual float	IMovementState_Unk_05(void) override;					// 05 006A7D40 { return this->processManager->Unk_0071F140(); }
	virtual float	IMovementState_Unk_06(void) override;					// 06 006A7C60 { return this->processManager->Unk_0071F2C0(); }
	virtual void	IMovementState_Unk_07(NiPoint3 &pos) override;			// 07 006A7D70 { pos = NiPoint3{0f,0f,0f}; }
	virtual bool	IMovementState_Unk_08(UInt32 arg) override;				// 08 006CE640
	virtual float	IMovementState_Unk_09(void) override;					// 09 006B1730
	virtual float	IMovementState_Unk_0A(void) override;					// 0A 006B1760
	virtual float	IMovementState_Unk_0B(void) override;					// 0B 006B1790
	virtual float	IMovementState_Unk_0C(void) override;					// 0C 006ABBC0 { return Actor::Unk_006AB410(); }
	virtual float	IMovementState_Unk_0D(void) override;					// 0D 006ABBD0 { return Acotr::Unk_006AB410() * 0.75; }
	virtual bool	IMovementState_Unk_0E(void) override;					// 0E 006B17C0
	virtual MovementParameters *	IMovementState_Unk_0F(void) override;	// 0F 006A7DF0 { return (MovementParameters*)0x01275B88; }
	virtual bool	IMovementState_Unk_10(UInt32 arg) override;				// 10 006A7DA0 { return processManager ? processManager->Unk_006FCF40(arg) : false; }
	virtual UInt32	IMovementState_Unk_11(void) override;					// 11 006ABB80 { processManager->Unk_00720880(); ... }
	virtual bool	IMovementState_Unk_12(void) override;					// 12 006ABBB0 { Actor::Unk_006A6F20(g_thePlayer)}
	virtual bool	IMovementState_Unk_13(void) override;					// 13 006A7DD0 { return (byte)rece->data.unk7C & 1; }
	virtual bool	ActorState_Unk_15(UInt32 arg);							// 15 006EBA30


	// @override class IAnimationGraphManagerHolder : (vtbl=010CFC54)
	virtual bool	SendAnimationEvent(const BSFixedString &eventName) override;						// 01 006A7E30 { return IAnimationGraphManagerHolder::SendAnimationEvent(eventName) override; }
	virtual bool	GetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager> &out) override;	// 02 006A7E10
	virtual bool	IAnimationGraphManagerHolder_Unk_03(UInt32 arg) = 0;								// 03 006B18F0
	virtual bool	IAnimationGraphManagerHolder_Unk_05(UInt32 arg) = 0;								// 05 006B1860 { BSTSmartPointer<Unk_0112509C> &arg = new Unk_0112509C((Actor*)this, ???); }
	virtual bool	IAnimationGraphManagerHolder_Unk_06(void) override;									// 06 0092D110 { return false; }
	virtual bool	IAnimationGraphManagerHolder_Unk_07(UInt32 arg) override;							// 07 006BBF30
	virtual bool	IAnimationGraphManagerHolder_Unk_08(UInt32 arg) override;							// 08 006C73C0 - register event sinks BSTransformDeltaEvent, BSAnimationGraphEvent
	virtual bool	IAnimationGraphManagerHolder_Unk_0A(UInt32 arg) override;							// 0A 006BC2B0
	virtual void	IAnimationGraphManagerHolder_Unk_0B(UInt32 arg) override;							// 0B 006DA560
	virtual void	IAnimationGraphManagerHolder_Unk_0C(void) override;									// 0C 006BC830
	virtual void	IAnimationGraphManagerHolder_Unk_0D(UInt32 arg1, UInt32 arg2) override;				// 0D 006CE6C0
	virtual bool	IAnimationGraphManagerHolder_Unk_0E(void) override;									// 0E 006A7E00
	virtual UInt32	IAnimationGraphManagerHolder_Unk_0F(void) override;									// 0F 006A7E40 { return [01275B50]; }
	virtual bool	GetAnimationVariableFloat(const BSFixedString& variableName, float& out) override;	// 10 006A7ED0
	virtual bool	GetAnimationVariableInt(const BSFixedString& variableName, SInt32& out) override;	// 11 006A7E90
	virtual bool	GetAnimationVariableBool(const BSFixedString& variableName, bool& out) override;	// 12 006A7E50


	// @override MagicTarget (vtbl=0x010CFC20)
	virtual bool	MagicTarget_Unk_01(float arg) override;						// 006ED250
	virtual Actor *	MagicTarget_Unk_02(void) override;							// 006C5160 { return static_cast<Actor*>(this); }
	virtual bool	IsActorMagicTarget(void) const override;					// 009B86F0 { return true; }
	virtual bool	MagicTarget_Unk_04(void) override;							// 006A9270
	virtual void	MagicTarget_Unk_05(int) override;							// 006E89F0 { if (processManager) processManager->Unk_00724530(arg); }
	virtual bool	MagicTarget_Unk_06(void) override;							// 006E8880
	virtual BSSimpleList<ActiveEffect *> *	GetActiveEffects(void) override;	// 006E9180 { return processManager ? processManager->Unk_0071F120() : nullptr; }
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
	virtual void	Unk_A2(TESForm *arg1, bool arg2, bool arg3);					// A2 006B2590 called when inventory changed? - called from 006D2824,006D298D,006D67B9,006D6A99
	virtual float	Unk_A3(UInt32 arg);												// A3 006A92B0
	virtual void	Unk_A4(UInt32 arg);												// A4 00588F30 { return; } - called from 0074E217,0074E238,0074864B
	virtual void	DrawSheatheWeapon(bool draw);									// A5 006B2050
	virtual void	Unk_A6(void);													// A6 006B8BF0 - called when delete? - called from 006A97EF
	virtual void	Unk_A7(void);													// A7 006CC930 { ... RemoveSink(BSTEventSink<bhkCharacterMoveFinishEvent? *)this); ... }
	virtual void	Unk_A8(UInt32 arg1, UInt32 arg2);								// A8 006AE470 - 00693025,00742C1C
	virtual void	Unk_A9(void);													// A9 006AC410
	virtual void	Unk_AA(UInt32 arg1, UInt32 arg2);								// AA 006DB0A0
	virtual void	Unk_AB(void);													// AB 006E7B70 - ExtraInterAction
	virtual void	Unk_AC(UInt32 arg);												// AC 006C7690 - from 0069495C
	virtual void	Unk_AD(UInt32 arg);												// AD 006A8030 { this->Unk11E(); }
	virtual void	Unk_AE(UInt32 arg);												// AE 006A79F0 PlayerCharacter={ return; } from 006D648C
	virtual void	Unk_AF(void);													// AF 006D64D0 PlayerCharacter={ return; } from 006D6498
	virtual void	Unk_B0(void);													// B0 006B5AF0
	virtual void	Unk_B1(bool arg);												// B1 006CD7C0 - draw weapon when arg is true. called multiple times when actor dies. - 006EE2E5,0072D618
	virtual bool	Unk_B2(void);													// B2 009B86F0 { return true; } called when die
	virtual void	Unk_B3(void);													// B3 006BCAF0
	virtual void	Unk_B4(void);													// B4 006AECA0
	virtual void	Unk_B5(void);													// B5 006AECC0
	virtual void	AddCrimeGold(UInt32 mount, bool bViolent, TESFaction *faction);	// B6 006AECF0
	virtual void	Unk_B7(void);													// B7 006AED10
	virtual void	Unk_B8(UInt32 arg1, UInt32 arg2, UInt32 arg3);					// B8 00D62BE0 { return; }
	virtual void	Unk_B9(void);													// B9 006C50E0 { return; }
	virtual void	Unk_BA(UInt32 arg1, UInt32 arg2, UInt32 arg3);					// BA 00D62BE0 { return; }
	virtual bool	Unk_BB(void);													// BB 0092D110 { return false; }
	virtual void	Unk_BC(UInt32 arg);												// BC 00588F30 { return; }
	virtual bool	Unk_BD(void);													// BD 0092D110 { return false; } - called 2 times when activate
	virtual void	Unk_BE(UInt32 arg);													// BE 00588F30 { return; }
	virtual void	Unk_BF(UInt32 arg1, UInt32 arg2);								// BF 004D43E0 { return; }
	virtual void	Unk_C0(UInt32 arg);												// C0 00588F30 { return; }
	virtual void	Unk_C1(void);													// C1 006BEC40 - called when weapon swing, item drop
	virtual void	Unk_C2(void);													// C2 006E9780
	virtual void	Unk_C3(UInt32 arg);												// C3 00588F30 { return; }
	virtual bool	Unk_C4(void);													// C4 009B86F0 { return true; }
	virtual UInt32	Unk_C5(void) = 0;												// C5 00F51EE8 pure, PlayerCharacter={ return 2; }
	virtual void	Unk_C6(void);													// C6 0064A3E0
	virtual void	Unk_C7(void);													// C7 006CF440 - called every frame?
	virtual void	Unk_C8(void);													// C8 006E8630
	virtual void	Unk_C9(void);													// C9 006C50E0 { return; }
	virtual void	DropItem(RefHandle *droppedItemHandle, TESForm *akItem, BaseExtraList *extraList, UInt32 count, UInt32 arg5, UInt32 arg6);		// CA 006BD1A0
	virtual void	PickUpItem(TESObjectREFR *item, UInt32 count, bool arg3, bool playSound);		// CB 006CE8B0  - called from 0084AA68
	virtual void	Unk_CC(UInt32 arg1);											// CC 006E3020 - "Arrow%d"
	virtual void	Unk_CD(UInt32 arg1);											// CD 006E31A0 - "Arrow%d"
	virtual void	Unk_CE(void);													// CE 006E9140
	virtual void	Unk_CF(UInt32 arg);												// CF 00588F30 { return; }
	virtual bool	Unk_D0(void);													// D0 006E0DA0 PlayerCharacter={ return false; }
	virtual void	Unk_D1(void);													// D1 006E2450
	virtual bool	Unk_D2(void);													// D2 006E3580 PlayerCharacter={ return false; }
	virtual void *	Unk_D3(void);													// D3 006E1620 { unk0D8 ? *unk0D8 : nullptr } PlayerCharacter={ return unk62C; }
	virtual void	Unk_D4(void * arg);												// D4 006E1630 { unk0D8 > *unk0D8 = arg; }
	virtual void	Unk_D5(void);													// D5 006E1650
	virtual void	Unk_D6(UInt32 arg);												// D6 004091A0 { return false; }
	virtual bool	Unk_D7(UInt32 arg1, UInt32 arg2, UInt32 arg3);					// D7 006BEE70 PlayerCharacter={ return false; }
	virtual void	Unk_D8(void);													// D8 006C1E90
	virtual void	Unk_D9(void);													// D9 006B7C50 PlayerCharacter={ return; }
	virtual void	Unk_DA(void);													// DA 006BEE10
	virtual void	Unk_DB(UInt32 arg);												// DB 00588F30 PlayerCharacter={ return; }
	virtual void	Unk_DC(void);													// DC 006BDC80
	virtual void	Unk_DD(void);													// DD 006CB280
	virtual void	Unk_DE(void);													// DE 006BAEE0
	virtual void	Unk_DF(void);													// DF 006E9EC0
	virtual void	Unk_E0(void);													// 006E9190
	virtual void	Unk_E1(void);													// 006E8770
	virtual bool	IsInCombat(void);												// E2 006E1340
	virtual void	Unk_E3(void);													// 006E2BF0 PlayerCharacter={ return; } 
	virtual void	Unk_E4(void);													// 006E5510
	virtual float	Unk_E5(void);													// 0066E8A0 { return 0.0f; }
	virtual float	Unk_E6(void);													// 0066E8A0 { return 0.0f; }
	virtual void	Unk_E7(void);													// 005EADD0 { return 0; }
	virtual void	Unk_E8(void);													// 0092D110 { return false; }
	virtual void	Unk_E9(UInt32 arg);												// 004091A0 { return false; }
	virtual void	Unk_EA(void);													// 006C5FA0
	virtual void	Unk_EB(void);													// 006AB7D0
	virtual void	Unk_EC(void);													// 006AB850
	virtual void	Unk_ED(void);													// 006C5F90
	virtual void	OnWeaponSwing(void);											// 006E3D50
	virtual void	Unk_EF(void);													// EE 006A8BD0 PlayerCharacter={ return; }
	virtual void	Unk_F0(void);													// 006DC790
	virtual void	Unk_F1(void);													// 006DCEA0
	virtual void	Unk_F2(void);													// 006DD4B0
	virtual void	Unk_F3(void);													// 006DD940
	virtual void	Unk_F4(void);													// 006E1290
	virtual void	Unk_F5(void);													// 006E12A0
	virtual void	AdvanceSkill(UInt32 skillId, float points, UInt32 unk1, UInt32 unk2);	// F6 00DE8190 { return; }
	virtual void	Unk_F7(void);													// 006ACBD0
	virtual bool	IsInFaction(TESFaction* faction);								// F8 006A9120
	virtual void	VisitPerks(PerkEntryVisitor &visitor);							// F9 006AA200 { return baseForm->BGSPerkRankArray::VisitPerkEntry(visitor); } - BGSPerk::FindPerkInRanksVisitor
	virtual void	AddPerk(BGSPerk * perk, UInt32 unk1);							// FA 004D43E0 { return; }
	virtual void	RemovePerk(BGSPerk * perk);										// FB 00588F30 { return; }
	virtual void	Unk_FC(UInt32 arg);												// 00588F30 { return; }
	virtual void	Unk_FD(UInt32 arg);												// 00588F30 { return; }
	virtual bool	CanProcessEntryPointPerkEntry(UInt32 entryType);				// FE 006AA210 
	virtual void	VisitEntryPointPerkEntries(UInt32 entryType, PerkEntryVisitor &visitor);	// FF 006AA240 { if (processManager) processManager->Unk00724660(arg1, visitor); }
	virtual void	Unk_100(void);													// 006AA260
	virtual void	Unk_101(void);													// 006C50E0 { return; }
	virtual bool	Unk_102(void);													// 0092D110 { return false; }
	virtual void	Unk_103(void);													// 006E4700
	virtual void	Unk_104(void);													// 006E1130
	virtual bool	Unk_105(void);													// 0092D110 { return false; }
	virtual void	Unk_106(void);													// 006C50F0
	virtual void	Unk_107(void);													// 006C5100
	virtual void	Unk_108(void);													// 006B2630
	virtual void	Unk_109(void);													// 006C5120 { return this->unk0E4; }
	virtual void	Unk_10A(UInt32 arg);											// 006C5130 { this->unk0E4 = arg; }
	virtual void	Unk_10B(void);													// 006C5140 { return this->unk0E8; }
	virtual void	Unk_10C(UInt32 arg);											// 006C5150 { this->unk0E8 = arg; }
	virtual void	Unk_10D(void);													// 006D6B30
	virtual void	Unk_10E(void);													// 006EA980
	virtual void	Unk_10F(void);													// 006E8F90
	virtual void	Unk_110(void);													// 006C50E0 { return; }
	virtual void	Unk_111(void);													// 006E8B30
	virtual void	Unk_112(UInt32 arg);											// 00588F30 { return; }
	virtual void	GetLastRiddenHorse(RefHandle &out) const;						// 006C51F0 { out = g_invalidRefHandle; }
	virtual void	Unk_114(void);													// 006B1340
	virtual void	Unk_115(void);													// 006B1290
	virtual void	Unk_116(UInt32 arg);											// 00588F30 { return; }
	virtual void	Unk_117(void);													// 006AA2E0
	virtual void	Unk_118(void);													// 006BBF00
	virtual void	Unk_119(void);													// 006AB8D0
	virtual void	Unk_11A(void);													// 006A79D0 PlayerCharacter={ return; }
	virtual void	Unk_11B(UInt32 arg);											// 006AB920 PlayerCharacter={ return; }
	virtual void	Unk_11C(void);													// 006A7A20
	virtual void	Unk_11D(void);													// 006A7A50
	virtual void	Unk_11E(void);													// 006ABD60
	virtual void	Unk_11F(void);													// 006CC840
	virtual void	Unk_120(void);													// 006B6060
	virtual void	Unk_121(void);													// 006B4C00
	virtual void	Unk_122(void);													// 006CECB0
	virtual void	Unk_123(void);													// 006B6EA0
	virtual void	Unk_124(void);													// 006A8EF0
	virtual void	Unk_125(void);													// 006A8F40
	virtual bool	Unk_126(UInt32 arg1, UInt32 arg2);								// 006B9BF0 PlayerCharacter={ return false; }
	virtual void	Unk_127(void);													// 006DFB30


	TESForm * GetEquippedObject(bool abLeftHand);
	void UpdateSkinColor();
	void UpdateHairColor();
	bool HasLOS(TESObjectREFR *target);

	///<summary>Gets the ActorBase of the actor.</summary>
	TESNPC * GetActorBase(void) const
	{
		return (TESNPC*)baseForm;
	}

	///<summary>Obtains this actor's Race.</summary>
	TESRace * GetRace() const;

	///<summary>Checks to see if this actor has the given Spell or Shout.</summary>
	bool HasSpell(TESForm * spell) const;

	///<summary>Checks to see if this actor has the given Spell.</summary>
	bool HasSpell(SpellItem * spell) const
	{
		return HasSpell_Impl(spell);
	}

	///<summary>Checks to see if this actor has the given Shout.</summary>
	DEFINE_MEMBER_FN_const(HasShout, bool, 0x006EAF10, TESShout* shout);

	///<summary>Forces the actor to dismount.</summary>
	DEFINE_MEMBER_FN(Dismount, void, 0x006C2EA0);
	
	///<summary>Enables or disables this actor's AI.</summary>
	DEFINE_MEMBER_FN(EnableAI, void, 0x006AA690, bool bEnable);

	///<summary>Forces this actor's AI to re-evaluate its package stack.</summary>
	void EvalueatePackage()
	{
		if (!flags.disabled && !flags.deleted)
			EvaluatePackage_Impl(false, false);
	}

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
		return flags1.guard;
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

	DEFINE_MEMBER_FN(VisitSpells, void, 0x006EA380, ForEachSpellVisitor *visitor);
	DEFINE_MEMBER_FN(QueueNiNodeUpdate, void, 0x00730EE0, bool updateWeight);
	DEFINE_MEMBER_FN(SetRace, void, 0x006AF590, TESRace *, bool isPlayer);
	DEFINE_MEMBER_FN(UpdateWeaponAbility, void, 0x006ED980, TESForm *, BaseExtraList *extraData, bool bLeftHand);
	DEFINE_MEMBER_FN(UpdateArmorAbility, void, 0x006E8650, TESForm *, BaseExtraList *extraData);
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

	// 10
	struct Data13C
	{
		BSFixedString	unk00;
		UInt32			unk04;
		BSFixedString	unk08;
		UInt32			unk0C;
	};

	// 0C
	struct Data150
	{
		UInt32	unk00;
		UInt32	unk04;
		UInt32	unk08;
	};


	// @members
	Flags1						flags1;								// 07C
	UInt32						unk080;								// 080
	UInt32						unk084;								// 084
	ActorProcessManager			* processManager;					// 088
	RefHandle					dialogueTargetRefHandle;			// 08C
	RefHandle					combatTargetRefHandle;				// 090
	RefHandle					killerRefHandle;					// 094
	UInt32						unk094[(0x0C8 - 0x098) >> 2];		// 098
	BGSLocation					* editorLocation;					// 0C8
	UInt32						pad0CC;								// 0CC
	MovementControllerAI		* movementControllerAI;				// 0D0
	UInt32						pad0D4[(0x0FC - 0x0D4) >> 2];		// 0D4
	BSTSmallArray<SpellItem *>	addedSpells;						// 0FC
	MagicCaster					* magicCaster[kNumSlots];			// 108 [0] lefthand [1] right hand [2] unknown [3] power/shout
	MagicItem					* equippingMagicItems[kNumSlots];	// 118
	TESForm						* equippedShout;					// 128
	UInt32						unk12C;								// 12C
	TESRace						* race;								// 130
	UInt32						unk134;								// 134
	Flags2						flags2;								// 138
	Data13C						unk13C;								// 13C
	UInt32						unk14C;								// 14C
	Data150						unk150;								// 150
	Data150						unk15C;								// 15C
	Data150						unk168;								// 168
	Data150						unk174;								// 174
	UInt32						unk180[(0x19C - 0x180) >> 2];		// 180

private:
	DEFINE_MEMBER_FN(ctor, Actor *, 0x006CE4F0);

	DEFINE_MEMBER_FN_const(HasSpell_Impl, bool, 0x006E9130, SpellItem* spell);
	DEFINE_MEMBER_FN(EvaluatePackage_Impl, void, 0x006BE790, bool, bool);
};
STATIC_ASSERT(offsetof(Actor, addedSpells) == 0xFC);
STATIC_ASSERT(sizeof(Actor) == 0x19C);
