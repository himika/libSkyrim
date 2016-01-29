#pragma once

#include "../BSSystem/BSTSmartPointer.h"
#include "../BSCore/BSTArray.h"

// 9C
class BSNavmesh : public BSIntrusiveRefCounted
{
public:
	// 28
	struct Data50
	{
		UInt32	unk00;	// 00 - init'd to 0
		UInt32	unk04;	// 04
		UInt32	unk08;	// 08
		UInt32	unk0C;	// 0C - init'd to 7F7FFFFF
		UInt32	unk10;	// 10
		UInt32	unk14;	// 14
		UInt32	unk18;	// 18
		UInt32	unk1C;	// 1C
		UInt32	unk20;	// 20
		UInt32	unk24;	// 24 - init'd to 0
	};

	// 10
	class Data84
	{
	public:
		virtual	~Data84();

		//		void	** _vtbl;	// 00
		UInt32	unk04;		// 04 - ctor arg, prime?
		void	* unk08;	// 08 - buf, len = unk04 * 4
		UInt32	unk0C;		// 0C
	};

	virtual ~BSNavmesh();


	// @members
	//void			** _vtbl;		// 00
	BSTArray<void*>	unk08;			// 08
	BSTArray<void*>	unk14;			// 14
	BSTArray<void*>	unk20;			// 20
	BSTArray<void*>	unk2C;			// 2C
	BSTArray<void*>	unk38;			// 38
	BSTArray<void*>	unk44;			// 44
	Data50			unk50;			// 50
	BSTArray<void*>	unk78;			// 78
	Data84			* unk84;		// 84
	BSTArray<void*>	unk88;			// 88
	UInt32			unk94;			// 94
	UInt32			unk98;			// 98
};
STATIC_ASSERT(sizeof(BSNavmesh) == 0x9C);
