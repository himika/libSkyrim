#include "Skyrim/TESForms/Character/BGSBaseAlias.h"


bool BGSBaseAlias::IsLocationAlias() const
{
	static BSFixedString loc = "Loc";
	return (GetTypeString() == loc);
}


bool BGSBaseAlias::IsReferenceAlias() const
{
	static BSFixedString ref = "Ref";
	return (GetTypeString() == ref);
}
