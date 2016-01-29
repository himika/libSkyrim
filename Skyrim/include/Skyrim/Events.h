#pragma once

struct BSPathEvent
{
	/*
	008BA5BE: 01B37E88.AddEventSink(01B407A0)
	class SkyrimScript::PathingCallbackMgr +0000
	+0000 05 class SkyrimScript::PathingCallbackMgr | 012B66EC
	+0004 03 struct BSTSingletonSDM<class SkyrimScript::PathingCallbackMgr,struct BSTSingletonSDMOpStaticBuffer> | 012B6720
	+0004 02 struct BSTSingletonSDMBase<struct BSTSDMTraits<class SkyrimScript::PathingCallbackMgr,struct BSTSingletonSDMOpStaticBuffer<class SkyrimScript::PathingCallbackMgr> > > | 012B6788
	+0004 00 struct BSTSDMTraits<class SkyrimScript::PathingCallbackMgr,struct BSTSingletonSDMOpStaticBuffer<class SkyrimScript::PathingCallbackMgr> > | 012B6828
	+0005 00 struct BSTSingletonSDMOpStaticBuffer<class SkyrimScript::PathingCallbackMgr> | 012B68B0
-->	+0000 00 class BSTEventSink<struct BSPathEvent> | 012B66BC
	*/
};
