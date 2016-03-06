#include "Skyrim/Menus/IMenu.h"
#include "Skyrim/Menus/BSScaleformLoader.h"

IMenu::IMenu() : view(nullptr), fxDelegate(nullptr), menuDepth(3), flags(0), context(0x12)
{
}


IMenu::~IMenu()
{
	if (fxDelegate)
		fxDelegate->Release();

	if (view)
		view->Release();
}


void IMenu::Accept(CallbackProcessor * processor)
{
}

void IMenu::OnOpen(void)		// called from 00A5D862
{
}

void IMenu::Unk_03(void)
{
}

UInt32 IMenu::ProcessMessage(UIMessage *message)		// called from 00A5D8C9, 00A5DC8A, 00A5D7C5
{
	UInt32 result = 2;

	if (message->type == UIMessage::kMessage_Scaleform)
	{
		if (view && message->data)
		{
			BSUIScaleformData *scaleformData = static_cast<BSUIScaleformData*>(message->data);

			view->HandleEvent(*scaleformData->event);
			result = 0;
		}
	}

	return result;
}

void IMenu::NextFrame(UInt32 arg0, UInt32 arg1)		// called from 00A5CE2B
{
	NextFrame_internal(arg0, arg1);
}


void IMenu::Render(void)		// called from 00A5CB49
{
	if (view)
		view->Display();
}

void IMenu::Unk_07(void)
{
}

void IMenu::InitMovie(void)
{
	InitMovie_internal(view);
}


bool IMenu::LoadMovie(const char *swfName, GFxMovieView::ScaleModeType mode, float alpha)
{
	BSScaleformMovieLoader *loader = BSScaleformMovieLoader::GetSingleton();
	if (!loader)
		return false;

	return loader->LoadMovie(this, view, swfName, mode, 0.0f);
}
