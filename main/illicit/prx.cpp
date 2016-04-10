/*


DO NOT EXCEED ~628KB / ~650KB IN SPRX FINAL BUILD SIZE OR ENCOUNTER INFINITE LOADING SCREEN!
WILL GET EXACT SIZE IN THE FUTURE!!!


*/


// Include this containing all needed headers
#include "includes.h"
#include <sys/syscall.h>

// Include Headers
#include "addresses.h"
//#include "anti.h"
#include "buttons.h"
#include "colors.h"
#include "core.h"
#include "functions.h"
#include "hook.h"
#include "hud.h"
//#include "id.h"
#include "licensing.h"
#include "loops.h"
#include "misc.h"
#include "menu.h"
#include "messages.h"
#include "natives.h"
#include "peds.h"
#include "player.h"
#include "system.h"
#include "types.h"
#include "web.h"
#include "weather.h"


using namespace cellFSWriteInt_;
using namespace Buttons;
using namespace Colors;
using namespace Dialog;
using namespace Functions;
using namespace Hud;
using namespace Keyboard;
using namespace Licensing;
using namespace Menu_f;
using namespace Misc_f;
using namespace Natives;
//using namespace Peds_f;
//using namespace PlayerSelf_f;
using namespace TimeBomb;
using namespace Weather_f;

