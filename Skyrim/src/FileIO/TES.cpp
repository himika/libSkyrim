#include "Skyrim.h"
#include "Skyrim/FileIO/TES.h"
#include "Skyrim/Forms/TESObjectCELL.h"

TES	*& g_TES = *(TES **)0x01B2E864;

ICellAttachDetachEventSource *& BSTSingletonExplicit<ICellAttachDetachEventSource>::m_pSingleton = *(ICellAttachDetachEventSource**)0x012E35C4;


bool TES::IsAttached(TESObjectCELL *cell) const
{
	if (!cell)
		return false;
	if (cell == currentCell)
		return true;
	if (!cell->IsInterior() && gridCellArray && gridCellArray->IsAttached(cell))
		return true;

	return false;
}
