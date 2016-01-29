#pragma once


/*==============================================================================
class BSTask +0000 (_vtbl=0107A320)
0000: class BSTask
==============================================================================*/
class BSTask
{
public:
	~BSTask();											// 00451580

	// @add
	virtual void	Unk_01(void) = 0;					// 00F51EE8 (pure)
	virtual void	Unk_02(void) = 0;					// 00F51EE8 (pure)
	virtual void	Unk_03(UInt32 arg1, UInt32 arg2);	// 00AF8560 { return; }
	virtual void	Unk_04(void);						// 00AF8660

};




/*==============================================================================
class IOTask +0000 (_vtbl=0107A3E0)
0000: class IOTask
0000: |   class BSTask
==============================================================================*/
class IOTask : public BSTask
{
public:
	// @add
	virtual bool   Unk_05(void);						// 00AF6910 { return false; }
	virtual void   Unk_06(void);						// 00AF6920 { return; }
	virtual void   Unk_07(void);						// 00AF6A40
	virtual void   Unk_08(void);						// 00AF6AC0
};


/*==============================================================================
class QueuedFile +0000 (_vtbl=0111D540)
0000: class QueuedFile
0000: |   class IOTask
0000: |   |   class BSTask
==============================================================================*/
class QueuedFile : public IOTask
{
public:
	virtual ~QueuedFile();											// 00AF4D60
	// @override class IOTask : (vtbl=0111D540)
	virtual void	Unk_01(void) override;							// 00AF46B0 { return; }
	virtual void	Unk_02(void) override;							// 00AF48E0
	virtual void	Unk_03(UInt32 arg1, UInt32 arg2) override;		// 00AF4950
	virtual void	Unk_08(void) override;							// 00AF48F0
	// @add
	virtual void	Unk_09(void);									// 00AF46E0 { return; }
	virtual void	Unk_0A(void);									// 00AF46F0 { return; }
	virtual void	Unk_0B(void);									// 00AF4700 { return; }
};