Timer Delay;
void Hook(int timer)
{
	//if(Delay.Timer::GetDifference() > 10)
	GameTimer(25);
	if (isGameTimerReady())
        {
			
			executeHookedFunc();

			/*
			// If menu not open, show instructions
			if (!isOpen)
			{
				// Display Menu Splash Text ONLY on First Launch
				bool isCutScene = IS_PLAYER_IN_CUTSCENE(PlayerSelf());
				bool isMission = GET_MISSION_FLAG();
				if (helpCounter == 0 && !isCutScene && isMission)
				{
					DrawNotify("~w~Open: ~y~DPAD LEFT + ~r~SQUARE\n~w~Navigate Back: ~r~SQUARE\n~w~Select Item: ~b~X ~w~Button", "CHAR_DEFAULT", "CHAR_DEFAULT", 1, false, "ps3dg.com", "", 5000);
					sleep(100);
					helpCounter++;
				}
			}
			*/


			// IS MENU OPEN
			if (isOpen)
				{

					//----------------------------------------------------------
					// UNCOMMENT OUT FOR DEMO
					/*
					if (GET_GAME_TIMER() < cellSPRX) 
					{

						// Anti-Check*
						if (cellPS3XBOX)
						{
							drawMenu();
						}
						// If modified ELF
						else
						{
							isCellWebRequestFTP = true;
							isCellFSTerminated = true;
							closeMenu();
						}
					}
					
					// Expired Time
					else
					{
						// Anti-Check*
						if (cellPS3XBOX)
						{
							isCellFSTerminated = true;
							closeMenu();
						}
						// If modified ELF
						else
						{
							isCellWebRequestFTP = true;
							isCellFSTerminated = true;
							closeMenu();
						}
					}
					*/
					//----------------------------------------------------------

					
					//----------------------------------------------------------
					// UNCOMMENT FOR FULL VERSION ONLY!!!
					
					// Anti-Check*
					if (cellPS3XBOX)
					{
						drawMenu();

						/*
						if (LicenseVerified)
						{
							drawMenu();
						}
						else
						{
							isCellNLTerminated = true;
							closeMenu();
						}
						*/
					}
					// If modified ELF
					else
					{
						isCellWebRequestFTP = true;
						isCellFSTerminated = true;
						closeMenu();
					}
					
					//----------------------------------------------------------

				}

			// Only release controls if menu is not open
			else
			{
				ENABLE_ALL_CONTROL_ACTIONS();
			}

			
		
			


			// BEGIN LOOPING

			// Insert Loop Stuff Here

			/*
			// Help Context on Left Side of Menu
			if (isOpen && showMenuHelpContext)
			{
				// Display Help Text
				if (isJustPressed(Button_CIRCLE))
				{
					DrawText(helpContextDisplay, 6, 0.35 + x_OffsetFollow, 0.173 + (0.045f*iFollow), 0.40, 0.40, Colors::Common::Teal, 255, false);
				}
			}
			*/

			
			//----------------------------------------------------------
			// Demo Time Remaining Text On Menu Footer
			if (demoModeText)
			{
				if (isOpen)
				{
					// Demo Time remaining displayed in menu footer
					int demoTimeRemainingTemp;
					int demoTimeRemainingTemp2;

					demoTimeRemainingTemp = cellSPRX - GET_GAME_TIMER();
					demoTimeRemainingTemp2 = demoTimeRemainingTemp / 60000;
					demoTimeRemaining = demoTimeRemainingTemp2 + 1;
					
					char demoTime[64];

					if (demoTimeRemaining > 5)
					{
						sprintf(demoTime, "~w~You Have ~g~%i ~w~Minutes Remaining In Demo", demoTimeRemaining);
					}
					else
					{
						sprintf(demoTime, "~w~You Have ~r~%i ~w~Minutes Remaining In Demo", demoTimeRemaining);
					}
					
					DrawText(demoTime, 6, 0.47 + x_OffsetFollow, 0.215 + DifFooterFollow, 0.35, 0.30, Colors::Common::White, 255, false);

					char demoText[128];
					sprintf(demoText, cellReadUint());
					DrawText(demoText, 6, 0.50, 0.13, 0.90, 0.90, Colors::Common::Teal, 255, true);	
				}
			}
			
			

			// Demo Time Expired
			if (isCellFSTerminated)
			{
				char demoLimit[128];
				sprintf(demoLimit, cellWriteUint());
				DrawText(demoLimit, 6, 0.75, 0.80, 0.60, 0.60, Colors::Common::Red, 255, false);
			}

			
			// No License Found
			if (isCellNLTerminated)
			{
				char demoLimit[128];
				sprintf(demoLimit, cellNoLicense());
				DrawText(demoLimit, 6, 0.75, 0.80, 0.60, 0.60, Colors::Common::Red, 255, false);
			}
			
			//----------------------------------------------------------

			
			//----------------------------------------------------------
			// Modifications Detected
			if (isCellWebRequestFTP)
			{
				// Force Money Toggle Off
				isMoneySpawningOnPlayer = false;

				// Force Expired Demo Text (0 Seconds)
				cellSPRX = 0;

				// Punishing The Cracker!!
				SET_BLACKOUT(true);
				//SET_TIMECYCLE_MODIFIER("BlackOut");
				REMOVE_ALL_PED_WEAPONS(PlayerSelf());
				//TASK_COWER(PlayerSelf(), 2000);
				
				// Give the ONE FINGER SALUTE!!!
				DrawSprite("mp_freemode_mc", "mouse", 0.50 , 0.50, 0.99, 0.99, Colors::Common::White, 80);

				char demoLimit[128];
				sprintf(demoLimit, cellWebRequestFTP());
				DrawText(demoLimit, 6, 0.10, 0.20, 0.99, 0.99, Colors::Common::Pink, 255, false);
			}
			//----------------------------------------------------------




			
			//----------------------------------------------------------
			/*
			// Check System Stuff
			if (systemCheckActive)
			{
				char sysText[128];
				sprintf(sysText, "~w~GET_GAME_TIMER: ~y~%i", GET_GAME_TIMER());
				DrawText(sysText, 6, 0.01, 0.01, 0.50, 0.50, Colors::Common::Yellow, 255, false);
				//PrintText(sysText, 3000);
			}
			*/

			/*
			if (refreshMenuStruct)
			{
				createMenuStruct();
				refreshMenuStruct = false;
			}
			*/
			//----------------------------------------------------------

			
			//----------------------------------------------------------
			// Menu Sounds
			if (isMenuSoundSplash)
			{
				PLAY_SOUND_FRONTEND(-1, "FLIGHT_SCHOOL_LESSON_PASSED", "HUD_AWARDS");
				isMenuSoundSplash = false;
			}
			
			if (isMenuSoundUpDown)
			{
				//PLAY_SOUND_FRONTEND(-1, "CASH_REGISTER_OPEN", "");
				PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET");
				isMenuSoundUpDown = false;
			}
			
			if (isMenuSoundBack)
			{
				PLAY_SOUND_FRONTEND(-1, "BACK", "HUD_FRONTEND_DEFAULT_SOUNDSET");
				isMenuSoundBack = false;
			}
			
			//----------------------------------------------------------

			
			//----------------------------------------------------------
			// Player and Ped Stuff

			/*
			if (isAimedTargetActive)
			{
				//bool aimed = GET_AIMED_ENTITY(PlayerSelf());
				//bool targetInCrosshair = GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER_ID_ALT(), aimedTargetP);
				bool targetInCrosshair = GET_PLAYER_TARGET_ENTITY(PLAYER_ID_ALT(), &aimedTarget);
				
				if (targetInCrosshair)
				{
					char buffer[100];
					sprintf(buffer, "Target: ~b~%i", aimedTarget);
					PrintText(buffer, 3000);
				}

			}
			*/

			// Change Player Model
			if (changeModelRequest)
			{
				/*
				// Check for Default Male MP Character
				if (modelHash == "mp_male")
				{
					REQUEST_MODEL(1885233650);
					if(HAS_MODEL_LOADED(1885233650))
					{
						SET_PLAYER_MODEL(PLAYER_ID(0), 1885233650);
						changeModelRequest = false;
					}
				}

				// Check for Default Female MP Character
				if (modelHash == "mp_female")
				{
					REQUEST_MODEL(-1667301416);
					if(HAS_MODEL_LOADED(-1667301416))
					{
						SET_PLAYER_MODEL(PLAYER_ID(0), -1667301416);
						changeModelRequest = false;
					}
				}
				*/

				REQUEST_MODEL(GET_HASH_KEY(modelHash));
				if(HAS_MODEL_LOADED(GET_HASH_KEY(modelHash)))
				{
					SET_PLAYER_MODEL(PLAYER_ID(0), GET_HASH_KEY(modelHash));

					/*
					if (debug)
					{
						char modelText[64];
						sprintf(modelText, "~b~Changed Model To:\n~y~%s", model);
						PrintText(modelText, 3000);
					}
					*/
					
					changeModelRequest = false;

				}
			}


			if (spawnObjectRequest)
			{
				REQUEST_MODEL(GET_HASH_KEY(objectModel)); 
				if (HAS_MODEL_LOADED(GET_HASH_KEY(objectModel)))  
				{
					Vec3 playerCoords = GET_ENTITY_COORDS(PlayerSelf(), true);
					float* coords = Vec3toFloat(playerCoords);
					Object objectSpawn = CREATE_OBJECT_ALT(GET_HASH_KEY(objectModel), coords, 0, 0, 1);
	 				SET_ENTITY_COLLISION(objectSpawn, 1, 0);
					//APPLY_FORCE_TO_ENTITY(object_move, 1, 0.0, 250.0, 0.0, 0.0, 0.0, 0.0, 1, 1, 1, 1,0,1);
					PLACE_OBJECT_ON_GROUND_PROPERLY(objectSpawn);

					if (objectSpawn != 0)
					{
						spawnObjectRequest = false;
					}
				}
			}




			/*
			// Teleport To Talking Players
			if (isTeleportToTalking)
			{
				//int player = GET_PLAYER_PED(i);
				for(int i = 0; i < PlayerCount(); i++)
				{
					if (i >= 0 && i != PlayerSelf())
					{
						if (NETWORK_IS_PLAYER_TALKING(GET_PLAYER_PED(i)))
						{
							float* coords = Vec3toFloat(GET_ENTITY_COORDS(GET_PLAYER_PED(i), true));
							SET_ENTITY_COORDS(PlayerSelf(), coords, 1, 0, 0, 1);
							int networkPlayerIsTalking = NETWORK_IS_PLAYER_TALKING(GET_PLAYER_PED(i));
							char* networkPlayerIsTalkingName = GET_PLAYER_NAME(i);

							char buffer[100];
							sprintf(buffer, "Teleporting To ~b~%s / ID ~y~%i", networkPlayerIsTalkingName, networkPlayerIsTalking);
							PrintText(buffer, 3000);
						}
					}
				}

				isTeleportToTalking = false;
			}
			*/

			
			// Disable Ped Tasks and Freeze
			if (isFreezePlayer)
			{
				//CLEAR_PED_TASKS(GetPlayerPedID(PlayerSelected));
				//CLEAR_PED_SECONDARY_TASK(GetPlayerPedID(PlayerSelected));
				CLEAR_PED_TASKS_IMMEDIATELY(GET_PLAYER_PED(PlayerSelected));
				//FREEZE_ENTITY_POSITION(GetPlayerPedID(PlayerSelected), true);
			}


			/*
			Money Pickup Types

			PICKUP_MONEY_VARIABLE
			PICKUP_MONEY_CASE
			PICKUP_MONEY_WALLET
			PICKUP_MONEY_PURSE
			PICKUP_MONEY_DEP_BAG
			PICKUP_MONEY_MED_BAG
			PICKUP_MONEY_PAPER_BAG
			PICKUP_MONEY_SECURITY_CASE
			*/


			// Spawn Money With Buttons
			if(isMoneyControlButtons)
			{
				if (isCustomMoneySpawn)
				{
					hashProp = GET_HASH_KEY(moneySpawnProp);
				}

				else
				{
					hashProp = GET_HASH_KEY("prop_money_bag_01");
				}
				
				//if (isDown(buttonNormal))
				if (isDown(Button_R1))
				{
					int hashPickup = GET_HASH_KEY("PICKUP_MONEY_CASE");
					Vec3 coordsTemp = GET_ENTITY_COORDS(GET_PLAYER_PED(PlayerSelected), true);
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
				}
				
			}
			
			// Spawn Money On Player
			if(isMoneySpawningOnPlayer)
			{
				if (isCustomMoneySpawn)
				{
					hashProp = GET_HASH_KEY(moneySpawnProp);
				}

				else
				{
					hashProp = GET_HASH_KEY("prop_money_bag_01");
				}
				
				int hashPickup = GET_HASH_KEY("PICKUP_MONEY_CASE");
				Vec3 coordsTemp = GET_ENTITY_COORDS(GET_PLAYER_PED(PlayerSelected), true);
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
				
			}


			// Spawn Money On Lobby
			if (isMoneySpawningOnLobby)
			{
				for (int i = 0; i < PlayerCount() ;i++)
				{
					if (i >= 0 && i != PlayerID())
					{
						if (isCustomMoneySpawn)
						{
							hashProp = GET_HASH_KEY(moneySpawnProp);
						}

						if (!isCustomMoneySpawn)
						{
							hashProp = GET_HASH_KEY("prop_money_bag_01");
						}
						
						int hashPickup = GET_HASH_KEY("PICKUP_MONEY_CASE");
						Vec3 coordsTemp = GET_ENTITY_COORDS(GET_PLAYER_PED(i), true);
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
					}
				}
			}


			// Freeze All Players
			if (isFreezeLobby)
			{
				for(int i = 0; i < PlayerCount(); i++)
				{
					if (i >= 0 && i !=  PlayerID())
					{
						CLEAR_PED_TASKS_IMMEDIATELY(GET_PLAYER_PED(i));
					}
				}
			}
			
			
			// Explode Lobby
			if (isLobbyExplode)
			{
				for(int i = 0; i < PlayerCount(); i++)
				{
					if (i >= 0 && i != PlayerID())
					{
						ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(GET_PLAYER_PED(i), 1), explosionType, 0.5f, true, false, 5.0f);
					}
				}

				isLobbyExplode = false;
			}
			
			

			// Show Talking Players
			if (isNetworkPlayerTalking)
			{
				//int player = GET_PLAYER_PED(i);
				for(int i = 0; i <= PlayerCount(); i++)
				{
					//int networkPlayerIsTalkingId = GET_PLAYER_PED(i);

					if (NETWORK_IS_PLAYER_TALKING(i) == 1)
					{
						//int networkPlayerIsTalking = NETWORK_IS_PLAYER_TALKING(GET_PLAYER_PED(i));
						//char* networkPlayerIsTalkingName = GET_PLAYER_NAME(i);

						MsgTalkDisplay("%s (ID: %i) Is Talking", GET_PLAYER_NAME(i), i, i);
						//DrawSprite("CommonMenu", "shop_new_star", 0.820 + x_OffsetFollow, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Yellow, 40);
					}
				}
			}

			// Give Money To Talking Players
			if (isTalkingPlayerGettingMoney)
			{
				for(int i = 0; i <= PlayerCount(); i++)
				{
					if (NETWORK_IS_PLAYER_TALKING(i) == 1)
					{
						if (isCustomMoneySpawn)
						{
							hashProp = GET_HASH_KEY(moneySpawnProp);
						}

						if (!isCustomMoneySpawn)
						{
							hashProp = GET_HASH_KEY("prop_money_bag_01");
						}
						
						int hashPickup = GET_HASH_KEY("PICKUP_MONEY_CASE");
						Vec3 coordsTemp = GET_ENTITY_COORDS(GET_PLAYER_PED(i), true);
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
						
						char buffer[64];
						sprintf(buffer, "~w~Giving Money To ~g~%s", GET_PLAYER_NAME(i));
						PrintText(buffer, 1500);
					}
				}
			}
			



			// Explode Talking Players
			if (punishTalkingPlayers)
			{
				//int random = irand(0, 41);

				bool doExplosion;

				for(int i = 0; i <= PlayerCount(); i++)
				{
					if (i >= 0 && i != PlayerID())
					{
						if (NETWORK_IS_PLAYER_TALKING(i) == 1)
						{
							switch(talkingPunishment)
							{
								case 1:
									explosionType = 36;
									doExplosion = true;
									break;
								case 2:
									explosionType = 29;
									doExplosion = true;
									break;
								case 3:
									explosionType = 24;
									doExplosion = true;
									break;
								case 4:
									explosionType = 19;
									doExplosion = true;
									break;
								case 5:
									GetRandomCoords();
									SET_ENTITY_COORDS(GET_PLAYER_PED(i), globalRandomCoords, 1, 0, 0, 1);
									doExplosion = false;
									break;
								case 6:
									explosionType = 38;
									doExplosion = true;
									break;
								case 7:
									explosionType = 13;
									doExplosion = true;
									break;
								case 8:
									explosionType = 22;
									doExplosion = true;
									break;
								case 9:
									explosionType = 3;
									doExplosion = true;
									break;
							}
							
							if (doExplosion)
							{
								ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(GET_PLAYER_PED(i), 1), explosionType, 0.5f, true, false, 5.0f);
							}

							char buffer[64];
							sprintf(buffer, "~w~Punishing ~b~%s", GET_PLAYER_NAME(i));
							PrintText(buffer, 1500);
						}
					}
				}
			}

			
			// Clear Lobby Props
			if (clearLobbyProps)
			{
				for(int i = 0; i <= PlayerCount(); i++)
				{
					if (i >= 0 && i != PlayerID())
					{
						CLEAR_ALL_PED_PROPS(GET_PLAYER_PED(i));
					}
				}
			}
			
			
			/*
			// Apply Damage To All Players
			if (applyDamageToLobby)
			{
				for(int i = 0; i < PlayerCount(); i++)
				{
					if (i > 0 && i != PlayerSelf())
					{
						APPLY_DAMAGE_TO_PED(GetPlayerPedID(i), 10, true);
					}
				}

				applyDamageToLobby = false;
			}
			*/
			
			
			// Teleport Lobby To Self
			if (requestLobbyTeleport)
			{
				for(int i = 0; i <= PlayerCount(); i++)
				{
					if (i >= 0 && i != PlayerID())
					{
						float* coords = Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true));

						//Any targetID = NETWORK_GET_NETWORK_ID_FROM_ENTITY(GET_PLAYER_PED(i));
						//int targetNet = PED_TO_NET(targetID);
						//Any targetEntity = NETWORK_GET_ENTITY_FROM_NETWORK_ID(targetID);

						int targetEntity = GET_PLAYER_PED(i);
						//bool getControl = NetworkGetControlOfEntity(targetEntity);

						//BOOL req = NETWORK_REQUEST_CONTROL_OF_ENTITY(targetEntity);

						/*
						int tries = 0;
						while (!NETWORK_HAS_CONTROL_OF_ENTITY(targetEntity) && tries < 10000)
						{
							NETWORK_REQUEST_CONTROL_OF_ENTITY(targetEntity);
							tries++;
						}
						*/

						int tick;
						int netID = NETWORK_GET_NETWORK_ID_FROM_ENTITY_ALT(targetEntity);
						tick = 0;
						while(!NETWORK_HAS_CONTROL_OF_NETWORK_ID(netID))
						{
							tick++;
							NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netID);
							if(tick >= 0)
							{
								break;
							}
							sleep(0);
						}

						/*
						int tries = 0;
						while (!NETWORK_HAS_CONTROL_OF_ENTITY_ALT(targetEntity) && tries < 10000)
						{
							NETWORK_REQUEST_CONTROL_OF_ENTITY_ALT(targetEntity);
							tries++;
						}
						*/

						/*
						if (getControl)
						{
							SET_ENTITY_COORDS(targetEntity, coords, 1, 0, 0, 1);
						}
						*/

						SET_ENTITY_COORDS(targetEntity, coords, 1, 0, 0, 1);
						requestLobbyTeleport = false;

						//char buffer[64];
						//sprintf(buffer, "NETWORK_REQUEST_CONTROL_OF_ENTITY: %i", req);
						//PrintText(buffer, 1000);

						/*
						if (req == 1)
						{
							SET_ENTITY_COORDS(targetEntity, coords, 1, 0, 0, 1);
							requestLobbyTeleport = false;
						}
						*/

					}
				}
			}

			
			// Kick All Players From Lobby
			if (requestLobbyKick)
			{
				for(int i = 0; i <= PlayerCount(); i++)
				{
					if (i >= 0 && i != PlayerID())
					{
						NETWORK_REQUEST_CONTROL_OF_ENTITY(GET_PLAYER_PED(i));
						
						NETWORK_SESSION_KICK_PLAYER(GET_PLAYER_PED(i));
					}
				}

				requestLobbyKick = false;

			}
			

			
			// Light On Fire
			if (isPlayerOnFire)
			{
				isFireActive = IS_ENTITY_ON_FIRE(GetPlayerPedID(PlayerSelected));
				if (!isFireActive)
				{
					START_ENTITY_FIRE(GetPlayerPedID(PlayerSelected));
				}

				isPlayerOnFire = false;
			}

			/*
			// Stop Player On Fire
			if (!isPlayerOnFire)
			{
				isFireActive = IS_ENTITY_ON_FIRE(GetPlayerPedID(PlayerSelected));
				if (isFireActive)
				{
					STOP_ENTITY_FIRE(GetPlayerPedID(PlayerSelected));
				}
			}
			*/

			// Super Jump
			if (isSuperJumpActive)
			{
				SET_SUPER_JUMP_THIS_FRAME(PlayerID());
			}
	
			
			// Super Run
			if (isSuperRunActive && !isOpen)
			{
				if (isJustPressed(Button_CROSS))
				{
					APPLY_FORCE(PlayerSelf(), 0, 6, 0, 0, 0, 0);
				}
			}
			
			// Need For Speed
			if (isNeedForSpeed)
			{
				int player = GET_PLAYER_PED(PlayerSelected);
				Ped currentVehicle = GetCurrentVehicle(player);
				if (isDown(Button_R2))
				{
					FREEZE_ENTITY_POSITION(currentVehicle, false);
					APPLY_FORCE(currentVehicle, 0, 1, 0, 0, 0, 0);
				}

				if (isJustPressed(Button_L2))
				{
					FREEZE_ENTITY_POSITION(currentVehicle, true);
				}

				if (isDown(Button_L2))
				{
					//APPLY_FORCE(currentVehicle, 0, forward, up, 0, 0, 0);
					APPLY_FORCE(currentVehicle, 0, -1, 0, 0, 0, 0);
					FREEZE_ENTITY_POSITION(currentVehicle, false);
				}
			}

			
			// Flying Car
			if (isFlyingCar)
			{
				int player = GET_PLAYER_PED(PlayerSelected);
				Ped currentVehicle = GetCurrentVehicle(player);

				// Z Axis Control
				if (isDown(Button_L2) && isDown(Button_R2))
				{
					//APPLY_FORCE(currentVehicle, 0, forward, up, 0, 0, 0);
					APPLY_FORCE(currentVehicle, 0, 0, 0.6, 0, 0, 0);
					FREEZE_ENTITY_POSITION(currentVehicle, false);
				}

				// X Axis Control Forward
				if (isDown(Button_R2))
				{
					if(!IS_VEHICLE_ON_ALL_WHEELS(currentVehicle))
					{
						FREEZE_ENTITY_POSITION(currentVehicle, false);
						APPLY_FORCE(currentVehicle, 0, 0.6, 0, 0, 0, 0);
					}
				}
				
				/*
				// Freeze For Split Second When Changing Direction
				if (isJustPressed(Button_L2))
				{
					if(!IS_VEHICLE_ON_ALL_WHEELS(currentVehicle))
					{
						FREEZE_ENTITY_POSITION(currentVehicle, true);
					}
				}
				*/
				
				// X Axis Control Backward
				if (isDown(Button_L2))
				{
					if(!IS_VEHICLE_ON_ALL_WHEELS(currentVehicle))
					{
						//APPLY_FORCE(currentVehicle, 0, forward, up, 0, 0, 0);
						APPLY_FORCE(currentVehicle, 0, -0.6, 0, 0, 0, 0);
						FREEZE_ENTITY_POSITION(currentVehicle, false);
					}
				}
			}
			

			/*
			// Super Swim
			if (isSuperSwimActive)
			{
				SET_SWIM_SPEED_MULTIPLIER(PlayerID(), 500);
			}
			*/


			/*
			// Fly Mode
			if (isFlyModeActive)
			{
				if (flyActiveNow)
				{
					int player = GET_PLAYER_PED(PlayerSelected);
					SET_PLAYER_INVINCIBLE(player, true);	
					CLEAR_PED_TASKS(player);
					CLEAR_PED_SECONDARY_TASK(player);
					CLEAR_PED_TASKS_IMMEDIATELY(player);
					//SET_PED_TO_RAGDOLL_WITH_FALL(PlayerSelf(), 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
					GIVE_DELAYED_WEAPON_TO_PED(player, Hashes_Weapons_Gadgets::GADGET_PARACHUTE, 9999, 1);
					//APPLY_FORCE_TO_ENTITY(player, 1, 0, GetEntityCoordsVec3(0).x, GetEntityCoordsVec3(0).y ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,1);
					flyActiveNow = false;
				}

				if (isFlyModeActive && !flyActiveNow && IS_ENTITY_IN_AIR && !IS_PED_RAGDOLL)
				{
					APPLY_FORCE(PlayerSelf(), 0, 1, 0.1, 0, 0, 0);
					//APPLY_FORCE_TO_ENTITY(PlayerSelf(), 1, 0, 3, 0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,1);
					//APPLY_FORCE_TO_ENTITY(PlayerSelf(), 1, 0, 3, 6 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,1);
					//APPLY_FORCE_TO_ENTITY(PlayerSelf(), 1, 0, 6, 0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,1);
				}
			}
			*/

			/*
			if (isParachuteSmokeEnabled)
			{
				Random colorR = irand(10, 255);
				Random colorG = irand(10, 255);
				Random colorB = irand(10, 255);

				SET_PLAYER_PARACHUTE_SMOKE_ENABLED(PlayerSelf(), true);
				SET_PLAYER_PARACHUTE_SMOKE_COLOUR(PlayerSelf(), colorR, colorG, colorB);
			}
			*/


			// Fire Feet (Uses Silent Moltov Cocktail)
			if (isFireFeetActive)
			{
				ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(PlayerSelf(), 1), 3, 0.34f, false, false, 0.42f);
			}

			/*
			// Show Coords
			if (isShowCoordsActive)
			{
				char coordsText[50];
				sprintf(coordsText, "~w~X: ~y~%i\n~w~Y: ~y~%i\n~w~Z: ~y~%i", GetEntityCoordsXYZ(PlayerSelf()).x, GetEntityCoordsXYZ(PlayerSelf()).y, GetEntityCoordsXYZ(PlayerSelf()).z);
				DrawText(coordsText, 6, 0.01, 0.01, 0.50, 0.50, Colors::Common::Teal, 255, false);
			}
			*/
			//----------------------------------------------------------

	

			
			//----------------------------------------------------------
			// World Stuff

			// Show In Game Date and Time
			if (showWorldDateTime)
			{
				char timeCrap[100];
				sprintf(timeCrap, "~b~World Time Stats\n~w~Date: ~y~%i-%i-%i\n~w~Time: ~y~%ih:%im:%is", gameYear, gameMonth, gameDayMonth, gameHours, gameMinutes, gameSeconds);
				//PrintText(timeCrap, 3000);
				DrawText(timeCrap, 6, 0.01, 0.01, 0.50, 0.50, Colors::Common::Teal, 255, false);
			}


			/*
			// Weather Control
			if(isWeatherLooped)
			{
				SET_RANDOM_WEATHER_TYPE();
			}
			*/


			/*
			// Freeze Time
			if(isTimeFrozen)
			{
				PAUSE_CLOCK(true);
			}

			if(!isTimeFrozen)
			{
				PAUSE_CLOCK(false);
			}
			*/


			/*
			// Particle FX
			if (particleFxEntityActive)
			{
				int id = GET_PLAYER_PED(SelectedPlayer);
				ParticleFX::START_PARTICLE_FX_LOOPED_ON_ENTITY("scr_trev4_747_blood_impact", id, GetCoordsFromWorld(id).x, GetCoordsFromWorld(id).y, GetCoordsFromWorld(id).z, 0, 0, 0, 30, false, false, false);
			}

			if (particleFxCoordsActive)
			{
				int id = GET_PLAYER_PED(SelectedPlayer);
				ParticleFX::START_PARTICLE_FX_LOOPED_AT_COORD("scr_trev4_747_blood_impact", GetCoordsFromWorld(id).x, GetCoordsFromWorld(id).y, GetCoordsFromWorld(id).z, 0, 0, 0, 30, false, false, false, false);
			}
			*/


			/*
			// Modify Water
			if(ifWaterModify)
			{
				//int SelectedPlayer = PlayerSelf();
				//Vec3 entityCoords = GET_ENTITY_COORDS(SelectedPlayer, true);
				MODIFY_WATER(-394.8745, -102.1641, 40.2580, waterLevel);
			}
			*/
			//----------------------------------------------------------


			
			//----------------------------------------------------------
			// Vehicle Stuff
			


			if (hydraulicsActive)
			{
				int player = GET_PLAYER_PED(PlayerSelected);
				int vehicle = GET_VEHICLE_PED_IS_USING(player);

				if (isJustPressed(Button_R1))
				{
					if(IS_PED_IN_ANY_VEHICLE(player, true))
					{
						if((!IS_PED_IN_ANY_BOAT(player)) && (!IS_PED_IN_ANY_HELI(player)) && (!IS_PED_IN_ANY_PLANE(player)))
						{
							if(IS_VEHICLE_ON_ALL_WHEELS(vehicle))
							{
								APPLY_FORCE(vehicle, 0, 0, hydraulicsHeight, 0, 0, 0.-3);
							}
						}
					}
				}
			}

			if (isHydroJump)
			{
				int player = GET_PLAYER_PED(PlayerSelected);
				int vehicle = GET_VEHICLE_PED_IS_USING(player);

				if (isJustPressed(Button_R1))
				{
					if(IS_PED_IN_ANY_VEHICLE(player, true))
					{
						if((!IS_PED_IN_ANY_BOAT(player)) && (!IS_PED_IN_ANY_HELI(player)) && (!IS_PED_IN_ANY_PLANE(player)))
						{
							if(IS_VEHICLE_ON_ALL_WHEELS(vehicle))
							{
								APPLY_FORCE(vehicle, 0, 0, 12, 0, 0, 0.-3);
							}
						}
					}
				}
			}


			if (isAirJump)
			{
				int player = GET_PLAYER_PED(PlayerSelected);
				int vehicle = GET_VEHICLE_PED_IS_USING(player);

				if (isJustPressed(Button_R1))
				{
					if(IS_PED_IN_ANY_VEHICLE(player, true))
					{
						if((!IS_PED_IN_ANY_BOAT(player)) && (!IS_PED_IN_ANY_HELI(player)) && (!IS_PED_IN_ANY_PLANE(player)))
						{
							APPLY_FORCE(vehicle, 0, 0, 12, 0, 0, 0.-3);
						}
					}
				}
			}



			if (deleteVehicle)
			{
    			Ped playerPed = GET_PLAYER_PED(PlayerSelected);

    			if(IS_PED_IN_ANY_VEHICLE(playerPed, false))
    			{
					Vehicle veh = GET_VEHICLE_PED_IS_IN(GET_PLAYER_PED(PlayerSelected), false);
					bool canDelete = DOES_ENTITY_EXIST(veh);

					if (canDelete)
					{
						SET_ENTITY_AS_MISSION_ENTITY(veh, 1, 1);
						DELETE_VEHICLE(&veh);
    				}
					else
					{
						PrintText("~r~Cannot Delete Vehicle!", 3000);
					}
				}

    			deleteVehicle = false;
			}
			

			if (isStopVehicleNow)
			{
				int player = GET_PLAYER_PED(PlayerSelected);
				int vehicle = GET_VEHICLE_PED_IS_IN(player, false);
				if(IS_PED_IN_ANY_VEHICLE(player, true))
				{
					//SET_VEHICLE_FORWARD_SPEED(player, 0.0f);
					//APPLY_FORCE(vehicle, 0, 0, 0, 0, 0, 0);
					FREEZE_ENTITY_POSITION(vehicle, true);
					sleep(50);
					FREEZE_ENTITY_POSITION(vehicle, false);
				}
			}


			if(doSpawnObjectAttachBuilder)
			{
				uint spawnPropHash = GET_HASH_KEY(spawnPropHashName);
				if (IS_MODEL_VALID(spawnPropHash)) 
				{
					REQUEST_MODEL(spawnPropHash);
					if (HAS_MODEL_LOADED(spawnPropHash))
					{
						Vec3 vehCoords = GET_ENTITY_COORDS(vehOnlineFollow, true);
						Object spawnObjectAttach = CREATE_OBJECT(spawnPropHash, vehCoords.x, vehCoords.y, vehCoords.z, 0, 0, 1);

						// Send to global for attachment prep
						spawnObjectAttachFollow = spawnObjectAttach;

						//char buffer[64];
						//sprintf(buffer, "Object Hash: ~b~%i", spawnObject);
						//PrintText(buffer, 3000);
							
						PrintText("~b~If Object Fails To Attach To Vehicle, Exit Vehicle and Respawn", 3000);

						doSpawnObjectAttachBuilder = false;
					}
				}
			}
			

			if (isVehicleSpawnRequest)
			{
				
				// Only spawn new vehicle if less than max already exists
				if (numberOfSpawnedVehicles <= maxVehicleSpawn)
				{

					REQUEST_MODEL(vehicleUint);
					if(HAS_MODEL_LOADED(vehicleUint))
					{
						float* playerCoords = Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true));

						VehicleUint vehOnline = CREATE_VEHICLE_ALT(vehicleUint, playerCoords, GET_ENTITY_HEADING(PlayerSelf()), 1, 0);
						vehOnlineFollow = vehOnline;

						// Check Object Flag for object creation ONLY if spawn is valid model
						if(doSpawnObjectAttach && vehOnline != 0)
						{
							doSpawnObjectAttachBuilder = true;
						}

						
						// Only execute if vehicleID DOES NOT return 0
						if (vehOnline != 0)
						{
							doSpawnObjectDeleteObject = false;

							// Check Object Flag Again For Attachment
							if (doSpawnObjectAttach)
							{
								//float heading = GET_ENTITY_HEADING(vehOnline);
								//Vector3 rot = GET_ENTITY_ROTATION(vehOnline, 1);

								float pos[3] = { 0.0, 0.0, 0.0 };
								float rotation[3] = { 0.0, 0.0, 0.0 };
								//float rotation[3] = { rot.x, rot.y, rot.z };

								ATTACH_ENTITY_TO_ENTITY_ALT(spawnObjectAttachFollow, vehOnline, 0, pos, rotation, 0, 0, 0, 0, 0, 0);
								
								//SET_ENTITY_HEADING(spawnObjectAttachFollow, heading);
								
								SET_ENTITY_ALPHA(vehOnline, 0, true);

								doSpawnObjectAttach = false;
								doSpawnObjectDeleteObject = true;
							}
				
									
							SET_VEHICLE_ON_GROUND_PROPERLY(vehOnline);
							SET_ENTITY_AS_MISSION_ENTITY(vehOnline, 1, 1);
							//SET_VEHICLE_IS_STOLEN(vehOnline, 0);

							//VEH_TO_NET(vehOnline);
							//SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(VEH_TO_NET(vehOnline), 1);
							//TASK_WARP_PED_INTO_VEHICLE(PlayerSelf(), vehOnline, -1);

							SET_MODEL_AS_NO_LONGER_NEEDED(vehicleUint);
					

							// If player in vehicle, dont put inside car
							if (IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true) == false)
							{
								SET_PED_INTO_VEHICLE(PlayerSelf(), vehOnline, -1);

								SET_VEHICLE_ON_GROUND_PROPERLY(vehOnline);
								SET_ENTITY_AS_MISSION_ENTITY(vehOnline, 1, 1);
								//SET_VEHICLE_IS_STOLEN(vehOnline, 0);

								// Set Current Vehicle Player Is In
								playersCurrentVehicle = GetCurrentVehicle(PlayerSelf());
							}

							if (godmodeOnVehicleMaxOut)
							{
								SET_ENTITY_PROOFS(vehOnline, true, true, true, true, true, true, true, true);
								SET_ENTITY_INVINCIBLE(vehOnline, true);
								SET_ENTITY_CAN_BE_DAMAGED(vehOnline, false);
								SET_VEHICLE_STRONG(vehOnline, true);
							}
						

							// MaxOut
							SET_VEHICLE_MOD_KIT(vehOnline, 0);
							
							//TOGGLE_VEHICLE_MOD(vehOnline, 16, 4);
							TOGGLE_VEHICLE_MOD(vehOnline, 18, 1);

							// Tire Smoke Color
							TOGGLE_VEHICLE_MOD(vehOnline, 20, 1);
							
							TOGGLE_VEHICLE_MOD(vehOnline, 22, 1);
							TOGGLE_VEHICLE_MOD(vehOnline, 23, 1);

							SET_VEHICLE_MOD(vehOnline, 0, 1, 0);
							SET_VEHICLE_MOD(vehOnline, 1, 1, 0);
							SET_VEHICLE_MOD(vehOnline, 2, 1, 0);
							SET_VEHICLE_MOD(vehOnline, 3, 1, 0);
							SET_VEHICLE_MOD(vehOnline, 4, 1, 0);
							SET_VEHICLE_MOD(vehOnline, 5, 1, 0);
							SET_VEHICLE_MOD(vehOnline, 6, 1, 0);
							SET_VEHICLE_MOD(vehOnline, 7, 1, 0);
							SET_VEHICLE_MOD(vehOnline, 8, 1, 0);
							SET_VEHICLE_MOD(vehOnline, 9, 1, 0);
							SET_VEHICLE_MOD(vehOnline, 10, 1, 0);
							SET_VEHICLE_MOD(vehOnline, 11, 3, 0);
							SET_VEHICLE_MOD(vehOnline, 12, 2, 0);
							SET_VEHICLE_MOD(vehOnline, 13, 2, 0);
							SET_VEHICLE_MOD(vehOnline, 14, 14, 0);
							SET_VEHICLE_MOD(vehOnline, 15, 3, 0);
							SET_VEHICLE_MOD(vehOnline, 16, 5, 0);
							SET_VEHICLE_MOD(vehOnline, 22, 13, 1);
							SET_VEHICLE_WINDOW_TINT(vehOnline, 5);
							SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(vehOnline, 0);
							
							// Check if Money Vehicle
							if (isMoneyVehicleCheck)
							{
								SET_VEHICLE_COLOURS(vehOnline, Hashes_Colors::MetallicLime, Hashes_Colors::ModshopBlack1);
								SET_VEHICLE_EXTRA_COLOURS(vehOnline, Hashes_Colors::MetallicLime, Hashes_Colors::MetallicLime);
								SET_VEHICLE_TYRE_SMOKE_COLOR(vehOnline, 0, 255, 35);
								SET_VEHICLE_WHEEL_TYPE(vehOnline, 2);
								SET_VEHICLE_MOD(vehOnline, 23, 11, 1);

								isMoneyVehicle = true;
								isMoneyVehicleActive = true;
								//isMoneyVehicleCheck = false;
								SET_VEHICLE_NUMBER_PLATE_TEXT(vehOnline, "MONEYCAR");
							}
							else
							{
								/*
								0: Sport
								1: Muscle
								2: Lowrider
								3: SUV
								4: Offroad
								5: Tuner
								6: Bike Wheels
								7: High End
								*/
								SET_VEHICLE_COLOURS(vehOnline, Hashes_Colors::ModshopBlack1, Hashes_Colors::ModshopBlack1);
								SET_VEHICLE_EXTRA_COLOURS(vehOnline, Hashes_Colors::ModshopBlack1, Hashes_Colors::ModshopBlack1);
								SET_VEHICLE_TYRE_SMOKE_COLOR(vehOnline, 1, 1, 1);
								SET_VEHICLE_WHEEL_TYPE(vehOnline, 6);
								SET_VEHICLE_MOD(vehOnline, 23, 19, 1);
								SET_VEHICLE_NUMBER_PLATE_TEXT(vehOnline, "ILLICIT");
							}


							// Check if demo
							if (demoMode)
							{
								isMoneyVehicle = false;
								isMoneyVehicleActive = false;
								isMoneyVehicleCheck = false;
								SET_VEHICLE_COLOURS(vehOnline, Hashes_Colors::HotPink, Hashes_Colors::ModshopBlack1);
								SET_VEHICLE_EXTRA_COLOURS(vehOnline, Hashes_Colors::HotPink, Hashes_Colors::HotPink);
								SET_VEHICLE_TYRE_SMOKE_COLOR(vehOnline, 255, 0, 127);
								SET_VEHICLE_WHEEL_TYPE(vehOnline, 6);
								SET_VEHICLE_MOD(vehOnline, 23, 19, 1);
								SET_VEHICLE_NUMBER_PLATE_TEXT(vehOnline, "  DEMO  ");
							}
							else
							{
								null;
							}

							// Increase spawn number for keeping track of # of spawned vehicles
							numberOfSpawnedVehicles++;

							// Add newly spawned vehicle to main list for manager
							spawnedVehicleList[numberOfSpawnedVehicles] = vehOnline;
					
							// Update Vehicle Manager
							isUpdateVehicleManager = true;
						

							//VEH_TO_NET(playersCurrentVehicle);
							SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(VEH_TO_NET(vehOnline), 1);

							// Found in cheat_controller.csc
							//SET_BIT(8, 0);

							// Clone vehOnline to GLOBAL
							vehOnlineFollow = vehOnline;

							// Turn Off after ONE spawns!!
							isVehicleSpawnRequest = false;
						}

					}
				}

				// Delete Some Vehicles if MAX spawned already
				else
				{
					for (int i = 0; i <= 49; i++)
					{
						Vehicle veh = spawnedVehicleList[i];
						SET_ENTITY_AS_MISSION_ENTITY(veh, 1, 1);
						DELETE_VEHICLE(&veh);
						PrintText("~r~SPAWN LIMIT REACHED!\n~w~Deleting Old Spawned Vehicles\n~y~PLEASE BE PATIENT!", 3000);
						sleep(10);
					}

					// Turn Off after ONE spawns!!
					isVehicleSpawnRequest = false;

					// Reset Number of Spawned Vehicles
					numberOfSpawnedVehicles = 0;
				}
			}


			if (deleteLastSpawnedVehicle)
			{
				int vehOnlineFollowInt = vehOnlineFollow;
				bool doesExist = DOES_ENTITY_EXIST(vehOnlineFollow);

				if (!doesExist)
				{
					if (doSpawnObjectDeleteObject)
					{
						int spawnObjectAttachFollow_ = spawnObjectAttachFollow;
						DELETE_OBJECT(&spawnObjectAttachFollow_);
						doSpawnObjectDeleteObject = false;
					}

					deleteLastSpawnedVehicle = false;
					doSpawnObjectDeleteObject = false;

					char buffer[64];
					sprintf(buffer, "Vehicle ID ~b~%i ~r~Does Not Exist ~w~In Memory", vehOnlineFollowInt);
					PrintText(buffer, 3000);
				}
				else
				{
					SET_ENTITY_AS_MISSION_ENTITY(vehOnlineFollowInt, 1, 1);
					DELETE_VEHICLE(&vehOnlineFollowInt);
					deleteLastSpawnedVehicle = false;
				}

			}
			

			
			if (isMoneyVehicle && isMoneyVehicleActive)
			{
				//hashProp = GET_HASH_KEY("prop_money_bag_01");
				int hashPickup = GET_HASH_KEY("PICKUP_MONEY_CASE");
				Vec3 coordsTemp = GET_ENTITY_COORDS(vehOnlineFollow, true);

				// Initial Z Height Adjustment
				coordsTemp.z = coordsTemp.z + 4.5f;

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
			}

			/*
			if (showHeading)
			{
				int player = GET_PLAYER_PED(PlayerSelected);
				float heading;

				if(IS_PED_IN_ANY_VEHICLE(player, true))
				{
					Vehicle vehicle = GET_VEHICLE_PED_IS_IN(player, false);
					heading = GET_ENTITY_HEADING(vehicle);
				}
				else
				{
					heading = GET_ENTITY_HEADING(player);
				}

				int headingInt = (int)heading;

				char buffer[32];
				sprintf(buffer, "Heading: ~b~%i", headingInt);
				DrawText(buffer, 6, 0.376, 0.925, 0.70, 0.70, Colors::Common::Pink, 255, false);
			}
			*/

			
			if (isSpeedometerActive)
			{
				//int player = GET_PLAYER_PED(PlayerSelected);
				int player = PlayerSelf();

				if(IS_PED_IN_ANY_VEHICLE(player, true))
				{
					Vehicle vehicle = GET_VEHICLE_PED_IS_IN(player, false);
					//bool isOnGround = IS_VEHICLE_ON_ALL_WHEELS(vehicle);
					float currentSpeed = GET_ENTITY_SPEED(vehicle);

					int currentSpeedInt;
					currentSpeed = currentSpeed * 2.4;
					currentSpeedInt = (int)currentSpeed;
				
					char buffer[32];
					sprintf(buffer, "%i MPH", currentSpeedInt);

					if (currentSpeedInt >= 0 && currentSpeedInt <= 24)
					{
						DrawText(buffer, 6, 0.076, 0.925, 0.70, 0.70, Colors::Common::Green, 255, false);
					}

					if (currentSpeedInt >= 25 && currentSpeedInt <= 49)
					{
						DrawText(buffer, 6, 0.076, 0.925, 0.75, 0.75, Colors::Common::Yellow, 255, false);
					}

					if (currentSpeedInt >= 50 && currentSpeedInt <= 74)
					{
						DrawText(buffer, 6, 0.076, 0.925, 0.80, 0.80, Colors::Common::Orange, 255, false);
					}

					if (currentSpeedInt >= 75 && currentSpeedInt <= 99)
					{
						DrawText(buffer, 6, 0.076, 0.925, 0.85, 0.85, Colors::Dark::DarkOrange, 255, false);
					}

					//---------------------------------------------------------------------------------
					// Back To The Future Speedometer
					if (currentSpeedInt == 88 && isSpeedometerBTTF)
					{
						if (!isBoostTriggered)
						{
							int alpha = currentSpeedInt - 88;
							//Vec3 coords = GET_ENTITY_COORDS(vehicle, true);
							//Vec3 coords = GET_ENTITY_FORWARD_VECTOR_ALT(vehicle);
							//float heading = GET_ENTITY_HEADING(vehicle);
							//Vec3 velocity = GET_ENTITY_VELOCITY(vehicle);
							//float coordsNew[3] = { coords.x + 100, coords.y, coords.z };
						
							ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(vehicle, 1), 3, 0.34f, false, false, 0.42f);
							SET_ENTITY_ALPHA(player, alpha, true);
							SET_ENTITY_ALPHA(vehicle, alpha, true);
							//APPLY_FORCE(vehicle, 0, 8.8, 0, 0, 0, 0);
							//SET_ENTITY_COORDS(vehicle, coordsNew, 1, 0, 0, 1);
							//SET_ENTITY_VELOCITY(vehicle, velocity.x, velocity.y, velocity.z);
							isBoostTriggered = true;
						}

					}

					if (currentSpeedInt > 88 && isSpeedometerBTTF)
					{
						//int alpha = currentSpeedInt - 88;
						int alpha = 0;
						ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(vehicle, 1), 3, 0.34f, false, false, 0.42f);
						//ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(vehicle, 1), 19, 0.34f, false, false, 0.42f);
						SET_ENTITY_ALPHA(player, alpha, true);
						SET_ENTITY_ALPHA(vehicle, alpha, true);
						isBoostTriggered = true;
					}

					if (currentSpeedInt < 88 && isSpeedometerBTTF)
					{
						SET_ENTITY_ALPHA(player, 255, true);
						SET_ENTITY_ALPHA(vehicle, 255, true);
						isBoostTriggered = false;
					}
					//---------------------------------------------------------------------------------

					if (currentSpeedInt >= 100)
					{
						DrawText(buffer, 6, 0.076, 0.925, 0.90, 0.90, Colors::Common::Red, 255, false);
					}
				}
			}
			

			// Speed Boost Main
			if(isSpeedBoostBinded && IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
			{
				// Adjust Boost Value
				if (isJustPressed(Button_R3_Down))
				{

					if (speedBoostValue < 999 && speedBoostValue > 20 && speedBoostDirection == 0);
					{
						speedBoostValue++;
						speedBoostAdjust(speedBoostDirection, speedBoostValue);
						//sleep(10);
					}

					if (speedBoostValue < 999 && speedBoostDirection == 1)
					{
						speedBoostValue--;
						speedBoostAdjust(speedBoostDirection, speedBoostValue);
						//sleep(10);
					}

					if (speedBoostValue >= 1000)
					{
						speedBoostDirection = 1;
						//sleep(10);
					}

				}
			
				// Do Speed Boost
				if (isJustPressed(Button_R3))
				{
					SET_VEHICLE_FORWARD_SPEED(GetCurrentVehicle(PlayerSelf()), speedBoostValue);
				}
			
				// Reset Back To Default
				if (isJustPressed(Button_L3))
				{
					speedBoostValue = 20;
				}

			}

			/*
			// Vehicle Torque Multiplier
			if(isTorqueModifierActive && IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
			{
				SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(GetCurrentVehicle(PlayerSelf()), torqueValue);
			}
			*/
			
			/*
			// Vehicle Jitter
			if(isVehicleJitterActive && IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
			{
				JITTER_VEHICLE(GetCurrentVehicle(PlayerSelf()), true, -500, -500, -500);
			}
			*/


			// Turn Signals
			if (areBlinkersActive && IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
			{
				
				if (isPressed(Button_L1))
				{
					SET_VEHICLE_INDICATOR_LIGHTS(GetCurrentVehicle(PlayerSelf()), 1, true);
				}

				// Left Blinker Off
				if (isPressed(Button_L1) && isPressed(Button_R2))
				{
					SET_VEHICLE_INDICATOR_LIGHTS(GetCurrentVehicle(PlayerSelf()), 1, false);
				}

				// Right Blinker On
				if (isPressed(Button_R1))
				{
					SET_VEHICLE_INDICATOR_LIGHTS(GetCurrentVehicle(PlayerSelf()), 0, true);
				}

				// Right Blinker Off
				if (isPressed(Button_R1) && isPressed(Button_R2))
				{
					SET_VEHICLE_INDICATOR_LIGHTS(GetCurrentVehicle(PlayerSelf()), 0, false);
				}
			}

			/*
			// Vehicle Density Mod
			if (isVehicleDensityMod)
			{
				SET_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME(9999);
			}
			*/
			//----------------------------------------------------------

			
			

			
			
			//----------------------------------------------------------
			// Nearby Car Stuff

			/*
			// Nearby Cars Detect
			if (isNearbyCarDetectActive)
			{
				int random = irand(0, 159);
				SET_VEHICLE_COLOURS(ClosestVehicleToPlayer(PlayerSelf()), random, random);
			}
			*/

			/*
			// Nearby Car Mayhem
			if (isNearbyCarMayhem)
			{
				int random = irand(0, 159);

				for (int i=0; i<=7; i++)
				{
					SET_VEHICLE_DOOR_BROKEN(ClosestVehicleToPlayer(PlayerSelf()), i, true);
					SMASH_VEHICLE_WINDOW(ClosestVehicleToPlayer(PlayerSelf()), i);
					//SET_VEHICLE_TYRE_BURST(ClosestVehicleToPlayer(PlayerSelf()), i, true, 1000.0);
				}

				SET_VEHICLE_GRAVITY(ClosestVehicleToPlayer(PlayerSelf()), false);
				SET_ENTITY_HAS_GRAVITY(ClosestVehicleToPlayer(PlayerSelf()), false);
				SET_VEHICLE_COLOURS(ClosestVehicleToPlayer(PlayerSelf()), random, random);
				SET_ENTITY_COLLISION(ClosestVehicleToPlayer(PlayerSelf()), false, false);
				//SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(ClosestVehicleToPlayer(PlayerSelf()), torqueValueNearby);

				if (isNearbyCarMayhemBoost) 
				{ 
					SET_VEHICLE_FORWARD_SPEED(ClosestVehicleToPlayer(PlayerSelf()), 15.0);
				}

				else if (isNearbyCarMayhemExplode) 
				{ 
					for (int m=0; m<=7; m++)
					{
						SET_VEHICLE_TYRE_BURST(ClosestVehicleToPlayer(PlayerSelf()), m, true, 1000.0);
					}

					EXPLODE_VEHICLE(ClosestVehicleToPlayer(PlayerSelf()), true, false);
				}

				else if (isNearbyCarMayhemUltimate) 
				{ 
					for (int m=0; m<=7; m++)
					{
						SET_VEHICLE_TYRE_BURST(ClosestVehicleToPlayer(PlayerSelf()), m, true, 1000.0);
					}

					SET_VEHICLE_FORWARD_SPEED(ClosestVehicleToPlayer(PlayerSelf()), 999.999);
					EXPLODE_VEHICLE(ClosestVehicleToPlayer(PlayerSelf()), true, false);
				}

			}
			*/
			
			/*
			// Nearby Cars Vehicle Torque Multiplier
			if(isTorqueModifierNearbyActive)
			{
				SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(ClosestVehicleToPlayer(PlayerSelf()), torqueValueNearby);
			}
			*/
			
			/*
			// Control All Nearby Vehicles
			if (isControlAllNearbyVehicles)
			{
				const int numElements = 10;
				const int arrSize = numElements * 2 + 2;
				Any vehicleTarget[arrSize];
				vehicleTarget[0] = numElements;

				int count = GET_PED_NEARBY_VEHICLES(PlayerSelf(), vehicleTarget);

				if (vehicleTarget != NULL)
				{
					//Simple loop to go through results
					for (int n = 0; n < count; n++)
					{
						int offsettedID = n * 2 + 2;

						//Make sure it exists
						if (vehicleTarget[offsettedID] != NULL && DOES_ENTITY_EXIST(vehicleTarget[offsettedID]))
						{
							//int random = irand(0, 159);
							//SET_VEHICLE_COLOURS(vehicleTarget[offsettedID], random, random);
							SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(vehicleTarget[offsettedID], torqueValueNearby);
						}
					}
				} 

			}
			*/
			//----------------------------------------------------------


	
			//----------------------------------------------------------
			// Keyboard

			if (isKeyboardActive) 
			{
				DISPLAY_ONSCREEN_KEYBOARD(true, "FMMC_KEY_TIP8S", "", "Preset Text", "", "", "", 100);
				isKeyboardDisplayed = true;
			}

			// Loop this in the submenu or in the background of the menu.
			if (isKeyboardDisplayed) {
				switch (UPDATE_ONSCREEN_KEYBOARD()) {
				case 1: // Success
					GET_ONSCREEN_KEYBOARD_RESULT();
					isKeyboardDisplayed = false;
					//isKeyboardActive = false;
					break;
				case 2: 
					break;
				case 3: 
					isKeyboardDisplayed = false; 
					//isKeyboardActive = false;
					break; // Cancelled || Error
				}
			}

			/*
			if (isKeyboardActive)
			{
				//oskResult = GET_ONSCREEN_KEYBOARD_RESULT();
				int updateKB = UPDATE_ONSCREEN_KEYBOARD();

				switch (updateKB)
				{
					case 1: oskResult = GET_ONSCREEN_KEYBOARD_RESULT(); // Finished Editing Input
							isKeyboardActive = false;
					break;
					case 2: isKeyboardActive = false; // Cancelled Editing Input
					break;
					case 3: isKeyboardActive = false; // Keyboard Error
					break;
				}
			}
			*/

			/*
			if (isKeyboardActive)
			{
				//keyboard("", "", "");
				
				int displayOSK = DISPLAY_ONSCREEN_KEYBOARD(0, "PM_NAME_CHALL", "", "", "", "", "", 40);

				char* resultOSK = GET_ONSCREEN_KEYBOARD_RESULT();
				int updateOSK = UPDATE_ONSCREEN_KEYBOARD();

				switch (updateOSK)
				{
					case 1: resultOSK;
					break;
					case 2: PrintText("~y~Keyboard Closing");
							isKeyboardActive = false;
					break;
					case 3: PrintText("~r~Keyboard Error", 2000);
					break;
				}
			}
			*/
			//----------------------------------------------------------

			
			/*
			//----------------------------------------------------------
			// MENU DEBUG OUTPUT LOCATED IN MENU.H
			
			// NETWORK DEBUG OPTIONS
			if (isDebugNetworkActive)
			{
				//HudOverlay("Network Debug Output", 1, false);

				// Network Debug Output
				//char debugNetwork1[32];
				//sprintf(debugNetwork1, "Network Debug Output");
				//DrawText(debugNetwork1, 7, 0.01, 0.25, 0.50, 0.50, Colors::Common::Teal, 255, false);	
					
				// Network Items To Show
				//char debugNetwork2[200];
				//sprintf(debugNetwork2, "DEV: %i\nPSN: %i\nNP: %i\nH: %i\nPED: %i", NETWORK_PLAYER_IS_ROCKSTAR_DEV(SelectedPlayer), NETWORK_IS_CLOUD_AVAILABLE, NETWORK_GET_NUM_CONNECTED_PLAYERS(), isHostNowAny, GetPlayerPedID(SelectedPlayer));
				//DrawText(debugNetwork2, 6, 0.01, 0.30, 0.50, 0.50, Colors::Common::Green, 255, false);	
					
				// Network Items To Show
				//char debugNetwork3[250];
				//sprintf(debugNetwork3, "PLAYER_IS_BADSPORT: %i\nPLAYER_IS_CHEATER: %i\nIS_PLAYER_ACTIVE: %i\nCAN_ENTER_MULTIPLAYER: %i", NETWORK_PLAYER_IS_BADSPORT, NETWORK_PLAYER_IS_CHEATER, IsNetworkPlayerActive, NETWORK_CAN_ENTER_MULTIPLAYER);
				//DrawText(debugNetwork3, 6, 0.01, 0.50, 0.50, 0.50, Colors::Common::Green, 255, false);	
			}
			

			// PLAYERS DEBUG OUTPUT
			if (isDebugPlayersActive)
			{
				//SystemTimer();

				char debugPlayer1[32];
				sprintf(debugPlayer1, "Players Debug Output");
				DrawText(debugPlayer1, 7, 0.01, 0.60, 0.50, 0.50, Colors::Common::Teal, 255, false);	

				char debugPlayer2[250];
				//sprintf(debugPlayer2, "~w~N: ~y~%s\n~w~CP: ~y~%i\n~w~Host: ~y~%i\n~w~ST: ~y~%i\n~w~GT: ~y~%i", NameCurrent, PlayerCurrent, isHostNowAny, elapse, GET_GAME_TIMER());
				sprintf(debugPlayer2, "~w~N: ~y~%s\n~w~CP: ~y~%i\n~w~Host: ~y~%i\n~w~i: ~y~%i\n~w~CM: ~y~%i", NameCurrent, PlayerCurrent, isHostNowAny, iFollow, currentMenuFollow);
				//sprintf(debugPlayer2, "~w~N: ~y~%s\n~w~CP: ~y~%i\n~w~Host: ~y~%i\n~w~i: ~y~%i\n~w~Wait: ~y~%i", NameCurrent, PlayerCurrent, isHostNowAny, iFollow, Wait);
				DrawText(debugPlayer2, 6, 0.01, 0.65, 0.50, 0.50, Colors::Common::Pink, 255, false);
				
				
				//int nameSlot[15];
				//char* nameSlotChar[250];

				
				for (int i = 0; i < 16; i++)
				{
					//nameSlot[i];
					//nameSlotChar[nameSlot[i]] = GET_PLAYER_NAME(i);
					
					char debugPlayer1[32];
					sprintf(debugPlayer1, "Players Debug Output");
					DrawText(debugPlayer1, 7, 0.01, 0.60, 0.50, 0.50, Colors::Common::Teal, 255, false);	

					char debugPlayer2[250];
					sprintf(debugPlayer2, "~w~Name: ~y~%s\n~w~Player: ~y~%i\n~w~Host: ~y~%i\n~w~i: ~y~%i\n~w~Menu: ~y~%i", NameCurrent, PlayerCurrent, isHostNowAny, iFollow, MenuFollow);
					DrawText(debugPlayer2, 6, 0.01, 0.65, 0.50, 0.50, Colors::Common::Pink, 255, false);
				}

			}
			
			//----------------------------------------------------------
			*/


			
			
			//----------------------------------------------------------
			// Ped Stuff
			
			/*
			// Fleeing Peds
			if (isPedFleeing)
			{
				SET_ALL_RANDOM_PEDS_FLEE_THIS_FRAME(GET_PLAYER_PED(SelectedPlayer));
			}
			*/

			/*
			// Ped Wetness
			if (isPedWet)
			{
				SET_PED_WETNESS_HEIGHT(GetPlayerPedID(PlayerSelected), 100);
				SET_PED_WETNESS_ENABLED_THIS_FRAME(GET_PLAYER_PED(PlayerSelected));
			}
			*/

			

			// Weapons
			
			
			if (isAmmoExplosive)
			{
				SET_EXPLOSIVE_AMMO_THIS_FRAME(PlayerID());
			}
			

			
			if (isAmmoFire)
			{
				SET_FIRE_AMMO_THIS_FRAME(PlayerID());
			}
			

			
			if (isMeleeExplosive)
			{
				SET_EXPLOSIVE_MELEE_THIS_FRAME(PlayerID());
			}
			
			//----------------------------------------------------------


			
			
			// Update Players Menu
			if (isUpdatePlayersMenu)
			{
				UpdatePlayersMenu();
				isUpdatePlayersMenu = false;	
			}

			// Update Vehicle Manager
			if (isUpdateVehicleManager)
			{
				if (isMoneyVehicleCheck)
				{
					//
				}
				updateVehicleManager();
				isUpdateVehicleManager = false;
			}


			
			/*
			// Exit Thread
			if (isThreadExit)
			{
				system_call_1(41, 0);
				isThreadExit = false;
			}
			*/



			
			// END LOOPING
			


			// Not needed???
			//return IS_PLAYER_ONLINE();

			if (!isOpen)
			{
				ResetGameTimer();
			}


			// Without this, PSN will not show signed in
            Delay.Restart();
			
        }
}


