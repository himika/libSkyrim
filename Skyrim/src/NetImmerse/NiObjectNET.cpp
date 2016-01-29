#include "Skyrim/NetImmerse/NiObjectNET.h"
#include "Skyrim/NetImmerse/NiRTTI.h"
#include "Skyrim/NetImmerse/NiExtraData.h"
#include "Skyrim/Memory.h"
#include <cstdlib>
#include <string>


#define NiAlloc(T, count)	((T*)FormHeap_Allocate(sizeof(T)*(count)))
#define NiFree(p)			FormHeap_Free(p)


bool NiObjectNET::InsertExtraData(NiExtraData* pkExtra)
{
	if (!pkExtra)
	{
		return false;
	}

	pkExtra->IncRefCount();

	if (m_extraDataCapacity < 1)
	{
		m_extraDataLen = m_extraDataCapacity = 1;
		m_extraData = NiAlloc(NiExtraData*, m_extraDataCapacity);
		m_extraData[0] = pkExtra;
		return true;
	}
	else if (m_extraDataLen == m_extraDataCapacity) // Array is full. Increase size.
	{
		m_extraDataCapacity = (m_extraDataCapacity * 2) + 1; // Balance memory fragmentation with storage efficiency.
		NiExtraData** ppkNewExtra = NiAlloc(NiExtraData*, m_extraDataCapacity);

		unsigned int uiDestSize = m_extraDataCapacity * sizeof(NiExtraData*);
		memcpy_s(ppkNewExtra, uiDestSize, m_extraData, m_extraDataLen * sizeof(NiExtraData*));

		NiFree(m_extraData);
		m_extraData = ppkNewExtra;
	}

	std::size_t i;

	// Insert new entry.
	m_extraData[m_extraDataLen] = pkExtra;
	m_extraDataLen++;

	for (i = m_extraDataLen; i < m_extraDataCapacity; i++)
	{
		m_extraData[i] = NULL;
	}

	// Sort.
	for (i = (m_extraDataLen - 1); i > 0; i--)
	{
		std::ptrdiff_t dtCompare = m_extraData[i - 1]->GetName() - m_extraData[i]->GetName();

		if (dtCompare == 0)  // Equal keys are a problem.  Reset.
		{
			DeleteExtraData(i);
			return false;
		}
		else if (dtCompare > 0)  // Previous key is greater.  Swap.
		{
			NiExtraData* pkTmpED = m_extraData[i - 1];
			m_extraData[i - 1] = m_extraData[i];
			m_extraData[i] = pkTmpED;
		}
		else    // Array is sorted.  Discontinue processing.
		{
			break;
		}
	}

	return true;
}


void NiObjectNET::DeleteExtraData(UInt16 usExtraDataIndex)
{
	if (usExtraDataIndex >= m_extraDataLen)  // Sanity check.
	{
		return;
	}

	if (m_extraData[usExtraDataIndex])
	{
		m_extraData[usExtraDataIndex]->DecRefCount();
	}

	// Shuffle downward.
	for (std::size_t i = usExtraDataIndex; i < (m_extraDataLen - 1); i++)
	{
		m_extraData[i] = m_extraData[i + 1];
	}

	m_extraDataLen--;
	m_extraData[m_extraDataLen] = NULL;
}


bool NiObjectNET::AddExtraData(NiExtraData* extraData)	// 00AB44C0
{
	if (!extraData)
		return false;

	if (!extraData->GetName())	// auto naming
	{
		const char* rttiName = extraData->GetRTTI()->GetName();

		if (rttiName && (strlen(rttiName) > 0))
		{
			char buff[6];
			sprintf_s(buff, "ED%03d", m_extraDataLen);

			std::size_t uiStrLength = 0;
			const char* pcSubstr = strstr(rttiName, "ExtraData");
			if (pcSubstr > rttiName)
				uiStrLength = pcSubstr - rttiName;

			std::size_t keyLength = uiStrLength + strlen(buff) + 1;
			char* key = NiAlloc(char, keyLength);

			strncpy_s(key, keyLength, rttiName, uiStrLength);
			strcat_s(key, keyLength, buff);

			extraData->SetName(key);

			NiFree(key);
		}
	}

	return InsertExtraData(extraData);
}





SInt32 NiObjectNET::GetIndexOf(NiExtraData * extraData)
{
	if (!extraData)
		return -1;
	if (!extraData->m_pcName)
		return -1;

	SInt16 min = 0;
	SInt16 max = (SInt16)m_extraDataLen - 1;
	SInt16 r = -1;
	while (max >= min) { // Iterative binary search
		SInt16 mid = (min + max) >> 1;
		if (m_extraData[mid]->m_pcName == extraData->m_pcName)
			r = mid; // Found entry
		else if (m_extraData[mid]->m_pcName < extraData->m_pcName)
			min = mid + 1;
		else
			max = mid - 1;
	}

	return r;
}

bool NiObjectNET::RemoveExtraData(NiExtraData * extraData)
{
	SInt32 index = GetIndexOf(extraData);
	if (index >= 0) { // Remove the entry
		extraData->DecRefCount();
		// Shift everything up
		for (UInt16 i = index; i < m_extraDataLen - 1; i++)
			m_extraData[i] = m_extraData[i + 1];
		// Remove the duplicate tail entry
		m_extraData[--m_extraDataLen] = nullptr;
		return true;
	}

	return false;
}

// This should be a BSFixedString before passing to this
NiExtraData * NiObjectNET::GetExtraData(const char * name)
{
	SInt16 min = 0;
	SInt16 max = (SInt16)m_extraDataLen - 1;

	while (max >= min) { // Iterative binary search
		SInt16 mid = (min + max) >> 1;
		if (m_extraData[mid]->m_pcName == name)
			return m_extraData[mid];
		else if (m_extraData[mid]->m_pcName < name)
			min = mid + 1;
		else
			max = mid - 1;
	}

	return nullptr;
}
