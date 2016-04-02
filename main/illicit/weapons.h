#ifndef __WEAPONS_H
#define __WEAPONS_H


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


// Weapons Stuffs are located in Hashes


namespace Weapons_f
{
	// Toggle Infinite Ammo 
	bool playerInfAmmo = false;
	void ToggleInfAmmo(int SelectedPlayer)
	{
		
		int player = GET_PLAYER_PED(SelectedPlayer);

		if (SelectedPlayer == 99)
		{
			int player = PlayerSelf();
		}
		

		playerInfAmmo = !playerInfAmmo;
		SET_PED_INFINITE_AMMO_CLIP(player, playerInfAmmo);

		MsgToggleDefault("Infinite Ammo For Current Weapon", playerInfAmmo);
	}
	

	void InfiniteAmmoDirect(int toggle)
	{
		*(int*)(0xFD3904) = 0x3b, 0xa0, 0x03, 0xe7;
		*(int*)(0xFDEC80) = 0x38, 0xe0, 0x00, 0x63;
	}


	/*
	// Give Weapons
	void WeaponsGiveOne(int Weapon)
	{
		GIVE_DELAYED_WEAPON_TO_PED(PlayerSelf(), Weapon, 9999, 5);
	}
	*/

	// Give All Weapons
	void WeaponsGiveAll(int SelectedPlayer)
	{
		int weapons[58];
		
		weapons[0] = Hashes_Weapons::WEAPON_ADVANCEDRIFLE;
		weapons[1] = Hashes_Weapons::WEAPON_APPISTOL;
		weapons[2] = Hashes_Weapons::WEAPON_ASSAULTRIFLE;
		weapons[3] = Hashes_Weapons::WEAPON_ASSAULTSHOTGUN;
		weapons[4] = Hashes_Weapons::WEAPON_ASSAULTSMG;
		weapons[5] = Hashes_Weapons::WEAPON_BALL;
		weapons[6] = Hashes_Weapons::WEAPON_BAT;
		weapons[7] = Hashes_Weapons::WEAPON_BULLPUPSHOTGUN;
		weapons[8] = Hashes_Weapons::WEAPON_BZGAS;
		weapons[9] = Hashes_Weapons::WEAPON_CARBINERIFLE;
		weapons[10] = Hashes_Weapons::WEAPON_COMBATMG;
		weapons[11] = Hashes_Weapons::WEAPON_COMBATPISTOL;
		weapons[12] = Hashes_Weapons::WEAPON_CROWBAR;
		weapons[13] = Hashes_Weapons::WEAPON_FIREEXTINGUISHER;
		weapons[14] = Hashes_Weapons::WEAPON_FLARE;
		weapons[15] = Hashes_Weapons::WEAPON_GOLFCLUB;
		weapons[16] = Hashes_Weapons::WEAPON_GRENADE;
		weapons[17] = Hashes_Weapons::WEAPON_GRENADELAUNCHER;
		weapons[18] = Hashes_Weapons::WEAPON_GRENADELAUNCHER_SMOKE;
		weapons[19] = Hashes_Weapons::WEAPON_HAMMER;
		weapons[20] = Hashes_Weapons::WEAPON_HEAVYSNIPER;
		weapons[21] = Hashes_Weapons::WEAPON_KNIFE;
		weapons[22] = Hashes_Weapons::WEAPON_MG;
		weapons[23] = Hashes_Weapons::WEAPON_MICROSMG;
		weapons[24] = Hashes_Weapons::WEAPON_MINIGUN;
		weapons[25] = Hashes_Weapons::WEAPON_MOLOTOV;
		weapons[26] = Hashes_Weapons::WEAPON_NIGHTSTICK;
		weapons[27] = Hashes_Weapons::WEAPON_PETROLCAN;
		weapons[28] = Hashes_Weapons::WEAPON_PISTOL;
		weapons[29] = Hashes_Weapons::WEAPON_PISTOL50;
		weapons[30] = Hashes_Weapons::WEAPON_PUMPSHOTGUN;
		weapons[31] = Hashes_Weapons::WEAPON_RPG;
		weapons[32] = Hashes_Weapons::WEAPON_SAWNOFFSHOTGUN;
		weapons[33] = Hashes_Weapons::WEAPON_SMG;
		weapons[34] = Hashes_Weapons::WEAPON_SMOKEGRENADE;
		weapons[35] = Hashes_Weapons::WEAPON_SNIPERRIFLE;
		weapons[36] = Hashes_Weapons::WEAPON_STICKYBOMB;
		weapons[37] = Hashes_Weapons::WEAPON_STINGER;
		weapons[38] = Hashes_Weapons::WEAPON_STUNGUN;
		weapons[39] = Hashes_Weapons_DLC::WEAPON_BOTTLE;
		weapons[40] = Hashes_Weapons_DLC::WEAPON_BULLPUPRIFLE;
		weapons[41] = Hashes_Weapons_DLC::WEAPON_COMBATPDW;
		weapons[42] = Hashes_Weapons_DLC::WEAPON_DAGGER;
		weapons[43] = Hashes_Weapons_DLC::WEAPON_FIREWORK;
		weapons[44] = Hashes_Weapons_DLC::WEAPON_FLAREGUN;
		weapons[45] = Hashes_Weapons_DLC::WEAPON_GUSENBERG;
		weapons[46] = Hashes_Weapons_DLC::WEAPON_HEAVYPISTOL;
		weapons[47] = Hashes_Weapons_DLC::WEAPON_HEAVYSHOTGUN;
		weapons[48] = Hashes_Weapons_DLC::WEAPON_HOMINGLAUNCHER;
		weapons[49] = Hashes_Weapons_DLC::WEAPON_KNUCKLE;
		weapons[50] = Hashes_Weapons_DLC::WEAPON_MARKSMANPISTOL;
		weapons[51] = Hashes_Weapons_DLC::WEAPON_MUSKET;
		weapons[52] = Hashes_Weapons_DLC::WEAPON_PROXMINE;
		weapons[53] = Hashes_Weapons_DLC::WEAPON_SNOWBALL;
		weapons[54] = Hashes_Weapons_DLC::WEAPON_SNSPISTOL;
		weapons[55] = Hashes_Weapons_DLC::WEAPON_SPECIALCARBINE;
		weapons[56] = Hashes_Weapons_DLC::WEAPON_VINTAGEPISTOL;
		weapons[57] = Hashes_Weapons_Gadgets::WEAPON_DIGISCANNER;

		/*
		// Normal Weapons
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_ADVANCEDRIFLE, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_AIRSTRIKE_ROCKET, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_ANIMAL, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_APPISTOL, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_ASSAULTRIFLE, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_ASSAULTSHOTGUN, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_ASSAULTSMG, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_BALL, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_BARBED_WIRE, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_BAT, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_BLEEDING, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_BRIEFCASE, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_BRIEFCASE_02, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_BULLPUPSHOTGUN, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_BZGAS, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_CARBINERIFLE, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_COMBATMG, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_COMBATPISTOL, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_COUGAR, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_CROWBAR, 1, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_DROWNING, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_DROWNING_IN_VEHICLE, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_ELECTRIC_FENCE, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_EXHAUSTION, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_EXPLOSION, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_FALL, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_FIRE, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_FIREEXTINGUISHER, 1, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_FLARE, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_GOLFCLUB, 1, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_GRENADE, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_GRENADELAUNCHER, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_GRENADELAUNCHER_SMOKE, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_HAMMER, 1, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_HEAVYSNIPER, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_HELI_CRASH, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_HIT_BY_WATER_CANNON, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_KNIFE, 1, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_MG, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_MICROSMG, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_MINIGUN, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_MOLOTOV, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_NIGHTSTICK, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_PASSENGER_ROCKET, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_PETROLCAN, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_PISTOL, 9999, 5);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_PISTOL50, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_PUMPSHOTGUN, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_RAMMED_BY_CAR, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_Other::WEAPON_REMOTESNIPER, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_RPG, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_RUN_OVER_BY_CAR, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_SAWNOFFSHOTGUN, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_SMG, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_SMOKEGRENADE, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_SNIPERRIFLE, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_STICKYBOMB, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_STINGER, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_STUNGUN, 1, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_UNARMED, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons::WEAPON_VEHICLE_ROCKET, 9999, 1);
			
		// DLC Weapons
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_BOTTLE, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_BULLPUPRIFLE, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_COMBATPDW, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_DAGGER, 1, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_FIREWORK, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_FLAREGUN, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_GARBAGEBAG, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_GUSENBERG, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_HANDCUFFS, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_HEAVYPISTOL, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_HEAVYSHOTGUN, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_HOMINGLAUNCHER, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_KNUCKLE, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_MARKSMANPISTOL, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_MARKSMANRIFLE, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_MUSKET, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_PROXMINE, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_SNOWBALL, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_SNSPISTOL, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_SPECIALCARBINE, 9999, 1);
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_DLC::WEAPON_VINTAGEPISTOL, 9999, 1);
			
		// Gadgets
		GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_Gadgets::WEAPON_DIGISCANNER, 99199, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_Gadgets::GADGET_NIGHTVISION, 9999, 1);
		//GIVE_DELAYED_WEAPON_TO_PED(GetPlayerPedID(SelectedPlayer), Hashes_Weapons_Gadgets::GADGET_PARACHUTE, 9999, 1);
		*/
		
		int player;
		char* name;
		//bool doesExist;

		if (SelectedPlayer == 99)
		{
			player = PlayerSelf();
			name = GET_PLAYER_NAME(PlayerSelf());
			//doesExist = DOES_ENTITY_EXIST(PlayerSelf());
		}
		else
		{
			player = GetPlayerPedID(SelectedPlayer);
			name = GET_PLAYER_NAME(SelectedPlayer);
			//doesExist = DOES_ENTITY_EXIST(SelectedPlayer);
		}


		//if (doesExist)
		//{
			for (int pos = 0; pos <= 57; pos++)
			{
				GIVE_DELAYED_WEAPON_TO_PED(player, weapons[pos], 9999, 1);
				SET_PED_INFINITE_AMMO(player, true, weapons[pos]);
				//SET_PED_INFINITE_AMMO_CLIP(player, playerInfAmmo);
			}

			// Set Default Weapon In-Hand
			SET_PED_GADGET(player, Hashes_Weapons_DLC::WEAPON_KNUCKLE, true);

			//NETWORK_REQUEST_CONTROL_OF_ENTITY(GET_PLAYER_PED(SelectedPlayer));

			char buffer[64];
			sprintf(buffer, "~w~Gave ALL Weapons and Infinite Ammo To ~b~%s", name);
			PrintText(buffer, 5000);
	
			//PrintText("~g~Gave All Weapons To ~b~%s", 3000);
		//}

		
	}
		
