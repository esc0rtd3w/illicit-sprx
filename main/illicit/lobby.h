#ifndef __LOBBY_H
#define __LOBBY_H


#include "hud.h"
#include "natives.h"
#include "weapons.h"

using namespace Hud;
using namespace Natives;
using namespace Weapons_f;


namespace Lobby_f
{

	// Give Lobby Weapons
	void GiveLobbyAllWeapons(int lobby)
	{
		for(int i = 0; i < PlayerCount(); i++)
		{
			if (i >= 0 && i != PlayerSelf())
			{
				WeaponsGiveAll(GET_PLAYER_PED(i));
				//PrintText("~g~Giving ALL Weapons To ~b~Lobby\n~y~DO NOT PUSH ANY BUTTONS!!!", 5000);
				sleep(250);
			}
		}
	}

	// Take Lobby Weapons
	void TakeLobbyAllWeapons(int lobby)
	{
		for(int i = 0; i < PlayerCount(); i++)
		{
			if (i >= 0 && i != PlayerSelf())
			{
				REMOVE_ALL_PED_WEAPONS(GET_PLAYER_PED(i));
				//PrintText("~r~Removing ALL Weapons From ~b~Lobby\n~y~DO NOT PUSH ANY BUTTONS!!!", 5000);
				sleep(250);
			}
		}
	}

	// Clear Lobby Tasks
	void ClearLobbyTasks(int lobby)
	{
		for(int i = 0; i < PlayerCount(); i++)
		{
			if (i >= 0 && i != PlayerSelf())
			{
				CLEAR_PED_TASKS_IMMEDIATELY(GET_PLAYER_PED(i));
			}
		}
	}

	// Freeze lobby
	bool isFreezeLobbyT = false;
	void FreezeLobby(int lobby)
	{
		isFreezeLobbyT = !isFreezeLobbyT;
		isFreezeLobby = isFreezeLobbyT;
		MsgToggleDefault("Frozen Lobby", isFreezeLobbyT);
	}

	// Teleport To Talking Player
	bool isTeleportToTalkingT = false;
	void TeleportToTalkingPlayer(int dummy)
	{
		isTeleportToTalkingT = !isTeleportToTalkingT;
		isTeleportToTalking = isTeleportToTalkingT;
	}
	
	
	// Clone All Lobby Players
	void CloneLobby(int dummy)
	{
		for(int i = 0; i < PlayerCount(); i++)
		{
			if (i >= 0 && i != PlayerSelf())
			{
				Ped lclone_ = CLONE_PED(GET_PLAYER_PED(i), GET_ENTITY_HEADING(GET_PLAYER_PED(i)), 1, 1);
				Ped* lclone = &lclone_;
				SET_ENTITY_AS_NO_LONGER_NEEDED(lclone);
			}
		}
	}


	bool isLobbyExplodeT = false;
	void ExplodeAllPlayers(int dummy)
	{
		isLobbyExplodeT = !isLobbyExplodeT;
		isLobbyExplode = isLobbyExplodeT;
	}


	/*
	// Get Player Names
	char* playerNames[15];
	void GetPlayerNames(int playerList)
	{
		for (int player = 0; player <=15; player++)
		{
			char* playerNames = GET_PLAYER_NAME(player);
			
			char namesTemp[128];
			sprintf(namesTemp, "~y~%s", playerNames);
			PrintText(namesTemp, 3000);
		}
	}
	*/


	/*
	// Toggle Freeze All Players
	bool allPlayersFrozen = false;
	void ToggleFreezeAllPlayers(int dummy)
	{
		allPlayersFrozen = !allPlayersFrozen;

		for (int player=0; player <= 15; player++)
		{
			FREEZE_ENTITY_POSITION(GET_PLAYER_PED(player), allPlayersFrozen);
		}
		PrintText(allPlayersFrozen ? "~g~All Players Frozen" : "~r~All Players Not Frozen" , 3000);
	}
	*/
	
	// Clear props from all players
	bool clearLobbyPropsT = false;
	void ClearLobbyProps(int SelectedPlayer)
	{
		clearLobbyPropsT = !clearLobbyPropsT;
		clearLobbyProps = clearLobbyPropsT;
		MsgToggleDefault("Lobby Clear Props", clearLobbyPropsT);

		/*
		for (int i = 0; i < 16 ;i++)
		{
			if (i > 0 && i != PLAYER_PED_ID())
			{
				CLEAR_ALL_PED_PROPS(GET_PLAYER_PED(i));
			}
		}
		*/
	}

	/*
	bool allPlayersFrozenT = false;
	void ToggleFreezeAllPlayers(int dummy)
	{
		allPlayersFrozenT = !allPlayersFrozenT;
		allPlayersFrozen = allPlayersFrozenT;
		MsgToggleDefault("Lobby Tasks", allPlayersFrozenT);
	}
	*/
	
	bool isMoneySpawningOnLobbyT = false;
	void ToggleMoneyAllPlayers(int dummy)
	{
		// Disabling Lobby money spawn
		isMoneySpawningOnPlayer = false;

		isMoneySpawningOnLobbyT = !isMoneySpawningOnLobbyT;
		isMoneySpawningOnLobby = isMoneySpawningOnLobbyT;
		MsgToggleDefault("Lobby Money Spawn", isMoneySpawningOnLobbyT);
	}

