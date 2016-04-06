#pragma once

#include "../../FormComponents/TESForm.h"
#include "../../NetImmerse/NiSmartPointer.h"
#include "../../BSMain/BSHandleRefObject.h"
#include "../../BSCore/BSTEvent.h"
#include "../../Events/ActorEvent.h"
#include "../../FormComponents/BaseExtraList.h"
#include "../../FormComponents/MagicCaster.h"
#include "../../Animation/IAnimationGraphManagerHolder.h"
#include "../../NetImmerse/NiPoint3.h"


class NiNode;
class BGSScene;
class BGSKeyword;
class BSFaceGenNiNode;
class BSFaceGenAnimationData;
class TESObjectCELL;
class TESNPC;
class TESPackage;
class BGSLocation;
class MagicTarget;
class BGSLocationRefType;
class Explosion;
class Projectile;
class TESContainer;
class BSAnimNoteReceiver;
struct LockState;

NiSmartPointer(TESObjectREFR)


// ??
class ActorWeightData
{
public:
	UInt32	unk00;		// 00 - Refcount?
	void	* unk04;	// 04
	void	* unk08;	// 08

	DEFINE_MEMBER_FN(UpdateWeightData, void, 0x0046D690);
	// DEFINE_MEMBER_FN(Unk_02, void, 0x004145F0);
};

// ??
class ActorWeightModel
{
public:
	enum {
		kWeightModel_Small = 0,
		kWeightModel_Large = 1
	};
	ActorWeightData * weightData;
};

