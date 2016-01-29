#pragma once


template <class T>
class GSize
{
public:
	// *** GSize data members
	T   Width;
	T   Height;

	enum BoundsType { Min, Max };

	// Constructors
	inline GSize() { }
	inline explicit GSize(T val) { SetSize(val); }
	inline GSize(T width, T height) { SetSize(width, height); }
	inline GSize(const GSize<T> &sz) { SetSize(sz.Width, sz.Height); }
	inline GSize(BoundsType bt) { SetSize(bt); }

	// Initialization
	inline void SetSize(T val) { Width = val; Height = val; }
	inline void SetSize(T w, T h) { Width = w;   Height = h; }
	inline void SetSize(const GSize<T> &sz) { SetSize(sz.Width, sz.Height); }
	//inline void SetSize(BoundsType bt);      // this function uses GFC_MAX_T which is not defined
	inline void SetWidth(T w) { Width = w; }
	inline void SetHeight(T h) { Height = h; }
	inline void Clear() { Width = 0; Height = 0; }

	// Swaps the two sizes
	inline void Swap(GSize<T> *psz);
	inline void Transpose() { G_Swap(Width, Height); }

	// Set to a + (b - a) * t
	inline GSize<T>& SetLerp(const GSize<T>& a, const GSize<T>& b, T t);

	// State                                            
	inline bool IsEmpty() const { return (Width <= 1) || (Height <= 1); }
	inline bool IsNull() const { return (Width == 0) && (Height == 0); }
	inline bool IsValid() const { return (Width >= 0) && (Height >= 0); }

	// Center values                        
	inline GSize<T> Center() const { return GSize<T>(HCenter(), VCenter()); }
	inline T HCenter() const { return Width / 2; }
	inline T VCenter() const { return Height / 2; }

	// Area
	inline T Area() const { return Width*Height; }

	// Expand the size
	inline GSize<T>& Expand(T w, T h) { Width += w; Height += h; return *this; }
	inline GSize<T>& Expand(const GSize<T> &sz) { return Expand(sz.Width, sz.Height); }
	inline GSize<T>& Expand(T value) { return Expand(value, value); }

	// Contract the size
	inline GSize<T>& Contract(T value) { Width -= value; Height -= value; return *this; }
	inline GSize<T>& Contract(const GSize<T> &sz) { return Contract(sz.Width, sz.Height); }
	inline GSize<T>& Contract(T w, T h) { Width -= w; Height -= h; return *this; }

	// Mul (scale) the size
	inline GSize<T>& Mul(const GSize<T> &sz) { return Mul(sz.Width, sz.Height); }
	inline GSize<T>& Mul(T value) { Width *= value; Height *= value; return *this; }
	inline GSize<T>& Mul(T w, T h) { Width *= w; Height *= h; return *this; }

	// Divide (scale) the size
	inline GSize<T>& Div(const GSize<T> &sz) { return Div(sz.Width, sz.Height); }
	inline GSize<T>& Div(T value) { Width /= value; Height /= value; return *this; }
	inline GSize<T>& Div(T w, T h) { Width /= w; Height /= h; return *this; }

	// Clamp the size
	inline GSize<T>& Clamp(const GSize<T> &sz) { return Clamp(sz.Width, sz.Height); }
	inline GSize<T>& Clamp(T w, T h) { if (Width>w) Width = w; if (Height>h) Height = h; return *this; }
	inline GSize<T>& ClampWidth(T w) { if (Width>w) Width = w; return *this; }
	inline GSize<T>& ClampHeight(T h) { if (Height>h) Height = h; return *this; }

	// Return new adjusted sizes
	inline GSize<T> ExpandedTo(const GSize<T> &sz) const { return GSize<T>(G_Max(Width, sz.Width), G_Max(Height, sz.Height)); }
	inline GSize<T> ExpandedTo(T w, T h) const { return GSize<T>(G_Max<T>(Width, w), G_Max<T>(Height, h)); }
	inline GSize<T> ExpandedToWidth(T w) const { return GSize<T>(G_Max<T>(Width, w), Height); }
	inline GSize<T> ExpandedToHeight(T h) const { return GSize<T>(Width, G_Max<T>(Height, h)); }

	inline GSize<T> ClampedTo(const GSize<T> &sz) const { return GSize<T>(G_Min(Width, sz.Width), G_Min(Height, sz.Height)); }
	inline GSize<T> ClampedTo(T w, T h) const { return GSize<T>(G_Min<T>(Width, w), G_Min<T>(Height, h)); }
	inline GSize<T> ClampedToWidth(T w) const { return GSize<T>(G_Min<T>(Width, w), Height); }
	inline GSize<T> ClampedToHeight(T h) const { return GSize<T>(Width, G_Min<T>(Height, h)); }

