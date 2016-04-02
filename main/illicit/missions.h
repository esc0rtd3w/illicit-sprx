#ifndef __MISSIONS_
#define __MISSIONS_


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



// Missions
namespace Missions_f
{
		
	void GetMissionFlag(int dummy)
	{
			
		bool isMission = GET_MISSION_FLAG();
		if (isMission)
		{
			PrintText("~w~Mission ~g~Active", 3000);
		}

		else
		{
			PrintText("~w~Mission ~r~Not Active", 3000);
		}
	}

	/*
	void SetMissionFlag(int dummy)
	{
			
		bool endMission = IS_MISSION_COMPLETE_PLAYING();
		if (!endMission)
		{
				
			SET_MISSION_FLAG(true);
			//endMission == false;
			PrintText("~g~Mission Active", 3000);
		}

		else
		{
			SET_MISSION_FLAG(false);
			//endMission == true;
			PrintText("~r~Mission Not Active", 3000);
		}
	}
	*/

	/*
	void ForceMissionComplete(int dummy)
	{
		//IS_MISSION_COMPLETE_PLAYING();
		SET_MISSION_FLAG(false);
		NETWORK_SET_MISSION_FINISHED();
		CLEAR_PED_TASKS(PlayerSelf());
		CLEAR_PED_SECONDARY_TASK(PlayerSelf());
		CLEAR_PED_TASKS_IMMEDIATELY(PlayerSelf());
		PrintText("~g~Mission Forcefully Ended", 3000);
	}
	*/

};


#endif


