#include "SKSE/GameEvents.h"
#include <Skyrim/BSDevices/InputManager.h>
#include <Skyrim/Menus/MenuManager.h>
#include <Skyrim/Events/DefaultObjectsReadyEvent.h>


template <>
BSTEventSource<InputEvent *>* SKSEEvent2<InputEvent *>::GetEventSource()
{
	return InputManager::GetSingleton();
}


template <>
BSTEventSource<MenuOpenCloseEvent>* SKSEEvent2<MenuOpenCloseEvent>::GetEventSource()
{
	MenuManager *mm = MenuManager::GetSingleton();
	return (mm) ? mm->GetMenuOpenCloseEventSource() : nullptr;
}


template <>
BSTEventSource<MenuModeChangeEvent>* SKSEEvent2<MenuModeChangeEvent>::GetEventSource()
{
	MenuManager *mm = MenuManager::GetSingleton();
	return (mm) ? mm->GetMenuModeChangeEventSource() : nullptr;
}


template <>
BSTEventSource<DefaultObjectsReadyEvent::Event>* SKSEEvent2<DefaultObjectsReadyEvent::Event>::GetEventSource()
{
	return DefaultObjectsReadyEvent::GetEventSource();
}
