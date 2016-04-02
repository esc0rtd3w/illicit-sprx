#ifndef __PLAYER_H
#define __PLAYER_H


//#include "anti.h"
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



namespace PlayerSelf_f
{
		
	void ChangePlayerName(int name)
	{
		NameChanged = true;
				
		if (name == 0) 
		{ 
			//ToggleKeyboard();
			//newName = oskResult;
		}

		//if (name == 1) { newName = ""; }
		//if (name == 2) { newName = ""; }
		//if (name == 3) { newName = ""; }

		/*
		if (name == 4) 
		{ 
			newName = ""; 
		}
		*/

		if (name == 5) { newName = "iLLiCiT"; }
		if (name == 6) { newName = "               "; }
		if (name == 7) { newName = "**Invalid**"; }
		if (name == 8) { newName = "Rockstar"; }
		if (name == 9) { newName = "Rockstar Games"; }
		if (name == 10) { newName = "Rockstar North"; }
		if (name == 11) { newName = "Sony Moderator"; }
		if (name == 12) { newName = "ps3dg.com"; }

		//1.25
		//strncpy((char*)0x01FF248C, newName, strlen(newName));
		//*(char*)(0x01FF248C+strlen(newName)) = 0;

		//1.25/1.26
		strncpy((char*)0x41143344, newName, strlen(newName));
		*(char*)(0x41143344+strlen(newName)) = 0;
		
		//1.26
		strncpy((char*)0x2002550, newName, strlen(newName));
		*(char*)(0x2002550+strlen(newName)) = 0;
		
		char nameText[128];
		sprintf(nameText, "~b~Player Name Updated!\nNew Name: ~y~%s\n~b~Join A New Lobby For Others To See", newName);
		PrintText(nameText, 3000);
	}

	void DevModeDirect(int toggle)
	{
		WriteMemoryDirect(0x3E30B4, 0x01);
		PrintText("Dev Mode ~g~Enabled", 3000);
	}

	/*
	void GodModeDirect(int toggle)
	{
		WriteMemoryDirect(0x118A548, 0x38);
		WriteMemoryDirect(0x118A548, 0x60);
		WriteMemoryDirect(0x118A548, 0x7F);
		WriteMemoryDirect(0x118A548, 0xB0);
		WriteMemoryDirect(0x118A548, 0x00);
		WriteMemoryDirect(0x118A548, 0xB4);
	}
	*/

	/*
	void WantedLevelDirect(int toggle)
	{
		WriteMemoryDirect(0x1041FE0, 0x39);
		WriteMemoryDirect(0x1041FE0, 0x60);
		WriteMemoryDirect(0x1041FE0, 0x00);
		WriteMemoryDirect(0x1041FE0, 0x00);
	}
	*/

	/*
	// Get Info On Target Entity Aimed At
	bool isAimedTargetActiveT = false;
	void GetAimedEntity(int dummy)
	{
		isAimedTargetActiveT = !isAimedTargetActiveT;
		isAimedTargetActive = isAimedTargetActiveT;
		MsgToggleDefault("Get Aimed Target Info", isAimedTargetActiveT);
	}
	*/
		

	/*
	// Color Name Changer Loop Toggle
	bool isColorNameChangeT = false;
	void ChangeNameMultiColor(int dummy)
	{
		isColorNameChangeT = !isColorNameChangeT;
		isColorNameChange = isColorNameChangeT;
		MsgToggleDefault("Multi Color Name", isColorNameChangeT);
	}
	*/
		
		
	/*
	// Boss Mode
	bool isTargeted;
	bool isTargetting;
	void BossMode(int SelectedPlayer)
	{

		int currentPlayer = PlayerSelf();

		for (int deadguy = 0; deadguy <= 15; deadguy++)
		{
			isTargeted = IS_PLAYER_FREE_AIMING_AT_ENTITY(currentPlayer, deadguy);
			isTargetting = IS_PLAYER_TARGETTING_ANYTHING(deadguy);

			if (isTargeted || isTargetting)
			{
				ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(GET_PLAYER_PED(deadguy), true), 29, 0.5f, true, false, 5.0f);
			}
		}

		//GET_AIMED_ENTITY(GetPlayerPedID(SelectedPlayer), GetPlayerPedID(SelectedPlayer));
		unk_0x74D42C03(currentPlayer, 100.0f);
	}
	*/


