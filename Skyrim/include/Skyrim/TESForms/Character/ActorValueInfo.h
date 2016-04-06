#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../FormComponents/TESFullName.h"
#include "../../FormComponents/TESDescription.h"
#include "../../FormComponents/TESIcon.h"
#include "../../FormComponents/BGSSkillPerkTreeNode.h"

class BGSSkillPerkTreeNode;

/*==============================================================================
class ActorValueInfo +0000 (_vtbl=010BF314)
0000: class ActorValueInfo
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
001C: |   class TESDescription
001C: |   |   class BaseFormComponent
0028: |   class TESIcon
0028: |   |   class TESTexture
0028: |   |   |   class BaseFormComponent
==============================================================================*/
// C8
class ActorValueInfo : public TESForm,
	public TESFullName,		// 14
	public TESDescription,	// 1C
	public TESIcon			// 28
{
public:
	enum { kTypeID = (UInt32)FormType::ActorValueInfo };

	// @override
	// 005AF190 Unk_05
	// 005AEB80 LoadForm
	// 005AF2F0 InitItem

	enum {
		kSkillUseMult = 0,
		kSkillOffsetMult,
		kSkillImproveMult,
		kSkillImproveOffset
	};

	// @members
	const char				* name;				// 30 - second ctor argument
	BSFixedString			unk34;				// 34
	UInt32					unk38;				// 38
	UInt32					unk3C;				// 3C
	UInt32					unk40;				// 40
	UInt32					unk44;				// 44
	UInt32					unk48[0x0F];		// 48 - init'd to 0xA4
	UInt32					numSubTypes;		// 84
	const char				* subTypes[0x0A];	// 88 - init'd to 0
	float					* skillUsages;		// B0
	UInt32					unkB4;				// B4
	UInt32					unkB8;				// B8
	BGSSkillPerkTreeNode	* perkTree;			// BC - BGSSkillPerkTreeNode
	UInt8					padC0[8];			// C0 - ? not initialized
};
STATIC_ASSERT(sizeof(ActorValueInfo) == 0xC8);
