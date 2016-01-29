#include "Skyrim.h"
#include "Skyrim/FormComponents/BaseExtraList.h"
#include "Skyrim/Memory.h"
#include "Skyrim/ExtraData/ExtraHealth.h"
#include "Skyrim/ExtraData/ExtraTextDisplayData.h"
#include <string.h>

BSSpinLock & BaseExtraList::ms_lock = *(BSSpinLock*)0x012E32D4;


UInt32 BaseExtraList::ItemsInList() const
{
#ifndef _IMPLOWN
	return ItemsInList_Impl();
#else
	ms_lock.Lock("BaseExtraList::ItemsInList");

	UInt32 count = 0;
	BSExtraData *extra = m_data;
	while (extra)
	{
		++count;
		extra = extra->next;
	}

	ms_lock.Release();

	return count;
#endif
}


BSExtraData* BaseExtraList::AddExtra(BSExtraData *extra)
{
#ifndef _IMPLOWN
	return AddExtra_Impl(extra);
#else
	ms_lock.Lock("BaseExtraList::AddExtra");

	ExtraDataType type = (ExtraDataType)extra->GetType();

	switch (type)
	{
	case ExtraDataType::PersistentCell:
	case ExtraDataType::Action:
	case ExtraDataType::ContainerChanges:
	case ExtraDataType::Teleport:
		// push front
		if (m_data)
			extra->next = m_data;
		m_data = extra;
		break;
	default:
		// push back
		if (!m_data)
			m_data = extra;
		else
		{
			BSExtraData *tail = m_data;
			while (tail->next)
				tail = tail->next;
			tail->next = extra;
		}
		break;
	}

	if (!m_presence)
	{
		m_presence = FormHeap_Allocate<PresenceBitfield>();
		memset(m_presence, 0, 17);
	}
	MarkType(type, false);

	ms_lock.Release();

	return extra;
#endif
}



BSExtraData* BaseExtraList::GetExtraData(UInt32 type) const
{
#ifndef _IMPLOWN
	return GetExtraData_Impl(type);
#else
	if (!HasType(type)) return nullptr;

	BSExtraData *result = nullptr;

	ms_lock.Lock("BaseExtraList::GetExtraData");
	for (BSExtraData *cur = m_data; cur; cur = cur->next)
	{
		if (cur->GetType() == type)
		{
			result = cur;
			break;
		}
	}
	ms_lock.Release();

	return result;
#endif
}


void BaseExtraList::RemoveAll(bool bDelete)
{
	RemoveAll_Impl(bDelete);
}


void BaseExtraList::RemoveAllDefault(bool bDelete)
{
	RemoveAllDefault_Impl(bDelete);
}


bool BaseExtraList::RemoveExtra(UInt32 type)
{
#ifndef _IMPLOWN
	return RemoveExtra1_Impl(type);
#else
	if (!HasType(type))
		return false;

	ms_lock.Lock("BaseExtraList::RemoveExtra");

	bool bRemoved = false;
	BSExtraData *prev = nullptr;
	for (BSExtraData *cur = m_data; cur; cur = cur->next)
	{
		if (cur->GetType() == type)
		{
			if (prev)
				prev->next = cur->next;
			else
				m_data = cur->next;
			delete cur;
			break;
		}

		prev = cur;
	}
	if (bRemoved) {
		MarkType(type, true);
	}

	ms_lock.Release();

	return bRemoved;
#endif
}


void BaseExtraList::RemoveExtra(BSExtraData *toRemove, bool bDelete)
{
	RemoveExtra2_Impl(toRemove, bDelete);
}


void BaseExtraList::RemoveAllCopyableExtra(bool bDelete)
{
	RemoveAllCopyableExtra_Impl(bDelete);
}


BSExtraData* BaseExtraList::GetByType(UInt32 type) const {
	if (!HasType(type)) return nullptr;

	BSExtraData *result = nullptr;

	ms_lock.Lock("BaseExtraList::GetExtraData");
	for (BSExtraData *cur = m_data; cur; cur = cur->next)
	{
		if (cur->GetType() == type)
		{
			result = cur;
			break;
		}
	}
	ms_lock.Unlock();

	return result;
}


bool BaseExtraList::Remove(UInt8 type, BSExtraData* toRemove)
{
	if (!toRemove)
		return false;

	bool bRemoved = false;
	
	if (m_data == toRemove) {
		m_data = m_data->next;
		bRemoved = true;
	}
	else
	{
		for (BSExtraData* traverse = m_data; traverse; traverse = traverse->next) {
			if (traverse->next == toRemove) {
				traverse->next = toRemove->next;
				bRemoved = true;
				break;
			}
		}
	}

	if (bRemoved) {
		MarkType(type, true);
	}

	return true;
}

bool BaseExtraList::Add(UInt8 type, BSExtraData* toAdd)
{
	if (!toAdd || HasType(type)) return false;

	BSExtraData* next = m_data;
	m_data = toAdd;
	toAdd->next = next;
	MarkType(type, false);
	return true;
}


const char * BaseExtraList::GetDisplayName(TESForm * type)
{
	float healthValue = 1.0;

	ExtraHealth* xHealth = GetByType<ExtraHealth>();
	if (xHealth)
		healthValue = xHealth->health;

	ExtraTextDisplayData * xText = GetExtraTextDisplayData();
	if (!xText && healthValue != 1.0)
	{
		xText = ExtraTextDisplayData::Create();
		Add(ExtraDataType::TextDisplayData, xText);
	}

	return ((xText) ? xText->GenerateName(type, healthValue) : nullptr);
}

BSExtraData* BSExtraData::Create(UInt32 size, UInt32 vtbl)
{
	void* memory = FormHeap_Allocate(size);
	memset(memory, 0, size);
	((UInt32*)memory)[0] = vtbl;
	BSExtraData* xData = (BSExtraData*)memory;
	return xData;
}
