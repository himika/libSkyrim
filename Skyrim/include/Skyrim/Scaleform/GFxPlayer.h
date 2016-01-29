#pragma once

#include "GTypes.h"
#include "GString.h"
#include "GRefCount.h"
#include "GRenderer.h"
#include "GFxLoader.h"
#include "GFxResource.h"
#include "GFxEvent.h"
#include <string.h>
#include <wchar.h>

class GMemoryHeap;
class GStatBag;

class GFxFunctionHandler;

class GFxMovieView;

// 10
class GFxValue
{
	friend class GFxMovieRoot;

public:
	class DisplayInfo
	{
	private:
		// @members
		double		X;						// 00
		double		Y;						// 08
		double		Rotation;				// 10
		double		XScale;					// 18
		double		YScale;					// 20
		double		Alpha;					// 28
		bool		Visible;				// 30
		double		Z;						// 38
		double		XRotation;				// 40
		double		YRotation;				// 48
		double		ZScale;					// 50
		double		PerspFOV;				// 58
		GMatrix3D	ViewMatrix3D;			// 60
		GMatrix3D	PerspectiveMatrix3D;	// A0
		UInt16		VarsSet;				// E0

	public:
		enum Flags
		{
			V_x				= 0x001,
			V_y				= 0x002,
			V_rotation		= 0x004,
			V_xscale		= 0x008,
			V_yscale		= 0x010,
			V_alpha			= 0x020,
			V_visible		= 0x040,
			V_z				= 0x080,
			V_xrotation		= 0x100,
			V_yrotation		= 0x200,
			V_zscale		= 0x400,
			V_perspFOV		= 0x800,
			V_perspMatrix3D	= 0x1000,
			V_viewMatrix3D	= 0x2000
		};

		DisplayInfo() : VarsSet(0)
		{
		}
		DisplayInfo(double x, double y) : VarsSet(0)
		{
			SetFlags(V_x | V_y);
			X = x;
			Y = y;
		}
		DisplayInfo(double rotation) : VarsSet(0)
		{
			SetFlags(V_rotation); Rotation = rotation;
		}
		DisplayInfo(bool visible) : VarsSet(0) {
			SetFlags(V_visible);
			Visible = visible;
		}

		void	Initialize(UInt16 varsSet, double x, double y, double rotation, double xscale, double yscale, double alpha, bool visible, double z, double xrotation, double yrotation, double zscale)
		{
			VarsSet = varsSet;
			X = x;
			Y = y;
			Rotation = rotation;
			XScale = xscale;
			YScale = yscale;
			Alpha = alpha;
			Visible = visible;
			Z = z;
			XRotation = xrotation;
			YRotation = yrotation;
			ZScale = zscale;
			PerspFOV = 55;				// DEFAULT_FLASH_FOV
		}
		void    Clear() { VarsSet = 0; }

		void	SetX(double x)							{ SetFlags(V_x); X = x; }
		void	SetY(double y)							{ SetFlags(V_y); Y = y; }
		void	SetRotation(double degrees)				{ SetFlags(V_rotation); Rotation = degrees; }
		void	SetXScale(double xscale)				{ SetFlags(V_xscale); XScale = xscale; }    // 100 == 100%
		void	SetYScale(double yscale)				{ SetFlags(V_yscale); YScale = yscale; }    // 100 == 100%
		void	SetAlpha(double alpha)					{ SetFlags(V_alpha); Alpha = alpha; }
		void	SetVisible(bool visible)				{ SetFlags(V_visible); Visible = visible; }
		void	SetZ(double z)							{ SetFlags(V_z); Z = z; }
		void	SetXRotation(double degrees)			{ SetFlags(V_xrotation); XRotation = degrees; }
		void	SetYRotation(double degrees)			{ SetFlags(V_yrotation); YRotation = degrees; }
		void	SetZScale(double zscale)				{ SetFlags(V_zscale); ZScale = zscale; }    // 100 == 100%
		void	SetPerspFOV(double fov)					{ SetFlags(V_perspFOV); PerspFOV = fov; }
		void	SetPerspective3D(const GMatrix3D *pmat)
		{
			if (pmat)
			{
				SetFlags(V_perspMatrix3D);
				PerspectiveMatrix3D = *pmat;
			}
			else
			{
				ClearFlags(V_perspMatrix3D);
			}
		}
		void    SetView3D(const GMatrix3D *pmat)
		{
			if (pmat)
			{
				SetFlags(V_viewMatrix3D);
				ViewMatrix3D = *pmat;
			}
			else
			{
				ClearFlags(V_viewMatrix3D);
			}
		}
		void	SetPosition(double x, double y)			{ SetFlags(V_x | V_y); X = x; Y = y; }
		void	SetScale(double xscale, double yscale)	{ SetFlags(V_xscale | V_yscale); XScale = xscale; YScale = yscale; }
		void	Set(double x, double y, double rotation, double xscale, double yscale, double alpha, bool visible, double z, double xrotation, double yrotation, double zscale)
		{
			X = x;
			Y = y;
			Rotation = rotation;
			XScale = xscale;
			YScale = yscale;
			Alpha = alpha;
			Visible = visible;
			SetFlags(V_x | V_y | V_rotation | V_xscale | V_yscale | V_alpha | V_visible);
			Z = z;
			XRotation = xrotation;
			YRotation = yrotation;
			ZScale = zscale;
			SetFlags(V_z | V_zscale | V_xrotation | V_yrotation);
		}

