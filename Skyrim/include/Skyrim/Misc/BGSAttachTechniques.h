#pragma once

#include "../BSCore/BSFixedString.h"

class NiNode;
class TESRace;

struct BSAttachTechniques
{
	/*==============================================================================
	class BSAttachTechniques::BSAttachTechnique +0000 (_vtbl=0107D138)
	0000: class BSAttachTechniques::BSAttachTechnique
	==============================================================================*/
	// ?
	class BSAttachTechnique
	{
	public:
	    virtual ~BSAttachTechnique();			// 00458F00

	    virtual void	Unk_001(void) = 0;		// 00F51EE8 (pure)
	    virtual bool	Unk_002(UInt32 arg);	// 00B06950 { return true; }
	    virtual void	Unk_003(void);			// 00B06960 { return; }

	};

	/*==============================================================================
	struct BSAttachTechniques::AttachTechniqueInput +0000 (_vtbl=010C8C34)
	0000: struct BSAttachTechniques::AttachTechniqueInput
	==============================================================================*/
	// 10
	class AttachTechniqueInput
	{
	public:
		virtual ~AttachTechniqueInput();	// 006573C0

		virtual void Release(void);			// 00B069C0

		// @members
		// void		** _vtbl;	// 00 - 010C8C34
		NiNode	* unk04;		// 04
		void	* unk08;		// 08
		UInt32	unk0C;			// 0C - 0 or 1
	};
};


/*==============================================================================
class BGSParticleArrayAttach +0000 (_vtbl=0107D174)
0000: class BGSParticleArrayAttach
0000: |   class BSAttachTechniques::BSAttachTechnique
==============================================================================*/
/*==============================================================================
class BGSHavokGeometryAttach +0000 (_vtbl=0107D1A4)
0000: class BGSHavokGeometryAttach
0000: |   class BSAttachTechniques::BSAttachTechnique
==============================================================================*/
/*==============================================================================
class BGSNamedNodeAttach +0000 (_vtbl=0107D1D0)
0000: class BGSNamedNodeAttach
0000: |   class BSAttachTechniques::BSAttachTechnique
==============================================================================*/
/*==============================================================================
class BGSMultiTechniqueAttach +0000 (_vtbl=0107D278)
0000: class BGSMultiTechniqueAttach
0000: |   class BSAttachTechniques::BSAttachTechnique
==============================================================================*/



/*==============================================================================
struct RefAttachTechniqueInput +0000 (_vtbl=010C8C40)
0000: struct RefAttachTechniqueInput
0000: |   struct BSAttachTechniques::AttachTechniqueInput
==============================================================================*/
// 24
class RefAttachTechniqueInput : public BSAttachTechniques::AttachTechniqueInput
{
public:
	virtual ~RefAttachTechniqueInput();		// 006573F0

	// @override
	virtual void Release(void) override;	// 00657C20

	// @members
	// void		** _vtbl;		// 00 - 010C8C40
	UInt32			unk10;
	TESRace			* race;
	UInt32			unk18;
	UInt32			unk1C;
	BSFixedString	unk20;
};