	bool isTalkingPlayerGettingMoneyT = false;
	void ToggleMoneyTalkingPlayers(int dummy)
	{
		isTalkingPlayerGettingMoneyT = !isTalkingPlayerGettingMoneyT;
		isTalkingPlayerGettingMoney = isTalkingPlayerGettingMoneyT;
		MsgToggleDefault("Talking Player Money Spawn", isTalkingPlayerGettingMoneyT);
	}

	
	/*
	// OLD FULL AND DEMO MONEY DROP 20151113
	bool isMoneySpawningOnLobbyT = false;
	void ToggleMoneyAllPlayers(int dummy)
	{
		if (!demoMode && notDemo && !notActivated)
		{
			// Disabling Lobby money spawn
			isMoneySpawningOnPlayer = false;

			isMoneySpawningOnLobbyT = !isMoneySpawningOnLobbyT;
			isMoneySpawningOnLobby = isMoneySpawningOnLobbyT;
			MsgToggleDefault("Lobby Money Spawn", isMoneySpawningOnLobbyT);
		}

		// DEMO ONLY
		// Single Tap Drop
		else
		{
			isMoneySpawningOnLobby = false;

			for (int i = 0; i <= PlayerCount() ;i++)
			{
				if (i >= 0 && i != PlayerID())
				{
					int hashProp = GET_HASH_KEY("prop_money_bag_01");
					int hashPickup = GET_HASH_KEY("PICKUP_MONEY_CASE");
					float* coords = Vec3toFloat(GET_ENTITY_COORDS(GET_PLAYER_PED(i),true));

					REQUEST_MODEL(hashProp);
					if (HAS_MODEL_LOADED(hashProp) == 1)
					{
						CREATE_AMBIENT_PICKUP(hashPickup, coords, 0, 40000, hashProp, 0, 1);
						SET_MODEL_AS_NO_LONGER_NEEDED(hashProp);
					}
				}
			}

			MsgDefault("~r~Lobby Money Loop Not Available In DEMO!", 3000);
			
		}
	}

	bool isTalkingPlayerGettingMoneyT = false;
	void ToggleMoneyTalkingPlayers(int dummy)
	{
		if (!demoMode && notDemo && !notActivated)
		{
			isTalkingPlayerGettingMoneyT = !isTalkingPlayerGettingMoneyT;
			isTalkingPlayerGettingMoney = isTalkingPlayerGettingMoneyT;
			MsgToggleDefault("Talking Player Money Spawn", isTalkingPlayerGettingMoneyT);
		}

		// DEMO ONLY
		else
		{
			isMoneySpawningOnLobby = false;
			isTalkingPlayerGettingMoney = false;
			MsgDefault("~r~Talking Player Money Loop Not Available In DEMO!", 3000);
			
		}
	}
	*/


	/*
	// Apply Damage To Lobby
	bool applyDamageToLobbyT = false;
	void ApplyDamageToLobby(int dummy)
	{
		applyDamageToLobbyT = !applyDamageToLobbyT;
		applyDamageToLobby = applyDamageToLobbyT;
	}
	*/

	// Teleport Lobby
	void TeleportLobbyToMe(int dummy)
	{
		requestLobbyTeleport = true;
	}

	// Kick Lobby
	void KickLobbyFromGame(int dummy)
	{
		requestLobbyKick = true;
	}

	/*
	// Send Lobby Text Message
	void SendLobbyText(int dummy)
	{
		for (int i = 0; i <= PlayerCount() ;i++)
			{
				if (i >= 0 && i != PlayerID())
				{
					int _player = GET_PLAYER_PED(i);
					int* player = &_player;
					NETWORK_SEND_TEXT_MESSAGE(networkText, player);
				}
			}
	}
	*/

	/*
	void ExplodePedHead(int SelectedPlayer)
	{
		EXPLODE_PED_HEAD(PlayerSelf(), Hashes::Hashes_Weapons_Explosions::GRENADE);
	}
	*/

	/*
	void HelicopterHead(Player)
	{
		Vector3 boneCoord = somePed.GetBoneCoord(Bone.SKEL_Head);
		SET_DRAW_ORIGIN, boneCoordX, boneCoordY, boneCoordZ, 0);
		DRAW_SPRITE, "helicopterhud", "hud_corner", -0.01, -0.015, 0.013, 0.013, 0.0, 255, 0, 0, 200;
		DRAW_SPRITE, "helicopterhud", "hud_corner", 0.01, -0.015, 0.013, 0.013, 90.0, 255, 0, 0, 200;
		DRAW_SPRITE, "helicopterhud", "hud_corner", -0.01, 0.015, 0.013, 0.013, 270.0, 255, 0, 0, 200;
		DRAW_SPRITE, "helicopterhud", "hud_corner", 0.01, 0.015, 0.013, 0.013, 180.0, 255, 0, 0, 200;
		CLEAR_DRAW_ORIGIN;
	}
	*/

};

#endif

