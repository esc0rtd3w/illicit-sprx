#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H


#include "buttons.h"
#include "core.h"
#include "hashes.h"
#include "hud.h"
#include "loops.h"
#include "messages.h"
#include "misc.h"
#include "natives.h"
#include "includes.h"
#include "licensing.h"
#include "models.h"
#include "particlefx.h"
#include "player.h"
#include "system.h"
#include "teleport.h"
#include "timecycle.h"
#include "types.h"
#include "vehicles.h"
#include "web.h"
#include "world.h"

using namespace Buttons;
using namespace Dialog;
using namespace Hashes;
using namespace Hud;
using namespace Keyboard;
using namespace Licensing;
using namespace Misc;
using namespace Models_Main;
using namespace Natives;
using namespace Teleport_Locations;
using namespace Vehicles_f;
using namespace World_f;


namespace Functions
{

	

	//GOTOMODELS
	// Models
	namespace Models_f
	{
		
		void ChangeModel(int modelc)
			{
				// Model List
				// Key: 
				//
				// Must Be Integers!
				//
				// Input Custom = 0xx
				// Clone From Lobby = 1xx
				// Animals = 2xx
				// Story Mode Characters = 3xx
				// Male Peds = 4xx
				// Female Peds = 5xx
				// Police & Emergency = 6xx
				// Strippers & Prostitutes = 7xx
				// Glitch Characters = 8xx
				
				

				if (modelc == 0)
				{
					isKeyboardActive = true;
					//DISPLAY_ONSCREEN_KEYBOARD(0, "PM_NAME_CHALL", "", "", "", "", "", 30);
					//GetKeyboardInput(30);
					//model = oskResult;
					//PrintText(oskResult, 3000);
				}


				/*
				if (modelc == 101)
				{
					ChangeModelReal("");
				}
				*/

				
				// Animals
				if (modelc == 201) { model = Animals_m::a_c_boar; }
				if (modelc == 202) { model = Animals_m::a_c_chickenhawk; }
				if (modelc == 203) { model = Animals_m::a_c_chimp; }
				//if (modelc == 204) { model = Animals_m::a_c_chop; }
				if (modelc == 205) { model = Animals_m::a_c_cormorant; }
				if (modelc == 206) { model = Animals_m::a_c_cow; }
				if (modelc == 207) { model = Animals_m::a_c_coyote; }
				if (modelc == 208) { model = Animals_m::a_c_crow; }
				if (modelc == 209) { model = Animals_m::a_c_deer; }
				if (modelc == 210) { model = Animals_m::a_c_fish; }
				if (modelc == 211) { model = Animals_m::a_c_hen; }
				//if (modelc == 212) { model = Animals_m::a_c_husky; }
				//if (modelc == 213) { model = Animals_m::a_c_mtlion; }
				if (modelc == 214) { model = Animals_m::a_c_pig; }
				if (modelc == 215) { model = Animals_m::a_c_pigeon; }
				if (modelc == 216) { model = Animals_m::a_c_rat; }
				//if (modelc == 217) { model = Animals_m::a_c_retriever; }
				if (modelc == 218) { model = Animals_m::a_c_rhesus; }
				//if (modelc == 219) { model = Animals_m::a_c_rottweiler; }
				if (modelc == 220) { model = Animals_m::a_c_seagull; }
				//if (modelc == 221) { model = Animals_m::a_c_sharktiger; }
				//if (modelc == 222) { model = Animals_m::a_c_shepherd; }

				
				// Story Mode Characters
				if (modelc == 301) { model = StoryMode_m::player_zero; }// Michael
				if (modelc == 302) { model = StoryMode_m::player_two; }// Trevor
				if (modelc == 303) { model = StoryMode_m::player_one; }// Franklin
				//if (modelc == 304) { model = StoryMode_m::ig_drfriedlander; }// Dr Friedlander
				if (modelc == 304) { model = StoryMode_m::cs_lamardavis; }// Lamar
				if (modelc == 305) { model = StoryMode_m::cs_lestercrest; }// Lester


				// Police & Emergency
				if (modelc == 601) { model = Police_m::s_m_y_fireman_01; }
				if (modelc == 602) { model = Police_m::s_m_m_paramedic_01; }
				//if (modelc == 603) { model = Police_m::csb_cop; }
				if (modelc == 604) { model = Police_m::s_f_y_cop_01; }
				//if (modelc == 605) { model = Police_m::s_m_m_snowcop_01; }
				if (modelc == 606) { model = Police_m::s_m_y_cop_01; }
				if (modelc == 607) { model = Police_m::s_m_y_hwaycop_01; }
				//if (modelc == 608) { model = Police_m::s_f_y_sheriff_01; }
				//if (modelc == 609) { model = Police_m::s_m_y_sheriff_01; }
				//if (modelc == 610) { model = Police_m::mp_m_fibsec_01; }
				if (modelc == 611) { model = Police_m::s_m_m_fiboffice_01; }
				//if (modelc == 612) { model = Police_m::s_m_m_fiboffice_02; }
				//if (modelc == 613) { model = Police_m::u_m_m_fibarchitect; }
				//if (modelc == 614) { model = Police_m::u_m_y_fibmugger_01; }
				if (modelc == 615) { model = Police_m::s_m_m_security_01; }
				//if (modelc == 616) { model = Police_m::comp_peds_marine; }
				//if (modelc == 617) { model = Police_m::csb_ramp_marine; }
				//if (modelc == 618) { model = Police_m::s_m_m_marine_01; }
				if (modelc == 619) { model = Police_m::s_m_m_marine_02; }
				//if (modelc == 620) { model = Police_m::s_m_y_marine_01; }
				//if (modelc == 621) { model = Police_m::s_m_y_marine_02; }
				//if (modelc == 622) { model = Police_m::s_m_y_marine_03; }
				//if (modelc == 623) { model = Police_m::mp_m_exarmy_01; }
				if (modelc == 624) { model = Police_m::s_m_y_armymech_01; }
				if (modelc == 625) { model = Police_m::u_m_y_militarybum; }


				// Strippers & Protitutes
				if (modelc == 701) { model = Strippers_m::csb_stripper_01; }
				//if (modelc == 702) { model = Strippers_m::csb_stripper_02; }
				//if (modelc == 703) { model = Strippers_m::mp_f_deadhooker; }
				//if (modelc == 704) { model = Strippers_m::mp_f_stripperlite; }
				if (modelc == 705) { model = Strippers_m::s_f_y_hooker_01; }
				//if (modelc == 706) { model = Strippers_m::s_f_y_hooker_02; }
				//if (modelc == 707) { model = Strippers_m::s_f_y_hooker_03; }
				//if (modelc == 708) { model = Strippers_m::s_f_y_stripperlite; }
				//if (modelc == 709) { model = Strippers_m::s_f_y_stripper_01; }
				//if (modelc == 710) { model = Strippers_m::s_f_y_stripper_02; }

				
				
				// Animal Freeze Fix Addresses 1.25
				//*(char*)(0x1131C28, 1);
				//*(char*)(0x11AED58, 1);
				//*(char*)(0x2D4ABC, 1);

				
				//char model[] = { 0x90, 0x90, 0x90, 0x90 };

				//model = "cs_old_man1a";
				
				/*
				// Default MP Hashes
				// Male Hash: 1885233650
				// Female Hash: -1667301416
				if (modelc == 801)
				{
					model = "mp_male";
				}

				if (modelc == 802)
				{
					model = "mp_female";
				}
				*/

				modelHash = model;
				

				/*
				REQUEST_MODEL(GET_HASH_KEY(model));
				if(HAS_MODEL_LOADED(GET_HASH_KEY(model)))
				{
					SET_PLAYER_MODEL(PLAYER_ID(0), GET_HASH_KEY(model));

					if (debug == true)
					{
						char modelText[64];
						sprintf(modelText, "~b~Changed Model To:\n~y~%s", model);
						PrintText(modelText, 3000);
					}
				}
				*/

				changeModelRequest = true;

			}

