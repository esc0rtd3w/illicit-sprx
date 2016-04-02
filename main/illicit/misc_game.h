#ifndef __MISC_GAME_
#define __MISC_GAME_



#include "functions.h"
#include "hashes.h"
#include "hud.h"
#include "licensing.h"
#include "messages.h"
#include "misc.h"
#include "natives.h"

using namespace Dialog;
using namespace Functions;
using namespace Hashes;
using namespace Hud;
using namespace Keyboard;
using namespace Licensing;
using namespace Misc;
using namespace Natives;



// Misc
namespace Misc_f
{

	
	/*
	bool adjustLRT = false;
	bool adjustUDT = false;
	void TestDpad(int test)
	{
		switch(test)
		{
			case 1: 
				adjustLRT = !adjustLRT;
				adjustLR = adjustLRT;
				MsgToggleDefault("Dpad Test Left/Right", adjustLRT);
			break;

			case 2:
				adjustUDT = !adjustUDT;
				adjustUD = adjustUDT;
				MsgToggleDefault("Dpad Test Up/Down", adjustUDT);
			break;
		}
	}
	*/
		
	// Toggle Credits Screen
	bool creditsAreActive = false;
	void ToggleEndCredits(int dummy)
	{
		creditsAreActive = !creditsAreActive;
		SET_CREDITS_ACTIVE(creditsAreActive);
		MsgToggleDefault("Credits", creditsAreActive);
	}
	

	/*
	void BeginSRL(int dummy)
	{
		//if (IS_SRL_LOADED() == true)
		//{
			SET_SRL_TIME(5000);
			BEGIN_SRL();
		//}
	}
	*/

	/*
	void EndSRL(int dummy)
	{
		END_SRL();
	}
	*/

		
	/*
	// Toggle Laser Sight
	bool laserSightActive = false;
	void ToggleLaserSight(int dummy)
	{
		laserSightActive = !laserSightActive;
		ENABLE_LASER_SIGHT_RENDERING(laserSightActive);
		PrintText(laserSightActive ? "~g~Laser Sight Activated" : "~r~Laser Sight Deactivated" , 3000);
	}
	
		
		
	/*
	// Toggle Credits Music
	bool creditMusicIsActive = false;
	void ToggleEndCreditsMusic(int dummy)
	{
		creditMusicIsActive = !creditMusicIsActive;
		PLAY_END_CREDITS_MUSIC(creditMusicIsActive);
		PrintText(creditMusicIsActive ? "~g~Credits Music Activated" : "~r~Credits Music Deactivated" , 3000);
	}
	*/
		
	// Game Pause
	bool gameIsPaused = false;
	void TogglePauseGame(int dummy)
	{
		gameIsPaused = !gameIsPaused;
		SET_GAME_PAUSED(gameIsPaused);
		PrintText(gameIsPaused ? "~b~Game Paused" : "~b~Game Resumed" , 3000);
	}

	/*
	// Game Pause Active
	bool pauseMenuActive = IS_PAUSE_MENU_ACTIVE();
	bool pauseMenuActiveState = GET_PAUSE_MENU_STATE();
	void GetPauseState(int dummy)
	{
		//pauseMenuActive = !pauseMenuActive;
		char msg[32];
		sprintf(msg, "Active: %s\nState: %s", pauseMenuActive, pauseMenuActiveState);
		PrintText(msg , 3000);
	}
	*/

	void LaunchSingleplayerGame(int dummy)
	{
		SHUTDOWN_AND_LAUNCH_SINGLE_PLAYER_GAME();
		PrintText("~b~Launching Single Player Mode!" , 3000);
	}

	/*
	void ShutdownLoadingScreen(int dummy)
	{
		SHUTDOWN_LOADING_SCREEN();
	}
	*/


	/*
	void DeathHorn(int dummy)
	{
		bool isPlayerPressingHorn = IS_PLAYER_PRESSING_HORN(PlayerSelf());

		if (isPlayerPressingHorn == true)
		{
			PlayerSelf_f::ExplodePlayer(0);
		}
			
	}
	*/


