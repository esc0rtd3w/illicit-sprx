#ifndef __MENU_H
#define __MENU_H


#include "anti.h"
#include "buttons.h"
#include "hud.h"
#include "functions.h"
#include "hashes.h"
#include "includes.h"
#include "licensing.h"
#include "messages.h"
#include "misc.h"
#include "natives.h"
#include "printf.h"
#include "stats.h"
#include "system.h"
#include "types.h"


using namespace cellFSWriteInt_;
using namespace Dialog;
using namespace Functions;
using namespace Hashes;
using namespace Keyboard;
using namespace Licensing;
using namespace Misc;
using namespace Natives;
using namespace Stats_f;


namespace Menu_f
{

	// Variable to check whether menu is open
	bool isOpen;


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
		// Main Menu Items
		MenuRecovery,
		MenuRecoveryRank,
		MenuRecoveryNetworkCash,
		MenuRecoveryUnlockables,
		MenuRecoveryGiveItems,
		
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
	//---------------------------------------------------------------------------


	//---------------------------------------------------------------------------
	// ADD MENU STUFF -----------------------------------------------------------

	// Add New Sub Menus
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
	}
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


	//---------------------------------------------------------------------------
	// This is what draws the menu on the screen.
	// This is where you change the theme, colors, position, etc.
	void drawMenu()
	{
		// Default Color Sets
		ColorSet Color = Colors::Common::White;
		ColorSet ColorHighlight = Colors::Common::Green;

		// Default X Offset
		float x_Offset = .3;
		x_OffsetFollow = x_Offset;

		const char** Options = subOptionText[currentMenu];

		// Set default difference for border
		float Dif = ((subOptionCount[currentMenu] > 16 ? 16 : subOptionCount[currentMenu]) * 0.45) / 10;
		DifFollow = Dif;

		// Set default footer attachment difference
		float DifFooter = ((subOptionCount[currentMenu] > 16 ? 16 : subOptionCount[currentMenu]) * 0.45) / 10;
		DifFooterFollow = DifFooter;

		// Main Title Text
		DrawText(cellReadFS(), 7, 0.52 + x_Offset, 0.063, 1.00, 0.50, Colors::Common::Green, 255, true);

		// Main Menu Current Subtitle Text
		DrawText(subMenuTitle[currentMenu], 4, 0.52 + x_Offset, 0.116, 0.95, 0.85, Colors::Common::Yellow, 255, true);
		
		
		// Menu Background -> Draw Around Entire Menu
		DrawRect(0.52 + x_Offset, 0.140 + Dif / 2, .2, 0.155 + Dif, Colors::Common::Black, 40);
		

		// Menu Background -> Draw Header
		DrawRect(0.52 + x_Offset, 0.048, 0.20, 0.03, Colors::Common::Green, 40);

		// Menu Background -> Draw Footer
		DrawRect(0.52 + x_Offset, 0.227 + DifFooter, 0.20, 0.02, Colors::Common::Green, 40);
		//---------------------------------------------------------------------------
		
		
		
		//---------------------------------------------------------------------------
		// Sub Menu Items
		for (int i = 0; i < 16; i++)
		{
			// Menu Sub Items Default Text NOT SELECTED Color
			Color = Colors::Common::White;
			
			//--------------------------------------------------------------------------------
			

			// Menu Items Text Default SELECTED Color
			if (i == currentOption) 
			{
				// Send current option to global
				currentOptionFollow = Options[(currentOption)];
				
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


				// Change the color on selected item
				Color = Colors::Common::Teal;


				// Draw a box around selected item
				DrawRect(0.52 + x_Offset, 0.202 + (0.045f*i), 0.20, 0.038, ColorHighlight, 30);

			}
			
			
			// Second+ Pages Greater Than 15 Items
			if (currentOption > 15)
			{
				// Menu Items Text SELECTED past first page
				if (i == 15) 
				{
					// Menu Sounds
					// UP and DOWN NAVIGATION
					if (!isMenuSoundUpDown && isMenuSoundUpDown_ == 1)
					{
						isMenuSoundUpDown_++;
						isMenuSoundUpDown___ = currentOptionFollow;
						isMenuSoundUpDown = true;
					}

					if (isMenuSoundUpDown___ != currentOptionFollow)
					{
						isMenuSoundUpDown_ = 1;
					}

					// Change the color on selected item
					Color = Colors::Common::Teal;


					// Draw a box around selected item
					DrawRect(0.52 + x_Offset, 0.202 + (0.045f*i), 0.20, 0.038, ColorHighlight, 30);

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

	}
	//---------------------------------------------------------------------------


	//---------------------------------------------------------------------------
	// Opens a sub menu
	void openSub(int Menu)
	{
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
		addMenu("Recovery & Stats", MenuRecovery);
		addHookedOption("~b~Gimmie The Goods", &Stats_f::Essentials);
		addHookedOption("Increase RP", &Stats_f::IncreaseRP);
		addOption("Give Network Cash", &openSub, MenuRecoveryNetworkCash);
		addOption("Unlockables", &openSub, MenuRecoveryUnlockables);
		//addOption("Rank Editor", &openSub, MenuRecoveryRank);
		addOption("Give Items", &openSub, MenuRecoveryGiveItems);
		//addOption("K/D Ratio Editor");
		addHookedOption("100% Max Skills", &Stats_f::MaxAllSkills);
		addHookedOption("Purchase All Weapons", &Stats_f::PurchaseAllWeapons);
		addHookedOption("Bypass Vehicle Sell Timer", &Stats_f::BypassVehicleSellTimer);
		addHookedOption("Enable Free Shopping", &Stats_f::FreeShopping);
		addHookedOption("Clear Mental State", &Stats_f::ClearMentalState);
		addHookedOption("Clear Reports", &Stats_f::ClearAllReports);
		addHookedOption("Disable Idle Kick", &Stats_f::DisableIdleKick);
		addHookedOption("Remove Badsport", &Stats_f::RemoveBadSport);
		addHookedOption("Disable 1.26 Anti-Cheat", &Stats_f::DisableAntiCheat);

		// Recovery -> Give Items
		addMenu("Give Items", MenuRecoveryGiveItems, MenuRecovery);
		addHookedOption("Give Armor", &Stats_f::GiveArmor);
		//addHookedOption("Give Health", &Stats_f::GiveHealth);
		addHookedOption("Give Fireworks", &Stats_f::GiveFireworks);
		addHookedOption("Give Snacks", &Stats_f::GiveSnacks);

		// Recovery -> Rank Editor
		//addMenu("Rank Editor", MenuRecoveryRank, MenuRecovery);
		//addHookedOption("Increase RP", &Stats_f::IncreaseRP);
		//addHookedOption("Rank 1", &Stats_f::RankMP, 0);
		//addHookedOption("Rank 120", &Stats_f::RankMP, 120);
		//addHookedOption("Rank 250", &Stats_f::RankMP, 250);
		//addHookedOption("Rank 500", &Stats_f::RankMP, 500);
		//addHookedOption("Rank 750", &Stats_f::RankMP, 750);
		//addHookedOption("Rank 999", &Stats_f::RankMP, 999);
		//addHookedOption("Rank 1337", &Stats_f::RankMP, 1337);
		//addHookedOption("Rank 6666", &Stats_f::RankMP, 6666);
		//addHookedOption("Rank 6969", &Stats_f::RankMP, 6969);
		//addHookedOption("Rank 8000", &Stats_f::RankMP, 8000);

		// Recovery -> Give Network Cash
		addMenu("Give Network Cash", MenuRecoveryNetworkCash, MenuRecovery);
		addHookedOption("$1,000", &Stats_f::GiveNetworkCash, 1000);
		addHookedOption("$10,000", &Stats_f::GiveNetworkCash, 10000);
		addHookedOption("$100,000", &Stats_f::GiveNetworkCash, 100000);
		addHookedOption("$500,000", &Stats_f::GiveNetworkCash, 500000);
		addHookedOption("$1,000,000", &Stats_f::GiveNetworkCash, 1000000);
		addHookedOption("$10,000,000", &Stats_f::GiveNetworkCash, 10000000);
		addHookedOption("$50,000,000", &Stats_f::GiveNetworkCash, 50000000);
		//addHookedOption("$500,000,000", &Stats_f::GiveNetworkCash, 500000000);
		//addHookedOption("$1,000,000,000", &Stats_f::GiveNetworkCash, 1000000000);


		// Recovery -> Unlockables
		addMenu("Unlockables", MenuRecoveryUnlockables, MenuRecovery);
		addHookedOption("Unlock All Heists", &Stats_f::UnlockAllHeists);
		addHookedOption("Unlock Heist Vehicles", &Stats_f::UnlockHeistVehicles);
		addHookedOption("Unlock Heist Trophies", &Stats_f::UnlockAllHeistTrophies);
		addHookedOption("Unlock Camos & Parachutes", &Stats_f::UnlockAllCamosParachutes);
		addHookedOption("Unlock Free Chrome Rims", &Stats_f::UnlockFreeChromeRims);
		addHookedOption("Unlock Exclusive T-Shirts", &Stats_f::UnlockExclusiveTshirts);
		addHookedOption("Unlock All Vehicle Mods", &Stats_f::UnlockAllVehicleMods);
		addHookedOption("Unlock Trophies & Awards", &Stats_f::UnlockAllTrophysAwards);
		addHookedOption("Unlock All Hairstyles", &Stats_f::UnlockAllHairstyles);
		addHookedOption("Unlock All Tatoos", &Stats_f::UnlockAllTattoos);
		//-----------------------------------------------------------------------//
		
	}

	
	
	//---------------------------------------------------------------------------

	
	//---------------------------------------------------------------------------
	//This is for executing the hooked options functions.
	void executeHookedFunc()
	{
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
				sleep(5);
				((void(*)(int))optionFunction[currentMenu][currentOption])(optionFunctionParam[currentMenu][currentOption]);
			}
		}

	}
	//---------------------------------------------------------------------------

};



#endif

