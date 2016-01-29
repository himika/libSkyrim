#pragma once

/*==============================================================================
class IPackageData +0000 (_vtbl=010C0160)
0000: class IPackageData
==============================================================================*/
class IPackageData
{
public:
	virtual ~IPackageData();									// 005B2D60

	virtual void	Unk_01(UInt32) = 0;							// 00F51EE8 (pure)
	virtual void	Unk_02(void) = 0;							// 00F51EE8 (pure)
	virtual void	Unk_03(UInt32) = 0;							// 00F51EE8 (pure)
	virtual void	Unk_04(void) = 0;							// 00F51EE8 (pure)
	virtual void	Unk_05(void) = 0;							// 00F51EE8 (pure)
	virtual void	Unk_06(UInt32, UInt32, UInt32);				// 00D62BE0 { return; }
	virtual void	Unk_07(UInt32);								// 00588F30 { return; }
	virtual void	Unk_08(UInt32);								// 00588F30 { return; }
	virtual void	Unk_09(UInt32);								// 00588F30 { return; }
	virtual void	Unk_0A(void) = 0;							// 00F51EE8 (pure)
	virtual void	Unk_0B(void) = 0;							// 00F51EE8 (pure)
	virtual bool	Unk_09(void);								// 0092D110 { return false; }
};
