#include "SKSE/PluginAPI.h"
#include "SKSE/Version.h"
#include "SKSE/DebugLog.h"
#include <Skyrim/Events/ScriptEvent.h>

#include <memory>
#include <string>
#include <fstream>


#ifdef _MSC_VER
#  pragma warning(push)
#  pragma warning(disable: 4091)
#endif
#include <shlobj.h>
#ifdef _MSC_VER
#  pragma warning(pop)
#endif


#define SKSE_API extern "C" __declspec(dllexport)


struct PluginInfo
{
	enum
	{
		Invalid = 0,
		Version_1 = 1,
		CurrentVersion = Version_1,
	};

	UInt32			infoVersion;
	const char *	name;
	UInt32			version;
};


enum SKSEInterfaceType
{
	kInterface_Invalid = 0,
	kInterface_Scaleform,
	kInterface_Papyrus,
	kInterface_Serialization,
	kInterface_Task,
	kInterface_Messaging,
	kInterface_Max,
};


static HINSTANCE                    hInstance;
static std::string					dllName;

static SKSEPlugin*					thePlugin = nullptr;

static PluginInfo*					thePluginInfo = nullptr;
static PluginHandle					pluginHandle = kPluginHandle_Invalid;
static UInt32						runtimeVersion = 0;
static UInt32						skseVersion = 0;
static UInt32						skseReleaseIndex = 0;

static const SKSEInterface*			skse = nullptr;
static SKSEScaleformInterface*		scaleform = nullptr;
static SKSEPapyrusInterface*		papyrus = nullptr;
static SKSESerializationInterface*	serialization = nullptr;
static SKSETaskInterface*			task = nullptr;
static SKSEMessagingInterface*		messaging = nullptr;

static void** s_vtbl = nullptr;

static UInt32 skses[] = {
	MAKE_SKYRIM_VERSION(1, 3, 0),
	MAKE_SKYRIM_VERSION(1, 4, 0),
	MAKE_SKYRIM_VERSION(1, 4, 1),
	MAKE_SKYRIM_VERSION(1, 4, 2),
	MAKE_SKYRIM_VERSION(1, 4, 3),
	MAKE_SKYRIM_VERSION(1, 4, 4),
	MAKE_SKYRIM_VERSION(1, 4, 5),
	MAKE_SKYRIM_VERSION(1, 4, 6),
	MAKE_SKYRIM_VERSION(1, 4, 7),
	MAKE_SKYRIM_VERSION(1, 4, 8),
	MAKE_SKYRIM_VERSION(1, 4, 9),
	MAKE_SKYRIM_VERSION(1, 4, 10),
	MAKE_SKYRIM_VERSION(1, 4, 11),
	MAKE_SKYRIM_VERSION(1, 4, 12),
	MAKE_SKYRIM_VERSION(1, 4, 13),
	MAKE_SKYRIM_VERSION(1, 4, 14),
	MAKE_SKYRIM_VERSION(1, 4, 15),
	MAKE_SKYRIM_VERSION(1, 5, 1),
	MAKE_SKYRIM_VERSION(1, 5, 2),
	MAKE_SKYRIM_VERSION(1, 5, 3),
	MAKE_SKYRIM_VERSION(1, 5, 4),
	MAKE_SKYRIM_VERSION(1, 5, 5),
	MAKE_SKYRIM_VERSION(1, 5, 6),
	MAKE_SKYRIM_VERSION(1, 5, 7),
	MAKE_SKYRIM_VERSION(1, 5, 8),
	MAKE_SKYRIM_VERSION(1, 5, 9),
	MAKE_SKYRIM_VERSION(1, 5, 10),
	MAKE_SKYRIM_VERSION(1, 5, 11),
	MAKE_SKYRIM_VERSION(1, 6, 0),
	MAKE_SKYRIM_VERSION(1, 6, 1),
	MAKE_SKYRIM_VERSION(1, 6, 2),
	MAKE_SKYRIM_VERSION(1, 6, 3),
	MAKE_SKYRIM_VERSION(1, 6, 4),
	MAKE_SKYRIM_VERSION(1, 6, 5),
	MAKE_SKYRIM_VERSION(1, 6, 6),
	MAKE_SKYRIM_VERSION(1, 6, 7),
	MAKE_SKYRIM_VERSION(1, 6, 8),
	MAKE_SKYRIM_VERSION(1, 6, 9),
	MAKE_SKYRIM_VERSION(1, 6, 10),
	MAKE_SKYRIM_VERSION(1, 6, 11),
	MAKE_SKYRIM_VERSION(1, 6, 12),
	MAKE_SKYRIM_VERSION(1, 6, 13),
	MAKE_SKYRIM_VERSION(1, 6, 14),
	MAKE_SKYRIM_VERSION(1, 6, 15),
	MAKE_SKYRIM_VERSION(1, 6, 16),
	0
};

