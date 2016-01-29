#include "Skyrim.h"
#include "Skyrim/FileIO/TES.h"

TES	*& g_TES = *(TES **)0x01B2E864;

ICellAttachDetachEventSource *& BSTSingletonExplicit<ICellAttachDetachEventSource>::m_pSingleton = *(ICellAttachDetachEventSource**)0x012E35C4;
