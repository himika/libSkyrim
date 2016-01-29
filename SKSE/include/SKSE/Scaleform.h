#pragma once

#include <Skyrim.h>
#include <Skyrim/BSCore/BSTArray.h>
#include <Skyrim/Scaleform/GfxPlayer.h>
#include "SKSE/PluginAPI.h"
#include <vector>
#include <functional>
#include <type_traits>

namespace SKSE
{
	template <class T>
	class GFxFunctionHandlerSingleton : public T
	{
	private:
		static T* singleton;

	public:
		virtual ~GFxFunctionHandlerSingleton(void) {
			singleton = nullptr;
		}

		static T* GetSingleton(void) {
			if (!singleton)
				singleton = new GFxFunctionHandlerSingleton;
			return singleton;
		}
	};

	template <class T>
	T* GFxFunctionHandlerSingleton<T>::singleton = nullptr;
}


template <class T>
typename std::enable_if<std::is_base_of<GFxFunctionHandler, T>::value>::type
RegisterFunction(GFxValue *val, GFxMovieView *movie, const char *name)
{
	T* pfc = SKSE::GFxFunctionHandlerSingleton<T>::GetSingleton();
	GFxValue	fnValue;
	movie->CreateFunction(&fnValue, pfc);
	val->SetMember(name, fnValue);
}


class UIInvokeDelegate : public UIDelegate
{
public:
	UIInvokeDelegate(GFxMovieView *view, const char *target);
	UIInvokeDelegate(const char *menuName, const char *target);
	~UIInvokeDelegate();

	virtual void Run() override;
	virtual void Dispose() override;

	void Queue();
	void Queue(bool b);
	void Queue(double f);
	void Queue(const char *str);
	void Queue(const wchar_t *wstr);
	void Queue(std::function<bool(std::vector<GFxValue> &args)> fn);

	inline GFxMovieView * GetView() {
		return m_view;
	}

	static UIInvokeDelegate * Create(const char *menuName, const char *target);
	static UIInvokeDelegate * Create(GFxMovieView *view, const char *target);

	std::vector<GFxValue>	m_args;

protected:
	GFxMovieView		* m_view;
	const char			* m_target;
};
