#pragma once

#include "BSExtraData.h"

class ExtraHotkey : public BSExtraData
{
public:
	enum { kExtraTypeID = (UInt32)ExtraDataType::Hotkey };

	ExtraHotkey();
	virtual ~ExtraHotkey();

	SInt8	hotkey;	// 08 (1 to 8, -1 unbound)

	static ExtraHotkey* Create();
};