SKSEPlugin::SKSEPlugin()
{
	thePlugin = this;

	s_vtbl = *reinterpret_cast<void***>(this);
}

// @virtual
SKSEPlugin::~SKSEPlugin()
{
	if (gLog.is_open())
	{
		gLog.close();
	}
}

// @virtual
bool SKSEPlugin::OnLoad()
{
	gLog << GetDllName() << ".dll" << std::endl;
	gLog << thePluginInfo->name << " ver." << thePluginInfo->version << " loaded." << std::endl;

	return true;
}

// @virtual
void SKSEPlugin::OnModLoaded()
{
}

const SKSEPlugin* SKSEPlugin::GetSingleton()
{
	return thePlugin;
}

void SKSEPlugin::SetName(const char* name)
{
	thePluginInfo->name = name;
}

void SKSEPlugin::SetVersion(UInt32 version)
{
	thePluginInfo->version = version;
}

PluginHandle SKSEPlugin::GetPluginHandle() const
{
	return pluginHandle;
}

UInt32 SKSEPlugin::GetRuntimeVersion() const
{
	return runtimeVersion;
}

UInt32 SKSEPlugin::GetSKSEVersion() const
{
	return skseVersion;
}

UInt32 SKSEPlugin::GetSKSEReleaseIndex() const
{
	return skseReleaseIndex;
}


template <> SKSEInterface::Version
SKSEPlugin::GetInterfaceVersion<SKSEInterface>() const
{
	return (SKSEInterface::Version)skseVersion;
}
template <> SKSEScaleformInterface::Version
SKSEPlugin::GetInterfaceVersion<SKSEScaleformInterface>() const
{
	return (SKSEScaleformInterface::Version)(scaleform ? scaleform->version : 0);
}
template <> SKSEPapyrusInterface::Version
SKSEPlugin::GetInterfaceVersion<SKSEPapyrusInterface>() const
{
	return (SKSEPapyrusInterface::Version)(papyrus ? papyrus->version : 0);
}
template <> SKSESerializationInterface::Version
SKSEPlugin::GetInterfaceVersion<SKSESerializationInterface>() const
{
	return (SKSESerializationInterface::Version)(serialization ? serialization->version : 0);
}
template <> SKSETaskInterface::Version
SKSEPlugin::GetInterfaceVersion<SKSETaskInterface>() const
{
	return (SKSETaskInterface::Version)(task ? task->version : 0);
}
template <> SKSEMessagingInterface::Version
SKSEPlugin::GetInterfaceVersion<SKSEMessagingInterface>() const
{
	return (SKSEMessagingInterface::Version)(messaging ? messaging->version : 0);
}


const SKSEInterface* SKSEPlugin::GetInterface(SKSEInterface::Version version) const
{
	return (skse && skseVersion >= version) ? skse : nullptr;
}
const SKSEScaleformInterface* SKSEPlugin::GetInterface(SKSEScaleformInterface::Version version) const
{
	return (scaleform && scaleform->version >= version) ? scaleform : nullptr;
}
const SKSEPapyrusInterface* SKSEPlugin::GetInterface(SKSEPapyrusInterface::Version version) const
{
	return (papyrus && papyrus->version >= version) ? papyrus : nullptr;
}
const SKSESerializationInterface* SKSEPlugin::GetInterface(SKSESerializationInterface::Version version) const
{
	return (serialization && serialization->version >= version) ? serialization : nullptr;
}
const SKSETaskInterface* SKSEPlugin::GetInterface(SKSETaskInterface::Version version) const
{
	return (task && task->version >= version) ? task : nullptr;
}
const SKSEMessagingInterface* SKSEPlugin::GetInterface(SKSEMessagingInterface::Version version) const
{
	return (messaging && messaging->version >= version) ? messaging : nullptr;
}


bool SKSEPlugin::Requires(SKSEVersion version) const
{
	return skseVersion >= version;
}
bool SKSEPlugin::Requires(SKSEScaleformInterface::Version version) const
{
	return scaleform->version >= version;
}
bool SKSEPlugin::Requires(SKSEPapyrusInterface::Version version) const
{
	return papyrus->version >= version;
}
bool SKSEPlugin::Requires(SKSESerializationInterface::Version version) const
{
	return serialization->version >= version;
}
bool SKSEPlugin::Requires(SKSETaskInterface::Version version) const
{
	return task->version >= version;
}
bool SKSEPlugin::Requires(SKSEMessagingInterface::Version version) const
{
	return messaging->version >= version;
}