	/*
	bool particleFxEntityActiveT = false;
	void ParticleTestEntity(int SelectedPlayer)
	{
		particleFxEntityActiveT = !particleFxEntityActiveT;
		particleFxEntityActive = particleFxEntityActiveT;
	}
		
	bool particleFxCoordsActiveT = false;
	void ParticleTestCoords(int SelectedPlayer)
	{
		particleFxCoordsActiveT = !particleFxCoordsActiveT;
		particleFxCoordsActive = particleFxCoordsActiveT;
	}
	*/

		

	/*
	void ShowCoordsHeading(int dummy)
	{
		char coordsTemp[64];
		sprintf(coordsTemp, "~w~Coords: ~y~%i\n~w~Heading: ~y~%i", GetEntityCoordsFloat(0), GetEntityHeadingFloat(0));
		PrintText(coordsTemp, 3000);
	}
	*/

	// Show Coords In Loop
	bool isShowCoordsActiveT = false;
	void ShowCoordsXYZ(int dummy)
	{
		isShowCoordsActiveT = !isShowCoordsActiveT;
		isShowCoordsActive = isShowCoordsActiveT;
	}
		

	// Fire Feet
	bool isFireFeetActiveT = false;
	void FireFeet(int SelectedPlayer)
	{
		if (isPlayerGodmodeActive && !playerGodmode)
		{
			isFireFeetActiveT = !isFireFeetActiveT;
			isFireFeetActive = isFireFeetActiveT;

			MsgToggleDefault("FireFeet", isFireFeetActiveT);
		}
		else
		{
			PrintText("~w~Wearing FireFeet Without ~b~Godmode ~w~Is ~r~Dangerous!", 3000);
		}
	}


	// Toggle Mobile Radio 
	bool playerMobileRadio = false;
	void ToggleMobileRadio(int SelectedPlayer)
	{
		playerMobileRadio = !playerMobileRadio;
		int station = irand(0, 17);
		SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(playerMobileRadio);
		SET_USER_RADIO_CONTROL_ENABLED(playerMobileRadio);
		SET_FRONTEND_RADIO_ACTIVE(playerMobileRadio);
		SET_RADIO_TO_STATION_INDEX(station);
		MsgToggleDefault("Mobile Radio", playerMobileRadio);
	}


	// Toggle Heatvision 
	bool playerHeatVision = false;
	void ToggleHeatVision(int toggle)
	{
		playerHeatVision = !playerHeatVision;
		SET_SEETHROUGH(playerHeatVision);
		MsgToggleDefault("Heatvision", playerHeatVision);
	}


	// Toggle Nightvision 
	bool playerNightvision = false;
	void ToggleNightvision(int toggle)
	{
		playerNightvision = !playerNightvision;
		SET_NIGHTVISION(playerNightvision);
		//MsgToggleDefault("Nightvision", playerNightvision);
		MsgToggleDefault("Nightvision", playerNightvision);
	}
	


