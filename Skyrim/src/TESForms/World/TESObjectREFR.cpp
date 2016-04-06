#include "Skyrim.h"
#include "Skyrim/RTTI.h"
#include "Skyrim/Forms/TESObjectREFR.h"
#include "Skyrim/Forms/TESNPC.h"
#include "Skyrim/Forms/Actor.h"
#include "Skyrim/Forms/TESObjectCONT.h"
#include "Skyrim/ExtraData/ExtraLocationRefType.h"
#include "Skyrim/ExtraData/ExtraLock.h"
#include "Skyrim/ExtraData/ExtraMapMarker.h"
#include "Skyrim/ExtraData/ExtraOwnership.h"
#include "Skyrim/ExtraData/ExtraReferenceHandle.h"
#include "Skyrim/ExtraData/ExtraTextDisplayData.h"
#include "Skyrim/NetImmerse/NiNode.h"

//#include "Skyrim/TESForms/Character/Components/ActorProcessManager.h"

const RefHandle & g_invalidRefHandle = *(RefHandle*)0x01310630;


bool TESObjectREFR::LookupByHandle(const RefHandle &refHandle, TESObjectREFR* &refrOut)
{
	return ::LookupREFRByHandle(refHandle, refrOut);
}

bool TESObjectREFR::LookupByHandle(const RefHandle &refHandle, TESObjectREFRPtr &refrOut)
{
	return ::LookupREFRByHandle(refHandle, refrOut);
}



RefHandle TESObjectREFR::CreateRefHandle(void)
{
	typedef void(*_CreateRefHandleByREFR)(RefHandle & refHandleOut, TESObjectREFR * refr);
	const _CreateRefHandleByREFR CreateRefHandleByREFR = (_CreateRefHandleByREFR)0x0065CC00;

	if (GetRefCount() > 0)
	{
		UInt32 refHandle = 0;
		CreateRefHandleByREFR(refHandle, this);
		return refHandle;
	}
	else
	{
		return g_invalidRefHandle;
	}
}

RefHandle & TESObjectREFR::CreateRefHandle(RefHandle & out)		// 006BD6C0
{
	if (GetRefCount() == 0)
	{
		out = g_invalidRefHandle;
	}
	else
	{
		typedef void(*_CreateRefHandleByREFR)(RefHandle & refHandleOut, TESObjectREFR * refr);
		const _CreateRefHandleByREFR CreateRefHandleByREFR = (_CreateRefHandleByREFR)0x0065CC00;

		CreateRefHandleByREFR(out, this);
	}
	return out;
}

RefHandle TESObjectREFR::GetRefHandle(void)
{
	ExtraReferenceHandle* xRefHandle = this->extraData.GetByType<ExtraReferenceHandle>();

	return (xRefHandle == nullptr) ? g_invalidRefHandle : xRefHandle->handle;
}

void TESObjectREFR::BlockActivation(bool bBlocked)
{
	MarkChanged(0x80000000);
	extraData.BlockActivation(bBlocked);
}

void TESObjectREFR::ClearDestruction(void)
{
	typedef void(*_ClearDestruction)(TESObjectREFR* ref);
	const _ClearDestruction fnClearDestruction = (_ClearDestruction)0x00449630;

	fnClearDestruction(this);
}

void TESObjectREFR::CreateDetectionEvent(Actor* owner, UInt32 soundLevel)
{
	if (owner && owner->processManager)
		owner->processManager->CreateDetectionEvent(owner, &this->pos, soundLevel, this);
}

TESNPC* TESObjectREFR::GetActorOwner(void) const
{
	ExtraOwnership* exOwnership = extraData.GetByType<ExtraOwnership>();
	if (exOwnership && exOwnership->owner && exOwnership->owner->Is(FormType::Character))
	{
		return (TESNPC*)exOwnership->owner;
	}
	return nullptr;
}

TESContainer * TESObjectREFR::GetContainer() const
{
	TESContainer *container = nullptr;
	if (baseForm)
	{
		if (baseForm->Is(FormType::Container))
			container = static_cast<TESContainer*>((TESObjectCONT*)baseForm);
		else if (baseForm->Is(FormType::NPC))
			container = static_cast<TESContainer*>((TESActorBase*)baseForm);
	}
	return container;
}

