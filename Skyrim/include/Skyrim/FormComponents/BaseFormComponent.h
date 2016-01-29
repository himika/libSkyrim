#pragma once

//// root

/*==============================================================================
class BaseFormComponent +0000 (_vtbl=01076B00)
0000: class BaseFormComponent
==============================================================================*/
// 04
class BaseFormComponent
{
public:
	BaseFormComponent();
	virtual ~BaseFormComponent();		// 0044CD10

	virtual void	Init(void);			// pure
	virtual void	ReleaseRefs(void);	// pure
	virtual void	CopyFromBase(BaseFormComponent * rhs);	// pure

	//	void	** _vtbl;	// 00
};
