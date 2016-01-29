#pragma once

#include "GTypes.h"
#include "GRefCount.h"
#include "GList.h"

class GTexture;
class GRendererEventHandler;
class GRenderTarget;
class GImageBase;

enum GStatRenderer
{
	GStatRender_Default = GStatGroup_Renderer,

	GStatRender_Mem,

	// Video Memory.
	GStatRender_VMem,
	  GStatRender_Texture_VMem,
	  GStatRender_Buffer_VMem,
	
	// Counts
	GStatRender_Counters,
	  GStatRender_TextureUpload_Cnt,
	  GStatRender_TextureUpdate_Cnt,
	  GStatRender_DP_Cnt,
		GStatRender_DP_Line_Cnt,
		GStatRender_DP_Triangle_Cnt,
	  GStatRender_Triangle_Cnt,
	  GStatRender_Line_Cnt,
	  GStatRender_Mask_Cnt,
	  GStatRender_Filter_Cnt,
};



class GViewport
{
public:
	SInt32	BufferWidth, BufferHeight;
	SInt32	Left, Top;
	SInt32	Width, Height;
	SInt32	ScissorLeft, ScissorTop;
	SInt32	ScissorWidth, ScissorHeight;
	float	Scale, AspectRatio;
	UInt32	Flags;

	enum
	{
		View_IsRenderTexture = 1,
		View_AlphaComposite = 2,
		View_UseScissorRect = 4,
		View_NoSetState = 8,
		View_RenderTextureAlpha = View_IsRenderTexture | View_AlphaComposite
	};

	GViewport()
	{
		BufferWidth = 0; BufferHeight = 0; Left = Top = 0; Width = Height = 1; ScissorLeft = ScissorTop = ScissorWidth = ScissorHeight = 0; Flags = 0;
		Scale = AspectRatio = 1.0f;
	}
	GViewport(SInt32 bw, SInt32 bh, SInt32 left, SInt32 top, SInt32 w, SInt32 h, SInt32 scleft, SInt32 sctop, SInt32 scw, SInt32 sch, UInt32 flags = 0)
	{
		BufferWidth = bw; BufferHeight = bh; Left = left; Top = top; Width = w; Height = h; Flags = flags | View_UseScissorRect;
		Scale = AspectRatio = 1.0f;
		SetScissorRect(scleft, sctop, scw, sch);
	}
	GViewport(SInt32 bw, SInt32 bh, SInt32 left, SInt32 top, SInt32 w, SInt32 h, SInt32 scleft, SInt32 sctop, SInt32 scw, SInt32 sch, float scale, float ratio, UInt32 flags = 0)
	{
		BufferWidth = bw; BufferHeight = bh; Left = left; Top = top; Width = w; Height = h; Flags = flags | View_UseScissorRect;
		Scale = scale; AspectRatio = ratio;
		SetScissorRect(scleft, sctop, scw, sch);
	}
	GViewport(SInt32 bw, SInt32 bh, SInt32 left, SInt32 top, SInt32 w, SInt32 h, UInt32 flags = 0)
	{
		BufferWidth = bw; BufferHeight = bh; Left = left; Top = top; Width = w; Height = h; Flags = flags;
		ScissorLeft = ScissorTop = ScissorWidth = ScissorHeight = 0;
		Scale = AspectRatio = 1.0f;
	}
	GViewport(const GViewport& src)
	{
		BufferWidth = src.BufferWidth; BufferHeight = src.BufferHeight; Left = src.Left; Top = src.Top; Width = src.Width; Height = src.Height; Flags = src.Flags;
		ScissorLeft = src.ScissorLeft; ScissorTop = src.ScissorTop; ScissorWidth = src.ScissorWidth; ScissorHeight = src.ScissorHeight;
		Scale = src.Scale; AspectRatio = src.AspectRatio;
	}


