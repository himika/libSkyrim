#pragma once

#include "PlayerControls.h"
#include "../Events/InputEvent.h"
#include "../Memory.h"

/*==============================================================================
class PlayerInputHandler +0000 (_vtbl=010D44B8)
0000: class PlayerInputHandler
==============================================================================*/
class PlayerInputHandler
{
public:
	PlayerInputHandler();
	virtual ~PlayerInputHandler();																// 007717B0

	TES_FORMHEAP_REDEFINE_NEW();

	virtual	bool	CanProcess(InputEvent *evn) = 0;											// pure - called from 00771AD9
	virtual	void	ProcessThumbstick(ThumbstickEvent *evn, PlayerControls::Data14 *arg2);		// { return; }
	virtual	void	ProcessMouseMove(MouseMoveEvent *evn, PlayerControls::Data14 *arg2);		// { return; }
	virtual	void	ProcessButton(ButtonEvent *evn, PlayerControls::Data14 *arg2);				// { return; }

	inline bool IsEnabled() const			{ return enabled != 0; }
	inline void Enable(bool bEnable = true)	{ enabled = (bEnable) ? 1 : 0; }

	// @members
	UInt32	enabled;			// 04
};


// 0C
class HeldStateHandler : public PlayerInputHandler
{
public:
	virtual	bool	Unk05(ButtonEvent *evn)		{ return Unk05_Impl(evn); }		// 00770EB0
	virtual	void	Unk06(bool arg1)			{ Unk06_Impl(arg1); }			// 00770D00 { unk08 = arg1; }

	// @members
	bool	unk08;				// 08
	bool	unk09;				// 09
	UInt8	pad0A[2];			// 0A

protected:
	DEFINE_MEMBER_FN(Unk05_Impl, bool, 0x00770EB0, ButtonEvent *);
	DEFINE_MEMBER_FN(Unk06_Impl, void, 0x00770D00, bool);
};


/*==============================================================================
struct SprintHandler +0000 (_vtbl=010D44FC)
0000: struct SprintHandler
0000: |   class HeldStateHandler
0000: |   |   class PlayerInputHandler
==============================================================================*/
// 10
	//// @override class PlayerInputHandler : (vtbl=010D44FC)
	//virtual ????   Unk_001(????) override;                           // 00772160
	//virtual ????   Unk_004(????) override;                           // 00773590
	//// @add
	//virtual ????   Unk_005(????);                                    // 00770EB0
	//virtual ????   Unk_006(????);                                    // 00770D00

/*==============================================================================
struct AttackBlockHandler +0000 (_vtbl=010D451C)
0000: struct AttackBlockHandler
0000: |   class HeldStateHandler
0000: |   |   class PlayerInputHandler
==============================================================================*/
	//// @override class PlayerInputHandler : (vtbl=010D451C)
	//virtual ????   Unk_000(????) override;                           // 00771560
	//virtual ????   Unk_001(????) override;                           // 00772190
	//virtual ????   Unk_004(????) override;                           // 00774CB0
	//// @add
	//virtual ????   Unk_005(????);                                    // 00770F30
	//virtual ????   Unk_006(????);                                    // 00770F50

/*==============================================================================
struct ActivateHandler +0000 (_vtbl=010D453C)
0000: struct ActivateHandler
0000: |   class HeldStateHandler
0000: |   |   class PlayerInputHandler
==============================================================================*/
// 10
struct ActivateHandler : public HeldStateHandler
{
public:
	virtual	bool	CanProcess(InputEvent *evn) override;										// 00772490
	virtual	void	ProcessButton(ButtonEvent *evn, PlayerControls::Data14 *arg2) override;		// 007724C0

	// @members
	bool		pressed;	// 0C 
	bool		longTap;	// 0D 
	bool		grabbing;	// 0E 
	bool		disabled;	// 0F - "Your hands are bound."
};


/*==============================================================================
struct ShoutHandler +0000 (_vtbl=010D455C)
0000: struct ShoutHandler
0000: |   class PlayerInputHandler
==============================================================================*/
	//// @override class PlayerInputHandler : (vtbl=010D455C)
	//virtual ????   Unk_000(????) override;                           // 007716D0
	//virtual ????   Unk_001(????) override;                           // 00772790
	//virtual ????   Unk_004(????) override;                           // 00771590

