#pragma once

#include "BaseFormComponent.h"

/*==============================================================================
class BGSPreloadable +0000 (_vtbl=01081240)
0000: class BGSPreloadable
0000: |   class BaseFormComponent
==============================================================================*/
// 04
class BGSPreloadable : public BaseFormComponent
{
public:
	// @override class BaseFormComponent : (vtbl=01081240)
	virtual void	Init(void) override;							// 006C50E0 { return; }
	virtual void	ReleaseRefs(void) override;						// 006C50E0 { return; }
	virtual void	CopyFromBase(BaseFormComponent * rhs) override;	// 00588F30 { return; }

	// @add
	virtual void	BGSPreloadable_Unk_04(void) = 0;				// 00F51EE8 (pure)
};
