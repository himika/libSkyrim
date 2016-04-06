#pragma once

#include "../../FormComponents/TESForm.h"


/*==============================================================================
class TESCombatStyle +0000 (_vtbl=010826D4)
0000: class TESCombatStyle
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 94
class TESCombatStyle : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::CombatStyle };

	// @override
	virtual void	Unk_04(void) override;				// 00496790
	virtual bool	LoadForm(TESFile *arg) override;	// 00496800
	virtual void	InitItem(void) override;			// 0049AF70

	// 28
	struct General	// CSGD
	{
		float	offensiveMult;		// 00 - init'd to 0.5
		float	defensiveMult;		// 04 - init'd to 0.5
		float	groupOffensiveMult;	// 08 - init'd to 1
		float	meleeMult;			// 0C - init'd to 1
		float	magicMult;			// 10 - init'd to 1
		float	rangedMult;			// 14 - init'd to 1
		float	shoutMult;			// 18 - init'd to 1
		float	unarmedMult;			// 1C - init'd to 1
		float	staffMult;		// 20 - init'd to 1
		float	avoidThreatChance;	// 24 - init'd to 0.2
	};

	// 20
	struct Melee	// CSME
	{
		float	attackStaggeredMult;		// 00 - init'd to 1
		float	powerAttackStaggeredMult;	// 04 - init'd to 1
		float	powerAttackBlockingMult;	// 08 - init'd to 1
		float	bashMult;					// 0C - init'd to 1
		float	bashRecoiledMult;			// 10 - init'd to 1
		float	bashAttackMult;				// 14 - init'd to 1
		float	bashPowerAttackMult;		// 18 - init'd to 1
		float	specialAttackMult;			// 1C - init'd to 0.1
	};

	// 10
	struct CloseRange	// CSCR
	{
		float	duelingCircleMult;		// 00 - init'd to 0.2
		float	duelingFallbackMult;	// 04 - init'd to 0.2
		float	flankingFlankDistance;	// 08 - init'd to 0.2
		float	flankingStalkTime;		// 0C - init'd to 0.2
	};

	// 4
	struct LongRange	// CSLR
	{
		float	strafeMult;		// 00 - init'd to 0.2
	};

	// 20
	struct Flight	// CSFL
	{
		float	hoverChance;		// 00 - init'd to 0.5
		float	diveBombChance;		// 04 - init'd to 1
		float	groundAttackChance;	// 08 - init'd to 0.5
		float	hoverTime;			// 0C - init'd to 0.5
		float	unk10;				// 10 - init'd to 0.5
		float	perchAttackChance;	// 14 - init'd to 0.5
		float	unk18;				// 18 - init'd to 0.5
		float	flyingAttackChance;	// 1C - init'd to 0.75
	};

	enum {
		kFlag_Dueling = 1,
		kFlag_Flanking = 2,
		kFlag_AllowDualWielding = 4
	};


	// @members
	General	general;			// 14 - CSGD
	Melee	melee;				// 3C - CSME
	CloseRange	closeRange;		// 5C - CSCR
	LongRange	longRange;		// 6C - CSLR
	Flight	flight;				// 70 - CSFL
	UInt8	flags;				// 90 - DATA
	UInt8	pad91[3];			// 91
};
