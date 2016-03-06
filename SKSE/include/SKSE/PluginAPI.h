#pragma once

#include <Skyrim.h>
#include <functional>

typedef UInt32	PluginHandle;	// treat this as an opaque type

// External Classes
class InventoryEntryData;
class GFxMovieView;
class GFxValue;
class VMState;
template <class> class BSTEventSource;

class TaskDelegate
{
public:
	virtual void	Run() = 0;
	virtual void	Dispose() = 0;
};


class UIDelegate
{
public:
	virtual void	Run(void) = 0;
	virtual void	Dispose(void) = 0;
};


enum
{
	kPluginHandle_Invalid = 0xFFFFFFFF
};


enum SKSEVersion
{
	kSKSEVersion_1_3_0  = 0x01030000,	// runtime 1.3.7
	kSKSEVersion_1_4_0  = 0x01040000,
	kSKSEVersion_1_4_1  = 0x01040010,
	kSKSEVersion_1_4_2  = 0x01040020,	// runtime 1.3.10
	kSKSEVersion_1_4_3  = 0x01040030,
	kSKSEVersion_1_4_4  = 0x01040040,
	kSKSEVersion_1_4_5  = 0x01040050,	// runtime 1.4.15
	kSKSEVersion_1_4_6  = 0x01040060,
	kSKSEVersion_1_4_7  = 0x01040070,	// runtime 1.4.20
	kSKSEVersion_1_4_8  = 0x01040080,	// runtime 1.4.21
	kSKSEVersion_1_4_9  = 0x01040090,
	kSKSEVersion_1_4_10 = 0x010400A0,
	kSKSEVersion_1_4_11 = 0x010400B0,	// runtime 1.4.26
	kSKSEVersion_1_4_12 = 0x010400C0,	// runtime 1.4.27
	kSKSEVersion_1_4_13 = 0x010400D0,
	kSKSEVersion_1_4_14 = 0x010400E0,	// runtime 1.5.24
	kSKSEVersion_1_4_15 = 0x010400F0,	// runtime 1.5.26
	kSKSEVersion_1_5_1  = 0x01050010,
	kSKSEVersion_1_5_2  = 0x01050020,
	kSKSEVersion_1_5_3  = 0x01050030,
	kSKSEVersion_1_5_4  = 0x01050040,
	kSKSEVersion_1_5_5  = 0x01050050,
	kSKSEVersion_1_5_6  = 0x01050060,
	kSKSEVersion_1_5_7  = 0x01050070,	// runtime 1.6.87
	kSKSEVersion_1_5_8  = 0x01050080,
	kSKSEVersion_1_5_9  = 0x01050090,	// runtime 1.6.89
	kSKSEVersion_1_5_10 = 0x010500A0,	// runtime 1.7.7
	kSKSEVersion_1_5_11 = 0x010500B0,
	kSKSEVersion_1_6_0  = 0x01060000,
	kSKSEVersion_1_6_1  = 0x01060010,
	kSKSEVersion_1_6_2  = 0x01060020,	// runtime 1.8.145
	kSKSEVersion_1_6_3  = 0x01060030,	// runtime 1.8.151
	kSKSEVersion_1_6_4  = 0x01060040,
	kSKSEVersion_1_6_5  = 0x01060050,
	kSKSEVersion_1_6_6  = 0x01060060,
	kSKSEVersion_1_6_7  = 0x01060070,
	kSKSEVersion_1_6_8  = 0x01060080,
	kSKSEVersion_1_6_9  = 0x01060090,
	kSKSEVersion_1_6_10 = 0x010600A0,	// runtime 1.9.26
	kSKSEVersion_1_6_11 = 0x010600B0,	// runtime 1.9.29
	kSKSEVersion_1_6_12 = 0x010600C0,	// runtime 1.9.32
	kSKSEVersion_1_6_13 = 0x010600D0,
	kSKSEVersion_1_6_14 = 0x010600E0,
	kSKSEVersion_1_6_15 = 0x010600F0,
	kSKSEVersion_1_6_16 = 0x01060100,
	kSKSEVersion_1_7_0  = 0x01070000,
	kSKSEVersion_1_7_1  = 0x01070010,
	kSKSEVersion_1_7_2  = 0x01070020,
	kSKSEVersion_1_7_3  = 0x01070030
};


struct SKSEInterface
{
	using Version = SKSEVersion;

	UInt32	skseVersion;
	UInt32	runtimeVersion;
	UInt32	editorVersion;
	UInt32	isEditor;
	void *	(*QueryInterface)(UInt32 id);

