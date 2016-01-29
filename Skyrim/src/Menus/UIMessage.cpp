#include "Skyrim/Menus/UIMessage.h"

void * UIMessage::CreateUIMessageData(const BSFixedString &name)
{
	typedef void * (*FnCreateUIMessageData)(const BSFixedString &name);
	const FnCreateUIMessageData fnCreateUIMessageData = (FnCreateUIMessageData)0x00547A00;

	return fnCreateUIMessageData(name);
}
