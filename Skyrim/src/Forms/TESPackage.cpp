#include "Skyrim.h"
#include "Skyrim/Forms/TESPackage.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

// 005DEFA0 - 1.9.32
bool TESPackage::IsExtraType()
{
	switch (type)
	{
	case kPackageType_Activate:
	case kPackageType_Alarm:
	case kPackageType_Flee:
	case kPackageType_Trespass:
	case kPackageType_Spectator:
	case kPackageType_ReactToDead:
	case kPackageType_DoNothing:
	case kPackageType_InGameDialogue:
	case kPackageType_Surface:
	case kPackageType_AvoidPlayer:
	case kPackageType_ReactToDestroyedObject:
	case kPackageType_ReactToGrenadeOrMine:
	case kPackageType_StealWarning:
	case kPackageType_PickPocketWarning:
	case kPackageType_MovementBlocked:
	case kPackageType_Unk37:
	case kPackageType_Unk38:
		return true;
		break;
	}

	return false;
}
