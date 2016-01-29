#pragma once

#include "../Scaleform/FxGameDelegate.h"
#include "../BSSystem/BSTSmartPointer.h"
#include "../Events/ScriptEvent.h"
#include "../Misc/InventoryChanges.h"

class EnchantmentItem;
class BGSConstructibleObject;

namespace CraftingSubMenus
{
	/*==============================================================================
	class CraftingSubMenus::CraftingSubMenu +0000 (_vtbl=010E440C)
	0000: class CraftingSubMenus::CraftingSubMenu
	0000: |   class FxDelegateHandler
	0000: |   |   class GRefCountBase<class FxDelegateHandler,2>
	0000: |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
	0000: |   |   |   |   class GRefCountImpl
	0000: |   |   |   |   |   class GRefCountImplCore
	0008: |   class BSTEventSink<struct TESFurnitureEvent>
	==============================================================================*/
	// 10+
	class CraftingSubMenu : public FxDelegateHandler,
		public BSTEventSink<TESFurnitureEvent>			// 08
	{
	public:
		virtual ~CraftingSubMenu();				// 00850B60

		// @override class BSTEventSink<struct TESFurnitureEvent> : (vtbl=010E4400)
		virtual EventResult ReceiveEvent(TESFurnitureEvent *, BSTEventSource<TESFurnitureEvent>*) override;		// 00850940

		// @add
		virtual void	Unk_02(void);			// 006C50E0 { return; }
		virtual void	Unk_03(void);			// 006C50E0 { return; }
		virtual bool	Unk_04(void);			// 009B86F0 { return true; }
		virtual bool	Unk_05(UInt32 arg);		// 004091A0 { return false; }
		virtual void	Unk_06(void);			// 006C50E0 { return; }
		virtual void	Unk_07(UInt32 arg);		// 00588F30 { return; }

		// @members
		GFxMovieView*	view;		// 0C
	};


	/*==============================================================================
	class CraftingSubMenus::EnchantConstructMenu +0000 (_vtbl=010E4460)
	0000: class CraftingSubMenus::EnchantConstructMenu
	0000: |   class CraftingSubMenus::CraftingSubMenu
	0000: |   |   class FxDelegateHandler
	0000: |   |   |   class GRefCountBase<class FxDelegateHandler,2>
	0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
	0000: |   |   |   |   |   class GRefCountImpl
	0000: |   |   |   |   |   |   class GRefCountImplCore
	0008: |   |   class BSTEventSink<struct TESFurnitureEvent>
	==============================================================================*/
	// 158
	class EnchantConstructMenu : public CraftingSubMenu
	{
	public:
		enum
		{
			kFilterFlag_EnchantWeapon = 0x1,
			kFilterFlag_DisenchantWeapon = 0x2,
			kFilterFlag_EnchanteArmor = 0x4,
			kFilterFlag_DisenchantArmor = 0x8,
			kFilterFlag_EffectWeapon = 0x10,
			kFilterFlag_EffectArmor = 0x20,
			kFilterFlag_SoulGem = 0x40
		};

		/*==============================================================================
		class CraftingSubMenus::EnchantConstructMenu::CategoryListEntry +0000 (_vtbl=010E4228)
		0000: class CraftingSubMenus::EnchantConstructMenu::CategoryListEntry
		0004: |   struct BSIntrusiveRefCounted
		==============================================================================*/
		// 10
		class CategoryListEntry : public BSIntrusiveRefCounted
		{
		public:
			virtual ~CategoryListEntry();					// 0084C620

			virtual void Unk_01(UInt32 arg);				// 00588F30 { return; }
			virtual void Unk_02(void);						// 0084E980
			virtual void Unk_03(void) = 0;					// pure
			virtual void SetData(GFxValue* dataContainer);	// 00588F30 { return; }

			DEFINE_MEMBER_FN(SetData, void, 0x0084CF60, GFxValue* target);

			// @members
			//void		** _vtbl;	// 00 - 010E4228
			UInt32		filterFlag;	// 08
			UInt8		bEquipped;	// 0C
			UInt8		bEnabled;	// 0D
			UInt16		pad0E;		// 0E
		};

		/*==============================================================================
		class CraftingSubMenus::EnchantConstructMenu::ItemChangeEntry +0000 (_vtbl=010E4240)
		0000: class CraftingSubMenus::EnchantConstructMenu::ItemChangeEntry
		0000: |   class CraftingSubMenus::EnchantConstructMenu::CategoryListEntry
		0004: |   |   struct BSIntrusiveRefCounted
		==============================================================================*/
		// 014
		class ItemChangeEntry : public CategoryListEntry
		{
		public:
			virtual ~ItemChangeEntry();			// 0084C650

