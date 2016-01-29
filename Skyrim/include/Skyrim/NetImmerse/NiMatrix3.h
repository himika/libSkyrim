#pragma once

#include "NiPoint3.h"

// 24
class NiMatrix3
{
public:
	NiMatrix3()		{ }
	NiMatrix3(const NiPoint3& col0, const NiPoint3& col1, const NiPoint3& col2) {
		SetCol(0, col0);
		SetCol(1, col1);
		SetCol(2, col2);
	}

	void GetRow(unsigned int row, NiPoint3 &pt) const {
		pt.x = m_entry[row][0];
		pt.y = m_entry[row][1];
		pt.z = m_entry[row][2];
	}
	void GetRow(unsigned int row, float &f0, float &f1, float &f2) const {
		f0 = m_entry[row][0];
		f1 = m_entry[row][1];
		f2 = m_entry[row][2];
	}
	void SetRow(unsigned int row, const NiPoint3 &pt) {
		m_entry[row][0] = pt.x;
		m_entry[row][1] = pt.y;
		m_entry[row][2] = pt.z;
	}
	void SetRow(unsigned int row, float f0, float f1, float f2) {
		m_entry[row][0] = f0;
		m_entry[row][1] = f1;
		m_entry[row][2] = f2;
	}
	void GetCol (unsigned int col, NiPoint3 &pt) const {
		pt.x = m_entry[0][col];
		pt.y = m_entry[1][col];
		pt.z = m_entry[2][col];
	}
	void GetCol(unsigned int col, float &f0, float &f1, float &f2) const {
		f0 = m_entry[0][col];
		f1 = m_entry[1][col];
		f2 = m_entry[2][col];
	}
	void SetCol(unsigned int col, const NiPoint3 &pt) {
		m_entry[0][col] = pt.x;
		m_entry[1][col] = pt.y;
		m_entry[2][col] = pt.z;
	}
	void SetCol(unsigned int col, float f0, float f1, float f2) {
		m_entry[0][col] = f0;
		m_entry[1][col] = f1;
		m_entry[2][col] = f2;
	}


	inline float GetEntry(std::size_t row, std::size_t col) const {
		return m_entry[row][col];
	}
	inline void SetEntry(std::size_t row, std::size_t col, float f) {
		m_entry[row][col] = f;
	}
	inline float & operator()(std::size_t row, std::size_t col) {
		return m_entry[row][col];
	}
	inline const float & operator()(std::size_t row, std::size_t col) const {
		return m_entry[row][col];
	}

	bool NiMatrix3::operator==(const NiMatrix3& mat) const;
	bool NiMatrix3::operator!=(const NiMatrix3& mat) const;

	NiMatrix3 operator+(const NiMatrix3& mat) const;
	NiMatrix3 operator-(const NiMatrix3& mat) const;
	NiMatrix3 operator*(const NiMatrix3& mat) const;
	NiPoint3 operator*(const NiPoint3& pt) const;
	NiMatrix3 operator*(float fScalar) const;

	void MakeZero();
	void MakeIdentity();
	void MakeDiagonal(float fDiag0, float fDiag1, float fDiag2);
	void MakeXRotation(float angle);
	void MakeYRotation(float angle);
	void MakeZRotation(float angle);
	void MakeRotation(float angle, float x, float y, float z);
	void MakeRotation(float angle, const NiPoint3& axis);

	bool ToEulerAnglesXYZ(float& rfXAngle, float& rfYAngle, float& rfZAngle) const;
	bool ToEulerAnglesXZY(float& rfXAngle, float& rfZAngle, float& rfYAngle) const;
	bool ToEulerAnglesYXZ(float& rfYAngle, float& rfXAngle, float& rfZAngle) const;
	bool ToEulerAnglesYZX(float& rfYAngle, float& rfZAngle, float& rfXAngle) const;
	bool ToEulerAnglesZXY(float& rfZAngle, float& rfXAngle, float& rfYAngle) const;
	bool ToEulerAnglesZYX(float& rfZAngle, float& rfYAngle, float& rfXAngle) const;

	static const NiMatrix3 ZERO;
	static const NiMatrix3 IDENTITY;

protected:
	// @members
	float	m_entry[3][3];
};

STATIC_ASSERT(sizeof(NiMatrix3) == 0x24);
