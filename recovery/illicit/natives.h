#ifndef __NATIVES_H
#define __NATIVES_H


#include "addresses.h"
#include "core.h"
#include "natives.h"
#include "types.h"


namespace Natives
{
	
	
	//---------------------------------------------------------------------------------------------//
	// Text Display

	opd_s _Snprintf = { Addresses::Addresses_Natives::Text_a::Snprintf, TOC };
	int(*snprintf)(char * s, size_t n, const char * format, ...) = (int(*)(char*, size_t, const char*, ...))&_Snprintf;
	
	opd_s _ARE_STRINGS_EQUAL = { Addresses::Addresses_Natives::Text_a::ARE_STRINGS_EQUAL, TOC };
	BOOL(*ARE_STRINGS_EQUAL)(char *string1, char *string2) = (BOOL(*)(char*, char*))&_ARE_STRINGS_EQUAL;

	opd_s _COMPARE_STRINGS = { Addresses::Addresses_Natives::Text_a::COMPARE_STRINGS, TOC };
	int(*COMPARE_STRINGS)(char *str1, char *str2, BOOL matchCase, int maxLength) = (int(*)(char*, char*, BOOL, int))&_COMPARE_STRINGS;

	opd_s _DRAW_TEXT = { Addresses::Addresses_Natives::Text_a::DRAW_TEXT, TOC };
	int(*DRAW_TEXT)(float x, float y) = (int(*)(float, float))&_DRAW_TEXT;

	opd_s _ADD_TEXT_COMPONENT_STRING = { Addresses::Addresses_Natives::Text_a::ADD_TEXT_COMPONENT_STRING, TOC };
	int(*ADD_TEXT_COMPONENT_STRING)(const char *text) = (int(*)(const char *))&_ADD_TEXT_COMPONENT_STRING;
	
	opd_s _ADD_TEXT_COMPONENT_ITEM_STRING = { Addresses::Addresses_Natives::Text_a::ADD_TEXT_COMPONENT_ITEM_STRING, TOC };
	int(*ADD_TEXT_COMPONENT_ITEM_STRING)(char* labelName) = (int(*)(char*))&_ADD_TEXT_COMPONENT_ITEM_STRING;
	
	opd_s _SET_TEXT_FONT = { Addresses::Addresses_Natives::Text_a::SET_TEXT_FONT, TOC };
	int(*SET_TEXT_FONT)(int Font) = (int(*)(int))&_SET_TEXT_FONT;

	opd_s _SET_TEXT_SCALE = { Addresses::Addresses_Natives::Text_a::SET_TEXT_SCALE, TOC };
	int(*SET_TEXT_SCALE)(float x, float y) = (int(*)(float, float))&_SET_TEXT_SCALE;

	opd_s _SET_TEXT_COLOUR = { Addresses::Addresses_Natives::Text_a::SET_TEXT_COLOUR, TOC };
	int(*SET_TEXT_COLOUR)(int r, int g, int b, int a) = (int(*)(int, int, int, int))&_SET_TEXT_COLOUR;

	opd_s _SET_TEXT_WRAP = { Addresses::Addresses_Natives::Text_a::SET_TEXT_WRAP, TOC };
	int(*SET_TEXT_WRAP)(float x, float y) = (int(*)(float, float))&_SET_TEXT_WRAP;

	opd_s _SET_TEXT_CENTRE = { Addresses::Addresses_Natives::Text_a::SET_TEXT_CENTRE, TOC };
	int(*SET_TEXT_CENTRE)(bool a) = (int(*)(bool))&_SET_TEXT_CENTRE;

	opd_s _SET_TEXT_DROPSHADOW = { Addresses::Addresses_Natives::Text_a::SET_TEXT_DROPSHADOW, TOC };
	int(*SET_TEXT_DROPSHADOW)(int p0, int p1, int p2, int p3, int p4) = (int(*)(int, int, int, int, int))&_SET_TEXT_DROPSHADOW;

	opd_s _SET_TEXT_OUTLINE = { Addresses::Addresses_Natives::Text_a::SET_TEXT_OUTLINE, TOC };
	int(*SET_TEXT_OUTLINE)() = (int(*)())&_SET_TEXT_OUTLINE;

	opd_s _SET_TEXT_ENTRY = { Addresses::Addresses_Natives::Text_a::SET_TEXT_ENTRY, TOC };
	int(*SET_TEXT_ENTRY)(const char* type) = (int(*)(const char*))&_SET_TEXT_ENTRY;
	
	opd_s _PRINT_TEXT_TIME = { Addresses::Addresses_Natives::Text_a::PRINT_TEXT_TIME, TOC };
	int(*PRINT_TEXT_TIME)(int) = (int(*)(int))&_PRINT_TEXT_TIME;

	opd_s _PRINT_TEXT_TYPE = { Addresses::Addresses_Natives::Text_a::PRINT_TEXT_TYPE, TOC };
	int(*PRINT_TEXT_TYPE)(const char*) = (int(*)(const char*))&_PRINT_TEXT_TYPE;
	
	opd_s _STRING_TO_INT = { Addresses::Addresses_Natives::Text_a::STRING_TO_INT, TOC };
	BOOL(*STRING_TO_INT)(char *string, int *outInteger) = (BOOL(*)(char*, int*))&_STRING_TO_INT;
	
	opd_s _NOTIFICATION_TYPE = { Addresses::Addresses_Natives::Text_a::NOTIFICATION_TYPE, TOC };
	int(*NOTIFICATION_TYPE)(char* type) = (int(*)(char*))&_NOTIFICATION_TYPE;
	
	opd_s _TIME_TO_DISPLAY = { Addresses::Addresses_Natives::Text_a::TIME_TO_DISPLAY, TOC };
	int(*TIME_TO_DISPLAY)(int time) = (int(*)(int))&_TIME_TO_DISPLAY;
	
	

