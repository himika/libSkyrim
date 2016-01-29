#pragma once

#include "../Memory.h"
#include "../Forms/TESForm.h"

/*==============================================================================
class IFormFactory +0000 (_vtbl=01076B14)
0000: class IFormFactory
==============================================================================*/
// 4
class IFormFactory
{
public:
	IFormFactory();
	virtual ~IFormFactory();								// 00401870

	virtual TESForm *		Create(void) = 0;
	virtual const char *	GetName(void) = 0;
	virtual UInt32			GetTypeID(void) = 0;
	virtual const char *	GetObjectName(void);			// 005EADD0 { return nullptr; }
	virtual UInt32			GetNum1(void);					// 00401860 { return 0x00000067; }
	virtual UInt32			GetNum2(void);					// 00904A50 { return 0x00000009; }

	inline static IFormFactory * GetFactoryForType(FormType type);	// 0043BDD0

	// @members
	//void		** _vtbl;	// 00 - 01076B14
};


/*==============================================================================
class ConcreteFormFactory<class AlchemyItem,46> +0000 (_vtbl=01076DE4)
0000: class ConcreteFormFactory<class AlchemyItem,46>
0000: |   class IFormFactory
==============================================================================*/
template <class T, UInt32 TyID = T::kTypeID>
class ConcreteFormFactory : public IFormFactory
{
public:
	virtual ~ConcreteFormFactory();						// 00401E60

	
	// @override
	virtual TESForm *		Create(void) override		// 00401E30
	{
		T *pT = FormHeap_Allocate<T>();
		if (pT)
			new (p) T;
		return pT;
	}

	virtual const char *	GetName(void) override		// 004F8CA0 (void) { return name; }
	{
		return name;
	}

	virtual UInt32			GetTypeID(void)				// 0056C050 (void) { return 0x0000002E; }
	{
		return TyID;
	}

	inline static IFormFactory * GetFactory()
	{
		return GetFactoryForType((FormType)T::kTypeID);
	}

	// @members
	//void			** _vtbl;	// 00 - 01076DE4
	const char		* name;		// 04
};


/*==============================================================================
class ConcreteObjectFormFactory<class AlchemyItem,46,17,2> +0000 (_vtbl=01076E04)
0000: class ConcreteObjectFormFactory<class AlchemyItem,46,17,2>
0000: |   class ConcreteFormFactory<class AlchemyItem,46>
0000: |   |   class IFormFactory
==============================================================================*/
template <class T, UInt32 TyID, UInt32 NUM1, UInt32 NUM2>
class ConcreteObjectFormFactory : public ConcreteFormFactory<T, TyID>
{
public:
	// @override
	virtual const char *	GetObjectName(void) override	// 004F8CA0 (void) { return (UInt32)unk4; }
	{
		return name;
	}

	virtual UInt32			GetNum1(void) override			// 00902E00 (void) { return 0x00000011; }
	{
		return NUM1;
	}

	virtual UInt32			GetNum2(void) override			// 005C8DE0 (void) { return 0x00000002; }
	{
		return NUM2
	}

	// @members
	//void	** _vtbl;		// 00 - 01076E04
};