		double	GetX() const						{ return X; }
		double	GetY() const						{ return Y; }
		double	GetRotation() const					{ return Rotation; }
		double	GetXScale() const					{ return XScale; }
		double	GetYScale() const					{ return YScale; }
		double	GetAlpha() const					{ return Alpha; }
		bool	GetVisible() const					{ return Visible; }
		double	GetZ() const						{ return Z; }
		double	GetXRotation() const				{ return XRotation; }
		double	GetYRotation() const				{ return YRotation; }
		double	GetZScale() const					{ return ZScale; }
		double	GetPerspFOV() const					{ return PerspFOV; }
		const	GMatrix3D* GetPerspective3D() const	{ return (IsFlagSet(V_perspMatrix3D)) ? &PerspectiveMatrix3D : nullptr; }
		const	GMatrix3D* GetView3D() const		{ return (IsFlagSet(V_viewMatrix3D)) ? &ViewMatrix3D : nullptr; }
		bool	IsFlagSet(UInt32 flag) const		{ return 0 != (VarsSet & flag); }

	private:
		void    SetFlags(UInt32 flags)		{ VarsSet |= flags; }
		void    ClearFlags(UInt32 flags)	{ VarsSet &= ~flags; }
	};

protected:
	enum ValueTypeControl
	{
		VTC_ConvertBit = 0x80,
		VTC_ManagedBit = 0x40,
		VTC_TypeMask = VTC_ConvertBit | 0x0F,
	};

	class ObjectInterface //: public GNewOverrideBase<GFxStatMV_Other_Mem>
	{
	public:
		class ObjVisitor
		{
		public:
			virtual ~ObjVisitor() {}
			virtual void    Visit(const char* name, const GFxValue& val) = 0;
		};
		class ArrVisitor
		{
		public:
			virtual ~ArrVisitor() {}
			virtual void    Visit(UInt32 idx, const GFxValue& val) = 0;
		};

		ObjectInterface(GFxMovieRoot* pmovieRoot) : pMovieRoot(pmovieRoot) {}

		DEFINE_MEMBER_FN(ObjectAddRef, void, 0x00921DA0, GFxValue *val, void *pobj);
		DEFINE_MEMBER_FN(ObjectRelease, void, 0x00922660, GFxValue *val, void *pobj);
		DEFINE_MEMBER_FN_const(HasMember, bool, 0x00920C50, void *pdata, const char *name, bool isdobj);
		DEFINE_MEMBER_FN_const(GetMember, bool, 0x00923960, void *pdata, const char *name, GFxValue *pval, bool isdobj);
		DEFINE_MEMBER_FN_const(SetMember, bool, 0x00920D20, void *pdata, const char *name, const GFxValue &pval, bool isdobj);
		DEFINE_MEMBER_FN(Invoke, bool, 0x00922ED0, void *pdata, GFxValue *presult, const char *name, const GFxValue *pargs, UInt32 nargs, bool isdobj);
		DEFINE_MEMBER_FN(DeleteMember, bool, 0x00920DE0, void *pdata, const char *name, bool isdobj);
		void    VisitMembers(void* pdata, ObjVisitor* visitor, bool isdobj) const;						// not found
		DEFINE_MEMBER_FN_const(GetArraySize, UInt32, 0x00920E80, void *pdata);
		DEFINE_MEMBER_FN(SetArraySize, bool, 0x00920450, void* pdata, UInt32 sz);
		DEFINE_MEMBER_FN_const(GetElement, bool, 0x00923AD0, void *pdata, UInt32 idx, GFxValue *pval);
		DEFINE_MEMBER_FN(SetElement, bool, 0x00920EA0, void* pdata, UInt32 idx, const GFxValue& value);
		void    VisitElements(void* pdata, ArrVisitor* visitor, UInt32 idx, SInt32 count) const;		// not found
		DEFINE_MEMBER_FN(PushBack, bool, 0x00920EF0, void *pada, const GFxValue &value);
		bool    PopBack(void* pdata, GFxValue* pval);													// not found
		DEFINE_MEMBER_FN(RemoveElements, bool, 0x00920F40, void* pdata, UInt32 idx, SInt32 count);
		bool    IsDisplayObjectActive(void* pdata) const;												// not found
		DEFINE_MEMBER_FN_const(GetDisplayInfo, bool, 0x00920F90, void *pdata, DisplayInfo *pinfo);
		DEFINE_MEMBER_FN(SetDisplayInfo, bool, 0x009211B0, void *pdata, const DisplayInfo &pinfo);
		//bool    GetDisplayMatrix(void* pdata, GMatrix2D* pmat) const;
		//bool    SetDisplayMatrix(void* pdata, const GMatrix2D& mat);
		bool    GetMatrix3D(void* pdata, GMatrix3D* pmat) const;										// not found
		bool    SetMatrix3D(void* pdata, const GMatrix3D& mat);											// not found
		bool    GetCxform(void* pdata, GRenderer::Cxform* pcx) const;
		bool    SetCxform(void* pdata, const GRenderer::Cxform& cx);

