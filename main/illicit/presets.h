#ifndef __PRESETS_H
#define __PRESETS_H



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



//GOTOPRESETS
// Presets
namespace Presets_f
{
		
	/*
	// Preset 1
	// Player Godmode
	// Player Wanted Level 0
	// Player Give All Weapons
	// Player Infinite Ammo

	void PresetOne(int dummy)
	{
		// Player Godmode
		SET_ENTITY_INVINCIBLE(PLAYER_ID(0), true);
		SET_ENTITY_PROOFS(PlayerSelf(), true, true, true, true, true, true, true, true);
		SET_PED_CAN_RAGDOLL(PlayerSelf(), false);
		SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PlayerSelf(), false);
		SET_PED_DIES_IN_VEHICLE(PlayerSelf(), false);
		SET_PED_DIES_IN_WATER(PlayerSelf(), false);
		SET_PED_DIES_IN_SINKING_VEHICLE(PlayerSelf(), false);
		SET_ENTITY_CAN_BE_DAMAGED(PlayerSelf(), false);
		//bool playerGodmode = true;

			
		// Give All Weapons
		//GIVE_DELAYED_WEAPON_TO_PED(PlayerSelf(), Hashes_Weapons::WEAPON_MINIGUN, 9999, 1);

		// Infinite Ammo
		SET_PED_INFINITE_AMMO_CLIP(PlayerSelf(), true);
		//bool playerInfAmmo = true;

		// No Police
		SET_MAX_WANTED_LEVEL(0);
		CLEAR_PLAYER_WANTED_LEVEL();
		SET_POLICE_IGNORE_PLAYER(PlayerSelf(), true);
		playerWanted = false;

		char presetOneText[100];
		sprintf(presetOneText, "~w~Godmode: ~g~ON\n~w~AllWpns: ~r~OFF\n~w~InfAmmo: ~g~ON\n~w~NoPolice: ~g~ON");
		PrintText(presetOneText, 3000);
	}
	*/
		
	/*
	void PresetTwo(int dummy)
	{
		// Player Godmode
		SET_ENTITY_INVINCIBLE(PLAYER_ID(0), true);
		SET_ENTITY_PROOFS(PlayerSelf(), true, true, true, true, true, true, true, true);
		SET_PED_CAN_RAGDOLL(PlayerSelf(), false);
		SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PlayerSelf(), false);
		SET_PED_DIES_IN_VEHICLE(PlayerSelf(), false);
		SET_PED_DIES_IN_WATER(PlayerSelf(), false);
		SET_PED_DIES_IN_SINKING_VEHICLE(PlayerSelf(), false);
		SET_ENTITY_CAN_BE_DAMAGED(PlayerSelf(), false);
		bool playerGodmode = true;

		// No Police
		SET_MAX_WANTED_LEVEL(0);
		CLEAR_PLAYER_WANTED_LEVEL();
		SET_POLICE_IGNORE_PLAYER(PlayerSelf(), true);
		playerWanted = false;

		char presetOneText[100];
		sprintf(presetOneText, "~w~Godmode: ~g~ON\n~w~NoPolice: ~g~ON");
		PrintText(presetOneText, 3000);
	}
	*/

	/*
	void PresetThree(int dummy)
	{
		//
	}

	*/


};



#endif