/*==============================================================================
class TESObjectREFR +0000 (_vtbl=01089424)
0000: class TESObjectREFR
0000: |   class TESForm
0000: |   |   class BaseFormComponent
0014: |   class BSHandleRefObject
0014: |   |   class NiRefObject
001C: |   class BSTEventSink<struct BSAnimationGraphEvent>
0020: |   class IAnimationGraphManagerHolder
==============================================================================*/
// 54
class TESObjectREFR : public TESForm,
	public BSHandleRefObject,						// 14
	public BSTEventSink <BSAnimationGraphEvent>,	// 1C
	public IAnimationGraphManagerHolder				// 20
{
public:
	enum { kTypeID = (UInt32)FormType::Reference };

	enum
	{
		kFlag_Harvested = 0x2000
	};

	enum RemoveType
	{
		kRemoveType_Remove,
		kRemoveType_Steal,
		kRemoveType_Trade,
		kRemoveType_Drop,
		kRemoveType_Take,
		kRemoveType_Unk05
	};

	//TESObjectREFR();																// 004E6930
	virtual ~TESObjectREFR();														// 004E6FA0

	// @override TESForm : (vtbl=01089424)
	virtual void			Unk_04(void) override;									// 004E67E0
	virtual void			Unk_05(void) override;									// 004D92E0
	virtual bool			LoadForm(TESFile *mod) override;						// 004DDFB0
	virtual TESForm *		DupulicateForm(UInt32 arg1, void * arg2) override;		// 004D6EB0
	virtual bool			PreSaveBuffer(BGSSaveFormBuffer *buf) override;			// 004D4B50
	virtual void			SaveBuffer(BGSSaveFormBuffer *buf) override;			// 004D4C00
	virtual void			LoadBuffer(BGSLoadFormBuffer *buf) override;			// 004DE9E0
	virtual void			Unk_10(BGSLoadFormBuffer *buf) override;				// 004DB2B0
	virtual void			Unk_11(BGSLoadFormBuffer *buf) override;				// 004DECF0
	virtual void			Unk_12(BGSLoadFormBuffer *buf) override;				// 004E1DE0
	virtual void			InitItem(void) override;								// 004E5B60
	virtual UInt32			GetFormType(void) override;								// 004D4D60
	virtual void			GetFormDesc(char * buf, UInt32 bufLen) override;		// 004D7100
	virtual bool			GetFlag00010000(void) override;							// 004D52F0
	virtual bool			Unk_1A(void) override;									// 004D4E20 { return (baseForm->Is(FormType::Light) && baseForm->flags.unk10); }
	virtual bool			GetFlag00020000(void) override;							// 004D4EA0
	virtual bool			GetFlag02000000(void) override;							// 004D4EB0
	virtual bool			GetFlag00000200(void) override;							// 004D63B0
	virtual bool			GetFlag00000100(void) override;							// 004E6A40
	virtual void			SetFlag00000200(bool set) override;						// 004D63E0
	virtual bool			Unk_22(void) override;									// 004D6420
	virtual void			SetFlag00000020(bool set) override;						// 004D9820
	virtual void			SetFlag00000002(bool set) override;						// 004D4A90
	virtual bool			Unk_2A(void) override;									// 004D5020
	virtual TESForm *		Unk_2B(void) override;									// 00C707B0 { return this; }
	virtual TESObjectREFR *	GetReference(void) override;							// 00C707B0 { return this; }
	virtual bool			Unk_30(void * arg0, UInt32 arg1, UInt32 arg2) override;	// 004D7220
	virtual bool			Unk_31(void * dst, void * unk) override;				// 004D72D0
	virtual const char *	GetName(void) override;									// 004D94A0

	// @override class BSTEventSink<struct BSAnimationGraphEvent> : (vtbl=0108940C)
	virtual EventResult		ReceiveEvent(BSAnimationGraphEvent*, BSTEventSource<BSAnimationGraphEvent> *) override;		// 004E8D90

	// @override class IAnimationGraphManagerHolder : (vtbl=010893BC)
	virtual bool	GetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager> & out) override;	// 004E8110
	virtual bool	IAnimationGraphManagerHolder_Unk_03(UInt32 arg) override;							// 004E8130
	virtual bool	IAnimationGraphManagerHolder_Unk_04(UInt32 arg) override;							// 004E8D30
	virtual bool	IAnimationGraphManagerHolder_Unk_05(UInt32 arg) override;							// 004E8920
	virtual bool	IAnimationGraphManagerHolder_Unk_08(UInt32 arg) override;							// 004E95C0
	virtual void	IAnimationGraphManagerHolder_Unk_0D(UInt32 arg, UInt32 arg2) override;				// 004E89A0

	// @add
	virtual void	Unk_3B(void);										// 004E6470 Release TESObjectREFR
	virtual BGSLocation *	GetEditorLocation(void);					// 004D8420 Actor={ return editorLocation; }
	virtual bool	Unk_3D(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4);		// 004DB090 - ExtraStartingWorldOrCell
	virtual void	Unk_3E(UInt32 arg);									// 004D5E60 { extraData->GetByType<ExtraStartingPosition>()->unk20 = arg; }
	virtual void	Unk_3F(void);										// 004DB190
	virtual void	Unk_40(void);										// 004E1950 - ExtraSayTopicInfo
	virtual bool	Unk_41(void);										// 004DFE00
	virtual void	Unk_42(void);										// 004D61D0
	virtual bool	Unk_43(void);										// 004D4E80 { return this->Is<FormType::Character>() && this->baseForm->IsNot<FormType::Light>() && this->flags & 0x010000; }
	virtual void	Unk_44(void);										// 004D7930
	virtual UInt32	Unk_45(void);										// 004D64E0 { return extraData->GetByType(0x8D)->unk08; }
	virtual bool	Unk_46(void);										// 009B86F0 { return true; }
	virtual bool	Unk_47(void);										// 009B86F0 { return true; } PlayerCharacter=false
	virtual bool	HasKeyword(BGSKeyword* keyword) const;				// 004D5760
	virtual TESPackage *	Unk_49(void);								// 005EADD0 { return nullptr; }
	virtual BGSScene *		GetCurrentScene(void) const;				// 004D6610
	virtual void	SetCurrentScene(BGSScene *);						// 004D6620
	virtual void	Unk_4C(void);										// 004DD3D0
	virtual UInt32	Unk_4D(void);										// 004D6540 { return extraData->GetByType<ExtraSayTopicInfo>()->unk18; } Actor={ return unk14C; }
	virtual void	Unk_4E(UInt32 arg);									// 004D6560 { extraData->GetByType<ExtraSayTopicInfo>()->unk18 = arg; }
	virtual void	Unk_4F(void);										// 004D6580
	virtual void	Unk_50(void);										// 004EAA70 ExtraActorCause
	virtual RefHandle *	GetActorCause(void);							// 004EB130
	virtual UInt32	Unk_52(UInt32 arg);									// 004D59B0 { extraData->GetByType<ExtraStartingPos>() ... return arg; }
	virtual UInt32	Unk_53(UInt32 arg);									// 004D59D0 { extraData->GetByType<ExtraStartingPos>() ... return arg; }
	virtual void	Unk_54(NiPoint3 * pos);								// 004D9C60 SetStartingPos ?
	virtual void	Unk_55(void);										// 004D5950
	virtual void	RemoveItem(RefHandle *droppedItemHandle, TESForm *akItem, UInt32 aiCount, UInt32 mode, BaseExtraList *extraList, TESObjectREFR *moveToRef, UInt32 unk7, UInt32 unk8);	// 004DC790 mode 0:remove 1:steal 2:trade(item ownership changes) 3:drop 4:take 5:idk - called from 0084ABE9
	virtual bool	EquipItem(TESForm *akItem, UInt32 aiCount, bool arg3, UInt32 arg4, UInt32 arg5);	// 004D5C00
	virtual void	Unk_58(UInt32 arg);									// 00588F30 { return; }
	virtual void	Unk_59(UInt32 arg1, UInt32 arg2);					// 004D43E0 { return; }
	virtual void	Unk_5A(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4);		// 004DF960
	virtual void	GetMarkerPosition(NiPoint3 * pos);					// 004D84D0
	virtual MagicCaster	*	GetMagicCaster(UInt32 slot) const;			// 004D5F10
	virtual MagicTarget *	GetMagicTarget(void) const;					// 004DA0C0 { return extraData->GetByType<NonActorMagicTarget>(); }
	virtual bool	IsChild(void) const;								// 0092D110 { return false; }
	virtual UInt32	Unk_5F(void);										// 005EADD0 { return nullptr; }
	virtual void	Unk_60(UInt32 arg);									// 00588F30 { return; }
	virtual BSFaceGenNiNode *	GetFaceGenNiNode(void);					// 005EADD0 { return nullptr; }
	virtual void	Unk_62(void);										// 004E69D0
	virtual BSFaceGenAnimationData *	GetFaceGenAnimationData(void);	// 005EADD0 { return nullptr; }
	virtual void	Unk_64(void);										// 004DCD10
	virtual void	Unk_65(void);										// 004E1770
	virtual void	Unk_66(void);										// 004E4FF0
	virtual void	Unk_67(void);										// 006C50E0 { return; }
	virtual void	Unk_68(void);										// 006C50E0 { return; }
	virtual void	Unk_69(void);										// 006C50E0 { return; }
	virtual void	Unk_6A(void);										// 004E6FD0
	virtual void 	Unk_6B(void);										// 004DF380
	virtual void	Unk_6C(UInt32 unk1, UInt32 unk2);					// 004E76C0 called from Unk_11
	virtual void	SetNiNode(NiNode * root, UInt32 unk1);				// 004D5660 nullptr, 1?
	virtual void	Unk_6E(void);										// 006C50E0 { return; }
	virtual NiNode *	GetNiRootNode(UInt32 firstPerson);				// 004E69E0
	virtual NiNode *	GetNiNode(void);								// 004D52C0 Root of the skeleton (Get3D)
	virtual bool	Unk_71(void);										// 009B86F0 { return true; }
	virtual void	Unk_72(void);										// 004E8CC0
	virtual NiPoint3 *	GetBoundLeftFrontBottom(NiPoint3 *) const;		// 004D5400
	virtual NiPoint3 *	GetBoundRightBackTop(NiPoint3 *) const;			// 004D54C0
	virtual UInt32	Unk_75(void);										// 005EADD0 { return nullptr; }
	virtual void	Unk_76(void);										// 004E0B20
	virtual void	Unk_77(void);										// 004E81B0
	virtual void	Unk_78(void);										// 004E8090
	virtual void	Unk_79(UInt32 arg);									// 00588F30 { return; }
	virtual bool	Unk_7A(void);										// 004E8670 Actor={ return false; }
	virtual void	Unk_7B(void);										// 004E86C0
	virtual bool	Unk_7C(void);										// 009B86F0 { return true; }
	virtual void	Unk_7D(void);										// 004E8C70
	virtual ActorWeightModel	* GetWeightModel(UInt32 weightModel);	// 004E69F0 - 0 Small 1 Large
	virtual void	Unk_7F(void);										// 004DF8A0
	virtual void	Unk_80(void);										// 004D5BF0
	virtual void	Unk_81(UInt32 arg);									// 00588F30 { return; }
	virtual void	Unk_82(UInt32 arg);									// 00588F30 { return; }
	virtual void	Unk_83(UInt32 arg);									// 00588F30 { return; }
	virtual void	Unk_84(UInt32 arg);									// 004D5DF0
	virtual void	Unk_85(void);										// 004D6120
	virtual void	Unk_86(void);										// 004DA630
	virtual void	Unk_87(UInt32 arg);									// 00588F30 { return; }
	virtual void	Unk_88(UInt32 arg);									// 00588F30 { return; }
	virtual void	ResetInventory(bool unk);							// 004E1250
	virtual void	Unk_8A(void);										// 004DC4A0
	virtual UInt32	Unk_8B(void);										// 005EADD0 { return nullptr; }
	virtual void	Unk_8C(UInt32 arg);									// 00588F30 { return; }
	virtual void	Unk_8D(void);										// 004E6A00
	virtual Explosion *		Unk_8E(void);								// 005EADD0 { return nullptr; }	ChainExplosion, Explosion={ return this; }
	virtual Projectile *	Unk_8F(void);								// 005EADD0 { return nullptr; } Projectile, AllowProjectile, MissileProjectile={ return this; }
	virtual bool	Unk_90(UInt32 arg);									// 00C8CCA0 { return true; }
	virtual void	Unk_91(void);										// 006C50E0 { return; }
	virtual void	Unk_92(void);										// 006C50E0 { return; }
	virtual bool	Unk_93(void);										// 0092D110 { return false; }
	virtual void	Unk_94(UInt32 arg);									// 00588F30 { return; }
	virtual void	Unk_95(void);										// 006C50E0 { return; }
	virtual void	Unk_96(void);										// 004D8A00
	virtual TESObjectCELL *	Unk_97(void);								// 004D5EE0
	virtual void	Unk_98(void);										// 004D9FE0
	virtual bool	IsDead(bool unk1) const;							// 004D5710 unk1 = true for Actors
	virtual BSAnimNoteReceiver *	CreateAnimNoteReceiver(void);			// 004E0210
	virtual BSAnimNoteReceiver *	GetAnimNoteReceiver(void);			// 004D62B0
	virtual bool	Unk_9C(UInt32 arg1, UInt32 arg2, UInt32 arg3);		// 004D8CB0
	virtual bool	Unk_9D(UInt32 arg1, UInt32 arg2, UInt32 arg3);		// 00933DE0 { return false; }
	virtual UInt32	Unk_9E(void);										// 005EADD0 { return nullptr; }
	virtual void *	GetDecalGroup(void);								// 004D66C0
	virtual void	Unk_A0(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4);	// 004D6750
	virtual void	Unk_A1(UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4);	// 00DE8190 { return; }

	struct LoadedState
	{
		UInt32	unk00;	// 00
		UInt32	unk04;	// 04
		UInt32	unk08;	// 08
		UInt32	unk0C;	// 0C
		UInt32	unk10;	// 10
		UInt32	unk14;	// 14
		UInt32	unk18;	// 18
		UInt32	unk1C;	// 1C
		NiNode	* node;	// 20
		// ... probably more
	};

	RefHandle CreateRefHandle(void);
	RefHandle GetRefHandle(void);

	RefHandle & CreateRefHandle(RefHandle &out);	// 006BD6C0

	///<summary>Activates this item with the specified reference as the activator.</summary>
	bool Activate(TESObjectREFR *activator, bool abDefaultProcessingOnly = false) {
		if (!activator)
			return false;
		return Activate_Impl(activator, false, false, true, abDefaultProcessingOnly);
	}

	void	BlockActivation(bool bBlocked);
	void	ClearDestruction(void);
	void	CreateDetectionEvent(Actor* owner, UInt32 soundLevel);

	//
	void EnableFastTravel(bool abEnable);

	// Obtains the actor base that owns this object.
	TESNPC * GetActorOwner(void) const;

	///<summary>Obtains this reference's base object.</summary>
	TESForm * GetBaseObject() const {
		return baseForm;
	}

	TESContainer * GetContainer() const;

	const char * GetFullName() const;

	// Gets the faction that owns this reference.
	TESFaction * GetFactionOwner(void) const;

	UInt16 GetLevel(bool unk = true) const {
		return GetLevel_Impl(unk);
	}

	// Obtains this object's current "open state".
	UInt32 GetOpenState() const;

	TESForm *GetOwner() const {
		return GetOwner_Impl();
	}

	// Obtains the cell this object is currently in.
	TESObjectCELL	* GetParentCell(void) {
		return parentCell;
	}

	// Returns this object's current X position.
	float GetPositionX() const {
		return pos.x;
	}

	// Returns this object's current Y position.
	float GetPositionY() const {
		return pos.y;
	}

	// Returns this object's current Z position.
	float GetPositionZ() const {
		return pos.z;
	}

	// Get this object's current scale.
	DEFINE_MEMBER_FN_const(GetScale, float, 0x004D5230);

	// Returns the number of objects inside this trigger volume.
	DEFINE_MEMBER_FN_const(GetTriggerObjectCount, float, 0x004DFB90);

	// Obtains the VoiceType for this actor or talking activator.
	BGSVoiceType * GetVoiceType() const;

	// Get the current height of the object.
	float GetHeight() const {	// 00902800
		NiPoint3 p1, p2;
		return GetBoundRightBackTop(&p1)->z - GetBoundLeftFrontBottom(&p2)->z;
	}

	// Get the current width of the object.
	float GetWidth() const {	// 009027B0
		NiPoint3 p1, p2;
		return GetBoundRightBackTop(&p1)->x - GetBoundLeftFrontBottom(&p2)->x;
	}

	// Returns the worldspace this reference is in.
	DEFINE_MEMBER_FN(GetWorldSpace, TESWorldSpace *, 0x004D5EB0);

	// Returns if this reference has an active effect coming from a magic effect with the specified keyword attached.
	bool HasEffectKeyword(const BGSKeyword *keyword) const;	// 004D57A0

	// Returns if this reference has the specified name node in its 3D.
	bool HasNode(const BSFixedString &nodeName)	const;

	// Returns if this reference has the specified LocationRefType attached.
	bool HasRefType(BGSLocationRefType *refType) const;

	// Checks to see if this reference's 3D data is currently loaded or not.
	bool Is3DLoaded() {
		return GetNiNode() != nullptr;
	}
	
	// Returns whether the passed in reference is an activate child of this reference.
	bool IsActivateChild(TESObjectREFR *akChild) const;		// 0090D120

	// Returns whether normal activation processing is currently blocked on this reference or not.
	bool IsActivationBlocked() const {
		return extraData.IsActivationBlocked();
	}

	// Checks to see if this object is currently flagged for delete.
	bool IsDeleted() const {
		return flags.deleted;
	}

	// Is this object currently disabled?
	bool IsDisabled() const {
		return flags.disabled;
	}

	//ObjectReference::IsFurnitureInUse (30F2B190) callback=0090F130

	//ObjectReference::IsFurnitureMarkerInUse (30F2B160) callback=00902970

	// Is this object ignoring friendly hits?
	bool IsIgnoringFriendlyHits() const {
		return flags.ignoreFriendlyHits;
	}

	//ObjectReference::IsInDialogueWithPlayer (30F2B100) callback=00908B20

	//ObjectReference::IsLockBroken (30F2B0D0) callback=009029A0

	/// <summary>Checks to see if this object is currently locked. If no lock is attached, returns false.</summary>
	bool IsLocked() const;	// 009036F0

	/// <summary>Returns the level of the lock attached to this object.</summary>
	SInt32 GetLockLevel() const;	// 00902750

	// Is this map marker visible to the player?
	bool IsMapMarkerVisible() const;

	bool SetDisplayName(const BSFixedString& text, bool bForce = false);

	DEFINE_MEMBER_FN(SetDestroyed, void, 0x00450E30, bool);
	DEFINE_MEMBER_FN_const(GetBaseScale, float, 0x004D5230);
	DEFINE_MEMBER_FN(GetCurrentLocation, BGSLocation*, 0x004D83C0);
	DEFINE_MEMBER_FN_const(IsOffLimits, bool, 0x004DA760);
	DEFINE_MEMBER_FN(GetReferenceName, const char *, 0x004DE820);
	DEFINE_MEMBER_FN_const(GetItemHealthPercent, float, 0x004EA050);
	DEFINE_MEMBER_FN_const(GetWeight, float, 0x004EA180);
	DEFINE_MEMBER_FN(ActivateRefChildren, UInt32, 0x004EB940, TESObjectREFR *activator);


	bool IsOwnedBy(Actor* actor, bool unk1 = true, bool unk2 = false) const {
		return IsOwnedBy_Impl(actor, unk1, unk2);
	}

	static bool LookupByHandle(const RefHandle &handle, TESObjectREFR* &refrOut);
	static bool LookupByHandle(const RefHandle &handle, TESObjectREFRPtr &managedOut);

	// @members
	//void			** _vtbl00;		// 00 - 01089424 TESObjectREFR
	//void			** _vtbl14;		// 14 - 01089418 BSHandleRefObject
	//void			** _vtbl1C;		// 1C - 0108940C BSTEventSink <BSAnimationGraphEvent>
	//void			** _vtbl20;		// 20 - 010893BC IAnimationGraphManagerHolder
	TESForm			* baseForm;		// 24
	NiPoint3		rot;			// 28
	NiPoint3		pos;			// 34
	TESObjectCELL	* parentCell;	// 40
	LoadedState		* loadedState;	// 44
	BaseExtraList	extraData;		// 48
	UInt32			unk50;			// 50 - flags?

	DEFINE_MEMBER_FN_const(GetNumItems, UInt32, 0x004D9F40, bool unk1, bool unk2);
	
