#include "Skyrim/Animation/AnimationHandlers.h"
#include "Skyrim/Forms/BGSSoundDescriptorForm.h"
#include "Skyrim/Forms/Character/Components/ActorProcessManager.h"


TESObjectWEAP * IHandlerFunctor<Actor, BSFixedStringCI>::GetEquippedWeapon(Actor *actor, UInt32 &hand)
{
#ifndef _IMPLOWN
	return GetEquippedWeapon_Impl(actor, hand);
#else

	ActorProcessManager *pm = actor->processManager;
	if (pm)
	{
		switch (hand)
		{
		case 0:
			return (TESObjectWEAP*)pm->GetEquippedLeftHand();
		case 1:
			return (TESObjectWEAP*)pm->GetEquippedRightHand();
		}
	}

	return nullptr;
#endif
}


bool IHandlerFunctor<Actor, BSFixedStringCI>::SwingWeapon(Actor *actor, UInt32 &hand, IHandlerFunctor* functor)
{
#ifndef _IMPLOWN
	return SwingWeapon_Impl(actor, hand, functor);
#else
	actor->ActorState::flags04 &= 0x0FFFFFFF;
	actor->ActorState::flags04 &= 0x20000000;

	TESObjectWEAP *weap = GetEquippedWeapon(actor, hand);
	if (weap && weap->attackFailSound)
	{
		NiNode *node = actor->GetNiNode();
		PlaySound(weap->attackFailSound, false, &actor->pos, actor->GetNiNode());
	}

	actor->OnWeaponSwing();

	return true;
#endif
}


bool IHandlerFunctor<Actor, BSFixedStringCI>::PlaySound(BGSSoundDescriptorForm *soundForm, UInt32 flags, const NiPoint3 *pos, NiNode *node)
{
#ifndef _IMPLOWN
	return PlaySound_Impl(soundForm, flags, pos, node);
#else
	if (!soundForm)
		return false;

	BGSSoundDescriptor *sound = static_cast<BGSSoundDescriptor*>(soundForm);
	BGSSoundDescriptor::SoundData data;
	sound->SetUp(&data, sound, flags | 0x10);

	if (pos)
		data.SetPosition(*pos);
	if (node)
		data.SetNiNode(node);

	return data.Play();
#endif
}


bool WeaponRightSwingHandler::ExecuteHandler(Actor *actor, BSFixedStringCI *arg2)
{
	UInt32 hand = 1;
	return SwingWeapon(actor, hand, this);
}


bool WeaponLeftSwingHandler::ExecuteHandler(Actor *actor, BSFixedStringCI *arg2)
{
	UInt32 hand = 0;
	return SwingWeapon(actor, hand, this);
}
