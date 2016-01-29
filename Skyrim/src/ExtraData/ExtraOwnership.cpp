#include "Skyrim.h"
#include "Skyrim/ExtraData/ExtraOwnership.h"
#include "Skyrim/Memory.h"

static const UInt32 s_ExtraOwnershipVtbl = 0x01079188;

ExtraOwnership* ExtraOwnership::Create(TESForm *owner)
{
	ExtraOwnership *p = FormHeap_Allocate<ExtraOwnership>();
	if (p)
		p->ctor(owner);
	return p;
}
