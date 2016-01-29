#pragma once

#include "../NetImmerse/NiTypes.h"
#include "../BSCore/BSTEvent.h"
#include "BSTask.h"

/*==============================================================================
class InterfacedClass +0000 (_vtbl=0107A314)
0000: class InterfacedClass
==============================================================================*/
class InterfacedClass
{
public:
	virtual ~InterfacedClass();

	virtual void Unk_01(void) = 0;
};


/*==============================================================================
class LockFreeMap<__int64,class NiPointer<class BSTask> > +0000 (_vtbl=0111D7BC)
0000: class LockFreeMap<__int64,class NiPointer<class BSTask> >
0000: |   class InterfacedClass
==============================================================================*/
template <class Key, class Value>
class LockFreeMap : public InterfacedClass
{
public:
	virtual ~LockFreeMap();									// 00AF9530

	// @override
	virtual void Unk_01(void) override;						// 00AF7690

	// @add
	virtual void	Unk_02(void);							// 00AF8420
	virtual void	Unk_03(void);							// 00AF84C0
	virtual void	Unk_04(void);							// 00AF8510
	virtual void	Unk_05(void);							// 00AF8470
	virtual void	Unk_06(void);							// 00AF8220
	virtual void	Unk_07(void);							// 00AF7730
	virtual void	Unk_08(void);							// 00AF9320
	virtual void	Unk_09(UInt32 arg1, UInt32 arg2);		// 004D43E0 { return; }
	virtual void	Unk_0A(void);							// 00AF75F0
	virtual void	Unk_0B(void);							// 00AF7600
	virtual void	Unk_0C(void);							// 00AF7620
	virtual void	Unk_0D(void);							// 00AF7650
	virtual void	Unk_0E(void);							// 0042BA10
	virtual void	Unk_0F(void);							// 00AF7680
	virtual UInt32	Unk_10(void);							// 009EA560 { return (UInt32)unk18; }

	/*==============================================================================
	class LockFreeMap<__int64,class NiPointer<class BSTask> >::LockFreeMapIterator +0000 (_vtbl=0111D650)
	0000: class LockFreeMap<__int64,class NiPointer<class BSTask> >::LockFreeMapIterator
	==============================================================================*/
	class LockFreeMapIterator
	{
	public:
		virtual ~LockFreeMapIterator();		// 00AF7340
		virtual void Unk_01(void);			// 00AF72B0
	};


	// @members
	//void	** _vtbl;		// 00 - 0111D7BC
	UInt32	unk04;
	UInt32	unk08;
	UInt32	unk0C;
	UInt32	unk10;
	UInt32	unk14;
	UInt32	unk18;
};

enum BSTaskManagerWaitAction
{
};


/*==============================================================================
class BSTaskManager +0000 (_vtbl=0111D814)
0000: class BSTaskManager
0000: |   class LockFreeMap<__int64,class NiPointer<class BSTask> >
0000: |   |   class InterfacedClass
001C: |   class BSTEventSource<enum BSTaskManagerWaitAction>
==============================================================================*/
class BSTaskManager : public LockFreeMap<SInt64, class NiPointer<BSTask>>,
	public BSTEventSource<BSTaskManagerWaitAction>			// 1C
{
public:
	virtual ~BSTaskManager();					// 00AF9590

	// @add
	virtual void	Unk_11(void);				// 00AF8870
	virtual void	Unk_12(void);				// 00AF8580
	virtual void	Unk_13(void);				// 00AF8730
	virtual void	Unk_14(void);				// 00AF8E60
	virtual void	Unk_15(UInt32 arg);			// 00AF85C0 { return; }
	virtual void	Unk_16(UInt32 arg);			// 00AF85D0 { return; }
	virtual void	Unk_17(UInt32 arg);			// 00AF85E0 { return; };
};


