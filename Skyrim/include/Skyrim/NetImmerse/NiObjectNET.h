#pragma once

#include "NiObject.h"

class NiTimeController;
class NiExtraData;

/*==============================================================================
class NiObjectNET +0000 (_vtbl=01117824)
0000: class NiObjectNET
0000: |   class NiObject
0000: |   |   class NiRefObject
==============================================================================*/
// 18
class NiObjectNET : public NiObject
{
public:
	enum { kRTTI = 0x01B91284 };

	virtual ~NiObjectNET();													// 00AB52F0

	// @override
	virtual NiRTTI *	GetRTTI(void) const override;						// 02 00AB52E0 { return 0x01B91284; }
	virtual void		LoadBinary(NiStream * stream) override;				// 14 00AB4030
	virtual void		LinkObject(NiStream * stream) override;				// 15 00AB4A00
	virtual bool		RegisterStreamables(NiStream * stream) override;	// 16 00AB4100
	virtual void		SaveBinary(NiStream * stream) override;				// 17 00AB4BD0
	virtual bool		IsEqual(NiObject * object) override;				// 18 00AB4CC0
	virtual void		ProcessClone(NiCloningProcess * cloner) override;	// 19 00AB4060
	virtual void		PostLinkObject(NiStream * stream) override;			// 1A 00AB4A80

	NiTimeController *	GetController() const {
		return m_controller;
	}

	bool AddExtraData(NiExtraData* extraData);			// 00AB44C0

	// UNTESTED
	bool RemoveExtraData(NiExtraData * extraData);
	SInt32 GetIndexOf(NiExtraData * extraData);
	NiExtraData * GetExtraData(const char * name);
private:
	bool InsertExtraData(NiExtraData* extraData);
	void DeleteExtraData(UInt16 usExtraDataIndex);


	// @members
	//void				** _vtbl;				// 00 - 01117824
	const char			* m_name;				// 08 - NiFixedString?
	NiTimeController	* m_controller;			// 0C - next pointer at +0x30
	NiExtraData			** m_extraData;			// 10 - extra data
	UInt16				m_extraDataLen;			// 14 - max valid entry
	UInt16				m_extraDataCapacity;	// 16 - array len
};
STATIC_ASSERT(sizeof(NiObjectNET) == 0x18);