	// Operator overrides
	inline const GSize<T>& operator =  (const GSize<T> &sz) { SetSize(sz); return *this; }
	inline const GSize<T>& operator =  (T value) { SetSize(value, value); return *this; }
	inline const GSize<T>& operator =  (BoundsType bt) { SetSize(bt); return *this; }

	inline const GSize<T>& operator += (const GSize<T> &sz) { return Expand(sz); }
	inline const GSize<T>& operator += (T value) { return Expand(value); }

	inline const GSize<T>& operator -= (const GSize<T> &sz) { return Contract(sz); }
	inline const GSize<T>& operator -= (T value) { return Contract(value); }

	inline const GSize<T>& operator *= (const GSize<T> &sz) { return Mul(sz); }
	inline const GSize<T>& operator *= (T value) { return Mul(value); }

	inline const GSize<T>& operator /= (const GSize<T> &sz) { return Div(sz); }
	inline const GSize<T>& operator /= (T value) { return Div(value); }

	inline const GSize<T>& operator |= (const GSize<T> &sz) { return (*this = ExpandedTo(sz)); }
	inline const GSize<T>& operator &= (const GSize<T> &sz) { return (*this = ClampedTo(sz)); }

	inline bool            operator == (const GSize<T> &sz) const { return (Width == sz.Width) && (Height == sz.Height); }
	inline bool            operator != (const GSize<T> &sz) const { return (Width != sz.Width) || (Height != sz.Height); }

	inline const GSize<T>  operator -  () { return GSize<T>(-Width, -Height); }
	inline const GSize<T>  operator +  (const GSize<T> &sz) { return GSize<T>(Width + sz.Width, Height + sz.Height); }
	inline const GSize<T>  operator +  (T value) { return GSize<T>(Width + value, Height + value); }
	inline const GSize<T>  operator -  (const GSize<T> &sz) { return GSize<T>(Width - sz.Width, Height - sz.Height); }
	inline const GSize<T>  operator -  (T value) { return GSize<T>(Width - value, Height - value); }
	inline const GSize<T>  operator *  (const GSize<T> &sz) { return GSize<T>(Width*sz.Width, Height*sz.Height); }
	inline const GSize<T>  operator *  (SInt32 value) { return GSize<T>(Width*value, Height*value); }
	//inline const GSize<T>    operator *  ( T value, const GSize<T> &sz )                 { return GSize<T>(sz.Width*value, sz.Height*value); }
	inline const GSize<T>  operator /  (const GSize<T> &sz) { return GSize<T>(Width / sz.Width, Height / sz.Height); }
	inline const GSize<T>  operator /  (T value) { return GSize<T>(Width / value, Height / value); }
	inline const GSize<T>  operator |  (const GSize<T> &sz) { return GSize<T>(G_Max(Width, sz.Width), G_Max(Height, sz.Height)); }
	inline const GSize<T>  operator &  (const GSize<T> &sz) { return GSize<T>(G_Min(Width, sz.Width), G_Min(Height, sz.Height)); }
};


template <class T>
class GPoint
{
public:
	// *** GPoint data members
	T   x;
	T   y;

	enum BoundsType { Min, Max };

	inline GPoint() { }
	inline explicit GPoint(T value) { SetPoint(value); }
	inline GPoint(T x2, T y2) { SetPoint(x2, y2); }
	inline GPoint(const GPoint<T> &pt) { SetPoint(pt); }
	//inline GPoint<T>(BoundsType bt)      { SetPoint(bt); }

	// *** Initialization                                                                                               
	inline void SetPoint(T val) { x = y = val; }
	inline void SetPoint(T x2, T y2) { x = x2; y = y2; }
	inline void SetPoint(const GPoint<T> &pt) { SetPoint(pt.x, pt.y); }
	inline void SetPoint(BoundsType bt);
	inline void Clear() { x = y = 0; }
	inline void Swap(GPoint<T> *ppt);

	// Set to a + (b - a) * t
	inline GPoint<T>& SetLerp(const GPoint<T>& a, const GPoint<T>& b, T t);

	// *** State information                                                                                            
	inline bool IsNull() const { return (x == 0 && y == 0); }

	// Offset the position
	inline GPoint<T>& Offset(const GPoint<T> &pt) { return Offset(pt.x, pt.y); }
	inline GPoint<T>& Offset(const GSize<T> &sz) { return Offset(sz.Width, sz.Height); }
	inline GPoint<T>& Offset(T val) { return Offset(val, val); }
	inline GPoint<T>& Offset(T x2, T y2) { x += x2; y += y2; return *this; }

	// Multiply the position
	inline GPoint<T>& Mul(const GPoint<T> &pt) { return Mul(pt.x, pt.y); }
	inline GPoint<T>& Mul(T val) { return Mul(val, val); }
	inline GPoint<T>& Mul(T x2, T y2) { x *= x2; y *= y2; return *this; }

