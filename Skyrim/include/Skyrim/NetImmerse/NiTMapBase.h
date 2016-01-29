#pragma once

#include "NiMemory.h"


template <class TKEY, class TVAL>
class NiTMapItem
{
public:
	typedef TKEY key_type;
	typedef TVAL value_type;

	// @members
	NiTMapItem	* next;
	key_type	key;
	value_type	value;
};


template <class TheAllocator, class TKEY, class TVAL>
class NiTMapBase
{
public:
	typedef TKEY					key_type;
	typedef TVAL					value_type;
	typedef NiTMapItem<TKEY, TVAL>	item_type;

	struct AntiBloatAllocator : public TheAllocator
	{
		// @members
		unsigned int m_uiCount;
	};

	NiTMapBase(std::size_t hashSize = 37) {
		m_uiHashSize = hashSize;
		m_kAllocator.m_uiCount = 0;

		std::size_t tableSize = sizeof(item_type*) * m_uiHashSize;
		m_ppkHashTable = (item_type**)NiMalloc(tableSize);

		memset(m_ppkHashTable, 0, tableSize);
	}
	virtual ~NiTMapBase() {
		RemoveAll();
		NiFree(m_ppkHashTable);
	}

protected:
	virtual	std::size_t		KeyToHashIndex(key_type key) const;								// 01 - return hash % m_uiHashSize;
	virtual	bool			IsKeysEqual(key_type lhs, key_type rhs) const;					// 02 - return lhs == rhs;

	virtual	void			SetValue(item_type *item, key_type key, value_type value);		// 03 - item->key = key; item->value = value;
	virtual void			ClearValue(item_type *item);									// 04 - nop
	virtual	item_type *		NewItem() = 0;													// 05 - return new item_type;
	virtual	void			DeleteItem(item_type *item) = 0;								// 06 - item->value = 0; delete item;

public:
	// counting elements in map
	unsigned int GetCount() const {
		return m_kAllocator.m_uiCount;
	}
	bool IsEmpty() const {
		return m_kAllocator.m_uiCount == 0;
	}

	// add or remove elements
	void SetAt(TKEY key, TVAL val) {
		// look up hash table location for key
		unsigned int uiIndex = KeyToHashIndex(key);
		item_type *pkItem = m_ppkHashTable[uiIndex];

		unsigned int uiDepth = 0;


		// search list at hash table location for key
		while (pkItem)
		{
			uiDepth++;
			if (IsKeysEqual(key, pkItem->key))
			{
				// item already in hash table, set its new value
				pkItem->val = val;
				return;
			}
			pkItem = pkItem->next;
		}

		// add object to beginning of list for this hash table index
		pkItem = (item_type*)NewItem();

		NIASSERT(pkItem);
		SetValue(pkItem, key, val);
		pkItem->next = m_ppkHashTable[uiIndex];
		m_ppkHashTable[uiIndex] = pkItem;
		m_kAllocator.m_uiCount++;
	}

	bool RemoveAt(TKEY key) {
		// look up hash table location for key
		unsigned int uiIndex = KeyToHashIndex(key);
		item_type* pkItem = m_ppkHashTable[uiIndex];

		// search list at hash table location for key
		if (pkItem)
		{
			if (IsKeysEqual(key, pkItem->key))
			{
				// item at front of list, remove it
				m_ppkHashTable[uiIndex] = pkItem->next;
				ClearValue(pkItem);

				DeleteItem(pkItem);

				m_kAllocator.m_uiCount--;
				return true;
			}
			else
			{
				// search rest of list for item
				item_type* pkPrev = pkItem;
				item_type* pkCurr = pkPrev->next;
				while (pkCurr && !IsKeysEqual(key, pkCurr->key))
				{
					pkPrev = pkCurr;
					pkCurr = pkCurr->next;
				}
				if (pkCurr)
				{
					// found the item, remove it
					pkPrev->next = pkCurr->next;
					ClearValue(pkCurr);

					DeleteItem(pkCurr);

					m_kAllocator.m_uiCount--;
					return true;
				}
			}
		}

		return false;
	}

	void RemoveAll() {
		for (unsigned int i = 0; i < m_uiHashSize; i++)
		{
			while (m_ppkHashTable[i])
			{
				item_type* pkSave = m_ppkHashTable[i];
				m_ppkHashTable[i] = m_ppkHashTable[i]->next;
				ClearValue(pkSave);

				DeleteItem(pkSave);
			}
		}

		m_kAllocator.m_uiCount = 0;
	}

	// element access
	bool GetAt(key_type key, value_type& val) const {
		std::size_t idx = KeyToHashIndex(key);
		for (item_type *p = m_ppkHashTable[idx]; p; p = p->next) {
			if (IsKeysEqual(key, p->key)) {
				val = p->value;
				return true;
			}
		}

		return false;
	}

	// map traversal
	//NiTMapIterator GetFirstPos() const;
	//void GetNext(NiTMapIterator& pos, TKEY& key, TVAL& val) const;

protected:
	// @members
	//void				** _vtbl;			// 00
	std::size_t			m_uiHashSize;		// 04
	item_type **		m_ppkHashTable;		// 08 - hash table storage
	AntiBloatAllocator	m_kAllocator;		// 0C

private:
	// hide
	NiTMapBase(const NiTMapBase &);
	NiTMapBase& operator=(const NiTMapBase &);
};
