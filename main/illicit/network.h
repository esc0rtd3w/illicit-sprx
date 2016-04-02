#ifndef __NETWORK_H
#define __NETWORK_H



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



namespace Network_f
{
	// Start New Online Session
	void StartNewOnlineSession(int dummy)
	{
		isCloudAvailable = NETWORK_IS_CLOUD_AVAILABLE();

		if (isCloudAvailable == 1)
		{
			NETWORK_DO_TRANSITION_TO_FREEMODE(0, 1, true, 16);
			PrintText("~w~Forcing New ~b~Online Session ~w~To Start", 3000);
		}
		else
		{
			PrintText("~w~PSN Network Is Currently ~r~Not Active", 3000);
		}
	}

	/*
	// Check How Many Online Players
	void CheckNumberOfPlayers(int dummy)
	{
		char message[64];
		sprintf(message, "~y~Number of Online Players: %i", PlayerCount());
		PrintText(message, 3000);
	}
	*/
	
	/*
	// Check Host of Network Game
	bool isHost(const char* str1, const char* str2)
	{

		if (strcmp(str1, str2) == 0)
			return true;
	}
	*/
	
	/*
	void GetHostOfScript(int dummy)
	{
		isHostNowInt = NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0);
		isHostNowAny = NETWORK_GET_HOST_OF_THIS_SCRIPT();
		//if (isHostNowInt && isHostNowAny == PlayerSelf())
		if (isHostNowInt == PlayerSelf())
		{
			PrintText("You Are Host", 3000);
		}
		else
		{
			char txtHost[64];
			sprintf(txtHost, "Player %i Is Host\nPlayer %i Is Host", isHostNow, isHostNowAny);
			PrintText(txtHost, 3000);
		}
	}
	*/

	/*
	void GetHostOfThisScript(int dummy)
	{
		NETWORK_GET_HOST_OF_THIS_SCRIPT();
	}
	*/


	// Kick Player if Host
	void NetworkKickPlayer(int SelectedPlayer)
	{
		NETWORK_SESSION_KICK_PLAYER(SelectedPlayer);
	}
	
	// Check if Cloud (PSN) is Available
	void NetworkIsCloudAvailable(int dummy)
	{
		isCloudAvailable = NETWORK_IS_CLOUD_AVAILABLE();
		//isNetworkSignedOnline = NETWORK_IS_SIGNED_ONLINE();
		char* cloudStatusText;
		if (isCloudAvailable == 1){ cloudStatusText = "~g~Active"; }
		if (isCloudAvailable == 0){ cloudStatusText = "~r~Not Active"; }
		char cloudTemp[32];
		sprintf(cloudTemp, "~w~PSN Network Is Currently %s", cloudStatusText);
		PrintText(cloudTemp, 3000);
	}


	// This Skips Online Prologue
	void NetworkEndTutorialSession(int dummy)
	{
		NETWORK_END_TUTORIAL_SESSION();
		PrintText("~y~Skipping Online Tutorial", 3000);
	}
	

	// Goes back to story mode
	void NetworkSessionLeaveSinglePlayer(int dummy)
	{
		NETWORK_SESSION_LEAVE_SINGLE_PLAYER();
		PrintText("~y~Leaving Network Session\n\n~b~Loading Single Player Mode", 3000);
	}
	

	void NetworkSetMissionFinished(int dummy)
	{
		SET_MISSION_FLAG(false);
		NETWORK_SET_MISSION_FINISHED();
	}


	void NetworkSessionHostSinglePlayer(int SelectedPlayer)
	{
		NETWORK_SESSION_HOST_SINGLE_PLAYER(SelectedPlayer);
	}

	/*
	void NetworkLeaveTransition(int dummy)
	{
		NETWORK_LEAVE_TRANSITION();
	}
	*/

	/*
	void NetworkBailTransition(int dummy)
	{
		NETWORK_BAIL_TRANSITION();
	}
	*/

	/*
	void NetworkLaunchTransition(int dummy)
	{
		NETWORK_LAUNCH_TRANSITION();
	}
	*/
	
