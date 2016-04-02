#ifndef __VEHICLES_H
#define __VEHICLES_H


#include "hashes.h"
#include "hud.h"
#include "licensing.h"
//#include "menu.h"
#include "messages.h"
#include "misc.h"
#include "natives.h"

using namespace Dialog;
using namespace Hashes;
using namespace Hud;
using namespace Keyboard;
using namespace Licensing;
//using namespace Menu_f;
using namespace Misc;
using namespace Natives;



namespace Vehicles_f
{
	
	// Set Player Into Vehicle
	void SET_INTO_VEHICLE(int VehicleHandle) 
	{
		bool Max = GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(VehicleHandle), Existing = GET_VEHICLE_NUMBER_OF_PASSENGERS(VehicleHandle);
		if (!Max == Existing) 
		{
			for (int SeatIndex = -1; SeatIndex <= Max; SeatIndex++) 
			{
				if (IS_VEHICLE_SEAT_FREE(VehicleHandle, SeatIndex)) 
				{
					SET_PED_INTO_VEHICLE(PlayerSelf(), VehicleHandle, SeatIndex);
					SeatIndex = Max + 1;
				}
			}
		}
	}

	bool hydraulicsActiveT = false;
	void CarHydraulics(int dummy)
	{
		hydraulicsHeightAdjust = 0;
		hydraulicsHeight = 0.8f;

		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			hydraulicsActiveT = !hydraulicsActiveT;
			hydraulicsActive = hydraulicsActiveT;

			if (hydraulicsActive)
			{
				char buffer[128];
				sprintf(buffer, "~w~Hydraulics ~g~Enabled\n~w~Adjust Height: ~y~DPAD L+R\n~w~Control: ~y~R1 ~w~Button");
				PrintText(buffer, 6000);
			}
			else
			{
				char buffer[48];
				sprintf(buffer, "Hydraulics ~r~Disabled");
				PrintText(buffer, 3000);
			}
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}

	
	void HydraulicsHeightControl()
	{
		if (HydraulicsHeightUp)
		{
			switch(hydraulicsHeightAdjust)
			{
				case 0:
					hydraulicsHeightAdjust = 1;
					hydraulicsHeight = 0.8f;
					break;
				case 1:
					hydraulicsHeightAdjust = 2;
					hydraulicsHeight = 1.0f;
					break;
				case 2:
					hydraulicsHeightAdjust = 3;
					hydraulicsHeight = 1.2f;
					break;
				case 3:
					hydraulicsHeightAdjust = 4;
					hydraulicsHeight = 1.4f;
					break;
				case 4:
					hydraulicsHeightAdjust = 5;
					hydraulicsHeight = 1.6f;
					break;
				case 5:
					hydraulicsHeightAdjust = 6;
					hydraulicsHeight = 1.8f;
					break;
				case 6:
					hydraulicsHeightAdjust = 7;
					hydraulicsHeight = 2.0f;
					break;
				case 7:
					hydraulicsHeightAdjust = 8;
					hydraulicsHeight = 2.2f;
					break;
				case 8:
					hydraulicsHeightAdjust = 9;
					hydraulicsHeight = 2.4f;
					break;
				case 9:
					hydraulicsHeightAdjust = 0;
					hydraulicsHeight = 0.6f;
					break;
			}
		}

		if (HydraulicsHeightDown)
		{

			switch(hydraulicsHeightAdjust)
			{
				case 0:
					hydraulicsHeightAdjust = 9;
					hydraulicsHeight = 2.4f;
					break;
				case 1:
					hydraulicsHeightAdjust = 0;
					hydraulicsHeight = 0.6f;
					break;
				case 2:
					hydraulicsHeightAdjust = 1;
					hydraulicsHeight = 0.8f;
					break;
				case 3:
					hydraulicsHeightAdjust = 2;
					hydraulicsHeight = 1.0f;
					break;
				case 4:
					hydraulicsHeightAdjust = 3;
					hydraulicsHeight = 1.2f;
					break;
				case 5:
					hydraulicsHeightAdjust = 4;
					hydraulicsHeight = 1.4f;
					break;
				case 6:
					hydraulicsHeightAdjust = 5;
					hydraulicsHeight = 1.6f;
					break;
				case 7:
					hydraulicsHeightAdjust = 6;
					hydraulicsHeight = 1.8f;
					break;
				case 8:
					hydraulicsHeightAdjust = 7;
					hydraulicsHeight = 2.0f;
					break;
				case 9:
					hydraulicsHeightAdjust = 8;
					hydraulicsHeight = 2.2f;
					break;
			}
		}
	}


	/*
	void HydraulicsHeightControl()
	{
		if (HydraulicsHeightUp)
		{
			if (hydraulicsHeightAdjust <= 0 || hydraulicsHeightAdjust >= 9)
			{
				hydraulicsHeightAdjust = 1;
				hydraulicsHeight = 0.8f;
				HydraulicsHeightReset = true;
				HydraulicsHeightUp = false;
			}

			if (hydraulicsHeight <= 0.0f || hydraulicsHeight >= 3.0f)
			{
				hydraulicsHeightAdjust = 1;
				hydraulicsHeight = 0.8f;
				HydraulicsHeightReset = true;
				HydraulicsHeightUp = false;
			}

			if (!HydraulicsHeightReset)
			{
				hydraulicsHeight = hydraulicsHeight += 0.2f;
				hydraulicsHeightAdjust = hydraulicsHeightAdjust += 1;
				HydraulicsHeightUp = false;
			}
		}

		if (HydraulicsHeightDown)
		{
			if (hydraulicsHeightAdjust <= 0 || hydraulicsHeightAdjust > 9)
			{
				hydraulicsHeightAdjust = 1;
				hydraulicsHeight = 0.8f;
				HydraulicsHeightReset = true;
				HydraulicsHeightDown = false;
			}

			if (hydraulicsHeight <= 0.0f || hydraulicsHeight >= 3.0f)
			{
				hydraulicsHeightAdjust = 1;
				hydraulicsHeight = 0.8f;
				HydraulicsHeightReset = true;
				HydraulicsHeightDown = false;
			}

			if (!HydraulicsHeightReset)
			{
				hydraulicsHeight = hydraulicsHeight -= 0.2f;
				hydraulicsHeightAdjust = hydraulicsHeightAdjust -= 1;
				HydraulicsHeightDown = false;
			}
		}
	}
	*/

