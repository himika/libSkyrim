#pragma once

#include "NiTypes.h"
#include "NiAVObject.h"

/*==============================================================================
class NiLight +0000 (_vtbl=0111818C)
0000: class NiLight
0000: |   class NiAVObject
0000: |   |   class NiObjectNET
0000: |   |   |   class NiObject
0000: |   |   |   |   class NiRefObject
==============================================================================*/
// D4
class NiLight : public NiAVObject
{
public:
	enum { kRTTI = 0x01B92474 };

	virtual ~NiLight();

	float	unkA8;
	float	unkAC;
	float	unkB0;
	float	unkB4;
	float	unkB8;
	float	unkBC;
	float	unkC0;
	float	unkC4;
	float	unkC8;
	float	unkCC;
	UInt32	unkD0;
};

// D4
class NiAmbientLight : public NiLight
{
public:
	virtual ~NiAmbientLight();
};

// E0
class NiPointLight : public NiLight
{
public:
	virtual ~NiPointLight();

	float	unkD4;
	float	unkD8;
	float	unkDC;
};

// EC
class NiDirectionalLight : public NiLight
{
public:
	virtual ~NiDirectionalLight();

	float	unkD4;
	float	unkD8;
	float	unkDC;
	float	unkE0;
	float	unkE4;
	float	unkE8;
};