	/*
	void AimCheater()
	{
		DrawText("o", 1, 0.50, 0.40, 0.30, 0.30, Colors::Common::Red, 255, true);
		//DrawText("o", 1, 0.50, 0.45, 0.40, 0.40, Colors::Common::Red, 255, true);
		//DrawText("o", 1, 0.50, 0.45, 0.50, 0.50, Colors::Common::Red, 255, true);
		//DrawText("o", 1, 0.50, 0.55, 0.60, 0.70, Colors::Common::Red, 255, true);
	}
	*/

	// Skip The Bullshit
	void SkipTheBullshit(int dummy)
	{
		SKIP_TO_NEXT_SCRIPTED_CONVERSATION_LINE();
		STOP_CUTSCENE_IMMEDIATELY();
		PrintText("~b~Skipping Current Dialog and Cutscene!" , 3000);
	}

		

	/*
	void StopCutsceneImmediately(int dummy)
	{
		STOP_CUTSCENE_IMMEDIATELY();
	}
	*/

	/*
	void StopAllAlarms(int dummy)
	{
		STOP_ALL_ALARMS(true);
	}
	*/

	/*
	void RandomTest(int test)
	{
		int random = irand(0, 255);
		char randomTest[16];
		sprintf(randomTest, "%i", random);
		PrintText(randomTest, 3000);
	}
	*/

	/*
	// Autosave Trigger with Check
	void DoAutoSave(int dummy)
	{
		bool isAutoSaveInProgress = IS_AUTO_SAVE_IN_PROGRESS();

		if (isAutoSaveInProgress == false)
		{
			DO_AUTO_SAVE();
			PrintText("~g~Triggering AutoSave Function", 3000);
		}

		else
		{
			PrintText("~r~AutoSave Is Currently Running", 3000);
		}
	}
	*/
		
