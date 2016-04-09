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
	virtual ~BaseFormComponent();							// 00 0044CD10

	virtual void	Init(void);								// 01 pure
	virtual void	ReleaseRefs(void);						// 02 pure
	virtual void	CopyFromBase(BaseFormComponent * rhs);	// 03 pure

	//	void	** _vtbl;	// 00
};
