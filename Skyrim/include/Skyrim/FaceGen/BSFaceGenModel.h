#pragma once

#include "../NetImmerse/NiRefObject.h"

class NiAVObject;
class BSFaceGenMorphData;
class TESModelTri;

/*==============================================================================
class BSFaceGenModel +0000 (_vtbl=010BE8A8)
0000: class BSFaceGenModel
0000: |   class NiRefObject
==============================================================================*/
// 10
class BSFaceGenModel : public NiRefObject
{
public:
	struct Data08
	{
		UInt32				unk00;		// 00
		NiAVObject			* unk04;	// 04
		NiAVObject			* unk08;	// 08
		UInt32				unk0C;		// 0C
		BSFaceGenMorphData	* unk10;	// 10
	};

	virtual ~BSFaceGenModel();			// 005A5E40

	// @members
	Data08	* unk08;	// 08
	UInt32	unk0C;		// 0C

private:
	DEFINE_MEMBER_FN(ctor, void, 0x005A5D40);
	DEFINE_MEMBER_FN(CopyFrom, void, 0x005A5D80, BSFaceGenModel * other);
	DEFINE_MEMBER_FN(SetModelData, bool, 0x005A60D0, const char * meshPath, void * unk1, UInt8 unk2);
	DEFINE_MEMBER_FN(ApplyMorph, UInt8, 0x005A5B70, const char ** morphName, TESModelTri * triModel, NiAVObject ** headNode, float relative, UInt8 unk1);
};


// 10
class BSFaceGenModelMap : public NiRefObject
{
public:
	/*==============================================================================
	class BSFaceGenModelMap::Entry +0000 (_vtbl=010BE8CC)
	0000: class BSFaceGenModelMap::Entry
	0000: |   class NiRefObject
	==============================================================================*/
	class Entry
	{
	public:
		// @add
		virtual void	Unk_02(void);	// 00444F46

		// @members
		BSFaceGenModel	* unk00;	// 00
		UInt32			unk04;		// 04
	};

	Entry	unk08;	// 08
};
