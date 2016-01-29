#pragma once

/*==============================================================================
class NiBinaryStream +0000 (_vtbl=01120DA0)
0000: class NiBinaryStream
==============================================================================*/
// 10
class NiBinaryStream
{
public:
	NiBinaryStream() : m_currentPos(0), m_readFn(nullptr), m_writeFn(nullptr) {}
	virtual ~NiBinaryStream() { };						// 00B2A630

	virtual operator bool() const = 0;
	virtual void	Seek(SInt32 delta) = 0;
	virtual UInt32	GetPosition(void) const;			// 00B2A390
	virtual void	CopyFrom(void * other);				// 00B2A350
	virtual void	SetEndianSwap(bool swap) = 0;

	inline bool IsValid() const {
		return *this;
	}

protected:
	typedef unsigned int(*NiBinaryStrema_ReadFn)(NiBinaryStream* pThis, void * buf, std::size_t bytes, std::size_t *componentSizes, std::size_t numComponents);
	typedef unsigned int(*NiBinaryStrema_WriteFn)(NiBinaryStream* pThis, const void * buf, std::size_t bytes, std::size_t *componentSizes, std::size_t numComponents);

	DEFINE_MEMBER_FN(CopyFrom_Impl, void, 0x00B2A350, void*);

	// @members
	//void					** _vtbl;		// 00 - 01120DA0
	UInt32					m_currentPos;	// 04
	NiBinaryStrema_ReadFn	m_readFn;		// 08
	NiBinaryStrema_WriteFn	m_writeFn;		// 0C
};