	/*
	picName1 & picName2 must match. Possibilities: "CHAR_DEFAULT", "CHAR_FACEBOOK", "CHAR_SOCIAL_CLUB".
	flash is a bool for fading in.
	iconTypes:
	1 : Chat Box
	2 : Email
	3 : Add Friend Request
	4 : Nothing
	5 : Nothing
	6 : Nothing
	7 : Right Jumping Arrow
	8 : RP Icon
	9 : $ Icon

	"sender" is the very top header. This can be any old string.
	"subject" is the header under the sender.
	*/
	opd_s _SET_NOTIFICATION_MESSAGE = { Addresses::Addresses_Natives::Text_a::SET_NOTIFICATION_MESSAGE, TOC };
	int(*SET_NOTIFICATION_MESSAGE)(char* picName1, char* picName2, BOOL flash, int iconType, char* sender, char* subject) = (int(*)(char*, char*, BOOL, int, char*, char*))&_SET_NOTIFICATION_MESSAGE;
	//---------------------------------------------------------------------------------------------//



	//---------------------------------------------------------------------------------------------//
	// Draw
	
	opd_s _DRAW_LIGHT_WITH_RANGE = { Addresses::Addresses_Natives::Draw_a::DRAW_LIGHT_WITH_RANGE, TOC };
	void(*DRAW_LIGHT_WITH_RANGE)(float x, float y, float z, int r, int g, int b, float range, float intensity) = (void(*)(float, float, float, int, int, int, float, float))&DRAW_LIGHT_WITH_RANGE;
	
	opd_s _DRAW_RECT = { Addresses::Addresses_Natives::Draw_a::DRAW_RECT, TOC };
	void(*DRAW_RECT)(float, float, float, float, int, int, int, int) = (void(*)(float, float, float, float, int, int, int, int))&_DRAW_RECT;

	opd_s _DRAW_SPRITE = { Addresses::Addresses_Natives::Draw_a::DRAW_SPRITE, TOC };
	void(*DRAW_SPRITE)(char *textureDict, char *textureName, float screenX, float screenY, float scaleX, float scaleY, float heading, int colorR, int colorG, int colorB, int colorA) = (void(*)(char*, char*, float, float, float, float, float, int, int, int, int))&_DRAW_SPRITE;
	

	/*
	Draws a notification above the map and returns the notifications handle

	Text should be set using _ADD_TEXT_COMPONENT_STRING.

	Color syntax:
	~r~ = Red
	~b~ = Blue
	~g~ = Green
	~y~ = Yellow
	~p~ = Purple
	~o~ = Orange
	~c~ = Grey)
	~m~ = Darker Grey
	~u~ = Black
	~n~ = New Line
	~s~ = Default White
	~h~ = Bold Text

	Special characters:
	¦ = Rockstar Verified Icon (U+00A6:Broken Bar - Alt+0166)
	÷ = Rockstar Icon (U+00F7:Division Sign - Alt+0247)
	? = Rockstar Icon 2 (U+2211:N-Ary Summation)
	*/
	opd_s _DRAW_NOTIFICATION = { Addresses::Addresses_Natives::Draw_a::DRAW_NOTIFICATION, TOC };
	void(*DRAW_NOTIFICATION)(BOOL blink, BOOL p1) = (void(*)(BOOL, BOOL))&_DRAW_NOTIFICATION;

	
	opd_s _DRAW_MARKER = { Addresses::Addresses_Natives::Draw_a::DRAW_MARKER, TOC };
	void(*DRAW_MARKER)(int type, float x, float y, float z, float dirX, float dirY, float dirZ, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ, Any colorR, Any colorG, Any colorB, int alpha, BOOL bobUpAndDown, BOOL faceCamera, int p19, BOOL rotate, char *textureDict, char *textureName, BOOL drawOnEnts) = (void(*)(int, float, float, float, float, float, float, float, float, float, float, float, float, Any, Any, Any, int, BOOL, BOOL, int, BOOL, char*, char*, BOOL))&_DRAW_MARKER;

	opd_s _SET_DRAW_ORIGIN = { Addresses::Addresses_Natives::Draw_a::SET_DRAW_ORIGIN, TOC };
	void(*SET_DRAW_ORIGIN)(float x, float y, float z, Any p3) = (void(*)(float, float, float, Any))&_SET_DRAW_ORIGIN;

	opd_s _REQUEST_STREAMED_TEXTURE_DICT = { Addresses::Addresses_Natives::Draw_a::REQUEST_STREAMED_TEXTURE_DICT, TOC };
	void(*REQUEST_STREAMED_TEXTURE_DICT)(char *textureDict, BOOL toggle) = (void(*)(char*, BOOL))&_REQUEST_STREAMED_TEXTURE_DICT;

	opd_s _HAS_STREAMED_TEXTURE_DICT_LOADED = { Addresses::Addresses_Natives::Draw_a::HAS_STREAMED_TEXTURE_DICT_LOADED, TOC };
	BOOL(*HAS_STREAMED_TEXTURE_DICT_LOADED)(char *textureDict) = (BOOL(*)(char*))&_HAS_STREAMED_TEXTURE_DICT_LOADED;

	opd_s _GET_TEXTURE_RESOLUTION = { Addresses::Addresses_Natives::Draw_a::GET_TEXTURE_RESOLUTION, TOC };
	Vec3(*GET_TEXTURE_RESOLUTION)(char *textureDict, char *textureName) = (Vec3(*)(char*, char*))&_GET_TEXTURE_RESOLUTION;

	
	//---------------------------------------------------------------------------------------------//


	
	//---------------------------------------------------------------------------------------------//
	// Controls

	opd_s _DISABLE_CONTROL_ACTION = { Addresses::Addresses_Natives::Controls_a::DISABLE_CONTROL_ACTION, TOC };
	void(*DISABLE_CONTROL_ACTION)(int p1, int p2) = (void(*)(int, int))&_DISABLE_CONTROL_ACTION;

	opd_s _IS_DISABLED_CONTROL_JUST_PRESSED = { Addresses::Addresses_Natives::Controls_a::IS_DISABLED_CONTROL_JUST_PRESSED, TOC };
	bool(*IS_DISABLED_CONTROL_JUST_PRESSED)(int p1, int p2) = (bool(*)(int, int))&_IS_DISABLED_CONTROL_JUST_PRESSED;

	opd_s _IS_DISABLED_CONTROL_JUST_RELEASED = { Addresses::Addresses_Natives::Controls_a::IS_DISABLED_CONTROL_JUST_RELEASED, TOC };
	bool(*IS_DISABLED_CONTROL_JUST_RELEASED)(int p1, int p2) = (bool(*)(int, int))&_IS_DISABLED_CONTROL_JUST_RELEASED;

