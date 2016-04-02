#ifndef __HUD_GAME_
#define __HUD_GAME_


#include "hashes.h"
#include "hud.h"
#include "licensing.h"
#include "messages.h"
#include "misc.h"
#include "natives.h"

using namespace Dialog;
using namespace Hashes;
using namespace Hud;
using namespace Keyboard;
using namespace Licensing;
using namespace Misc;
using namespace Natives;


namespace Hud_f
{
	/*
	// New Waypoint
	void SetNewWaypoint(int dummy)
	{
		SET_NEW_WAYPOINT(0.00, 0.00);
	}
	*/

	/*
	// Clear Waypoint
	void ClearWaypoint(int dummy)
	{
		SET_WAYPOINT_OFF();
	}
	*/

	// Toggle HUD
	bool hudState = true;
	void ToggleHud(int dummy)
	{
		hudState = !hudState;
		DISPLAY_HUD(hudState);
		MsgToggleReverse("HUD Visibility", hudState);
		//PrintText(hudState ? "~r~HUD Hidden" : "~g~HUD Visible" , 3000);
	}


	// Toggle Radar
	bool radarState = false;
	void ToggleRadar(int dummy)
	{
		radarState = !radarState;
		DISPLAY_RADAR(radarState);
		TOGGLE_STEALTH_RADAR(radarState);
		//IS_RADAR_HIDDEN();
		MsgToggleDefault("Radar Visibility", radarState);
		//PrintText(radarState ? "~g~Radar Visible" : "~r~Radar Hidden" , 3000);
	}
};



#endif