/*==============================================================================
struct TogglePOVHandler +0000 (_vtbl=010D4574)
0000: struct TogglePOVHandler
0000: |   class HeldStateHandler
0000: |   |   class PlayerInputHandler
==============================================================================*/
	//// @override class PlayerInputHandler : (vtbl=010D4574)
	//virtual ????   Unk_001(????) override;                           // 00772810
	//virtual ????   Unk_004(????) override;                           // 00771700
	//// @add
	//virtual ????   Unk_005(????);                                    // 00770EB0
	//virtual ????   Unk_006(????);                                    // 00770D00

/*==============================================================================
struct MovementHandler +0000 (_vtbl=010D4594)
0000: struct MovementHandler
0000: |   class PlayerInputHandler
==============================================================================*/
	//// @override class PlayerInputHandler : (vtbl=010D4594)
	//virtual ????   Unk_001(????) override;                           // 00772000
	//virtual ????   Unk_002(????) override;                           // 00770F70
	//virtual ????   Unk_004(????) override;                           // 00772090

/*==============================================================================
struct LookHandler +0000 (_vtbl=010D45AC)
0000: struct LookHandler
0000: |   class PlayerInputHandler
==============================================================================*/
	//// @override class PlayerInputHandler : (vtbl=010D45AC)
	//virtual ????   Unk_001(????) override;                           // 00771940
	//virtual ????   Unk_002(????) override;                           // 00770F90
	//virtual ????   Unk_003(????) override;                           // 00770FB0

/*==============================================================================
struct ReadyWeaponHandler +0000 (_vtbl=010D45C4)
0000: struct ReadyWeaponHandler
0000: |   class PlayerInputHandler
==============================================================================*/
// 08
struct ReadyWeaponHandler : public PlayerInputHandler
{
public:
	virtual	bool	CanProcess(InputEvent *evn) override;										// 00772460
	virtual	void	ProcessButton(ButtonEvent *evn, PlayerControls::Data14 *arg2) override;		// 00773ED0

};

/*==============================================================================
struct AutoMoveHandler +0000 (_vtbl=010D45DC)
0000: struct AutoMoveHandler
0000: |   class PlayerInputHandler
==============================================================================*/
	//// @override class PlayerInputHandler : (vtbl=010D45DC)
	//virtual ????   Unk_001(????) override;                           // 007726A0
	//virtual ????   Unk_004(????) override;                           // 00770FD0

/*==============================================================================
struct ToggleRunHandler +0000 (_vtbl=010D45F4)
0000: struct ToggleRunHandler
0000: |   class PlayerInputHandler
==============================================================================*/
	//// @override class PlayerInputHandler : (vtbl=010D45F4)
	//virtual ????   Unk_001(????) override;                           // 007726D0
	//virtual ????   Unk_004(????) override;                           // 00771010

/*==============================================================================
struct JumpHandler +0000 (_vtbl=010D460C)
0000: struct JumpHandler
0000: |   class PlayerInputHandler
==============================================================================*/
// 08
struct JumpHandler : public PlayerInputHandler
{
public:
	virtual ~JumpHandler();		// 00772730

	// @override
	virtual	void	ProcessButton(ButtonEvent *evn, PlayerControls::Data14 *arg2) override;		// 00771800
};

/*==============================================================================
struct RunHandler +0000 (_vtbl=010D4624)
0000: struct RunHandler
0000: |   class HeldStateHandler
0000: |   |   class PlayerInputHandler
==============================================================================*/
	//// @override class PlayerInputHandler : (vtbl=010D4624)
	//virtual ????   Unk_001(????) override;                           // 00772700
	//virtual ????   Unk_004(????) override;                           // 00771050
	//// @add
	//virtual ????   Unk_005(????);                                    // 00770EB0
	//virtual ????   Unk_006(????);                                    // 00770D00

/*==============================================================================
struct SneakHandler +0000 (_vtbl=010D4644)
0000: struct SneakHandler
0000: |   class PlayerInputHandler
==============================================================================*/
	//// @override class PlayerInputHandler : (vtbl=010D4644)
	//virtual ????   Unk_001(????) override;                           // 00772760
	//virtual ????   Unk_004(????) override;                           // 00773F50