		bool    GetText(void* pdata, GFxValue* pval, bool ishtml) const;								// not found
		bool  SetText(void* pdata, const char* ptext, bool ishtml)				{ return SetTextA(pdata, ptext, ishtml); }
		inline bool	SetText(void* pdata, const wchar_t* ptext, bool ishtml)		{ return SetTextW(pdata, ptext, ishtml); }

		bool    CreateEmptyMovieClip(void* pdata, GFxValue* pmc, const char* instanceName, SInt32 depth);	// not found
		bool    AttachMovie(void* pdata, GFxValue* pmc, const char* symbolName, const char* instanceName, SInt32 depth, const GFxValue* initObj);	// not found

		inline bool	GotoAndPlay(void* pdata, const char* frame, bool stop)		{ return GotoAndPlayA(pdata, frame, stop); }
		inline bool	GotoAndPlay(void* pdata, UInt32 frame, bool stop)			{ return GotoAndPlayI(pdata, frame, stop); }

		inline bool	IsSameContext(ObjectInterface* pobjInterface)				{ return (pMovieRoot == pobjInterface->pMovieRoot); }

		void    ToString(GString* pstr, const GFxValue& thisVal) const;									// not found

	private:
		DEFINE_MEMBER_FN(SetTextA, bool, 0x009233A0, void *pdata, const char *ptext, bool ishtml);
		DEFINE_MEMBER_FN(SetTextW, bool, 0x00000000, void *pdata, const wchar_t *ptext, bool ishtml);
		DEFINE_MEMBER_FN(GotoAndPlayA, bool, 0x00920660, void* pdata, const char* frame, bool stop);
		DEFINE_MEMBER_FN(GotoAndPlayI, bool, 0x009206E0, void* pdata, UInt32 frame, bool stop);

	protected:
		// @members
		GFxMovieRoot*   pMovieRoot;
	};

public:
	enum ValueType
	{
		VT_Undefined		= 0x00,
		VT_Null				= 0x01,
		VT_Boolean			= 0x02,
		VT_Number			= 0x03,
		VT_String			= 0x04,
		VT_StringW			= 0x05,  // wchar_t* string
		VT_Object			= 0x06,
		VT_Array			= 0x07,
		VT_DisplayObject	= 0x08,
		VT_ConvertBoolean	= VTC_ConvertBit | VT_Boolean,
		VT_ConvertNumber	= VTC_ConvertBit | VT_Number,
		VT_ConvertString	= VTC_ConvertBit | VT_String,
		VT_ConvertStringW	= VTC_ConvertBit | VT_StringW
	};

	GFxValue() : pObjectInterface(nullptr), Type(VT_Undefined) { }
	GFxValue(ValueType type) : pObjectInterface(nullptr), Type(type) { Value.pString = 0; }
	GFxValue(double v) : pObjectInterface(nullptr), Type(VT_Number) { Value.NValue = v; }
	GFxValue(bool v) : pObjectInterface(nullptr), Type(VT_Boolean) { Value.BValue = v; }
	GFxValue(const char* ps) : pObjectInterface(nullptr), Type(VT_String) { Value.pString = ps; }
	GFxValue(const wchar_t* ps) : pObjectInterface(nullptr), Type(VT_StringW) { Value.pStringW = ps; }
	GFxValue(const GFxValue& src) : pObjectInterface(nullptr), Type(src.Type)
	{
		Value = src.Value;
		if (src.IsManagedValue()) AcquireManagedValue(src);
	}

	~GFxValue() { if (IsManagedValue()) ReleaseManagedValue();  }

