#include "Skyrim.h"
#include "Skyrim/RTTI.h"
#include "Skyrim/FormComponents/TESForm.h"

#include "Skyrim/Forms/TESObjectARMO.h"
#include "Skyrim/Forms/EffectSetting.h"
#include "Skyrim/Forms/TESObjectREFR.h"
#include "Skyrim/Forms/TESActorBase.h"
#include "Skyrim/Forms/TESObjectARMO.h"
#include "Skyrim/Forms/TESObjectWEAP.h"
#include "Skyrim/Forms/TESObjectACTI.h"
#include "Skyrim/Forms/MagicItem.h"
#include "Skyrim/Forms/TESObjectMISC.h"
#include "Skyrim/Forms/TESAmmo.h"
#include "Skyrim/Forms/TESObjectBOOK.h"

#include "Skyrim/Forms/TESRace.h"
#include "Skyrim/Forms/BGSLocation.h"

#include "Skyrim/FormComponents/BGSKeywordForm.h"


const _LookupFormByID LookupFormByID = (_LookupFormByID)0x00451A30;

TESForm * TESForm::CreateEmptyForm(FormType formType)
{
#if 0
	IFormFactory *factory = IFormFactory::GetFactoryForType(formType);
	return (factory) ? factory->Create() : nullptr;
#endif
	typedef TESForm*(*Fn)(FormType formType);
	Fn fn = (Fn)0x0043BDD0;
	return fn(formType);
}




template <typename T, typename F>
static inline void Copy(F* lhs, F* rhs) {
	static_cast<T*>(lhs)->CopyFromBase(static_cast<T*>(rhs));
}

bool TESForm::HasWorldModel(void) const
{
	const TESModel *pModel = DYNAMIC_CAST<const TESModel *>(this);

	return pModel != nullptr;
}


UInt32 TESForm::GetGoldValue() const	// 008FCD00 - Form.GetGoldValue()
{
	typedef UInt32(*_GetGoldValue)(const TESForm* akForm);
	const _GetGoldValue GetGoldValue = (_GetGoldValue)0x00457DA0;

	TESObjectREFR* ref = const_cast<TESForm*>(this)->GetReference();
	return GetGoldValue(ref ? ref->baseForm : this);
}

double TESForm::GetWeight() const
{
	typedef double(*_GetFormWeight)(const TESForm* form);
	const _GetFormWeight GetFormWeight = (_GetFormWeight)0x00457EC0;

	TESObjectREFR* ref = const_cast<TESForm*>(this)->GetReference();
	return GetFormWeight(ref ? ref->baseForm : this);
}

template <typename T>
static inline const BGSKeywordForm* cast_to_keywordform(const TESForm* form) {
	return static_cast<const BGSKeywordForm*>(static_cast<const T *>(form));
}

bool TESForm::HasKeyword(BGSKeyword* keyword) const	// 008FCCA0
{
	const BGSKeywordForm* keywordForm = nullptr;

	switch (this->formType)
	{
	case FormType::EffectSetting:
		keywordForm = cast_to_keywordform<EffectSetting>(this);
		break;
	case FormType::NPC:
		keywordForm = cast_to_keywordform<TESActorBase>(this);
		break;
	case FormType::Race:
		keywordForm = cast_to_keywordform<TESRace>(this);
		break;
	case FormType::Armor:
		keywordForm = cast_to_keywordform<TESObjectARMO>(this);
		break;
	case FormType::Weapon:
		keywordForm = cast_to_keywordform<TESObjectWEAP>(this);
		break;
	case FormType::Location:
		keywordForm = cast_to_keywordform<BGSLocation>(this);
		break;
	case FormType::Activator:
	case FormType::TalkingActivator:
	case FormType::Flora:
	case FormType::Furniture:
		keywordForm = cast_to_keywordform<TESObjectACTI>(this);
		break;
	case FormType::Enchantment:
	case FormType::Spell:
	case FormType::ScrollItem:
	case FormType::Ingredient:
	case FormType::Potion:
		keywordForm = cast_to_keywordform<MagicItem>(this);
		break;
	case FormType::Misc:
	case FormType::Apparatus:
	case FormType::Key:
	case FormType::SoulGem:
		keywordForm = cast_to_keywordform<TESObjectMISC>(this);
		break;
	case FormType::Ammo:
		keywordForm = cast_to_keywordform<TESAmmo>(this);
		break;
	case FormType::Book:
		keywordForm = cast_to_keywordform<TESObjectBOOK>(this);
		break;
	default:
		keywordForm = DYNAMIC_CAST<BGSKeywordForm*>(const_cast<TESForm*>(this));
		break;
	}
	if (keywordForm)
	{
		return keywordForm->HasKeyword(keyword);
	}

	TESObjectREFR* ref = const_cast<TESForm*>(this)->GetReference();
	if (ref)
	{
		return ref->HasKeyword(keyword);
	}

	return false;
}
