#pragma once

#include "NiObject.h"
#include "NiSmartPointer.h"
#include "../BSCore/BSFixedString.h"

NiSmartPointer(NiControllerSequence);

class NiControllerSequence : public NiObject
{
public:
	enum { kRTTI = 0x01B904A8 };

	virtual bool	Unk_21(UInt32 arg1, UInt32 arg2);				// 21 00A72A40

	const BSFixedString & GetName() const
	{
		return m_name;
	}

	inline bool Activate(char cPriority, bool bStartOver, float fWeight, float fEaseInTime, NiControllerSequence* pkTimeSyncSeq, bool bTransition)
	{
		return Activate_Impl(cPriority, bStartOver, fWeight, fEaseInTime, pkTimeSyncSeq, bTransition);
	}

	// @members
	BSFixedString	m_name;		// 08

private:
	DEFINE_MEMBER_FN(Activate_Impl, bool, 0x00A72930, char, bool, float, float, NiControllerSequence *, bool);

};
STATIC_ASSERT(offsetof(NiControllerSequence, m_name) == 0x08);
