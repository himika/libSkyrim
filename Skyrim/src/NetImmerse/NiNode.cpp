#include "Skyrim/NetImmerse/NiNode.h"
#include "Skyrim/Memory.h"
#include <memory>

NiNode * NiNode::Create(UInt32 arrBufLen)
{
	NiNode *xData = FormHeap_Allocate<NiNode>();
	if (xData)
	{
		std::memset(xData, 0, sizeof(NiNode));
		xData->ctor(arrBufLen);
	}
	return xData;
}
