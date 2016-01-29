#include "Skyrim.h"
#include "Skyrim/NetImmerse/NiMemory.h"
#include "Skyrim/Memory.h"

void* NiMalloc(std::size_t size)
{
	return FormHeap_Allocate(size);
}


void NiFree(void* p)
{
	FormHeap_Free(p);
}
