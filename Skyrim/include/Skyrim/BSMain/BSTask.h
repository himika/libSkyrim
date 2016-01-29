#pragma once


/*==============================================================================
class BSTask +0000 (_vtbl=0107A320)
0000: class BSTask
==============================================================================*/
class BSTask
{
public:
	virtual ~BSTask();										// 00451580

	// DoTask, CanExecute, Clear?
	virtual void	Unk_01(void) = 0;						// 00F51EE8 (pure) QueuedTempEffect=(void){ return; }
	virtual void	Unk_02(void) = 0;						// 00F51EE8 (pure) QueuedTempEffect=(void){ return; }
	virtual void	Unk_03(UInt32 arg1, UInt32 arg2);		// 00AF8560 { return; } QueuedTempEffect={ return; }
	virtual void	Unk_04(void);							// 00AF8660
};