	// Time Cycle Modifier
	const char* timeCycle;
	void TimeCycleModifier(int style)
	{
		if (style == 0) 
		{ 
			// Do Random
			//int random = irand(0, 78);
			//CLEAR_TIMECYCLE_MODIFIER();
			//sleep(10);
			//SET_TIMECYCLE_MODIFIER(timeCycle); 
		}

		//if (style == 1) { SET_TIMECYCLE_MODIFIER("Bank_HLWD"); }
		if (style == 2) { SET_TIMECYCLE_MODIFIER("Barry1_Stoned"); }
		if (style == 3) { SET_TIMECYCLE_MODIFIER("BlackOut"); }
		if (style == 4) { SET_TIMECYCLE_MODIFIER("BulletTimeDark"); }
		//if (style == 5) { SET_TIMECYCLE_MODIFIER("BulletTimeLight"); }
		if (style == 6) { SET_TIMECYCLE_MODIFIER("CAMERA_BW"); }
		if (style == 7) { SET_TIMECYCLE_MODIFIER("CAMERA_secuirity"); }
		if (style == 8) { SET_TIMECYCLE_MODIFIER("CAMERA_secuirity_FUZZ"); }
		if (style == 9) { SET_TIMECYCLE_MODIFIER("CHOP"); }
		if (style == 10) { SET_TIMECYCLE_MODIFIER("cinema"); }
		if (style == 11) { SET_TIMECYCLE_MODIFIER("cinema_001"); }
		//if (style == 12) { SET_TIMECYCLE_MODIFIER("cops"); }
		if (style == 13) { SET_TIMECYCLE_MODIFIER("CopsSPLASH"); }
		if (style == 14) { SET_TIMECYCLE_MODIFIER("crane_cam"); }
		if (style == 15) { SET_TIMECYCLE_MODIFIER("crane_cam_cinematic"); }
		if (style == 16) { SET_TIMECYCLE_MODIFIER("damage"); }
		if (style == 17) { SET_TIMECYCLE_MODIFIER("death"); }
		if (style == 18) { SET_TIMECYCLE_MODIFIER("Dont_tazeme_bro"); }
		if (style == 19) { SET_TIMECYCLE_MODIFIER("dont_tazeme_bro_b"); }
		if (style == 20) { SET_TIMECYCLE_MODIFIER("DRUG_2_drive"); }
		if (style == 21) { SET_TIMECYCLE_MODIFIER("drug_drive_blend01"); }
		if (style == 22) { SET_TIMECYCLE_MODIFIER("drug_drive_blend02"); }
		if (style == 23) { SET_TIMECYCLE_MODIFIER("Drug_deadman"); }
		//if (style == 24) { SET_TIMECYCLE_MODIFIER("Drug_deadman_blend"); }
		if (style == 25) { SET_TIMECYCLE_MODIFIER("drug_flying_01"); }
		if (style == 26) { SET_TIMECYCLE_MODIFIER("drug_flying_02"); }
		if (style == 27) { SET_TIMECYCLE_MODIFIER("drug_flying_base"); }
		if (style == 28) { SET_TIMECYCLE_MODIFIER("drug_wobbly"); }
		if (style == 29) { SET_TIMECYCLE_MODIFIER("Drunk"); }
		if (style == 30) { SET_TIMECYCLE_MODIFIER("dying"); }
		//if (style == 31) { SET_TIMECYCLE_MODIFIER("DrivingFocusDark"); }
		//if (style == 32) { SET_TIMECYCLE_MODIFIER("DrivingFocusLight"); }
		if (style == 33) { SET_TIMECYCLE_MODIFIER("eyeINtheSKY"); }
		//if (style == 34) { SET_TIMECYCLE_MODIFIER("FIB_interview"); }
		//if (style == 35) { SET_TIMECYCLE_MODIFIER("FRANKLIN"); }
		if (style == 36) { SET_TIMECYCLE_MODIFIER("DRUG_gas_huffin"); }
		//if (style == 37) { SET_TIMECYCLE_MODIFIER("Hint_cam"); }
		//if (style == 38) { SET_TIMECYCLE_MODIFIER("hitped"); }
		if (style == 39) { SET_TIMECYCLE_MODIFIER("hud_def_blur"); }
		//if (style == 40) { SET_TIMECYCLE_MODIFIER("int_Hospital_Blue"); }
		//if (style == 41) { SET_TIMECYCLE_MODIFIER("micheal"); }
		//if (style == 42) { SET_TIMECYCLE_MODIFIER("phone_cam"); }
		//if (style == 43) { SET_TIMECYCLE_MODIFIER("phone_cam1"); }
		//if (style == 44) { SET_TIMECYCLE_MODIFIER("phone_cam2"); }
		//if (style == 45) { SET_TIMECYCLE_MODIFIER("phone_cam3"); }
		//if (style == 46) { SET_TIMECYCLE_MODIFIER("phone_cam4"); }
		//if (style == 47) { SET_TIMECYCLE_MODIFIER("phone_cam5"); }
		//if (style == 48) { SET_TIMECYCLE_MODIFIER("phone_cam6"); }
		//if (style == 49) { SET_TIMECYCLE_MODIFIER("phone_cam7"); }
		//if (style == 50) { SET_TIMECYCLE_MODIFIER("phone_cam8"); }
		//if (style == 51) { SET_TIMECYCLE_MODIFIER("phone_cam9"); }
		//if (style == 52) { SET_TIMECYCLE_MODIFIER("phone_cam10"); }
		//if (style == 53) { SET_TIMECYCLE_MODIFIER("phone_cam11"); }
		//if (style == 54) { SET_TIMECYCLE_MODIFIER("phone_cam12"); }
		//if (style == 55) { SET_TIMECYCLE_MODIFIER("phone_cam13"); }
		//if (style == 56) { SET_TIMECYCLE_MODIFIER("prologue"); }
		if (style == 57) { SET_TIMECYCLE_MODIFIER("prologue_ending_fog"); }
		//if (style == 58) { SET_TIMECYCLE_MODIFIER("prologue_ext_art_amb"); }
		//if (style == 59) { SET_TIMECYCLE_MODIFIER("prologue_reflection_opt"); }
		if (style == 60) { SET_TIMECYCLE_MODIFIER("prologue_shootout"); }
		if (style == 61) { SET_TIMECYCLE_MODIFIER("Prologue_shootout_opt"); }
		if (style == 62) { SET_TIMECYCLE_MODIFIER("secret_camera"); }
		//if (style == 63) { SET_TIMECYCLE_MODIFIER("scope_zoom_in"); }
		//if (style == 64) { SET_TIMECYCLE_MODIFIER("scope_zoom_out"); }
		//if (style == 65) { SET_TIMECYCLE_MODIFIER("SheriffStation"); }
		//if (style == 66) { SET_TIMECYCLE_MODIFIER("spectator1"); }
		//if (style == 67) { SET_TIMECYCLE_MODIFIER("spectator2"); }
		//if (style == 68) { SET_TIMECYCLE_MODIFIER("spectator3"); }
		//if (style == 69) { SET_TIMECYCLE_MODIFIER("spectator4"); }
		//if (style == 70) { SET_TIMECYCLE_MODIFIER("spectator5"); }
		//if (style == 71) { SET_TIMECYCLE_MODIFIER("spectator6"); }
		//if (style == 72) { SET_TIMECYCLE_MODIFIER("spectator7"); }
		//if (style == 73) { SET_TIMECYCLE_MODIFIER("spectator8"); }
		//if (style == 74) { SET_TIMECYCLE_MODIFIER("spectator9"); }
		//if (style == 75) { SET_TIMECYCLE_MODIFIER("spectator10"); }
		if (style == 76) { SET_TIMECYCLE_MODIFIER("stoned"); }
		if (style == 77) { SET_TIMECYCLE_MODIFIER("stoned_aliens"); }
		//if (style == 78) { SET_TIMECYCLE_MODIFIER("stoned_monkeys"); }
		//if (style == 79) { SET_TIMECYCLE_MODIFIER("sunglasses"); }
		//if (style == 80) { SET_TIMECYCLE_MODIFIER("superDARK"); }
		if (style == 81) { SET_TIMECYCLE_MODIFIER("telescope"); }
		if (style == 82) { SET_TIMECYCLE_MODIFIER("traffic_skycam"); }
		if (style == 83) { SET_TIMECYCLE_MODIFIER("ufo"); }
		if (style == 84) { SET_TIMECYCLE_MODIFIER("ufo_deathray"); }
		//if (style == 85) { SET_TIMECYCLE_MODIFIER("underwater"); }
		//if (style == 86) { SET_TIMECYCLE_MODIFIER("underwater_deep"); }
		//if (style == 87) { SET_TIMECYCLE_MODIFIER("underwater_deep_clear"); }
		//if (style == 88) { SET_TIMECYCLE_MODIFIER("WhiteOut"); }
		

	}
		
