#include "Skyrim.h"
#include "Skyrim/ExtraData/ExtraLinkedRef.h"

static const UInt32 s_ExtraLinkedRefVtbl = 0x01079AF8;

ExtraLinkedRef* ExtraLinkedRef::Create()
{
	ExtraLinkedRef* xLinkedRef = (ExtraLinkedRef*)BSExtraData::Create(sizeof(ExtraLinkedRef), s_ExtraLinkedRefVtbl);
	return xLinkedRef;
}
