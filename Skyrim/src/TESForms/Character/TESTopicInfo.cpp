#include "Skyrim/Forms/TESTopicInfo.h"
#include "Skyrim/BSCore/BSTHashMap.h"
#include "Skyrim/BSCore/BSFixedString.h"

class TESNPC;
class BGSSoundOutput;

BSTHashMap<TESTopicInfo *, BSFixedString> &s_promptMap = *(BSTHashMap<TESTopicInfo *, BSFixedString> *)0x0125AE88;
BSTHashMap<TESTopicInfo *, TESNPC *> &s_speakerMap = *(BSTHashMap<TESTopicInfo *, TESNPC *> *)0x0125AEA8;
BSTHashMap<TESTopicInfo *, TESTopic *> &s_walkAwayTopicMap = *(BSTHashMap<TESTopicInfo *, TESTopic *> *)0x0125AEC8;
BSTHashMap<TESTopicInfo *, TESTopic **> &s_linkToTopicsMap = *(BSTHashMap<TESTopicInfo *, TESTopic **> *)0x0125AEE8;
BSTHashMap<TESTopicInfo *, BGSSoundOutput *> &s_soundOutputMap = *(BSTHashMap<TESTopicInfo *, BGSSoundOutput *> *)0x0125AF08;


const char * TESTopicInfo::GetPrompt() const
{
	BSFixedString prompt = "";
	s_promptMap.GetAt(const_cast<TESTopicInfo *>(this), prompt);
	return prompt.c_str();
}


TESNPC * TESTopicInfo::GetSpeaker() const
{
	TESNPC *speaker = nullptr;
	s_speakerMap.GetAt(const_cast<TESTopicInfo *>(this), speaker);
	return speaker;
}


TESTopic * TESTopicInfo::GetWalkAwayTopic() const
{
	TESTopic *topic = nullptr;
	s_walkAwayTopicMap.GetAt(const_cast<TESTopicInfo *>(this), topic);
	return topic;
}


BGSSoundOutput * TESTopicInfo::GetSoundOutputOverride() const
{
	BGSSoundOutput *sound = nullptr;
	s_soundOutputMap.GetAt(const_cast<TESTopicInfo *>(this), sound);
	return sound;
}