bool SKSEPlugin::Requires(const char* modName) const
{
	bool result = false;

	char buf[MAX_PATH];
	SHGetFolderPath(nullptr, CSIDL_LOCAL_APPDATA, nullptr, SHGFP_TYPE_CURRENT, buf);
	strcat_s(buf, "\\Skyrim\\plugins.txt");

	std::ifstream in(buf);
	if (in.is_open())
	{
		while (!in.eof())
		{
			in.getline(buf, MAX_PATH);
			
			if (buf[0] == '#')
				continue;

			if (_stricmp(buf, modName) == 0)
			{
				result = true;
				break;
			}
		}

		in.close();
	}

	return result;
}

//=============================================================================================

const char * SKSEPlugin::GetDllName() const
{
	return dllName.c_str();
}

//=============================================================================================

void SKSESerializationInterface::SetUniqueID(UInt32 uid) const
{
	m_SetUniqueID(pluginHandle, uid);
}
void SKSESerializationInterface::SetRevertCallback(SKSESerializationInterface::EventCallback callback) const
{
	m_SetRevertCallback(pluginHandle, callback);
}
void SKSESerializationInterface::SetSaveCallback(SKSESerializationInterface::EventCallback callback) const
{
	m_SetSaveCallback(pluginHandle, callback);
}
void SKSESerializationInterface::SetLoadCallback(SKSESerializationInterface::EventCallback callback) const
{
	m_SetLoadCallback(pluginHandle, callback);
}
void SKSESerializationInterface::SetFormDeleteCallback(SKSESerializationInterface::FormDeleteCallback callback) const
{
	m_SetFormDeleteCallback(pluginHandle, callback);
}

//=============================================================================================

namespace
{
	template <class BaseT>
	class TempTaskDelegate : public BaseT
	{
	public:
		std::function<void()> m_task;

		inline explicit TempTaskDelegate(const std::function<void()> &task) : m_task(task) {}

		void Run() override
		{
			m_task();
		}

		void Dispose() override
		{
			delete this;
		}

		inline static BaseT * Create(const std::function<void()> &task)
		{
			TempTaskDelegate *pThis = new TempTaskDelegate(task);
			return pThis;
		}
	};
}


void SKSETaskInterface::AddTask(std::function<void()> task) const
{
	AddTask(TempTaskDelegate<TaskDelegate>::Create(task));
}

void SKSETaskInterface::AddUITask(std::function<void()> task) const
{
	AddUITask(TempTaskDelegate<UIDelegate>::Create(task));
}


//=============================================================================================

bool SKSEMessagingInterface::RegisterListener(const char* sender, SKSEMessagingInterface::EventCallback handler) const
{
	return m_RegisterListener(pluginHandle, sender, handler);
}

bool SKSEMessagingInterface::Dispatch(MessageType messageType, void *data, UInt32 dataLen, const char *receiver) const
{
	return m_Dispatch(pluginHandle, messageType, data, dataLen, receiver);
}

void * SKSEMessagingInterface::GetEventDispatcher(DispatcherType dispatcherId) const
{
	return m_GetEventDispatcher(dispatcherId);
}

struct SKSEModCallbackEvent;
struct SKSECameraEvent;
struct SKSECrosshairRefEvent;
struct SKSEActionEvent;
struct SKSENiNodeUpdateEvent;

template <>
BSTEventSource<SKSEModCallbackEvent> * SKSEMessagingInterface::GetEventDispatcher() const
{
	return (BSTEventSource<SKSEModCallbackEvent> *)GetEventDispatcher(kDispatcher_ModEvent);
}

template <>
BSTEventSource<SKSECameraEvent> * SKSEMessagingInterface::GetEventDispatcher() const
{
	return (BSTEventSource<SKSECameraEvent> *)GetEventDispatcher(kDispatcher_CameraEvent);
}

template <>
BSTEventSource<SKSECrosshairRefEvent> * SKSEMessagingInterface::GetEventDispatcher() const
{
	return (BSTEventSource<SKSECrosshairRefEvent> *)GetEventDispatcher(kDispatcher_CrosshairEvent);
}

