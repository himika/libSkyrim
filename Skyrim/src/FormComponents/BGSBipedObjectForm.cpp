#include "Skyrim.h"
#include "Skyrim/FormComponents/BGSBipedObjectForm.h"


UInt32 BGSBipedObjectForm::AddSlotToMask(UInt32 slot)
{
	bipedObjectData.parts |= slot;
	return bipedObjectData.parts;
}

UInt32 BGSBipedObjectForm::RemoveSlotFromMask(UInt32 slot)
{
	bipedObjectData.parts &= ~slot;
	return bipedObjectData.parts;
}
