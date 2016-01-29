#pragma once

#include "NiTimeController.h"
#include "NiTArray.h"
#include "NiControllerSequence.h"

class NiControllerSequence;
class BSFixedString;


/*==============================================================================
class NiControllerManager +0000 (_vtbl=0110EF9C)
0000: class NiControllerManager
0000: |   class NiTimeController
0000: |   |   class NiObject
0000: |   |   |   class NiRefObject
==============================================================================*/

class NiControllerManager : public NiTimeController
{
public:
	enum { kRTTI = 0x01B90490 };

	inline NiControllerSequence* GetSequenceByName(const BSFixedString &name) {
		return GetSequenceByName_Impl(name);
	}

	// @members
	NiTObjectArray<NiControllerSequencePtr> m_sequences;		// 34

private:
	DEFINE_MEMBER_FN(GetSequenceByName_Impl, NiControllerSequence*, 0x0044BC70, const BSFixedString &);
};
