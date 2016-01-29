#pragma once

#include "Projectile.h"

/*==============================================================================
class ConeProjectile +0000 (_vtbl=010D7BC4)
0000: class ConeProjectile
0000: |   class Projectile
0000: |   |   class TESObjectREFR
0000: |   |   |   class TESForm
0000: |   |   |   |   class BaseFormComponent
0014: |   |   |   class BSHandleRefObject
0014: |   |   |   |   class NiRefObject
001C: |   |   |   class BSTEventSink<struct BSAnimationGraphEvent>
0020: |   |   |   class IAnimationGraphManagerHolder
==============================================================================*/
// 16C
class ConeProjectile : public Projectile
{
public:
	enum { kTypeID = (UInt32)FormType::ConeProj };
};
