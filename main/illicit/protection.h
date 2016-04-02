#ifndef __PROTECTION_H
#define __PROTECTION_H



#include "hud.h"
#include "peds.h"

using namespace Hud_f;


namespace Protection
{
	
	void SetTunable(int index, int value)
	{
		int address = (*(int*)0x1E70374) + 4;
		{
			if (address != 0)
			{
				int temp = address;
				temp += (index * 4);
				*(int*)temp = value;
			}
		}
	}

	
	// Clear All Reports
	void ClearAllReports(int dummy)
	{
		
		STAT_SET_INT(GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), 100, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_FRIENDLY"), 100, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_HELPFUL"), 100, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_GRIEFING"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_VC_ANNOYINGME"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_VC_HATE"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_OFFENSIVE_TAGPLATE"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_BAD_CREW_NAME"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_BAD_CREW_MOTTO"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_BAD_CREW_STATUS"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_BAD_CREW_EMBLEM"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_EXPLOITS"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_ISPUNISHED"), 0, 1);

		STAT_SET_INT(GET_HASH_KEY("MP0_TIMES_CHEATED"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_EXPLOITS"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_GAME_EXPLOITS"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_COMMEND_STRENGTH"), 100, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_FRIENDLY"), 100, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_HELPFUL"), 100, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_VC_HATE"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_VC_ANNOYINGME"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_RACE_CHEAT_TALLY"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_GRIEFING"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_LTS_CHEAT_TALLY"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_SUR_CHEAT_TALLY"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_CAP_CHEAT_TALLY"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_SCADMIN_IS_CHEATER"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_MC_CHEAT_TALLY"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_RACE_CHEAT_TALLY"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_DM_CHEAT_TALLY"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_BECAME_CHEATER_NUM"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_OVERALL_CHEAT"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_WAS_I_CHEATER"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_CHEAT_BITSET"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_BAD_SPORT_BITSET"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_WAS_I_BAD_SPORT"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_OVERALL_BADSPORT"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_CHAR_IS_BADSPORT"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_BECAME_BADSPORT_NUM"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_DESTROYED_PVEHICLES"), 0, 1);
		
		PrintText("All Reports ~g~Cleared", 3000);
	}


	
	// Clear Mental State
	void ClearMentalState(int dummy)
	{
		STAT_SET_FLOAT(GET_HASH_KEY("PLAYER_MENTAL_STATE"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MP0_PLAYER_MENTAL_STATE"), 0, 1);
		PrintText("Mental State ~g~Cleared", 3000);
	}

	
	// Remove Bad Sport
	void RemoveBadSport(int dummy)
	{
		SetTunable(119, 0x00000000);
		SetTunable(120, 0x00000000);
		SetTunable(121, 0x00000000);
		SetTunable(122, 0x00000000);
		SetTunable(123, 0x00000000);
		SetTunable(124, 0x00000000);
		SetTunable(125, 0x00000000);
		SetTunable(126, 0x00000000);
		SetTunable(127, 0x00000000);
		SetTunable(128, 0x00000000);
		
		STAT_SET_INT(GET_HASH_KEY("MP0_BAD_SPORT_BITSET"), 0, 0);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_WAS_I_BAD_SPORT"), 0, 0);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_OVERALL_BADSPORT"), 0, 0);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_CHAR_IS_BADSPORT"), 0, 0);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_BECAME_BADSPORT_NUM"), 0, 0);
		STAT_SET_INT(GET_HASH_KEY("MP0_MPPLY_DESTROYED_PVEHICLES"), 0, 0);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_REPORT_STRENGTH"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_COMMEND_STRENGTH"), 100, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_FRIENDLY"), 100, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_HELPFUL"), 100, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_GRIEFING"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_VC_ANNOYINGME"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_VC_HATE"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_OFFENSIVE_LANGUAGE"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_OFFENSIVE_TAGPLATE"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_OFFENSIVE_UGC"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_BAD_CREW_NAME"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_BAD_CREW_MOTTO"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_BAD_CREW_STATUS"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_BAD_CREW_EMBLEM"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_GAME_EXPLOITS"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_EXPLOITS"), 0, 1);
		STAT_SET_INT(GET_HASH_KEY("MPPLY_ISPUNISHED"), 0, 1);
		
		PrintText("Bad Sport ~r~Removed", 3000);
	}

	
	// Disable Idle Kick
	void DisableIdleKick(int dummy)
	{
		SetTunable(73, 0x3B9ACA00);
		SetTunable(74, 0x3B9ACA00);
		SetTunable(75, 0x3B9ACA00);
		SetTunable(76, 0x3B9ACA00);
		PrintText("Idle Kick ~r~Disabled", 3000);
	}


	// Disable 1.26 Anti-Ban
	void DisableAntiCheat(int dummy)
	{
		//
		PrintText("Attempting To ~r~Disable ~w~Known ~y~1.26 Anti-Cheat ~w~Functions", 3000);
	}


	// Check For Modder
	void CheckForModder(int SelectedPlayer)
	{
		int player = GET_PLAYER_PED(SelectedPlayer);

		// Explode Player
		explosionType = 38;
		ADD_EXPLOSION_ALT(&GET_ENTITY_COORDS(player, 1), explosionType, 0.2f, false, false, 0.0f);
		//sleep(1500);
		
		// Check if Player Dead
		bool isDead = IS_ENTITY_DEAD(player);
		bool isFatalyInjured = IS_PED_FATALLY_INJURED(player);

		// If Player is NOT Dead, Set MODDER FLAG
		if (!isFatalyInjured)
		{
			sleep(300);

			if (!isDead)
			{
				modderID = player;
				char* modderName = GET_PLAYER_NAME(player);

				char modderNameText[120];
				//sprintf(modderNameText, "~w~Mod Status For ~b~%s ~w~With ID ~y~%i ~w~Is ~r~DIRTY", modderNames[modderID], modderList[modderID]);
				sprintf(modderNameText, "~w~Name: ~b~%s\n~w~ID: ~y~%i\n~w~Status: ~r~DIRTY", modderName, modderID);

				PrintText(modderNameText, 5000);

				isModder = 1;
			}
		}
	
		// If Player is Dead, DO NOT Set MODDER FLAG
		else
		{
			cleanID = player;
			char* cleanName = GET_PLAYER_NAME(player);

			char cleanNameText[120];
			sprintf(cleanNameText, "~w~Name: ~b~%s\n~w~ID: ~y~%i\n~w~Status: ~g~CLEAN", cleanName, cleanID);

			PrintText(cleanNameText, 5000);

			isModder = 0;
		}

	}
	
	

};



#endif
