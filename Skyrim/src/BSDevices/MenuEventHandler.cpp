#include "Skyrim/BSDevices/MenuEventHandler.h"

MenuEventHandler::MenuEventHandler() : unk08(0), unk09(0)
{
}

MenuEventHandler::~MenuEventHandler()
{
}

bool MenuEventHandler::ProcessKinect(KinectEvent *evn)
{
	return false;
}

bool MenuEventHandler::ProcessThumbstick(ThumbstickEvent *evn)
{
	return false;
}

bool MenuEventHandler::ProcessMouseMove(MouseMoveEvent *evn)
{
	return false;
}

bool MenuEventHandler::ProcessButton(ButtonEvent *evn)
{
	return false;
}
