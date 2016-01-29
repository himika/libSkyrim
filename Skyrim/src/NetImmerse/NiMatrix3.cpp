#include "Skyrim/NetImmerse/NiMatrix3.h"


const NiMatrix3 NiMatrix3::ZERO(
	NiPoint3(0.0f, 0.0f, 0.0f),
	NiPoint3(0.0f, 0.0f, 0.0f),
	NiPoint3(0.0f, 0.0f, 0.0f));

const NiMatrix3 NiMatrix3::IDENTITY(
	NiPoint3(1.0f, 0.0f, 0.0f),
	NiPoint3(0.0f, 1.0f, 0.0f),
	NiPoint3(0.0f, 0.0f, 1.0f));


static inline void sincos(float radians, float& sin, float& cos)
{
	float s, c;

	__asm fld radians
	__asm fsincos
	__asm fstp c
	__asm fstp s

	sin = s;
	cos = c;
}


void NiMatrix3::MakeIdentity()
{
	SetCol(0, 1.0f, 0.0f, 0.0f);
	SetCol(1, 0.0f, 1.0f, 0.0f);
	SetCol(2, 0.0f, 0.0f, 1.0f);
}


void NiMatrix3::MakeDiagonal(float dia0, float dia1, float dia2)
{
	SetCol(0, dia0, 0.0f, 0.0f);
	SetCol(1, 0.0f, dia1, 0.0f);
	SetCol(2, 0.0f, 0.0f, dia2);
}


void NiMatrix3::MakeZero()
{
	SetCol(0, 0.0f, 0.0f, 0.0f);
	SetCol(1, 0.0f, 0.0f, 0.0f);
	SetCol(2, 0.0f, 0.0f, 0.0f);
}


bool NiMatrix3::operator== (const NiMatrix3& mat) const
{
	return
		(m_entry[0][0] == mat.m_entry[0][0]) &&
		(m_entry[0][1] == mat.m_entry[0][1]) &&
		(m_entry[0][2] == mat.m_entry[0][2]) &&
		(m_entry[1][0] == mat.m_entry[1][0]) &&
		(m_entry[1][1] == mat.m_entry[1][1]) &&
		(m_entry[1][2] == mat.m_entry[1][2]) &&
		(m_entry[2][0] == mat.m_entry[2][0]) &&
		(m_entry[2][1] == mat.m_entry[2][1]) &&
		(m_entry[2][2] == mat.m_entry[2][2]);
}


bool NiMatrix3::operator!= (const NiMatrix3& mat) const
{
	return !operator==(mat);
}


NiMatrix3 NiMatrix3::operator+(const NiMatrix3& mat) const
{
	NiMatrix3 tmp = *this;
	tmp.m_entry[0][0] += mat.m_entry[0][0];
	tmp.m_entry[0][1] += mat.m_entry[0][1];
	tmp.m_entry[0][2] += mat.m_entry[0][2];
	tmp.m_entry[1][0] += mat.m_entry[1][0];
	tmp.m_entry[1][1] += mat.m_entry[1][1];
	tmp.m_entry[1][2] += mat.m_entry[1][2];
	tmp.m_entry[2][0] += mat.m_entry[2][0];
	tmp.m_entry[2][1] += mat.m_entry[2][1];
	tmp.m_entry[2][2] += mat.m_entry[2][2];
	return tmp;
}


NiMatrix3 NiMatrix3::operator-(const NiMatrix3& mat) const
{
	NiMatrix3 tmp = *this;
	tmp.m_entry[0][0] -= mat.m_entry[0][0];
	tmp.m_entry[0][1] -= mat.m_entry[0][1];
	tmp.m_entry[0][2] -= mat.m_entry[0][2];
	tmp.m_entry[1][0] -= mat.m_entry[1][0];
	tmp.m_entry[1][1] -= mat.m_entry[1][1];
	tmp.m_entry[1][2] -= mat.m_entry[1][2];
	tmp.m_entry[2][0] -= mat.m_entry[2][0];
	tmp.m_entry[2][1] -= mat.m_entry[2][1];
	tmp.m_entry[2][2] -= mat.m_entry[2][2];
	return tmp;
}