	const GFxValue& operator = (const GFxValue& src)
	{
		if (this != &src)
		{
			if (IsManagedValue()) ReleaseManagedValue();
			Type = src.Type;
			Value = src.Value;
			if (src.IsManagedValue()) AcquireManagedValue(src);
		}
		return *this;
	}

	bool operator == (const GFxValue& other) const
	{
		if (Type != other.Type) return false;
		switch (Type & 0x0F)
		{
		case VT_Boolean:	return Value.BValue == other.Value.BValue;
		case VT_Number:		return Value.NValue == other.Value.NValue;
		case VT_String:		return !strcmp(GetString(), other.GetString());
		case VT_StringW:	return !wcscmp(GetStringW(), other.GetStringW());
		default:			return Value.pData == other.Value.pData;
		}
	}

	GString         ToString() const;
	const wchar_t*  ToStringW(wchar_t* pwstr, UInt32 length) const;

	ValueType	GetType() const { return ValueType(Type & VTC_TypeMask); }

	bool		IsUndefined() const { return GetType() == VT_Undefined; }
	bool		IsNull() const { return GetType() == VT_Null; }
	bool		IsBool() const { return GetType() == VT_Boolean; }
	bool		IsNumber() const { return GetType() == VT_Number; }
	bool		IsString() const { return GetType() == VT_String; }
	bool		IsStringW() const { return GetType() == VT_StringW; }
	bool		IsObject() const {
		return (GetType() == VT_Object) ||
			GetType() == VT_Array ||
			GetType() == VT_DisplayObject;
	}
	bool		IsArray() const { return GetType() == VT_Array; }
	bool		IsDisplayObject() const { return GetType() == VT_DisplayObject; }

	bool		GetBool() const { return Value.BValue; }
	double		GetNumber() const { return Value.NValue; }
	const char*	GetString() const
	{
		return IsManagedValue() ? *Value.pStringManaged : Value.pString;
	}
	const wchar_t* GetStringW() const { return Value.pStringW; }

	void		SetUndefined() { ChangeType(VT_Undefined); }
	void		SetNull() { ChangeType(VT_Null); }
	void		SetBoolean(bool v) { ChangeType(VT_Boolean);   Value.BValue = v; }
	void		SetNumber(double v) { ChangeType(VT_Number);    Value.NValue = v; }
	void		SetString(const char* p) { ChangeType(VT_String);    Value.pString = p; }
	void		SetStringW(const wchar_t* p) { ChangeType(VT_StringW);   Value.pStringW = p; }

	void		SetConvertBoolean() { ChangeType(VT_ConvertBoolean); }
	void		SetConvertNumber() { ChangeType(VT_ConvertNumber); }
	void		SetConvertString() { ChangeType(VT_ConvertString); }
	void		SetConvertStringW() { ChangeType(VT_ConvertStringW); }

public:
	typedef     ObjectInterface::ObjVisitor     ObjectVisitor;
	typedef     ObjectInterface::ArrVisitor     ArrayVisitor;

	bool HasMember(const char* name) const
	{
		return pObjectInterface->HasMember(Value.pData, name, IsDisplayObject());
	}
	bool GetMember(const char* name, GFxValue* pval) const
	{
		return pObjectInterface->GetMember(Value.pData, name, pval, IsDisplayObject());
	}
	bool SetMember(const char* name, const GFxValue& val)
	{
		return pObjectInterface->SetMember(Value.pData, name, val, IsDisplayObject());
	}
	bool Invoke(const char* name, GFxValue* presult, const GFxValue* pargs, UInt32 nargs)
	{
		return pObjectInterface->Invoke(Value.pData, presult, name, pargs, nargs, IsDisplayObject());
	}
	bool Invoke(const char* name, GFxValue* presult = nullptr)
	{
		return Invoke(name, presult, nullptr, 0);
	}
	void VisitMembers(ObjectVisitor* visitor) const
	{
		pObjectInterface->VisitMembers(Value.pData, visitor, IsDisplayObject());
	}
	bool DeleteMember(const char* name)
	{
		return pObjectInterface->DeleteMember(Value.pData, name, IsDisplayObject());
	}
	UInt32 GetArraySize() const
	{
		return pObjectInterface->GetArraySize(Value.pData);
	}
	bool SetArraySize(UInt32 sz)
	{
		return pObjectInterface->SetArraySize(Value.pData, sz);
	}
	bool GetElement(UInt32 idx, GFxValue* pval) const
	{
		return pObjectInterface->GetElement(Value.pData, idx, pval);
	}
	bool SetElement(UInt32 idx, const GFxValue& val)
	{
		return pObjectInterface->SetElement(Value.pData, idx, val);
	}
	void VisitElements(ArrayVisitor* visitor, UInt32 idx, SInt32 count = -1) const
	{
		return pObjectInterface->VisitElements(Value.pData, visitor, idx, count);
	}
	void VisitElements(ArrayVisitor* visitor) const
	{
		VisitElements(visitor, 0);
	}
	bool PushBack(const GFxValue& val)
	{
		return pObjectInterface->PushBack(Value.pData, val);
	}
	bool PopBack(GFxValue* pval = nullptr)
	{
		return pObjectInterface->PopBack(Value.pData, pval);
	}
	bool RemoveElements(UInt32 idx, SInt32 count = -1)
	{
		return pObjectInterface->RemoveElements(Value.pData, idx, count);
	}
	bool RemoveElement(UInt32 idx)
	{
		return RemoveElements(idx, 1);
	}
	bool ClearElements()
	{
		return RemoveElements(0);
	}

