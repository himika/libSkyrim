#include "Skyrim.h"
#include "Skyrim/SkyrimVM.h"
#include "Skyrim/VMState.h"
#include <utility>

DECLARE_BSTSINGLETONSDM_STATIC_INSTANCE(SkyrimVM, 0x012E568C, 0x01B333C0);


SkyrimVM *& g_skyrimVM = *(SkyrimVM **)0x012E568C;

void UpdateRegistrationHolder::Order(UInt32 index)
{
	UInt32 count = m_regs.size();
	UInt32 pivotIndex = count >> 1;

	if (index >= pivotIndex)
		return;

	Registration * pOldReg = m_regs[index];
	UInt32 startIndex = index;
	UInt32 cmpIndex;
	do
	{
		cmpIndex = 2 * index + 1;

		if (cmpIndex < (count - 1))
		{
			Registration * pCur = m_regs[cmpIndex];
			Registration * pSucc = m_regs[cmpIndex + 1];
			if (!pCur || !pSucc || pCur->schedTime > pSucc->schedTime)
				cmpIndex++;
		}

		Registration * pCmpReg = m_regs[cmpIndex];
		if (!pCmpReg || !pOldReg || pCmpReg->schedTime > pOldReg->schedTime)
			break;

		m_regs[index] = pCmpReg;
		index = cmpIndex;

	} while (cmpIndex < pivotIndex);

	if (index != startIndex)
		m_regs[index] = pOldReg;

}

bool UpdateRegistrationHolder::Remove(VMHandle & handle)
{
	if (m_regs.size() == 0)
		return false;

	for (UInt32 i = 0; i < m_regs.size(); i++)
	{
		Registration * pReg = m_regs[i];

		if (pReg && pReg->handle == handle)
		{
			UInt32 lastIndex = m_regs.size() - 1;

			// Remove last entry => no reorganizing necessary
			if (i == lastIndex)
			{
				m_regs.pop_back();
			}
			else
			{
				std::swap(m_regs[i], m_regs[lastIndex]);
				m_regs.pop_back();
				Order(i);
			}
			return true;
		}
	}
	return false;
}

UInt32 SkyrimVM::ClearInvalidRegistrations(void)
{
	auto policy = m_state->GetHandlePolicy();
	VMHandle invalidHandle = policy->GetInvalidHandle();

	m_updateLock.Lock();

	UInt32 count = 0;
	while (m_updateRegHolder.Remove(invalidHandle) == true)
		count++;

	while (m_updateGameTimeRegHolder.Remove(invalidHandle) == true)
		count++;

	m_updateLock.Unlock();

	return count;
}
