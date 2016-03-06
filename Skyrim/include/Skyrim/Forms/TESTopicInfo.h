#pragma once

#include "TESForm.h"
#include "../FormComponents/Condition.h"
#include "../BSCore/BSFixedString.h"
#include "../BSCore/BSString.h"

class TESTopic;
class TESNPC;
class BGSSoundOutput;
class BGSSoundDescriptorForm;
class TESIdleForm;

/*==============================================================================
class TESTopicInfo +0000 (_vtbl=010A6CCC)
0000: class TESTopicInfo
0000: |   class TESForm
0000: |   |   class BaseFormComponent
==============================================================================*/
// 2C
class TESTopicInfo : public TESForm
{
public:
	enum { kTypeID = (UInt32)FormType::TopicInfo };

	enum DialogFlag
	{
		kDialogFlag_Goodbye =					1 << 0,
		kDialogFlag_Random =					1 << 1,
		kDialogFlag_SayOnce =					1 << 2,
		kDialogFlag_RandomEnd =					1 << 5,
		kDialogFlag_InvisibleContinue =			1 << 6,
		kDialogFlag_ForceSubtitle =				1 << 8,
		kDialogFlag_CanMoveWhileGreeting =		1 << 10,
		kDialogFlag_HasNoLipFile =				1 << 11,
		kDialogFlag_RequiresPostProcessing =	1 << 12,
		kDialogFlag_SpendsFavorPoints =			1 << 14,
	};

	enum EmotionType
	{
		kEmotionType_Neutral	= 0,
		kEmotionType_Anger,
		kEmotionType_Disgust,
		kEmotionType_Fear,
		kEmotionType_Sad,
		kEmotionType_Happy,
		kEmotionType_Surprise,
		kEmotionType_Puzzled
	};

	// 28
	struct ResponseData
	{
		UInt32					emotionType;		// 00
		UInt32					emotionValue;		// 04
		UInt32					unk08;				// 08
		UInt32					unk0C;				// 0C
		BGSSoundDescriptorForm	* sound;			// 10
		UInt32					unk14;				// 14
		const char				* responseText;		// 18
		TESIdleForm				* idleSpeaker;		// 1C
		TESIdleForm				* idleListener;		// 20
		ResponseData			* next;				// 24
	};
	STATIC_ASSERT(sizeof(ResponseData) == 0x28);


	virtual ~TESTopicInfo();		// 0057ED90

	// @override
	virtual void	Unk_04(void) override;									// 04 0057E4E0
	virtual void	Unk_05(void) override;									// 05 0057E580
	virtual bool	LoadForm(TESFile *mod) override;						// 06 0057E8F0
	virtual void	LoadBuffer(BGSLoadFormBuffer *buf) override;			// 0F 0057D4D0 set unk22 1
	virtual void	Unk_12(BGSLoadFormBuffer *buf) override;				// 12 0057D4F0 set unk22 0
	virtual void	InitItem(void) override;								// 13 0057E5D0
	virtual void	GetFormDesc(char * buf, UInt32 bufLen) override;		// 16 004D43E0 { return; }
	virtual void	SetFlag00000002(bool set) override;						// 24 0057D430
	virtual bool	Unk_30(void * arg0, UInt32 arg1, UInt32 arg2) override;	// 30 0057D320
	virtual bool	Unk_31(void * dst, void * unk) override;				// 31 0057D470

	const char *		GetPrompt() const;
	TESNPC *			GetSpeaker() const;
	TESTopic *			GetWalkAwayTopic() const;
	BGSSoundOutput *	GetSoundOutputOverride() const;

	// @members
	TESTopic		* topic;			// 14
	TESTopicInfo	* sharesInfo;		// 18 - DNAM - share response data from info?
	Condition		* conditions;		// 1C - CTDA
	UInt16			unk20;				// 20 - init'd to FFFF
	UInt8			unk22;				// 22
	UInt8			favorLevel;			// 23 - CNAM
	UInt16			dialogFlags;		// 24 - ENAM - Response flags
	UInt16			hoursUntilReset;	// 26
	UInt32			unk28;				// 28 - response data

private:
	DEFINE_MEMBER_FN(ctor, TESTopicInfo *, 0x0057ECC0);
	DEFINE_MEMBER_FN(dtor, void, 0x0057ECF0);

	DEFINE_MEMBER_FN(GetResponseData, void *, 0x0057DA40, ResponseData *& rawData);

	DEFINE_MEMBER_FN(SendEvent, void, 0x0057E1F0, UInt32 flag, RefHandle speakerRefHandle, bool arg3);
};
STATIC_ASSERT(sizeof(TESTopicInfo) == 0x2C);
