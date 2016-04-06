#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/TESDescription.h"
#include "../../BSCore/BSFixedString.h"
#include "../../BSCore/BSTArray.h"


/*==============================================================================
class BGSCollisionLayer +0000 (_vtbl=0108A61C)
0000: class BGSCollisionLayer
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESDescription
0014: |   |   class BaseFormComponent
==============================================================================*/
// 3C
class BGSCollisionLayer : public TESForm,
	public TESDescription					// 14
{
public:
	enum { kTypeID = (UInt32)FormType::CollisionLayer };

	enum {
		kCollisionLayer_Unidentified = 0x00,
		kCollisionLayer_Static,
		kCollisionLayer_AnimStatic,
		kCollisionLayer_Transparent,
		kCollisionLayer_Clutter,
		kCollisionLayer_Weapon,
		kCollisionLayer_Projectile,
		kCollisionLayer_Spell,
		kCollisionLayer_Biped,
		kCollisionLayer_Trees,
		kCollisionLayer_Props,
		kCollisionLayer_Water,
		kCollisionLayer_Trigger,
		kCollisionLayer_Terrain,
		kCollisionLayer_Trap,
		kCollisionLayer_NonCollidable,
		kCollisionLayer_CloudTrap,
		kCollisionLayer_Ground,
		kCollisionLayer_Portal,
		kCollisionLayer_DebrisSmall,
		kCollisionLayer_DebrisLarge,
		kCollisionLayer_AcousticSpace,
		kCollisionLayer_ActorZone,
		kCollisionLayer_ProjectileZone,
		kCollisionLayer_GasTrap,
		kCollisionLayer_Shellcasing,
		kCollisionLayer_TransparentSmall,
		kCollisionLayer_InvisibleWall,
		kCollisionLayer_TransparentSmallAnim,
		kCollisionLayer_Ward,
		kCollisionLayer_CharController,
		kCollisionLayer_StairHelper,
		kCollisionLayer_DeadBip,
		kCollisionLayer_BipedNoCC,
		kCollisionLayer_AvoidBox,
		kCollisionLayer_CollisionBox,
		kCollisionLayer_CameraSphere,
		kCollisionLayer_DoorDetection,
		kCollisionLayer_ConeProjectile,
		kCollisionLayer_Camera,
		kCollisionLayer_ItemPicker,
		kCollisionLayer_Los,
		kCollisionLayer_PathingPick,
		kCollisionLayer_CustomPick1,
		kCollisionLayer_CustomPick2,
		kCollisionLayer_SpellExplosion,
		kCollisionLayer_DroppingPick,
		kCollisionLayer_DeadActorZone,
		kCollisionLayer_TriggerFallingTrap,
		kCollisionLayer_Navcut,
		kCollisionLayer_Critter,
		kCollisionLayer_SpellTrigger,
		kCollisionLayer_LivingAndDeadActors,
		kCollisionLayer_Detection,
		kCollisionLayer_TrapTrigger
	};

	// @members
	UInt32							layerId;		// 20
	UInt32							flags;			// 24
	UInt32							unk28;			// 28
	BSFixedString					name;			// 2C
	BSTArray<BGSCollisionLayer *>	interactables;	// 30 - really?
};
STATIC_ASSERT(sizeof(BGSCollisionLayer) == 0x3C);
