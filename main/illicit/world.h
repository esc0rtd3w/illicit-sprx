#ifndef __WORLD_H
#define __WORLD_H



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



namespace World_f
{
	
	//---------------------------------------------------------------------------

	// Display Area Name
	bool displayAreaName = true;
	void DisplayAreaName(int dummy)
	{
		DISPLAY_AREA_NAME(true);
		//displayAreaName = !displayAreaName;
		//DISPLAY_AREA_NAME(displayAreaName);
		//MsgToggleDefault("Display Area Name", displayAreaName);
	}


	void GetRandomCoords()
	{
		float randomX = GET_RANDOM_FLOAT_IN_RANGE(-5000, 5000);
		float randomY = GET_RANDOM_FLOAT_IN_RANGE(-4000, 4000);
		float randomZ = GET_RANDOM_FLOAT_IN_RANGE(1, 50);
		float Random[3] = { randomX, randomY, randomZ };
		globalRandomCoords = Random;
	}
	


	/*
	void SetNumberOfParkedVehicles(int amount)
	{
		SET_NUMBER_OF_PARKED_VEHICLES(amount);
	}
	*/


	void ClearArea(int dummy)
	{
		//int player = GET_PLAYER_PED(PlayerSelected);
		int player = 0;

		CLEAR_HD_AREA();
		//CLEAR_PED_NON_CREATION_AREA();
		//CLEAR_UNSYNCED_PROJECTILES();
		//CLEAR_ANGLED_AREA_OF_VEHICLES(GetEntityCoordsVec3(player).x, GetEntityCoordsVec3(player).y, GetEntityCoordsVec3(player).z, 50, 20, 20, 20, true, true, true, true, true);
		CLEAR_AREA(GetEntityCoordsVec3(player).x, GetEntityCoordsVec3(player).y, GetEntityCoordsVec3(player).z, 100, true, true, true, true);
		//CLEAR_AREA(GetEntityCoordsVec3(player).x, GetEntityCoordsVec3(player).y, GetEntityCoordsVec3(player).z, 25, true, true, true, true);
		CLEAR_AREA_OF_VEHICLES(GetEntityCoordsVec3(player).x, GetEntityCoordsVec3(player).y, GetEntityCoordsVec3(player).z, 100, true, true, true, true, true);
		//CLEAR_AREA_OF_VEHICLES(GetEntityCoordsVec3(player).x, GetEntityCoordsVec3(player).y, GetEntityCoordsVec3(player).z, 25, true, true, true, true, true);
		CLEAR_AREA_OF_PEDS(GetEntityCoordsVec3(player).x, GetEntityCoordsVec3(player).y, GetEntityCoordsVec3(player).z, 100, true);
		//CLEAR_AREA_OF_PEDS(GetEntityCoordsVec3(player).x, GetEntityCoordsVec3(player).y, GetEntityCoordsVec3(player).z, 25, true);
		CLEAR_AREA_OF_OBJECTS(GetEntityCoordsVec3(player).x, GetEntityCoordsVec3(player).y, GetEntityCoordsVec3(player).z, 100, true);
		//CLEAR_AREA_OF_OBJECTS(GetEntityCoordsVec3(player).x, GetEntityCoordsVec3(player).y, GetEntityCoordsVec3(player).z, 25, true);
		CLEAR_AREA_OF_COPS(GetEntityCoordsVec3(player).x, GetEntityCoordsVec3(player).y, GetEntityCoordsVec3(player).z, 100, true);
		//CLEAR_AREA_OF_COPS(GetEntityCoordsVec3(player).x, GetEntityCoordsVec3(player).y, GetEntityCoordsVec3(player).z, 25, true);
		CLEAR_AREA_OF_PROJECTILES(GetEntityCoordsVec3(player).x, GetEntityCoordsVec3(player).y, GetEntityCoordsVec3(player).z, 100, true);
		//CLEAR_AREA_OF_PROJECTILES(GetEntityCoordsVec3(player).x, GetEntityCoordsVec3(player).y, GetEntityCoordsVec3(player).z, 25, true);
		
		//char* playerNameActive = GET_PLAYER_NAME(player);

		//char buffer[64];
		//sprintf(buffer, "~w~Cleared Area Around ~b~%s \n~w~ID: ~y~%i", playerNameActive, player);
		//PrintText(buffer, 3000);

		PrintText("~b~Area Cleared", 3000);
	}


