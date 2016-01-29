#include "Skyrim.h"
#include "Skyrim/ExtraData/NonActorMagicTarget.h"
#include "Skyrim/Memory.h"

NonActorMagicTarget* NonActorMagicTarget::Create()
{
	NonActorMagicTarget* pThis = FormHeap_Allocate<NonActorMagicTarget>();
	if (pThis)
		pThis->ctor();
	return pThis;
}
