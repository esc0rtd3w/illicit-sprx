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

	int changeModelHack;

	bool isNeedForSpeed;
	
	bool isHydroJump;
	bool isAirJump; 

	bool HydraulicsHeightUp;
	bool HydraulicsHeightDown;
	bool HydraulicsHeightReset;
	
	int wantedLevel;

	bool isFreezePlayer;
	
	int dirtLevel;

	bool flyActiveNow;
	bool isFlyingCar;

	bool showPlayerIcon;

	bool isTalkingPlayerGettingMoney;

	int talkingPunishment;
	int talkSlot;
	
	int explosionType = 29;

	float* globalRandomCoords;
	
	bool isModder;
	int modderID;
	int cleanID;
	int isModderID;
	int modderList[15];
	char* modderNames[15];

	// Help Splashes for Some Menus
	int seenHelpMenuRank = 0;
	int seenHelpMoneyCoords = 0;
	int seenHelpSelectedPlayer = 0;
	int seenHelpVehicleManager = 0;
	int seenWarningGiveAllWeaponsLobby = 0;
	int seenWarningTalkingPunish = 0;
	
	//int rankValue;
	//int rankValueModifier = 2048;


	bool isMoneyControlButtons;

	// Button Names
	//int buttonCustom;
	int buttonNormal;
	char* buttonNormalName;

	
	bool moneyCoordsAdjustX_;
	bool moneyCoordsAdjustY_;
	bool moneyCoordsAdjustZ_;

	float moneyCoordsAdjustX = 0.0f;
	float moneyCoordsAdjustY = 0.0f;
	float moneyCoordsAdjustZ = 0.0f;


	char* networkText = "iLLiCiT SPRX Menu / Community ID: 5141";

	char* objectModel;
	bool spawnObjectRequest;


	bool requestLobbyTeleport;
	bool requestLobbyKick;

	
	//Entity aimedTarget;
	//Entity* aimedTargetP;
	//bool isAimedTargetActive;


	/*
	char* moneyPickupTypes[8] = { "PICKUP_MONEY_VARIABLE",
	"PICKUP_MONEY_CASE",
	"PICKUP_MONEY_WALLET",
	"PICKUP_MONEY_PURSE",
	"PICKUP_MONEY_DEP_BAG",
	"PICKUP_MONEY_MED_BAG",
	"PICKUP_MONEY_PAPER_BAG",
	"PICKUP_MONEY_SECURITY_CASE" };
	*/

	/*
	void ResetTimerTest(int dummy)
	{
		ResetGameTimer();
	}
	*/

	//bool adjustLR;
	//bool adjustUD;


	/*
	// Menu Colors
	//ColorSet menuTextHeader;
	//ColorSet menuTextFooter;
	ColorSet menuTextFooterLeft = Colors::Mixed::Teal2;
	ColorSet menuTextFooterCenter = Colors::Mixed::Teal2;
	ColorSet menuTextFooterRight = Colors::Mixed::Teal2;
	ColorSet menuTextTitle = Colors::Common::Orange;
	ColorSet menuTextSubTitle = Colors::Common::Teal;
	ColorSet menuTextMenuTitle = Colors::Common::Yellow;
	//ColorSet menuTextItem;
	ColorSet menuTextItemNotSelected = Colors::Common::White;
	ColorSet menuTextItemSelected = Colors::Dark::DarkOrange;
	ColorSet menuTextItemSelectedLeft = Colors::Dark::DarkOrange;
	ColorSet menuTextItemSelectedRight = Colors::Dark::DarkOrange;
	ColorSet menuTextItemSelectedHelp = Colors::Common::Teal;
	
	ColorSet menuBGMain = Colors::Common::Black;
	ColorSet menuBGMainDemo = Colors::Common::Red;
	ColorSet menuBGHeader = Colors::Common::Orange;
	ColorSet menuBGFooter = Colors::Common::Orange;
	//ColorSet menuBGTitle;
	ColorSet menuBGSubTitle = Colors::Mixed::Lime;
	//ColorSet menuBGItem;
	//ColorSet menuBGItemNotSelected;
	ColorSet menuBGItemSelected = Colors::Common::Yellow;
	*/


	// Debug Stuff
	bool debug = false;
	//bool debugMenuColors = false;

	
	// Menu Colors for Players
	//bool self__;
	//bool host__;
	//bool inveh__;


	// Menu Debug Output Text
	//bool debugMenuItems = false;
	//bool debugNetworkItems = true;
	//bool debugPlayers = true;
	
	float x_OffsetFollow;
	float DifFollow;
	float DifFooterFollow;
	int iFollow;
	int aFollow;
	const char* currentOptionFollow;
	int MenuFollow;
	int currentMenuFollow;
	bool currentMenuFollowMoney;

	
	// Menu Stuff
	const char* helpContextDisplay = "This Is A Sample Help Text\nEach Item Will Have A Unique Description";
	const char* helpContextItem;
	
	bool refreshMenuStruct;
	bool refreshMenuStructQueue;

	bool isMoneyToggleHighlight;
	bool isHostHighlight;
	bool isSelfHighlight;
	bool inVehHighlight;

	bool doSpawnObjectAttach;
	bool doSpawnObjectDeleteObject;
	bool doSpawnObjectAttachBuilder;
	int spawnObjectType;
	uint spawnObjectAttachFollow;
	//uint spawnPropHash;
	const char* spawnPropHashName;
	
	//bool showHeading = true;

	bool isSpeedometerActive;
	bool isSpeedometerBTTF;
	bool isBoostTriggered = false;
	bool disable88Temp;

	bool deleteLastSpawnedVehicle;

	char* funcArgCharP;
	bool isToggle;

	bool isHighlightedToggleActive;
	bool isHighlightedOptionToggleable;

	// Default Menu Counter
	int menuCounter = 0;
	int helpCounter = 0;
	int problemCounter = 0;

	bool hook2Active = false;


	bool showMenuHelpContextT = false;
	void ToggleMenuHelpContext(int dummy)
	{
		showMenuHelpContextT = !showMenuHelpContextT;
		showMenuHelpContext = showMenuHelpContextT;
		MsgToggleDefault("Help Context Menu", showMenuHelpContextT);
		//PrintText(showMenuHelpContextT ? "~g~Help Context Menu Enabled\n~b~Press CIRCLE to Activate" : "~r~Help Context Menu Disabled", 3000);
	}


	//float iplCoords;
	const char* iplTeleportLocation;

	/*
	void ShowCID(int dummy)
	{
		GetCID();
	}
	*/


	// Exit Thread
	// This may be useful for saving online???
	/*
	void ExitThread(int dummy)
	{
		isThreadExit = true;
	}
	*/

	/*
	void GetPlayerNamesTest()
	{
		for (int player=1; player <= 16; player++)
		char PlayerNames[] = { player };
	}
	*/

	bool isStopVehicleNow;
	bool hydraulicsActive;
	float hydraulicsHeight;
	int hydraulicsHeightAdjust;

	bool isCustomMoneySpawn;

	// Default Money Spawn Prop
	int hashProp = GET_HASH_KEY("prop_money_bag_01");


	// Player Stuff

	// This is active selected player name in menu
	int PlayerNow;
	
	char* NameCurrentFollow;
	int PlayerFollow;
	
	int isCloudAvailable;
	//int isNetworkSignedOnline;
	//int isNetworkSignedIn = NETWORK_IS_SIGNED_IN();// Social Club Signin

	bool isHostNow;

	// Set to Player 0 initially
	int isHostNowInt = 0;
	Any isHostNowAny = 0;

	bool isPlayerOnATrain;
	bool isPedInVehicle;

	Vector3 playerPos;
	
	uint PlayerID() {
		return PLAYER_ID(0);
	}

	Ped PlayerSelf() {
		return PLAYER_PED_ID();
	}

	int GetPlayerPedID(int player) {
		return GET_PLAYER_PED(player);
	}

	bool IsPedInAnyVehicle(int ped) {
		return IS_PED_IN_ANY_VEHICLE(ped, true);
	}

	
	int PlayerCount(){
		return NETWORK_GET_NUM_CONNECTED_PLAYERS();
	}

	
		
	

	int currentPlayer = PlayerSelf();

	// Players From Menu Stuff
	//const char* PlayerNames[16];
	int PlayerCurrent;
	char* NameCurrent;
	//char* Name;

	const char* modelHash;

	Ped SelectedPed;
	Ped playerPed;
	//int Player;
	//int PlayerCount;
	//int SelectedClient;


	//int isHostNowInt2;

	/*
	int test1()
	{
		array<int>^ arr = gcnew array<int>
		{0,1,2,5,7,8,11};

		int even=0, odd=0;

		for each (int i in arr) 
		{
			if (i%2 == 0) 
			even++;      
			else
			odd++; 
		}
	}
	*/

	BOOL NetworkGetControlOfEntity(int SelectedPlayer)
	{
		NETWORK_REQUEST_CONTROL_OF_ENTITY_ALT(GET_PLAYER_PED(SelectedPlayer));
		sleep(50);
		if (NETWORK_HAS_CONTROL_OF_ENTITY_ALT(GET_PLAYER_PED(SelectedPlayer)))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	/*
	int IsPlayerOnline(){
		if (is_player_online_stub() == 0)
			return 0;
		if (is_player_online_stub() == 1)
			return 1;
	}
	*/


	// Coordinates Stuff
	Vector3 pedCoords;
	Vector3 pedForward;
	float* pedCoordsFloat;
	float* pedForwardFloat;

	// Blip
	Vec3 blipCoords;	
	float* blipCoordsFloat;
	int waypointHandle;


	Vec3 GetEntityCoordsVec3(int ped) {
		return GET_ENTITY_COORDS(GET_PLAYER_PED(ped), true);
	}

	Vec3 GetPedCoordsVec3(int ped) {
		return GET_ENTITY_COORDS(GET_PLAYER_PED(ped), true);
	}
	
	Vector3 GetEntityCoordsXYZ(int ped) {
		return GET_ENTITY_COORDS_XYZ(GET_PLAYER_PED(ped), true);
	}
	
	Vector3 GetPedCoordsXYZ(int ped) {
		return GET_ENTITY_COORDS_XYZ(GET_PLAYER_PED(ped), true);
	}
	
	//Vector3P GetEntityCoordsPXYZ(int ped) {
		//return GET_ENTITY_COORDS_XYZ(GET_PLAYER_PED(ped), true);
	//}

	float* GetEntityCoordsFloat(int ped) {
		return Vec3toFloat(GET_ENTITY_COORDS(GET_PLAYER_PED(ped), true));
	}

	float* GetPedCoordsFloat(int ped) {
		return Vec3toFloat(GET_ENTITY_COORDS(GET_PLAYER_PED(ped), true));
	}
	
	float GetEntityHeadingVec3(int ped) {
		return GET_ENTITY_HEADING(GET_PLAYER_PED(ped));
	}

	Vector3 GetCoordsFromWorld(int ped) {
		return GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(GET_PLAYER_PED(ped), GET_ENTITY_COORDS(GET_PLAYER_PED(ped), true).x, GET_ENTITY_COORDS(GET_PLAYER_PED(ped), true).y, GET_ENTITY_COORDS(GET_PLAYER_PED(ped), true).z);
	}

	Vector3 GetCoordsBeforePedVector3(float distance){
		Vector3 pedCoords = GET_ENTITY_COORDS_XYZ(PlayerSelf(), true);
		Vector3 pedForward = GET_ENTITY_FORWARD_VECTOR(PlayerSelf());
		pedCoords.x = pedCoords.x + pedForward.x * distance;
		pedCoords.y = pedCoords.y + pedForward.y * distance;

		return pedCoords;
	}

	float* GetCoordsBeforePedFloat(float distance){
		float* pedCoordsFloat = Vec3toFloat(GET_ENTITY_COORDS(PlayerSelf(), true));
		//pedCoordsFloat = pedCoordsFloat * distance;
		return pedCoordsFloat;
	}


	
	

	/*
	Vector3 GetNetworkAllPlayersCoords(){
		for (int i = 0; i < PlayerCount(); i++)
		{
			if (GET_PLAYER_PED(i) > 0 && PlayerSelf() != GET_PLAYER_PED(i))
			{
				Ped playerPed = GET_PLAYER_PED(i);
				Vector3 playerPos = GET_ENTITY_COORDS_XYZ(playerPed, true);

				//char pCoords[128];
				//sprintf(pCoords, "Player: %i\nCoords: %i", playerPed, playerPos);
				//PrintText(pCoords, 3000);
			}
		}

		return playerPos;
	}
	*/


	/*
	Vector3 GetNetworkPlayersCoords(Player SelectedPlayer){
		Ped playerPed = GET_PLAYER_PED(SelectedPlayer);
		Vector3 playerPos = GET_ENTITY_COORDS_XYZ(playerPed, true);

		return playerPos;
	}
	*/


	/*
	float* GetNetworkPlayersCoordsFloat(Player SelectedPlayer){
		Ped playerPed = GET_PLAYER_PED(SelectedPlayer);
		Vec3 playerPos = GetEntityCoordsVec3(playerPed);
		float* pedCoordsFloat = Vec3toFloat(playerPos);

		return pedCoordsFloat;
	}
	*/


	// Vehicle Stuff
	
	const char* vehicleName;
	uint vehicleUint;


	
	bool isVehicleDensityMod;


	int GetCurrentVehicle(int ped) {
		return GET_VEHICLE_PED_IS_USING(ped);
	}

	int ClosestVehicleToPlayer(int ped) {
		return GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(GET_PLAYER_PED(ped), true)), 120, 0, 100);
	}

	Vec3 GetVehicleCoordsVec3(int ped) {
		return GET_ENTITY_COORDS(GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(GET_PLAYER_PED(ped), true)), 120, 0, 100), true);
	}

	float* GetVehicleCoordsFloat(int ped) {
		return Vec3toFloat(GET_ENTITY_COORDS(GET_CLOSEST_VEHICLE(Vec3toFloat(GET_ENTITY_COORDS(GET_PLAYER_PED(ped), true)), 120, 0, 100), true));
	}
	
	float GetVehicleHeadingVec3(int ped) {
		return GET_ENTITY_HEADING(GET_PLAYER_PED(ped));
	}




	// Teleport Stuff
	int location;
	float* coords;
	
	float* TeleportToClient(int SelectedPlayer)
	{
		entityCoords(0x10030000, GET_PLAYER_PED(SelectedPlayer));
		return ReadFloat(0x10030000, 3);
	}




	// Main Get Player Names
	
	//const char* PlayerName;

	//const char* PlayerNameSlot[16];
	/*
	int PlayerName[16];
	int GetAllPlayerNames()
	{
		//int Player = 0;
		for (int name = 0; name < 16; name++)
		{
			PlayerName = GET_PLAYER_NAME(name);
		}

		//Player++;
	}
	*/

	/*
	// Sticky Menu Items
	int thisMenuContext;
	int currentOptionContext;
	int currentMenuContext;
	int subOptionCountContext[99];
	int previousSubContext[99];
	int previousOptionContext[99];
	const char* subMenuTitleContext;
	const char* subOptionTextContext;
	void(*optionFunctionContext[99][99])(int);
	int optionFunctionParamContext[99][99];
	bool optionFunctionHookedContext[99][99];
	*/


	// Rope Stuff
	Object rope;

	

	// Bone Indexes
	

	//int Head = GET_PED_BONE_INDEX(currentPlayer, 31086);
	//const int RightWrist = GET_PED_BONE_INDEX(currentPlayer, 28422);
	//const int LeftWrist = GET_PED_BONE_INDEX(currentPlayer, 60309);
	//const int RightHand = GET_PED_BONE_INDEX(currentPlayer, 57005);
	//const int Chest = GET_PED_BONE_INDEX(currentPlayer, 24818);
	//const int Mouth = GET_PED_BONE_INDEX(currentPlayer, 39317);
	//const int LeftWrist = GET_PED_BONE_INDEX(currentPlayer, 18905);
	//const int LeftKnee = GET_PED_BONE_INDEX(currentPlayer, 63931);
	//const int RightKnee = GET_PED_BONE_INDEX(currentPlayer, 36864);
	//const int LeftShoe = GET_PED_BONE_INDEX(currentPlayer, 14201);
	//const int RightShoe = GET_PED_BONE_INDEX(currentPlayer, 52301);
	//const int Crotch = GET_PED_BONE_INDEX(currentPlayer, 51826);
	//const int Umbilical = GET_PED_BONE_INDEX(currentPlayer, 11816);
	//const int RightShoulder = GET_PED_BONE_INDEX(currentPlayer, 40269);
	//const int RightArm = GET_PED_BONE_INDEX(currentPlayer, 28252);
	//const int LeftShoulder = GET_PED_BONE_INDEX(currentPlayer, 45509);
	//const int LeftArm = GET_PED_BONE_INDEX(currentPlayer, 61163);

	Object objectFollow;


	// Misc Declarations

	float timecycleStrength;


	// Game Timer
	int gameTimer = GET_GAME_TIMER();
	int gameYear = GET_CLOCK_YEAR();
	int gameMonth = GET_CLOCK_MONTH();
	int gameHours = GET_CLOCK_HOURS();
	int gameMinutes = GET_CLOCK_MINUTES();
	int gameSeconds = GET_CLOCK_SECONDS();
	int gameDayWeek = GET_CLOCK_DAY_OF_WEEK();
	int gameDayMonth = GET_CLOCK_DAY_OF_MONTH();


	// Menu Timer
	bool newTimerTickTrace;
	int maxTimerCountTrace;
	int tickTimeTrace;


	int Arg1;
	int Arg2;
	int Arg3;

	int ModelHash;
	int PickupHash;

	
	// Just some DUMMIES!!!
	//bool dummyBool;
	//bool* dummyBoolPointer;
	//float dummyFloat;
	//float* dummyFloatPointer;
	//int dummyInt;
	//int* dummyIntPointer;
	//char dummyChar;
	//char* dummyCharPointer;
	//const char dummyConstChar;
	//const char* dummyContCharPointer;
	

	// Shameless Credit Tag ;)
	// Anti-Check*
	char* creditTag = cellRequestPPU;


	// Rotation Stuff
	float rotX;
	float rotY;
	float rotZ;

	
	// Color Name Changer Function
	int nc_tick = 0;
	int nc_delay = 500;
	char* nc_colors[] = { "~p~", "~b~", "~l~", "~g~", "~y~", "~r~", "~o~", "~m~", "~w~", "~h~" };
	size_t nc_len = sizeof(nc_colors) / sizeof(char);

	
	void ColorCycleName()
	{
		if (GET_GAME_TIMER() - nc_tick > nc_delay)
		{
			char nc_buf[42];
			int rng = irand(0, nc_len);
			strcpy(nc_buf, nc_colors[rng]);
			strcat(nc_buf, GET_PLAYER_NAME(PlayerSelf()));
			strcat(nc_buf, "\0");
			nc_tick = GET_GAME_TIMER();
		}
	}





	struct PlayersLastVehicleList
	{
		int LastVehicleID, LastVehicleSlot;
	};


	// Vehicle Stuff

	bool firstTimeVehicleSpawnHasHappened;
	uint maxVehicleSpawn = 49;
	uint numberOfSpawnedVehicles;
	uint spawnedVehicleList[49];

	bool wheelTypeActive;

	bool inVehicle;
	
	
	uint maxObjectSpawn = 49;
	uint numberOfSpawnedObjects;
	uint spawnedObjectList[49];
	const char* spawnedObjectName;
	
	// Players Current Vehicle
	int playersCurrentVehicle;
	//Vehicle currentVehicle;

	// Players Last Vehicle
	int playersLastVehicle;
	int playersLastVehicleAdd;
	int playersLastVehicleRemove;
	int playersLastVehicleAppend;
	int playersLastVehicleEdit;
	int playersLastVehicleMoveUp;
	int playersLastVehicleMoveDown;

	
	// Vehicle Toggles
	bool areDoorsOpen;
	bool isWindowSmashed;
	bool isWindowDown;
	bool areVehicleBrightsOn;
	bool areVehicleLightsOn;


	// Presets and Mixed Stuff
	//bool playerGodmode;
	//bool playerInfAmmo;
	bool playerWanted;


	// Peds Stuff
	bool firstTimeCloneHasHappened;
	bool firstTimeSpawnHasHappened;
	int numberOfSpawnedPeds;
	int numberOfTimesCloned;



	bool moneySpawning = true;



	// System Toggles

	// Vehicle Stuff
	bool godmodeOnVehicleSpawn = true;
	bool maxoutOnVehicleSpawn = true;
	bool godmodeOnVehicleMaxOut = true;
	bool spawnVehiclesOnline = true;
	int currentVehicle;

	// Button Bind Options
	bool bindTurnSignals = false;

	


	// Used for passing info to debug output
	//char* DebugOutputText;
	//const char** DebugOutputText2;
	//const char* DebugOutputText3;
	//int DebugOutputInt;
	//int DebugOutputIntFont;
	//int DebugOutputIntFloatX;
	//int DebugOutputIntFloatY;
	//int DebugOutputIntScaleX;
	//int DebugOutputIntScaleY;
	//ColorSet DebugOutputTextColor;
	//int DebugOutputIntAlpha;
	//bool DebugOutputCentered;
	// Returns back to string
	//char* DebugOutputValue;


	// Debug Menu Stuff To Print
	//char* DebugCurrentMenuName;
	//char* DebugSubOptionCount;
	//char* DebugSubMenuTitleCurrentMenu;






	// Multi Use Number Array
	float* numArray;


	// Name Change Stuff
	bool NameChanged;
	const char* NewName;
	const char* newName;


	// Some Player Stuff
	int PlayerSelected;
	int Self;

	
	//--------------------------------------------------------------------------------
	// DPAD LEFT and RIGHT STUFF
	char* dpadAdjustType;

	int wheelType;
	int modType;
	int modIndex;
	int modVariation;

	void PlayerSelectedNext()
	{
		switch(PlayerSelected)
		{
			case 0: PlayerSelected = 1;
				break;
			case 1: PlayerSelected = 2;
				break;
			case 2: PlayerSelected = 3;
				break;
			case 3: PlayerSelected = 4;
				break;
			case 4: PlayerSelected = 5;
				break;
			case 5: PlayerSelected = 6;
				break;
			case 6: PlayerSelected = 7;
				break;
			case 7: PlayerSelected = 8;
				break;
			case 8: PlayerSelected = 9;
				break;
			case 9: PlayerSelected = 10;
				break;
			case 10: PlayerSelected = 11;
				break;
			case 11: PlayerSelected = 12;
				break;
			case 12: PlayerSelected = 13;
				break;
			case 13: PlayerSelected = 14;
				break;
			case 14: PlayerSelected = 15;
				break;
			case 15: PlayerSelected = 0;
				break;
		}
	}

	void PlayerSelectedPrev()
	{
		switch(PlayerSelected)
		{
			case 0: PlayerSelected = 15;
				break;
			case 1: PlayerSelected = 0;
				break;
			case 2: PlayerSelected = 1;
				break;
			case 3: PlayerSelected = 2;
				break;
			case 4: PlayerSelected = 3;
				break;
			case 5: PlayerSelected = 4;
				break;
			case 6: PlayerSelected = 5;
				break;
			case 7: PlayerSelected = 6;
				break;
			case 8: PlayerSelected = 7;
				break;
			case 9: PlayerSelected = 8;
				break;
			case 10: PlayerSelected = 9;
				break;
			case 11: PlayerSelected = 10;
				break;
			case 12: PlayerSelected = 11;
				break;
			case 13: PlayerSelected = 12;
				break;
			case 14: PlayerSelected = 13;
				break;
			case 15: PlayerSelected = 14;
				break;
		}
	}

	void ExplosionSelectNext()
	{
		switch(explosionType)
		{
			case 0: explosionType = 1;
				break;
			case 1: explosionType = 2;
				break;
			case 2: explosionType = 3;
				break;
			case 3: explosionType = 4;
				break;
			case 4: explosionType = 5;
				break;
			case 5: explosionType = 6;
				break;
			case 6: explosionType = 7;
				break;
			case 7: explosionType = 8;
				break;
			case 8: explosionType = 9;
				break;
			case 9: explosionType = 10;
				break;
			case 10: explosionType = 11;
				break;
			case 11: explosionType = 12;
				break;
			case 12: explosionType = 13;
				break;
			case 13: explosionType = 14;
				break;
			case 14: explosionType = 15;
				break;
			case 15: explosionType = 16;
				break;
			case 16: explosionType = 17;
				break;
			case 17: explosionType = 18;
				break;
			case 18: explosionType = 19;
				break;
			case 19: explosionType = 20;
				break;
			case 20: explosionType = 21;
				break;
			case 21: explosionType = 22;
				break;
			case 22: explosionType = 23;
				break;
			case 23: explosionType = 24;
				break;
			case 24: explosionType = 25;
				break;
			case 25: explosionType = 26;
				break;
			case 26: explosionType = 27;
				break;
			case 27: explosionType = 28;
				break;
			case 28: explosionType = 29;
				break;
			case 29: explosionType = 30;
				break;
			case 30: explosionType = 31;
				break;
			case 31: explosionType = 32;
				break;
			case 32: explosionType = 33;
				break;
			case 33: explosionType = 34;
				break;
			case 34: explosionType = 35;
				break;
			case 35: explosionType = 36;
				break;
			case 36: explosionType = 37;
				break;
			case 37: explosionType = 38;
				break;
			case 38: explosionType = 39;
				break;
			case 39: explosionType = 40;
				break;
			case 40: explosionType = 0;
				break;
		}
	}

	void ExplosionSelectPrev()
	{
		switch(explosionType)
		{
			case 0: explosionType = 40;
				break;
			case 1: explosionType = 0;
				break;
			case 2: explosionType = 1;
				break;
			case 3: explosionType = 2;
				break;
			case 4: explosionType = 3;
				break;
			case 5: explosionType = 4;
				break;
			case 6: explosionType = 5;
				break;
			case 7: explosionType = 6;
				break;
			case 8: explosionType = 7;
				break;
			case 9: explosionType = 8;
				break;
			case 10: explosionType = 9;
				break;
			case 11: explosionType = 10;
				break;
			case 12: explosionType = 11;
				break;
			case 13: explosionType = 12;
				break;
			case 14: explosionType = 13;
				break;
			case 15: explosionType = 14;
				break;
			case 16: explosionType = 15;
				break;
			case 17: explosionType = 16;
				break;
			case 18: explosionType = 17;
				break;
			case 19: explosionType = 18;
				break;
			case 20: explosionType = 19;
				break;
			case 21: explosionType = 20;
				break;
			case 22: explosionType = 21;
				break;
			case 23: explosionType = 22;
				break;
			case 24: explosionType = 23;
				break;
			case 25: explosionType = 24;
				break;
			case 26: explosionType = 25;
				break;
			case 27: explosionType = 26;
				break;
			case 28: explosionType = 27;
				break;
			case 29: explosionType = 28;
				break;
			case 30: explosionType = 29;
				break;
			case 31: explosionType = 30;
				break;
			case 32: explosionType = 31;
				break;
			case 33: explosionType = 32;
				break;
			case 34: explosionType = 33;
				break;
			case 35: explosionType = 34;
				break;
			case 36: explosionType = 35;
				break;
			case 37: explosionType = 36;
				break;
			case 38: explosionType = 37;
				break;
			case 39: explosionType = 38;
				break;
			case 40: explosionType = 39;
				break;
		}
	}
	//--------------------------------------------------------------------------------
	
	/*
	void WantedLevelIncrease()
	{
		switch(wantedLevel)
		{
			case 0:
				wantedLevel = 1;
				break;
			case 1:
				wantedLevel = 2;
				break;
			case 2:
				wantedLevel = 3;
				break;
			case 3:
				wantedLevel = 4;
				break;
			case 4:
				wantedLevel = 5;
				break;
			case 5:
				wantedLevel = 0;
				break;
		}
						
		SET_MAX_WANTED_LEVEL(5);
		SET_PLAYER_WANTED_LEVEL(PlayerSelf(), wantedLevel, false);
		SET_PLAYER_WANTED_LEVEL_NOW(PlayerSelf(), false);

		//char buffer[64];
		//sprintf(buffer, "~w~Wanted Level ~r~Decreased", rankValueModifier);
		//PrintText(buffer);
	}
	

	void WantedLevelDecrease()
	{
		switch(wantedLevel)
		{
			case 0:
				wantedLevel = 5;
				break;
			case 1:
				wantedLevel = 0;
				break;
			case 2:
				wantedLevel = 1;
				break;
			case 3:
				wantedLevel = 2;
				break;
			case 4:
				wantedLevel = 3;
				break;
			case 5:
				wantedLevel = 4;
				break;
		}
						
		SET_MAX_WANTED_LEVEL(5);
		SET_PLAYER_WANTED_LEVEL(PlayerSelf(), wantedLevel, false);
		SET_PLAYER_WANTED_LEVEL_NOW(PlayerSelf(), false);

		//char buffer[64];
		//sprintf(buffer, "~w~Wanted Level ~r~Decreased", rankValueModifier);
		//PrintText(buffer);
	}
	*/


	// Main model hash name
	const char* model;

	// Using modelc for selecting from menu by number
	int modelc;


	/*
	int ClonePedx(uint PedHandle)
	{
		return CLONE_PED(PedHandle, GET_ENTITY_HEADING(PedHandle), 1, 1);
	}
	*/



	// For Time Cycle Modifier
	//const char* setTimeCycleStyle;



	// Extra HUD Overlay Stuff
	bool hudOverlay = true;


	

	struct waypoint
	{
		float x, y;
	};
	

	};




	// Threading
	//int threadIDPrevious;
	//int threadIDNew;
	//bool isThreadPreviousActive;
	//bool isThreadNewActive;



	typedef enum ExternalFile
	{
		ext_License,
		ext_Settings,
	} ExternalFile;



	





#endif







