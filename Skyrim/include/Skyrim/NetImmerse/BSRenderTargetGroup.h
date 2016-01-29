#pragma once

#include "NiObject.h"

class NiRenderedTexture;
class NiRenderTargetGroup;

// Bethesda class, unknown name
class BSRenderTargetGroup : public NiObject
{
public:
	virtual ~BSRenderTargetGroup();

	NiRenderTargetGroup * unk08[6];			// 08
	UInt32	unk20;							// 20
	UInt32	unk24;							// 24
	UInt32	unk28;							// 28
	UInt32	unk2C;							// 2C inited to FFFFFFFF
	NiRenderedTexture * renderedTexture[4];	// 30

	static BSRenderTargetGroup *	GetPlayerFaceMask(void)
	{
		return *((BSRenderTargetGroup **)0x01B3FD54);
	}
};