			/*
			// Change Model
			void ChangeModelReal(const char* model)
			{

				REQUEST_MODEL(GET_HASH_KEY(model));
				if(HAS_MODEL_LOADED(GET_HASH_KEY(model)))
				{
					SET_PLAYER_MODEL(PLAYER_ID(0), GET_HASH_KEY(model));
					PrintText("~b~Changed Model", 3000);
				}
			}
			*/



	};

	 
	//GOTOTELEPORT
	// Teleport
	namespace Teleport_f
	{

		/*
		// Blip Stuff
		bool blipFound = false;
		int blipIterator = _GET_BLIP_INFO_ID_ITERATOR();
		for (Blip i = GET_FIRST_BLIP_INFO_ID(blipIterator); DOES_BLIP_EXIST(i) != 0; i = GET_NEXT_BLIP_INFO_ID(blipIterator))
		{
			if (GET_BLIP_INFO_ID_TYPE(i) == 4) 
			{
				coords = GET_BLIP_INFO_ID_COORD(i);
				blipFound = true;
				break;
			}
		}	
		*/


		void TeleportToLocation(int location)
		{
			// Set No Coords if None Set
			bool noCoords = false;

			// Key: 
			//
			// Must Be Integers!
			//
			// Main Locations = 0xx
			// Story Mode Locations= 1xx
			// Inside Locations = 2xx
			// Outside Locations = 3xx
			// Places of Interest = 4xx
			// Helipad Locations = 5xx
			// Hospitals & Medical = 6xx
			// Water Towers = 7xx
			// Sniper Locations = 8xx
			// Glitch Locations = 9xx
			// Other Locations = 10xx
			

			// Locations On Main Teleport Menu
			if (location == 001) 
			{ 
				//float randomX = GET_RANDOM_FLOAT_IN_RANGE(-5000, 5000);
				//float randomY = GET_RANDOM_FLOAT_IN_RANGE(-4000, 4000);
				//float randomZ = GET_RANDOM_FLOAT_IN_RANGE(1, 50);
				//float Random[3] = { randomX, randomY, randomZ };

				GetRandomCoords();
				coords = globalRandomCoords;
			}

			if (location == 002) 
			{	
				waypointHandle = GET_FIRST_BLIP_INFO_ID(8);

				if(DOES_BLIP_EXIST(waypointHandle))						
				{
					noCoords = false;

					blipCoords = GET_BLIP_COORDS_ALT(waypointHandle);

					// Try getting closest objects Z coord to set on ground properly
					//blipCoords.z = GetVehicleCoordsVec3(0).z * 1.5;

					blipCoordsFloat = Vec3toFloat(blipCoords);
					coords = blipCoordsFloat;
				}
				else
				{
					noCoords = true;
					PrintText("~r~No Waypoint Set", 3000);
				}
			}

			//if (location == 003) { coords = Main_Locations::NearestVehicle; }// Not Used
			//if (location == 004) { coords = Main_Locations::NearestPed; }// Not Used
			//if (location == 005) { coords = Main_Locations::ForwardShort; }// Not Used
			//if (location == 006) { coords = Main_Locations::ForwardLong; }// Not Used
			
			// Story Mode Locations
			if (location == 101) { coords = StoryMode::BankVault; }
			if (location == 102) { coords = StoryMode::FranklinsAuntsHouse; }
			if (location == 103) { coords = StoryMode::FranklinsBedroom; }
			if (location == 104) { coords = StoryMode::FranklinsHouseNew; }
			if (location == 105) { coords = StoryMode::FranklinsHouseOld; }
			if (location == 106) { coords = StoryMode::LestersHouse; }
			if (location == 107) { coords = StoryMode::MichaelsHouse; }
			if (location == 108) { coords = StoryMode::PrologueStart; }
			if (location == 109) { coords = StoryMode::TrevorsHouse; }
			if (location == 110) { coords = StoryMode::TrevorMethLab; }
			if (location == 111) { coords = StoryMode::TrevorOfficeStripClub; }
			if (location == 112) { coords = StoryMode::WaynesCousinsHouse; }

			// Inside Locations
			if (location == 201) { coords = Inside::FourHunderedKGarage; }
			if (location == 202) { coords = Inside::AirportTerminal; }
			if (location == 203) { coords = Inside::BlaineCountyBank; }
			if (location == 216) { coords = Inside::Casino; }
			if (location == 204) { coords = Inside::FIBBuildingInside; }
			if (location == 205) { coords = Inside::FleecaBank; }
			if (location == 206) { coords = Inside::GunRangeCity; }
			if (location == 207) { coords = Inside::GunRangeGhetto; }
			if (location == 208) { coords = Inside::House1; }
			if (location == 209) { coords = Inside::HumaneResearchLab1; }
			if (location == 210) { coords = Inside::HumaneResearchLab2; }
			if (location == 211) { coords = Inside::IAABuilding; }
			if (location == 212) { coords = Inside::IOUTower; }
			if (location == 213) { coords = Inside::JanitorAptRoom; }
			if (location == 214) { coords = Inside::PoliceStationInside; }
			if (location == 215) { coords = Inside::PrisonCell; }
			if (location == 216) { coords = Inside::LestersHouseInside; }
			if (location == 217) { coords = Inside::LestersWarehouseInside; }
			
			// Outside 
			if (location == 301) { coords = Outside::FourHunderedKApartment; }
			if (location == 302) { coords = Outside::FourHunderedKApartmentRoof; }
			if (location == 303) { coords = Outside::Airport; }
			if (location == 350) { coords = Outside::ATM1; }
			if (location == 304) { coords = Outside::BeachIsland; }
			if (location == 348) { coords = Outside::Bigfoot; }
			if (location == 305) { coords = Outside::CannibalCamp; }
			if (location == 306) { coords = Outside::CannibalCampMountainTop; }
			if (location == 307) { coords = Outside::CannibalCampRoof; }
			//if (location == 308) { coords = Outside::CherryPopperStand; }
			if (location == 309) { coords = Outside::DelPerroPier; }
			if (location == 310) { coords = Outside::DirtbikeTrail; }
			if (location == 311) { coords = Outside::FarAwayIsland; }
			if (location == 312) { coords = Outside::FerrisWheelInLine; }
			if (location == 313) { coords = Outside::FerrisWheelCenter; }
			if (location == 314) { coords = Outside::FerrisWheelTop; }
			if (location == 315) { coords = Outside::FIBBuildingRoof; }
			if (location == 316) { coords = Outside::FortZancudo; }
			//if (location == 317) { coords = Outside::GiftsAtThePier; }
			if (location == 318) { coords = Outside::GrapeseedAirfield; }
			if (location == 319) { coords = Outside::IAABuildingRoof; }
			if (location == 320) { coords = Outside::ImpoundLot; }
			if (location == 321) { coords = Outside::LSPDParkingLot; }
			if (location == 322) { coords = Outside::MazeBankArenaRoof; }
			if (location == 323) { coords = Outside::MovieTheaterOutside; }
			if (location == 324) { coords = Outside::MorsMutualInsurance; }
			if (location == 325) { coords = Outside::MountChiliad; }
			//if (location == 326) { coords = Outside::MugshotStand; }
			if (location == 327) { coords = Outside::PaletoBay; }
			if (location == 328) { coords = Outside::PoliceParkingRoof; }
			if (location == 329) { coords = Outside::PoliceStationOutside; }
			if (location == 349) { coords = Outside::PrisonYard; }
			if (location == 330) { coords = Outside::RollerCoasterInLine; }
			if (location == 331) { coords = Outside::RollerCoasterTopHill; }
			if (location == 332) { coords = Outside::TrevorsAirfield; }
			if (location == 333) { coords = Outside::TunnelUnderTrainStation; }
			if (location == 334) { coords = Outside::TutorialTennisCourt; }
			if (location == 348) { coords = Outside::VanillaUnicorn; }
			if (location == 335) { coords = Outside::VendingMachinesPier; }
			if (location == 336) { coords = Outside::VespucciBeach; }
			if (location == 337) { coords = Outside::VinewoodSign; }
			//if (location == 338) { coords = Outside::VinewoodSignV; }
			//if (location == 339) { coords = Outside::VinewoodSignI; }
			//if (location == 340) { coords = Outside::VinewoodSignN; }
			//if (location == 341) { coords = Outside::VinewoodSignE; }
			//if (location == 342) { coords = Outside::VinewoodSignW; }
			//if (location == 343) { coords = Outside::VinewoodSignO1; }
			//if (location == 344) { coords = Outside::VinewoodSignO2; }
			//if (location == 345) { coords = Outside::VinewoodSignD; }
			if (location == 346) { coords = Outside::Waterfall; }
			if (location == 347) { coords = Outside::ZancudoRiver; }
			if (location == 348) { coords = Outside::LestersHouseOutside; }
			if (location == 349) { coords = Outside::LestersWarehouseOutside; }
			
			// Places of Interest 
			if (location == 401) { coords = VehicleGarages::BeekersGarage; }
			if (location == 402) { coords = VehicleGarages::LSCustomsAirport; }
			if (location == 403) { coords = VehicleGarages::LSCustomsBurton; }
			if (location == 404) { coords = VehicleGarages::LSCustomsDesert; }
			if (location == 405) { coords = VehicleGarages::LSCustomsLaMesa; }
			
			// Helipads 
			if (location == 501) { coords = Helipads::EmergencyHelipad; }
			if (location == 502) { coords = Helipads::HospitalHelipad; }
			if (location == 503) { coords = Helipads::MazeBankHelipad; }
			if (location == 504) { coords = Helipads::PoliceHelipad; }
			if (location == 505) { coords = Helipads::UnknownHelipad1; }
			if (location == 506) { coords = Helipads::UnknownHelipad2; }

			// Hospitals & Medical
			if (location == 601) { coords = Hospitals::CentralLSMedical; }
			if (location == 602) { coords = Hospitals::MountZonahHospital; }
			if (location == 603) { coords = Hospitals::PillboxHillMedical; }
			if (location == 604) { coords = Hospitals::SandyShoresMedical; }
			if (location == 605) { coords = Hospitals::TheBayCareCenter; }

			// Water Towers
			if (location == 701) { coords = WaterTowers::FinalMissionWaterTower; }
			if (location == 702) { coords = WaterTowers::LaMesaWaterTower; }
			//if (location == 701) { coords = WaterTowers::; }
			
			// Sniper Locations 
			if (location == 801) { coords = Sniper::AirportTower; }
			if (location == 802) { coords = Sniper::Antenna; }
			if (location == 803) { coords = Sniper::ArcadiusBusinessCenter; }
			if (location == 804) { coords = Sniper::BuildingWireframe; }
			//if (location == 805) { coords = Sniper::Crane1; }
			//if (location == 806) { coords = Sniper::Crane2; }
			//if (location == 807) { coords = Sniper::Crane3; }
			//if (location == 808) { coords = Sniper::Crane4; }
			//if (location == 809) { coords = Sniper::Crane5; }
			//if (location == 810) { coords = Sniper::Crane6; }
			//if (location == 811) { coords = Sniper::Crane7; }
			if (location == 812) { coords = Sniper::MilitaryBaseTower; }
			//if (location == 805) { coords = Sniper:; }
			
			// Glitch Locations 
			if (location == 901) { coords = Glitch::BehindGamesAreaAtPier; }
			if (location == 902) { coords = Glitch::FortZancudoBuilding0101; }
			if (location == 903) { coords = Glitch::FortZancudoBuilding3499; }
			if (location == 904) { coords = Glitch::FortZancudoBuildingA2; }
			if (location == 905) { coords = Glitch::Garage3566WestVinewood; }
			if (location == 906) { coords = Glitch::PipeDownCigarsInside; }
			if (location == 907) { coords = Glitch::TunnelUnderPillbox; }
			if (location == 908) { coords = Glitch::UnionDepositoryBuilding; }
			if (location == 909) { coords = Glitch::UnknownGlitchArea1; }
			if (location == 910) { coords = Glitch::UnknownGlitchArea2; }
			if (location == 911) { coords = Glitch::VesupucciHouse; }
			//if (location == 901) { coords = Glitch::; }

			// Other Locations
			if (location == 1001) { coords = Other::Atmosphere; }
			if (location == 1002) { coords = Other::MazeBankClouds; }
			if (location == 1003) { coords = Other::MazeBankSky; }
			if (location == 1004) { coords = Other::Space; }

			/*
			// Robbery Locations
			if (location == 1101) { coords = Robbery::GasStationElBurroHeights; }
			if (location == 1102) { coords = Robbery::GrandSenoraFreeway; }
			if (location == 1103) { coords = Robbery::GrapeseedMainSt; }
			if (location == 1104) { coords = Robbery::GreatOceanHighway; }
			if (location == 1105) { coords = Robbery::LTDGasolineEMirrorDr; }
			if (location == 1106) { coords = Robbery::LTDGasolineGroveSt; }
			if (location == 1107) { coords = Robbery::LTDGasolineLindsay; }
			if (location == 1108) { coords = Robbery::LTDGasolineTongvaDr; }
			if (location == 1109) { coords = Robbery::RobsLiquorElRancho; }
			if (location == 1110) { coords = Robbery::RobsLiquorProsperity; }
			if (location == 1111) { coords = Robbery::RobsLiquorSanAndreas; }
			if (location == 1112) { coords = Robbery::Route68Harmony; }
			if (location == 1113) { coords = Robbery::Route68ScoopsLiquor; }
			if (location == 1114) { coords = Robbery::SupermarketBarbarenoRd; }
			if (location == 1115) { coords = Robbery::SupermarketClintonAve; }
			if (location == 1116) { coords = Robbery::SupermarketInesenoRd; }
			if (location == 1117) { coords = Robbery::SupermarketInnocence; }
			if (location == 1118) { coords = Robbery::SupermarketNilandAve; }
			if (location == 1119) { coords = Robbery::SupermarketSenora; }
			if (location == 1120) { coords = Robbery::SupermarketTataviamMtn; }
			*/

			// Do The Actual Teleport
			int player = PlayerSelf();

			if (!noCoords)
			{
				// If player in vehicle, dont put inside car
				if (IS_PED_IN_ANY_VEHICLE(player, true) == false)
				{
					//DO_SCREEN_FADE_OUT(400);
					sleep(200);
					//coords = Vec3toFloat(GET_ENTITY_COORDS(player, true));
					float heading = GET_ENTITY_HEADING(player);
					SET_ENTITY_COORDS(player, coords, 1, 0, 0, 1);
					SET_ENTITY_HEADING(player, heading);
					//SET_ENTITY_HEADING(player, heading);
					//sleep(750);
					//DO_SCREEN_FADE_IN(400);
				}
				else
				{
					//DO_SCREEN_FADE_OUT(400);
					sleep(200);
					Vehicle vehicle = GET_VEHICLE_PED_IS_IN(player, false);
					float heading = GET_ENTITY_HEADING(vehicle);
					//coords = Vec3toFloat(GET_ENTITY_COORDS(vehicle, true));
					SET_ENTITY_COORDS(vehicle, coords, 1, 0, 0, 1);
					SET_ENTITY_HEADING(vehicle, heading);
					//SET_ENTITY_HEADING(vehicle, heading);
					//sleep(750);
					//DO_SCREEN_FADE_IN(400);
				}
			}
		}

		