	void SetViewport(SInt32 bw, SInt32 bh, SInt32 left, SInt32 top, SInt32 w, SInt32 h, UInt32 flags = 0)
	{
		BufferWidth = bw; BufferHeight = bh; Left = left; Top = top; Width = w; Height = h; Flags = flags;
		ScissorLeft = ScissorTop = ScissorWidth = ScissorHeight = 0;
		Scale = AspectRatio = 1.0f;
	}


	void SetScissorRect(SInt32 scleft, SInt32 sctop, SInt32 scw, SInt32 sch)
	{
		ScissorLeft = scleft; ScissorTop = sctop; ScissorWidth = scw; ScissorHeight = sch;
		Flags |= View_UseScissorRect;
	}
};


class GRenderer : public GRefCountBase<GRenderer, GStatRender_Mem>
{
public:
	GRenderer();
	virtual ~GRenderer(); 

	typedef GPointF     Point;
	typedef GRectF      Rect;
	typedef GMatrix2D   Matrix;
	typedef void*       Handle;

	enum BlendType
	{
		Blend_None          = 0,
		Blend_Normal        = 1,
		Blend_Layer         = 2,
		Blend_Multiply      = 3,
		Blend_Screen        = 4,
		Blend_Lighten       = 5,
		Blend_Darken        = 6,
		Blend_Difference    = 7,
		Blend_Add           = 8,
		Blend_Subtract      = 9,
		Blend_Invert        = 10,
		Blend_Alpha         = 11,
		Blend_Erase         = 12,
		Blend_Overlay       = 13,
		Blend_HardLight     = 14
	};

	enum ResizeImageType
	{
		ResizeRgbToRgb,
		ResizeRgbaToRgba,
		ResizeRgbToRgba,
		ResizeGray
	};

	enum VertexFormat
	{
		Vertex_None         = 0,
		Vertex_XY16i        = 1,
		Vertex_XY32f        = 2,
		Vertex_XY16iC32     = 3,
		Vertex_XY16iCF32    = 4 
	};

	enum IndexFormat
	{
		Index_None      = 0,
		Index_16        = 1,
		Index_32        = 2 
	};

	enum RenderCapBits
	{
		Cap_CacheDataUse            = 0x00000001,       
		Cap_Index16                 = 0x00000004,
		Cap_Index32                 = 0x00000008,
		Cap_RenderStats             = 0x00000010,
		
		Cap_FillGouraud             = 0x00000100,
		Cap_FillGouraudTex          = 0x00000200,

		Cap_CxformAdd               = 0x00001000,

		Cap_NestedMasks             = 0x00002000,

		Cap_TexNonPower2            = 0x00004000,
		Cap_TexNonPower2Wrap        = 0x00008000,
		Cap_TexNonPower2Mip         = 0x00080000,

		Cap_CanLoseData             = 0x00010000,
		Cap_KeepVertexData          = 0x00020000,
		Cap_NoTexOverwrite          = 0x00040000,
		Cap_ThreadedTextureCreation = 0x00100000,

		Cap_RenderTargets           = 0x00000020,
		Cap_RenderTargetPrePass     = 0x00000040,
		Cap_RenderTargetNonPow2     = 0x00000080,
		Cap_RenderTargetMip         = 0x00200000,

		Cap_Filter_Blurs            = 0x00400000,
		Cap_Filter_ColorMatrix      = 0x00800000,

	};

	enum StereoDisplay
	{
		StereoCenter,
		StereoLeft,
		StereoRight
	};

	struct StereoParams
	{
		float DisplayWidthCm;
		float Distortion;
		float DisplayDiagInches;
		float DisplayAspectRatio;
		float EyeSeparationCm;
		StereoParams() : DisplayWidthCm(0), Distortion(0.75f), DisplayDiagInches(52.f), DisplayAspectRatio(9.f/16.f), EyeSeparationCm(6.4f) {  }
	};

	struct RenderCaps
	{
		UInt32  CapBits;
		UInt32  VertexFormats;
		UInt32  BlendModes;
		UInt32  MaxTextureSize; 
	};

