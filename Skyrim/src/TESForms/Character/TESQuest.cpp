#include "Skyrim.h"
#include "Skyrim/TESForms/Character/TESQuest.h"
#include "Skyrim/TESForms/Character/BGSBaseAlias.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

BSSpinLock & TESQuest::ms_lock = *(BSSpinLock*)0x012E5BE8;

bool TESQuest::IsActive(void) const {
	//return ((data.flags & Data07C::kQuestFlag_Active) != 0);
	return data.flags.active;
}


/*
009152F0  /.  8B4424 0C         MOV EAX,DWORD PTR SS:[ARG.3]
009152F4  |.  0FB780 80000000   MOVZX EAX,WORD PTR DS:[EAX+80]
009152FB  |.  D1E8              SHR EAX,1
009152FD  |.  83E0 01           AND EAX,00000001
00915300  \.  C3                RETN
*/
bool TESQuest::IsCompleted() const
{
	//return (data.flags & Data07C::kQuestFlag_Completed) != 0;
	return data.flags.completed;
}

/*
00915930  /.  8B4424 0C         MOV EAX,DWORD PTR SS:[ARG.3]
00915934  |.  F680 80000000 01  TEST BYTE PTR DS:[EAX+80],01
0091593B  |.  74 1D             JZ SHORT 0091595A
0091593D  |.  8A88 80000000     MOV CL,BYTE PTR DS:[EAX+80]
00915943  |.  C0E9 07           SHR CL,7
00915946  |.  F6C1 01           TEST CL,01
00915949  |.  75 0F             JNZ SHORT 0091595A
0091594B  |.  83B8 48010000 00  CMP DWORD PTR DS:[EAX+148],0
00915952  |.  75 06             JNE SHORT 0091595A
00915954  |.  B8 01000000       MOV EAX,1
00915959  |.  C3                RETN
0091595A  |>  33C0              XOR EAX,EAX
0091595C  \.  C3                RETN
*/
bool TESQuest::IsRunning() const
{
	//return ((data.flags & Data07C::kQuestFlag_Running) != 0 && (data.flags & Data07C::kQuestFlag_Stopping) == 0 && unk148 == 0);
	return data.flags.running && !data.flags.stopping && unk148 == 0;
}


/*
00915960  /.  8B4424 0C         MOV EAX,DWORD PTR SS:[ARG.3]
00915964  |.  F680 80000000 01  TEST BYTE PTR DS:[EAX+80],01
0091596B  |.  74 1D             JZ SHORT 0091598A
0091596D  |.  8A88 80000000     MOV CL,BYTE PTR DS:[EAX+80]
00915973  |.  C0E9 07           SHR CL,7
00915976  |.  F6C1 01           TEST CL,01
00915979  |.  75 09             JNZ SHORT 00915984
0091597B  |.  83B8 48010000 00  CMP DWORD PTR DS:[EAX+148],0
00915982  |.  74 06             JE SHORT 0091598A
00915984  |>  B8 01000000       MOV EAX,1
00915989  |.  C3                RETN
0091598A  |>  33C0              XOR EAX,EAX
0091598C  \.  C3                RETN
*/
bool TESQuest::IsStarting() const
{
	//return ((data.flags & Data07C::kQuestFlag_Running) != 0 && (data.flags & Data07C::kQuestFlag_Stopping) == 0 && unk148 != 0);
	return data.flags.running && !data.flags.stopping && unk148 != 0;
}


/*
00915990  /.  8B4424 0C         MOV EAX,DWORD PTR SS:[ARG.3]
00915994  |.  F680 80000000 01  TEST BYTE PTR DS:[EAX+80],01
0091599B  |.  75 13             JNZ SHORT 009159B0
0091599D  |.  8A80 80000000     MOV AL,BYTE PTR DS:[EAX+80]
009159A3  |.  C0E8 07           SHR AL,7
009159A6  |.  A8 01             TEST AL,01
009159A8  |.  74 06             JZ SHORT 009159B0
009159AA  |.  B8 01000000       MOV EAX,1
009159AF  |.  C3                RETN
009159B0  |>  33C0              XOR EAX,EAX
009159B2  \.  C3                RETN
*/
bool TESQuest::IsStopping() const
{
	//return ((data.flags & Data07C::kQuestFlag_Running) == 0 && (data.flags & Data07C::kQuestFlag_Stopping) != 0);
	return !data.flags.running && data.flags.stopping;
}

/*
CPU Disasm
Address   Hex dump              Command                                  Comments
009159C0  /.  8B4424 0C         MOV EAX,DWORD PTR SS:[ARG.3]
009159C4  |.  F680 80000000 01  TEST BYTE PTR DS:[EAX+80],01
009159CB  |.  75 13             JNZ SHORT 009159E0
009159CD  |.  8A80 80000000     MOV AL,BYTE PTR DS:[EAX+80]
009159D3  |.  C0E8 07           SHR AL,7
009159D6  |.  A8 01             TEST AL,01
009159D8  |.  75 06             JNZ SHORT 009159E0
009159DA  |.  B8 01000000       MOV EAX,1
009159DF  |.  C3                RETN
009159E0  |>  33C0              XOR EAX,EAX
009159E2  \.  C3                RETN
*/
bool TESQuest::IsStopped() const
{
	//return ((data.flags & Data07C::kQuestFlag_Running) == 0 && (data.flags & Data07C::kQuestFlag_Stopping) == 0);
	return !data.flags.running && !data.flags.stopping;
}


BGSBaseAlias* TESQuest::GetAlias(UInt32 aliasID) const	// 0056B6F0
{
	BGSBaseAlias *alias = nullptr;

	for (BGSBaseAlias *p : aliases)
	{
		if (p && p->aliasId == aliasID)
		{
			alias = p;
			break;
		}
	}

	return alias;
}