	// Divide the position                                                      
	inline GPoint<T>& Div(const GPoint<T> &pt) { return Div(pt.x, pt.y); }
	inline GPoint<T>& Div(T val) { return Div(val, val); }
	inline GPoint<T>& Div(T x2, T y2) { x /= x2; y /= y2; return *this; }

	// Dot product
	inline T Dot(T x2, T y2) const { return (x*x2 + y*y2); }
	inline T Dot(const GPoint<T> &pt) const { return Dot(pt.x, pt.y); }

	// Angle in radians (between this and the passed point)
	inline T Angle(T x2, T y2) const { return (T)atan2(y2 - y, x2 - x); }
	inline T Angle(const GPoint<T> &pt) const { return Angle(pt.x, pt.y); }

	// Distance squared (between this and the passed point)
	inline T DistanceSquared(T x2, T y2) const { return ((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)); }
	inline T DistanceSquared(const GPoint<T> &pt) const { return DistanceSquared(pt.x, pt.y); }
	inline T DistanceSquared() const { return Dot(*this); }

	// Distance
	inline T Distance(T x2, T y2) const { return T(sqrt(DistanceSquared(x2, y2))); }
	inline T Distance(const GPoint<T> &pt) const { return Distance(pt.x, pt.y); }
	inline T Distance() const { return T(sqrt(DistanceSquared())); }

	// L1 Distance (Manhattan style)
	// - the equation is: fabs(x1-x2) + fabs(y1-y2)
	inline T DistanceL1(T x2, T y2) const { return T(fabs(x - x2) + fabs(y - y2)); }
	inline T DistanceL1(const GPoint<T> &pt) const { return DistanceL1(pt.x, pt.y); }
	// L Infinite Distance 
	// - the equation is: max(fabs(x1-x2),fabs(y1-y2))
	inline T DistanceLn(T x2, T y2) const { return T(G_Max(fabs(x - x2), fabs(y - y2))); }
	inline T DistanceLn(const GPoint<T> &pt) const { return DistanceLn(pt.x, pt.y); }

	// Clamping                                                                     
	inline void Clamp(T _min, T _max) {
		if (x<_min) x = _min; else if (x>_max) x = _max;
		if (y<_min) y = _min; else if (y>_max) y = _max;
	}
	inline void ClampMin(T _min) { if (x<_min) x = _min; if (y<_min) y = _min; }
	inline void ClampMax(T _max) { if (x>_max) x = _max; if (y>_max) y = _max; }

	// Stores the absolute version of the point                         
	inline GPoint<T>& Absolute() { x = (T)fabs(x); y = (T)fabs(y); return *this; }

	// Bitwise comparison; return true if *this is bitwise identical to p.  
	inline bool BitwiseEqual(const GPoint<T>& p) const { return memcmp(this, &p, sizeof(p)) == 0; }

	// *** Operators
	inline const GPoint<T>& operator = (const GPoint<T> &pt) { SetPoint(pt); return *this; }
	inline const GPoint<T>& operator = (T val) { SetPoint(val); return *this; }
	inline const GPoint<T>& operator = (BoundsType bt) { SetPoint(bt); return *this; }

	inline const GPoint<T>   operator - () const { return GPoint<T>(-x, -y); }

	inline const GPoint<T>& operator += (const GPoint<T> &pt) { return Offset(pt); }
	inline const GPoint<T>& operator += (const GSize<T> &sz) { return Offset(sz); }
	inline const GPoint<T>& operator += (T val) { return Offset(val); }

	inline const GPoint<T>& operator -= (const GPoint<T> &pt) { return Offset(-pt.x, -pt.y); }
	inline const GPoint<T>& operator -= (const GSize<T> &sz) { return Offset(-sz.Width, -sz.Height); }
	inline const GPoint<T>& operator -= (T val) { return Offset(-val); }

	inline const GPoint<T>& operator *= (const GPoint<T> &pt) { return Mul(pt); }
	inline const GPoint<T>& operator *= (T val) { return Mul(val); }

	inline const GPoint<T>& operator /= (const GPoint<T> &pt) { return Div(pt); }
	inline const GPoint<T>& operator /= (T val) { return Div(val); }

	inline bool operator == (const GPoint<T> &pt) const { return ((x == pt.x) && (y == pt.y)); }
	inline bool operator != (const GPoint<T> &pt) const { return ((x != pt.x) || (y != pt.y)); }

