#pragma once

template <class Ty>
class NiTPointerAllocator
{
public:
	class AllocNode
	{
	public:
		AllocNode	* next;
		void		* data;
		Ty			m_element;
	};

	void* Allocate() {
		return NiMalloc(sizeof(AllocNode));
	}
	void Deallocate(void* p) {
		return NiFree(p);
	}
};