NiMatrix3 NiMatrix3::operator*(const NiMatrix3& rhs) const
{
	NiMatrix3 tmp;
	tmp.m_entry[0][0] =
		m_entry[0][0]*rhs.m_entry[0][0]+
		m_entry[0][1]*rhs.m_entry[1][0]+
		m_entry[0][2]*rhs.m_entry[2][0];

	tmp.m_entry[1][0] =
		m_entry[1][0]*rhs.m_entry[0][0]+
		m_entry[1][1]*rhs.m_entry[1][0]+
		m_entry[1][2]*rhs.m_entry[2][0];

	tmp.m_entry[2][0] =
		m_entry[2][0]*rhs.m_entry[0][0]+
		m_entry[2][1]*rhs.m_entry[1][0]+
		m_entry[2][2]*rhs.m_entry[2][0];

	tmp.m_entry[0][1] =
		m_entry[0][0]*rhs.m_entry[0][1]+
		m_entry[0][1]*rhs.m_entry[1][1]+
		m_entry[0][2]*rhs.m_entry[2][1];

	tmp.m_entry[1][1] =
		m_entry[1][0]*rhs.m_entry[0][1]+
		m_entry[1][1]*rhs.m_entry[1][1]+
		m_entry[1][2]*rhs.m_entry[2][1];

	tmp.m_entry[2][1] =
		m_entry[2][0]*rhs.m_entry[0][1]+
		m_entry[2][1]*rhs.m_entry[1][1]+
		m_entry[2][2]*rhs.m_entry[2][1];

	tmp.m_entry[0][2] =
		m_entry[0][0]*rhs.m_entry[0][2]+
		m_entry[0][1]*rhs.m_entry[1][2]+
		m_entry[0][2]*rhs.m_entry[2][2];

	tmp.m_entry[1][2] =
		m_entry[1][0]*rhs.m_entry[0][2]+
		m_entry[1][1]*rhs.m_entry[1][2]+
		m_entry[1][2]*rhs.m_entry[2][2];

	tmp.m_entry[2][2] =
		m_entry[2][0]*rhs.m_entry[0][2]+
		m_entry[2][1]*rhs.m_entry[1][2]+
		m_entry[2][2]*rhs.m_entry[2][2];

	return tmp;
}


NiMatrix3 NiMatrix3::operator*(float scalar) const
{
	NiMatrix3 result;
	result.m_entry[0][0] = m_entry[0][0] * scalar;
	result.m_entry[0][1] = m_entry[0][1] * scalar;
	result.m_entry[0][2] = m_entry[0][2] * scalar;
	result.m_entry[1][0] = m_entry[1][0] * scalar;
	result.m_entry[1][1] = m_entry[1][1] * scalar;
	result.m_entry[1][2] = m_entry[1][2] * scalar;
	result.m_entry[2][0] = m_entry[2][0] * scalar;
	result.m_entry[2][1] = m_entry[2][1] * scalar;
	result.m_entry[2][2] = m_entry[2][2] * scalar;
	return result;
}


NiPoint3 NiMatrix3::operator*(const NiPoint3 &pt) const
{
	return NiPoint3(
		m_entry[0][0]*pt.x + m_entry[0][1]*pt.y + m_entry[0][2]*pt.z,
		m_entry[1][0]*pt.x + m_entry[1][1]*pt.y + m_entry[1][2]*pt.z,
		m_entry[2][0]*pt.x + m_entry[2][1]*pt.y + m_entry[2][2]*pt.z
	);
}


void NiMatrix3::MakeRotation(float angle, float x, float y, float z)
{
	float sin, cos;
	sincos(angle, sin, cos);

	float omcs = 1.0f - cos;
	float x2 = x*x;
	float y2 = y*y;
	float z2 = z*z;
	float xym = x*y*omcs;
	float xzm = x*z*omcs;
	float yzm = y*z*omcs;
	float xsin = x*sin;
	float ysin = y*sin;
	float zsin = z*sin;

	m_entry[0][0] = x2*omcs + cos;
	m_entry[0][1] = xym + zsin;
	m_entry[0][2] = xzm - ysin;

	m_entry[1][0] = xym - zsin;
	m_entry[1][1] = y2*omcs + cos;
	m_entry[1][2] = yzm + xsin;

	m_entry[2][0] = xzm + ysin;
	m_entry[2][1] = yzm - xsin;
	m_entry[2][2] = z2*omcs + cos;
}


void NiMatrix3::MakeXRotation(float angle)
{
	float sin, cos;
	sincos(angle, sin, cos);

	m_entry[0][0] = 1.0f;
	m_entry[0][1] = 0.0f;
	m_entry[0][2] = 0.0f;

	m_entry[1][0] = 0.0f;
	m_entry[1][1] = cos;
	m_entry[1][2] = sin;

	m_entry[2][0] = 0.0f;
	m_entry[2][1] = -sin;
	m_entry[2][2] = cos;
}