	bool IsDisplayObjectActive() const
	{
		return pObjectInterface->IsDisplayObjectActive(Value.pData);
	}
	bool GetDisplayInfo(DisplayInfo* pinfo) const
	{
		return pObjectInterface->GetDisplayInfo(Value.pData, pinfo);
	}
	bool SetDisplayInfo(const DisplayInfo& info)
	{
		return pObjectInterface->SetDisplayInfo(Value.pData, info);
	}
	bool GetMatrix3D(GMatrix3D* pmat) const
	{
		return pObjectInterface->GetMatrix3D(Value.pData, pmat);
	}
	bool SetMatrix3D(const GMatrix3D& mat)
	{
		return pObjectInterface->SetMatrix3D(Value.pData, mat);
	}
	bool	GetColorTransform(GRenderer::Cxform* pcx) const
	{
		return pObjectInterface->GetCxform(Value.pData, pcx);
	}
	bool	SetColorTransform(GRenderer::Cxform& cx)
	{
		return pObjectInterface->SetCxform(Value.pData, cx);
	}

	bool	SetText(const char* ptext)
	{
		return pObjectInterface->SetText(Value.pData, ptext, false);
	}
	bool SetText(const wchar_t* ptext)
	{
		return pObjectInterface->SetText(Value.pData, ptext, false);
	}
	bool	SetTextHTML(const char* phtml)
	{
		return pObjectInterface->SetText(Value.pData, phtml, true);
	}
	bool SetTextHTML(const wchar_t* phtml)
	{
		return pObjectInterface->SetText(Value.pData, phtml, true);
	}
	bool GetText(GFxValue* pval) const
	{
		return pObjectInterface->GetText(Value.pData, pval, false);
	}
	bool GetTextHTML(GFxValue* pval) const
	{
		return pObjectInterface->GetText(Value.pData, pval, true);
	}

	bool CreateEmptyMovieClip(GFxValue* pmc, const char* instanceName, SInt32 depth = -1)
	{
		return pObjectInterface->CreateEmptyMovieClip(Value.pData, pmc, instanceName, depth);
	}
	bool AttachMovie(GFxValue* pmc, const char* symbolName, const char* instanceName, SInt32 depth = -1, const GFxValue* initObj = nullptr)
	{
		return pObjectInterface->AttachMovie(Value.pData, pmc, symbolName, instanceName, depth, initObj);
	}
	bool GotoAndPlay(const char* frame)
	{
		return pObjectInterface->GotoAndPlay(Value.pData, frame, false);
	}
	bool GotoAndStop(const char* frame)
	{
		return pObjectInterface->GotoAndPlay(Value.pData, frame, true);
	}
	bool GotoAndPlay(UInt32 frame)
	{
		return pObjectInterface->GotoAndPlay(Value.pData, frame, false);
	}
	bool GotoAndStop(UInt32 frame)
	{
		return pObjectInterface->GotoAndPlay(Value.pData, frame, true);
	}

protected:
	union ValueUnion
	{
		double			NValue;
		bool			BValue;
		const char*		pString;
		const char**	pStringManaged;
		const wchar_t*	pStringW;
		void*			pData;
	};

	ObjectInterface*	pObjectInterface;	// 00
	ValueType			Type;				// 04
	ValueUnion			Value;				// 08

	bool IsManagedValue() const
	{
		return (Type & VTC_ManagedBit) != 0;
	}
	void ChangeType(ValueType type)
	{
		if (IsManagedValue()) ReleaseManagedValue();
		Type = type;
	}
	void AcquireManagedValue(const GFxValue& src)
	{
		pObjectInterface = src.pObjectInterface;
		pObjectInterface->ObjectAddRef(this, Value.pData);
	}
	void ReleaseManagedValue()
	{
		pObjectInterface->ObjectRelease(this, Value.pData);
		pObjectInterface = nullptr;
	}
};
STATIC_ASSERT(sizeof(GFxValue) == 0x10);


