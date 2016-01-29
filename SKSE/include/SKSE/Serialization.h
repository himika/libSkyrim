#pragma once

#include <Skyrim.h>
#include <Skyrim/BSCore/BSSpinLock.h>
#include <Skyrim/BSCore/BSFixedString.h>
#include <Skyrim/SkyrimScript.h>
#include <Skyrim/SkyrimVM.h>
#include <Skyrim/BSScript/BSScriptTypeTraits.h>
#include "PluginAPI.h"

#include <tuple>
#include <utility>
#include <forward_list>
#include <type_traits>

#include "DebugLog.h"

#define ENABLE_IF(expr) typename std::enable_if<(expr)>::type *& = enabler

struct ReadInterface
{
protected:
	template <class Ty>
	static bool ReadRecordData(SKSESerializationInterface * intrfc, Ty & val) {
		return intrfc->ReadRecordData(&val, sizeof(Ty)) == sizeof(Ty);
	}

	template <>
	static bool ReadRecordData(SKSESerializationInterface * intrfc, BSFixedString & str) {
		UInt16 len;
		if (!ReadRecordData(intrfc, len))
			return false;
		if (len > 256)
			return false;

		char buf[257] = { 0 };
		if (len > 0) {
			if (intrfc->ReadRecordData(buf, len) != len)
				return false;
		}
		buf[len] = 0;
		str = buf;

		return true;
	}

	template <>
	static bool ReadRecordData(SKSESerializationInterface * intrfc, VMHandle & handle) {
		bool result = (intrfc->ReadRecordData(&handle, sizeof(VMHandle)) == sizeof(VMHandle));
		if (result) {
			VMHandle newHandle = 0;
			result = intrfc->ResolveHandle(handle, &newHandle);
			handle = result ? newHandle : 0;
		}
		return result;
	}

	template <class Ty, ENABLE_IF( BSScript::is_form<Ty>::value )>
	static bool ReadRecordData(SKSESerializationInterface * intrfc, Ty *& p) {
		VMHandle handle;
		if (!ReadRecordData(intrfc, handle))
			return false;

		auto handlePolicy = g_skyrimVM->GetState()->GetHandlePolicy();
		p = (Ty*)handlePolicy->Resolve(Ty::kTypeID, handle);
		return true;
	}

	template <class Ty1, class Ty2>
	static bool ReadRecordData(SKSESerializationInterface * intrfc, std::pair<Ty1, Ty2> & pair) {
		return ReadRecordData(intrfc, pair.first) && ReadRecordData(intrfc, pair.second);
	}

	template <class... Params>
	static bool ReadRecordData(SKSESerializationInterface * intrfc, std::tuple<Params...> & tp) {
		return ReadTuple(intrfc, tp);
	}

private:
	static void * enabler;

	template <std::size_t N = 0, class Tuple, ENABLE_IF( N < std::tuple_size<Tuple>::value )>
	static bool ReadTuple(SKSESerializationInterface * intrfc, Tuple & tp) {
		return ReadRecordData(intrfc, std::get<N>(tp)) && ReadTuple<N + 1>(intrfc, tp);
	}

	template <std::size_t N = 0, class Tuple, ENABLE_IF( N == std::tuple_size<Tuple>::value )>
	static bool ReadTuple(SKSESerializationInterface * intrfc, Tuple & tp) {
		return true;
	}
};


struct WriteInterface
{
protected:
	template <class Ty>
	static bool WriteRecordData(SKSESerializationInterface * intrfc, Ty & val) {
		return intrfc->WriteRecordData(&val, sizeof(Ty));
	}

	template <>
	static bool WriteRecordData(SKSESerializationInterface * intrfc, BSFixedString & str) {
		UInt16 len = str.length();
		if (len > 256)
			return false;
		if (!WriteRecordData(intrfc, len))
			return false;
		if (len > 0) {
			if (!intrfc->WriteRecordData(str.c_str(), len))
				return false;
		}
		return true;
	}

