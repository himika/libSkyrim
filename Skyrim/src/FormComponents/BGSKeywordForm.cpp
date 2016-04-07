#include "Skyrim/FormComponents/BGSKeywordForm.h"
#include "Skyrim/TESForms/Character/BGSKeyword.h"

bool BGSKeywordForm::HasKeyword(FormID formID) const
{
	bool result = false;

	if (keywords)
	{
		for (UInt32 idx = 0; idx < numKeywords; ++idx)
		{
			if (keywords[idx] && keywords[idx]->formID == formID)
			{
				result = true;
				break;
			}
		}
	}

	return result;
}
