#pragma once

#include "../Scaleform/GFxLoader.h"
#include "../Scaleform/GFxPlayer.h"
#include "../Menus/IMenu.h"

/*==============================================================================
class BSScaleformImageLoader +0000 (_vtbl=0110E86C)
0000: class BSScaleformImageLoader
0000: |   class GFxImageLoader
0000: |   |   class GFxState
0000: |   |   |   class GRefCountBase<class GFxState,2>
0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   |   |   class GRefCountImpl
0000: |   |   |   |   |   |   class GRefCountImplCore
==============================================================================*/
class BSScaleformImageLoader : public GFxImageLoader
{
public:
	virtual ~BSScaleformImageLoader();						// 00A65F60
	virtual GImageInfoBase*	LoadImage(const char * url);	// 00A655F0;

	DEFINE_MEMBER_FN(AddVirtualImage, UInt8, 0x00A65710, NiTexture ** texture);
	DEFINE_MEMBER_FN(ReleaseVirtualImage, UInt8, 0x00A65A40, NiTexture ** texture);
};


class BSScaleformMovieLoader
{
public:
	static BSScaleformMovieLoader * GetSingleton()
	{
		return *((BSScaleformMovieLoader **)0x01B2E9B0);
	}

	inline bool LoadMovie(IMenu *menu, GFxMovieView *&viewOut, const char *swfName, GFxMovieView::ScaleModeType mode, float backgroundAlpha)
	{
		return LoadMovie_Impl(menu, viewOut, swfName, mode, backgroundAlpha);
	}


	// @members
	UInt32					unk00;				// 00
	GFxStateBag				* stateBag;			// 04
	void					* unk08;			// 08 - size 4 - ctor 0x00A62310
	UInt32					unk0C;				// 0C
	BSScaleformImageLoader	* imageLoader;		// 10
	UInt32					unk14;
	UInt16					unk18;
	UInt16					unk1A;

private:
	DEFINE_MEMBER_FN(ctor, UInt32, 0x00A60FE0);

	DEFINE_MEMBER_FN(LoadMovie_Impl, bool, 0x00A60C80, IMenu *menu, GFxMovieView *&viewOut, const char *swfName, UInt32 flags, float backgroundAlpha);
	DEFINE_MEMBER_FN(CreateMovie_Impl, bool, 0x00A60C10, UInt32 arg1, UInt32 arg2)
};
