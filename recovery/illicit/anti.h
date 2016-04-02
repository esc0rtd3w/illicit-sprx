#ifndef __ANTI_H
#define __ANTI_H


//#include "hud.h"
#include "includes.h"
#include "licensing.h"
#include "misc.h"

using namespace std;
using namespace Hud;
using namespace Licensing;



namespace cellFSWriteInt_
{

	// Anti-Cracking Stuff


	// Expired Time Loop Flag
	bool isCellFSTerminated;

	// No License Loop Flag
	bool isCellNLTerminated;
	
	// Display Tampered Message Loop Flag
	bool isCellWebRequestFTP;


	// Credits Splash
	bool cellPRXInt8;

	// Check Title Text

	// iLLiCiT
	bool cellPRXInt32;

	// Startup Splash
	bool cellPRXUint256;

	// 2ND COLLECTIVE NEW BOOL TO PASS ON
	bool cellPRXInt4;

	// Main Double Check Passes To This BOOL
	// All Demo Text Anti Flags Must Be Set To TRUE to PASS VERIFICATION
	// This single BOOL is then used to check against modifications while SPRX is in memory
	bool cellPS3XBOX;


	// Threshold

	// Max Flags for Mod Detection
	int stdArgsPS3 = 8;

	// Single Anti Flag
	int stdArgsPS3Cell;

	
	//----------------------------------------------------------------------------
	// Menu Main Title
	const char* cellReadFS1 = "iLLiCiT Recovery Menu";

	const char* cellReadFS()
	{
		char buffer[100];
		sprintf(buffer, "%s",  cellReadFS1);
		return buffer;
	}
	//----------------------------------------------------------------------------
	
	
	//----------------------------------------------------------------------------
	// Credit Tag on First Menu Open
	char* cellRequestPPU = "~r~W~g~e~y~l~b~c~r~o~g~m~y~e ~b~T~r~o ~g~i~y~L~b~L~r~i~g~C~y~i~b~T~r~\n\n~w~ps3dg.com/gta5";
	//----------------------------------------------------------------------------
	
	
	//----------------------------------------------------------------------------
	// Modifications Detected In Game Message (Needs Extra Protection)
	char* cellWebRequestFTP1 = "PIRATED OR MODIFIED ELF DETECTED!!!\n";
	char* cellWebRequestFTP2 = "Please Visit ps3dg.com";

	const char* cellWebRequestFTP()
	{
		char buffer[100];
		sprintf(buffer, "~r~%s%s~", cellWebRequestFTP1, cellWebRequestFTP2);
		return buffer;
	}
	//----------------------------------------------------------------------------


	//----------------------------------------------------------------------------
	// Main Startup Splash
	
	// Normal Message
	char* cellWebRequest1 = "Welcome To iLLiCiT!\n\n";
	char* cellWebRequest2 = "Recovery and Stats Menu\n\n";
	char* cellWebRequest3 = "Open Menu: SQUARE + DPAD LEFT\n";
	char* cellWebRequest4 = "Navigate Back: SQUARE\n";
	char* cellWebRequest5 = "Select Item: CROSS (X)\n\n";
	char* cellWebRequest6 = "For More Info, Please Visit:\n";
	char* cellWebRequest7 = "http://ps3dg.com/gta5";
	
	char* cellWebRequest()
	{
		char buffer[250];
		sprintf(buffer, "%s%s%s%s%s%s%s", cellWebRequest1, cellWebRequest2, cellWebRequest3, cellWebRequest4, cellWebRequest5, cellWebRequest6, cellWebRequest7);
		return buffer;
	}
	//----------------------------------------------------------------------------


	//----------------------------------------------------------------------------
	// Modified Message
	char* cellWebRequestHTTPS1 = "PIRATED OR MODIFIED ELF DETECTED!!!\n";
	char* cellWebRequestHTTPS2 = "THE MENU HAS BEEN DISABLED!\n\n";
	char* cellWebRequestHTTPS3 = "Please Visit:\n";
	char* cellWebRequestHTTPS4 = "http://ps3dg.com/gta5";
	
	char* cellWebRequestHTTPS()
	{
		char buffer[250];
		sprintf(buffer, "%s%s%s%s", cellWebRequestHTTPS1, cellWebRequestHTTPS2, cellWebRequestHTTPS3, cellWebRequestHTTPS4);
		return buffer;
	}
	//----------------------------------------------------------------------------


	//----------------------------------------------------------------------------
	// MAIN ANTI CHECK FUNCTION (ONLY GETS CALLED BEFORE MENU IS DRAWN)
	// IT WILL SET APPROPRIATE RESPONSES BASED ON CHECKED CONDITIONS
	// THERE WILL BE 2 NEW BOOLS CREATED IF ALL ANTI CHECKS PASS
	// THE 2 NEW BOOLS WILL BE CHECKED AT MAIN PRX BEFORE MENU IS DRAWN

	// Check All Targeted Text Areas
	void cellPS3EnumInt32()
	{
		// Check Title Text Part 1
		if (cellReadFS1[0] == 'i' && cellReadFS1[1] == 'L' && cellReadFS1[2] == 'L' && cellReadFS1[3] == 'i' && cellReadFS1[4] == 'C' && cellReadFS1[5] == 'i' && cellReadFS1[6] == 'T') 
		{
			cellPRXInt32 = true;
		}

		else
		{
			cellPRXInt32 - false;
		}
		
		// Check Startup Splash Text Line 1
		if (cellWebRequest1[0] == 'W' && cellWebRequest1[1] == 'e' && cellWebRequest1[2] == 'l' && cellWebRequest1[3] == 'c' && cellWebRequest1[4] == 'o' && cellWebRequest1[5] == 'm' && cellWebRequest1[6] == 'e' && cellWebRequest1[7] == ' ' && cellWebRequest1[8] == 'T' && cellWebRequest1[9] == 'o' && cellWebRequest1[10] == ' ' && cellWebRequest1[11] == 'i' && cellWebRequest1[12] == 'L' && cellWebRequest1[13] == 'L' && cellWebRequest1[14] == 'i' && cellWebRequest1[15] == 'C' && cellWebRequest1[16] == 'i' && cellWebRequest1[17] == 'T' && cellWebRequest1[18] == '!') 
		{
			cellPRXUint256 = true;
		}
		
		else
		{
			cellPRXUint256 - false;
		}

		// Check Credits Splash
		// Skip this CHECK and force to TRUE 20151113
		cellPRXInt8 = true;
		

		// ANTI CHECKS COMPLETE


		// DOUBLE CHECK ANTI-FLAGS
		// Check all above appended for title and make a new BOOL to pass checks to
		if (cellPRXInt32 && cellPRXUint256)
		{
			cellPRXInt4 = true;
		}

		else
		{
			cellPRXInt4 - false;
		}
	}
	//----------------------------------------------------------------------------



};




#endif


