#pragma once

template <class Ty>
class CRC32Calculator
{
public:
	inline CRC32Calculator() {}
	inline CRC32Calculator(const Ty &val) {
		operator=(val);
	}

	inline operator UInt32() {
		return m_checksum;
	}

protected:
	template <std::size_t SIZE = sizeof(Ty)>
	inline CRC32Calculator & operator=(const Ty &val) {
		typedef void(*Fn)(UInt32 *, const void *, std::size_t);
		const Fn fn = (Fn)0x00A4A530;

		fn(&m_checksum, &val, SIZE);
		return *this;
	}

	template <>
	inline CRC32Calculator & operator=<4>(const Ty &val) {
		typedef void(*Fn)(UInt32 *, Ty);
		const Fn fn = (Fn)0x00A4A570;

		fn(&m_checksum, val);
		return *this;
	}

	template <>
	inline CRC32Calculator & operator=<8>(const Ty &val) {
		typedef void(*Fn)(UInt32 *, Ty);
		const Fn fn = (Fn)0x00A4A5D0;

		fn(&m_checksum, val);
		return *this;
	}

	UInt32	m_checksum;
};


class CRC32StringCalculator
{
public:
	inline CRC32StringCalculator() {}
	inline CRC32StringCalculator(const char *str) {
		operator=(str);
	}

	inline operator UInt32() {
		return m_checksum;
	}

protected:
	inline CRC32StringCalculator & operator=(const char *str) {
		typedef void(*Fn)(UInt32 *, const char *);
		const Fn fn = (Fn)0x00A50670;

		fn(&m_checksum, str);
		return *this;
	}

	UInt32	m_checksum;
};


class CRC32StringCalculatorCI
{
public:
	inline CRC32StringCalculatorCI() {}
	inline CRC32StringCalculatorCI(const char *str) {
		operator=(str);
	}

	inline operator UInt32() {
		return m_checksum;
	}

protected:
	inline CRC32StringCalculatorCI & operator=(const char *str) {
		typedef void(*Fn)(UInt32 *, const char *);
		const Fn fn = (Fn)0x00A50620;

		fn(&m_checksum, str);
		return *this;
	}

	UInt32	m_checksum;
};


template <class Ty>
inline UInt32 CalcCRC32(const Ty &val) {
	CRC32Calculator<Ty> crc(val);
	return crc;
}

template <class Ty>
inline UInt32 CalcCRC32String(const Ty &val) {
	CRC32StringCalculator<Ty> crc(val);
	return crc;
}

template <class Ty>
inline UInt32 CalcCRC32StringCI(const Ty &val) {
	CRC32StringCalculatorCI<Ty> crc(val);
	return crc;
}