template <>
BSTEventSource<SKSEActionEvent> * SKSEMessagingInterface::GetEventDispatcher() const
{
	return (BSTEventSource<SKSEActionEvent> *)GetEventDispatcher(kDispatcher_ActionEvent);
}

template <>
BSTEventSource<SKSENiNodeUpdateEvent> * SKSEMessagingInterface::GetEventDispatcher() const
{
	return (BSTEventSource<SKSENiNodeUpdateEvent> *)GetEventDispatcher(kDispatcher_NiNodeUpdateEvent);
}


//=============================================================================================

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	char path[MAX_PATH];

	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		hInstance = hinstDLL;

		if (GetModuleFileName(hInstance, path, MAX_PATH))
		{
			char file_name[MAX_PATH];

			_splitpath_s(path, nullptr, 0, nullptr, 0, file_name, MAX_PATH, nullptr, 0);
			dllName = file_name;
		}
		break;
	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}




	return TRUE;
}


SKSE_API bool SKSEPlugin_Query(const SKSEInterface * a_skse, PluginInfo * info)
{
	if (!thePlugin)
		return false;

	skse = a_skse;
	thePluginInfo = info;

	if (skse->isEditor)
	{
		// _MESSAGE("loaded in editor, marking as incompatible");
		return false;
	}

	if (skse->runtimeVersion != RUNTIME_VERSION_1_9_32_0)
	{
		//UInt32 runtimeVersion = skse->runtimeVersion;
		//int major = (runtimeVersion >> 24) & 0xFF;
		//int minor = (runtimeVersion >> 16) & 0xFF;
		//int build = (runtimeVersion >> 8) & 0xFF;
		//int sub = runtimeVersion & 0xFF;

		//_MESSAGE("unsupported runtime version 1.%d.%d.%d", major, minor, build);
		//_MESSAGE("(this plugin needs 1.%d.%d.%d)", major, minor, build);
		return false;
	}

	pluginHandle = skse->GetPluginHandle();
	runtimeVersion = skse->runtimeVersion;
	skseVersion = skse->skseVersion;

	if (skseVersion >= MAKE_SKYRIM_VERSION(1, 7, 0))
	{
		skseReleaseIndex = skse->GetReleaseIndex();
	}
	else
	{
		// skse < 1.7.0
		// SKSEInterface::GetReleaseIndex() is not implemented
		for (int i = 0; skses[i]; i++)
		{
			if (skses[i] >= skseVersion)
			{
				skseReleaseIndex = i;
				break;
			}
		}
	}

	if (!gLog.is_open())
	{
		char path[MAX_PATH];

		if (!dllName.empty() && SHGetFolderPath(0, CSIDL_MYDOCUMENTS, 0, SHGFP_TYPE_CURRENT, path) == S_OK)
		{
			strcat_s(path, "\\My Games\\Skyrim\\SKSE\\");
			strcat_s(path, dllName.c_str());
			strcat_s(path, ".log");
			gLog.open(path);
		}
	}

	scaleform       = (SKSEScaleformInterface*)skse->QueryInterface(kInterface_Scaleform);
	papyrus         = (SKSEPapyrusInterface*)skse->QueryInterface(kInterface_Papyrus);
	serialization   = (SKSESerializationInterface*)skse->QueryInterface(kInterface_Serialization);
	task            = (SKSETaskInterface*)skse->QueryInterface(kInterface_Task);
	messaging       = (SKSEMessagingInterface*)skse->QueryInterface(kInterface_Messaging);

	if (!thePlugin->InitInstance())
	{
		return false;
	}

	return true;
}



SKSE_API bool SKSEPlugin_Load(const SKSEInterface * skse)
{
	if (!thePlugin->OnLoad())
	{
		return false;
	}

	// vtable of thePlugin class
	void **vtbl = *reinterpret_cast<void***>(thePlugin);
	
	// check if OnModLoaded() is overridden
	const std::size_t idxOnModLoaded = 3;
	if (s_vtbl[idxOnModLoaded] != vtbl[idxOnModLoaded])
	{
		class ModLoadedEventSink : public BSTEventSink<TESMagicEffectApplyEvent>
		{
		public:
			ModLoadedEventSink() {}
			virtual EventResult ReceiveEvent(TESMagicEffectApplyEvent *evn, BSTEventSource<TESMagicEffectApplyEvent> *source) override
			{
				source->RemoveEventSink(this);
				thePlugin->OnModLoaded();
				return kEvent_Continue;
			}
		};

		static ModLoadedEventSink modLoadedSink;
		g_magicEffectApplyEventSource.AddEventSink(&modLoadedSink);
	}

	return true;
}
