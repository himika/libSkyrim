#pragma once

#include "BSSystem/BSTSmartPointer.h"
#include "BSCore/BSTSingleton.h"
#include "BSCore/BSSpinLock.h"
#include "SkyrimScript.h"
#include "Events/ScriptEvent.h"
#include "Events/PositionPlayerEvent.h"

class VMState;

class ICallStackManagerBase
{
public:
	virtual ~ICallStackManagerBase() { }		// 00B72260

	virtual UInt32	Unk_01(void) = 0;
	virtual UInt32	Unk_02(UInt32 arg1, UInt32 arg2, UInt32 arg3) = 0;
	virtual UInt32	Unk_03(UInt32 arg1) = 0;
	virtual void	Unk_04(UInt32 arg) = 0;

	// @members
	// void **	_vtbl	// 00 - 01122D2C
};


// 24
class ProbablyCallStackManager : public ICallStackManagerBase
{
public:
	ProbablyCallStackManager(UInt32 arg1, UInt32 arg2, UInt32 arg3)						// 00C428A0 call from 008D7DCE
		: unk04(arg1), unk08(arg2), unk0C(arg3)
	{
	}

	virtual UInt32	Unk_01(void) override;										// 00C42890 { return unk8; }
	virtual UInt32	Unk_02(UInt32 arg1, UInt32 arg2, UInt32 arg3) override;		// 00C428E0
	virtual UInt32	Unk_03(UInt32 arg1) override;								// 00C42A10
	virtual void	Unk_04(UInt32 arg) override;								// 00C42B00

	// @members
	// void **	_vtbl		// 00 - 01149B68
	UInt32		unk04;
	UInt32		unk08;
	UInt32		unk0C;
	bool		unk10;
	UInt32		unk14;
	UInt32		unk18;
	UInt32		unk1C;
	UInt32		unk20;
};



// 20
class ProbablyLoader : public BSScript::ILoader
{
public:
	ProbablyLoader();
	ProbablyLoader(SkyrimScript::Logger *a_logger, UInt8 arg1, UInt32 arg2) {
		ctor(a_logger, arg1, arg2);
	}

	virtual ~ProbablyLoader();									// 00C45DF0

	virtual ILoader *	Unk_01(void) override;					// 00C42D70
	virtual void		Unk_02(void *arg0) override;			// 00C42E80
	virtual bool		Unk_03(const char *name, void *unkObj);	// 00C45410 called from 00C68E76

	struct Data
	{
		UInt32	unk00;
		UInt32	unk04;
		UInt32	unk08;
		UInt32	unk0C;
	};

	// @members
	// void **	_vtbl					// 00 - 01149B98
	SkyrimScript::Logger	* logger;	// 04
	Data					unk08;		// 08
	UInt32					unk18;		// 18
	UInt8					unk1C;		// 1C
	UInt8					unk1D;		// 1D
	UInt8					unk1E;		// 1E
	UInt8					pad1F;		// 1F

private:
	DEFINE_MEMBER_FN(ctor, ProbablyLoader *, 0x00C42D20, SkyrimScript::Logger *, UInt8, UInt32);
};
STATIC_ASSERT(sizeof(ProbablyLoader) == 0x20);


// 0C
// Some generic type but I haven't figured it out yet
class UpdateRegistrationHolder
{
	// 018
	class Registration : public BSIntrusiveRefCounted
	{
	public:
		typedef BSTSmartPointer<Registration> SmartPtr;

		bool			runOnce;	// 04
		UInt8			pad05;		// 05
		UInt16			pad06;		// 06
		UInt32			schedTime;	// 08
		UInt32			interval;	// 0C
		VMHandle		handle;		// 10
	};

	BSTArray<BSTSmartPointer<Registration>>	m_regs;	// 00

	void	Order(UInt32 index);

public:
	bool	Remove(VMHandle & handle);	// TESV.008CF2D0
};

// 0C
class LOSRegistrationHolder
{
	// 020
	class Registration : public BSIntrusiveRefCounted
	{
	public:
		typedef BSTSmartPointer<Registration> SmartPtr;

