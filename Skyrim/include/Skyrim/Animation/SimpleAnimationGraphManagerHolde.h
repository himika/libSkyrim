#pragma once

#include "IAnimationGraphManagerHolder.h"

/*==============================================================================
class SimpleAnimationGraphManagerHolder +0000 (_vtbl=010C8664)
0000: class SimpleAnimationGraphManagerHolder
0000: |   class IAnimationGraphManagerHolder
==============================================================================*/
// 0C
class SimpleAnimationGraphManagerHolder : public IAnimationGraphManagerHolder
{
public:
	virtual ~SimpleAnimationGraphManagerHolder();														// 00651A90

	// @override
	virtual bool	GetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager> &out) override;	// 00651980
	virtual bool	IAnimationGraphManagerHolder_Unk_03(UInt32 arg) override;							// 006519D0
	virtual bool	IAnimationGraphManagerHolder_Unk_05(UInt32 arg) override;							// 00651A20

	// @add
	virtual void	SimpleAnimationGraphManagerHolder_Unk_13(void);										// 006C50E0 { return; }

	// @members
	//	void	** _vtbl;		// 00   0x010C8664
	void		* unk04;		// 04
	UInt32		unk08;			// 08

private:
	DEFINE_MEMBER_FN(ctor, SimpleAnimationGraphManagerHolder*, 0x00651870);
};
