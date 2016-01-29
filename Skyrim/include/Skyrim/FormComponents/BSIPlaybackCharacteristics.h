#pragma once

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
