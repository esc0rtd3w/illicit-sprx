#ifndef __DEBUG_H
#define __DEBUG_H


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


namespace Debug_f
{
	/*

	//if (i == currentOption) 
	/*
	// MENU DEBUG OUTPUT
	if (debugMenuItems == true)
	{
		// SHOW TITLE
		char debugOut1[32];
		sprintf(debugOut1, "Menu Debug Output");
		DrawText(debugOut1, 7, 0.01, 0.01, 0.50, 0.50, Colors::Common::Teal, 255, false);

		// SHOW NUMBER OF MENU ITEMS ONLY IN TOP LEFT CORNER ABOVE STATS
		char debugOut2[100];
		sprintf(debugOut2, "~w~Number of Menus: ~g~%i\n~w~Max Menus: ~b~138", Menus_Length);
		DrawText(debugOut2, 6, 0.01, 0.06, 0.50, 0.50, Colors::Common::Teal, 255, false);
					
		// SHOW MENU STATS IN TOP LEFT CORNER
		char debugOut3[100];
		sprintf(debugOut3, "~w~Name: ~y~%s\n~w~Current: ~y~%i\n~w~Items: ~y~%i\n~w~Option: ~y~%i", subOptionText[currentMenu][currentOption], currentMenu, subOptionCount[currentMenu], currentOption);
		DrawText(debugOut3, 6, 0.01, 0.15, 0.50, 0.50, Colors::Common::Teal, 255, false);	
	}
	*/


	/*
	//if (currentOption > 15)

	// MENU DEBUG OUTPUT
	if (debugMenuItems == true)
	{
		// SHOW TITLE
		char debugOut1[32];
		sprintf(debugOut1, "Menu Debug Output");
		DrawText(debugOut1, 7, 0.01, 0.01, 0.50, 0.50, Colors::Common::Teal, 255, false);

		// SHOW NUMBER OF MENU ITEMS ONLY IN TOP LEFT CORNER ABOVE STATS
		char debugOut2[100];
		sprintf(debugOut2, "~w~Number of Menus: ~g~%i\n~w~Max Menus: ~b~138", Menus_Length);
		DrawText(debugOut2, 6, 0.01, 0.06, 0.50, 0.50, Colors::Common::Teal, 255, false);
					
		// SHOW MENU STATS IN TOP LEFT CORNER
		char debugOut3[100];
		sprintf(debugOut3, "~w~Name: ~y~%s\n~w~Current: ~y~%i\n~w~Items: ~y~%i\n~w~Option: ~y~%i", subOptionText[currentMenu][currentOption], currentMenu, subOptionCount[currentMenu], currentOption);
		DrawText(debugOut3, 6, 0.01, 0.15, 0.50, 0.50, Colors::Common::Teal, 255, false);	
	}
	*/



	/*
	// Verbose Debug Output on screen for current menu selection
	void DebugMenuStats()
	{
		// SHOW NUMBER OF MENU ITEMS ONLY IN TOP LEFT CORNER ABOVE STATS
		char debugOut[100];
		sprintf(debugOut, "~w~Number of Menus: ~b~%i\n~w~Max Menus: ~r~144", Menus_Length);
		//PrintText(debugOut, 3000);
		DrawText(debugOut, 6, 0.01, 0.01, 0.70, 0.70, Colors::Common::Teal, 255, false);


		// SHOW MENU STATS IN TOP LEFT CORNER
		char debugOut[100];
		sprintf(debugOut, "~w~Name: ~y~%s\n~w~Current: ~y~%i\n~w~Items: ~y~%i\n~w~Option: ~y~%i", subOptionText[currentMenu][currentOption], currentMenu, subOptionCount[currentMenu], currentOption);
		//PrintText(debugOut, 3000);
		DrawText(debugOut, 6, 0.01, 0.03, 0.70, 0.70, Colors::Common::Teal, 255, false);	
	}
	*/
		

};




#endif