void NiMatrix3::MakeYRotation(float angle)
{
	float sin, cos;
	sincos(angle, sin, cos);

	m_entry[0][0] = cos;
	m_entry[0][1] = 0.0f;
	m_entry[0][2] = -sin;

	m_entry[1][0] = 0.0f;
	m_entry[1][1] = 1.0f;
	m_entry[1][2] = 0.0f;

	m_entry[2][0] = sin;
	m_entry[2][1] = 0.0f;
	m_entry[2][2] = cos;
}


void NiMatrix3::MakeZRotation(float angle)
{
	float sin, cos;
	sincos(angle, sin, cos);

	m_entry[0][0] = cos;
	m_entry[0][1] = sin;
	m_entry[0][2] = 0.0f;

	m_entry[1][0] = -sin;
	m_entry[1][1] = cos;
	m_entry[1][2] = 0.0f;

	m_entry[2][0] = 0.0f;
	m_entry[2][1] = 0.0f;
	m_entry[2][2] = 1.0f;
}


void NiMatrix3::MakeRotation(float angle, const NiPoint3& axis)
{
	MakeRotation(angle, axis.x, axis.y, axis.z);
}


//---------------------------------------------------------------------------
// ÉIÉCÉâÅ[äp
//---------------------------------------------------------------------------

const float NI_PI = 3.1415926535897932f;
const float NI_HALF_PI = 0.5f * NI_PI;
const float NI_TWO_PI = 2.0f * NI_PI;


inline float NiASin(float value)
{
	if (-1.0f < value)
	{
		if (value < 1.0f)
			return float(std::asin(value));
		else
			return NI_HALF_PI;
	}
	else
	{
		return -NI_HALF_PI;
	}
}


static float NiFastATan2(float y, float x)
{
	if (x == 0.0f && y == 0.0f)
		return 0.0f;

	float offset = 0.0f;
	float z;

	if (std::fabs(y) > std::fabs(x))
	{
		z = x / y;
		if (z > 0.0f)
			offset = NI_HALF_PI;
		else if (z < 0.0f)
			offset = -NI_HALF_PI;
		else
			return (y > 0.0f) ? NI_HALF_PI : -NI_HALF_PI;
	}
	else
	{
		z = y / x;

		if (z == 0.0f)
			return (x > 0.0f) ? 0.0f : NI_PI;
	}

	float z2 = z * z;

	float result;
	result = 0.0208351f;
	result *= z2;
	result -= 0.0851330f;
	result *= z2;
	result += 0.1801410f;
	result *= z2;
	result -= 0.3302995f;
	result *= z2;
	result += 0.9998660f;
	result *= z;

	if (offset)
		result = offset - result;

	if (y < 0.0f && x < 0.0f)
		result -= NI_PI;
	if (y > 0.0f && x < 0.0f)
		result += NI_PI;

	return result;
}



bool NiMatrix3::ToEulerAnglesXYZ(float& rfXAngle, float& rfYAngle, float& rfZAngle) const
{
	rfYAngle = -NiASin(m_entry[0][2]);
	if (rfYAngle < NI_HALF_PI)
	{
		if (rfYAngle > -NI_HALF_PI)
		{
			rfXAngle = -NiFastATan2(-m_entry[1][2], m_entry[2][2]);
			rfZAngle = -NiFastATan2(-m_entry[0][1], m_entry[0][0]);
			return true;
		}
		else
		{
			float fRmY = NiFastATan2(m_entry[1][0], m_entry[1][1]);
			rfZAngle = 0.0f;
			rfXAngle = fRmY - rfZAngle;
			return false;
		}
	}
	else
	{
		float fRpY = NiFastATan2(m_entry[1][0], m_entry[1][1]);
		rfZAngle = 0.0f;
		rfXAngle = rfZAngle - fRpY;
		return false;
	}
}


