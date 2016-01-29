#pragma once

/*==============================================================================
class BGSOpenCloseForm +0000 (_vtbl=0108411C)
0000: class BGSOpenCloseForm
==============================================================================*/
// 04
class BGSOpenCloseForm
{
public:
	virtual ~BGSOpenCloseForm();													// 0049FD20

	virtual	void	ProcessOpen(TESObjectREFR *target, Actor *activator);		// 004D43E0 { return; }
	virtual	void	ProcessClose(TESObjectREFR *target, Actor *activator);		// 004D43E0 { return; }
	virtual	bool	CanProcessOpenClose(void);									// 0092D110 { return false; }

	//void	** _vtbl;	// 00 - 0108411C
};
