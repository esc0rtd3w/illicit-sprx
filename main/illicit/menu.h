#ifndef __MENU_H
#define __MENU_H


#include "animations.h"
#include "anti.h"
#include "buttons.h"
#include "hud.h"
#include "hud_game.h"
#include "functions.h"
#include "hashes.h"
#include "help.h"
#include "includes.h"
//#include "keyboard.h"
#include "licensing.h"
#include "lobby.h"
#include "messages.h"
#include "misc.h"
#include "misc_game.h"
#include "missions.h"
#include "natives.h"
#include "network.h"
#include "objects.h"
#include "peds.h"
#include "presets.h"
#include "printf.h"
#include "protection.h"
#include "system.h"
#include "types.h"
#include "vehicles.h"
#include "weapons.h"
#include "weather.h"
#include "web.h"
#include "world.h"


using namespace cellFSWriteInt_;
using namespace Animations_f;
using namespace Dialog;
using namespace Functions;
using namespace Hashes;
using namespace Help_f;
//using namespace Hud_f;
using namespace Keyboard;
//using namespace Keyboard_OSK;
using namespace Licensing;
using namespace Misc;
//using namespace Missions_f;
using namespace Natives;
using namespace Network_f;
using namespace Objects_f;
using namespace Peds_f;
using namespace Presets_f;
using namespace Protection;
using namespace Vehicles_f;
using namespace Weapons_f;
using namespace Weather_f;
using namespace Web_f;
using namespace World_f;


namespace Menu_f
{

	// Variable to check whether menu is open
	bool isOpen;

	/*
	void isClosed(int)
	{
		isOpen = false;
		sleep(100);
	};
	*/

	// Just a simple CLOSE MENU function
	void closeMenu()
	{
		isOpen = false;
		sleep(100);
	};

	// Just a simple OPEN MENU function
	void openMenu()
	{
		isOpen = true;
		sleep(100);
	};

	
	// Indices of the (sub)menus
	enum Menus
	{
		// Main Menu
		MenuMain,

		// Main Menu Items
		MenuPlayerSelf,
		MenuPlayersAll,
		MenuLobby,
		MenuWorld,
		MenuTeleport,
		MenuWeapons,
		MenuVehicles,
		MenuObjects,
		MenuPeds,
		MenuTime,
		MenuWeather,
		MenuRecovery,
		MenuProtection,
		MenuNetwork,
		MenuMisc,
		MenuHelp,

		// Menu -> Self
		MenuPlayerSelfChangeName,
		MenuPlayerSelfModel,
		MenuPlayerSelfModelAnimals,
		MenuPlayerSelfModelStoryMode,
		MenuPlayerSelfModelMalePeds,
		MenuPlayerSelfModelFemalePeds,
		MenuPlayerSelfModelPolice,
		MenuPlayerSelfModelStrippers,
		MenuPlayerSelfModelGlitch,
		//MenuPlayerSelfModelMP,
		MenuPlayerSelfOutfit,
		MenuPlayerSelfToggles,
		MenuPlayerSelfAnimations,
		MenuPlayerSelfPhone,
		MenuPlayerSelfCamera,
		MenuPlayerSelfTimeCycle,
		MenuPlayerSelfExplode,
		
		// Menu -> All Players
		MenuPlayersAllToggles,
		//MenuPlayersAllTogglesMoneyCustom,
		//MenuPlayersAllTogglesMoneyCustomNumbers,
		//MenuPlayersAllEditVehicleToggles,
		MenuPlayersAllAttachments,
		MenuPlayersAllAttachmentsManager,
		MenuPlayersAllPedActions,
		MenuPlayersAllPedsManager,
		MenuPlayersAllEditVehicle,
		//MenuPlayersAllEditVehicleModshop,
		
		// Menu -> Lobby
		MenuLobbyToggles,
		MenuLobbyTalking,
		MenuLobbyTalkingLoops,

		// Menu -> Money Drops
		MenuMoney,
		MenuMoneyCustom,
		MenuMoneyCustomNumbers,
		MenuMoneyCoords,
		MenuMoneyPlayers,
		
		// Menu -> Teleport
		MenuTeleportStoryMode,
		MenuTeleportInside,
		MenuTeleportOutside,
		MenuTeleportGarages,
		MenuTeleportHelipads,
		MenuTeleportHospitals,
		MenuTeleportWaterTowers,
		MenuTeleportSniper,
		MenuTeleportGlitch,
		MenuTeleportOther,
		MenuTeleportRobbery,
		
		// Menu -> Vehicles
		MenuVehiclesNearby,
		MenuVehiclesManager,
		MenuVehicleSpawn,
		//MenuVehiclesSpawnCar,
		MenuVehicleSpawnBikes,
		MenuVehicleSpawnBoats,
		MenuVehicleSpawnCommercial,
		MenuVehicleSpawnCompacts,
		MenuVehicleSpawnCoupes,
		MenuVehicleSpawnEmergency,
		MenuVehicleSpawnHelicopters,
		MenuVehicleSpawnIndustrial,
		MenuVehicleSpawnMilitary,
		MenuVehicleSpawnMotorcycles,
		MenuVehicleSpawnMuscle,
		MenuVehicleSpawnOffroad,
		MenuVehicleSpawnPlanes,
		MenuVehicleSpawnSedans,
		MenuVehicleSpawnService,
		MenuVehicleSpawnSports,
		MenuVehicleSpawnSportsClassics,
		MenuVehicleSpawnSuper,
		MenuVehicleSpawnSUVs,
		MenuVehicleSpawnUtilities,
		MenuVehicleSpawnVans,
		MenuVehicleSpawnSpecial,
		MenuVehicleSpawnProps,

		MenuVehiclesEditVehicleTurnSignals,
		MenuVehiclesEditVehicleToggles,
		MenuVehiclesEditVehicleAdjustMultipliers,
		MenuVehiclesEditVehicleModshop,
		MenuVehiclesEditVehicleModshopPlate,
		MenuVehiclesEditVehicleModshopPaint,
		MenuVehiclesEditVehicleModshopPaintMatte,
		MenuVehiclesEditVehicleModshopPaintMetallic,
		MenuVehiclesEditVehicleModshopPaintUtility,
		MenuVehiclesEditVehicleModshopPaintWorn,
		MenuVehiclesEditVehicleMultipliers,
		MenuVehiclesEditVehicleModshopTireSmoke,
		
		// Menu -> Weapons
		//MenuPlayersAllWeapons,
		//MenuWeaponsManager,
		//MenuWeaponsManagerNormal,
		//MenuWeaponsManagerDLC,
		//MenuWeaponsManagerDLCOther,
		//MenuWeaponsManagerGadgets,
		//MenuWeaponsManagerOther,
		
		// Menu -> Objects
		MenuObjectsManager,
		MenuObjectsAttachments,
		
		// Menu -> Peds
		MenuPedsManager,
		
		// Menu -> Time
		//

		// Menu -> Weather
		MenuWeatherWindEditor,

		MenuWorldIPL,
		
		// Menu -> Recovery
		MenuRecoveryRank,
		MenuRecoveryNetworkCash,
		MenuRecoveryUnlockables,
		MenuRecoveryGiveItems,
		
		// Menu -> Sounds
		//MenuSoundsMain,
		//MenuSoundsName,
		//MenuSoundsSoundsets,
		
		// Menu -> Network
		//
		
		// Menu -> Misc
		MenuMiscToggles,
		//MenuMiscTuneables,
		//MenuSettings,
		//MenuSettingsButtons,
		//MenuMiscPlugins,
		
		// Menu -> Settings
		//MenuSettingsUIColors,
		//MenuSettingsUISizes,
		//MenuSettingsUIText,
		//MenuSettingsUIBackground,
		
		// Menu -> System
		//MenuSystemToggles,
		
		// Menu -> Presets
		//MenuPresets,
		
		// Menu -> Help
		//
		
		// Menu -> Debug
		//
		
		Menus_Length
	};


	void updateVehicleManager();

	// All of these should be self explanitory
	int thisMenu;
	int currentOption;
	int currentMenu;

	// Allow an extra 16 slots over Max Menu Length for each Player
	// Array which stores count of options for each sub menu
	int subOptionCount[132];

	// Array which stores the index of the previous menu
	int previousSub[132];

	// Array which stores the index of the last selected option in a sub menu
	int previousOption[132];

	// Array - stores sub menu's titles
	const char* subMenuTitle[132];

	// 2d array, stores the text for each option. 1st dimension is sub menu index, 2nd is option index
	const char* subOptionText[132][132];

	// Stores pointer to the function for each option
	void(*optionFunction[132][132])(int);

	// Stores parameter for the function above
	int optionFunctionParam[132][132];

	// Variable that tells whether to call function in hook or thread
	bool optionFunctionHooked[132][132];
	

	//int optionType[138][138];

	//bool* optionToggle[138][138];

	
	//---------------------------------------------------------------------------
	// PRINT MESSAGE STUFF ------------------------------------------------------

	// Simple function that just prints out the text of the current option.
	void Message(int)
	{
		PrintText(subOptionText[currentMenu][currentOption]);
	}

	void MsgDisplay(int)
	{
		PrintText(subOptionText[currentMenu][currentOption]);
	}

	/*
	void SetParams(char*, bool)
	{
		PrintText(subOptionText[currentMenu][currentOption]);
	}
	*/
	//---------------------------------------------------------------------------


	//---------------------------------------------------------------------------
	// ADD MENU STUFF -----------------------------------------------------------

	// Add New Sub Menus
	// First parameter is a char* which is the name of the submenu
	// Next is the index of the menu
	// Last is the index of the previous menu it's coming from
	void addMenu(const char* Name, int Menu, int Previous = -1)
	{
		thisMenu = Menu;
		subMenuTitle[Menu] = Name;
		subOptionCount[Menu] = 0;
		previousSub[Menu] = Previous;
	}
	//---------------------------------------------------------------------------


	//---------------------------------------------------------------------------
	// ADD OPTIONS STUFF --------------------------------------------------------

	// Add Sub Menu Options (Adds an option to the newest sub menu)
	// 1 param is a char* and this is the text that you'll see in the menu.
	// Next is a pointer to the function for this option, which takes an int
	// Last is the variable for that function
	void addOption(const char* Text = "", void(*Func)(int) = &Message, int Param1 = -1)
	{
		int Menu = thisMenu;
		int Num = subOptionCount[Menu];
		subOptionText[Menu][Num] = Text;
		optionFunction[Menu][Num] = Func;
		optionFunctionParam[Menu][Num] = Param1;
		optionFunctionHooked[Menu][Num] = false;
		subOptionCount[Menu]++;
	}


	// Add Sub Menu Options Alt
	// Same as addOption, but used for different cases
	void addOptionAlt(int Menu, int Option, bool Hooked, const char* Text, void(*Func)(int) = &Message, int Param1 = -1)
	{
		subOptionText[Menu][Option] = Text;
		optionFunction[Menu][Option] = Func;
		optionFunctionParam[Menu][Option] = Param1;
		optionFunctionHooked[Menu][Option] = Hooked;
	}


	// Add Sub Menu Options TEXT ONLY
	void addOptionAltNoExecute(int Menu, int Option, bool Hooked, const char* Text, int Param1 = -1)
	{
		subOptionText[Menu][Option] = Text;
		//optionFunction[Menu][Option] = Func;
		//optionFunctionParam[Menu][Option] = Param1;
		//optionFunctionHooked[Menu][Option] = Hooked;
	}


	// Add Sub Menu Options With Color
	/*
	void addOptionAltColorGreen(int Menu, int Option, bool Hooked, const char* Text, void(*Func)(int) = &Message, int Param1 = -1)
	{
		char buffer[32];
		sprintf(buffer, "~g~%s", Text);
		Text = buffer;
		subOptionText[Menu][Option] = Text;
		optionFunction[Menu][Option] = Func;
		optionFunctionParam[Menu][Option] = Param1;
		optionFunctionHooked[Menu][Option] = Hooked;
	}
	*/

	/*
	void addOptionAltColorRed(int Menu, int Option, bool Hooked, const char* Text, void(*Func)(int) = &Message, int Param1 = -1)
	{
		char buffer[32];
		sprintf(buffer, "~r~%s", Text);
		subOptionText[Menu][Option] = buffer;
		optionFunction[Menu][Option] = Func;
		optionFunctionParam[Menu][Option] = Param1;
		optionFunctionHooked[Menu][Option] = Hooked;
	}
	*/

	/*
	void addOptionAltColorBlue(int Menu, int Option, bool Hooked, const char* Text, void(*Func)(int) = &Message, int Param1 = -1)
	{
		char buffer[32];
		sprintf(buffer, "~b~%s", Text);
		Text = buffer;
		subOptionText[Menu][Option] = Text;
		optionFunction[Menu][Option] = Func;
		optionFunctionParam[Menu][Option] = Param1;
		optionFunctionHooked[Menu][Option] = Hooked;
	}
	*/

	/*
	void addOptionAltColorYellow(int Menu, int Option, bool Hooked, const char* Text, void(*Func)(int) = &Message, int Param1 = -1)
	{
		char buffer[32];
		sprintf(buffer, "~y~%s", Text);
		Text = buffer;
		subOptionText[Menu][Option] = Text;
		optionFunction[Menu][Option] = Func;
		optionFunctionParam[Menu][Option] = Param1;
		optionFunctionHooked[Menu][Option] = Hooked;
	}
	*/

	/*
	// Add Sub Menu with BOOL
	void addOptionBool(const char* Text, bool* Toggle, bool State)
	{
		int Menu = thisMenu;
		int Num = subOptionCount[Menu];
		subOptionText[Menu][Num] = Text;
		optionToggle[Menu][Num] = Toggle;
		optionFunctionParam[Menu][Num] = State;
		optionType[Menu][Num] = 1;
		subOptionCount[Menu]++;
	}
	*/
	//---------------------------------------------------------------------------

	
	
	//---------------------------------------------------------------------------
	// ADD HOOKED OPTION STUFF --------------------------------------------------

	// Add Sub Menu Options Hooked
	void addHookedOption(const char* Text = "", void(*Func)(int) = &Message, int Param1 = -1)
	{
		addOption(Text, Func, Param1);
		optionFunctionHooked[thisMenu][subOptionCount[thisMenu]-1] = true;
	}
	//---------------------------------------------------------------------------

	
	void openSub(int Menu);

	//void RefreshPlayerMenu();
	//void UpdatePlayersMenu();


	// Default Color Sets
	//ColorSet ColorText = Colors::Common::White;
	//ColorSet ColorTextSelected = Colors::Dark::DarkOrange;
	//ColorSet ColorHighlight = Colors::Common::Yellow;

	


	//---------------------------------------------------------------------------
	// Updates the players menu
	void UpdatePlayersMenu()
	{

		int Player = 0;
		//int PlayerMax = PlayerCount();
		//for (int i = 0; i <= PlayerMax; i++)
		int PlayerMax = 15;
		for (int i = 0; i <= PlayerMax; i++)
		{

			//char* Name = GET_PLAYER_NAME(i);
			//NameCurrent = Name;

			/*
			if (NETWORK_GET_NUM_CONNECTED_PLAYERS() == 0)
			{
				NameCurrent = GET_PLAYER_NAME(0);
			}
			
			if (NETWORK_GET_NUM_CONNECTED_PLAYERS() > 0)
			{
				NameCurrent = GetNetPlayerName(i);
			}
			*/
			
			//NameCurrent = GET_PLAYER_NAME(i);
			NameCurrent = GetNetPlayerName(i);
			NameCurrentFollow = NameCurrent;

			

			int Menu;
			bool canSelect;
			
			bool doesExist = DOES_ENTITY_EXIST(GET_PLAYER_PED(Player));

			if (Player < 16)
			{
				// If Invalid Name
				if (!strcmp(NameCurrent, "**Invalid**")) 
				{
					canSelect = false;
					
					if (!doesExist)
					{
						Menu = Menus_Length + Player;
						addOptionAltNoExecute(MenuPlayersAll, Player, false, "-", Menu);
					}
					/*
					else
					{
						Menu = Menus_Length + Player;
						addOptionAltNoExecute(MenuPlayersAll, Player, false, "~r~** CORRUPT SLOT **", Menu);
					}
					*/

					//isOnlyPlayerPlaying = true;
					//isPlayerPlayingOnline = false;

					// This will make menu not expand 
					// Only shows the same amount of active players
					//continue;

					//showPlayerIcon = false;
				}
				
				// If Valid Name
				if (strcmp(NameCurrent, "**Invalid**")) 
				{
					canSelect = true;
					
					if (doesExist)
					{
						Menu = Menus_Length + Player;
						addOptionAlt(MenuPlayersAll, Player, false, NameCurrent, &openSub, Menu);
					}

					//showPlayerIcon = true;
				}
			}
			
			/*
			// SCTV Slots
			if (Player == 16 || Player == 17)
			{
				//canSelect = false;

				if (strcmp(NameCurrent, "**Invalid**")) 
				{
					Menu = Menus_Length + Player;
					addOptionAltNoExecute(MenuPlayersAll, Player, false, "~r~*** ~y~SCTV Slot ~r~***", &openSub, Menu);
				}
			}
			*/


			// Original Add To Players Menu Code
			//int Menu = Menus_Length + Player;
			//addOptionAlt(MenuPlayersAll, Player, false, NameCurrent, &openSub, Menu);



			// Navigation item follow
			//iFollow = i;
			//currentMenuFollow = currentMenu;
			//PlayerFollow = Player;
			//NameCurrentFollow = NameCurrent;
			//MenuFollow = Menu;

			
			if (canSelect)
			{
				//-----------------------------------------------------------------------//
				// All Players Main
				addMenu(NameCurrent, Menu, MenuPlayersAll);
				addHookedOption("Get Player Info", &Peds_f::GetPlayerInfo, Player);
				addHookedOption("Check If Modder", &Protection::CheckForModder);
				addHookedOption("Teleport To Player", &Peds_f::TeleportToPlayer, Player);
				addHookedOption("Attach To Player", &Peds_f::AttachToPlayer, Player);
				addHookedOption("Detach From Player", &Peds_f::DetachFromPlayer, Player);
				//addHookedOption("Check If In Vehicle", &Peds_f::CheckIfIsPedInAnyVehicle, Player);
				//addOption("Toggles", &openSub, MenuPlayersAllToggles);
				addOption("Vehicle Options", &openSub, MenuPlayersAllEditVehicle);
				addOption("Objects & Props", &openSub, MenuPlayersAllAttachments);
				//addHookedOption("Attach To Player Head", &Peds_f::AttachToPlayerHead, Player);
				//addHookedOption("Attach To Player L Arm", &Peds_f::AttachToPlayerLeftArm, Player);
				//addHookedOption("Attach To Player R Arm", &Peds_f::AttachToPlayerRightArm, Player);
				//addHookedOption("Attach Rope", &Peds_f::TogglePedRopeAttach, Player);
				//addHookedOption("Give $10,000,000", &Stats_f::GiveNetworkCashToPlayer, Player);
				addHookedOption("Give All Weapons", &Weapons_f::WeaponsGiveAll, Player);
				addHookedOption("Take All Weapons", &Weapons_f::WeaponsTakeAll, Player);
				//addHookedOption("Max Armor", &Peds_f::GiveMaxArmor, Player);
				//addHookedOption("Max Health", &Peds_f::GiveMaxHealth, Player);
				//addHookedOption("Apply Damage", &Peds_f::ApplyDamageToPed, Player);
				addHookedOption("Clone Player", &Peds_f::ClonePed, Player);
				//addHookedOption("Punish The Guilty", &PlayerSelf_f::BossMode, Player);
				//addHookedOption("Slingshot Player", &Peds_f::SlingshotPed, Player);
				//addHookedOption("Light On Fire", &Peds_f::TogglePlayerOnFire, Player);
				addHookedOption("Clear Props", &Peds_f::ClearPedProps, Player);
				addHookedOption("Kick Player", &Network_f::NetworkKickPlayer, Player);
				addHookedOption("Freeze Player", &Peds_f::FreezePlayer, Player);
				addHookedOption("< Explode >", &Peds_f::ExplodePlayer, Player);
				addHookedOption("Silent Snipe", &Peds_f::SilentSnipe, Player);
				//addHookedOption("Explode Custom", &openSub, MenuPlayerSelfExplode);
			
				// All Players -> Toggles
				//addMenu("Player Toggles", MenuPlayersAllToggles, MenuPlayersAll);
				//addHookedOption("Wet", &Peds_f::TogglePedWetness, Player);
				//addHookedOption("Sweating", &Peds_f::TogglePedSweat, Player);
				//addHookedOption("Bleeding", &Peds_f::TogglePedBlood, Player);
				//addHookedOption("Handcuffs", &Peds_f::ToggleHandcuffs, Player);
				//addHookedOption("Pin Down", &Peds_f::TogglePedPinDown, Player);
				//addHookedOption("Ragdoll", &Peds_f::ToggleRagdoll, Player);
				//addHookedOption("Gravity", &Peds_f::TogglePedGravity);
				//addHookedOption("No Clipping Mode", Peds_f::TogglePedIsClipping, Player);
				//addHookedOption("Flying Mode", Peds_f::ToggleFlyMode, Player);
				//addHookedOption("Freeze Position", &Peds_f::ToggleFreezePedPosition, Player);
			
				// UNUSED
				//addOption("Walk On Water");
				//addOption("Forcefield");
				//addHookedOption("Dispatch Police", &Peds_f::ToggleCopDispatch, Player);
				
					
				// All Players -> Vehicle
				addMenu("Player Vehicle", MenuPlayersAllEditVehicle, MenuPlayersAll);
				addHookedOption("Get Vehicle Info", &Vehicles_f::GetCarInfo, Player);
				addHookedOption("Fix & Wash", &Vehicles_f::FixAndWash, Player);
				addHookedOption("Fully Tune", &Vehicles_f::MaxOutVehicle, Player);
				addHookedOption("Hijack", &Vehicles_f::HijackVehicle, Player);
				addHookedOption("Force Stop", &Vehicles_f::StopVehicleNow, Player);
				addHookedOption("Boost Forward", &Vehicles_f::BoostVehicle, 1);
				addHookedOption("Boost Backwards", &Vehicles_f::BoostVehicle, 2);
				addHookedOption("Flip Vehicle Upright", &Vehicles_f::FlipVehicleUpright, Player);
				addHookedOption("Set On Fire", &Vehicles_f::ToggleVehicleOnFire, Player);
				addHookedOption("Freeze", &Vehicles_f::ToggleFreezeVehiclePosition, Player);
				addHookedOption("Slingshot Vehicle", &Vehicles_f::SlingshotVehicle, Player);
				//addHookedOption("< Change Dirt Level >", &Vehicles_f::ChangeDirtLevel, Player);
				addHookedOption("Explode Tires", &Vehicles_f::ExplodeAllTires, Player);
				addHookedOption("Smash Windows", &Vehicles_f::ToggleVehicleWindowsBroken, Player);
				addHookedOption("Destroy", &Vehicles_f::ToggleVehicleDriveable, Player);
				addHookedOption("< Explode >", &Vehicles_f::ExplodeVehicle, Player);
				//addHookedOption("Take Vehicle Ownership", Vehicles_f::TakeVehicleOwnership, Player);
				addHookedOption("Delete", &Vehicles_f::DeletePlayersVehicle, Player);
				
			
				//-----------------------------------------------------------------------//
				// All Players -> Attachments
				addMenu("Attachments", MenuPlayersAllAttachments, MenuPlayersAll);
				addOption("Attachment Manager", &openSub, MenuPlayersAllAttachmentsManager);
				addHookedOption("Attach Object Test", &Peds_f::AttachObjectToPed, Player);
				//addOption("Attach Prop");
				//addOption("Attach Vehicle");
				//addOption("Attach Ped");
				//addOption("Attach Weapon");
				addHookedOption("Detach All", &Peds_f::DetachObjectsFromPlayer, Player);
				//-----------------------------------------------------------------------//
				
			
				//-----------------------------------------------------------------------//
				// All Players -> Attachments -> Manager
				addMenu("Attachment Manager", MenuPlayersAllAttachmentsManager, MenuPlayersAllAttachments);
				//-----------------------------------------------------------------------//
			}

			
			
			Player++;

		}

		subOptionCount[MenuPlayersAll] = Player;
		

		// Try setting player active for global stuff
		//SelectedPlayer = Player;
		//PlayerCurrent = Player;
		PlayerFollow = Player;
		NameCurrentFollow = NameCurrent;
	}
	//---------------------------------------------------------------------------
	

	//---------------------------------------------------------------------------
	// Declare Default Menu Struct
	//void createMenuStruct();
	//---------------------------------------------------------------------------


