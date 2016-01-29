#pragma once

#include "BaseFormComponent.h"
#include "TESModel.h"

class BGSTextureSet;

/*==============================================================================
class TESModelTextureSwap +0000 (_vtbl=0107CEF0)
0000: class TESModelTextureSwap
0000: |   class TESModel
0000: |   |   class BaseFormComponent
==============================================================================*/
// 1C
class TESModelTextureSwap : public TESModel
{
public:
	virtual ~TESModelTextureSwap();							// 004552D0

	// @override
	virtual TESModel *	TESModel_Unk_06(void) override;		// 00C707B0 { return this; }

	// 0C
	struct SwapInfo
	{
		BGSTextureSet	* textureSet;	// 00
		UInt32			unk04;			// 04 - index?
		BSFixedString	name;			// 08
	};

	SwapInfo	* m_swaps;		// 14
	UInt32		m_count;		// 18
};