class GFxMovieDef : public GFxResource, public GFxStateBag
{
public:
	enum FileAttrFlags
	{
		FileAttr_UseNetwork = 0x0001,
		FileAttr_HasMetadata = 0x0010
	};

	struct MemoryParams
	{
		GMemoryHeap::HeapDesc   Desc;
		float                   HeapLimitMultiplier;
		UInt32					MaxCollectionRoots;
		UInt32					FramesBetweenCollections;

		MemoryParams(UInt32 memoryArena = 0)
		{
			Desc.Arena = memoryArena;
			HeapLimitMultiplier = 0.25; // 25%
			MaxCollectionRoots = ~0u; // Default value will be used.
			FramesBetweenCollections = ~0u; // Default value will be used.
		}
	};

	class MemoryContext : public GRefCountBase<MemoryContext, GStat_Default_Mem>
	{
	public:
		virtual ~MemoryContext() { }
	protected:
		MemoryContext() { }
	};

	virtual UInt32		GetVersion() const = 0;
	virtual UInt32		GetLoadingFrame() const = 0;
	virtual float		GetWidth() const = 0;
	virtual float		GetHeight() const = 0;
	virtual UInt32		GetFrameCount() const = 0;
	virtual float		GetFrameRate() const = 0;
	//more


	inline GFxMovieView * CreateInstance(bool initFirstFrame = true, std::size_t memoryArena = 0)
	{
		return CreateInstance_Impl(initFirstFrame, memoryArena);
	}

private:
	DEFINE_MEMBER_FN(CreateInstance_Impl, GFxMovieView*, 0x00A60200, bool, std::size_t);
};


// 08
class GFxMovie : public GRefCountBase<GFxMovie, GFxStatMV_Other_Mem>
{
public:
	enum PlayState
	{
		Playing,
		Stopped
	};

	enum SetVarType
	{
		SV_Normal,
		SV_Sticky,
		SV_Permanent
	};

	enum SetArrayType
	{
		SA_Int,
		SA_Double,
		SA_Float,
		SA_String,
		SA_StringW,
		SA_Value
	};

	virtual GFxMovieDef *	GetMovieDef() const = 0;										// 01
	virtual UInt32			GetCurrentFrame() const = 0;									// 02
	virtual bool			HasLooped() const = 0;											// 03
	virtual void			GotoFrame(UInt32 frameNumber) = 0;								// 04
	virtual bool			GotoLabeledFrame(const char* plabel, SInt32 offset = 0) = 0;	// 05
	virtual void			SetPlayState(PlayState s) = 0;									// 06
	virtual PlayState		GetPlayState() const = 0;										// 07
	virtual void			SetVisible(bool visible) = 0;									// 08
	virtual bool			GetVisible() const = 0;											// 09
	virtual bool			IsAvailable(const char* pPathToVar) const = 0;					// 0A
	virtual void			CreateString(GFxValue* pValue, const char* pstring) = 0;		// 0B
	virtual void			CreateStringW(GFxValue* pValue, const wchar_t* pstring) = 0;	// 0C
	virtual void			CreateObject(GFxValue* pValue, const char* className = NULL, const GFxValue* pargs = NULL, UInt32 nargs = 0) = 0;	// 0D
	virtual void			CreateArray(GFxValue* pValue) = 0;								// 0E
	virtual void			CreateFunction(GFxValue* pValue, GFxFunctionHandler* pfc, void* puserData = NULL) = 0;						// 0F
	virtual bool			SetVariable(const char* pPathToVar, const GFxValue& value, SetVarType setType = SV_Sticky) = 0;				// 10
	virtual bool			GetVariable(GFxValue *pVal, const char* pPathToVar) const = 0;												// 11
	virtual bool			SetVariableArray(SetArrayType type, const char* pPathToVar, UInt32 index, const void* pdata, UInt32 count, SetVarType setType = SV_Sticky) = 0;
	virtual bool			SetVariableArraySize(const char* pPathToVar, UInt32 count, SetVarType setType = SV_Sticky) = 0;				// 13
	virtual UInt32			GetVariableArraySize(const char* pPathToVar) = 0;															// 14
	virtual bool			GetVariableArray(SetArrayType type, const char* pPathToVar, UInt32 index, void* pdata, UInt32 count) = 0;	// 15
	virtual bool			Invoke(const char* pmethodName, GFxValue *presult, const GFxValue* pargs, UInt32 numArgs) = 0;				// 16
	virtual bool			Invoke(const char* pmethodName, GFxValue *presult, const char* pargFmt, ...) = 0;							// 17
	virtual bool			InvokeArgs(const char* pmethodName, GFxValue *presult, const char* pargFmt, va_list args) = 0;				// 18

