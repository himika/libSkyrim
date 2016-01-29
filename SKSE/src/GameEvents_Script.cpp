#include "SKSE/GameEvents.h"
#include <Skyrim/SkyrimVM.h>

template <>
BSTEventSource<BGSEventProcessedEvent>* SKSEEvent2<BGSEventProcessedEvent>::GetEventSource()
{
	return &g_eventProcessedEventSource;
}
template <>
BSTEventSource<TESActivateEvent>* SKSEEvent2<TESActivateEvent>::GetEventSource()
{
	return &g_activateEventSource;
}
template <>
BSTEventSource<TESActiveEffectApplyRemoveEvent>* SKSEEvent2<TESActiveEffectApplyRemoveEvent>::GetEventSource()
{
	return &g_activeEffectApplyRemoveEventSource;
}
template <>
BSTEventSource<TESActorLocationChangeEvent>* SKSEEvent2<TESActorLocationChangeEvent>::GetEventSource()
{
	return &g_actorLocationChangeEventSource;
}
template <>
BSTEventSource<TESBookReadEvent>* SKSEEvent2<TESBookReadEvent>::GetEventSource()
{
	return &g_bookReadEventSource;
}
template <>
BSTEventSource<TESCellAttachDetachEvent>* SKSEEvent2<TESCellAttachDetachEvent>::GetEventSource()
{
	return &g_cellAttachDetachEventSource;
}
template <>
BSTEventSource<TESCellFullyLoadedEvent>* SKSEEvent2<TESCellFullyLoadedEvent>::GetEventSource()
{
	return &g_cellFullyLoadedEventSource;
}
template <>
BSTEventSource<TESCellReadyToApplyDecalsEvent>* SKSEEvent2<TESCellReadyToApplyDecalsEvent>::GetEventSource()
{
	return &g_cellReadyToApplyDecalsEventSource;
}
template <>
BSTEventSource<TESCombatEvent>* SKSEEvent2<TESCombatEvent>::GetEventSource()
{
	return &g_combatEventSource;
}
template <>
BSTEventSource<TESContainerChangedEvent>* SKSEEvent2<TESContainerChangedEvent>::GetEventSource()
{
	return &g_containerChangedEventSource;
}
template <>
BSTEventSource<TESDeathEvent>* SKSEEvent2<TESDeathEvent>::GetEventSource()
{
	return &g_deathEventSource;
}
template <>
BSTEventSource<TESDestructionStageChangedEvent>* SKSEEvent2<TESDestructionStageChangedEvent>::GetEventSource()
{
	return &g_destructionStageChangedEventSource;
}
template <>
BSTEventSource<TESEnterBleedoutEvent>* SKSEEvent2<TESEnterBleedoutEvent>::GetEventSource()
{
	return &g_enterBleedoutEventSource;
}
template <>
BSTEventSource<TESEquipEvent>* SKSEEvent2<TESEquipEvent>::GetEventSource()
{
	return &g_equipEventSource;
}
template <>
BSTEventSource<TESFormDeleteEvent>* SKSEEvent2<TESFormDeleteEvent>::GetEventSource()
{
	return &g_formDeleteEventSource;
}
template <>
BSTEventSource<TESFurnitureEvent>* SKSEEvent2<TESFurnitureEvent>::GetEventSource()
{
	return &g_furnitureEventSource;
}
template <>
BSTEventSource<TESGrabReleaseEvent>* SKSEEvent2<TESGrabReleaseEvent>::GetEventSource()
{
	return &g_grabReleaseEventSource;
}
template <>
BSTEventSource<TESHitEvent>* SKSEEvent2<TESHitEvent>::GetEventSource()
{
	return &g_hitEventSource;
}
template <>
BSTEventSource<TESInitScriptEvent>* SKSEEvent2<TESInitScriptEvent>::GetEventSource()
{
	return &g_initScriptEventSource;
}
template <>
BSTEventSource<TESLoadGameEvent>* SKSEEvent2<TESLoadGameEvent>::GetEventSource()
{
	return &g_loadGameEventSource;
}
template <>
BSTEventSource<TESLockChangedEvent>* SKSEEvent2<TESLockChangedEvent>::GetEventSource()
{
	return &g_lockChangedEventSource;
}
template <>
BSTEventSource<TESMagicEffectApplyEvent>* SKSEEvent2<TESMagicEffectApplyEvent>::GetEventSource()
{
	return &g_magicEffectApplyEventSource;
}
template <>
BSTEventSource<TESMagicWardHitEvent>* SKSEEvent2<TESMagicWardHitEvent>::GetEventSource()
{
	return &g_magicWardHitEventSource;
}
template <>
BSTEventSource<TESMoveAttachDetachEvent>* SKSEEvent2<TESMoveAttachDetachEvent>::GetEventSource()
{
	return &g_moveAttachDetachEventSource;
}
template <>
BSTEventSource<TESObjectLoadedEvent>* SKSEEvent2<TESObjectLoadedEvent>::GetEventSource()
{
	return &g_objectLoadedEventSource;
}
template <>
BSTEventSource<TESObjectREFRTranslationEvent>* SKSEEvent2<TESObjectREFRTranslationEvent>::GetEventSource()
{
	return &g_objectREFRTranslationEventSource;
}
template <>
BSTEventSource<TESOpenCloseEvent>* SKSEEvent2<TESOpenCloseEvent>::GetEventSource()
{
	return &g_openCloseEventSource;
}
template <>
BSTEventSource<TESPackageEvent>* SKSEEvent2<TESPackageEvent>::GetEventSource()
{
	return &g_packageEventSource;
}
template <>
BSTEventSource<TESPerkEntryRunEvent>* SKSEEvent2<TESPerkEntryRunEvent>::GetEventSource()
{
	return &g_perkEntryRunEventSource;
}
template <>
BSTEventSource<TESQuestInitEvent>* SKSEEvent2<TESQuestInitEvent>::GetEventSource()
{
	return &g_questInitEventSource;
}
template <>
BSTEventSource<TESQuestStageEvent>* SKSEEvent2<TESQuestStageEvent>::GetEventSource()
{
	return &g_questStageEventSource;
}
template <>
BSTEventSource<TESQuestStageItemDoneEvent>* SKSEEvent2<TESQuestStageItemDoneEvent>::GetEventSource()
{
	return &g_questStageItemDoneEventSource;
}
template <>
BSTEventSource<TESQuestStartStopEvent>* SKSEEvent2<TESQuestStartStopEvent>::GetEventSource()
{
	return &g_questStartStopEventSource;
}
template <>
BSTEventSource<TESResetEvent>* SKSEEvent2<TESResetEvent>::GetEventSource()
{
	return &g_resetEventSource;
}
template <>
BSTEventSource<TESResolveNPCTemplatesEvent>* SKSEEvent2<TESResolveNPCTemplatesEvent>::GetEventSource()
{
	return &g_resolveNPCTemplatesEventSource;
}
template <>
BSTEventSource<TESSceneEvent>* SKSEEvent2<TESSceneEvent>::GetEventSource()
{
	return &g_sceneEventSource;
}
template <>
BSTEventSource<TESSceneActionEvent>* SKSEEvent2<TESSceneActionEvent>::GetEventSource()
{
	return &g_sceneActionEventSource;
}
template <>
BSTEventSource<TESScenePhaseEvent>* SKSEEvent2<TESScenePhaseEvent>::GetEventSource()
{
	return &g_scenePhaseEventSource;
}
template <>
BSTEventSource<TESSellEvent>* SKSEEvent2<TESSellEvent>::GetEventSource()
{
	return &g_sellEventSource;
}
template <>
BSTEventSource<TESSleepStartEvent>* SKSEEvent2<TESSleepStartEvent>::GetEventSource()
{
	return &g_sleepStartEventSource;
}
template <>
BSTEventSource<TESSleepStopEvent>* SKSEEvent2<TESSleepStopEvent>::GetEventSource()
{
	return &g_sleepStopEventSource;
}
template <>
BSTEventSource<TESSpellCastEvent>* SKSEEvent2<TESSpellCastEvent>::GetEventSource()
{
	return &g_spellCastEventSource;
}
template <>
BSTEventSource<TESPlayerBowShotEvent>* SKSEEvent2<TESPlayerBowShotEvent>::GetEventSource()
{
	return &g_playerBowShotEventSource;
}
template <>
BSTEventSource<TESTopicInfoEvent>* SKSEEvent2<TESTopicInfoEvent>::GetEventSource()
{
	return &g_topicInfoEventSource;
}
template <>
BSTEventSource<TESTrackedStatsEvent>* SKSEEvent2<TESTrackedStatsEvent>::GetEventSource()
{
	return &g_trackedStatsEventSource;
}
template <>
BSTEventSource<TESTrapHitEvent>* SKSEEvent2<TESTrapHitEvent>::GetEventSource()
{
	return &g_trapHitEventSource;
}
template <>
BSTEventSource<TESTriggerEvent>* SKSEEvent2<TESTriggerEvent>::GetEventSource()
{
	return &g_triggerEventSource;
}
template <>
BSTEventSource<TESTriggerEnterEvent>* SKSEEvent2<TESTriggerEnterEvent>::GetEventSource()
{
	return &g_triggerEnterEventSource;
}
template <>
BSTEventSource<TESTriggerLeaveEvent>* SKSEEvent2<TESTriggerLeaveEvent>::GetEventSource()
{
	return &g_triggerLeaveEventSource;
}
template <>
BSTEventSource<TESUniqueIDChangeEvent>* SKSEEvent2<TESUniqueIDChangeEvent>::GetEventSource()
{
	return &g_uniqueIDChangeEventSource;
}
template <>
BSTEventSource<TESWaitStartEvent>* SKSEEvent2<TESWaitStartEvent>::GetEventSource()
{
	return &g_waitStartEventSource;
}
template <>
BSTEventSource<TESWaitStopEvent>* SKSEEvent2<TESWaitStopEvent>::GetEventSource()
{
	return &g_waitStopEventSource;
}
template <>
BSTEventSource<TESSwitchRaceCompleteEvent>* SKSEEvent2<TESSwitchRaceCompleteEvent>::GetEventSource()
{
	return &g_switchRaceCompleteEventSource;
}

//=============================================================================================

template <>
BSTEventSource<SkyrimScript::StatsEvent>* SKSEEvent2<SkyrimScript::StatsEvent>::GetEventSource()
{
	return g_skyrimVM ? static_cast<BSTEventSource<SkyrimScript::StatsEvent> *>(g_skyrimVM) : nullptr;
}