	void ForceCleanup(int dummy)
	{
		int player = PlayerSelf();

		// ??
		FORCE_CLEANUP(1);
		FORCE_CLEANUP(2);
		FORCE_CLEANUP(8);
		FORCE_CLEANUP(64);
		FORCE_CLEANUP(128);
		
		
		//char* playerNameActive = GET_PLAYER_NAME(player);

		//char buffer[64];
		//sprintf(buffer, "~w~Forced Cleanup Around ~b~%s ~w~(ID: ~y~%i)", playerNameActive, player);
		//PrintText(buffer, 3000);
		PrintText("~w~Running All Known ~b~FORCE CLEANUP ~w~Commands", 3000);
	}
	

	/*
	// Water Test Loop
	bool ifWaterModifyT = false;
	void TsunamiTest(int dummy)
	{
		ifWaterModifyT = !ifWaterModifyT;
		ifWaterModify = ifWaterModifyT;
	}
	*/

	/*
	// Water Test 2
	void WaterTest(int waterLevel)
	{
		MODIFY_WATER(-394.8745, -102.1641, 40.2580, waterLevel);
	}
	*/

	/*
	void SetGravityLevel(int level)
	{
		SET_GRAVITY_LEVEL(level);
	}
	*/

	/*
	void RemoveAllCoverBlockingAreas(int dummy)
	{
		REMOVE_ALL_COVER_BLOCKING_AREAS();
	}
	*/
	

	//float iplCoords[3];

	//---------------------------------------------------------------------------

	
	//---------------------------------------------------------------------------
	// IPL STUFF

	void RequestIPL(int ipl)
	{

		switch (ipl)
		{
			// North Yankton
			case 0:
				REQUEST_IPL("prologue01");
				REQUEST_IPL("prologue01c");
				REQUEST_IPL("prologue01d");
				REQUEST_IPL("prologue01e");
				REQUEST_IPL("prologue01f");
				REQUEST_IPL("prologue01g");
				REQUEST_IPL("prologue01h");
				REQUEST_IPL("prologue01i");
				REQUEST_IPL("prologue01j");
				REQUEST_IPL("prologue01k");
				REQUEST_IPL("prologue01z");
				REQUEST_IPL("prologue02");
				REQUEST_IPL("prologue03");
				REQUEST_IPL("prologue03b");
				REQUEST_IPL("prologue03_grv_fun");
				REQUEST_IPL("prologue04");
				REQUEST_IPL("prologue04b");
				REQUEST_IPL("prologue05");
				REQUEST_IPL("prologue05b");
				REQUEST_IPL("prologue06");
				REQUEST_IPL("prologue06b");
				REQUEST_IPL("prologue06_int");
				REQUEST_IPL("prologuerd");
				REQUEST_IPL("prologuerdb");
				REQUEST_IPL("prologue_DistantLights");
				REQUEST_IPL("prologue_LODLights");
				REQUEST_IPL("prologue_m2_door");
				
				REQUEST_IPL("farm");
				REQUEST_IPL("farm_props");
				REQUEST_IPL("farmint");
				REQUEST_IPL("farmint_cap");
				
				REQUEST_IPL("des_farmhouse");
				REQUEST_IPL("des_farmhs_endimap");
				REQUEST_IPL("des_farmhs_end_occl");
				REQUEST_IPL("des_farmhs_startimap");
				REQUEST_IPL("des_farmhs_start_occl");
				
				/*
				//iplTeleportLocation = "NorthYankton";
				float iplNorthYanktonCoords[3] = { 2447.9f, 4973.4f, 47.7f };
				

				// Some Crappy Way To Do This!!!

				if (IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true) == false)
				{
					SET_ENTITY_COORDS(PlayerSelf(), iplNorthYanktonCoords, 1, 0, 0, 1);
				}
				else
				{
					Ped currentVehicle = GetCurrentVehicle(PlayerSelf());
					SET_ENTITY_COORDS(currentVehicle, iplNorthYanktonCoords, 1, 0, 0, 1);
				}
				*/
				break;

			// Yacht (Heist)
			case 1:
				REQUEST_IPL("hei_yacht_heist");
				REQUEST_IPL("hei_yacht_heist_Bar");
				REQUEST_IPL("hei_yacht_heist_Bedrm");
				REQUEST_IPL("hei_yacht_heist_Bridge");
				REQUEST_IPL("hei_yacht_heist_DistantLights");
				REQUEST_IPL("hei_yacht_heist_enginrm");
				REQUEST_IPL("hei_yacht_heist_LODLights");
				REQUEST_IPL("hei_yacht_heist_Lounge");
				
				/*
				//iplTeleportLocation = "YachtHeist";
				float iplYachtCoords[3] = { -2043.974f, -1031.582f, 11.981f };
				

				// Some Crappy Way To Do This!!!

				if (IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true) == false)
				{ 
					SET_ENTITY_COORDS(PlayerSelf(), iplYachtCoords, 1, 0, 0, 1);
				}
				else
				{
					Ped currentVehicle = GetCurrentVehicle(PlayerSelf());
					SET_ENTITY_COORDS(currentVehicle, iplYachtCoords, 1, 0, 0, 1);
				}
				*/
				break;
		}

		

	}