	inline UInt32 GetFrameCount() const { return GetMovieDef()->GetFrameCount(); }
	inline float GetFrameRate() const { return GetMovieDef()->GetFrameRate(); }

	inline bool GFxMovie::SetVariable(const char* pPathToVar, const char* pValue, SetVarType setType = SV_Sticky)
	{
		GFxValue v(pValue);
		return SetVariable(pPathToVar, v, setType);
	}
	inline bool GFxMovie::SetVariable(const char* pPathToVar, const wchar_t* pValue, SetVarType setType = SV_Sticky)
	{
		GFxValue v(pValue);
		return SetVariable(pPathToVar, v, setType);
	}
	inline bool GFxMovie::SetVariableDouble(const char* pPathToVar, double value, SetVarType setType = SV_Sticky)
	{
		GFxValue v(value);
		return SetVariable(pPathToVar, v, setType);
	}
	inline double GFxMovie::GetVariableDouble(const char* pPathToVar) const
	{
		GFxValue v(GFxValue::VT_ConvertNumber);
		GetVariable(&v, pPathToVar);
		if (v.GetType() == GFxValue::VT_Number)
			return v.GetNumber();
		return 0.0;
	}
	inline bool GFxMovie::SetVariableArray(const char* pPathToVar, UInt32 index, const GFxValue* pdata, UInt32 count, SetVarType setType = SV_Sticky)
	{
		return SetVariableArray(SA_Value, pPathToVar, index, pdata, count, setType);
	}
	inline bool GFxMovie::GetVariableArray(const char* pPathToVar, UInt32 index, GFxValue* pdata, UInt32 count)
	{
		return GetVariableArray(SA_Value, pPathToVar, index, pdata, count);
	}

	static float GetRenderPixelScale() { return 20.f; }
};


/*==============================================================================
class GFxExternalInterface +0000 (_vtbl=????????)
0000: class GFxExternalInterface
0000: |   class GFxState
0000: |   |   class GRefCountBase<class GFxState,2>
0000: |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   |   class GRefCountImpl
0000: |   |   |   |   |   class GRefCountImplCore
==============================================================================*/
// 0C
class GFxExternalInterface : public GFxState
{
public:
	GFxExternalInterface() : GFxState(State_ExternalInterface) { }

	virtual ~GFxExternalInterface() {}

	// @add
	virtual void Callback(GFxMovieView *pMovieView, const char* methodName, const GFxValue *args, UInt32 numArgs) = 0;
};


// 0C
class GFxMovieView : public GFxMovie, public GFxStateBag
{
protected:
	friend class GFxCharacter;

public:
	GFxMovieView();
	virtual ~GFxMovieView();


	enum ScaleModeType
	{
		SM_NoScale,
		SM_ShowAll,
		SM_ExactFit,
		SM_NoBorder
	};
	enum AlignType
	{
		Align_Center,
		Align_TopCenter,
		Align_BottomCenter,
		Align_CenterLeft,
		Align_CenterRight,
		Align_TopLeft,
		Align_TopRight,
		Align_BottomLeft,
		Align_BottomRight
	};
	enum HE_ReturnValueType
	{
		HE_NotHandled = 0,
		HE_Handled = 1,
		HE_NoDefaultAction = 2,
		HE_Completed = (HE_Handled | HE_NoDefaultAction)
	};
	enum HitTestType
	{
		HitTest_Bounds = 0,
		HitTest_Shapes = 1,
		HitTest_ButtonEvents = 2,
		HitTest_ShapesNoInvisible = 3
	};