	void StopTimeCycle(int dummy)
	{
		timecycleStrength = 0;
		CLEAR_TIMECYCLE_MODIFIER();
	}


	void IncreaseTimeCycleStrength(int dummy)
	{
		SET_TIMECYCLE_MODIFIER_STRENGTH(timecycleStrength++);
	}


	void DecreaseTimeCycleStrength(int dummy)
	{
		SET_TIMECYCLE_MODIFIER_STRENGTH(timecycleStrength--);
	}


	void ResetTimeCycleStrength(int dummy)
	{
		SET_TIMECYCLE_MODIFIER_STRENGTH(1);
	}

		
	
// Freeze Protection
/*
void FreezeProtection()
{
	int ped;
	Vector3 c = GET_ENTITY_COORDS(_ID, 1);
	if (GET_CLOSEST_PED(&c, 5, 1, 1, &ped, 0, 1, -1))
	{
		if (GET_ENTITY_MODEL(ped) == GET_ENTITY_MODEL(_ID))
		{
			if (GET_PED_DRAWABLE_VARIATION(ped, Shirt) == GET_PED_DRAWABLE_VARIATION(_ID, Shirt) && GET_PED_TEXTURE_VARIATION(ped, Shirt) == GET_PED_TEXTURE_VARIATION(_ID, Shirt))
			{
				if (RequestLoop(ped))
				{
					if (DOES_ENTITY_EXIST(ped)){
						SET_ENTITY_AS_MISSION_ENTITY(ped, 0, 1);
						DELETE_PED(&ped);
						PrintText("Stopped freeze attempt", 2000);
					}
				}
			}
		}
	}
		
}
*/

	
	/*
	// Get Stack Size
	void GetAllocatedStackSize(int dummy)
	{
		int stackSize = GET_ALLOCATED_STACK_SIZE();
			
		char stackText[20];
		sprintf(stackText, "~w~Stack Size: ~y~%i", stackSize);
		PrintText(stackText , 3000);
	}
	*/


