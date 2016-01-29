#pragma once

#include "TESForm.h"
#include "../FormComponents/TESFullName.h"
#include "../FormComponents/TESAIForm.h"

#include "../BSCore/BSTArray.h"

class TESNPC;
class TESFaction;

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


	struct IDecalRefFunctor
	{
		virtual ~IDecalRefFunctor();		// 004C1200
		virtual void operator()(void) = 0;
	};

	// @members

	// 8
	struct Data
	{
		UInt32	unk0;
		UInt32	unk4;
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

	enum {
		kFlag_Interior = 1,
		kFlag_Public = 0x20
	};

	/// <summary>Is this cell an interior cell ?</summary>
	bool IsInterior(void) const {
		return (unk2C & kFlag_Interior) != 0;
	}

	bool IsPublic(void) const {
		return (unk2C & kFlag_Public) != 0;
	}

	TESForm* GetOwner() const;
	
	/// <summary>Obtains the actor base object that owns this cell.</summary>
	TESNPC* GetActorOwner() const;

	/// <summary>Obtains the faction that owns this cell.</summary>
	TESFaction* GetFactionOwner() const;

	DEFINE_MEMBER_FN(GetNorthRotation, double, 0x004C0FC0);
	DEFINE_MEMBER_FN(SetPublic, void, 0x004C0260, bool bPublic);

	// @memebrs
	Data						unk1C;		// 1C
	Data						unk24;		// 24
	UInt16						unk2C;		// 2C - kFlagPublic = 0x20
	UInt16						unk2E;		// 2E
	UInt8						unk30;		// 30
	UInt8						unk31;		// 31
	UInt8						unk32;		// 32
	UInt8						pad33;		// 33
	TESAIForm::Data				unk34;		// 34 - ExtraDataList
	TVDT						* unk3C;	// 3C
	UInt32						unk40;		// 40
	UInt32						unk44;		// 44
	UInt32						unk48;		// 48
	BSTArray<TESObjectREFR*>	objectList;	// 4C
	UInt32						unk58;		// 58
	UInt32						unk5C;		// 5C
	BSTArray<void*>				unk60;		// 60
	BSTArray<void*>				unk6C;		// 6C
	Data						unk78;		// 78
	UInt32						unk80;		// 80
	UInt32						unk84;		// 84
	UInt32						unk88;		// 88
	UInt32						unk8C;		// 8C

private:
	DEFINE_MEMBER_FN_const(GetOwner_Impl, TESForm*, 0x004C4DC0);

};
STATIC_ASSERT(offsetof(TESObjectCELL, objectList) == 0x4C);
STATIC_ASSERT(sizeof(TESObjectCELL) == 0x90);