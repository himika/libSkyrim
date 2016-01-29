#include "Skyrim.h"
#include "Skyrim/Sky/Sky.h"
#include "Skyrim/FileIO/TES.h"

void Sky::ReleaseOverride()
{
	if (unk38)
	{
		unk18C |= 0x00200000;
		unk38 = 0;
	}
}