	inline const GPoint<T>   operator + (const GPoint<T> &pt) { return GPoint<T>(x + pt.x, y + pt.y); }
	inline const GPoint<T>   operator + (const GSize<T> &sz) { return GPoint<T>(x + sz.Width, y + sz.Height); }
	inline const GPoint<T>   operator + (T val) { return GPoint<T>(x + val, y + val); }
	inline const GPoint<T>   operator - (const GPoint<T> &pt) { return GPoint<T>(x - pt.x, y - pt.y); }
	inline const GPoint<T>   operator - (const GSize<T> &sz) { return GPoint<T>(x - sz.Width, y - sz.Height); }
	inline const GPoint<T>   operator - (T val) { return GPoint<T>(x - val, y - val); }
	inline const GPoint<T>   operator * (const GPoint<T> &pt) { return GPoint<T>(x*pt.x, y*pt.y); }
	inline const GPoint<T>   operator * (T val) { return GPoint<T>(x*val, y*val); }
	//inline const GPoint<T>   operator * (T val, const GPoint<T> &pt)               { return GPoint<T>(pt.x*val, pt.y*val); }
	inline const GPoint<T>   operator / (const GPoint<T> &pt) { return GPoint<T>(x / pt.x, y / pt.y); }
	inline const GPoint<T>   operator / (T val) { return GPoint<T>(x / val, y / val); }
};


template <class T>
class GPoint3
{
public:
	T   x;
	T   y;
	T   z;

	inline GPoint3() { }
	inline explicit GPoint3(T value) { SetPoint(value); }
	inline GPoint3(T x2, T y2, T z2) { SetPoint(x2, y2, z2); }
	inline GPoint3(const GPoint3<T> &pt) { SetPoint(pt); }

	// *** Initialization                                                                                               
	inline void SetPoint(T val) { x = y = z = val; }
	inline void SetPoint(T x2, T y2, T z2) { x = x2; y = y2; z = z2; }
	inline void SetPoint(const GPoint3<T> &pt) { SetPoint(pt.x, pt.y, pt.z); }
	inline void Clear() { x = y = z = 0; }

	// Offset the position
	inline GPoint3<T>& Offset(const GPoint3<T> &pt) { return Offset(pt.x, pt.y, pt.z); }
	inline GPoint3<T>& Offset(T val) { return Offset(val, val, val); }
	inline GPoint3<T>& Offset(T x2, T y2, T z2) { x += x2; y += y2; z += z2; return *this; }

	// Multiply the position
	inline GPoint3<T>& Mul(const GPoint3<T> &pt) { return Mul(pt.x, pt.y, pt.z); }
	inline GPoint3<T>& Mul(T val) { return Mul(val, val, val); }
	inline GPoint3<T>& Mul(T x2, T y2, T z2) { x *= x2; y *= y2; z *= z2; return *this; }

	// Divide the position                                                      
	inline GPoint3<T>& Div(const GPoint3<T> &pt) { return Div(pt.x, pt.y, pt.z); }
	inline GPoint3<T>& Div(T val) { return Div(val, val, val); }
	inline GPoint3<T>& Div(T x2, T y2, T z2) { x /= x2; y /= y2; z /= z2; return *this; }

	// Distance squared (between this and the passed point)
	inline T DistanceSquared(T x2, T y2, T z2) const { return ((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y) + (z2 - z)*(z2 - z)); }
	inline T DistanceSquared(const GPoint3<T> &pt) const { return DistanceSquared(pt.x, pt.y, pt.z); }
	inline T DistanceSquared() const { return Dot(*this); }

	// Distance
	inline T Distance(T x2, T y2, T z2) const { return T(sqrt(DistanceSquared(x2, y2, z2))); }
	inline T Distance(const GPoint3<T> &pt) const { return Distance(pt.x, pt.y, pt.z); }
	inline T Distance() const { return T(sqrt(DistanceSquared())); }

	inline T Magnitude() const { return sqrt(x*x + y*y + z*z); }
	inline void Normalize()
	{
		T length = Magnitude();
		x = x / length;
		y = y / length;
		z = z / length;
	}

	// Dot product
	inline T Dot(T x2, T y2, T z2) const { return (x*x2 + y*y2 + z*z2); }
	inline T Dot(const GPoint3<T> &pt) const { return Dot(pt.x, pt.y, pt.z); }

	// cross product
	inline void Cross(const GPoint3<T> &a, const GPoint3<T> &b)
	{
		x = a.y*b.z - a.z*b.y;
		y = a.z*b.x - a.x*b.z;
		z = a.x*b.y - a.y*b.x;
	}
	inline const GPoint3<T>& operator = (const GPoint3<T> &pt) { SetPoint(pt); return *this; }
	inline const GPoint3<T>& operator = (T val) { SetPoint(val); return *this; }

	inline const GPoint3<T>   operator - () const { return GPoint3<T>(-x, -y, -z); }

	inline const GPoint3<T>& operator += (const GPoint3<T> &pt) { return Offset(pt); }
	inline const GPoint3<T>& operator += (T val) { return Offset(val); }

	inline const GPoint3<T>& operator -= (const GPoint3<T> &pt) { return Offset(-pt.x, -pt.y, -pt.z); }
	inline const GPoint3<T>& operator -= (T val) { return Offset(-val); }