	void GetCarInfo(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		int vehicle = GetCurrentVehicle(player);
		int kit = GET_VEHICLE_MOD_KIT(vehicle);
		int type = GET_VEHICLE_MOD_KIT_TYPE(vehicle);
		int wheel = GET_VEHICLE_WHEEL_TYPE(vehicle);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			char buffer[100];
			//sprintf(buffer, "~w~Player: ~y~%s / ~w~Vehicle: ~p~%i\n~w~Kit: ~b~%i ~w~/ Type: ~b~%i ~w~/ Wheel: ~b~%i", player, vehicle, kit, type, wheel);
			sprintf(buffer, "~w~Vehicle: ~p~%i\n~w~Kit: ~b~%i ~w~/ Type: ~b~%i ~w~/ Wheel: ~b~%i", vehicle, kit, type, wheel);
			PrintText(buffer, 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}

	

	
	// Toggle Blinker Control 
	bool areBlinkersActiveT = false;
	void ToggleBlinkerBind(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			areBlinkersActiveT = !areBlinkersActiveT;
			areBlinkersActive = areBlinkersActiveT;
			char bbEnabled[64];
			sprintf(bbEnabled, "~g~Turn Signals Enabled\n~b~L1 or R1 ON\nR2+L1 or R2+L1 OFF");
			char bbDisabled[32];
			sprintf(bbDisabled, "~r~Turn Signals Disabled");
			PrintText(areBlinkersActiveT ? bbEnabled : bbDisabled , 5000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}

	/*
	void TakeVehicleOwnership(int SelectedPlayer)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			playersCurrentVehicle = GetCurrentVehicle(player);

			SET_PLAYER_MAY_ONLY_ENTER_THIS_VEHICLE(player, playersCurrentVehicle);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/

	/*
	// Toggle Vehicle Entity Collision
	bool vehicleIsClipping = true;
	void ToggleVehicleIsClipping(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			playersCurrentVehicle = GetCurrentVehicle(PlayerSelf());
			vehicleIsClipping = !vehicleIsClipping;
			SET_ENTITY_COLLISION(playersCurrentVehicle, vehicleIsClipping, false);
			MsgToggleReverse("No Clipping", vehicleIsClipping);
			//PrintText(vehicleIsClipping ? "~r~No Clipping Disabled" : "~g~No Clipping Enabled" , 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/

	/*
	// Set Entity Max Speed
	void SetVehicleMaxSpeed(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			playersCurrentVehicle = GetCurrentVehicle(PlayerSelf());
			SET_ENTITY_MAX_SPEED(playersCurrentVehicle, 400);
			PrintText("~y~Max Speed Set", 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/

	// Change License Plate Text
	void ChangeLicensePlateText(int textChoice)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			if (textChoice == 0) { void ToggleKeyboard(); SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "ILLICIT");}
			if (textChoice == 1) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "ILLICIT"); }
			if (textChoice == 2) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "        "); }
			if (textChoice == 3) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "ROCKSTAR"); }
			if (textChoice == 4) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "SONY"); }
			if (textChoice == 5) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "CHEATER"); }
			if (textChoice == 6) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "HACKER"); }
			if (textChoice == 7) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "MODDER"); }
			if (textChoice == 8) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "BOOBIES"); }
			if (textChoice == 9) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "RACENE1"); }
			if (textChoice == 10) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "2FAST4U"); }
			if (textChoice == 11) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "LUV2XLR8"); }
			if (textChoice == 12) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "420"); }
			if (textChoice == 13) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "  5 0  "); }
			if (textChoice == 14) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "POLICE"); }
			if (textChoice == 15) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "THE FUZZ"); }
			if (textChoice == 16) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "THE PIGS"); }
			if (textChoice == 17) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "  PIG  "); }
			if (textChoice == 18) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "OUTATIME"); }
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}

	// Change License Plate Type
	void ChangeLicensePlateType(int typeChoice)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		int currentVehicle = GetCurrentVehicle(PlayerSelf());
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			if (typeChoice == 1) { SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(currentVehicle, 0); }
			if (typeChoice == 2) { SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(currentVehicle, 1); }
			if (typeChoice == 3) { SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(currentVehicle, 2); }
			if (typeChoice == 4) { SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(currentVehicle, 3); }
			if (typeChoice == 5) { SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(currentVehicle, 4); }
			if (typeChoice == 6) { SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(currentVehicle, 5); }
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
			
	}

	// Change Licence Plate Color (???)
	void ChangeLicensePlateColor(int colorChoice)
	{
		//if (colorChoice == 1) { SET_VEHICLE_NUMBER_PLATE_TEXT(GetCurrentVehicle(PlayerSelf()), "ILLICIT"); }
	}


	// Fully Tune Max Out Vehicle
	void MaxOutVehicle(int vehicleID)
	{
		//int player = GET_PLAYER_PED(PlayerSelected);
		int player = PlayerSelf();
		int VehicleHandle = GetCurrentVehicle(player);
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
				
			//Vehicle VehicleHandle = GetCurrentVehicle(PlayerSelf());
			
			// Check if demo
			if (demoMode == true)
			{
				SET_VEHICLE_NUMBER_PLATE_TEXT(playersCurrentVehicle, "DEMOTEST");
			}
			else
			{
				SET_VEHICLE_NUMBER_PLATE_TEXT(VehicleHandle, "ILLICIT");
			}
			// Make Godmode on Max Out
			if (godmodeOnVehicleMaxOut == true)
			{
				SET_ENTITY_PROOFS(VehicleHandle, true, true, true, true, true, true, true, true);
				SET_ENTITY_INVINCIBLE(VehicleHandle, true);
				SET_ENTITY_CAN_BE_DAMAGED(VehicleHandle, false);
				SET_VEHICLE_STRONG(VehicleHandle, true);
			}
			
			SET_VEHICLE_MOD_KIT(VehicleHandle, 0);
			SET_VEHICLE_COLOURS(VehicleHandle, Hashes_Colors::ModshopBlack1, Hashes_Colors::ModshopBlack1);
			SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(VehicleHandle, 0);
			TOGGLE_VEHICLE_MOD(VehicleHandle, 18, 1);
			TOGGLE_VEHICLE_MOD(VehicleHandle, 20, 1);
			TOGGLE_VEHICLE_MOD(VehicleHandle, 22, 1);
			SET_VEHICLE_MOD(VehicleHandle, 16, 5, 0);
			SET_VEHICLE_MOD(VehicleHandle, 12, 2, 0);
			SET_VEHICLE_MOD(VehicleHandle, 11, 3, 0);
			SET_VEHICLE_MOD(VehicleHandle, 14, 14, 0);
			SET_VEHICLE_MOD(VehicleHandle, 15, 3, 0);
			SET_VEHICLE_MOD(VehicleHandle, 13, 2, 0);
			SET_VEHICLE_WHEEL_TYPE(VehicleHandle, 6);
			SET_VEHICLE_WINDOW_TINT(VehicleHandle, 5);
			SET_VEHICLE_MOD(VehicleHandle, 23, 19, 1);
			SET_VEHICLE_MOD(VehicleHandle, 0, 1, 0);
			SET_VEHICLE_MOD(VehicleHandle, 1, 1, 0);
			SET_VEHICLE_MOD(VehicleHandle, 2, 1, 0);
			SET_VEHICLE_MOD(VehicleHandle, 3, 1, 0);
			SET_VEHICLE_MOD(VehicleHandle, 4, 1, 0);
			SET_VEHICLE_MOD(VehicleHandle, 5, 1, 0);
			SET_VEHICLE_MOD(VehicleHandle, 6, 1, 0);
			SET_VEHICLE_MOD(VehicleHandle, 7, 1, 0);
			SET_VEHICLE_MOD(VehicleHandle, 8, 1, 0);
			SET_VEHICLE_MOD(VehicleHandle, 9, 1, 0);
			SET_VEHICLE_MOD(VehicleHandle, 10, 1, 0);
			SET_VEHICLE_TYRE_SMOKE_COLOR(VehicleHandle, 1, 1, 1);
				
			SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(VEH_TO_NET(VehicleHandle), 1);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	
	
	
	// Toggle Vehicle Godmode
	bool vehicleGodmode = false;
	void ToggleVehicleGodmode(int vehicle)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			int vehicle = GetCurrentVehicle(PlayerSelf());
			vehicleGodmode = !vehicleGodmode;
			SET_ENTITY_PROOFS(vehicle, vehicleGodmode, vehicleGodmode, vehicleGodmode, vehicleGodmode, vehicleGodmode, vehicleGodmode, vehicleGodmode, vehicleGodmode);
			SET_ENTITY_INVINCIBLE(vehicle, vehicleGodmode);
			SET_ENTITY_CAN_BE_DAMAGED(vehicle, !vehicleGodmode);
			SET_VEHICLE_TYRES_CAN_BURST(vehicle, !vehicleGodmode);
			SET_VEHICLE_WHEELS_CAN_BREAK(vehicle, !vehicleGodmode);
			SET_VEHICLE_STRONG(vehicle, vehicleGodmode);
			MsgToggleDefault("Vehicle Godmode", vehicleGodmode);
			//SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(VEH_TO_NET(vehicle), 1);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}


	// Vehicle Godmode
	void VehicleGodmode(int vehicle)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			int vehicle = GetCurrentVehicle(PlayerSelf());
			SET_ENTITY_PROOFS(vehicle, true, true, true, true, true, true, true, true);
			SET_ENTITY_INVINCIBLE(vehicle, true);
			SET_ENTITY_CAN_BE_DAMAGED(vehicle, false);
			SET_VEHICLE_TYRES_CAN_BURST(vehicle, false);
			SET_VEHICLE_WHEELS_CAN_BREAK(vehicle, false);
			SET_VEHICLE_STRONG(vehicle, true);
			//SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(VEH_TO_NET(vehicle), 1);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}


	// Spawn Vehicles
	void SpawnVehicle(int vehicleChoice)
	{
		
		// Bikes (1xx)
		switch(vehicleChoice)
		{
			case 101: vehicleUint = 1131912276, vehicleName = "";// BMX Bike
			break;
			case 102: vehicleUint = 448402357, vehicleName = "";// Cruiser
			break;
			case 103: vehicleUint = 3061159916, vehicleName = "";// Endurex Race Bike
			break;
			case 104: vehicleUint = 3458454463, vehicleName = "";// Fixter
			break;
			case 105: vehicleUint = 4108429845, vehicleName = "";// Scorcher
			break;
			case 106: vehicleUint = 3894672200, vehicleName = "";// Tri-Cycles Race Bike
			break;
			case 107: vehicleUint = 1127861609, vehicleName = "";// Whippet Race Bike
			break;

			// Boats (2xx)
			case 201: vehicleUint = 1033245328, vehicleName = "";// Dinghy
			break;
			case 202: vehicleUint = 276773164, vehicleName = "";// Dinghy 2-Seater
			break;
			case 203: vehicleUint = 509498602, vehicleName = "";// Dinghy (New)
			break;
			case 204: vehicleUint = 861409633, vehicleName = "";// Jetmax
			break;
			case 205: vehicleUint = 3228633070, vehicleName = "";// Kraken
			break;
			case 206: vehicleUint = 3251507587, vehicleName = "";// Marquis
			break;
			case 207: vehicleUint = 3264692260, vehicleName = "";// Seashark (Speedophile)
			break;
			case 208: vehicleUint = 3678636260, vehicleName = "";// Seashark (LifeGuard)
			break;
			case 209: vehicleUint = 231083307, vehicleName = "";// Speeder (DLC)
			break;
			case 210: vehicleUint = 400514754, vehicleName = "";// Squalo
			break;
			case 211: vehicleUint = 771711535, vehicleName = "";// Submersible
			break;
			case 212: vehicleUint = 4012021193, vehicleName = "";// Suntrap
			break;
			case 213: vehicleUint = 1070967343, vehicleName = "";// Toro (DLC)
			break;
			case 214: vehicleUint = 290013743, vehicleName = "";// Tropic
			break;

			// Commercial (3xx)
			case 301: vehicleUint = 2053223216, vehicleName = "";// Benson
			break;
			case 302: vehicleUint = 850991848, vehicleName = "";// Biff
			break;
			case 303: vehicleUint = 1518533038, vehicleName = "";// Hauler
			break;
			case 304: vehicleUint = 904750859, vehicleName = "";// Mule
			break;
			case 305: vehicleUint = 3244501995, vehicleName = "";// Mule (Drop Down)
			break;
			case 306: vehicleUint = 569305213, vehicleName = "";// Packer
			break;
			case 307: vehicleUint = 2157618379, vehicleName = "";// Phantom
			break;
			case 308: vehicleUint = 2112052861, vehicleName = "";// Pounder
			break;
			case 309: vehicleUint = 1747439474, vehicleName = "";// Stockade
			break;
			case 310: vehicleUint = 4080511798, vehicleName = "";// Stockade (Snowy)
			break;

			// Compacts (4xx)
			case 401: vehicleUint = 3950024287, vehicleName = "";// Blista
			break;
			case 402: vehicleUint = 3164157193, vehicleName = "";// Dilettante
			break;
			case 403: vehicleUint = 3117103977, vehicleName = "";// Issi (Convertible)
			break;
			case 404: vehicleUint = 3863274624, vehicleName = "";// Panto (DLC)
			break;
			case 405: vehicleUint = 2844316578, vehicleName = "";// Prairie
			break;
			case 406: vehicleUint = 841808271, vehicleName = "";//  Rhapsody (DLC)
			break;

			// Coupes (5xx)
			case 501: vehicleUint = 330661258, vehicleName = "";// Cognoscenti Cabrio
			break;
			case 502: vehicleUint = 4289813342, vehicleName = "";// Exemplar
			break;
			case 503: vehicleUint = 3703357000, vehicleName = "";// F620
			break;
			case 504: vehicleUint = 3903372712, vehicleName = "";// Felon
			break;
			case 505: vehicleUint = 4205676014, vehicleName = "";// Felon GT (C)
			break;
			case 506: vehicleUint = 3670438162, vehicleName = "";// Jackal
			break;
			case 507: vehicleUint = 1348744438, vehicleName = "";// Oracle
			break;
			case 508: vehicleUint = 3783366066, vehicleName = "";// Oracle XS
			break;
			case 509: vehicleUint = 1349725314, vehicleName = "";// Sentinel
			break;
			case 510: vehicleUint = 873639469, vehicleName = "";// Sentinel XS
			break;
			case 511: vehicleUint = 1581459400, vehicleName = "";// Windsor (DLC)
			break;
			case 512: vehicleUint = 3172678083, vehicleName = "";// Zion XS
			break;
			case 513: vehicleUint = 3101863448, vehicleName = "";// Zion XS (C)
			break;

			// Emergency (6xx)
			case 601: vehicleUint = 1131912276, vehicleName = "";// Air Ambulance
			break;
			case 602: vehicleUint = 1171614426, vehicleName = "";// Ambulance
			break;
			case 603: vehicleUint = 1621617168, vehicleName = "";// Cargobob (Medical)
			break;
			case 604: vehicleUint = 1127131465, vehicleName = "";// FIB Buffalo
			break;
			case 605: vehicleUint = 2647026068, vehicleName = "";// FIB Granger
			break;
			case 606: vehicleUint = 1938952078, vehicleName = "";// Fire Truck
			break;
			case 607: vehicleUint = 4246935337, vehicleName = "";// LifeGuard Blazer
			break;
			case 608: vehicleUint = 469291905, vehicleName = "";// LifeGuard Granger
			break;
			case 609: vehicleUint = 1682114128, vehicleName = "";// Merryweather Patrol Car
			break;
			case 610: vehicleUint = 741586030, vehicleName = "";// Park Ranger
			break;
			case 611: vehicleUint = 4260343491, vehicleName = "";// Police Bike
			break;
			case 612: vehicleUint = 2667966721, vehicleName = "";// Police Buffalo
			break;
			case 613: vehicleUint = 2046537925, vehicleName = "";// Police Cruiser (Stanier)
			break;
			case 614: vehicleUint = 1912215274, vehicleName = "";// Police Interceptor
			break;
			case 615: vehicleUint = 353883353, vehicleName = "";// Police Maverick
			break;
			case 616: vehicleUint = 2758042359, vehicleName = "";// Police Rancher (Snowy)
			break;
			case 617: vehicleUint = 3089277354, vehicleName = "";// Police Riot
			break;
			case 618: vehicleUint = 2515846680, vehicleName = "";// Police Roadcruiser
			break;
			case 619: vehicleUint = 456714581, vehicleName = "";// Police Transporter
			break;
			case 620: vehicleUint = 2287941233, vehicleName = "";// Police Prison Bus
			break;
			case 621: vehicleUint = 3806844075, vehicleName = "";// Police Predator Boat
			break;
			case 622: vehicleUint = 2611638396, vehicleName = "";// Sheriff Cruiser (Stanier)
			break;
			case 623: vehicleUint = 1922257928, vehicleName = "";// Sheriff Granger
			break;
			case 624: vehicleUint = 2321795001, vehicleName = "";// Unmarked Cruiser
			break;

			// Helicopters (7xx)
			case 701: vehicleUint = 837858166, vehicleName = "";// Annihilator
			break;
			case 702: vehicleUint = 745926877, vehicleName = "";// Buzzard
			break;
			case 703: vehicleUint = 788747387, vehicleName = "";// Buzzard (Attack Chopper)
			break;
			case 704: vehicleUint = 4244420235, vehicleName = "";// Cargobob
			break;
			case 705: vehicleUint = 1394036463, vehicleName = "";// Cargobob (Trevor)
			break;
			case 706: vehicleUint = 744705981, vehicleName = "";// Frogger
			break;
			case 707: vehicleUint = 1949211328, vehicleName = "";// Frogger (Trevor)
			break;
			case 708: vehicleUint = 2634305738, vehicleName = "";// Maverick
			break;
			case 709: vehicleUint = 4212341271, vehicleName = "";// Savage (DLC)
			break;
			case 710: vehicleUint = 1044954915, vehicleName = "";// Skylift
			break;
			case 711: vehicleUint = 3955379698, vehicleName = "";// Swift (DLC)
			break;
			case 712: vehicleUint = 1075432268, vehicleName = "";// Swift Deluxe (DLC)
			break;
			case 713: vehicleUint = 2694714877, vehicleName = "";// Valkyrie (DLC)
			break;

			// Industrial (8xx)
			case 801: vehicleUint = 1886712733, vehicleName = "";// Bulldozer
			break;
			case 802: vehicleUint = 3288047904, vehicleName = "";// Cutter
			break;
			case 803: vehicleUint = 444583674, vehicleName = "";// Dock Handler
			break;
			case 804: vehicleUint = 2164484578, vehicleName = "";// Dump Truck
			break;
			case 805: vehicleUint = 1353720154, vehicleName = "";// Flatbed
			break;
			case 806: vehicleUint = 2186977100, vehicleName = "";// Guardian (DLC)
			break;
			case 807: vehicleUint = 3510150843, vehicleName = "";// Mixer
			break;
			case 808: vehicleUint = 475220373, vehicleName = "";// Mixer (Wheels On Back)
			break;
			case 809: vehicleUint = 2589662668, vehicleName = "";// Rubble
			break;
			case 810: vehicleUint = 48339065, vehicleName = "";// Tipper (6-Wheeler)
			break;
			case 811: vehicleUint = 3347205726, vehicleName = "";// Tipper (10-Wheeler)
			break;

			// Military (9xx)
			case 901: vehicleUint = 3471458123, vehicleName = "";// Barracks
			break;
			case 902: vehicleUint = 630371791, vehicleName = "";// Barracks (Dark Camo)
			break;
			case 903: vehicleUint = 1074326203, vehicleName = "";// Barracks (Semi)
			break;
			case 904: vehicleUint = 321739290, vehicleName = "";// Crusader
			break;
			case 905: vehicleUint = 782665360, vehicleName = "";// Rhino Tank
			break;

			// Motorcycles (10xx)
			case 1001: vehicleUint = 1672195559, vehicleName = "";// Akuma
			break;
			case 1002: vehicleUint = 2154536131, vehicleName = "";// Bagger
			break;
			case 1003: vehicleUint = 4180675781, vehicleName = "";// Bati 801
			break;
			case 1004: vehicleUint = 3403504941, vehicleName = "";// Bati 801RR
			break;
			case 1005: vehicleUint = 11251904, vehicleName = "";// Carbon RS
			break;
			case 1006: vehicleUint = 2006142190, vehicleName = "";// Daemon
			break;
			case 1007: vehicleUint = 2623969160, vehicleName = "";// Double T
			break;
			case 1008: vehicleUint = 1753414259, vehicleName = "";// Enduro (DLC)
			break;
			case 1009: vehicleUint = 55628203, vehicleName = "";// Faggio
			break;
			case 1010: vehicleUint = 1265391242, vehicleName = "";// Hakuchou (DLC)
			break;
			case 1011: vehicleUint = 301427732, vehicleName = "";// Hexer
			break;
			case 1012: vehicleUint = 4135840458, vehicleName = "";// Innovation (DLC)
			break;
			case 1013: vehicleUint = 640818791, vehicleName = "";// Lectro (DLC)
			break;
			case 1014: vehicleUint = 3660088182, vehicleName = "";// Nemesis
			break;
			case 1015: vehicleUint = 3385765638, vehicleName = "";// PCJ 600
			break;
			case 1016: vehicleUint = 3401388520, vehicleName = "";// Ruffian
			break;
			case 1017: vehicleUint = 788045382, vehicleName = "";// Sanchez (Livery)
			break;
			case 1018: vehicleUint = 2841686334, vehicleName = "";// Sanchez (Paint)
			break;
			case 1019: vehicleUint = 743478836, vehicleName = "";// Sovereign (DLC)
			break;
			case 1020: vehicleUint = 1836027715, vehicleName = "";// Thrust (DLC)
			break;
			case 1021: vehicleUint = 4154065143, vehicleName = "";// Vader
			break;
			case 1022: vehicleUint = 2941886209, vehicleName = "";// Vindicator (DLC)
			break;

			// Muscle (11xx)
			case 1101: vehicleUint = 3089165662, vehicleName = "";// Blade
			break;
			case 1102: vehicleUint = 3612755468, vehicleName = "";// Buccaneer
			break;
			case 1103: vehicleUint = 349605904, vehicleName = "";// Chino (DLC)
			break;
			case 1104: vehicleUint = 784565758, vehicleName = "";// Coquette BlackFin (DLC)
			break;
			case 1105: vehicleUint = 80636076, vehicleName = "";// Dominator
			break;
			case 1106: vehicleUint = 3379262425, vehicleName = "";// Dominator (Pisswasser)
			break;
			case 1107: vehicleUint = 3968823444, vehicleName = "";// Duke O'Death
			break;
			case 1108: vehicleUint = 723973206, vehicleName = "";// Dukes
			break;
			case 1109: vehicleUint = 2494797253, vehicleName = "";// Gauntlet
			break;
			case 1110: vehicleUint = 349315417, vehicleName = "";// Gauntlet (Redwood)
			break;
			case 1111: vehicleUint = 37348240, vehicleName = "";// Hotknife
			break;
			case 1112: vehicleUint = 2199527893, vehicleName = "";// Phoenix
			break;
			case 1113: vehicleUint = 1507916787, vehicleName = "";// Picador
			break;
			case 1114: vehicleUint = 3627815886, vehicleName = "";// Rat-Loader
			break;
			case 1115: vehicleUint = 3705788919, vehicleName = "";// Rat-Truck (DLC)
			break;
			case 1116: vehicleUint = 4067225593, vehicleName = "";// Ruiner
			break;
			case 1117: vehicleUint = 2609945748, vehicleName = "";// Sabre Turbo
			break;
			case 1118: vehicleUint = 729783779, vehicleName = "";// Slamvan (DLC)
			break;
			case 1119: vehicleUint = 833469436, vehicleName = "";// Slamvan Lost (DLC)
			break;
			case 1120: vehicleUint = 1923400478, vehicleName = "";// Stallion
			break;
			case 1121: vehicleUint = 3893323758, vehicleName = "";// Stallion (Burger Shot)
			break;
			case 1122: vehicleUint = 3796912450, vehicleName = "";// Virgo (DLC)
			break;
			case 1123: vehicleUint = 3469130167, vehicleName = "";// Vigero
			break;
			case 1124: vehicleUint = 523724515, vehicleName = "";// Voodoo (Rusty)
			break;

			// Off-Road (12xx)
			case 1201: vehicleUint = 1126868326, vehicleName = "";// BF Injection
			break;
			case 1202: vehicleUint = 3945366167, vehicleName = "";// Bifta (DLC)
			break;
			case 1203: vehicleUint = 2166734073, vehicleName = "";// Blazer
			break;
			case 1204: vehicleUint = 3025077634, vehicleName = "";// Blazer (Hotrod)
			break;
			case 1205: vehicleUint = 2859047862, vehicleName = "";// Bodhi
			break;
			case 1206: vehicleUint = 2815302597, vehicleName = "";// Brawler (DLC)
			break;
			case 1207: vehicleUint = 3057713523, vehicleName = "";// Dubsta 6x6 (DLC)
			break;
			case 1208: vehicleUint = 2633113103, vehicleName = "";// Dune Buggy
			break;
			case 1209: vehicleUint = 1770332643, vehicleName = "";// Dune Loader
			break;
			case 1210: vehicleUint = 2434067162, vehicleName = "";// Insurgent (DLC)
			break;
			case 1211: vehicleUint = 2071877360, vehicleName = "";// Insurgent Truck (DLC)
			break;
			case 1212: vehicleUint = 92612664, vehicleName = "";// Kalahari (DLC)
			break;
			case 1213: vehicleUint = 1233534620, vehicleName = "";// Marshall
			break;
			case 1214: vehicleUint = 1645267888, vehicleName = "";// Rancher XL
			break;
			case 1215: vehicleUint = 1933662059, vehicleName = "";// Rancher XL (Snowy)
			break;
			case 1216: vehicleUint = 2249373259, vehicleName = "";// Rebel (Clean)
			break;
			case 1217: vehicleUint = 3087195462, vehicleName = "";// Rebel (Rusty)
			break;
			case 1218: vehicleUint = 989381445, vehicleName = "";// Sandking (2-Seater)
			break;
			case 1219: vehicleUint = 3105951696, vehicleName = "";// Sandking (4-Seater)
			break;
			case 1220: vehicleUint = 534258863, vehicleName = "";// Space Docker
			break;
			case 1221: vehicleUint = 2198148358, vehicleName = "";// Technical (DLC)
			break;
			case 1222: vehicleUint = 3449006043, vehicleName = "";// The Liberator (DLC)
			break;

			// Planes (13xx)
			case 1301: vehicleUint = 4143991942, vehicleName = "";// Atomic Blimp
			break;
			case 1302: vehicleUint = 1824333165, vehicleName = "";// Besra (DLC)
			break;
			case 1303: vehicleUint = 368211810, vehicleName = "";// Cargo Plane
			break;
			case 1304: vehicleUint = 3650256867, vehicleName = "";// Cuban 800
			break;
			case 1305: vehicleUint = 3393804037, vehicleName = "";// Dodo
			break;
			case 1306: vehicleUint = 970356638, vehicleName = "";// Duster
			break;
			case 1307: vehicleUint = 970385471, vehicleName = "";// Hydra (DLC)
			break;
			case 1308: vehicleUint = 1058115860, vehicleName = "";// Jet
			break;
			case 1309: vehicleUint = 621481054, vehicleName = "";// Luxor
			break;
			case 1310: vehicleUint = 3080673438, vehicleName = "";// Luxor Deluxe (DLC)
			break;
			case 1311: vehicleUint = 2172210288, vehicleName = "";// Mallard (Stunt Plane)
			break;
			case 1312: vehicleUint = 2548391185, vehicleName = "";// Mammatus
			break;
			case 1313: vehicleUint = 165154707, vehicleName = "";// Miljet (DLC)
			break;
			case 1314: vehicleUint = 3013282534, vehicleName = "";// P-996 Lazer
			break;
			case 1315: vehicleUint = 3080461301, vehicleName = "";// Shamal
			break;
			case 1316: vehicleUint = 1981688531, vehicleName = "";// Titan
			break;
			case 1317: vehicleUint = 2621610858, vehicleName = "";// Velum
			break;
			case 1318: vehicleUint = 1077420264, vehicleName = "";// Velum 5-Seater (DLC)
			break;
			case 1319: vehicleUint = 1341619767, vehicleName = "";// Vestra (DLC)
			break;
			case 1320: vehicleUint = 3681241380, vehicleName = "";// Xero Blimp
			break;

			// Sedans (14xx)
			case 1401: vehicleUint = 2485144969, vehicleName = "";// Asea
			break;
			case 1402: vehicleUint = 2487343317, vehicleName = "";// Asea (Snowy)
			break;
			case 1403: vehicleUint = 2391954683, vehicleName = "";// Asterope
			break;
			case 1404: vehicleUint = 3609690755, vehicleName = "";// Emperor
			break;
			case 1405: vehicleUint = 2411965148, vehicleName = "";// Emperor (Rusty)
			break;
			case 1406: vehicleUint = 3053254478, vehicleName = "";// Emperor (Snowy)
			break;
			case 1407: vehicleUint = 1909141499, vehicleName = "";// Fugitive
			break;
			case 1408: vehicleUint = 75131841, vehicleName = "";// Glendale (DLC)
			break;
			case 1409: vehicleUint = 3005245074, vehicleName = "";// Ingot
			break;
			case 1410: vehicleUint = 886934177, vehicleName = "";// Intruder
			break;
			case 1411: vehicleUint = 2411098011, vehicleName = "";// Premier
			break;
			case 1412: vehicleUint = 3144368207, vehicleName = "";// Primo
			break;
			case 1413: vehicleUint = 4280472072, vehicleName = "";// Regina
			break;
			case 1414: vehicleUint = 627094268, vehicleName = "";// Romero Hearse
			break;
			case 1415: vehicleUint = 3039514899, vehicleName = "";// Schafter
			break;
			case 1416: vehicleUint = 2817386317, vehicleName = "";// Stanier
			break;
			case 1417: vehicleUint = 1723137093, vehicleName = "";// Stratum
			break;
			case 1418: vehicleUint = 2333339779, vehicleName = "";// Stretch
			break;
			case 1419: vehicleUint = 1123216662, vehicleName = "";// Super Diamond
			break;
			case 1420: vehicleUint = 2400073108, vehicleName = "";// Surge
			break;
			case 1421: vehicleUint = 3286105550, vehicleName = "";// Tailgater
			break;
			case 1422: vehicleUint = 1373123368, vehicleName = "";// Warrener (DLC)
			break;
			case 1423: vehicleUint = 1777363799, vehicleName = "";// Washington
			break;

			// Service (15xx)
			case 1501: vehicleUint = 1283517198, vehicleName = "";// Airport Bus
			break;
			case 1502: vehicleUint = 3581397346, vehicleName = "";// City Bus
			break;
			case 1503: vehicleUint = 2222034228, vehicleName = "";// Dashound
			break;
			case 1504: vehicleUint = 1917016601, vehicleName = "";// Garbage Truck
			break;
			case 1505: vehicleUint = 3039269212, vehicleName = "";// Garbage Truck (Rusty)
			break;
			case 1506: vehicleUint = 3196165219, vehicleName = "";// Rental Shuttle Bus
			break;
			case 1507: vehicleUint = 3338918751, vehicleName = "";// Taxi
			break;
			case 1508: vehicleUint = 1941029835, vehicleName = "";// Tour Bus
			break;

			// Sports (16xx)
			case 1601: vehicleUint = 1032823388, vehicleName = "";// 9F
			break;
			case 1602: vehicleUint = 2833484545, vehicleName = "";// 9F2
			break;
			case 1603: vehicleUint = 767087018, vehicleName = "";// Alpha (DLC)
			break;
			case 1604: vehicleUint = 3253274834, vehicleName = "";// Banshee
			break;
			case 1605: vehicleUint = 1039032026, vehicleName = "";// Blista Compact
			break;
			case 1606: vehicleUint = 3990165190, vehicleName = "";// Buffalo
			break;
			case 1607: vehicleUint = 736902334, vehicleName = "";// Buffalo S (Franklin)
			break;
			case 1608: vehicleUint = 2072687711, vehicleName = "";// Carbonizzare
			break;
			case 1609: vehicleUint = 3249425686, vehicleName = "";// Comet
			break;
			case 1610: vehicleUint = 108773431, vehicleName = "";// Coquette
			break;
			case 1611: vehicleUint = 3728579874, vehicleName = "";// Elegy RH8
			break;
			case 1612: vehicleUint = 2299640309, vehicleName = "";// Feltzer
			break;
			case 1613: vehicleUint = 3205927392, vehicleName = "";// Furore GT (DLC)
			break;
			case 1614: vehicleUint = 499169875, vehicleName = "";// Fusilade
			break;
			case 1615: vehicleUint = 2016857647, vehicleName = "";// Futo
			break;
			case 1616: vehicleUint = 3703315515, vehicleName = "";// Go Go Monkey Blista
			break;
			case 1617: vehicleUint = 2997294755, vehicleName = "";// Jester
			break;
			case 1618: vehicleUint = 3188613414, vehicleName = "";// Jester (Racecar)
			break;
			case 1619: vehicleUint = 544021352, vehicleName = "";// Khamelion
			break;
			case 1620: vehicleUint = 2922118804, vehicleName = "";// Kuruma (DLC)
			break;
			case 1621: vehicleUint = 410882957, vehicleName = "";// Kuruma Armored (DLC)
			break;
			case 1622: vehicleUint = 4152024626, vehicleName = "";// Massacro (DLC)
			break;
			case 1623: vehicleUint = 3663206819, vehicleName = "";// Massacro Race (DLC)
			break;
			case 1624: vehicleUint = 3917501776, vehicleName = "";// Penumbra
			break;
			case 1625: vehicleUint = 2360515092, vehicleName = "";// Rapid GT
			break;
			case 1626: vehicleUint = 1737773231, vehicleName = "";// Rapid GT (C)
			break;
			case 1627: vehicleUint = 3548084598, vehicleName = "";// Schwartzer
			break;
			case 1628: vehicleUint = 237764926, vehicleName = "";// Sprunk Buffalo
			break;
			case 1629: vehicleUint = 970598228, vehicleName = "";// Sultan
			break;
			case 1630: vehicleUint = 384071873, vehicleName = "";// Surano
			break;

			// Sports Classics (17xx)
			case 1701: vehicleUint = 941800958, vehicleName = "";// Casco (DLC)
			break;
			case 1702: vehicleUint = 1011753235, vehicleName = "";// Coquette Classic (DLC)
			break;
			case 1703: vehicleUint = 1051415893, vehicleName = "";// JB 700
			break;
			case 1704: vehicleUint = 2170765704, vehicleName = "";// Manana
			break;
			case 1705: vehicleUint = 3861591579, vehicleName = "";// Monroe
			break;
			case 1706: vehicleUint = 1830407356, vehicleName = "";// Peyote
			break;
			case 1707: vehicleUint = 1078682497, vehicleName = "";// Pigalle (DLC)
			break;
			case 1708: vehicleUint = 117401876, vehicleName = "";// Roosevelt (DLC)
			break;
			case 1709: vehicleUint = 1545842587, vehicleName = "";// Stinger
			break;
			case 1710: vehicleUint = 2196019706, vehicleName = "";// Stinger GT
			break;
			case 1711: vehicleUint = 2728226064, vehicleName = "";// Stirling GT (DLC)
			break;
			case 1712: vehicleUint = 464687292, vehicleName = "";// Tornado
			break;
			case 1713: vehicleUint = 1531094468, vehicleName = "";// Tornado (C)
			break;
			case 1714: vehicleUint = 1762279763, vehicleName = "";// Tornado (Rusty)
			break;
			case 1715: vehicleUint = 2261744861, vehicleName = "";// Tornado (Guitarmariachi)
			break;
			case 1716: vehicleUint = 758895617, vehicleName = "";// Z-Type
			break;

			// Super (18xx)
			case 1801: vehicleUint = 3078201489, vehicleName = "Adder";// Adder
			break;
			case 1802: vehicleUint = 2598821281, vehicleName = "Bullet";// Bullet
			break;
			case 1803: vehicleUint = 2983812512, vehicleName = "Cheetah";// Cheetah
			break;
			case 1804: vehicleUint = 3003014393, vehicleName = "Entity XF";// Entity XF
			break;
			case 1805: vehicleUint = 418536135, vehicleName = "Infernus";// Infernus
			break;
			case 1806: vehicleUint = 1987142870, vehicleName = "Osiris";// Osiris
			break;
			case 1807: vehicleUint = 1663218586, vehicleName = "T-20";// T-20
			break;
			case 1808: vehicleUint = 408192225, vehicleName = "Turismo-R";// Turismo-R
			break;
			case 1809: vehicleUint = 338562499, vehicleName = "Vacca";// Vacca
			break;
			case 1810: vehicleUint = 2672523198, vehicleName = "Voltic";// Voltic
			break;
			case 1811: vehicleUint = 2891838741, vehicleName = "Zentorno";// Zentorno
			break;

			// SUVs (19xx)
			case 1901: vehicleUint = 3486135912, vehicleName = "";// Baller
			break;
			case 1902: vehicleUint = 142944341, vehicleName = "";// Baller (R-Evoque)
			break;
			case 1903: vehicleUint = 850565707, vehicleName = "";// BeeJay XL
			break;
			case 1904: vehicleUint = 2006918058, vehicleName = "";// Cavalcade 2005
			break;
			case 1905: vehicleUint = 3505073125, vehicleName = "";// Cavalcade 2013
			break;
			case 1906: vehicleUint = 1177543287, vehicleName = "";// Dubsta
			break;
			case 1907: vehicleUint = 3900892662, vehicleName = "";// Dubsta (Blacked Out)
			break;
			case 1908: vehicleUint = 3157435195, vehicleName = "";// FQ 2
			break;
			case 1909: vehicleUint = 2519238556, vehicleName = "";// Granger
			break;
			case 1910: vehicleUint = 2751205197, vehicleName = "";// Gresley
			break;
			case 1911: vehicleUint = 884422927, vehicleName = "";// Habanero
			break;
			case 1912: vehicleUint = 486987393, vehicleName = "";// Huntley S (DLC)
			break;
			case 1913: vehicleUint = 1269098716, vehicleName = "";// Landstalker
			break;
			case 1914: vehicleUint = 914654722, vehicleName = "";// Mesa
			break;
			case 1915: vehicleUint = 3546958660, vehicleName = "";// Mesa (Snowy)
			break;
			case 1916: vehicleUint = 2230595153, vehicleName = "";// Mesa (Merryweather)
			break;
			case 1917: vehicleUint = 3486509883, vehicleName = "";// Patriot
			break;
			case 1918: vehicleUint = 2643899483, vehicleName = "";// Radius
			break;
			case 1919: vehicleUint = 2136773105, vehicleName = "";// Rocoto
			break;
			case 1920: vehicleUint = 1221512915, vehicleName = "";// Seminole
			break;
			case 1921: vehicleUint = 1337041428, vehicleName = "";// Serrano
			break;

			// Utilities (20xx)
			case 2001: vehicleUint = 1560980623, vehicleName = "";// Airtug
			break;
			case 2002: vehicleUint = 3410276810, vehicleName = "";// Docktug
			break;
			case 2003: vehicleUint = 1147287684, vehicleName = "";// Golf Cart (ProLaps)
			break;
			case 2004: vehicleUint = 3757070668, vehicleName = "";// Golf Cart (Nagasaki)
			break;
			case 2005: vehicleUint = 1491375716, vehicleName = "";// Forklift
			break;
			case 2006: vehicleUint = 1783355638, vehicleName = "";// Lawn Mower
			break;
			case 2007: vehicleUint = 3448987385, vehicleName = "";// Ripley
			break;
			case 2008: vehicleUint = 3695398481, vehicleName = "";// Sadler
			break;
			case 2009: vehicleUint = 734217681, vehicleName = "";// Sadler (Snowy)
			break;
			case 2010: vehicleUint = 2594165727, vehicleName = "";// Scrap Truck
			break;
			case 2011: vehicleUint = 2218488798, vehicleName = "";// Tractor (Farm)
			break;
			case 2012: vehicleUint = 1641462412, vehicleName = "";// Tractor (Rusty)
			break;
			case 2013: vehicleUint = 1445631933, vehicleName = "";// Tractor (Snowy)
			break;
			case 2014: vehicleUint = 2971866336, vehicleName = "";// Tow Truck (Large)
			break;
			case 2015: vehicleUint = 3852654278, vehicleName = "";// Tow Truck (Small)
			break;
			case 2016: vehicleUint = 516990260, vehicleName = "";// Utility Basket Truck
			break;
			case 2017: vehicleUint = 887537515, vehicleName = "";// Utility Landscape Truck
			break;
			case 2018: vehicleUint = 2132890591, vehicleName = "";// Utility Pick-Up Truck
			break;

			// Vans (21xx)
			case 2101: vehicleUint = 4278019151, vehicleName = "";// Bison
			break;
			case 2102: vehicleUint = 2072156101, vehicleName = "";// Bison (Cowboy)
			break;
			case 2103: vehicleUint = 1739845664, vehicleName = "";// Bison (Landscaping)
			break;
			case 2104: vehicleUint = 1069929536, vehicleName = "";// Bobcat
			break;
			case 2105: vehicleUint = 2307837162, vehicleName = "";// Boxville (Utility)
			break;
			case 2106: vehicleUint = 4061868990, vehicleName = "";// Boxville (Postal)
			break;
			case 2107: vehicleUint = 121658888, vehicleName = "";// Boxville (Humane)
			break;
			case 2108: vehicleUint = 444171386, vehicleName = "";// Boxville (Post Op)
			break;
			case 2109: vehicleUint = 2948279460, vehicleName = "";// Burrito
			break;
			case 2110: vehicleUint = 3387490166, vehicleName = "";// Burrito (BugStars)
			break;
			case 2111: vehicleUint = 893081117, vehicleName = "";// Burrito (Cowboy)
			break;
			case 2112: vehicleUint = 2549763894, vehicleName = "";// Burrito (Gang)
			break;
			case 2113: vehicleUint = 296357396, vehicleName = "";// Burrito Gang NL (DLC)
			break;
			case 2114: vehicleUint = 2551651283, vehicleName = "";// Burrito (No Livery)
			break;
			case 2115: vehicleUint = 1132262048, vehicleName = "";// Burrito (Snowy)
			break;
			case 2116: vehicleUint = 1876516712, vehicleName = "";// Camper
			break;
			case 2117: vehicleUint = 4174679674, vehicleName = "";// Journey
			break;
			case 2118: vehicleUint = 3984502180, vehicleName = "";// Minivan
			break;
			case 2119: vehicleUint = 1488164764, vehicleName = "";// Paradise (DLC)
			break;
			case 2120: vehicleUint = 4175309224, vehicleName = "";// Pony
			break;
			case 2121: vehicleUint = 943752001, vehicleName = "";// Pony (Weed Van)
			break;
			case 2122: vehicleUint = 1162065741, vehicleName = "";// Rumpo (Weazel News)
			break;
			case 2123: vehicleUint = 2518351607, vehicleName = "";// Rumpo (Deludamol)
			break;
			case 2124: vehicleUint = 3484649228, vehicleName = "";// Speedo
			break;
			case 2125: vehicleUint = 728614474, vehicleName = "";// Speedo (Clown Van)
			break;
			case 2126: vehicleUint = 699456151, vehicleName = "";// Surfer
			break;
			case 2127: vehicleUint = 2983726598, vehicleName = "";// Surfer (Rusty)
			break;
			case 2128: vehicleUint = 1951180813, vehicleName = "";// Taco Van
			break;

			// *Special* (22xx)
			case 2201: vehicleUint = 3087536137, vehicleName = "";// Army Tanker
			break;
			case 2202: vehicleUint = 2818520053, vehicleName = "";// Army Trailer
			break;
			case 2203: vehicleUint = 2657817814, vehicleName = "";// Army Trailer 2
			break;
			case 2204: vehicleUint = 3895125590, vehicleName = "";// Bale Trailer
			break;
			case 2205: vehicleUint = 2236089197, vehicleName = "";// Big Goods Trailer
			break;
			case 2206: vehicleUint = 524108981, vehicleName = "";// Boat Trailer
			break;
			case 2207: vehicleUint = 3334677549, vehicleName = "";// Cable Car
			break;
			case 2208: vehicleUint = 2078290630, vehicleName = "";// Car Carrier Trailer
			break;
			case 2209: vehicleUint = 2715434129, vehicleName = "";// Cluckin/Other Trailer
			break;
			case 2210: vehicleUint = 712162987, vehicleName = "";// Construction Trailer
			break;
			case 2211: vehicleUint = 2154757102, vehicleName = "";// Dock Trailer
			break;
			case 2212: vehicleUint = 2524324030, vehicleName = "";// Fame or Shame Trailer
			break;
			case 2213: vehicleUint = 390902130, vehicleName = "";// Farm Cultivator
			break;
			case 2214: vehicleUint = 2942498482, vehicleName = "";// Flatbed Trailer
			break;
			case 2215: vehicleUint = 1019737494, vehicleName = "";// Grain Trailer
			break;
			case 2216: vehicleUint = 2016027501, vehicleName = "";// Log Trailer
			break;
			case 2217: vehicleUint = 1784254509, vehicleName = "";// Marquis Trailer
			break;
			case 2218: vehicleUint = 3417488910, vehicleName = "";// Metal Tarp Trailer
			break;
			case 2219: vehicleUint = 356391690, vehicleName = "";// Mobile Home Trailer
			break;
			case 2220: vehicleUint = 2242229361, vehicleName = "";// Mule (No Livery)
			break;
			case 2221: vehicleUint = 2091594960, vehicleName = "";// Super Car Carrier
			break;
			case 2222: vehicleUint = 3564062519, vehicleName = "";// Tanker
			break;
			case 2223: vehicleUint = 1956216962, vehicleName = "";// Tanker (No Livery)
			break;
			case 2224: vehicleUint = 1030400667, vehicleName = "";// Train (Freight)
			break;
			case 2225: vehicleUint = 3517691494, vehicleName = "";// Train (Flatbed)
			break;
			case 2226: vehicleUint = 868868440, vehicleName = "";// Train (Metro)
			break;
			case 2227: vehicleUint = 642617954, vehicleName = "";// Train Boxcar
			break;
			case 2228: vehicleUint = 920453016, vehicleName = "";// Train Container
			break;
			case 2229: vehicleUint = 240201337, vehicleName = "";// Train Container 2
			break;
			case 2230: vehicleUint = 586013744, vehicleName = "";// Train Fuel Tank Car
			break;
			case 2231: vehicleUint = 184361638, vehicleName = "";// Train Well Car
			break;
		

			// *Props* (23xx)
			//case 2301) { vehicleName = "", vehicleName = "";// Test Prop
			case 2301: 
				vehicleUint = 1783355638;
				vehicleName = "Exercise Bike";
				spawnPropHashName = "prop_exer_bike_01";
				doSpawnObjectAttach = true;
				spawnObjectType = 0;
				break;
			case 2302: 
				vehicleUint = 4244420235;
				vehicleName = "UFO";
				spawnPropHashName = "p_spinning_anus_s";
				doSpawnObjectAttach = true;
				spawnObjectType = 0;
				break;
			case 2303: 
				vehicleUint = 788747387;
				vehicleName = "UFO + Guns";
				spawnPropHashName = "p_spinning_anus_s";
				doSpawnObjectAttach = true;
				spawnObjectType = 0;
				break;
			case 2304: 
				vehicleUint = 788747387;
				vehicleName = "Windmill + Guns";
				spawnPropHashName = "prop_windmill_01";
				doSpawnObjectAttach = true;
				spawnObjectType = 0;
				break;
			case 2305: 
				vehicleUint = 534258863;
				vehicleName = "Wheelchair";
				spawnPropHashName = "prop_wheelchair_01_s";
				doSpawnObjectAttach = true;
				spawnObjectType = 0;
				break;
		}
		

		firstTimeVehicleSpawnHasHappened = true;

		isVehicleSpawnRequest = true;

		if (addVehicleToPhone)
		{
			STAT_SET_INT(GET_HASH_KEY("MPPLY_VEHICLE_ID_ADMIN_WEB"), vehicleUint, 1);
		}

	}


	// Delete Last Spawned Vehicle
	bool deleteLastSpawnedVehicleT = false;
	void DeleteLastSpawnedVehicle(int dummy)
	{
		int vehOnlineFollowInt = vehOnlineFollow;
		deleteLastSpawnedVehicleT = !deleteLastSpawnedVehicleT;
		deleteLastSpawnedVehicle = deleteLastSpawnedVehicleT;

		char buffer[64];
		sprintf(buffer, "~r~Deleted ~w~Vehicle ID: ~b~%i", vehOnlineFollowInt);
		PrintText(buffer, 3000);
	}

	// Spawned Money Vehicle Control
	void ControlMoneyVehicles()
	{
		//
	}


	// Money Vehicle Check
	bool isMoneyVehicleCheckT = false;
	void ToggleMoneyVehicle(int vehicle)
	{
		isMoneyVehicleCheckT = !isMoneyVehicleCheckT;
		isMoneyVehicleCheck = isMoneyVehicleCheckT;

		if (!isMoneyVehicleCheck)
		{
			isMoneyVehicle = false;
			isMoneyVehicleActive = false;

			// Turn off other money toggles
			isCustomMoneySpawn = false;
			isMoneySpawningOnLobby = false;
		}

		PrintText(isMoneyVehicleCheckT ? "~w~Money Vehicle: ~g~Enabled\n~b~Spawn Vehicle To Activate Money Drop" : "~w~Money Vehicle: ~r~Disabled", 3000);
	}

	
	// Add spawned vehicle to phone toggle
	bool addVehicleToPhoneT = false;
	void ToggleAddSpawnedVehicleToPhone(int dummy)
	{
		addVehicleToPhoneT = !addVehicleToPhoneT;
		addVehicleToPhone = addVehicleToPhoneT;
		MsgToggleDefault("Add Spawned Vehicle To Phone", addVehicleToPhoneT);
	}

	void FlipVehicleUpright(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		int vehicle = GetCurrentVehicle(player);
		if (IS_PED_IN_ANY_VEHICLE(player, true))
		{
			SET_VEHICLE_ON_GROUND_PROPERLY(vehicle);
		}
	}


	
	// Delete Vehicle
	bool deleteVehicleT = false;
	void DeletePlayersVehicle(int SelectedPlayer)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		char* pName = GET_PLAYER_NAME(player);
		if(IS_PED_IN_ANY_VEHICLE(player, false))
    	{
			deleteVehicleT = !deleteVehicleT;
			deleteVehicle = deleteVehicleT;

			char buffer[64];
			sprintf("~w~Deleting ~b~%s's ~w~Vehicle", pName);
			PrintText(buffer, 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	

	// Speedometer
	bool isSpeedometerActiveT = false;
	void Speedometer(int type)
	{
		//int player = GET_PLAYER_PED(PlayerSelected);
		int player = PlayerSelf();
		char* pName = GET_PLAYER_NAME(player);
		if(IS_PED_IN_ANY_VEHICLE(player, false))
    	{
			switch(type)
			{
				case 1:
					isSpeedometerActiveT = !isSpeedometerActiveT;
					isSpeedometerActive = isSpeedometerActiveT;
					isSpeedometerBTTF = false;
					MsgToggleDefault("Speedometer", isSpeedometerActiveT);
					break;
				case 2:
					isSpeedometerActiveT = !isSpeedometerActiveT;
					isSpeedometerActive = isSpeedometerActiveT;
					isSpeedometerBTTF = isSpeedometerActiveT;
					MsgToggleDefault("Back To The Future Speedometer", isSpeedometerActiveT);
					break;
			}
		}
		else
		{
			MsgPlayerNotInVehicle();
		}


	} 


	// Teleport To Vehicle In Vehicle Manager
	void TeleportToVehicleFromManager(int slot)
	{
		SET_ENTITY_COORDS(slot, coords, 1, 0, 0, 1);
	}

	// Delete Vehicle From Manager
	void DeleteVehicleFromManager(int slot)
	{
		Vehicle veh = spawnedVehicleList[slot];
		SET_ENTITY_AS_MISSION_ENTITY(veh, 1, 1);
		DELETE_VEHICLE(&veh);
		sleep(100);
	}
	

	// Hijack Vehicle
	void HijackVehicle(int slot)
	{
		int tick;
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(playerPed, false))
    	{
			Vehicle veh = GET_VEHICLE_PED_IS_IN(player, false);
			int netID = NETWORK_GET_NETWORK_ID_FROM_ENTITY(veh);
			NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netID);
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

			CLEAR_PED_TASKS_IMMEDIATELY(player);
			sleep(100);
			SET_INTO_VEHICLE(veh);

    	}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}

	/*
	// Delete Vehicle From Manager
	void DeleteVehicleFromManager(int slot)
	{
		if (slot != 0)
		{
			SET_ENTITY_AS_MISSION_ENTITY(slot, false, true);
			DELETE_VEHICLE_UINT(slot);
		}
	}
	*/

		
	/*
	// Toggle Vehicle Burnout
	bool isVehicleInBurnout = false;
	void ToggleVehicleBurnout(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			isVehicleInBurnout = !isVehicleInBurnout;
			SET_VEHICLE_BURNOUT(GetCurrentVehicle(PlayerSelf()), isVehicleInBurnout);
			MsgToggleDefault("Burnout", isVehicleInBurnout);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/

	/*
	// Toggle Vehicle Wanted
	bool isVehicleWanted = false;
	void ToggleVehicleWanted(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			isVehicleWanted = !isVehicleWanted;
			SET_VEHICLE_IS_WANTED(GetCurrentVehicle(PlayerSelf()), isVehicleWanted);
			MsgToggleDefault("Vehicle Wanted", isVehicleWanted);
			//PrintText(isVehicleWanted ? "~g~Vehicle Is Wanted" : "~r~Vehicle Is Not Wanted", 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/
	
	/*
	// Toggle Vehicle Out of Control
	bool isVehicleOutOfControl = false;
	void ToggleVehicleOutOfControl(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			isVehicleOutOfControl = !isVehicleOutOfControl;
			SET_VEHICLE_OUT_OF_CONTROL(GetCurrentVehicle(PlayerSelf()), false, false);
			PrintText(isVehicleOutOfControl ? "~g~Vehicle Is Out Of Control" : "~r~Vehicle Is Not Out Of Control", 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/
	
	/*
	// Toggle Vehicle Stolen
	bool isVehicleStolen = false;
	void ToggleVehicleStolen(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			isVehicleStolen = !isVehicleStolen;
			SET_VEHICLE_IS_WANTED(GetCurrentVehicle(PlayerSelf()), isVehicleStolen);
			PrintText(isVehicleStolen ? "~g~Vehicle Is Stolen" : "~r~Vehicle Is Not Stolen", 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/

	// Toggle Vehicle Lights
	//bool areVehicleLightsOn = true;
	void ToggleVehicleLights(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			areVehicleLightsOn = !areVehicleLightsOn;
			switch (areVehicleLightsOn)
			{
				//SET_ENTITY_LIGHTS(GetCurrentVehicle(PlayerSelf()), areVehicleLightsOn);
				case false: SET_VEHICLE_LIGHT_MULTIPLIER(GetCurrentVehicle(player), 0.0);
							areVehicleBrightsOn = false;
				break;
				case true: if (areVehicleBrightsOn){SET_VEHICLE_LIGHT_MULTIPLIER(GetCurrentVehicle(player), 250.0);}
							else {SET_VEHICLE_LIGHT_MULTIPLIER(GetCurrentVehicle(player), 1.0);}
							areVehicleBrightsOn = true;
				break;
			}

				MsgToggleDefault("Lights", areVehicleLightsOn);
				//PrintText(areVehicleLightsOn ? "~r~Lights Are Off" : "~g~Lights Are On", 3000);
			}
			else
			{
				MsgPlayerNotInVehicle();
			}
			
	}

	// Toggle Vehicle Brights
	//bool areVehicleBrightsOn = false;
	void ToggleVehicleBrights(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			areVehicleBrightsOn = !areVehicleBrightsOn;
			switch (areVehicleBrightsOn)
			{
				//SET_ENTITY_LIGHTS(GetCurrentVehicle(PlayerSelf()), areVehicleLightsOn);
				case true:	if (areVehicleLightsOn){SET_VEHICLE_LIGHT_MULTIPLIER(GetCurrentVehicle(player), 250.0);}
							areVehicleBrightsOn = true;
				break;
				case false: if (areVehicleLightsOn){SET_VEHICLE_LIGHT_MULTIPLIER(GetCurrentVehicle(player), 1.0);}
							areVehicleBrightsOn = false;
				break;
			}

			MsgToggleDefault("Brights", areVehicleBrightsOn);
			//PrintText(areVehicleBrightsOn ? "~g~Brights Are On" : "~r~Brights Are Off", 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}


	// Explode Vehicle
	void ExplodeVehicle(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			EXPLODE_VEHICLE(GetCurrentVehicle(player), true, false);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}

	/*
	void GetVehicleMaxSpeed(int dummy)
	{
		GET_VEHICLE_MAX_SPEED(GetCurrentVehicle(PlayerSelf()));
	}
	*/

	
	// Set Car on Fire
	bool isVehicleOnFire = false;
	void ToggleVehicleOnFire(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		int vehicle = GetCurrentVehicle(player);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			START_ENTITY_FIRE(vehicle);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	

	// Explode All Tires
	void ExplodeAllTires(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			for (int tire = 0; tire <= 7; tire++)
			SET_VEHICLE_TYRE_BURST(GetCurrentVehicle(player), tire, true, 1000.0);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}

	/*
	// Toggle Can Respray Vehicle
	bool canResprayVehicle = false;
	void ToggleCanResprayVehicle(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			canResprayVehicle = !canResprayVehicle;
			SET_CAN_RESPRAY_VEHICLE(GetCurrentVehicle(PlayerSelf()), canResprayVehicle);
			MsgToggleDefault("Can Respray Vehicle", canResprayVehicle);
			//PrintText(canResprayVehicle ? "~g~Can Respray Vehicle Enabled" : "~r~Can Respray Vehicle Disabled" , 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/

	
	/*
	// Toggle Vehicle Density Random
	void SetVehicleDensityModRandom(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			SET_RANDOM_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME();
			PrintText("~g~Random Density Set", 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/
		
	/*
	// Toggle Vehicle Density
	bool isVehicleDensityModT = false;
	void ToggleVehicleDensityMod(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			isVehicleDensityModT = !isVehicleDensityModT;
			isVehicleDensityMod = isVehicleDensityModT;
			
			//char bbEnabled[64];
			//sprintf(bbEnabled, "~g~Density Modifier Enabled");
			//char bbDisabled[32];
			//sprintf(bbDisabled, "~r~Density Modifier Disabled");
			//PrintText(isVehicleDensityModT ? bbEnabled : bbDisabled , 5000);
			
			MsgToggleDefault("Density Modifier", isVehicleDensityModT);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/

	// Toggle Freeze Vehicle
	bool isVehicleFrozen = false;
	void ToggleFreezeVehiclePosition(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			isVehicleFrozen = !isVehicleFrozen;
			FREEZE_ENTITY_POSITION(GetCurrentVehicle(player), isVehicleFrozen);
			MsgToggleDefault("Vehicle Freeze", isVehicleFrozen);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
		
	/*
	// Toggle Door Locks
	bool isDoorLocked = true;
	void ToggleVehicleDoorLocks(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			//isDoorLocked = !isDoorLocked;
			//SET_VEHICLE_DOORS_LOCKED(GetCurrentVehicle(PlayerSelf()), isDoorLocked);
			//PrintText(isDoorLocked ? "~r~Doors Locked" : "~g~Doors Unlocked" , 3000);

			
			if (!isDoorLocked)
			{
				SET_VEHICLE_DOORS_LOCKED(GetCurrentVehicle(PlayerSelf()), 1);
				//SET_VEHICLE_DOORS_LOCKED_FOR_PLAYER(GetCurrentVehicle(PlayerSelf()), PlayerSelf());
				//SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS(GetCurrentVehicle(PlayerSelf()), true);
				isDoorLocked == true;
				PrintText("~r~Doors Locked", 3000);
			}

			if (isDoorLocked)
			{
				SET_VEHICLE_DOORS_LOCKED(GetCurrentVehicle(PlayerSelf()), 0);
				//SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS(GetCurrentVehicle(PlayerSelf()), false);
				isDoorLocked == false;
				PrintText("~g~Doors Unlocked" , 3000);
			}
			
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/

	// Toggle Vehicle Undriveable
	bool isVehicleDriveable = false;
	void ToggleVehicleDriveable(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			isVehicleDriveable = !isVehicleDriveable;
			SET_VEHICLE_UNDRIVEABLE(GetCurrentVehicle(player), isVehicleDriveable);
			PrintText(isVehicleDriveable ? "~r~Vehicle Not Driveable" : "~g~Vehicle Driveable" , 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}

	/*
	// Toggle Vehicle Doors Open/Closed
	bool areDoorsOpen = false;
	void ToggleVehicleDoorsOpen(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
				
			if (areDoorsOpen == false)
			{
				for (int i=0; i<=5; i++)
				{
					SET_VEHICLE_DOOR_OPEN(GetCurrentVehicle(player), i, true, true);
				}

				areDoorsOpen == true;
				PrintText("~b~Vehicle Doors Opened", 3000);
			}

			if (areDoorsOpen == true)
			{
				SET_VEHICLE_DOORS_SHUT(GetCurrentVehicle(PlayerSelf()), true);
				areDoorsOpen == false;
				PrintText("~b~Vehicle Doors Closed", 3000);
			}
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/

	// Toggle Remove Vehicle Windows
	void ToggleRemoveVehicleWindows(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			for (int i = 0; i <= 7; i++)
			{
				REMOVE_VEHICLE_WINDOW(GetCurrentVehicle(player), i);
			}
			
			PrintText("~g~Vehicle Windows Removed", 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}


	// Toggle Smashed Vehicle Windows
	bool isWindowSmashed = false;
	void ToggleVehicleWindowsBroken(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			if (isWindowSmashed == false)
			{
				for (int i=0; i<=7; i++)
				{
					SMASH_VEHICLE_WINDOW(GetCurrentVehicle(player), i);
				}
				
				isWindowSmashed == true;
				PrintText("~r~Vehicle Windows Broken", 3000);
			}

			/*
			if (isWindowSmashed == true)
			{
				for (int i=0; i<=7; i++)
				{
					FIX_VEHICLE_WINDOW(GetCurrentVehicle(player), i);
				}
				
				isWindowSmashed == false;
				PrintText("~g~Vehicle Windows Fixed", 3000);
			}
			*/
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}

	/*
	// Toggle Vehicle Windows
	bool isWindowDown = false;
	void ToggleVehicleWindowsUpDown(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			if (isWindowDown == false)
			{
				for (int i=0; i<=3; i++)
				{
					ROLL_DOWN_WINDOW(GetCurrentVehicle(PlayerSelf()), i);
					isWindowDown == true;
				}

				PrintText("~r~Vehicle Windows Rolled Down", 3000);
			}

			if (isWindowDown == true)
			{
				for (int i=0; i<=4; i++)
				{
					ROLL_UP_WINDOW(GetCurrentVehicle(PlayerSelf()), i);
					isWindowDown == false;
				}

				PrintText("~g~Vehicle Windows Rolled Up", 3000);
			}
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/

	/*
	// Break Doors Off
	void BreakOffVehicleDoors(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			for (int i=0; i<=7; i++)
			{
				SET_VEHICLE_DOOR_BROKEN(GetCurrentVehicle(player), i, true);
			}
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/

	
	//---------------------------------------------------------------------------------------
		

	// Fix and Wash Vehicle
	void FixAndWash(int SelectedPlayer)
	{
		//int tick;
		//int player = PlayerSelf();
		int player = GET_PLAYER_PED(PlayerSelected);
		int vehicle = GetCurrentVehicle(player);

		/*
		//Vehicle veh = GET_VEHICLE_PED_IS_IN(player, false);
		int netID = NETWORK_GET_NETWORK_ID_FROM_ENTITY(vehicle);
		NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netID);
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
		*/

		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			SET_VEHICLE_FIXED(vehicle);
			SET_VEHICLE_DEFORMATION_FIXED(vehicle);
			SET_VEHICLE_DIRT_LEVEL(vehicle, 0);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}

		
	// Make Vehicle Invisible
	bool vehicleVisible = true;
	void ToggleInvisibilityVehicle(int SelectedPlayer)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		int vehicle = GetCurrentVehicle(player);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			vehicleVisible = !vehicleVisible;
			SET_ENTITY_VISIBLE(vehicle, vehicleVisible);
			MsgToggleReverse("Vehicle Invisibility", vehicleVisible);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	
	/*
	// Toggle Vehicle Needs Hotwired Mode
	bool vehicleHotwire = false;
	void ToggleVehicleNeedsHotwired(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			vehicleHotwire = !vehicleHotwire;
			SET_VEHICLE_NEEDS_TO_BE_HOTWIRED(GetCurrentVehicle(player), vehicleHotwire);
			MsgToggleDefault("Needs Hotwired", vehicleHotwire);
			//PrintText(vehicleHotwire ? "~g~Needs Hotwired Enabled" : "~r~Needs Hotwired Disabled" , 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/
		
	/*
	// Toggle Vehicle Drift Mode
	bool vehicleDrift = false;
	void ToggleVehicleDriftMode(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			vehicleDrift = !vehicleDrift;
			SET_VEHICLE_REDUCE_GRIP(GetCurrentVehicle(player), vehicleDrift);
			MsgToggleDefault("Drifting", vehicleDrift);
			//PrintText(vehicleDrift ? "~g~Drifting Enabled" : "~r~Drifting Disabled", 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/


	void ChangeDirtLevel(int SelectedPlayer)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		int vehicle = GetCurrentVehicle(player);
		//float amount = GET_VEHICLE_DIRT_LEVEL(vehicle);
		
		SET_VEHICLE_DIRT_LEVEL(vehicle, dirtLevel);
	}

	/*
	bool wheelTypeActiveT = false;
	void SetWheelType(int SelectedPlayer)
	{
		wheelTypeActiveT = !wheelTypeActiveT;
		wheelTypeActive = wheelTypeActiveT;
		//MsgToggleDefault("Wheel Type Select", wheelTypeActiveT);
		if (wheelTypeActiveT)
		{
			dpadAdjustType = "Wheel Type";
			char buffer[100];
			sprintf(buffer, "~w~Wheel Type Select ~g~Enabled\n~w~Adjust With ~y~DPAD L+R\n~w~Select With ~b~X ~w~Button");
			PrintText(buffer, 5000);
		}
		else
		{
			PrintText("~w~Wheel Type Select ~r~Enabled", 5000);
		}
	}


	void WheelTypeChange()
	{
		switch(wheelType)
		{
			case 0: wheelType = 1;
				break;
			case 1: wheelType = 2;
				break;
			case 2: wheelType = 3;
				break;
			case 3: wheelType = 4;
				break;
			case 4: wheelType = 5;
				break;
			case 5: wheelType = 6;
				break;
			case 6: wheelType = 7;
				break;
			case 7: wheelType = 8;
				break;
			case 8: wheelType = 9;
				break;
			case 9: wheelType = 10;
				break;
			case 10: wheelType = 11;
				break;
			case 11: wheelType = 12;
				break;
			case 12: wheelType = 13;
				break;
			case 13: wheelType = 14;
				break;
			case 14: wheelType = 15;
				break;
			case 15: wheelType = 0;
				break;
		}
	}
	*/

	/*
	// Toggle Vehicle Searchlight
	bool vehicleSearchLight = true;
	void ToggleVehicleSearchLight(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			vehicleSearchLight = !vehicleSearchLight;
			SET_VEHICLE_SEARCHLIGHT(GetCurrentVehicle(PlayerSelf()), vehicleSearchLight, vehicleSearchLight);
			PrintText(vehicleSearchLight ? "~g~Searchlight Enabled" : "~r~Searchlight Disabled" , 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/

	/*
	// Toggle Vehicle Gravity
	bool vehicleGravity = true;
	void ToggleVehicleGravity(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			vehicleGravity = !vehicleGravity;
			SET_VEHICLE_GRAVITY(GetCurrentVehicle(PlayerSelf()), vehicleGravity);
			MsgToggleDefault("Gravity", vehicleGravity);
			//PrintText(vehicleGravity ? "~g~Gravity Enabled" : "~r~Gravity Disabled" , 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/
	
	/*
	void DirtLevelMore()
	{
		switch(dirtLevel)
		{
			case 0: dirtLevel = 1;
				break;
			case 1: dirtLevel = 2;
				break;
			case 2: dirtLevel = 3;
				break;
			case 3: dirtLevel = 4;
				break;
			case 4: dirtLevel = 5;
				break;
			case 5: dirtLevel = 6;
				break;
			case 6: dirtLevel = 7;
				break;
			case 7: dirtLevel = 8;
				break;
			case 8: dirtLevel = 9;
				break;
			case 9: dirtLevel = 10;
				break;
			case 10: dirtLevel = 11;
				break;
			case 11: dirtLevel = 12;
				break;
			case 12: dirtLevel = 13;
				break;
			case 13: dirtLevel = 14;
				break;
			case 14: dirtLevel = 15;
				break;
			case 15: dirtLevel = 0;
				break;
		}
	}

	void DirtLevelLess()
	{
		switch(dirtLevel)
		{
			case 0: dirtLevel = 15;
				break;
			case 1: dirtLevel = 0;
				break;
			case 2: dirtLevel = 1;
				break;
			case 3: dirtLevel = 2;
				break;
			case 4: dirtLevel = 3;
				break;
			case 5: dirtLevel = 4;
				break;
			case 6: dirtLevel = 5;
				break;
			case 7: dirtLevel = 6;
				break;
			case 8: dirtLevel = 7;
				break;
			case 9: dirtLevel = 8;
				break;
			case 10: dirtLevel = 9;
				break;
			case 11: dirtLevel = 10;
				break;
			case 12: dirtLevel = 11;
				break;
			case 13: dirtLevel = 12;
				break;
			case 14: dirtLevel = 13;
				break;
			case 15: dirtLevel = 14;
				break;
		}
	}
	*/
		
	
	void SlingshotVehicle(int SelectedPlayer)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		Ped currentVehicle = GetCurrentVehicle(player);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			APPLY_FORCE(currentVehicle, 80, 60, 100, 0, 0, 0);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	
	
	/*
	bool isTorqueModifierActiveT = false;
	void ToggleVehicleTorqueModifier(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			// Reset Torque To Default
			torqueValue = 20;

			isTorqueModifierActiveT = !isTorqueModifierActiveT;
			isTorqueModifierActive = isTorqueModifierActiveT;
			char torqueEnabled[82];
			sprintf(torqueEnabled, "~g~Torque Modified");
			char torqueDisabled[32];
			sprintf(torqueDisabled, "~r~Torque Restored");
			PrintText(isTorqueModifierActiveT ? torqueEnabled : torqueDisabled , 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/
	
	/*
	void ToggleVehicleTorqueBackward(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			torqueValue = -400;
			
			isTorqueModifierActiveT = !isTorqueModifierActiveT;
			isTorqueModifierActive = isTorqueModifierActiveT;
			
			MsgToggleDefault("Torque Backwards", isTorqueModifierActiveT);
			//PrintText(isTorqueModifierActiveT ? "~g~Torque Backwards Enabled" : "~r~Torque Backwards Disabled" , 3000);

			//SET_VEHICLE_FORWARD_SPEED(GetCurrentVehicle(PlayerSelf()), speedBoostValue);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/

	bool isStopVehicleNowT = false;
	void StopVehicleNow(int SelectedPlayer)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			isStopVehicleNowT = !isStopVehicleNowT;
			isStopVehicleNow = isStopVehicleNowT;
			MsgToggleDefault("Vehicle Force Stop", isStopVehicleNowT);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}

	bool isNeedForSpeedT = false;
	void NeedForSpeed(int speed)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			isNeedForSpeedT = !isNeedForSpeedT;
			isNeedForSpeed = isNeedForSpeedT;
			MsgToggleDefault("Need For Speed", isNeedForSpeedT);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}

	bool isFlyingCarT = false;
	void FlyingCar(int speed)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			isFlyingCarT = !isFlyingCarT;
			isFlyingCar = isFlyingCarT;

			if (isFlyingCar)
			{
				char buffer[128];
				sprintf(buffer, "~w~Flying Car ~g~Enabled\n~w~Fly Up: ~y~L2 ~w~+ ~y~R2");
				PrintText(buffer, 6000);
			}
			else
			{
				char buffer[48];
				sprintf(buffer, "Flying Car ~r~Disabled");
				PrintText(buffer, 3000);
			}
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}

	bool isHydroJumpT = false;
	void HydroJump(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			isHydroJumpT = !isHydroJumpT;
			isHydroJump = isHydroJumpT;
			
			if (isHydroJump)
			{
				isAirJump = false;

				char buffer[128];
				sprintf(buffer, "~w~Hydro Jump ~g~Enabled\n~w~Use: ~y~R1 ~w~To Activate");
				PrintText(buffer, 6000);
			}
			else
			{
				char buffer[48];
				sprintf(buffer, "Hydro Jump ~r~Disabled");
				PrintText(buffer, 3000);
			}
			
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}

	bool isAirJumpT = false;
	void AirJump(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			isAirJumpT = !isAirJumpT;
			isAirJump = isAirJumpT;
			
			if (isAirJump)
			{
				isHydroJump = false;

				char buffer[128];
				sprintf(buffer, "~w~Air Jump ~g~Enabled\n~w~Use: ~y~R1 ~w~To Activate");
				PrintText(buffer, 6000);
			}
			else
			{
				char buffer[48];
				sprintf(buffer, "Air Jump ~r~Disabled");
				PrintText(buffer, 3000);
			}
			
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	
	void BoostVehicle(int direction)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		Vehicle vehicle = GET_VEHICLE_PED_IS_USING(player);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			switch(direction)
			{
				case 1: APPLY_FORCE(vehicle, 0, 80, 0, 0, 0, 0);
					break;
				case 2: APPLY_FORCE(vehicle, 0, -80, 0, 0, 0, 0);
					break;
			}

			//SET_VEHICLE_FORWARD_SPEED(GetCurrentVehicle(player), speedBoostValue);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}

	bool isSpeedBoostBindedT = false;
	void BoostVehicleButtonBind(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			// Reset Boost Speed To Default
			speedBoostValue = 20;

			// Reset Boost Direction To UP
			speedBoostDirection = 0;

			isSpeedBoostBindedT = !isSpeedBoostBindedT;
			isSpeedBoostBinded = isSpeedBoostBindedT;
			char boostHelpEnabled[82];
			sprintf(boostHelpEnabled, "~g~Boost Button Bind Enabled\n~b~R3 Boost\nR3 Down Adjust\nL3 Reset");
			char boostHelpDisabled[32];
			sprintf(boostHelpDisabled, "~r~Boost Button Bind Disabled");
			PrintText(isSpeedBoostBindedT ? boostHelpEnabled : boostHelpDisabled , 3000);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}


	/*
	bool isVehicleJitterActiveT = false;
	void ToggleVehicleJitter(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			isVehicleJitterActiveT = !isVehicleJitterActiveT;
			isVehicleJitterActive = isVehicleJitterActiveT;
			char jitterHelpEnabled[32];
			sprintf(jitterHelpEnabled, "~g~Vehicle Jitter Enabled");
			char jitterHelpDisabled[32];
			sprintf(jitterHelpDisabled, "~r~Vehicle Jitter Disabled");
			PrintText(isVehicleJitterActiveT ? jitterHelpEnabled : jitterHelpDisabled , 3000);

		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/

		
	int getFreeSeat(int vehicle)
	{
		int seatMax = GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(vehicle);
		int seat = -1;
		while (seat < seatMax)
		{
			if (IS_VEHICLE_SEAT_FREE(vehicle, seat))
			{
				return seat;
			}

			seat++;
		}
		return -2;
	}

	/*
	// Convertible Roof
	void ToggleConvertibleRoof(int dummy)
	{
		if(IS_PED_IN_ANY_VEHICLE(PlayerSelf(), true))
		{
			BOOL isConv = IS_VEHICLE_A_CONVERTIBLE(GetCurrentVehicle(PlayerSelf()), true);
			int roofState = GET_CONVERTIBLE_ROOF_STATE(GetCurrentVehicle(PlayerSelf()));

			if (isConv)
			{
				switch (roofState)
				{
					case 0: LOWER_CONVERTIBLE_ROOF(GetCurrentVehicle(PlayerSelf()), true);// Closed
					break;
					case 1: LOWER_CONVERTIBLE_ROOF(GetCurrentVehicle(PlayerSelf()), true);// Opening
					break;
					case 2: RAISE_CONVERTIBLE_ROOF(GetCurrentVehicle(PlayerSelf()), true);// Closing
					break;
					case 3: RAISE_CONVERTIBLE_ROOF(GetCurrentVehicle(PlayerSelf()), true);// Open
					break;
				}
			}
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	*/

	// Turn Signal Control
	void VehicleBlinkerControl(int turnSignal)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			/*
			// If Bind Is Requested
			if (turnSignal == 0)
			{
				if (bindTurnSignals == true)
				{
					PrintText("~r~Turn Signal Bind Off", 3000);
					bindTurnSignals = false;
				}
				else
				{
					PrintText("~g~Turn Signal Bind On", 3000);
					bindTurnSignals = true;
				}
			}
			*/
			
			// Right Side = 0
			// Left Side = 1
			if (turnSignal == 1) { SET_VEHICLE_INDICATOR_LIGHTS(GetCurrentVehicle(player), 1, true); }
			if (turnSignal == 2) { SET_VEHICLE_INDICATOR_LIGHTS(GetCurrentVehicle(player), 1, false); }
			if (turnSignal == 3) { SET_VEHICLE_INDICATOR_LIGHTS(GetCurrentVehicle(player), 0, true); }
			if (turnSignal == 4) { SET_VEHICLE_INDICATOR_LIGHTS(GetCurrentVehicle(player), 0, false); }

			if (turnSignal == 5)
			{ 
				SET_VEHICLE_INDICATOR_LIGHTS(GetCurrentVehicle(player), 0, true); 
				SET_VEHICLE_INDICATOR_LIGHTS(GetCurrentVehicle(player), 1, true); 
			}

			if (turnSignal == 6)
			{ 
				SET_VEHICLE_INDICATOR_LIGHTS(GetCurrentVehicle(player), 0, false); 
				SET_VEHICLE_INDICATOR_LIGHTS(GetCurrentVehicle(player), 1, false); 
			}
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}


