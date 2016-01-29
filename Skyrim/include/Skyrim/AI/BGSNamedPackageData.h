#pragma once

#include "IPackageData.h"

/*==============================================================================
class BGSNamedPackageData<class IPackageData> +0000 (_vtbl=010C0208)
0000: class BGSNamedPackageData<class IPackageData>
0000: |   class IPackageData
==============================================================================*/
template <class Ty>
class BGSNamedPackageData : public Ty
{
public:
	virtual ~BGSNamedPackageData();										// 005B3FD0

	// @override class IPackageData : (vtbl=010C0208)
	virtual	void	Unk_01(UInt32) override;							// 005B3FD0 { return; }
	virtual	void	Unk_02(UInt32) override;							// 005B3290
	virtual	void	Unk_03(UInt32) override;							// 005B3FD0 { return; }
	virtual	bool	Unk_04(UInt32) override;							// 005B2CD0
};
