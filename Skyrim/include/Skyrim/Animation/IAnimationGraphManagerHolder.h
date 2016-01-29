#pragma once

#include "BSAnimationGraphManager.h"

class BSFixedString;

/*==============================================================================
class IAnimationGraphManagerHolder +0000 (_vtbl=010C8544)
0000: class IAnimationGraphManagerHolder
==============================================================================*/
// 4
class IAnimationGraphManagerHolder
{
public:
	virtual ~IAnimationGraphManagerHolder();			// 0064F4D0

	virtual bool	SendAnimationEvent(const BSFixedString &eventName);								// 0064F7D0
	virtual bool	GetAnimationGraphManager(BSAnimationGraphManagerPtr &out) = 0;	// 00F51EE8
	virtual bool	IAnimationGraphManagerHolder_Unk_03(UInt32 arg) = 0;							// 00F51EE8 (pure)
	virtual bool	IAnimationGraphManagerHolder_Unk_04(UInt32 arg);								// 004091A0 { return false; }
	virtual bool	IAnimationGraphManagerHolder_Unk_05(UInt32 arg) = 0;							// 00F51EE8 (pure)
	virtual bool	IAnimationGraphManagerHolder_Unk_06(void);										// 009B86F0 { return true; } Actor={ return false; }
	virtual bool	IAnimationGraphManagerHolder_Unk_07(UInt32 arg);								// 00C8CCA0 { return true; }
	virtual bool	IAnimationGraphManagerHolder_Unk_08(UInt32 arg);								// 00C8CCA0 { return true; }
	virtual void	IAnimationGraphManagerHolder_Unk_09(void);										// 006C50E0 { return; }
	virtual bool	IAnimationGraphManagerHolder_Unk_0A(UInt32 arg);								// 004091A0 { return false; }
	virtual void	IAnimationGraphManagerHolder_Unk_0B(UInt32 arg);								// 00588F30 { return; }
	virtual void	IAnimationGraphManagerHolder_Unk_0C(void);										// 006C50E0 { return; }
	virtual void	IAnimationGraphManagerHolder_Unk_0D(UInt32 arg1, UInt32 arg2);					// 004D43E0 { return; }
	virtual bool	IAnimationGraphManagerHolder_Unk_0E(void);										// 009B86F0 { return true; }
	virtual UInt32	IAnimationGraphManagerHolder_Unk_0F(void);										// 005EADD0 { return nullptr; }
	virtual bool	GetAnimationVariableFloat(const BSFixedString &variableName, float &out);		// 00650C40
	virtual bool	GetAnimationVariableInt(const BSFixedString &variableName, SInt32 &out);		// 00650C30
	virtual bool	GetAnimationVariableBool(const BSFixedString &variableName, bool &out);			// 00650C20

	DEFINE_MEMBER_FN(SetAnimationVariableBool, bool, 0x00650C60, const BSFixedString &variableName, bool val);
	DEFINE_MEMBER_FN(SetAnimationVariableInt, bool, 0x00650C80, const BSFixedString &variableName, SInt32 val);
	DEFINE_MEMBER_FN(SetAnimationVariableFloat, bool, 0x00650CA0, const BSFixedString &variableName, float val);

private:
	DEFINE_MEMBER_FN(ctor, IAnimationGraphManagerHolder*, 0x0064F460);
};
