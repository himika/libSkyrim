#pragma once

#include "TESObjectREFR.h"

/*==============================================================================
class Explosion +0000 (_vtbl=010D7F74)
0000: class Explosion
0000: |   class TESObjectREFR
0000: |   |   class TESForm
0000: |   |   |   class BaseFormComponent
0014: |   |   class BSHandleRefObject
0014: |   |   |   class NiRefObject
001C: |   |   class BSTEventSink<struct BSAnimationGraphEvent>
0020: |   |   class IAnimationGraphManagerHolder
==============================================================================*/
// D8
class Explosion : public TESObjectREFR
{
public:
	virtual ~Explosion();			// 00792E00

	// @override
	//virtual void Unk_00(void) override;		// 00792E00
	//virtual void Unk_0E(void) override;		// 00790B90
	//virtual void Unk_0F(void) override;		// 00790290
	//virtual void Unk_10(void) override;		// 0078FAB0
	//virtual void Unk_11(void) override;		// 00791960
	//virtual void Unk_12(void) override;		// 0078FE70
	//virtual void Unk_50(void) override;		// 0068E260
	//virtual void Unk_51(void) override;		// 0078FAE0
	//virtual void Unk_5C(void) override;		// 0078F7A0
	//virtual void Unk_66(void) override;		// 00792740
	//virtual void Unk_6B(void) override;		// 0078FB80
	virtual Explosion *	Unk_8E(void) override;			// 00C707B0 { return this; }
	virtual bool	Unk_90(UInt32 arg) override;		// 004091A0 { return false; }

	// @add
	virtual void Unk_A2(void);		// 00790600
	virtual void Unk_A3(void);		// 00793BD0
	virtual void Unk_A4(void);		// 00791980
};
