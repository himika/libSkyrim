#pragma once

#include "TESTexture.h"

// 08
class TESIcon : public TESTexture
{
public:
	virtual ~TESIcon();										// 004524B0

	// @override
	virtual const char *	GetSearchDir(void) override;	// 00457980 { return "Texture"; }

};