	void ChangeVehicleColor(int colorall)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			SET_VEHICLE_COLOURS(GetCurrentVehicle(player), colorall, colorall);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}


	void RandomVehicleColor(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			int random = irand(0, 159);
			SET_VEHICLE_COLOURS(GetCurrentVehicle(player), random, random);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}


	void ChangeTireSmokeColor(int tireSmokeColor)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			TOGGLE_VEHICLE_MOD(GetCurrentVehicle(player), 20, true);
			
			int randomR = irand(40, 240);
			int randomG = irand(40, 240);
			int randomB = irand(40, 240);

			Vehicle vehicle = GetCurrentVehicle(player);

			switch (tireSmokeColor)
			{
				case 0: SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, randomR, randomG, randomB);// Random
						break;
				case 1: SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, 0, 0, 0);// Patriot
						break;
				case 2: SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, 1, 1, 1);// Black
						break;
				case 3: SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, 254, 254, 254);// White
						break;
				case 4: SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, 255, 0, 0);// Red
						break;
				case 5: SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, 0, 255, 0);// Green
						break;
				case 6: SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, 0, 0, 255);// Blue
						break;
				case 7: SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, 232, 232, 23);// Yellow
						break;
				case 8: SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, 240, 168, 23);// Orange
						break;
				case 9: SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, 255, 0, 127);// Hot Pink
						break;
				case 10: SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, 153, 0, 153);// Purple
						break;
				case 11: SET_VEHICLE_TYRE_SMOKE_COLOR(vehicle, 23, 232, 232);// Teal
						break;
			}
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}


	void ChangeVehiclePrimaryColor(int colorpri)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			//if (colorpri == 1) { SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(GetCurrentVehicle(PlayerSelf()), 0, 0, 0); }// Black
			//if (colorpri == 1) { SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(GetCurrentVehicle(PlayerSelf()), 0, 0, 0); }// Black
			//if (colorpri == 1) { SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(GetCurrentVehicle(PlayerSelf()), 0, 0, 0); }// Black
			
			int randomR = irand(0, 159);
			int randomG = irand(0, 159);
			int randomB = irand(0, 159);

			SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(GetCurrentVehicle(player), randomR, randomG, randomB);

			//Preset Colors (Gold, Chrome, ...)
			//SET_VEHICLE_MOD_KIT(GetCurrentVehicle(PlayerSelf()), 0);
			//SET_VEHICLE_COLOURS(GetCurrentVehicle(PlayerSelf()), ColorIndex_1, ColorIndex_2);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}


	void ChangeVehicleSecondaryColor(int colorsec)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			//Secondary Color (Custom RGB)
			//if (colorsec == 1) { SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(GetCurrentVehicle(PlayerSelf()), 0, 0, 0); }// Black
			//if (colorsec == 2) { SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(GetCurrentVehicle(PlayerSelf()), 255, 255, 255); }// White
			//if (colorsec == 1) { SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(GetCurrentVehicle(PlayerSelf()), 0, 0, 0); }// Black
			//if (colorsec == 1) { SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(GetCurrentVehicle(PlayerSelf()), 0, 0, 0); }// Black
			//if (colorsec == 1) { SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(GetCurrentVehicle(PlayerSelf()), 0, 0, 0); }// Black
			
			int randomR = irand(0, 159);
			int randomG = irand(0, 159);
			int randomB = irand(0, 159);

			SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(GetCurrentVehicle(player), randomR, randomG, randomB);

			//Preset Colors (Gold, Chrome, ...)
			//SET_VEHICLE_MOD_KIT(GetCurrentVehicle(PlayerSelf()), 0);
			//SET_VEHICLE_COLOURS(GetCurrentVehicle(PlayerSelf()), ColorIndex_1, ColorIndex_2);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}


	void ChangeVehicleExtraColor(int colorExtra)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			//int pearl = irand(0, 159);
			//int wheel = irand(0, 159);
			int combo = irand(0, 159);

			SET_VEHICLE_EXTRA_COLOURS(GetCurrentVehicle(player), combo, combo);

			//Preset Colors (Gold, Chrome, ...)
			//SET_VEHICLE_MOD_KIT(GetCurrentVehicle(PlayerSelf()), 0);
			//SET_VEHICLE_COLOURS(GetCurrentVehicle(PlayerSelf()), ColorIndex_1, ColorIndex_2);
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}
	

	void SetVehicleOnGroundProperly(int dummy)
	{
		int player = GET_PLAYER_PED(PlayerSelected);
		if(IS_PED_IN_ANY_VEHICLE(player, true))
		{
			SET_VEHICLE_ON_GROUND_PROPERLY(GetCurrentVehicle(player));
		}
		else
		{
			MsgPlayerNotInVehicle();
		}
	}


};



#endif