		UInt32			pad04;			// 04
		VMHandle		handle;			// 08
		UInt32			viewerFormID;	// 10
		UInt32			targetFormID;	// 14
		UInt32			unk4;			// 18
		UInt32			hasLOS;			// 1C
	};

	BSTArray<BSTSmartPointer<Registration>>	m_regs;	// 00
};


/*==============================================================================
class SkyrimVM +0000 (_vtbl=010EBEBC)
0000: class SkyrimVM
00CC: |   struct BSTSingletonSDM<class SkyrimVM,struct BSTSingletonSDMOpStaticBuffer>
00CC: |   |   struct BSTSingletonSDMBase<struct BSTSDMTraits<class SkyrimVM,struct BSTSingletonSDMOpStaticBuffer<class SkyrimVM> > >
00CC: |   |   |   struct BSTSDMTraits<class SkyrimVM,struct BSTSingletonSDMOpStaticBuffer<class SkyrimVM> >
00CD: |   |   |   struct BSTSingletonSDMOpStaticBuffer<class SkyrimVM>
0000: |   class BSScript::IFreezeQuery
0004: |   class BSScript::IStackCallbackSaveInterface
0008: |   class BSTEventSink<struct TESActivateEvent>
000C: |   class BSTEventSink<struct TESActiveEffectApplyRemoveEvent>
0010: |   class BSTEventSink<struct TESActorLocationChangeEvent>
0014: |   class BSTEventSink<struct TESBookReadEvent>
0018: |   class BSTEventSink<struct TESCellAttachDetachEvent>
001C: |   class BSTEventSink<struct TESCellFullyLoadedEvent>
0020: |   class BSTEventSink<struct TESCombatEvent>
0024: |   class BSTEventSink<struct TESContainerChangedEvent>
0028: |   class BSTEventSink<struct TESDeathEvent>
002C: |   class BSTEventSink<struct TESDestructionStageChangedEvent>
0030: |   class BSTEventSink<struct TESEnterBleedoutEvent>
0034: |   class BSTEventSink<struct TESEquipEvent>
0038: |   class BSTEventSink<struct TESFormDeleteEvent>
003C: |   class BSTEventSink<struct TESFurnitureEvent>
0040: |   class BSTEventSink<struct TESGrabReleaseEvent>
0044: |   class BSTEventSink<struct TESHitEvent>
0048: |   class BSTEventSink<struct TESInitScriptEvent>
004C: |   class BSTEventSink<struct TESLoadGameEvent>
0050: |   class BSTEventSink<struct TESLockChangedEvent>
0054: |   class BSTEventSink<struct TESMagicEffectApplyEvent>
0058: |   class BSTEventSink<struct TESMagicWardHitEvent>
005C: |   class BSTEventSink<struct TESMoveAttachDetachEvent>
0060: |   class BSTEventSink<struct TESObjectLoadedEvent>
0064: |   class BSTEventSink<struct TESObjectREFRTranslationEvent>
0068: |   class BSTEventSink<struct TESOpenCloseEvent>
006C: |   class BSTEventSink<struct TESPackageEvent>
0070: |   class BSTEventSink<struct TESPerkEntryRunEvent>
0074: |   class BSTEventSink<struct TESQuestInitEvent>
0078: |   class BSTEventSink<struct TESQuestStageEvent>
007C: |   class BSTEventSink<struct TESResetEvent>
0080: |   class BSTEventSink<struct TESResolveNPCTemplatesEvent>
0084: |   class BSTEventSink<struct TESSceneEvent>
0088: |   class BSTEventSink<struct TESSceneActionEvent>
008C: |   class BSTEventSink<struct TESScenePhaseEvent>
0090: |   class BSTEventSink<struct TESSellEvent>
0094: |   class BSTEventSink<struct TESSleepStartEvent>
0098: |   class BSTEventSink<struct TESSleepStopEvent>
009C: |   class BSTEventSink<struct TESSpellCastEvent>
00A0: |   class BSTEventSink<struct TESTopicInfoEvent>
00A4: |   class BSTEventSink<struct TESTrackedStatsEvent>
00A8: |   class BSTEventSink<struct TESTrapHitEvent>
00AC: |   class BSTEventSink<struct TESTriggerEvent>
00B0: |   class BSTEventSink<struct TESTriggerEnterEvent>
00B4: |   class BSTEventSink<struct TESTriggerLeaveEvent>
00B8: |   class BSTEventSink<struct TESUniqueIDChangeEvent>
00BC: |   class BSTEventSink<struct TESSwitchRaceCompleteEvent>
00C0: |   class BSTEventSink<struct TESPlayerBowShotEvent>
00C4: |   class BSTEventSink<struct PositionPlayerEvent>
00C8: |   class BSTEventSink<struct BSScript::StatsEvent>
00D0: |   class BSTEventSource<struct SkyrimScript::StatsEvent>
==============================================================================*/
// 45D0
class SkyrimVM :
	public BSTSingletonSDM<SkyrimVM>,						// 00CC
	public BSScript::IFreezeQuery,							// 0000
	public BSScript::IStackCallbackSaveInterface,			// 0004
	public BSTEventSink<TESActivateEvent>,					// 0008
	public BSTEventSink<TESActiveEffectApplyRemoveEvent>,	// 000C
	public BSTEventSink<TESActorLocationChangeEvent>,		// 0010
	public BSTEventSink<TESBookReadEvent>,					// 0014
	public BSTEventSink<TESCellAttachDetachEvent>,			// 0018
	public BSTEventSink<TESCellFullyLoadedEvent>,			// 001C
	public BSTEventSink<TESCombatEvent>,					// 0020
	public BSTEventSink<TESContainerChangedEvent>,			// 0024
	public BSTEventSink<TESDeathEvent>,						// 0028
	public BSTEventSink<TESDestructionStageChangedEvent>,	// 002C
	public BSTEventSink<TESEnterBleedoutEvent>,				// 0030
	public BSTEventSink<TESEquipEvent>,						// 0034
	public BSTEventSink<TESFormDeleteEvent>,				// 0038
	public BSTEventSink<TESFurnitureEvent>,					// 003C
	public BSTEventSink<TESGrabReleaseEvent>,				// 0040
	public BSTEventSink<TESHitEvent>,						// 0044
	public BSTEventSink<TESInitScriptEvent>,				// 0048
	public BSTEventSink<TESLoadGameEvent>,					// 004C
	public BSTEventSink<TESLockChangedEvent>,				// 0050
	public BSTEventSink<TESMagicEffectApplyEvent>,			// 0054
	public BSTEventSink<TESMagicWardHitEvent>,				// 0058
	public BSTEventSink<TESMoveAttachDetachEvent>,			// 005C
	public BSTEventSink<TESObjectLoadedEvent>,				// 0060
	public BSTEventSink<TESObjectREFRTranslationEvent>,		// 0064
	public BSTEventSink<TESOpenCloseEvent>,					// 0068
	public BSTEventSink<TESPackageEvent>,					// 006C
	public BSTEventSink<TESPerkEntryRunEvent>,				// 0070
	public BSTEventSink<TESQuestInitEvent>,					// 0074
	public BSTEventSink<TESQuestStageEvent>,				// 0078
	public BSTEventSink<TESResetEvent>,						// 007C
	public BSTEventSink<TESResolveNPCTemplatesEvent>,		// 0080
	public BSTEventSink<TESSceneEvent>,						// 0084
	public BSTEventSink<TESSceneActionEvent>,				// 0088
	public BSTEventSink<TESScenePhaseEvent>,				// 008C
	public BSTEventSink<TESSellEvent>,						// 0090
	public BSTEventSink<TESSleepStartEvent>,				// 0094
	public BSTEventSink<TESSleepStopEvent>,					// 0098
	public BSTEventSink<TESSpellCastEvent>,					// 009C
	public BSTEventSink<TESTopicInfoEvent>,					// 00A0
	public BSTEventSink<TESTrackedStatsEvent>,				// 00A4
	public BSTEventSink<TESTrapHitEvent>,					// 00A8
	public BSTEventSink<TESTriggerEvent>,					// 00AC
	public BSTEventSink<TESTriggerEnterEvent>,				// 00B0
	public BSTEventSink<TESTriggerLeaveEvent>,				// 00B4
	public BSTEventSink<TESUniqueIDChangeEvent>,			// 00B8
	public BSTEventSink<TESSwitchRaceCompleteEvent>,		// 00BC
	public BSTEventSink<TESPlayerBowShotEvent>,				// 00C0
	public BSTEventSink<PositionPlayerEvent>,				// 00C4
	public BSTEventSink<BSScript::StatsEvent>,				// 00C8
	public BSTEventSource<SkyrimScript::StatsEvent>			// 00D0
{
public:
	virtual ~SkyrimVM();																					// 008D84D0

	// @override class BSScript::IFreezeQuery : (vtbl=010EBEBC)
	virtual bool	IFreezeQuery_Unk_01(void) override;														// 008C78E0

	// @override class BSScript::IStackCallbackSaveInterface : (vtbl=010EBEAC)
	virtual bool	IStackCallbackSaveInterface_Unk_01(UInt32 arg1, UInt32 arg2) override;					// 008C87D0
	virtual bool	IStackCallbackSaveInterface_Unk_02(UInt32 arg1, UInt32 arg2, UInt32 arg3) override;		// 008CC500

	inline VMState * GetState(void) const
	{
		return m_state;
	}

	DEPRECATED__("use GetState() instead")
	inline VMState * GetClassRegistry(void) const
	{
		return m_state;
	}

	UInt32 ClearInvalidRegistrations(void);

	DEFINE_MEMBER_FN(QueueAliasEvent, void, 0x008C6B30, VMHandle handle, const BSFixedString& eventName, BSScript::IFunctionArguments* args, UInt32 arg4);
	DEFINE_MEMBER_FN(UnregisterForUpdate, void, 0x008D1E00, VMHandle handle);
	DEFINE_MEMBER_FN(AddDelayFunctor, bool, 0x008C7810, BSTSmartPointer<SkyrimScript::DelayFunctor> &delayFunctorPtr);


	// @members
	//void						** _vtbl;					// 0000
	VMState						* m_state;					// 0100
	UInt32						pad104;						// 
	UInt32						pad108;						//      (vtbl)    (demangled class name)
	ProbablyCallStackManager	unk10C;						// 010C 01149B68  ? probably stack manager
	ProbablyLoader				papyrusLoader;				// 0130
	UInt8						pad150[0x1B8 - 0x150];		// 0150
	//SkyrimScript::Logger									// 0150 01148BF4  SkyrimScript::Logger
															// 01AC             | BSFixedString("Papyrus")
															// 01B0             | BSFixedString("Logs/Script")
	SkyrimScript::HandlePolicy	handlePolicy;				// 01B8 010EBA1C  SkyrimScript::HandlePolicy
	UInt8						pad1B8[0x454 - 0x204];		// 0204
	//SkyrimScript::ObjectBindPolicy						// 0204 010EBAD4  SkyrimScript::ObjectBindPolicy
															// 0294           BSTHashMap<????>  traits=012B64D4
															// 0294+48            BSSpinLock
															// 0360 010EA744  SkyrimScript::Profiler
															// 0400 010EA79C  SkyrimScript::SavePatcher
															// 0430           ?
															// 0438           ?
															// 043C           ?
															// 0444           ?
															// 0448           ?
	BSSpinLock					m_losLock;					// 0454
	LOSRegistrationHolder		m_losRegHolder;				// 045C
	UInt32						unk468;						// 0468
	BSSpinLock					m_updateLock;				// 046C
	UpdateRegistrationHolder	m_updateRegHolder;			// 0474
	UpdateRegistrationHolder	m_updateGameTimeRegHolder;	// 0480
	//BSSpinLock				m_delayFunctorLock;			// 4570
	//BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>> *delayFunctorQueue;	// 457C

private:
	friend struct BSTSingletonSDMBase<BSTSDMTraits<SkyrimVM>>;
	DEFINE_MEMBER_FN(ctor, SkyrimVM*, 0x008D7A40);
	DEFINE_MEMBER_FN(dtor, void, 0x008D7000);
};
STATIC_ASSERT(offsetof(SkyrimVM, m_state) == 0x100);
STATIC_ASSERT(offsetof(SkyrimVM, m_updateRegHolder) == 0x474);

extern SkyrimVM	*& g_skyrimVM;
