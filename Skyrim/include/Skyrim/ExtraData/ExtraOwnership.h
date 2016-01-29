#pragma once

#include "BSExtraData.h"

class TESForm;

/*==============================================================================
class ExtraOwnership +0000 (_vtbl=01079188)
0000: class ExtraOwnership
0000: |   class BSExtraData
==============================================================================*/
// 0C
class ExtraOwnership : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Ownership };

	static ExtraOwnership* Create(TESForm *owner = nullptr);

	ExtraOwnership();
	virtual ~ExtraOwnership();

	TESForm* owner;
private:
	DEFINE_MEMBER_FN(ctor, ExtraOwnership*, 0x00422690, TESForm *owner);
};
