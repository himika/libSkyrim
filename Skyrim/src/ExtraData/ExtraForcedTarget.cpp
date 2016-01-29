#include "Skyrim.h"
#include "Skyrim/ExtraData/ExtraForcedTarget.h"
#include "Skyrim/Forms/TESObjectREFR.h"

static const UInt32 s_ExtraForcedTargetVtbl = 0x010797C0;

ExtraForcedTarget* ExtraForcedTarget::Create()
{
	ExtraForcedTarget* xForcedTarget = (ExtraForcedTarget*)BSExtraData::Create(sizeof(ExtraForcedTarget), s_ExtraForcedTargetVtbl);
	xForcedTarget->handle = g_invalidRefHandle;
	return xForcedTarget;
}


TESObjectREFR * ExtraForcedTarget::GetReference()
{
	TESObjectREFR * reference = nullptr;
	if (handle == g_invalidRefHandle || handle == 0)
		return nullptr;

	LookupREFRByHandle(handle, reference);
	return reference;
}