	// Toggle Godmode 
	bool playerGodmode = false;
	void ToggleGodMode(int SelectedPlayer)
	{
		if (playerGodmode = !playerGodmode)
		{
			uint currentPlayerU = PLAYER_ID(SelectedPlayer);
			int currentPlayer = GetPlayerPedID(SelectedPlayer);

			SET_ENTITY_INVINCIBLE(currentPlayerU, true);
			SET_ENTITY_PROOFS(PlayerSelf(), true, true, true, true, true, true, true, true);
			SET_PED_DIES_IN_VEHICLE(currentPlayer, false);
			SET_PED_DIES_IN_WATER(currentPlayer, false);
			SET_PED_DIES_IN_SINKING_VEHICLE(currentPlayer, false);
			SET_ENTITY_CAN_BE_DAMAGED(currentPlayer, false);
		
			SET_PLAYER_INVINCIBLE(currentPlayerU, true);
			SET_PED_CAN_RAGDOLL(currentPlayer, false);
			SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(currentPlayer, false);
			SET_PLAYER_INVINCIBLE(currentPlayer, true);		
			SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(currentPlayer, false);
			GIVE_PLAYER_RAGDOLL_CONTROL(currentPlayer, false);
			SET_PED_RAGDOLL_ON_COLLISION(currentPlayer, false);
			playerGodmode = true;
			//playerRagdoll = false;
			isPlayerGodmodeActive = true;
		}

		else
		{
			uint currentPlayerU = PLAYER_ID(SelectedPlayer);
			int currentPlayer = GetPlayerPedID(SelectedPlayer);

			SET_ENTITY_INVINCIBLE(currentPlayerU, false);
			SET_ENTITY_PROOFS(currentPlayer, false, false, false, false, false, false, false, false);
			SET_PLAYER_INVINCIBLE(currentPlayerU, true);
			SET_PED_DIES_IN_VEHICLE(currentPlayer, true);
			SET_PED_DIES_IN_WATER(currentPlayer, true);
			SET_PED_DIES_IN_SINKING_VEHICLE(currentPlayer, true);
			SET_ENTITY_CAN_BE_DAMAGED(currentPlayer, true);
		
			SET_PED_CAN_RAGDOLL(currentPlayer, true);
			SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(currentPlayer, true);
			SET_PLAYER_INVINCIBLE(currentPlayer, true);		
			SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(currentPlayer, true);
			GIVE_PLAYER_RAGDOLL_CONTROL(currentPlayer, true);
			SET_PED_RAGDOLL_ON_COLLISION(currentPlayer, true);
			playerGodmode = false;
			//playerRagdoll = true;
			isPlayerGodmodeActive = false;
		}
			
		MsgToggleDefault("Godmode", playerGodmode);
		//PrintText(playerGodmode ? "~g~Godmode Enabled" : "~r~Godmode Disabled" , 3000);
	}



	// Toggle Wanted Level
	bool isWantedLevelOnT = false;
	void ToggleWantedLevel(int SelectedPlayer)
	{
		// Wanted Level
		if (isWantedLevelOnT)
		{
			//int currentPlayer = GetPlayerPedID(SelectedPlayer);
			int currentPlayer = PlayerSelf();

			// Wanted By Police Address 1.25
			//*(char*)(0x103D780, 1);
			CLEAR_PLAYER_WANTED_LEVEL();
			SET_MAX_WANTED_LEVEL(5);
			//FLASH_WANTED_DISPLAY(true);
			SET_POLICE_IGNORE_PLAYER(currentPlayer, false);
			SET_PLAYER_WANTED_LEVEL(currentPlayer, 5, false);
			SET_PLAYER_WANTED_LEVEL_NOW(currentPlayer, false);
			isWantedLevelOnT = false;
		}
	
		else
		{
			//int currentPlayer = GetPlayerPedID(SelectedPlayer);
			int currentPlayer = PlayerSelf();

			CLEAR_PLAYER_WANTED_LEVEL();
			SET_MAX_WANTED_LEVEL(0);
			//FLASH_WANTED_DISPLAY(false);
			SET_POLICE_IGNORE_PLAYER(currentPlayer, true);
			SET_PLAYER_WANTED_LEVEL(currentPlayer, 0, false);
			SET_PLAYER_WANTED_LEVEL_NOW(currentPlayer, false);
			CLEAR_PLAYER_WANTED_LEVEL();
			isWantedLevelOnT = true;
		}

		//isWantedLevelOnT = !isWantedLevelOnT;
		//isWantedLevelOn = isWantedLevelOnT;
		//MsgToggleReverse("Wanted Level", isWantedLevelOnT);
		PrintText(isWantedLevelOnT ? "~r~Wanted Level Off\n~y~Kill Cop To Activate" : "~g~Wanted Level On" , 3000);
	}

	
	// Give Max Health and Armor
	void GiveMaxHealthArmor(int SelectedPlayer)
	{
		int currentPlayer = PlayerSelf();

		// Max Health and Armor
		int maxHealth = GET_ENTITY_MAX_HEALTH(currentPlayer);
		SET_ENTITY_HEALTH(currentPlayer, maxHealth);
		SET_PED_ARMOUR(currentPlayer, 100);

		MsgDefault("Max ~g~Health ~w~and ~b~Armor", 3000);
	}
	

