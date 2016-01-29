#include <SKSE.h>
#include <SKSE/PluginAPI.h>
#include <SKSE/DebugLog.h>
#include <SKSE/GameRTTI.h>
#include <SKSE/HookUtil.h>
#include <SKSE/GameForms.h>
#include <SKSE/GameObjects.h>
#include <SKSE/GameReferences.h>
#include <SKSE/GameExtraData.h>
#include <SKSE/GameMenus.h>
#include <SKSE/PapyrusFunctions.h>

#include <vector>
#include <algorithm>

/*=================================
/ papyrus functions
/==================================*/

// scriptname PluginExample_TestQuest extends Quest
class PluginExample_TestQuest : public TESQuest
{
public:
	// int Function Add(int a, int b) native
	SInt32 Add(SInt32 a, SInt32 b)
	{
		return a + b;
	}

	// 要素a,b,cから成る、新しい配列を作成する
	// （直接VMArrayを扱うサンプル）
	static VMArray<SInt32> MakeArray(SInt32 a, SInt32 b, SInt32 c)
	{
		VMArray<SInt32> arr(3);
		arr[0] = a;
		arr[1] = b;
		arr[2] = c;

		return arr;
	}

	// 配列の要素をソートした新しい配列を返す
	// （いちどvectorを経由してVMArrayを扱うサンプル）
	static VMArray<SInt32> SortArray(VMArray<SInt32> arr)
	{
		std::vector<SInt32> vec = arr;

		std::sort(vec.begin(), vec.end());

		return vec;	// vector=>VMArrayの変換は勝手にやってくれる。そのまま返して良い。
	}

	// 配列の要素の順番を反転させる。引数の配列自体を変更する。
	static void ReverseArray(VMArray<SInt32> arr)
	{
		std::size_t size = arr.GetSize();
		std::size_t n = size / 2;

		for (int i = 0; i < n; i++)
		{
			arr.Swap(i, size - i - 1);
		}
	}

	static bool Register(VMState* state)
	{
		REGISTER_PAPYRUS_FUNCTION(PluginExample_TestQuest, Add, state);
		REGISTER_PAPYRUS_FUNCTION(PluginExample_TestQuest, MakeArray, state);
		REGISTER_PAPYRUS_FUNCTION(PluginExample_TestQuest, SortArray, state);
		REGISTER_PAPYRUS_FUNCTION(PluginExample_TestQuest, ReverseArray, state);

		_MESSAGE("regok");

		return true;
	}
};