	/*
	bool systemCheckActiveT = false;
	void ToggleSystemStats(int dummy)
	{
		systemCheckActiveT = !systemCheckActiveT;
		systemCheckActive = systemCheckActiveT;
	}
	*/

	
	/*
	int idTemp = 1;
	void TerminateThread(int idTemp)
	{
		TERMINATE_THREAD(idTemp);
		char tid[50];
		sprintf(tid, "Terminated Thread ID: %i", idTemp);
	}

	void TerminateThisThread(int id)
	{
		int threadID = GET_ID_OF_THIS_THREAD();
		TERMINATE_THIS_THREAD();
		char tid[50];
		sprintf(tid, "Terminated Thread ID: %i", threadID);
	}

	void GetIdOfThisThread(int id)
	{
		int threadID = GET_ID_OF_THIS_THREAD();
		bool isThreadActive = IS_THREAD_ACTIVE(threadID);
		char tid[50];
		sprintf(tid, "Current Thread ID: %i", threadID);
		PrintText(tid, 3000);
	}
		
	void IsThreadActive(int id)
	{
		//int threadID = GET_ID_OF_THIS_THREAD();
		bool isThreadActive = IS_THREAD_ACTIVE(id);
		char tid[50];
		sprintf(tid, "Current Thread ID: %i\nIs Thread Active: %s", id, isThreadActive);
		PrintText(tid, 3000);
	}
	*/
		

	/*
	void RequestNewThreadId(int id)
	{
		// Checking current thread
		PrintText("~y~Requesting New Thread ID\nPlease Wait....", 3000);
		int threadIDPrevious = GET_ID_OF_THIS_THREAD();
		sleep(100);
		TERMINATE_THIS_THREAD();
		//Menu::closeMenu;
		sleep(1000);

		// Check if previous thread is terminated
		bool isThreadPreviousActive = IS_THREAD_ACTIVE(threadIDPrevious);
		if (isThreadPreviousActive == false)
		{
			//Menu::openMenu();
			sleep(500);
			int threadIDNew = GET_ID_OF_THIS_THREAD();
			bool isThreadNewActive = IS_THREAD_ACTIVE(threadIDNew);
			char threadTmp[50];
			sprintf(threadTmp, "~y~Requesting New Thread ID\n~w~New ID: ~y~%i", threadIDNew);
			PrintText(threadTmp, 3000);
		}
		else
		{
			sleep(500);
			//TERMINATE_THIS_THREAD();
		}

		// ONLY DO THIS if previous thread is terminated
		if (isThreadPreviousActive == false)
		{
				
			int threadIDNew = GET_ID_OF_THIS_THREAD();
			bool isThreadNewActive = IS_THREAD_ACTIVE(threadIDNew);
			//Menu::openMenu();
			char tid[50];
			sprintf(tid, "~b~Previous ID: %i\n~y~New ID: %i", threadIDPrevious, threadIDNew);

			// Check new thread
			if (isThreadNewActive == true)
			{
				sleep(200);
				char tid[50];
				sprintf(tid, "~b~Previous ID: %i\n~y~New ID: %i", threadIDPrevious, threadIDNew);
			}
		}
	}
	*/


