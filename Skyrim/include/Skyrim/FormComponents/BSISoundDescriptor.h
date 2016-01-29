#pragma once

// 04
class BSISoundDescriptor
{
public:
	virtual ~BSISoundDescriptor();

	virtual void	BSISoundDescriptor_Unk_01(void) = 0;
	virtual void	BSISoundDescriptor_Unk_02(void) = 0;

	//	void	** _vtbl;	// 00
};

