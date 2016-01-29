#pragma once

#include "../BSCore/BSTEvent.h"
#include "../Events/PositionPlayerEvent.h"

/*==============================================================================
class Main +0000 (_vtbl=010CE13C)
0000: class Main
0000: |   class BSTEventSink<struct PositionPlayerEvent>
==============================================================================*/
// 128
class Main : public BSTEventSink<PositionPlayerEvent>
{
public:
	// @members
	UInt8	unk04;		// 04 - init'd 0
	UInt8	unk05;		// 05 - init'd 0
	UInt8	unk06;		// 06 - init'd 0
	UInt8	unk07;		// 07 - init'd 0
	UInt8	unk08;		// 08 - init'd 0
	UInt8	unk09;		// 09 - init'd 0
	bool	bPaused;	// 0A - init'd 0
	UInt8	pad0B;
	UInt32	unk0C;
	UInt32	unk10;
	long	threadID;	// 14
	UInt32	unk18;
	UInt32	unk1C;		// 1C - init'd 0
	//...
	//BSGeometryListCullingProcess	* unk0EC;
	//...

	inline bool IsPaused()
	{
		return bPaused;
	}

private:
	DEFINE_MEMBER_FN(ctor, Main*, 0x0069BFE0, UInt32, UInt32)
};

extern Main *& g_main;

