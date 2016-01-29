#pragma once

void* NiMalloc(std::size_t size);
void NiFree(void* p);

template <class T>
class NiTMallocInterface
{
public:
	static T* Allocate(unsigned int uiNumElements)
	{
		return NiMalloc(sizeof(T) * uiNumElements);
	};
	static void Deallocate(T* pArray)
	{
		NiFree(pArray);
	};
};

template <class T>
class NiTNewInterface
{
public:
	static T* Allocate(unsigned int uiNumElements)
	{
		return new T[uiNumElements];
	};
	static void Deallocate(T* pArray)
	{
		delete[] pArray;
	};
};
