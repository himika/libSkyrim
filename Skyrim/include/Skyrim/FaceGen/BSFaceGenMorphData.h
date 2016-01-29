#pragma once

#include "../NetImmerse/NiRefObject.h"

class NiRTTI;

class NiNode;
class NiSwitchNode;
class NiGeometry;
class NiTriBasedGeom;
class NiTriStrips;
class NiTriShape;
class BSSegmentedTriShape;

// ??
class BSFaceGenMorphData : public NiRefObject
{
public:
	void	* unk08;	// 08
	UInt32	unk0C;		// 0C

	virtual NiRTTI *		GetRTTI(void);								// 02 ???????? { return 0x01B1DF0C; }
	virtual NiNode			* GetAsNiNode(void);						// 03 005EADD0 { return 0; }
	virtual NiSwitchNode	* GetAsNiSwitchNode(void);					// 04 005EADD0 { return 0; }
	virtual UInt32			Unk_05(void);								// 05 005EADD0 { return 0; }
	virtual UInt32			Unk_06(void);								// 06 005EADD0 { return 0; }
	virtual NiGeometry		* GetAsNiGeometry(void);					// 07 005EADD0 { return 0; }
	virtual NiTriBasedGeom	* GetAsNiTriBasedGeom(void);				// 08 005EADD0 { return 0; }
	virtual NiTriStrips		* GetAsNiTriStrips(void);					// 09 005EADD0 { return 0; }
	virtual NiTriShape		* GetAsNiTriShape(void);					// 0A 005EADD0 { return 0; }
	virtual BSSegmentedTriShape * GetAsBSSegmentedTriShape(void);		// 0B 005EADD0 { return 0; }
	virtual UInt32			Unk_0C(void);								// 0C 005EADD0 { return 0; }
	virtual UInt32			Unk_0D(void);								// 0D 005EADD0 { return 0; }
	virtual UInt32			Unk_0E(void);								// 0E 005EADD0 { return 0; }
	virtual UInt32			Unk_0F(void);								// 0F 005EADD0 { return 0; }
	virtual UInt32			Unk_10(void);								// 10 005EADD0 { return 0; }
	virtual UInt32			Unk_11(void);								// 11 005EADD0 { return 0; }
	virtual UInt32			Unk_12(void);								// 12 005EADD0 { return 0; }

	//DEFINE_MEMBER_FN(ApplyMorph, UInt8, 0x005A75F0, const char ** morphName, NiAVObject * faceTrishape, float relative, UInt8 unk2);
};



/*==============================================================================
class BSFaceGenMorphDataHead +0000 (_vtbl=010BE9D4)
0000: class BSFaceGenMorphDataHead
0000: |   class BSFaceGenMorphData
0000: |   |   class NiRefObject
==============================================================================*/
// 4C
class BSFaceGenMorphDataHead : public BSFaceGenMorphData
{
public:
	virtual NiRTTI *	GetRTTI(void);		// 005A7860 { return 0x01B1DF14; }

	// @members
	UInt32	unk10[(0x48 - 0x10) >> 2];
	UInt32	unk48;
};
STATIC_ASSERT(offsetof(BSFaceGenMorphDataHead, unk48) == 0x48);
STATIC_ASSERT(sizeof(BSFaceGenMorphDataHead) == 0x4C);


/*==============================================================================
class BSFaceGenMorphDataHair +0000 (_vtbl=010BE8DC)
0000: class BSFaceGenMorphDataHair
0000: |   class BSFaceGenMorphData
0000: |   |   class NiRefObject
==============================================================================*/
// 10
class BSFaceGenMorphDataHair : public BSFaceGenMorphData
{
public:
	virtual NiRTTI *	GetRTTI(void);		// 005A7460{ return 0x01B1DF1C; }
};
STATIC_ASSERT(sizeof(BSFaceGenMorphDataHair) == 0x10);
