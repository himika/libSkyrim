#pragma once

// 04
class BSISoundOutputModel
{
public:
	virtual ~BSISoundOutputModel();		// 00500C60

	virtual void	BSISoundOutputModel_Unk_01(void) = 0;
	virtual void	BSISoundOutputModel_Unk_02(void) = 0;
	virtual void	BSISoundOutputModel_Unk_03(void) = 0;
	virtual void	BSISoundOutputModel_Unk_04(void) = 0;
	virtual void	BSISoundOutputModel_Unk_05(void) = 0;
	virtual void	BSISoundOutputModel_Unk_06(void) = 0;
	virtual void	BSISoundOutputModel_Unk_07(void) = 0;
	virtual void	BSISoundOutputModel_Unk_08(void) = 0;
	virtual void	BSISoundOutputModel_Unk_09(void) = 0;

	struct BSIAttenuationCharacteristics
	{
		virtual ~BSIAttenuationCharacteristics();	// 00500C90
		virtual void Unk_001(void) = 0;
		virtual void Unk_002(void) = 0;
		virtual void Unk_003(void) = 0;
	};

	//	void	** _vtbl;	// 00
};