	/*
	void NetworkShowProfileUi(int SelectedPlayer)
	{
		Any* player = 0;
		NETWORK_SHOW_PROFILE_UI(player);
	}
	*/
	

	void NetworkSetOverrideSpectatorMode(int SelectedPlayer)
	{
		return NETWORK_SET_OVERRIDE_SPECTATOR_MODE(true);
	}
	
	/*
	void NetworkSetFriendlyFireOption(int SelectedPlayer)
	{
		return NETWORK_SET_FRIENDLY_FIRE_OPTION(true);
	}
	*/
	
		
	bool IsNetworkPlayerActive(int SelectedPlayer)
	{
		return NETWORK_IS_PLAYER_ACTIVE(SelectedPlayer);
	}


	void NetworkOverrideClockTime(int dummy)
	{
		NETWORK_OVERRIDE_CLOCK_TIME(12, 12, 12);
	}


	// Get Host
	//if (NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == PLAYER_ID())
	//{
    
	//}
	
	
	// Show Talking Players
	bool isNetworkPlayerTalkingT = false;
	void ToggleTalkingPlayers(int SelectedPlayer)
	{
		isNetworkPlayerTalkingT = !isNetworkPlayerTalkingT;
		isNetworkPlayerTalking = isNetworkPlayerTalkingT;
		MsgToggleDefault("Show Talking Players", isNetworkPlayerTalkingT);
	}
	
	
	// Punish Talking Players Loop
	bool punishTalkingPlayersT = false;
	void PunishTalkingPlayersLoop(int type)
	{
		talkingPunishment = type;

		punishTalkingPlayersT = !punishTalkingPlayersT;
		punishTalkingPlayers = punishTalkingPlayersT;
		MsgToggleDefault("Punish Talking Players", punishTalkingPlayersT);
		

	}

	
	// Punish Talking Players
	void PunishTalkingPlayers(int type)
	{
		talkingPunishment = type;

		for(int i = 0; i < PlayerCount(); i++)
		{
			if (i > 0 && i != PlayerSelf())
			{
				if (NETWORK_IS_PLAYER_TALKING(i) == 1)
				{
					switch(talkingPunishment)
					{
						case 1:
							explosionType = 36;
							ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(GET_PLAYER_PED(i), 1), explosionType, 0.5f, true, false, 5.0f);
							break;
						case 2:
							explosionType = 29;
							ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(GET_PLAYER_PED(i), 1), explosionType, 0.5f, true, false, 5.0f);
							break;
						case 3:
							explosionType = 24;
							ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(GET_PLAYER_PED(i), 1), explosionType, 0.5f, true, false, 5.0f);
							break;
						case 4:
							explosionType = 19;
							ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(GET_PLAYER_PED(i), 1), explosionType, 0.5f, true, false, 5.0f);
							break;
						case 5:
							GetRandomCoords();
							SET_ENTITY_COORDS(GET_PLAYER_PED(i), globalRandomCoords, 1, 0, 0, 1);
							break;
						case 6:
							explosionType = 38;
							ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(GET_PLAYER_PED(i), 1), explosionType, 0.5f, true, false, 5.0f);
							break;
						case 7:
							explosionType = 13;
							ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(GET_PLAYER_PED(i), 1), explosionType, 0.5f, true, false, 5.0f);
							break;
						case 8:
							explosionType = 22;
							ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(GET_PLAYER_PED(i), 1), explosionType, 0.5f, true, false, 5.0f);
							break;
						case 9:
							explosionType = 3;
							ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(GET_PLAYER_PED(i), 1), explosionType, 0.5f, true, false, 5.0f);
							break;
					}

					char buffer[64];
					sprintf(buffer, "Punishing %s", GET_PLAYER_NAME(i));
					PrintText(buffer, 3000);
				}
			}
		}

	}
	

	// Stats
	
	/*
	// Network Stats
	bool isDebugNetworkActiveT = false;
	void ToggleStatsNetwork(int toggle)
	{
		isDebugNetworkActiveT = !isDebugNetworkActiveT;
		isDebugNetworkActive = isDebugNetworkActiveT;
	}
	*/


};






#endif


