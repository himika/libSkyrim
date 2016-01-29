#pragma once

/*==============================================================================
class BSFaceGenKeyframe +0000 (_vtbl=010BE584)
0000: class BSFaceGenKeyframe
==============================================================================*/
class BSFaceGenKeyframe
{
public:
	virtual ~BSFaceGenKeyframe();		// 005A3470

	virtual void Unk_01(void);			// 00F51EE8 (pure)
	virtual void Unk_02(void);			// 00F51EE8 (pure)
	virtual void Unk_03(void);			// 00F51EE8 (pure)
	virtual void Unk_04(UInt32 unk1);	// 00F51EE8 (pure)
	virtual void Unk_05(void);			// 00F51EE8 (pure)
	virtual void Unk_06(void);			// 00F51EE8 (pure)
	virtual void Unk_07(void);			// 00F51EE8 (pure)
	virtual void Unk_08(void);			// 00F51EE8 (pure)
	virtual void Unk_09(void);			// 00F51EE8 (pure)
	virtual void Unk_0A(void);			// 00F51EE8 (pure)
	virtual void Unk_0B(void);			// 00F51EE8 (pure)
	virtual void Unk_0C(void);			// 0092D110 { return false; }
	virtual void Unk_0D(void);			// 0092D110 { return false; }
};


/*==============================================================================
class BSFaceGenKeyframeMultiple +0000 (_vtbl=010BE5C4)
0000: class BSFaceGenKeyframeMultiple
0000: |   class BSFaceGenKeyframe
==============================================================================*/
class BSFaceGenKeyframeMultiple : public BSFaceGenKeyframe
{
public:
	virtual ~BSFaceGenKeyframeMultiple();		// 005A3D30

	// @override
	virtual void Unk_01(void) override;			// 005A3D60
	virtual void Unk_02(void) override;			// 005A3710
	virtual void Unk_03(void) override;			// 005A3560
	virtual void Unk_04(UInt32 unk1) override;	// 005A3000
	virtual void Unk_05(void) override;			// 005A3CD0
	virtual void Unk_06(void) override;			// 005A3040
	virtual void Unk_07(void) override;			// 005A30F0
	virtual void Unk_08(void) override;			// 005A3180
	virtual void Unk_09(void) override;			// 005A31D0
	virtual void Unk_0A(void) override;			// 005A3260
	virtual void Unk_0B(void) override;			// 005A3210
	virtual void Unk_0C(void) override;			// 009B86F0 { return true; }

	// @add
	virtual void Unk_00E(void);					// 005A33F0
	virtual void Unk_00F(void);					// 005A3910


	// @members
	UInt32	type;		// 04
	UInt32	unk08;		// 08
	float	* values;	// 0C
	UInt32	count;		// 10
	UInt8	isUpdated;	// 14 - Set to 0 for update request
	UInt8	pad15[3];
};
STATIC_ASSERT(sizeof(BSFaceGenKeyframeMultiple) == 0x18);
