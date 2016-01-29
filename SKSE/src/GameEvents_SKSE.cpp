#include "SKSE/GameEvents.h"
#include "SKSE/PluginAPI.h"


template <>
BSTEventSource<SKSEModCallbackEvent>* SKSEEvent2<SKSEModCallbackEvent>::GetEventSource()
{
	const SKSEPlugin *plugin = SKSEPlugin::GetSingleton();
	if (!plugin)
		return nullptr;
	
	const SKSEMessagingInterface *mes = plugin->GetInterface(SKSEMessagingInterface::Version_1);
	if (!mes)
		return nullptr;

	return mes->GetEventDispatcher<SKSEModCallbackEvent>();
}

template <>
BSTEventSource<SKSECameraEvent>* SKSEEvent2<SKSECameraEvent>::GetEventSource()
{
	const SKSEPlugin *plugin = SKSEPlugin::GetSingleton();
	if (!plugin)
		return nullptr;

	const SKSEMessagingInterface *mes = plugin->GetInterface(SKSEMessagingInterface::Version_1);
	if (!mes)
		return nullptr;

	return mes->GetEventDispatcher<SKSECameraEvent>();
}

template <>
BSTEventSource<SKSECrosshairRefEvent>* SKSEEvent2<SKSECrosshairRefEvent>::GetEventSource()
{
	const SKSEPlugin *plugin = SKSEPlugin::GetSingleton();
	if (!plugin)
		return nullptr;

	const SKSEMessagingInterface *mes = plugin->GetInterface(SKSEMessagingInterface::Version_1);
	if (!mes)
		return nullptr;

	return mes->GetEventDispatcher<SKSECrosshairRefEvent>();
}

template <>
BSTEventSource<SKSEActionEvent>* SKSEEvent2<SKSEActionEvent>::GetEventSource()
{
	const SKSEPlugin *plugin = SKSEPlugin::GetSingleton();
	if (!plugin)
		return nullptr;

	const SKSEMessagingInterface *mes = plugin->GetInterface(SKSEMessagingInterface::Version_2);
	if (!mes)
		return nullptr;

	return mes->GetEventDispatcher<SKSEActionEvent>();
}

template <>
BSTEventSource<SKSENiNodeUpdateEvent>* SKSEEvent2<SKSENiNodeUpdateEvent>::GetEventSource()
{
	const SKSEPlugin *plugin = SKSEPlugin::GetSingleton();
	if (!plugin)
		return nullptr;

	const SKSEMessagingInterface *mes = plugin->GetInterface(SKSEMessagingInterface::Version_1);
	if (!mes)
		return nullptr;

	return mes->GetEventDispatcher<SKSENiNodeUpdateEvent>();
}