		/*
		// Teleport To Talking Player
		bool isTeleportToTalkingT = false;
		void TeleportToTalkingPlayer(int SelectedPlayer)
		{
			isTeleportToTalkingT = !isTeleportToTalkingT;
			isTeleportToTalking = isTeleportToTalkingT;
		}
		*/
		
		
		/*
		// Teleport To Client
		int SelectedClient;
		void TeleportToPlayer(int client)
		{
			Ped playerPed = GET_PLAYER_PED(client);
			Vec3 playerPos = GetEntityCoordsVec3(playerPed);
			float* pedCoordsFloat = Vec3toFloat(playerPos);

			if (IS_PED_IN_ANY_VEHICLE(client, true) == false)
			{
				SET_ENTITY_COORDS(PlayerSelf(), pedCoordsFloat, 1, 0, 0, 1);
			}
			else
			{
				SET_ENTITY_COORDS(PlayerSelf(), pedCoordsFloat, 1, 0, 0, 1);
				Vehicle currentVehicle = GetCurrentVehicle(GET_PLAYER_PED(SelectedPlayer));
				//SET_ENTITY_COORDS(PlayerSelf(), coords, 1, 0, 0, 1);
				//SET_ENTITY_COORDS(currentVehicle, coords, 1, 0, 0, 1);
				SET_PED_INTO_VEHICLE(PlayerSelf(), currentVehicle, -1);
			}
		}
		*/
		