	void SkipToNextConversation(int dummy)
	{
		SKIP_TO_NEXT_SCRIPTED_CONVERSATION_LINE();
	}


	/*
	void RestartConversation(int dummy)
	{
		RESTART_SCRIPTED_CONVERSATION();
	}
	*/


	// Skip Prologue Hack
	void SkipPrologue(int method)
	{
		// Get Mission Flag Status
		bool isMission = GET_MISSION_FLAG();
		changeModelHack = 0;

		// Forcefully Change To Fish if Mission Active
		if (isMission)
		{	
			if (method == 1)
			{
					PrintText("~y~Hold X To Activate", 3000);

				if (isMission && isDown(Button_CROSS))
				{
					PrintText("~b~Teleporting You Outta Here!!!", 5000);
					
					sleep(100);

					FORCE_CLEANUP(1);
					FORCE_CLEANUP(2);
					FORCE_CLEANUP(8);
					FORCE_CLEANUP(64);
					FORCE_CLEANUP(128);

					sleep(100);

					coords = Outside::FourHunderedKApartment;
					SET_ENTITY_COORDS(PlayerSelf(), coords, 1, 0, 0, 1);
					SET_ENTITY_VISIBLE(PlayerSelf(), true);
					method = 0;
					changeModelHack = 0;
				}
			}

			if (method == 2)
			{
				PrintText("~g~1) HOLD X UNTIL DEAD\n~y~2) Wait For Hospital Respawn\n~g~3) PRESS X ON RESPAWN", 5000);
				
				// Spawn To a fish to force WASTED MESSAGE and MISSION FLAG RESET
				if (isMission && isDown(Button_CROSS))
				{
					PrintText("~g~1) HOLD X UNTIL DEAD\n~y~2) Wait For Hospital Respawn\n~g~3) PRESS X ON RESPAWN", 5000);
					modelc = 210;
					SET_ENTITY_VISIBLE(PlayerSelf(), false);
					Models_f::ChangeModel(210);
					SET_ENTITY_VISIBLE(PlayerSelf(), false);
					method = 0;
					changeModelHack = 1;
				}
			}
						
			if (method == 3)
			{
					PrintText("~y~Hold X To Activate", 3000);

				if (isMission && isDown(Button_CROSS))
				{
					PrintText("~b~Teleporting You Outta Here!!!", 5000);
					SET_ENTITY_VISIBLE(PlayerSelf(), false);
					Models_f::ChangeModel(601);
					sleep(100);
					Models_f::ChangeModel(601);
					sleep(100);
					coords = Outside::FourHunderedKApartment;
					SET_ENTITY_COORDS(PlayerSelf(), coords, 1, 0, 0, 1);
					SET_ENTITY_VISIBLE(PlayerSelf(), true);
					method = 0;
					changeModelHack = 1;
				}
			}
		}
				

		if (!isMission)
		{
			if (changeModelHack == 1)
			{
				modelc = 601;
				Models_f::ChangeModel(601);
				SET_ENTITY_VISIBLE(PlayerSelf(), true);
			}

			PrintText("~r~You Are No Longer In Prologue\n~y~Trying To Change Model Back", 1200);
		}
	}




	

	void DisableAllMoneyToggles(int dummy)
	{
		// Turn off vehicle money toggles
		isMoneyVehicle = false;
		isMoneyVehicleActive = false;
		isMoneyVehicleCheck = false;

		// Turn off other money toggles
		isCustomMoneySpawn = false;
		isMoneySpawningOnPlayer = false;
		//isMoneySpawningOnPlayerT = false;
		isMoneySpawningOnLobby = false;
		//isMoneySpawningOnLobbyT = false;

		PrintText("~r~All Money Toggles Disabled", 1200);
	}


	// Skip Tutorial
	void SkipAllTutorials(int dummy)
	{
		STAT_SET_BOOL(GET_HASH_KEY("MP0_NO_MORE_TUTORIALS"), 1, 1);

		PrintText("Skip Tutorial Flag ~g~Active", 3000);
	}



};



#endif


