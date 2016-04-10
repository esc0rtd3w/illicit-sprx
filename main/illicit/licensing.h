#ifndef __LICENSING_H
#define __LICENSING_H


#include "anti.h"
#include "core.h"
#include "hud.h"
#include "natives.h"

//using namespace cellFSWriteInt_;
using namespace Hud;
using namespace Natives;


namespace Licensing
{
	// If DEMO set TRUE
	// If FALSE means FULL VERSION
	bool demoMode = false;

	// If DEMO set TRUE
	// If FALSE means FULL VERSION
	// THIS ONE ONLY USED FOR TEXT
	bool demoModeText = false;

	// If DEMO set FALSE
	// If TRUE means FULL VERSION
	bool notDemo = true;

	// If DEMO set TRUE
	// If FALSE means ACTIVATED
	bool notActivated = false;

	//bool runDemoTimer;

	
	// License Key
	char* LicenseKey;
	char* LicenseText;
	char* LicenseFile;
	//char* LicenseKey = "694c4c69436954";
	bool LicenseVerified;
	

	// Different License Types
	//char* LicenseType[4] = { "Demo", "Free Demo", "Preview", "Paid Version" };
	//char* LicenseType = "Demo";
	//char* LicenseType = "Free Demo";
	//char* LicenseType = "Preview";
	char* LicenseType = "Paid Version";

	//int LicenseTypeCheckDemo = 1;
	//int LicenseTypeCheckDemoFree = 2;
	//int LicenseTypeCheckPreview = 3;
	//int LicenseTypeCheckPaid = 4;

	// This must match current license type
	//int LicenseTypeCheck = LicenseTypeCheckPaid;


	// Real remaining time (TOTAL - GET_GAME_TIMER)
	int demoTimeRemaining;

	// Total Time In Milliseconds
	int demoTimeTotal = 1812639;
	//const int demoTimeTotal = 3000;
	int demoTimeTick = GET_GAME_TIMER();

	
	// Read License File
	int fdl;
	char licStr[32];
	CellFsErrno readLic;
	uint64_t swl, srl;
	void CheckLicense()
	{
		LicenseFile = "/dev_hdd0/tmp/iLLiCiT.txt";

		readLic = cellFsOpen(LicenseFile, CELL_FS_O_RDONLY, &fdl, NULL, 0);

		if (readLic == 0)
		{
			cellFsRead(fdl, licStr, sizeof(licStr), &swl);
			LicenseKey = licStr;
			cellFsClose(fdl);
			
			LicenseVerified = false;

			if (LicenseKey == "FN52L-9YXVP-17TRZ")
			{
				LicenseVerified = true;
			}
		}
	}


	namespace TimeBomb
	{
		// DEMO Timer Stuff


		/*
		int DemoTimeRemaining()
		{
			demoTimeRemaining = demoTimeTotal - GET_GAME_TIMER();
			return demoTimeRemaining;
		}
		*/

	};


	namespace KeyGen
	{
		// Generate random number sequences
		
		//int random_s = irand(1, 9);
		//int random_d = irand(10, 99);
		//int random_t = irand(100, 999);
		
		//int garbage = (random_s * random_d / random_t * random_d + random_d * random_s - random_t);
		//int seed = random_t;
		
		//int key1 = random_s + random_d + random_t + garbage;
		//int key2 = seed + random_d + random_t + garbage / random_s;

		//int key1;
		//int key2;

		//key1 = irand(1001, 100001);
		//key2 = irand(500005, 5000005);

		/*
		void KeygenTest(int dummy)
		{
			char keygenText[128];
			sprintf(keygenText, "~w~Key1: ~y~%i\n~w~Key2: ~y~%i", key1, key2);
			PrintText(keygenText, 5000);
		}
		*/




	};



};




#endif




