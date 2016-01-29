#pragma once

#include "TESActorBase.h"
#include "../FormComponents/TESRaceForm.h"
#include "../FormComponents/BGSOverridePackCollection.h"
#include "../Events/ActorEvent.h"
#include "../Events/MenuEvent.h"

class BGSColorForm;
class TESClass;
class TESCombatStyle;
class BGSOutfit;
class BGSHeadPart;
class BSFaceGenNiNode;
class NiColorA;
class TintMask;

/*==============================================================================
class TESNPC +0000 (_vtbl=010A5964)
0000: class TESNPC
0000: |   class TESActorBase
0000: |   |   class TESBoundAnimObject
0000: |   |   |   class TESBoundObject
0000: |   |   |   |   class TESObject
0000: |   |   |   |   |   class TESForm
0000: |   |   |   |   |   |   class BaseFormComponent
0020: |   |   class TESActorBaseData
0020: |   |   |   class BaseFormComponent
0058: |   |   class TESContainer
0058: |   |   |   class BaseFormComponent
0064: |   |   class TESSpellList
0064: |   |   |   class BaseFormComponent
006C: |   |   class TESAIForm
006C: |   |   |   class BaseFormComponent
0084: |   |   class TESFullName
0084: |   |   |   class BaseFormComponent
008C: |   |   class ActorValueOwner
0090: |   |   class BGSDestructibleObjectForm
0090: |   |   |   class BaseFormComponent
0098: |   |   class BGSSkinForm
0098: |   |   |   class BaseFormComponent
00A0: |   |   class BGSKeywordForm
00A0: |   |   |   class BaseFormComponent
00AC: |   |   class BGSAttackDataForm
00AC: |   |   |   class BaseFormComponent
00B4: |   |   class BGSPerkRankArray
00B4: |   |   |   class BaseFormComponent
00C0: |   class TESRaceForm
00C0: |   |   class BaseFormComponent
00C8: |   class BGSOverridePackCollection
00C8: |   |   class BaseFormComponent
00DC: |   class BSTEventSink<class MenuOpenCloseEvent>
==============================================================================*/
// 164
class TESNPC : public TESActorBase,
	public TESRaceForm,							// 0C0
	public BGSOverridePackCollection,			// 0C8
	public BSTEventSink<MenuOpenCloseEvent>		// 0DC
{
public:
	enum { kTypeID = (UInt32)FormType::NPC };

	// @override TESForm
	virtual const char *	GetAliasName(const BSFixedString &param) override;					// 00560F90
	virtual void			CopyFrom(TESForm * srcForm) override;								// 00562FB0
	virtual bool			ActivateReference(TESObjectREFR* targetRef, TESObjectREFR* activatorRef, UInt32 arg2, UInt32 arg3, UInt32 arg4) override;	// 005672C0

	// @override TESObject
	virtual void	Unk_41(void * arg) override;												// 00569970

	// @override TESBoundObject
	virtual void	Unk_49(UInt32 arg) override;												// 0072F970
	virtual BGSVoiceType	* GetVoiceType(void) const override;								// 00563620
	virtual UInt32	Unk_4B(UInt32 arg) override;												// 00566220
	virtual bool	GetCrosshairText(TESObjectREFR *ref, BSString *dst, bool unk) override;		// 00566910
	virtual bool	Unk_4E(void * arg0, UInt8 arg1, UInt32 arg2, float arg3) override;			// 00562450

	// @override TESActorBase
	virtual TESCombatStyle *	GetCombatStyle(void) override;									// 00560AF0 { return combatStyle; }
	virtual void				SetCombatStyle(TESCombatStyle *arg) override;					// 00588F30 { combatStyle = arg; }

	struct FaceMorphs
	{
		enum
		{
			kNumOptions = 19,
			kNumPresets = 4,
		};

		float	option[kNumOptions];
		UInt32	presets[kNumPresets];
	};

	struct HeadData {
		BGSColorForm * hairColor;
		BGSTextureSet * headTexture;	// Only seems to apply to the player
	};

	// members @0E0
	UInt8			unk0E0[0x12];		// 0E0 - init'd to 5
	UInt8			unk0F2[0x12];		// 0F2 - init'd to 0
	UInt8			pad104[0x10A - 0x104];	// 104
	UInt16			unk10A;				// 10A
	TESClass		* npcClass;			// 10C
	HeadData		* headData;			// 110
	UInt32			unk114;				// 114
	TESCombatStyle	* combatStyle;		// 118
	UInt32			unk11C;				// 11C
	UInt32			unk120;				// 120
	TESNPC			* nextTemplate;		// 124
	float			height;				// 128
	float			weight;				// 12C
	UInt32			pad130;				// 130
	BSFixedString	shortName;			// 134
	TESObjectARMO	* skinFar;			// 138
	BGSOutfit		* defaultOutfit;	// 13C
	BGSOutfit		* sleepOutfit;		// 140
	UInt32			unk144;				// 144
	TESFaction*		faction;			// 148
	BGSHeadPart		** headparts;		// 14C
	UInt8			numHeadParts;		// 150
	UInt8			unk151;				// 151
	UInt8			unk152;				// 152
	UInt8			unk153;				// 153
	struct Color {						// 797979 Transparent
		UInt8   red, green, blue; // 154 - 156 - Skin Color
	} color;
	UInt8			pad157;				// 157
	UInt32			unk158;				// 158 // Relationships?
	FaceMorphs		* faceMorph;		// 15C
	UInt32			unk160;				// 160


	TESRace * GetRace() const {
		return race;
	}

	DEFINE_MEMBER_FN_const(GetShortName, const char*, 0x00560350);
	//DEFINE_MEMBER_FN(GetHeadPartByType, BGSHeadPart *, 0x00561270, UInt32);
	DEFINE_MEMBER_FN_const(GetSex, char, 0x0055B510);
	DEFINE_MEMBER_FN_const(HasOverlays, bool, 0x005681C0);

	// Swaps a headPart of the same type as target with target
	DEFINE_MEMBER_FN(ChangeHeadPart, void, 0x00567CE0, BGSHeadPart * target);

	struct MorphAction {
		BSFaceGenNiNode * faceNode;
		TESNPC * npc;
		const char ** morphName;
		float	value;
	};

	// Applies a morph to all parts of a head
	DEFINE_MEMBER_FN(ApplyMorph, void, 0x005A4870, MorphAction * morphAction);

	// Updates the neck seam when weight changed
	DEFINE_MEMBER_FN(UpdateNeck, void, 0x00567C30, BSFaceGenNiNode * faceNode);

	// Computes RGB SkinTone from RGBA TintMask
	DEFINE_MEMBER_FN(SetSkinFromTint, void, 0x005643C0, NiColorA * result, TintMask * tintMask, UInt32 compute, UInt32 unk1);

	void SetFaceTexture(BGSTextureSet * textureSet);
	void SetHairColor(BGSColorForm * hairColor);

	BGSHeadPart * GetHeadPartByType(UInt32 type);
	BGSHeadPart * GetHeadPartOverlayByType(UInt32 type);
	BGSHeadPart * GetCurrentHeadPartByType(UInt32 type);
	TESNPC * GetRootTemplate();
};

STATIC_ASSERT(sizeof(TESNPC) == 0x164);
