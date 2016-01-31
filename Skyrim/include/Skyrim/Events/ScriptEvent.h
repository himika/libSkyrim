#pragma once

#include "../BSCore/BSTEvent.h"

class TESForm;
class ActiveEffect;
class TESObjectCELL;
class TESObjectREFR;
class Actor;

struct BGSEventProcessedEvent
{
};

// 8
struct TESActivateEvent
{
	TESObjectREFR* target;
	TESObjectREFR* caster;
};

struct TESActiveEffectApplyRemoveEvent
{
	TESObjectREFR	* caster;
	TESObjectREFR	* target;
	UInt32			unk08;
	UInt32			unk0C;
	UInt32			unk10;
	UInt32			unk14;
	UInt32			unk18; // Flags?
	UInt32			unk1C; // Use effect2 if this is 1
	TESForm			* source; // Not really sure what this is, probably the extra form
	ActiveEffect	* effect1;
	ActiveEffect	* effect2;
};

// 0C
struct TESActorLocationChangeEvent
{
	UInt32 unk00;
	UInt32 unk01;
	UInt32 unk02;
};

struct TESBookReadEvent
{
};

struct TESCellAttachDetachEvent
{
	// SendEvent: 004CEB5F
	TESObjectREFR*	ref;
	bool			bAttach;
	UInt8			pad[3];
};

struct TESCellReadyToApplyDecalsEvent
{
	/*
	004CB1B8: 012E4D80.SendEvent(01310448)
	class `anonymous namespace'::DecalApplier +0000
	+0000 01 class `anonymous namespace'::DecalApplier | 01244C0C
	-->	+0000 00 class BSTEventSink<struct TESCellReadyToApplyDecalsEvent> | 01244288
	*/
};

// 04
struct TESCellFullyLoadedEvent
{
	// SendEvent: 00437663 <= 4CDD8E
	TESObjectCELL*	cell;
};

// 0C
struct TESCombatEvent
{
	Actor*  caster;
	Actor*  target;
	UInt32  state;
};

// 18
struct TESContainerChangedEvent
{
	FormID		from;
	FormID		to;
	FormID		item;
	UInt32		count;
	RefHandle	toReference;
	UInt32		unk14;
};

struct TESDeathEvent
{
};


struct TESDestructionStageChangedEvent
{
};

struct TESEnterBleedoutEvent
{
};

// 10
struct TESEquipEvent
{
	UInt32 unk_00;
	UInt32 unk_01;
	UInt32 unk_02;
	UInt32 unk_03;
};

struct TESFormDeleteEvent
{
};

struct TESFurnitureEvent
{
};

struct TESGrabReleaseEvent
{
};

struct TESHitEvent
{
	TESObjectREFR	* target;			// 00
	TESObjectREFR	* caster;			// 04
	FormID			sourceFormID;		// 08
	FormID			projectileFormID;	// 0C

	struct Flags {
		bool powerAttack : 1;
		bool sneakAttack : 1;
		bool bash : 1;
		bool blocked : 1;
	} flags;							// 10

	void			* unk14[7];			// 14
};

struct TESInitScriptEvent
{
	TESObjectREFR	* reference;
	UInt32			unk04;
};


struct TESLoadGameEvent
{
};

struct TESLockChangedEvent
{
};

// 0C
struct TESMagicEffectApplyEvent
{
	TESObjectREFR	* target;
	TESObjectREFR	* caster;
	UInt32          unk08;
};

struct TESMagicWardHitEvent
{
};

struct TESMoveAttachDetachEvent
{
};

struct TESObjectLoadedEvent
{
	FormID	formID;
};

struct TESObjectREFRTranslationEvent
{
};

struct TESOpenCloseEvent
{
};

struct TESPackageEvent
{
};

struct TESPerkEntryRunEvent
{
};

struct TESQuestInitEvent
{
	FormID	formId;
};

struct TESQuestStageEvent
{
	void			* finishedCallback;
	FormID			formId;
	UInt32			stage;
};

struct TESQuestStageItemDoneEvent
{
};

struct TESQuestStartStopEvent
{
};

struct TESResetEvent
{
};

struct TESResolveNPCTemplatesEvent
{
};

struct TESSceneEvent
{
};

struct TESSceneActionEvent
{
};

struct TESScenePhaseEvent
{
};

struct TESSellEvent
{
};

// 08
struct TESSleepStartEvent
{
	float startTime;	// 00
	float endTime;		// 04
};

struct TESSleepStopEvent
{
};

struct TESSpellCastEvent
{
};

struct TESPlayerBowShotEvent
{
};

struct TESTrackedStatsEvent
{
};

struct TESTrapHitEvent
{
};

struct TESTopicInfoEvent
{
	Actor	* speaker;		// 00 - NiTPointer<Actor>
	void	* unk04;		// 04 - BSTSmartPointer<REFREventCallbacks::IEventCallback>
	FormID  topicInfoID;	// 08
	bool	flag;			// 0C

	inline bool IsStarting() {
		return !flag;
	}
	inline bool IsStopping() {
		return flag;
	}
};

struct TESTriggerEvent
{
};

struct TESTriggerLeaveEvent
{
};

struct TESTriggerEnterEvent
{
};

struct TESUniqueIDChangeEvent	// see: TESV.00482050
{
	UInt32	unk00;		// always 0?
	FormID	formID1;
	FormID	formID2;
	UInt16	unk0C;
	UInt16	unk0E;
};

