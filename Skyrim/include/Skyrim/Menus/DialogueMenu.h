#pragma once

/*==============================================================================
class DialogueMenu +0000 (_vtbl=010E4C9C)
0000: class DialogueMenu
0000: |   class IMenu
0000: |   |   class FxDelegateHandler
0000: |   |   |   class GRefCountBase<class FxDelegateHandler,2>
0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   |   |   class GRefCountImpl
0000: |   |   |   |   |   |   class GRefCountImplCore
001C: |   class BSTEventSink<class MenuOpenCloseEvent>
==============================================================================*/
// 2C
class DialogueMenu : public IMenu,
	public BSTEventSink<class MenuOpenCloseEvent>	// 1C
{
	// DialogueMenu
	// unk0C - 3
	// Flags - 0x4400
	// unk14 - 1
public:
	// @members
	UInt32	unk20;
	UInt32	unk24;
	UInt32	unk28;	// init'd 0 ctor=0x00A49B40

private:
	DEFINE_MEMBER_FN(ctor, DialogueMenu*, 0x0085A1D0)
};
