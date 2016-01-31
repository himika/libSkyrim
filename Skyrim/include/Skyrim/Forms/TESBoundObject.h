#pragma once

#include "TESObject.h"

class BSString;
class BGSVoiceType;

/*==============================================================================
class TESBoundObject +0000 (_vtbl=01083E6C)
0000: class TESBoundObject
0000: |   class TESObject
0000: |   |   class TESForm
0000: |   |   |   class BaseFormComponent
==============================================================================*/
// 20
class TESBoundObject : public TESObject
{
public:
	struct Bound
	{
		UInt16	x;
		UInt16	y;
		UInt16	z;
	};

	// @override TESObject
	virtual void	Unk_26(TESFile *arg) override;				// 0049EB60
	virtual bool	Has3D(void) override;						// 009B86F0 { return true; }
	virtual bool	ActivateReference(TESObjectREFR* targetRef, TESObjectREFR* activatorRef, UInt32 arg2, UInt32 arg3, UInt32 arg4) override;	// 0049E460
	virtual UInt32	Unk_40(UInt32 arg0, UInt32 arg1) override;	// 0049EC90
	virtual bool	Unk_44(void) override;						// 0049E440

	// @add
	virtual void	Unk_49(UInt32 arg);							// 00588F30 { return; }
	virtual BGSVoiceType	* GetVoiceType(void) const;			// 005EADD0 { return nullptr; }
	virtual UInt32	Unk_4B(UInt32 arg);							// 0049E420 { return Unk_40(arg, 0); } model-related?
	virtual bool	Unk_4C(void);								// 0049E8B0 { return true; }
	virtual bool	GetCrosshairText(TESObjectREFR *ref, BSString *dst, bool unk);	// 0049EBC0 steal/take string - called from 0073A136
	virtual bool	Unk_4E(void * arg0, UInt8 arg1, UInt32 arg2, float arg3);	// 004995F0
	virtual void	OnRemovedFrom(TESObjectREFR *ref);			// 00588F30 { return; } TESAmmo=004961B0 - RemoveAttackedArrow3D ?
	virtual void	Unk_50(UInt32 arg);							// 00588F30 { return; }
	virtual void	Unk_51(void);								// 006C50E0 { return; }
	virtual void	Unk_52(void);								// 006C50E0 { return; }
	virtual void	Unk_53(void);								// 006C50E0 { return; }

	// @members
	//void	** vtbl		// 00 - 0x01083E6C	
	Bound	bounds;		// 14
	Bound	bounds2;	// 1A

private:
	DEFINE_MEMBER_FN(ctor, void, 0x0049EAB0);
};

STATIC_ASSERT(sizeof(TESBoundObject) == 0x20);
