#pragma once

// c:_skyrim\code\tesv\bscore\BSTHashMap.h

#include "BSTScatterTable.h"


// 00
template <class Key, class Value, class Table>
struct BSTHashMapTraits
{
	typedef Table	table_type;
};


// 20
template <class Traits>
class BSTHashMapBase :
	public Traits,				// 00
	public Traits::table_type	// 04
{
};


// 20
template <class Key, class Value, template <class, class> class Table = BSTDefaultScatterTable>
class BSTHashMap : public BSTHashMapBase< BSTHashMapTraits<Key, Value, Table<Key, Value>> >
{
	// @members
	//BSTHashMapTraits			pad00;				// 00
	//BSTScatterTableTraits		pad04;				// 04
	//size_type					m_size;				// 08
	//size_type					m_freeCount;		// 0C
	//size_type					m_freeOffset;		// 10
	//entry_type				* m_eolPtr;			// 14 - hash sentinel
	//UInt32					pad18;				// 18
	//entry_type				* m_entries;		// 1C
};


/*==============================================================================
0000: class BSTHashMap<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTDefaultScatterTable>
0000: |   class BSTHashMapBase<struct BSTHashMapTraits<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTDefaultScatterTable<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *> > >
0000: |   |   struct BSTHashMapTraits<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTDefaultScatterTable<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *> >
0004: |   |   struct BSTDefaultScatterTable<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *>
0004: |   |   |   class BSTScatterTable<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage,struct BSTScatterTableDefaultHashPolicy,struct BSTScatterTableHeapAllocator,8>
0004: |   |   |   |   class BSTScatterTableBase<struct BSTScatterTableTraits<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage,struct BSTScatterTableDefaultHashPolicy<unsigned int>,struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage> >,8> >
0004: |   |   |   |   |   class BSTScatterTableKernel<struct BSTScatterTableTraits<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage,struct BSTScatterTableDefaultHashPolicy<unsigned int>,struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage> >,8> >
0004: |   |   |   |   |   |   struct BSTScatterTableTraits<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage,struct BSTScatterTableDefaultHashPolicy<unsigned int>,struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage> >,8>
0005: |   |   |   |   |   |   struct BSTScatterTableDefaultHashPolicy<unsigned int>
0019: |   |   |   |   |   struct BSTScatterTableHeapAllocator<struct BSTScatterTableEntry<unsigned int,class BSTArray<struct SetEventData,class BSTArrayHeapAllocator> const *,struct BSTScatterTableDefaultKVStorage> >
==============================================================================*/

#ifdef _DEBUG

struct DbgHashMap_ : public BSTHashMap<UInt32, void*>
{
	static void _assert_function() {
		STATIC_ASSERT(offsetof(DbgHashMap_, m_size) == 0x08);
		STATIC_ASSERT(offsetof(DbgHashMap_, m_eolPtr) == 0x14);
		STATIC_ASSERT(offsetof(DbgHashMap_, m_entries) == 0x1C);
	}
};
STATIC_ASSERT(sizeof(DbgHashMap_) == 0x20);

#endif
