#pragma once

#include <atomic>

class GFxResourceLibBase;

class GFxResource //: public GNewOverrideBase<GStat_Default_Mem>
{
	friend class GFxResourceWeakLib;

private:
	// @members;
	std::atomic_int32_t		RefCount;
	GFxResourceLibBase		* pLib;

public:
	enum ResourceType
	{
		RT_CharacterDef_Bit = 0x0080,
		RT_None = 0,
		RT_Image,
		RT_Font,
		RT_MovieDef,
		RT_SoundSample,
		RT_MovieDataDef = RT_CharacterDef_Bit | 0,
		RT_ButtonDef,
		RT_TextDef,
		RT_EditTextDef,
		RT_SpriteDef,
		RT_ShapeDef,
		RT_VideoDef,
		RT_TypeCode_Mask = 0xFF00,
		RT_TypeCode_Shift = 8
	};

	enum ResourceUse
	{
		Use_None = 0,
		Use_Bitmap = 1,
		Use_Gradient = 2,
		Use_FontTexture = 3,
		Use_SoundSample = 4,
		Use_TypeCode_Mask = 0xFF
	};

	GFxResource() : RefCount(1), pLib(nullptr)
	{
	}

	virtual ~GFxResource();

	//virtual	GFxResourceKey		GetKey() { GASSERT(0); return GFxResourceKey(); }
	//virtual	UInt32				GetResourceTypeCode() const { return MakeTypeCode(RT_None); }
	//virtual	GFxResourceReport *	GetResourceReport() { return 0; }
	virtual void Unk_00();
	virtual void Unk_01();
	virtual void Unk_02();

	void        AddRef();
	void        Release();
	bool        AddRef_NotZero();
	SInt32      GetRefCount() const;
};
