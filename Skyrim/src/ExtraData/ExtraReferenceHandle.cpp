#include "Skyrim.h"
#include "Skyrim/ExtraData/ExtraReferenceHandle.h"
#include "Skyrim/Forms/TESObjectREFR.h"

static const UInt32 s_ExtraReferenceHandleVtbl = 0x01079740;

ExtraReferenceHandle* ExtraReferenceHandle::Create()
{
	ExtraReferenceHandle* xReference = (ExtraReferenceHandle*)BSExtraData::Create(sizeof(ExtraReferenceHandle), s_ExtraReferenceHandleVtbl);
	return xReference;
}


TESObjectREFR * ExtraReferenceHandle::GetReference()
{
	TESObjectREFR * reference = nullptr;
	if (handle == g_invalidRefHandle || handle == 0)
		return nullptr;

	LookupREFRByHandle(handle, reference);
	return reference;
}