struct TESWaitStartEvent
{
};

struct TESWaitStopEvent
{
};

struct TESSwitchRaceCompleteEvent
{
	Actor	* actor;
};


extern BSTEventSource<BGSEventProcessedEvent>&				g_eventProcessedEventSource;
extern BSTEventSource<TESActivateEvent>&					g_activateEventSource;
extern BSTEventSource<TESActiveEffectApplyRemoveEvent>&		g_activeEffectApplyRemoveEventSource;
extern BSTEventSource<TESActorLocationChangeEvent>&			g_actorLocationChangeEventSource;
extern BSTEventSource<TESBookReadEvent>&					g_bookReadEventSource;
extern BSTEventSource<TESCellAttachDetachEvent>&			g_cellAttachDetachEventSource;
extern BSTEventSource<TESCellFullyLoadedEvent>&				g_cellFullyLoadedEventSource;
extern BSTEventSource<TESCellReadyToApplyDecalsEvent>&		g_cellReadyToApplyDecalsEventSource;
extern BSTEventSource<TESCombatEvent>&						g_combatEventSource;
extern BSTEventSource<TESContainerChangedEvent>&			g_containerChangedEventSource;
extern BSTEventSource<TESDeathEvent>&						g_deathEventSource;
extern BSTEventSource<TESDestructionStageChangedEvent>&		g_destructionStageChangedEventSource;
extern BSTEventSource<TESEnterBleedoutEvent>&				g_enterBleedoutEventSource;
extern BSTEventSource<TESEquipEvent>&						g_equipEventSource;
extern BSTEventSource<TESFormDeleteEvent>&					g_formDeleteEventSource;
extern BSTEventSource<TESFurnitureEvent>&					g_furnitureEventSource;
extern BSTEventSource<TESGrabReleaseEvent>&					g_grabReleaseEventSource;
extern BSTEventSource<TESHitEvent>&							g_hitEventSource;
extern BSTEventSource<TESInitScriptEvent>&					g_initScriptEventSource;
extern BSTEventSource<TESLoadGameEvent>&					g_loadGameEventSource;
extern BSTEventSource<TESLockChangedEvent>&					g_lockChangedEventSource;
extern BSTEventSource<TESMagicEffectApplyEvent>&			g_magicEffectApplyEventSource;
extern BSTEventSource<TESMagicWardHitEvent>&				g_magicWardHitEventSource;
extern BSTEventSource<TESMoveAttachDetachEvent>&			g_moveAttachDetachEventSource;
extern BSTEventSource<TESObjectLoadedEvent>&				g_objectLoadedEventSource;
extern BSTEventSource<TESObjectREFRTranslationEvent>&		g_objectREFRTranslationEventSource;
extern BSTEventSource<TESOpenCloseEvent>&					g_openCloseEventSource;
extern BSTEventSource<TESPackageEvent>&						g_packageEventSource;
extern BSTEventSource<TESPerkEntryRunEvent>&				g_perkEntryRunEventSource;
extern BSTEventSource<TESQuestInitEvent>&					g_questInitEventSource;
extern BSTEventSource<TESQuestStageEvent>&					g_questStageEventSource;
extern BSTEventSource<TESQuestStageItemDoneEvent>&			g_questStageItemDoneEventSource;
extern BSTEventSource<TESQuestStartStopEvent>&				g_questStartStopEventSource;
extern BSTEventSource<TESResetEvent>&						g_resetEventSource;
extern BSTEventSource<TESResolveNPCTemplatesEvent>&			g_resolveNPCTemplatesEventSource;
extern BSTEventSource<TESSceneEvent>&						g_sceneEventSource;
extern BSTEventSource<TESSceneActionEvent>&					g_sceneActionEventSource;
extern BSTEventSource<TESScenePhaseEvent>&					g_scenePhaseEventSource;
extern BSTEventSource<TESSellEvent>&						g_sellEventSource;
extern BSTEventSource<TESSleepStartEvent>&					g_sleepStartEventSource;
extern BSTEventSource<TESSleepStopEvent>&					g_sleepStopEventSource;
extern BSTEventSource<TESSpellCastEvent>&					g_spellCastEventSource;
extern BSTEventSource<TESPlayerBowShotEvent>&				g_playerBowShotEventSource;
extern BSTEventSource<TESTopicInfoEvent>&					g_topicInfoEventSource;
extern BSTEventSource<TESTrackedStatsEvent>&				g_trackedStatsEventSource;
extern BSTEventSource<TESTrapHitEvent>&						g_trapHitEventSource;
extern BSTEventSource<TESTriggerEvent>&						g_triggerEventSource;
extern BSTEventSource<TESTriggerEnterEvent>&				g_triggerEnterEventSource;
extern BSTEventSource<TESTriggerLeaveEvent>&				g_triggerLeaveEventSource;
extern BSTEventSource<TESUniqueIDChangeEvent>&				g_uniqueIDChangeEventSource;
extern BSTEventSource<TESWaitStartEvent>&					g_waitStartEventSource;
extern BSTEventSource<TESWaitStopEvent>&					g_waitStopEventSource;
extern BSTEventSource<TESSwitchRaceCompleteEvent>&			g_switchRaceCompleteEventSource;
