#pragma once

#define NiTDefaultAllocator DFALL

template <class Ty>
class NiTDefaultAllocator
{
public:
	void* Allocate() {
		return NiMalloc(sizeof(Ty));
	}
	void Deallocate(void* p) {
		return NiFree(p);
	}

};
