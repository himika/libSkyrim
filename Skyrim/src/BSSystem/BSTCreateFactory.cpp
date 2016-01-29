#include "Skyrim/BSSystem/BSTCreateFactory.h"



IFormFactory* IFormFactory::GetFactoryForType(FormType type)
{
	IFormFactory *result = nullptr;

	if (type <= FormType::Max)
	{
		IFormFactory ** factoryList = (IFormFactory **)0x012E57B0;
		result = factoryList[(std::size_t)type];
	}

	return result;
}
