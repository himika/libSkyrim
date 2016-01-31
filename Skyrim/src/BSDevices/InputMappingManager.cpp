#include "Skyrim/BSDevices/InputMappingManager.h"


DECLARE_BSTSINGLETONSDM_STATIC_INSTANCE(InputMappingManager, 0x012E7458, 0x01B37FB0);

UInt32 InputMappingManager::GetMappedKey(const BSFixedString &name, DeviceType deviceType, ContextType contextIdx) const
{
	BSTArray<InputMapping::Data> * maps = nullptr;

	if (deviceType == kDevice_Mouse)
		maps = &mappings[contextIdx]->mouseMap;
	else if (deviceType == kDevice_Gamepad)
		maps = &mappings[contextIdx]->gamepadMap;
	else if (deviceType == kDevice_Keyboard)
		maps = &mappings[contextIdx]->keyboardMap;

	if (maps)
	{
		for (InputMapping::Data &data : *maps)
		{
			if (data.name == name)
				return data.buttonID;
		}
	}

	return 0xFF;
}

const BSFixedString & InputMappingManager::GetUserEventName(UInt32 buttonID, DeviceType deviceType, ContextType contextIdx) const
{
	BSTArray<InputMapping::Data> * maps = nullptr;

	if (deviceType == kDevice_Mouse)
		maps = &mappings[contextIdx]->mouseMap;
	else if (deviceType == kDevice_Gamepad)
		maps = &mappings[contextIdx]->gamepadMap;
	else if (deviceType == kDevice_Keyboard)
		maps = &mappings[contextIdx]->keyboardMap;

	static BSFixedString none = "";

	if (maps)
	{
		for (InputMapping::Data &data : *maps)
		{
			if (data.buttonID == buttonID)
				return data.name;
		}
	}

	return none;
}