	// call during your Query or Load functions to get a PluginHandle uniquely identifying your plugin
	// invalid if called at any other time, so call it once and save the result
	PluginHandle(*GetPluginHandle)(void);

	// returns the SKSE build's release index
	UInt32(*GetReleaseIndex)(void);		// 1.7.0
};


struct SKSEScaleformInterface
{
	enum Version
	{
		Invalid = 0,
		Version_1 = 1,			// 1.6.13
		Version_2 = 2,			// 1.7.3
		CurrentVersion = Version_2
	};

	UInt32	version;

	// This callback will be called once for every new menu that is created.
	// Create your objects relative to the 'root' GFxValue parameter.
	typedef bool(*RegisterCallback)(GFxMovieView * view, GFxValue * root);
	typedef void(*RegisterInventoryCallback)(GFxMovieView * view, GFxValue * object, InventoryEntryData * item);

	// Register your plugin's scaleform API creation callback here.
	// The "name" parameter will be used to create an object with the path:
	// "skse.plugins.name" that will be passed to the callback.
	// Make sure that the memory it points to is valid from the point the callback
	// is registered until the game exits.
	bool(*Register)(const char * name, RegisterCallback callback);

	// Registers your plugin for when item data is extended to the UI
	// either favorites menu, or inventory menu
	void(*RegisterForInventory)(RegisterInventoryCallback callback);	// ver.2 (1.7.3)
};


struct SKSESerializationInterface
{
	enum Version
	{
		Invalid = 0,
		Version_1 = 1,			// 1.6.13
		Version_2 = 2,			// 1.6.14
		Version_3 = 3,			// 1.7.2
		Version_4 = 4,			// 1.7.3
		CurrentVersion = Version_4
	};

	typedef void(*EventCallback)(SKSESerializationInterface * intfc);
	typedef void(*FormDeleteCallback)(VMHandle handle);

	void	SetUniqueID(UInt32 uid) const;						// ver.2 (1.6.14)
	void	SetRevertCallback(EventCallback callback) const;
	void	SetSaveCallback(EventCallback callback) const;
	void	SetLoadCallback(EventCallback callback) const;
	void	SetFormDeleteCallback(FormDeleteCallback callback) const;

	inline bool WriteRecord(UInt32 type, UInt32 version, const void * buf, UInt32 length) const	{ return m_WriteRecord(type, version, buf, length);  }
	inline bool OpenRecord(UInt32 type, UInt32 version) const									{ return m_OpenRecord(type, version); }
	inline bool WriteRecordData(const void * buf, UInt32 length) const							{ return m_WriteRecordData(buf, length); }

	// @members
	UInt32	version;

	void(*m_SetUniqueID)(PluginHandle plugin, UInt32 uid);
	void(*m_SetRevertCallback)(PluginHandle plugin, EventCallback callback);
	void(*m_SetSaveCallback)(PluginHandle plugin, EventCallback callback);
	void(*m_SetLoadCallback)(PluginHandle plugin, EventCallback callback);
	void(*m_SetFormDeleteCallback)(PluginHandle plugin, FormDeleteCallback callback);

	bool(*m_WriteRecord)(UInt32 type, UInt32 version, const void * buf, UInt32 length);
	bool(*m_OpenRecord)(UInt32 type, UInt32 version);
	bool(*m_WriteRecordData)(const void * buf, UInt32 length);

	bool(*GetNextRecordInfo)(UInt32 * type, UInt32 * version, UInt32 * length);
	UInt32(*ReadRecordData)(void * buf, UInt32 length);
	bool(*ResolveHandle)(VMHandle handle, VMHandle * handleOut);
	bool(*ResolveFormId)(UInt32 formId, UInt32 * formIdOut);		// ver.4 (1.7.3)
};


struct SKSETaskInterface
{
	enum Version
	{
		Invalid = 0,
		Version_1 = 1,			// 1.6.15
		Version_2 = 2,			// 1.7.1
		CurrentVersion = Version_2
	};

	UInt32	version;

	// Derive your type from TaskDelegate or UIDelegate
	// Allocate before adding
	// Define your Run function
	// Delete your object in the Dispose call
	
	inline void AddTask(TaskDelegate *task) const {
		m_AddTask(task);
	}
	void AddTask(std::function<void()> task) const;

	inline void AddUITask(UIDelegate *task) const {
		m_AddUITask(task);
	}
	void AddUITask(std::function<void()> task) const;

	void(*m_AddTask)(TaskDelegate * task);
	void(*m_AddUITask)(UIDelegate * task);		// ver.2 (1.7.1)
};