protected:
	DEFINE_MEMBER_FN_const(GetDistance_Impl, float, 0x004D7E70, TESObjectREFR *target);
	DEFINE_MEMBER_FN(Activate_Impl, bool, 0x004E4230, TESObjectREFR*, bool, bool, bool, bool);
	DEFINE_MEMBER_FN_const(GetLevel_Impl, UInt16, 0x004EAB60, bool);
	DEFINE_MEMBER_FN_const(IsOwnedBy_Impl, bool, 0x004EC3B0, Actor* actor, bool unk1, bool unk2);
	DEFINE_MEMBER_FN_const(GetOwner_Impl, TESForm *, 0x004EC0C0);
	DEFINE_MEMBER_FN_const(GetLockState_Impl, LockState *, 0x004EB5B0);


private:
	DEFINE_MEMBER_FN(ctor, void, 0x004E6930);
	DEFINE_MEMBER_FN(dtor, void, 0x004E6A50);
};
STATIC_ASSERT(sizeof(TESObjectREFR) == 0x54);


// Note: May set refHandle to 0
extern const RefHandle & g_invalidRefHandle;

inline bool LookupREFRByHandle(const RefHandle &refHandle, TESObjectREFR *&refrOut)
{
	typedef bool(*_Lookup)(const RefHandle &refHandle, TESObjectREFR *&refrOut);
	const _Lookup Lookup = (_Lookup)0x004A9180;

	return Lookup(refHandle, refrOut);
}

inline bool LookupREFRByHandle(const RefHandle &refHandle, TESObjectREFRPtr &refrOut)
{
	typedef bool(*_Lookup)(const RefHandle &refHandle, TESObjectREFRPtr &managedOut);
	const _Lookup Lookup = (_Lookup)0x004951F0;

	return Lookup(refHandle, refrOut);
}


// This does alot more, but no idea what it is yet
// ??
class CrosshairRefHandleHolder
{
	UInt32		unk00;					// 00
	RefHandle	crosshairRefHandle;		// 04
										// ...
public:
	static CrosshairRefHandleHolder * GetSingleton(void)
	{
		return *((CrosshairRefHandleHolder **)0x01B115D8);
	}

	UInt32 CrosshairRefHandle(void) const { return crosshairRefHandle; }

private:
	DEFINE_MEMBER_FN(ctor, CrosshairRefHandleHolder, 0x0058BD40);
};