	inline const GPoint3<T>& operator *= (const GPoint3<T> &pt) { return Mul(pt); }
	inline const GPoint3<T>& operator *= (T val) { return Mul(val); }

	inline const GPoint3<T>& operator /= (const GPoint3<T> &pt) { return Div(pt); }
	inline const GPoint3<T>& operator /= (T val) { return Div(val); }

	inline bool operator == (const GPoint3<T> &pt) const { return ((x == pt.x) && (y == pt.y) && (z == pt.z)); }
	inline bool operator != (const GPoint3<T> &pt) const { return ((x != pt.x) || (y != pt.y) || (z != pt.z)); }

	inline const GPoint3<T>   operator + (const GPoint3<T> &pt) const { return GPoint3<T>(x + pt.x, y + pt.y, z + pt.z); }
	inline const GPoint3<T>   operator + (T val) const { return GPoint3<T>(x + val, y + val, z + val); }
	inline const GPoint3<T>   operator - (const GPoint3<T> &pt) const { return GPoint3<T>(x - pt.x, y - pt.y, z - pt.z); }
	inline const GPoint3<T>   operator - (T val) const { return GPoint3<T>(x - val, y - val, z - val); }
	inline const GPoint3<T>   operator * (const GPoint3<T> &pt) const { return GPoint3<T>(x*pt.x, y*pt.y, z*pt.z); }
	inline const GPoint3<T>   operator * (T val) const { return GPoint3<T>(x*val, y*val, z*val); }
	//inline const GPoint3<T>   operator * (T val, const GPoint3<T> &pt)               { return GPoint3<T>(pt.x*val, pt.y*val); }
	inline const GPoint3<T>   operator / (const GPoint3<T> &pt) const { return GPoint3<T>(x / pt.x, y / pt.y, z / pt.z); }
	inline const GPoint3<T>   operator / (T val) const { return GPoint3<T>(x / val, y / val, z / val); }
};



template <class T>
class GRect
{
public:
	// *** GRect data members
	T   Left;
	T   Top;
	T   Right;
	T   Bottom;

	enum BoundsType { Min, Max };

	// Constructors
	inline GRect() { SetRect(0, 0, 0, 0); }
	inline explicit GRect(T val) { SetRect(val, val); }
	inline GRect(const GRect<T> &rc) { SetRect(rc); }
	inline GRect(const GSize<T> &sz) { SetRect(sz); }
	inline GRect(T w, T h) { SetRect(w, h); }
	inline GRect(const GPoint<T> &tl, const GPoint<T> &br) { SetRect(tl, br); }
	inline GRect(const GPoint<T> &tl, const GSize<T> &sz) { SetRect(tl, sz); }
	inline GRect(T x, T y, const GSize<T> &sz) { SetRect(x, y, sz); }
	inline GRect(T left, T top, T right, T bottom) { SetRect(left, top, right, bottom); }
	inline GRect(BoundsType bt) { SetRect(bt); }

	// *** Utility functions

	// Initialization
	inline void SetRect(T l, T t, T r, T b) { Left = l; Top = t; Right = r; Bottom = b; }
	inline void SetRect(const GSize<T> &sz) { SetRect(0, 0, sz.Width, sz.Height); }
	inline void SetRect(T w, T h) { SetRect(0, 0, w, h); }
	inline void SetRect(const GRect<T> &rc) { SetRect(rc.Left, rc.Top, rc.Right, rc.Bottom); }
	inline void SetRect(const GPoint<T> &tl, const GPoint<T> &br) { SetRect(tl.x, tl.y, br.x, br.y); }
	inline void SetRect(T x, T y, const GSize<T> &sz) { SetRect(x, y, x + sz.Width, y + sz.Height); }
	inline void SetRect(const GPoint<T> &tl, const GSize<T> &sz) { SetRect(tl.x, tl.y, sz); }
	inline void SetRect(BoundsType bt);

	// Set to a + (b - a) * t
	inline GRect<T>& SetLerp(const GRect<T>& a, const GRect<T>& b, T t);

	inline void Clear() { SetRect(GPoint<T>(0, 0), GSize<T>(0, 0)); }

	inline void Swap(GRect<T> *pr);


	// *** Different rect data conversion
	// Point/Size rect (values are stored as a point and a size)
	inline GRect<T>&   FromRectPS(const GRect<T> *prc) { SetRect(prc->Left, prc->Top, GSize<T>(prc->Right, prc->Bottom)); return *this; }
	inline void        ToRectPS(GRect<T> *prc) const { prc->SetRect(Left, Top, Width(), Height()); }


	//  *** State functions
	// - these functions are for Normal rectangles only
	inline bool IsNull() const { return (Right == Left) && (Bottom == Top); }
	inline bool IsEmpty() const { return (Left >= Right) || (Top >= Bottom); }
	inline bool IsNormal() const { return (Right >= Left) && (Bottom >= Top); }

