#pragma once

#include "TESBoundAnimObject.h"

#include "../FormComponents/TESActorBaseData.h"
#include "../FormComponents/TESContainer.h"
#include "../FormComponents/TESSpellList.h"
#include "../FormComponents/TESAIForm.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/ActorValueOwner.h"
#include "../FormComponents/BGSDestructibleObjectForm.h"
#include "../FormComponents/BGSSkinForm.h"
#include "../FormComponents/BGSKeywordForm.h"
#include "../FormComponents/BGSAttackDataForm.h"
#include "../FormComponents/BGSPerkRankArray.h"

class TESCombatStyle;

/*==============================================================================
class TESActorBase +0000 (_vtbl=010A56A4)
0000: class TESActorBase
0000: |   class TESBoundAnimObject
0000: |   |   class TESBoundObject
0000: |   |   |   class TESObject
0000: |   |   |   |   class TESForm
0000: |   |   |   |   |   class BaseFormComponent
0020: |   class TESActorBaseData
0020: |   |   class BaseFormComponent
0058: |   class TESContainer
0058: |   |   class BaseFormComponent
0064: |   class TESSpellList
0064: |   |   class BaseFormComponent
006C: |   class TESAIForm
006C: |   |   class BaseFormComponent
0084: |   class TESFullName
0084: |   |   class BaseFormComponent
008C: |   class ActorValueOwner
0090: |   class BGSDestructibleObjectForm
0090: |   |   class BaseFormComponent
0098: |   class BGSSkinForm
0098: |   |   class BaseFormComponent
00A0: |   class BGSKeywordForm
00A0: |   |   class BaseFormComponent
00AC: |   class BGSAttackDataForm
00AC: |   |   class BaseFormComponent
00B4: |   class BGSPerkRankArray
00B4: |   |   class BaseFormComponent
==============================================================================*/
// C0
class TESActorBase : public TESBoundAnimObject,
	public TESActorBaseData,			// 20
	public TESContainer,				// 58
	public TESSpellList,				// 64
	public TESAIForm,					// 6C
	public TESFullName,					// 84
	public ActorValueOwner,				// 8C
	public BGSDestructibleObjectForm,	// 90
	public BGSSkinForm,					// 98
	public BGSKeywordForm,				// A0
	public BGSAttackDataForm,			// AC
	public BGSPerkRankArray				// B4

{
public:
	// @override
	virtual bool	MarkChanged(UInt32 changed) override;			// 0055B970
	virtual void	Unk_0B(UInt32 arg) override;					// 0055B9D0
	virtual void	SaveBuffer(BGSSaveFormBuffer *buf) override;	// 0055B840
	virtual void	LoadBuffer(BGSLoadFormBuffer *buf) override;	// 0055B8E0
	virtual void	Unk_12(BGSLoadFormBuffer *buf) override;		// 005F92A0 { return TESForm::Unk_12(buf); }
	virtual bool	IsAutoCalc(void) override;						// 0055B530 { return (formType == FormType::NPC) ? ((this->TESActorBaseData::flags >> 4) & 1) : 0; }
	virtual void	Unk_3F(bool arg) override;						// 0055B550 { if (formType == FormType::NPC) this->TESActorBaseData::Unk_0044D3D0(10, arg, 1); }

	// @add
	virtual bool				Unk_54(void);							// 0092D110 { return false; }
	virtual TESCombatStyle *	GetCombatStyle(void);					// 005EADD0	{ return nullptr; } TESNPC={ return combatStyle; }
	virtual void				SetCombatStyle(TESCombatStyle *arg);	// 00588F30 { return; }
	virtual TESActorBase *		Unk_57(void);							// 00C707B0 { return this; }

	// @members
	//void	** _vtbl	// 00 - 010A56A4
};
STATIC_ASSERT(sizeof(TESActorBase) == 0xC0);
