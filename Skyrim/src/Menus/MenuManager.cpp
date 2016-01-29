#include "Skyrim/Menus/MenuManager.h"
#include "Skyrim/Menus/UIManager.h"

DECLARE_BSTSINGLETONSDM_STATIC_INSTANCE(MenuManager, 0x012E3548, 0x01B3E360);

bool MenuManager::IsMenuOpen(const BSFixedString &menuName) const
{
	return IsMenuOpen_internal(menuName);
}

GFxMovieView * MenuManager::GetMovieView(const BSFixedString &menuName) const
{
	IMenu * menu = GetMenu(menuName);
	if (!menu)
		return NULL;

	return menu->view;
}

IMenu * MenuManager::GetMenu(const BSFixedString &menuName) const
{
	if (!menuName.length())
		return nullptr;

	auto it = menuTable.find(menuName);
	if (it == menuTable.end())
		return nullptr;

	return it->value.menuInstance;
}

void MenuManager::Register(const char *name, CreatorFunc creator)
{
	Register_internal(name, creator);
}


void MenuManager::OpenMenu(const BSFixedString &menuName)
{
	UIManager *ui = UIManager::GetSingleton();
	if (ui)
	{
		ui->AddMessage(menuName, UIMessage::kMessage_Open, nullptr);
	}
}


void MenuManager::CloseMenu(const BSFixedString &menuName)
{
	UIManager *ui = UIManager::GetSingleton();
	if (ui)
	{
		ui->AddMessage(menuName, UIMessage::kMessage_Close, nullptr);
	}
}