	opd_s _IS_DISABLED_CONTROL_PRESSED = { Addresses::Addresses_Natives::Controls_a::IS_DISABLED_CONTROL_PRESSED, TOC };
	bool(*IS_DISABLED_CONTROL_PRESSED)(int p1, int p2) = (bool(*)(int, int))&_IS_DISABLED_CONTROL_PRESSED;

	opd_s _IS_CONTROL_ENABLED = { Addresses::Addresses_Natives::Controls_a::IS_CONTROL_ENABLED, TOC };
	BOOL(*IS_CONTROL_ENABLED)(int index, int control) = (BOOL(*)(int,int))&_IS_CONTROL_ENABLED;

	opd_s _IS_CONTROL_PRESSED = { Addresses::Addresses_Natives::Controls_a::IS_CONTROL_PRESSED, TOC };
	int(*IS_CONTROL_PRESSED)(int index, int control) = (int(*)(int,int))&_IS_CONTROL_PRESSED;

	opd_s _IS_CONTROL_RELEASED = { Addresses::Addresses_Natives::Controls_a::IS_CONTROL_RELEASED, TOC };
	int(*IS_CONTROL_RELEASED)(int index, int control) = (int(*)(int,int))&_IS_CONTROL_RELEASED;

	opd_s _IS_CONTROL_JUST_PRESSED = { Addresses::Addresses_Natives::Controls_a::IS_CONTROL_JUST_PRESSED, TOC };
	int(*IS_CONTROL_JUST_PRESSED)(int index, int control) = (int(*)(int,int))&_IS_CONTROL_JUST_PRESSED;

	opd_s _IS_CONTROL_JUST_RELEASED = { Addresses::Addresses_Natives::Controls_a::IS_CONTROL_JUST_RELEASED, TOC };
	int(*IS_CONTROL_JUST_RELEASED)(int index, int control) = (int(*)(int,int))&_IS_CONTROL_JUST_RELEASED;

	opd_s _GET_CONTROL_VALUE = { Addresses::Addresses_Natives::Controls_a::GET_CONTROL_VALUE, TOC };
	int(*GET_CONTROL_VALUE)(int index, int control) = (int(*)(int, int))&_GET_CONTROL_VALUE;

	opd_s _DISABLE_ALL_CONTROL_ACTIONS_ALT = { Addresses::Addresses_Natives::Controls_a::DISABLE_ALL_CONTROL_ACTIONS, TOC };
	void(*DISABLE_ALL_CONTROL_ACTIONS_ALT)(int index) = (void(*)(int))&_DISABLE_ALL_CONTROL_ACTIONS_ALT;

	opd_s _ENABLE_ALL_CONTROL_ACTIONS_ALT = { Addresses::Addresses_Natives::Controls_a::ENABLE_ALL_CONTROL_ACTIONS, TOC };
	void(*ENABLE_ALL_CONTROL_ACTIONS_ALT)(int index) = (void(*)(int))&_ENABLE_ALL_CONTROL_ACTIONS_ALT;

	opd_s _DISABLE_ALL_CONTROL_ACTIONS = { Addresses::Addresses_Natives::Controls_a::DISABLE_ALL_CONTROL_ACTIONS, TOC };
	void(*DISABLE_ALL_CONTROL_ACTIONS)() = (void(*)())&_DISABLE_ALL_CONTROL_ACTIONS;

	opd_s _ENABLE_ALL_CONTROL_ACTIONS = { Addresses::Addresses_Natives::Controls_a::ENABLE_ALL_CONTROL_ACTIONS, TOC };
	void(*ENABLE_ALL_CONTROL_ACTIONS)() = (void(*)())&_ENABLE_ALL_CONTROL_ACTIONS;

	opd_s _SET_INPUT_EXCLUSIVE = { Addresses::Addresses_Natives::Controls_a::SET_INPUT_EXCLUSIVE, TOC };
	void(*SET_INPUT_EXCLUSIVE)(int p1, int p2) = (void(*)(int, int))&_SET_INPUT_EXCLUSIVE;
	//---------------------------------------------------------------------------------------------//

	
	//---------------------------------------------------------------------------------------------//
	// Entity

