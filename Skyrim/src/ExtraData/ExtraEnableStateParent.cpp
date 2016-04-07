#include "Skyrim.h"
#include "Skyrim/ExtraData/ExtraEnableStateParent.h"
#include "Skyrim/TESForms/World/TESObjectREFR.h"

TESObjectREFR * ExtraEnableStateParent::GetReference()
{
	TESObjectREFR * reference = nullptr;
	if (handle == (g_invalidRefHandle) || handle == 0)
		return nullptr;

	LookupREFRByHandle(handle, reference);
	return reference;
}