	class Stats
	{
	public:
		UInt32    Triangles;
		UInt32    Lines;
		UInt32    Primitives;
		UInt32    Masks;
		UInt32    Filters;

		Stats()         { Clear();}
		void Clear()    { Triangles = 0; Lines = 0; Primitives = 0; Masks = 0; Filters = 0; }           
	};

	class CacheProvider;

	enum CachedDataType
	{
		Cached_Vertex      = 1,
		Cached_Index       = 2,
		Cached_BitmapList  = 3
	};

	class CachedData
	{
		friend class CacheProvider;

		GRenderer * pRenderer;
		Handle      hData;

	public:
		FORCE_INLINE CachedData();
		FORCE_INLINE ~CachedData();

		FORCE_INLINE GRenderer*  GetRenderer() const         { return pRenderer; }
		FORCE_INLINE Handle      GetRendererData() const     { return hData; }
		FORCE_INLINE void        SetRendererData(Handle h)   { hData = h; }

		FORCE_INLINE void        ReleaseData(CachedDataType type);
		FORCE_INLINE void        ReleaseDataByRenderer();        
	};

	class CacheProvider
	{
		friend class GFxCachedStroke;
		friend class GFxMesh;

		CachedData*     pData;      
		bool            DiscardSharedData;

	public:
		FORCE_INLINE CacheProvider(CachedData* pcache);
		FORCE_INLINE ~CacheProvider();
		FORCE_INLINE CachedData*     GetCachedData(GRenderer* prenderer);
		FORCE_INLINE CachedData*     CreateCachedData(GRenderer::CachedDataType type, GRenderer* prenderer, bool keepSharedData = 1);
		FORCE_INLINE bool            CanDiscardData() { return DiscardSharedData; }
	};

	class Cxform
	{
	public:
		float   M_[4][2];

		Cxform();
		void    Concatenate(const Cxform& c);
		GColor  Transform(const GColor in) const;
		
		void    Format(char *pbuffer) const;        

		void    SetIdentity();
		bool    IsIdentity() const;

		bool    operator== (const Cxform& x) const
		{
			return M_[0][0] == x.M_[0][0] && M_[1][0] == x.M_[1][0] && M_[2][0] == x.M_[2][0] && M_[3][0] == x.M_[3][0] &&
				M_[0][1] == x.M_[0][1] && M_[1][1] == x.M_[1][1] && M_[2][1] == x.M_[2][1] && M_[3][1] == x.M_[3][1];
		}
		static Cxform   Identity;
	};

	enum UserDataPropertyFlag
	{
		UD_None = 0x0,
		UD_HasString,
		UD_HasFloat,
		UD_HasMatrix
	};

	struct UserData
	{
		const char*     pString;
		float*          pFloat;
		float*          pMatrix;
		UInt32            MatrixSize;
		UInt8           PropFlags;
		UserData()
			: pString(NULL), pFloat(NULL), pMatrix(0), MatrixSize(0), PropFlags(UD_None) { }
	};

	enum BitmapWrapMode
	{
		Wrap_Repeat,
		Wrap_Clamp
	};
	enum BitmapSampleMode
	{
		Sample_Point,
		Sample_Linear
	};

	struct FillTexture
	{
		GTexture*           pTexture;
		Matrix              TextureMatrix;
		BitmapWrapMode      WrapMode;
		BitmapSampleMode    SampleMode;
	};

	struct VertexXY16i
	{
		SInt16 x;
		SInt16 y;
	};

	struct VertexXY16iC32
	{
		enum { VFormat = Vertex_XY16iC32 };
		SInt16  x, y;
		UInt32  Color;
	};

	struct VertexXY16iCF32
	{
		enum { VFormat = Vertex_XY16iCF32 };
		SInt16  x, y;
		UInt32  Color;
		UInt32  Factors;
	};

