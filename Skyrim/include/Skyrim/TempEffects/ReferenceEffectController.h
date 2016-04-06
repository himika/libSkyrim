#pragma once

/*==============================================================================
class ReferenceEffectController +0000 (_vtbl=010887FC)
0000: class ReferenceEffectController
==============================================================================*/
// 04 - visual effect controller
class ReferenceEffectController
{
public:
	virtual ~ReferenceEffectController();		// 004D4920

	virtual void	Unk_01(UInt32 arg);                              // 00588F30 { return; }
	virtual float	Unk_02(void);                                    // 0066E8A0 { return 0.0f; }
	virtual void	Unk_03(void);                                    // 0064A3E0
	virtual void	Unk_04(UInt32 arg1, UInt32 arg2);                // 004D43E0 { return; }
	virtual float *	Unk_05(void);                                    // 006686B0 { return 0x01B910A4; }
	virtual bool	Unk_06(void);                                    // 0092D110 { return false; }
	virtual bool	Unk_07(void);                                    // 0092D110 { return false; }
	virtual bool	Unk_08(void);                                    // 009B86F0 { return true; }
	virtual bool	Unk_09(void);                                    // 0092D110 { return false; }
	virtual void	Unk_0A(UInt32 arg);                              // 00588F30 { return; }
	virtual void	Unk_0B(void) = 0;                                // 00F51EE8 (pure)
	virtual UInt32	Unk_0C(void) = 0;                                // 00F51EE8 (pure)
	virtual UInt32	Unk_0D(void) = 0;                                // 00F51EE8 (pure)
	virtual bool	Unk_0E(void) = 0;                                // 00F51EE8 (pure)
	virtual void	Unk_0F(void);                                    // 00668690
	virtual float	Unk_10(void);                                    // 0066E8A0 { return 0.0f; }
	virtual bool	Unk_11(void);                                    // 0092D110 { return false; }
	virtual bool	Unk_12(void);                                    // 009B86F0 { return true; }
	virtual bool	Unk_13(void);                                    // 0092D110 { return false; }
	virtual bool	Unk_14(void);                                    // 0092D110 { return false; }
	virtual void	Unk_15(void);                                    // 00668780
	virtual bool	Unk_16(void);                                    // 0092D110 { return false; }
	virtual bool	Unk_17(void);                                    // 0092D110 { return false; }
	virtual UInt32	Unk_18(void);                                    // 005EADD0 { return 0; }
	virtual bool	Unk_19(void);                                    // 009B86F0 { return true; }
	virtual bool	Unk_1A(void);                                    // 0092D110 { return false; }
	virtual bool	Unk_1B(void);                                    // 0092D110 { return false; }
	virtual bool	Unk_1C(void);                                    // 009B86F0 { return true; }
	virtual bool	Unk_1D(void);                                    // 009B86F0 { return true; }
	virtual void	Unk_1E(UInt32 *arg);                             // 00588F30 { return; }
	virtual float *	Unk_1F(void);                                    // 006686B0 { return 0x01B910A4; }
	virtual bool	Unk_20(void);                                    // 0092D110 { return false; }
	virtual void	Unk_21(UInt32 arg);                              // 00588F30 { return; }
	virtual void	Unk_22(UInt32 arg);                              // 00588F30 { return; }
};
