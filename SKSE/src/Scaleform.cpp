#include "SKSE/Scaleform.h"
#include "SKSE/PluginAPI.h"
#include <Skyrim/Menus/MenuManager.h>
#include <string>
#include <vector>

UIInvokeDelegate::UIInvokeDelegate(GFxMovieView *view, const char *target) : m_view(view), m_target(nullptr), m_args()
{
	if (target && target[0])
	{
		std::size_t len = strlen(target) + 1;
		char *p = (char*)FormHeap_Allocate(len);
		if (p)
		{
			strcpy_s(p, len, target);
			m_target = p;
		}
	}
}


UIInvokeDelegate::UIInvokeDelegate(const char *menuName, const char *target) : m_view(nullptr), m_target(nullptr), m_args()
{
	if (!menuName || !menuName[0])
		return;

	if (!target || !target[0])
		return;

	MenuManager * mm = MenuManager::GetSingleton();
	if (!mm)
		return;

	BSFixedString t = menuName;
	GFxMovieView *view = mm->GetMovieView(t);
	if (!view)
		return;

	std::size_t len = strlen(target) + 1;
	char *p = (char*)FormHeap_Allocate(len);
	if (p)
	{
		strcpy_s(p, len, target);
		m_target = p;
	}
}


UIInvokeDelegate::~UIInvokeDelegate()
{
	if (m_target)
		FormHeap_Free((void*)m_target);
}


void UIInvokeDelegate::Run()
{
	if (!m_view)
		return;

	GFxValue *value = (m_args.size() > 0) ? &m_args[0] : nullptr;

	m_view->Invoke(m_target, nullptr, value, m_args.size());
}


void UIInvokeDelegate::Dispose()
{
	delete this;
}


void UIInvokeDelegate::Queue()
{
	if (m_target)
	{
		const SKSEPlugin *plugin = SKSEPlugin::GetSingleton();
		const SKSETaskInterface *task = plugin->GetInterface(SKSETaskInterface::Version_2);
		if (task)
			task->AddUITask(this);
	}
}


void UIInvokeDelegate::Queue(bool val)
{
	m_args.reserve(1);
	GFxValue value(val);
	m_args.push_back(value);

	Queue();
}


void UIInvokeDelegate::Queue(double val)
{
	m_args.reserve(1);
	GFxValue value(val);
	m_args.push_back(value);

	Queue();
}


void UIInvokeDelegate::Queue(const char *str)
{
	m_args.reserve(1);
	GFxValue value;
	m_view->CreateString(&value, str);
	m_args.push_back(value);

	Queue();
}


void UIInvokeDelegate::Queue(const wchar_t *wstr)
{
	m_args.reserve(1);
	GFxValue value;
	m_view->CreateStringW(&value, wstr);
	m_args.push_back(value);

	Queue();
}


void UIInvokeDelegate::Queue(std::function<bool(std::vector<GFxValue> &args)> fn)
{
	if (m_target && fn(m_args))
	{
		const SKSEPlugin *plugin = SKSEPlugin::GetSingleton();
		const SKSETaskInterface *task = plugin->GetInterface(SKSETaskInterface::Version_2);
		if (task)
			task->AddUITask(this);
	}
}


UIInvokeDelegate * UIInvokeDelegate::Create(const char *menuName, const char *target)
{
	if (!menuName || !menuName[0])
		return nullptr;

	MenuManager * mm = MenuManager::GetSingleton();
	if (!mm)
		return nullptr;

	BSFixedString t = menuName;
	GFxMovieView *view = mm->GetMovieView(t);
	if (!view)
		return nullptr;

	return new UIInvokeDelegate(view, target);
}


UIInvokeDelegate * UIInvokeDelegate::Create(GFxMovieView *view, const char *target)
{
	if (!view)
		return nullptr;

	return new UIInvokeDelegate(view, target);
}