	enum GouraudFillType
	{
		GFill_Color,
		GFill_1Texture,
		GFill_1TextureColor,
		GFill_2Texture,
		GFill_2TextureColor,
		GFill_3Texture
	};

	struct BitmapDesc
	{
		Rect    Coords;
		Rect    TextureCoords;
		GColor  Color;
	};

	struct DistanceFieldParams
	{
		float   Width;

		float   ShadowWidth;
		GColor  ShadowColor;
		GPointF ShadowOffset;
		GColor  GlowColor;
		float   GlowSize[2];

		DistanceFieldParams() : Width(6), ShadowWidth(12), ShadowColor(0), ShadowOffset(5, 5), GlowColor(0) {}
	};

	enum SubmitMaskMode
	{
		Mask_Clear,
		Mask_Increment,
		Mask_Decrement
	};

	enum FilterModes
	{
		Filter_Blur = 1,
		Filter_Shadow = 2,
		Filter_Highlight = 4,

		Filter_Knockout = 0x100,
		Filter_Inner = 0x200,
		Filter_HideObject = 0x400,

		Filter_UserModes = 0x0ffff,
		Filter_SkipLastPass = 0x10000,
		Filter_LastPassOnly = 0x20000,
	};

	enum FilterSupport
	{
		FilterSupport_None = 0,
		FilterSupport_Ok = 1,
		FilterSupport_Multipass = 2,
		FilterSupport_Slow = 4,
	};

	struct BlurFilterParams
	{
		UInt32    Mode;
		float   BlurX, BlurY;
		UInt32    Passes;
		GPointF Offset;
		GColor  Color, Color2;
		float   Strength;
		Cxform  cxform;

		BlurFilterParams() : Mode(0), BlurX(5), BlurY(5), Passes(1), Offset(0, 0), Strength(1) {}
		BlurFilterParams(UInt32 mode, float x, float y, UInt32 n = 1, GPointF offset = GPointF(0, 0), GColor color = GColor(), float str = 1, Cxform& cx = Cxform::Identity)
			: Mode(mode), BlurX(x), BlurY(y), Passes(n), Offset(offset), Color(color), Strength(str), cxform(cx) {}

		BlurFilterParams(UInt32 mode, float x, float y, UInt32 n = 1, float str = 1, Cxform& cx = Cxform::Identity)
			: Mode(mode), BlurX(x), BlurY(y), Passes(n), Offset(0, 0), Strength(str), cxform(cx) {}

		bool operator==(const BlurFilterParams& b) const
		{
			return (Mode == b.Mode && BlurX == b.BlurX && BlurY == b.BlurY && Passes == b.Passes);
		}

		BlurFilterParams& Scale(float x, float y)
		{
			BlurX = G_Max<float>(1, BlurX*x);
			BlurY = G_Max<float>(1, BlurY*y);
			Offset.x *= x;
			Offset.y *= y;
			return *this;
		}
	};