	void RemoveIPL(int ipl)
	{
		switch (ipl)
		{
			// North Yankton
			case 0:
				REMOVE_IPL("prologue01");
				REMOVE_IPL("prologue01c");
				REMOVE_IPL("prologue01d");
				REMOVE_IPL("prologue01e");
				REMOVE_IPL("prologue01f");
				REMOVE_IPL("prologue01g");
				REMOVE_IPL("prologue01h");
				REMOVE_IPL("prologue01i");
				REMOVE_IPL("prologue01j");
				REMOVE_IPL("prologue01k");
				REMOVE_IPL("prologue01z");
				REMOVE_IPL("prologue02");
				REMOVE_IPL("prologue03");
				REMOVE_IPL("prologue03b");
				REMOVE_IPL("prologue03_grv_fun");
				REMOVE_IPL("prologue04");
				REMOVE_IPL("prologue04b");
				REMOVE_IPL("prologue05");
				REMOVE_IPL("prologue05b");
				REMOVE_IPL("prologue06");
				REMOVE_IPL("prologue06b");
				REMOVE_IPL("prologue06_int");
				REMOVE_IPL("prologuerd");
				REMOVE_IPL("prologuerdb");
				REMOVE_IPL("prologue_DistantLights");
				REMOVE_IPL("prologue_LODLights");
				REMOVE_IPL("prologue_m2_door");
				
				REMOVE_IPL("farm");
				REMOVE_IPL("farm_props");
				REMOVE_IPL("farmint");
				REMOVE_IPL("farmint_cap");
				
				REMOVE_IPL("des_farmhouse");
				REMOVE_IPL("des_farmhs_endimap");
				REMOVE_IPL("des_farmhs_end_occl");
				REMOVE_IPL("des_farmhs_startimap");
				REMOVE_IPL("des_farmhs_start_occl");
				break;

			// Yacht (Heist)
			case 1:
				REMOVE_IPL("hei_yacht_heist");
				REMOVE_IPL("hei_yacht_heist_Bar");
				REMOVE_IPL("hei_yacht_heist_Bedrm");
				REMOVE_IPL("hei_yacht_heist_Bridge");
				REMOVE_IPL("hei_yacht_heist_DistantLights");
				REMOVE_IPL("hei_yacht_heist_enginrm");
				REMOVE_IPL("hei_yacht_heist_LODLights");
				REMOVE_IPL("hei_yacht_heist_Lounge");
				break;

		}

	}
	//---------------------------------------------------------------------------

	

	//---------------------------------------------------------------------------
	// TOGGLES START HERE
		
		
	// Toggle Ambient Light Blackout
	bool isBlackout = false;
	void ToggleBlackout(int dummy)
	{
		isBlackout = !isBlackout;
		SET_BLACKOUT(isBlackout);
		MsgToggleDefault("Blackout", isBlackout);
	}

	//---------------------------------------------------------------------------


};


