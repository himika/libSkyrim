#pragma once

#include "../../FormComponents/TESForm.h"

/*==============================================================================
class TESObject +0000 (_vtbl=01083D14)
0000: class TESObject
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 14+
class TESObject : public TESForm
{
public:
	// @override
	virtual bool	Unk_28(void) override;				// 009B86F0 { return true; }

	// @add
	virtual UInt32	Unk_3B(void);						// 005EADD0 { return nullptr; }
	virtual bool	CanAnimate(void);					// 0092D110 { return false; }
	virtual UInt32	Unk_3D(void);						// 005EADD0 { return nullptr; }
	virtual bool	IsAutoCalc(void);					// 0092D110 { return false; }
	virtual void	Unk_3F(bool arg);					// 00588F30 { return; }
	virtual UInt32	Unk_40(UInt32 arg0, UInt32 arg1);	// 00A5F140 { return nullptr; }
	virtual void	Unk_41(void * arg);					// 0049FC90
	virtual bool	Unk_42(void);						// 0049E900 "EditorMarker.nif"
	virtual bool	Unk_43(void);						// 0049E9B0
	virtual bool	Unk_44(void);						// 0049E9E0
	virtual void	Unk_45(UInt32 arg0, UInt32 arg1);	// 004D43E0 { return; }
	virtual UInt32	Unk_46(void);						// 005EADD0 { return nullptr; }
	virtual UInt32	Unk_47(void);						// 005EADD0 { return nullptr; }
	virtual void *	Unk_48(void);						// 0049F730

public:
	// @members
	// vtbl						0x01083D14			// 000
};