	// Point properties
	inline T X1() const { return Left; }
	inline T Y1() const { return Top; }
	inline T X2() const { return Right; }
	inline T Y2() const { return Bottom; }

	// *** Corner position
	inline GPoint<T> TopLeft() const { return GPoint<T>(Left, Top); }
	inline GPoint<T> TopRight() const { return GPoint<T>(Right, Top); }
	inline GPoint<T> BottomLeft() const { return GPoint<T>(Left, Bottom); }
	inline GPoint<T> BottomRight() const { return GPoint<T>(Right, Bottom); }

	inline void SetTopLeft(const GPoint<T> &pt) { Left = pt.x; Top = pt.y; }
	inline void SetTopRight(const GPoint<T> &pt) { Right = pt.x; Top = pt.y; }
	inline void SetBottomLeft(const GPoint<T> &pt) { Left = pt.x; Bottom = pt.y; }
	inline void SetBottomRight(const GPoint<T> &pt) { Right = pt.x; Bottom = pt.y; }

	// *** Side access
	// Returns a new rectangle that 
	inline GRect<T> TopSide(T height = 0.0) const { return GRect<T>(Left, Top, Right, (Top + height)); }
	inline GRect<T> BottomSide(T height = 0.0) const { return GRect<T>(Left, (Bottom - height), Right, Bottom); }
	inline GRect<T> LeftSide(T width = 0.0) const { return GRect<T>(Left, Top, (Left + width), Bottom); }
	inline GRect<T> RightSide(T width = 0.0) const { return GRect<T>((Right - width), Top, Right, Bottom); }

	// *** Center
	inline GPoint<T> Center() const { return GPoint<T>(HCenter(), VCenter()); }
	inline T HCenter() const { return (Right + Left) / 2; }
	inline T VCenter() const { return (Bottom + Top) / 2; }

	inline void SetCenter(const GPoint<T> &nc);
	inline void SetCenter(T x, T y) { SetCenter(GPoint<T>(x, y)); }
	inline void SetHCenter(T x);
	inline void SetVCenter(T y);


	// *** Size functions                                                                                                                       
	inline T Width() const { return Right - Left; }
	inline T Height() const { return Bottom - Top; }
	// Checked functions return 0 size for non-normal coordinate        
	inline T CheckedWidth() const { return (Right >= Left) ? Width() : 0; }
	inline T CheckedHeight() const { return (Bottom >= Top) ? Height() : 0; }

	inline GSize<T> Size() const { return GSize<T>(Width(), Height()); }
	inline GSize<T> CheckedSize() const { return GSize<T>(CheckedWidth(), CheckedHeight()); }

	inline void SetSize(T width, T height) { SetWidth(width); SetHeight(height); }
	inline void SetSize(const GSize<T> &sz) { SetSize(sz.Width, sz.Height); }

	inline void SetWidth(T width) { Right = (Left + width); }
	inline void SetHeight(T height) { Bottom = (Top + height); }

	// *** Area                                                                                                                                 
	inline T Area() const { return Width()*Height(); }

	// *** Ranges                                                                                                               
	inline void SetHRange(T l, T r) { Left = l; Right = r; }
	inline void SetVRange(T t, T b) { Left = t; Right = b; }

	// *** Sizing/Movement
	// Offset the rect
	inline GRect<T>& Offset(T x, T y) { Left += x; Right += x; Top += y; Bottom += y; return *this; }
	inline GRect<T>& Offset(const GPoint<T> &pt) { return Offset(pt.x, pt.y); }
	inline GRect<T>& OffsetX(T x) { Left += x; Right += x; return *this; }
	inline GRect<T>& OffsetY(T y) { Top += y; Bottom += y; return *this; }

	// Expand (inflate) rect
	inline GRect<T>& Expand(T l, T t, T r, T b) { Left -= l; Right += r; Top -= t; Bottom += b; return *this; }
	inline GRect<T>& Expand(T val) { return Expand(val, val, val, val); }
	// Applies the value to both sides (h = Left-h & Right+h)                   
	inline GRect<T>& Expand(T h, T v) { return Expand(h, v, h, v); }
	inline GRect<T>& HExpand(T h) { Left -= h; Right += h; return *this; }
	inline GRect<T>& HExpand(T l, T r) { Left -= l; Right += r; return *this; }
	inline GRect<T>& VExpand(T v) { Top -= v; Bottom += v; return *this; }
	inline GRect<T>& VExpand(T t, T b) { Top -= t; Bottom += b; return *this; }

	// Expand this rectangle to enclose the given point.
	inline GRect<T>& ExpandToPoint(const GPoint<T> &pt) { return ExpandToPoint(pt.x, pt.y); }
	inline GRect<T>& ExpandToPoint(T x, T y);

