#pragma once

#include "../Events/PositionPlayerEvent.h"
#include "../BSResource/BSResource.h"
#include "../BSCore/BSTSingleton.h"
#include "../BSCore/BSTList.h"
#include "../NetImmerse/NiNode.h"
#include "../Forms/NavMeshInfoMap.h"

class NiSourceTexture;
class TESNPC;
class TESObjectCELL;
class Sky;
class TESWorldSpace;
class QueuedFile;

// ?
struct CellAttachDetachEvent
{
};


/*==============================================================================
class ICellAttachDetachEventSource +0000 (_vtbl=0107AC40)
0000: class ICellAttachDetachEventSource
0004: |   class BSTSingletonExplicit<class ICellAttachDetachEventSource>
0004: |   class BSTEventSource<struct CellAttachDetachEvent>
==============================================================================*/
// 34
class ICellAttachDetachEventSource :
	public BSTSingletonExplicit<class ICellAttachDetachEventSource>,	// 04
	public BSTEventSource<CellAttachDetachEvent>						// 04
{
public:
	virtual ~ICellAttachDetachEventSource();		// 00435BE0
};

/*==============================================================================
class GridArray +0000 (_vtbl=0107F38C)
0000: class GridArray
==============================================================================*/
class GridArray
{
public:
	virtual ~GridArray();			// 004743C0

	virtual void Unk_01(void);		// 00474170
	virtual void Unk_02(void);		// 00474190
	virtual void Unk_03(void);		// 00474180
	virtual void Unk_04(void);		// 004741D0
	virtual void Unk_05(void);		// 00474200
	virtual void Unk_06(void) = 0;	// 00F51EE8 (pure)
	virtual void Unk_07(void) = 0;	// 00F51EE8 (pure)
	virtual void Unk_08(void) = 0;	// 00F51EE8 (pure)
	virtual void Unk_09(void) = 0;	// 00F51EE8 (pure)
};

/*==============================================================================
class GridCellArray +0000 (_vtbl=0107F3C0)
0000: class GridCellArray
0000: |   class GridArray
==============================================================================*/
class GridCellArray : public GridArray
{
public:
	virtual ~GridCellArray();				// 00474B00

	// @override
	virtual void Unk_03(void) override;		// 00474AE0
	virtual void Unk_04(void) override;		// 00474500
	virtual void Unk_05(void) override;		// 00474200
	virtual void Unk_06(void) override;		// 00474570
	virtual void Unk_07(void) override;		// 004745C0
	virtual void Unk_08(void) override;		// 00474600
	virtual void Unk_09(void) override;		// 00474660

	// @add
	virtual void Unk_0A(void);				// 004744E0

	
	TESObjectCELL * Get(UInt32 x, UInt32 y) {
		if (!cells || x >= size || y >= size)
			return nullptr;
		return cells[x + y*size];
	}

	bool IsAttached(TESObjectCELL *cell) const {
		if (!cells || cell)
			return false;

		const UInt32 length = size * size;
		for (UInt32 i = 0; i < length; ++i) {
			if (cells[i] == cell)
				return true;
		}

		return false;
	}

	// @members
	//void	** _vtbl;		// 00 - 0107F3C0
	UInt32	unk04;
	UInt32	unk08;
	UInt32	size;			// 0C
	TESObjectCELL**	cells;	// 10
};


/*==============================================================================
class BSTempNodeManager +0000 (_vtbl=0107AA0C)
0000: class BSTempNodeManager
0000: |   class NiNode
0000: |   |   class NiAVObject
0000: |   |   |   class NiObjectNET
0000: |   |   |   |   class NiObject
0000: |   |   |   |   |   class NiRefObject
==============================================================================*/
class BSTempNodeManager : public NiNode
{
public:
	virtual ~BSTempNodeManager();																			// 00431200

	// @override class NiNode : (vtbl=0107AA0C)
	virtual NiRTTI *	GetRTTI(void) const override;														// 004311F0 { return (NiRTTI* )0x01B97F20; }
	virtual void		UpdateDownwardPass(ControllerUpdateContext * ctx, UInt32 unk1) override;			// 00AFF810
	virtual void		UpdateSelectedDownwardPass(ControllerUpdateContext * ctx, UInt32 unk1) override;	// 00AFF840
	virtual void		UpdateRigidDownwardPass(ControllerUpdateContext * ctx, UInt32 unk1) override;		// 00AFF870

	// @members
	//void	** _vtbl;		// 00 - 0107AA0C

private:
	DEFINE_MEMBER_FN(dtor, void, 0x00AFF660);
};


/*==============================================================================
class LoadedAreaBound +0000 (_vtbl=010A7CBC)
0000: class LoadedAreaBound
0000: |   class NiRefObject
==============================================================================*/
// 6C
class LoadedAreaBound : public NiRefObject
{
public:
	virtual ~LoadedAreaBound();					// 00587060