		// Teleport Into Vehicle
		void TeleportToNearestVehicle(int seat)
		{
			//int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 100.0, 0, 260);
			int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 250.0, 0, 100);

			//int freeSeat = Functions::Vehicles_f::getFreeSeat(closestVehicleToPlayer);

			//SET_PED_INTO_VEHICLE(PlayerSelf(), closestVehicleToPlayer, -1);
			SET_PED_INTO_VEHICLE(PlayerSelf(), closestVehicleToPlayer, seat);
			//SET_INTO_VEHICLE(vehicle);
				
			playersCurrentVehicle = GetCurrentVehicle(PlayerSelf());
		}

		// Teleport Into Vehicle Any Free Seat
		void TeleportToNearestVehicleAnySeat(int seat)
		{
			int closestVehicleToPlayer = GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true)), 250.0, 0, 100);

			int freeSeat = Vehicles_f::getFreeSeat(closestVehicleToPlayer);

			SET_PED_INTO_VEHICLE(PlayerSelf(), closestVehicleToPlayer, freeSeat);
				
			playersCurrentVehicle = GetCurrentVehicle(PlayerSelf());
		}


		void TeleportUp(int dummy)
		{
			Vec3 playerCoordsVec3 = GET_ENTITY_COORDS(PlayerSelf(), true);

			playerCoordsVec3.z = playerCoordsVec3.z + 5;

			float* playerCoords = Vec3toFloat(playerCoordsVec3);


			if (IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true) == false)
			{
				SET_ENTITY_COORDS(PlayerSelf(), playerCoords, 1, 0, 0, 1);
			}
			else
			{
				Ped currentVehicle = GetCurrentVehicle(PlayerSelf());
				SET_ENTITY_COORDS(currentVehicle, playerCoords, 1, 0, 0, 1);
			}

			
			//char coordsTemp[64];
			//Print(coordsTemp, "~w~Coords: ~y~%i\n~w~Heading: ~y~%i", playerCoords, playerHeading);
			//PrintText(coordsTemp, 3000);
		}


		void TeleportUpSuper(int dummy)
		{
			Vec3 playerCoordsVec3 = GET_ENTITY_COORDS(PlayerSelf(), true);

			playerCoordsVec3.z = playerCoordsVec3.z + 500;

			float* playerCoords = Vec3toFloat(playerCoordsVec3);


			if (IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true) == false)
			{
				SET_ENTITY_COORDS(PlayerSelf(), playerCoords, 1, 0, 0, 1);
			}
			else
			{
				Ped currentVehicle = GetCurrentVehicle(PlayerSelf());
				SET_ENTITY_COORDS(currentVehicle, playerCoords, 1, 0, 0, 1);
			}

			
			//char coordsTemp[64];
			//Print(coordsTemp, "~w~Coords: ~y~%i\n~w~Heading: ~y~%i", playerCoords, playerHeading);
			//PrintText(coordsTemp, 3000);
		}
		

		void TeleportForward(int type)
		{
			Vec3 playerDirection = GET_ENTITY_FORWARD_VECTOR_ALT(PlayerSelf());
			//float playerHeading = GET_ENTITY_HEADING(PlayerSelf());
			//float playerHeading = GET_ENTITY_HEADING(PlayerSelf()) + (90.0f);;
			//float* playerHeading = playerHeading_;
			//Vec3 playerCoordsVec3 = GET_ENTITY_COORDS(PlayerSelf(), true);

			
			
			if (type == 1)
			{
				//playerHeading += 5;
				//playerCoordsVec3.x = playerCoordsVec3.x + 10;
				//playerCoordsVec3.y = playerCoordsVec3.y - 5;
				playerDirection.y += playerDirection.y + 2;
			}
			if (type == 2)
			{
				//playerHeading += 50;
				//playerCoordsVec3.x = playerCoordsVec3.x + 50;
				//playerCoordsVec3.y = playerCoordsVec3.y - 25;
				playerDirection.y += playerDirection.y + 10;
			}
			if (type == 3)
			{
				//playerHeading += 500;
				//playerCoordsVec3.x = playerCoordsVec3.x + 500;
				//playerCoordsVec3.y = playerCoordsVec3.y - 250;
				playerDirection.y += playerDirection.y + 50;
			}
			
			float* playerCoords = Vec3toFloat(playerDirection);
			//float* playerCoords = Vec3toFloat(playerCoordsVec3);
			//float playerHeading = GET_ENTITY_HEADING(PlayerSelf());
			//Vec3 entityCoords = GET_ENTITY_COORDS(PlayerSelf(),true);


			if (IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true) == false)
			{
				SET_ENTITY_COORDS(PlayerSelf(), playerCoords, 1, 0, 0, 1);
			}
			else
			{
				Ped currentVehicle = GetCurrentVehicle(PlayerSelf());
				SET_ENTITY_COORDS(currentVehicle, playerCoords, 1, 0, 0, 1);
			}

		}


		void TeleportBackward(int type)
		{
			Vec3 playerDirection = GET_ENTITY_FORWARD_VECTOR_ALT(PlayerSelf());
			//float playerHeading = GET_ENTITY_HEADING(PlayerSelf());
			//float playerHeading = GET_ENTITY_HEADING(PlayerSelf()) + (90.0f);;
			//float* playerHeading = playerHeading_;
			//Vec3 playerCoordsVec3 = GET_ENTITY_COORDS(PlayerSelf(), true);

			
			
			if (type == 1)
			{
				//playerHeading += 5;
				//playerCoordsVec3.x = playerCoordsVec3.x + 10;
				//playerCoordsVec3.y = playerCoordsVec3.y - 5;
				playerDirection.y += playerDirection.y - 2;
			}
			if (type == 2)
			{
				//playerHeading += 50;
				//playerCoordsVec3.x = playerCoordsVec3.x + 50;
				//playerCoordsVec3.y = playerCoordsVec3.y - 25;
				playerDirection.y += playerDirection.y - 10;
			}
			if (type == 3)
			{
				//playerHeading += 500;
				//playerCoordsVec3.x = playerCoordsVec3.x + 500;
				//playerCoordsVec3.y = playerCoordsVec3.y - 250;
				playerDirection.y += playerDirection.y - 50;
			}
			
			float* playerCoords = Vec3toFloat(playerDirection);
			//float* playerCoords = Vec3toFloat(playerCoordsVec3);
			//float playerHeading = GET_ENTITY_HEADING(PlayerSelf());
			//Vec3 entityCoords = GET_ENTITY_COORDS(PlayerSelf(),true);


			if (IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true) == false)
			{
				SET_ENTITY_COORDS(PlayerSelf(), playerCoords, 1, 0, 0, 1);
			}
			else
			{
				Ped currentVehicle = GetCurrentVehicle(PlayerSelf());
				SET_ENTITY_COORDS(currentVehicle, playerCoords, 1, 0, 0, 1);
			}

		}
		
	};

};





#endif

