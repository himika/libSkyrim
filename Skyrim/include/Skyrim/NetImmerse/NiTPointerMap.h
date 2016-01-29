#pragma once

#include "NiTMapBase.h"
#include "NiTPointerAllocator.h"

// 10
template <class TKEY, class TVAL>
class NiTPointerMap : public NiTMapBase<NiTPointerAllocator<std::size_t>, TKEY, TVAL>
{
public:
	NiTPointerMap(std::size_t hashSize = 37) : NiTMapBase(hashSize) {
	}
	~NiTPointerMap() {
		RemoveAll();
	}

protected:
	// @override
	virtual item_type* NewItem() override {
		return (item_type*)m_kAllocator.Allocate();
	}
	virtual void DeleteItem(item_type *item) override {
		item->~item_type();
		m_kAllocator.Deallocate(item);
	}
};
STATIC_ASSERT(sizeof(NiTPointerMap<UInt32, void*>) == 0x10);
