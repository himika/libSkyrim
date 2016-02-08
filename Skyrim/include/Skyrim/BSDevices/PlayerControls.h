#pragma once

#include "../BSCore/BSTEvent.h"
#include "../BSCore/BSTSingleton.h"
#include "../Events/MenuEvent.h"
#include "../Events/ScriptEvent.h"
#include "../Events/InputEvent.h"

class PlayerInputHandler;
struct MovementHandler;
struct LookHandler;
struct SprintHandler;
struct ReadyWeaponHandler;
struct AutoMoveHandler;
struct ToggleRunHandler;
struct ActivateHandler;
struct JumpHandler;
struct ShoutHandler;
struct AttackBlockHandler;
struct RunHandler;
struct SneakHandler;
struct TogglePOVHandler;

/*==============================================================================
class PlayerControls +0000 (_vtbl=010D4680)
0000: class PlayerControls
0000: |   class BSTEventSink<class InputEvent *>
0004: |   class BSTEventSink<class MenuOpenCloseEvent>
0008: |   class BSTEventSink<class MenuModeChangeEvent>
0010: |   struct BSTSingletonSDM<class PlayerControls,struct BSTSingletonSDMOpStaticBuffer>
0010: |   |   struct BSTSingletonSDMBase<struct BSTSDMTraits<class PlayerControls,struct BSTSingletonSDMOpStaticBuffer<class PlayerControls> > >
0010: |   |   |   struct BSTSDMTraits<class PlayerControls,struct BSTSingletonSDMOpStaticBuffer<class PlayerControls> >
0011: |   |   |   struct BSTSingletonSDMOpStaticBuffer<class PlayerControls>
000C: |   class BSTEventSink<struct TESFurnitureEvent>
==============================================================================*/
// 160?
class PlayerControls :
	public BSTEventSink<InputEvent *>,			// 00
	public BSTEventSink<MenuOpenCloseEvent>,	// 04
	public BSTEventSink<MenuModeChangeEvent>,	// 08
	public BSTSingletonSDM<PlayerControls>,		// 10
	public BSTEventSink<TESFurnitureEvent>		// 0C
{
public:
	virtual ~PlayerControls();		// 007750C0

	// @override class BSTEventSink<class InputEvent *> : (vtbl=010D4680)
	virtual EventResult ReceiveEvent(InputEvent **evn, BSTEventSource<InputEvent *> *source) override;					// 00774550

	// @override class BSTEventSink<class MenuOpenCloseEvent> : (vtbl=010D4674)
	virtual EventResult ReceiveEvent(MenuOpenCloseEvent *evn, BSTEventSource<MenuOpenCloseEvent> *source) override;		// 00773340

	// @override class BSTEventSink<class MenuModeChangeEvent> : (vtbl=010D4668)
	virtual EventResult ReceiveEvent(MenuModeChangeEvent *evn, BSTEventSource<MenuModeChangeEvent> *source) override;	// 00772B10

	// @override class BSTEventSink<struct TESFurnitureEvent> : (vtbl=010D465C)
	virtual EventResult ReceiveEvent(TESFurnitureEvent *evn, BSTEventSource<TESFurnitureEvent> *source) override;		// 007717E0

	// 30
	struct Data14
	{
		UInt32		unk00;		// 00 (14) - init'd [01B912CC]
		UInt32		unk04;		// 04 (18) - init'd [01B912D0]
		UInt32		unk08;		// 08 (1C) - init'd [01B912CC]
		UInt32		unk0C;		// 0C (20) - init'd [01B912D0]
		UInt32		unk10;		// 10 (24) - init'd [01B912CC]
		UInt32		unk14;		// 14 (28) - init'd [01B912D0]
		UInt32		unk18;		// 18 (2C) - init'd [01B912CC]
		UInt32		unk1C;		// 1C (30) - init'd [01B912D0]
		float		unk20;		// 20 (34) - init'd 0 - init'd [0127B934] in PlayerControls::ctor()
		UInt8		autoRun;	// 24 (38)
		UInt8		runMode;	// 25 (39)
		UInt8		unk26;		// 26 (3A)
		UInt8		unk27;		// 27 (3B)
		UInt16		unk28;		// 28 (3C)
		UInt8		unk2A;		// 2A (3E)
		UInt8		unk2B;		// 2B (3F)
		bool		remapMod;	// 2C (40)
		UInt8		pad2D[3];	// 2D
	};

	// @members
	//void							** _vtbl;				// 00
	//BSTSingletonSDM				singleton;				// 10
	Data14							unk14;					// 14
	BSTArray<PlayerInputHandler *>	handlers;				// 44
	BSTArray<UInt32>				unk50;					// 50
	BSTArray<UInt32>				unk5C;					// 5C
	UInt8							unk68;					// 68
	UInt8							pad69[3];				// 69
	UInt32							unk6C[(0x114 - 0x6C) >> 2];	// 6C
	BSTArray<UInt32>				unk114;					// 114
	UInt32							unk120;					// 120
	UInt32							unk124;					// 124
	MovementHandler					* movementHandler;		// 128
	LookHandler						* lookHandler;			// 12C
	SprintHandler					* sprintHandler;		// 130
	ReadyWeaponHandler				* readyWeaponHandler;	// 134
	AutoMoveHandler					* autoMoveHandler;		// 138
	ToggleRunHandler				* toggleRunHandler;		// 13C
	ActivateHandler					* activateHandler;		// 140
	JumpHandler						* jumpHandler;			// 144
	ShoutHandler					* shoutHandler;			// 148
	AttackBlockHandler				* attackBlockHandler;	// 14C
	RunHandler						* runHandler;			// 150
	SneakHandler					* sneakHandler;			// 154
	TogglePOVHandler				* togglePOVHandler;		// 158
	UInt8							unk15C;					// 15C

private:
	friend struct BSTSingletonSDMBase<BSTSDMTraits<PlayerControls>>;
	DEFINE_MEMBER_FN(ctor, PlayerControls *, 0x00774F20);
	DEFINE_MEMBER_FN(dtor, void, 0x007750C0);

	DEFINE_MEMBER_FN(IsGrabbing, bool, 0x00771200);
	DEFINE_MEMBER_FN(HandleEvent, void, 0x00771A60, InputEvent *evn);
};
