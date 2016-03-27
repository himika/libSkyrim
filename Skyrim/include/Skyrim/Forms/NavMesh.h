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


	virtual ~NavMesh();				// 005F6410

	// @override class TESForm : (vtbl=010C56C4)
	virtual bool	LoadForm(TESFile *mod) override;						// 005F92E0
	virtual void	Unk_11(BGSLoadFormBuffer *buf) override;				// 005F92A0
	virtual void	InitItem(void) override;								// 005F9730
	virtual void	GetFormDesc(char * buf, UInt32 bufLen) override;		// 005F94B0
	virtual void	SetFlag00000020(bool set) override;						// 005F9510
	virtual void	SetFlag00000002(bool set) override;						// 005F95A0
	virtual bool	Unk_30(void * arg0, UInt32 arg1, UInt32 arg2) override;	// 005F9220
	virtual bool	Unk_31(void * dst, void * unk) override;				// 005F95F0

	// @add
	virtual void	Unk_03B(void);											// 006C50E0 { return; }
	virtual bool	Unk_03C(UInt32 arg);									// 004091A0 { return false; }
	virtual bool	Unk_03D(UInt32 arg);									// 004091A0 { return false; }
	virtual bool	Unk_03E(void);											// 0092D110 { return false; }

	// @override class TESChildCell : (vtbl=010C56B8)
	virtual	UInt32	TESChildCell_Unk_01(void);								// 005F67A0 { return [1310460].Unk_00604910(&this->BSNavmesh::unk94); }

	// @override class BSNavmesh : (vtbl=010C57C4)
	virtual FormID	GetFormID(void) override;								// 005F60D0 { return this->formID; }

	// @members
	//void		** _vtbl;		// 00 - 010C56C4

private:
	DEFINE_MEMBER_FN(ctor, NavMesh *, 0x005F6070);
};
STATIC_ASSERT(sizeof(NavMesh) == 0xB4);