	// Toggle Invisibility 
	bool playerVisible = true;
	void ToggleInvisiblePlayer(int SelectedPlayer)
	{
		//int alpha;
		playerVisible = !playerVisible;
		//if (playerVisible) { alpha = 0; }
		//if (!playerVisible) { alpha = 255; }
		SET_ENTITY_VISIBLE(PlayerSelf(), playerVisible);
		//SET_ENTITY_ALPHA(GetPlayerPedID(SelectedPlayer), alpha, playerVisible);
		MsgToggleReverse("Invisibility", playerVisible);
	}

	
	// Toggle Super Jump 
	bool isSuperJumpActiveT = false;
	void ToggleSuperJump(int SelectedPlayer)
	{
		isSuperJumpActiveT = !isSuperJumpActiveT;
		isSuperJumpActive = isSuperJumpActiveT;
		MsgToggleDefault("Super Jump", isSuperJumpActiveT);
	}

	
	// Toggle Super Run 
	bool isSuperRunActiveT = false;
	void ToggleSuperRun(int dummy)
	{
		isSuperRunActiveT = !isSuperRunActiveT;
		isSuperRunActive = isSuperRunActiveT;
		MsgToggleDefault("Super Run", isSuperRunActiveT);
	}
	

	/*
	// Is Player On A Train
	void IsPlayerRidingTrain(int dummy)
	{
		bool isPlayerOnATrain = IS_PLAYER_RIDING_TRAIN();
		char buffer[32];
		sprintf(buffer, "%s", isPlayerOnATrain);
		PrintText(buffer, 3000);
	}
	*/

	/*	
	// Toggle Super Swim 
	bool isSuperSwimActiveT = false;
	void ToggleSuperSwim(int dummy)
	{
		isSuperSwimActiveT = !isSuperSwimActiveT;
		isSuperSwimActive = isSuperSwimActiveT;
		MsgToggleDefault("Super Swim", isSuperSwimActiveT);
	}
	*/

	// Destroy Phone
	void DestroyPhone(int phone)
	{
		DESTROY_MOBILE_PHONE();
		//PrintText("~r~Mobile Phone Closed", 3000);
	}

	// Phone Options 
	void CreatePhone(int phone)
	{
		//DestroyPhone(0);
		//sleep(50);
		SET_MOBILE_PHONE_SCALE(450);
		SET_MOBILE_PHONE_POSITION(70, 30, 2);
		CREATE_MOBILE_PHONE(phone);
		//PrintText("~g~Mobile Phone Opened", 3000);
	}

	void UsePhone(int phone)
	{
		//DestroyPhone(0);
		//sleep(50);
		SET_MOBILE_PHONE_SCALE(450);
		SET_MOBILE_PHONE_POSITION(70, 30, 2);
		CREATE_MOBILE_PHONE(phone);
		TASK_USE_MOBILE_PHONE(PlayerSelf(), 1);
		//PrintText("~b~Using Mobile Phone", 3000);
	}

	/*
	void GetPhoneInfo(int phone)
	{
		char inUse = IS_MOBILE_PHONE_CALL_ONGOING();
		//GET_MOBILE_PHONE_POSITION(0);
		//GET_MOBILE_PHONE_ROTATION(0);
		char msgPhone[32];
		sprintf(msgPhone, "~y~Ongoing Phone Call: %s", inUse); 
		PrintText(msgPhone, 3000);
	}
	*/

		
	/*
	// Toggle Ped Is Drunk 
	bool pedIsDrunk = false;
	void ToggleDrunk(int SelectedPlayer)
	{
		if (pedIsDrunk == false)
		{
			SET_PED_IS_DRUNK(PlayerSelf(), true);
			SET_TIMECYCLE_MODIFIER("Drunk");
			pedIsDrunk = true;
			//PrintText("~r~You Are Drunk", 3000);
		}

		else
		{
			SET_PED_IS_DRUNK(PlayerSelf(), false);
			CLEAR_TIMECYCLE_MODIFIER();
			pedIsDrunk = false;
			//PrintText("~g~You Are Not Drunk", 3000);
		}
	}

			
	// Toggle Ped Is High 
	bool pedIsHigh = false;
	void ToggleHigh(int SelectedPlayer)
	{
		if (pedIsHigh == false)
		{
			SET_PED_IS_DRUNK(PlayerSelf(), true);
			SET_TIMECYCLE_MODIFIER("DRUG_gas_huffin");
			pedIsHigh = true;
			//PrintText("~r~You Are High", 3000);
		}

		else
		{
			SET_PED_IS_DRUNK(PlayerSelf(), false);
			CLEAR_TIMECYCLE_MODIFIER();
			pedIsHigh = false;
			//PrintText("~g~You Are Not High", 3000);
		}
	}
	*/
		
	
	/*
	void SetPlayersLastVehicle(int dummy)
	{
		GetCurrentVehicle(PlayerSelf());
		SET_PLAYERS_LAST_VEHICLE(0);
	}
	*/


