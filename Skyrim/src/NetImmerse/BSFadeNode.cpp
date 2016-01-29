#include "Skyrim/NetImmerse/BSFadeNode.h"
#include <memory.h>

BSFadeNode * BSFadeNode::Create()
{
	BSFadeNode *xData = FormHeap_Allocate<BSFadeNode>();
	if (xData)
	{
		memset(xData, 0, sizeof(BSFadeNode));
		xData->ctor();
	}
	return xData;
}
