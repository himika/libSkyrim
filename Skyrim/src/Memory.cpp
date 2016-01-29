#include "Skyrim.h"
#include "Skyrim/Memory.h"

Heap * g_formHeap = (Heap *)0x01B418B0;

void * FormHeap_Allocate(UInt32 size)
{
	return g_formHeap->Allocate(size, 0, false);
}

void FormHeap_Free(void * ptr)
{
	g_formHeap->Free(ptr, false);
}
