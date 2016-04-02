#ifndef __MISC_H
#define __MISC_H


#include "anti.h"
#include "buttons.h"
#include "colors.h"
#include "hud.h"

using namespace cellFSWriteInt_;
using namespace Colors;
using namespace Hud;
using namespace Natives;




namespace Misc
{
	
	// Directly Write To Memory
	void WriteMemoryDirect(int address, int value)
	{
		int memoryAddress = (*(int*)address) + 4;
		{
			if (memoryAddress != 0)
			{
				*(int*)address = value;
			}
		}
	}


	bool isMenuSoundUpDown;
	int isMenuSoundUpDown_;
	int isMenuSoundUpDown__;
	const char* isMenuSoundUpDown___;
	
	bool isMenuSoundSplash;
	//int isMenuSoundSplash_;
	//int isMenuSoundSplash__;

	bool isMenuSoundSelect;
	int isMenuSoundSelect_;
	int isMenuSoundSelect__;

	bool isMenuSoundBack;

	int rankValueModifier;

	
	float x_OffsetFollow;
	float DifFollow;
	float DifFooterFollow;
	int iFollow;
	int aFollow;
	const char* currentOptionFollow;
	int MenuFollow;
	int currentMenuFollow;
	bool currentMenuFollowMoney;

	
	

	// Default Menu Counter
	int menuCounter = 0;
	int helpCounter = 0;
	int problemCounter = 0;

	bool hook2Active = false;


	char* NameCurrentFollow;
	int PlayerFollow;
	
	int isCloudAvailable;

	
	uint PlayerID() {
		return PLAYER_ID(0);
	}

	Ped PlayerSelf() {
		return PLAYER_PED_ID();
	}
	

	int currentPlayer = PlayerSelf();

	int PlayerCurrent;
	char* NameCurrent;
	//char* Name;

	const char* modelHash;

	Ped SelectedPed;
	Ped playerPed;

	


	// Name Change Stuff
	bool NameChanged;
	const char* NewName;
	const char* newName;


	// Some Player Stuff
	int PlayerSelected;
	int Self;



	};


	

#endif