	// Take All Weapons
	void WeaponsTakeAll(int SelectedPlayer)
	{
		int player;
		char* name;
		//bool doesExist;

		if (SelectedPlayer == 99)
		{
			player = PlayerSelf();
			name = GET_PLAYER_NAME(PlayerSelf());
			//doesExist = DOES_ENTITY_EXIST(SelectedPlayer);
		}
		else
		{
			player = GetPlayerPedID(SelectedPlayer);
			name = GET_PLAYER_NAME(SelectedPlayer);
			//doesExist = DOES_ENTITY_EXIST(SelectedPlayer);
		}

		// Take From Other Players
		REMOVE_ALL_PED_WEAPONS(player);

		//if (doesExist)
		//{
			//PrintText("~r~Removed All Weapons", 3000);
			char buffer[64];
			sprintf(buffer, "~w~Removed ALL Weapons From ~b~%s", name);
			PrintText(buffer, 5000);
		//}
	}
	
	


	// LOOPS HERE


	// Explosive Ammo
	bool isAmmoExplosiveT = false;
	void WeaponsAmmoExplosive(int dummy)
	{
		isAmmoExplosiveT = !isAmmoExplosiveT;
		isAmmoExplosive = isAmmoExplosiveT;
		MsgToggleDefault("Explosive Ammo", isAmmoExplosiveT);
	}
	

