#pragma once

#include "../BSSystem/BSTSmartPointer.h"
#include "../BSCore/BSTArray.h"
#include "../BSCore/BSTHashMap.h"
#include "../NetImmerse/NiPoint3.h"

class BSPathingCell;

BSSmartPointer(BSNavmesh);



/*==============================================================================
class BSPathingStreamRead +0000 (_vtbl=010C587C)
0000: class BSPathingStreamRead
==============================================================================*/
class BSPathingStreamRead
{
public:
	virtual void	Unk_00(void) = 0;								// 00
	virtual void	Unk_01(void) = 0;								// 01
	virtual void	Unk_02(void) = 0;								// 02
	virtual void	Unk_03(void) = 0;								// 03
	virtual void	Unk_04(void) = 0;								// 04
	virtual void	Unk_05(void) = 0;								// 05
	virtual void	Unk_06(void) = 0;								// 06
	virtual void	Unk_07(void) = 0;								// 07
	virtual void	Unk_08(void) = 0;								// 08
	virtual void	Unk_09(void) = 0;								// 09
	virtual void	Unk_0A(void) = 0;								// 0A
	virtual void	Unk_0B(void) = 0;								// 0B
	virtual bool	Unk_0C(UInt32 arg);								// 0C 00B53E30 { return false; }
	virtual bool	Unk_0D(UInt32 arg);								// 0D 00B53E40 { return false; }
	virtual bool	Unk_0E(UInt32 arg);								// 0E 00B53E50 { return false; }
	virtual ~BSPathingStreamRead();									// 0F 005F92B0
	virtual void	Unk_10(void) = 0;								// 10
	virtual void	Unk_11(void) = 0;								// 11
	virtual void	Unk_12(void) = 0;								// 12
};


/*==============================================================================
class PathingStreamMasterFileRead +0000 (_vtbl=010C58CC)
0000: class PathingStreamMasterFileRead
0000: |   class BSPathingStreamRead
==============================================================================*/
class PathingStreamMasterFileRead : public BSPathingStreamRead
{
public:
	// @override class BSPathingStreamRead : (vtbl=010C58CC)
	//virtual void   Unk_000(void) override;                           // 0060C230
	//virtual void   Unk_001(void) override;                           // 0060C150
	//virtual void   Unk_002(void) override;                           // 0060C1E0
	//virtual void   Unk_003(void) override;                           // 0060C150
	//virtual void   Unk_004(void) override;                           // 0060C150
	//virtual void   Unk_005(void) override;                           // 0060C110
	//virtual void   Unk_006(void) override;                           // 0060C110
	//virtual void   Unk_007(void) override;                           // 0060C0E0
	//virtual void   Unk_008(void) override;                           // 0060C0E0
	//virtual void   Unk_009(void) override;                           // 0060C0E0
	//virtual void   Unk_00A(void) override;                           // 0060C090
	//virtual void   Unk_00B(void) override;                           // 0060C190
	//virtual void   Unk_010(void) override;                           // 0060C0B0
	//virtual void   Unk_011(void) override;                           // 0060C0A0
	//virtual UInt32 Unk_012(void) override;                           // 005EADD0 { return 0; }

	// @members
	//void		** _vtbl;		// 00 - 010C58CC
	void		* unk04;		// 04
	void		* unk08;		// 08
	TESFile		* unk0C;		// 0C
};


/*==============================================================================
class BSNavmesh +0000 (_vtbl=011218FC)
0018: class BSNavmesh
001C: |   struct BSIntrusiveRefCounted
==============================================================================*/
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

	// 10 - BSNavmeshTriangle ?
	struct Triangle
	{
		UInt16	vertices[3];	// 00
		UInt16	unk06[3];		// 06
		UInt32	unk0C;
	};
	STATIC_ASSERT(sizeof(Triangle) == 0x10);

	// 0C
	struct ExternalConnection
	{
		UInt32	unk00;
		FormID	navmeshID;
		UInt32	unk08;
	};

	virtual ~BSNavmesh();
	virtual FormID	GetFormID(void) = 0;


	DEFINE_MEMBER_FN(ReadPathingStream, void, 0x00B50080, BSPathingStreamRead *stream);


	// @members
	//void							** _vtbl;				// 00 - 011218FC
	BSTArray<NiPoint3>				vertices;				// 08
	BSTArray<Triangle>				triangles;				// 14
	BSTArray<ExternalConnection>	externalConnections;	// 20
	BSTArray<void *>				unk2C;					// 2C
	BSTArray<void *>				unk38;					// 38
	BSTArray<UInt16>				unk44;					// 44
	Data50							unk50;					// 50
	BSTArray<void *>				unk78;					// 78
	BSTHashMap<void *, void *>		* unk84;				// 84 - hash sentinel 012C9588
	BSTArray<void *>				unk88;					// 88
	BSPathingCell					* pathingCell;			// 94 - init'd 0
	void							* unk98;				// 98 - init'd 0

private:
	DEFINE_MEMBER_FN(ctor, BSNavmesh *, 0x00B4FD10);
	DEFINE_MEMBER_FN(dtor, void, 0x00B4FE40);
};
STATIC_ASSERT(sizeof(BSNavmesh) == 0x9C);
