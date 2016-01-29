#pragma once

class TESTexture;

class TintMask
{
public:
	TintMask()
	{
		alpha = 0.0;
		tintType = 0;
		texture = nullptr;
	};
	~TintMask() { };

#ifdef PAPYRUS_CUSTOM_CLASS
	enum { kTypeID = 300 };
#endif

	enum {
		kMaskType_Frekles = 0,
		kMaskType_Lips,
		kMaskType_Cheeks,
		kMaskType_Eyeliner,
		kMaskType_UpperEyeSocket,
		kMaskType_LowerEyeSocket,
		kMaskType_SkinTone,
		kMaskType_WarPaint,
		kMaskType_FrownLines,
		kMaskType_LowerCheeks,
		kMaskType_Nose,
		kMaskType_Chin,
		kMaskType_Neck,
		kMaskType_Forehead,
		kMaskType_Dirt
	};
	TESTexture	* texture;

	struct Color {
		UInt8 red;
		UInt8 green;
		UInt8 blue;
		UInt8 alpha; // The alpha isn't actually used here so its usually zero
	} color;

	float		alpha;
	UInt32		tintType;

	UInt32 ToARGB();
};