	// @add
	virtual void			SetViewport(const GViewport& viewDesc) = 0;			// 19
	virtual void			GetViewport(GViewport *pviewDesc) const = 0;		// 1A
	virtual void			SetViewScaleMode(ScaleModeType) = 0;				// 1B
	virtual ScaleModeType	GetViewScaleMode() const = 0;						// 1C
	virtual void			SetViewAlignment(AlignType) = 0;					// 1D
	virtual AlignType		GetViewAlignment() const = 0;						// 1E
	virtual GRectF          GetVisibleFrameRect() const = 0;					// 1F
	virtual void			SetPerspective3D(const GMatrix3D &projMatIn) = 0;	// 20
	virtual void			SetView3D(const GMatrix3D &viewMatIn) = 0;			// 21
	virtual GRectF			GetSafeRect() const = 0;							// 22
	virtual void			SetSafeRect(const GRectF& rect) = 0;				// 23
	virtual void			Restart() = 0;										// 24
	virtual float			Advance(float deltaT, UInt32 frameCatchUpCount = 2) = 0;	// 25
	virtual void			Display() = 0;										// 26
	virtual void			DisplayPrePass() = 0;								// 27
	virtual void			SetPause(bool pause) = 0;							// 28
	virtual bool			IsPaused() const = 0;								// 29
	virtual void			SetBackgroundColor(const GColor BgColor) = 0;		// 2A
	virtual void			SetBackgroundAlpha(float alpha) = 0;				// 2B
	virtual float			GetBackgroundAlpha() const = 0;						// 2C
	virtual UInt32			HandleEvent(const GFxEvent &event) = 0;				// 2D
	virtual void			GetMouseState(UInt32 mouseIndex, float* x, float* y, UInt32* buttons) = 0;							// 2E
	virtual void			NotifyMouseState(float x, float y, UInt32 buttons, UInt32 mouseIndex = 0) = 0;						// 2F
	virtual bool			HitTest(float x, float y, HitTestType testCond = HitTest_Shapes, UInt32 controllerIdx = 0) = 0;		// 30
	virtual bool			HitTest3D(GPoint3F *ptout, float x, float y, UInt32 controllerIdx = 0) = 0;							// 31
	virtual void			SetExternalInterfaceRetVal(const GFxValue&) = 0;	// 32
	virtual void *			GetUserData() const = 0;							// 33
	virtual void			SetUserData(void*) = 0;								// 34
	virtual bool			AttachDisplayCallback(const char* pPathToObject, void (*callback)(void* pUser), void* pUser) = 0;	// 35
	virtual bool			IsMovieFocused() const = 0;							// 36
	virtual bool			GetDirtyFlag(bool doReset = true) = 0;				// 37
	virtual void			SetMouseCursorCount(UInt32 n) = 0;					// 38
	virtual UInt32			GetMouseCursorCount() const = 0;					// 39
	virtual void			SetControllerCount(UInt32 n) = 0;					// 3A
	virtual UInt32			GetControllerCount() const = 0;						// 3B
	virtual void			GetStats(GStatBag* pbag, bool reset = true) = 0;	// 3C
	virtual GMemoryHeap *	GetHeap() const = 0;								// 3D
	virtual void			ForceCollectGarbage() = 0;							// 3E

	virtual GPointF			TranslateToScreen(const GPointF& p, GMatrix2D userMatrix) = 0;					// 3F
	virtual GRectF			TranslateToScreen(const GRectF& p, GMatrix2D userMatrix) = 0;					// 40
	virtual bool			TranslateLocalToScreen(const char* pathToCharacter, const GPointF& pt, GPointF* presPt, GMatrix2D userMatrix) = 0;	// 41
	virtual bool			SetControllerFocusGroup(UInt32 controllerIdx, UInt32 focusGroupIndex) = 0;		// 42
	virtual UInt32			GetControllerFocusGroup(UInt32 controllerIdx) const = 0;						// 43
	virtual GFxMovieDef::MemoryContext *	GetMemoryContext() const = 0;		// 44
	virtual void			Release() = 0;										// 45


	//void 		SetViewport(SInt32 bufw, SInt32 bufh, SInt32 left, SInt32 top, SInt32 w, SInt32 h, UInt32 flags = 0)
	//{
	//	GViewport desc(bufw, bufh, left, top, w, h, flags);
	//	SetViewport(desc);
	//}

	//const char *	GetVariable(const char* pPathToVar) const;
	//const wchar_t *	GetVariableStringW(const char* pPathToVar) const;
	//const char *	Invoke(const char* pmethodName, const GFxValue* pargs, UInt32 numArgs);
	//const char *	Invoke(const char* pmethodName, const char* pargFmt, ...);
	//const char *	InvokeArgs(const char* pmethodName, const char* pargFmt, va_list args);
};


/*==============================================================================
class GFxFunctionHandler +0000 (_vtbl=010E4A60)
0000: class GFxFunctionHandler
0000: |   class GRefCountBase<class GFxFunctionHandler,2>
0000: |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
0000: |   |   |   class GRefCountImpl
0000: |   |   |   |   class GRefCountImplCore
==============================================================================*/
class GFxFunctionHandler : public GRefCountBase<GFxFunctionHandler>
{
public:
	struct Params
	{
		GFxValue*			pRetVal;			// 00
		GFxMovieView*		pMovie;				// 04
		GFxValue*			pThis;				// 08
		GFxValue*			pArgsWithThisRef;	// 0C
		GFxValue*			pArgs;				// 10
		UInt32				ArgCount;			// 14
		void*               pUserData;			// 18
	};
	
	virtual ~GFxFunctionHandler() {}

	virtual void	Call(const Params& params) = 0;
};