	// @add
	virtual bool        GetRenderCaps(RenderCaps *pcaps)                                = 0;	// 01
	virtual GTexture*   CreateTexture()                                                 = 0;	// 02
	virtual GTexture*   CreateTextureYUV()                                              = 0;	// 03
	virtual void        BeginFrame() { }														// 04
	virtual void        EndFrame();																// 05
	virtual GRenderTarget*   CreateRenderTarget()                                       = 0;
	virtual void        SetDisplayRenderTarget(GRenderTarget* prt, bool setstate = 1)   = 0;
	virtual void        PushRenderTarget(const GRectF& frameRect, GRenderTarget* prt)   = 0;
	virtual void        PopRenderTarget()                                               = 0;
	virtual GTexture*   PushTempRenderTarget(const GRectF& frameRect, UInt32 targetW, UInt32 targetH) = 0;
	virtual void        ReleaseTempRenderTargets(UInt32 keepArea);
	virtual void        BeginDisplay(GColor backgroundColor, const GViewport& viewport, float x0, float x1, float y0, float y1) = 0;
	virtual void        EndDisplay()                                                    = 0;
	virtual void        SetMatrix(const Matrix& m)                                      = 0;
	virtual void        SetUserMatrix(const Matrix& m)                                  = 0;
	virtual void        SetCxform(const Cxform& cx)                                     = 0;
	virtual void        PushBlendMode(BlendType mode)                                   = 0;
	virtual void        PopBlendMode()                                                  = 0;
	virtual bool        PushUserData(UserData* pdata);
	virtual void        PopUserData() { }
	virtual void        SetPerspective3D(const GMatrix3D &projMatIn) = 0;
	virtual void        SetView3D(const GMatrix3D &viewMatIn) = 0;
	virtual void        SetWorld3D(const GMatrix3D *pWorldMatIn) = 0;
	virtual void        SetStereoParams(StereoParams sParams);
	virtual void        SetStereoDisplay(StereoDisplay sDisplay, bool setstate = 0);
	virtual void        SetVertexData(const void* pvertices, int numVertices,
									  VertexFormat vf, CacheProvider *pcache = 0)       = 0;
	virtual void        SetIndexData(const void* pindices, int numIndices,
									 IndexFormat idxf, CacheProvider *pcache = 0)       = 0;
	virtual void        ReleaseCachedData(CachedData *pdata, CachedDataType type)		= 0;
	virtual void        DrawIndexedTriList(
									int baseVertexIndex, int minVertexIndex, int numVertices,
									int startIndex, int triangleCount)                  = 0;
	virtual void        DrawLineStrip(int baseVertexIndex, int lineCount)               = 0;
	virtual void        LineStyleDisable()                                              = 0;
	virtual void        LineStyleColor(GColor color)                                    = 0;
	virtual void        FillStyleDisable()                                              = 0;
	virtual void        FillStyleColor(GColor color)                                    = 0;
	virtual void        FillStyleBitmap(const FillTexture* pfill)                       = 0;
	virtual void        FillStyleGouraud(GouraudFillType fillType,
										 const FillTexture *ptexture0 = 0,
										 const FillTexture *ptexture1 = 0,
										 const FillTexture *ptexture2 = 0)              = 0;
	virtual void        DrawBitmaps(BitmapDesc* pbitmapList, int listSize,
									 int startIndex, int count,
									 const GTexture* pti, const Matrix& m,
									 CacheProvider *pcache = 0 )                        = 0;
	virtual void        DrawDistanceFieldBitmaps(BitmapDesc* pbitmapList, int listSize,
												 int startIndex, int count,
												 const GTexture* pti, const Matrix& m, const DistanceFieldParams& params,
												 CacheProvider *pcache = 0 );
	virtual void        BeginSubmitMask(SubmitMaskMode maskMode = Mask_Clear)           = 0;
	virtual void        EndSubmitMask()                                                 = 0;
	virtual void        DisableMask()                                                   = 0;
	virtual UInt32      CheckFilterSupport(const BlurFilterParams& params)              = 0;
	virtual void        DrawBlurRect(GTexture* psrcin, const GRectF& insrcrect, const GRectF& indestrect, const BlurFilterParams& params) = 0;
	virtual void        DrawColorMatrixRect(GTexture* psrcin, const GRectF& insrcrect, const GRectF& destrect, const float *matrix) = 0;
	virtual void        GetRenderStats(Stats *pstats, bool resetStats = 0)              = 0;
	virtual void        GetStats(GStatBag* pbag, bool reset = true)                     = 0;
	virtual void        ReleaseResources()                                              = 0;         
	virtual bool        AddEventHandler(GRendererEventHandler *phandler);
	virtual void        RemoveEventHandler(GRendererEventHandler *phandler);

protected:
	GList<GRendererEventHandler> Handlers;
	StereoParams  S3DParams;
	StereoDisplay S3DDisplay;

	void GetStereoProjectionMatrix(GMatrix3D *left, GMatrix3D *right, const GMatrix3D &original, float screenDist);
};
