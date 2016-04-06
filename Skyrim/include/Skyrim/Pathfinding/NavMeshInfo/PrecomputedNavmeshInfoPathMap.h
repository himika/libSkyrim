#pragma once

#include "../../BSPathFinding/BSPrecomputedNavmeshInfoPathMap.h"

// 2C
class PrecomputedNavmeshInfoPathMap : public BSPrecomputedNavmeshInfoPathMap
{
public:

private:
	DEFINE_MEMBER_FN(ctor, PrecomputedNavmeshInfoPathMap*, 0x005FCA40)
};
STATIC_ASSERT(sizeof(PrecomputedNavmeshInfoPathMap) == 0x2C);
