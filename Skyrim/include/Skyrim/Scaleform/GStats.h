#pragma once

enum GStatGroup
{
	GStatGroup_Default = 0,

	GStatGroup_Core = 16,
	GStatGroup_Renderer = 1 << 6,
	GStatGroup_RenderGen = 2 << 6,

	GStatGroup_GFxFontCache = 3 << 6,
	GStatGroup_GFxMovieData = 4 << 6,
	GStatGroup_GFxMovieView = 5 << 6,
	GStatGroup_GFxRenderCache = 6 << 6,
	GStatGroup_GFxPlayer = 7 << 6,
	GStatGroup_GFxIME = 8 << 6,

	// General Memory

	GStat_Mem = GStatGroup_Default + 1,
	GStat_Default_Mem,
	GStat_Image_Mem,
	GStat_Sound_Mem,
	GStat_String_Mem,
	GStat_Video_Mem,
	// Memory allocated for debugging purposes.
	GStat_Debug_Mem,
	GStat_DebugHUD_Mem,
	GStat_DebugTracker_Mem,
	GStat_StatBag_Mem,

	// Core entries.
	GStatHeap_Start = GStatGroup_Core,
	// 16 slots for HeapSummary
	
	// How many entries we support by default
	GStat_MaxId = 64 << 6, // 64 * 64 = 4096
	GStat_EntryCount = 512
};


enum GFxStatMovieView
{
	GFxStatMV_Default = GStatGroup_GFxMovieView,

	// MovieView memory.
	GFxStatMV_Mem,
	GFxStatMV_MovieClip_Mem,
	GFxStatMV_ActionScript_Mem,
	GFxStatMV_Text_Mem,
	GFxStatMV_XML_Mem,
	GFxStatMV_Other_Mem,

	// MovieView Timings.
	GFxStatMV_Tks,
	GFxStatMV_Advance_Tks,
	GFxStatMV_Action_Tks,
	GFxStatMV_Timeline_Tks,
	GFxStatMV_Input_Tks,
	GFxStatMV_Mouse_Tks,
	GFxStatMV_ScriptCommunication_Tks,
	GFxStatMV_GetVariable_Tks,
	GFxStatMV_SetVariable_Tks,
	GFxStatMV_Invoke_Tks,
	GFxStatMV_Display_Tks,
	GFxStatMV_Tessellate_Tks,
	GFxStatMV_GradientGen_Tks,
};
