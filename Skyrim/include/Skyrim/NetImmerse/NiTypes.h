#pragma once

#include "NiSmartPointer.h"

#include "NiPoint2.h"
#include "NiPoint3.h"
#include "NiMatrix3.h"

// 10
template <class Ty>
class NiRect
{
public:
	NiRect(Ty left = Ty(0), Ty right = Ty(0), Ty top = Ty(0), Ty bottom = Ty(0)) {
		m_left = left;
		m_right = right;
		m_top = top;
		m_bottom = bottom;
	}

	Ty GetWidth() const {
		return m_right > m_left ? (m_right - m_left) : (m_left - m_right);
	}
	Ty GetHeight() const {
		return m_top > m_bottom ? (m_top - m_bottom) : (m_bottom - m_top);
	}

	Ty	m_left;		// 00
	Ty	m_right;	// 04
	Ty	m_top;		// 08
	Ty	m_bottom;	// 0C
};


// 1C
class NiFrustum
{
public:
	float	m_fLeft;	// 00
	float	m_fRight;	// 04
	float	m_fTop;		// 08
	float	m_fBottom;	// 0C
	float	m_fNear;	// 10
	float	m_fFar;		// 14
	bool	m_bOrtho;	// 18
};


// 10
class NiQuaternion
{
public:
	// w is first

	float	m_fW;	// 0
	float	m_fX;	// 4
	float	m_fY;	// 8
	float	m_fZ;	// C
};


// 0C
class NiColor
{
public:
	float	r;	// 0
	float	g;	// 4
	float	b;	// 8
};


// 10
class NiColorA
{
public:
	float	r;	// 0
	float	g;	// 4
	float	b;	// 8
	float	a;	// C
};


// 34
class NiTransform
{
public:
	NiMatrix3	rot;	// 00
	NiPoint3	pos;	// 24
	float		scale;	// 30

	NiTransform();

	// Multiply transforms
	NiTransform operator*(const NiTransform &rhs) const;

	// Transform point
	NiPoint3 operator*(const NiPoint3 &pt) const;
};
STATIC_ASSERT(sizeof(NiTransform) == 0x34);


// 10
class NiBound
{
public:
	NiPoint3	pos;
	float		radius;
};
STATIC_ASSERT(sizeof(NiBound) == 0x10);
