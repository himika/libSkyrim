#pragma once

#include "NiTMapBase.h"
#include "NiTDefaultAllocator.h"

// 10
template <class TKEY, class TVAL>
class NiTMap : public NiTMapBase<NiTDefaultAllocator<NiTMapItem<TKEY, TVAL>>, TKEY, TVAL>
{
public:
	NiTMap(unsigned int uiHashSize = 37) : NiTMapBase(uiHashSize) {
	}
	~NiTMap() {
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