	template <class Ty, ENABLE_IF( BSScript::is_form<Ty>::value )>
	static bool WriteRecordData(SKSESerializationInterface * intrfc, Ty *& p) {
		auto handlePolicy = g_skyrimVM->GetState()->GetHandlePolicy();
		VMHandle handle = handlePolicy->Create(Ty::kTypeID, p);
		return WriteRecordData(intrfc, handle);
	}

	template <class Ty1, class Ty2>
	static bool WriteRecordData(SKSESerializationInterface * intrfc, std::pair<Ty1, Ty2> & pair) {
		return WriteRecordData(intrfc, pair.first) && WriteRecordData(intrfc, pair.second);
	}

	template <class... Params>
	static bool WriteRecordData(SKSESerializationInterface * intrfc, std::tuple<Params...> & tp) {
		return WriteTuple(intrfc, tp);
	}

private:
	static void * enabler;

	template <std::size_t N = 0, class Tuple, ENABLE_IF( N < std::tuple_size<Tuple>::value )>
	static bool WriteTuple(SKSESerializationInterface * intrfc, Tuple & tp) {
		return WriteRecordData(intrfc, std::get<N>(tp)) && WriteTuple<N + 1>(intrfc, tp);
	}

	template <std::size_t N = 0, class Tuple, ENABLE_IF( N == std::tuple_size<Tuple>::value)>
	static bool WriteTuple(SKSESerializationInterface * intrfc, Tuple & tp) {
		return true;
	}
};


struct CompareInterface
{
protected:
	template <std::size_t N = 0, class Tuple1, class Tuple2, ENABLE_IF( N < std::tuple_size<Tuple1>::value )>
	static bool Compare(Tuple1 &tp1, Tuple2 &tp2) {
		return std::get<N>(tp1) == std::get<N>(tp2) && Compare<N + 1>(tp1, tp2);
	}

	template <std::size_t N = 0, class Tuple1, class Tuple2, ENABLE_IF( N == std::tuple_size<Tuple1>::value)>
	static bool Compare(Tuple1 &tp1, Tuple2 &tp2) { return true; }

	static void * enabler;
};

struct VMHandleInterface
{
protected:
	using HandlePolicy = SkyrimScript::HandlePolicy;

	// incref handle
	template <class Ty>
	static void	IncRefCount(HandlePolicy * handlePolicy, Ty & val) {
		// do nothing
	}

	template <>
	static void IncRefCount(HandlePolicy * handlePolicy, VMHandle & handle) {
		handlePolicy->AddRef(handle);
	}

	template <class Ty1, class Ty2>
	static void IncRefCount(HandlePolicy * handlePolicy, std::pair<Ty1, Ty2> & pair) {
		IncRefCount(handlePolicy, pair.first);
		IncRefCount(handlePolicy, pair.second);
	}

	template <class... Params>
	static void IncRefCount(HandlePolicy * handlePolicy, std::tuple<Params...> & tp) {
		IncRefCountTuple(handlePolicy, tp);
	}

	// decref handle
	template <class Ty>
	static void	DecRefCount(HandlePolicy * handlePolicy, Ty & val) { }

	template <>
	static void DecRefCount(HandlePolicy * handlePolicy, VMHandle & handle) {
		handlePolicy->Release(handle);
	}

	template <class Ty1, class Ty2>
	static void DecRefCount(HandlePolicy * handlePolicy, std::pair<Ty1, Ty2> & pair) {
		DecRefCount(handlePolicy, pair.first);
		DecRefCount(handlePolicy, pair.second);
	}

	template <class... Params>
	static void DecRefCount(HandlePolicy * handlePolicy, std::tuple<Params...> & tp) {
		DecRefCountTuple(handlePolicy, tp);
	}

	// has handle
	template <class Ty>
	static bool HasHandle(VMHandle handle, Ty & val) { return false; }

