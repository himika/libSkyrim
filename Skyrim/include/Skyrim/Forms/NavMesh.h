#pragma once

#include "TESForm.h"
#include "../FormComponents/TESChildCell.h"
#include "../BSPathFinding/BSNavmesh.h"

/*==============================================================================
class NavMesh +0000 (_vtbl=010C56C4)
0000: class NavMesh
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESChildCell
0018: |   class BSNavmesh
001C: |   |   struct BSIntrusiveRefCounted
==============================================================================*/
// B4
class NavMesh : public TESForm,
	public TESChildCell,		// 14
	public BSNavmesh			// 18
{
public:
	enum { kTypeID = (UInt32)FormType::NAVM };

	// @add
	virtual void Unk_3B(void);		// 006C50E0 (void) { return; }
	virtual void Unk_3C(void);		// 004091A0 (UInt32 arg) { return false; }
	virtual void Unk_3D(void);		// 004091A0 (UInt32 arg) { return false; }
	virtual void Unk_3E(void);		// 0092D110 (void) { return false; }
};
STATIC_ASSERT(sizeof(NavMesh) == 0xB4);
