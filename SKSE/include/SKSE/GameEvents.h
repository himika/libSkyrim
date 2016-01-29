#pragma once

#include <Skyrim.h>
#include <Skyrim/BSCore/BSTEvent.h>
#include <Skyrim/Events/ScriptEvent.h>
#include <Skyrim/Events/BGSStoryEvent.h>
#include <Skyrim/Events/PositionPlayerEvent.h>
#include <Skyrim/Events/MenuEvent.h>
#include <Skyrim/Events/ActorEvent.h>
#include <Skyrim/Events/DefaultObjectsReadyEvent.h>
#include <Skyrim/Misc/BGSFootstepManager.h>
#include <Skyrim/Misc/BGSCombatImpactManager.h>
#include <Skyrim/Misc/BGSCollisionSoundManager.h>
#include "SKSEEvents.h"

#include <functional>
#include <type_traits>


template <class EventT>
struct SKSEEvent
{
	typedef BSTEventSource<EventT> SourceT;
	typedef BSTEventSink<EventT> SinkT;

	typedef EventResult(*FuncPtr0)();
	typedef EventResult(*FuncPtr1)(EventT*);
	typedef EventResult(*FuncPtr2)(EventT*, SourceT*);
	typedef EventResult(*FuncPtr3)(EventT*, SourceT*, SinkT*);

	struct Arg0	{ template <class Fn> static inline EventResult Call(Fn f, EventT* e, SourceT* src, SinkT* snk) { return f(); } };
	struct Arg1	{ template <class Fn> static inline EventResult Call(Fn f, EventT* e, SourceT* src, SinkT* snk) { return f(e); } };
	struct Arg2	{ template <class Fn> static inline EventResult Call(Fn f, EventT* e, SourceT* src, SinkT* snk) { return f(e, src); } };
	struct Arg3	{ template <class Fn> static inline EventResult Call(Fn f, EventT* e, SourceT* src, SinkT* snk) { return f(e, src, snk); } };

	struct CompFunction	{ template <class Sn> static inline bool Equal(Sn* a, Sn* b) { return a->fn == b->fn; } };
	struct CompFunctor	{ template <class Sn> static inline bool Equal(Sn* a, Sn* b) { return &a->fn == &b->fn; } };
	struct CompLambda	{ template <class Sn> static inline bool Equal(Sn* a, Sn* b) { return true; } };

	template <class _Sink, class _Src> static _Src SourceType(EventResult(_Sink::*)(EventT*, _Src*));

	template <class Fn, class Arguments, class Compare>
	class EventSink : public SinkT
	{
	public:
		typedef decltype(SourceType(&SinkT::ReceiveEvent)) SourceT;

		EventSink(Fn f) : fn(f) {}
		virtual ~EventSink() {}
		virtual EventResult ReceiveEvent(EventT* evn, SourceT* source) {
			return Arguments::Call(fn, evn, source, this);
		}
		bool operator==(SinkT& sink) {
			void* vtblA = *reinterpret_cast<void**>(this);
			void* vtblB = *reinterpret_cast<void**>(&sink);
			return (vtblA == vtblB && Compare::Equal(this, reinterpret_cast<EventSink*>(&sink)));
		}
		Fn fn;
	};

	// functor
	template <class F> static EventSink<F&, Arg0, CompFunctor> ObjSinkType(EventResult(F::*)());
	template <class F> static EventSink<F&, Arg1, CompFunctor> ObjSinkType(EventResult(F::*)(EventT*));
	template <class F> static EventSink<F&, Arg2, CompFunctor> ObjSinkType(EventResult(F::*)(EventT*, SourceT*));
	template <class F> static EventSink<F&, Arg3, CompFunctor> ObjSinkType(EventResult(F::*)(EventT*, SourceT*, SinkT*));

	// lambda
	template <class F> static EventSink<F, Arg0, CompLambda>  ObjSinkType(EventResult(F::*)() const);
	template <class F> static EventSink<F, Arg1, CompLambda>  ObjSinkType(EventResult(F::*)(EventT*) const);
	template <class F> static EventSink<F, Arg2, CompLambda>  ObjSinkType(EventResult(F::*)(EventT*, SourceT*) const);
	template <class F> static EventSink<F, Arg3, CompLambda>  ObjSinkType(EventResult(F::*)(EventT*, SourceT*, SinkT*) const);

	static EventSink<FuncPtr0, Arg0, CompFunction> SinkType(FuncPtr0);
	static EventSink<FuncPtr1, Arg1, CompFunction> SinkType(FuncPtr1);
	static EventSink<FuncPtr2, Arg2, CompFunction> SinkType(FuncPtr2);
	static EventSink<FuncPtr3, Arg3, CompFunction> SinkType(FuncPtr3);
	template <class F> static auto SinkType(F f) -> decltype(ObjSinkType(&F::operator())) {};
};

template<class EventT, class F>
BSTEventSource<EventT>& operator+=(BSTEventSource<EventT>& source, F& f) {
	typedef decltype(SKSEEvent<EventT>::SinkType(f)) SinkT;

	SinkT* sink = new SinkT(f);
	source.AddEventSink(sink);

	return source;
}

template <class EventT, class F>
BSTEventSource<EventT>& operator-=(BSTEventSource<EventT>& source, F& f) {
	typedef decltype(SKSEEvent<EventT>::SinkType(f)) SinkT;

	SinkT tmpSink(f);

	int i = 0;
	SinkT* sink = nullptr;
	BSTArray<SinkT*>* eventSinks = reinterpret_cast<BSTArray<SinkT*>*>((UInt32)&source + 8);
	while (eventSinks->GetAt(i++, sink)) {
		if (tmpSink == *sink) {
			RemoveEventSink(sink);
			delete sink;
			break;
		}
	}

	return source;
}

//=========================================================================================================

template <class EventT>
struct SKSEEvent2
{
	typedef BSTEventSource<EventT> Source;

	class Sink : public BSTEventSink<EventT>
	{
	public:
		typedef std::function<EventResult(EventT *, Source *)> Callback;

		Sink(Callback a_callback) : m_callback(a_callback)
		{
		}

		virtual ~Sink()
		{
		}

		virtual EventResult ReceiveEvent(EventT* evn, Source* source)
		{
			return m_callback(evn, source);
		}

		Callback m_callback;
	};

	static Sink* CreateSink(typename Sink::Callback callback)
	{
		return new Sink(callback);
	}

	static Source* GetEventSource(void);
};


template <class EventT>
inline void AddEventSink(BSTEventSink<EventT> *sink)
{
	auto source = SKSEEvent2<EventT>::GetEventSource();
	if (sink && source)
	{
		source->AddEventSink(sink);
	}
}

template <class EventT>
BSTEventSink<EventT>* AddEventSink(std::function<EventResult(EventT *, BSTEventSource<EventT> *)> fn)
{
	auto sink = SKSEEvent2<EventT>::CreateSink(fn);
	if (sink)
	{
		AddEventSink(sink);
	}

	return sink;
}
