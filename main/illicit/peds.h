#ifndef __EMPTY_H
#define __EMPTY_H



//#include "anti.h"
#include "hud.h"
//#include "menu.h"
#include "misc.h"
#include "natives.h"

using namespace Hud;
//using namespace Menu_f;
using namespace Misc;
using namespace Natives;


namespace Peds_f
{
	
	// Get current player
	char* GetNetPlayerName(int CurrentPlayerNum)
	{

		bool active = NETWORK_IS_PLAYER_ACTIVE(GET_PLAYER_PED(CurrentPlayerNum));
		if (active)
		{

			return GET_PLAYER_NAME(CurrentPlayerNum);

			//PrintText(GET_PLAYER_NAME(CurrentPlayerNum), 1500);


			bool SignedIn = NETWORK_IS_SIGNED_IN();
			if (SignedIn)
			{
				
				return GET_PLAYER_NAME(CurrentPlayerNum);

				//PrintText(GET_PLAYER_NAME(CurrentPlayerNum), 1500);
			}

			if (!SignedIn)
			{
				//char NameNew[64];
				//sprintf(NameNew, "%s / ~b~ID: ~w~%i", GET_PLAYER_NAME(CurrentPlayerNum), CurrentPlayerNum);
				//return NameNew;
				return GET_PLAYER_NAME(CurrentPlayerNum);

				//PrintText(GET_PLAYER_NAME(CurrentPlayerNum), 1500);
			}
		}
		
		if (!active)
		{
			//isUpdatePlayersMenu = true;
			return GET_PLAYER_NAME(CurrentPlayerNum);
			//return "-";
			//Menu_f::UpdatePlayersMenu();
		}

		else
		{
			//isUpdatePlayersMenu = true;
			return "-";
		}

		//return GET_PLAYER_NAME(CurrentPlayerNum);

		//PrintText(GET_PLAYER_NAME(CurrentPlayerNum), 1500);
	}


	// Player Stats
	bool isDebugPlayersActiveT = false;
	void ToggleStatsPlayers(int toggle)
	{
		isDebugPlayersActiveT = !isDebugPlayersActiveT;
		isDebugPlayersActive = isDebugPlayersActiveT;
	}
	
	

	// Get Entity Model
	void GetPlayerInfo(int SelectedPlayer)
	{
		char* playerName = GET_PLAYER_NAME(SelectedPlayer);
		Hash playerModel = GET_ENTITY_MODEL(GET_PLAYER_PED(SelectedPlayer));
		char buffer[64];
		sprintf(buffer, "~b~%s ~w~Has Model Hash: ~y~%i", playerName, playerModel);
		PrintText(buffer, 3000);
	}

	// Player Select For Money Drop
	void MoneyPlayerAdjust(int selected)
	{
		PlayerSelected = selected;
	}