#endif






/*
GTA V IPL list + Coords
IPLname // X, Y, Z

-------------------------------------------------------
airfield 		//1743.682f, 3286.251f, 40.0875f
AP1_04_TriAf01 		//-1277.629f, -2030.913f, 1.2823f
bh1_16_refurb 		//-623.6868f, -231.935f, 40.30703f
BH1_47_JoshHse_Burnt
bh1_47_joshhse_firevfx
BH1_47_JoshHse_UnBurnt
BH1_48_Killed_Michael
bnkheist_apt_dest
bnkheist_apt_norm
burgershot_yoga 	//-813.3f, 177.5f, 75.76f
burnt_switch_off
cargoship 		//-162.8918f, -2365.769f, 0f
canyonriver01 		//-532.1309f, 4526.187f, 88.7955f
canyonriver01_traincrash //-532.1309f, 4526.187f, 88.7955f
chemgrill_grp1 		//3832.9f, 3665.5f, -23.4f
CH1_07_TriAf03
CH3_RD2_BishopsChickenGraffiti //1861.28f, 2402.11f, 58.53f
chop_props 		//-13.83f, -1455.45f, 31.81f
chophillskennel 	//19.0568f, 536.4818f, 169.6277f
CJ_IOABoat
coronertrash 		//233.9f, -1355f, 30.3f -The Morgue (trash)
Coroner_Int_off 	//234.4f, -1355.6f, 40.5f -The Morgue
Coroner_Int_on 		//234.4f, -1355.6f, 40.5f -The Morgue
crashed_cargoplane
CS1_02_cf_offmission 	//-146.3837f, 6161.5f, 30.2062f -Cluckin Bell ( Remove this to open the gates )
CS1_02_cf_onmission1 	//-146.3837f, 6161.5f, 30.2062f -Cluckin Bell
CS1_02_cf_onmission2 	//-146.3837f, 6161.5f, 30.2062f -Cluckin Bell
CS1_02_cf_onmission3 	//-146.3837f, 6161.5f, 30.2062f -Cluckin Bell
CS1_02_cf_onmission4 	//-146.3837f, 6161.5f, 30.2062f -Cluckin Bell
CS2_06_TriAf02 		//2384.969f, 4277.583f, 30.379f -Cluckin Bell
CS3_05_water_grp1 	//-24.685f, 3032.92f, 40.331f
CS3_05_water_grp2 	//-24.685f, 3032.92f, 40.331f
cs3_07_mpgates 		//-1601.424f, 2808.213f, 16.2598f
CS4_08_TriAf02
CS4_04_TriAf03 		//1577.881f, 3836.107f, 30.7717f
CS5_04_MazeBillboardGraffiti //2697.32f, 3162.18f, 58.1f
cs5_4_trains 		//2773.61f, 2835.327f, 35.1903f
CS5_Roads_RonOilGraffiti //2119.12f, 3058.21f, 53.25f
des_farmhouse 		//2447.9f, 4973.4f, 47.7f
des_farmhs_endimap 	//2450.595f, 4959.929f //2383.756f, 4929.988f //2505.756f, 5023.988f
des_farmhs_end_occl 	//2450.595f, 4959.929f
des_farmhs_startimap 	//2450.595f, 4959.929f //2383.756f, 4929.988f //2505.756f, 5023.988f
des_farmhs_start_occl 	//2450.595f, 4959.929f, 44.2575f
DES_ProTree_start
DES_ProTree_start_lod
DES_Smash2_endimap 	//890.3647f, -2367.289f, 28.10582f
DES_Smash2_startimap 	//890.3647f, -2367.289f, 28.10582f
DES_StiltHouse_imapend 	//-1020.5f, 663.41f, 154.75f //-1018.913f, 603.2904f, 105.6611f //-1038.913f, 639.2904f, 135.6611f
DES_StiltHouse_imapstart //-1020.5f, 663.41f, 154.75f //-1018.913f, 603.2904f, 105.6611f //-1038.913f, 639.2904f, 135.6611f
des_stilthouse_rebuild 	//-1020.5f, 663.41f, 154.75f //-1018.913f, 603.2904f, 105.6611f //-1038.913f, 639.2904f, 135.6611f
DT1_05_HC_REMOVE 	//169f, -670.3f, 41.9f
DT1_05_HC_REQ 		//169f, -670.3f, 41.9f
DT1_05_REQUEST 		//163.4f, -745.7f, 251f
DT1_05_rubble 		//74.29f, -736.05f, 46.76f
DT1_17_OldBill		//391.81f, -962.71f, 41.97f
DT1_17_NewBill		//391.81f, -962.71f, 41.97f
DT1_21_prop_lift_on 	//-180.5771f, -1016.928f, 28.2893f
fakeint			//-59.7936f, -1098.784f, 27.2612f
farm			//2447.9f, 4973.4f, 47.7f
farm_burnt		//2447.9f, 4973.4f, 47.7f
farm_burnt_props	//2447.9f, 4973.4f, 47.7f
farmint_cap		//2447.9f, 4973.4f, 47.7f
farmint			//2447.9f, 4973.4f, 47.7f
farm_props		//2447.9f, 4973.4f, 47.7f
FBI_colPLUG 		//74.29f, -736.05f, 46.76f
FIBlobby		//105.4557f, -745.4835f, 44.7548f
FIBlobbyfake		//105.4557f, -745.4835f, 44.7548f
FBI_repair		//74.29f, -736.05f, 46.76f
ferris_finale_Anim	//-1675.178f, -1143.605f, 12.0175f
FruitBB			//-1327.46f, -274.82f, 54.25f
gasparticle_grp2	//-95.2f, 6411.3f, 31.5f
gasstation_ipl_group1	//-93.4f, 6410.9f, 36.8f
gasstation_ipl_group2	//-93.4f, 6410.9f, 36.8f
hei_carrier		//3069.98f,-4632.49f, 16.26f 	- Heist Aircraft Carier Group1
hei_carrier_DistantLights 				- Heist Aircraft Carier Group2
hei_Carrier_int1 					- Heist Aircraft Carier Group3 
hei_Carrier_int2 					- Heist Aircraft Carier Group4 
hei_Carrier_int3 					- Heist Aircraft Carier Group5 
hei_Carrier_int4 					- Heist Aircraft Carier Group6 
hei_Carrier_int5 					- Heist Aircraft Carier Group7 
hei_Carrier_int6 					- Heist Aircraft Carier Group8 
hei_carrier_LODLights 					- Heist Aircraft Carier Group9 
hei_yacht_heist		//-2043.974,-1031.582, 11.981
hei_yacht_heist_Bar
hei_yacht_heist_Bedrm
hei_yacht_heist_Bridge
hei_yacht_heist_DistantLights
hei_yacht_heist_enginrm
hei_yacht_heist_LODLights
hei_yacht_heist_Lounge
id2_14_during_door	//716.84f, -962.05f, 31.59f - Lester's Factory
id2_14_during1		//716.84f, -962.05f, 31.59f - Lester's Factory
id2_14_during2		//716.84f, -962.05f, 31.59f - Lester's Factory
id2_14_on_fire		//716.84f, -962.05f, 31.59f - Lester's Factory ( On Fire )
id2_14_post_no_int	//716.84f, -962.05f, 31.59f - Lester's Factory ( Remove to unlock door maybe ?? )
id2_14_pre_no_int	//716.84f, -962.05f, 31.59f - Lester's Factory ( Remove to unlock door maybe ?? )
ID2_21_G_Night
Jetsteal_ipl_grp1	//787.3967f, -1808.858f, 29.8532 //814f, -1750f, 20f //790f, -1899f, 35f
Jetsteal_ipl_grp2	//787.3967f, -1808.858f, 29.8532 //814f, -1750f, 20f //790f, -1899f, 35f
jetstealtunnel		//801.7f, -1810.8f, 23.3f
jewel2fake		//-630.4205f, -236.7843f, 37.057f
Jewel_Gasmasks		//707.2563f, -965.147f, 29.4179f
layer_sextoys_a		//-1157.129f, -1523.028f, 9.6327f
layer_torture		//-1157.129f, -1523.028f, 9.6327f
ld_rail_02_track	//2626.374f, 2949.869f, 39.1409f
MG-Flight School 5
Michael_premier		//-813.3f, 177.5f, 75.76f
occl_meth_grp1		//29.4838f, 3735.593f, 38.688f
Plane_crash_trench	//2814.7f, 4758.5f, 47.9f
post_hiest_unload	//-630.4205f, -236.7843f, 37.057f
prologue01
prologue01c
prologue01d
prologue01e
prologue01f
prologue01g
prologue01h
prologue01i
prologue01j
prologue01k
prologue01z
prologue02
prologue03
prologue03b
prologue03_grv_fun
prologue04
prologue04b
prologue05
prologue05b
prologue06
prologue06b
prologue06_int
prologuerd
prologuerdb
prologue_DistantLights
prologue_LODLights
prologue_m2_door
prop_cheetah_covered	//490.8999f, -1334.068f, 28.3298f
prop_entityXF_covered	//490.8999f, -1334.068f, 28.3298f
prop_jb700_covered 	//490.8999f, -1334.068f, 28.3298f
prop_ztype_covered	//490.8999f, -1334.068f, 28.3298f
railing_end		//-532.1309f, 4526.187f, 88.7955f
railing_start		//-532.1309f, 4526.187f, 88.7955f
RC12B_Default		//330.4596f, -584.8196f, 42.3174f
RC12B_Destroyed		//330.4596f, -584.8196f, 42.3174f
RC12B_Fixed		//330.4596f, -584.8196f, 42.3174f
RC12B_HospitalInterior	//330.4596f, -584.8196f, 42.3174f
refit_unload		//-583.1606f, -282.3967f, 35.394f
REMOVE_ALL_STATES
SC1_01_NewBill		//-351f, -1324f, 44.02f
SC1_01_OldBill		//-351f, -1324f, 44.02f
SC1_30_Keep_Closed
ship_occ_grp1
ship_occ_grp2
shr_int			//-59.7936f, -1098.784f, 27.2612f
smboat			// -2041.974f, -1031.582f, 12.981f
SM_15_BldGRAF1
sunkcargoship 		//-162.8918f, -2365.7690f, 0f
tankerexp_grp0		//1676.415f, -1626.37f
tankerexp_grp1		//1676.415f, -1626.37f
tankerexp_grp2		//1676.415f, -1626.37f
tankerexp_grp3		//1676.415f, -1626.37f
TrevorsMP		//1973f, 3815f, 34f
TrevorsTrailer		//1973f, 3815f, 34f
TrevorsTrailerTidy	//1973f, 3815f, 34f
TrevorsTrailerTrash	//1973f, 3815f, 34f
triathlon2_VBprops
TRV1_Trail_end		//-24.685f, 3032.92f
TRV1_Trail_Finish	//-24.685f, 3032.92f
TRV1_Trail_start	//-24.685f, 3032.92f
UFO			//487.31f, 5588.386f, 793.0532f
V_35_Fireman		//707.2563f, -965.147f, 29.4179f
VB_08_TriAf01
v_carshowroom		//-30.8793f, -1088.336f, 25.4221f
V_Michael		//-811.2679f, 179.3344f, 75.7408f
V_Michael_Garage	//-810.5301f, 187.7868f, 71.4786f
V_Michael_FameShame	//-810.5301f, 187.7868f, 71.4786f
V_Michael_JewelHeist	//-813.3f, 177.5f, 75.76f
V_Michael_plane_ticket	//-813.3f, 177.5f, 75.76f
V_Michael_Scuba		//-810.5301f, 187.7868f, 71.4786f
v_tunnel_hole		//-14.651f, -604.3639f, 25.1823f
v_tunnel_hole_swap	//-14.651f, -604.3639f, 25.1823f
yogagame		//-781.6566f, 186.8937f, 71.8352f
FINBANK			// 2.69689322f, -667.0166f, 16.1306286f - Union Depository vault
DT1_03_Shutter		// 23.9346f, -669.7552f, 30.8853f	- Union Deposity shutters
DT1_03_Gr_Closed	// 23.7318f, -647.2123f, 37.9549f	- Remove this to remove Tunnel Fence Cover
DES_tankercrash		// 1676.415f, -1626.37f, 111.4848f
*/


