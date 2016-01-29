#pragma once

class NiRTTI;
class NiNode;
class NiSwitchNode;
class NiGeometry;
class NiTriBasedGeom;
class NiTriStrips;
class NiTriShape;
class BSSegmentedTriShape;
class NiParticles;
class NiLines;

/*==============================================================================
class NiCullingProcess +0000 (_vtbl=011195E4)
0000: class NiCullingProcess
==============================================================================*/
// 110 ?
class NiCullingProcess
{
public:
	enum { kRTTI = 0x01B92798 };

	virtual NiRTTI *		GetRTTI(void) const;							// 00 00ACE3A0 { return 0x01B92798; }
	virtual NiNode			* GetAsNiNode(void);							// 01 005EADD0 { return 0; } 01 - 10 unused
	virtual NiSwitchNode	* GetAsNiSwitchNode(void);						// 02 005EADD0 { return 0; }
	virtual void *			Unk_05(void);									// 03 005EADD0 { return 0; }
	virtual void *			Unk_06(void);									// 04 005EADD0 { return 0; }
	virtual NiGeometry		* GetAsNiGeometry(void);						// 05 005EADD0 { return 0; }
	virtual NiTriBasedGeom	* GetAsNiTriBasedGeom(void);					// 06 005EADD0 { return 0; }
	virtual NiTriStrips		* GetAsNiTriStrips(void);						// 07 005EADD0 { return 0; }
	virtual NiTriShape		* GetAsNiTriShape(void);						// 08 005EADD0 { return 0; }
	virtual BSSegmentedTriShape * GetAsBSSegmentedTriShape(void);			// 09 005EADD0 { return 0; }
	virtual void *			Unk_0A(void);									// 0A 005EADD0 { return 0; }
	virtual NiParticles *	GetAsNiParticles(void);							// 0B 005EADD0 { return 0; }
	virtual NiLines *		GetAsNiLines(void);								// 0C 005EADD0 { return 0; }
	virtual void *			Unk_0D(void);									// 0D 005EADD0 { return 0; }
	virtual void *			Unk_0E(void);									// 0E 005EADD0 { return 0; }
	virtual void *			Unk_0F(void);									// 0F 005EADD0 { return 0; }
	virtual void *			Unk_10(void);									// 10 005EADD0 { return 0; }

	virtual ~NiCullingProcess();											// 11 00ACE3B0
	virtual void			Unk_12(UInt32 arg);								// 12 00ACE1D0
	virtual void			Unk_13(UInt32 arg1, UInt32 arg2, UInt32 arg3);	// 13 00ACE2B0
	virtual void			Unk_14(UInt32 arg);								// 14 005AAE70 { DebugBreak(); }

	//"NiCullingProcess::Append> Geometry failed RegisterObject, not rendering: %s

	// @members
	UInt8	unk04;									// 04 Perhaps refcount?
	UInt8	pad05[3];
	UInt32	visibleArray; 							// 08 NiVisibleArray *
	UInt32	camera;   								// 0C NiCamera *
	UInt32	fustrum[(0x30 - 0x10) >> 2];			// 10 NiFustrum
	UInt32	fustrumPlanes[(0x90 - 0x30) >> 2];		// 2C NiFrustumPlanes
	UInt32	activePlanes;							// 90
	UInt32	unk94;									// 94
	UInt32	unk98;									// 98
	UInt32	fustrumPlanes2[(0x100 - 0x9C) >> 2];	// 9C NiFrustumPlanes
	UInt32	activePlanes2;							// 100
	UInt32	unk104;									// 104
	UInt32	unk108;									// 108
	UInt32	unk10C;									// 10C
};
STATIC_ASSERT(sizeof(NiCullingProcess) == 0x110);


/*==============================================================================
class BSCullingProcess +0000 (_vtbl=0111EA6C)
0000: class BSCullingProcess
0000: |   class NiCullingProcess
==============================================================================*/
// 170
class BSCullingProcess : public NiCullingProcess
{
public:
	// @override
	virtual NiRTTI *	GetRTTI(void) const override;		// 00 00B083A0 { return 0x01B9C52C; }

	virtual ~BSCullingProcess();													// 11 00ACE3B0
	virtual void		Unk_12(UInt32 arg) override;								// 12 00B07C80
	virtual void		Unk_13(UInt32 arg1, UInt32 arg2, UInt32 arg3) override;		// 13 00B07E70
	virtual void		Unk_14(UInt32 arg) override;								// 14 00B07B50

	// @add
	virtual void	Unk_15(UInt32 arg);		// 15 00B07AD0 { return; }
	virtual void	Unk_16(UInt32 arg);		// 16 00B07C10 { return p = arg1->unk0C; p->Unk_25(&this->unk2C); }
	virtual void	Unk_17(void);			// 17 00B07BF0
	virtual void	Unk_18(void);			// 18 00B07B90

	UInt32	unk110[(0x170 - 0x110) >> 2];
};
STATIC_ASSERT(sizeof(BSCullingProcess) == 0x170);