	/*
	void LastVehicleManager(int dummy)
	{
		char tmp[256];
		sprintf(tmp, "%i");
		PrintText(tmp, 3000);
	}
	*/

		
	// Activate Sky Diving 
	void ActivateSkyDive(int SelectedPlayer)
	{
		TASK_SKY_DIVE(PlayerSelf());
		//PrintText("~g~Sky Diving Enabled", 3000);
	}
			
	/*
	bool playerLongFallBoots = false;
	void ToggleLongFallBoots(int dummy)
	{
		playerLongFallBoots = !playerLongFallBoots;
		SET_ENTITY_PROOFS(PlayerSelf(), true, true, true, true, true, true, true, true);
		//PrintText(playerLongFallBoots ? "~g~Long Fall Boots Enabled" : "~r~Long Fall Boots Disabled" , 3000);
	}
	*/

	/*
	// Toggle Tennis Mode 
	bool isPlayingTennis = false;
	void ToggleTennisMode(int dummy)
	{
		isPlayingTennis = !isPlayingTennis;
		ENABLE_TENNIS_MODE(PlayerSelf(), isPlayingTennis, isPlayingTennis);
		//PrintText(isPlayingTennis ? "~g~Tennis Mode Enabled" : "~r~Tennis Mode Disabled" , 3000);
	}
	*/

	// Parachute Stuff

	/*
	void RequestParachuteModel(int dummy)
	{
		REQUEST_PLAYER_PARACHUTE_MODEL(PlayerSelf(), 0x73268708);
	}
	*/

	/*
	// Parachute Smoke
	bool isParachuteSmokeEnabledT = false;
	void ToggleParachuteSmoke(int dummy)
	{
		isParachuteSmokeEnabledT = !isParachuteSmokeEnabledT;
		isParachuteSmokeEnabled = isParachuteSmokeEnabledT;
		 
		if (isParachuteSmokeEnabledT) 
		{
			REQUEST_PLAYER_PARACHUTE_MODEL(PlayerSelf(), 0x73268708);
		}

		MsgToggleDefault("Parachute Smoke", isParachuteSmokeEnabledT);
	}
	*/

	/*
	// Get parachute state
	void GetParachuteState(int dummy)
	{
		int parachuteState = GET_PED_PARACHUTE_STATE(PlayerSelf());

		switch (parachuteState)
		{
			case -1: PrintText("No Parachute", 2000);
				break;
			case 0: PrintText("Parachute On Back", 2000);
				break;
			case 1: PrintText("Parachute Opening", 2000);
				break;
			case 2: PrintText("Parachute Open", 2000);
				break;
			case 3: PrintText("Falling To Your Death", 2000);
				break;
		}
	}
	*/
		
	/*
	bool canPedDieInVehicle = true;
	void TogglePedCanDieInVehicle(int dummy)
	{
		canPedDieInVehicle = !canPedDieInVehicle;
		SET_PED_DIES_IN_VEHICLE(PlayerSelf(), canPedDieInVehicle);
		PrintText(canPedDieInVehicle ? "~g~Ped Cannot Die In Vehicle" : "~r~Ped Can Die In Vehicle", 3000);
	}
	*/
		

	// Extend Water Time
	void ExtendPedWaterTime(int dummy)
	{
		SET_PED_MAX_TIME_IN_WATER(PlayerSelf(), 9999);
		SET_PED_MAX_TIME_UNDERWATER(PlayerSelf(), 9999);
		PrintText("~g~Water Time Extended", 3000);
	}
		
	/*
	void PedMaxTimeInWater(int dummy)
	{
		SET_PED_MAX_TIME_IN_WATER(PlayerSelf(), 9999);
	}
	*/

	/*
	void PedMaxTimeUnderWater(int dummy)
	{
		SET_PED_MAX_TIME_UNDERWATER(PlayerSelf(), 9999);
	}
	*/


};




#endif






