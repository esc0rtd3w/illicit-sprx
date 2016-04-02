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


	// Token Sent To Server
	int cellFSWebTokenOut;
	bool cellFSWebTokenSend;
	char* cellFSWebTokenTextOut = "7yP";

	// Token Received From Server
	int cellFSWebTokenIn;
	bool cellFSWebTokenReceive;
	char* cellFSWebTokenTextIn = "7yP";


	// Main Modify Detected BOOL
	//bool isCellReadRandom = false;


	// Expired Time Loop Flag
	bool isCellFSTerminated;

	// No License Loop Flag
	bool isCellNLTerminated;
	
	// Display Tampered Message Loop Flag
	bool isCellWebRequestFTP;

	// REAL DEMO TIMER
	// Total Time In Milliseconds
	// Max Timer For Demo (30 Minutes = 1800000 / 31 Minutes = 1860000)
	int cellSPRXDummy1 = 1860001;
	int cellSPRXDummy2 = 1860020;
	int cellSPRXDummy3 = 1800000;
	int cellSPRXDummy4 = 1860000;
	int cellSPRXDummy5 = 1800001;

	// Real Max (Extra Time To Account for loading menu)
	// Should be a little over 30 minutes at game start
	//int cellSPRX = 640000;
	int cellSPRX = 1840111;

	// Use system timer to keep track of time for demo when splash text or xmb is displayed
	//int systemTimer;


	// Credits Splash
	bool cellPRXInt8;

	// Check Title Text

	// iLLiCiT
	bool cellPRXInt32;
	// S
	bool cellPRXInt16a;
	// P
	bool cellPRXInt16b;
	// R
	bool cellPRXInt16c;
	// X
	bool cellPRXInt16d;
	// M
	bool cellPRXInt16e;
	// e
	bool cellPRXInt16f;
	// n
	bool cellPRXInt16g;
	// u
	bool cellPRXInt16h;


	bool cellPRXInt64;
	bool cellPRXUint64;
	bool cellPRXUint32;
	bool cellPRXUint128;

	// Startup Splash
	bool cellPRXUint256;

	//Help -> About Text
	bool cellPRXUint512;
	


	// 1ST COLLECTIVE NEW BOOL TO PASS ON
	bool cellPRXInt16;

	// 2ND COLLECTIVE NEW BOOL TO PASS ON
	bool cellPRXInt4;

	// Main Double Check Passes To This BOOL
	// All Demo Text Anti Flags Must Be Set To TRUE to PASS VERIFICATION
	// This single BOOL is then used to check against modifications while SPRX is in memory
	bool cellPS3XBOX;




	//bool antiTest = true;

	// Return FALSE if NOT TAMPERED
	//int cellPRXInt64_ = false;



	// Threshold

	// Max Flags for Mod Detection
	int stdArgsPS3 = 8;

	// Single Anti Flag
	int stdArgsPS3Cell;



	// Secret Character Picker
	//const char* charPickerL = "abcdefghijklmnopqrstuvwxyz";
	//const char* charPickerU = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//const char* charPickerS = "~!@#$%^&*()-_=+[]{};:<>/?";
	//const char* charPickerN = "0123456789";
	
	//const char* charPicker_i = "i";
	//const char* charPicker_L = "L";
	//const char* charPicker_C = "C";
	//const char* charPicker_T = "T";

	
	//----------------------------------------------------------------------------
	// Menu Main Title
	const char* cellReadFS1 = "iLLiCiT";
	const char* cellReadFS2 = "u";
	const char* cellReadFS3 = "M";
	const char* cellReadFS4 = "S";
	const char* cellReadFS5 = "e";
	const char* cellReadFS6 = "X";
	const char* cellReadFS7 = "P";
	const char* cellReadFS8 = "R";
	const char* cellReadFS9 = "n";

	const char* cellReadFS()
	{
		char buffer[100];
		sprintf(buffer, "%s %s%s%s%s %s%s%s%s",  cellReadFS1, cellReadFS4, cellReadFS7, cellReadFS8, cellReadFS6, cellReadFS3, cellReadFS5, cellReadFS9, cellReadFS2);
		return buffer;
	}
	//----------------------------------------------------------------------------
	
	
	//----------------------------------------------------------------------------
	// // Help -> Credits Text Splash
	const char* cellWriteIntRequest1 = "Joren (Samples)\n";
	const char* cellWriteIntRequest2 = "DexModderFTW (Samples)\n";
	const char* cellWriteIntRequest3 = "All I Forgot (C++ Samples)\n\n";
	const char* cellWriteIntRequest4 = "Testers:\n";
	const char* cellWriteIntRequest5 = "budlight4142\n";
	const char* cellWriteIntRequest6 = "BLinDepTH\n";
	const char* cellWriteIntRequest7 = "Jess03500";

	const char* cellWriteIntRequest()
	{
		char buffer[200];
		sprintf(buffer, "%s%s%s%s%s%s%s", cellWriteIntRequest1, cellWriteIntRequest2, cellWriteIntRequest3, cellWriteIntRequest4, cellWriteIntRequest5, cellWriteIntRequest6, cellWriteIntRequest7);
		return buffer;
	}
	//----------------------------------------------------------------------------
	
	
	//----------------------------------------------------------------------------
	// Help -> About Text
	const char* cellSendRequest1 = "iLLiCiT Public Build 20160328\n";
	const char* cellSendRequest2 = "esc0rtd3w / ps3dg.com\n";
	const char* cellSendRequest3 = "License: ";

	const char* cellSendRequest()
	{
		char buffer[128];
		//sprintf(buffer, "~b~%s~y~%s~w~%s~g~%s ~w~/~g~ %s", cellSendRequest1, cellSendRequest2, cellSendRequest3, LicenseKey, LicenseType);
		sprintf(buffer, "~b~%s~y~%s~w~%s~g~%s", cellSendRequest1, cellSendRequest2, cellSendRequest3, LicenseType);
		return buffer;
	}
	//----------------------------------------------------------------------------
	
	
	//----------------------------------------------------------------------------
	// Credit Tag on First Menu Open
	char* cellRequestPPU = "~r~W~g~e~y~l~b~c~r~o~g~m~y~e ~b~T~r~o ~g~i~y~L~b~L~r~i~g~C~y~i~b~T~r~\n\n~w~ps3dg.com/gta5";
	//char* cellRequestPPU2 = "~y~Open Menu: ~r~SQUARE ~y~+ ~w~DPAD LEFT\n~y~Function Loop: ~w~L1 ~y~+ ~b~X";
	//----------------------------------------------------------------------------

	
	//----------------------------------------------------------------------------
	// Demo Evaluation Text
	const char* cellReadUint1 = "TEST VERSION\n";
	const char* cellReadUint2 = "FOR EVALUATION ";
	const char* cellReadUint3 = "PURPOSES ONLY\n";
	const char* cellReadUint4 = "ps3dg.com/gta5";

	const char* cellReadUint()
	{
		char buffer[100];
		sprintf(buffer, "~h~%s%s%s~y~%s", cellReadUint1, cellReadUint2, cellReadUint3, cellReadUint4);
		return buffer;
	}
	//----------------------------------------------------------------------------
	
	
	//----------------------------------------------------------------------------
	// Demo Expired Text (Needs Extra Protection)
	const char* cellWriteUint1 = "DEMO TIME EXPIRED!\n";
	const char* cellWriteUint2 = "RESTART GAME TO USE AGAIN!\n";
	const char* cellWriteUint3 = "Visit ps3dg.com/gta5 To Buy Full Version";

	const char* cellWriteUint()
	{
		char buffer[100];
		sprintf(buffer, "~r~%s%s~y~%s", cellWriteUint1, cellWriteUint2, cellWriteUint3);
		return buffer;
	}
	//----------------------------------------------------------------------------

	
	//----------------------------------------------------------------------------
	// No License Found
	const char* cellNoLicense1 = "~r~LICENSE KEY NOT FOUND\n";
	const char* cellNoLicense2 = "~w~Copy ~b~iLLiCiT.txt ~w~to:\n";
	const char* cellNoLicense3 = "~y~/dev_hdd0/tmp/iLLiCiT.txt";

	const char* cellNoLicense()
	{
		char buffer[100];
		sprintf(buffer, "%s%s%s", cellNoLicense1, cellNoLicense2, cellNoLicense3);
		return buffer;
	}
	//----------------------------------------------------------------------------
	

	
	//----------------------------------------------------------------------------
	// Modifications Detected In Game Message (Needs Extra Protection)
	char* cellWebRequestFTP1 = "PIRATED OR MODIFIED ELF DETECTED!!!\n";
	char* cellWebRequestFTP2 = "TAKING YOUR LIGHT AND WEAPONS!";

	const char* cellWebRequestFTP()
	{
		char buffer[100];
		sprintf(buffer, "~r~%s%s~", cellWebRequestFTP1, cellWebRequestFTP2);
		return buffer;
	}
	//----------------------------------------------------------------------------
	
	//----------------------------------------------------------------------------
	// Menu -> Draw Footer Text Left Side
	const char* cellReadUint32 = "**CRACKED DEMO**";
	//----------------------------------------------------------------------------

	
	//----------------------------------------------------------------------------
	// Menu -> Draw Footer Text Center
	const char* cellReadUint64 = "PS3DG.COM/GTA5";
	//----------------------------------------------------------------------------


	//----------------------------------------------------------------------------
	// Main Startup Splash
	
	// Normal Message
	char* cellWebRequest1 = "Welcome To iLLiCiT!\n\n";
	char* cellWebRequest2 = "Thank You For Your Purchase!\n\n";
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

	/*
	//----------------------------------------------------------------------------
	// Main Startup Splash No License
	
	char* cellWebRequestNL1 = "Welcome To iLLiCiT!\n\n";
	//char* cellWebRequestNL2 = "NO LICENSE HAS BEEN FOUND\n";
	char* cellWebRequestNL2 = LicenseKey;
	char* cellWebRequestNL3 = "\n\n";
	char* cellWebRequestNL4 = "To activate license:\n";
	char* cellWebRequestNL5 = "Copy iLLiCiT.txt to\n";
	char* cellWebRequestNL6 = "/dev_hdd0/tmp/iLLiCiT.txt\n";
	char* cellWebRequestNL7 = "";
	
	char* cellWebRequestNL()
	{
		char buffer[250];
		sprintf(buffer, "%s%s%s%s%s%s%s", cellWebRequestNL1, cellWebRequestNL2, cellWebRequestNL3, cellWebRequestNL4, cellWebRequestNL5, cellWebRequestNL6, cellWebRequestNL7);
		return buffer;
	}
	//----------------------------------------------------------------------------
	*/
	
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


	



	//---------------------------------------------------------------------------------------------
	// Check Text Items For Alterations

	/*
	// Check Web Token
	void cellPS3EnumRandoms()
	{
		if (cellFSWebTokenTextOut[0] == cellFSWebTokenTextIn[0] && cellFSWebTokenTextOut[1] == cellFSWebTokenTextIn[1] && cellFSWebTokenTextOut[2] == cellFSWebTokenTextIn[2]) 
		{
			cellFSWebTokenIn = 3;
			cellFSWebTokenSend = true;
			cellFSWebTokenReceive = true;
		}

		else
		{
			cellFSWebTokenIn = 420;
			cellFSWebTokenSend = false;
			cellFSWebTokenReceive = false;
		}
	}
	*/

	
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
			cellPRXInt32 = false;
		}
		
		// Check Title Text Part 2
		if (cellReadFS2[0] == 'u') 
		{
			cellPRXInt16a = true;
		}

		else
		{
			cellPRXInt16a = false;
		}
		
		// Check Title Text Part 3
		if (cellReadFS3[0] == 'M') 
		{
			cellPRXInt16b = true;
		}

		else
		{
			cellPRXInt16b = false;
		}
		
		// Check Title Text Part 4
		if (cellReadFS4[0] == 'S') 
		{
			cellPRXInt16c = true;
		}

		else
		{
			cellPRXInt16c = false;
		}
		
		// Check Title Text Part 5
		if (cellReadFS5[0] == 'e') 
		{
			cellPRXInt16d = true;
		}

		else
		{
			cellPRXInt16d = false;
		}
		
		// Check Title Text Part 6
		if (cellReadFS6[0] == 'X') 
		{
			cellPRXInt16e = true;
		}

		else
		{
			cellPRXInt16e = false;
		}
		
		// Check Title Text Part 7
		if (cellReadFS7[0] == 'P') 
		{
			cellPRXInt16f = true;
		}

		else
		{
			cellPRXInt16f = false;
		}
		
		// Check Title Text Part 8
		if (cellReadFS8[0] == 'R') 
		{
			cellPRXInt16g = true;
		}

		else
		{
			cellPRXInt16g = false;
		}
		
		// Check Title Text Part 9
		if (cellReadFS9[0] == 'n') 
		{
			cellPRXInt16h = true;
		}

		else
		{
			cellPRXInt16h = false;
		}



		// Check Demo Evaluation Text Line 1
		if (cellReadUint1[0] == 'T' && cellReadUint1[1] == 'E' && cellReadUint1[2] == 'S' && cellReadUint1[3] == 'T' && cellReadUint1[4] == ' ' && cellReadUint1[5] == 'V' && cellReadUint1[6] == 'E' && cellReadUint1[7] == 'R' && cellReadUint1[8] == 'S' && cellReadUint1[9] == 'I' && cellReadUint1[10] == 'O' && cellReadUint1[11] == 'N') 
		{
			cellPRXInt64 = true;
		}

		else
		{
			cellPRXInt64 = false;
		}

		// Check Demo Evaluation Text Line 2 1st Half
		if (cellReadUint2[0] == 'F' && cellReadUint2[1] == 'O' && cellReadUint2[2] == 'R' && cellReadUint2[3] == ' ' && cellReadUint2[4] == 'E' && cellReadUint2[5] == 'V' && cellReadUint2[6] == 'A' && cellReadUint2[7] == 'L' && cellReadUint2[8] == 'U' && cellReadUint2[9] == 'A' && cellReadUint2[10] == 'T' && cellReadUint2[11] == 'I' && cellReadUint2[12] == 'O' && cellReadUint2[13] == 'N' && cellReadUint2[14] == ' ') 
		{
			cellPRXUint64 = true;
		}

		else
		{
			cellPRXUint64 = false;
		}

		// Check Demo Evaluation Text Line 2 2nd Half
		if (cellReadUint3[0] == 'P' && cellReadUint3[1] == 'U' && cellReadUint3[2] == 'R' && cellReadUint3[3] == 'P' && cellReadUint3[4] == 'O' && cellReadUint3[5] == 'S' && cellReadUint3[6] == 'E' && cellReadUint3[7] == 'S' && cellReadUint3[8] == ' ' && cellReadUint3[9] == 'O' && cellReadUint3[10] == 'N' && cellReadUint3[11] == 'L' && cellReadUint3[12] == 'Y') 
		{
			cellPRXUint128 = true;
		}

		else
		{
			cellPRXUint128 = false;
		}
		
		// Check Demo Evaluation Text Line 3
		if (cellReadUint4[0] == 'p' && cellReadUint4[1] == 's' && cellReadUint4[2] == '3' && cellReadUint4[3] == 'd' && cellReadUint4[4] == 'g' && cellReadUint4[5] == '.' && cellReadUint4[6] == 'c' && cellReadUint4[7] == 'o' && cellReadUint4[8] == 'm' && cellReadUint4[9] == '/' && cellReadUint4[10] == 'g' && cellReadUint4[11] == 't' && cellReadUint4[12] == 'a' && cellReadUint4[13] == '5') 
		{
			cellPRXUint32 = true;
		}
		
		else
		{
			cellPRXUint32 = false;
		}
		
		// Check Startup Splash Text Line 1
		if (cellWebRequest1[0] == 'W' && cellWebRequest1[1] == 'e' && cellWebRequest1[2] == 'l' && cellWebRequest1[3] == 'c' && cellWebRequest1[4] == 'o' && cellWebRequest1[5] == 'm' && cellWebRequest1[6] == 'e' && cellWebRequest1[7] == ' ' && cellWebRequest1[8] == 'T' && cellWebRequest1[9] == 'o' && cellWebRequest1[10] == ' ' && cellWebRequest1[11] == 'i' && cellWebRequest1[12] == 'L' && cellWebRequest1[13] == 'L' && cellWebRequest1[14] == 'i' && cellWebRequest1[15] == 'C' && cellWebRequest1[16] == 'i' && cellWebRequest1[17] == 'T' && cellWebRequest1[18] == '!') 
		{
			cellPRXUint256 = true;
		}
		
		else
		{
			cellPRXUint256 = false;
		}

		// Check Help -> About Text
		if (cellSendRequest1[0] == 'i' && cellSendRequest1[1] == 'L' && cellSendRequest1[2] == 'L' && cellSendRequest1[3] == 'i' && cellSendRequest1[4] == 'C' && cellSendRequest1[5] == 'i' && cellSendRequest1[6] == 'T') 
		{
			cellPRXUint512 = true;
		}

		else
		{
			cellPRXUint512 = false;
		}
		
		/*
		// Check Credits Splash
		if (cellWriteIntRequest1[0] == 'M' && cellWriteIntRequest1[1] == 'a' && cellWriteIntRequest1[2] == 'g' && cellWriteIntRequest1[3] == 'n'  && cellWriteIntRequest1[4] == 'u' && cellWriteIntRequest1[5] == 's') 
		{
			cellPRXInt8 = true;
		}

		else
		{
			cellPRXInt8 = false;
		}
		*/

		// Check Credits Splash
		// Skip this CHECK and force to TRUE 20151113
		cellPRXInt8 = true;
		

		

		// ANTI CHECKS COMPLETE



		// DOUBLE CHECK ANTI-FLAGS
		// Check all above appended for title and make a new BOOL to pass checks to
		if (cellPRXInt16a && cellPRXInt16b && cellPRXInt16c && cellPRXInt16d && cellPRXInt16e && cellPRXInt16f && cellPRXInt16g && cellPRXInt16h)
		{
			cellPRXInt16 = true;
		}

		else
		{
			cellPRXInt16 = false;
		}

		
		// TRIPLE CHECK ANTI-FLAGS
		// Check all above appended for title and make a new BOOL to pass checks to
		if (cellPRXInt8 && cellPRXInt16 && cellPRXInt32 && cellPRXInt64 && cellPRXUint64 && cellPRXUint32 && cellPRXUint128 && cellPRXUint256 && cellPRXUint512)
		{
			cellPRXInt4 = true;
		}

		else
		{
			cellPRXInt4 = false;
		}
	}
	//----------------------------------------------------------------------------



	


	/*
	// Check for alterations
	bool HasSpecialCharacters(const char *str)
	{
		return str[strspn(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_")] != 0;
	}
	*/
	

	/*
	// Check for alterations
	int cellFSFilesystem()
	//int cellFSFilesystem(const char *str)
	//void cellFSFilesystem(int dummy)
	{
		//const char cellFSinput1[] = "i";
		//const char cellFSinput2[] = "L";
		//const char cellFSinput3[] = "C";
		//const char cellFSinput4[] = "T";

		//const char* cellFSinput5 = cellReadFS;

		// i, L , L , i , C , i , T
		// 6, 13, 18, 20, 25, 30, 35  -> 47 total
		//const char cellFSmap[] = "uqlowiNsjdoTLasdvLvasdqhLsitaysClrbviaksyTkdldz";
		
		// Find 1st i (13)
		//const char cellFSmap1[] = "hsHYsojshtwoihhlhLLhjsYstdhjfkgGlkdlLHdkjuhtsD";
		
		// Find 1st L (16)
		//const char cellFSmap2[] = "hdgfuadgfafibghLhsffavGdkdHdshisggGksgKLZjgkdsA";
		
		// Find 2nd L (4)
		//const char cellFSmap3[] = "psoLIsustsdnDjJkFkjgaruiOHiFYdTYvkJuhgjhgFhYDFy";
		
		// Find 2nd i (40)
		//const char cellFSmap4[] = "sdyfYFSdsvkjsfdjJLlkSyfyuFuFhHFTDdTStrshijJFkgf";
		
		// Find C (8)
		//const char cellFSmap5[] = "raytsuYCFYUukfkjKjkKJhgdhdfhvjjhfdEDdkhHJFdhgUa";
		
		// Find 3rd i (15)
		//const char cellFSmap6[] = "qpLlghDdTRksqhiGgdStSSnjoUTdednhJJGdSHjhgJHFdjh";
		
		// Find T (46)
		//const char cellFSmap7[] = "ysoiFddhkLKKJfdaseyjljhgKjflkjdstrdkughlgStrsTo";

		
		int cellTest1;
		int cellTest2;
		int cellTest3;
		int cellTest4;
		int cellTest5;
		int cellTest6;
		int cellTest7;

		//cellTest1 = strcspn ("i", cellReadFS);
		//cellTest2 = strcspn ("L", cellReadFS);
		//cellTest3 = strcspn ("L", cellReadFS);
		//cellTest4 = strcspn ("i", cellReadFS);
		//cellTest5 = strcspn ("C", cellReadFS);
		//cellTest6 = strcspn ("i", cellReadFS);
		//cellTest7 = strcspn ("T", cellReadFS);

		//char cellTestNet[128];
		//sprintf(cellTestNet, "i is at position %d, %d, %d\nL is at position %d, %d\nC is at position %d\nT is at position %d\n", cellTest1 + 1, cellTest4 + 1, cellTest6 + 1, cellTest2 + 1, cellTest3 + 1, cellTest5 + 1, cellTest7 + 1);
		//PrintText(cellTestNet, 5000);
		//return 0;
		//return str[strcspn(str, "i")] != 0;

		int cellTestReturn = cellTest1 + cellTest2 + cellTest3 + cellTest4 + cellTest5 + cellTest6 + cellTest7;

		return cellTestReturn;

	}
	*/


	/*
	// Check for alterations
	bool HasFirstLetterBeenManipulated(const char *str)
	{
		return str[strspn(cellWebRequest, "W")] != 0;
	}
	*/





	/*
	void CheckCell()
	{
		std::string check();
		if (check.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_") != std::string::npos)
		{
			// Error
		}
	}
	*/


	/*
	char junk;
	if (sscanf(str, "%*[A-Za-z0-9_]%c", &junk))
	{
		// it has at least one "special" character
	}
	else
    // no special characters
	*/


	/*
	s.erase(std::remove_if(s.begin(), s.end(), my_predicate), s.end());
    bool my_predicate(char c)
    {
     return !(isalpha(c) || c=='_');
    }
	*/




};




#endif


