#pragma once

#include "../BSCore/BSFixedString.h"
#include "UIMessage.h"

class BSString;

/*==============================================================================
class BSTMessageQueue<class UIMessage *> +0000 (_vtbl=0110DF4C)
0000: class BSTMessageQueue<class UIMessage *>
==============================================================================*/
// 04
template <typename T>
class BSTMessageQueue
{
public:
	BSTMessageQueue();
	virtual ~BSTMessageQueue();

	virtual bool	Push(T * obj) = 0;		// pure, add (loop until lock taken, call Fn05)
	virtual bool	TryPush(T * obj) = 0;	// pure, try add (try to take lock, return false if already taken, else call Fn05)
	virtual bool	Pop(T * obj) = 0;		// pure, remove (loop until lock taken, call Fn06)
	virtual bool	TryPop(T * obj) = 0;	// pure, try remove (try to take lock, return false if already taken, else call Fn06)

											//void	** _vtbl;	// 00
};

// 08
template <typename T>
class BSTCommonMessageQueue : public BSTMessageQueue <T>
{
protected:
	// @add
	virtual bool	PushInternal(T * obj) = 0;	// pure
	virtual bool	PopInternal(T * obj) = 0;	// pure

public:
	volatile long	lock;	// 04
};

/*==============================================================================
class BSTCommonScrapHeapMessageQueue<struct BSPackedTask> +0000 (_vtbl=010CDF80)
0000: class BSTCommonScrapHeapMessageQueue<struct BSPackedTask>
0000: |   class BSTCommonMessageQueue<struct BSPackedTask>
0000: |   |   class BSTMessageQueue<struct BSPackedTask>
==============================================================================*/
template <typename T>
class BSTCommonScrapHeapMessageQueue : public BSTCommonMessageQueue<T>
{
public:
	BSTCommonScrapHeapMessageQueue();
	virtual ~BSTCommonScrapHeapMessageQueue();

	// @override
	virtual bool	Push(T * obj) override;
	virtual bool	TryPush(T * obj) override;
	virtual bool	Pop(T * obj) override;
	virtual bool	TryPop(T * obj) override;
	virtual bool	PushInternal(T * obj) override;
	virtual bool	PopInternal(T * obj) override;

	UInt32 unk08;	// 08
	UInt32 unk0C;	// 0C
	UInt32 unk10;	// 10
};

/*==============================================================================
class BSTCommonStaticMessageQueue<class UIMessage *,100> +0000 (_vtbl=0110DF78)
0000: class BSTCommonStaticMessageQueue<class UIMessage *,100>
0000: |   class BSTCommonMessageQueue<class UIMessage *>
0000: |   |   class BSTMessageQueue<class UIMessage *>
==============================================================================*/
// 08 + sizeof(T) * T_len + 0C
template <typename T, std::size_t SIZE>
class BSTCommonStaticMessageQueue : public BSTCommonMessageQueue <T>
{
public:
	// @override
	virtual bool	Push(T * obj) override;
	virtual bool	TryPush(T * obj) override;
	virtual bool	Pop(T * obj) override;
	virtual bool	TryPop(T * obj) override;
	virtual bool	PushInternal(T * obj) override;
	virtual bool	PopInternal(T * obj) override;

	// @members
	T		data[SIZE];		// 008
	UInt32	numEntries;		// 198 - offsets are for <UIMessage *, 100>
	UInt32	writePtr;		// 19C
	UInt32	readPtr;		// 1A0
};


// 1C8
// 5CC - pool added in 1.2 or 1.3
class UIManager
{
public:
	enum
	{
		kPoolSize = 0x40,
	};

	typedef BSTCommonStaticMessageQueue <UIMessage *, 100>	MessageQueue;

	static UIManager *	GetSingleton(void)
	{
		return *((UIManager **)0x012E35E4);
	}

	// this takes ownership of the message ptr
	//	DEFINE_MEMBER_FN(AddMessage, void, 0x004503E0, UIMessage * msg);	// old 1.1 implementation
	// 1.3 uses a little non-thread-safe pool of UIMessages to wrap around the nicely thread-safe BSTMessageQueue it gets added to
	void AddMessage(const BSFixedString & strData, UInt32 msgID, IUIMessageData * pData) {
		AddMessage_Impl(strData, msgID, pData);
	}

	IUIMessageData * CreateMessageData(const BSFixedString &name) {
		return CreateMessageData_Impl(name);
	}

	static void AddBSUIMessage(const BSFixedString &menuName, UInt32 msgID, const BSFixedString &cmd)
	{
		typedef void(*Fn)(const BSFixedString &menuName, UInt32 msgID, const BSFixedString &cmd);
		const Fn fn = (Fn)0x00A5E650;

		fn(menuName, msgID, cmd);
	}

	// @members
	UInt32			unk000;							// 000
	MessageQueue	messages;						// 004
	UInt32			pad1A8[(0x1C8 - 0x1A8) / 4];	// 1A8
	UInt32			poolUsed;						// 1C8
	UIMessage		messagePool[kPoolSize];			// 1CC

private:
	DEFINE_MEMBER_FN(AddMessage_Impl, void, 0x00431B00, const BSFixedString & strData, UInt32 msgID, IUIMessageData * pData);

	DEFINE_MEMBER_FN(Unk_00A5C2D0, void, 0x00A5C2D0, const BSFixedString &menuName, UInt32 arg2);
	DEFINE_MEMBER_FN(CreateMessageData_Impl, IUIMessageData *, 0x00A5C300, const BSFixedString &name);
};
