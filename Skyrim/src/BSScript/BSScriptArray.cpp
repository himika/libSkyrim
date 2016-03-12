#include "Skyrim.h"
#include "Skyrim/BSScript/BSScriptArray.h"
#include "Skyrim/BSScript/BSScriptObject.h"
#include "Skyrim/BSScript/BSScriptVariable.h"

namespace BSScript
{
	BSScriptVariable& BSScriptArray::operator[](size_type idx)
	{
		BSScriptVariable *entries = GetData();
		return entries[idx];
	}

	const BSScriptVariable& BSScriptArray::operator[](size_type idx) const
	{
		const BSScriptVariable *entries = GetData();
		return entries[idx];
	}

	// 0x00C3A0A0
	//BSScriptArray::dtor()
	//{
	//	for (int i = 0; i < len; i++) {
	//		(GetData() + i)->~BSScriptVariable();
	//	}
	//}
}