struct SKSEPapyrusInterface
{
	enum Version
	{
		Invalid = 0,
		Version_1 = 1,			// 1.7.1
		CurrentVersion = Version_1
	};

	typedef bool(*RegisterFunctions)(VMState * state);

	UInt32	version;
	bool(*Register)(RegisterFunctions callback);
};


/**** Messaging API docs ********************************************************************
*
*	Messaging API allows inter-plugin communication at run-time. A plugin may register
*	one callback for each plugin from which it wishes to receive messages, specifying
*	the sender by name in the call to RegisterListener(). RegisterListener returns false
*	if the specified plugin is not loaded, true otherwise. Any messages dispatched by
*	the specified plugin will then be forwarded to the listener as they occur. Passing nullptr as
*	the sender registers the calling plugin as a listener to every loaded plugin.
*
*	Messages may be dispatched via Dispatch() to either a specific listener (specified
*	by name) or to all listeners (with nullptr passed as the receiver). The contents and format of
*	messageData are left up to the sender, and the receiver is responsible for casting the message
*	to the expected type. If no plugins are registered as listeners for the sender,
*	Dispatch() returns false, otherwise it returns true.
*
*	Calling RegisterListener() or Dispatch() during plugin load is not advised as the requested plugin
*	may not yet be loaded at that point. Instead, if you wish to register as a listener or dispatch a
*	message immediately after plugin load, use RegisterListener() during load to register to receive
*	messages from SKSE (sender name: "SKSE"). You will then receive a message from SKSE once
*	all plugins have been loaded, at which point it is safe to establish communications between
*	plugins.
*
*	Some plugin authors may wish to use strings instead of integers to denote message type. In
*	that case the receiver can pass the address of the string as an integer and require the receiver
*	to cast it back to a char* on receipt.
*
*********************************************************************************************/

struct SKSEMessagingInterface
{
	struct Message {
		const char	* sender;
		UInt32		type;
		UInt32		dataLen;
		void		* data;
	};

	typedef void(*EventCallback)(Message *msg);

	enum Version
	{
		Invalid = 0,
		Version_1 = 1,			// 1.7.1
		Version_2 = 2,			// 1.7.2
		CurrentVersion = Version_2
	};

	// SKSE messages
	enum MessageType
	{
		kMessage_PostLoad,		// sent to registered plugins once all plugins have been loaded (no data)
		kMessage_PostPostLoad,	// sent right after kMessage_PostLoad to facilitate the correct dispatching/registering of messages/listeners
		kMessage_PreLoadGame,	// dispatched immediately before savegame is read by Fallout
								// dataLen: length of file path, data: char* file path of .ess savegame file
		kMessage_PostLoadGame,	//dispatched after an attempt to load a saved game has finished (the game's LoadGame() routine
								//has returned). You will probably want to handle this event if your plugin uses a Preload callback
								//as there is a chance that after that callback is invoked the game will encounter an error
								//while loading the saved game (eg. corrupted save) which may require you to reset some of your
								//plugin state.
								//data: bool, true if game successfully loaded, false otherwise
								// plugins may register as listeners during the first callback while deferring dispatches until the next
		kMessage_SaveGame,
		kMessage_DeleteGame,	// sent right before deleting the .skse cosave and the .ess save.
								// dataLen: length of file path, data: char* file path of .ess savegame file
		kMessage_InputLoaded,	// sent right after game input is loaded, right before the main menu initializes
		kMessage_NewGame,		// ver.2 (1.7.2) sent after a new game is created, before the game has loaded (Sends CharGen TESQuest pointer)
		kMessage_DataLoaded		// ver.3 (1.7.3) send after the data handler has loaded all its forms
	};

	enum DispatcherType
	{
		kDispatcher_ModEvent = 0,
		kDispatcher_CameraEvent,
		kDispatcher_CrosshairEvent,
		kDispatcher_ActionEvent,		// ver.2 (1.7.2)
		kDispatcher_NiNodeUpdateEvent	// ver.2 (1.7.2)
	};

	bool	RegisterListener(const char* sender, EventCallback handler)  const;
	bool	Dispatch(MessageType messageType, void *data, UInt32 dataLen, const char *receiver)  const;
	void *	GetEventDispatcher(DispatcherType dispatcherId) const;
	