	UInt32						unk08;			// 08 - init'd 0
	UInt32						unk0C;			// 0C - init'd 0
	UInt32						unk10;			// 10 - init'd 0
	UInt32						unk14;			// 14 - init'd 0
	UInt32						unk18;			// 18 - init'd 0
	UInt32						unk1C;			// 1C - init'd 0
	UInt32						unk20;			// 20 - init'd 0
	BSTHashMap<UInt32, void*>	unk24;			// 24
	NiPoint3					boundsMax;		// 44
	NiPoint3					boundsMin;		// 50
	UInt32						unk5C;
	UInt32						unk60;
	UInt32						unk64;
	UInt32						unk68;
};
STATIC_ASSERT(sizeof(LoadedAreaBound) == 0x6C);
STATIC_ASSERT(offsetof(LoadedAreaBound, boundsMax) == 0x44);


/*=============================================================================
class TES +0000 (_vtbl=0107AC60)
0000: class TES
0000: |   class ICellAttachDetachEventSource
0004: |   |   class BSTSingletonExplicit<class ICellAttachDetachEventSource>
0004: |   |   class BSTEventSource<struct CellAttachDetachEvent>
0034: |   class BSTEventSink<struct BSResource::ArchiveStreamOpenedEvent>
0038: |   class BSTEventSink<struct PositionPlayerEvent>
=============================================================================*/
// E8
class TES : public ICellAttachDetachEventSource,
	public BSTEventSink<BSResource::ArchiveStreamOpenedEvent>,			// 34
	public BSTEventSink<PositionPlayerEvent>							// 38
{
public:
	struct NPCDeadCount
	{
		TESNPC*	npc;		// 00
		UInt32	deadCount;	// 04
	};

	//TES(const char *datadir, UInt32 arg2, UInt32 arg3, Sky *a_sky, NiNode *a_node);		// 00435C10;
	virtual ~TES();																			// 00438310

	// @override class BSTEventSink<struct BSResource::ArchiveStreamOpenedEvent> : (vtbl=0107AC54)
	virtual EventResult ReceiveEvent(BSResource::ArchiveStreamOpenedEvent *, BSTEventSource<BSResource::ArchiveStreamOpenedEvent> *) override;	// 00A5F140 { return 0; }

	// @override class BSTEventSink<struct PositionPlayerEvent> : (vtbl=0107AC48)
	virtual EventResult ReceiveEvent(PositionPlayerEvent *, BSTEventSource<PositionPlayerEvent> *) override;	// 00439490


	bool IsAttached(TESObjectCELL *cell) const;

	UInt32				unk3C;					// 3C - init'd 0
	GridCellArray		* gridCellArray;		// 40 - init'd 0
	NiNode				* objectLODRoot;		// 44 - init'd 0
	NiNode				* landLOD;				// 48
	NiNode				* waterLOD;				// 4C
	BSTempNodeManager *	tempNodeManager;
	UInt32				unk54;
	UInt32				unk58;
	UInt32				unk5C;					// 7FFFFFFF
	UInt32				unk60;					// 7FFFFFFF
	UInt32				unk64;					// 7FFFFFFF
	UInt32				unk68;					// 7FFFFFFF
	TESObjectCELL		* currentCell;
	TESObjectCELL		**  interiorCellBuffer; // idk, visited cells perhaps?
	UInt32				unk74;
	UInt32				unk78;					// 0
	UInt32				unk7C;					// 0
	UInt32				unk80;					// 7FFFFFFF
	UInt32				unk84;					// 7FFFFFFF
	UInt32				unk88;
	UInt32				unk8C;
	UInt32				unk90;
	Sky					* sky;					// Sky
	UInt32				imageSpaceModifier;		// ImageSpaceModifierInstanceForm
	UInt32				unk9C;					// ImageSpaceModifierInstanceDOF ** ??
	UInt32				unkA0;
	UInt32				unkA4;
	UInt8				unkA8;
	UInt8				unkA9;
	UInt8				unkAA;
	UInt8				unkAB;
	UInt8				unkAC;
	UInt8				unkAD;
	UInt8				unkAE;
	UInt8				unkAF;
	UInt8				unkB0;
	UInt8				padB1[3];
	UInt32				unkB4;					// B4 - 4579A000
	UInt32				unkB8;					// B8 - 457D2000
	TESWorldSpace		* worldSpace;			// BC
	BSSimpleList<NPCDeadCount*>	npcDeadCount;	// C0
	QueuedFile			* queuedFile;			// C8 - QueuedFile
	NiSourceTexture		* someTexture;			// CC
	QueuedFile			* queuedFile1;			// D0 - QueuedFile
	QueuedFile			* queuedFile2;			// D4
	UInt32				unkD8;					// D8 - BSFadeNode ** ??
	UInt32				unkDC;					// DC
	NavMeshInfoMap		* navMeshInfoMap;		// E0
	LoadedAreaBound		* loadedAreaBound;		// E4

private:
	DEFINE_MEMBER_FN(ctor, TES *, 0x00435C10, const char *datadir, UInt32 arg2, UInt32 arg3, Sky *a_sky, NiNode *a_node);
};
STATIC_ASSERT(sizeof(TES) == 0xE8);
STATIC_ASSERT(offsetof(TES, loadedAreaBound) == 0xE4);


// 01B2E864
extern TES *& g_TES;