	// Teleport To Player
	void TeleportToPlayer(int SelectedPlayer)
	{
		// If Player is not in a vehicle, just teleport Player to target
		if (!IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			SET_ENTITY_COORDS(PlayerSelf(), GetPedCoordsFloat(SelectedPlayer), 1, 0, 0, 1);
		}
		// If Player is in a vehicle, teleport the vehicle to target
		else
		{
			Ped currentVehicle = GetCurrentVehicle(PlayerSelf());
			SET_ENTITY_COORDS(currentVehicle, GetPedCoordsFloat(SelectedPlayer), 1, 0, 0, 1);
		}

		
		// If Target player is in a vehicle and Player is not in a vehicle, teleport into target vehicle
		if (IS_PED_IN_ANY_VEHICLE(GetPlayerPedID(SelectedPlayer), true) && !IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			int currentPedVehicle = GET_VEHICLE_PED_IS_USING(GetPlayerPedID(SelectedPlayer));
			SET_PED_INTO_VEHICLE(PlayerSelf(), currentPedVehicle, getFreeSeat(currentPedVehicle));
		}

	}

	
	// Explode Player
	void ExplodePlayer(int SelectedPlayer)
	{
		Vec3 coords = GetEntityCoordsVec3(GET_PLAYER_PED(SelectedPlayer));
		//ADD_EXPLOSION(coords.x, coords.y, coords.z, 3, 0.34f, false, false, 0.42f);
		//ADD_EXPLOSION_ALT(&GetEntityCoordsVec3(GET_PLAYER_PED(SelectedPlayer)), 29, 0.5f, true, false, 5.0f);
		ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(GET_PLAYER_PED(SelectedPlayer), 1), explosionType, 0.5f, true, false, 5.0f);
	}

	/*
	// Owned Explosion Player
	void ExplodePlayerOwned(int SelectedPlayer)
	{
		//ADD_OWNED_EXPLOSION(playerPed, playerPos, 29, 0.5f, true, false, 5.0f);
	}
	*/

	/*
	// Explode Player Custom
	void ExplodePlayerCustom(int Type)
	{
		explosionType = 29;
		ADD_EXPLOSION_ALT(&GetEntityCoordsVec3(GET_PLAYER_PED(PlayerSelected)), explosionType, 0.5f, true, false, 5.0f);
	}
	*/
	
	// Set Player on Fire
	bool isPlayerOnFireT = false;
	void TogglePlayerOnFire(int SelectedPlayer)
	{
		isPlayerOnFireT = !isPlayerOnFireT;
		isPlayerOnFire = isPlayerOnFireT;
		//PlayerSelected = SelectedPlayer;
	}

	void SilentSnipe(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);

		explosionType = 38;
		ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(player, 1), explosionType, 0.1f, false, false, 0.0f);
	}

	/*
	void GetEntityCoordsFloat(int dummy)
	{
		char coordsTemp[64];
		sprintf(coordsTemp, "~b~Player Coords: ~y~%i", GetCoordsFromWorld(0));
		PrintText(coordsTemp, 3000);
	}
	*/


	// Toggle Ragdoll Effect
	//bool playerRagdoll = IS_PED_RUNNING_RAGDOLL_TASK(playerRagdoll);
	bool playerRagdoll = true;
	void ToggleRagdoll(int SelectedPlayer)
	{
		if (playerRagdoll == true)
		{
			SET_PED_CAN_RAGDOLL(GetPlayerPedID(SelectedPlayer), false);
			SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(GetPlayerPedID(SelectedPlayer), false);			
			SET_PLAYER_INVINCIBLE(GetPlayerPedID(SelectedPlayer), true);		
			SET_ENTITY_INVINCIBLE(GetPlayerPedID(SelectedPlayer), true);
			SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(GetPlayerPedID(SelectedPlayer), false);
			GIVE_PLAYER_RAGDOLL_CONTROL(GetPlayerPedID(SelectedPlayer), false);
			SET_PED_RAGDOLL_ON_COLLISION(GetPlayerPedID(SelectedPlayer), false);
			playerRagdoll = false;
			PrintText("~r~Ragdoll Off", 3000);
		}
		else
		{
			SET_PED_CAN_RAGDOLL(GetPlayerPedID(SelectedPlayer), true);
			SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(GetPlayerPedID(SelectedPlayer), true);			
			SET_PLAYER_INVINCIBLE(GetPlayerPedID(SelectedPlayer), false);		
			SET_ENTITY_INVINCIBLE(GetPlayerPedID(SelectedPlayer), false);
			SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(GetPlayerPedID(SelectedPlayer), true);
			GIVE_PLAYER_RAGDOLL_CONTROL(GetPlayerPedID(SelectedPlayer), true);
			SET_PED_RAGDOLL_ON_COLLISION(GetPlayerPedID(SelectedPlayer), true);
			playerRagdoll = true;
			PrintText("~g~Ragdoll On", 3000);
		}

	}
	
	void SlingshotPed(int SelectedPlayer)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		Ped currentVehicle = GetCurrentVehicle(player);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			APPLY_FORCE(currentVehicle, 80, 60, 100, 0, 0, 0);
		}
		else
		{
			APPLY_FORCE(player, 80, 60, 100, 0, 0, 0);
		}
	}


	// Fly Mode
	bool isFlyModeActiveT = false;
	void ToggleFlyMode(int toggle)
	{
		flyActiveNow = isFlyModeActiveT;
		isFlyModeActiveT = !isFlyModeActiveT;
		isFlyModeActive = isFlyModeActiveT;
		MsgToggleDefault("Fly Mode", isFlyModeActiveT);
	}


	// Cower In Fear
	void PedCowerInFear(int SelectedPlayer)
	{
		TASK_COWER(GetPlayerPedID(SelectedPlayer), 9999);
	}

	// Give Max Armor
	void GiveMaxArmor(int SelectedPlayer)
	{
		SET_PED_ARMOUR(GetPlayerPedID(SelectedPlayer), 100);
	}

	// Give Max Health
	void GiveMaxHealth(int SelectedPlayer)
	{
		int maxHealth = GET_ENTITY_MAX_HEALTH(GetPlayerPedID(SelectedPlayer));
		SET_ENTITY_HEALTH(GetPlayerPedID(SelectedPlayer), maxHealth);
	}


	// Attach an object to a player
	void AttachObjectToPed(int SelectedPlayer)
	{
		if (numberOfSpawnedObjects <= maxObjectSpawn)
		{
			uint attachObjHash = GET_HASH_KEY("Prop_inflategate_01");
			//uint attachObjHash = GET_HASH_KEY("prop_mp_cone_01");
			if (IS_MODEL_VALID(attachObjHash)) 
			{
				REQUEST_MODEL(attachObjHash);
				if (HAS_MODEL_LOADED(attachObjHash))
				{
					int player = GET_PLAYER_PED(PlayerSelected);
					//float heading = GET_ENTITY_HEADING(player);
					Vec3 playerCoords = GET_ENTITY_COORDS(PlayerSelf(), true);
					Object object = CREATE_OBJECT(attachObjHash, playerCoords.x, playerCoords.y, playerCoords.z, 0, 0, 1);
				
					objectFollow = object;

					float xyz[3] = { 0.0, 0.0, 0.0 };
					float xyz_rotation[3] = { 0.0, 0.0, 0.0 };
		
					ATTACH_ENTITY_TO_ENTITY_ALT(object, player, 0, xyz, xyz_rotation, 0, 0, 0, 0, 0, 0);

					//SET_ENTITY_HEADING(object, heading);
					
					spawnedObjectList[numberOfSpawnedObjects] = object;

					//Object o = CREATE_OBJECT(attachhash, GET_ENTITY_COORDS(GetPlayerPedID(SelectedPlayer), true).x, GET_ENTITY_COORDS(GetPlayerPedID(SelectedPlayer), true).y, GET_ENTITY_COORDS(GetPlayerPedID(SelectedPlayer), true).z, 1, 1, 1);
					//ATTACH_ENTITY_TO_ENTITY(object, GetPlayerPedID(SelectedPlayer), Head, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false, false, false, false, 2, true);
				}
			}
		}
		else
		{
			for (int i = 0; i <= 99; i++)
			{
				Object obj = spawnedObjectList[i];
				DETACH_ENTITY(obj, 1, 1);
				PrintText("~r~SPAWN LIMIT REACHED!\n~w~Deleting Old Spawned Objects\n~y~PLEASE BE PATIENT!", 3000);
				sleep(10);
			}
		}
	}

	
	bool isMoneyControlButtonsT = false;
	void MoneyButton(int button)
	{
		isMoneyControlButtonsT = !isMoneyControlButtonsT;
		isMoneyControlButtons = isMoneyControlButtonsT;
		//MsgToggleDefault("Money Button Control", isMoneyControlButtonsT);
		
		/*
		switch(button)
		{
			case 0:
				buttonNormal = Button_CROSS;
				buttonNormalName = "CROSS";
				break;
			case 1:
				buttonNormal = Button_CIRCLE;
				buttonNormalName = "CIRCLE";
				break;
			case 2:
				buttonNormal = Button_SQUARE;
				buttonNormalName = "SQUARE";
				break;
			case 3:
				buttonNormal = Button_TRIANGLE;
				buttonNormalName = "TRIANGLE";
				break;
			case 4:
				buttonNormal = Button_L1;
				buttonNormalName = "L1";
				break;
			case 5:
				buttonNormal = Button_L2;
				buttonNormalName = "L2";
				break;
			case 6:
				buttonNormal = Button_L3;
				buttonNormalName = "L3";
				break;
			case 7:
				buttonNormal = Button_R1;
				buttonNormalName = "R1";
				break;
			case 8:
				buttonNormal = Button_R2;
				buttonNormalName = "R2";
				break;
			case 9:
				buttonNormal = Button_R3;
				buttonNormalName = "R3";
				break;
			case 10:
				buttonNormal = Button_R3_Down;
				buttonNormalName = "R3 Down";
				break;
			case 11:
				buttonNormal = Dpad_Up;
				buttonNormalName = "Dpad Up";
				break;
			case 12:
				buttonNormal = Dpad_Down;
				buttonNormalName = "Dpad Down";
				break;
			case 13:
				buttonNormal = Dpad_Left;
				buttonNormalName = "Dpad Left";
				break;
			case 14:
				buttonNormal = Dpad_Right;
				buttonNormalName = "Dpad Right";
				break;
		}
		*/

		buttonNormalName = "R1";

		char buffer[100];

		if (isMoneyControlButtons)
		{
			sprintf(buffer, "~w~Money Button Control ~g~Enabled\n~w~Hold Button: ~y~%s ~w~To Use", buttonNormalName);
		}
		else
		{
			sprintf(buffer, "~w~Money Button Control ~r~Disabled");
		}

		PrintText(buffer, 3000);
	}
	
	
	
	// Attach to another player
	void AttachToPlayer(int SelectedPlayer)
	{
		//ATTACH_ENTITY_TO_ENTITY(object, PLAYER::PLAYER_PED_ID, GET_ENTITY_BONE_INDEX(hashofplayer, bonename), 0.0, -2.5, 0.85, 0.0, 0.0, 0.0, false, false, false, false, 2, true)
		//ATTACH_ENTITY_TO_ENTITY(PlayerSelf(), GetPlayerPedID(SelectedPlayer), Chest, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false, false, false, false, 2, true);
		
		int player = GET_PLAYER_PED(PlayerSelected);

		float xyz[3] = { 0.0, -0.3, 0.0 };
		float xyz_rotation[3] = { 0.0, 0.0, 0.0 };
		
		bool doesExist = DOES_ENTITY_EXIST(player);

		if (doesExist)
		{
			ATTACH_ENTITY_TO_ENTITY_ALT(PlayerSelf(), player, -1, xyz, xyz_rotation, 0, 0, 0, 0, 2, 1);
		}
	}

	void AttachToPlayerHead(int SelectedPlayer)
	{
		//int self = PlayerSelf();
		//int player = GET_PLAYER_PED(PlayerSelected);
		//Vehicle vehicle = GET_VEHICLE_PED_IS_USING(player);

		//objectModel = "prop_dog_cage_02";

		//Vec3 playerCoords = GET_ENTITY_COORDS(PlayerSelf(), true);
		//float* coords = Vec3toFloat(playerCoords);
		//Object objectSpawn = CREATE_OBJECT_ALT(GET_HASH_KEY(objectModel), coords, 0, 0, 1);

		//float xyz[3] = { 0.0, -0.3, 0.0 };
		//float xyz_rotation[3] = { 0.0, 0.0, 0.0 };
		
		//ATTACH_ENTITY_TO_ENTITY_ALT(objectSpawn, player, Head, xyz, xyz_rotation, 0, 0, 0, 0, 2, 1);


		//ATTACH_ENTITY_TO_ENTITY(PlayerSelf(), GetPlayerPedID(SelectedPlayer), Head, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false, false, false, false, 2, true);
		//AniType ani = "gestures@m@sitting@generic@casual";
		//AniState state = "gesture_bye_soft";
		//REQUEST_ANIM_DICT(ani);
		//if(HAS_ANIM_DICT_LOADED(ani))
		//TASK_PLAY_ANIM(PlayerSelf(), ani, state, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
	}

	void AttachToPlayerRightArm(int SelectedPlayer)
	{
		//ATTACH_ENTITY_TO_ENTITY(PlayerSelf(), GetPlayerPedID(SelectedPlayer), RightArm, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false, false, false, false, 2, true);
	}

	void AttachToPlayerLeftArm(int SelectedPlayer)
	{
		//ATTACH_ENTITY_TO_ENTITY(PlayerSelf(), GetPlayerPedID(SelectedPlayer), LeftArm, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false, false, false, false, 2, true);
	}
	

	// Detach From Player
	void DetachFromPlayer(int SelectedPlayer)
	{
		DETACH_ENTITY(PlayerSelf(), 1, 1);
		//CLEAR_PED_TASKS_IMMEDIATELY(PlayerSelf());
	}

	// Detach Object From Player
	void DetachObjectFromPlayer(int object)
	{

		DETACH_ENTITY(object, 1, 1);

		/*
		for (int i = 0; i <= 99; i++)
		{
			Object obj = spawnedObjectList[i];
			DETACH_ENTITY(obj, 1, 1);
			PrintText("~r~SPAWN LIMIT REACHED!\n~w~Deleting Old Spawned Objects\n~y~PLEASE BE PATIENT!", 3000);
			sleep(10);
		}
		*/
	}

	// Detach Objects From Player
	void DetachObjectsFromPlayer(int SelectedPlayer)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		DETACH_ENTITY(objectFollow, 1, 1);
		CLEAR_ALL_PED_PROPS(player);
	}

	/*
	// Check if ped is in vehicle
	void CheckIfIsPedInAnyVehicle(int SelectedPlayer)
	{
		if(IsPedInAnyVehicle(GetPlayerPedID(SelectedPlayer)))
		{
			isPedInVehicle = true;
			char pedVehicleCheck[64];
			sprintf(pedVehicleCheck, "~g~%s Is In A Vehicle\n~y~Vehicle ID: %i", NameCurrentFollow, GetCurrentVehicle(SelectedPlayer));
			PrintText(pedVehicleCheck, 3000);
		}
		else
		{
			isPedInVehicle = false;
			MsgPlayerNotInVehicle();
		}
	}
	*/

	// Show Ped Spawn Stats
	void SpawnedPedStats(int SelectedPlayer)
	{
		char spawnTmp[64];
		sprintf(spawnTmp, "~w~Peds Spawned: ~y~%i\n~w~Times Cloned: ~y~%i", numberOfSpawnedPeds, numberOfTimesCloned);
		PrintText(spawnTmp, 3000);
	}
		
		
	// Delete Ped
	void DeletePed(int SelectedPlayer)
	{
		//DELETE_PED(SelectedPlayer);
	}


	void ClonePed(int SelectedPlayer)
	{
		// Set First Time Clone Flag
		if (!firstTimeCloneHasHappened)
			{
				firstTimeCloneHasHappened = true;
			}

		// Also set Spawn Flag if Spawn Ped has not been done yet
		if (!firstTimeSpawnHasHappened)
			{
				firstTimeSpawnHasHappened = true;
			}

		Ped clone_ = CLONE_PED(GetPlayerPedID(SelectedPlayer), GET_ENTITY_HEADING(GetPlayerPedID(SelectedPlayer)), 1, 1);

		Ped* clone = &clone_;

		//SET_PED_AS_NO_LONGER_NEEDED(clone);
		SET_ENTITY_AS_NO_LONGER_NEEDED(clone);

		// Increment Counter To Keep Track of Times Cloned
		numberOfTimesCloned++;

		// Increment Counter To Keep Track of TOTAL Spawned Peds
		numberOfSpawnedPeds++;
			
		char spawnTmp[64];
		sprintf(spawnTmp, "~w~Peds Spawned: ~y~%i\n~w~Times Cloned: ~y~%i", numberOfSpawnedPeds, numberOfTimesCloned);
		PrintText(spawnTmp, 3000);
	}

	/*
	void SpawnRandomPed(int SelectedPlayer)
	{
		// Set First Time Spawn Flag
		firstTimeCloneHasHappened = true;

		Vec3 entityCoords = GET_ENTITY_COORDS(GET_PLAYER_PED(SelectedPlayer), true);
		Ped randomPed = CREATE_RANDOM_PED(entityCoords.x, entityCoords.y, entityCoords.z);
		//SET_PED_AS_NO_LONGER_NEEDED(randomPed);
		//SET_ENTITY_AS_NO_LONGER_NEEDED(randomPed);

		// Increment Counter To Keep Track of TOTAL Spawned Peds
		numberOfSpawnedPeds++;
			
		char spawnTmp[64];
		sprintf(spawnTmp, "~w~Peds Spawned: ~y~%i", numberOfSpawnedPeds);
		PrintText(spawnTmp, 3000);
	}
	*/


	/*
	void SpawnPed(const char* PedHashName)
	{
		REQUEST_MODEL(GET_HASH_KEY(PedHashName));
		if(HAS_MODEL_LOADED(GET_HASH_KEY(PedHashName)))
		CreatedPED[NumberPeds] = CREATE_PED(26, GET_HASH_KEY(PedHashName), get_entity_coords_float(PlayerSelf()), 0, 1, 0);
		NumberPeds++;
	}
	*/
		

	// Disable Ped Tasks (FREEZE PLAYER)
	bool isFreezePlayerT = false;
	void FreezePlayer(int SelectedPlayer)
	{
		isFreezePlayerT = !isFreezePlayerT;
		isFreezePlayer = isFreezePlayerT;
		MsgToggleDefault("Freeze Player", isFreezePlayerT);
	}


	/*
	// Apply Damage To Ped
	void ApplyDamageToPed(int SelectedPlayer)
	{
		APPLY_DAMAGE_TO_PED(GetPlayerPedID(SelectedPlayer), 10, true);
	}
	*/



		
		
	//-------------------------------------------------------------------------------------------
	// TOGGLES START


	/*
	// Player Cycle Test
	bool isPlayerCycleT = false;
	void TogglePlayerCycle(int toggle)
	{
		isPlayerCycleT = !isPlayerCycleT;
		isPlayerCycle = isPlayerCycleT;
		//char pcEnabled[64];
		//sprintf(pcEnabled, "~w~Cycle Through Players With\n~b~DPAD LEFT & DPAD RIGHT");
		//char pcDisabled[64];
		//sprintf(pcDisabled, "~r~Cycle Through Players Disabled");
		//PrintText(isPlayerCycleT ? pcEnabled : pcDisabled , 3000);
	}
	*/
	
	/*
	// Set Peds To Flee
	bool isPedFleeingT = false;
	void TogglePedFleeing(int SelectedPlayer)
	{
		isPedFleeingT = !isPedFleeingT;
		isPedFleeing = isPedFleeingT;
		SET_ALL_RANDOM_PEDS_FLEE(GET_PLAYER_PED(SelectedPlayer), isPedFleeingT);
		PrintText(isPedFleeingT ? "~g~Peds Are Fleeing" : "~r~Peds Are Normal" , 3000);
	}
	*/

	/*
	// Set Peds Wetness
	bool isPedWetT = false;
	void TogglePedWetness(int SelectedPlayer)
	{
		if (!isPedWetT)
			{
				SET_PED_WETNESS_HEIGHT(GetPlayerPedID(SelectedPlayer), 100);
				isPedWet = true;
				isPedWetT = true;
			}
		else
		{
			SET_PED_WETNESS_HEIGHT(GetPlayerPedID(SelectedPlayer), 0);
			CLEAR_PED_WETNESS(GetPlayerPedID(SelectedPlayer));
			isPedWet = false;
			isPedWetT = false;
		}

		MsgToggleDefault("Ped Wetness", isPedWet);
	}
	*/

	/*
	// Set Ped Is Sweating
	bool isPedSweating = false;
	void TogglePedSweat(int SelectedPlayer)
	{
		if (isPedSweating == false)
			{
				SET_PED_SWEAT(GetPlayerPedID(SelectedPlayer), 100);
				isPedSweating = true;
				//PrintText("~g~Ped Is Sweating" , 3000);
			}
		else
		{
			SET_PED_SWEAT(GetPlayerPedID(SelectedPlayer), 0);
			isPedSweating = false;
			//PrintText("~r~Ped Is Not Sweating" , 3000);
		}

		MsgToggleDefault("Ped Sweating", isPedSweating);
	}
	*/


	/*
	// Dispatch Cops To Ped
	bool areCopsDispatched = false;
	void ToggleCopDispatch(int SelectedPlayer)
	{
		areCopsDispatched = !areCopsDispatched;
		SET_DISPATCH_COPS_FOR_PLAYER(GET_PLAYER_PED(SelectedPlayer), areCopsDispatched);
		PrintText(areCopsDispatched ? "~g~Cops Have Been Dispatched" : "~r~Calling Off The Fuzz" , 3000);
	}
	*/
	

	// Toggle Entity Collision
	bool pedIsClipping = true;
	void TogglePedIsClipping(int SelectedPlayer)
	{
		pedIsClipping = !pedIsClipping;
		SET_ENTITY_COLLISION(GetPlayerPedID(SelectedPlayer), pedIsClipping, false);
		MsgToggleReverse("No Clipping", pedIsClipping);
	}
		
	/*
	// Toggle Entity Motion Blur
	bool pedIsBlurred = false;
	void TogglePedIsBlurred(int SelectedPlayer)
	{
		pedIsBlurred = !pedIsBlurred;
		SET_ENTITY_MOTION_BLUR(PlayerSelf(), pedIsBlurred);
		MsgToggleReverse("Motion Blur", pedIsBlurred);
	}
	*/

	/*
	// Toggle Ped Is A Cop
	bool pedIsCop = false;
	void TogglePedIsCop(int SelectedPlayer)
	{
		pedIsCop = !pedIsCop;
		SET_PED_AS_COP(PlayerSelf(), pedIsCop);
		PrintText(pedIsCop ? "~g~You Are The Law" : "~r~You Are A Civilian" , 3000);
	}
	*/

	
	// Toggle Ped Gravity
	bool pedGravity = true;
	void TogglePedGravity(int SelectedPlayer)
	{
		pedGravity = !pedGravity;
		SET_PED_GRAVITY(GetPlayerPedID(SelectedPlayer), pedGravity);
		SET_ENTITY_HAS_GRAVITY(GetPlayerPedID(SelectedPlayer), pedGravity);
		MsgToggleDefault("Ped Gravity", pedGravity);
	}
	

	/*
	// Toggle Ped Can Drown In Water
	bool canPedDrownInWater = true;
	void ToggleCanPedDrownInWater(int dummy)
	{
		canPedDrownInWater = !canPedDrownInWater;
		SET_PED_DIES_IN_WATER(PlayerSelf(), canPedDrownInWater);
		MsgToggleDefault("Ped Can Drown In Water", canPedDrownInWater);
	}
	*/
		
	/*
	// Toggle Ped Can Drown In Vehicle
	bool canPedDrownInVehicle = true;
	void ToggleCanPedDrownInVehicle(int dummy)
	{
		canPedDrownInVehicle = !canPedDrownInVehicle;
		SET_PED_DIES_IN_SINKING_VEHICLE(PlayerSelf(), canPedDrownInVehicle);
		MsgToggleReverse("Ped Can Drown In Vehicle", canPedDrownInVehicle);
	}
	*/


	// Bones
	/*
		------------------------------------
	Ped Bone Index	 		|
	Name		Num	Hex	|
	------------------------------------
	BONE_ROOT	0	0x0000
	Head:		31086	0x796E
	Right Wrist:	28422	0x6F06
	Left Wrist:	60309	0xEB95
	Right Hand:	57005	0xDEAD  ( lol DEAD )
	Chest:		24818	0x60F2
	Month:		39317	0x9995
	Left Wrist:	18905	0x49D9
	Left Knee:	63931	0xF9BB
	Right Knee:	36864	0x9000
	Left Shoe:	14201	0x3779
	Right Shoe:	52301	0xCC4D
	Gentils:	51826	0xCA72
	Umbilical:	11816	0x2E28
	Right Shoulder:	40269	0x9D4D
	Right Arm:	28252	0x6E5C
	Left Shoulder:	45509	0xB1C5
	Left Arm:	61163	0xEEEB

	------------------------------------
	Vehicle Bone Index 		|
	Name		Num	Hex	|
	------------------------------------
	BONE_ROOT	0	0x0000

	Example usage:
	int Head = GET_PED_BONE_INDEX(GET_PLAYER_PED(PlayerID), 31086);
	ATTACH_ENTITY_TO_ENTITY(ObjectHandle, EntityHandle, Head, 0, 0, 0, 0, 0, 0);

	Head:31086
	Right Wrist:28422
	Left Wrist:60309
	Right Hand:57005
	Chest:24818
	Month:39317
	Left Wrist:18905
	Left Knee:63931
	Right Knee:36864
	Left Shoe:14201
	Right Shoe:52301
	Vagaina:51826
	Umbilical:11816
	Right Shoulder:40269
	Right Arm:28252
	Left Shoulder:45509
	Left Arm:61163
	*/

	/*
	// Toggle Rope Attach
	bool isPedRopeAttached = false;
	void TogglePedRopeAttach(int SelectedPlayer)
	{
		//Object rope = ADD_ROPE(GetPedCoordsXYZ(SelectedPlayer).x, GetPedCoordsXYZ(SelectedPlayer).y, GetPedCoordsXYZ(SelectedPlayer).z, 0.0, 0.0, 0.0, 20.0, 4, 20.0, 1.0, 0.0, false, false, false, 5.0, false, NULL);
			
		if (!isPedRopeAttached)
		{
			//ATTACH_ROPE_TO_ENTITY(rope, GetPlayerPedID(SelectedPlayer), GetPedCoordsXYZ(SelectedPlayer).x, GetPedCoordsXYZ(SelectedPlayer).y, GetPedCoordsXYZ(SelectedPlayer).z, true);
			//ATTACH_ENTITIES_TO_ROPE(rope, GetPlayerPedID(SelectedPlayer), ClosestVehicleToPlayer(SelectedPlayer), GetPedCoordsXYZ(SelectedPlayer).x, GetPedCoordsXYZ(SelectedPlayer).y, GetPedCoordsXYZ(SelectedPlayer).z, GetVehicleCoordsVec3(SelectedPlayer).x, GetVehicleCoordsVec3(SelectedPlayer).y, GetVehicleCoordsVec3(SelectedPlayer).z, 50, true, true, 0, 0);
			//ACTIVATE_PHYSICS(rope);
			//SET_DISABLE_BREAKING(rope, true);
			isPedRopeAttached = true;
			PrintText("~g~Rope Attached To Ped", 3000);
		}

		if (isPedRopeAttached)
		{
			//DETACH_ROPE_FROM_ENTITY(rope, GetPlayerPedID(SelectedPlayer));
			//DELETE_ROPE(rope);
			isPedRopeAttached = false;
			PrintText("~r~Rope Detached From Ped", 3000);
		}
	}
	*/

	/*
	// Toggle Freeze Ped
	bool isPedFrozen = false;
	void ToggleFreezePedPosition(int SelectedPlayer)
	{
		int ped = GetPlayerPedID(SelectedPlayer);
		isPedFrozen = !isPedFrozen;

		NETWORK_REQUEST_CONTROL_OF_ENTITY(ped);
		if (NETWORK_HAS_CONTROL_OF_ENTITY(ped) == true)
		{
			FREEZE_ENTITY_POSITION(ped, isPedFrozen);
		}

		MsgToggleDefault("Ped Freeze", isPedFrozen);
	}
	*/

	/*
	// Toggle Pin Down Ped
	bool isPedPinned = false;
	void TogglePedPinDown(int SelectedPlayer)
	{
		isPedPinned = !isPedPinned;
		SET_PED_PINNED_DOWN(GetPlayerPedID(SelectedPlayer), 1, 1);
		MsgToggleDefault("Ped Pinned Down", isPedPinned);
	}
	*/

	/*
	// Toggle Ped Blood
	bool playerBleed = false;
	void TogglePedBlood(int SelectedPlayer)
	{
		int currentPlayer = PlayerSelf();

		if (playerBleed = !playerBleed)
		{
			
			//ATTACH_ENTITY_TO_ENTITY(currentPlayer, currentPlayer, Head, 0, 0, 0, 0, 0, 0);
			//SET_PARTICLE_FX_BLOOD_SCALE(true);
			//APPLY_PED_BLOOD(currentPlayer, Head, 500, 500, 500, "GUNSHOT");
			//APPLY_PED_BLOOD(currentPlayer, Chest, 500, 500, 500, "GUNSHOT");
			playerBleed = true;
		}

		else
		{
			//GET_ENTITY_ROTATION(currentPlayer, 0);
			//CLEAR_PED_BLOOD_DAMAGE(currentPlayer);
			playerBleed = false;
		}
			
		PrintText(playerBleed ? "~r~Player Is Bleeding" : "~g~Player Is Not Bleeding" , 3000);
	}
	*/
		

	// Toggle Handcuffs 
	bool playerHandcuffs = false;
	void ToggleHandcuffs(int SelectedPlayer)
	{
		if (playerHandcuffs == false)
			{
			TASK_ARREST_PED(1, GetPlayerPedID(SelectedPlayer));
			GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_HANDCUFFS, 1, 1);
			SET_ENABLE_HANDCUFFS(GetPlayerPedID(SelectedPlayer), true);
			//SET_ENABLE_BOUND_ANKLES(GetPlayerPedID(SelectedPlayer), true);
			playerHandcuffs = true;
			}
		else
		{
			UNCUFF_PED(GetPlayerPedID(SelectedPlayer));
			SET_ENABLE_HANDCUFFS(GetPlayerPedID(SelectedPlayer), false);
			//SET_ENABLE_BOUND_ANKLES(GetPlayerPedID(SelectedPlayer), false);
			GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_UNARMED, 1, 1);
			playerHandcuffs = false;
		}
		
		MsgToggleDefault("Handcuffs", playerHandcuffs);
	}

	/*
	void ArrestPed(int dummy)
	{
	TASK_ARREST_PED(1, PlayerSelf());
	GIVE_DELAYED_WEAPON_TO_PED(PlayerSelf(), Hashes_Weapons_DLC::WEAPON_HANDCUFFS, 1, 1);
	}
	*/

	/*
	void UncuffPed(int dummy)
	{
	UNCUFF_PED(PlayerSelf());
	GIVE_DELAYED_WEAPON_TO_PED(PlayerSelf(), Hashes_Weapons::WEAPON_UNARMED, 1, 1);
	}
	*/
	
	// Clear Props
	void ClearPedProps(int SelectedPlayer)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		//int player = GET_PLAYER_PED(SelectedPlayer);
		CLEAR_ALL_PED_PROPS(player);

		char buffer[64];
		sprintf(buffer, "~w~Cleared All Props From ~b~%s", GET_PLAYER_NAME(PlayerSelected));
		PrintText(buffer, 3000);
	}


	// Money Spawn Default
	bool isMoneySpawningOnPlayerT = false;
	void ToggleMoneySpawnDefault(int SelectedPlayer)
	{
		isCustomMoneySpawn = false;
		isMoneySpawningOnLobby = false;

		isMoneySpawningOnPlayerT = !isMoneySpawningOnPlayerT;
		isMoneySpawningOnPlayer = isMoneySpawningOnPlayerT;

		MsgToggleDefault("Money Toggle", isMoneySpawningOnPlayerT);
	}


	// Money Spawn Custom
	void ToggleMoneySpawnCustom(int propSelect)
	{
		isCustomMoneySpawn = true;

		switch (propSelect)
		{
			//case 0: moneySpawnProp = (char*)GetKeyboardInput(30);
			//break;
			case 1: moneySpawnProp = "prop_lawnmower_01";
			break;
			case 2: moneySpawnProp = "prop_pizza_box_01";
			break;
			case 3: moneySpawnProp = "prop_acc_guitar_01";
			break;
			case 4: moneySpawnProp = "prop_toilet_roll_01";
			break;
			case 5: moneySpawnProp = "prop_cs_dildo_01";
			break;
			case 6: moneySpawnProp = "prop_amb_40oz_02";
			break;
			case 7: moneySpawnProp = "prop_time_capsule_01";
			break;
			case 8: moneySpawnProp = "prop_ld_jerrycan_01";
			break;
			case 9: moneySpawnProp = "prop_toaster_01";
			break;
			case 10: moneySpawnProp = "prop_money_bag_01";
			break;
			case 11: moneySpawnProp = "prop_alien_egg_01";
			break;
			case 12: moneySpawnProp = "prop_car_engine_01";
			break;
			case 13: moneySpawnProp = "prop_couch_lg_02";
			break;
			case 14: moneySpawnProp = "prop_asteroid_01";
			break;
			case 15: moneySpawnProp = "prop_bskball_01";
			break;
			case 16: moneySpawnProp = "prop_sh_bong_01";
			break;
			case 17: moneySpawnProp = "prop_toilet_01";
			break;
			case 18: moneySpawnProp = "prop_poly_bag_money";
			break;
			case 19: moneySpawnProp = "prop_bowling_ball";
			break;
			case 20: moneySpawnProp = "prop_bowling_pin";
			break;
			case 21: moneySpawnProp = "prop_car_seat";
			break;
			case 22: moneySpawnProp = "prop_boombox_01";
			break;
			case 23: moneySpawnProp = "prop_parachute";
			break;
			case 24: moneySpawnProp = "prop_cs_hotdog_01";
			break;
			case 25: moneySpawnProp = "v_res_tre_pineapple";
			break;
			case 26: moneySpawnProp = "prop_mp_cone_04";
			break;
			case 27: moneySpawnProp = "id1_28_ladder01";
			break;
			case 28: moneySpawnProp = "prop_mp_cone_02";
			break;
			case 29: moneySpawnProp = "prop_mp_cone_03";
			break;
			case 30: moneySpawnProp = "prop_mp_cone_01";
			break;
			case 31: moneySpawnProp = "prop_mp_num_0";
			break;
			case 32: moneySpawnProp = "prop_mp_num_1";
			break;
			case 33: moneySpawnProp = "prop_mp_num_2";
			break;
			case 34: moneySpawnProp = "prop_mp_num_3";
			break;
			case 35: moneySpawnProp = "prop_mp_num_4";
			break;
			case 36: moneySpawnProp = "prop_mp_num_5";
			break;
			case 37: moneySpawnProp = "prop_mp_num_6";
			break;
			case 38: moneySpawnProp = "prop_mp_num_7";
			break;
			case 39: moneySpawnProp = "prop_mp_num_8";
			break;
			case 40: moneySpawnProp = "prop_mp_num_9";
			break;
			case 41: moneySpawnProp = "prop_battery_01";
			break;
			case 42: moneySpawnProp = "prop_printer_01";
			break;
			case 43: moneySpawnProp = "prop_old_boot";
			break;
			case 44: moneySpawnProp = "prop_golf_ball";
			break;
			case 45: moneySpawnProp = "v_res_r_teapot";
			break;
			case 46: moneySpawnProp = "prop_fridge_01";
			break;
			case 47: moneySpawnProp = "v_med_pillow";
			break;
			case 48: moneySpawnProp = "prop_cs_katana_01";
			break;
			case 49: moneySpawnProp = "prop_cs_mopbucket_01";
			break;
			case 50: moneySpawnProp = "ch2_03c_props_rrlwindmill_lod";
			break;
			case 51: moneySpawnProp = "v_res_fa_umbrella";
			break;
			case 52: moneySpawnProp = "prop_tool_pickaxe";
			break;
			case 53: moneySpawnProp = "prop_tool_shovel";
			break;
			case 54: moneySpawnProp = "v_res_fa_pyramid";
			break;
			case 55: moneySpawnProp = "prop_beach_fire";
			break;
			case 56: moneySpawnProp = "prop_air_lights_01a";
			break;
			case 57: moneySpawnProp = "p_SPINNING_ANUS_S";
			break;
			case 58: moneySpawnProp = "prop_mp_halo";
			break;
			case 59: moneySpawnProp = "prop_weed_01";
			break;
			case 60: moneySpawnProp = "prop_golf_bag_01";
			break;
			case 61: moneySpawnProp = "prop_golf_iron_01";
			break;
			case 62: moneySpawnProp = "prop_hard_hat_01";
			break;
			case 63: moneySpawnProp = "prop_hottub2";
			break;
			case 64: moneySpawnProp = "prop_pooltable_02";
			break;
			case 65: moneySpawnProp = "prop_microwave_1";
			break;
			case 66: moneySpawnProp = "prop_ld_greenscreen_01";
			break;
			case 67: moneySpawnProp = "prop_ld_shoe_01";
			break;
			case 68: moneySpawnProp = "prop_office_desk_01";
			break;
			case 69: moneySpawnProp = "prop_sink_01";
			break;
			case 70: moneySpawnProp = "prop_log_01";
			break;
			case 71: moneySpawnProp = "prop_mem_teddy_01";
			break;
			case 72: moneySpawnProp = "p_ferris_wheel_amo_l";
			break;
			case 73: moneySpawnProp = "prop_tv_06";
			break;
			case 74: moneySpawnProp = "prop_wheelchair_01";
			break;
			case 75: moneySpawnProp = "prop_windmill2";
			break;
		}
				
		if (isMoneySpawningOnLobby)
		{
			//
		}
		else
		{
			isMoneySpawningOnPlayerT = !isMoneySpawningOnPlayerT;
			isMoneySpawningOnPlayer = isMoneySpawningOnPlayerT;
		}

		MsgToggleDefault("Custom Money Toggle", isMoneySpawningOnPlayerT);

	}


	void ResetDropCoords(int dummy)
	{
		moneyCoordsAdjustX = 0.0f;
		moneyCoordsAdjustY = 0.0f;
		moneyCoordsAdjustZ = 0.0f;
	}
		
	bool moneyCoordsAdjustX_T = false;
	void ModifyDropCoordX(int dummy)
	{
		moneyCoordsAdjustY_ = false;
		moneyCoordsAdjustZ_ = false;

		moneyCoordsAdjustX_T = !moneyCoordsAdjustX_T;
		moneyCoordsAdjustX_ = moneyCoordsAdjustX_T;

		char* toggleState;
		if (moneyCoordsAdjustX_T) {toggleState = "~g~Enabled";}
		if (!moneyCoordsAdjustX_T) {toggleState = "~r~Disabled";}
		char buffer[64];
		sprintf(buffer, "~w~Modify Drop Coord %s\n~w~X Coord: ~b~%i", toggleState, moneyCoordsAdjustX);
		PrintText(buffer, 3000);
	}
		

	bool moneyCoordsAdjustY_T = false;
	void ModifyDropCoordY(int dummy)
	{
		moneyCoordsAdjustX_ = false;
		moneyCoordsAdjustZ_ = false;

		moneyCoordsAdjustY_T = !moneyCoordsAdjustY_T;
		moneyCoordsAdjustY_ = moneyCoordsAdjustY_T;

		char* toggleState;
		if (moneyCoordsAdjustY_T) {toggleState = "~g~Enabled";}
		if (!moneyCoordsAdjustY_T) {toggleState = "~r~Disabled";}
		char buffer[64];
		sprintf(buffer, "~w~Modify Drop Coord %s\n~w~Y Coord: ~b~%i", toggleState, moneyCoordsAdjustY);
		PrintText(buffer, 3000);
	}
		

	bool moneyCoordsAdjustZ_T = false;
	void ModifyDropCoordZ(int dummy)
	{
		moneyCoordsAdjustX_ = false;
		moneyCoordsAdjustY_ = false;

		moneyCoordsAdjustZ_T = !moneyCoordsAdjustZ_T;
		moneyCoordsAdjustZ_ = moneyCoordsAdjustZ_T;

		char* toggleState;
		if (moneyCoordsAdjustZ_T) {toggleState = "~g~Enabled";}
		if (!moneyCoordsAdjustZ_T) {toggleState = "~r~Disabled";}
		char buffer[64];
		sprintf(buffer, "~w~Modify Drop Coord %s\n~w~Z Coord: ~b~%i", toggleState, moneyCoordsAdjustZ);
		PrintText(buffer, 3000);
	}


	/*
	// OLD FULL AND DEMO MONEY DROP 20151113
	// Money Spawn Default
	bool isMoneySpawningOnPlayerT = false;
	void ToggleMoneySpawnDefault(int SelectedPlayer)
	{
		isCustomMoneySpawn = false;

		//SelectedPlayer = _SelectedPlayer;
		// FULL VERSION
		if (!demoMode && notDemo && !notActivated)
		{
			//moneySpawnProp = "prop_money_bag_01";
			
			// Disabling Player money spawn
			isMoneySpawningOnLobby = false;

			isMoneySpawningOnPlayerT = !isMoneySpawningOnPlayerT;
			isMoneySpawningOnPlayer = isMoneySpawningOnPlayerT;

			MsgToggleDefault("Money Toggle", isMoneySpawningOnPlayerT);
		}

		// DEMO ONLY
		// Single Tap Drop
		else
		{
			isMoneySpawningOnPlayer = false;

			int hashProp = GET_HASH_KEY("prop_money_bag_01");
			int hashPickup = GET_HASH_KEY("PICKUP_MONEY_CASE");
			Vec3 coordsTemp = GET_ENTITY_COORDS(GET_PLAYER_PED(SelectedPlayer),true);
			coordsTemp.x += coordsTemp.x * 0.015f;
			//coordsTemp.y += coordsTemp.y * 0.02f;
			//coordsTemp.z += coordsTemp.z * 0.02f;
			float* coords = Vec3toFloat(coordsTemp);

			REQUEST_MODEL(hashProp);
			if (HAS_MODEL_LOADED(hashProp) == 1)
			{
				CREATE_AMBIENT_PICKUP(hashPickup, coords, 0, 40000, hashProp, 0, 1);
				SET_MODEL_AS_NO_LONGER_NEEDED(hashProp);
			}

			MsgDefault("~r~Money Loop Not Available In DEMO!", 3000);
			
		}
	}


	// Money Spawn Custom
	//bool isMoneySpawningOnPlayerT = false;
	void ToggleMoneySpawnCustom(int propSelect)
	{
		isCustomMoneySpawn = true;

		// FULL VERSION
		if (!demoMode && notDemo && !notActivated)
		{
				
			switch (propSelect)
			{
				//case 0: moneySpawnProp = (char*)GetKeyboardInput(30);
				//break;
				case 1: moneySpawnProp = "prop_lawnmower_01";
				break;
				case 2: moneySpawnProp = "prop_pizza_box_01";
				break;
				case 3: moneySpawnProp = "prop_acc_guitar_01";
				break;
				case 4: moneySpawnProp = "prop_toilet_roll_01";
				break;
				case 5: moneySpawnProp = "prop_cs_dildo_01";
				break;
				case 6: moneySpawnProp = "prop_amb_40oz_02";
				break;
				case 7: moneySpawnProp = "prop_time_capsule_01";
				break;
				case 8: moneySpawnProp = "prop_ld_jerrycan_01";
				break;
				case 9: moneySpawnProp = "prop_toaster_01";
				break;
				case 10: moneySpawnProp = "prop_money_bag_01";
				break;
				case 11: moneySpawnProp = "prop_alien_egg_01";
				break;
				case 12: moneySpawnProp = "prop_car_engine_01";
				break;
				case 13: moneySpawnProp = "prop_couch_lg_02";
				break;
				case 14: moneySpawnProp = "prop_asteroid_01";
				break;
				case 15: moneySpawnProp = "prop_bskball_01";
				break;
				case 16: moneySpawnProp = "prop_sh_bong_01";
				break;
				case 17: moneySpawnProp = "prop_toilet_01";
				break;
				case 18: moneySpawnProp = "prop_poly_bag_money";
				break;
				case 19: moneySpawnProp = "prop_bowling_ball";
				break;
				case 20: moneySpawnProp = "prop_bowling_pin";
				break;
				case 21: moneySpawnProp = "prop_car_seat";
				break;
				case 22: moneySpawnProp = "prop_boombox_01";
				break;
				case 23: moneySpawnProp = "prop_parachute";
				break;
				case 24: moneySpawnProp = "prop_cs_hotdog_01";
				break;
				case 25: moneySpawnProp = "v_res_tre_pineapple";
				break;
				case 26: moneySpawnProp = "prop_mp_cone_04";
				break;
				case 27: moneySpawnProp = "id1_28_ladder01";
				break;
				case 28: moneySpawnProp = "prop_mp_cone_02";
				break;
				case 29: moneySpawnProp = "prop_mp_cone_03";
				break;
				case 30: moneySpawnProp = "prop_mp_cone_01";
				break;
				case 31: moneySpawnProp = "prop_mp_num_0";
				break;
				case 32: moneySpawnProp = "prop_mp_num_1";
				break;
				case 33: moneySpawnProp = "prop_mp_num_2";
				break;
				case 34: moneySpawnProp = "prop_mp_num_3";
				break;
				case 35: moneySpawnProp = "prop_mp_num_4";
				break;
				case 36: moneySpawnProp = "prop_mp_num_5";
				break;
				case 37: moneySpawnProp = "prop_mp_num_6";
				break;
				case 38: moneySpawnProp = "prop_mp_num_7";
				break;
				case 39: moneySpawnProp = "prop_mp_num_8";
				break;
				case 40: moneySpawnProp = "prop_mp_num_9";
				break;
				case 41: moneySpawnProp = "prop_battery_01";
				break;
				case 42: moneySpawnProp = "prop_printer_01";
				break;
				case 43: moneySpawnProp = "prop_old_boot";
				break;
				case 44: moneySpawnProp = "prop_golf_ball";
				break;
				case 45: moneySpawnProp = "v_res_r_teapot";
				break;
				case 46: moneySpawnProp = "prop_fridge_01";
				break;
				case 47: moneySpawnProp = "v_med_pillow";
				break;
				case 48: moneySpawnProp = "prop_cs_katana_01";
				break;
				case 49: moneySpawnProp = "prop_cs_mopbucket_01";
				break;
				case 50: moneySpawnProp = "ch2_03c_props_rrlwindmill_lod";
				break;
				case 51: moneySpawnProp = "v_res_fa_umbrella";
				break;
				case 52: moneySpawnProp = "prop_tool_pickaxe";
				break;
				case 53: moneySpawnProp = "prop_tool_shovel";
				break;
				case 54: moneySpawnProp = "v_res_fa_pyramid";
				break;
				case 55: moneySpawnProp = "prop_beach_fire";
				break;
				case 56: moneySpawnProp = "prop_air_lights_01a";
				break;
				case 57: moneySpawnProp = "p_SPINNING_ANUS_S";
				break;
				case 58: moneySpawnProp = "prop_mp_halo";
				break;
				case 59: moneySpawnProp = "prop_weed_01";
				break;
				case 60: moneySpawnProp = "prop_golf_bag_01";
				break;
				case 61: moneySpawnProp = "prop_golf_iron_01";
				break;
				case 62: moneySpawnProp = "prop_hard_hat_01";
				break;
				case 63: moneySpawnProp = "prop_hottub2";
				break;
				case 64: moneySpawnProp = "prop_pooltable_02";
				break;
				case 65: moneySpawnProp = "prop_microwave_1";
				break;
				case 66: moneySpawnProp = "prop_ld_greenscreen_01";
				break;
				case 67: moneySpawnProp = "prop_ld_shoe_01";
				break;
				case 68: moneySpawnProp = "prop_office_desk_01";
				break;
				case 69: moneySpawnProp = "prop_sink_01";
				break;
				case 70: moneySpawnProp = "prop_log_01";
				break;
				case 71: moneySpawnProp = "prop_mem_teddy_01";
				break;
				case 72: moneySpawnProp = "p_ferris_wheel_amo_l";
				break;
				case 73: moneySpawnProp = "prop_tv_06";
				break;
				case 74: moneySpawnProp = "prop_wheelchair_01";
				break;
				case 75: moneySpawnProp = "prop_windmill2";
				break;
			}
				
			if (isMoneySpawningOnLobby)
			{
				//
			}
			else
			{
				isMoneySpawningOnPlayerT = !isMoneySpawningOnPlayerT;
				isMoneySpawningOnPlayer = isMoneySpawningOnPlayerT;
			}

			MsgToggleDefault("Custom Money Toggle", isMoneySpawningOnPlayerT);
			
		}

		// DEMO ONLY
		// Single Tap Drop
		else
		{
			isMoneySpawningOnPlayer = false;
			
			int hashProp = GET_HASH_KEY("prop_money_bag_01");
			int hashPickup = GET_HASH_KEY("PICKUP_MONEY_CASE");
			Vec3 coordsTemp = GET_ENTITY_COORDS(GET_PLAYER_PED(PlayerSelected),true);
			coordsTemp.x = coordsTemp.x + moneyCoordsAdjustX;
			coordsTemp.y = coordsTemp.y + moneyCoordsAdjustY;
			coordsTemp.z = coordsTemp.z + moneyCoordsAdjustZ;
			float* coords = Vec3toFloat(coordsTemp);

			REQUEST_MODEL(hashProp);
			if (HAS_MODEL_LOADED(hashProp) == 1)
			{
				CREATE_AMBIENT_PICKUP(hashPickup, coords, 0, 40000, hashProp, 0, 1);
				SET_MODEL_AS_NO_LONGER_NEEDED(hashProp);
			}

			
			MsgDefault("~r~Custom Money Loop Not Available In DEMO!", 3000);
			
		}

	}
	*/

		
	// TOGGLES END
	//-------------------------------------------------------------------------------------------

		
		
		


	//------------------------------------------------------------------------------------
	// Nearby Car Stuff

	

	bool isControlAllNearbyVehiclesT = false;
	void NearbyCarControlAll(int dummy)
	{
		isControlAllNearbyVehiclesT = !isControlAllNearbyVehiclesT;
		isControlAllNearbyVehicles = isControlAllNearbyVehiclesT;
		MsgToggleDefault("Control All Nearby Cars", isControlAllNearbyVehiclesT);
	}


	bool isNearbyCarMayhemT = false;
	//bool isNearbyCarMayhemBoost = false;
	void NearbyCarMayhem(int style)
	{
		if (style == 2) { isNearbyCarMayhemBoost = true; isNearbyCarMayhemExplode = false; isNearbyCarMayhemUltimate = false; }
		if (style == 3) { isNearbyCarMayhemBoost = false; isNearbyCarMayhemExplode = true; isNearbyCarMayhemUltimate = false; }
		if (style == 4) { isNearbyCarMayhemBoost = false; isNearbyCarMayhemExplode = false; isNearbyCarMayhemUltimate = true; }

		isNearbyCarMayhemT = !isNearbyCarMayhemT;
		isNearbyCarMayhem = isNearbyCarMayhemT;
		MsgToggleDefault("Total Mayhem", isNearbyCarMayhemT);
	}
		

	

	/*

	void KnockPedOffVehicle(int dummy)
	{
		//GET_CLOSEST_PED
		//GET_PED_NEARBY_PEDS
		//GET_PED_NEARBY_VEHICLES
		//KNOCK_PED_OFF_VEHICLE

		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);

		KNOCK_PED_OFF_VEHICLE(closestVehicleToPlayer);
	}


	void KnockAllPedsOffVehicle(int dummy)
	{
		const int numElements = 10;
		const int arrSize = numElements * 2 + 2;
		Any vehicleTarget[arrSize];
		//0 index is the size of the array
		vehicleTarget[0] = numElements;

		int count = GET_PED_NEARBY_VEHICLES(PlayerSelf(), vehicleTarget);

		if (vehicleTarget != NULL)
		{
			//Simple loop to go through results
			for (int i = 0; i < count; i++)
			{
				int offsettedID = i * 2 + 2;
				//Make sure it exists
				if (vehicleTarget[offsettedID] != NULL && DOES_ENTITY_EXIST(vehicleTarget[offsettedID]))
				{
					KNOCK_PED_OFF_VEHICLE(vehicleTarget[offsettedID]);
				}
			}
		} 

	}
	*/
	
	bool isNearbyCarDetectActiveT = false;
	void ToggleNearbyVehicleDetect(int dummy)
	{		
		isNearbyCarDetectActiveT = !isNearbyCarDetectActiveT;
		isNearbyCarDetectActive = isNearbyCarDetectActiveT;
		MsgToggleDefault("Closest Vehicle Detect", isNearbyCarDetectActiveT);

	}
	
	/*
	bool isTorqueModifierNearbyActiveT = false;
	void ToggleNearbyVehicleTorqueBackward(int dummy)
	{
		torqueValueNearby = -400;
			
		isTorqueModifierNearbyActiveT = !isTorqueModifierNearbyActiveT;
		isTorqueModifierNearbyActive = isTorqueModifierNearbyActiveT;
		MsgToggleDefault("Torque Backwards", isTorqueModifierNearbyActiveT);

	}
	*/

	/*
	bool vehicleIsClipping = true;
	void ToggleClippingNearbyCars(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		vehicleIsClipping = !vehicleIsClipping;
		SET_ENTITY_COLLISION(closestVehicleToPlayer, vehicleIsClipping, false);
		MsgToggleDefault("No Clipping", vehicleIsClipping);
	}
	*/

	/*
	bool vehicleIsOutOfControl = false;
	void ToggleOutOfControlNearbyCars(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		vehicleIsOutOfControl = !vehicleIsOutOfControl;
		SET_VEHICLE_OUT_OF_CONTROL(closestVehicleToPlayer, false, false);
		MsgToggleDefault("Vehicle Out Of Control", vehicleIsOutOfControl);
	}
	*/

	/*
	bool vehicleIsDrifting = false;
	void ToggleDriftingNearbyCars(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		vehicleIsDrifting = !vehicleIsDrifting;
		SET_VEHICLE_REDUCE_GRIP(closestVehicleToPlayer, vehicleIsDrifting);
		MsgToggleDefault("Vehicle Drifting", vehicleIsDrifting);
	}
	*/

	/*
	void TeleportToRandomNearbyCars(int dummy)
	{
		float randomX = GET_RANDOM_FLOAT_IN_RANGE(-5000, 5000);
		float randomY = GET_RANDOM_FLOAT_IN_RANGE(-4000, 4000);
		float randomZ = GET_RANDOM_FLOAT_IN_RANGE(1, 50);
		float Random[3] = { randomX, randomY, randomZ };
		coords = Random;
			
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);

		SET_ENTITY_COORDS(closestVehicleToPlayer, coords, 1, 0, 0, 1);
	}
	*/
				
	/*
	// Toggle 4-Way Signals Nearby Cars
	bool isVehicle4WayActive = false;
	void ToggleSignalsNearbyCars(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		isVehicle4WayActive = !isVehicle4WayActive;
		SET_VEHICLE_INDICATOR_LIGHTS(closestVehicleToPlayer, 0, isVehicle4WayActive); 
		SET_VEHICLE_INDICATOR_LIGHTS(closestVehicleToPlayer, 1, isVehicle4WayActive); 
		MsgToggleDefault("Emergency 4-Way Signals", isVehicle4WayActive);
	}
	*/

	/*
	// Break Off Doors Nearby Cars
	void BreakOffDoorsNearbyCars(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
			
		for (int i=0; i<=7; i++)
		{
			SET_VEHICLE_DOOR_BROKEN(closestVehicleToPlayer, i, true);
		}
	}
	*/

	/*
	// Toggle Burnout Nearby Cars
	bool isVehicleInBurnout = false;
	void ToggleBurnoutNearbyCars(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		isVehicleInBurnout = !isVehicleInBurnout;
		SET_VEHICLE_BURNOUT(closestVehicleToPlayer, isVehicleInBurnout);
		MsgToggleDefault("Burnout", isVehicleInBurnout);
	}
	*/

	/*
	// Destroy Nearby Cars
	bool isVehicleDriveable = false;
	void DestroyNearbyCars(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		isVehicleDriveable = !isVehicleDriveable;
		SET_VEHICLE_UNDRIVEABLE(closestVehicleToPlayer, isVehicleDriveable);
		MsgToggleDefault("Vehicle", isVehicleDriveable);
	}
	*/
	
	/*
	// Toggle Hot Flag Nearby Cars
	bool canResprayVehicle = false;
	void ToggleHotFlagNearbyCars(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		canResprayVehicle = !canResprayVehicle;
		SET_CAN_RESPRAY_VEHICLE(closestVehicleToPlayer, canResprayVehicle);
		MsgToggleDefault("Can Respray Vehicle", canResprayVehicle);
	}
	*/

	// Fix and Wash Nearby Cars
	void FixAndWashNearbyCars(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		SET_VEHICLE_FIXED(closestVehicleToPlayer);
		SET_VEHICLE_DEFORMATION_FIXED(closestVehicleToPlayer);
		SET_VEHICLE_DIRT_LEVEL(closestVehicleToPlayer, 0);
	}
	
	
	/*
	void ExplodeNearbyCars(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		for (int tire=0; tire<=7; tire++)
		EXPLODE_VEHICLE(closestVehicleToPlayer, true, false);
	}

	bool isVehicleFrozen = false;
	void FreezeNearbyCars(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		isVehicleFrozen = !isVehicleFrozen;
		FREEZE_ENTITY_POSITION(closestVehicleToPlayer, isVehicleFrozen);
		MsgToggleDefault("Vehicle Freeze", isVehicleFrozen);
	}

	bool vehicleGravity = true;
	void GravityNearbyCars(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		vehicleGravity = !vehicleGravity;
		SET_VEHICLE_GRAVITY(closestVehicleToPlayer, vehicleGravity);
		SET_ENTITY_HAS_GRAVITY(closestVehicleToPlayer, vehicleGravity);
		MsgToggleDefault("Gravity", vehicleGravity);
	}

	void SmashNearbyCarWindows(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		for (int window=0; window<=7; window++)
		SMASH_VEHICLE_WINDOW(closestVehicleToPlayer, window);
	}

	void ExplodeNearbyCarTires(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		for (int tire=0; tire<=7; tire++)
		SET_VEHICLE_TYRE_BURST(closestVehicleToPlayer, tire, true, 1000.0);
	}

	void RandomPaintNearbyCars(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		int random = irand(0, 159);
		SET_VEHICLE_COLOURS(closestVehicleToPlayer, random, random);
	}

	void SpeedBoostNearbyCars(int speed)
	{
		float speedf = speed;
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		SET_VEHICLE_FORWARD_SPEED(closestVehicleToPlayer, speedf);
	}
		
	// Make Vehicle Invisible
	bool vehicleVisible = true;
	void ToggleInvisibilityNearbyCars(int dummy)
	{
		vehicleVisible = !vehicleVisible;
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		SET_ENTITY_VISIBLE(closestVehicleToPlayer, vehicleVisible);
		MsgToggleReverse("Vehicle Invisibility", vehicleVisible);
	}
	*/

	void GodmodeNearbyCars(int dummy)
	{
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);
		SET_ENTITY_PROOFS(closestVehicleToPlayer, true, true, true, true, true, true, true, true);
		SET_ENTITY_INVINCIBLE(closestVehicleToPlayer, true);
		SET_ENTITY_CAN_BE_DAMAGED(closestVehicleToPlayer, false);
		SET_VEHICLE_TYRES_CAN_BURST(closestVehicleToPlayer, false);
		SET_VEHICLE_WHEELS_CAN_BREAK(closestVehicleToPlayer, false);
	}

	void MaxOutNearbyCars(int dummy)
	{
		int random = irand(0, 157);
		int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 100);

		SET_VEHICLE_MOD_KIT(closestVehicleToPlayer, 0);
		SET_VEHICLE_COLOURS(closestVehicleToPlayer, random, random);
		SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(closestVehicleToPlayer, 0);
		TOGGLE_VEHICLE_MOD(closestVehicleToPlayer, 18, 1);
		TOGGLE_VEHICLE_MOD(closestVehicleToPlayer, 22, 1);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 16, 5, 0);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 12, 2, 0);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 11, 3, 0);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 14, 14, 0);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 15, 3, 0);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 13, 2, 0);
		SET_VEHICLE_WHEEL_TYPE(closestVehicleToPlayer, 6);
		SET_VEHICLE_WINDOW_TINT(closestVehicleToPlayer, 5);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 23, 19, 1);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 0, 1, 0);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 1, 1, 0);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 2, 1, 0);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 3, 1, 0);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 4, 1, 0);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 5, 1, 0);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 6, 1, 0);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 7, 1, 0);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 8, 1, 0);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 9, 1, 0);
		SET_VEHICLE_MOD(closestVehicleToPlayer, 10, 1, 0);
	}
	//------------------------------------------------------------------------------------






};




#endif


