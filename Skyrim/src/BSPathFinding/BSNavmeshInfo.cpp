#include "Skyrim/BSPathFinding/BSNavmeshInfo.h"
#include "Skyrim/BSPathFinding/BSPrecomputedNavmeshInfoPathMap.h"

BSNavmeshInfoMap *& BSTSingletonExplicit<BSNavmeshInfoMap>::m_pSingleton = *(BSNavmeshInfoMap**)0x01B20FE0;

BSPrecomputedNavmeshInfoPathMap *& BSTSingletonExplicit<BSPrecomputedNavmeshInfoPathMap>::m_pSingleton = *(BSPrecomputedNavmeshInfoPathMap**)0x01B9DF48;