const char * TESObjectREFR::GetFullName(void) const
{
	const char *result = nullptr;
	if (baseForm)
	{
		TESFullName *fullName = DYNAMIC_CAST<TESFullName*>(baseForm);
		if (fullName)
			result = fullName->GetFullName();
	}
	return result;
}

TESFaction* TESObjectREFR::GetFactionOwner(void) const
{
	ExtraOwnership* exOwnership = extraData.GetByType<ExtraOwnership>();
	if (exOwnership && exOwnership->owner && exOwnership->owner->Is(FormType::Faction))
	{
		return (TESFaction*)exOwnership->owner;
	}
	return nullptr;
}

bool TESObjectREFR::IsActivateChild(TESObjectREFR *akChild) const
{
	typedef bool(*_IsActivateChild)(FormID, TESObjectREFR *);
	const _IsActivateChild fnIsActivateChild = (_IsActivateChild)0x0090C920;
	return (akChild) ? fnIsActivateChild(GetFormID(), akChild) : false;
}

bool TESObjectREFR::IsLocked() const
{
	LockState *state = GetLockState_Impl();
	return (state && state->isLocked);
}

SInt32 TESObjectREFR::GetLockLevel() const
{
	SInt32 level = 0;
	LockState *state = GetLockState_Impl();
	if (state)
		level = state->GetLockLevel(this);
	return level;
}

void TESObjectREFR::EnableFastTravel(bool abEnable)
{
	ExtraMapMarker *xMarker = extraData.GetByType<ExtraMapMarker>();
	if (xMarker && xMarker->mapMarker)
	{
		xMarker->mapMarker->Enable(abEnable);
		MarkChanged(0x80000000);
	}
}

bool TESObjectREFR::IsMapMarkerVisible() const
{
	ExtraMapMarker *xMarker = extraData.GetByType<ExtraMapMarker>();
	
	return xMarker && xMarker->mapMarker && flags.visible;
}

bool TESObjectREFR::HasEffectKeyword(const BGSKeyword *keyword) const
{
	MagicTarget *magicTarget = GetMagicTarget();

	return magicTarget ? magicTarget->HasEffectKeyword(keyword) : false;
}

BGSVoiceType * TESObjectREFR::GetVoiceType() const
{
	TESBoundObject* boundObject = (TESBoundObject*)GetBaseObject();
	return boundObject ? boundObject->GetVoiceType() : nullptr;
}

UInt32 TESObjectREFR::GetOpenState() const
{
	typedef UInt32(*_GetOpenState)(const TESObjectREFR*);
	const _GetOpenState fnGetOpenState = (_GetOpenState)0x0044BE80;

	return fnGetOpenState(this);
}

bool TESObjectREFR::HasNode(const BSFixedString &nodeName) const
{
	NiNode *node = const_cast<TESObjectREFR*>(this)->GetNiNode();
	if (!node)
		return false;

	NiAVObject *obj = node->GetObjectByName(nodeName);
	return obj != nullptr;
}

bool TESObjectREFR::HasRefType(BGSLocationRefType *refType) const
{
	if (!refType)
		return false;

	ExtraLocationRefType * xRefType = extraData.GetByType<ExtraLocationRefType>();
	return xRefType && xRefType->refType == refType;
}

bool TESObjectREFR::SetDisplayName(const BSFixedString &name, bool force)
{
	bool renamed = false;

	ExtraTextDisplayData* xTextData = extraData.GetByType<ExtraTextDisplayData>();
	if (xTextData)
	{
		bool inUse = (xTextData->message || xTextData->owner);
		if (inUse && force)
		{
			xTextData->message = nullptr;
			xTextData->owner = nullptr;
		}
		renamed = (!inUse || force);
		xTextData->SetName(name.c_str());
	}
	else
	{
		ExtraTextDisplayData* newTextData = ExtraTextDisplayData::Create();
		newTextData->SetName(name.c_str());
		extraData.Add(newTextData);
		renamed = true;
	}

	return renamed;
}