	template <>
	static bool HasHandle(VMHandle handle, VMHandle & val) {
		return val == handle;
	}

	template <class Ty1, class Ty2>
	static bool HasHandle(VMHandle handle, std::pair<Ty1, Ty2> & pair) {
		return HasHandle(handle, pair.first) || HasHandle(handle, pair.second);
	}

	template <class... Params>
	static bool HasHandle(VMHandle handle, std::tuple<Params...> & tp) {
		return HasHandleTuple(handle, tp);
	}

	// has form
	template <class Ty>
	static bool HasForm(void * obj, Ty & val) { return false; }

	template <class Ty, ENABLE_IF( BSScript::is_form<Ty>::value )>
	static bool HasForm(void * obj, Ty *& p) {
		return obj == (void*)p;
	}

	template <class Ty1, class Ty2>
	static bool HasForm(void * obj, std::pair<Ty1, Ty2> & pair) {
		return HasForm(obj, pair.first) || HasForm(obj, pair.second);
	}

	template <class... Params>
	static bool HasForm(void * obj, std::tuple<Params...> & tp) {
		return HasFormTuple(obj, tp);
	}

private:
	static void * enabler;

	template <std::size_t N = 0, class Tuple, ENABLE_IF( N < std::tuple_size<Tuple>::value )>
	static void IncRefCountTuple(HandlePolicy * handlePolicy, Tuple & tp) {
		IncRefCount(handlePolicy, std::get<N>(tp));
		IncRefCountTuple<N + 1>(handlePolicy, tp);
	}

	template <std::size_t N = 0, class Tuple, ENABLE_IF( N == std::tuple_size<Tuple>::value )>
	static void IncRefCountTuple(HandlePolicy * handlePolicy, Tuple & tp) {
	}

	template <std::size_t N = 0, class Tuple, ENABLE_IF( N < std::tuple_size<Tuple>::value )>
	static void DecRefCountTuple(HandlePolicy * handlePolicy, Tuple & tp) {
		DecRefCount(handlePolicy, std::get<N>(tp));
		DecRefCountTuple<N + 1>(handlePolicy, tp);
	}

	template <std::size_t N = 0, class Tuple, ENABLE_IF( N == std::tuple_size<Tuple>::value )>
	static void DecRefCountTuple(HandlePolicy * handlePolicy, Tuple & tp) {
	}

	template <std::size_t N = 0, class Tuple, ENABLE_IF( N < std::tuple_size<Tuple>::value )>
	static bool HasHandleTuple(VMHandle handle, Tuple & tp) {
		return HasHandle(handle, std::get<N>(tp)) || HasHandleTuple<N + 1>(handle, tp);
	}

	template <std::size_t N = 0, class Tuple, ENABLE_IF( N == std::tuple_size<Tuple>::value )>
	static bool HasHandleTuple(VMHandle handle, Tuple & tp) {
		return false;
	}

	template <std::size_t N = 0, class Tuple, ENABLE_IF( N < std::tuple_size<Tuple>::value )>
	static bool HasFormTuple(void * obj, Tuple & tp) {
		return HasForm(obj, std::get<N>(tp)) || HasFormTuple<N + 1>(obj, tp);
	}

	template <std::size_t N = 0, class Tuple, ENABLE_IF( N == std::tuple_size<Tuple>::value )>
	static bool HasFormTuple(void * obj, Tuple & tp) {
		return false;
	}
};



class SerializableBase : public ReadInterface, public WriteInterface, public CompareInterface, public VMHandleInterface
{
public:
	SerializableBase();
	virtual ~SerializableBase();

	virtual UInt32 GetType() = 0;
	virtual UInt32 GetVersion() = 0;
	virtual bool Save(SKSESerializationInterface * intrfc) = 0;
	virtual bool Load(SKSESerializationInterface * intrfc, UInt32 version) = 0;
	virtual void Revert(SKSESerializationInterface * intrfc) = 0;
	virtual void DeleteHandle(VMHandle handle) = 0;

