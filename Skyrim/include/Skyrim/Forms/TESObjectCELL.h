#pragma once

#include "TESForm.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/TESAIForm.h"
#include "../FormComponents/BaseExtraList.h"


#include "../BSCore/BSTArray.h"

class TESNPC;
class TESFaction;
class BGSLightingTemplate;

class BSPortalGraph;
class BSMultiBoundNode;
class NiNode;

/*==============================================================================
class TESObjectCELL +0000 (_vtbl=01087EC4)
0000: class TESObjectCELL
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class TESFullName
0014: |   |   class BaseFormComponent
==============================================================================*/
// 90
class TESObjectCELL : public TESForm,
	public TESFullName				// 14
{
public:
	enum { kTypeID = (UInt32)FormType::Cell };

	enum
	{
		kFlag_Interior = 1,
		kFlag_Public = 0x20
	};

	/*==============================================================================
	struct TESObjectCELL::IDecalRefFunctor +0000 (_vtbl=01087B54)
	0000: struct TESObjectCELL::IDecalRefFunctor
	==============================================================================*/
	struct IDecalRefFunctor
	{
		virtual ~IDecalRefFunctor();		// 004C1200
		virtual void operator()(void) = 0;
	};

	// 8
	struct Data
	{
		UInt32	unk0;
		UInt32	unk4;
	};

	struct Data88
	{
		BSPortalGraph *		unk00;
		BSMultiBoundNode *	unk04;
		NiNode *			unk08;
		NiNode *			unk0C;
	};

	struct TVDT
	{
		struct TVDT1
		{
			UInt32	* unk00;	// array?
			UInt32	* unk04;	// array?
			UInt32	unk08;		// size?
		};

		struct TVDT0
		{
			TVDT1	* unk00;
			UInt32	unk04;
			UInt32	unk08;	// skip TVDT1 if > 1
		};

		UInt32	unk00;
		UInt32	unk04;
		UInt32	unk08;
		TVDT0	* unk0C;
		// ...
	};

	virtual ~TESObjectCELL();			// 004CD5B0

	// @override class TESForm : (vtbl=01087EC4)
	virtual void			Unk_05(void) override;									// 004C4130
	virtual bool			LoadForm(TESFile *mod) override;						// 004C41E0
	virtual TESForm *		DupulicateForm(UInt32 arg1, void * arg2) override;		// 00A5F140 { return nullptr; }
	virtual bool			Unk_0C(UInt32 arg) override;							// 004C0BC0
	virtual void			SaveBuffer(BGSSaveFormBuffer *buf) override;			// 004C5FE0
	virtual void			LoadBuffer(BGSLoadFormBuffer *buf) override;			// 004C2F90
	virtual void			Unk_12(BGSLoadFormBuffer *buf) override;				// 004C3120
	virtual void			InitItem(void) override;								// 004CB3C0
	virtual void			GetFormDesc(char * buf, UInt32 bufLen) override;		// 004C0CE0
	virtual void			SetFlag00000002(bool set) override;						// 004C0EE0
	virtual bool			Unk_30(void * arg0, UInt32 arg1, UInt32 arg2) override;	// 004C4B20
	virtual bool			Unk_31(void * dst, void * unk) override;				// 004C4C20
	virtual const char *	GetName(void) override;									// 004C2B00 { if (extraData->GetEditorID()){ return extraData->GetEditorID(); } return (IsInterior() ? "" : "wilderness"); }
	virtual bool			SetName(const char * str) override;						// 004C2AA0
	virtual bool			Unk_34(void) override;									// 009B86F0 { return true; }
	virtual bool			Unk_36(FormType arg) override;							// 004C2F50

	/// <summary>Returns whether this cell is currently 'attached' or not. (In the loaded area)</summary>
	bool IsAttached() const {
		return (unk30 == 7);
	}

	/// <summary>Is this cell an interior cell ?</summary>
	bool IsInterior(void) const {
		return (unk2C & kFlag_Interior) != 0;
	}

	bool IsPublic(void) const {
		return (unk2C & kFlag_Public) != 0;
	}

	TESForm * GetOwner() const;
	
	/// <summary>Obtains the actor base object that owns this cell.</summary>
	TESNPC * GetActorOwner() const;

	/// <summary>Obtains the faction that owns this cell.</summary>
	TESFaction * GetFactionOwner() const;

	DEFINE_MEMBER_FN(GetNorthRotation, double, 0x004C0FC0);
	DEFINE_MEMBER_FN(SetPublic, void, 0x004C0260, bool bPublic);


	// @memebrs
	Data						unk1C;				// 1C
	Data						unk24;				// 24
	UInt16						unk2C;				// 2C - kFlagPublic = 0x20
	UInt16						unk2E;				// 2E
	UInt8						unk30;				// 30
	UInt8						unk31;				// 31
	UInt8						unk32;				// 32
	UInt8						pad33;				// 33
	BaseExtraList				extraData;			// 34
	TVDT						* unk3C;			// 3C
	UInt32						unk40;				// 40
	UInt32						unk44;				// 44
	UInt32						unk48;				// 48
	BSTArray<TESObjectREFR*>	objectList;			// 4C
	UInt32						unk58;				// 58
	UInt32						unk5C;				// 5C
	BSTArray<void*>				unk60;				// 60
	BSTArray<void*>				unk6C;				// 6C
	Data						unk78;				// 78
	UInt32						unk80;				// 80
	void						* unk84;			// 84 - related to light level
	Data88						* unk88;			// 88
	BGSLightingTemplate			* lightingTemplate;	// 8C

private:
	DEFINE_MEMBER_FN_const(GetOwner_Impl, TESForm*, 0x004C4DC0);

};
STATIC_ASSERT(offsetof(TESObjectCELL, objectList) == 0x4C);
STATIC_ASSERT(sizeof(TESObjectCELL) == 0x90);