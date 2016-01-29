#pragma once

#include <cmath>

// 8
class NiPoint2
{
public:
	NiPoint2()	{}
	NiPoint2(float X, float Y) : x(X), y(Y)	{}

	float & operator[](std::size_t idx) {
		const float *arr = &x;
		return (float &)arr[idx];
	}
	const float & operator[](std::size_t idx) const {
		const float *arr = &x;
		return (float &)arr[idx];
	}

	bool operator==(const NiPoint2 &rhs) const {
		return (x == rhs.x && y == rhs.y);
	}
	bool operator!=(const NiPoint2 &rhs) const {
		return !operator==(rhs);
	}

	NiPoint2 operator+(const NiPoint2 &rhs) const {
		return NiPoint2(x + rhs.x, y + rhs.y);
	}
	NiPoint2 operator-(const NiPoint2 &rhs) const {
		return NiPoint2(x - rhs.x, y - rhs.y);
	}
	float operator*(const NiPoint2 &rhs) const {
		return x*rhs.x + y*rhs.y;
	}
	NiPoint2 operator*(float scalar) const {
		return NiPoint2(x*scalar, y*scalar);
	}
	NiPoint2 operator/(float scalar) const {
		return NiPoint2(x/scalar, y/scalar);
	}
	NiPoint2 operator-() const {
		return NiPoint2(-x, -y);
	}

	NiPoint2 & operator+=(const NiPoint2 &rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	NiPoint2 & operator-=(const NiPoint2 &rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
	NiPoint2 & operator*=(float scalar) {
		x *= scalar;
		y *= scalar;
		return *this;
	}
	NiPoint2 & operator/=(float scalar) {
		x /= scalar;
		y /= scalar;
		return *this;
	}

	float SqrLength() const {
		return x*x + y*y;
	}
	float Length() const {
		return std::sqrt(x*x + y*y);
	}
	float Unitize() {
		float length = Length();
		if (length > 1e-6f) {
			(*this) /= length;
		}
		else {
			x = 0.0f;
			y = 0.0f;
			length = 0.0f;
		}
		return length;
	}

	// @members
	float	x;	// 0
	float	y;	// 4
};
