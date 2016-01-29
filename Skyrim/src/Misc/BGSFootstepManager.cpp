#include "Skyrim/Misc/BGSFootstepManager.h"
#include <new>

DECLARE_BSTSINGLETONSDM_STATIC_INSTANCE(BGSFootstepManager, 0x01B2E9C0, 0x01B380A0);

BGSFootstepManager * BGSFootstepManager::ctor()
{
	new (this) BGSFootstepManager;

	return this;
}
