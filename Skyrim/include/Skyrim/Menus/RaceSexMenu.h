#pragma once

#include "IMenu.h"
#include "../Camera/RaceSexCamera.h"
#include "../BSCore/BSTArray.h"
#include "../BSDevices/MenuEventHandler.h"

class BGSHeadPart;
class TESRace;

class RaceMenuSlider
{
public:
	RaceMenuSlider::RaceMenuSlider() {};
	RaceMenuSlider::RaceMenuSlider(UInt32 filterFlag, const char * sliderName, const char * callbackName, UInt32 sliderId, UInt32 index, UInt32 type, UInt8 unk8, float min, float max, float value, float interval, UInt32 unk13);

	enum {
		kTypeHeadPart = 0,
		kTypeUnk1,
		kTypeDoubleMorph,
		kTypePreset,
		kTypeTintingMask,
		kTypeHairColorPreset,
		kTypeUnk6,
		kTypeUnused7,
		kTypeUnk8,
		kTypeUnk9,
		kTypeUnk10
	};

	float	min;	// 00
	float	max;	// 04
	float	value;	// 08
	float	interval;	// 0C
	UInt32	filterFlag;	// 10
	UInt32	type;	// 14
	const char	* name;	// 18
	char	callback[260];	// 1C - MAX_PATH = 260
	UInt32	index;	// 120
	UInt32	id;	// 124
	UInt32	unk128;	// 128
	UInt32	unk12C;	// 12C - 0x7F7FFFFF
	UInt8	unk130;	// 130
	UInt8	pad131[3]; // 131


private:
	DEFINE_MEMBER_FN(ctor, RaceMenuSlider *, 0x0087D840, UInt32 filterFlag, const char * sliderName, const char * callbackName, UInt32 sliderId, UInt32 index, UInt32 type, UInt8 unk8, float min, float max, float value, float interval, UInt32 unk13);
};


/*==============================================================================
class RaceSexMenu +0000 (_vtbl=010E7404)
0000: class RaceSexMenu
0000: |   class IMenu
0000: |   |   class FxDelegateHandler
0000: |   |   |   class GRefCountBase<class FxDelegateHandler,2>
0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   |   |   class GRefCountImpl
0000: |   |   |   |   |   |   class GRefCountImplCore
001C: |   class MenuEventHandler
0020: |   |   struct BSIntrusiveRefCounted
==============================================================================*/
class RaceSexMenu : public IMenu,
	public MenuEventHandler			// 1C
{
public:
	// unk0C - 3
	// Flags - 0x709
	// unk14 - 3

	enum {
		kHeadPartsHairLine = 0,
		kHeadPartsHead,
		kHeadPartsEyes,
		kHeadPartsHair,
		kHeadPartsBeard,
		kHeadPartsScars,
		kHeadPartsBrows,
		kNumHeadPartLists
	};

	struct RaceComponent
	{
		TESRace						* race;		// 00
		BSTArray<RaceMenuSlider>	sliders;	// 04
		UInt32						unk10;		// 10
	};

	// @override
	virtual bool	CanProcess(InputEvent *evn) override;				// 00880990
	virtual bool	ProcessThumbstick(ThumbstickEvent *evn) override;	// 0087E3C0
	virtual bool	ProcessMouseMove(MouseMoveEvent *evn) override;		// 0087E700
	virtual bool	ProcessButton(ButtonEvent *evn) override;			// 008809F0

	// @members
	//void					** _vtbl;						// 00 - 010E7404
	//void					** _vtblMenuEventHandler;		// 1C - 010E73E8
	BSTArray<BGSHeadPart*>	headParts[kNumHeadPartLists];	// 28 - 70
															// 28 - BSTArray<BGSHeadPart*>	hairline;
															// 34 - BSTArray<BGSHeadPart*>	head;
															// 40 - BSTArray<BGSHeadPart*>	eyes;
															// 4C - BSTArray<BGSHeadPart*>	hair;
															// 58 - BSTArray<BGSHeadPart*>	beard
															// 64 - BSTArray<BGSHeadPart*>	scars;
															// 70 - BSTArray<BGSHeadPart*>	brows;
	RaceSexCamera			camera;							// 7C
	float					unkA4[0x07];					// A4
	BSTArray<RaceComponent*>	sliderData[2];				// C0
	UInt32					unkD8;							// D8
	UInt32					unkDC;							// DC
	UInt32					unkE0;							// E0
	UInt32					raceIndex;						// E4

	DEFINE_MEMBER_FN(LoadSliders, void *, 0x00882290, UInt32 unk1, UInt8 unk2);

};
STATIC_ASSERT(offsetof(RaceSexMenu, sliderData) == 0xC0);
STATIC_ASSERT(offsetof(RaceSexMenu, raceIndex) == 0xE4);