	void Lock() {
		spinLock.Lock();
	}
	void Unlock() {
		spinLock.Unlock();
	}

private:
	// @members
	BSSpinLock spinLock;
};


template <UInt32 TYPE, UInt32 VERSION, class...Params>
class Serializable : public SerializableBase, public std::forward_list< std::tuple<Params...> >
{
public:
	typedef std::tuple<Params...> Tuple;

	enum { kType = TYPE };
	enum { kVersion = VERSION };

	Serializable()
	{
	}

	virtual UInt32 GetType() override
	{
		return TYPE;
	}

	virtual UInt32 GetVersion() override
	{
		return VERSION;
	}

	virtual bool Save(SKSESerializationInterface * intrfc) override
	{
		std::size_t size = std::distance(begin(), end());
		if (!WriteRecordData(intrfc, size)) {
			return false;
		}

		Lock();
		for (auto &node : *this)
		{
			if (std::get<0>(node)) {
				if (!WriteRecordData(intrfc, node)) {
					Unlock();
					return false;
				}
			}
		}
		Unlock();

		return true;
	}

	virtual bool Load(SKSESerializationInterface * intrfc, UInt32 version) override
	{
		VMState * state = g_skyrimVM->GetState();
		auto handlePolicy = state->GetHandlePolicy();


		std::size_t size = 0;
		if (!ReadRecordData(intrfc, size)) {
			return false;
		}

		Lock();
		for (std::size_t i = 0; i < size; i++) {
			Tuple tp;
			_MESSAGE("read tuple %s", typeid(Tuple).name());
			if (!ReadRecordData(intrfc, tp)) {
				Unlock();
				return false;
			}

			IncRefCount(handlePolicy, tp);
			this->push_front(tp);
		}
		Unlock();

		return true;
	}

	virtual void Revert(SKSESerializationInterface * intrfc) override
	{
		Lock();
		this->clear();
		Unlock();

		return;
	}

	virtual void DeleteHandle(VMHandle handle) override
	{
		// resolve handle to form pointer
		VMState * state = g_skyrimVM->GetState();
		auto handlePolicy = state->GetHandlePolicy();
		void *obj = handlePolicy->Resolve(0, handle);

		Lock();
		for (auto &node : *this)
		{
			if (HasHandle(handle, node)) {
				DecRefCount(handlePolicy, node);
				std::get<0>(node) = 0;
			}
			else if (obj && HasForm(obj, node)) {
				std::get<0>(node) = 0;
			}
		}
		Unlock();
	}

	void Register(Params... params) {
		VMState * state = g_skyrimVM->GetState();
		auto handlePolicy = state->GetHandlePolicy();

		auto entry = std::make_tuple(params...);
		IncRefCount(handlePolicy, entry);

		Lock();

		bool bEmptyFound = false;
		for (auto &node : *this) {
			if (std::get<0>(node) == 0) {
				node = entry;

				bEmptyFound = true;
				break;
			}
		}

		if (!bEmptyFound) {
			this->push_front(entry);
		}

		Unlock();
	}

	template <class... P2>
	std::size_t Unregister(P2... params) {
		VMState * state = g_skyrimVM->GetState();
		auto handlePolicy = state->GetHandlePolicy();

		std::size_t num = 0;
		auto comp = std::make_tuple(params...);

		Lock();
		auto prev = end();
		auto it = begin();
		while (it != end()) {
			auto next = it; ++next;
			if (Compare(comp, *it)) {
				DecRefCount(handlePolicy, *it);
				++num;
				if (prev == end()) {
					pop_front();
				}
				else {
					erase_after(prev);
				}
			}
			else {
				prev = it;
			}
			it = next;
		}
		Unlock();

		return num;
	}
};

#undef ENABLE_IF
