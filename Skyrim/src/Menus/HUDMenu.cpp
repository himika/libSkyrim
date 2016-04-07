#include "Skyrim/Menus/HUDMenu.h"
#include "Skyrim/TESForms/World/PlayerCharacter.h"

HUDObject::HUDObject(GFxMovieView *movie)
{
	if (movie)
		movie->AddRef();
	view = movie;
}

HUDObject::~HUDObject(void)
{
	if (view)
		view->ForceCollectGarbage();
}

TESObjectREFR * EnemyHealth::GetTarget() const
{
	TESObjectREFR * refr = nullptr;
	RefHandle refHandle = g_thePlayer->targetHandle;

	TESObjectREFR::LookupByHandle(refHandle, refr);
	if (!refr)
	{
		refHandle = handle;
		TESObjectREFR::LookupByHandle(refHandle, refr);
	}

	return refr;
}


IMenu * HUDMenu::Create()
{
	typedef IMenu* (*FnMenuConstructor)(void);

	return ((FnMenuConstructor)0x00865F50)();
}
