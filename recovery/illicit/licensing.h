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
	char* LicenseType = "Paid Version";

	
	// FAKE DEMO TIMER
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


};




#endif




