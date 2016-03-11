#pragma once


template <class Ty>
class BSTPointerAndFlags
{
public:
	BSTPointerAndFlags() {
		m_pointerAndFlags = 0;
	}
	BSTPointerAndFlags(Ty *a_pointer, bool a_flag = false) {
		m_pointerAndFlags = (UInt32)a_pointer;
		if (a_flag)
			m_pointerAndFlags |= 1;
	}
	BSTPointerAndFlags(const BSTPointerAndFlags &rhs) {
		m_pointerAndFlags = rhs.m_pointerAndFlags;
	}

	bool GetFlag(void) const {
		return (m_pointerAndFlags & 1) != 0;
	}
	bool SetFlag(void) {
		m_pointerAndFlags &= ~1U;
		if (a_flag)
			m_pointerAndFlags |= 1;
	}

	operator const Ty *() const {
		return (const Ty *)(m_pointerAndFlags & ~1U);
	}
	operator Ty *() {
		return (Ty *)(m_pointerAndFlags & ~1U);
	}
	const Ty * operator->() const {
		return (const Ty *)*this;
	}
	Ty * operator->() {
		return (Ty *)*this;
	}
	const Ty & operator*() const {
		return *(const Ty *)*this;
	}
	Ty & operator*() {
		return *(Ty *)*this;
	}

	BSTPointerAndFlags & operator=(Ty *pointer) {
		UInt32 flag = m_pointerAndFlags & 1;
		m_pointerAndFlags = (UInt32)pointer | flag;
	}
	bool operator==(Ty *pointer) const {
		return (Ty *)this == pointer;
	}
	bool operator==(const BSTPointerAndFlags &rhs) const {
		return m_pointerAndFlags == rhs.m_pointerAndFlags;
	}
	bool operator!=(const BSTPointerAndFlags &rhs) const {
		return !operator==(rhs);
	}

protected:
	UInt32	m_pointerAndFlags;
};