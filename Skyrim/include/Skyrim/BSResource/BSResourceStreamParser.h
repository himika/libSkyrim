#pragma once

#include "BSResourceNiBinaryStream.h"

/*==============================================================================
class BSStreamParserData +0000 (_vtbl=0110E144)
0000: class BSStreamParserData
==============================================================================*/
class BSStreamParserData
{
public:
	virtual ~BSStreamParserData();		// 00A60260
	
	virtual void	Unk_01(void) = 0;
	virtual void	Unk_02(void) = 0;
	virtual void	* Unk_03(void) = 0;
};


/*==============================================================================
class BSResourceStreamParser +0000 (_vtbl=0110E16C)
0000: class BSResourceStreamParser
0000: |   class BSResourceNiBinaryStream
0000: |   |   class NiBinaryStream
0020: |   class BSStreamParserData
==============================================================================*/
class BSResourceStreamParser :
	public BSResourceNiBinaryStream,	// 00
	public BSStreamParserData			// 20
{
public:
	virtual ~BSResourceStreamParser();				// 00A61420

	// @override class BSResourceNiBinaryStream : (vtbl=0110E16C)
	// none

	// @override class BSStreamParserData : (vtbl=0110E158)
	virtual void	Unk_01(void) override;					// 00B21740
	virtual void	Unk_02(void) override;					// 00B21750 { return; }
	virtual void *	Unk_03(void) override;					// 00B21760 { return (BSResourceNiBinaryStream*)this; }

};