void Hook2(int timer)
{
	GameTimer2(25);
	if (hook2Active && isGameTimerReady2())
    {
		//executeHookedFunc();

		if (!isOpen)
		{
			//
		}


		if (isOpen)
		{
			PrintText("Hook 2 Running", 1);
		}
		
		
		//ResetGameTimer2();
        Delay.Restart();
	}
}


/*
OLD HOOK (ONLINE BROKEN)
void Hook()
{
	executeHookedFunc();
	if (isOpen) drawMenu();
	else ENABLE_ALL_CONTROL_ACTIONS();

	Stub(0);

	// BEGIN LOOPING

	// Insert Loop Stuff Here

	


	// END LOOPING

}
*/


void Monitor(uint64_t)
{
	// Default Init Sleep
	sleep(2000);


	// Build Default Menu Structure
	createMenuStruct();


	// Monitor Buttons While Running
	for (;;)
	{
		// ISCLOSED
		if (!isOpen)
		{
			if (isDown(Button_SQUARE) && isDown(Dpad_Left))
			{
				isOpen = true;
				sleep(100);


				// Display Menu Splash Text ONLY on First Launch
				if (menuCounter == 0)
				{
					isMenuSoundSplash = true;
					// 101 Char Max for PRINT???
					PrintText(cellRequestPPU, 6000);
					//DrawNotify("Welcome To iLLiCiT SPRX Menu", "CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 4, false, "ps3dg.com", "");
					//wait(7000);
					//PrintText(cellRequestPPU2, 5000);
					sleep(100);
				}
				
				// Increment Menu Counter By 1 For Each Use
				// Used for controlling splash text to display on first run only
				menuCounter++;


			}// END ISDOWN OPEN BUTTONS


			
			




		}// END IF ISCLOSED


		// Default actions for buttons
		else
		{
			
			// Navigate menu UP and DOWN while open
			if (isJustPressed(Dpad_Up) || isJustPressed(Dpad_Down))
			{
				currentOption += isJustPressed(Dpad_Down) ? 1 : -1;
				currentOption = currentOption < 0 ? subOptionCount[currentMenu] - 1 : currentOption > subOptionCount[currentMenu] - 1 ? 0 : currentOption;
				sleep(100);
			}
			

			/*
			// Navigate menu UP and DOWN while open
			if (!isDown(Dpad_Up) && !isDown(Dpad_Down) && isJustPressed(Dpad_Up) || isJustPressed(Dpad_Down))
			{
				currentOption += isJustPressed(Dpad_Down) ? 1 : -1;
				currentOption = currentOption < 0 ? subOptionCount[currentMenu] - 1 : currentOption > subOptionCount[currentMenu] - 1 ? 0 : currentOption;
				sleep(100);
			}


			// Navigate menu UP and DOWN while open and WHILE HOLDING BUTTON
			if (!isJustPressed(Dpad_Up) && !isJustPressed(Dpad_Down) && isDown(Dpad_Up) || isDown(Dpad_Down))
			{
				currentOption += isDown(Dpad_Down) ? 1 : -1;
				currentOption = currentOption < 0 ? subOptionCount[currentMenu] - 1 : currentOption > subOptionCount[currentMenu] - 1 ? 0 : currentOption;
				sleep(100);
			}
			*/


			if (isJustPressed(Dpad_Left) || isJustPressed(Dpad_Right))
			{
				//int random = irand(0, 15);
				
				// If LEFT Pressed
				if (isJustPressed(Dpad_Left))
				{
					
					if (moneyCoordsAdjustX_ && currentMenu == MenuMoneyCoords)
					{
						moneyCoordsAdjustY_ = false;
						moneyCoordsAdjustZ_ = false;
						moneyCoordsAdjustX = moneyCoordsAdjustX -= 0.1;
					}
					
					if (moneyCoordsAdjustY_ && currentMenu == MenuMoneyCoords)
					{
						moneyCoordsAdjustX_ = false;
						moneyCoordsAdjustZ_ = false;
						moneyCoordsAdjustY = moneyCoordsAdjustY -= 0.1;
					}
					
					if (moneyCoordsAdjustZ_ && currentMenu == MenuMoneyCoords)
					{
						moneyCoordsAdjustX_ = false;
						moneyCoordsAdjustY_ = false;
						moneyCoordsAdjustZ = moneyCoordsAdjustZ -= 0.1;
					}

					/*
					if (currentOptionFollow == "< Increase RP >")
					{
						if (rankValueModifier < 0)
						{
							rankValueModifier = 4096;
						}

						rankValueModifier = rankValueModifier -= 2048;

						char buffer[64];
						sprintf(buffer, "~w~Rank Value: ~y~%i", rankValueModifier);
						PrintText(buffer);
					}
					*/

					if (currentOptionFollow == "< Explode >")
					{
						ExplosionSelectPrev();
						sleep(100);
					}

					/*
					if (currentOptionFollow == "< Change Dirt Level >")
					{
						DirtLevelLess();
						sleep(100);
					}
					*/

					/*
					if (currentOptionFollow == "Wheel Type")
					{
						WheelTypeChange();
						sleep(100);

						char buffer[64];
						sprintf(buffer, "~w~Wheel Type: ~b~%i", wheelType);
						PrintText(buffer);
					}
					*/

					if (hydraulicsActive && currentOptionFollow == "< Hydraulics >")
					{
						HydraulicsHeightDown = true;
						HydraulicsHeightControl();
						sleep(100);
						HydraulicsHeightDown = false;

						char buffer[64];
						sprintf(buffer, "~w~Hydraulics Height: ~b~%i", hydraulicsHeight);
						PrintText(buffer);
					}
		

					
					if (adjustPlayerSelect && currentOptionFollow != "< Hydraulics >" && currentOptionFollow != "< Wheel Type >" && currentOptionFollow != "< Increase RP >" && currentOptionFollow != "< Change Dirt Level >" && currentOptionFollow != "< Explode >" && currentMenu != MenuPlayerSelfToggles && currentMenu != MenuRecoveryRank && currentMenu != MenuMoneyCoords)
					{
						PlayerSelectedPrev();
						sleep(100);

						char buffer[64];
						sprintf(buffer, "~w~ID: ~b~%i\n~w~Name: ~y~%s", PlayerSelected, GET_PLAYER_NAME(PlayerSelected));
						PrintText(buffer);
					}

					/*
					if (currentMenu == MenuPlayerSelfToggles)
					{
						WantedLevelDecrease();
					}
					*/
				}


				// If RIGHT Pressed
				if (isJustPressed(Dpad_Right))
				{
					
					if (moneyCoordsAdjustX_ && currentMenu == MenuMoneyCoords)
					{
						moneyCoordsAdjustY_ = false;
						moneyCoordsAdjustZ_ = false;
						moneyCoordsAdjustX = moneyCoordsAdjustX += 0.1;
					}
					
					if (moneyCoordsAdjustY_ && currentMenu == MenuMoneyCoords)
					{
						moneyCoordsAdjustX_ = false;
						moneyCoordsAdjustZ_ = false;
						moneyCoordsAdjustY = moneyCoordsAdjustY += 0.1;
					}
					
					if (moneyCoordsAdjustZ_ && currentMenu == MenuMoneyCoords)
					{
						moneyCoordsAdjustX_ = false;
						moneyCoordsAdjustY_ = false;
						moneyCoordsAdjustZ = moneyCoordsAdjustZ += 0.1;
					}

					if (currentOptionFollow == "< Explode >")
					{
						ExplosionSelectNext();
						sleep(100);
					}

					/*
					if (currentOptionFollow == "< Change Dirt Level >")
					{
						DirtLevelMore();
						sleep(100);
					}
					*/

					/*
					if (currentOptionFollow == "< Increase RP >")
					{
						if (rankValueModifier < 0)
						{
							rankValueModifier = 4096;
						}

						rankValueModifier = rankValueModifier += 2048;

						char buffer[64];
						sprintf(buffer, "~w~Rank Value: ~y~%i", rankValueModifier);
						PrintText(buffer);
					}
					*/

					/*
					if (currentOptionFollow == "Wheel Type")
					{
						WheelTypeChange();
						sleep(100);

						char buffer[64];
						sprintf(buffer, "~w~Wheel Type: ~b~%i", wheelType);
						PrintText(buffer);
					}
					*/

					if (hydraulicsActive)
					{
						HydraulicsHeightUp = true;
						HydraulicsHeightControl();
						sleep(100);
						HydraulicsHeightUp = false;

						char buffer[64];
						sprintf(buffer, "~w~Hydraulics Height: ~b~%i", hydraulicsHeightAdjust);
						PrintText(buffer);
					}


					if (adjustPlayerSelect && currentOptionFollow != "< Hydraulics >" && currentOptionFollow != "< Wheel Type >" && currentOptionFollow != "< Increase RP >" && currentOptionFollow != "< Change Dirt Level >"  && currentOptionFollow != "< Explode >" && currentMenu != MenuPlayerSelfToggles && currentMenu != MenuMoneyCoords)
					{
						PlayerSelectedNext();
						sleep(100);

						char buffer[64];
						sprintf(buffer, "~w~ID: ~b~%i\n~w~Name: ~y~%s", PlayerSelected, GET_PLAYER_NAME(PlayerSelected));
						PrintText(buffer);
					}
				}

				/*
				if (currentMenu == MenuPlayerSelfToggles)
				{
					WantedLevelIncrease();
				}
				*/
			}



			// Select menu item button
			if (isJustPressed(Button_CROSS))
			{
				isMenuSoundSelect = true;

				if (optionFunctionHooked[currentMenu][currentOption])
				{
					executeOptionFunc = true;
				}
				else
				{
					((void(*)(int))optionFunction[currentMenu][currentOption])(optionFunctionParam[currentMenu][currentOption]);
				}

				sleep(100);
			}
			
			
			/*
			// Function Loop Button Combo Start
			if (isDown(Button_L1) && isDown(Button_CROSS))
			{
				executeOptionFuncLoop = true;
				//if (optionFunctionHooked[currentMenu][currentOption]) executeOptionFuncLoop = true;
				//else ((void(*)(int))optionFunction[currentMenu][currentOption])(optionFunctionParam[currentMenu][currentOption]);
				//sleep(100);
				PrintText("~g~Function Loop Started!\n~w~L1~y~+~w~L2~y~+~b~X~y~ To Stop", 3000);
			}
			*/
			
			/*
			// Function Loop Button Combo Stop
			if (isDown(Button_L1) && isDown(Button_L2) && isDown(Button_CROSS))
			{
				executeOptionFuncLoop = false;
				PrintText("~r~Function Loop Stopped!", 3000);
			}
			*/

			// Return to previous menu button
			if (isJustPressed(Button_SQUARE))
			{
				isMenuSoundBack = true;

				if (previousSub[currentMenu] != -1)
				{
					openSub(previousSub[currentMenu]);
				}
				else 
				{
					isOpen = false;

					// Reset Help Text On 1st Open
					seenHelpMenuRank = 0;
					seenHelpMoneyCoords = 0;
					seenHelpSelectedPlayer = 0;
					seenHelpVehicleManager = 0;

					// Reset Warning Text On 1st Open
					//seenWarningGiveAllWeaponsLobby = 0;
					seenWarningTalkingPunish = 0;
				}
				sleep(100);
			}


			
		}// END ELSE STATEMENT


		
		// THIS AREA BELOW CAN RUN WITHOUT MENU DISPLAYED
		
		


				
		// Default Micro Sleep After Menu Button Check
		// Leave This At The Bottom
		sleep(20);

	}// END MAIN FOR (;;) STATEMENT

	

      
} // END MAIN MONITOR FUNCTION






