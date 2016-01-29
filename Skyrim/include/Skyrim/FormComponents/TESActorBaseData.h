#pragma once

#include "BaseFormComponent.h"
#include "../BSCore/BSTArray.h"

class BGSVoiceType;
class TESFaction;

// 38
class TESActorBaseData : public BaseFormComponent
{
public:
	virtual void			Unk_04(UInt32 arg);			// 00588F30 (UInt32 arg) { return; }
	virtual bool			GetFlag20000000(void);		// 0044D9C0 { return (flags >> 0x1D) & 1; }
	virtual bool			GetFlag80000000(void);		// 0044D9D0 { return (flags & 0x80000000); }
	virtual bool			Unk_07(void);				// 009B86F0 (void) { return true; }
	virtual BGSVoiceType *	GetVoiceType(void);			// 0044D9E0 { return voiceType; }

	DEFINE_MEMBER_FN(GetLevel, UInt16, 0x0044D4D0);

	enum {
		kFlag_PCLevelMult = 0x80
	};

	// flags bit4 = auto calc

	struct
	{
		bool female : 1;				// 00
		bool essential : 1;				// 01
		bool unk02 : 1;					// 02
		bool respawn : 1;				// 03
		bool autoCalc : 1;				// 04
		bool unique : 1;				// 05
		bool dontAffectStealth : 1;		// 06
		bool pcLevelMult : 1;			// 07
		bool unk08 : 1;					// 08
		bool unk09 : 1;					// 09 not used
		bool unk0A : 1;					// 0A not used
		bool protect : 1;				// 0B
		bool unk0C : 1;					// 0C not used
		bool unk0D : 1;					// 0D not used
		bool summonable : 1;			// 0E
		bool unk0F : 1;					// 0F not used
		bool doesntBleed : 1;			// 10
		bool unk11 : 1;					// 11 FormID=00013475, 00013479, 0001347A, 02003361, 02003362, 02003363, 02011E5E
		bool bleedoutOverride : 1;		// 12
		bool oppositeGenderAnims : 1;	// 13
		bool simpleActor : 1;			// 14
		bool unk15 : 1;					// 15 ???
		bool unk16 : 1;					// 16 not used
		bool unk17 : 1;					// 17 not used
		bool unk18 : 1;					// 18 not used
		bool unk19 : 1;					// 19 000132A1, 0003BB85, 00075C7F, 000D0573
		bool unk1A : 1;					// 1A not used
		bool unk1B : 1;					// 1B not used
		bool unk1C : 1;					// 1C not used
		bool ghost : 1;					// 1D 
		bool unk1E : 1;					// 1E not used
		bool invulnerable : 1;			// 1F
	} flags;					// 04 - init'd to 0
	UInt16				unk08;	// 08 - init'd to 0
	UInt16				unk0A;	// 0A - init'd to 0
	UInt16				level;	// 0C - init'd to 1	(CK Multiplier * 1000 if PCLevelMult is true)
	UInt16				minLevel;	// 0E - init'd to 0
	UInt16				maxLevel;	// 10 - init'd to 0
	UInt16				unk12;	// 12 - init'd to 0x64 (100)
	UInt16				unk14;	// 14 - init'd to iBaseDisposition (35)
	UInt16				unk16;	// 16 - init'd to 0
	UInt16				unk18;	// 18 - init'd to 0
	UInt16				unk1A;	// 1A - init'd to 0
	UInt32				unk1C;	// 1C
	BGSVoiceType		* voiceType;	// 20
	UInt32				unk24;	// 24
	UInt32				unk28;	// 28 - init'd to 0
	BSTArray<TESFaction*>	unk2C;	// 2C
};
