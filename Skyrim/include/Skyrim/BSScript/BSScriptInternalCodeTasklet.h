#pragma once


/*==============================================================================
class BSTaskletData +0000 (_vtbl=010A7838)
0000: class BSTaskletData
==============================================================================*/
class BSTaskletData
{
public:
	virtual ~BSTaskletData();	// 00581880

	virtual	bool	Unk_01(void);		// 00A595E0 { return true; }
	virtual void	Unk_02(void);		// 00A595F0 { return; }
	virtual	void	Unk_03(void);		// 00A59600 { return; }
};


/*==============================================================================
class BSWin32TaskletData +0000 (_vtbl=010A7854)
0000: class BSWin32TaskletData
0000: |   class BSTaskletData
==============================================================================*/
// 18
class BSWin32TaskletData : public BSTaskletData
{
public:
	virtual ~BSWin32TaskletData();		// 005818B0


	// @members
	bool	unk04;		// 04 - init'd false
	UInt32	unk08;		// 08 - init'd 0
	bool	unk0C;		// 0C - init'd true
	UInt32	unk10;		// 10 - init'd 0
	UInt32	unk14;
};


// 04
// VMState+0010
// UnkClass_0114C944+0018
class IUnknown_0112197C
{
public:
	virtual ~IUnknown_0112197C();						// 00B578A0
	virtual void	IUnknown_0112197C_Unk01(void) = 0;
};


namespace BSScript
{
	// 44
	class InternalCodeTaskletData :
		public BSWin32TaskletData,		// 00
		public IUnknown_0112197C,		// 18 - vtbl override 0114C93C
		public BSIntrusiveRefCounted	// 1C
	{
	public:
		virtual ~InternalCodeTaskletData();		// 00C65850

		virtual	void	Unk_02(void) override;	// 00C65280


		DEFINE_MEMBER_FN(ctor, InternalCodeTaskletData *, 0x00C60420, UInt32 arg1, UInt32 arg2, UInt32 arg3);
		DEFINE_MEMBER_FN(dtor, void, 0x00A59970);

		// @members
		//void		** _vtbl;		// 00 - 0114C944
	};
}