// PS3 System PRX Loading


SYS_LIB_DECLARE_WITH_STUB(LIBNAME, SYS_LIB_AUTO_EXPORT, STUBNAME);
SYS_LIB_EXPORT(MainExport, LIBNAME);

extern "C" int MainExport(void)
{
    return CELL_OK;
}


SYS_MODULE_INFO(illicit, 0, 1, 1);
SYS_MODULE_START(Main);

extern "C" int Main(void)
{
	// Read License File
	//ReadLicense();

	// Check For Valid License
	//CheckLicense();

	// Anti-Check Initialize*
	cellPS3EnumInt32();

	// Main Splash Dialog
	if (cellPRXInt4 && cellPRXInt16)
	{

		//CheckLicense();
		//ReadFile();

		// Temp fix until licensing issues resolved
		//LicenseVerified = true;

		/*
		if (LicenseVerified)
		{
			// Show Normal Welcome Message
			msgdialog_mode = MODE_STRING_OK;
			Show(cellWebRequest());
		}
		else
		{
			// Show NO LICENSE Welcome Message
			msgdialog_mode = MODE_STRING_OK;
			Show(cellWebRequestNL());
		}
		*/

		msgdialog_mode = MODE_STRING_OK;
		Show(cellWebRequest());

		// If all anti checks pass, then set this BOOL to TRUE to use here after
		cellPS3XBOX = true;
	}

	else
	{
		// Show Pirated/Modification message
		msgdialog_mode = MODE_STRING_OK;
		Show(cellWebRequestHTTPS());

		// If ANY of the anti checks fail, then set this BOOL to FALSE to use here after
		cellPS3XBOX = false;
	}



	// Different Hooks (Only Use One!!)
	//hookFunctionStart(0x3E33C0, (int)Stub, (int)Hook);// Blank Menu DEX
	//hookFunctionStartAlt(0x3E33C0, (int)Stub, (int)Hook);// Blank Menu DEX
	//hookFunctionStart(0x3E38B0, (int)is_player_online_stub, (int)Hook);// This one works
	//hookFunctionStart(IS_PLAYER_ONLINE, (int)Stub, (int)Hook);// This one works
	hookFunctionStart(0x3E3A20, (int)IS_PLAYER_ONLINE, (int)Hook);// This one works
	//hookFunctionStart(0x422B94, (int)IS_PLAYER_PLAYING, (int)Hook2);// This one works
	//hookFunctionStart(0x423F30, (int)IS_PLAYER_SCRIPT_CONTROL_ON, (int)Hook2);
	//hookFunctionStartAlt(0x3E38B0, (int)Stub, (int)Hook);
	
	sys_ppu_thread_t MainThread;
	sys_ppu_thread_create(&MainThread, Monitor, 0, 2000, 0x5000, 0, "iLLiCiT GTAV SPRX Menu");

	return SYS_PRX_RESIDENT;
}
