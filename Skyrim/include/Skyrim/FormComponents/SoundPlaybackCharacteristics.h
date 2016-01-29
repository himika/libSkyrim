#pragma once

#include "BSIPlaybackCharacteristics.h"

class BGSSoundOutput;

class SoundPlaybackCharacteristics : public BSIPlaybackCharacteristics
{
public:
	virtual UInt8	GetFrequencyShift(void) override;
	virtual UInt8	GetFrequencyVariance(void) override;
	virtual UInt8	GetPriority(void) override;
	virtual UInt16	GetDBAttenuation(void) override;
	virtual UInt8	GetDBVariance(void) override;

	UInt8	frequencyShift;
	UInt8	frequencyVariance;
	UInt8	priority;
	UInt8	dbVariance;
	UInt16	dbAttenuation;			// CK Value * 100
	UInt16	pad1A;
	UInt32	unk20;
	BGSSoundOutput	* soundOutput;
	UInt32	unk28;
	UInt32	unk2C;
};

