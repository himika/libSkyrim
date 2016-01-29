#pragma once

#include <cmath>

// C
class NiPoint3
{
public:
	NiPoint3()	{}
	NiPoint3(float X, float Y, float Z) : x(X), y(Y), z(Z) {};

	float & operator[](std::size_t idx) {
		const float *arr = &x;
		return (float &)arr[idx];
	}
	const float & operator[](std::size_t idx) const {
		const float *arr = &x;
		return (float &)arr[idx];
	}

	bool operator==(const NiPoint3 &rhs) const {
		return (x == rhs.x && y == rhs.y && z == rhs.z);
	}
	bool operator!=(const NiPoint3 &rhs) const {
		return !operator==(rhs);
	}

	NiPoint3 operator+(const NiPoint3 &rhs) const {
		return NiPoint3(x + rhs.x, y + rhs.y, z + rhs.z);
	}
	NiPoint3 operator-(const NiPoint3 &rhs) const {
		return NiPoint3(x - rhs.x, y - rhs.y, z - rhs.z);
	}
	float operator*(const NiPoint3 &rhs) const {
		return x*rhs.x + y*rhs.y + z*rhs.z;
	}
	NiPoint3 operator*(float scalar) const {
		return NiPoint3(x*scalar, y*scalar, z*scalar);
	}
	NiPoint3 operator/(float scalar) const {
		return (*this) * (1.0f / scalar);
	}
	NiPoint3 operator-() const {
		return NiPoint3(-x, -y, -z);
	}

	NiPoint3 & operator+=(const NiPoint3 &rhs) {
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}
	NiPoint3 & operator-=(const NiPoint3 &rhs) {
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}
	NiPoint3 & operator*=(float scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}
	NiPoint3 & operator/=(float scalar) {
		return (*this) *= (1.0f / scalar);
	}

	float SqrLength() const {
		return x*x + y*y + z*z;
	}
	float Length() const {
		return std::sqrt(x*x + y*y + z*z);
	}
	float Unitize() {
		float length = Length();
		if (length > 1e-6f) {
			(*this) /= length;
		}
		else {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			length = 0.0f;
		}
		return length;
	}
	float QuickLength() const {
		float length = SqrLength();
		unsigned int *pUIRep = (unsigned int*)&length;

		if (*pUIRep == 0) {
			length = 0.0f;
		}
		else {
			short exp = ((*pUIRep) >> 23) - 127;
			*pUIRep &= 0x007fffff;
			if (exp & 1)
				*pUIRep |= 0x00800000;
			exp >>= 1;
			*pUIRep = m_sqrtTable[(*pUIRep) >> 16] | ((exp + 127) << 23);
		}

		return length;
	}
	float QuickUnitize() {
		float length = QuickLength();
		if (length > 1e-6f) {
			(*this) /= length;
		}
		else {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			length = 0.0f;
		}
		return length;
	}

	NiPoint3 Cross(const NiPoint3 &pt) const {
		return NiPoint3(
			y*pt.z - z*pt.y,
			z*pt.x - x*pt.z,
			x*pt.y - y*pt.x
		);
	}
	NiPoint3 UnitCross(const NiPoint3 &pt) const {
		NiPoint3 cross = Cross(pt);
		cross.Unitize();
		return cross;
	}

	static float VectorLength(const NiPoint3 &v) {
		return v.QuickLength();
	}

	static float UnitizeVector(NiPoint3 &v) {
		return v.QuickUnitize();
	}

	// @members
	float	x;	// 0
	float	y;	// 4
	float	z;	// 8

protected:
	static unsigned int m_sqrtTable[256];
};