	//---------------------------------------------------------------------------
	// This is what draws the menu on the screen.
	// This is where you change the theme, colors, position, etc.
	void drawMenu()
	{
		/*
		if (problemCounter == 0)
		{
			DrawNotify("Please report any problems to esc0rtd3w@gmail.com", "CHAR_DEFAULT", "CHAR_DEFAULT", 1, false, "ps3dg.com", "", 5000);
			sleep(100);
			problemCounter++;
		}
		*/	

		// Default Color Sets
		//ColorSet ColorText = Colors::Common::White;
		//ColorSet ColorTextSelected = Colors::Dark::DarkOrange;
		ColorSet Color = Colors::Common::White;
		ColorSet ColorHighlight = Colors::Common::Yellow;

		// Default X Offset
		float x_Offset = .3;
		x_OffsetFollow = x_Offset;

		// Default Y Offset
		//float y_Offset = .3;

		const char** Options = subOptionText[currentMenu];

		
		// Main Title Text -> TEST FONT LETTERS
		// Font #3 Displays ABC=Small Filled/Medium Filled/Large Hollow Type 1
		// Font #3 Displays DEF=Small Filled/Medium Filled/Large Hollow Type 2
		// Font #3 Displays GHI=Small Filled/Medium Filled/Large Hollow Type 3
		//DrawText("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 3, 0.5 + x_Offset, 0.063, 1.00, 0.70, Colors::Common::Orange, 255, true);
		
		// Main Title Text -> TEST FONT NUMBERS
		// Font #3 Displays 1=Left Arrow, 2=Right Arrow, 3=Up Arrow, 4=Down Arrow
		//DrawText("0123456789", 3, 0.5 + x_Offset, 0.063, 1.00, 0.70, Colors::Common::Orange, 255, true);
		
		// Main Title Text -> TEST FONT SPECIAL MOST
		// Does not display any of these characters in game
		//DrawText("~!@#$%^&*()_+{}|:<>?`-=[];',./", 3, 0.5 + x_Offset, 0.063, 1.00, 0.70, Colors::Common::Orange, 255, true);
		
		
		// Set default difference for border
		float Dif = ((subOptionCount[currentMenu] > 16 ? 16 : subOptionCount[currentMenu]) * 0.45) / 10;
		DifFollow = Dif;

		// Set default footer attachment difference
		float DifFooter = ((subOptionCount[currentMenu] > 16 ? 16 : subOptionCount[currentMenu]) * 0.45) / 10;
		DifFooterFollow = DifFooter;

		// Main Title Text
		//DrawText(cellReadFS(), 7, 0.52 + x_Offset, 0.063, 1.00, 0.70, menuTextTitle, 255, true);
		DrawText(cellReadFS(), 7, 0.52 + x_Offset, 0.063, 1.00, 0.70, Colors::Common::Orange, 255, true);

		// Main Title SubText
		//DrawText("GTA:V Title Update v1.25", 6, 0.52 + x_Offset, 0.095, 0.35, 0.35, menuTextSubTitle, 255, true);
		//DrawText("GTA:V Title Update v1.25", 6, 0.52 + x_Offset, 0.095, 0.35, 0.35, Colors::Common::Teal, 255, true);

		// Main Menu Current Subtitle Text
		//DrawText(subMenuTitle[currentMenu], 1, 0.52 + x_Offset, 0.116, 0.95, 0.85, menuTextSubTitle, 255, true);
		DrawText(subMenuTitle[currentMenu], 1, 0.52 + x_Offset, 0.116, 0.95, 0.85, Colors::Common::Yellow, 255, true);
		//DrawSprite("CommonMenu", "mp_hostcrown", 0.52 + x_Offset, 0.116, 0.05, 0.05, Colors::Common::Orange, 40);
		//DrawSprite("CommonMenu", "mp_specitem_weed", 0.52 + x_Offset, 0.121, 0.05, 0.05, Colors::Common::Green, 40);
		
		
		// Menu Background -> Draw Around Entire Menu
		if (demoModeText)
		{
			if (demoTimeRemaining > 5)
			{
				//DrawRect(0.52 + x_Offset, 0.140 + Dif / 2, .2, 0.155 + Dif, menuBGMain, 40);
				DrawRect(0.52 + x_Offset, 0.140 + Dif / 2, .2, 0.155 + Dif, Colors::Common::Black, 40);
			}
			else
			{
				//DrawRect(0.52 + x_Offset, 0.140 + Dif / 2, .2, 0.155 + Dif, menuBGMainDemo, 30);
				DrawRect(0.52 + x_Offset, 0.140 + Dif / 2, .2, 0.155 + Dif, Colors::Common::Red, 30);
			}
		}
		else
		{
			//DrawRect(0.52 + x_Offset, 0.140 + Dif / 2, .2, 0.155 + Dif, menuBGMain, 40);
			DrawRect(0.52 + x_Offset, 0.140 + Dif / 2, .2, 0.155 + Dif, Colors::Common::Black, 40);
		}

		// Menu Background -> Draw Header
		//DrawRect(0.52 + x_Offset, 0.048, 0.20, 0.03, menuBGHeader, 40);
		DrawRect(0.52 + x_Offset, 0.048, 0.20, 0.03, Colors::Common::Orange, 40);

		// Menu Background -> Draw Around Sub Title Text
		//DrawRect(0.52 + x_Offset, 0.123, 0.20, 0.02, menuBGSubTitle, 20);
		//DrawRect(0.52 + x_Offset, 0.123, 0.20, 0.02, Colors::Mixed::Lime, 20);

		// Menu Background -> Draw Footer
		//DrawRect(0.52 + x_Offset, 0.227 + DifFooter, 0.20, 0.02, menuBGFooter, 40);
		DrawRect(0.52 + x_Offset, 0.227 + DifFooter, 0.20, 0.02, Colors::Common::Orange, 40);

		// Menu -> Draw Footer Text Left Side
		//DrawText("esc0rtd3w", 6, 0.440 + x_Offset, 0.215 + DifFooter, 0.35, 0.30, menuTextFooterLeft, 255, true);

		// Menu -> Draw Footer Text Center
		//DrawText("Center Text", 6, 0.52 + x_Offset, 0.215 + DifFooter, 0.35, 0.30, menuTextFooterCenter, 255, true);

		// Menu -> Draw Footer Text Right Side
		//DrawText("ps3dg.com", 6, 0.600 + x_Offset, 0.215 + DifFooter, 0.35, 0.30, menuTextFooterRight, 255, true);

		
		if (currentMenu == MenuRecoveryRank && seenHelpMenuRank == 0)
		{
			MsgHelpWarning(3);
			seenHelpMenuRank++;
		}

		
		if (currentMenu == MenuMoneyCoords && seenHelpMoneyCoords == 0)
		{
			MsgHelpWarning(1);
			seenHelpMoneyCoords++;
		}

		
		if (currentMenu == MenuMoney && seenHelpSelectedPlayer == 0)
		{
			MsgHelpWarning(2);
			seenHelpSelectedPlayer++;
		}

		
		if (currentMenu == MenuVehiclesManager && seenHelpVehicleManager == 0)
		{
			MsgHelpWarning(4);
			seenHelpVehicleManager++;
		}
		
		if (currentMenu == MenuLobbyTalkingLoops && seenWarningTalkingPunish == 0)
		{
			MsgHelpWarning(5);
			seenWarningTalkingPunish++;
		}

		//---------------------------------------------------------------------------
		
		
		
		//---------------------------------------------------------------------------
		// Sub Menu Items
		for (int i = 0; i < 16; i++)
		{
			//bool isActive = NETWORK_IS_PLAYER_ACTIVE(GET_PLAYER_PED(i));
			//bool isSignedIn = NETWORK_IS_SIGNED_IN();
			
			int isHostHighlight = NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0);
			//int isSelfHighlight = PlayerSelf();
			
			//int seatMax = GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(GET_PLAYER_PED(i));
			bool inVehHighlight = IsPedInAnyVehicle(GET_PLAYER_PED(i));
			//bool inVehHighlight = IS_PED_IN_VEHICLE(GET_PLAYER_PED(i));
			bool inBoatHighlight = IS_PED_IN_ANY_BOAT(GET_PLAYER_PED(i));
			bool inHeliHighlight = IS_PED_IN_ANY_HELI(GET_PLAYER_PED(i));
			bool inPlaneHighlight = IS_PED_IN_ANY_PLANE(GET_PLAYER_PED(i));
			bool inPoliceHighlight = IS_PED_IN_ANY_POLICE_VEHICLE(GET_PLAYER_PED(i));
			//bool inSubHighlight = IS_PED_IN_ANY_SUB(GET_PLAYER_PED(i));
			//bool inTaxiHighlight = IS_PED_IN_ANY_TAXI(GET_PLAYER_PED(i));
			//bool inTrainHighlight = IS_PED_IN_ANY_TRAIN(GET_PLAYER_PED(i));
			//bool inFlyingHighlight = IS_PED_IN_FLYING_VEHICLE(GET_PLAYER_PED(i));
			bool inBikeHighlight = IS_PED_ON_ANY_BIKE(GET_PLAYER_PED(i));
			//bool inTaxiHighlight = IS_PED_IN_ANY_TAXI(GET_PLAYER_PED(i));
			//bool inBicycleHighlight = false;
			
			//bool isTalking = NETWORK_IS_PLAYER_TALKING(i);

			bool isInWater = IS_ENTITY_IN_WATER(GET_PLAYER_PED(i));
			bool isInAir = IS_ENTITY_IN_AIR(GET_PLAYER_PED(i));

			bool isDead = IS_ENTITY_DEAD(GET_PLAYER_PED(i));
			//bool isVisible = IS_ENTITY_VISIBLE(GET_PLAYER_PED(i));
			bool doesExist = DOES_ENTITY_EXIST(GET_PLAYER_PED(i));

			//bool isInvincible = GET_PLAYER_INVINCIBLE(GET_PLAYER_PED(i));
			Hash checkModel = GET_ENTITY_MODEL(GET_PLAYER_PED(i));
			
			//int wantedLevel = GET_PLAYER_WANTED_LEVEL(GET_PLAYER_PED(i));
			//bool isWanted;
			
			//bool isVoteToKick = NETWORK_SESSION_ARE_PLAYERS_VOTING_TO_KICK(PlayerSelf());
			
			//int _player = GET_PLAYER_PED(GET_PLAYER_PED(i));
			//int _vehicle = GetCurrentVehicle(_player);

			// Get length of Options
			//int str_len = strlen(Options[i]);
			//PrintInt(str_len, 3000);

			// Menu Sub Items Default Text NOT SELECTED Color
			//ColorSet Color = menuTextItemNotSelected;
			Color = Colors::Common::White;
			
			//--------------------------------------------------------------------------------
			// PLAYER ACTIVITY ICON SLOTS
			/*
			if (isSelfHighlight == i && currentMenu == MenuPlayersAll)
			{
				DrawSprite("mpleaderboard", "leaderboard_players_icon", 0.402 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Orange, 40);
			}
			*/
			
			// Icon Slot 4 Left (Far Left)
			if (isDead && doesExist && currentMenu == MenuPlayersAll)
			{
				DrawSprite("mpinventory", "deathmatch", 0.330 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::White, 40);
			}
			
			/*
			if (isTalking && currentMenu == MenuPlayersAll)
			{
				DrawSprite("mpinventory", "mp_specitem_weed", 0.283 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Green, 40);
			}
			*/
			
			/*
			if (!isVisible && currentMenu == MenuPlayersAll)
			{
				DrawSprite("mpleaderboard", "leaderboard_players_icon", 0.330 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Pink, 40);
			}
			*/
			
			// Icon Slot Left 3
			// Male Hash: 1885233650
			// Female Hash: -1667301416
			if (checkModel != 1885233650 && doesExist && currentMenu == MenuPlayersAll)
			{
				if (checkModel != -1667301416)
				{
					DrawSprite("helicopterhud", "targetlost", 0.355 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Yellow, 40);
				}
			}

			/*
			if (isInvincible && doesExist && currentMenu == MenuPlayersAll)
			{
				DrawSprite("mpleaderboard", "leaderboard_players_icon", 0.330 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Pink, 40);
			}
			*/
			
			// Icon Slot Left 2
			if (isInAir && currentMenu == MenuPlayersAll)
			{
				DrawSprite("commonmenutu", "race_air", 0.380 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Orange, 40);
			}

			if (isInWater && currentMenu == MenuPlayersAll)
			{
				DrawSprite("commonmenutu", "race_water", 0.380 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Blue, 40);
			}
			
			// Icon Slot Left 1 (Rightmost On Left of Menu)
			//if (inVehHighlight && !inTaxiHighlight && !inBoatHighlight && !inHeliHighlight && !inPlaneHighlight && !inBikeHighlight && !inPoliceHighlight && currentMenu == MenuPlayersAll)
			if (inVehHighlight && !inBoatHighlight && !inHeliHighlight && !inPlaneHighlight && !inBikeHighlight && !inPoliceHighlight && currentMenu == MenuPlayersAll)
			{
				DrawSprite("mpcarhud", "transport_car_icon", 0.405 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Teal, 40);
			}
			
			if (inBoatHighlight && currentMenu == MenuPlayersAll)
			{
				DrawSprite("mpcarhud", "transport_boat_icon", 0.405 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Teal, 40);
			}
			
			if (inHeliHighlight && currentMenu == MenuPlayersAll)
			{
				DrawSprite("mpcarhud", "transport_heli_icon", 0.405 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Teal, 40);
			}
			
			if (inPlaneHighlight && currentMenu == MenuPlayersAll)
			{
				DrawSprite("mpcarhud", "transport_plane_icon", 0.405 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Teal, 40);
			}
			
			/*
			if (inTaxiHighlight && currentMenu == MenuPlayersAll)
			{
				DrawSprite("mpcarhud", "transport_boat_icon", 0.405 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Teal, 40);
			}
			
			if (_vehicle == 1131912276 && currentMenu == MenuPlayersAll)
			{
				DrawSprite("mpcarhud", "transport_bicycle_icon", 0.405 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Teal, 40);
			}
			*/

			if (inBikeHighlight && currentMenu == MenuPlayersAll)
			{
				DrawSprite("mpcarhud", "transport_bike_icon", 0.405 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Teal, 40);
			}
			
			if (inPoliceHighlight && currentMenu == MenuPlayersAll)
			{
				DrawSprite("mpleaderboard", "leaderboard_cops_icon", 0.405 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Teal, 40);
			}
			
			// Icon Slot Right 1 (Leftmost On Right of Menu)
			if (isHostHighlight == i && currentMenu == MenuPlayersAll)
			{
				DrawSprite("CommonMenu", "mp_hostcrown", 0.638 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, Colors::Common::Green, 40);
			}
			
			/*
			// Icon Slot Right 2
			ColorSet wantedColor;
			if (isWanted && wantedLevel >= 1 && doesExist && currentMenu == MenuPlayersAll)
			{
				switch(wantedLevel)
				{
					case 1: 
						wantedColor = Colors::Common::White;
						break;
					case 2: 
						wantedColor = Colors::Common::Yellow;
						break;
					case 3: 
						wantedColor = Colors::Common::Orange;
						break;
					case 4: 
						wantedColor = Colors::Common::Pink;
						break;
					case 5: 
						wantedColor = Colors::Common::Red;
						break;
						
				}

				DrawSprite("commonmenu", "shop_new_star", 0.663 + x_Offset, 0.202 + (0.045f*i), 0.025, 0.04, wantedColor, 40);
			}
			*/

			
			

			//--------------------------------------------------------------------------------
			

			// Menu Items Text Default SELECTED Color
			if (i == currentOption) 
			{
				// Send current option to global
				currentOptionFollow = Options[(currentOption)];
				helpContextItem = Options[(currentOption)];

				
				if (currentMenu == MenuPlayersAll)
				{
					PlayerSelected = i;
					//char buffer[32];
					//sprintf(buffer, "%s", GET_PLAYER_NAME(PlayerSelected));
					//DrawNotify(buffer, "CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 4, false);
				}

				currentMenuFollow = currentMenu;

				
				// Menu Sounds

				// UP and DOWN NAVIGATION
				if (!isMenuSoundUpDown && isMenuSoundUpDown_ == 0)
				{
					isMenuSoundUpDown_++;
					isMenuSoundUpDown__ = i;
					isMenuSoundUpDown = true;
				}

				if (isMenuSoundUpDown__ != i)
				{
					isMenuSoundUpDown_ = 0;
				}

				/*
				// SELECT ITEM
				if (!isMenuSoundSelect && isMenuSoundSelect_ == 0)
				{
					isMenuSoundSelect_++;
					isMenuSoundSelect__ = i;
					isMenuSoundSelect = true;
				}

				if (isMenuSoundSelect__ != i)
				{
					isMenuSoundSelect_ = 0;
				}
				*/
				
				if (currentMenu == MenuLobby && currentOptionFollow == "Give All Weapons" || currentMenu == MenuLobby && currentOptionFollow == "Take All Weapons")
				{
					MsgHelpWarningShort(1);
				}
		
				if (currentMenu == MenuPlayerSelf && currentOptionFollow == "Change Model")
				{
					MsgHelpWarningShort(2);
				}
		
				if (currentOptionFollow == "< Explode >")
				{
					dpadAdjustType = "Explosion Type";
					//MsgDpadAdjust(1);
					char buffer[100];
					sprintf(buffer, "~w~%s: ~p~%i\n~w~Use ~y~DPAD L+R ~w~To Adjust\n~w~Select Option With ~b~X ~w~Button", dpadAdjustType, explosionType);
					PrintText(buffer, 100);
				}
		
				/*
				if (currentOptionFollow == "< Change Dirt Level >")
				{
					dpadAdjustType = "Dirt Level";
					//MsgDpadAdjust(1);
					char buffer[100];
					sprintf(buffer, "~w~%s: ~p~%i\n~w~Use ~y~DPAD L+R ~w~To Adjust\n~w~Select Option With ~b~X ~w~Button", dpadAdjustType, dirtLevel);
					PrintText(buffer, 100);
				}
				*/

				if (currentOptionFollow == "Kick All Players" || currentOptionFollow == "Kick Player")
				{
					PrintText("This Option Only Works If You Are ~g~HOST", 100);
				}
		
				/*
				if (currentOptionFollow == "Wheel Type")
				{
					dpadAdjustType = "Wheel Type";
					//MsgDpadAdjust(1);
					char buffer[100];
					sprintf(buffer, "~w~%s: ~p~%i\n~w~Use ~y~DPAD L+R ~w~To Adjust\n~w~Select Option With ~b~X ~w~Button", dpadAdjustType, wheelType);
					PrintText(buffer, 100);
				}
				*/
		
				/*
				if (currentMenu == MenuPlayerSelfToggles && currentOptionFollow == "Wanted Level")
				{
					MsgHelpWarningShort(3);
				}
				*/
				
				/*
				if (currentMenu == MenuProtection && currentOptionFollow == "Identify Modders In Lobby")
				{
					MsgHelpWarningShort(6);
				}
				*/

				// Change the color on selected item
				//Color = menuTextItemSelected;
				Color = Colors::Dark::DarkOrange;


				// Check money vehicle
				if (isMoneyVehicleCheck && currentMenu == MenuVehicles && currentOption == 0 || isMoneyVehicleCheck && currentMenu == MenuVehicleSpawn)
				{
					ColorHighlight = Colors::Common::Green;
				}


				// Check for custom highlight if on a vehicle spawn menu
				if (currentMenu == MenuVehicleSpawnBikes && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnBoats && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnCommercial && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnCompacts && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnCoupes && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnEmergency && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnHelicopters && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnIndustrial && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnMilitary && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnMotorcycles && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnMuscle && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnOffroad && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnPlanes && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnSedans && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnService && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnSports && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnSportsClassics && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnSuper && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnSUVs && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnUtilities && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnVans && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnSpecial && isMoneyVehicleCheck || 
				currentMenu == MenuVehicleSpawnProps && isMoneyVehicleCheck)
				{
					//currentMenuFollowMoney = true;
					ColorHighlight = Colors::Common::Green;
				}


				if (currentMenu != MenuVehicles || currentMenu != MenuVehicleSpawn)
				{
					isMoneyToggleHighlight = false;
				}

				else
				{
					ColorSet ColorHighlight = Colors::Common::Yellow;
				}

				// Draw a box around selected item
				//DrawRect(0.52 + x_Offset, 0.202 + (0.045f*i), 0.20, 0.038, menuBGItemSelected, 30);
				DrawRect(0.52 + x_Offset, 0.202 + (0.045f*i), 0.20, 0.038, ColorHighlight, 30);


				

				// Display Help Text
				if (showMenuHelpContext)
				{
					const char* txtHelp = checkHelpContext(helpContextItem, helpContextDisplay);

					//MenuArrow(2, 0.60, Colors::Common::Orange, 255);
					DrawText("2", 3, 0.409 + x_Offset, 0.176 + (0.045f*i), 0.50, 0.50, Colors::Common::Orange, 255, true);

					//MenuHelpContext(txtHelp, 6, 0.40, Colors::Common::White, 255);
					DrawText(txtHelp, 6, 0.24 + x_Offset, 0.166 + (0.045f*i), 0.40, 0.40, Colors::Common::Teal, 255, false);
				}

			}
			
			


			// Second+ Pages Greater Than 15 Items
			if (currentOption > 15)
			{

				//iFollow = i;

				// Menu Items Text SELECTED past first page
				if (i == 15) 
				{
					// Send current option to global
					currentOptionFollow = Options[(currentOption)];
					helpContextItem = Options[(currentOption)];

					if (currentMenu == MenuPlayersAll)
					{
						PlayerSelected = i;
					}

					currentMenuFollow = currentMenu;

					//char buffer[64];
					//sprintf(buffer, "%s", currentOptionFollow);
					//PrintText(buffer, 100);

					
					// Menu Sounds

					// UP and DOWN NAVIGATION
					if (!isMenuSoundUpDown && isMenuSoundUpDown_ == 1)
					{
						isMenuSoundUpDown_++;
						//isMenuSoundUpDown__ = currentMenu;
						isMenuSoundUpDown___ = currentOptionFollow;
						isMenuSoundUpDown = true;
					}

					if (isMenuSoundUpDown___ != currentOptionFollow)
					{
						isMenuSoundUpDown_ = 1;
					}

					// Change the color on selected item
					Color = Colors::Dark::DarkOrange;


					// Check money vehicle
					if (isMoneyVehicleCheck && currentMenu == MenuVehicles && currentOption == 0 || isMoneyVehicleCheck && currentMenu == MenuVehicleSpawn)
					{
						ColorHighlight = Colors::Common::Green;
					}


					// Check for custom highlight if on a vehicle spawn menu
					if (currentMenu == MenuVehicleSpawnEmergency && isMoneyVehicleCheck || 
					currentMenu == MenuVehicleSpawnMotorcycles && isMoneyVehicleCheck || 
					currentMenu == MenuVehicleSpawnMuscle && isMoneyVehicleCheck || 
					currentMenu == MenuVehicleSpawnOffroad && isMoneyVehicleCheck || 
					currentMenu == MenuVehicleSpawnPlanes && isMoneyVehicleCheck || 
					currentMenu == MenuVehicleSpawnSedans && isMoneyVehicleCheck || 
					currentMenu == MenuVehicleSpawnSports && isMoneyVehicleCheck || 
					currentMenu == MenuVehicleSpawnSUVs && isMoneyVehicleCheck || 
					currentMenu == MenuVehicleSpawnUtilities && isMoneyVehicleCheck || 
					currentMenu == MenuVehicleSpawnVans && isMoneyVehicleCheck || 
					currentMenu == MenuVehicleSpawnSpecial && isMoneyVehicleCheck)
					{
						//currentMenuFollowMoney = true;
						ColorHighlight = Colors::Common::Green;
					}


					if (currentMenu != MenuVehicles || currentMenu != MenuVehicleSpawn)
					{
						isMoneyToggleHighlight = false;
					}

					else
					{
						ColorSet ColorHighlight = Colors::Common::Yellow;
					}


					// Draw a box around selected item
					//DrawRect(0.52 + x_Offset, 0.202 + (0.045f*i), 0.20, 0.038, menuBGItemSelected, 30);
					DrawRect(0.52 + x_Offset, 0.202 + (0.045f*i), 0.20, 0.038, ColorHighlight, 30);


					// Draw a Left Arrow to the right of menu on current option
					//DrawText("2", 3, 0.409 + x_Offset, 0.173 + (0.045f*i), 0.60, 0.60, menuTextItemSelectedLeft, 255, true);

					// Draw a Right Arrow to the left of menu on current option
					//DrawText("1", 3, 0.820 + x_Offset, 0.173 + (0.045f*i), 0.60, 0.60, menuTextItemSelectedRight, 255, true);
					
					

					// Display Help Text
					if (showMenuHelpContext)
					{
						const char* txtHelp = checkHelpContext(helpContextItem, helpContextDisplay);

						//MenuArrow(2, 0.60, Colors::Common::Orange, 255);
						DrawText("2", 3, 0.409 + x_Offset, 0.176 + (0.045f*i), 0.50, 0.50, Colors::Common::Orange, 255, true);

						//MenuHelpContext(txtHelp, 6, 0.40, Colors::Common::White, 255);
						DrawText(txtHelp, 6, 0.24 + x_Offset, 0.166 + (0.045f*i), 0.40, 0.40, Colors::Common::Teal, 255, false);
					}

				}
				
				// Menu Items Default Selected Color
				DrawText(Options[(currentOption + i)-15], 4, 0.52 + x_Offset, 0.18 + (0.045f*i), 0.65, 0.65, Color, 255, true);
				

				continue;
				

			}

			// Menu Items/Sub Items Text Current Color
			DrawText(Options[i], 4, 0.52 + x_Offset, 0.18 + (0.045f*i), 0.65, 0.65, Color, 255, true);
		}
	
		//DrawCursor();

