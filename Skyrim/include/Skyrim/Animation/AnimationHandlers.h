#pragma once

#include "../BSSystem/IHandlerFunctor.h"
#include "../Forms/Actor.h"
#include "../Forms/TESObjectWEAP.h"
#include "../BSCore/BSFixedString.h"


/*==============================================================================
class IHandlerFunctor<class Actor,class BSFixedStringCI> +0000 (_vtbl=010D5408)
0000: class IHandlerFunctor<class Actor,class BSFixedStringCI>
0004: |   struct BSIntrusiveRefCounted
==============================================================================*/
// 08
template <>
class IHandlerFunctor<Actor, BSFixedStringCI> : public BSIntrusiveRefCounted
{
public:
	virtual ~IHandlerFunctor() {}
	virtual bool ExecuteHandler(Actor *actor, BSFixedStringCI *arg2) = 0;

protected:
	static TESObjectWEAP * GetEquippedWeapon(Actor *actor, UInt32 &hand);
	static bool SwingWeapon(Actor *actor, UInt32 &hand, IHandlerFunctor* functor);	// 00780920
	static bool PlaySound(BGSSoundDescriptorForm *sound, UInt32 flag, const NiPoint3 *pos, NiNode *node);

	DEFINE_STATIC_FN(GetEquippedWeapon_Impl,	TESObjectWEAP *,	0x00780920,	Actor *actor, UInt32 &hand);
	DEFINE_STATIC_FN(PlaySound_Impl,			bool,				0x00653A60,	BGSSoundDescriptorForm *sound, UInt32 flag, const NiPoint3 *pos, NiNode *node);
	DEFINE_STATIC_FN(SwingWeapon_Impl,			bool,				0x00780920,	Actor *actor, UInt32 &hand, IHandlerFunctor* functor);
};


/*==============================================================================
class WeaponRightSwingHandler +0000 (_vtbl=010D5414)
0000: class WeaponRightSwingHandler
0000: |   class IHandlerFunctor<class Actor,class BSFixedStringCI>
0004: |   |   struct BSIntrusiveRefCounted
==============================================================================*/
class WeaponRightSwingHandler : public IHandlerFunctor<Actor, BSFixedStringCI>
{
public:
	// @override class IHandlerFunctor<class Actor,class BSFixedStringCI> : (vtbl=010D5414)
	virtual bool ExecuteHandler(Actor *actor, BSFixedStringCI *arg2) override;		// 00780980
};

/*==============================================================================
class WeaponLeftSwingHandler +0000 (_vtbl=010D5420)
0000: class WeaponLeftSwingHandler
0000: |   class IHandlerFunctor<class Actor,class BSFixedStringCI>
0004: |   |   struct BSIntrusiveRefCounted
==============================================================================*/
class WeaponLeftSwingHandler : public IHandlerFunctor<Actor, BSFixedStringCI>
{
public:
	// @override class IHandlerFunctor<class Actor,class BSFixedStringCI> : (vtbl=010D5420)
	virtual bool ExecuteHandler(Actor *actor, BSFixedStringCI *arg2) override;		// 007809A0
};