	// Contract (deflate) rect          
	inline GRect<T>& Contract(T l, T t, T r, T b) { Left += l; Right -= r; Top += t; Bottom -= b; return *this; }
	inline GRect<T>& Contract(T val) { return Contract(val, val, val, val); }
	// Applies the value to both sides (w = Left+w & Right-w)       
	inline GRect<T>& Contract(T h, T v) { return Contract(h, v, h, v); }
	inline GRect<T>& HContract(T h) { Left += h; Right -= h; return *this; }
	inline GRect<T>& HContract(T l, T r) { Left += l; Right -= r; return *this; }
	inline GRect<T>& VContract(T v) { Top += v; Bottom -= v; return *this; }
	inline GRect<T>& VContract(T t, T b) { Top += t; Bottom -= b; return *this; }

	// Clamp rect
	inline GRect<T>& Clamp(const GRect<T> &r) { return Clamp(r.Left, r.Top, r.Right, r.Bottom); }
	inline GRect<T>& Clamp(T l, T t, T r, T b);
	inline GRect<T>& HClamp(T l, T r);
	inline GRect<T>& HClamp(const GRect<T> &r) { return HClamp(r.Left, r.Right); }
	inline GRect<T>& VClamp(T t, T b);
	inline GRect<T>& VClamp(const GRect<T> &r) { return VClamp(r.Top, r.Bottom); }

	// Rectangle becomes the sum of this and r
	inline GRect<T>& Union(T l, T t, T r, T b);
	inline GRect<T>& Union(const GRect<T> &r) { return Union(r.Left, r.Top, r.Right, r.Bottom); }

	// Stores the area inside both rectangles
	// - clears the rectangle if they don’t intersect
	inline GRect<T>& Intersect(T l, T t, T r, T b);
	inline GRect<T>& Intersect(const GRect<T> &r) { return Intersect(r.Left, r.Top, r.Right, r.Bottom); }

	// Normalize the rectangle
	inline void Normalize();
	inline void NormalizeX();
	inline void NormalizeY();
	// Returns a normalized copy 
	inline GRect<T> Normal() const;

	// *** Area Testing
	// Returns 1 if the passed geometry is completely inside the rectangle
	inline bool Contains(T x, T y) const { return ((x <= Right) && (x >= Left) && (y <= Bottom) && (y >= Top)); }
	inline bool Contains(const GPoint<T> &pt) const { return ((pt.x <= Right) && (pt.x >= Left) && (pt.y <= Bottom) && (pt.y >= Top)); }
	inline bool Contains(const GRect<T> &r) const { return ((Right >= r.Right) && (Bottom >= r.Bottom) && (Left <= r.Left) && (Top <= r.Top)); }

	// Returns 1 if rectangles overlap at all
	// - r maybe completely inside
	inline bool Intersects(const GRect<T> &r) const;

	// Returns 1 if the rectangle touches one of the edges
	// - can optionally adjust the edge width
	inline bool IntersectsEdge(const GRect<T> &r, T ewidth = 1) const;
	// Handles separate widths for each sides edge
	inline bool IntersectsEdge(const GRect<T> &r, T leftw, T topw, T rightw, T bottomw) const;

	// *** General calculations
	// - store new rectangle inside pdest

	// Clamps a point to the rectangle
	// - returns a new value that is inside the rect
	inline GPoint<T> ClampPoint(const GPoint<T> &pt) const;

	// Calculates area inside both rectangles
	// Returns 0 if rectangles don’t intersect
	inline bool IntersectRect(GRect<T> *pdest, const GRect<T> &r) const;
	// Calculates the area enclosing both rectangles
	inline void UnionRect(GRect<T> *pdest, const GRect<T> &r) const;

	// *** Operator overrides
	inline const GRect<T>& operator =  (const GRect<T> &r) { SetRect(r); return *this; }
	inline const GRect<T>& operator =  (BoundsType bt) { SetRect(bt); return *this; }

	inline const GRect<T>& operator += (const GPoint<T> &pt) { return Offset(pt); }
	inline const GRect<T>& operator += (T val) { return Offset(val, val); }

	inline GRect<T>& operator -= (const GPoint<T> &pt) { return Offset(-pt); }
	inline GRect<T>& operator -= (T val) { return Offset(-val, -val); }

	inline const GRect<T>& operator |= (const GRect<T> &r);
	inline const GRect<T>& operator &= (const GRect<T> &r);

	inline bool operator == (const GRect<T> &r) const { return ((Left == r.Left) && (Right == r.Right) && (Top == r.Top) && (Bottom == r.Bottom)); }
	inline bool operator != (const GRect<T> &r) const { return ((Left != r.Left) || (Right != r.Right) || (Top != r.Top) || (Bottom != r.Bottom)); }