			// @override
			virtual void Unk_01(UInt32 arg);				// 0084DB10
			virtual void Unk_02(void);						// 0084E990
			virtual void Unk_03(void) = 0;					// 0084C5B0
			virtual void SetData(GFxValue* dataContainer);	// 0084D0C0

			// @members
			InventoryEntryData*	data;	// 10
			UInt32				unk14;	// 14
			UInt32				unk18;	// 18
		};

		/*==============================================================================
		class CraftingSubMenus::EnchantConstructMenu::EnchantmentEntry +0000 (_vtbl=010E4258)
		0000: class CraftingSubMenus::EnchantConstructMenu::EnchantmentEntry
		0000: |   class CraftingSubMenus::EnchantConstructMenu::CategoryListEntry
		0004: |   |   struct BSIntrusiveRefCounted
		==============================================================================*/
		// 01C
		class EnchantmentEntry : public CategoryListEntry
		{
		public:
			// @override
			virtual void Unk_01(UInt32 arg);				// 0084DB20
			virtual void Unk_02(void);						// 0084E9C0
			virtual void Unk_03(void) = 0;					// 0084C600
			virtual void SetData(GFxValue* dataContainer);	// 0084D1B0

			// @members
			EnchantmentItem	* data;		// 10
		};

		virtual ~EnchantConstructMenu();								// 00853790

		// @override class CraftingSubMenus::CraftingSubMenu : (vtbl=010E4460)
		virtual void	Accept(CallbackProcessor* cbreg) override;		// 01 00853410
		virtual bool	Unk_04(void) override;							// 04 00851350
		virtual bool	Unk_05(UInt32 arg) override;					// 05 00852600
		virtual void	Unk_07(UInt32 arg) override;					// 07 00851380

		// @override class BSTEventSink<struct TESFurnitureEvent> : (vtbl=010E4454)
		virtual	EventResult	ReceiveEvent(TESFurnitureEvent *evn, BSTEventSource<TESFurnitureEvent> *src) override;	// 00850940


		// ...
	};

	/*==============================================================================
	class CraftingSubMenus::SmithingMenu +0000 (_vtbl=010E4778)
	0000: class CraftingSubMenus::SmithingMenu
	0000: |   class CraftingSubMenus::CraftingSubMenu
	0000: |   |   class FxDelegateHandler
	0000: |   |   |   class GRefCountBase<class FxDelegateHandler,2>
	0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
	0000: |   |   |   |   |   class GRefCountImpl
	0000: |   |   |   |   |   |   class GRefCountImplCore
	0008: |   |   class BSTEventSink<struct TESFurnitureEvent>
	==============================================================================*/
	// 0E8
	class SmithingMenu : public CraftingSubMenu
	{
	public:


		// ...
	};

	/*==============================================================================
	class CraftingSubMenus::ConstructibleObjectMenu +0000 (_vtbl=010E4888)
	0000: class CraftingSubMenus::ConstructibleObjectMenu
	0000: |   class CraftingSubMenus::CraftingSubMenu
	0000: |   |   class FxDelegateHandler
	0000: |   |   |   class GRefCountBase<class FxDelegateHandler,2>
	0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
	0000: |   |   |   |   |   class GRefCountImpl
	0000: |   |   |   |   |   |   class GRefCountImplCore
	0008: |   |   class BSTEventSink<struct TESFurnitureEvent>
	==============================================================================*/
	// 0E0
	class ConstructibleObjectMenu : public CraftingSubMenu
	{
	public:
		// 08
		struct EntryData
		{
			BGSConstructibleObject*	object;			// 00
			UInt32					filterFlag;		// 04
		};

		// ...
	};

	// Declared outside of AlchemyMenu for forward decls
	// 08
	struct AlchemyEffectCategory
	{
		UInt32 formId;
		UInt32 unk1;
	};

	/*==============================================================================
	class CraftingSubMenus::AlchemyMenu +0000 (_vtbl=010E4688)
	0000: class CraftingSubMenus::AlchemyMenu
	0000: |   class CraftingSubMenus::CraftingSubMenu
	0000: |   |   class FxDelegateHandler
	0000: |   |   |   class GRefCountBase<class FxDelegateHandler,2>
	0000: |   |   |   |   class GRefCountBaseStatImpl<class GRefCountImpl,2>
	0000: |   |   |   |   |   class GRefCountImpl
	0000: |   |   |   |   |   |   class GRefCountImplCore
	0008: |   |   class BSTEventSink<struct TESFurnitureEvent>
	==============================================================================*/
	// 100
	class AlchemyMenu : public CraftingSubMenu
	{
	public:
		// 0C
		struct EntryData
		{
			InventoryEntryData*	data;		// 00
			UInt32				filterFlag;	// 04
			UInt8				bEquipped;	// 08
			UInt8				bEnabled;	// 09
			UInt16				pad0E;		// 0A
		};

		// ...
	};







}
