#pragma once

#include "NiNode.h"

// E4
class BSFadeNode : public NiNode
{
public:
	enum { kRTTI = 0x01BA72B8 };

	UInt32	unkB8[(0xE4 - 0xB8) >> 2];

	static BSFadeNode * Create();

private:
	DEFINE_MEMBER_FN(ctor, BSFadeNode *, 0x00C6BBE0);
};
STATIC_ASSERT(sizeof(BSFadeNode) == 0xE4);
