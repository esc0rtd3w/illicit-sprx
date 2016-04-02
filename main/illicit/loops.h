#ifndef __LOOPS_H
#define __LOOPS_H

#include "hud.h"


using namespace Hud;


//----------------------------------------------------
// Loops


bool isThreadExit;

// Menu Colors for Players
//bool self_;
//bool host_;
//bool inveh_;

bool addVehicleToPhone;


bool adjustPlayerSelect = true;
int adjustRankIncrease = 1024;


bool isDebugPlayersActive;
bool isDebugNetworkActive;

// Used for help context on menu
//bool isHelpContext;
bool showMenuHelpContext;
//bool hideMenuHelpContext;

bool systemCheckActive;

bool showWorldDateTime;

bool isKeyboardActive;
bool isKeyboardDisplayed;

char* oskResult;

bool isTeleportToTalking;

bool disablePedTasks;
bool punishTalkingPlayers;
bool allPlayersFrozen;
bool isLobbyExplode;
bool isFreezeLobby;

bool applyDamageToLobby;

bool changeModelRequest;


bool deleteVehicle;

// Nearby Car Stuff

bool isNearbyCarMayhem;
bool isNearbyCarMayhemBoost;
bool isNearbyCarMayhemExplode;
bool isNearbyCarMayhemUltimate;
bool isNearbyCarDetectActive;
bool isControlAllNearbyVehicles;

bool isTorqueModifierActive;
int torqueValue;

bool isTorqueModifierNearbyActive;
int torqueValueNearby;

bool areBlinkersActive;

bool clearLobbyProps;


bool isPlayerCycle = true;

bool isOnlyPlayerPlaying;
bool isPlayerPlayingOnline;
bool isPlayerOnFire;
bool isFireActive;

bool isFlyModeActive;

bool isVehicleSpawnRequest;

bool isMoneyVehicle;
bool isMoneyVehicleActive;
bool isMoneyVehicleCheck;
uint vehOnlineFollow;

bool isMoneyCoordsAdjust;
bool isMoneySpawningOnLobby;
bool isMoneySpawningOnPlayer;
bool isMoneySpawningOnVehicleForNearbyCars;
bool isMoneySpawningOnVehicle;
char* moneySpawnProp;
	

bool isVehicleJitterActive;

bool isUpdateVehicleManager;
bool isUpdatePlayersMenu;

bool isSpeedBoostBinded;
bool isSpeedBoostActive;
int speedBoostValue = 100;
int speedBoostDirection;
int speedBoostAdjust(int direction, int amount)
{
	// 0 is UP   1 is DOWN
	switch (direction) 
	{ 
		case 0: speedBoostValue = speedBoostValue + amount; 
		case 1: speedBoostValue = speedBoostValue - amount;
	}
			
	char test[16];
	sprintf(test, "Boost: %i", speedBoostValue);
	PrintText(test, 3000);
};

bool isNetworkPlayerTalking;

bool isSuperJumpActive;
bool isSuperRunActive;
bool isSuperSwimActive;

bool isParachuteOpen;
bool isParachuteSmokeEnabled;

bool isFireFeetActive;
bool isShowCoordsActive;
bool isWantedLevelOn;
bool isColorNameChange;
bool isPlayerGodmodeActive;
bool playerGodmode;



// Peds
bool isPedFleeing;
bool isPedWet;


//bool ifWaterModify;
int waterLevel;



//bool isTimeFrozen;

//bool isWeatherLooped;


//bool particleFxCoordsActive;
//bool particleFxEntityActive;




// Weapons
bool isAmmoExplosive;
bool isAmmoFire;
bool isMeleeExplosive;



#endif
