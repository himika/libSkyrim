#pragma once

#include "../BSCore/BSTEvent.h"
#include "../BSCore/BSTSingleton.h"
#include "../Events/MenuEvent.h"
#include "../Events/InputEvent.h"
#include "PlayerInputHandler.h"

class MenuEventHandler;

/*==============================================================================
class MenuControls +0000 (_vtbl=010E6A60)
0000: class MenuControls
0000: |   class BSTEventSink<class InputEvent *>
0008: |   struct BSTSingletonSDM<class MenuControls,struct BSTSingletonSDMOpStaticBuffer>
0008: |   |   struct BSTSingletonSDMBase<struct BSTSDMTraits<class MenuControls,struct BSTSingletonSDMOpStaticBuffer<class MenuControls> > >
0008: |   |   |   struct BSTSDMTraits<class MenuControls,struct BSTSingletonSDMOpStaticBuffer<class MenuControls> >
0009: |   |   |   struct BSTSingletonSDMOpStaticBuffer<class MenuControls>
0004: |   class BSTEventSink<class MenuModeChangeEvent>
==============================================================================*/
// 44?
class MenuControls :
	public BSTEventSink<InputEvent *>,					// 00
	public BSTSingletonSDM<MenuControls>,				// 08
	public BSTEventSink<class MenuModeChangeEvent>		// 04
{
public:
	virtual			~MenuControls();

	// @override class BSTEventSink<class InputEvent *> : (vtbl=010E6A60)
	virtual EventResult ReceiveEvent(InputEvent **evn, BSTEventSource<InputEvent *> *source) override;	// 0087A3D0


	void RegisterHandler(MenuEventHandler *handler)
	{
		RegisterHandler_Impl(handler);
	}

	void RemoveHandler(MenuEventHandler *handler)
	{
		RemoveHandler_Impl(handler);
	}

	//void						** _vtbl;		// 00
	//BSTSingletonSDM			singleton;		// 08
	BSTArray<MenuEventHandler*>	handlers;		// 0C
	BSTArray<void*>				regBuffer;		// 18
	UInt32						unk24;
	UInt32						unk28;
	UInt32						unk2C;
	UInt32						unk30;
	UInt32						unk34;
	UInt32						unk38;
	UInt32						unk3C;
	bool						nowProcessing;	// 40
	UInt8						pad41;			// 41
	bool						remapMode;		// 42
	UInt8						pad43;			// 43

private:
	friend struct BSTSingletonSDMBase<BSTSDMTraits<MenuControls>>;
	DEFINE_MEMBER_FN(ctor, MenuControls *, 0x0087A120);
	DEFINE_MEMBER_FN(RegisterHandler_Impl, void, 0x00878DB0, MenuEventHandler *handler);
	DEFINE_MEMBER_FN(RemoveHandler_Impl, void, 0x00878E00, MenuEventHandler *handler);
};
STATIC_ASSERT(offsetof(MenuControls, remapMode) == 0x042);
