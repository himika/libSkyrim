#include "Skyrim.h"
#include "Skyrim/ExtraData/ExtraEnableStateParent.h"
#include "Skyrim/Forms/TESObjectREFR.h"

TESObjectREFR * ExtraEnableStateParent::GetReference()
{
	TESObjectREFR * reference = nullptr;
	if (handle == (g_invalidRefHandle) || handle == 0)
		return nullptr;

	LookupREFRByHandle(handle, reference);
	return reference;
}