	inline const GRect<T>    operator -  () { return GRect<T>(-Left, -Top, -Right, -Bottom); }
	inline const GRect<T>    operator +  (const GPoint<T> &pt) { return GRect<T>(*this).Offset(pt); }
	inline const GRect<T>    operator +  (T val) { return GRect<T>(Left + val, Top + val, Right + val, Bottom + val); }
	inline const GRect<T>    operator -  (const GPoint<T> &pt) { return GRect<T>(*this).Offset(-pt); }
	inline const GRect<T>    operator -  (T val) { return GRect<T>(Left - val, Top - val, Right - val, Bottom - val); }
	inline const GRect<T>    operator +  (const GRect<T> &r) { GRect<T> dest; UnionRect(&dest, r); return dest; }
	inline const GRect<T>    operator |  (const GRect<T> &r) { GRect<T> dest; UnionRect(&dest, r); return dest; }
	inline const GRect<T>    operator &  (const GRect<T> &r) { GRect<T> dest; IntersectRect(&dest, r); return dest; }
};

typedef GPoint<float> GPointF;
typedef GPoint3<float> GPoint3F;
typedef GRect<float> GRectF;


class GColor
{
public:
	struct Rgb24
	{
		UInt8   Blue;
		UInt8   Green;
		UInt8   Red;
	};

	struct Rgb32
	{
		UInt8   Blue;
		UInt8   Green;
		UInt8   Red;
		UInt8   Alpha;
	};

	union
	{
		Rgb32   Channels;
		UInt32  Raw;
	};

	GColor()													{ }
	GColor(const GColor &c)										{ SetColor(c); }
	GColor(const GColor &c, UInt8 a8)							{ SetColor(c, a8); }
	GColor(const GColor &c, GColor ac)							{ SetColor(c, ac); }
	GColor(UInt32 raw32)										{ SetColor(raw32); }
	GColor(UInt32 raw32, UInt8 a8)								{ SetColor(raw32, a8); }
	GColor(UInt8 red, UInt8 green, UInt8 blue, UInt8 a8 = 0)	{ SetColor(red, green, blue, a8); }

	void	SetColor(const GColor &c)							{ Raw = c.Raw; }
	void	SetColor(const GColor &c, UInt8 a8)					{ SetColor(c.Raw, a8); }
	void	SetColor(const GColor &c, GColor ac)				{ SetColor(c.Raw, ac.GetAlpha()); }
	void	SetColor(UInt32 raw)								{ Raw = raw; }
	void	SetColor(UInt32 raw, UInt8 a8)						{ Raw = raw; SetAlpha(a8); }
	void	SetColor(UInt8 r, UInt8 g, UInt8 b, UInt8 a = 0)	{ SetRGBA(r, g, b, a); }

	void	GColor::SetRGB(UInt8 r, UInt8 g, UInt8 b)
	{
		SetRed(r);
		SetGreen(g);
		SetBlue(b);
	}
	void	GColor::GetRGB(UInt8 *pr, UInt8 *pg, UInt8 *pb) const
	{
		*pr = GetRed();
		*pg = GetGreen();
		*pb = GetBlue();
	}
	void	GColor::SetRGBA(UInt8 r, UInt8 g, UInt8 b, UInt8 a)
	{
		SetRGB(r, g, b);
		SetAlpha(a);
	}
	void	GColor::GetRGBA(UInt8 *pr, UInt8 *pg, UInt8 *pb, UInt8 *pa) const
	{
		GetRGB(pr, pg, pb);
		*pa = GetAlpha();
	}

	UInt8	GetAlpha() const	{ return Channels.Alpha; }
	UInt8	GetRed() const		{ return Channels.Red; }
	UInt8	GetGreen() const	{ return Channels.Green; }
	UInt8	GetBlue() const		{ return Channels.Blue; }
	void	SetAlpha(UInt8 a)	{ Channels.Alpha = a; }
	void	SetRed(UInt8 r)		{ Channels.Red = r; }
	void	SetGreen(UInt8 g)	{ Channels.Green = g; }
	void	SetBlue(UInt8 b)	{ Channels.Blue = b; }

};


class GMatrix2D
{
public:
	float   M_[2][3];
};

class GMatrix3D
{
public:
	float   M_[4][4];
};

template <typename T> inline const T G_Min(const T a, const T b)						{ return (a < b) ? a : b; }
template <typename T> inline const T G_Max(const T a, const T b)						{ return (b < a) ? a : b; }
template <typename T> inline const T G_Clamp(const T v, const T minVal, const T maxVal)	{ return G_Max<T>(minVal, G_Min<T>(v, maxVal)); }
template <typename T> inline int G_IRound(const T a)									{ return (a > 0.0) ? (int)(a + 0.5) : (int)(a - 0.5); }
template <typename T> inline unsigned G_URound(const T a)								{ return (unsigned)(a + 0.5); }