	// Fire Ammo
	bool isAmmoFireT = false;
	void WeaponsAmmoFire(int dummy)
	{
		isAmmoFireT = !isAmmoFireT;
		isAmmoFire = isAmmoFireT;
		MsgToggleDefault("Fire Ammo", isAmmoFireT);
	}

	
	// Explosive Melee
	bool isMeleeExplosiveT = false;
	void WeaponsAmmoExplosiveMelee(int dummy)
	{
		if (isPlayerGodmodeActive && !playerGodmode)
		{
			isMeleeExplosiveT = !isMeleeExplosiveT;
			isMeleeExplosive = isMeleeExplosiveT;
			MsgToggleDefault("Explosive Melee", isMeleeExplosiveT);
			//SelectedPlayer = SelectedPlayer_;
		}
		else
		{
			PrintText("~r~Using This Without Godmode Is Dangerous!", 3000);
		}
	}

};


#endif





/*
// Pickups List

PICKUP_WEAPON_PISTOL=-105925489
PICKUP_WEAPON_COMBATPISTOL=-1989692173
PICKUP_WEAPON_APPISTOL=996550793
PICKUP_WEAPON_MICROSMG=496339155
PICKUP_WEAPON_SMG=978070226
PICKUP_WEAPON_ASSAULTRIFLE=-214137936
PICKUP_WEAPON_CARBINERIFLE=-546236071
PICKUP_WEAPON_ADVANCEDRIFLE=-1296747938
PICKUP_WEAPON_SAWNOFFSHOTGUN=-1766583645
PICKUP_WEAPON_PUMPSHOTGUN=-1456120371
PICKUP_WEAPON_ASSAULTSHOTGUN=-1835415205
PICKUP_WEAPON_SNIPERRIFLE=-30788308
PICKUP_WEAPON_HEAVYSNIPER=1765114797
PICKUP_WEAPON_MG=-2050315855
PICKUP_WEAPON_COMBATMG=-1298986476
PICKUP_WEAPON_GRENADELAUNCHER=779501861
PICKUP_WEAPON_RPG=1295434569
PICKUP_WEAPON_MINIGUN=792114228
PICKUP_WEAPON_GRENADE=1577485217
PICKUP_WEAPON_STICKYBOMB=2081529176
PICKUP_WEAPON_MOLOTOV=768803961
PICKUP_WEAPON_PETROLCAN=-962731009
PICKUP_WEAPON_SMOKEGRENADE=483787975
PICKUP_WEAPON_KNIFE=663586612
PICKUP_WEAPON_BAT=-2115084258
PICKUP_WEAPON_HAMMER=693539241
PICKUP_WEAPON_CROWBAR=-2027042680
PICKUP_WEAPON_GOLFCLUB=-1997886297
PICKUP_WEAPON_NIGHTSTICK=1587637620
PICKUP_WEAPON_FIREEXTINGUISHER=-887893374
PICKUP_WEAPON_LASSO=1724937680
PICKUP_WEAPON_LOUDHAILER=2017151059
PICKUP_PARACHUTE=1735599485
PICKUP_ARMOUR_STANDARD=1274757841
PICKUP_HEALTH_STANDARD=-1888453608
PICKUP_VEHICLE_WEAPON_PISTOL=-1521817673
PICKUP_VEHICLE_WEAPON_COMBATPISTOL=-794112265
PICKUP_VEHICLE_WEAPON_APPISTOL=-863291131
PICKUP_VEHICLE_WEAPON_MICROSMG=-1200951717
PICKUP_VEHICLE_WEAPON_SMG=-864236261
PICKUP_VEHICLE_WEAPON_SAWNOFF=772217690
PICKUP_VEHICLE_WEAPON_GRENADE=-1491601256
PICKUP_VEHICLE_WEAPON_MOLOTOV=-2066319660
PICKUP_VEHICLE_WEAPON_SMOKEGRENADE=1705498857
PICKUP_VEHICLE_WEAPON_STICKYBOMB=746606563
PICKUP_VEHICLE_HEALTH_STANDARD=160266735
PICKUP_VEHICLE_ARMOUR_STANDARD=1125567497
PICKUP_MONEY_CASE=-831529621
PICKUP_MONEY_DEP_BAG=545862290
PICKUP_MONEY_MED_BAG=341217064
PICKUP_MONEY_PAPER_BAG=1897726628
PICKUP_PORTABLE_CRATE_UNFIXED=1852930709
PICKUP_PORTABLE_PACKAGE=-2136239332
PICKUP_MONEY_CASE=-831529621
PICKUP_AMMO_BULLET_MP=1426343849
PICKUP_AMMO_MISSILE_MP=-107080240
PICKUP_CAMERA=-482507216
PICKUP_CUSTOM_SCRIPT=738282662
PICKUP_HANDCUFF_KEY=155886031
PICKUP_HEALTH_SNACK=483577702
PICKUP_MONEY_PURSE=513448440
PICKUP_MONEY_SECURITY_CASE=-562499202
PICKUP_MONEY_VARIABLE=-31919185
PICKUP_MONEY_WALLET=1575005502
PICKUP_SUBMARINE=-405862452
PICKUP_TYPE_INVALID=-723152950
PICKUP_MONEY_WALLET=1575005502
PICKUP_VEHICLE_CUSTOM_SCRIPT=-1514616151

*/