#pragma once

#include "TESObjectREFR.h"

/*==============================================================================
class Projectile +0000 (_vtbl=010D91B4)
0000: class Projectile
0000: |   class TESObjectREFR
0000: |   |   class TESForm
0000: |   |   |   class BaseFormComponent
0014: |   |   class BSHandleRefObject
0014: |   |   |   class NiRefObject
001C: |   |   class BSTEventSink<struct BSAnimationGraphEvent>
0020: |   |   class IAnimationGraphManagerHolder
==============================================================================*/
// 140
class Projectile : public TESObjectREFR
{
public:
	// @add
	virtual void Unk_A2(void);		// 0092D110 (void) { return false; }
	virtual void Unk_A3(void);		// 0092D110 (void) { return false; }
	virtual void Unk_A4(void);		// 0092D110 (void) { return false; }
	virtual void Unk_A5(void);		// 0092D110 (void) { return false; }
	virtual void Unk_A6(void);		// 0092D110 (void) { return false; }
	virtual void Unk_A7(void);		// 0092D110 (void) { return false; }
	virtual void Unk_A8(void);		// 006C50E0 (void) { return; }
	virtual void Unk_A9(void);		// 006C50E0 (void) { return; }
	virtual void Unk_AA(void);		// 0079D200
	virtual void Unk_AB(void);		// 00F51EE8 (pure)
	virtual void Unk_AC(void);		// 007A3850
	virtual void Unk_AD(void);		// 0079BFE0
	virtual void Unk_AE(void);		// 0092D110 (void) { return false; }
	virtual void Unk_AF(void);		// 0079BF10
	virtual void Unk_B0(void);		// 0064A3E0
	virtual void Unk_B1(void);		// 0092D110 (void) { return false; }
	virtual void Unk_B2(void);		// 006C50E0 (void) { return; }
	virtual void Unk_B3(void);		// 0079C8A0
	virtual void Unk_B4(void);		// 0079E450
	virtual void Unk_B5(void);		// 0079CF60
	virtual void Unk_B6(void);		// 0079D8D0
	virtual void Unk_B7(void);		// 007A3C50
	virtual void Unk_B8(void);		// 009B86F0 (void) { return true; }
	virtual void Unk_B9(void);		// 0092D110 (void) { return false; }
	virtual void Unk_BA(void);		// 0092D110 (void) { return false; }
	virtual void Unk_BB(void);		// 0079E9B0
	virtual void Unk_BC(void);		// 0079D5D0
	virtual void Unk_BD(void);		// 0079EBB0
	virtual void Unk_BE(void);		// 007A2F90
	virtual void Unk_BF(void);		// 006C50E0 (void) { return; }
	virtual void Unk_C0(void);		// 006C50E0 (void) { return; }
	virtual void Unk_C1(void);		// 0092D110 (void) { return false; }

	class LaunchData
	{
	public:
		virtual ~LaunchData();

		float	unk04[(0x68 - 0x04) >> 2];
		bool	unk68[7];
	};

	// @members
	UInt32 pad54[(0x140 - 0x54) >> 2];
};
STATIC_ASSERT(sizeof(Projectile) == 0x140);