		// Disable Some Buttons While Menu Is Loaded
		ToggleControls(0, Dpad_Up);
		ToggleControls(0, Dpad_Down);
		ToggleControls(0, Dpad_Left);
		ToggleControls(0, Dpad_Right);
		ToggleControls(0, Button_CROSS);
		ToggleControls(0, Button_CIRCLE);
		//ToggleControls(0, Button_TRIANGLE);
		//SET_INPUT_EXCLUSIVE(0, Button_CROSS);

	}
	//---------------------------------------------------------------------------


	

	// Refresh Players Menu
	void RefreshPlayerMenu()
	{
		//
	}

	
	//---------------------------------------------------------------------------
	// Opens a sub menu
	void openSub(int Menu)
	{
		if (Menu == MenuPlayersAll)
		{
			isUpdatePlayersMenu = true;
		}

		/*
		if (Menu == MenuVehicles)
		{
			PlayerSelected = PlayerSelf();
		}
		*/

		previousOption[currentMenu] = currentOption;
		currentOption = previousOption[Menu];
		currentMenu = Menu;
		currentMenuFollow = currentMenu;
	}
	//---------------------------------------------------------------------------



	//---------------------------------------------------------------------------
	//And this is where you build our menu's structure, idk any other way to explain it
	void createMenuStruct()
	{
		//-----------------------------------------------------------------------//
		// Main Text
		addMenu("Main Menu", MenuMain);
		addOption("~w~$$ ~g~Money Drops ~w~$$", &openSub, MenuMoney);
		addOption("Self Mods", &openSub, MenuPlayerSelf);
		addOption("Players", &openSub, MenuPlayersAll);
		addOption("Lobby", &openSub, MenuLobby);
		addOption("World", &openSub, MenuWorld);
		addOption("Teleport", &openSub, MenuTeleport);
		addOption("Vehicles", &openSub, MenuVehicles);
		addOption("Objects", &openSub, MenuObjects);
		addOption("Peds", &openSub, MenuPeds);
		addOption("Protection", &openSub, MenuProtection);
		addOption("Network", &openSub, MenuNetwork);
		addOption("Misc", &openSub, MenuMisc);
		addOption("Help", &openSub, MenuHelp);
		
		// UNUSED
		//addOption("Sounds", &openSub, MenuSoundsMain);
		//addOption("Missions", &openSub, MenuProtection);
		//addOption("Presets", &openSub, MenuPresets);
		//addOption("Settings", &openSub, MenuSettings);

		
		//addHookedOption("Test Button", &cellFSFilesystem);

		/*
		if (debug == true)
		{
			addOption("*Debug*", &openSub, MenuDebug);
		}
		*/
		
		//addOption("Close Menu", &isClosed);
		//-----------------------------------------------------------------------//
		
		
		//-----------------------------------------------------------------------//
		// Money Drops
		addMenu("~w~$$ ~g~Money Drops ~w~$$", MenuMoney, MenuMain);
		addHookedOption("Toggle Lobby Drop", &Lobby_f::ToggleMoneyAllPlayers);
		addHookedOption("Toggle Player Drop", &Peds_f::ToggleMoneySpawnDefault);
		addHookedOption("Toggle Vehicle Drop", &Vehicles_f::ToggleMoneyVehicle);
		addHookedOption("Toggle Talking Drop", &Lobby_f::ToggleMoneyTalkingPlayers);
		addHookedOption("Toggle Button Drop", &Peds_f::MoneyButton);
		addOption("");
		addOption("Change Drop Prop", &openSub, MenuMoneyCustom);
		//addOption("Change Drop Buttons");
		//addOption("Change Active Player", &openSub, MenuMoneyPlayers);
		addOption("Adjust Coordinates", &openSub, MenuMoneyCoords);
		addOption("");
		addOption("Disable All Money Toggles", &Misc_f::DisableAllMoneyToggles);
		
		/*
		// Money Drops -> Change Player
		addMenu("Active Players", MenuMoneyPlayers, MenuMoney);
		addHookedOption("Player 0", &Peds_f::MoneyPlayerAdjust, 0);
		addHookedOption("Player 1", &Peds_f::MoneyPlayerAdjust, 1);
		addHookedOption("Player 2", &Peds_f::MoneyPlayerAdjust, 2);
		addHookedOption("Player 3", &Peds_f::MoneyPlayerAdjust, 3);
		addHookedOption("Player 4", &Peds_f::MoneyPlayerAdjust, 4);
		addHookedOption("Player 5", &Peds_f::MoneyPlayerAdjust, 5);
		addHookedOption("Player 6", &Peds_f::MoneyPlayerAdjust, 6);
		addHookedOption("Player 7", &Peds_f::MoneyPlayerAdjust, 7);
		addHookedOption("Player 8", &Peds_f::MoneyPlayerAdjust, 8);
		addHookedOption("Player 9", &Peds_f::MoneyPlayerAdjust, 9);
		addHookedOption("Player 10", &Peds_f::MoneyPlayerAdjust, 10);
		addHookedOption("Player 11", &Peds_f::MoneyPlayerAdjust, 11);
		addHookedOption("Player 12", &Peds_f::MoneyPlayerAdjust, 12);
		addHookedOption("Player 13", &Peds_f::MoneyPlayerAdjust, 13);
		addHookedOption("Player 14", &Peds_f::MoneyPlayerAdjust, 14);
		addHookedOption("Player 15", &Peds_f::MoneyPlayerAdjust, 15);
		*/

		// Money Drops -> Adjust Coords
		addMenu("Adjust Coords", MenuMoneyCoords, MenuMoney);
		addHookedOption("Reset Drop Coords", &Peds_f::ResetDropCoords);
		addHookedOption("< Modify X Coord >", &Peds_f::ModifyDropCoordX);
		addHookedOption("< Modify Y Coord >", &Peds_f::ModifyDropCoordY);
		addHookedOption("< Modify Z Coord >", &Peds_f::ModifyDropCoordZ);

		// Money Drops -> Custom
		addMenu("~w~$$ ~g~Custom Drops ~w~$$", MenuMoneyCustom, MenuMoney);
		//addHookedOption("Input Custom", &Peds_f::ToggleMoneySpawnCustom, 0);
		addHookedOption("# Numbers", &openSub, MenuMoneyCustomNumbers);
		addHookedOption("40 Oz.", &Peds_f::ToggleMoneySpawnCustom, 6);
		addHookedOption("Alien Egg", &Peds_f::ToggleMoneySpawnCustom, 11);
		addHookedOption("Asteroid (CAUTION!)", &Peds_f::ToggleMoneySpawnCustom, 14);
		addHookedOption("Basketball", &Peds_f::ToggleMoneySpawnCustom, 15);
		addHookedOption("Battery", &Peds_f::ToggleMoneySpawnCustom, 41);
		addHookedOption("Beach Fire (CAUTION!)", &Peds_f::ToggleMoneySpawnCustom, 55);
		addHookedOption("Bong", &Peds_f::ToggleMoneySpawnCustom, 16);
		addHookedOption("Boombox", &Peds_f::ToggleMoneySpawnCustom, 22);
		addHookedOption("Bowling Ball", &Peds_f::ToggleMoneySpawnCustom, 19);
		addHookedOption("Bowling Pin", &Peds_f::ToggleMoneySpawnCustom, 20);
		addHookedOption("Car Engine", &Peds_f::ToggleMoneySpawnCustom, 12);
		addHookedOption("Car Seat", &Peds_f::ToggleMoneySpawnCustom, 21);
		addHookedOption("Couch", &Peds_f::ToggleMoneySpawnCustom, 13);
		addHookedOption("Dildo", &Peds_f::ToggleMoneySpawnCustom, 5);
		addHookedOption("Ferris Wheel (CAUTION!)", &Peds_f::ToggleMoneySpawnCustom, 72);
		addHookedOption("Gas Can", &Peds_f::ToggleMoneySpawnCustom, 8);
		addHookedOption("Golf Bag", &Peds_f::ToggleMoneySpawnCustom, 60);
		//addHookedOption("Golf Ball", &Peds_f::ToggleMoneySpawnCustom, 44);
		addHookedOption("Golf Iron", &Peds_f::ToggleMoneySpawnCustom, 61);
		//addHookedOption("Green Screen", &Peds_f::ToggleMoneySpawnCustom, 66);
		addHookedOption("Guitar", &Peds_f::ToggleMoneySpawnCustom, 3);
		addHookedOption("Halo", &Peds_f::ToggleMoneySpawnCustom, 58);
		addHookedOption("Hard Hat", &Peds_f::ToggleMoneySpawnCustom, 62);
		addHookedOption("Hot Dog", &Peds_f::ToggleMoneySpawnCustom, 24);
		//addHookedOption("Hot Tub (CAUTION!)", &Peds_f::ToggleMoneySpawnCustom, 63);
		addHookedOption("Katana", &Peds_f::ToggleMoneySpawnCustom, 48);
		addHookedOption("Ladder", &Peds_f::ToggleMoneySpawnCustom, 26);
		addHookedOption("Lawn Mower", &Peds_f::ToggleMoneySpawnCustom, 1);
		//addHookedOption("Lights (CAUTION!)", &Peds_f::ToggleMoneySpawnCustom, 56);
		addHookedOption("Log", &Peds_f::ToggleMoneySpawnCustom, 70);
		addHookedOption("Microwave", &Peds_f::ToggleMoneySpawnCustom, 65);
		addHookedOption("Money Bag", &Peds_f::ToggleMoneySpawnCustom, 10);
		addHookedOption("Money Bag Poly", &Peds_f::ToggleMoneySpawnCustom, 18);
		addHookedOption("Mop Bucket", &Peds_f::ToggleMoneySpawnCustom, 49);
		addHookedOption("Office Desk", &Peds_f::ToggleMoneySpawnCustom, 68);
		//addHookedOption("Old Boot", &Peds_f::ToggleMoneySpawnCustom, 43);
		//addHookedOption("Parachute", &Peds_f::ToggleMoneySpawnCustom, 23);
		//addHookedOption("Pick-Axe", &Peds_f::ToggleMoneySpawnCustom, 52);
		addHookedOption("Pillow", &Peds_f::ToggleMoneySpawnCustom, 47);
		addHookedOption("Pineapple", &Peds_f::ToggleMoneySpawnCustom, 25);
		//addHookedOption("Pinwheel", &Peds_f::ToggleMoneySpawnCustom, 75);
		addHookedOption("Printer", &Peds_f::ToggleMoneySpawnCustom, 42);
		addHookedOption("Pizza Box", &Peds_f::ToggleMoneySpawnCustom, 2);
		addHookedOption("Pool Table (CAUTION!)", &Peds_f::ToggleMoneySpawnCustom, 64);
		addHookedOption("Pyramid", &Peds_f::ToggleMoneySpawnCustom, 54);
		//addHookedOption("Radar (CAUTION!)", &Peds_f::ToggleMoneySpawnCustom, 60);
		addHookedOption("Refrigerator", &Peds_f::ToggleMoneySpawnCustom, 46);
		addHookedOption("Shoe", &Peds_f::ToggleMoneySpawnCustom, 67);
		addHookedOption("Shovel", &Peds_f::ToggleMoneySpawnCustom, 53);
		//addHookedOption("Sink", &Peds_f::ToggleMoneySpawnCustom, 69);
		//addHookedOption("Teapot", &Peds_f::ToggleMoneySpawnCustom, 45);
		addHookedOption("Teddy Bear", &Peds_f::ToggleMoneySpawnCustom, 71);
		addHookedOption("Television", &Peds_f::ToggleMoneySpawnCustom, 73);
		//addHookedOption("Time Capsule", &Peds_f::ToggleMoneySpawnCustom, 7);
		addHookedOption("Toaster", &Peds_f::ToggleMoneySpawnCustom, 9);
		addHookedOption("Toilet", &Peds_f::ToggleMoneySpawnCustom, 17);
		addHookedOption("Toilet Paper", &Peds_f::ToggleMoneySpawnCustom, 4);
		addHookedOption("Traffic Cone 1", &Peds_f::ToggleMoneySpawnCustom, 30);
		addHookedOption("Traffic Cone 2", &Peds_f::ToggleMoneySpawnCustom, 28);
		addHookedOption("Traffic Cone 3", &Peds_f::ToggleMoneySpawnCustom, 29);
		addHookedOption("Traffic Cone 4", &Peds_f::ToggleMoneySpawnCustom, 26);
		addHookedOption("UFO (CAUTION!)", &Peds_f::ToggleMoneySpawnCustom, 57);
		addHookedOption("Umbrella", &Peds_f::ToggleMoneySpawnCustom, 51);
		addHookedOption("Weed Plant", &Peds_f::ToggleMoneySpawnCustom, 59);
		addHookedOption("Wheel Chair", &Peds_f::ToggleMoneySpawnCustom, 74);
		//addHookedOption("Windmill (Large)", &Peds_f::ToggleMoneySpawnCustom, 50);
		
			
		// All Players -> Toggles -> Money Drop Custom -> Numbers
		addMenu("Money Drop: Numbers", MenuMoneyCustomNumbers, MenuMoneyCustom);
		addHookedOption("Number 0", &Peds_f::ToggleMoneySpawnCustom, 31);
		addHookedOption("Number 1", &Peds_f::ToggleMoneySpawnCustom, 32);
		addHookedOption("Number 2", &Peds_f::ToggleMoneySpawnCustom, 33);
		addHookedOption("Number 3", &Peds_f::ToggleMoneySpawnCustom, 34);
		addHookedOption("Number 4", &Peds_f::ToggleMoneySpawnCustom, 35);
		addHookedOption("Number 5", &Peds_f::ToggleMoneySpawnCustom, 36);
		addHookedOption("Number 6", &Peds_f::ToggleMoneySpawnCustom, 37);
		addHookedOption("Number 7", &Peds_f::ToggleMoneySpawnCustom, 38);
		addHookedOption("Number 8", &Peds_f::ToggleMoneySpawnCustom, 39);
		addHookedOption("Number 9", &Peds_f::ToggleMoneySpawnCustom, 40);
		
		//-----------------------------------------------------------------------//
		
		//-----------------------------------------------------------------------//
		// Player Self
		//int self = PlayerSelf();
		addMenu("Self Mods", MenuPlayerSelf, MenuMain);
		addOption("Toggles", &openSub, MenuPlayerSelfToggles);
		addOption("Weapons", &openSub, MenuWeapons);
		addOption("Animations", &openSub, MenuPlayerSelfAnimations);
		addOption("Change Name", &openSub, MenuPlayerSelfChangeName);
		addOption("Change Model", &openSub, MenuPlayerSelfModel);
		addHookedOption("Max Health/Armor", &PlayerSelf_f::GiveMaxHealthArmor);
		//addOption("Change Outfit", &openSub, MenuPlayerSelfOutfit);
		//addOption("Camera Options", &openSub, MenuPlayerSelfCamera);
		addOption("Time Cycle Modifier", &openSub, MenuPlayerSelfTimeCycle);
		addOption("Mobile Phone", &openSub, MenuPlayerSelfPhone);
		addHookedOption("Clone Player", &Peds_f::ClonePed, 0);
		addHookedOption("Sky Dive", &PlayerSelf_f::ActivateSkyDive);
		//addHookedOption("Cower In Fear", Peds_f::PedCowerInFear);
		addHookedOption("Extend Water Time", &PlayerSelf_f::ExtendPedWaterTime);
		addHookedOption("< Explode >", &Peds_f::ExplodePlayer);
		//addHookedOption("Explode Custom", &openSub, MenuPlayerSelfExplode);

		// UNUSED
		//addOption("Items", &openSub, MenuPlayerSelfItems);
		//addOption("Multipliers", &openSub, MenuPlayerSelfMultipliers);
		//addOption("Developer T-Shirts");
		//addHookedOption("Show Coords Heading", &PlayerSelf_f::ShowCoordsHeading);
		//addHookedOption("Explode Head", &PlayersAll_f::ExplodePedHead);
		//addHookedOption("Is Player On Train", &PlayerSelf_f::IsPlayerRidingTrain);
		//addHookedOption("Punish The Guilty", &PlayerSelf_f::BossMode, 0);
		//addHookedOption("Parachute Smoke", &PlayerSelf_f::ToggleParachuteSmoke);
		//addHookedOption("Get Parachute State", &PlayerSelf_f::GetParachuteState);
		//addHookedOption("Max Armor", &Peds_f::GiveMaxArmor);
		//addHookedOption("Max Health", &Peds_f::GiveMaxHealth);
		//addHookedOption("Apply Damage", &Peds_f::ApplyDamageToPed);
		//addHookedOption("Slingshot", &Vehicles_f::Slingshot, 0);
		
		// Player Self -> Toggles
		addMenu("Player Toggles", MenuPlayerSelfToggles, MenuPlayerSelf);
		addHookedOption("God Mode", &PlayerSelf_f::ToggleGodMode, 0);
		addHookedOption("< Wanted Level >", &PlayerSelf_f::ToggleWantedLevel, 0);
		addHookedOption("Invisibility", &PlayerSelf_f::ToggleInvisiblePlayer);
		addHookedOption("Heat Vision", &PlayerSelf_f::ToggleHeatVision);
		addHookedOption("Night Vision", &PlayerSelf_f::ToggleNightvision);
		addHookedOption("Explosive Melee", &Weapons_f::WeaponsAmmoExplosiveMelee);
		addHookedOption("Fire Feet", &PlayerSelf_f::FireFeet);
		addHookedOption("Super Jump", &PlayerSelf_f::ToggleSuperJump);
		addHookedOption("Super Run", &PlayerSelf_f::ToggleSuperRun);
		//addHookedOption("Super Swim", &PlayerSelf_f::ToggleSuperSwim);
		//addHookedOption("Flying Mode", Peds_f::ToggleFlyMode);
		addHookedOption("< Mobile Radio >", &PlayerSelf_f::ToggleMobileRadio);
		//addHookedOption("Get Aimed Target Info", &PlayerSelf_f::GetAimedEntity);
		
		

		// SOME FOR TESTING
		//addOption("Sprint Time");
		//addOption("Superman Mode");
		//addOption("Magic Carpet");
		//addHookedOption("Bleeding", &Peds_f::TogglePedBlood);
		//addHookedOption("Tennis Mode", &PlayerSelf_f::ToggleTennisMode);
		//addOption("Forcefield");
		//addHookedOption("Police Officer", &Peds_f::TogglePedIsCop);
		//addHookedOption("Motion Blur", &Peds_f::TogglePedIsBlurred);
		//addHookedOption("Draw Light", &Drawing_f::DrawLight);
		//addHookedOption("Long Fall Boots", &PlayerSelf_f::ToggleLongFallBoots);// BASICALLY GODMODE
		//addHookedOption("Drunk", &PlayerSelf_f::ToggleDrunk);
		//addHookedOption("High", &PlayerSelf_f::ToggleHigh);
		//addHookedOption("Die In Vehicle", &PlayerSelf_f::TogglePedCanDieInVehicle);
		//addHookedOption("Drown In Water", &Peds_f::ToggleCanPedDrownInWater);
		//addHookedOption("Drown In Vehicle", &Peds_f::ToggleCanPedDrownInVehicle);

		
		// Player Self -> Time Cycle Modifier
		addMenu("Time Cycle Modifier", MenuPlayerSelfTimeCycle, MenuPlayerSelf);
		addHookedOption("Increase Effect", &Misc_f::IncreaseTimeCycleStrength);
		addHookedOption("Decrease Effect", &Misc_f::DecreaseTimeCycleStrength);
		addHookedOption("Reset Effect", &Misc_f::ResetTimeCycleStrength);
		addHookedOption("Stop Time Cycle", &Misc_f::StopTimeCycle);
		addOption("");
		//addHookedOption("Input Custom", &System_f::Keyboard_f::ToggleKeyboard);
		//addHookedOption("Random", &Misc_f::TimeCycleModifier, 0);
		addHookedOption("BlackOut", &Misc_f::TimeCycleModifier, 0);
		addHookedOption("Camera Black & White", &Misc_f::TimeCycleModifier, 1);
		addHookedOption("Camera Security Fuzzy", &Misc_f::TimeCycleModifier, 2);
		addHookedOption("Chop", &Misc_f::TimeCycleModifier, 3);
		addHookedOption("Cinema 1", &Misc_f::TimeCycleModifier, 4);
		addHookedOption("Cops Splash", &Misc_f::TimeCycleModifier, 5);
		addHookedOption("Crane Cam", &Misc_f::TimeCycleModifier, 6);
		addHookedOption("Damage", &Misc_f::TimeCycleModifier, 7);
		addHookedOption("Death", &Misc_f::TimeCycleModifier, 8);
		addHookedOption("Don't Taze Me Bro 1", &Misc_f::TimeCycleModifier, 9);
		addHookedOption("Drugged Driving 3", &Misc_f::TimeCycleModifier, 10);
		addHookedOption("Drug Dead Man", &Misc_f::TimeCycleModifier, 11);
		addHookedOption("Drugged Flying 3", &Misc_f::TimeCycleModifier, 12);
		addHookedOption("Drugged Wobbly", &Misc_f::TimeCycleModifier, 13);
		addHookedOption("Drunk", &Misc_f::TimeCycleModifier, 14);
		addHookedOption("Dying", &Misc_f::TimeCycleModifier, 15);
		addHookedOption("Eye In The Sky", &Misc_f::TimeCycleModifier, 16);
		addHookedOption("Huff Gasoline", &Misc_f::TimeCycleModifier, 36);
		addHookedOption("Prologue Ending Fog", &Misc_f::TimeCycleModifier, 17);
		addHookedOption("Prologue Shootout 1", &Misc_f::TimeCycleModifier, 18);
		addHookedOption("Prologue Shootout 2", &Misc_f::TimeCycleModifier, 19);
		addHookedOption("Secret Camera", &Misc_f::TimeCycleModifier, 20);
		addHookedOption("Stoned", &Misc_f::TimeCycleModifier, 21);
		addHookedOption("Sunglasses", &Misc_f::TimeCycleModifier, 22);
		addHookedOption("Telescope", &Misc_f::TimeCycleModifier, 23);
		addHookedOption("Traffic Skycam", &Misc_f::TimeCycleModifier, 24);
		addHookedOption("UFO", &Misc_f::TimeCycleModifier, 25);
		addHookedOption("UFO Deathray", &Misc_f::TimeCycleModifier, 26);
		addHookedOption("Underwater Deep", &Misc_f::TimeCycleModifier, 27);

		// Player Self -> Items
		//addMenu("Stuff Menu", MenuPlayerSelfItems, MenuPlayerSelf);
		//addHookedOption("Max Armor", &PlayerSelf_f::GiveMaxArmor);
		//addHookedOption("Max Health", &PlayerSelf_f::GiveMaxHealth);
		
		// Player Self -> Change Name
		addMenu("Change Name", MenuPlayerSelfChangeName, MenuPlayerSelf);
		//addHookedOption("Input Custom", &PlayerSelf_f::ChangePlayerName, 0);
		//addHookedOption("Color Cycle Toggle", &PlayerSelf_f::ChangeNameMultiColor);
		addOption("Random", &PlayerSelf_f::ChangePlayerName, 2);
		addOption("Clone From Lobby", &PlayerSelf_f::ChangePlayerName, 3);
		addHookedOption("Default PSN", &PlayerSelf_f::ChangePlayerName, 4);
		addHookedOption("iLLiCiT", &PlayerSelf_f::ChangePlayerName, 5);
		addHookedOption("ps3dg.com", &PlayerSelf_f::ChangePlayerName, 12);
		addHookedOption("ALL EMPTY SPACES", &PlayerSelf_f::ChangePlayerName, 6);
		addHookedOption("**Invalid**", &PlayerSelf_f::ChangePlayerName, 7);
		addHookedOption("Rockstar", &PlayerSelf_f::ChangePlayerName, 8);
		addHookedOption("Rockstar Games", &PlayerSelf_f::ChangePlayerName, 9);
		addHookedOption("Rockstar North", &PlayerSelf_f::ChangePlayerName, 10);
		addHookedOption("Sony Moderator", &PlayerSelf_f::ChangePlayerName, 11);
		
		// Player Self -> Change Outfit
		//addMenu("Change Outfit", MenuPlayerSelfOutfit, MenuPlayerSelf);
		//addHookedOption("Input Custom", &Keyboard_OSK::ToggleKeyboard);
		//addOption("Police Officer");
		//addOption("Fireman");

		// Player Self -> Change Model
		addMenu("Change Model", MenuPlayerSelfModel, MenuPlayerSelf);
		addHookedOption("Input Custom", &Models_f::ChangeModel, 0);
		//addOption("Clone Another Player");
		//addOption("Default MP Characters", &openSub,MenuPlayerSelfModelMP);
		addOption("Animals", &openSub,MenuPlayerSelfModelAnimals);
		addOption("Story Mode Characters", &openSub, MenuPlayerSelfModelStoryMode);
		//addOption("Male Peds", &openSub, MenuPlayerSelfModelMalePeds);
		//addOption("Female Peds", &openSub, MenuPlayerSelfModelFemalePeds);
		addOption("Police & Emergency", &openSub, MenuPlayerSelfModelPolice);
		addHookedOption("Strippers & Hookers", &openSub, MenuPlayerSelfModelStrippers);
		//addOption("Glitch Characters", &openSub, MenuPlayerSelfModelGlitch);

		// Player Self -> Change Model -> Animals
		addMenu("Animals", MenuPlayerSelfModelAnimals, MenuPlayerSelfModel);
		addHookedOption("Boar", &Models_f::ChangeModel, 201);
		//addMenuTextFunction("Boar", );
		
		addHookedOption("Chickenhawk", &Models_f::ChangeModel, 202);
		addHookedOption("Chimp", &Models_f::ChangeModel, 203);
		//addHookedOption("Chop", &Models_f::ChangeModel, 204);
		addHookedOption("Cormorant", &Models_f::ChangeModel, 205);
		addHookedOption("Cow", &Models_f::ChangeModel, 206);
		addHookedOption("Coyote", &Models_f::ChangeModel, 207);
		addHookedOption("Crow", &Models_f::ChangeModel, 208);
		addHookedOption("Deer", &Models_f::ChangeModel, 209);
		addHookedOption("Fish (Dies Instantly)", &Models_f::ChangeModel, 210);
		addHookedOption("Hen", &Models_f::ChangeModel, 211);
		//addHookedOption("Husky", &Models_f::ChangeModel, 212);
		//addHookedOption("Mountain Lion", &Models_f::ChangeModel, 213);
		addHookedOption("Pig", &Models_f::ChangeModel, 214);
		addHookedOption("Pigeon", &Models_f::ChangeModel, 215);
		addHookedOption("Rat", &Models_f::ChangeModel, 216);
		//addHookedOption("Retriever", &Models_f::ChangeModel, 217);
		addHookedOption("Rhesus Monkey", &Models_f::ChangeModel, 218);
		//addHookedOption("Rottweiler", &Models_f::ChangeModel, 219);
		addHookedOption("Seagull", &Models_f::ChangeModel, 220);
		//addHookedOption("Shark", &Models_f::ChangeModel, 221);
		//addHookedOption("Shepherd", &Models_f::ChangeModel, 222);

		// Player Self -> Change Model -> Story Mode
		addMenu("Story Mode Characters", MenuPlayerSelfModelStoryMode, MenuPlayerSelfModel);
		addHookedOption("Michael", &Models_f::ChangeModel, 301);
		addHookedOption("Trevor", &Models_f::ChangeModel, 302);
		addHookedOption("Franklin", &Models_f::ChangeModel, 303);
		//addHookedOption("Dr. Friedlander", &Models_f::ChangeModel, 304);
		addHookedOption("Lamar", &Models_f::ChangeModel, 305);
		addHookedOption("Lester", &Models_f::ChangeModel, 306);

		// Player Self -> Change Model -> Male Peds
		//addMenu("Male Peds", MenuPlayerSelfModelMalePeds, MenuPlayerSelfModel);

		// Player Self -> Change Model -> Female Peds
		//addMenu("Female Peds", MenuPlayerSelfModelFemalePeds, MenuPlayerSelfModel);

		// Player Self -> Change Model -> Police
		addMenu("Police & Emergency", MenuPlayerSelfModelPolice, MenuPlayerSelfModel);
		addHookedOption("Army Mechanic", &Models_f::ChangeModel, 624);
		//addHookedOption("Cop Local", &Models_f::ChangeModel, 603);//DOUBLE WITH SHERIFF MALE
		//addHookedOption("Ex-Army Dude", &Models_f::ChangeModel, 623);
		//addHookedOption("FIB Architect", &Models_f::ChangeModel, 613);
		//addHookedOption("FIB Mugger", &Models_f::ChangeModel, 614);
		addHookedOption("FIB Office 1", &Models_f::ChangeModel, 611);
		//addHookedOption("FIB Office 2", &Models_f::ChangeModel, 612);
		addHookedOption("Fireman", &Models_f::ChangeModel, 601);
		addHookedOption("Highway Cop Male", &Models_f::ChangeModel, 607);
		addHookedOption("Local Cop Female", &Models_f::ChangeModel, 604);
		addHookedOption("Local Cop Male", &Models_f::ChangeModel, 606);
		addHookedOption("Marine Master Sergeant", &Models_f::ChangeModel, 619);
		//addHookedOption("Marine Private 1", &Models_f::ChangeModel, 617);
		//addHookedOption("Marine Private 2", &Models_f::ChangeModel, 618);
		//addHookedOption("Marine Private 3", &Models_f::ChangeModel, 622);
		//addHookedOption("Marine Private 4", &Models_f::ChangeModel, 620);
		//addHookedOption("Marine Shirtless", &Models_f::ChangeModel, 621);
		addHookedOption("Military Bum", &Models_f::ChangeModel, 625);
		addHookedOption("Paramedic", &Models_f::ChangeModel, 602);
		addHookedOption("Security Guard", &Models_f::ChangeModel, 615);
		//addHookedOption("Sheriff Female", &Models_f::ChangeModel, 608);
		//addHookedOption("Sheriff Male", &Models_f::ChangeModel, 609);
		//addHookedOption("Sheriff Male Snow", &Models_f::ChangeModel, 605);
		//addHookedOption("mp_m_fibsec_01", &Models_f::ChangeModel, 610);//FREEZES
		//addHookedOption("comp_peds_marine", &Models_f::ChangeModel, 616);//FREEZES

		// Player Self -> Change Model -> Strippers
		addMenu("Strippers & Hookers", MenuPlayerSelfModelStrippers, MenuPlayerSelfModel);
		//addHookedOption("Dead Hooker", &Models_f::ChangeModel, 703);
		//addHookedOption("mp_f_stripperlite", &Models_f::ChangeModel, 704);//FREEZES
		addHookedOption("Hooker 1", &Models_f::ChangeModel, 705);
		//addHookedOption("Hooker 2", &Models_f::ChangeModel, 706);
		//addHookedOption("Hooker 3", &Models_f::ChangeModel, 707);
		addHookedOption("Stripper 1", &Models_f::ChangeModel, 701);
		//addHookedOption("Stripper 2", &Models_f::ChangeModel, 702);
		//addHookedOption("Stripper 3", &Models_f::ChangeModel, 708);
		//addHookedOption("Stripper 4", &Models_f::ChangeModel, 709);
		//addHookedOption("Stripper 5", &Models_f::ChangeModel, 710);

		// Player Self -> Change Model -> Glitch
		//addMenu("Glitch Characters", MenuPlayerSelfModelGlitch, MenuPlayerSelfModel);

		// Player Self -> Change Model -> Default MP
		//addMenu("Default MP Characters", MenuPlayerSelfModelMP, MenuPlayerSelfModel);
		//addHookedOption("Female", &Models_f::ChangeModel, 802);
		//addHookedOption("Male", &Models_f::ChangeModel, 801);

		// Player Self -> Phone
		addMenu("Cell Phone Options", MenuPlayerSelfPhone, MenuPlayerSelf);
		addHookedOption("Open Prologue Phone", &PlayerSelf_f::CreatePhone, 4);
		addHookedOption("Talk On Prologue Phone", &PlayerSelf_f::UsePhone, 4);
		//addHookedOption("Open Franklin's Phone", &PlayerSelf_f::CreatePhone, 2);
		//addHookedOption("Talk On Franklin's Phone", &PlayerSelf_f::UsePhone, 2);
		//addHookedOption("Open Michael's Phone", &PlayerSelf_f::CreatePhone, 0);
		//addHookedOption("Talk On Michael's Phone", &PlayerSelf_f::UsePhone, 0);
		//addHookedOption("Open Trevor's Phone", &PlayerSelf_f::CreatePhone, 1);
		//addHookedOption("Talk On Trevor's Phone", &PlayerSelf_f::UsePhone, 1);
		addHookedOption("Close Phone", &PlayerSelf_f::DestroyPhone);
		//addHookedOption("Check Phone Stats", &PlayerSelf_f::GetPhoneInfo);

		// Player Self -> Weapons
		addMenu("Weapons", MenuWeapons, MenuPlayerSelf);
		//addOption("Weapon Manager", &openSub, MenuWeaponsManager);
		addHookedOption("Give All Weapons", &Weapons_f::WeaponsGiveAll, 99);
		addHookedOption("Take All Weapons", &Weapons_f::WeaponsTakeAll, 99);
		//addHookedOption("Infinite Ammo", &Weapons_f::ToggleInfAmmo, 99);
		addHookedOption("Explosive Bullets", &Weapons_f::WeaponsAmmoExplosive);
		addHookedOption("Fire Bullets", &Weapons_f::WeaponsAmmoFire);
		//addOption("Change Bullet Type");
		//addOption("Change Bullet Impact");
		//addOption("Change Bullet Attachment");
		//addOption("One Shot Kill");
		//addHookedOption("Laser Sight", &Misc_f::ToggleLaserSight);

		// Player Self -> Weapons -> Manager
		//addMenu("Weapon Manager", MenuWeaponsManager, MenuWeapons);
		//addOption("Normal Weapons", &openSub, MenuWeaponsManagerNormal);
		//addOption("DLC Weapons", &openSub, MenuWeaponsManagerDLC);
		//addOption("DLC Weapons Other", &openSub, MenuWeaponsManagerDLCOther);
		//addOption("Gadgets", &openSub, MenuWeaponsManagerGadgets);
		//addOption("Not Actually Weapons", &openSub, MenuWeaponsManagerOther);

		// Player Self -> Weapons -> Normal
		//addMenu("Normal Weapons", MenuWeaponsManagerNormal, MenuWeaponsManager);
		/*
		addHookedOption("Advanced Rifle", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_ADVANCEDRIFLE);
		addHookedOption("AP Pistol", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_APPISTOL);
		addHookedOption("Assault Rifle", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_ASSAULTRIFLE);
		addHookedOption("Assault Shotgun", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_ASSAULTSHOTGUN);
		addHookedOption("Assault SMG", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_ASSAULTSMG);
		addHookedOption("Baseball", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_BALL);
		addHookedOption("Bat", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_BAT);
		addHookedOption("Briefcase", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_BRIEFCASE);
		addHookedOption("Briefcase 2", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_BRIEFCASE_02);
		addHookedOption("Bullpup Shotgun", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_BULLPUPSHOTGUN);
		addHookedOption("BZ Gas", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_BZGAS);
		addHookedOption("Carbine Rifle", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_CARBINERIFLE);
		addHookedOption("Combat MG", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_COMBATMG);
		addHookedOption("Combat Pistol", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_COMBATPISTOL);
		addHookedOption("Crowbar", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_CROWBAR);
		addHookedOption("Fire Extinguisher", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_FIREEXTINGUISHER);
		addHookedOption("Flare", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_FLARE);
		addHookedOption("Golf Club", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_GOLFCLUB);
		addHookedOption("Grenade", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_GRENADE);
		addHookedOption("Grenade Launcher", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_GRENADELAUNCHER);
		addHookedOption("Grenade Launcher Smoke", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_GRENADELAUNCHER_SMOKE);
		addHookedOption("Hammer", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_HAMMER);
		addHookedOption("Heavy Sniper", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_HEAVYSNIPER);
		addHookedOption("Knife", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_KNIFE);
		addHookedOption("MG", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_MG);
		addHookedOption("Micro SMG", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_MICROSMG);
		addHookedOption("Minigun", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_MINIGUN);
		addHookedOption("Molotov Cocktail", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_MOLOTOV);
		addHookedOption("Nightstick", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_NIGHTSTICK);
		addHookedOption("Gas Can", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_PETROLCAN);
		addHookedOption("Passenger Rocket", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_PASSENGER_ROCKET);
		addHookedOption("Pistol", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_PISTOL);
		addHookedOption("Pistol 50 Cal", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_PISTOL50);
		addHookedOption("Pump Shotgun", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_PUMPSHOTGUN);
		addHookedOption("RPG", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_RPG);
		addHookedOption("Sawn-Off Shotgun", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_SAWNOFFSHOTGUN);
		addHookedOption("SMG", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_SMG);
		addHookedOption("Smoke Grenade", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_SMOKEGRENADE);
		addHookedOption("Sniper Rifle", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_SNIPERRIFLE);
		addHookedOption("Sticky Bomb", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_STICKYBOMB);
		addHookedOption("Stinger", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_STINGER);
		addHookedOption("Stun Gun", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_STUNGUN);
		addHookedOption("Unarmed", &Weapons_f::WeaponsGiveOne, Hashes_Weapons::WEAPON_UNARMED);
		*/
		// Player Self -> Weapons -> DLC
		//addMenu("DLC Weapons", MenuWeaponsManagerDLC, MenuWeaponsManager);
		/*
		addHookedOption("Bottle", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_BOTTLE);
		addHookedOption("Bullpup Rifle", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_BULLPUPRIFLE);
		addHookedOption("Combat PDW", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_COMBATPDW);
		addHookedOption("Dagger", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_DAGGER);
		addHookedOption("Firework Launcher", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_FIREWORK);
		addHookedOption("Flare Gun", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_FLAREGUN);
		addHookedOption("Gusenburg", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_GUSENBERG);
		addHookedOption("Heavy Pistol", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_HEAVYPISTOL);
		addHookedOption("Heavy Shotgun", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_HEAVYSHOTGUN);
		addHookedOption("Homing Launcher", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_HOMINGLAUNCHER);
		addHookedOption("Knuckle Duster", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_KNUCKLE);
		addHookedOption("Marksman Pistol", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_MARKSMANPISTOL);
		addHookedOption("Marksman Rifle", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_MARKSMANRIFLE);
		addHookedOption("Musket", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_MUSKET);
		addHookedOption("Proximity Mine", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_PROXMINE);
		addHookedOption("Snowball", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_SNOWBALL);
		addHookedOption("SNS Pistol", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_SNSPISTOL);
		addHookedOption("Special Carbine", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_SPECIALCARBINE);
		addHookedOption("Vintage Pistol", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_VINTAGEPISTOL);
		*/
		// Player Self -> Weapons -> DLC -> Other
		//addMenu("Other DLC Weapons", MenuWeaponsManagerDLCOther, MenuWeaponsManager);
		/*
		addHookedOption("Garbage Bag", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_GARBAGEBAG);
		addHookedOption("Handcuffs", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_DLC::WEAPON_HANDCUFFS);
		*/
		// Player Self -> Weapons -> Gadgets
		//addMenu("Gadgets", MenuWeaponsManagerGadgets, MenuWeaponsManager);
		/*
		addHookedOption("DigiScanner", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Gadgets::WEAPON_DIGISCANNER);
		addHookedOption("Nightvision", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Gadgets::GADGET_NIGHTVISION);
		addHookedOption("Parachute", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Gadgets::GADGET_PARACHUTE);
		*/

		/*
		// Player Self -> Weapons -> Other
		addMenu("Not Actually Weapons", MenuWeaponsManagerOther, MenuWeaponsManager);
		addHookedOption("Airstrike Rocket", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_AIRSTRIKE_ROCKET);
		addHookedOption("Animal", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_ANIMAL);
		addHookedOption("Barbed Wire", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_BARBED_WIRE);
		addHookedOption("Bleeding", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_BLEEDING);
		addHookedOption("Cougar", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_COUGAR);
		addHookedOption("Drowning", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_DROWNING);
		addHookedOption("Drowning In Vehicle", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_DROWNING_IN_VEHICLE);
		addHookedOption("Electric Fence", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_ELECTRIC_FENCE);
		addHookedOption("Exhaustion", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_EXHAUSTION);
		addHookedOption("Explosion", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_EXPLOSION);
		addHookedOption("Fall", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_FALL);
		addHookedOption("Fire", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_FIRE);
		addHookedOption("Heli Crash", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_HELI_CRASH);
		addHookedOption("Hit By Water Cannon", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_HIT_BY_WATER_CANNON);
		addHookedOption("Rammed By Car", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_RAMMED_BY_CAR);
		addHookedOption("Remote Sniper", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_REMOTESNIPER);
		addHookedOption("Run Over By Car", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_RUN_OVER_BY_CAR);
		addHookedOption("Vehicle Rocket", &Weapons_f::WeaponsGiveOne, Hashes_Weapons_Other::WEAPON_VEHICLE_ROCKET);
		*/

		// Player Self -> Animations
		addMenu("Animation Editor", MenuPlayerSelfAnimations, MenuPlayerSelf);
		addOption("Animation Manager");
		//addHookedOption("Input Custom", &Keyboard_OSK::ToggleKeyboard);
		addHookedOption("Stop Animation", &Animations_f::StopAnimation);
		addHookedOption("Test Animation", &Animations_f::PlayAnimation);
		//addOption("Animals");
		//addOption("Dancing");
		//addOption("Faces");
		//addOption("Heist");
		//addOption("Misc");
		//addOption("Naughty");
		//addOption("Peds");
		//addOption("Sports");
		//addOption("Walking");
		//addOption("Unsorted");

		// Player Self -> Camera Options
		//addMenu("Camera Options", MenuPlayerSelfCamera, MenuPlayerSelf);
		//addOption("Reset Camera");
		//addOption("First Person View");

		// Player Self -> Explode
		// FIX OTHER PLAYERS LATER!!!
		//addMenu("Explosion Editor", MenuPlayerSelfExplode, MenuPlayerSelf);
		//addHookedOption("Input Custom", &Keyboard_OSK::ToggleKeyboard);
		/*
		addHookedOption("Grenade", &Peds_f::ExplodePlayerCustom, 0);
		addHookedOption("Grenade Launcher", &Peds_f::ExplodePlayerCustom, 1);
		addHookedOption("Sticky Bomb", &Peds_f::ExplodePlayerCustom, 2);
		addHookedOption("Molotov Cocktail", &Peds_f::ExplodePlayerCustom, 3);
		addHookedOption("Rocket", &Peds_f::ExplodePlayerCustom, 4);
		addHookedOption("Tank Shell", &Peds_f::ExplodePlayerCustom, 5);
		addHookedOption("Hi Octane", &Peds_f::ExplodePlayerCustom, 6);
		addHookedOption("Car", &Peds_f::ExplodePlayerCustom, 7);
		addHookedOption("Plane", &Peds_f::ExplodePlayerCustom, 8);
		addHookedOption("Gas Pump", &Peds_f::ExplodePlayerCustom, 9);
		addHookedOption("Bike", &Peds_f::ExplodePlayerCustom, 10);
		addHookedOption("Steam Directional", &Peds_f::ExplodePlayerCustom, 11);
		addHookedOption("Fire Directional", &Peds_f::ExplodePlayerCustom, 12);
		addHookedOption("Water Hydrant", &Peds_f::ExplodePlayerCustom, 13);
		addHookedOption("Gas Canister", &Peds_f::ExplodePlayerCustom, 14);
		addHookedOption("Boat", &Peds_f::ExplodePlayerCustom, 15);
		addHookedOption("Ship Destroy", &Peds_f::ExplodePlayerCustom, 16);
		addHookedOption("Truck", &Peds_f::ExplodePlayerCustom, 17);
		addHookedOption("Bullet", &Peds_f::ExplodePlayerCustom, 18);
		addHookedOption("Smoke Grenade Launcher", &Peds_f::ExplodePlayerCustom, 19);
		addHookedOption("Smoke Grenade", &Peds_f::ExplodePlayerCustom, 20);
		addHookedOption("BZ Gas", &Peds_f::ExplodePlayerCustom, 21);
		addHookedOption("Flare", &Peds_f::ExplodePlayerCustom, 22);
		addHookedOption("Gas Canister", &Peds_f::ExplodePlayerCustom, 23);
		addHookedOption("Fire Extinguisher", &Peds_f::ExplodePlayerCustom, 24);
		addHookedOption("Programmable AR", &Peds_f::ExplodePlayerCustom, 25);
		addHookedOption("Train", &Peds_f::ExplodePlayerCustom, 26);
		addHookedOption("Barrel", &Peds_f::ExplodePlayerCustom, 27);
		addHookedOption("Propane", &Peds_f::ExplodePlayerCustom, 28);
		addHookedOption("Blimp", &Peds_f::ExplodePlayerCustom, 29);
		addHookedOption("Fire Explode", &Peds_f::ExplodePlayerCustom, 30);
		addHookedOption("Tanker", &Peds_f::ExplodePlayerCustom, 31);
		addHookedOption("Plane Rocket", &Peds_f::ExplodePlayerCustom, 32);
		addHookedOption("Vehicle Bullet", &Peds_f::ExplodePlayerCustom, 33);
		addHookedOption("Gas Tank", &Peds_f::ExplodePlayerCustom, 34);
		addHookedOption("Firework", &Peds_f::ExplodePlayerCustom, 35);
		addHookedOption("Snowball", &Peds_f::ExplodePlayerCustom, 36);
		addHookedOption("Proximity Mine", &Peds_f::ExplodePlayerCustom, 37);
		addHookedOption("Valkyrie Cannon", &Peds_f::ExplodePlayerCustom, 38);
		addHookedOption("Glitch Steam", &Peds_f::ExplodePlayerCustom, 39);
		addHookedOption("Glitch Steam", &Peds_f::ExplodePlayerCustom, 40);
		addHookedOption("Glitch Attachment", &Peds_f::ExplodePlayerCustom, 41);
		*/
		
		// Player Self -> Adjust Multipliers
		//addMenu("Adjust Multipliers", MenuPlayerSelfMultipliers, MenuPlayerSelf);
		//addOption("Walk Speed");
		//addOption("Swim Speed");
		//-----------------------------------------------------------------------//
	
		//-----------------------------------------------------------------------//
		// Players All
		/*
		if (isCloudAvailable == 1 && NETWORK_GET_NUM_CONNECTED_PLAYERS() > 0)
		{
			addMenu("All Players", MenuPlayersAll, MenuMain);
			//for (int a = 0; a < 16; a++) 
			for (int a = 0; a < NETWORK_GET_NUM_CONNECTED_PLAYERS() + 1; a++) 
			{
				//UpdatePlayersMenu();
				aFollow = a;
				addOption();
			}
		}

		if (isCloudAvailable == 0 && NETWORK_GET_NUM_CONNECTED_PLAYERS() == 0)
		{
			addMenu("Solo Player", MenuPlayersAll, MenuMain);
			//for (int a = 0; a < 16; a++) 
			for (int a = 0; a < NETWORK_GET_NUM_CONNECTED_PLAYERS() + 1; a++) 
			{
				//UpdatePlayersMenu();
				aFollow = a;
				addOption();
			}
		}
		*/

		addMenu("All Players", MenuPlayersAll, MenuMain);
		//int PlayerMax = PlayerCount();
		//for (int i = 0; i <= PlayerMax; i++)
		for (int i = 0; i <= 15; i++)
		{
			addOption();
		}
		
		//-----------------------------------------------------------------------//
	
		//-----------------------------------------------------------------------//
		// Lobby
		addMenu("Lobby", MenuLobby, MenuMain);
		//addOption("Attachments");
		//addOption("Toggles", &openSub, MenuLobbyToggles);
		addHookedOption("Show Talking Players", &Network_f::ToggleTalkingPlayers);
		addOption("Talking Punishments", &openSub, MenuLobbyTalking);
		addOption("Talking Punishments Loop", &openSub, MenuLobbyTalkingLoops);
		//addHookedOption("Teleport To A Talking Player", &Lobby_f::TeleportToTalkingPlayer);
		addHookedOption("Teleport Lobby To Me", &Lobby_f::TeleportLobbyToMe);
		addHookedOption("Give All Weapons", &Lobby_f::GiveLobbyAllWeapons);
		addHookedOption("Take All Weapons", &Lobby_f::TakeLobbyAllWeapons);
		//addHookedOption("Spam Text Message", &Lobby_f::SendLobbyText);
		addHookedOption("Clone Lobby", &Lobby_f::CloneLobby);
		addHookedOption("Kick All Players", &Lobby_f::KickLobbyFromGame);
		addHookedOption("Disable All Tasks", &Lobby_f::ClearLobbyTasks);
		addHookedOption("< Explode >", &Lobby_f::ExplodeAllPlayers);
		addHookedOption("Clear Props", &Lobby_f::ClearLobbyProps);
		addHookedOption("Freeze All Players", &Lobby_f::FreezeLobby);
		//addHookedOption("Apply Damage", &Lobby_f::ApplyDamageToLobby);
		
		// Lobby -> Toggles
		//addMenu("Lobby Toggles", MenuLobbyToggles, MenuLobby);
		//addHookedOption("Clear Props", &Lobby_f::ClearLobbyProps);
		//addHookedOption("Freeze All Players", &Lobby_f::FreezeLobby);
		
		// Lobby -> Talking Punishments Single
		addMenu("Punish The Talking", MenuLobbyTalking, MenuLobby);
		addHookedOption("Earthquake (Snowball)", &Network_f::PunishTalkingPlayers, 1);
		addHookedOption("Explode Blimp", &Network_f::PunishTalkingPlayers, 2);
		addHookedOption("Fire Extinguisher", &Network_f::PunishTalkingPlayers, 3);
		addHookedOption("Flare", &Network_f::PunishTalkingPlayers, 8);
		addHookedOption("Molotov Cocktail", &Network_f::PunishTalkingPlayers, 9);
		addHookedOption("Smoke Grenade", &Network_f::PunishTalkingPlayers, 4);
		addHookedOption("Teleport To Random", &Network_f::PunishTalkingPlayers, 5);
		addHookedOption("Valkyrie Cannon", &Network_f::PunishTalkingPlayers, 6);
		addHookedOption("Water Hydrant", &Network_f::PunishTalkingPlayers, 7);
		
		// Lobby -> Talking Punishments Loops
		addMenu("Punish The Talking", MenuLobbyTalkingLoops, MenuLobby);
		addHookedOption("Earthquake (Snowball)", &Network_f::PunishTalkingPlayersLoop, 1);
		addHookedOption("Explode Blimp", &Network_f::PunishTalkingPlayersLoop, 2);
		addHookedOption("Fire Extinguisher", &Network_f::PunishTalkingPlayersLoop, 3);
		addHookedOption("Flare", &Network_f::PunishTalkingPlayersLoop, 8);
		addHookedOption("Molotov Cocktail", &Network_f::PunishTalkingPlayersLoop, 9);
		addHookedOption("Smoke Grenade", &Network_f::PunishTalkingPlayersLoop, 4);
		addHookedOption("Teleport To Random", &Network_f::PunishTalkingPlayersLoop, 5);
		addHookedOption("Valkyrie Cannon", &Network_f::PunishTalkingPlayersLoop, 6);
		addHookedOption("Water Hydrant", &Network_f::PunishTalkingPlayersLoop, 7);
		//-----------------------------------------------------------------------//
		
		
		//-----------------------------------------------------------------------//
		// Teleport
		addMenu("Teleport", MenuTeleport, MenuMain);
		//addHookedOption("Input Custom", &Keyboard_OSK::ToggleKeyboard);
		addHookedOption("Waypoint", &Teleport_f::TeleportToLocation, 002);
		addHookedOption("Random Location", &Teleport_f::TeleportToLocation, 001);
		//addHookedOption("Talking Player", &Teleport_f::TeleportToTalkingPlayer);
		addHookedOption("Nearest Vehicle Free Seat", &Teleport_f::TeleportToNearestVehicleAnySeat);
		//addHookedOption("Nearest Vehicle Driver", &Teleport_f::TeleportToNearestVehicle, -1);
		//addHookedOption("Nearest Vehicle Passenger", &Teleport_f::TeleportToNearestVehicle, 0);
		//addHookedOption("Nearest Vehicle Backseat L", &Teleport_f::TeleportToNearestVehicle, 1);
		//addHookedOption("Nearest Vehicle Backseat R", &Teleport_f::TeleportToNearestVehicle, 2);
		//addHookedOption("To Nearest Ped", &Teleport_f::TeleportToPlayer);
		//addHookedOption("Forward Short", &Teleport_f::TeleportForward, 1);
		//addHookedOption("Forward Long", &Teleport_f::TeleportForward, 2);
		//addHookedOption("Forward Super", &Teleport_f::TeleportForward, 3);
		//addHookedOption("Backward Short", &Teleport_f::TeleportBackward, 1);
		//addHookedOption("Backward Super", &Teleport_f::TeleportBackward, 3);
		addHookedOption("Up Short", &Teleport_f::TeleportUp);
		addHookedOption("Up Super", &Teleport_f::TeleportUpSuper);
		addOption("");
		addOption("Story Mode Locations", &openSub, MenuTeleportStoryMode);
		addOption("Inside Locations", &openSub, MenuTeleportInside);
		addOption("Outside Locations", &openSub, MenuTeleportOutside);
		addOption("Vehicle Garages", &openSub, MenuTeleportGarages);
		//addOption("Robbery Locations", &openSub, MenuTeleportRobbery);
		addOption("Helipads", &openSub, MenuTeleportHelipads);
		addOption("Medical Facilities", &openSub, MenuTeleportHospitals);
		addOption("Water Towers", &openSub, MenuTeleportWaterTowers);
		addOption("Sniper Locations", &openSub, MenuTeleportSniper);
		//addOption("IPL Locations", &openSub, MenuTeleportIPL);
		addOption("Glitch Locations", &openSub, MenuTeleportGlitch);
		addOption("Other Locations", &openSub, MenuTeleportOther);

		// Story Mode Locations
		addMenu("Story Mode Locations", MenuTeleportStoryMode, MenuTeleport);
		addHookedOption("Bank Vault", &Teleport_f::TeleportToLocation, 101);
		addHookedOption("Franklins Aunts House", &Teleport_f::TeleportToLocation, 102);
		addHookedOption("Franklins Bedroom", &Teleport_f::TeleportToLocation, 103);
		addHookedOption("Franklins New House", &Teleport_f::TeleportToLocation, 104);
		addHookedOption("Franklins Old House", &Teleport_f::TeleportToLocation, 105);
		addHookedOption("Lesters House", &Teleport_f::TeleportToLocation, 106);
		addHookedOption("Michaels House", &Teleport_f::TeleportToLocation, 107);
		addHookedOption("Prologue Start Point", &Teleport_f::TeleportToLocation, 108);
		addHookedOption("Trevors House", &Teleport_f::TeleportToLocation, 109);
		addHookedOption("Trevors Meth Lab", &Teleport_f::TeleportToLocation, 110);
		addHookedOption("Trevors Office", &Teleport_f::TeleportToLocation, 111);
		addHookedOption("Wayne's Cousins House", &Teleport_f::TeleportToLocation, 112);
		

		// Inside Locations
		addMenu("Inside Locations", MenuTeleportInside, MenuTeleport);
		addHookedOption("400K Garage", &Teleport_f::TeleportToLocation, 201);
		addHookedOption("Airport Terminal", &Teleport_f::TeleportToLocation, 202);
		addHookedOption("Blaine County Bank", &Teleport_f::TeleportToLocation, 203);
		addHookedOption("Casino", &Teleport_f::TeleportToLocation, 216);
		addHookedOption("FIB Building Inside", &Teleport_f::TeleportToLocation, 204);
		addHookedOption("Fleeca Bank", &Teleport_f::TeleportToLocation, 205);
		addHookedOption("Gun Range City", &Teleport_f::TeleportToLocation, 206);
		addHookedOption("Gun Range Ghetto", &Teleport_f::TeleportToLocation, 207);
		//addHookedOption("House 1", &Teleport_f::TeleportToLocation, 208);
		addHookedOption("Humane Research Lab 1", &Teleport_f::TeleportToLocation, 209);
		addHookedOption("Humane Research Lab 2", &Teleport_f::TeleportToLocation, 210);
		addHookedOption("IAA Building", &Teleport_f::TeleportToLocation, 211);
		addHookedOption("IOU Tower", &Teleport_f::TeleportToLocation, 212);
		addHookedOption("Janitors Apt", &Teleport_f::TeleportToLocation, 213);
		addHookedOption("Lesters House", &Teleport_f::TeleportToLocation, 216);
		addHookedOption("Lesters Warehouse", &Teleport_f::TeleportToLocation, 217);
		addHookedOption("Police Station", &Teleport_f::TeleportToLocation, 214);
		addHookedOption("Prison Cell", &Teleport_f::TeleportToLocation, 215);

		// Outside Locations
		addMenu("Outside Locations", MenuTeleportOutside, MenuTeleport);
		addHookedOption("400K Apartment", &Teleport_f::TeleportToLocation, 301);
		addHookedOption("400K Apartment Roof", &Teleport_f::TeleportToLocation, 302);
		addHookedOption("Airport", &Teleport_f::TeleportToLocation, 303);
		addHookedOption("ATM #1", &Teleport_f::TeleportToLocation, 350);
		addHookedOption("Bigfoot", &Teleport_f::TeleportToLocation, 348);
		addHookedOption("Beach Island", &Teleport_f::TeleportToLocation, 304);
		addHookedOption("Cannibal Camp", &Teleport_f::TeleportToLocation, 305);
		addHookedOption("Cannibal Camp Mountain", &Teleport_f::TeleportToLocation, 306);
		addHookedOption("Cannibal Camp Roof", &Teleport_f::TeleportToLocation, 307);
		//addHookedOption("Cherry Popper Stand", &Teleport_f::TeleportToLocation, 308);
		addHookedOption("Del Perro Pier", &Teleport_f::TeleportToLocation, 309);
		addHookedOption("Dirtbike Trail", &Teleport_f::TeleportToLocation, 310);
		addHookedOption("Far Island", &Teleport_f::TeleportToLocation, 311);
		addHookedOption("Ferris Wheel In Line", &Teleport_f::TeleportToLocation, 312);
		addHookedOption("Ferris Wheel Center", &Teleport_f::TeleportToLocation, 313);
		addHookedOption("Ferris Wheel Top", &Teleport_f::TeleportToLocation, 314);
		addHookedOption("FIB Building Roof", &Teleport_f::TeleportToLocation, 315);
		addHookedOption("Fort Zancudo", &Teleport_f::TeleportToLocation, 316);
		//addHookedOption("Gifts At The Pier", &Teleport_f::TeleportToLocation, 317);
		addHookedOption("Grapeseed Airfield", &Teleport_f::TeleportToLocation, 318);
		addHookedOption("IAA Building Roof", &Teleport_f::TeleportToLocation, 319);
		addHookedOption("Impound Lot", &Teleport_f::TeleportToLocation, 320);
		addHookedOption("Lesters House", &Teleport_f::TeleportToLocation, 348);
		addHookedOption("Lesters Warehouse", &Teleport_f::TeleportToLocation, 349);
		addHookedOption("LSPD Parking lot", &Teleport_f::TeleportToLocation, 321);
		addHookedOption("Maze Bank Arena Roof", &Teleport_f::TeleportToLocation, 322);
		addHookedOption("Movie Theater Entrance", &Teleport_f::TeleportToLocation, 323);
		addHookedOption("Mors Mutual Insurance", &Teleport_f::TeleportToLocation, 324);
		addHookedOption("Mount Chiliad", &Teleport_f::TeleportToLocation, 325);
		//addHookedOption("MugShots Stand", &Teleport_f::TeleportToLocation, 326);
		addHookedOption("Paleto Bay", &Teleport_f::TeleportToLocation, 327);
		addHookedOption("Police Parking Roof", &Teleport_f::TeleportToLocation, 328);
		addHookedOption("Police Station", &Teleport_f::TeleportToLocation, 329);
		addHookedOption("Prison Yard", &Teleport_f::TeleportToLocation, 349);
		addHookedOption("RollerCoaster In Line", &Teleport_f::TeleportToLocation, 330);
		addHookedOption("RollerCoaster Top Hill", &Teleport_f::TeleportToLocation, 331);
		addHookedOption("Trevors Airfield", &Teleport_f::TeleportToLocation, 332);
		addHookedOption("Tunnel Under Train Station", &Teleport_f::TeleportToLocation, 333);
		addHookedOption("Tutorial Tennis Court", &Teleport_f::TeleportToLocation, 334);
		addHookedOption("Vanilla Unicorn", &Teleport_f::TeleportToLocation, 348);
		addHookedOption("Vending Machines Pier", &Teleport_f::TeleportToLocation, 335);
		addHookedOption("Vespucci Beach", &Teleport_f::TeleportToLocation, 336);
		addHookedOption("Vinewood Sign", &Teleport_f::TeleportToLocation, 337);
		//addHookedOption("Vinewood Letter V", &Teleport_f::TeleportToLocation, 338);
		//addHookedOption("Vinewood Letter I", &Teleport_f::TeleportToLocation, 339);
		//addHookedOption("Vinewood Letter N", &Teleport_f::TeleportToLocation, 340);
		//addHookedOption("Vinewood Letter E", &Teleport_f::TeleportToLocation, 341);
		//addHookedOption("Vinewood Letter W", &Teleport_f::TeleportToLocation, 342);
		//addHookedOption("Vinewood 1st Letter O", &Teleport_f::TeleportToLocation, 343);
		//addHookedOption("Vinewood 2nd Letter O", &Teleport_f::TeleportToLocation, 344);
		//addHookedOption("Vinewood Letter D", &Teleport_f::TeleportToLocation, 345);
		addHookedOption("Waterfall", &Teleport_f::TeleportToLocation, 346);
		addHookedOption("Zancudo River", &Teleport_f::TeleportToLocation, 347);
		

		// Vehicle Garages
		addMenu("Vehicle Garages", MenuTeleportGarages, MenuTeleport);
		addHookedOption("Beekers Garage", &Teleport_f::TeleportToLocation, 401);
		addHookedOption("LS Customs Airport", &Teleport_f::TeleportToLocation, 402);
		addHookedOption("LS Customs Burton", &Teleport_f::TeleportToLocation, 403);
		addHookedOption("LS Customs Desert", &Teleport_f::TeleportToLocation, 404);
		addHookedOption("LS Customs LaMesa", &Teleport_f::TeleportToLocation, 405);

		/*
		// Robbery Locations
		addMenu("Robbery Locations", MenuTeleportRobbery, MenuTeleport);
		addHookedOption("Gas Station El Burro", &Teleport_f::TeleportToLocation, 1101);
		addHookedOption("Grand Senora Freeway", &Teleport_f::TeleportToLocation, 1102);
		addHookedOption("Grapeseed Main St", &Teleport_f::TeleportToLocation, 1103);
		addHookedOption("Great Ocean Highway", &Teleport_f::TeleportToLocation, 1104);
		addHookedOption("LTDGasoline E Mirror", &Teleport_f::TeleportToLocation, 1105);
		addHookedOption("LTDGasoline Grove St", &Teleport_f::TeleportToLocation, 1106);
		addHookedOption("LTDGasoline Lindsay", &Teleport_f::TeleportToLocation, 1107);
		addHookedOption("LTDGasoline Tongva Dr", &Teleport_f::TeleportToLocation, 1108);
		addHookedOption("Robs Liquor El Rancho", &Teleport_f::TeleportToLocation, 1109);
		addHookedOption("Robs Liquor Prosperity", &Teleport_f::TeleportToLocation, 1110);
		addHookedOption("Robs Liquor SanAndreas", &Teleport_f::TeleportToLocation, 1111);
		addHookedOption("Route 68 Harmony", &Teleport_f::TeleportToLocation, 1112);
		addHookedOption("Route 68 Scoops", &Teleport_f::TeleportToLocation, 1113);
		addHookedOption("Supermarket Barbareno", &Teleport_f::TeleportToLocation, 1114);
		addHookedOption("Supermarket Clinton", &Teleport_f::TeleportToLocation, 1115);
		addHookedOption("Supermarket Ineseno", &Teleport_f::TeleportToLocation, 1116);
		addHookedOption("Supermarket Innocence", &Teleport_f::TeleportToLocation, 1117);
		addHookedOption("Supermarket Niland", &Teleport_f::TeleportToLocation, 1118);
		addHookedOption("Supermarket Senora", &Teleport_f::TeleportToLocation, 1119);
		addHookedOption("Supermarket Tataviam", &Teleport_f::TeleportToLocation, 1120);
		*/

		// Helipads
		addMenu("Helipads", MenuTeleportHelipads, MenuTeleport);
		addHookedOption("Emergency", &Teleport_f::TeleportToLocation, 501);
		addHookedOption("Hospital", &Teleport_f::TeleportToLocation, 502);
		addHookedOption("Maze Bank", &Teleport_f::TeleportToLocation, 503);
		addHookedOption("Police Station", &Teleport_f::TeleportToLocation, 504);
		addHookedOption("Unknown Helipad 1", &Teleport_f::TeleportToLocation, 505);
		addHookedOption("Unknown Helipad 2", &Teleport_f::TeleportToLocation, 506);
		

		// Hospitals & Medical
		addMenu("Medical Facilities", MenuTeleportHospitals, MenuTeleport);
		addHookedOption("Central LS Medical", &Teleport_f::TeleportToLocation, 601);
		addHookedOption("Mount Zonah Hospital", &Teleport_f::TeleportToLocation, 602);
		addHookedOption("Pillbox Hill Medical", &Teleport_f::TeleportToLocation, 603);
		addHookedOption("Sandy Shores Medical", &Teleport_f::TeleportToLocation, 604);
		addHookedOption("The Bay Care Center", &Teleport_f::TeleportToLocation, 605);
		

		// Water Towers
		addMenu("Water Towers", MenuTeleportWaterTowers, MenuTeleport);
		addHookedOption("Final Mission Water Tower", &Teleport_f::TeleportToLocation, 701);
		addHookedOption("La Mesa Water Tower", &Teleport_f::TeleportToLocation, 702);
		

		// Sniping Locations
		addMenu("Sniper Locations", MenuTeleportSniper, MenuTeleport);
		addHookedOption("Airport Tower", &Teleport_f::TeleportToLocation, 801);
		addHookedOption("Antenna", &Teleport_f::TeleportToLocation, 802);
		addHookedOption("Arcadius Business Center", &Teleport_f::TeleportToLocation, 803);
		addHookedOption("Building Wireframe", &Teleport_f::TeleportToLocation, 804);
		addHookedOption("Construction Crane 1", &Teleport_f::TeleportToLocation, 805);
		//addHookedOption("Construction Crane 2", &Teleport_f::TeleportToLocation, 806);
		//addHookedOption("Construction Crane 3", &Teleport_f::TeleportToLocation, 807);
		//addHookedOption("Construction Crane 4", &Teleport_f::TeleportToLocation, 808);
		////addHookedOption("Construction Crane 5", &Teleport_f::TeleportToLocation, 809);
		//addHookedOption("Construction Crane 6", &Teleport_f::TeleportToLocation, 810);
		//addHookedOption("Construction Crane 7", &Teleport_f::TeleportToLocation, 811);
		addHookedOption("Military Base Tower", &Teleport_f::TeleportToLocation, 812);
		

		// Glitch Locations
		addMenu("Glitch Locations", MenuTeleportGlitch, MenuTeleport);
		addHookedOption("Behind Games Area At Pier", &Teleport_f::TeleportToLocation, 901);
		//addHookedOption("Fort Zancudo Building 0101", &Teleport_f::TeleportToLocation, 902);
		//addHookedOption("Fort Zancudo Building 3499", &Teleport_f::TeleportToLocation, 903);
		//addHookedOption("Fort Zancudo Building A2", &Teleport_f::TeleportToLocation, 904);
		addHookedOption("Garage 3566 W Vinewood", &Teleport_f::TeleportToLocation, 905);
		addHookedOption("Pipe Down Cigars Inside", &Teleport_f::TeleportToLocation, 906);
		addHookedOption("Tunnel Under Pillbox", &Teleport_f::TeleportToLocation, 907);
		addHookedOption("Union Depository Building", &Teleport_f::TeleportToLocation, 908);
		//addHookedOption("Unknown Glitch Area 1", &Teleport_f::TeleportToLocation, 909);
		//addHookedOption("Unknown Glitch Area 2", &Teleport_f::TeleportToLocation, 910);
		//addHookedOption("Vesupucci House", &Teleport_f::TeleportToLocation, 911);
		

		// Other Locations
		addMenu("Other Locations", MenuTeleportOther, MenuTeleport);
		addHookedOption("Atmosphere", &Teleport_f::TeleportToLocation, 1001);
		addHookedOption("Maze Bank Clouds", &Teleport_f::TeleportToLocation, 1002);
		addHookedOption("Maze Bank Sky", &Teleport_f::TeleportToLocation, 1003);
		addHookedOption("Space", &Teleport_f::TeleportToLocation, 1004);
		//-----------------------------------------------------------------------//
		
		//-----------------------------------------------------------------------//
		// Vehicles
		addMenu("Vehicles", MenuVehicles, MenuMain);
		addOption("Spawn Vehicles", &openSub, MenuVehicleSpawn);
		addHookedOption("~r~Delete Last Vehicle", &Vehicles_f::DeleteLastSpawnedVehicle);
		addOption("Mod & Repair Shop", &openSub, MenuVehiclesEditVehicleModshop);
		addOption("Vehicle Manager", &openSub, MenuVehiclesManager);
		//addOption("Garage Editor");
		addOption("Toggles", &openSub, MenuVehiclesEditVehicleToggles);
		//addOption("Nearby Vehicles", &openSub, MenuVehiclesNearby);
		//addOption("Adjust Multipliers", &openSub, MenuVehiclesEditVehicleAdjustMultipliers);
		addOption("Turn Signals", &openSub, MenuVehiclesEditVehicleTurnSignals);
		//addOption("Clone Vehicle");
		
		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn
		addMenu("Spawn Vehicles", MenuVehicleSpawn, MenuVehicles);
		
		// Build Vehicle Class List Part 1
		const char* namesVehicleClasses[10] = { 
			"Bikes", 
			"Boats", 
			"Commercial", 
			"Compacts",
			"Coupes", 
			"Emergency", 
			"Helicopters",
			"Industrial",
			"Military",
			"Motorcycles" };

		for (int vclass = MenuVehicleSpawnBikes; vclass < MenuVehicleSpawnMuscle; vclass++)
		{
			addOption(namesVehicleClasses[vclass - MenuVehicleSpawnBikes], &openSub, vclass);
		}
		
		// Build Vehicle Class List Part 2
		const char* namesVehicleClasses2[10] = { 
			"Muscle", 
			"Off-Road", 
			"Planes", 
			"Sedans",
			"Service", 
			"Sports", 
			"Sports Classic",
			"Super",
			"SUVs",
			"Utility" };

		for (int vclass2 = MenuVehicleSpawnMuscle; vclass2 < MenuVehicleSpawnVans; vclass2++)
		{
			addOption(namesVehicleClasses2[vclass2 - MenuVehicleSpawnMuscle], &openSub, vclass2);
		}
		
		
		// Build Vehicle Class List Part 3
		const char* namesVehicleClasses3[3] = { 
			"Vans",
			"*Special*",
			"*Props*" };

		for (int vclass3 = MenuVehicleSpawnVans; vclass3 < MenuVehicleSpawnProps + 1; vclass3++)
		{
			addOption(namesVehicleClasses3[vclass3 - MenuVehicleSpawnVans], &openSub, vclass3);
		}

		//addOption("Custom Input", &Vehicles_f::SpawnVehicle, 0);
		//-------------------------------------------------------------------------------
		
		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Bikes
		addMenu("Class: Bikes", MenuVehicleSpawnBikes, MenuVehicleSpawn);
		
		// Build Bikes List
		const char* namesBikes[7] = { 
			"BMX", 
			"Cruiser", 
			"Endurex Race Bike", 
			"Fixter",
			"Scorcher", 
			"Tri-Cycles Race Bike", 
			"Whippet Race Bike" };

		for (int bike = 101; bike < 108; bike++)
		{
			addHookedOption(namesBikes[bike - 101], &Vehicles_f::SpawnVehicle, bike);
		}
		//-------------------------------------------------------------------------------
		
		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Boats
		addMenu("Class: Boats", MenuVehicleSpawnBoats, MenuVehicleSpawn);
		
		// Build Boat List Part 1
		const char* namesBoats[10] = { 
			"Dinghy", 
			"Dinghy 2-Seater", 
			"Dinghy (New)", 
			"Jetmax", 
			"Kraken", 
			"Marquis", 
			"Seashark (Speedophile)", 
			"Seashark (LifeGuard)", 
			"Speeder (DLC)", 
			"Squalo" };

		for (int boat = 201; boat < 211; boat++)
		{
			addHookedOption(namesBoats[boat - 201], &Vehicles_f::SpawnVehicle, boat);
		}
		
		// Build Boat List Part 2
		const char* namesBoats2[4] = { 
			"Submersible", 
			"Suntrap", 
			"Toro (DLC)", 
			"Tropic" };

		for (int boat2 = 211; boat2 < 215; boat2++)
		{
			addHookedOption(namesBoats2[boat2 - 211], &Vehicles_f::SpawnVehicle, boat2);
		}
		//-------------------------------------------------------------------------------
		
		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Commercial
		addMenu("Class: Commercial", MenuVehicleSpawnCommercial, MenuVehicleSpawn);
		
		// Build Commercial List
		const char* namesCommercial[10] = { 
			"Benson", 
			"Biff", 
			"Hauler", 
			"Mule", 
			"Mule (Drop Down)", 
			"Packer", 
			"Phantom", 
			"Pounder", 
			"Stockade", 
			"Stockade (Snowy)" };

		for (int comm = 301; comm < 311; comm++)
		{
			addHookedOption(namesCommercial[comm - 301], &Vehicles_f::SpawnVehicle, comm);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Compacts
		addMenu("Class: Compacts", MenuVehicleSpawnCompacts, MenuVehicleSpawn);
		
		// Build Compacts List
		const char* namesCompacts[6] = { 
			"Blista", 
			"Dilettante", 
			"Issa (C)", 
			"Panto (DLC)", 
			"Prairie", 
			"Rhapsody" };

		for (int comp = 401; comp < 407; comp++)
		{
			addHookedOption(namesCompacts[comp - 401], &Vehicles_f::SpawnVehicle, comp);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Coupes
		addMenu("Class: Coupes", MenuVehicleSpawnCoupes, MenuVehicleSpawn);
		
		// Build Coupes List Part 1
		const char* namesCoupes[10] = { 
			"Cognoscenti Cabrio", 
			"Exemplar", 
			"F620", 
			"Felon", 
			"Felon GT (C)", 
			"Jackal", 
			"Oracle", 
			"Oracle XS", 
			"Sentinel", 
			"Sentinel XS" };

		for (int coupe = 501; coupe < 511; coupe++)
		{
			addHookedOption(namesCoupes[coupe - 501], &Vehicles_f::SpawnVehicle, coupe);
		}

		
		// Build Coupes List Part 2
		const char* namesCoupes2[3] = { 
			"Windsor (DLC)", 
			"Zion XS", 
			"Zion XS (C)" };

		for (int coupe2 = 511; coupe2 < 514; coupe2++)
		{
			addHookedOption(namesCoupes2[coupe2 - 511], &Vehicles_f::SpawnVehicle, coupe2);
		}
		//-------------------------------------------------------------------------------
		

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Emergency
		addMenu("Class: Emergency", MenuVehicleSpawnEmergency, MenuVehicleSpawn);
		
		// Build Emergency List Part 1
		const char* namesEmergency[10] = { 
			"Air Ambulance", 
			"Ambulance", 
			"Cargobob (Medical)", 
			"FIB Buffalo", 
			"FIB Granger", 
			"Fire Truck", 
			"LifeGuard Blazer", 
			"LifeGuard Granger", 
			"Merryweather Patrol", 
			"Park Ranger" };

		for (int emrgncy = 601; emrgncy < 611; emrgncy++)
		{
			addHookedOption(namesEmergency[emrgncy - 601], &Vehicles_f::SpawnVehicle, emrgncy);
		}
		
		
		// Build Emergency List Part 2
		const char* namesEmergency2[10] = { 
			"Police Bike", 
			"Police Buffalo", 
			"Police Cruiser", 
			"Police Interceptor", 
			"Police Maverick", 
			"Police Rancher (Snowy)", 
			"Police Riot", 
			"Police Roadcruiser", 
			"Police Transporter", 
			"Police Prison Bus" };

		for (int emrgncy = 611; emrgncy < 621; emrgncy++)
		{
			addHookedOption(namesEmergency2[emrgncy - 611], &Vehicles_f::SpawnVehicle, emrgncy);
		}
		
		
		// Build Emergency List Part 3
		const char* namesEmergency3[4] = { 
			"Police Predator", 
			"Sheriff Cruiser", 
			"Sheriff Granger", 
			"Unmarked Cruiser" };

		for (int emrgncy = 621; emrgncy < 625; emrgncy++)
		{
			addHookedOption(namesEmergency3[emrgncy - 621], &Vehicles_f::SpawnVehicle, emrgncy);
		}
		//-------------------------------------------------------------------------------
		

		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Helicopters
		addMenu("Class: Helicopters", MenuVehicleSpawnHelicopters, MenuVehicleSpawn);
		
		// Build Helicopters List Part 1
		const char* namesHeli[10] = { 
			"Annihilator", 
			"Buzzard", 
			"Buzzard (Attack Chopper)", 
			"Cargobob", 
			"Cargobob (Trevor)", 
			"Frogger", 
			"Frogger (Trevor)", 
			"Maverick", 
			"Savage (DLC)", 
			"Skylift" };

		for (int heli = 701; heli < 711; heli++)
		{
			addHookedOption(namesHeli[heli - 701], &Vehicles_f::SpawnVehicle, heli);
		}
		
		// Build Helicopters List Part 2
		const char* namesHeli2[3] = { 
			"Swift (DLC)", 
			"Swift Deluxe (DLC)", 
			"Valkyrie (DLC)" };

		for (int heli2 = 711; heli2 < 714; heli2++)
		{
			addHookedOption(namesHeli2[heli2 - 711], &Vehicles_f::SpawnVehicle, heli2);
		}
		//-------------------------------------------------------------------------------
		

		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Industrial
		addMenu("Class: Industrial", MenuVehicleSpawnIndustrial, MenuVehicleSpawn);
		
		// Build Industrial List Part 1
		const char* namesIndustry[10] = { 
			"Bulldozer", 
			"Cutter", 
			"Dock Handler", 
			"Dump Truck", 
			"Flatbed", 
			"Guardian (DLC)", 
			"Mixer", 
			"Mixer (Wheels On Back)", 
			"Rubble", 
			"Tipper (6-Wheeler)" };

		for (int indus = 801; indus < 811; indus++)
		{
			addHookedOption(namesIndustry[indus - 801], &Vehicles_f::SpawnVehicle, indus);
		}
		
		// Build Industrial List Part 2
		const char* namesIndustry2[1] = { 
			"Tipper (10-Wheeler)" };

		for (int indus2 = 811; indus2 < 812; indus2++)
		{
			addHookedOption(namesIndustry2[indus2 - 811], &Vehicles_f::SpawnVehicle, indus2);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Military
		addMenu("Class: Military", MenuVehicleSpawnMilitary, MenuVehicleSpawn);
		
		const char* namesMilitary[5] = { 
			"Barracks", 
			"Barracks (Dark Camo)", 
			"Barracks (Semi)", 
			"Crusader", 
			"Rhino Tank" };

		for (int mil = 901; mil < 906; mil++)
		{
			addHookedOption(namesMilitary[mil - 901], &Vehicles_f::SpawnVehicle, mil);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Motorcycles
		addMenu("Class: Motorcycles", MenuVehicleSpawnMotorcycles, MenuVehicleSpawn);
		
		// Build Motorcycles List Part 1
		const char* namesCycles[10] = { 
			"Akuma", 
			"Bagger", 
			"Bati 801", 
			"Bati 801RR", 
			"Carbon RS", 
			"Daemon", 
			"Double T", 
			"Enduro (DLC)", 
			"Faggio", 
			"Hakuchou (DLC)" };

		for (int mcycle = 1001; mcycle < 1011; mcycle++)
		{
			addHookedOption(namesCycles[mcycle - 1001], &Vehicles_f::SpawnVehicle, mcycle);
		}
		
		
		// Build Motorcycles List Part 2
		const char* namesCycles2[10] = { 
			"Hexer", 
			"Innovation (DLC)", 
			"Lectro (DLC)", 
			"Nemesis", 
			"PCJ 600", 
			"Ruffian", 
			"Sanchez (Livery)", 
			"Sanchez (Paint)", 
			"Sovereign (DLC)", 
			"Thrust (DLC)" };

		for (int mcycle2 = 1011; mcycle2 < 1021; mcycle2++)
		{
			addHookedOption(namesCycles2[mcycle2 - 1011], &Vehicles_f::SpawnVehicle, mcycle2);
		}
		
		
		// Build Motorcycles List Part 3
		const char* namesCycles3[2] = { 
			"Vader", 
			"Vindicator (DLC)" };

		for (int mcycle3 = 1021; mcycle3 < 1023; mcycle3++)
		{
			addHookedOption(namesCycles3[mcycle3 - 1021], &Vehicles_f::SpawnVehicle, mcycle3);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Muscle
		addMenu("Class: Muscle", MenuVehicleSpawnMuscle, MenuVehicleSpawn);
		
		// Build Muscle List Part 1
		const char* namesMuscle[10] = { 
			"Blade (DLC)", 
			"Buccaneer", 
			"Chino (DLC)", 
			"Coquette BlackFin (DLC)", 
			"Dominator", 
			"Dominator (Pisswasser)", 
			"Duke O'Death", 
			"Dukes", 
			"Gauntlet", 
			"Gauntlet (Redwood)" };

		for (int muscle = 1101; muscle < 1111; muscle++)
		{
			addHookedOption(namesMuscle[muscle - 1101], &Vehicles_f::SpawnVehicle, muscle);
		}
		
		
		// Build Muscle List Part 2
		const char* namesMuscle2[10] = { 
			"Hotknife", 
			"Phoenix", 
			"Picador", 
			"Rat-Loader", 
			"Rat-Truck (DLC)", 
			"Ruiner", 
			"Sabre Turbo", 
			"Slamvan (DLC)", 
			"Slamvan Lost (DLC)", 
			"Stallion" };

		for (int muscle2 = 1111; muscle2 < 1121; muscle2++)
		{
			addHookedOption(namesMuscle2[muscle2 - 1111], &Vehicles_f::SpawnVehicle, muscle2);
		}
		
		
		// Build Muscle List Part 3
		const char* namesMuscle3[4] = { 
			"Stallion (Burger Shot)", 
			"Virgo (DLC)", 
			"Vigero", 
			"Voodoo (Rusty)" };

		for (int muscle3 = 1121; muscle3 < 1125; muscle3++)
		{
			addHookedOption(namesMuscle3[muscle3 - 1121], &Vehicles_f::SpawnVehicle, muscle3);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Off-Road
		addMenu("Class: Off-Road", MenuVehicleSpawnOffroad, MenuVehicleSpawn);
		
		// Build Off-Road List Part 1
		const char* namesOffRoad[10] = { 
			"BF Injection",
			"Bifta (DLC)",
			"Blazer",
			"Blazer (Hotrod)",
			"Bodhi",
			"Brawler (DLC)",
			"Dubsta 6x6 (DLC)",
			"Dune Buggy",
			"Dune Loader",
			"Insurgent (DLC)" };

		for (int offroad = 1201; offroad < 1211; offroad++)
		{
			addHookedOption(namesOffRoad[offroad - 1201], &Vehicles_f::SpawnVehicle, offroad);
		}
		
		
		// Build Off-Road List Part 2
		const char* namesOffRoad2[10] = {  
			"Insurgent Truck (DLC)",
			"Kalahari (DLC)",
			"Marshall",
			"Rancher XL",
			"Rancher XL (Snowy)",
			"Rebel (Clean)",
			"Rebel (Rusty)",
			"Sandking (2-Seater)",
			"Sandking (4-Seater)",
			"Space Docker" };

		for (int offroad2 = 1211; offroad2 < 1221; offroad2++)
		{
			addHookedOption(namesOffRoad2[offroad2 - 1211], &Vehicles_f::SpawnVehicle, offroad2);
		}
		
		
		// Build Off-Road List Part 3
		const char* namesOffRoad3[2] = { 
			"Technical (DLC)",
			"The Liberator (DLC)" };

		for (int offroad3 = 1221; offroad3 < 1223; offroad3++)
		{
			addHookedOption(namesOffRoad3[offroad3 - 1221], &Vehicles_f::SpawnVehicle, offroad3);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Planes
		addMenu("Class: Planes", MenuVehicleSpawnPlanes, MenuVehicleSpawn);
		
		// Build Planes List Part 1
		const char* namesPlanes[10] = { 
			"Atomic Blimp", 
			"Besra (DLC)", 
			"Cargo Plane", 
			"Cuban 800", 
			"Dodo", 
			"Duster", 
			"Hydra (DLC)", 
			"Jet", 
			"Luxor", 
			"Luxor Deluxe (DLC)" };

		for (int plane = 1301; plane < 1311; plane++)
		{
			addHookedOption(namesPlanes[plane - 1301], &Vehicles_f::SpawnVehicle, plane);
		}
		
		// Build Planes List Part 2
		const char* namesPlanes2[10] = { 
			"Mallard (Stunt Plane)", 
			"Mammatus", 
			"Miljet (DLC)", 
			"P-996 Lazer",
			"Shamal",
			"Titan",
			"Velum",
			"Velum 5-Seater (DLC)",
			"Vestra (DLC)",
			"Xero Blimp" };

		for (int plane2 = 1311; plane2 < 1321; plane2++)
		{
			addHookedOption(namesPlanes2[plane2 - 1311], &Vehicles_f::SpawnVehicle, plane2);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Sedans
		addMenu("Class: Sedans", MenuVehicleSpawnSedans, MenuVehicleSpawn);
		
		// Build Sedans List Part 1
		const char* namesSedans[10] = { 
			"Asea", 
			"Asea (Snowy)", 
			"Asterope", 
			"Emperor", 
			"Emperor (Rusty)", 
			"Emperor (Snowy)", 
			"Fugitive", 
			"Glendale (DLC)", 
			"Ingot", 
			"Intruder" };

		for (int sedan = 1401; sedan < 1411; sedan++)
		{
			addHookedOption(namesSedans[sedan - 1401], &Vehicles_f::SpawnVehicle, sedan);
		}
		
		
		// Build Sedans List Part 2
		const char* namesSedans2[10] = { 
			"Premier", 
			"Primo", 
			"Regina", 
			"Romero Hearse", 
			"Schafter", 
			"Stanier", 
			"Stratum", 
			"Stretch", 
			"Super Diamond", 
			"Surge" };

		for (int sedan2 = 1411; sedan2 < 1421; sedan2++)
		{
			addHookedOption(namesSedans2[sedan2 - 1411], &Vehicles_f::SpawnVehicle, sedan2);
		}
		
		
		// Build Sedans List Part 3
		const char* namesSedans3[3] = { 
			"Tailgater", 
			"Warrener (DLC)",
			"Washington" };

		for (int sedan3 = 1421; sedan3 < 1424; sedan3++)
		{
			addHookedOption(namesSedans3[sedan3 - 1421], &Vehicles_f::SpawnVehicle, sedan3);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Service
		addMenu("Class: Service", MenuVehicleSpawnService, MenuVehicleSpawn);
		
		// Build Service List
		const char* namesService[8] = { 
			"Airport Bus", 
			"City Bus", 
			"Dashound", 
			"Garbage Truck", 
			"Garbage Truck (Rusty)", 
			"Rental Shuttle Bus", 
			"Taxi", 
			"Tour Bus" };

		for (int svc = 1501; svc < 1509; svc++)
		{
			addHookedOption(namesService[svc - 1501], &Vehicles_f::SpawnVehicle, svc);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Sports
		addMenu("Class: Sports", MenuVehicleSpawnSports, MenuVehicleSpawn);
		
		// Build Sports List Part 1
		const char* namesSports[10] = { 
			"9F", 
			"9F2", 
			"Alpha (DLC)", 
			"Banshee", 
			"Blista Compact", 
			"Buffalo", 
			"Buffalo S (Franklin)", 
			"Carbonizzare", 
			"Comet", 
			"Coquette" };

		for (int sports = 1601; sports < 1611; sports++)
		{
			addHookedOption(namesSports[sports - 1601], &Vehicles_f::SpawnVehicle, sports);
		}
		
		
		// Build Sports List Part 2
		const char* namesSports2[10] = { 
			"Elegy RH8", 
			"Feltzer", 
			"Furore GT (DLC)", 
			"Fusilade", 
			"Futo", 
			"Go Go Monkey Blista", 
			"Jester", 
			"Jester (Racecar)", 
			"Khamelion", 
			"Kuruma (DLC)" };

		for (int sports2 = 1611; sports2 < 1621; sports2++)
		{
			addHookedOption(namesSports2[sports2 - 1611], &Vehicles_f::SpawnVehicle, sports2);
		}
		
		
		// Build Sports List Part 3
		const char* namesSports3[10] = { 
			"Kuruma Armored (DLC)", 
			"Massacro (DLC)", 
			"Massacro Race (DLC)", 
			"Penumbra", 
			"Rapid GT", 
			"Rapid GT (C)", 
			"Schwartzer", 
			"Sprunk Buffalo", 
			"Sultan", 
			"Surano" };

		for (int sports3 = 1621; sports3 < 1631; sports3++)
		{
			addHookedOption(namesSports3[sports3 - 1621], &Vehicles_f::SpawnVehicle, sports3);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Sports Classics
		addMenu("Class: Sports Classics", MenuVehicleSpawnSportsClassics, MenuVehicleSpawn);
		
		// Build Sports Classics List Part 1
		const char* namesSportsC[10] = { 
			"Casco (DLC)", 
			"Coquette Classic (DLC)", 
			"JB 700", 
			"Manana", 
			"Monroe", 
			"Peyote", 
			"Pigalle (DLC)", 
			"Roosevelt (DLC)", 
			"Stinger", 
			"Stinger GT" };

		for (int sportsc = 1701; sportsc < 1711; sportsc++)
		{
			addHookedOption(namesSportsC[sportsc - 1701], &Vehicles_f::SpawnVehicle, sportsc);
		}
		
		// Build Sports Classics List Part 2
		const char* namesSportsC2[6] = { 
			"Stirling GT (DLC)", 
			"Tornado", 
			"Tornado (C)", 
			"Tornado (Rusty)", 
			"Tornado (G-Mariachi)", 
			"Z-Type" };

		for (int sportsc2 = 1711; sportsc2 < 1717; sportsc2++)
		{
			addHookedOption(namesSportsC2[sportsc2 - 1711], &Vehicles_f::SpawnVehicle, sportsc2);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Super
		addMenu("Class: Super", MenuVehicleSpawnSuper, MenuVehicleSpawn);
		
		// Build Super List Part 1
		const char* namesSuper[10] = { 
			"Adder", 
			"Bullet", 
			"Cheetah", 
			"Entity XF", 
			"Infernus", 
			"Osiris (DLC)", 
			"T20 (DLC)", 
			"Turismo-R (DLC)", 
			"Vacca", 
			"Voltic" };

		for (int super = 1801; super < 1811; super++)
		{
			addHookedOption(namesSuper[super - 1801], &Vehicles_f::SpawnVehicle, super);
		}
		
		// Build Super List Part 2
		const char* namesSuper2[1] = { 
			"Zentorno (DLC)" };

		for (int super2 = 1811; super2 < 1812; super2++)
		{
			addHookedOption(namesSuper2[super2 - 1811], &Vehicles_f::SpawnVehicle, super2);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> SUVs
		addMenu("Class: SUVs", MenuVehicleSpawnSUVs, MenuVehicleSpawn);
		
		// Build SUVs List Part 1
		const char* namesSUVs[10] = { 
			"Baller",
			"Baller (R-Evoque)",
			"BeeJay XL",
			"Cavalcade 2005",
			"Cavalcade 2013",
			"Dubsta",
			"Dubsta (Blacked Out)",
			"FQ 2",
			"Granger", 
			"Gresley" };

		for (int suvs = 1901; suvs < 1911; suvs++)
		{
			addHookedOption(namesSUVs[suvs - 1901], &Vehicles_f::SpawnVehicle, suvs);
		}
		
		// Build SUVs List Part 2
		const char* namesSUVs2[10] = { 
			"Habanero",
			"Huntley S (DLC)",
			"Landstalker",
			"Mesa",
			"Mesa (Snowy)",
			"Mesa (Merryweather)",
			"Patriot",
			"Radius",
			"Rocoto",  
			"Seminole" };

		for (int suvs2 = 1911; suvs2 < 1921; suvs2++)
		{
			addHookedOption(namesSUVs2[suvs2 - 1911], &Vehicles_f::SpawnVehicle, suvs2);
		}
		
		// Build SUVs List Part 3
		const char* namesSUVs3[1] = { 
			"Serrano" };

		for (int suvs3 = 1921; suvs3 < 1922; suvs3++)
		{
			addHookedOption(namesSUVs3[suvs3 - 1921], &Vehicles_f::SpawnVehicle, suvs3);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Utilities
		addMenu("Class: Utilities", MenuVehicleSpawnUtilities, MenuVehicleSpawn);
		
		// Build Utilities List Part 1
		const char* namesUtilities[10] = { 
			"Airtug", 
			"Docktug", 
			"Golf Cart (ProLaps)", 
			"Golf Cart (Nagasaki)", 
			"Forklift", 
			"Lawn Mower", 
			"Ripley", 
			"Sadler", 
			"Sadler (Snowy)", 
			"Scrap Truck" };

		for (int util = 2001; util < 2011; util++)
		{
			addHookedOption(namesUtilities[util - 2001], &Vehicles_f::SpawnVehicle, util);
		}
		
		// Build Utilities List Part 2
		const char* namesUtilities2[8] = { 
			"Tractor (Farm)", 
			"Tractor (Rusty)", 
			"Tractor (Snowy)", 
			"Tow Truck (Large)",
			"Tow Truck (Small)",
			"Utility Basket Truck",
			"Utility Landscape Truck",
			"Utility Pick-Up Truck" };

		for (int util2 = 2011; util2 < 2019; util2++)
		{
			addHookedOption(namesUtilities2[util2 - 2011], &Vehicles_f::SpawnVehicle, util2);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> Vans
		addMenu("Class: Vans", MenuVehicleSpawnVans, MenuVehicleSpawn);
		
		// Build Vans List Part 1
		const char* namesVans[10] = { 
			"Bison", 
			"Bison (Cowboy)", 
			"Bison (Landscaping)", 
			"Bobcat", 
			"Boxville (Utility)", 
			"Boxville (Postal)", 
			"Boxville (Humane)", 
			"Boxville (Post Op)", 
			"Burrito", 
			"Burrito (BugStars)" };

		for (int van = 2101; van < 2111; van++)
		{
			addHookedOption(namesVans[van - 2101], &Vehicles_f::SpawnVehicle, van);
		}
		
		
		// Build Vans List Part 2
		const char* namesVans2[10] = {  
			"Burrito (Cowboy)",  
			"Burrito (Gang)", 
			"Burrito Gang NL (DLC)", 
			"Burrito (No Livery)",
			"Burrito (Snowy)", 
			"Camper", 
			"Journey", 
			"Minivan", 
			"Paradise (DLC)", 
			"Pony"  };

		for (int van2 = 2111; van2 < 2121; van2++)
		{
			addHookedOption(namesVans2[van2 - 2111], &Vehicles_f::SpawnVehicle, van2);
		}
		
		
		// Build Vans List Part 3
		const char* namesVans3[9] = { 
			"Pony (Weed Van)",
			"Rumpo (Weazel News)",
			"Rumpo (Deludamol)", 
			"Speedo", 
			"Speedo (Clown Van)", 
			"Surfer", 
			"Surfer (Rusty)", 
			"Taco Van", 
			"Youga" };

		for (int van3 = 2121; van3 < 2130; van3++)
		{
			addHookedOption(namesVans3[van3 - 2121], &Vehicles_f::SpawnVehicle, van3);
		}
		//-------------------------------------------------------------------------------

		
		//-------------------------------------------------------------------------------
		// Vehicles -> Spawn -> *Special*
		addMenu("Class: *Special*", MenuVehicleSpawnSpecial, MenuVehicleSpawn);
		
		// Build *Special* List Part 1
		const char* namesSpecial[10] = {
			"Army Tanker", 
			"Army Trailer", 
			"Army Trailer 2", 
			"Bale Trailer", 
			"Big Goods Trailer", 
			"Boat Trailer", 
			"Cable Car", 
			"Car Carrier Trailer", 
			"Cluckin/Other Trailer",
			"Construction Trailer" };

		for (int special = 2201; special < 2211; special++)
		{
			addHookedOption(namesSpecial[special - 2201], &Vehicles_f::SpawnVehicle, special);
		}
		
		// Build *Special* List Part 2
		const char* namesSpecial2[10] = { 
			"Dock Trailer", 
			"Fame or Shame Trailer", 
			"Farm Cultivator", 
			"Flatbed Trailer", 
			"Grain Trailer", 
			"Log Trailer", 
			"Marquis Trailer", 
			"Metal Tarp Trailer", 
			"Mobile Home Trailer",
			"Mule (No Livery)" };

		for (int special2 = 2211; special2 < 2221; special2++)
		{
			addHookedOption(namesSpecial2[special2 - 2211], &Vehicles_f::SpawnVehicle, special2);
		}
		
		// Build *Special* List Part 3
		const char* namesSpecial3[10] = { 
			"Super Car Carrier", 
			"Tanker", 
			"Tanker (No Livery)", 
			"Train (Freight)", 
			"Train (Flatbed)", 
			"Train (Metro)", 
			"Train Boxcar",
			"Train Container",
			"Train Container 2", 
			"Train Fuel Tank Car" };

		for (int special3 = 2221; special3 < 2231; special3++)
		{
			addHookedOption(namesSpecial3[special3 - 2221], &Vehicles_f::SpawnVehicle, special3);
		}
		
		// Build *Special* List Part 4
		const char* namesSpecial4[1] = { 
			"Train Well Car" };

		for (int special4 = 2231; special4 < 2232; special4++)
		{
			addHookedOption(namesSpecial4[special4 - 2231], &Vehicles_f::SpawnVehicle, special4);
		}
		//-------------------------------------------------------------------------------
		
		//-------------------------------------------------------------------------------
		
		// Vehicles -> Spawn -> *Props*
		addMenu("Class: *Props*", MenuVehicleSpawnProps, MenuVehicleSpawn);
		
		// Build *Props* List Part 1
		const char* namesProps[5] = {
			"Exercise Bike",
			"UFO",
			"UFO (Weaponized)",
			"Windmill (Weaponized)",
			"Wheelchair" };

		for (int prop = 2301; prop < 2306; prop++)
		{
			addHookedOption(namesProps[prop - 2301], &Vehicles_f::SpawnVehicle, prop);
		}
		
		//-------------------------------------------------------------------------------
		
		// Update Vehicle Manager
		updateVehicleManager();


		// Vehicles -> Turn Signals
		addMenu("Turn Signals", MenuVehiclesEditVehicleTurnSignals, MenuVehicles);
		addHookedOption("Toggle Bind To L1+R1", &Vehicles_f::ToggleBlinkerBind);
		addHookedOption("Left Blinker On", &Vehicles_f::VehicleBlinkerControl, 1);
		addHookedOption("Left Blinker Off", &Vehicles_f::VehicleBlinkerControl, 2);
		addHookedOption("Right Blinker On", &Vehicles_f::VehicleBlinkerControl, 3);
		addHookedOption("Right Blinker Off", &Vehicles_f::VehicleBlinkerControl, 4);
		addHookedOption("All Blinkers On", &Vehicles_f::VehicleBlinkerControl, 5);
		addHookedOption("All Blinkers Off", &Vehicles_f::VehicleBlinkerControl, 6);

		
		// Vehicles -> Toggles
		addMenu("Vehicle Toggles", MenuVehiclesEditVehicleToggles, MenuVehicles);
		addHookedOption("Boost Button Bind", &Vehicles_f::BoostVehicleButtonBind);
		addHookedOption("Speedometer", &Vehicles_f::Speedometer, 1);
		addHookedOption("Speedometer: BTTF", &Vehicles_f::Speedometer, 2);
		addHookedOption("Spawned Car To Phone", &Vehicles_f::ToggleAddSpawnedVehicleToPhone);
		addHookedOption("< Hydraulics >", &Vehicles_f::CarHydraulics);
		addHookedOption("Need For Speed", &Vehicles_f::NeedForSpeed);
		addHookedOption("Flying Car", &Vehicles_f::FlyingCar);
		addHookedOption("Hydro Jump", &Vehicles_f::HydroJump);
		addHookedOption("Air Jump", &Vehicles_f::AirJump);
		//addHookedOption("Torque Modifier", &Vehicles_f::ToggleVehicleTorqueModifier);
		//addHookedOption("Torque Backwards", &Vehicles_f::ToggleVehicleTorqueBackward);
		//addHookedOption("Density Modifier", &Vehicles_f::ToggleVehicleDensityMod);
		//addHookedOption("Set Random Density", &Vehicles_f::SetVehicleDensityModRandom);
		addHookedOption("GodMode", &Vehicles_f::ToggleVehicleGodmode);
		addHookedOption("Invisibility", &Vehicles_f::ToggleInvisibilityVehicle);
		//addHookedOption("Gravity", &Vehicles_f::ToggleVehicleGravity);
		addHookedOption("Freeze", &Vehicles_f::ToggleFreezeVehiclePosition);
		//addHookedOption("Burnout", &Vehicles_f::ToggleVehicleBurnout);
		//addHookedOption("Drift Mode", &Vehicles_f::ToggleVehicleDriftMode);
		//addHookedOption("Out Of Control", &Vehicles_f::ToggleVehicleOutOfControl);
		//addHookedOption("Jitter", &Vehicles_f::ToggleVehicleJitter);
		addHookedOption("Lights", &Vehicles_f::ToggleVehicleLights);
		addHookedOption("Brights", &Vehicles_f::ToggleVehicleBrights);
		//addHookedOption("Convertible Roof", &Vehicles_f::ToggleConvertibleRoof);
		//addHookedOption("Roll Windows Up/Down", &Vehicles_f::ToggleVehicleWindowsUpDown);
		//addHookedOption("Door Locks", &Vehicles_f::ToggleVehicleDoorLocks);
		//addHookedOption("Open/Close Doors", &Vehicles_f::ToggleVehicleDoorsOpen);
		//addOption("Rocket Car");
		//addOption("Drive On Water");
		//addHookedOption("Searchlight", &Vehicles_f::ToggleVehicleSearchLight);
		//addHookedOption("No Clipping Mode", &Vehicles_f::ToggleVehicleIsClipping);
		addHookedOption("Light On Fire", &Vehicles_f::ToggleVehicleOnFire);
		//addHookedOption("Wanted Level", &Vehicles_f::ToggleVehicleWanted);
		//addHookedOption("Stolen", &Vehicles_f::ToggleVehicleStolen);
		addHookedOption("Destroy Vehicle", &Vehicles_f::ToggleVehicleDriveable);
		//addHookedOption("Needs Hotwired", &Vehicles_f::ToggleVehicleNeedsHotwired);
		//addHookedOption("Hot Flag", &Vehicles_f::ToggleCanResprayVehicle);
			
		// Vehicles -> Edit Vehicle -> Adjust Multipliers
		//addMenu("Adjust Multipliers", MenuVehiclesEditVehicleAdjustMultipliers, MenuVehicles);
		//addOption("Bind Controls");
		//addOption("Acceleration");
		//addOption("Brake");
		//addOption("Handling");
		//addOption("RPM");
			
		// Vehicles -> Nearby Vehicles
		//addMenu("Nearby Vehicles", MenuVehiclesNearby, MenuVehicles);
		//addHookedOption("Control All In Range", &Peds_f::NearbyCarControlAll);
		//addHookedOption("Show Closest Vehicle", &Peds_f::ToggleNearbyVehicleDetect);
		//addHookedOption("Fix & Wash", &Peds_f::FixAndWashNearbyCars);
		//addHookedOption("Fully Tune", &Peds_f::MaxOutNearbyCars);
		/*
		addHookedOption("Teleport To Random", &Peds_f::TeleportToRandomNearbyCars);
		addHookedOption("Speed Boost Hyper", &Peds_f::SpeedBoostNearbyCars, 900);
		addHookedOption("Speed Boost Fast", &Peds_f::SpeedBoostNearbyCars, 100);
		addHookedOption("Speed Boost Slow", &Peds_f::SpeedBoostNearbyCars, 35);
		addHookedOption("Torque Backwards", &Peds_f::ToggleNearbyVehicleTorqueBackward);
		addHookedOption("Godmode", &Peds_f::GodmodeNearbyCars);
		addHookedOption("Invisibility", &Peds_f::ToggleInvisibilityNearbyCars);
		addHookedOption("Smash Windows", &Peds_f::SmashNearbyCarWindows);
		addHookedOption("Explode Tires", &Peds_f::ExplodeNearbyCarTires);
		addHookedOption("Break Off Doors", &Peds_f::BreakOffDoorsNearbyCars);
		addHookedOption("Explode Vehicle", &Peds_f::ExplodeNearbyCars);
		addHookedOption("Toggle Drifting", &Peds_f::ToggleDriftingNearbyCars);
		addHookedOption("Toggle Clipping", &Peds_f::ToggleClippingNearbyCars);
		addHookedOption("Toggle Burnout", &Peds_f::ToggleBurnoutNearbyCars);
		addHookedOption("Toggle Freeze", &Peds_f::FreezeNearbyCars);
		addHookedOption("Toggle Gravity", &Peds_f::GravityNearbyCars);
		addHookedOption("Toggle Hot Flag", &Peds_f::ToggleHotFlagNearbyCars);
		addHookedOption("Total Mayhem!", &Peds_f::NearbyCarMayhem);
		addHookedOption("Total Mayhem! + Boost", &Peds_f::NearbyCarMayhem, 2);
		addHookedOption("Total Mayhem! + Explode", &Peds_f::NearbyCarMayhem, 3);
		addHookedOption("Ultimate Total Mayhem!", &Peds_f::NearbyCarMayhem, 4);
		*/

		// UNUSED
		//addHookedOption("Knock Ped Off Vehicle", &Peds_f::KnockPedOffVehicle);
		//addHookedOption("Knock All Peds Off Vehicle", &Peds_f::KnockAllPedsOffVehicle);
		//addHookedOption("Random Paint", &Peds_f::RandomPaintNearbyCars);
		//addHookedOption("Toggle 4-Way Signals", &Peds_f::ToggleSignalsNearbyCars);
		//addHookedOption("Toggle Destroy", &Peds_f::DestroyNearbyCars);
		//addHookedOption("Toggle Money Rain", &Peds_f::ToggleMoneySpawn, 0);

		// Vehicles -> Edit Vehicle -> Modshop
		addMenu("Los Santos Customs", MenuVehiclesEditVehicleModshop, MenuVehicles);
		addHookedOption("Fix & Wash", &Vehicles_f::FixAndWash);
		addHookedOption("Fully Tune", &Vehicles_f::MaxOutVehicle);
		addOption("Change License Plate", &openSub, MenuVehiclesEditVehicleModshopPlate);
		addOption("Colors & Paint", &openSub, MenuVehiclesEditVehicleModshopPaint);
		addOption("Tire Smoke Color", &openSub, MenuVehiclesEditVehicleModshopTireSmoke);
		//addHookedOption("Wheel Type", &Vehicles_f::SetWheelType);
		//addHookedOption("Mod Type", &Vehicles_f::SetWheelType);
		//addHookedOption("Mod Index", &Vehicles_f::SetWheelType);
		//addOption("Parts & Accessories", &openSub, MenuVehiclesEditVehicleModshopParts);
		
		// Vehicles -> Edit Vehicle -> Modshop -> Tire Smoke
		addMenu("Tire Smoke Color", MenuVehiclesEditVehicleModshopTireSmoke, MenuVehiclesEditVehicleModshop);
		//addHookedOption("Input Custom", &Keyboard_OSK::ToggleKeyboard);
		addHookedOption("Random", &Vehicles_f::ChangeTireSmokeColor, 0);
		addHookedOption("Patriot", &Vehicles_f::ChangeTireSmokeColor, 1);
		addHookedOption("Black", &Vehicles_f::ChangeTireSmokeColor, 2);
		addHookedOption("White", &Vehicles_f::ChangeTireSmokeColor, 3);
		addHookedOption("Red", &Vehicles_f::ChangeTireSmokeColor, 4);
		addHookedOption("Green", &Vehicles_f::ChangeTireSmokeColor, 5);
		addHookedOption("Blue", &Vehicles_f::ChangeTireSmokeColor, 6);
		addHookedOption("Yellow", &Vehicles_f::ChangeTireSmokeColor, 7);
		addHookedOption("Orange", &Vehicles_f::ChangeTireSmokeColor, 8);
		addHookedOption("Hot Pink", &Vehicles_f::ChangeTireSmokeColor, 9);
		addHookedOption("Purple", &Vehicles_f::ChangeTireSmokeColor, 10);
		addHookedOption("Teal", &Vehicles_f::ChangeTireSmokeColor, 11);
		
		// Vehicles -> Edit Vehicle -> Modshop -> Change License Plate
		addMenu("Change License Plate", MenuVehiclesEditVehicleModshopPlate, MenuVehiclesEditVehicleModshop);
		//addHookedOption("Input Custom Text", &Keyboard_OSK::ToggleKeyboard, 0);
		addHookedOption("ILLICIT", &Vehicles_f::ChangeLicensePlateText, 1);
		addHookedOption("ALL BLANK SPACES", &Vehicles_f::ChangeLicensePlateText, 2);
		addHookedOption("ROCKSTAR", &Vehicles_f::ChangeLicensePlateText, 3);
		addHookedOption("SONY", &Vehicles_f::ChangeLicensePlateText, 4);
		addHookedOption("CHEATER", &Vehicles_f::ChangeLicensePlateText, 5);
		addHookedOption("HACKER", &Vehicles_f::ChangeLicensePlateText, 6);
		addHookedOption("MODDER", &Vehicles_f::ChangeLicensePlateText, 7);
		//addHookedOption("BOOBIES", &Vehicles_f::ChangeLicensePlateText, 8);
		addHookedOption("RACENE1", &Vehicles_f::ChangeLicensePlateText, 9);
		addHookedOption("2FAST4U", &Vehicles_f::ChangeLicensePlateText, 10);
		addHookedOption("LUV2XLR8", &Vehicles_f::ChangeLicensePlateText, 11);
		addHookedOption("420", &Vehicles_f::ChangeLicensePlateText, 12);
		addHookedOption("  5 0  ", &Vehicles_f::ChangeLicensePlateText, 13);
		addHookedOption("POLICE", &Vehicles_f::ChangeLicensePlateText, 14);
		addHookedOption("THE FUZZ", &Vehicles_f::ChangeLicensePlateText, 15);
		addHookedOption("THE PIGS", &Vehicles_f::ChangeLicensePlateText, 16);
		addHookedOption("  PIG  ", &Vehicles_f::ChangeLicensePlateText, 17);
		addHookedOption("OUTATIME", &Vehicles_f::ChangeLicensePlateText, 18);
		addOption("");
		//addHookedOption("Input Custom Color", &Keyboard_OSK::ToggleKeyboard);
		addHookedOption("Blue & White 1", &Vehicles_f::ChangeLicensePlateType, 1);
		addHookedOption("Blue & White 2", &Vehicles_f::ChangeLicensePlateType, 2);
		addHookedOption("Blue & White 3", &Vehicles_f::ChangeLicensePlateType, 3);
		addHookedOption("Yellow & Black", &Vehicles_f::ChangeLicensePlateType, 4);
		addHookedOption("Yellow & Blue", &Vehicles_f::ChangeLicensePlateType, 5);
		addHookedOption("North Yankton", &Vehicles_f::ChangeLicensePlateType, 6);
		
		/*
		// Vehicles -> Edit Vehicle -> Modshop -> Parts
		addMenu("Parts & Accessories", MenuVehiclesEditVehicleModshopParts, MenuVehiclesEditVehicleModshop);
		addOption("Armor", &openSub, MenuVehiclesEditVehicleModshopPartsArmor);
		addOption("Brakes", &openSub, MenuVehiclesEditVehicleModshopPartsBrakes);
		addOption("Bumpers", &openSub, MenuVehiclesEditVehicleModshopPartsBumpers);
		addOption("Engine", &openSub, MenuVehiclesEditVehicleModshopPartsEngine);
		addOption("Exhaust", &openSub, MenuVehiclesEditVehicleModshopPartsExhaust);
		addOption("Grills", &openSub, MenuVehiclesEditVehicleModshopPartsGrills);
		addOption("Hoods", &openSub, MenuVehiclesEditVehicleModshopPartsHoods);
		addOption("Interior", &openSub, MenuVehiclesEditVehicleModshopPartsInterior);
		addOption("Lights", &openSub, MenuVehiclesEditVehicleModshopPartsLights);
		addOption("Side Skirts", &openSub, MenuVehiclesEditVehicleModshopPartsSideSkirts);
		addOption("Spoilers", &openSub, MenuVehiclesEditVehicleModshopPartsSpoilers);
		addOption("Suspension", &openSub, MenuVehiclesEditVehicleModshopPartsSuspension);
		addOption("Transmission", &openSub, MenuVehiclesEditVehicleModshopPartsTransmission);
		addOption("Turbo", &openSub, MenuVehiclesEditVehicleModshopPartsTurbo);
		addOption("Wheels", &openSub, MenuVehiclesEditVehicleModshopPartsWheels);
		addOption("Windows", &openSub, MenuVehiclesEditVehicleModshopPartsWindows);
		*/
		
		// Vehicles -> Edit Vehicle -> Modshop -> Paint
		addMenu("Colors & Paint", MenuVehiclesEditVehicleModshopPaint, MenuVehiclesEditVehicleModshop);
		addHookedOption("Random Color", &Vehicles_f::RandomVehicleColor);
		addHookedOption("Random Primary Color", &Vehicles_f::ChangeVehiclePrimaryColor);
		addHookedOption("Random Secondary Color", &Vehicles_f::ChangeVehicleSecondaryColor);
		addHookedOption("Random Extra Colors", &Vehicles_f::ChangeVehicleExtraColor);
		//addOption("Pearlescent Color");
		//addOption("Wheels");
		addOption("");
		//addOption("Matte", &openSub, MenuVehiclesEditVehicleModshopPaintMatte);
		//addOption("Metallic", &openSub, MenuVehiclesEditVehicleModshopPaintMetallic);
		//addOption("Utility", &openSub, MenuVehiclesEditVehicleModshopPaintUtility);
		//addOption("Worn", &openSub, MenuVehiclesEditVehicleModshopPaintWorn);
		//addOption("");
		addHookedOption("Brushed Aluminum", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::BrushedAluminium);
		addHookedOption("Brushed Black Steel", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::BrushedBlackSteel);
		addHookedOption("Brushed Steel", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::BrushedSteel);
		addHookedOption("Chrome", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::Chrome);
		//addHookedOption("Gold", &Vehicles_f::ChangeVehicleColor, 1);
		//addHookedOption("Default Alloy Color", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::DefaultAlloyColor);
		//addHookedOption("Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::Blue);
		//addHookedOption("Epsilon Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::EpsilonBlue);
		//addHookedOption("Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::Green);
		//addHookedOption("Hot Pink", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::HotPink);
		//addHookedOption("Hunter Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::HunterGreen);
		//addHookedOption("Modshop Black", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::ModshopBlack1);
		//addHookedOption("Orange", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::Orange);
		//addHookedOption("Police Car Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::PoliceCarBlue);
		//addHookedOption("Pure White", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::PureWhite);
		//addHookedOption("Salmon Pink", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::Salmonpink);
		
		/*
		// Vehicles -> Edit Vehicle -> Modshop -> Paint -> Matte
		addMenu("Colors: Matte", MenuVehiclesEditVehicleModshopPaintMatte, MenuVehiclesEditVehicleModshopPaint);
		addHookedOption("Black", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteBlack);
		addHookedOption("Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteBlue);
		addHookedOption("Brown", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteBrown);
		addHookedOption("DarkBlue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteDarkBlue);
		addHookedOption("Dark Purple", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteDarkPurple);
		addHookedOption("Dark Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteDarkRed);
		//addHookedOption("Desert Brown", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteDesertBrown);
		//addHookedOption("Desert Tan", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteDesertTan);
		//addHookedOption("Foilage Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteFoilageGreen);
		addHookedOption("Forest Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteForestGreen);
		addHookedOption("Gray", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteGray);
		addHookedOption("Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteGreen);
		addHookedOption("Light Grey", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteLightGrey);
		addHookedOption("Lime Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteLimeGreen);
		addHookedOption("Midnight Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteMidnightBlue);
		//addHookedOption("Olive Drab", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteOliveDrab);
		addHookedOption("Orange", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteOrange);
		addHookedOption("Purple", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MattePurple);
		addHookedOption("Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteRed);
		addHookedOption("White", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteWhite);
		addHookedOption("Yellow", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MatteYellow);

		// Vehicles -> Edit Vehicle -> Modshop -> Paint -> Metallic
		addMenu("Colors: Metallic", MenuVehiclesEditVehicleModshopPaintMetallic, MenuVehiclesEditVehicleModshopPaint);
		addHookedOption("Dark Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetaillicVDarkBlue);
		//addHookedOption("Anthracite Grey", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicAnthraciteGrey);
		//addHookedOption("Beach Sand", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicBeachSand);
		//addHookedOption("Beechwood", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicBeechwood);
		//addHookedOption("BistonBrown", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicBistonBrown);
		addHookedOption("Black", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicBlack);
		addHookedOption("Black Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MettalicBlackBlue);
		addHookedOption("Black Purple", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicBlackPurple);
		addHookedOption("Black Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicBlackRed);
		addHookedOption("Black Steal", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicBlackSteal);
		addHookedOption("Blaze Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicBlazeRed);
		addHookedOption("Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicBlue);
		addHookedOption("Blue Silver", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicBlueSilver);
		addHookedOption("Bright Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicBrightBlue);
		//addHookedOption("Bright Blue 2", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicBrightBlue2);
		addHookedOption("Bronze", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicBronze);
		addHookedOption("Cabernet Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicCabernetRed);
		addHookedOption("Candy Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicCandyRed);
		addHookedOption("Champagne", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicChampagne);
		addHookedOption("Choco Brown", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicChocoBrown);
		addHookedOption("Choco Orange", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicChocoOrange);
		addHookedOption("Classic Gold", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicClassicGold);
		addHookedOption("Cream", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicCream);
		addHookedOption("Dark Beechwood", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicDarkBeechwood);
		addHookedOption("Dark Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicDarkBlue);
		addHookedOption("Dark Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicDarkGreen);
		addHookedOption("Dark Ivory", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicDarkIvory);
		addHookedOption("Dark Silver", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicDarkSilver);
		addHookedOption("Desert Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicDesertRed);
		addHookedOption("Diamond Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicDiamondBlue);
		addHookedOption("Formula Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicFormulaRed);
		addHookedOption("Frost White", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicFrostWhite);
		addHookedOption("Garnet Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicGarnetRed);
		addHookedOption("Gasoline Blue Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicGasolineBlueGreen);
		//addHookedOption("GoldenBrown", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicGoldenBrown);
		addHookedOption("Graceful Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicGracefulRed);
		addHookedOption("Graphite Black", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicGraphiteBlack);
		addHookedOption("Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicGreen);
		addHookedOption("Gun Metal", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicGunMetal);
		addHookedOption("Harbor Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicHarborBlue);
		addHookedOption("Lava Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicLavaRed);
		addHookedOption("Light Brown", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicLightBrown);
		addHookedOption("Lime", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicLime);
		addHookedOption("Mariner Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicMarinerBlue);
		addHookedOption("Midnight Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicMidnightBlue);
		addHookedOption("Midnight Silver", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicMidnightSilver);
		//addHookedOption("Moss Brown", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicMossBrown);
		addHookedOption("Nautical Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicNauticalBlue);
		addHookedOption("Olive Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicOliveGreen);
		addHookedOption("Orange", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicOrange);
		addHookedOption("Pueblo Beige", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicPuebloBeige);
		addHookedOption("Purple", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicPurple);
		addHookedOption("Purple Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicPurpleBlue);
		addHookedOption("Race Yellow", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicRaceYellow);
		addHookedOption("Racing Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicRacingGreen);
		addHookedOption("Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicRed);
		addHookedOption("Saxony Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicSaxonyBlue);
		addHookedOption("Sea Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicSeaGreen);
		addHookedOption("Securicor Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicSecuricorGreen);
		addHookedOption("Shadow Silver", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicShadowSilver);
		addHookedOption("Silver", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicSilver);
		addHookedOption("Spinnaker Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicSpinnakerBlue);
		addHookedOption("Steel Gray", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicSteelGray);
		addHookedOption("Stone Silver", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicStoneSilver);
		addHookedOption("Straw Beige", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicStrawBeige);
		//addHookedOption("Sun Bleeched Sand", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicSunBleechedSand);
		addHookedOption("Sunrise Orange", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicSunriseOrange);
		addHookedOption("Surf Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicSurfBlue);
		addHookedOption("Taxi Yellow", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicTaxiYellow);
		addHookedOption("Torino Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicTorinoRed);
		addHookedOption("Ultra Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicUltraBlue);
		addHookedOption("Vermillion Pink", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicVermillionPink);
		addHookedOption("White", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicWhite);
		addHookedOption("Yellow Bird", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::MetallicYellowBird);

		// Vehicles -> Edit Vehicle -> Modshop -> Paint -> Utility
		addMenu("Colors: Utility", MenuVehiclesEditVehicleModshopPaintUtility, MenuVehiclesEditVehicleModshopPaint);
		addHookedOption("Black", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilBlack);
		addHookedOption("Black Poly", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilBlackPoly);
		addHookedOption("Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilBlue);
		addHookedOption("Bright Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilBrightBlue);
		addHookedOption("Bright Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilBrightRed);
		addHookedOption("Brown", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilBrown);
		addHookedOption("Dark Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilDarkBlue);
		addHookedOption("Dark Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilDarkGreen);
		addHookedOption("Dark Silver", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilDarkSilver);
		addHookedOption("Garnet Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilGarnetRed);
		addHookedOption("Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilGreen);
		addHookedOption("Gun Metal", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilGunMetal);
		//addHookedOption("LightBrown", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilLightBrown);
		addHookedOption("Lightning Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UilLightningBlue);
		addHookedOption("Maui Blue Poly", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilMauiBluePoly);
		//addHookedOption("Medium Brown", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilMediumBrown);
		addHookedOption("Midnight Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilMidnightBlue);
		addHookedOption("Off White", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilOffWhite);
		addHookedOption("Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilRed);
		addHookedOption("Sea Foam Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilSeaFoamBlue);
		addHookedOption("Shadow Silver", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilShadowSilver);
		addHookedOption("Silver", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::UtilSilver);

		// Vehicles -> Edit Vehicle -> Modshop -> Paint -> Worn
		addMenu("Colors: Worn", MenuVehiclesEditVehicleModshopPaintWorn, MenuVehiclesEditVehicleModshopPaint);
		addHookedOption("Black", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornBlack);
		addHookedOption("Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornBlue);
		addHookedOption("Blue Silver", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornBlueSilver);
		addHookedOption("Brown", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornBrown);
		addHookedOption("Dark Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornDarkblue);
		addHookedOption("Dark Brown", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornDarkBrown);
		addHookedOption("Dark Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornDarkGreen);
		addHookedOption("Dark Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornDarkRed);
		addHookedOption("GoldenRed", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornGoldenRed);
		addHookedOption("Graphite", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornGraphite);
		addHookedOption("Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornGreen);
		addHookedOption("Honey Beige", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornHoneyBeige);
		addHookedOption("Light Blue", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornLightBlue);
		addHookedOption("Light Orange", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornLightOrange);
		addHookedOption("Off White", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornOffWhite);
		addHookedOption("Olive Army Green", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornOliveArmyGreen);
		addHookedOption("Orange", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornOrange);
		addHookedOption("Orange 2", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornOrange2);
		addHookedOption("Red", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornRed);
		addHookedOption("Sea Wash", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornSeaWash);
		addHookedOption("Shadow Silver", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornShadowSilver);
		addHookedOption("Silver", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornSilver);
		addHookedOption("Silver Grey", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornSilverGrey);
		addHookedOption("Straw Beige", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornStrawBeige);
		addHookedOption("Taxi Yellow", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornTaxiYellow);
		addHookedOption("White", &Vehicles_f::ChangeVehicleColor, Hashes_Colors::WornWhite);
		*/
		//-----------------------------------------------------------------------//
		
		//-----------------------------------------------------------------------//
		// Objects
		addMenu("Objects", MenuObjects, MenuMain);
		addOption("Object Manager", &openSub, MenuObjectsManager);
		addOption("Toggle Forge Pickup");
		addOption("Attachment Menu", &openSub, MenuObjectsAttachments);
		addOption("Spawn Custom Input");
		//addHookedOption("Pinwheel", &Objects_f::SpawnObjects, 2);
		//addHookedOption("UFO (CAUTION!)", &Objects_f::SpawnObjects, 3);
		//addHookedOption("Weed Plant", &Objects_f::SpawnObjects, 1);
		//addHookedOption("Windmill (Large)", &Objects_f::SpawnObjects, 4);

		// Object Spawn List 1
		const char* objectList[10] = { 
			"Pinwheel", 
			"UFO (CAUTION!)", 
			"Weed Plant", 
			"prop_ld_ferris_wheel",
			"prop_rub_cage01a", 
			"prop_windmill_01", 
			"prop_water_corpse_01", 
			"prop_dog_cage_02", 
			"prop_burgerstand_01", 
			"prop_wheelchair_01_s" };

		for (int object = 101; object < 111; object++)
		{
			addHookedOption(objectList[object - 101], &Objects_f::SpawnObjects, object);
		}
		
		
		// Object Spawn List 2
		const char* objectList2[10] = { 
			"prop_cs_dumpster_01a", 
			"prop_mb_hesco_06",
			"prop_roofvent_06a",
			"prop_dummy_car", 
			"prop_swiss_ball_01", 
			"prop_exer_bike_01",
			"prop_keg_01",
			"prop_mb_ordnance_02",
			"Prop_inflategate_01",
			"prop_inflatearch_01" };

		for (int object2 = 111; object2 < 121; object2++)
		{
			addHookedOption(objectList2[object2 - 111], &Objects_f::SpawnObjects, object2);
		}
		
		
		// Object Spawn List 3
		const char* objectList3[10] = { 
			"p_cs_mp_jet_01_s", 
			"prop_mr_raspberry_01",
			"prop_chall_lamp_01n",
			"Prop_vend_snak_01_tu", 
			"ind_prop_dlc_flag_02", 
			"prop_doghouse_01",
			"prop_trafficdiv_01",
			"prop_trafficdiv_02",
			"ind_prop_dlc_roller_car",
			"ind_prop_dlc_roller_car_02" };

		for (int object3 = 121; object3 < 131; object3++)
		{
			addHookedOption(objectList3[object3 - 121], &Objects_f::SpawnObjects, object3);
		}
		

		//addOption("Spawn Tiny");
		//addOption("Spawn Small");
		//addOption("Spawn Medium");
		//addOption("Spawn Large");
		//addOption("Spawn Extra Large");

		// Objects -> Manager
		addMenu("Objects Manager", MenuObjectsManager, MenuObjects);
		addOption("Option1");
		//addOption("Option2");
		//addOption("Option3");
		//addOption("Option4");
		//addOption("Option5");
		//addOption("Option6");

		// Objects -> Attachments
		addMenu("Attachment Menu", MenuObjectsAttachments, MenuObjects);
		addOption("Attach To Closet Object");
		//addOption("Detach Object");
		//addOption("Copy Object");
		//addOption("Delete Object");
		//addOption("Precision Level");
		//addOption("X Coord");
		//addOption("Y Coord");
		//addOption("Z Coord");
		//addOption("Pitch");
		//addOption("Roll");
		//addOption("Yaw");
		//-----------------------------------------------------------------------//
		
		//-----------------------------------------------------------------------//
		// Peds
		addMenu("Peds", MenuPeds, MenuMain);
		addOption("Ped Manager", &openSub, MenuPedsManager);
		//addHookedOption("Spawn Custom Input", &Keyboard_OSK::ToggleKeyboard);
		//addHookedOption("Spawn Random Ped", &Peds_f::SpawnRandomPed);
		//addHookedOption("All Random Peds Flee", &Peds_f::TogglePedFleeing);
		//addOption("Spawn Ped (Friendly)");
		//addOption("Spawn Ped (Hostile)");

		// Peds -> Manager
		addMenu("Ped Manager", MenuPedsManager, MenuPeds);
		addHookedOption("Show Ped Spawn Stats", &Peds_f::SpawnedPedStats);
		//addOption("Option1");
		//addOption("Option2");
		//addOption("Option3");
		//addOption("Option4");
		//addOption("Option5");
		//addOption("Option6");
		//-----------------------------------------------------------------------//
		
		
		//-----------------------------------------------------------------------//
		// World
		addMenu("World", MenuWorld, MenuMain);
		addOption("Time", &openSub, MenuTime);
		addOption("Weather", &openSub, MenuWeather);
		addOption("IPL Locations", &openSub, MenuWorldIPL);
		addHookedOption("Clear Area", &World_f::ClearArea);
		addHookedOption("Force Cleanup", &World_f::ForceCleanup);
		addHookedOption("Show Coords X Y Z", &PlayerSelf_f::ShowCoordsXYZ);
		addHookedOption("Display Area Name", &World_f::DisplayAreaName);
		addHookedOption("Blackout All Lights", &World_f::ToggleBlackout);
		
		// Time
		addMenu("Time Manager", MenuTime, MenuWorld);
		addHookedOption("Show Game Date & Time", &Weather_f::ShowDateTime);
		addHookedOption("Advance Time", &Weather_f::AdvanceTime);
		addHookedOption("Freeze Time", &Weather_f::ToggleFreezeTime);
		//addOption("24/7 Daylight");
		//addOption("24/7 Night");
		//addHookedOption("Time Scale Fast", &Weather_f::SetTimeScaleFast);
		//addHookedOption("Time Scale Slow", &Weather_f::SetTimeScaleSlow);
		//addOption("Set Year");
		//addOption("Set Month");
		//addOption("Set Day");
		//addOption("Set Hour");
		//addOption("Set Minute");

		// Weather
		addMenu("Weather Manager", MenuWeather, MenuWorld);
		//addHookedOption("Input Custom Weather", &Keyboard_OSK::ToggleKeyboard);
		//addOption("Wind Editor", &openSub, MenuWeatherWindEditor);
		//addOption("Toggle Persistance");
		addHookedOption("Random", &Weather_f::ChangeWeather, 0);
		addHookedOption("Blizzard", &Weather_f::ChangeWeather, 1);
		addHookedOption("Christmas", &Weather_f::ChangeWeather, 2);
		addHookedOption("Clear", &Weather_f::ChangeWeather, 3);
		addHookedOption("Clearing", &Weather_f::ChangeWeather, 4);
		addHookedOption("Clouds", &Weather_f::ChangeWeather, 5);
		addHookedOption("Extra Sunny", &Weather_f::ChangeWeather, 6);
		addHookedOption("Foggy", &Weather_f::ChangeWeather, 7);
		addHookedOption("Light Snow", &Weather_f::ChangeWeather, 8);
		addHookedOption("Neutral", &Weather_f::ChangeWeather, 9);
		addHookedOption("Overcast", &Weather_f::ChangeWeather, 10);
		addHookedOption("Rain", &Weather_f::ChangeWeather, 11);
		addHookedOption("Smog", &Weather_f::ChangeWeather, 12);
		addHookedOption("Snow", &Weather_f::ChangeWeather, 13);
		addHookedOption("Thunder Storm", &Weather_f::ChangeWeather, 14);

		// UNUSED
		//addHookedOption("Tsunami Test Loop", &World_f::TsunamiTest);
		//addHookedOption("Random Loop", &Weather_f::ChangeWeather, 99);

		// Weather -> Wind Editor
		addMenu("Wind Editor", MenuWeatherWindEditor, MenuWeather);
		//addHookedOption("Enter Custom Speed", &Keyboard_OSK::ToggleKeyboard);
		//addHookedOption("Enter Custom Direction", &Keyboard_OSK::ToggleKeyboard);
		//addOption("No Wind");
		//addOption("Breazy");
		//addOption("Light Wind");
		//addOption("Medium Wind");
		//addOption("Heavy Wind");
		//addOption("Hurricane");
		//addOption("Neptune");

		// UNUSED
		//addOption("Create Wind Cycle To Loop");
		//addOption("Toggle Speed Adjust (L1+L2)");
		//addOption("Toggle Direction Adjust (R1+R2)");
		
		// IPL Locations
		addMenu("IPL Locations", MenuWorldIPL, MenuWorld);
		addHookedOption("North Yankton Request", &World_f::RequestIPL, 0);
		addHookedOption("North Yankton Remove", &World_f::RemoveIPL, 0);
		addHookedOption("Heist Yacht Request", &World_f::RequestIPL, 1);
		addHookedOption("Heist Yacht Remove", &World_f::RemoveIPL, 1);

		// UNUSED
		//addHookedOption("Set Parked Vehicles To 0", &World_f::SetNumberOfParkedVehicles, 0);
		//addHookedOption("Set Parked Vehicles To 100", &World_f::SetNumberOfParkedVehicles, 100);
		
		//-----------------------------------------------------------------------//


		
		//-----------------------------------------------------------------------//
		// Protection
		addMenu("Protection Options", MenuProtection, MenuMain);
		addHookedOption("Clear Mental State", &Protection::ClearMentalState);
		addHookedOption("Clear Reports", &Protection::ClearAllReports);
		addHookedOption("Disable Idle Kick", &Protection::DisableIdleKick);
		addHookedOption("Remove Badsport", &Protection::RemoveBadSport);
		addHookedOption("Disable 1.26 Anti-Cheat", &Protection::DisableAntiCheat);
		//addOption("Freeze Protection");
		//addOption("");
		//addOption("Monitor Reports");
		//addOption("View Reports");
		//addOption("Monitor SCTV Slots");
		//addOption("Enter SCTV Slot #1");
		//addOption("Enter SCTV Slot #2");

		//-----------------------------------------------------------------------//
		
		/*
		//-----------------------------------------------------------------------//
		// Sounds
		addMenu("Sound Set Manager", MenuSoundsMain, MenuMain);
		addOption("0");
		addOption("EXILE_1");
		addOption("HintCamSounds");
		addOption("HUD_AWARDS");
		addHookedOption("HUD_FRONTEND_DEFAULT_SOUNDSET", &Sounds_f::menuHudSoundLoad);
		addOption("HUD_FRONTEND_MP_SOUNDSET", &Sounds_f::menuHudSoundBack);
		addOption("HUD_MINIGAME_SOUNDSET", &Sounds_f::menuHudSoundUpDown);
		addOption("MissionFailedSounds", &Sounds_f::menuHudSoundLeftRight);
		addOption("Prologue_Sounds", &Sounds_f::menuHudSoundSelect);
		addOption("SPECIAL_ABILITY_SOUNDSET");
		addOption("WastedSounds");
		//-----------------------------------------------------------------------//
		*/
		
		
		//-----------------------------------------------------------------------//
		// Network
		addMenu("Network", MenuNetwork, MenuMain);
		addHookedOption("Skip Online Tutorial", &Network_f::NetworkEndTutorialSession);
		addHookedOption("Set Mission Finished", &Network_f::NetworkSetMissionFinished);
		addHookedOption("Start New Online Session", &Network_f::StartNewOnlineSession);
		addHookedOption("Start Solo Single Player", &Network_f::NetworkSessionHostSinglePlayer);
		addHookedOption("Leave Current Session", &Network_f::NetworkSessionLeaveSinglePlayer);
		//addHookedOption("Launch Transition", &Network_f::NetworkLaunchTransition);
		//addHookedOption("Leave Transition", &Network_f::NetworkLeaveTransition);
		//addHookedOption("Bail Transition", &Network_f::NetworkBailTransition);
		addHookedOption("Override Spectator Mode", &Network_f::NetworkSetOverrideSpectatorMode);
		//addHookedOption("Set Friendly Fire Option", &Network_f::NetworkSetFriendlyFireOption);
		addHookedOption("Override Network Clock", &Network_f::NetworkOverrideClockTime);
		addHookedOption("Is Cloud Available", &Network_f::NetworkIsCloudAvailable);
		//addHookedOption("Check Number of Players", &Network_f::CheckNumberOfPlayers);
		//addHookedOption("Get Host of Script", &Network_f::GetHostOfScript);
		//addHookedOption("Get Players Stats", &Peds_f::ToggleStatsPlayers);
		//addHookedOption("Network Stats", &Network_f::ToggleStatsNetwork);
		
		// UNUSED
		//addHookedOption("Show Profile UI", &Network_f::NetworkShowProfileUi);
		
		
		//-----------------------------------------------------------------------//



		//-----------------------------------------------------------------------//
		// Misc
		addMenu("Misc", MenuMisc, MenuMain);
		//addOption("Plugin Manager", &openSub, MenuMiscPlugins);
		//addOption("Tuneables", &openSub, MenuMiscTuneables);
		addOption("Toggles", &openSub, MenuMiscToggles);
		addHookedOption("Skip The Bullshit!", &Misc_f::SkipTheBullshit);
		addHookedOption("Skip All Tutorials", &Misc_f::SkipAllTutorials);
		addHookedOption("Show Mission Flag", &Missions_f::GetMissionFlag);
		addHookedOption("Launch Single Player Game", &Misc_f::LaunchSingleplayerGame);
		//addHookedOption("Request New Thread ID", &Misc_f::RequestNewThreadId);
		//addHookedOption("Begin SRL", &Misc_f::BeginSRL);
		//addHookedOption("End SRL", &Misc_f::EndSRL);
		addHookedOption("Skip Prologue Hack 1", &Misc_f::SkipPrologue, 1);
		addHookedOption("Skip Prologue Hack 2", &Misc_f::SkipPrologue, 2);
		addHookedOption("Skip Prologue Hack 3", &Misc_f::SkipPrologue, 3);
		//addHookedOption("Save Game", &Misc_f::DoAutoSave);
		addHookedOption("Pause Game", &Misc_f::TogglePauseGame);
		addHookedOption("Show End Credits Screen", &Misc_f::ToggleEndCredits);
		//addHookedOption("Exit Thread (Kills Menu)", &Misc::ExitThread);

		/*
		addHookedOption("HUD Overlay Test 1", &Hud::HudOverlay, 1);
		addHookedOption("HUD Overlay Test 2", &Hud::HudOverlay, 2);
		addHookedOption("HUD Overlay Test 3", &Hud::HudOverlay, 3);
		addHookedOption("HUD Overlay Test 4", &Hud::HudOverlay, 4);
		addHookedOption("HUD Overlay Test 5", &Hud::HudOverlay, 5);
		addHookedOption("HUD Overlay Test 6", &Hud::HudOverlay, 6);
		addHookedOption("HUD Overlay Test 7", &Hud::HudOverlay, 7);
		addHookedOption("HUD Overlay Test 8", &Hud::HudOverlay, 8);
		addHookedOption("HUD Overlay Test 9", &Hud::HudOverlay, 9);
		*/

		// Options Used For Testing
		// Some Do Not Work or Work Partially
		// Most Will Not Make The Final Build or Have Been Integrated Into Other Functions
		
		
		//addHookedOption("Test Write File", &WriteFile);
		//addHookedOption("Test Read File", &ReadFile);

		//addHookedOption("Particle Test Coords", &PlayerSelf_f::ParticleTestCoords);
		//addHookedOption("Particle Test Entity", &PlayerSelf_f::ParticleTestEntity);
		//addHookedOption("Force Mission Complete", &Missions_f::ForceMissionComplete);
		//addHookedOption("Explode Talking Players");
		//addHookedOption("Remove All Cover Areas", &World_f::RemoveAllCoverBlockingAreas);
		//addHookedOption("Set Gravity Level 1", &World_f::SetGravityLevel, 1);
		//addHookedOption("Set Gravity Level 2", &World_f::SetGravityLevel, 2);
		//addHookedOption("Set Gravity Level 3", &World_f::SetGravityLevel, 3);
		//addHookedOption("Enable Roosevelt In Phone", &Stats_f::EnableRooseveltInPhone);
		//addHookedOption("Set New Waypoint", &Hud_f::SetNewWaypoint);
		//addHookedOption("Clear Waypoint", &Hud_f::ClearWaypoint);
		//addHookedOption("Show If Player In Vehicle", &Peds_f::IsPedInAnyVehicle);
		//addHookedOption("Show If Player Is Invincible", &PlayerSelf_f::CheckGodModeStatus);
		//addHookedOption("Stop All Alarms", &Misc_f::StopAllAlarms);
		//addHookedOption("Get Allocated Stack Size", &System_f::GetAllocatedStackSize);
		//addHookedOption("Random Test", &Misc_f::RandomTest);
		//addHookedOption("Send Web Request", &Web_f::SendWebRequest);
		//addOption("Blip Editor");
		//addHookedOption("Get Vehicle Ped Is Using", &Vehicles_f::GetVehiclePedIsUsing);
		//addHookedOption("Play End Credits Music", &Debug_f::ToggleEndCreditsMusic);
		//addHookedOption("Skip Conversation", &System_f::SkipToNextConversation);
		//addHookedOption("Restart Conversation", &System_f::RestartConversation);
		//addHookedOption("Stop Cutscene Immediately", &Misc_f::StopCutsceneImmediately);
		//addHookedOption("Get Pause Game State", &Debug_f::GetPauseState);
		//addHookedOption("Terminate Thread", &Misc_f::TerminateThread);
		//addHookedOption("Terminate This Thread", &Misc_f::TerminateThisThread);
		//addHookedOption("Check If Thread Is Active", &Misc_f::IsThreadActive);
		//addHookedOption("Redesign Character Prompt", &Stats_f::RedesignCharacterPrompt);
		//addHookedOption("Show Player Coords", &PlayerSelf_f::ShowCoords);
		//addHookedOption("Get ID of This Thread", &Misc_f::GetIdOfThisThread);
		//addHookedOption("Get All Player Names", &Debug_f::GetPlayerNames);
		//addHookedOption("Set No Loading Screen", &Misc_f::SetNoLoadingScreen);
		//addHookedOption("Shutdown Loading Screen", &Debug_f::ShutdownLoadingScreen);
		//addOption("Turn Debug Options On", &DebugOn);
		//addOption("Turn Debug Options Off", &DebugOff);


		// Misc -> Plugins
		//addMenu("Plugin Manager", MenuMiscPlugins, MenuMisc);
		//addOption("List Plugins");
		//addOption("Add Plugin");
		//addOption("Edit Plugin");
		//addOption("Remove Plugin");
		//addOption("Load Plugin");
		//addOption("Unload Plugin");
		

		// Misc -> Tuneables
		//addMenu("Tuneables", MenuMiscTuneables, MenuMisc);
		//addOption("Toggle Heists");
		//addOption("Remove Bet Limits");
		//addOption("Disable Roller Coaster");
		//addOption("Disable Ferris Wheel");
		//addOption("Disable Fireworks");
		//addOption("Turn On EyeFind Promo Page");
		
					
		// Misc -> Toggles
		addMenu("Misc Toggles", MenuMiscToggles, MenuMisc);
		addHookedOption("Radar", &Hud_f::ToggleRadar);
		addHookedOption("HUD", &Hud_f::ToggleHud);
		addHookedOption("Enable Dev Mode", &PlayerSelf_f::DevModeDirect);
		//addHookedOption("DPAD Test U/D", &Misc_f::TestDpad, 2);
		//addHookedOption("DPAD Test L/R", &Misc_f::TestDpad, 1);

		// UNUSED
		//addHookedOption("System Stats", &Misc_f::ToggleSystemStats);
		//addHookedOption("Debug Lines and Spheres", &System_f::ToggleDebugLines);
		
		// Toggles Used For Testing
		// Some Do Not Work or Work Partially
		// Most Will Not Make The Final Build and Have Been Integrated Into Other Functions
		//addHookedOption("Aim Cheater");
		//-----------------------------------------------------------------------//
		

		/*
		//-----------------------------------------------------------------------//
		// Settings
		addMenu("Settings", MenuSettings, MenuMain);
		addOption("Button Manager", &openSub, MenuSettingsButtons);
		//addOption("UI Menu Colors", &openSub, MenuSettingsUIColors);
		//addOption("UI Menu Sizes", &openSub, MenuSettingsUISizes);
		//addOption("UI Menu Text", &openSub, MenuSettingsUIText);
		//addOption("UI Menu Background", &openSub, MenuSettingsUIBackground);
		addOption("Move Menu Up");
		addOption("Move Menu Right");
		addOption("Move Menu Down");
		addOption("Move Menu Left");
		addOption("Save Current Settings");
		addOption("Load Custom Settings");
		
		// Settings -> Button Manager
		addMenu("Button Manager", MenuSettingsButtons, MenuSettings);
		addOption("Change Menu Button Combo");
		addOption("New Button Combo");
		addOption("Configure CIRCLE");
		addOption("Configure CROSS");
		addOption("Configure SQUARE");
		addOption("Configure TRIANGLE");
		addOption("Configure R1");
		addOption("Configure R2");
		addOption("Configure R3");
		addOption("Configure L1");
		addOption("Configure L2");
		addOption("Configure L3");
		addOption("Configure L3 Stick Down");

		// Settings -> UI Menu Colors
		addMenu("UI Menu Colors", MenuSettingsUIColors, MenuSettings);
		addOption("Title Color");
		addOption("Subtitle Color");
		addOption("Item Text Color");
		addOption("Item Text Color Selected");
		addOption("Footer Color");
		addOption("Background Color");

		// Settings -> UI Menu Colors
		addMenu("UI Menu Sizes", MenuSettingsUISizes, MenuSettings);
		addOption("");
		addOption("");
		addOption("");
		addOption("");
		addOption("");
		addOption("");
		addOption("");

		// Settings -> UI Menu Colors
		addMenu("UI Menu Text", MenuSettingsUIText, MenuSettings);
		addOption("");
		addOption("");
		addOption("");
		addOption("");
		addOption("");
		addOption("");

		// Settings -> UI Menu Colors
		addMenu("UI Menu Background", MenuSettingsUIBackground, MenuSettings);
		addOption("");
		addOption("");
		addOption("");
		addOption("");
		addOption("");
		addOption("");
		addOption("");
		*/
		//-----------------------------------------------------------------------//

		/*
		//-----------------------------------------------------------------------//
		// System Toggles
		addMenu("System Toggles", MenuSystemToggles, MenuMisc);
		addOption("Online Vehicle Spawn");
		addOption("GodMode On Vehicle Spawn");
		addOption("GodMode On Fully Tune");
		addOption("Max Out On Vehicle Spawn");
		addOption("Turn Signal Bind");
		addOption("Vehicle Boost Bind");
		//-----------------------------------------------------------------------//
		*/

		/*
		//-----------------------------------------------------------------------//
		// Presets
		addMenu("Preset Shortcuts", MenuPresets, MenuMain);
		addHookedOption("Preset 1", &Presets_f::PresetOne);
		addOption("Preset 2");
		addOption("Preset 3");
		//-----------------------------------------------------------------------//
		*/

		//-----------------------------------------------------------------------//
		// Help
		addMenu("Help", MenuHelp, MenuMain);
		addHookedOption("Toggle Help Context", &Misc::ToggleMenuHelpContext);
		//addOption("Using Menus");
		//addOption("Customization");
		
		/*
		// DEMO_MODE_ONLY
		if (demoMode == true)
		{
			addHookedOption("Purchase License", &Licensing::KeyGen::KeygenTest);
		}
		
		// IF_FULL_VERSION_ONLY
		if (notDemo == true && notActivated == true)
		{
			addHookedOption("Activate License", &Licensing::KeyGen::KeygenTest);
		}
		*/

		// Credits Splash pauses in-game timer (GET_GAME_TIMER) function
		// The system timer must also be used only while credits splash is running
		// The system timer must subtract its millisecond counter value from demo time left
		addHookedOption("Credits", &Help_f::ShowCreditsText);

		addHookedOption("About", &Help_f::ShowAboutText);
		//-----------------------------------------------------------------------//
		

		/*
		//-----------------------------------------------------------------------//
		// Debug
		
		if (debug == true)
		{
			addMenu("*Debug*", MenuDebug, MenuMain);
			addOption("Dump Game Memory");
			addOption("Edit Game Memory", &openSub, MenuDebugEditMemory);
			addOption("Invoke Game Natives", &openSub, MenuDebugNatives);
			addOption("Remote Network Menu", &openSub, MenuDebugRemoteNetMenu);
			addOption("Patch EBOOT.BIN", &openSub, MenuDebugPatchEboot);
			addOption("Patch update.rpf", &openSub, MenuDebugPatchUpdateRpf);
			addOption("Patch Custom File", &openSub, MenuDebugPatchCustom);
			addOption("Load an SPRX File");
			addOption("Unload an SPRX File");
			addOption("Reload Game Normal");
			addOption("Reload Game With Patches");
			addHookedOption("Pause Game", &Debug_f::TogglePauseGame);
			addOption("Controller Debug Output");
			addOption("Keyboard Test", &System_f::Keyboard_f::ToggleKeyboard);
			addOption("Toggle Verbose Output");

			// Debug -> Edit Game Memory
			addMenu("*Edit Game Memory*", MenuDebugEditMemory, MenuDebug);
			addOption("Display In Hex");
			addOption("Jump To Address In Memory");
			addOption("Search For Value");
			addOption("Peek At Address");
			addOption("Poke Address");
			addOption("Save Current Memory As File");
			addOption("Pre-Compiled Patches");

			// Debug -> Remote Network Menu
			addMenu("*Remote Network Menu*", MenuDebugRemoteNetMenu, MenuDebug);
			addOption("Ping Test");
			addOption("IP Settings");
			addOption("Port Settings");
			addOption("TCP/IP & UDP Settings");
			addOption("Display IPs From Lobby");
			addOption("Connect To RPC/RTM Tool");
			addOption("Send Data To Remote Port");
			addOption("Toggle Multi-Attach");
			addOption("Attach To Another Menu");
			addOption("Detach From All Menus");
			addOption("Inject Menu Into Player");
			addOption("Inject Script Into Player");
			addOption("Backup Menu From Player");
			addOption("Restore Menu To Player");
		
			// Debug -> Patch EBOOT.BIN
			addMenu("*Patch EBOOT.BIN*", MenuDebugPatchEboot, MenuDebug);
			addOption("Change SPRX Path");
			addOption("Toggle SPRX Loading");
			addOption("Toggle Script Bypass");
			addOption("Patch To DEX");
			addOption("Patch To CEX");
			addOption("Change Region To BLES");
			addOption("Change Region To BLUS");
			addOption("Backup EBOOT.BIN");
			addOption("Restore EBOOT.BIN");
			addOption("Delete EBOOT.BIN");
		
			// Debug -> Patch update.rpf
			addMenu("*Patch update.rpf*", MenuDebugPatchUpdateRpf, MenuDebug);
			addOption("Script Manager");
			addOption("Download Scripts");
			addOption("Add Script");
			addOption("Edit Script");
			addOption("Delete Script");
			addOption("RPF Manager");
			addOption("Download RPF Files");
			addOption("Extract RPF");
			addOption("Create RPF");
			addOption("Backup RPF");
			addOption("Restore RPF");
			addOption("Delete RPF");
		
			// Debug -> Patch Custom File
			addMenu("*Custom File Patcher*", MenuDebugPatchCustom, MenuDebug);
			addOption("Open File");
			addOption("Save File");
			addOption("Delete File");

			// Debug -> Invoke Game Natives
			addMenu("*Invoke Game Natives*", MenuDebugNatives, MenuDebug);
			addHookedOption("CREATE_MONEY_PICKUPS", &Peds_f::CreateMoneyPickup);
			addHookedOption("DISPLAY_CASH", &Peds_f::ToggleDisplayCashOnHud);
			addHookedOption("GET_PED_MONEY", &Peds_f::GetPedMoney);
			addHookedOption("IS_PED_RUNNING_CASH_DROP", &Peds_f::IsPedRunningCashDrop);
			addOption("NETWORK_CAN_RECEIVE_PLAYER_CASH");
			addOption("NETWORK_GIVE_PLAYER_JOBSHARE_CASH");
			addOption("NETWORK_RECEIVE_PLAYER_JOBSHARE_CASH");
			addOption("NETWORK_SPENT_CASH_DROP");
			addHookedOption("REMOVE_MULTIPLAYER_BANK_CASH", &Peds_f::RemoveMultiplayerBankCash);
			addHookedOption("REMOVE_MULTIPLAYER_HUD_CASH", &Peds_f::RemoveMultiplayerHudCash);
			addHookedOption("SET_MULTIPLAYER_BANK_CASH", &Peds_f::SetMultiplayerBankCash);
			addHookedOption("SET_MULTIPLAYER_HUD_CASH", &Peds_f::SetMultiplayerHudCash);
			addHookedOption("SET_PED_MONEY", &Peds_f::SetPedMoney);
			addOption("Test14");
			addOption("Test15");
			addOption("Test16");
			addOption("Test17");
			addOption("Test18");
			addOption("Test19");
			addOption("Test20");
			addOption("Test21");
			addOption("Test22");
			addOption("Test23");
			addOption("Test24");
			addOption("Test25");
			addOption("Test26");
			addOption("Test27");
			addOption("Test28");
			addOption("Test29");
			addOption("Test30");
			}
		//-----------------------------------------------------------------------//
		*/


	}

	
	// Update Vehicle Manager
	void updateVehicleManager()
	{
		// Vehicles -> Manager
		addMenu("Vehicle Manager", MenuVehiclesManager, MenuVehicles);

		for (int slot = 0; slot < numberOfSpawnedVehicles; slot++)
		{
			
			uint vehicleSlot = spawnedVehicleList[slot];

			addHookedOption(vehicleName, &Vehicles_f::DeleteVehicleFromManager, vehicleSlot);

			/*
			if (spawnedVehicleList[slot] == 0)
			{
				addOption("**No Vehicle In Slot**");
			}
			else
			{
				addHookedOption(vehicleIDc, &Vehicles_f::DeleteVehicleFromManager, spawnedVehicleList[slot]);
			}
			*/
		}
	}

	
	// Update Attachment Manager
	void updateAttachmentManager()
	{
		// Attachments -> Manager
		addMenu("Attachment Manager", MenuPlayersAllAttachmentsManager, MenuPlayersAllAttachments);

		for (int slot = 0; slot < numberOfSpawnedObjects; slot++)
		{
			
			uint ObjectSlot = spawnedObjectList[slot];
			
			//addHookedOption(spawnedObjectName, &Peds_f::AttachObjectToPed, ObjectSlot);
			addHookedOption(spawnedObjectName, &Peds_f::DetachObjectFromPlayer, ObjectSlot);

			/*
			if (numberOfSpawnedObjects[slot] == 0)
			{
				addOption("**No Object In Slot**");
			}
			else
			{
				addHookedOption(spawnedObjectName, &Peds_f::DetachObjectFromPlayer, spawnedObjectList[slot]);
			}
			*/
		}
	}
	//---------------------------------------------------------------------------

	
	//---------------------------------------------------------------------------
	//This is for executing the hooked options functions.
	void executeHookedFunc()
	{
		//UpdatePlayersMenu();
		isUpdatePlayersMenu = true;

		// Redraw menu structure after option is executed
		//createMenuStruct();
		
		// Update Vehicle Manager
		//updateVehicleManager();

		// Pressing Default X Button
		if (executeOptionFunc)
		{
			sleep(50);
			((void(*)(int))optionFunction[currentMenu][currentOption])(optionFunctionParam[currentMenu][currentOption]);
			executeOptionFunc = false;

		}

		// Pressing Default Loop Combo
		if (executeOptionFuncLoop)
		{
			if (optionFunctionHooked[currentMenu][currentOption])
			{
				//wait(2000);
				sleep(5);
				((void(*)(int))optionFunction[currentMenu][currentOption])(optionFunctionParam[currentMenu][currentOption]);
			}
		}

		

	}
	//---------------------------------------------------------------------------

};




//UNUSED CRAP

// Display Counter On Bottom Center of Menu
/*
char msg[100];
sprintf(msg, "%i/%i", currentOption+1, subOptionCount[currentMenu]);
DRAW_TEXT(msg, 6, .5 + x_Offset, 0.20 + (0.045f*(subOptionCount[currentMenu] > 16 ? 17 : subOptionCount[currentMenu]+ 1)), 0.65, 0.65, Colors::Yellow, 255, true);
*/

// Show Current Option Under Bottom Border
/*
char msg[100];
sprintf(msg, "%s", subOptionText[currentMenu][currentOption]);
DRAW_TEXT(msg, 6, .5 + x_Offset, 0.22 + (0.045f*(subOptionCount[currentMenu] > 16 ? 17 : subOptionCount[currentMenu]+ 1)), 0.60, 0.60, Colors::Pink, 255, true);
*/



// Display Menu Times Opened Counter On Bottom Center of Menu
/*
char msgMenuCounter[100];
sprintf(msgMenuCounter, "Menu Opened %i Times", menuCounter);
DRAW_TEXT(msgMenuCounter, 6, .5 + x_Offset, 0.24 + (0.045f*(subOptionCount[currentMenu] > 16 ? 17 : subOptionCount[currentMenu]+ 1)), 0.40, 0.40, Colors::Teal, 255, true);
*/



/*
// Scrolling Example 
void DoScroll(const char* Direction)
{
	if(cstrcmp(Direction, "UP"))
	{
		Scroll --;
		if(Scroll < 0)
		{
			Scroll = MaxScroll;
		}
	}
	else
	{
		Scroll ++;
		if(Scroll > MaxScroll)
		{
			Scroll = 0;
		}
	}
	for(int i = 0; i < 20; i++)
	{
		if(i == Scroll)
		{
			Text[i].R = 255; Text[i].G = 215; Text[i].B = 0; Text[i].A = 255;
		}
		else
		{
			Text[i].R = 255; Text[i].G = 255; Text[i].B = 255; Text[i].A = 255;
		}
	}
}
*/



#endif