	opd_s _GET_ENTITY_MAX_HEALTH = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_MAX_HEALTH, TOC };
	int(*GET_ENTITY_MAX_HEALTH)(Entity entity) = (int(*)(Entity))&_GET_ENTITY_MAX_HEALTH;

	opd_s _SET_ENTITY_HEALTH = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_HEALTH, TOC };
	void(*SET_ENTITY_HEALTH)(Entity entity, int health) = (void(*)(Entity, int))&_SET_ENTITY_HEALTH;

	opd_s _SET_ENTITY_INVINCIBLE = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_INVINCIBLE, TOC };
	void(*SET_ENTITY_INVINCIBLE)(int p1, bool p2) = (void(*)(int, bool))&_SET_ENTITY_INVINCIBLE;

	opd_s _SET_ENTITY_PROOFS = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_PROOFS, TOC };
	void(*SET_ENTITY_PROOFS)(Entity entity, BOOL bulletProof, BOOL fireProof, BOOL explosionProof, BOOL collisionProof, BOOL meleeProof, BOOL p6, BOOL p7, BOOL drownProof) = (void(*)(Entity, BOOL, BOOL, BOOL, BOOL, BOOL, BOOL, BOOL, BOOL))&_SET_ENTITY_PROOFS;
	
	opd_s _SET_ENTITY_CAN_BE_DAMAGED = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_CAN_BE_DAMAGED, TOC };
	void(*SET_ENTITY_CAN_BE_DAMAGED)(Entity entity, BOOL toggle) = (void(*)(Entity, BOOL))&_SET_ENTITY_CAN_BE_DAMAGED;
	//---------------------------------------------------------------------------------------------//
	


	//---------------------------------------------------------------------------------------------//
	// Ped
	
	opd_s _SET_PED_ARMOUR = { Addresses::Addresses_Natives::Peds_a::SET_PED_ARMOUR, TOC };
	void(*SET_PED_ARMOUR)(Ped ped, int amount) = (void(*)(Ped, int))&_SET_PED_ARMOUR;

	opd_s _SET_PED_RAGDOLL_ON_COLLISION = { Addresses::Addresses_Natives::Peds_a::SET_PED_RAGDOLL_ON_COLLISION, TOC };
	void(*SET_PED_RAGDOLL_ON_COLLISION)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_PED_RAGDOLL_ON_COLLISION;

	opd_s _SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE = { Addresses::Addresses_Natives::Peds_a::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE, TOC };
	void(*SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE)(Ped ped, BOOL state) = (void(*)(Ped, BOOL))&_SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE;

	opd_s _SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT = { Addresses::Addresses_Natives::Peds_a::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT, TOC };
	void(*SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT;
	
	opd_s _SET_PED_CAN_RAGDOLL = { Addresses::Addresses_Natives::Peds_a::SET_PED_CAN_RAGDOLL, TOC };
	void(*SET_PED_CAN_RAGDOLL)(int player, bool ragdoll) = (void(*)(int, bool))&_SET_PED_CAN_RAGDOLL;
	
	opd_s _SET_PED_DIES_IN_VEHICLE = { Addresses::Addresses_Natives::Peds_a::SET_PED_DIES_IN_VEHICLE, TOC };
	void(*SET_PED_DIES_IN_VEHICLE)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_PED_DIES_IN_VEHICLE;

	opd_s _SET_PED_DIES_IN_WATER = { Addresses::Addresses_Natives::Peds_a::SET_PED_DIES_IN_WATER, TOC };
	void(*SET_PED_DIES_IN_WATER)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_PED_DIES_IN_WATER;

	opd_s _SET_PED_DIES_IN_SINKING_VEHICLE = { Addresses::Addresses_Natives::Peds_a::SET_PED_DIES_IN_SINKING_VEHICLE, TOC };
	void(*SET_PED_DIES_IN_SINKING_VEHICLE)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_PED_DIES_IN_SINKING_VEHICLE;
	
	//---------------------------------------------------------------------------------------------//

	
	//---------------------------------------------------------------------------------------------//
	// System

	opd_s _GET_HASH_KEY_ALT = { Addresses::Addresses_Natives::System_a::GET_HASH_KEY, TOC };
	int(*GET_HASH_KEY_ALT)(const char* Model) = (int(*)(const char*))&_GET_HASH_KEY_ALT;

	opd_s _GET_HASH_KEY = { Addresses::Addresses_Natives::System_a::GET_HASH_KEY, TOC };
	uint(*GET_HASH_KEY)(const char* Model) = (uint(*)(const char*))&_GET_HASH_KEY;

	opd_s _GET_GAME_TIMER = { Addresses::Addresses_Natives::System_a::GET_GAME_TIMER, TOC };
	Any(*GET_GAME_TIMER)() = (Any(*)())&_GET_GAME_TIMER;
	//---------------------------------------------------------------------------------------------//

	

	

	
	//---------------------------------------------------------------------------------------------//
	// Player

	opd_s _GIVE_PLAYER_RAGDOLL_CONTROL = { Addresses::Addresses_Natives::Peds_a::GIVE_PLAYER_RAGDOLL_CONTROL, TOC };
	void(*GIVE_PLAYER_RAGDOLL_CONTROL)(Player player, BOOL toggle) = (void(*)(Ped, BOOL))&_GIVE_PLAYER_RAGDOLL_CONTROL;

	opd_s _SET_PLAYER_INVINCIBLE = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_INVINCIBLE, TOC };
	void(*SET_PLAYER_INVINCIBLE)(uint PLAYER_ID, bool Enabled) = (void(*)(uint, bool))&_SET_PLAYER_INVINCIBLE;

	opd_s _IS_PLAYER_ONLINE = { Addresses::Addresses_Natives::Player_a::IS_PLAYER_ONLINE, TOC };
	BOOL(*IS_PLAYER_ONLINE)() = (BOOL(*)())&_IS_PLAYER_ONLINE;

	opd_s _GET_PLAYER_PED = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_PED, TOC };
	int(*GET_PLAYER_PED)(int p1) = (int(*)(int))&_GET_PLAYER_PED;

	opd_s _GET_PLAYER_PED_UINT = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_PED, TOC };
	uint(*GET_PLAYER_PED_UINT)(Player player) = (uint(*)(Player))&_GET_PLAYER_PED_UINT;
	
	// Player That Is Running Menu
	opd_s _PLAYER_ID = { Addresses::Addresses_Natives::Player_a::PLAYER_ID, TOC };
	uint(*PLAYER_ID)(uint player) = (uint(*)(uint))&_PLAYER_ID;

	opd_s _PLAYER_ID_ALT = { Addresses::Addresses_Natives::Player_a::PLAYER_ID, TOC };
	Player(*PLAYER_ID_ALT)() = (Player(*)())&_PLAYER_ID_ALT;

	opd_s _PLAYER_PED_ID = { Addresses::Addresses_Natives::Player_a::PLAYER_PED_ID, TOC };
	Ped(*PLAYER_PED_ID)() = (Ped(*)())&_PLAYER_PED_ID;

	opd_s _PLAYER_PED_ID_UINT = { Addresses::Addresses_Natives::Player_a::PLAYER_PED_ID, TOC };
	uint(*PLAYER_PED_ID_UINT)() = (uint(*)())&_PLAYER_PED_ID_UINT;

	opd_s _GET_PLAYER_NAME = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_NAME, TOC };
	char*(*GET_PLAYER_NAME)(Player player) = (char*(*)(Player))&_GET_PLAYER_NAME;
	
	opd_s _GET_PLAYER_NAME_ALT = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_NAME, TOC };
	char*(*GET_PLAYER_NAME_ALT)(uint PlayerID) = (char*(*)(uint))&_GET_PLAYER_NAME_ALT;
	
	// Alt
	opd_s _getPlayerPed = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_PED, TOC };
	int(*getPlayerPed)(int p1) = (int(*)(int))&_getPlayerPed;

	opd_s _IS_PLAYER_PLAYING = { Addresses::Addresses_Natives::Player_a::IS_PLAYER_PLAYING, TOC };
	BOOL(*IS_PLAYER_PLAYING)(int p1) = (BOOL(*)(int))&_IS_PLAYER_PLAYING;
	
	opd_s _IS_PLAYER_DEAD = { Addresses::Addresses_Natives::Player_a::IS_PLAYER_DEAD, TOC };
	BOOL(*IS_PLAYER_DEAD)(Player player) = (BOOL(*)(Player))&_IS_PLAYER_DEAD;

	opd_s _SET_MAX_WANTED_LEVEL = { Addresses::Addresses_Natives::Player_a::SET_MAX_WANTED_LEVEL, TOC };
	BOOL(*SET_MAX_WANTED_LEVEL)(int maxWantedLevel) = (BOOL(*)(int))&_SET_MAX_WANTED_LEVEL;

	opd_s _SET_PLAYER_WANTED_LEVEL_NOW = { Addresses::Addresses_Natives::Player_a::SET_PLAYER_WANTED_LEVEL_NOW, TOC };
	int(*SET_PLAYER_WANTED_LEVEL_NOW)(Player player, BOOL p1) = (int(*)(Player, BOOL))&_SET_PLAYER_WANTED_LEVEL_NOW;

	opd_s _GET_PLAYER_WANTED_LEVEL = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_WANTED_LEVEL, TOC };
	int(*GET_PLAYER_WANTED_LEVEL)(Player player) = (int(*)(Player))&_GET_PLAYER_WANTED_LEVEL;

	opd_s _SET_PLAYER_WANTED_LEVEL = { Addresses::Addresses_Natives::Player_a::SET_PLAYER_WANTED_LEVEL, TOC };
	int(*SET_PLAYER_WANTED_LEVEL)(Player player, int wantedLevel, BOOL p2) = (int(*)(Player, int, BOOL))&_SET_PLAYER_WANTED_LEVEL;

	opd_s _CLEAR_PLAYER_WANTED_LEVEL = { Addresses::Addresses_Natives::Player_a::CLEAR_PLAYER_WANTED_LEVEL, TOC };
	void(*CLEAR_PLAYER_WANTED_LEVEL)() = (void(*)())&_CLEAR_PLAYER_WANTED_LEVEL;

	opd_s _SET_POLICE_IGNORE_PLAYER = { Addresses::Addresses_Natives::Player_a::SET_POLICE_IGNORE_PLAYER, TOC };
	void(*SET_POLICE_IGNORE_PLAYER)(Player player, BOOL toggle) = (void(*)(Player, BOOL))&_SET_POLICE_IGNORE_PLAYER;

	//---------------------------------------------------------------------------------------------//
	

	//---------------------------------------------------------------------------------------------//
	// Weapons

	opd_s _SET_PED_GADGET = { Addresses::Addresses_Natives::Peds_a::SET_PED_GADGET, TOC };
	void(*SET_PED_GADGET)(Ped ped, Hash gadgetHash, BOOL p2) = (void(*)(Ped, Hash, BOOL))&_SET_PED_GADGET;

	opd_s _SET_PED_INFINITE_AMMO = { Addresses::Addresses_Natives::Weapons_a::SET_PED_INFINITE_AMMO, TOC };
	void(*SET_PED_INFINITE_AMMO)(Ped ped, BOOL toggle, Hash weaponHash) = (void(*)(Ped, BOOL, Hash))&_SET_PED_INFINITE_AMMO;

	opd_s _GIVE_DELAYED_WEAPON_TO_PED ={ Addresses::Addresses_Natives::Weapons_a::GIVE_DELAYED_WEAPON_TO_PED, TOC };
	void(*GIVE_DELAYED_WEAPON_TO_PED)(Ped ped, Hash weaponHash, int time, BOOL equipNow) = (void(*)(Ped, Hash, int, BOOL))&_GIVE_DELAYED_WEAPON_TO_PED;
	
	//---------------------------------------------------------------------------------------------//
	
	
	
	//---------------------------------------------------------------------------------------------//
	// Keyboard
	
	//opd_s _DISPLAY_ONSCREEN_KEYBOARD = { Addresses::Addresses_Natives::Keyboard_a::DISPLAY_ONSCREEN_KEYBOARD, TOC };
	//int(*DISPLAY_ONSCREEN_KEYBOARD)(int x, const char* a, const char* b, const char* c, const char* d, const char* e, const char* f, int maxLength) = (int(*)(int, const char*, const char*, const char*, const char*, const char*, const char*, int))&_DISPLAY_ONSCREEN_KEYBOARD;

	/*
	NOTE: windowTitle uses enumerables, and an invalid value will display nothing.

	http://gtaforums.com/topic/788343-vrel-script-hook-v/?p=1067380474

	windowTitle's
	-----------------
	CELL_EMAIL_BOD = "Enter your Eyefind message"
	CELL_EMAIL_BODE = "Message too long. Try again"
	CELL_EMAIL_BODF = "Forbidden message. Try again"
	CELL_EMAIL_SOD = "Enter your Eyefind subject"
	CELL_EMAIL_SODE = "Subject too long. Try again"
	CELL_EMAIL_SODF = "Forbidden text. Try again"
	CELL_EMASH_BOD = "Enter your Eyefind message"
	CELL_EMASH_BODE = "Message too long. Try again"
	CELL_EMASH_BODF = "Forbidden message. Try again"
	CELL_EMASH_SOD = "Enter your Eyefind subject"
	CELL_EMASH_SODE = "Subject too long. Try again"
	CELL_EMASH_SODF = "Forbidden Text. Try again"
	FMMC_KEY_TIP10 = "Enter Synopsis"
	FMMC_KEY_TIP12 = "Enter Custom Team Name"
	FMMC_KEY_TIP12F = "Forbidden Text. Try again"
	FMMC_KEY_TIP12N = "Custom Team Name"
	FMMC_KEY_TIP8 = "Enter Message"
	FMMC_KEY_TIP8F = "Forbidden Text. Try again"
	FMMC_KEY_TIP8FS = "Invalid Message. Try again"
	FMMC_KEY_TIP8S = "Enter Message"
	FMMC_KEY_TIP9 = "Enter Outfit Name"
	FMMC_KEY_TIP9F = "Invalid Outfit Name. Try again"
	FMMC_KEY_TIP9N = "Outfit Name"
	PM_NAME_CHALL = "Enter Challenge Name"
	*/
	opd_s _DISPLAY_ONSCREEN_KEYBOARD = { Addresses::Addresses_Natives::Keyboard_a::DISPLAY_ONSCREEN_KEYBOARD, TOC };
	int(*DISPLAY_ONSCREEN_KEYBOARD)(BOOL p0, char *windowTitle, char *p2, char *defaultText, char *defaultConcat1, char *defaultConcat2, char *defaultConcat3, int maxInputLength) = (int(*)(BOOL, char*, char*, char*, char*, char*, char*, int))&_DISPLAY_ONSCREEN_KEYBOARD;

	// Returns NULL unless UPDATE_ONSCREEN_KEYBOARD() returns 2 in the same tick.
	opd_s _GET_ONSCREEN_KEYBOARD_RESULT = { Addresses::Addresses_Natives::Keyboard_a::GET_ONSCREEN_KEYBOARD_RESULT, TOC };
	char*(*GET_ONSCREEN_KEYBOARD_RESULT)() = (char*(*)())&_GET_ONSCREEN_KEYBOARD_RESULT;

	/*
	0 - User still editing
	1 - User has finished editing
	2 - User has canceled editing
	3 - Keyboard isn't active
	*/
	opd_s _UPDATE_ONSCREEN_KEYBOARD = { Addresses::Addresses_Natives::Keyboard_a::UPDATE_ONSCREEN_KEYBOARD, TOC };
	int(*UPDATE_ONSCREEN_KEYBOARD)() = (int(*)())&_UPDATE_ONSCREEN_KEYBOARD;

	opd_s _IS_SYSTEM_UI_BEING_DISPLAYED = { Addresses::Addresses_Natives::Keyboard_a::IS_SYSTEM_UI_BEING_DISPLAYED, TOC };
	BOOL(*IS_SYSTEM_UI_BEING_DISPLAYED)() = (BOOL(*)())&_IS_SYSTEM_UI_BEING_DISPLAYED;
	//---------------------------------------------------------------------------------------------//



	//---------------------------------------------------------------------------------------------//
	// Stats

	opd_s _STAT_SET_BOOL = { Addresses::Addresses_Natives::Player_a::STAT_SET_BOOL, TOC };
	BOOL(*STAT_SET_BOOL)(Hash statName, BOOL value, BOOL save) = (BOOL(*)(Hash, BOOL, BOOL))&_STAT_SET_BOOL;
	
	//opd_s _STAT_SET_BOOL_MASKED = { Addresses::Addresses_Natives::Player_a::STAT_SET_BOOL_MASKED, TOC };
	//BOOL(*STAT_SET_BOOL_MASKED)(Any p0, BOOL p1, Any p2, BOOL p3) = (BOOL(*)(Any, BOOL, Any, BOOL))&_STAT_SET_BOOL_MASKED;
	
	//opd_s _STAT_SET_DATE = { Addresses::Addresses_Natives::Player_a::STAT_SET_DATE, TOC };
	//BOOL(*STAT_SET_DATE)(Hash statName, Any *value, int numFields, BOOL save) = (BOOL(*)(Hash, Any*, int, BOOL))&_STAT_SET_DATE;
	
	opd_s _STAT_SET_FLOAT = { Addresses::Addresses_Natives::Player_a::STAT_SET_FLOAT, TOC };
	BOOL(*STAT_SET_FLOAT)(Hash statName, float value, BOOL save) = (BOOL(*)(Hash, float, BOOL))&_STAT_SET_FLOAT;
	
	opd_s _STAT_SET_INT = { Addresses::Addresses_Natives::Player_a::STAT_SET_INT, TOC };
	BOOL(*STAT_SET_INT)(Hash statName, int value, BOOL save) = (BOOL(*)(Hash, int, BOOL))&_STAT_SET_INT;
	
	opd_s _STAT_SET_INT_UINT = { Addresses::Addresses_Natives::Player_a::STAT_SET_INT, TOC };
	BOOL(*STAT_SET_INT_UINT)(uint statName, int value, BOOL save) = (BOOL(*)(uint, int, BOOL))&_STAT_SET_INT_UINT;
	
	//opd_s _STAT_SET_MASKED_INT = { Addresses::Addresses_Natives::Player_a::STAT_SET_MASKED_INT, TOC };
	//BOOL(*STAT_SET_MASKED_INT)(Hash statName, Any p1, Any p2, int p3, BOOL save) = (BOOL(*)(Hash, Any, Any, int, BOOL))&_STAT_SET_MASKED_INT;
	
	//opd_s _STAT_SET_POS = { Addresses::Addresses_Natives::Player_a::STAT_SET_POS, TOC };
	//BOOL(*STAT_SET_POS)(Hash statName, float x, float y, float z, BOOL save) = (BOOL(*)(Hash, float, float, float, BOOL))&_STAT_SET_POS;
	
	//opd_s _STAT_SET_STRING = { Addresses::Addresses_Natives::Player_a::STAT_SET_STRING, TOC };
	//BOOL(*STAT_SET_STRING)(Hash statName, char *value, BOOL save) = (BOOL(*)(Hash, char*, BOOL))&_STAT_SET_STRING;
	
	//opd_s _STAT_SET_USER_ID = { Addresses::Addresses_Natives::Player_a::STAT_SET_USER_ID, TOC };
	//BOOL(*STAT_SET_USER_ID)(Hash statName, char *value, BOOL save) = (BOOL(*)(Hash, char*, BOOL))&_STAT_SET_USER_ID;

	// p2 appears to always be -1
	opd_s _STAT_GET_INT = { Addresses::Addresses_Natives::Player_a::STAT_GET_INT, TOC };
	BOOL(*STAT_GET_INT)(Hash statHash, int *outValue, int p2) = (BOOL(*)(Hash, int*, int))&_STAT_GET_INT;

	opd_s _STAT_INCREMENT = { Addresses::Addresses_Natives::Player_a::STAT_INCREMENT, TOC };
	void(*STAT_INCREMENT)(Hash statName, float value) = (void(*)(Hash, float))&_STAT_INCREMENT;
	//---------------------------------------------------------------------------------------------//

	
	//---------------------------------------------------------------------------------------------//
	// Network

	opd_s _NETWORK_EARN_FROM_ROCKSTAR = { Addresses::Addresses_Natives::Network_a::NETWORK_EARN_FROM_ROCKSTAR, TOC };
	BOOL(*NETWORK_EARN_FROM_ROCKSTAR)(int value) = (BOOL(*)(int))&_NETWORK_EARN_FROM_ROCKSTAR; 
	//---------------------------------------------------------------------------------------------//


	
	//---------------------------------------------------------------------------------------------//
	// Sounds

	//opd_s _PLAY_SOUND = { Addresses::Addresses_Natives::Sounds_a::PLAY_SOUND, TOC };
	//void(*PLAY_SOUND)(int soundId, char *soundName, char *setName, BOOL p3, Any p4, BOOL p5) = (void(*)(int, char*, char*, BOOL, Any, BOOL))&_PLAY_SOUND;
	
	//opd_s _PLAY_SOUND_FROM_ENTITY = { Addresses::Addresses_Natives::Sounds_a::PLAY_SOUND_FROM_ENTITY, TOC };
	//void(*PLAY_SOUND_FROM_ENTITY)(int soundId, char *soundName, Entity entity, char *setName, BOOL p4, Any p5) = (void(*)(int, char*, Entity, char*, BOOL, Any))&_PLAY_SOUND_FROM_ENTITY;
	
	//opd_s _PLAY_SOUND_FROM_COORD = { Addresses::Addresses_Natives::Sounds_a::PLAY_SOUND_FROM_COORD, TOC };
	//void(*PLAY_SOUND_FROM_COORD)(int soundId, char *soundName, float x, float y, float z, char *setName, BOOL p6, Any p7, BOOL p8) = (void(*)(int, char*, float, float, float, char*, BOOL, Any, BOOL))&_PLAY_SOUND_FROM_COORD;
	
	opd_s _PLAY_SOUND_FRONTEND = { Addresses::Addresses_Natives::Sounds_a::PLAY_SOUND_FRONTEND, TOC };
	void(*PLAY_SOUND_FRONTEND)(int soundID, const char* sound, const char* soundIndex) = (void(*)(int, const char*, const char*))&_PLAY_SOUND_FRONTEND;
	
	//opd_s _PLAY_SOUND_FROM_OBJECT = { Addresses::Addresses_Natives::Sounds_a::PLAY_SOUND_FROM_OBJECT, TOC };
	//void(*PLAY_SOUND_FROM_OBJECT)(int soundID, const char* sound, const char* soundIndex) = (void(*)(int, const char*, const char*))&_PLAY_SOUND_FROM_OBJECT;
	
	//opd_s _PLAY_VEHICLE_DOOR_CLOSE_SOUND = { Addresses::Addresses_Natives::Sounds_a::PLAY_VEHICLE_DOOR_CLOSE_SOUND, TOC };
	//void(*PLAY_VEHICLE_DOOR_CLOSE_SOUND)(Vehicle vehicle, Any p1) = (void(*)(Vehicle, Any))&_PLAY_VEHICLE_DOOR_CLOSE_SOUND;
	
	//opd_s _PLAY_VEHICLE_DOOR_OPEN_SOUND = { Addresses::Addresses_Natives::Sounds_a::PLAY_VEHICLE_DOOR_OPEN_SOUND, TOC };
	//void(*PLAY_VEHICLE_DOOR_OPEN_SOUND)(Vehicle vehicle, Any p1) = (void(*)(Vehicle, Any))&_PLAY_VEHICLE_DOOR_OPEN_SOUND;
	
	//opd_s _STOP_SOUND = { Addresses::Addresses_Natives::Sounds_a::STOP_SOUND, TOC };
	//void(*STOP_SOUND)(int soundID) = (void(*)(int))&_STOP_SOUND;
	//---------------------------------------------------------------------------------------------//
	
	
	
	//---------------------------------------------------------------------------------------------//
	// System

	opd_s _SET_BIT = { Addresses::Addresses_Natives::Misc_a::SET_BIT, TOC };
	void(*SET_BIT)(int var, int bit) = (void(*)(int, int))&_SET_BIT;

	//opd_s _GET_BITS_IN_RANGE = { Addresses::Addresses_Natives::System_a::GET_BITS_IN_RANGE, TOC };
	//void(*GET_BITS_IN_RANGE)(Any p0, Any p1, Any p2) = (void(*)(Any, Any, Any))&_GET_BITS_IN_RANGE;

	//opd_s _SET_BITS_IN_RANGE = { Addresses::Addresses_Natives::System_a::SET_BITS_IN_RANGE, TOC };
	//void(*SET_BITS_IN_RANGE)(Any *p0, Any p1, Any p2, Any p3) = (void(*)(Any*, Any, Any, Any))&_SET_BITS_IN_RANGE;

	//opd_s _CLEAR_BIT = { Addresses::Addresses_Natives::System_a::CLEAR_BIT, TOC };
	//void(*CLEAR_BIT)(int *var, int bit) = (void(*)(int*, int))&_CLEAR_BIT;
	//---------------------------------------------------------------------------------------------//

	
	//---------------------------------------------------------------------------------------------//
	// Randoms

	//opd_s _SET_RANDOM_SEED = { Addresses::Addresses_Natives::System_a::SET_RANDOM_SEED, TOC };
	//BOOL(*SET_RANDOM_SEED)(Any p0) = (BOOL(*)(Any))&_SET_RANDOM_SEED;

	//opd_s _SET_RANDOM_EVENT_FLAG = { Addresses::Addresses_Natives::System_a::SET_RANDOM_EVENT_FLAG, TOC };
	//BOOL(*SET_RANDOM_EVENT_FLAG)(Any p0) = (BOOL(*)(Any))&_SET_RANDOM_EVENT_FLAG;

	//opd_s _GET_RANDOM_EVENT_FLAG = { Addresses::Addresses_Natives::Misc_a::GET_RANDOM_EVENT_FLAG, TOC };
	//Any(*GET_RANDOM_EVENT_FLAG)() = (Any(*)())&_GET_RANDOM_EVENT_FLAG;
	
	opd_s _GET_RANDOM_FLOAT_IN_RANGE = { Addresses::Addresses_Natives::Misc_a::GET_RANDOM_FLOAT_IN_RANGE, TOC };
	float(*GET_RANDOM_FLOAT_IN_RANGE)(float startRange, float endRange) = (float(*)(float, float))&_GET_RANDOM_FLOAT_IN_RANGE;

	// Using GET_RANDOM_FLOAT_IN_RANGE as irandf
	opd_s _GET_RANDOM_FLOAT_IN_RANGE_f = { Addresses::Addresses_Natives::Misc_a::GET_RANDOM_FLOAT_IN_RANGE, TOC };
	float(*irandf)(float startRange, float endRange) = (float(*)(float, float))&_GET_RANDOM_FLOAT_IN_RANGE_f;

	opd_s _GET_RANDOM_FLOAT_IN_RANGE_fp = { Addresses::Addresses_Natives::Misc_a::GET_RANDOM_FLOAT_IN_RANGE, TOC };
	float*(*irandfp)(float startRange, float endRange) = (float*(*)(float, float))&_GET_RANDOM_FLOAT_IN_RANGE_fp;

	opd_s _GET_RANDOM_INT_IN_RANGE = { Addresses::Addresses_Natives::Misc_a::GET_RANDOM_INT_IN_RANGE, TOC };
	int(*GET_RANDOM_INT_IN_RANGE)(int startRange, int endRange) = (int(*)(int, int))&_GET_RANDOM_INT_IN_RANGE;

	// Using GET_RANDOM_INT_IN_RANGE as irand
	opd_s _GET_RANDOM_INT_IN_RANGE_f = { Addresses::Addresses_Natives::Misc_a::GET_RANDOM_INT_IN_RANGE, TOC };
	int(*irand)(int startRange, int endRange) = (int(*)(int, int))&_GET_RANDOM_INT_IN_RANGE_f;

	//opd_s _GET_RANDOM_PED_2D_OPERATION_INFO = { Addresses::Addresses_Natives::Misc_a::GET_RANDOM_PED_2D_OPERATION_INFO, TOC };
	//void(*GET_RANDOM_PED_2D_OPERATION_INFO)(BOOL enable) = (void(*)(BOOL))&_GET_RANDOM_PED_2D_OPERATION_INFO;

	//opd_s _GET_RANDOM_PED_AT_COORD = { Addresses::Addresses_Natives::Misc_a::GET_RANDOM_PED_AT_COORD, TOC };
	//Ped(*GET_RANDOM_PED_AT_COORD)(float x, float y, float z, float xRadius, float yRadius, float zRadius, int pedType) = (Ped(*)(float, float, float, float, float, float, int))&_GET_RANDOM_PED_AT_COORD;

	//opd_s _GET_RANDOM_VEHICLE_BACK_BUMPER_IN_SPHERE = { Addresses::Addresses_Natives::Misc_a::GET_RANDOM_VEHICLE_BACK_BUMPER_IN_SPHERE, TOC };
	//Vehicle(*GET_RANDOM_VEHICLE_BACK_BUMPER_IN_SPHERE)(float p0, float p1, float p2, float p3, int p4, int p5, int p6) = (Vehicle(*)(float, float, float, float, int, int, int))&_GET_RANDOM_VEHICLE_BACK_BUMPER_IN_SPHERE;

	//opd_s _GET_RANDOM_VEHICLE_FRONT_BUMPER_IN_SPHERE = { Addresses::Addresses_Natives::Misc_a::GET_RANDOM_VEHICLE_FRONT_BUMPER_IN_SPHERE, TOC };
	//Vehicle(*GET_RANDOM_VEHICLE_FRONT_BUMPER_IN_SPHERE)(float p0, float p1, float p2, float p3, int p4, int p5, int p6) = (Vehicle(*)(float, float, float, float, int, int, int))&_GET_RANDOM_VEHICLE_FRONT_BUMPER_IN_SPHERE;

	//opd_s _GET_RANDOM_VEHICLE_IN_SPHERE = { Addresses::Addresses_Natives::Misc_a::GET_RANDOM_VEHICLE_IN_SPHERE, TOC };
	//Vehicle(*GET_RANDOM_VEHICLE_IN_SPHERE)(float x, float y, float z, float radius, Hash modelHash, int flags) = (Vehicle(*)(float, float, float, float, Hash, int))&_GET_RANDOM_VEHICLE_IN_SPHERE;

	//opd_s _GET_RANDOM_VEHICLE_MODEL_IN_MEMORY = { Addresses::Addresses_Natives::Misc_a::GET_RANDOM_VEHICLE_MODEL_IN_MEMORY, TOC };
	//void(*GET_RANDOM_VEHICLE_MODEL_IN_MEMORY)(BOOL b0, Hash *p1, int *p2) = (void(*)(BOOL, Hash*, int*))&_GET_RANDOM_VEHICLE_MODEL_IN_MEMORY;

	//opd_s _GET_RANDOM_VEHICLE_NODE = { Addresses::Addresses_Natives::Misc_a::GET_RANDOM_VEHICLE_NODE, TOC };
	//Any(*GET_RANDOM_VEHICLE_NODE)(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8) = (Any(*)(Any, Any, Any, Any, Any, Any, Any, Any, Any))&_GET_RANDOM_VEHICLE_NODE;

	
	//---------------------------------------------------------------------------------------------//
	// Some Other Native Stuff
	float floatArray[100];
	float* ReadFloat(int address, int length)
	{
		for (int i = 0; i < length; i++)
			{
				*floatArray = *(float*)(address + (i * 0x04));
			}

			return floatArray;
	}

	
	// Wait Function For Game
	bool newWaitTick = true;
	int maxWaitCount;
	void WAIT(int waitTime) 
	{
		if (newWaitTick)
		{
			maxWaitCount = GET_GAME_TIMER() + waitTime;
			newWaitTick = false;
		}
	}

	bool isWaitReady() 
	{
		return GET_GAME_TIMER() > maxWaitCount;
	}

	void ResetWait()
	{
		newWaitTick = true;
	}


	//---------------------------------------------------------------------------------------------//
	

};



#endif