bool NiMatrix3::ToEulerAnglesXZY(float& rfXAngle, float& rfZAngle,
	float& rfYAngle) const
{
	rfZAngle = NiASin(m_entry[0][1]);
	if (rfZAngle < NI_HALF_PI)
	{
		if (rfZAngle > -NI_HALF_PI)
		{
			rfXAngle = -NiFastATan2(m_entry[2][1], m_entry[1][1]);
			rfYAngle = -NiFastATan2(m_entry[0][2], m_entry[0][0]);
			return true;
		}
		else
		{
			float fRmY = NiFastATan2(-m_entry[2][0], m_entry[2][2]);
			rfYAngle = 0.0f;
			rfXAngle = fRmY - rfYAngle;
			return false;
		}
	}
	else
	{
		float fRpY = NiFastATan2(-m_entry[2][0], m_entry[2][2]);
		rfYAngle = 0.0f;
		rfXAngle = rfYAngle - fRpY;
		return false;
	}
}


bool NiMatrix3::ToEulerAnglesYXZ(float& rfYAngle, float& rfXAngle,
	float& rfZAngle) const
{
	rfXAngle = NiASin(m_entry[1][2]);
	if (rfXAngle < NI_HALF_PI)
	{
		if (rfXAngle > -NI_HALF_PI)
		{
			rfYAngle = -NiFastATan2(m_entry[0][2], m_entry[2][2]);
			rfZAngle = -NiFastATan2(m_entry[1][0], m_entry[1][1]);
			return true;
		}
		else
		{
			float fRmY = NiFastATan2(-m_entry[0][1], m_entry[0][0]);
			rfZAngle = 0.0f;
			rfYAngle = fRmY - rfZAngle;
			return false;
		}
	}
	else
	{
		float fRpY = NiFastATan2(-m_entry[0][1], m_entry[0][0]);
		rfZAngle = 0.0f;
		rfYAngle = rfZAngle - fRpY;
		return false;
	}
}


bool NiMatrix3::ToEulerAnglesYZX(float& rfYAngle, float& rfZAngle,
	float& rfXAngle) const
{
	rfZAngle = -NiASin(m_entry[1][0]);
	if (rfZAngle < NI_HALF_PI)
	{
		if (rfZAngle > -NI_HALF_PI)
		{
			rfYAngle = -NiFastATan2(-m_entry[2][0], m_entry[0][0]);
			rfXAngle = -NiFastATan2(-m_entry[1][2], m_entry[1][1]);
			return true;
		}
		else
		{
			float fRmY = NiFastATan2(m_entry[2][1], m_entry[2][2]);
			rfXAngle = 0.0f;
			rfYAngle = fRmY - rfXAngle;
			return false;
		}
	}
	else
	{
		float fRpY = NiFastATan2(m_entry[2][1], m_entry[2][2]);
		rfXAngle = 0.0f;
		rfYAngle = rfXAngle - fRpY;
		return false;
	}
}


bool NiMatrix3::ToEulerAnglesZXY(float& rfZAngle, float& rfXAngle,
	float& rfYAngle) const
{
	rfXAngle = -NiASin(m_entry[2][1]);
	if (rfXAngle < NI_HALF_PI)
	{
		if (rfXAngle > -NI_HALF_PI)
		{
			rfZAngle = -NiFastATan2(-m_entry[0][1], m_entry[1][1]);
			rfYAngle = -NiFastATan2(-m_entry[2][0], m_entry[2][2]);
			return true;
		}
		else
		{
			float fRmY = NiFastATan2(m_entry[0][2], m_entry[0][0]);
			rfYAngle = 0.0f;
			rfZAngle = fRmY - rfYAngle;
			return false;
		}
	}
	else
	{
		float fRpY = NiFastATan2(m_entry[0][2], m_entry[0][0]);
		rfYAngle = 0.0f;
		rfZAngle = rfYAngle - fRpY;
		return false;
	}
}


bool NiMatrix3::ToEulerAnglesZYX(float& rfZAngle, float& rfYAngle,
	float& rfXAngle) const
{
	rfYAngle = NiASin(m_entry[2][0]);
	if (rfYAngle < NI_HALF_PI)
	{
		if (rfYAngle > -NI_HALF_PI)
		{
			rfZAngle = -NiFastATan2(m_entry[1][0], m_entry[0][0]);
			rfXAngle = -NiFastATan2(m_entry[2][1], m_entry[2][2]);
			return true;
		}
		else
		{
			float fRmY = NiFastATan2(-m_entry[0][1], m_entry[0][2]);
			rfXAngle = 0.0f;
			rfZAngle = fRmY - rfXAngle;
			return false;
		}
	}
	else
	{
		float fRpY = NiFastATan2(-m_entry[0][1], m_entry[0][2]);
		rfXAngle = 0.0f;
		rfZAngle = rfXAngle - fRpY;
		return false;
	}
}
