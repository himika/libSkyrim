#include "Skyrim.h"
#include "Skyrim/TESForms/Gameplay/BGSListForm.h"

UInt32 BGSListForm::GetSize() const
{
	UInt32 totalSize = forms.size();
	if (addedForms) {
		totalSize += addedForms->size();
	}

	return totalSize;
}

TESForm* BGSListForm::Find(std::function<bool(TESForm *)> fn) const
{
	// Base Added Forms
	for (int i = 0; i < forms.size(); i++) {
		TESForm* childForm = forms[i];
		if (childForm && fn(childForm)) {
			return childForm;
		}
	}
	// Script Added Forms
	if (addedForms) {
		for (int i = 0; i < addedForms->size(); i++) {
			UInt32 formID = (*addedForms)[i];
			TESForm* childForm = LookupFormByID(formID);
			if (childForm && fn(childForm)) {
				return childForm;
			}
		}
	}
	return nullptr;
}
