#pragma once

#include "../BSCore/BSTSingleton.h"
#include "../BSCore/BSTEvent.h"
#include "../BSDevices/InputManager.h"

struct BSMusicEvent
{
};

/*==============================================================================
class MoviePlayer +0000 (_vtbl=0118E024)
0000: class MoviePlayer
==============================================================================*/
class MoviePlayer
{
public:
	virtual ~MoviePlayer();				// 00F50280	
	virtual void	 Unk_01(void);		// 00F51EE8 (pure)
	virtual void	 Unk_02(void);		// 00F51EE8 (pure)
	virtual void	 Unk_03(void);		// 00F51EE8 (pure)
	virtual void	 Unk_04(void);		// 00F51EE8 (pure)
	virtual void	 Unk_05(void);		// 00F51EE8 (pure)
	virtual void	 Unk_06(void);		// 00F51EE8 (pure)
	virtual void	 Unk_07(void);		// 00F51EE8 (pure)
	virtual void	 Unk_08(void);		// 00F51EE8 (pure)
	virtual void	 Unk_09(void);		// 00F51EE8 (pure)
	virtual void	 Unk_0A(void);		// 00F51EE8 (pure)
	virtual void	 Unk_0B(void);		// 00F51EE8 (pure)
	virtual void	 Unk_0C(void);		// 00F51EE8 (pure)
	virtual void	 Unk_0D(void);		// 00F51EE8 (pure)
	virtual void	 Unk_0E(void);		// 00F4F2C0

};


/*==============================================================================
class BGSMoviePlayer +0000 (_vtbl=010CD524)
0000: class BGSMoviePlayer
0000: |   class MoviePlayer
0034: |   class BSTEventSource<struct BSMusicEvent>
0030: |   class BSTEventSink<class InputEvent *>
=============================================================================*/
class BGSMoviePlayer : public MoviePlayer,
	public BSTEventSource<BSMusicEvent>,
	public BSTEventSink<InputEvent *>
{
public:
	virtual ~BGSMoviePlayer();					// 0068C940

	virtual void	Unk_01(void) override;		// 0068C700
	virtual void	Unk_02(void) override;		// 0068C750
	virtual void	Unk_03(void) override;		// 0068C880
	virtual void	Unk_04(void) override;		// 0068C8B0
	virtual void	Unk_05(void) override;		// 006C50E0 { return; }
	virtual void	Unk_06(void) override;		// 006C50E0 { return; }
	virtual void	Unk_07(void) override;		// 0068C6A0
	virtual void	Unk_08(void) override;		// 0068C6B0
	virtual void	Unk_09(void) override;		// 0068C6D0
	virtual void	Unk_0A(void) override;		// 0068C5E0
	virtual void	Unk_0B(void) override;		// 0068C5F0
	virtual void	Unk_0C(void) override;		// 0068C6F0
	virtual void	Unk_0D(void) override;		// 0068C600
	virtual void	Unk_0E(void) override;		// 0068C610
};		/*==============================================================================
class BSMusicManager +0000 (_vtbl=011B1F4C)
0000: class BSMusicManager
0004: |   struct BSTSingletonSDM<class BSMusicManager,struct BSTSingletonSDMOpStaticBuffer>
0004: |   |   struct BSTSingletonSDMBase<struct BSTSDMTraits<class BSMusicManager,struct BSTSingletonSDMOpStaticBuffer<class BSMusicManager> > >
0004: |   |   |   struct BSTSDMTraits<class BSMusicManager,struct BSTSingletonSDMOpStaticBuffer<class BSMusicManager> >
0005: |   |   |   struct BSTSingletonSDMOpStaticBuffer<class BSMusicManager>
0000: |   class BSTEventSink<struct BSMusicEvent>
==============================================================================*/
class BSMusicManager : public BSTSingletonSDM<BSMusicManager>,
	public BSTEventSink<BSMusicEvent>		// 00
{
public:
	virtual ~BSMusicManager();			// 00401180

	virtual EventResult	ReceiveEvent(BSMusicEvent *evn, BSTEventSource<BSMusicEvent> *source) override;		// 00FC2BB0
};
