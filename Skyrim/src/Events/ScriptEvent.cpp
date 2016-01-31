#include "Skyrim/Events/ScriptEvent.h"

// 9F0
struct ScriptEventSourceHolder :
	public BSTEventSource<BGSEventProcessedEvent>,				// 000
	public BSTEventSource<TESActivateEvent>,					// 030
	public BSTEventSource<TESActiveEffectApplyRemoveEvent>,		// 060
	public BSTEventSource<TESActorLocationChangeEvent>,			// 090
	public BSTEventSource<TESBookReadEvent>,					// 0C0
	public BSTEventSource<TESCellAttachDetachEvent>,			// 0F0
	public BSTEventSource<TESCellFullyLoadedEvent>,				// 120
	public BSTEventSource<TESCellReadyToApplyDecalsEvent>,		// 
	public BSTEventSource<TESCombatEvent>,						// 
	public BSTEventSource<TESContainerChangedEvent>,			// 
	public BSTEventSource<TESDeathEvent>,						// 
	public BSTEventSource<TESDestructionStageChangedEvent>,		// 
	public BSTEventSource<TESEnterBleedoutEvent>,				// 
	public BSTEventSource<TESEquipEvent>,						// 
	public BSTEventSource<TESFormDeleteEvent>,					// 
	public BSTEventSource<TESFurnitureEvent>,					// 
	public BSTEventSource<TESGrabReleaseEvent>,					// 
	public BSTEventSource<TESHitEvent>,							// 
	public BSTEventSource<TESInitScriptEvent>,					// 
	public BSTEventSource<TESLoadGameEvent>,					//
	public BSTEventSource<TESLockChangedEvent>,
	public BSTEventSource<TESMagicEffectApplyEvent>,
	public BSTEventSource<TESMagicWardHitEvent>,
	public BSTEventSource<TESMoveAttachDetachEvent>,
	public BSTEventSource<TESObjectLoadedEvent>,
	public BSTEventSource<TESObjectREFRTranslationEvent>,
	public BSTEventSource<TESOpenCloseEvent>,
	public BSTEventSource<TESPackageEvent>,
	public BSTEventSource<TESPerkEntryRunEvent>,
	public BSTEventSource<TESQuestInitEvent>,
	public BSTEventSource<TESQuestStageEvent>,
	public BSTEventSource<TESQuestStageItemDoneEvent>,
	public BSTEventSource<TESQuestStartStopEvent>,
	public BSTEventSource<TESResetEvent>,
	public BSTEventSource<TESResolveNPCTemplatesEvent>,
	public BSTEventSource<TESSceneEvent>,
	public BSTEventSource<TESSceneActionEvent>,
	public BSTEventSource<TESScenePhaseEvent>,
	public BSTEventSource<TESSellEvent>,
	public BSTEventSource<TESSleepStartEvent>,
	public BSTEventSource<TESSleepStopEvent>,
	public BSTEventSource<TESSpellCastEvent>,
	public BSTEventSource<TESPlayerBowShotEvent>,
	public BSTEventSource<TESTopicInfoEvent>,						// 810
	public BSTEventSource<TESTrackedStatsEvent>,					// 840
	public BSTEventSource<TESTrapHitEvent>,							// 870
	public BSTEventSource<TESTriggerEvent>,							// 8A0
	public BSTEventSource<TESTriggerEnterEvent>,					// 8D0
	public BSTEventSource<TESTriggerLeaveEvent>,					// 900
	public BSTEventSource<TESUniqueIDChangeEvent>,					// 930
	public BSTEventSource<TESWaitStartEvent>,						// 960
	public BSTEventSource<TESWaitStopEvent>,						// 990
	public BSTEventSource<TESSwitchRaceCompleteEvent>				// 9C0
{
	static inline ScriptEventSourceHolder* GetInstance(void) {
		return (ScriptEventSourceHolder*)0x012E4C30;
	}

	template <class EventT>
	static inline BSTEventSource<EventT>* GetEventSource() {
		return static_cast<BSTEventSource<EventT>*>(GetInstance());
	}

private:
	DEFINE_MEMBER_FN(ctor, ScriptEventSourceHolder*, 0x00436B90);
	//DEFINE_MEMBER_FN(SendTopicInfoEvent, void, 0x0057DDD0, FormID topicInfoID, ActorPtr &speaker, UInt32 flag, BSTSmartPointer<REFREventCallbacks::IEventCallback> &arg4);
};
STATIC_ASSERT(sizeof(ScriptEventSourceHolder) == 0x9F0);


#define DECLARE_EVENT_SOURCE(name, g_name) \
	BSTEventSource<name>& g_name = *ScriptEventSourceHolder::GetEventSource<name>();

