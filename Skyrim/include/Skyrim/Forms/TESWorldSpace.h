#pragma once

#include "TESForm.h"
#include "../BSCore/BSString.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/TESModel.h"
#include "../FormComponents/TESTexture.h"
#include "../NetImmerse/NiTypes.h"
#include "../BSCore/BSTArray.h"
#include "../BSCore/BSTHashMap.h"
#include "TESQuest.h"

class TESFile;

/*==============================================================================
class TESWorldSpace +0000 (_vtbl=01089EFC)
0000: class TESWorldSpace
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
001C: |   class TESModel
001C: |   |   class BaseFormComponent
==============================================================================*/
// 1D8
class TESWorldSpace : public TESForm,
	public TESFullName,			// 14
	public TESModel				// 1C
{
public:
	enum { kTypeID = (UInt32)FormType::WorldSpace };

	virtual ~TESWorldSpace();		// 004F5E00

	// @members

	// 4
	struct Data038
	{
		UInt16	unk0;
		UInt16	unk2;
	};

	// 020
	struct Data03C
	{
		UInt8	unk0[0x20];
	};

	// ?
	struct OFFSET_DATA { };

	// 40
	struct Data12C
	{
		// this struct keeps showing up everywhere
		struct Entry
		{
			UInt8	pad00[8];	// 00
			UInt32	unk08;		// 08
			UInt32	unk0C;		// 0C
			UInt32	unk10;		// 10
			void	* unk14;	// 14
			UInt8	pad18[4];	// 18
			UInt32	unk1C;		// 1C
		};

		Entry	unk00;
		Entry	unk20;
	};

	
	// âêÕíÜ
	//BSTHashMap<UInt32, void*>	unk05C;	// 064
	//									// 078 - hash sentinel
	//UInt32					unk07C;	// 084;

	//BSTHashMap<Uint32, void*>	unk098;	// 098
	//									// 0AC - hash sentinel

	//BSTHashMap<UInt32, void*>	unk124;	// 124
	//									// 138 - hash sentinel

	/* à»â∫ÅAä‘à·Ç¢ÇæÇÁÇØÇ≈éQçlÇ…Ç»ÇÁÇ»Ç¢
	typedef NiTPointerMap <int, TESObjectCELL *>	CellMap;
	CellMap	* cellMap;	// 024
	UInt32	unk028;		// 028
	UInt32	unk02C;		// 02C
	UInt32	unk030;		// 030
	UInt8	worldSpaceFlags;	// 034
	UInt8	pad035;		// 035
	UInt16	unk036;		// 036
	Data038	unk038;		// 038
	Data03C	unk03C;		// 03C

	BSTArray<void*>	unk05C;	// 05C
	UInt32	unk068;		// 068
	UInt32	unk06C;		// 06C
	BSTHashMap<UInt32, void*>	unk070;	// 070 - same type of TESQuest::unk060 because of same hash-sentinel
	void	* unk090;	// 090 - refcounted ptr
	UInt32	unk094;		// 094
	UInt32	unk098;		// 098
	UInt32	unk09C;		// 09C
	UInt32	unk0A0;		// 0A0
	UInt32	unk0A4;		// 0A4
	UInt32	unk0A8;		// 0A8
	UInt32	unk0AC;		// 0AC
	UInt32	unk0B0;		// 0B0
	UInt32	unk0B4;		// 0B4
	UInt32	unk0B8;		// 0B8

	UInt8	unk0BC[0x10];	// 0BC
	float	unk0CC;		// 0CC
	UInt32	unk0D0;		// 0D0
	UInt32	unk0D4;		// 0D4
	UInt32	unk0D8;		// 0D8
	UInt32	unk0DC;		// 0DC
	UInt32	unk0E0;		// 0E0
	UInt32	unk0E4;		// 0E4
	UInt32	unk0E8;		// 0E8
	UInt32	unk0EC;		// 0EC
	NiTMap <TESFile *, TESWorldSpace::OFFSET_DATA *>	unk0F0;	// 0F0
	BSString	unk100;	// 100
	void		* unk108;	// 108
	UInt32		unk10C;	// 10C
	float		unk110;	// 110
	UInt32		unk114;	// 114
	UInt32		unk118;	// 118
	TESTexture	unk11C;	// 11C
	TESTexture	unk124;	// 124
	Data12C		unk12C;	// 12C
	UInt32		unk16C;	// 16C
	UInt32		unk170;	// 170
	*/
private:
	DEFINE_MEMBER_FN(ctor, void, 0x004F5630);
	DEFINE_MEMBER_FN(dtor, void, 0x004F5C00);
};
//STATIC_ASSERT(sizeof(TESWorldSpace) == 0x1D8);
