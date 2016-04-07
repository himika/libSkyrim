#include "Skyrim.h"
#include "Skyrim/TESForms/Character/BGSScene.h"
#include "Skyrim/TESForms/Character/TESQuest.h"

void BGSScene::ForceStart(void)
{
	if (GetOwningQuest()->IsRunning())
		ForceStart_impl();
}

void BGSScene::Start(void)
{
	if (GetOwningQuest()->IsRunning())
		StartStop_impl(1);
}

void BGSScene::Stop(void)
{
	StartStop_impl(0);
}
