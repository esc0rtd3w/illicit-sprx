#ifndef __WEATHER_H
#define __WEATHER_H



#include "hashes.h"
#include "hud.h"
#include "messages.h"
#include "misc.h"
#include "natives.h"

using namespace Hashes;
using namespace Hud;
using namespace Keyboard;
using namespace Misc;
using namespace Natives;


namespace Weather_f
{
	/*
	const char* weatherBlizzard = "Blizzard";
	const char* weatherClear = "Clear";
	const char* weatherClearing = "Clearing";
	const char* weatherClouds = "Clouds";
	const char* weatherExtraSunny = "ExtraSunny";
	const char* weatherFoggy = "Foggy";
	const char* weatherNeutral = "Neutral";
	const char* weatherOvercast = "Overcast";
	const char* weatherRain = "Rain";
	const char* weatherThunderStorm = "Thunder";
	const char* weatherSmog = "Smog";
	const char* weatherSnow = "Snow";
	const char* weatherLightSnow = "SnowLight";
	const char* weatherChristmas = "Xmas";
	*/


	// Show In Game Date and Time
	bool showWorldDateTimeT = false;
	void ShowDateTime(int dummy)
	{
		showWorldDateTimeT = !showWorldDateTimeT;
		showWorldDateTime = showWorldDateTimeT;
	}
		

	void SetTimeScaleFast(int dummy)
	{
		SET_TIME_SCALE(9999.999);
	}

	void SetTimeScaleSlow(int dummy)
	{
		SET_TIME_SCALE(9.999);
	}


	void AdvanceTime(int dummy)
	{
		ADD_TO_CLOCK_TIME(1, 0, 0);
	}
		

	// Toggle Freeze Time
	bool timeFrozen = false;
	void ToggleFreezeTime(int dummy)
	{
		timeFrozen = !timeFrozen;
		PAUSE_CLOCK(timeFrozen);
		//isTimeFrozen = timeFrozen;
		PrintText(timeFrozen ? "~r~Time Not Frozen" : "~g~Time Frozen" , 3000);
	}


	void ChangeWeather(int weather)
	{
		//bool isWeatherLoopedT = false;

		/*
		if (weather == 99) 
		{ 
			isWeatherLoopedT = !isWeatherLoopedT;
			isWeatherLooped = isWeatherLoopedT;
		}
		*/

		if (weather == 0) 
		{ 
			SET_RANDOM_WEATHER_TYPE();
		}
			

		//const char* weatherType;

		if (weather == 1) { SET_OVERRIDE_WEATHER("Blizzard"); }
		if (weather == 2) { SET_OVERRIDE_WEATHER("Xmas"); }// Christmas on Menu
		if (weather == 3) { SET_OVERRIDE_WEATHER("Clear"); }
		if (weather == 4) { SET_OVERRIDE_WEATHER("Clearing"); }
		if (weather == 5) { SET_OVERRIDE_WEATHER("Clouds"); }
		if (weather == 6) { SET_OVERRIDE_WEATHER("ExtraSunny"); }
		if (weather == 7) { SET_OVERRIDE_WEATHER("Foggy"); }
		if (weather == 8) { SET_OVERRIDE_WEATHER("SnowLight"); }// Light Snow on Menu
		if (weather == 9) { SET_OVERRIDE_WEATHER("Neutral"); }
		if (weather == 10) { SET_OVERRIDE_WEATHER("Overcast"); }
		if (weather == 11) { SET_OVERRIDE_WEATHER("Rain"); }
		if (weather == 12) { SET_OVERRIDE_WEATHER("Smog"); }
		if (weather == 13) { SET_OVERRIDE_WEATHER("Snow"); }
		if (weather == 14) { SET_OVERRIDE_WEATHER("Thunder"); }

		/*
		if (persistance == true)
		{
			SET_WEATHER_TYPE_PERSIST(weatherType);
		}

		else
		{
			SET_OVERRIDE_WEATHER(weatherType);
		}
		*/

	}
		
	/*
	void SetWeatherPersist(int dummy)
	{
		SET_WEATHER_TYPE_PERSIST(weatherType);
	}
	*/

	void ClearWeatherPersist(int dummy)
	{
		CLEAR_OVERRIDE_WEATHER();
		CLEAR_WEATHER_TYPE_PERSIST();
	}
	
};






#endif


