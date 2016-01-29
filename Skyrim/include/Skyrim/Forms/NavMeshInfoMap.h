#pragma once

#include "TESForm.h"
#include "../BSPathFinding/BSNavmeshInfo.h"


// 2C
class PrecomputedNavmeshInfoPathMap : public BSPrecomputedNavmeshInfoPathMap
{
public:

private:
	DEFINE_MEMBER_FN(ctor, PrecomputedNavmeshInfoPathMap*, 0x005FCA40)
};
STATIC_ASSERT(sizeof(PrecomputedNavmeshInfoPathMap) == 0x2C);


/*==============================================================================
class NavMeshInfoMap +0000 (_vtbl=010C59DC)
0000: class NavMeshInfoMap
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class BSNavmeshInfoMap
0018: |   |   class BSTSingletonExplicit<class BSNavmeshInfoMap>
001C: |   class PrecomputedNavmeshInfoPathMap
001C: |   |   class BSPrecomputedNavmeshInfoPathMap
001C: |   |   |   class BSTSingletonExplicit<class BSPrecomputedNavmeshInfoPathMap>
==============================================================================*/
// 98
class NavMeshInfoMap : public TESForm,
	public BSNavmeshInfoMap,				// 14
	public BSPrecomputedNavmeshInfoPathMap	// 1C
{
public:
	enum { kTypeID = (UInt32)FormType::NAVI };

	// @override class BSNavmeshInfoMap : (vtbl=010C59BC)
	virtual void	BSNavmeshInfoMap_Unk_01(void) override;		// 005FAB40
	virtual void	BSNavmeshInfoMap_Unk_02(void) override;		// 005FABD0
	virtual void	BSNavmeshInfoMap_Unk_03(void) override;		// 005FA920
	virtual void	BSNavmeshInfoMap_Unk_04(void) override;		// 005FAD40
	virtual void	BSNavmeshInfoMap_Unk_05(void) override;		// 005FAA20

	// 8
	struct Data8C
	{
		UInt32	unk0;
		UInt32	unk4;
	};

	// @members
	//void						** _vtbl;	// 00 - 010C59DC
	UInt8						unk48;		// 48
	UInt8						pad49[3];	// 49
	BSTHashMap<UInt32, void*>	unk4C;		// 4C
	BSTHashMap<UInt32, void*>	unk6C;		// 6C
	Data8C						unk8C;		// 8C
	UInt8						unk94;		// 94 - init'd 0
	UInt8						pad95[3];	// 95

private:
	DEFINE_MEMBER_FN(ctor, NavMeshInfoMap*, 0x005FC5B0)
};
STATIC_ASSERT(offsetof(NavMeshInfoMap, unk00) == 0x1C);
STATIC_ASSERT(sizeof(NavMeshInfoMap) == 0x98);
