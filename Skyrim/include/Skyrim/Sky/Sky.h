#pragma once

class NiNode;
class TESWeather;
class TESClimate;
class TESRegion;
class Atmosphere;
class Stars;
class Sun;
class Clouds;
class Moon;
class Precipitation;

/*==============================================================================
class Sky +0000 (_vtbl=010A81BC)
0000: class Sky
==============================================================================*/
// 238
class Sky
{
public:
	virtual ~Sky();						// 010A81BC

	static Sky* GetSingleton() {
		return (Sky*)0x01B1160C;
	}
	
	void ReleaseOverride();				// 0x005939C0

	DEFINE_MEMBER_FN_const(FindWeather, TESWeather*, 0x009180E0, UInt32);

private:
	DEFINE_MEMBER_FN(ctor, Sky*, 0x005939C0);
	DEFINE_MEMBER_FN_const(IsSnowing, bool, 0x00504350);

	// members
	//void			** _vtbl			// 00 - 010A81BC
	void			* unk04;			// 04 - BSMultiBoundNode
	NiNode			* unk08;			// 08
	UInt32			unk0C;				// 0C
	UInt32			unk10;				// 10
	UInt32			unk14;				// 14
	UInt32			unk18;				// 18
	UInt32			unk1C;				// 1C
	UInt32			unk20;				// 20
	UInt32			unk24;				// 24
	TESClimate		* climate;			// 28
	TESWeather		* curentWeather;	// 2C - Weather.GetCurrentWeather()
	TESWeather		* outgoingWeather;	// 30 - Weather.GetOutgoingWeather()
	UInt32			unk34;				// 34
	UInt32			unk38;				// 38
	TESRegion		* region;			// 3C
	Atmosphere		* atmosphere;		// 40
	Stars			* stars;			// 44
	Sun				* sun;				// 48
	Clouds			* clouds;			// 4C
	Moon			* masser;			// 50
	Moon			* secunda;			// 54
	Precipitation	* precipitation;	// 58
	float			unk5C[6];			// 5C
	UInt32			unk74[3];			// 74
	float			unk80[6];			// 80
	UInt32			unk98[6];			// 98
	float			unkB0[9];			// B0
	UInt32			unkD4[6];			// D4
	float			unkEC[9];			// EC
	UInt32			unk110[9];			// 110
	float			unk134[7];			// 134
	UInt32			unk150[3];			// 150
	float			unk15C[4];			// 15C
	float			unk16C;				// 16C - Weather.GetCurrentWeatherTransition()
	UInt32			skyMode;			// 170 - Weather.GetSkyMode()
	void			* unk174;			// 174
	UInt32			unk178[3];			// 178
	float			unk184;				// 184
	UInt32			unk188;				// 188
	UInt32			unk18C;				// 18C
	UInt32			unk190[4];			// 190

	float			unk1A0[(0x210 - 0x1A0) >> 2];	// 1A0
	void			* skyEffectController;			// 210
	UInt32			unk214[(0x238 - 0x214) >> 2];	// 214
};
STATIC_ASSERT(sizeof(Sky) == 0x238);