	template <class T>
	inline bool Dispatch(MessageType messageType, T *data, const char *receiver) const {
		return Dispatch(messageType, data, sizeof(T), receiver);
	}
	template <class T, std::size_t SIZE>
	inline bool Dispatch(MessageType messageType, T (&data)[SIZE], const char *receiver) const {
		return Dispatch(messageType, data, sizeof(T) * SIZE, receiver);
	}
	template <class T>
	BSTEventSource<T> * GetEventDispatcher() const;

	// @members
	UInt32	version;
	bool(*m_RegisterListener)(PluginHandle listener, const char *sender, EventCallback handler);
	bool(*m_Dispatch)(PluginHandle sender, MessageType messageType, void *data, UInt32 dataLen, const char *receiver);
	void *(*m_GetEventDispatcher)(DispatcherType dispatcherId);
};


/**** plugin API docs **********************************************************
*
*	The base API is pretty simple. Create a project based on the
*	skse_plugin_example project included with the SKSE source code, then define
*	and export these functions:
*
*	bool SKSEPlugin_Query(const SKSEInterface * skse, PluginInfo * info)
*
*	This primary purposes of this function are to fill out the PluginInfo
*	structure, and to perform basic version checks based on the info in the
*	SKSEInterface structure. Return false if your plugin is incompatible with
*	the version of SKSE or the runtime passed in, otherwise return true. In
*	either case, fill out the PluginInfo structure.
*
*	Do not do anything other than fill out the PluginInfo structure and return
*	true/false in this callback.
*
*	If the plugin is being loaded in the context of the editor, isEditor will be
*	non-zero, editorVersion will contain the current editor version, and
*	runtimeVersion will be zero. In this case you can probably just return
*	true, however if you have multiple DLLs implementing the same behavior, for
*	example one for each version of ther runtime, only one of them should return
*	true.
*
*	The PluginInfo fields should be filled out as follows:
*	- infoVersion should be set to PluginInfo::kInfoVersion
*	- name should be a pointer to a null-terminated string uniquely identifying
*	  your plugin, it will be used in the plugin querying API
*	- version is only used by the plugin query API, and will be returned to
*	  scripts requesting the current version of your plugin
*
*	bool SKSEPlugin_Load(const SKSEInterface * skse)
*
*	In this function, use the interfaces above to register your commands, patch
*	memory, generally do whatever you need to for integration with the runtime.
*
*	At this time, or at any point forward you can call the QueryInterface
*	callback to retrieve an interface structure for the base services provided
*	by the SKSE core.
*
*	You may optionally return false from this function to unload your plugin,
*	but make sure that you DO NOT register any commands if you do.
*
*	Note that all structure versions are backwards-compatible, so you only need
*	to check against the latest version that you need. New fields will be only
*	added to the end, and all old fields will remain compatible with their
*	previous implementations.
*
******************************************************************************/

class SKSEPlugin
{
public:
	SKSEPlugin();
	virtual ~SKSEPlugin();

	virtual bool InitInstance() = 0;
	virtual bool OnLoad();
	virtual void OnModLoaded();

	const char * GetDllName() const;
	static const SKSEPlugin* GetSingleton();

	PluginHandle GetPluginHandle() const;
	UInt32 GetRuntimeVersion() const;
	UInt32 GetSKSEVersion() const;
	UInt32 GetSKSEReleaseIndex() const;

	template <class Interface>
	typename Interface::Version GetInterfaceVersion() const;

	const SKSEInterface*				GetInterface(SKSEInterface::Version version) const;
	const SKSEScaleformInterface*		GetInterface(SKSEScaleformInterface::Version version) const;
	const SKSEPapyrusInterface*			GetInterface(SKSEPapyrusInterface::Version version) const;
	const SKSESerializationInterface*	GetInterface(SKSESerializationInterface::Version version) const;
	const SKSETaskInterface*			GetInterface(SKSETaskInterface::Version version) const;
	const SKSEMessagingInterface*		GetInterface(SKSEMessagingInterface::Version version) const;

	template <class Interface>
	const Interface* GetInterface() const {
		return GetInterface((Interface::Version)0);
	}

protected:
	void SetName(const char* name);
	void SetVersion(UInt32 version);

	bool Requires(SKSEVersion version) const;
	bool Requires(SKSEScaleformInterface::Version version) const;
	bool Requires(SKSEPapyrusInterface::Version version) const;
	bool Requires(SKSESerializationInterface::Version version) const;
	bool Requires(SKSETaskInterface::Version version) const;
	bool Requires(SKSEMessagingInterface::Version version) const;
	bool Requires(const char* modName) const;

	template <class Arg0, class... Args>
	bool Requires(Arg0 arg0, Args... args) const {
		return Requires(arg0) && Requires(args...);
	}
};
