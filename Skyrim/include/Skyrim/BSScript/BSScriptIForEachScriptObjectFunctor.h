namespace BSScript
{
	/*==============================================================================
	class BSScript::IForEachScriptObjectFunctor +0000 (_vtbl=0108E93C)
	0000: class BSScript::IForEachScriptObjectFunctor
	==============================================================================*/
	// 04
	class IForEachScriptObjectFunctor
	{
	public:
		IForEachScriptObjectFunctor() {};
		virtual ~IForEachScriptObjectFunctor() {};

		// return true to continue
		virtual bool Visit(class BSScriptObject * object, bool bConditional) = 0;

		//	void	** _vtbl;	// 00 - 0108E93C
	};
}
