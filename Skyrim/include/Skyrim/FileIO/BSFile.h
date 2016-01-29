#pragma once

// 15C
class BSFile
{
public:
	virtual ~BSFile();		// 00A579B0

	virtual bool	Unk_01(void) const;						// 00B2B180 { return (bool)unk2C; }
	virtual void	Unk_02(UInt32 arg1);					// 00A56F60 { return this->Unk_06([01120D48], arg1); }
	virtual UInt32	Unk_03(void) const;						// 00B2A390 { return unk04; }
	virtual void	Unk_04(UInt32 arg1);					// 00B2B460
	virtual void	Unk_05(UInt32 arg1);					// 00A57500 { if (unk04) { unk08=00A572A0, unk0C=00A573D0; } else { unk08=00A57260, unk0C=00A57280; } }
	virtual void	Unk_06(UInt32 arg1, UInt32 arg2);		// 00A57DE0
	virtual UInt32	Unk_07(void);							// 00A57220 { if (unk154) unk154 = Unk_0A(); return unk154; }
	virtual bool	Unk_08(UInt32 arg1, UInt32 arg2);		// 00A57700 open? "a+t" "a+b" "r+t" "r+b" "rt" "rb"
	virtual bool	Unk_09(UInt32 arg1);					// 00A576D0
	virtual UInt32	Unk_0A(void);							// 00A57D70
	virtual void	Unk_0B(UInt32 arg1, UInt32 arg2);		// 00A577E0
	virtual UInt32	Unk_0C(UInt32 arg1, UInt32 arg2);		// 00A578B0
	virtual bool	Unk_0D(UInt32 arg1, UInt32 arg2, UInt32 arg3);		// 00A572E0
	virtual void	Unk_0E(void);							// 00A575B0
	virtual void	Unk_0F(void);							// 00A57530
	virtual bool	Unk_10(void);							// 00A57440 { return (Unk_00F562C2(fullPathName, 0) != -1); }
	virtual void	Unk_11(void);							// 00A57E70
	virtual void	Unk_12(void);							// 00A57240

	// @members
	//void		** _vtbl;				// 000 - 0110DBA8 (no rtti)
	UInt32		unk04;					// 004
	void		* unk08;				// 008 - entry point - read function ?
	void		* unk0C;				// 00C - entry point - write function ?
	UInt32		unk10;					// 010 - init'd 0
	UInt32		unk14;					// 014 - init'd 0
	UInt32		unk18;					// 018 - init'd 0
	UInt32		unk1C;
	UInt32		unk20;					// 010 - init'd 0
	UInt32		unk24;					// 010 - init'd 0
	UInt32		unk28;					// 010 - init'd 0
	bool		unk2C;					// 02C - init'd false
	UInt8		pad2D[3];
	bool		unk30;					// 030 - init'd false
	UInt8		pad31[3];
	UInt32		unk34;
	SInt32		unk38;					// 038 - init'd -1
	UInt32		unk3C;
	UInt32		unk40;
	char		fullPathName[0x104];	// 044 - init'd ""
	UInt32		unk148;					// 148 - init'd 0
	UInt32		unk14C;					// 14C - init'd 0
	UInt32		unk150;					// 150 - init'd 0
	UInt32		unk154;
	bool		unk158;					// 158 - init'd false

private:
	DEFINE_MEMBER_FN(ctor, BSFile*, 0x00A571C0);
	DEFINE_MEMBER_FN(ctor3, BSFile*, 0x00A57EA0, const char* fileName, UInt32, UInt32, UInt32);
};
STATIC_ASSERT(sizeof(BSFile) == 0x15C);
