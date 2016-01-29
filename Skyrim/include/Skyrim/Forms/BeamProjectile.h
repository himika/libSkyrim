#pragma once

#include "Projectile.h"

struct BeamProjectileImpactEvent;
class BSProceduralGeomEvent;

/*==============================================================================
class BeamProjectile +0000 (_vtbl=010D783C)
0000: class BeamProjectile
0000: |   class Projectile
0000: |   |   class TESObjectREFR
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0014: |   |   |   class BSHandleRefObject
0014: |   |   |   |   class NiRefObject
001C: |   |   |   class BSTEventSink<struct BSAnimationGraphEvent>
0020: |   |   |   class IAnimationGraphManagerHolder
0144: |   class BSTEventSource<struct BeamProjectileImpactEvent>
0140: |   class BSTEventSink<class BSProceduralGeomEvent>
==============================================================================*/
// 174
class BeamProjectile : public Projectile,
	public BSTEventSource<BeamProjectileImpactEvent>,	// 144
	public BSTEventSink<BSProceduralGeomEvent>			// 140
{
public:
	enum { kTypeID = (UInt32)FormType::BeamProj };
};
STATIC_ASSERT(sizeof(BeamProjectile) == 0x174);
