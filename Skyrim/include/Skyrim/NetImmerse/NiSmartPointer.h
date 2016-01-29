#pragma once

#define NiSmartPointer(className)					\
	class className;								\
	typedef NiPointer<className> className##Ptr;


template <class Ty>
class NiPointer
{
public:
	typedef Ty			* pointer;
	typedef const Ty	* const_pointer;
	typedef Ty			& reference;
	typedef const Ty	& const_reference;

	// constructor and destractor
	NiPointer(pointer pObject = (pointer)nullptr) {
		m_pObject = pObject;
		if (m_pObject)
			m_pObject->IncRefCount();
	}
	NiPointer(const NiPointer &ptr) {
		m_pObject = ptr.m_pObject;
		if (m_pObject)
			m_pObject->IncRefCount();
	}
	NiPointer(const NiPointer &&ptr) {
		m_pObject = ptr.m_pObject;
		ptr.m_pObject = nullptr;
	}
	~NiPointer() {
		if (m_pObject)
			m_pObject->DecRefCount();
	}

	// type conversions
	operator pointer() const {
		return m_pObject;
	}
	reference operator*() {
		return *m_pObject;
	}
	pointer operator->() {
		return m_pObject;
	}

	// assignment
	NiPointer& operator=(pointer pObject) {
		if (m_pObject)
			m_pObject->DecRefCount();
		m_pObject = pObject;
		if (m_pObject)
			m_pObject->IncRefCount();
		return *this;
	}
	NiPointer& operator=(const NiPointer &rhs) {
		if (m_pObject)
			m_pObject->DecRefCount();
		m_pObject = rhs.pObject;
		if (m_pObject)
			m_pObject->IncRefCount();
		return *this;
	}
	NiPointer& operator=(NiPointer &&rhs) {
		m_pObject = rhs.m_pObject;
		rhs.m_pObject = nullptr;
		return *this;
	}

	// comparisons
	bool operator==(const pointer pObject) const {
		return (m_pObject == pObject);
	}
	bool operator!=(const pointer pObject) const {
		return (m_pObject != pObject);
	}
	bool operator==(const NiPointer &rhs) const {
		return (m_pObject == rhs.pObject);
	}
	bool operator!=(const NiPointer &rhs) const {
		return (m_pObject != rhs.pObject);
	}

protected:
	pointer m_pObject;
};
