#include "Skyrim/TESForms/World/BGSLocation.h"

UInt32 BGSLocation::GetRefTypeAliveCount(const BGSLocationRefType *locationRefType) const
{
	return GetRefTypeCount_Impl(locationRefType, false, false, false, true, false);
}

UInt32 BGSLocation::GetRefTypeDeadCount(const BGSLocationRefType *locationRefType) const
{
	return GetRefTypeCount_Impl(locationRefType, false, true, false, true, false);
}

bool BGSLocation::HasRefType(const BGSLocationRefType *locationRefType) const
{
	return HasRefType_Impl(locationRefType, false);
}