class plugin_example_plugin : public SKSEPlugin,
	public BSTEventSink<MenuOpenCloseEvent>
{
public:
	plugin_example_plugin()
	{
	}

	virtual bool InitInstance() override
	{
		//// plugin_example.esp がロードされている必要がある
		//if (!Requires("plugin_example.esp"))
		//{
		//	return false;
		//}

		// SKSE ver 1.7.1 と Papyrusインタフェースver 1以上が必要
		if (!Requires(kSKSEVersion_1_7_1, SKSEPapyrusInterface::Version_1))
		{
			gLog << "ERROR: your skse version is too old" << std::endl;
			return false;
		}

		// プラグイン名とバージョンを設定
		SetName("plugin_example");
		SetVersion(1);

		return true;
	}

	virtual bool OnLoad() override
	{
		SKSEPlugin::OnLoad();

		MenuManager *mm = MenuManager::GetSingleton();
		mm->BSTEventSource<MenuOpenCloseEvent>::AddEventSink(this);

		const SKSEPapyrusInterface *pap = GetInterface(SKSEPapyrusInterface::Version_1);
		if (pap)
			pap->Register(&PluginExample_TestQuest::Register);

		return true;
	}

	virtual EventResult ReceiveEvent(MenuOpenCloseEvent *evn, BSTEventSource<MenuOpenCloseEvent> *src) override
	{
		_MESSAGE("%s %s", evn->menuName, (evn->opening ? "open" : "close"));

		UIStringHolder *holder = UIStringHolder::GetSingleton();
		if (evn->menuName != holder->console)
			return kEvent_Continue;

		if (evn->opening)
		{
			MenuManager *mm = MenuManager::GetSingleton();
			IMenu *menu = mm->GetMenu(holder->inventoryMenu);
			if (menu)
			{
				InventoryMenu *invMenu = static_cast<InventoryMenu*>(menu);

				StandardItemData *itemData = invMenu->inventoryData->GetSelectedItemData();
				_MESSAGE("itemData = %p %s", itemData, GetObjectClassName(itemData));
				if (itemData)
				{
					_MESSAGE("itemName = %s", itemData->GetName());
					_MESSAGE("objDesc  = %p", itemData->objDesc);
					if (itemData->objDesc)
					{
						BSSimpleList<BaseExtraList*> *list = itemData->objDesc->extraList;
						_MESSAGE("  formID = %p", itemData->objDesc->baseForm->formID);
						_MESSAGE("  count  = %d", itemData->objDesc->countDelta);
						_MESSAGE("  extra  = %p", list);
						if (list)
						{
							for (BaseExtraList *ex : *list)
							{
								_MESSAGE("    extraList %p", ex);
								for (BSExtraData *data : *ex)
								{
									_MESSAGE("      %p [%s]", data, GetObjectClassName(data));
								}
							}
						}
					}
					_MESSAGE("08 0C    = %p %p", itemData->unk08, itemData->pad0C);
				}
			}
		}
		else
		{
			TESObjectREFR *ref = Console::GetPickedReference();
			if (ref)
			{
				DumpContainer(ref);
			}
		}

		return kEvent_Continue;
	}

	virtual void OnModLoaded() override
	{
	}

	static void DumpContainer(TESObjectREFR *ref)
	{
		_MESSAGE("%08X %02X [%s]", ref->formID, ref->baseForm->formType, ref->GetReferenceName());

		TESContainer *container = ref->GetContainer();
		if (container)
		{
			TESContainer::Entry *entry;
			UInt32 idx = 0;
			while (container->GetContainerItemAt(idx++, entry))
			{
				TESForm *item = entry->form;
				if (item->Is(FormType::LeveledItem))
				{
					_MESSAGE("  %08X LeveledItem", item->formID);
				}
				else
				{
					bool bPlayable = item->IsPlayable();
					TESFullName *name = DYNAMIC_CAST<TESFullName*>(item);
					_MESSAGE("  %08X [%s] count=%d playable=%d", item->formID, name->GetFullName(), entry->count, bPlayable);
				}
			}
		}

		if (ref->extraData.HasType<ExtraContainerChanges>())
		{
			ExtraContainerChanges *exChanges = ref->extraData.GetByType<ExtraContainerChanges>();
			InventoryChanges *changes = exChanges ? exChanges->changes : nullptr;

			if (changes && changes->entryList)
			{
				for (InventoryEntryData *data : *changes->entryList)
				{
					TESForm *item = data->baseForm;

					bool bPlayable = item->IsPlayable();
					TESFullName *name = DYNAMIC_CAST<TESFullName*>(item);
					_MESSAGE("  - %08X [%s] %p count=%d playable=%d", item->formID, name->GetFullName(), data, data->countDelta, bPlayable);

					if (!data->extraList)
					{
						_MESSAGE("      extraList - not found");
						continue;
					}

					for (BaseExtraList *extraList : *data->extraList)
					{
						_MESSAGE("      extraList - %p", extraList);
						for (BSExtraData *extraData : *extraList)
						{
							const char *className = GetObjectClassName(extraData);
							if (extraData->GetType() == ExtraCount::kExtraTypeID)
								_MESSAGE("        %02X %s (%d)", extraData->GetType(), className, ((ExtraCount*)extraData)->count);
							else
								_MESSAGE("        %02X %s", extraData->GetType(), className);
						}
					}
				}
			}

			if (changes)
			{
				_MESSAGE("  * %d %d", changes->unk10, changes->unk11);
			}
		}

		_MESSAGE("| extraData");
		for (BSExtraData *extraData : ref->extraData)
		{
			_MESSAGE("|   %02X %p %s", extraData->GetType(), extraData, GetObjectClassName(extraData));
		}
	}

} thePlugin;