DECLARE_EVENT_SOURCE(BGSEventProcessedEvent, g_eventProcessedEventSource);
DECLARE_EVENT_SOURCE(TESActivateEvent, g_activateEventSource);
DECLARE_EVENT_SOURCE(TESActiveEffectApplyRemoveEvent, g_activeEffectApplyRemoveEventSource);
DECLARE_EVENT_SOURCE(TESActorLocationChangeEvent, g_actorLocationChangeEventSource);
DECLARE_EVENT_SOURCE(TESBookReadEvent, g_bookReadEventSource);
DECLARE_EVENT_SOURCE(TESCellAttachDetachEvent, g_cellAttachDetachEventSource);
DECLARE_EVENT_SOURCE(TESCellFullyLoadedEvent, g_cellFullyLoadedEventSource);
DECLARE_EVENT_SOURCE(TESCellReadyToApplyDecalsEvent, g_cellReadyToApplyDecalsEventSource);
DECLARE_EVENT_SOURCE(TESCombatEvent, g_combatEventSource);
DECLARE_EVENT_SOURCE(TESContainerChangedEvent, g_containerChangedEventSource);
DECLARE_EVENT_SOURCE(TESDeathEvent, g_deathEventSource);
DECLARE_EVENT_SOURCE(TESDestructionStageChangedEvent, g_destructionStageChangedEventSource);
DECLARE_EVENT_SOURCE(TESEnterBleedoutEvent, g_enterBleedoutEventSource);
DECLARE_EVENT_SOURCE(TESEquipEvent, g_equipEventSource);
DECLARE_EVENT_SOURCE(TESFormDeleteEvent, g_formDeleteEventSource);
DECLARE_EVENT_SOURCE(TESFurnitureEvent, g_furnitureEventSource);
DECLARE_EVENT_SOURCE(TESGrabReleaseEvent, g_grabReleaseEventSource);
DECLARE_EVENT_SOURCE(TESHitEvent, g_hitEventSource);
DECLARE_EVENT_SOURCE(TESInitScriptEvent, g_initScriptEventSource);
DECLARE_EVENT_SOURCE(TESLoadGameEvent, g_loadGameEventSource);
DECLARE_EVENT_SOURCE(TESLockChangedEvent, g_lockChangedEventSource);
DECLARE_EVENT_SOURCE(TESMagicEffectApplyEvent, g_magicEffectApplyEventSource);
DECLARE_EVENT_SOURCE(TESMagicWardHitEvent, g_magicWardHitEventSource);
DECLARE_EVENT_SOURCE(TESMoveAttachDetachEvent, g_moveAttachDetachEventSource);
DECLARE_EVENT_SOURCE(TESObjectLoadedEvent, g_objectLoadedEventSource);
DECLARE_EVENT_SOURCE(TESObjectREFRTranslationEvent, g_objectREFRTranslationEventSource);
DECLARE_EVENT_SOURCE(TESOpenCloseEvent, g_openCloseEventSource);
DECLARE_EVENT_SOURCE(TESPackageEvent, g_packageEventSource);
DECLARE_EVENT_SOURCE(TESPerkEntryRunEvent, g_perkEntryRunEventSource);
DECLARE_EVENT_SOURCE(TESQuestInitEvent, g_questInitEventSource);
DECLARE_EVENT_SOURCE(TESQuestStageEvent, g_questStageEventSource);
DECLARE_EVENT_SOURCE(TESQuestStageItemDoneEvent, g_questStageItemDoneEventSource);
DECLARE_EVENT_SOURCE(TESQuestStartStopEvent, g_questStartStopEventSource);
DECLARE_EVENT_SOURCE(TESResetEvent, g_resetEventSource);
DECLARE_EVENT_SOURCE(TESResolveNPCTemplatesEvent, g_resolveNPCTemplatesEventSource);
DECLARE_EVENT_SOURCE(TESSceneEvent, g_sceneEventSource);
DECLARE_EVENT_SOURCE(TESSceneActionEvent, g_sceneActionEventSource);
DECLARE_EVENT_SOURCE(TESScenePhaseEvent, g_scenePhaseEventSource);
DECLARE_EVENT_SOURCE(TESSellEvent, g_sellEventSource);
DECLARE_EVENT_SOURCE(TESSleepStartEvent, g_sleepStartEventSource);
DECLARE_EVENT_SOURCE(TESSleepStopEvent, g_sleepStopEventSource);
DECLARE_EVENT_SOURCE(TESSpellCastEvent, g_spellCastEventSource);
DECLARE_EVENT_SOURCE(TESPlayerBowShotEvent, g_playerBowShotEventSource);
DECLARE_EVENT_SOURCE(TESTopicInfoEvent, g_topicInfoEventSource);
DECLARE_EVENT_SOURCE(TESTrackedStatsEvent, g_trackedStatsEventSource);
DECLARE_EVENT_SOURCE(TESTrapHitEvent, g_trapHitEventSource);
DECLARE_EVENT_SOURCE(TESTriggerEvent, g_triggerEventSource);
DECLARE_EVENT_SOURCE(TESTriggerEnterEvent, g_triggerEnterEventSource);
DECLARE_EVENT_SOURCE(TESTriggerLeaveEvent, g_triggerLeaveEventSource);
DECLARE_EVENT_SOURCE(TESUniqueIDChangeEvent, g_uniqueIDChangeEventSource);
DECLARE_EVENT_SOURCE(TESWaitStartEvent, g_waitStartEventSource);
DECLARE_EVENT_SOURCE(TESWaitStopEvent, g_waitStopEventSource);
DECLARE_EVENT_SOURCE(TESSwitchRaceCompleteEvent, g_switchRaceCompleteEventSource);

#undef DECLARE_EVENT_SOURCE
