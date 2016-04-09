#pragma once


/*==============================================================================
class BSISoundDescriptor +0000 (_vtbl=0108E0B0)
0000: class BSISoundDescriptor
==============================================================================*/
// 04
class BSISoundDescriptor
{
public:
	/*==============================================================================
	struct BSISoundDescriptor::BSIPlaybackCharacteristics +0000 (_vtbl=0108E410)
	0000: struct BSISoundDescriptor::BSIPlaybackCharacteristics
	==============================================================================*/
	class BSIPlaybackCharacteristics
	{
	public:
		virtual ~BSIPlaybackCharacteristics();

		virtual UInt8	GetFrequencyShift(void) = 0;
		virtual UInt8	GetFrequencyVariance(void) = 0;
		virtual UInt8	GetPriority(void) = 0;
		virtual UInt16	GetDBAttenuation(void) = 0;
		virtual UInt8	GetDBVariance(void) = 0;
	};


	virtual ~BSISoundDescriptor();

	virtual void	BSISoundDescriptor_Unk_01(void) = 0;
	virtual void	BSISoundDescriptor_Unk_02(void) = 0;

	//	void	** _vtbl;	// 00
};
