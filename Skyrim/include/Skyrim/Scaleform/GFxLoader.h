#pragma once

#include "GRefCount.h"

class GFxTranslator;



/*==============================================================================
class GFxState +0000 (_vtbl=0110E014)
0000: class GFxState
0000: |   class GRefCountBase<class GFxState,2>
0000: |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   class GRefCountImpl
0000: |   |   |   |   class GRefCountImplCore
==============================================================================*/
// 0C
class GFxState : public GRefCountBase<GFxState>
{
public:
	enum StateType
	{
		State_None,

		// *** Instance - related states.
		State_RenderConfig,
		State_RenderStats,
		State_Translator,
		State_Log,
		State_ImageLoader,
		State_ActionControl,
		State_UserEventHandler,
		State_FSCommandHandler,
		State_ExternalInterface,

		// *** Loading - related states.
		State_FileOpener,
		State_URLBuilder,
		State_ImageCreator,
		State_ParseControl,
		State_ProgressHandler,
		State_ImportVisitor,
		//State_ImageVisitor,
		State_MeshCacheManager,
		State_FontPackParams,
		State_FontCacheManager,
		State_FontLib,
		State_FontProvider,
		State_FontMap,
		State_GradientParams,
		State_TaskManager,
		State_TextClipboard,
		State_TextKeyMap,
		State_PreprocessParams,
		State_IMEManager,
		State_XMLSupport,
		State_JpegSupport,
		State_ZlibSupport,
		State_FontCompactorParams,
		State_ImagePackerParams,
		State_PNGSupport,
		State_Audio,
		State_Video,
		State_TestStream,
		State_SharedObject,
		State_LocSupport
	};

protected:
	StateType       SType;	// 08

public:
	GFxState(StateType st = State_None) : SType(st) { }
	virtual ~GFxState() { }

	inline StateType   GetStateType() const { return SType; }
};


class GImageInfoBase;

/*==============================================================================
class GFxImageLoader +0000 (_vtbl=????????)
0000: class GFxImageLoader
0000: |   class GFxState
0000: |   |   class GRefCountBase<class GFxState,2>
0000: |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   |   class GRefCountImpl
0000: |   |   |   |   |   class GRefCountImplCore
==============================================================================*/
class GFxImageLoader : public GFxState
{
public:
	GFxImageLoader() : GFxState(State_ImageLoader)
	{
	}

	virtual GImageInfoBase * LoadImage(const char* purl) = 0;
};



class GFxFileConstants
{
public:

	// All File formats supported and/or used by GFx.
	enum FileFormatType
	{
		File_Unopened,
		File_Unknown,

		// SWF file formats.
		File_SWF,
		File_GFX,

		// Image formats supported by Flash.        
		File_JPEG = 10,
		File_PNG = 11,
		File_GIF = 12,
		// Other image formats.
		File_TGA = 13,
		File_DDS = 14,
		File_HDR = 15,
		File_BMP = 16,
		File_DIB = 17,
		File_PFM = 18,
		File_TIFF = 19,

		// Sound formats
		File_WAVE = 20,

		File_NextAvail,
		File_Original = 65535
	};
};



class GFxStateBag : public GFxFileConstants
{
protected:
	virtual	GFxStateBag *	GetStateBagImpl(void) const;	// { return 0; }

public:
	virtual	~GFxStateBag();

	virtual void		SetState(GFxState::StateType state, GFxState* pstate);
	virtual void *		GetStateAddRef(GFxState::StateType state) const;
	virtual void        GetStatesAddRef(GFxState** pstateList, const GFxState::StateType *pstates, UInt32 count) const;

	inline GFxTranslator *	GetTranslator() const { return (GFxTranslator*)GetStateAddRef(GFxState::State_Translator); }

};



class GFxLoaderImpl;
class GFxResourceLib;
class GFxMovieInfo;
class GFxMovieDef;

class GFxLoader : public GFxStateBag
{
	GFxLoaderImpl	* pImpl;				// 04
	GFxResourceLib	* pStrongResourceLib;	// 08
	UInt32			DefLoadFlags;			// 0C

protected:
	// @add
	virtual GFxStateBag* GetStateBagImpl() const override;
	virtual bool CheckTagLoader(int tagType) const;

public:
	enum LoadConstants
	{
		LoadAll				= 0x00000000,
		LoadWaitCompletion	= 0x00000001,
		LoadWaitFrame1		= 0x00000002,
		LoadOrdered			= 0x00000010,
		LoadThreadedBinding	= 0x00000020,
		LoadOnThread		= 0x00000040,
		LoadKeepBindData	= 0x00000080,
		LoadImageFiles		= 0x00010000,
		LoadDisableSWF		= 0x00080000,
		LoadDisableImports	= 0x00100000,
		LoadQuietOpen		= 0x00200000,

		LoadDebugHeap		= 0x10000000
	};

	GFxLoader(const GFxLoader& src);

	virtual ~GFxLoader();

	bool GetMovieInfo(const char* pFileName, GFxMovieInfo *pMovieInfo, bool getTagCount = 0, UInt32 loadConstants = LoadAll);
	GFxMovieDef* CreateMovie(const char* pFileName, UInt32 loadConstants = LoadAll, std::size_t memoryArena = 0);

	void UnpinAll();
	void CancelLoading();

	GFxLoaderImpl * GetLoaderImpl() const { return pImpl; }
};
STATIC_ASSERT(sizeof(GFxLoader) == 0x10);
