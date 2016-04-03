#ifndef __NATIVES_H
#define __NATIVES_H


#include "addresses.h"
#include "core.h"
#include "natives.h"
#include "types.h"


namespace Natives
{
	// Natives For v1.25

	
	//---------------------------------------------------------------------------------------------//
	// Templates

	// Templates -> void
	//opd_s _NATIVE_NAME_HERE = { Addresses::Addresses_Natives::Text_a::NATIVE_NAME_HERE, TOC };
	//void(*NATIVE_NAME_HERE)(int test_i, char test_c, bool test_b) = (void(*)(int, char, bool))&_NATIVE_NAME_HERE;

	// Templates -> int
	//opd_s _NATIVE_NAME_HERE = { Addresses::Addresses_Natives::Text_a::NATIVE_NAME_HERE, TOC };
	//int(*NATIVE_NAME_HERE)(int test_i, char test_c, bool test_b) = (int(*)(int, char, bool))&_NATIVE_NAME_HERE;

	// Templates -> int (Pointer)
	//opd_s _NATIVE_NAME_HERE = { Addresses::Addresses_Natives::Text_a::NATIVE_NAME_HERE, TOC };
	//int*(*NATIVE_NAME_HERE)(int test_i, char test_c, bool test_b) = (int*(*)(int, char, bool))&_NATIVE_NAME_HERE;

	// Templates -> uint
	//opd_s _NATIVE_NAME_HERE = { Addresses::Addresses_Natives::Text_a::NATIVE_NAME_HERE, TOC };
	//uint(*NATIVE_NAME_HERE)(int test_i, char test_c, bool test_b) = (uint(*)(int, char, bool))&_NATIVE_NAME_HERE;

	// Templates -> uint (Pointer)
	//opd_s _NATIVE_NAME_HERE = { Addresses::Addresses_Natives::Text_a::NATIVE_NAME_HERE, TOC };
	//uint*(*NATIVE_NAME_HERE)(int test_i, char test_c, bool test_b) = (uint*(*)(int, char, bool))&_NATIVE_NAME_HERE;

	// Templates -> char
	//opd_s _NATIVE_NAME_HERE = { Addresses::Addresses_Natives::Text_a::NATIVE_NAME_HERE, TOC };
	//char(*NATIVE_NAME_HERE)(int test) = (char(*)(int))&_NATIVE_NAME_HERE;

	// Templates -> char* (Pointer)
	//opd_s _NATIVE_NAME_HERE = { Addresses::Addresses_Natives::Text_a::NATIVE_NAME_HERE, TOC };
	//char*(*NATIVE_NAME_HERE)(int test) = (char*(*)(int))&_NATIVE_NAME_HERE;

	// Templates -> bool
	//opd_s _NATIVE_NAME_HERE = { Addresses::Addresses_Natives::Text_a::NATIVE_NAME_HERE, TOC };
	//bool(*NATIVE_NAME_HERE)() = (bool(*)())&_NATIVE_NAME_HERE;
	//---------------------------------------------------------------------------------------------//


	
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


	/*
	Called prior to adding a text component to the UI. After doing so, GRAPHICS::_END_TEXT_COMPONENT is called.

	Examples:
	GRAPHICS::_BEGIN_TEXT_COMPONENT("NUMBER");
	UI::ADD_TEXT_COMPONENT_INTEGER(GAMEPLAY::ABSI(a_1));
	GRAPHICS::_END_TEXT_COMPONENT();

	GRAPHICS::_BEGIN_TEXT_COMPONENT("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(a_2);
	GRAPHICS::_END_TEXT_COMPONENT();

	GRAPHICS::_BEGIN_TEXT_COMPONENT("STRTNM2");
	UI::_0x17299B63C7683A2B(v_3);
	UI::_0x17299B63C7683A2B(v_4);
	GRAPHICS::_END_TEXT_COMPONENT();

	GRAPHICS::_BEGIN_TEXT_COMPONENT("STRTNM1");
	UI::_0x17299B63C7683A2B(v_3);
	GRAPHICS::_END_TEXT_COMPONENT();
	*/
	//opd_s _BEGIN_TEXT_COMPONENT = { Addresses::Addresses_Natives::Text_a::BEGIN_TEXT_COMPONENT, TOC };
	//void(*BEGIN_TEXT_COMPONENT)(char* componentType) = (void(*)(char*))&_BEGIN_TEXT_COMPONENT;


	//opd_s _END_TEXT_COMPONENT = { Addresses::Addresses_Natives::Text_a::END_TEXT_COMPONENT, TOC };
	//void(*END_TEXT_COMPONENT)() = (void(*)())&_END_TEXT_COMPONENT;


	//opd_s _ADD_TEXT_COMPONENT_INTEGER = { Addresses::Addresses_Natives::Text_a::ADD_TEXT_COMPONENT_INTEGER, TOC };
	//int(*ADD_TEXT_COMPONENT_INTEGER)(int number) = (int(*)(int))&_ADD_TEXT_COMPONENT_INTEGER;

	//opd_s _ADD_TEXT_COMPONENT_SUBSTRING_TIME = { Addresses::Addresses_Natives::Text_a::ADD_TEXT_COMPONENT_SUBSTRING_TIME, TOC };
	//int(*ADD_TEXT_COMPONENT_SUBSTRING_TIME)(int timestamp, int flags) = (int(*)(int, int))&_ADD_TEXT_COMPONENT_SUBSTRING_TIME;

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

	//opd_s _SET_TEXT_ENTRY_2 = { Addresses::Addresses_Natives::Text_a::SET_TEXT_ENTRY_2, TOC };
	//int(*SET_TEXT_ENTRY_2)(char* p0) = (int(*)(char*))&_SET_TEXT_ENTRY_2;
	
	opd_s _PRINT_TEXT_TIME = { Addresses::Addresses_Natives::Text_a::PRINT_TEXT_TIME, TOC };
	int(*PRINT_TEXT_TIME)(int) = (int(*)(int))&_PRINT_TEXT_TIME;

	opd_s _PRINT_TEXT_TYPE = { Addresses::Addresses_Natives::Text_a::PRINT_TEXT_TYPE, TOC };
	int(*PRINT_TEXT_TYPE)(const char*) = (int(*)(const char*))&_PRINT_TEXT_TYPE;
	
	opd_s _STRING_TO_INT = { Addresses::Addresses_Natives::Text_a::STRING_TO_INT, TOC };
	BOOL(*STRING_TO_INT)(char *string, int *outInteger) = (BOOL(*)(char*, int*))&_STRING_TO_INT;
	
	

	// Guess
	opd_s _NOTIFICATION_TYPE = { Addresses::Addresses_Natives::Text_a::NOTIFICATION_TYPE, TOC };
	int(*NOTIFICATION_TYPE)(char* type) = (int(*)(char*))&_NOTIFICATION_TYPE;
	
	// Guess
	//opd_s _NOTIFICATION_TEXT = { Addresses::Addresses_Natives::Text_a::NOTIFICATION_TEXT, TOC };
	//char*(*NOTIFICATION_TEXT)(char* text) = (char*(*)(char*))&_NOTIFICATION_TEXT;
	
	// Guess
	//opd_s _NOTIFICATION_SHOW = { Addresses::Addresses_Natives::Text_a::NOTIFICATION_SHOW, TOC };
	//void(*NOTIFICATION_SHOW)(int time, int unk1) = (void(*)(int, int))&_NOTIFICATION_SHOW;
	
	// Guess
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
	//opd_s _DRAW_DEBUG_BOX = { Addresses::Addresses_Natives::Draw_a::DRAW_DEBUG_BOX, TOC };
	//void(*DRAW_DEBUG_BOX)(float x1, float y1, float z1, float x2, float y2, float z2, int r, int g, int b, int alpha) = (void(*)(float, float, float, float, float, float, int, int, int, int))&_DRAW_DEBUG_BOX;
  
	//opd_s _DRAW_DEBUG_TEXT = { Addresses::Addresses_Natives::Draw_a::DRAW_DEBUG_TEXT, TOC };
	//void(*DRAW_DEBUG_TEXT)(char *text, float x, float y, float z, int r, int g, int b, int alpha) = (void(*)(char*, float, float, float, int, int, int, int))&DRAW_DEBUG_TEXT;

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

	
	


	/*
	dirX/Y/Z represent a heading on each axis in which the marker should face, alternatively you can rotate each axis independently with rotX/Y/Z (and set dirX/Y/Z all to 0).

	faceCamera - Rotates only the y-axis (the heading) towards the camera

	p19 - no effect, default value in script is 2

	rotate - Rotates only on the y-axis (the heading)

	textureDict - Name of texture dictionary to load texture from (e.g. "GolfPutting")

	textureName - Name of texture inside dictionary to load (e.g. "PuttingMarker")

	drawOnEnts - Draws the marker onto any entities that intersect it
	*/
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
	// System
	opd_s _GET_HASH_KEY_ALT = { Addresses::Addresses_Natives::System_a::GET_HASH_KEY, TOC };
	int(*GET_HASH_KEY_ALT)(const char* Model) = (int(*)(const char*))&_GET_HASH_KEY_ALT;

	opd_s _GET_HASH_KEY = { Addresses::Addresses_Natives::System_a::GET_HASH_KEY, TOC };
	uint(*GET_HASH_KEY)(const char* Model) = (uint(*)(const char*))&_GET_HASH_KEY;

	opd_s _GET_GAME_TIMER = { Addresses::Addresses_Natives::System_a::GET_GAME_TIMER, TOC };
	Any(*GET_GAME_TIMER)() = (Any(*)())&_GET_GAME_TIMER;

	//opd_s _SET_NO_LOADING_SCREEN = { Addresses::Addresses_Natives::System_a::SET_NO_LOADING_SCREEN, TOC };
	//void(*SET_NO_LOADING_SCREEN)(BOOL toggle) = (void(*)(BOOL))&_SET_NO_LOADING_SCREEN;
	//---------------------------------------------------------------------------------------------//

	

	

	
	//---------------------------------------------------------------------------------------------//
	// Player
	
	

	opd_s _GET_PLAYER_MAX_ARMOUR = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_MAX_ARMOUR, TOC };
	int(*GET_PLAYER_MAX_ARMOUR)(Player player) = (int(*)(Player))&_GET_PLAYER_MAX_ARMOUR;

	opd_s _SET_PLAYER_MAX_ARMOUR = { Addresses::Addresses_Natives::Player_a::SET_PLAYER_MAX_ARMOUR, TOC };
	int(*SET_PLAYER_MAX_ARMOUR)(Player player, int value) = (int(*)(Player, int))&_SET_PLAYER_MAX_ARMOUR;

	opd_s _IS_PLAYER_IN_CUTSCENE = { Addresses::Addresses_Natives::Player_a::IS_PLAYER_IN_CUTSCENE, TOC };
	BOOL(*IS_PLAYER_IN_CUTSCENE)(Any p0) = (BOOL(*)(Any))&_IS_PLAYER_IN_CUTSCENE;

	opd_s _IS_PLAYER_ONLINE = { Addresses::Addresses_Natives::Player_a::IS_PLAYER_ONLINE, TOC };
	BOOL(*IS_PLAYER_ONLINE)() = (BOOL(*)())&_IS_PLAYER_ONLINE;

	//opd_s _IS_PLAYER_RIDING_TRAIN = { Addresses::Addresses_Natives::Player_a::IS_PLAYER_RIDING_TRAIN, TOC };
	//BOOL(*IS_PLAYER_RIDING_TRAIN)() = (BOOL(*)())&_IS_PLAYER_RIDING_TRAIN;

	//opd_s _SET_DISPATCH_COPS_FOR_PLAYER = { Addresses::Addresses_Natives::Player_a::SET_DISPATCH_COPS_FOR_PLAYER, TOC };
	//void(*SET_DISPATCH_COPS_FOR_PLAYER)(Player player, BOOL toggle) = (void(*)(Player, BOOL))&_SET_DISPATCH_COPS_FOR_PLAYER;

	//opd_s _GET_PLAYER_RGB_COLOUR = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_RGB_COLOUR, TOC };
	//void(*GET_PLAYER_RGB_COLOUR)(Player player, int *r, int *g, int *b) = (void(*)(Player, int*, int*, int*))&_GET_PLAYER_RGB_COLOUR;


	// Multiplier can go up to 1.49
	//opd_s _SET_SWIM_SPEED_MULTIPLIER = { Addresses::Addresses_Natives::Player_a::SET_SWIM_SPEED_MULTIPLIER, TOC };
	//void(*SET_SWIM_SPEED_MULTIPLIER)(Player player, float multiplier) = (void(*)(Player, float))&_SET_SWIM_SPEED_MULTIPLIER;

	// Multiplier can go up to 1.49
	//opd_s _SET_MOVE_SPEED_MULTIPLIER = { Addresses::Addresses_Natives::Player_a::SET_MOVE_SPEED_MULTIPLIER, TOC };
	//void(*SET_MOVE_SPEED_MULTIPLIER)(Player player, float multiplier) = (void(*)(Player, float))&_SET_MOVE_SPEED_MULTIPLIER;


	//opd_s _CHANGE_PLAYER_PED = { Addresses::Addresses_Natives::Player_a::CHANGE_PLAYER_PED, TOC };
	//void(*CHANGE_PLAYER_PED)(Player player, Ped ped, BOOL p2, BOOL p3) = (void(*)(Player, Ped, BOOL, BOOL))&_CHANGE_PLAYER_PED;

	
	
	//opd_s _SET_PLAYER_MAY_ONLY_ENTER_THIS_VEHICLE = { Addresses::Addresses_Natives::Player_a::SET_PLAYER_MAY_ONLY_ENTER_THIS_VEHICLE, TOC };
	//void(*SET_PLAYER_MAY_ONLY_ENTER_THIS_VEHICLE)(Player player, Vehicle vehicle) = (void(*)(Player, Vehicle))&_SET_PLAYER_MAY_ONLY_ENTER_THIS_VEHICLE;


	opd_s _SET_PLAYER_MODEL = { Addresses::Addresses_Natives::Player_a::SET_PLAYER_MODEL, TOC };
	void(*SET_PLAYER_MODEL)(uint playerID, uint ModelHash) = (void(*)(uint, uint))&_SET_PLAYER_MODEL;

	opd_s _ADD_EXPLOSION_ALT = { Addresses::Addresses_Natives::Player_a::ADD_EXPLOSION, TOC };
	void(*ADD_EXPLOSION_ALT)(Vec3* coords, int ExplosionType, float ExplosionRadius, bool isAudible, bool isVisible, float CameraShake) = (void(*)(Vec3*, int, float, bool, bool, float))&_ADD_EXPLOSION_ALT;
	
	opd_s _ADD_EXPLOSION = { Addresses::Addresses_Natives::Player_a::ADD_EXPLOSION, TOC };
	void(*ADD_EXPLOSION)(float x, float y, float z, int explosionType, float damageScale, BOOL isAudible, BOOL isInvisible, float cameraShake) = (void(*)(float, float, float, int, float, BOOL, BOOL, float))&_ADD_EXPLOSION;
	
	opd_s _ADD_OWNED_EXPLOSION = { Addresses::Addresses_Natives::Player_a::ADD_OWNED_EXPLOSION, TOC };
	void(*ADD_OWNED_EXPLOSION)(Ped ped, float x, float y, float z, int explosionType, float damageScale, BOOL isAudible, BOOL isInvisible, float cameraShake) = (void(*)(Ped, float, float, float, int, float, BOOL, BOOL, float))&ADD_OWNED_EXPLOSION;
	
	opd_s _GET_PLAYER_PED = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_PED, TOC };
	int(*GET_PLAYER_PED)(int p1) = (int(*)(int))&_GET_PLAYER_PED;
	
	//opd_s _GET_PLAYER_PED_ALT = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_PED, TOC };
	//Ped(*GET_PLAYER_PED_ALT)(Player player) = (Ped(*)(Player))&_GET_PLAYER_PED_ALT;
	
	opd_s _GET_PLAYER_PED_UINT = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_PED, TOC };
	uint(*GET_PLAYER_PED_UINT)(Player player) = (uint(*)(Player))&_GET_PLAYER_PED_UINT;
	
	//opd_s _GET_PLAYER_PED = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_PED, TOC };
	//uint(*GET_PLAYER_PED)(Player player) = (uint(*)(Player))&_GET_PLAYER_PED;
	
	//opd_s _PLAYER_ID = { Addresses::Addresses_Natives::Player_a::PLAYER_ID, TOC };
	//int(*PLAYER_ID)(int) = (int(*)(int))&_PLAYER_ID;

	// Player That Is Running Menu
	opd_s _PLAYER_ID = { Addresses::Addresses_Natives::Player_a::PLAYER_ID, TOC };
	uint(*PLAYER_ID)(uint player) = (uint(*)(uint))&_PLAYER_ID;

	opd_s _PLAYER_ID_ALT = { Addresses::Addresses_Natives::Player_a::PLAYER_ID, TOC };
	Player(*PLAYER_ID_ALT)() = (Player(*)())&_PLAYER_ID_ALT;

	opd_s _PLAYER_PED_ID = { Addresses::Addresses_Natives::Player_a::PLAYER_PED_ID, TOC };
	Ped(*PLAYER_PED_ID)() = (Ped(*)())&_PLAYER_PED_ID;

	opd_s _PLAYER_PED_ID_UINT = { Addresses::Addresses_Natives::Player_a::PLAYER_PED_ID, TOC };
	uint(*PLAYER_PED_ID_UINT)() = (uint(*)())&_PLAYER_PED_ID_UINT;

	//opd_s _PLAYER_PED_ID = { Addresses::Addresses_Natives::Player_a::PLAYER_PED_ID, TOC };
	//uint(*PLAYER_PED_ID)() = (uint(*)())&_PLAYER_PED_ID;

	//opd_s _PLAYER_PED_ID = { Addresses::Addresses_Natives::Player_a::PLAYER_PED_ID, TOC };
	//uint(*PLAYER_PED_ID)(uint) = (uint(*)(uint))&_PLAYER_PED_ID;
	
	//opd_s _GET_PLAYER_NAME = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_NAME, TOC };
	//char*(*GET_PLAYER_NAME)(int p1) = (char*(*)(int))&_GET_PLAYER_NAME;

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
	
	//opd_s _IS_PLAYER_PRESSING_HORN = { Addresses::Addresses_Natives::Player_a::IS_PLAYER_PRESSING_HORN, TOC };
	//BOOL(*IS_PLAYER_PRESSING_HORN)(Player player) = (BOOL(*)(Player))&_IS_PLAYER_PRESSING_HORN;

	// Alt
	//opd_s _playerPedID = { Addresses::Addresses_Natives::Player_a::PLAYER_PED_ID, TOC };
	//uint(*playerPedID)() = (uint(*)())&_playerPedID;

	//opd_s _PLAYER_PED_ID = { Addresses::Addresses_Natives::Player_a::PLAYER_PED_ID, TOC };
	//int(*PLAYER_PED_ID)() = (int(*)())&_PLAYER_PED_ID;
	
	//opd_s _SET_PLAYER_INVINCIBLE = { Addresses::Addresses_Natives::Player_a::SET_PLAYER_INVINCIBLE, TOC };
	//void(*SET_PLAYER_INVINCIBLE)(int p1, bool p2) = (void(*)(int, bool))&_SET_PLAYER_INVINCIBLE;

	//opd_s _SET_PLAYER_INVINCIBLE = { Addresses::Addresses_Natives::Player_a::SET_PLAYER_INVINCIBLE, TOC };
	//void(*SET_PLAYER_INVINCIBLE)(uint PLAYER_ID, bool Enabled) = (void(*)(uint, bool))&_SET_PLAYER_INVINCIBLE;

	//opd_s _SET_PLAYER_INVINCIBLE = { Addresses::Addresses_Natives::Player_a::SET_PLAYER_INVINCIBLE, TOC };
	//void(*SET_PLAYER_INVINCIBLE)(int PLAYER_ID, bool Enabled) = (void(*)(int, bool))&_SET_PLAYER_INVINCIBLE;

	//opd_s _GET_PLAYER_INVINCIBLE = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_INVINCIBLE, TOC };
	//
	
	opd_s _GET_PLAYER_INVINCIBLE = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_INVINCIBLE, TOC };
	BOOL(*GET_PLAYER_INVINCIBLE)(Player player) = (BOOL(*)(Player))&_GET_PLAYER_INVINCIBLE;

	opd_s _SET_PLAYER_INVINCIBLE = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_INVINCIBLE, TOC };
	void(*SET_PLAYER_INVINCIBLE)(uint PLAYER_ID, bool Enabled) = (void(*)(uint, bool))&_SET_PLAYER_INVINCIBLE;

	opd_s _TASK_COWER = { Addresses::Addresses_Natives::Tasks_a::TASK_COWER, TOC };
	void(*TASK_COWER)(Ped ped, int duration) = (void(*)(Ped, int))&_TASK_COWER;


	//opd_s _SET_PLAYERS_LAST_VEHICLE = { Addresses::Addresses_Natives::Player_a::SET_PLAYERS_LAST_VEHICLE, TOC };
	//void(*SET_PLAYERS_LAST_VEHICLE)(Vehicle vehicle) = (void(*)(Vehicle))&_SET_PLAYERS_LAST_VEHICLE;

	//opd_s _SET_SUPER_JUMP_THIS_FRAME = { Addresses::Addresses_Natives::Player_a::SET_SUPER_JUMP_THIS_FRAME, TOC };
	//void(*SET_SUPER_JUMP_THIS_FRAME)(int PLAYER_ID) = (void(*)(int))&_SET_SUPER_JUMP_THIS_FRAME;

	opd_s _SET_SUPER_JUMP_THIS_FRAME = { Addresses::Addresses_Natives::Player_a::SET_SUPER_JUMP_THIS_FRAME, TOC };
	void(*SET_SUPER_JUMP_THIS_FRAME)(Player player) = (void(*)(Player))&_SET_SUPER_JUMP_THIS_FRAME;

	//opd_s _SET_PLAYER_PARACHUTE_PACK_TINT_INDEX = { Addresses::Addresses_Natives::Player_a::SET_PLAYER_PARACHUTE_PACK_TINT_INDEX, TOC };
	//void(*SET_PLAYER_PARACHUTE_PACK_TINT_INDEX)(Player player, int tintIndex) = (void(*)(Player, int))&_SET_PLAYER_PARACHUTE_PACK_TINT_INDEX;

	//opd_s _SET_PLAYER_PARACHUTE_TINT_INDEX = { Addresses::Addresses_Natives::Player_a::SET_PLAYER_PARACHUTE_TINT_INDEX, TOC };
	//void(*SET_PLAYER_PARACHUTE_TINT_INDEX)(Player player, int tintIndex) = (void(*)(Player, int))&_SET_PLAYER_PARACHUTE_TINT_INDEX;

	//opd_s _SET_PLAYER_PARACHUTE_SMOKE_ENABLED = { Addresses::Addresses_Natives::Player_a::SET_PLAYER_PARACHUTE_SMOKE_ENABLED, TOC };
	//void(*SET_PLAYER_PARACHUTE_SMOKE_ENABLED)(Player player, BOOL enabled) = (void(*)(Player, BOOL))&_SET_PLAYER_PARACHUTE_SMOKE_ENABLED;

	//opd_s _SET_PLAYER_PARACHUTE_SMOKE_COLOUR = { Addresses::Addresses_Natives::Player_a::SET_PLAYER_PARACHUTE_SMOKE_COLOUR, TOC };
	//void(*SET_PLAYER_PARACHUTE_SMOKE_COLOUR)(Player player, int r, int g, int b) = (void(*)(Player, int, int, int))&_SET_PLAYER_PARACHUTE_SMOKE_COLOUR;

	/*
	-1: Normal
	0: Wearing parachute on back
	1: Parachute opening
	2: Parachute open
	3: Falling to doom (e.g. after exiting parachute)
	*/
	//opd_s _GET_PED_PARACHUTE_STATE = { Addresses::Addresses_Natives::Player_a::GET_PED_PARACHUTE_STATE, TOC };
	//int(*GET_PED_PARACHUTE_STATE)(Ped ped) = (int(*)(Ped))&_GET_PED_PARACHUTE_STATE;

	// Example: PLAYER::_977DB4641F6FC3DB(PLAYER::PLAYER_ID(), 0x73268708);
	//opd_s _REQUEST_PLAYER_PARACHUTE_MODEL = { Addresses::Addresses_Natives::Player_a::REQUEST_PLAYER_PARACHUTE_MODEL, TOC };
	//void(*REQUEST_PLAYER_PARACHUTE_MODEL)(Player player, Hash model) = (void(*)(Player, Hash))&_REQUEST_PLAYER_PARACHUTE_MODEL;

	opd_s _IS_PLAYER_SCRIPT_CONTROL_ON = { Addresses::Addresses_Natives::Player_a::IS_PLAYER_SCRIPT_CONTROL_ON, TOC };
	BOOL(*IS_PLAYER_SCRIPT_CONTROL_ON)(Player player) = (BOOL(*)(Player))&_IS_PLAYER_SCRIPT_CONTROL_ON;


	
	opd_s _SET_NIGHTVISION = { Addresses::Addresses_Natives::Player_a::SET_NIGHTVISION, TOC };
	void(*SET_NIGHTVISION)(BOOL Toggle) = (void(*)(BOOL))&_SET_NIGHTVISION;


	opd_s _SET_SEETHROUGH = { Addresses::Addresses_Natives::Player_a::SET_SEETHROUGH, TOC };
	void(*SET_SEETHROUGH)(BOOL Toggle) = (void(*)(BOOL))&_SET_SEETHROUGH;


	// Radio Stuff
	opd_s _SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY = { Addresses::Addresses_Natives::Player_a::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY, TOC };
	void(*SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY)(BOOL toggle) = (void(*)(BOOL))&_SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY;

	opd_s _SET_USER_RADIO_CONTROL_ENABLED = { Addresses::Addresses_Natives::Radio_a::SET_USER_RADIO_CONTROL_ENABLED, TOC };
	void(*SET_USER_RADIO_CONTROL_ENABLED)(BOOL p0) = (void(*)(BOOL))&_SET_USER_RADIO_CONTROL_ENABLED;

	opd_s _SET_RADIO_TRACK = { Addresses::Addresses_Natives::Radio_a::SET_RADIO_TRACK, TOC };
	void(*SET_RADIO_TRACK)(Any *p0, Any *p1) = (void(*)(Any*, Any*))&_SET_RADIO_TRACK;

	opd_s _SET_FRONTEND_RADIO_ACTIVE = { Addresses::Addresses_Natives::Radio_a::SET_FRONTEND_RADIO_ACTIVE, TOC };
	void(*SET_FRONTEND_RADIO_ACTIVE)(BOOL p0) = (void(*)(BOOL))&_SET_FRONTEND_RADIO_ACTIVE;

	opd_s _SET_RADIO_TO_STATION_INDEX = { Addresses::Addresses_Natives::Radio_a::SET_RADIO_TO_STATION_INDEX, TOC };
	void(*SET_RADIO_TO_STATION_INDEX)(Any p0) = (void(*)(Any))&_SET_RADIO_TO_STATION_INDEX;
	
	opd_s _SKIP_RADIO_FORWARD = { Addresses::Addresses_Natives::Radio_a::SKIP_RADIO_FORWARD, TOC };
	void(*SKIP_RADIO_FORWARD)() = (void(*)())&_SKIP_RADIO_FORWARD;



	


	// Boss Mode
	//opd_s _IS_PLAYER_TARGETTING_ANYTHING = { Addresses::Addresses_Natives::Player_a::IS_PLAYER_TARGETTING_ANYTHING, TOC };
	//BOOL(*IS_PLAYER_TARGETTING_ANYTHING)(Player player) = (BOOL(*)(Player))&_IS_PLAYER_TARGETTING_ANYTHING;
	
	//opd_s _IS_PLAYER_TARGETTING_ENTITY = { Addresses::Addresses_Natives::Player_a::IS_PLAYER_TARGETTING_ENTITY, TOC };
	//BOOL(*IS_PLAYER_TARGETTING_ENTITY)(Player player, Entity entity) = (BOOL(*)(Player, Entity))&_IS_PLAYER_TARGETTING_ENTITY;

	opd_s _IS_PLAYER_FREE_AIMING = { Addresses::Addresses_Natives::Player_a::IS_PLAYER_FREE_AIMING, TOC };
	BOOL(*IS_PLAYER_FREE_AIMING)(Player player) = (BOOL(*)(Player))&_IS_PLAYER_FREE_AIMING;

	opd_s _IS_PLAYER_FREE_AIMING_AT_ENTITY = { Addresses::Addresses_Natives::Player_a::IS_PLAYER_FREE_AIMING_AT_ENTITY, TOC };
	BOOL(*IS_PLAYER_FREE_AIMING_AT_ENTITY)(Player player, Entity entity) = (BOOL(*)(Player, Entity))&_IS_PLAYER_FREE_AIMING_AT_ENTITY;

	//opd_s _GET_AIMED_ENTITY = { Addresses::Addresses_Natives::Entity_a::GET_AIMED_ENTITY, TOC };
	//BOOL(*GET_AIMED_ENTITY)(Player player) = (BOOL(*)(Player))&_GET_AIMED_ENTITY;

	/*
	Returns TRUE if it found an entity in your crosshairs within range of your weapon. 
	Assigns the handle of the target to the *entity that you pass it; returns false if no entity found. 
	Player must be PLAYER::PLAYER_ID() and not PLAYER::PLAYER_PED_ID()
	*/
	//opd_s _GET_ENTITY_PLAYER_IS_FREE_AIMING_AT = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT, TOC };
	//BOOL(*GET_ENTITY_PLAYER_IS_FREE_AIMING_AT)(Player player, Entity entity) = (BOOL(*)(Player, Entity))&_GET_ENTITY_PLAYER_IS_FREE_AIMING_AT;
	
	/*
	Assigns the handle of locked-on melee target to *entity that you pass it; returns false if no entity found. 
	Player must be PLAYER::PLAYER_ID and not PLAYER::PLAYER_PED_ID
	*/
	opd_s _GET_PLAYER_TARGET_ENTITY = { Addresses::Addresses_Natives::Player_a::GET_PLAYER_TARGET_ENTITY, TOC };
	BOOL(*GET_PLAYER_TARGET_ENTITY)(Player player, Entity* entity) = (BOOL(*)(Player, Entity*))&_GET_PLAYER_TARGET_ENTITY;
	
	

	// Unknown Player Stuff
	//opd_s _unk_0x74D42C03 = { Addresses::Addresses_Natives::Entity_a::unk_0x74D42C03, TOC };
	//void(*unk_0x74D42C03)(Player player, float p1) = (void(*)(Player player, float p1))&_unk_0x74D42C03;

	opd_s _TASK_WARP_PED_INTO_VEHICLE = { Addresses::Addresses_Natives::Tasks_a::TASK_WARP_PED_INTO_VEHICLE, TOC };
	void(*TASK_WARP_PED_INTO_VEHICLE)(Ped ped, Vehicle vehicle, Any seat) = (void(*)(Ped, Vehicle, Any))&_TASK_WARP_PED_INTO_VEHICLE;



	


	//---------------------------------------------------------------------------------------------//



	//---------------------------------------------------------------------------------------------//
	// Entity


	
	opd_s _GET_ENTITY_SPEED = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_SPEED, TOC };
	float(*GET_ENTITY_SPEED)(Entity Entity) = (float(*)(Entity))&_GET_ENTITY_SPEED;

	opd_s _IS_ENTITY_IN_AIR = { Addresses::Addresses_Natives::Entity_a::IS_ENTITY_IN_AIR, TOC };
	BOOL(*IS_ENTITY_IN_AIR)(Entity Entity) = (BOOL(*)(Entity))&_IS_ENTITY_IN_AIR;

	opd_s _GET_ENTITY_FORWARD_VECTOR = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_FORWARD_VECTOR, TOC };
	Vector3(*GET_ENTITY_FORWARD_VECTOR)(Entity Entity) = (Vector3(*)(Entity))&_GET_ENTITY_FORWARD_VECTOR;

	opd_s _GET_ENTITY_FORWARD_VECTOR_ALT = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_FORWARD_VECTOR, TOC };
	Vec3(*GET_ENTITY_FORWARD_VECTOR_ALT)(Entity Entity) = (Vec3(*)(Entity))&_GET_ENTITY_FORWARD_VECTOR_ALT;

	opd_s _SET_ENTITY_VELOCITY = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_VELOCITY, TOC };
	void(*SET_ENTITY_VELOCITY)(Entity entity, float x, float y, float z) = (void(*)(Entity, float, float, float))&_SET_ENTITY_VELOCITY;

	opd_s _GET_ENTITY_VELOCITY = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_VELOCITY, TOC };
	Vec3(*GET_ENTITY_VELOCITY)(Entity Entity) = (Vec3(*)(Entity))&_GET_ENTITY_VELOCITY;
	
	opd_s _SET_ENTITY_HEADING = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_HEADING, TOC };
	void(*SET_ENTITY_HEADING)(Entity entity, float heading) = (void(*)(Entity, float))&_SET_ENTITY_HEADING;

	
	
	

	/*
	"int unk" mainly set as 2 in scripts
	"BOOL p14" mainly set as true in scripts
	*/
	opd_s _ATTACH_ENTITY_TO_ENTITY = { Addresses::Addresses_Natives::Entity_a::ATTACH_ENTITY_TO_ENTITY, TOC };
	void(*ATTACH_ENTITY_TO_ENTITY)(Entity entity1, Entity entity2, int boneIndex, float x, float y, float z, float xRot, float yRot, float zRot, BOOL p9, BOOL isRel, BOOL ignoreUpVec, BOOL allowRotation, int unk, BOOL p14) = (void(*)(Entity, Entity, int, float, float, float, float, float, float, BOOL, BOOL, BOOL, BOOL, int, BOOL))&_ATTACH_ENTITY_TO_ENTITY;

	opd_s _ATTACH_ENTITY_TO_ENTITY_PHYSICALLY = { Addresses::Addresses_Natives::Entity_a::ATTACH_ENTITY_TO_ENTITY_PHYSICALLY, TOC };
	void(*ATTACH_ENTITY_TO_ENTITY_PHYSICALLY)(Entity entity1, Entity entity2, int boneIndex, int boneIndex2, float x1, float y1, float z1, float x2, float y2, float z2, float xRot, float yRot, float zRot, float forceToBreak, BOOL p14, BOOL p15, BOOL p16, BOOL p17, Any p18) = (void(*)(Entity, Entity, int, int, float, float, float, float, float, float, float, float, float, float, BOOL, BOOL, BOOL, BOOL, Any))&_ATTACH_ENTITY_TO_ENTITY_PHYSICALLY;






	// Rope Stuff
	//The position supplied can be anywhere, and the entity should anchor relative to that point from it's origin.
	//opd_s _ATTACH_ROPE_TO_ENTITY = { Addresses::Addresses_Natives::Rope_a::ATTACH_ROPE_TO_ENTITY, TOC };
	//void(*ATTACH_ROPE_TO_ENTITY)(Any rope, Entity entity, float x, float y, float z, BOOL p5) = (void(*)(Any, Entity, float, float, float, BOOL))&_ATTACH_ROPE_TO_ENTITY;

	//opd_s _DETACH_ROPE_FROM_ENTITY = { Addresses::Addresses_Natives::Rope_a::DETACH_ROPE_FROM_ENTITY, TOC };
	//void(*DETACH_ROPE_FROM_ENTITY)(Any rope, Entity entity) = (void(*)(Any, Entity))&_DETACH_ROPE_FROM_ENTITY;

	/*
	Creates a rope at the specific position, that extends in the specified direction when not attached to any entities.
	__

	Add_Rope(pos.x,pos.y,pos.z,0.0,0.0,0.0,20.0,4,20.0,1.0,0.0,false,false,false,5.0,false,NULL)

	When attached, Position<vector> does not matter
	When attached, Angle<vector> does not matter

	Rope Type:
	4 and bellow is a thick rope
	5 and up are small metal wires
	0 crashes the game

	Max_length - Rope is forced to this length, generally best to keep this the same as your rope length.

	Rigid - If max length is zero, and this is set to false the rope will become rigid (it will force a specific distance, what ever length is, between the objects).

	breakable - Whether or not shooting the rope will break it.

	unkPtr - unknown ptr, always 0 in orig scripts
	__

	Lengths can be calculated like so:

	float distance = abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2); // Rope length


	NOTES:

	Rope does NOT interact with anything you attach it to, in some cases it make interact with the world AFTER it breaks (seems to occur if you set the type to -1).

	Rope will sometimes contract and fall to the ground like you'd expect it to, but since it doesn't interact with the world the effect is just jarring.
	*/

	//opd_s _ADD_ROPE = { Addresses::Addresses_Natives::Rope_a::ADD_ROPE, TOC };
	//Object(*ADD_ROPE)(float x, float y, float z, float rotX, float rotY, float rotZ, float length, int ropeType, float maxLength, float minLength, float p10, BOOL p11, BOOL p12, BOOL rigid, float p14, BOOL breakWhenShot, Any *unkPtr) = (Object(*)(float, float, float, float, float, float, float, int, float, float, float, BOOL, BOOL, BOOL, float, BOOL, Any*))&_ADD_ROPE;
	
	//opd_s _DELETE_ROPE = { Addresses::Addresses_Natives::Rope_a::DELETE_ROPE, TOC };
	//void(*DELETE_ROPE)(Any p0) = (void(*)(Any))&_DELETE_ROPE;

	//opd_s _ATTACH_ENTITIES_TO_ROPE = { Addresses::Addresses_Natives::Rope_a::ATTACH_ENTITIES_TO_ROPE, TOC };
	//void(*ATTACH_ENTITIES_TO_ROPE)(Object rope, Entity ent1, Entity ent2, float ent1_x, float ent1_y, float ent1_z, float ent2_x, float ent2_y, float ent2_z, float length, BOOL p10, BOOL p11, Any *p12, Any *p13) = (void(*)(Object, Entity, Entity, float, float, float, float, float, float, float, BOOL, BOOL, Any*, Any*))&_ATTACH_ENTITIES_TO_ROPE;
	
	//opd_s _ACTIVATE_PHYSICS = { Addresses::Addresses_Natives::Rope_a::ACTIVATE_PHYSICS, TOC };
	//void(*ACTIVATE_PHYSICS)(Object rope) = (void(*)(Object))&_ACTIVATE_PHYSICS;

	//opd_s _SET_DISABLE_BREAKING = { Addresses::Addresses_Natives::Rope_a::SET_DISABLE_BREAKING, TOC };
	//void(*SET_DISABLE_BREAKING)(Object rope, BOOL enabled) = (void(*)(Object, BOOL))&_SET_DISABLE_BREAKING;

	
	opd_s _ATTACH_ENTITY_TO_ENTITY_ALT = { Addresses::Addresses_Natives::Entity_a::ATTACH_ENTITY_TO_ENTITY, TOC };
	int(*ATTACH_ENTITY_TO_ENTITY_ALT)(int host,int f,int d,float* x,float* y,int c,int t,int u,int l,int fg,int re) = (int(*)(int,int,int,float*,float*,int,int,int,int,int,int))&_ATTACH_ENTITY_TO_ENTITY_ALT;

	
	opd_s _DETACH_ENTITY = { Addresses::Addresses_Natives::Entity_a::DETACH_ENTITY, TOC };
	void(*DETACH_ENTITY)(int p1,int n,int y) = (void(*)(int,int,int))&_DETACH_ENTITY;


	/*
	p1 is usually 2 in scripts
	------
	ENTITY::GET_ENTITY_ROTATION(Any p0, false or true);
	if false than return from -180 to 180
	if true than return from -90 to 90

	---

	As said above, the value of p1 affects the outcome. R* uses 1 and 2 instead of 0 and 1, so I marked it as an int.

	What it returns is the yaw on the z part of the vector, which makes sense considering R* considers z as vertical. 
	
	Here's a picture for those of you who don't understand pitch, yaw, and roll:

	http://www.allstar.fiu.edu/aero/images/pic5-1.gif

	I don't know why it returns a Vec3, but sometimes the values x and y go negative, yet they're always zero. 
	Just use GET_ENTITY_PITCH and GET_ENTITY_ROLL for pitch and roll.
	*/
	opd_s _GET_ENTITY_ROTATION = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_ROTATION, TOC };
	Vector3(*GET_ENTITY_ROTATION)(Entity entity, int p1) = (Vector3(*)(Entity, int))&_GET_ENTITY_ROTATION;

	
	//opd_s _GET_ENTITY_ROTATION_ALT = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_ROTATION, TOC };
	//Vector3(*GET_ENTITY_ROTATION_ALT)(Entity entity, int p1) = (Vector3(*)(Entity, int))&_GET_ENTITY_ROTATION_ALT;

	opd_s _GET_ENTITY_ROTATION_VELOCITY = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_ROTATION_VELOCITY, TOC };
	Vector3(*GET_ENTITY_ROTATION_VELOCITY)(Entity entity) = (Vector3(*)(Entity))&_GET_ENTITY_ROTATION_VELOCITY;


	// p4 is usually 2 in scripts and p5 is usually 1
	opd_s _SET_ENTITY_ROTATION = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_ROTATION, TOC };
	void(*SET_ENTITY_ROTATION)(Entity entity, float pitch, float roll, float yaw, int p4, BOOL p5) = (void(*)(Entity, float, float, float, int, BOOL))&_SET_ENTITY_ROTATION;
	

	opd_s _GET_ENTITY_PITCH = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_PITCH, TOC };
	float(*GET_ENTITY_PITCH)(Entity entity) = (float(*)(Entity))&_GET_ENTITY_PITCH;

	// Displays the current ROLL axis of the entity [-180.0000/180.0000+] (Sideways Roll) such as a vehicle tipped on its side
	opd_s _GET_ENTITY_ROLL = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_ROLL, TOC };
	float(*GET_ENTITY_ROLL)(Entity entity) = (float(*)(Entity))&_GET_ENTITY_ROLL;


	

	

	//opd_s _ATTACH_TV_AUDIO_TO_ENTITY = { Addresses::Addresses_Natives::Entity_a::ATTACH_TV_AUDIO_TO_ENTITY, TOC };
	//void(*ATTACH_TV_AUDIO_TO_ENTITY)(Any p0) = (void(*)(Any))&_ATTACH_TV_AUDIO_TO_ENTITY;

	//opd_s _ATTACH_SYNCHRONIZED_SCENE_TO_ENTITY = { Addresses::Addresses_Natives::Entity_a::ATTACH_SYNCHRONIZED_SCENE_TO_ENTITY, TOC };
	//void(*ATTACH_SYNCHRONIZED_SCENE_TO_ENTITY)(Any p0, Any p1, Any p2) = (void(*)(Any, Any, Any))&_ATTACH_SYNCHRONIZED_SCENE_TO_ENTITY;

	//opd_s _DETACH_SYNCHRONIZED_SCENE = { Addresses::Addresses_Natives::Entity_a::DETACH_SYNCHRONIZED_SCENE, TOC };
	//void(*DETACH_SYNCHRONIZED_SCENE)(Any p0) = (void(*)(Any))&_DETACH_SYNCHRONIZED_SCENE;

	opd_s _DOES_ENTITY_EXIST = { Addresses::Addresses_Natives::Entity_a::DOES_ENTITY_EXIST, TOC };
	BOOL(*DOES_ENTITY_EXIST)(Entity Entity) = (BOOL(*)(Entity))&_DOES_ENTITY_EXIST;

	opd_s _SET_ENTITY_AS_MISSION_ENTITY = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_AS_MISSION_ENTITY, TOC };
	void(*SET_ENTITY_AS_MISSION_ENTITY)(Entity entity, BOOL value, BOOL p2) = (void(*)(Entity, BOOL, BOOL))&_SET_ENTITY_AS_MISSION_ENTITY;

	opd_s _IS_ENTITY_DEAD = { Addresses::Addresses_Natives::Entity_a::IS_ENTITY_DEAD, TOC };
	BOOL(*IS_ENTITY_DEAD)(Entity Entity) = (BOOL(*)(Entity))&_IS_ENTITY_DEAD;
	
	opd_s _IS_ENTITY_ON_FIRE = { Addresses::Addresses_Natives::Entity_a::IS_ENTITY_ON_FIRE, TOC };
	BOOL(*IS_ENTITY_ON_FIRE)(Entity Entity) = (BOOL(*)(Entity))&_IS_ENTITY_ON_FIRE;
	
	
	opd_s _START_ENTITY_FIRE = { Addresses::Addresses_Natives::Entity_a::START_ENTITY_FIRE, TOC };
	void(*START_ENTITY_FIRE)(Entity Entity) = (void(*)(Entity))&_START_ENTITY_FIRE;

	opd_s _STOP_ENTITY_FIRE = { Addresses::Addresses_Natives::Entity_a::STOP_ENTITY_FIRE, TOC };
	void(*STOP_ENTITY_FIRE)(Entity Entity) = (void(*)(Entity))&_STOP_ENTITY_FIRE;

	
	opd_s getCoords = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_COORDS, TOC };
	void(*entityCoords)(int address, uint pedID) = (void(*)(int, uint))&getCoords;

	opd_s _entityCoordsAlt = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_COORDS, TOC };
	void(*entityCoordsAlt)(int address, uint pedID) = (void(*)(int, uint))&_entityCoordsAlt;

	//opd_s _GET_ENTITY_COORDS_2 = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_COORDS, TOC };
	//Vec3(*GET_ENTITY_COORDS_2)(int p1) = (Vec3(*)(int))&_GET_ENTITY_COORDS_2;

	opd_s _GET_ENTITY_COORDS = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_COORDS, TOC };
	Vec3(*GET_ENTITY_COORDS)(int p1, bool p2) = (Vec3(*)(int, bool))&_GET_ENTITY_COORDS;

	opd_s _GET_ENTITY_COORDS_XYZ = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_COORDS, TOC };
	Vector3(*GET_ENTITY_COORDS_XYZ)(Entity entity, BOOL p1) = (Vector3(*)(Entity, BOOL))&_GET_ENTITY_COORDS_XYZ;

	//opd_s _GET_ENTITY_COORDS = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_COORDS, TOC };
	//Vector3(*GET_ENTITY_COORDS)(int p1, bool p2) = (Vector3(*)(int, bool))&_GET_ENTITY_COORDS;

	opd_s _GET_ENTITY_HEADING = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_HEADING, TOC };
	float(*GET_ENTITY_HEADING)(Entity entity) = (float(*)(Entity))&_GET_ENTITY_HEADING;

	opd_s _SET_ENTITY_COORDS = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_COORDS, TOC };
	int(*SET_ENTITY_COORDS)(int PedID, float* numArray, int r0, int r1, int r2, int r3) = (int(*)(int, float*, int, int, int, int))&_SET_ENTITY_COORDS;
	
	opd_s _FREEZE_ENTITY_POSITION = { Addresses::Addresses_Natives::Entity_a::FREEZE_ENTITY_POSITION, TOC };
	void(*FREEZE_ENTITY_POSITION)(Entity entity, BOOL toggle) = (void(*)(Entity, BOOL))&_FREEZE_ENTITY_POSITION;
	
	opd_s _IS_ENTITY_VISIBLE = { Addresses::Addresses_Natives::Entity_a::IS_ENTITY_VISIBLE, TOC };
	BOOL(*IS_ENTITY_VISIBLE)(Entity entity) = (BOOL(*)(Entity))&_IS_ENTITY_VISIBLE;

	opd_s _SET_ENTITY_VISIBLE = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_VISIBLE, TOC };
	void(*SET_ENTITY_VISIBLE)(int p1, bool p2) = (void(*)(int, bool))&_SET_ENTITY_VISIBLE;

	opd_s _SET_ENTITY_ALPHA = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_ALPHA, TOC };
	void(*SET_ENTITY_ALPHA)(Entity entity, int alphaLevel, BOOL p2) = (void(*)(Entity, int, BOOL))&_SET_ENTITY_ALPHA;

	opd_s _GET_ENTITY_MODEL = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_MODEL, TOC };
	Hash(*GET_ENTITY_MODEL)(Entity entity) = (Hash(*)(Entity))&_GET_ENTITY_MODEL;
	
	opd_s _IS_ENTITY_IN_WATER = { Addresses::Addresses_Natives::Entity_a::IS_ENTITY_IN_WATER, TOC };
	BOOL(*IS_ENTITY_IN_WATER)(Entity entity) = (BOOL(*)(Entity))&_IS_ENTITY_IN_WATER;
	
	//opd_s _SET_ENTITY_LOCALLY_INVISIBLE = { Addresses::Addresses_Natives::Entity::SET_ENTITY_LOCALLY_INVISIBLE, TOC };
	//
	
	opd_s _SET_ENTITY_INVINCIBLE = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_INVINCIBLE, TOC };
	void(*SET_ENTITY_INVINCIBLE)(int p1, bool p2) = (void(*)(int, bool))&_SET_ENTITY_INVINCIBLE;

	//opd_s _SET_ENTITY_INVINCIBLE = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_INVINCIBLE, TOC };
	//void(*SET_ENTITY_INVINCIBLE)(int playerID, int ed) = (void(*)(int,int))&_SET_ENTITY_INVINCIBLE;

	//opd_s _APPLY_FORCE_TO_ENTITY_ALT = { Addresses::Addresses_Natives::Entity_a::APPLY_FORCE_TO_ENTITY, TOC };
	//void(*APPLY_FORCE_TO_ENTITY_ALT)(int p0, int p1, float* Force, float* Pos, int p8, int p9, int p10, int p11, int p12, int p13) = (void(*)(int, int, float* Force, float* Pos, int, int, int, int, int, int))&_APPLY_FORCE_TO_ENTITY_ALT;
	
	// isRel - specifies if the force direction is relative to direction entity is facing (true), or static world direction (false).
	opd_s _APPLY_FORCE_TO_ENTITY = { Addresses::Addresses_Natives::Entity_a::APPLY_FORCE_TO_ENTITY, TOC };
	void(*APPLY_FORCE_TO_ENTITY)(Entity entity, int forceType, float x, float y, float z, float xRot, float yRot, float zRot, BOOL p8, BOOL isRel, BOOL ignoreUpVec, BOOL p11, BOOL p12, BOOL p13) = (void(*)(Entity, int, float, float, float, float, float, float, BOOL, BOOL, BOOL, BOOL, BOOL, BOOL))&_APPLY_FORCE_TO_ENTITY;
	
	opd_s _APPLY_FORCE_TO_ENTITY_ALT = { Addresses::Addresses_Natives::Entity_a::APPLY_FORCE_TO_ENTITY, TOC };
	void(*APPLY_FORCE_TO_ENTITY_ALT)(int p0, int p1, float* Force, float* Pos, int p8, int p9, int p10, int p11, int p12, int p13) = (void(*)(int, int, float* Force, float* Pos, int, int, int, int, int, int))&_APPLY_FORCE_TO_ENTITY_ALT;

	void APPLY_FORCE(Entity entity, float f, float o, float r, float p, float v, float s)
	{
		float xyz[3] = { f, o, r };
		float pos[3] = { p, v, s };
		APPLY_FORCE_TO_ENTITY_ALT(entity, 1, xyz, pos, 0, 1, 1, 1, 0, 1);
	}

	//opd_s _SET_ENTITY_COORDS_TELEPORT_ALT = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_COORDS_TELEPORT, TOC };
	//void(*SET_ENTITY_COORDS_TELEPORT_ALT)(uint PlayerID, float* TeleportFunc, bool b1, bool b2, bool b3, bool b4) = (void(*)(uint, float*, bool, bool, bool, bool))&_SET_ENTITY_COORDS_TELEPORT_ALT;
	
	//opd_s _SET_ENTITY_COORDS_TELEPORT = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_COORDS_TELEPORT, TOC };
	//void(*SET_ENTITY_COORDS_TELEPORT)(Player player, float* TeleportFunc, BOOL b1, BOOL b2, BOOL b3, BOOL b4) = (void(*)(Player, float*, BOOL, BOOL, BOOL, BOOL))&_SET_ENTITY_COORDS_TELEPORT;
	
	opd_s _GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS = { Addresses::Addresses_Natives::Entity_a::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS, TOC };
	Vector3(*GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS)(Entity entity, float xOffset, float yOffset, float zOffset) = (Vector3(*)(Entity, float, float, float))&_GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS;
	
	opd_s _SET_ENTITY_PROOFS = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_PROOFS, TOC };
	void(*SET_ENTITY_PROOFS)(Entity entity, BOOL bulletProof, BOOL fireProof, BOOL explosionProof, BOOL collisionProof, BOOL meleeProof, BOOL p6, BOOL p7, BOOL drownProof) = (void(*)(Entity, BOOL, BOOL, BOOL, BOOL, BOOL, BOOL, BOOL, BOOL))&_SET_ENTITY_PROOFS;
	
	
	
	opd_s _SET_ENTITY_AS_NO_LONGER_NEEDED = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_AS_NO_LONGER_NEEDED, TOC };
	void(*SET_ENTITY_AS_NO_LONGER_NEEDED)(Entity *entity) = (void(*)(Entity*))&_SET_ENTITY_AS_NO_LONGER_NEEDED;
	
	opd_s _SET_ENTITY_CAN_BE_DAMAGED = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_CAN_BE_DAMAGED, TOC };
	void(*SET_ENTITY_CAN_BE_DAMAGED)(Entity entity, BOOL toggle) = (void(*)(Entity, BOOL))&_SET_ENTITY_CAN_BE_DAMAGED;

	//opd_s _SET_ENTITY_MOTION_BLUR = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_MOTION_BLUR, TOC };
	//void(*SET_ENTITY_MOTION_BLUR)(Entity entity, BOOL toggle) = (void(*)(Entity, BOOL))&_SET_ENTITY_MOTION_BLUR;

	//opd_s _SET_ENTITY_NO_COLLISION_ENTITY = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_NO_COLLISION_ENTITY, TOC };
	//void(*SET_ENTITY_NO_COLLISION_ENTITY)(Entity entity1, Entity entity2, BOOL toggle) = (void(*)(Entity, Entity, BOOL))&_SET_ENTITY_NO_COLLISION_ENTITY;

	/*
	Collision on when toggle -> 1
	Collision off when toggle -> 0
	p2 is always 0 in the decompiled scripts (gtav.ysc.decompiled)
	*/
	opd_s _SET_ENTITY_COLLISION = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_COLLISION, TOC };
	void(*SET_ENTITY_COLLISION)(Entity entity, BOOL toggle, BOOL p2) = (void(*)(Entity, BOOL, BOOL))&_SET_ENTITY_COLLISION;

	opd_s _SET_ENTITY_MAX_SPEED = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_MAX_SPEED, TOC };
	void(*SET_ENTITY_MAX_SPEED)(Entity entity, float speed) = (void(*)(Entity, float))&_SET_ENTITY_MAX_SPEED;

	opd_s _SET_ENTITY_LIGHTS = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_LIGHTS, TOC };
	void(*SET_ENTITY_LIGHTS)(Entity entity, BOOL toggle) = (void(*)(Entity, BOOL))&_SET_ENTITY_LIGHTS;

	
	opd_s _SET_ENTITY_HAS_GRAVITY = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_HAS_GRAVITY, TOC };
	void(*SET_ENTITY_HAS_GRAVITY)(Entity entity, BOOL toggle) = (void(*)(Entity, BOOL))&_SET_ENTITY_HAS_GRAVITY;
	
	opd_s _SET_ENTITY_MAX_HEALTH = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_MAX_HEALTH, TOC };
	void(*SET_ENTITY_MAX_HEALTH)(Entity entity, int value) = (void(*)(Entity, int))&_SET_ENTITY_MAX_HEALTH;

	opd_s _GET_ENTITY_MAX_HEALTH = { Addresses::Addresses_Natives::Entity_a::GET_ENTITY_MAX_HEALTH, TOC };
	int(*GET_ENTITY_MAX_HEALTH)(Entity entity) = (int(*)(Entity))&_GET_ENTITY_MAX_HEALTH;

	opd_s _SET_ENTITY_HEALTH = { Addresses::Addresses_Natives::Entity_a::SET_ENTITY_HEALTH, TOC };
	void(*SET_ENTITY_HEALTH)(Entity entity, int health) = (void(*)(Entity, int))&_SET_ENTITY_HEALTH;

	
	
	//---------------------------------------------------------------------------------------------//



	
	//---------------------------------------------------------------------------------------------//
	// Camera

	//opd_s _GET_GAMEPLAY_CAM_ROT = { Addresses::Addresses_Natives::Camera_a::GET_GAMEPLAY_CAM_ROT, TOC };
	//Vector3(*GET_GAMEPLAY_CAM_ROT)(Any p0) = (Vector3(*)(Any))&_GET_GAMEPLAY_CAM_ROT;

	//opd_s _GET_GAMEPLAY_CAM_ROT = { Addresses::Addresses_Natives::Camera_a::GET_GAMEPLAY_CAM_ROT, TOC };
	//Vec3(*GET_GAMEPLAY_CAM_ROT)(Any p0) = (Vec3(*)(Any))&_GET_GAMEPLAY_CAM_ROT;
	
	//opd_s _GET_GAMEPLAY_CAM_ROT = { Addresses::Addresses_Natives::Camera_a::GET_GAMEPLAY_CAM_ROT, TOC };
	//Vec3(*GET_GAMEPLAY_CAM_ROT)(int) = (Vec3(*)(int))&_GET_GAMEPLAY_CAM_ROT;
	
	//opd_s _ATTACH_CAM_TO_ENTITY = { Addresses::Addresses_Natives::Camera_a::ATTACH_CAM_TO_ENTITY, TOC };
	//void(*ATTACH_CAM_TO_ENTITY)(Any cam, Entity entity, float xOffset, float yOffset, float zOffset, BOOL p5) = (void(*)(Any, Entity, float, float, float, BOOL))&_ATTACH_CAM_TO_ENTITY;
	//---------------------------------------------------------------------------------------------//
	


	
	//---------------------------------------------------------------------------------------------//
	// Models
	opd_s _IS_MODEL_IN_CDIMAGE = { Addresses::Addresses_Natives::Models_a::IS_MODEL_IN_CDIMAGE, TOC };
	BOOL(*IS_MODEL_IN_CDIMAGE)(Hash model) = (BOOL(*)(Hash))&_IS_MODEL_IN_CDIMAGE;

	opd_s _IS_MODEL_VALID = { Addresses::Addresses_Natives::Models_a::IS_MODEL_VALID, TOC };
	BOOL(*IS_MODEL_VALID)(Hash model) = (BOOL(*)(Hash))&_IS_MODEL_VALID;

	//opd_s _IS_MODEL_VALID = { Addresses::Addresses_Natives::Models_a::IS_MODEL_VALID, TOC };
	//BOOL(*IS_MODEL_VALID)(uint Hash) = (BOOL(*)(uint))&_IS_MODEL_VALID;

	//opd_s _IS_MODEL_A_VEHICLE = { Addresses::Addresses_Natives::Models_a::IS_MODEL_A_VEHICLE, TOC };
	//BOOL(*IS_MODEL_A_VEHICLE)(Hash model) = (BOOL(*)(Hash))&_IS_MODEL_A_VEHICLE;

	//opd_s _IS_MODEL_A_VEHICLE = { Addresses::Addresses_Natives::Models_a::IS_MODEL_A_VEHICLE, TOC };
	//BOOL(*IS_MODEL_A_VEHICLE)(uint Hash) = (BOOL(*)(uint))&_IS_MODEL_A_VEHICLE;

	
	
	//opd_s _REQUEST_MODEL = { Addresses::Addresses_Natives::Models_a::REQUEST_MODEL, TOC };
	//void(*REQUEST_MODEL)(int Hash) = (void(*)(int))&_REQUEST_MODEL;

	//opd_s _CREATE_AMBIENT_PICKUP = { Addresses::Addresses_Natives::Models_a::CREATE_AMBIENT_PICKUP, TOC };
	//void(*CREATE_AMBIENT_PICKUP)(int hash, float* xyz, int a, int b, int c, int d, int e) = (void(*)(int, float*, int, int, int, int, int))&_CREATE_AMBIENT_PICKUP;

	//opd_s _CREATE_AMBIENT_PICKUP = { Addresses::Addresses_Natives::Models_a::CREATE_AMBIENT_PICKUP, TOC };
	//void(*CREATE_AMBIENT_PICKUP)(uint hash, float* xyz, int a, int b, int c, int d, int e) = (void(*)(uint, float*, int, int, int, int, int))&_CREATE_AMBIENT_PICKUP;

	opd_s _CREATE_AMBIENT_PICKUP_ALT = { Addresses::Addresses_Natives::Models_a::CREATE_AMBIENT_PICKUP, TOC };
	void(*CREATE_AMBIENT_PICKUP_ALT)(Hash pickupHash, float posX, float posY, float posZ, int p4, int value, Hash modelHash, BOOL p7, BOOL p8) = (void(*)(Hash, float, float, float, int, int, Hash, BOOL, BOOL))&_CREATE_AMBIENT_PICKUP_ALT;

	opd_s _CREATE_AMBIENT_PICKUP = { Addresses::Addresses_Natives::Models_a::CREATE_AMBIENT_PICKUP, TOC };
	void(*CREATE_AMBIENT_PICKUP)(Hash pickupHash, float* xyz, int p4, int value, Hash modelHash, BOOL p7, BOOL p8) = (void(*)(Hash, float*, int, int, Hash, BOOL, BOOL))&_CREATE_AMBIENT_PICKUP;

	opd_s _CREATE_AMBIENT_PICKUP_UINT = { Addresses::Addresses_Natives::Models_a::CREATE_AMBIENT_PICKUP, TOC };
	void(*CREATE_AMBIENT_PICKUP_UINT)(uint pickupHash, float* xyz, int p4, int value, Hash modelHash, BOOL p7, BOOL p8) = (void(*)(uint, float*, int, int, Hash, BOOL, BOOL))&_CREATE_AMBIENT_PICKUP_UINT;

	opd_s _REQUEST_MODEL = { Addresses::Addresses_Natives::Models_a::REQUEST_MODEL, TOC };
	void(*REQUEST_MODEL)(uint Hash) = (void(*)(uint))&_REQUEST_MODEL;

	//opd_s _REQUEST_MODEL = { Addresses::Addresses_Natives::Models_a::REQUEST_MODEL, TOC };
	//void(*REQUEST_MODEL)(Hash model) = (void(*)(Hash))&_REQUEST_MODEL;

	//opd_s _HAS_MODEL_LOADED = { Addresses::Addresses_Natives::Models_a::HAS_MODEL_LOADED, TOC };
	//BOOL(*HAS_MODEL_LOADED)(Hash model) = (BOOL(*)(Hash))&_HAS_MODEL_LOADED;
	
	opd_s _HAS_MODEL_LOADED = {Addresses::Addresses_Natives::Models_a::HAS_MODEL_LOADED, TOC};
	bool(*HAS_MODEL_LOADED)(uint Hash) = (bool(*)(uint))&_HAS_MODEL_LOADED;

	opd_s _SET_MODEL_AS_NO_LONGER_NEEDED = { Addresses::Addresses_Natives::Models_a::SET_MODEL_AS_NO_LONGER_NEEDED, TOC };
	int(*SET_MODEL_AS_NO_LONGER_NEEDED)(int Hash) = (int(*)(int))&_SET_MODEL_AS_NO_LONGER_NEEDED;
	//---------------------------------------------------------------------------------------------//


	//---------------------------------------------------------------------------------------------//
	// HUD
	opd_s _DISPLAY_HUD = { Addresses::Addresses_Natives::Hud_a::Hud_Stuff::DISPLAY_HUD, TOC };
	void(*DISPLAY_HUD)(BOOL toggle) = (void(*)(BOOL))&_DISPLAY_HUD;

	// Radar
	opd_s _DISPLAY_RADAR = { Addresses::Addresses_Natives::Hud_a::Radar_a::DISPLAY_RADAR, TOC };
	void(*DISPLAY_RADAR)(BOOL toggle) = (void(*)(BOOL))&_DISPLAY_RADAR;

	opd_s _TOGGLE_STEALTH_RADAR = { Addresses::Addresses_Natives::Hud_a::Radar_a::TOGGLE_STEALTH_RADAR, TOC };
	void(*TOGGLE_STEALTH_RADAR)(BOOL p0) = (void(*)(BOOL))&_TOGGLE_STEALTH_RADAR;

	//opd_s _IS_RADAR_HIDDEN = { Addresses::Addresses_Natives::Hud_a::Radar_a::IS_RADAR_HIDDEN, TOC };
	//BOOL(*IS_RADAR_HIDDEN)() = (BOOL(*)())&_IS_RADAR_HIDDEN;

	//opd_s _IS_RADAR_PREFERENCE_SWITCHED_ON = { Addresses::Addresses_Natives::Hud_a::Radar_a::IS_RADAR_PREFERENCE_SWITCHED_ON, TOC };
	//BOOL(*IS_RADAR_PREFERENCE_SWITCHED_ON)() = (BOOL(*)())&_IS_RADAR_PREFERENCE_SWITCHED_ON;

	//opd_s _SET_RADAR_ZOOM = { Addresses::Addresses_Natives::Hud_a::Radar_a::SET_RADAR_ZOOM, TOC };
	//void(*SET_RADAR_ZOOM)(int p0) = (void(*)(int))&_SET_RADAR_ZOOM;

	//opd_s __SET_RADAR_ZOOM_LEVEL_THIS_FRAME = { Addresses::Addresses_Natives::Hud_a::_SET_RADAR_ZOOM_LEVEL_THIS_FRAME, TOC };
	//void(*_SET_RADAR_ZOOM_LEVEL_THIS_FRAME)() = (void(*)())&__SET_RADAR_ZOOM_LEVEL_THIS_FRAME;

	//opd_s _SET_RADAR_AS_INTERIOR_THIS_FRAME = { Addresses::Addresses_Natives::Hud_a::Radar_a::SET_RADAR_AS_INTERIOR_THIS_FRAME, TOC };
	//void(*SET_RADAR_AS_INTERIOR_THIS_FRAME)(Any p0, float p1, float p2, Any p3, Any p4) = (void(*)(Any, float, float, Any, Any))&_SET_RADAR_AS_INTERIOR_THIS_FRAME;

	//opd_s _SET_RADAR_AS_EXTERIOR_THIS_FRAME = { Addresses::Addresses_Natives::Hud_a::Radar_a::SET_RADAR_AS_EXTERIOR_THIS_FRAME, TOC };
	//void(*SET_RADAR_AS_EXTERIOR_THIS_FRAME)() = (void(*)())&_SET_RADAR_AS_EXTERIOR_THIS_FRAME;

	opd_s _SET_NEW_WAYPOINT = { Addresses::Addresses_Natives::Hud_a::Hud_Stuff::SET_NEW_WAYPOINT, TOC };
	void(*SET_NEW_WAYPOINT)(float x, float y) = (void(*)(float, float))&_SET_NEW_WAYPOINT;

	opd_s _SET_WAYPOINT_OFF = { Addresses::Addresses_Natives::Hud_a::Hud_Stuff::SET_WAYPOINT_OFF, TOC };
	void(*SET_WAYPOINT_OFF)() = (void(*)())&_SET_WAYPOINT_OFF;


	// Blip Stuff
	
	opd_s _GET_FIRST_BLIP_INFO_ID = { Addresses::Addresses_Natives::Hud_a::Hud_Stuff::GET_FIRST_BLIP_INFO_ID, TOC };
	int(*GET_FIRST_BLIP_INFO_ID)(int blip) = (int(*)(int))&_GET_FIRST_BLIP_INFO_ID;

	opd_s _DOES_BLIP_EXIST = { Addresses::Addresses_Natives::Hud_a::Hud_Stuff::DOES_BLIP_EXIST, TOC };
	BOOL(*DOES_BLIP_EXIST)(Any p0) = (BOOL(*)(Any))&_DOES_BLIP_EXIST;
	
	opd_s _GET_BLIP_COORDS = { Addresses::Addresses_Natives::Hud_a::Hud_Stuff::GET_BLIP_COORDS, TOC };
	Vector3(*GET_BLIP_COORDS)(Any p0) = (Vector3(*)(Any))&_GET_BLIP_COORDS;

	opd_s _GET_BLIP_COORDS_ALT = { Addresses::Addresses_Natives::Hud_a::Hud_Stuff::GET_BLIP_COORDS, TOC };
	Vec3(*GET_BLIP_COORDS_ALT)(Any p0) = (Vec3(*)(Any))&_GET_BLIP_COORDS_ALT;

	
	
	//---------------------------------------------------------------------------------------------//



	//---------------------------------------------------------------------------------------------//
	// Tasks
	opd_s _TASK_SKY_DIVE = { Addresses::Addresses_Natives::Tasks_a::TASK_SKY_DIVE, TOC };
	void(*TASK_SKY_DIVE)(Ped ped) = (void(*)(Ped))&_TASK_SKY_DIVE; 
	//---------------------------------------------------------------------------------------------//
	
	
	

	//---------------------------------------------------------------------------------------------//
	// Animations
	opd_s _REQUEST_ANIM_DICT = { Addresses::Addresses_Natives::Animations_a::REQUEST_ANIM_DICT, TOC };
	void(*REQUEST_ANIM_DICT)(char *animDict) = (void(*)(char *))&_REQUEST_ANIM_DICT; 
	
	opd_s _REMOVE_ANIM_DICT = { Addresses::Addresses_Natives::Animations_a::REMOVE_ANIM_DICT, TOC };
	void(*REMOVE_ANIM_DICT)(char *animDict) = (void(*)(char *))&_REMOVE_ANIM_DICT; 
	
	opd_s _REQUEST_ANIM_SET = { Addresses::Addresses_Natives::Animations_a::REQUEST_ANIM_SET, TOC };
	void(*REQUEST_ANIM_SET)(char *animSet) = (void(*)(char *))&_REQUEST_ANIM_SET; 
	
	opd_s _REMOVE_ANIM_SET = { Addresses::Addresses_Natives::Animations_a::REMOVE_ANIM_SET, TOC };
	void(*REMOVE_ANIM_SET)(char *animSet) = (void(*)(char *))&_REMOVE_ANIM_SET; 
	
	opd_s _HAS_ANIM_DICT_LOADED = { Addresses::Addresses_Natives::Animations_a::HAS_ANIM_DICT_LOADED, TOC };
	BOOL(*HAS_ANIM_DICT_LOADED)(char *animDict) = (BOOL(*)(char *))&_HAS_ANIM_DICT_LOADED; 
	
	opd_s _HAS_ANIM_SET_LOADED = { Addresses::Addresses_Natives::Animations_a::HAS_ANIM_SET_LOADED, TOC };
	BOOL(*HAS_ANIM_SET_LOADED)(char *animSet) = (BOOL(*)(char *))&_HAS_ANIM_SET_LOADED; 
	
	opd_s _STOP_ANIM_PLAYBACK = { Addresses::Addresses_Natives::Animations_a::STOP_ANIM_PLAYBACK, TOC };
	void(*STOP_ANIM_PLAYBACK)(Any p0, Any p1, BOOL p2) = (void(*)(Any, Any, BOOL))&_STOP_ANIM_PLAYBACK; 
	
	opd_s _STOP_ANIM_TASK = { Addresses::Addresses_Natives::Animations_a::STOP_ANIM_TASK, TOC };
	void(*STOP_ANIM_TASK)(Any p0, Any *p1, Any *p2, float p3) = (void(*)(Any, Any*, Any*, float))&_STOP_ANIM_TASK; 
	
	opd_s _TASK_PLAY_ANIM = { Addresses::Addresses_Natives::Animations_a::TASK_PLAY_ANIM, TOC };
	void(*TASK_PLAY_ANIM)(Ped ped, char *animDictionary, char *animationName, float speed, float speedMultiplier, int duration, int flag, float playbackRate, BOOL lockX, BOOL lockY, BOOL lockZ) = (void(*)(Ped, char*, char*, float, float, int, int, float, BOOL, BOOL, BOOL))&_TASK_PLAY_ANIM; 
	
	//opd_s _SET_ANIM_LOOPED = { Addresses::Addresses_Natives::Animations_a::SET_ANIM_LOOPED, TOC };
	//void(*SET_ANIM_LOOPED)(Any p0, BOOL p1, Any p2, BOOL p3) = (void(*)(Any, BOOL, Any, BOOL))&_SET_ANIM_LOOPED; 

	//opd_s _SET_ANIM_RATE = { Addresses::Addresses_Natives::Animations_a::SET_ANIM_RATE, TOC };
	//void(*SET_ANIM_RATE)(Any p0, float p1, Any p2, BOOL p3) = (void(*)(Any, float, Any, BOOL))&_SET_ANIM_RATE; 
	
	//opd_s _SET_ANIM_WEIGHT = { Addresses::Addresses_Natives::Animations_a::SET_ANIM_WEIGHT, TOC };
	//void(*SET_ANIM_WEIGHT)(Any p0, float p1, Any p2, Any p3, BOOL p4) = (void(*)(Any, float, Any, Any, BOOL))&_SET_ANIM_WEIGHT; 
	//---------------------------------------------------------------------------------------------//


	
	//---------------------------------------------------------------------------------------------//
	// Keyboard
	//
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
	// Network

	opd_s _NETWORK_IS_GAME_IN_PROGRESS = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_GAME_IN_PROGRESS, TOC };
	BOOL(*NETWORK_IS_GAME_IN_PROGRESS)() = (BOOL(*)())&_NETWORK_IS_GAME_IN_PROGRESS; 

	
	opd_s _SET_NETWORK_ID_CAN_MIGRATE = { Addresses::Addresses_Natives::Network_a::SET_NETWORK_ID_CAN_MIGRATE, TOC };
	void(*SET_NETWORK_ID_CAN_MIGRATE)(Any p0, BOOL p1) = (void(*)(Any, BOOL))&_SET_NETWORK_ID_CAN_MIGRATE; 

	opd_s _NETWORK_END_TUTORIAL_SESSION = { Addresses::Addresses_Natives::Network_a::NETWORK_END_TUTORIAL_SESSION, TOC };
	void(*NETWORK_END_TUTORIAL_SESSION)() = (void(*)())&_NETWORK_END_TUTORIAL_SESSION; 

	opd_s _SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES = { Addresses::Addresses_Natives::Network_a::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES, TOC };
	void(*SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES)(int NetID, BOOL DoesExist) = (void(*)(int, BOOL))&_SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES; 

	opd_s _SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES_ALT = { Addresses::Addresses_Natives::Network_a::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES, TOC };
	int(*SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES_ALT)(int p1, int t) = (int(*)(int, int))&_SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES_ALT; 

	opd_s _NETWORK_SESSION_KICK_PLAYER = { Addresses::Addresses_Natives::Network_a::NETWORK_SESSION_KICK_PLAYER, TOC };
	void(*NETWORK_SESSION_KICK_PLAYER)(Player player) = (void(*)(Player))&_NETWORK_SESSION_KICK_PLAYER; 

	opd_s _NETWORK_SESSION_KICK_PLAYER_ALT = { Addresses::Addresses_Natives::Network_a::NETWORK_SESSION_KICK_PLAYER, TOC };
	int(*NETWORK_SESSION_KICK_PLAYER_ALT)(Player player) = (int(*)(Player))&_NETWORK_SESSION_KICK_PLAYER_ALT; 

	opd_s _NETWORK_IS_CLOUD_AVAILABLE = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_CLOUD_AVAILABLE, TOC };
	Any(*NETWORK_IS_CLOUD_AVAILABLE)() = (Any(*)())&_NETWORK_IS_CLOUD_AVAILABLE; 

	//opd_s _NETWORK_SEND_TEXT_MESSAGE = { Addresses::Addresses_Natives::Network_a::NETWORK_SEND_TEXT_MESSAGE, TOC };
	//Any(*NETWORK_SEND_TEXT_MESSAGE)(char* message, int* playerId) = (Any(*)(char*, int*))&_NETWORK_SEND_TEXT_MESSAGE; 

	
	//opd_s _NETWORK_GET_HOST_OF_SCRIPT = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_HOST_OF_SCRIPT, TOC };
	//int(*NETWORK_GET_HOST_OF_SCRIPT)(const char* script, int unk, int unk2) = (int(*)(const char*, int, int))&_NETWORK_GET_HOST_OF_SCRIPT;

	opd_s _NETWORK_GET_HOST_OF_SCRIPT = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_HOST_OF_SCRIPT, TOC };
	int(*NETWORK_GET_HOST_OF_SCRIPT)(char* gamemode, Any p1, Any p2) = (int(*)(char*, Any, Any))&_NETWORK_GET_HOST_OF_SCRIPT;

	opd_s _NETWORK_GET_HOST_OF_THIS_SCRIPT = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_HOST_OF_THIS_SCRIPT, TOC };
	Any(*NETWORK_GET_HOST_OF_THIS_SCRIPT)() = (Any(*)())&_NETWORK_GET_HOST_OF_THIS_SCRIPT;

	opd_s _NETWORK_IS_PLAYER_ACTIVE = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_PLAYER_ACTIVE, TOC };
	BOOL(*NETWORK_IS_PLAYER_ACTIVE)(int playerID) = (BOOL(*)(int))&_NETWORK_IS_PLAYER_ACTIVE;

	//opd_s _NETWORK_IS_PLAYER_A_PARTICIPANT = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_PLAYER_A_PARTICIPANT, TOC };
	//BOOL(*NETWORK_IS_PLAYER_A_PARTICIPANT)(Any p0) = (BOOL(*)(Any))&_NETWORK_IS_PLAYER_A_PARTICIPANT;

	//opd_s _NETWORK_IS_PARTICIPANT_ACTIVE = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_PARTICIPANT_ACTIVE, TOC };
	//BOOL(*NETWORK_IS_PARTICIPANT_ACTIVE)(Any p0) = (BOOL(*)(Any))&_NETWORK_IS_PARTICIPANT_ACTIVE;

	//opd_s _NETWORK_IS_PLAYER_CONNECTED = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_PLAYER_CONNECTED, TOC };
	//BOOL(*NETWORK_IS_PLAYER_CONNECTED)(Any p0) = (BOOL(*)(Any))&_NETWORK_IS_PLAYER_CONNECTED;

	//opd_s _NETWORK_GET_PARTICIPANT_INDEX = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_PARTICIPANT_INDEX, TOC };
	//Any(*NETWORK_GET_PARTICIPANT_INDEX)(Any p0) = (Any(*)(Any))&_NETWORK_GET_PARTICIPANT_INDEX;

	//opd_s _NETWORK_GET_PLAYER_INDEX = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_PLAYER_INDEX, TOC };
	//Any(*NETWORK_GET_PLAYER_INDEX)(Ped PedHandle) = (Any(*)(Ped))&_NETWORK_GET_PLAYER_INDEX;

	//opd_s _NETWORK_REGISTER_PLAYER_BROADCAST_VARIABLES = { Addresses::Addresses_Natives::Network_a::NETWORK_REGISTER_PLAYER_BROADCAST_VARIABLES, TOC };
	//void(*NETWORK_REGISTER_PLAYER_BROADCAST_VARIABLES)(Any* p0, Any p1) = (void(*)(Any*, Any))&_NETWORK_REGISTER_PLAYER_BROADCAST_VARIABLES;

	//opd_s _NETWORK_REGISTER_HOST_BROADCAST_VARIABLES = { Addresses::Addresses_Natives::Network_a::NETWORK_REGISTER_HOST_BROADCAST_VARIABLES, TOC };
	//void(*NETWORK_REGISTER_HOST_BROADCAST_VARIABLES)(Any* p0, Any p1) = (void(*)(Any*, Any))&_NETWORK_REGISTER_HOST_BROADCAST_VARIABLES;

	//opd_s _NETWORK_GET_SCRIPT_STATUS = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_SCRIPT_STATUS, TOC };
	//Any(*NETWORK_GET_SCRIPT_STATUS)() = (Any(*)())&_NETWORK_GET_SCRIPT_STATUS;

	//opd_s _NETWORK_GET_NUM_PARTICIPANTS = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_NUM_PARTICIPANTS, TOC };
	//int(*NETWORK_GET_NUM_PARTICIPANTS)() = (int(*)())&_NETWORK_GET_NUM_PARTICIPANTS;


	/*
	Seems to always return 0, but it's used in quite a few loops.

	for (num3 = 0; num3 < NETWORK::0xCCD8C02D(); num3++)
	{
	if (NETWORK::NETWORK_IS_PARTICIPANT_ACTIVE(PLAYER::0x98F3B274(num3)) != 0)
	{
	var num5 = NETWORK::NETWORK_GET_PLAYER_INDEX(PLAYER::0x98F3B274(num3));
	*/
	//opd_s _NETWORK_GET_NUM_PARTICIPANTS_HOST = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_NUM_PARTICIPANTS_HOST, TOC };
	//int(*NETWORK_GET_NUM_PARTICIPANTS_HOST)() = (int(*)())&_NETWORK_GET_NUM_PARTICIPANTS_HOST;


	//opd_s _NETWORK_GET_THIS_SCRIPT_IS_NETWORK_SCRIPT = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_THIS_SCRIPT_IS_NETWORK_SCRIPT, TOC };
	//BOOL(*NETWORK_GET_THIS_SCRIPT_IS_NETWORK_SCRIPT)() = (BOOL(*)())&_NETWORK_GET_THIS_SCRIPT_IS_NETWORK_SCRIPT;

	//opd_s _NETWORK_SET_THIS_SCRIPT_IS_NETWORK_SCRIPT = { Addresses::Addresses_Natives::Network_a::NETWORK_SET_THIS_SCRIPT_IS_NETWORK_SCRIPT, TOC };
	//void(*NETWORK_SET_THIS_SCRIPT_IS_NETWORK_SCRIPT)(Any p0, BOOL p1, Any p2) = (void(*)(Any, BOOL, Any))&_NETWORK_SET_THIS_SCRIPT_IS_NETWORK_SCRIPT;

	//opd_s _NETWORK_PLAYER_IS_BADSPORT = { Addresses::Addresses_Natives::Network_a::NETWORK_PLAYER_IS_BADSPORT, TOC };
	//Any(*NETWORK_PLAYER_IS_BADSPORT)() = (Any(*)())&_NETWORK_PLAYER_IS_BADSPORT;

	//opd_s _NETWORK_PLAYER_IS_CHEATER = { Addresses::Addresses_Natives::Network_a::NETWORK_PLAYER_IS_CHEATER, TOC };
	//Any(*NETWORK_PLAYER_IS_CHEATER)() = (Any(*)())&_NETWORK_PLAYER_IS_CHEATER;

	
	//opd_s _NETWORK_SESSION_ARE_PLAYERS_VOTING_TO_KICK = { Addresses::Addresses_Natives::Network_a::NETWORK_SESSION_ARE_PLAYERS_VOTING_TO_KICK, TOC };
	//BOOL(*NETWORK_SESSION_ARE_PLAYERS_VOTING_TO_KICK)(Player player) = (BOOL(*)(Player))&_NETWORK_SESSION_ARE_PLAYERS_VOTING_TO_KICK; 

	/*
	opd_s _NETWORK_IS_IN_SPECTATOR_MODE = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_IN_SPECTATOR_MODE, TOC };
	int*(*NETWORK_IS_IN_SPECTATOR_MODE)() = (int*(*)())&_NETWORK_IS_IN_SPECTATOR_MODE; 
	*/
	
	//opd_s _NETWORK_IS_LOCAL_PLAYER_INVINCIBLE = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_LOCAL_PLAYER_INVINCIBLE, TOC };
	//

	//opd_s _NETWORK_SET_LOCAL_PLAYER_INVINCIBLE_TIME = { Addresses::Addresses_Natives::Network_a::NETWORK_SET_LOCAL_PLAYER_INVINCIBLE_TIME, TOC };
	//

	//opd_s _NETWORK_CAN_ENTER_MULTIPLAYER = { Addresses::Addresses_Natives::Network_a::NETWORK_CAN_ENTER_MULTIPLAYER, TOC };
	//BOOL(*NETWORK_CAN_ENTER_MULTIPLAYER)() = (BOOL(*)())&_NETWORK_CAN_ENTER_MULTIPLAYER; 

	opd_s _NETWORK_IS_PLAYER_TALKING = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_PLAYER_TALKING, TOC };
	BOOL(*NETWORK_IS_PLAYER_TALKING)(int PlayerID) = (BOOL(*)(int))&_NETWORK_IS_PLAYER_TALKING; 

	opd_s _NETWORK_IS_GAMER_TALKING = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_GAMER_TALKING, TOC };
	BOOL(*NETWORK_IS_GAMER_TALKING)(int PlayerID) = (BOOL(*)(int))&_NETWORK_IS_GAMER_TALKING; 

	//opd_s _NETWORK_IS_LOCAL_TALKING = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_LOCAL_TALKING, TOC };
	//BOOL(*NETWORK_IS_LOCAL_TALKING)(int PlayerID) = (BOOL(*)(int))&_NETWORK_IS_LOCAL_TALKING; 

	opd_s _NETWORK_EARN_FROM_ROCKSTAR = { Addresses::Addresses_Natives::Network_a::NETWORK_EARN_FROM_ROCKSTAR, TOC };
	BOOL(*NETWORK_EARN_FROM_ROCKSTAR)(int value) = (BOOL(*)(int))&_NETWORK_EARN_FROM_ROCKSTAR; 

	opd_s _NETWORK_GET_NUM_CONNECTED_PLAYERS = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_NUM_CONNECTED_PLAYERS, TOC };
	int(*NETWORK_GET_NUM_CONNECTED_PLAYERS)() = (int(*)())&_NETWORK_GET_NUM_CONNECTED_PLAYERS; 

	opd_s _NETWORK_LEAVE_TRANSITION = { Addresses::Addresses_Natives::Network_a::NETWORK_LEAVE_TRANSITION, TOC };
	Any(*NETWORK_LEAVE_TRANSITION)() = (Any(*)())&_NETWORK_LEAVE_TRANSITION; 

	opd_s _NETWORK_LAUNCH_TRANSITION = { Addresses::Addresses_Natives::Network_a::NETWORK_LAUNCH_TRANSITION, TOC };
	Any(*NETWORK_LAUNCH_TRANSITION)() = (Any(*)())&_NETWORK_LAUNCH_TRANSITION; 

	//opd_s _NETWORK_BAIL_TRANSITION = { Addresses::Addresses_Natives::Network_a::NETWORK_BAIL_TRANSITION, TOC };
	//void(*NETWORK_BAIL_TRANSITION)() = (void(*)())&_NETWORK_BAIL_TRANSITION; 

	opd_s _NETWORK_SESSION_LEAVE_SINGLE_PLAYER = { Addresses::Addresses_Natives::Network_a::NETWORK_SESSION_LEAVE_SINGLE_PLAYER, TOC };
	void(*NETWORK_SESSION_LEAVE_SINGLE_PLAYER)() = (void(*)())&_NETWORK_SESSION_LEAVE_SINGLE_PLAYER; 

	opd_s _NETWORK_SESSION_HOST_SINGLE_PLAYER = { Addresses::Addresses_Natives::Network_a::NETWORK_SESSION_HOST_SINGLE_PLAYER, TOC };
	void(*NETWORK_SESSION_HOST_SINGLE_PLAYER)(Any p0) = (void(*)(Any))&_NETWORK_SESSION_HOST_SINGLE_PLAYER; 
	
	/*
	p2 is true 3/4 of the occurrences I found.
	players is the number of players for a session. On PS3/360 it's always 18. On PC it's 32.
	*/
	opd_s _NETWORK_DO_TRANSITION_TO_FREEMODE = { Addresses::Addresses_Natives::Network_a::NETWORK_DO_TRANSITION_TO_FREEMODE, TOC };
	BOOL(*NETWORK_DO_TRANSITION_TO_FREEMODE)(Any* p0, Any p1, BOOL p2, int players) = (BOOL(*)(Any*, Any, BOOL, int))&_NETWORK_DO_TRANSITION_TO_FREEMODE; 

	opd_s _NETWORK_DO_TRANSITION_TO_NEW_FREEMODE = { Addresses::Addresses_Natives::Network_a::NETWORK_DO_TRANSITION_TO_NEW_FREEMODE, TOC };
	BOOL(*NETWORK_DO_TRANSITION_TO_NEW_FREEMODE)(Any* p0, Any p1, Any p2, BOOL p3, BOOL p4) = (BOOL(*)(Any*, Any, Any, BOOL, BOOL))&_NETWORK_DO_TRANSITION_TO_NEW_FREEMODE; 

	//opd_s _NETWORK_DO_TRANSITION_TO_GAME = { Addresses::Addresses_Natives::Network_a::NETWORK_DO_TRANSITION_TO_GAME, TOC };
	//BOOL(*NETWORK_DO_TRANSITION_TO_GAME)(BOOL p0, Any p1) = (BOOL(*)(BOOL, Any))&_NETWORK_DO_TRANSITION_TO_GAME; 

	//opd_s _NETWORK_DO_TRANSITION_TO_NEW_GAME = { Addresses::Addresses_Natives::Network_a::NETWORK_DO_TRANSITION_TO_NEW_GAME, TOC };
	//BOOL(*NETWORK_DO_TRANSITION_TO_NEW_GAME)(BOOL p0, Any p1, BOOL p2) = (BOOL(*)(BOOL, Any, BOOL))&_NETWORK_DO_TRANSITION_TO_NEW_GAME; 
	

	//opd_s _NETWORK_IS_SIGNED_IN = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_SIGNED_IN, TOC };
	//Any(*NETWORK_IS_SIGNED_IN)() = (Any(*)())&_NETWORK_IS_SIGNED_IN; 

	opd_s _NETWORK_IS_SIGNED_IN = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_SIGNED_IN, TOC };
	Any(*NETWORK_IS_SIGNED_IN)() = (Any(*)())&_NETWORK_IS_SIGNED_IN; 

	opd_s _NETWORK_IS_SIGNED_ONLINE = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_SIGNED_ONLINE, TOC };
	Any(*NETWORK_IS_SIGNED_ONLINE)() = (Any(*)())&_NETWORK_IS_SIGNED_ONLINE; 

	//opd_s _NETWORK_BUY_BOUNTY = { Addresses::Addresses_Natives::Network_a::NETWORK_BUY_BOUNTY, TOC };
	//void(*NETWORK_BUY_BOUNTY)(Any p0, Any p1, BOOL p2, BOOL p3) = (void(*)(Any, Any, BOOL, BOOL))&_NETWORK_BUY_BOUNTY; 

	//p1 = 0 (always) p2 = 1 (always)
	//opd_s _NETWORK_BUY_AIRSTRIKE = { Addresses::Addresses_Natives::Network_a::NETWORK_BUY_AIRSTRIKE, TOC };
	//void(*NETWORK_BUY_AIRSTRIKE)(int cost, BOOL p1, BOOL p2) = (void(*)(int, BOOL, BOOL))&_NETWORK_BUY_AIRSTRIKE; 

	//p1 = 0 (always) p2 = 1 (always)
	//opd_s _NETWORK_BUY_HELI_STRIKE = { Addresses::Addresses_Natives::Network_a::NETWORK_BUY_HELI_STRIKE, TOC };
	//void(*NETWORK_BUY_HELI_STRIKE)(int cost, BOOL p1, BOOL p2) = (void(*)(int, BOOL, BOOL))&_NETWORK_BUY_HELI_STRIKE; 

	//opd_s _NETWORK_BUY_HEALTHCARE = { Addresses::Addresses_Natives::Network_a::NETWORK_BUY_HEALTHCARE, TOC };
	//void(*NETWORK_BUY_HEALTHCARE)(int cost, BOOL p1, BOOL p2) = (void(*)(int, BOOL, BOOL))&_NETWORK_BUY_HEALTHCARE; 

	//opd_s _NETWORK_BUY_PROPERTY = { Addresses::Addresses_Natives::Network_a::NETWORK_BUY_PROPERTY, TOC };
	//void(*NETWORK_BUY_PROPERTY)(float propertyCost, Hash propertyName, BOOL p2, BOOL p3) = (void(*)(float, Hash, BOOL, BOOL))&_NETWORK_BUY_PROPERTY; 

	//opd_s _NETWORK_BUY_ITEM = { Addresses::Addresses_Natives::Network_a::NETWORK_BUY_ITEM, TOC };
	//void(*NETWORK_BUY_ITEM)(Ped player, Hash item, Any p2, Any p3, BOOL p4, Any* p5, Any p6, Any p7, Any p8, BOOL p9) = (void(*)(Ped, Hash, Any, Any, BOOL, Any*, Any, Any, Any, BOOL))&_NETWORK_BUY_ITEM; 

	opd_s _NETWORK_GET_GAMERTAG_FROM_HANDLE = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_GAMERTAG_FROM_HANDLE, TOC };
	Any(*NETWORK_GET_GAMERTAG_FROM_HANDLE)(Any* p0) = (Any(*)(Any*))&_NETWORK_GET_GAMERTAG_FROM_HANDLE; 


	// param 2 is 13 much like NETWORK_HANDLE_FROM_PLAYER
	opd_s _NETWORK_IS_HANDLE_VALID = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_HANDLE_VALID, TOC };
	BOOL(*NETWORK_IS_HANDLE_VALID)(int *p0, int p1) = (BOOL(*)(int*, int))&_NETWORK_IS_HANDLE_VALID; 


	/*
	"p2" mainly set as 13 in scripts

	From scripts use:
	struct<13> func_27(var uParam0)
	{
	struct<13> Var0;
	network_handle_from_player(uParam0, &Var0, 13);
	return Var0;
	}
	*/
	//opd_s _NETWORK_HANDLE_FROM_PLAYER = { Addresses::Addresses_Natives::Network_a::NETWORK_HANDLE_FROM_PLAYER, TOC };
	//void(*NETWORK_HANDLE_FROM_PLAYER)(Player player, int *p1, int p2) = (void(*)(Player, int*, int))&_NETWORK_HANDLE_FROM_PLAYER; 

	//opd_s _NETWORK_HANDLE_FROM_MEMBER_ID = { Addresses::Addresses_Natives::Network_a::NETWORK_HANDLE_FROM_MEMBER_ID, TOC };
	//void(*NETWORK_HANDLE_FROM_MEMBER_ID)(Any *p0, Any *p1, Any p2) = (void(*)(Any*, Any*, Any))&_NETWORK_HANDLE_FROM_MEMBER_ID; 

	//opd_s _NETWORK_HANDLE_FROM_USER_ID = { Addresses::Addresses_Natives::Network_a::NETWORK_HANDLE_FROM_USER_ID, TOC };
	//void(*NETWORK_HANDLE_FROM_USER_ID)(Any *p0, Any *p1, Any p2) = (void(*)(Any*, Any*, Any))&_NETWORK_HANDLE_FROM_USER_ID; 

	//opd_s _NETWORK_GET_LOCAL_HANDLE = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_LOCAL_HANDLE, TOC };
	//void(*NETWORK_GET_LOCAL_HANDLE)(Any *p0, Any p1) = (void(*)(Any*, Any))&_NETWORK_GET_LOCAL_HANDLE; 



	opd_s _NETWORK_GET_NETWORK_ID_FROM_ENTITY = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_NETWORK_ID_FROM_ENTITY, TOC };
	Any(*NETWORK_GET_NETWORK_ID_FROM_ENTITY)(Any p0) = (Any(*)(Any))&_NETWORK_GET_NETWORK_ID_FROM_ENTITY; 

	opd_s _NETWORK_GET_NETWORK_ID_FROM_ENTITY_ALT = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_NETWORK_ID_FROM_ENTITY, TOC };
	int(*NETWORK_GET_NETWORK_ID_FROM_ENTITY_ALT)(int player) = (int(*)(int))&_NETWORK_GET_NETWORK_ID_FROM_ENTITY_ALT; 

	opd_s _NETWORK_GET_ENTITY_FROM_NETWORK_ID = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_ENTITY_FROM_NETWORK_ID, TOC };
	Any(*NETWORK_GET_ENTITY_FROM_NETWORK_ID)(Any p0) = (Any(*)(Any))&_NETWORK_GET_ENTITY_FROM_NETWORK_ID; 

	//opd_s _NETWORK_GET_ENTITY_IS_LOCAL = { Addresses::Addresses_Natives::Network_a::NETWORK_GET_ENTITY_IS_LOCAL, TOC };
	//BOOL(*NETWORK_GET_ENTITY_IS_LOCAL)(Any p0) = (BOOL(*)(Any))&_NETWORK_GET_ENTITY_IS_LOCAL; 

	opd_s _NETWORK_DOES_NETWORK_ID_EXIST = { Addresses::Addresses_Natives::Network_a::NETWORK_DOES_NETWORK_ID_EXIST, TOC };
	BOOL(*NETWORK_DOES_NETWORK_ID_EXIST)(Any p0) = (BOOL(*)(Any))&_NETWORK_DOES_NETWORK_ID_EXIST; 

	opd_s _NETWORK_DOES_ENTITY_EXIST_WITH_NETWORK_ID = { Addresses::Addresses_Natives::Network_a::NETWORK_DOES_ENTITY_EXIST_WITH_NETWORK_ID, TOC };
	BOOL(*NETWORK_DOES_ENTITY_EXIST_WITH_NETWORK_ID)(Any p0) = (BOOL(*)(Any))&_NETWORK_DOES_ENTITY_EXIST_WITH_NETWORK_ID; 



	//opd_s _NETWORK_REQUEST_CONTROL_OF_NETWORK_ID = { Addresses::Addresses_Natives::Network_a::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID, TOC };
	//BOOL(*NETWORK_REQUEST_CONTROL_OF_NETWORK_ID)(int netID) = (BOOL(*)(int))&_NETWORK_REQUEST_CONTROL_OF_NETWORK_ID; 

	opd_s _NETWORK_REQUEST_CONTROL_OF_NETWORK_ID = { Addresses::Addresses_Natives::Network_a::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID, TOC };
	int(*NETWORK_REQUEST_CONTROL_OF_NETWORK_ID)(int netID) = (int(*)(int))&_NETWORK_REQUEST_CONTROL_OF_NETWORK_ID; 

	//opd_s _NETWORK_HAS_CONTROL_OF_NETWORK_ID = { Addresses::Addresses_Natives::Network_a::NETWORK_HAS_CONTROL_OF_NETWORK_ID, TOC };
	//BOOL(*NETWORK_HAS_CONTROL_OF_NETWORK_ID)(int netID) = (BOOL(*)(int))&_NETWORK_HAS_CONTROL_OF_NETWORK_ID; 

	opd_s _NETWORK_HAS_CONTROL_OF_NETWORK_ID = { Addresses::Addresses_Natives::Network_a::NETWORK_HAS_CONTROL_OF_NETWORK_ID, TOC };
	int(*NETWORK_HAS_CONTROL_OF_NETWORK_ID)(int netID) = (int(*)(int))&_NETWORK_HAS_CONTROL_OF_NETWORK_ID; 

	opd_s _NETWORK_REQUEST_CONTROL_OF_ENTITY = { Addresses::Addresses_Natives::Network_a::NETWORK_REQUEST_CONTROL_OF_ENTITY, TOC };
	BOOL(*NETWORK_REQUEST_CONTROL_OF_ENTITY)(Entity entity) = (BOOL(*)(Entity))&_NETWORK_REQUEST_CONTROL_OF_ENTITY; 

	opd_s _NETWORK_REQUEST_CONTROL_OF_ENTITY_ALT = { Addresses::Addresses_Natives::Network_a::NETWORK_REQUEST_CONTROL_OF_ENTITY, TOC };
	int(*NETWORK_REQUEST_CONTROL_OF_ENTITY_ALT)(int entity) = (int(*)(int))&_NETWORK_REQUEST_CONTROL_OF_ENTITY_ALT; 

	//opd_s _NETWORK_REQUEST_CONTROL_OF_DOOR = { Addresses::Addresses_Natives::Network_a::NETWORK_REQUEST_CONTROL_OF_DOOR, TOC };
	//BOOL(*NETWORK_REQUEST_CONTROL_OF_DOOR)(Any p0) = (BOOL(*)(Any))&_NETWORK_REQUEST_CONTROL_OF_DOOR; 

	opd_s _NETWORK_HAS_CONTROL_OF_DOOR = { Addresses::Addresses_Natives::Network_a::NETWORK_HAS_CONTROL_OF_DOOR, TOC };
	BOOL(*NETWORK_HAS_CONTROL_OF_DOOR)(Any p0) = (BOOL(*)(Any))&_NETWORK_HAS_CONTROL_OF_DOOR; 

	opd_s _NETWORK_HAS_CONTROL_OF_ENTITY = { Addresses::Addresses_Natives::Network_a::NETWORK_HAS_CONTROL_OF_ENTITY, TOC };
	BOOL(*NETWORK_HAS_CONTROL_OF_ENTITY)(Entity entity) = (BOOL(*)(Entity))&_NETWORK_HAS_CONTROL_OF_ENTITY; 

	opd_s _NETWORK_HAS_CONTROL_OF_ENTITY_ALT = { Addresses::Addresses_Natives::Network_a::NETWORK_HAS_CONTROL_OF_ENTITY, TOC };
	bool(*NETWORK_HAS_CONTROL_OF_ENTITY_ALT)(int entity) = (bool(*)(int))&_NETWORK_HAS_CONTROL_OF_ENTITY_ALT; 

	//opd_s _NETWORK_HAS_CONTROL_OF_PICKUP = { Addresses::Addresses_Natives::Network_a::NETWORK_HAS_CONTROL_OF_PICKUP, TOC };
	//BOOL(*NETWORK_HAS_CONTROL_OF_PICKUP)(Any p0) = (BOOL(*)(Any))&_NETWORK_HAS_CONTROL_OF_PICKUP; 

	//opd_s _NETWORK_IS_GAMER_IN_MY_SESSION = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_GAMER_IN_MY_SESSION, TOC };
	//BOOL(*NETWORK_IS_GAMER_IN_MY_SESSION)(Any p0) = (BOOL(*)(Any))&_NETWORK_IS_GAMER_IN_MY_SESSION; 



	//opd_s _NETWORK_SHOW_PROFILE_UI = { Addresses::Addresses_Natives::Network_a::NETWORK_SHOW_PROFILE_UI, TOC };
	//void(*NETWORK_SHOW_PROFILE_UI)(Any* p0) = (void(*)(Any*))&_NETWORK_SHOW_PROFILE_UI; 


	opd_s _NETWORK_PLAYER_GET_NAME = { Addresses::Addresses_Natives::Network_a::NETWORK_PLAYER_GET_NAME, TOC };
	char*(*NETWORK_PLAYER_GET_NAME)(Player player) = (char*(*)(Player))&_NETWORK_PLAYER_GET_NAME; 


	opd_s _NETWORK_PLAYER_IS_ROCKSTAR_DEV = { Addresses::Addresses_Natives::Network_a::NETWORK_PLAYER_IS_ROCKSTAR_DEV, TOC };
	BOOL(*NETWORK_PLAYER_IS_ROCKSTAR_DEV)(Player player) = (BOOL(*)(Player))&_NETWORK_PLAYER_IS_ROCKSTAR_DEV; 

	//opd_s _NETWORK_IS_FRIEND_ONLINE = { Addresses::Addresses_Natives::Network_a::NETWORK_IS_FRIEND_ONLINE, TOC };
	//BOOL(*NETWORK_IS_FRIEND_ONLINE)(Any* p0) = (BOOL(*)(Any*))&_NETWORK_IS_FRIEND_ONLINE; 


	opd_s _NETWORK_SET_OVERRIDE_SPECTATOR_MODE = { Addresses::Addresses_Natives::Network_a::NETWORK_SET_OVERRIDE_SPECTATOR_MODE, TOC };
	void(*NETWORK_SET_OVERRIDE_SPECTATOR_MODE)(BOOL p0) = (void(*)(BOOL))&_NETWORK_SET_OVERRIDE_SPECTATOR_MODE; 

	//opd_s _NETWORK_SET_FRIENDLY_FIRE_OPTION = { Addresses::Addresses_Natives::Network_a::NETWORK_SET_FRIENDLY_FIRE_OPTION, TOC };
	//void(*NETWORK_SET_FRIENDLY_FIRE_OPTION)(BOOL p0) = (void(*)(BOOL))&_NETWORK_SET_FRIENDLY_FIRE_OPTION; 


	//opd_s _NETWORK_RESURRECT_LOCAL_PLAYER = { Addresses::Addresses_Natives::Network_a::NETWORK_RESURRECT_LOCAL_PLAYER, TOC };
	//void(*NETWORK_RESURRECT_LOCAL_PLAYER)(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5) = (void(*)(Any, Any, Any, Any, Any, Any))&_NETWORK_RESURRECT_LOCAL_PLAYER; 

	//opd_s _NETWORK_RESURRECT_LOCAL_PLAYER_ALT = { Addresses::Addresses_Natives::Network_a::NETWORK_RESURRECT_LOCAL_PLAYER, TOC };
	//void(*NETWORK_RESURRECT_LOCAL_PLAYER_ALT)(float p0, float p1, float p2, int p3, int p4, int p5, int p6) = (void(*)(float, float, float, int, int, int, int))&_NETWORK_RESURRECT_LOCAL_PLAYER_ALT; 

	
	

	//opd_s _NETWORK_EXPLODE_VEHICLE = { Addresses::Addresses_Natives::Network_a::NETWORK_EXPLODE_VEHICLE, TOC };
	//void(*NETWORK_EXPLODE_VEHICLE)(BOOL p0) = (void(*)(BOOL))&_NETWORK_EXPLODE_VEHICLE; 

	opd_s _NETWORK_SET_MISSION_FINISHED = { Addresses::Addresses_Natives::Network_a::NETWORK_SET_MISSION_FINISHED, TOC };
	void(*NETWORK_SET_MISSION_FINISHED)() = (void(*)())&_NETWORK_SET_MISSION_FINISHED; 


	opd_s _NETWORK_OVERRIDE_CLOCK_TIME = { Addresses::Addresses_Natives::Network_a::NETWORK_OVERRIDE_CLOCK_TIME, TOC };
	void(*NETWORK_OVERRIDE_CLOCK_TIME)(int Hours, int Minutes, int Seconds) = (void(*)(int, int, int))&_NETWORK_OVERRIDE_CLOCK_TIME; 

	


	//opd_s _PARTICIPANT_ID = { Addresses::Addresses_Natives::Network_a::PARTICIPANT_ID, TOC };
	//Any(*PARTICIPANT_ID)() = (Any(*)())&_PARTICIPANT_ID; 

	//opd_s _PARTICIPANT_ID_TO_INT = { Addresses::Addresses_Natives::Network_a::PARTICIPANT_ID_TO_INT, TOC };
	//Any(*PARTICIPANT_ID_TO_INT)() = (Any(*)())&_PARTICIPANT_ID_TO_INT; 


	opd_s _NET_TO_ENT = { Addresses::Addresses_Natives::Network_a::NET_TO_ENT, TOC };
	Entity(*NET_TO_ENT)(int netHandle) = (Entity(*)(int))&_NET_TO_ENT; 

	opd_s _NET_TO_OBJ = { Addresses::Addresses_Natives::Network_a::NET_TO_OBJ, TOC };
	Object(*NET_TO_OBJ)(int netHandle) = (Object(*)(int))&_NET_TO_OBJ; 

	opd_s _NET_TO_PED = { Addresses::Addresses_Natives::Network_a::NET_TO_PED, TOC };
	Ped(*NET_TO_PED)(int netHandle) = (Ped(*)(int))&_NET_TO_PED; 

	opd_s _NET_TO_VEH = { Addresses::Addresses_Natives::Network_a::NET_TO_VEH, TOC };
	Vehicle(*NET_TO_VEH)(int netHandle) = (Vehicle(*)(int))&_NET_TO_VEH; 

	opd_s _OBJ_TO_NET = { Addresses::Addresses_Natives::Network_a::OBJ_TO_NET, TOC };
	int(*OBJ_TO_NET)(Object object) = (int(*)(Object))&_OBJ_TO_NET; 

	opd_s _PED_TO_NET = { Addresses::Addresses_Natives::Network_a::PED_TO_NET, TOC };
	int(*PED_TO_NET)(Ped ped) = (int(*)(Ped))&_PED_TO_NET; 

	opd_s _VEH_TO_NET = { Addresses::Addresses_Natives::Network_a::VEH_TO_NET, TOC };
	int(*VEH_TO_NET)(Vehicle vehicle) = (int(*)(Vehicle))&_VEH_TO_NET; 

	


	// Known Unknowns
	//opd_s _unk_0x4818ACD0 = { Addresses::Addresses_Natives::Network_a::unk_0x4818ACD0, TOC };
	//void(*unk_0x4818ACD0)(Any p0, Any p1) = (void(*)(Any, Any))&_unk_0x4818ACD0;

	//opd_s _unk_0x4C2C6B6A = { Addresses::Addresses_Natives::Network_a::unk_0x4C2C6B6A, TOC };
	//BOOL(*unk_0x4C2C6B6A)(Any* p0, Any p1, Any p2) = (BOOL(*)(Any*, Any, Any))&_unk_0x4C2C6B6A;

	//opd_s _unk_0xF9A51B92 = { Addresses::Addresses_Natives::Network_a::unk_0xF9A51B92, TOC };
	//BOOL(*unk_0xF9A51B92)(Any p0, Any p1, Any p2) = (BOOL(*)(Any, Any, Any))&_unk_0xF9A51B92;

	//opd_s _unk_0x1720ABA6 = { Addresses::Addresses_Natives::Network_a::unk_0x1720ABA6, TOC };
	//Any(*unk_0x1720ABA6)() = (Any(*)())&_unk_0x1720ABA6;

	


	//---------------------------------------------------------------------------------------------//
	

	
	//---------------------------------------------------------------------------------------------//
	// Money

	//opd_s _CREATE_MONEY_PICKUPS = { Addresses::Addresses_Natives::Money_a::CREATE_MONEY_PICKUPS, TOC };
	//void(*CREATE_MONEY_PICKUPS)(Ped ped, int amount) = (void(*)(Ped, int))&_CREATE_MONEY_PICKUPS;
	
	//opd_s _DISPLAY_CASH = { Addresses::Addresses_Natives::Money_a::DISPLAY_CASH, TOC };
	//void(*DISPLAY_CASH)(BOOL toggle) = (void(*)(BOOL))&_DISPLAY_CASH;

	//opd_s _GET_PED_MONEY = { Addresses::Addresses_Natives::Money_a::GET_PED_MONEY, TOC };
	//void(*GET_PED_MONEY)(Ped ped) = (void(*)(Ped))&_GET_PED_MONEY;

	//opd_s _IS_PED_RUNNING_CASH_DROP = { Addresses::Addresses_Natives::Money_a::IS_PED_RUNNING_CASH_DROP, TOC };
	//bool(*IS_PED_RUNNING_CASH_DROP)() = (bool(*)())&_IS_PED_RUNNING_CASH_DROP;

	//opd_s _NETWORK_CAN_RECEIVE_PLAYER_CASH = { Addresses::Addresses_Natives::Money_a::NETWORK_CAN_RECEIVE_PLAYER_CASH, TOC };
	//void(*NETWORK_CAN_RECEIVE_PLAYER_CASH)(Any p0, Any p1, Any p2, Any p3) = (void(*)(Any, Any, Any, Any))&_NETWORK_CAN_RECEIVE_PLAYER_CASH;

	//opd_s _NETWORK_GIVE_PLAYER_JOBSHARE_CASH = { Addresses::Addresses_Natives::Money_a::NETWORK_GIVE_PLAYER_JOBSHARE_CASH, TOC };
	//void(*NETWORK_GIVE_PLAYER_JOBSHARE_CASH)(Any p0, Any *p1) = (void(*)(Any, Any*))&_NETWORK_GIVE_PLAYER_JOBSHARE_CASH;

	//opd_s _NETWORK_RECEIVE_PLAYER_JOBSHARE_CASH = { Addresses::Addresses_Natives::Money_a::NETWORK_RECEIVE_PLAYER_JOBSHARE_CASH, TOC };
	//void(*NETWORK_RECEIVE_PLAYER_JOBSHARE_CASH)(Any p0, Any *p1) = (void(*)(Any, Any*))&_NETWORK_RECEIVE_PLAYER_JOBSHARE_CASH;

	//opd_s _NETWORK_SPENT_CASH_DROP = { Addresses::Addresses_Natives::Money_a::NETWORK_SPENT_CASH_DROP, TOC };
	//void(*NETWORK_SPENT_CASH_DROP)(Any p0, BOOL p1, BOOL p2) = (void(*)(Any, BOOL, BOOL))&_NETWORK_SPENT_CASH_DROP;

	//opd_s _REMOVE_MULTIPLAYER_BANK_CASH = { Addresses::Addresses_Natives::Money_a::REMOVE_MULTIPLAYER_BANK_CASH, TOC };
	//void(*REMOVE_MULTIPLAYER_BANK_CASH)() = (void(*)())&_REMOVE_MULTIPLAYER_BANK_CASH;

	//opd_s _REMOVE_MULTIPLAYER_HUD_CASH = { Addresses::Addresses_Natives::Money_a::REMOVE_MULTIPLAYER_HUD_CASH, TOC };
	//void(*REMOVE_MULTIPLAYER_HUD_CASH)() = (void(*)())&_REMOVE_MULTIPLAYER_HUD_CASH;

	//opd_s _SET_MULTIPLAYER_BANK_CASH = { Addresses::Addresses_Natives::Money_a::SET_MULTIPLAYER_BANK_CASH, TOC };
	//void(*SET_MULTIPLAYER_BANK_CASH)() = (void(*)())&_SET_MULTIPLAYER_BANK_CASH;

	//opd_s _SET_MULTIPLAYER_HUD_CASH = { Addresses::Addresses_Natives::Money_a::SET_MULTIPLAYER_HUD_CASH, TOC };
	//void(*SET_MULTIPLAYER_HUD_CASH)(int p0, int p1) = (void(*)(int, int))&_SET_MULTIPLAYER_HUD_CASH;

	//opd_s _SET_PED_MONEY = { Addresses::Addresses_Natives::Money_a::SET_PED_MONEY, TOC };
	//void(*SET_PED_MONEY)(Ped ped, int amount) = (void(*)(Ped, int))&_SET_PED_MONEY;



	

	//---------------------------------------------------------------------------------------------//


	
	//---------------------------------------------------------------------------------------------//
	// Bleeding
	//opd_s _APPLY_PED_BLOOD = { Addresses::Addresses_Natives::Player_a::APPLY_PED_BLOOD, TOC };
	//void(*APPLY_PED_BLOOD)(Ped ped, int boneIndex, float xRot, float yRot, float zRot, char *woundType) = (void(*)(Ped ped, int boneIndex, float xRot, float yRot, float zRot, char *woundType))&_APPLY_PED_BLOOD;
	
	//opd_s _APPLY_DAMAGE_TO_PED = { Addresses::Addresses_Natives::Player_a::APPLY_DAMAGE_TO_PED, TOC };
	//void(*APPLY_DAMAGE_TO_PED)(Ped ped, Any damageAmount, BOOL p2) = (void(*)(Ped ped, Any damageAmount, BOOL p2))&_APPLY_DAMAGE_TO_PED;
	
	//opd_s _CLEAR_PED_BLOOD_DAMAGE = { Addresses::Addresses_Natives::Player_a::CLEAR_PED_BLOOD_DAMAGE, TOC };
	//void(*CLEAR_PED_BLOOD_DAMAGE)(Ped ped) = (void(*)(Ped ped))&_CLEAR_PED_BLOOD_DAMAGE;
	
	//opd_s _SET_PARTICLE_FX_BLOOD_SCALE = { Addresses::Addresses_Natives::Player_a::SET_PARTICLE_FX_BLOOD_SCALE, TOC };
	//void(*SET_PARTICLE_FX_BLOOD_SCALE)(BOOL p0) = (void(*)(BOOL p0))&_SET_PARTICLE_FX_BLOOD_SCALE;
	//---------------------------------------------------------------------------------------------//
	

	
	//---------------------------------------------------------------------------------------------//
	// Wanted Level
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

	opd_s _FLASH_WANTED_DISPLAY = { Addresses::Addresses_Natives::Player_a::FLASH_WANTED_DISPLAY, TOC };
	void(*FLASH_WANTED_DISPLAY)(BOOL p0) = (void(*)(BOOL))&_FLASH_WANTED_DISPLAY;

	//opd_s _SET_WANTED_LEVEL_MULTIPLIER = { Addresses::Addresses_Natives::Player_a::SET_WANTED_LEVEL_MULTIPLIER, TOC };
	//void(*SET_WANTED_LEVEL_MULTIPLIER)(float multiplier) = (void(*)(float))&_SET_WANTED_LEVEL_MULTIPLIER;

	//opd_s _SET_WANTED_LEVEL_DIFFICULTY = { Addresses::Addresses_Natives::Player_a::SET_WANTED_LEVEL_DIFFICULTY, TOC };
	//void(*SET_WANTED_LEVEL_DIFFICULTY)(Player player, float difficulty) = (void(*)(Player, float))&_SET_WANTED_LEVEL_DIFFICULTY;
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
	// Peds
	
	//opd_s _SET_PED_PLAYS_HEAD_ON_HORN_ANIM_WHEN_DIES_IN_VEHICLE = { Addresses::Addresses_Natives::Peds_a::SET_PED_PLAYS_HEAD_ON_HORN_ANIM_WHEN_DIES_IN_VEHICLE, TOC };
	//BOOL(*SET_PED_PLAYS_HEAD_ON_HORN_ANIM_WHEN_DIES_IN_VEHICLE)(Ped ped, BOOL toggle) = (BOOL(*)(Ped, BOOL))&_SET_PED_PLAYS_HEAD_ON_HORN_ANIM_WHEN_DIES_IN_VEHICLE;

	
	// combined with SET_PED_WETNESS_HEIGHT(), this makes the ped drenched in water up to the height specified in the other function
	opd_s _SET_PED_WETNESS_ENABLED_THIS_FRAME = { Addresses::Addresses_Natives::Peds_a::SET_PED_WETNESS_ENABLED_THIS_FRAME, TOC };
	void(*SET_PED_WETNESS_ENABLED_THIS_FRAME)(Ped ped) = (void(*)(Ped))&_SET_PED_WETNESS_ENABLED_THIS_FRAME;

	opd_s _SET_PED_WETNESS_HEIGHT = { Addresses::Addresses_Natives::Peds_a::SET_PED_WETNESS_HEIGHT, TOC };
	void(*SET_PED_WETNESS_HEIGHT)(Ped ped, float height) = (void(*)(Ped, float))&_SET_PED_WETNESS_HEIGHT;

	opd_s _CLEAR_PED_WETNESS = { Addresses::Addresses_Natives::Peds_a::CLEAR_PED_WETNESS, TOC };
	void(*CLEAR_PED_WETNESS)(Ped ped) = (void(*)(Ped))&_CLEAR_PED_WETNESS;

	// Sweat is set to 100.0 or 0.0 in the decompiled scripts
	opd_s _SET_PED_SWEAT = { Addresses::Addresses_Natives::Peds_a::SET_PED_SWEAT, TOC };
	void(*SET_PED_SWEAT)(Ped ped, float sweat) = (void(*)(Ped, float))&_SET_PED_SWEAT;

	
	
	//opd_s _SET_ALL_RANDOM_PEDS_FLEE_THIS_FRAME = { Addresses::Addresses_Natives::Peds_a::SET_ALL_RANDOM_PEDS_FLEE_THIS_FRAME, TOC };
	//void(*SET_ALL_RANDOM_PEDS_FLEE_THIS_FRAME)(Player player) = (void(*)(Player))&_SET_ALL_RANDOM_PEDS_FLEE_THIS_FRAME;

	//opd_s _SET_ALL_RANDOM_PEDS_FLEE = { Addresses::Addresses_Natives::Peds_a::SET_ALL_RANDOM_PEDS_FLEE, TOC };
	//void(*SET_ALL_RANDOM_PEDS_FLEE)(Player player, BOOL toggle) = (void(*)(Player, BOOL))&_SET_ALL_RANDOM_PEDS_FLEE;

	
	opd_s _SET_PED_TO_RAGDOLL_WITH_FALL = { Addresses::Addresses_Natives::Peds_a::SET_PED_TO_RAGDOLL_WITH_FALL, TOC };
	Ped(*SET_PED_TO_RAGDOLL_WITH_FALL)(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10, Any p11, Any p12, Any p13) = (Ped(*)(Any, Any, Any, Any, Any, Any, Any, Any, Any, Any, Any, Any, Any, Any))&_SET_PED_TO_RAGDOLL_WITH_FALL;
	
	opd_s _IS_PED_RAGDOLL = { Addresses::Addresses_Natives::Peds_a::IS_PED_RAGDOLL, TOC };
	BOOL(*IS_PED_RAGDOLL)(Ped ped) = (BOOL(*)(Ped))&_IS_PED_RAGDOLL;

	

	opd_s _CLEAR_ALL_PED_PROPS = { Addresses::Addresses_Natives::Area_a::CLEAR_ALL_PED_PROPS, TOC };
	void(*CLEAR_ALL_PED_PROPS)(Ped ped) = (void(*)(Ped))&_CLEAR_ALL_PED_PROPS;

	//opd_s _CLONE_PED = { Addresses::Addresses_Natives::Peds_a::CLONE_PED, TOC };
	//void(*CLONE_PED)(uint PedID, float heading, bool networkHandle, bool pedHandle) = (void(*)(uint, float, bool, bool))&_CLONE_PED;

	opd_s _CLONE_PED = { Addresses::Addresses_Natives::Peds_a::CLONE_PED, TOC };
	Ped(*CLONE_PED)(Ped ped, float heading, BOOL networkHandle, BOOL pedHandle) = (Ped(*)(Ped, float, BOOL, BOOL))&_CLONE_PED;
	
	// Ped Types
	/*
	Player = 1
	Male = 4
	Female = 5
	Cop = 6
	Human = 26
	SWAT = 27
	Animal = 28
	Army = 29

	*Heading*: 0.0
	*Heading* is the Z axis spawn rotation of the ped 0->5th parameter.

	Ped Types:
	[Player,1|Male,4|Female,5|Cop,6|Human,26|SWAT,27|Animal,28|Army,29]
	*/
	
	opd_s _CREATE_PED = { Addresses::Addresses_Natives::Peds_a::CREATE_PED, TOC };
	Ped(*CREATE_PED)(int pedType, Hash modelHash, float x, float y, float z, float heading, BOOL networkHandle, BOOL pedHandle) = (Ped(*)(int, Hash, float, float, float, float, BOOL, BOOL))&_CREATE_PED;
	
	opd_s _DELETE_PED = { Addresses::Addresses_Natives::Peds_a::DELETE_PED, TOC };
	void(*DELETE_PED)(Ped* ped) = (void(*)(Ped*))&_DELETE_PED;

	opd_s _SET_PED_DIES_IN_WATER = { Addresses::Addresses_Natives::Peds_a::SET_PED_DIES_IN_WATER, TOC };
	void(*SET_PED_DIES_IN_WATER)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_PED_DIES_IN_WATER;

	opd_s _SET_PED_DIES_IN_SINKING_VEHICLE = { Addresses::Addresses_Natives::Peds_a::SET_PED_DIES_IN_SINKING_VEHICLE, TOC };
	void(*SET_PED_DIES_IN_SINKING_VEHICLE)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_PED_DIES_IN_SINKING_VEHICLE;
	
	opd_s _SET_PED_GRAVITY = { Addresses::Addresses_Natives::Peds_a::SET_PED_GRAVITY, TOC };
	void(*SET_PED_GRAVITY)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_PED_GRAVITY;
	
	

	/*
	im ped_handle As Integer
	With Game.Player.Character
	Dim pos As Vector3 = .Position + .ForwardVector * 3
	ped_handle = Native.Function.Call(Of Integer)(Hash.CREATE_RANDOM_PED, pos.X, pos.Y, pos.Z)
	End With

	Creates a Ped at the specified location, returns the Ped Handle.
	Ped will not act until SET_PED_AS_NO_LONGER_NEEDED is called.
	*/
	//opd_s _CREATE_RANDOM_PED = { Addresses::Addresses_Natives::Peds_a::CREATE_RANDOM_PED, TOC };
	//Ped(*CREATE_RANDOM_PED)(float posX, float posY, float posZ) = (Ped(*)(float, float, float))&_CREATE_RANDOM_PED;
	
	//opd_s _CREATE_RANDOM_PED_AS_DRIVER = { Addresses::Addresses_Natives::Peds_a::CREATE_RANDOM_PED_AS_DRIVER, TOC };
	//Ped(*CREATE_RANDOM_PED_AS_DRIVER)(Vehicle vehicle, BOOL returnHandle) = (Ped(*)(Vehicle, BOOL))&_CREATE_RANDOM_PED_AS_DRIVER;
	
	opd_s _SET_PED_AS_NO_LONGER_NEEDED = { Addresses::Addresses_Natives::Peds_a::SET_PED_AS_NO_LONGER_NEEDED, TOC };
	void(*SET_PED_AS_NO_LONGER_NEEDED)(Ped* ped) = (void(*)(Ped*))&_SET_PED_AS_NO_LONGER_NEEDED;
	
	
	

	opd_s _CREATE_PED_INSIDE_VEHICLE = { Addresses::Addresses_Natives::Peds_a::CREATE_PED_INSIDE_VEHICLE, TOC };
	Ped(*CREATE_PED_INSIDE_VEHICLE)(Vehicle vehicle, int pedType, Hash modelHash, int seat, BOOL createNetHandle, BOOL createPedHandle) = (Ped(*)(Vehicle, int, Hash, int, BOOL, BOOL))&_CREATE_PED_INSIDE_VEHICLE;

	opd_s _CLEAR_PED_SECONDARY_TASK = { Addresses::Addresses_Natives::Peds_a::CLEAR_PED_SECONDARY_TASK, TOC };
	void(*CLEAR_PED_SECONDARY_TASK)(Ped ped) = (void(*)(Ped))&_CLEAR_PED_SECONDARY_TASK;
	
	opd_s _CLEAR_PED_TASKS = { Addresses::Addresses_Natives::Peds_a::CLEAR_PED_TASKS, TOC };
	void(*CLEAR_PED_TASKS)(Ped ped) = (void(*)(Ped))&_CLEAR_PED_TASKS;
	
	opd_s _CLEAR_PED_TASKS_IMMEDIATELY = { Addresses::Addresses_Natives::Peds_a::CLEAR_PED_TASKS_IMMEDIATELY, TOC };
	void(*CLEAR_PED_TASKS_IMMEDIATELY)(int player) = (void(*)(int))&_CLEAR_PED_TASKS_IMMEDIATELY;
	
	//opd_s _EXPLODE_PED_HEAD = { Addresses::Addresses_Natives::Peds_a::EXPLODE_PED_HEAD, TOC };
	//void(*EXPLODE_PED_HEAD)(Ped ped, Hash weaponHash) = (void(*)(Ped, Hash))&_EXPLODE_PED_HEAD;
	
	opd_s _IS_PED_RUNNING_RAGDOLL_TASK = { Addresses::Addresses_Natives::Peds_a::IS_PED_RUNNING_RAGDOLL_TASK, TOC };
	BOOL(*IS_PED_RUNNING_RAGDOLL_TASK)(Ped ped) = (BOOL(*)(Ped))&_IS_PED_RUNNING_RAGDOLL_TASK;
	
	opd_s _SET_PED_CAN_RAGDOLL = { Addresses::Addresses_Natives::Peds_a::SET_PED_CAN_RAGDOLL, TOC };
	void(*SET_PED_CAN_RAGDOLL)(int player, bool ragdoll) = (void(*)(int, bool))&_SET_PED_CAN_RAGDOLL;
	
	opd_s _SET_PED_TO_RAGDOLL = { Addresses::Addresses_Natives::Peds_a::SET_PED_TO_RAGDOLL, TOC };
	BOOL(*SET_PED_TO_RAGDOLL)(Ped ped, int time1, int time2, int ragdollType, BOOL p4, BOOL p5, BOOL p6) = (BOOL(*)(Ped, int, int, int, BOOL, BOOL, BOOL))&_SET_PED_TO_RAGDOLL;
	
	opd_s _SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT = { Addresses::Addresses_Natives::Peds_a::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT, TOC };
	void(*SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT;
	
	//opd_s _SET_PED_IS_DRUNK = { Addresses::Addresses_Natives::Peds_a::SET_PED_IS_DRUNK, TOC };
	//void(*SET_PED_IS_DRUNK)(Any p0, BOOL p1) = (void(*)(Any, BOOL))&_SET_PED_IS_DRUNK;
	
	opd_s _TASK_ARREST_PED = { Addresses::Addresses_Natives::Peds_a::TASK_ARREST_PED, TOC };
	void(*TASK_ARREST_PED)(Any p0, Any p1) = (void(*)(Any, Any))&_TASK_ARREST_PED;
	
	opd_s _UNCUFF_PED = { Addresses::Addresses_Natives::Peds_a::UNCUFF_PED, TOC };
	void(*UNCUFF_PED)(Ped ped) = (void(*)(Ped))&_UNCUFF_PED;

	opd_s _SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE = { Addresses::Addresses_Natives::Peds_a::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE, TOC };
	void(*SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE)(Ped ped, BOOL state) = (void(*)(Ped, BOOL))&_SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE;

	opd_s _GIVE_PLAYER_RAGDOLL_CONTROL = { Addresses::Addresses_Natives::Peds_a::GIVE_PLAYER_RAGDOLL_CONTROL, TOC };
	void(*GIVE_PLAYER_RAGDOLL_CONTROL)(Player player, BOOL toggle) = (void(*)(Ped, BOOL))&_GIVE_PLAYER_RAGDOLL_CONTROL;

	opd_s _SET_PED_RAGDOLL_ON_COLLISION = { Addresses::Addresses_Natives::Peds_a::SET_PED_RAGDOLL_ON_COLLISION, TOC };
	void(*SET_PED_RAGDOLL_ON_COLLISION)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_PED_RAGDOLL_ON_COLLISION;



	opd_s _SET_PED_MAX_TIME_IN_WATER = { Addresses::Addresses_Natives::Peds_a::SET_PED_MAX_TIME_IN_WATER, TOC };
	void(*SET_PED_MAX_TIME_IN_WATER)(Ped ped, float value) = (void(*)(Ped, float))&_SET_PED_MAX_TIME_IN_WATER;

	opd_s _SET_PED_MAX_TIME_UNDERWATER = { Addresses::Addresses_Natives::Peds_a::SET_PED_MAX_TIME_UNDERWATER, TOC };
	void(*SET_PED_MAX_TIME_UNDERWATER)(Ped ped, float value) = (void(*)(Ped, float))&_SET_PED_MAX_TIME_UNDERWATER;


	opd_s _SET_PED_DIES_IN_VEHICLE = { Addresses::Addresses_Natives::Peds_a::SET_PED_DIES_IN_VEHICLE, TOC };
	void(*SET_PED_DIES_IN_VEHICLE)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_PED_DIES_IN_VEHICLE;

	
	
	opd_s _SET_PED_ARMOUR = { Addresses::Addresses_Natives::Peds_a::SET_PED_ARMOUR, TOC };
	void(*SET_PED_ARMOUR)(Ped ped, int amount) = (void(*)(Ped, int))&_SET_PED_ARMOUR;

	opd_s _SET_PED_MAX_HEALTH = { Addresses::Addresses_Natives::Peds_a::SET_PED_MAX_HEALTH, TOC };
	void(*SET_PED_MAX_HEALTH)(Ped ped, Any value) = (void(*)(Ped, Any))&_SET_PED_MAX_HEALTH;

	opd_s _GET_PED_MAX_HEALTH = { Addresses::Addresses_Natives::Peds_a::GET_PED_MAX_HEALTH, TOC };
	Any(*GET_PED_MAX_HEALTH)(Ped ped) = (Any(*)(Ped))&_GET_PED_MAX_HEALTH;

	//opd_s _SET_PED_AS_COP = { Addresses::Addresses_Natives::Peds_a::SET_PED_AS_COP, TOC };
	//void(*SET_PED_AS_COP)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_PED_AS_COP;

	/*
		Gets the closest ped in a radius.

	Ped Types:
	Any ped = -1
	Player = 1
	Male = 4
	Female = 5
	Cop = 6
	Human = 26
	SWAT = 27
	Animal = 28
	Army = 29

	------------------
	P4 P5 P7 P8
	1 0 x x = return nearest walking Ped
	1 x 0 x = return nearest walking Ped
	x 1 1 x = return Ped you are using
	0 0 x x = no effect
	0 x 0 x = no effect

	x = can be 1 or 0. Does not have any obvious changes.

	This function does not return ped who is:
	1. Standing still
	2. Driving
	3. Fleeing
	4. Attacking

	This function only work if the ped is:
	1. walking normally.
	2. waiting to cross a road.

	Note: PED::GET_PED_NEARBY_PEDS works for more peds.
	*/
	opd_s _GET_CLOSEST_PED = { Addresses::Addresses_Natives::Peds_a::GET_CLOSEST_PED, TOC };
	BOOL(*GET_CLOSEST_PED)(float x, float y, float z, float radius, BOOL p4, BOOL p5, Ped *outPed, BOOL p7, BOOL p8, int pedType) = (BOOL(*)(float, float, float, float, BOOL, BOOL, Ped*, BOOL, BOOL, int))&_GET_CLOSEST_PED;

	

	/*
	sizeAndPeds is a pointer to an array. The array is filled with peds found nearby the ped supplied to the first argument.

	p2 tend to be -1 (could be pedType)

	Return value is the number of peds found and added to the array passed.

	-----------------------------------

	Example of returned array:
	0: 4 (This value need to be set before passing the array to this function)
	1: -858993460
	2: 31274
	3: -858993460
	4: 7211
	5: -858993460
	6: 50732
	7: -858993460
	8: -858993460

	Return : 3
	*/
	opd_s _GET_PED_NEARBY_PEDS = { Addresses::Addresses_Natives::Peds_a::GET_PED_NEARBY_PEDS, TOC };
	int(*GET_PED_NEARBY_PEDS)(Ped ped, int *sizeAndPeds, int p2) = (int(*)(Ped, int*, int))&_GET_PED_NEARBY_PEDS;


	/*
	Returns size of array, passed into the second variable.

	See below for usage information.

	>moment0
	This function actually requires a struct, where the first value is the maximum number of elements to return. Here is a sample of how I was able to get it to work correctly, without yet knowing the struct format.

	//Setup the array
	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Any veh[arrSize];
	//0 index is the size of the array
	veh[0] = numElements;

	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);

	if (veh != NULL)
	{
	//Simple loop to go through results
	for (int i = 0; i < count; i++)
	{
	int offsettedID = i * 2 + 2;
	//Make sure it exists
	if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
	{
	//Do something
	}
	}
	} 
	*/

	opd_s _GET_PED_NEARBY_VEHICLES = { Addresses::Addresses_Natives::Peds_a::GET_PED_NEARBY_VEHICLES, TOC };
	int(*GET_PED_NEARBY_VEHICLES)(Ped ped, int *sizeAndVehs) = (int(*)(Ped, int*))&_GET_PED_NEARBY_VEHICLES;

	
	

	
	// Peds Vehicle Stuff
	opd_s _IS_PED_IN_VEHICLE = { Addresses::Addresses_Natives::Peds_a::IS_PED_IN_VEHICLE, TOC };
	BOOL(*IS_PED_IN_VEHICLE)(Ped ped, Vehicle vehicle, BOOL atGetIn) = (BOOL(*)(Ped, Vehicle, BOOL))&_IS_PED_IN_VEHICLE;

	opd_s _IS_PED_FATALLY_INJURED = { Addresses::Addresses_Natives::Peds_a::IS_PED_FATALLY_INJURED, TOC };
	BOOL(*IS_PED_FATALLY_INJURED)(Ped ped) = (BOOL(*)(Ped))&_IS_PED_FATALLY_INJURED;

	opd_s _IS_PED_IN_ANY_VEHICLE = { Addresses::Addresses_Natives::Peds_a::IS_PED_IN_ANY_VEHICLE, TOC };
	BOOL(*IS_PED_IN_ANY_VEHICLE)(Ped ped, BOOL atGetIn) = (BOOL(*)(Ped, BOOL))&_IS_PED_IN_ANY_VEHICLE;

	opd_s _IS_PED_IN_ANY_TAXI = { Addresses::Addresses_Natives::Peds_a::IS_PED_IN_ANY_TAXI, TOC };
	BOOL(*IS_PED_IN_ANY_TAXI)(Ped ped) = (BOOL(*)(Ped))&_IS_PED_IN_ANY_TAXI;
	
	// [False = CurrentVehicle, True = LastVehicle]
	opd_s _GET_VEHICLE_PED_IS_IN = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_PED_IS_IN, TOC };
	Vehicle(*GET_VEHICLE_PED_IS_IN)(Ped ped, BOOL getLastVehicle) = (Vehicle(*)(Ped, BOOL))&_GET_VEHICLE_PED_IS_IN;
	
	//opd_s _IS_PED_IN_ANY_VEHICLE = { Addresses::Addresses_Natives::Peds_a::IS_PED_IN_ANY_VEHICLE, TOC };
	//bool(*IS_PED_IN_ANY_VEHICLE)(uint pedid, int Zero) = (bool(*)(uint, int))&_IS_PED_IN_ANY_VEHICLE;
	
		
	opd_s _IS_PED_IN_ANY_BOAT = { Addresses::Addresses_Natives::Peds_a::IS_PED_IN_ANY_BOAT, TOC };
	BOOL(*IS_PED_IN_ANY_BOAT)(Ped ped) = (BOOL(*)(Ped))&_IS_PED_IN_ANY_BOAT;
		
	opd_s _IS_PED_IN_ANY_HELI = { Addresses::Addresses_Natives::Peds_a::IS_PED_IN_ANY_HELI, TOC };
	BOOL(*IS_PED_IN_ANY_HELI)(Ped ped) = (BOOL(*)(Ped))&_IS_PED_IN_ANY_HELI;
		
	opd_s _IS_PED_IN_ANY_PLANE = { Addresses::Addresses_Natives::Peds_a::IS_PED_IN_ANY_PLANE, TOC };
	BOOL(*IS_PED_IN_ANY_PLANE)(Ped ped) = (BOOL(*)(Ped))&_IS_PED_IN_ANY_PLANE;
		
	opd_s _IS_PED_IN_ANY_POLICE_VEHICLE = { Addresses::Addresses_Natives::Peds_a::IS_PED_IN_ANY_POLICE_VEHICLE, TOC };
	BOOL(*IS_PED_IN_ANY_POLICE_VEHICLE)(Ped ped) = (BOOL(*)(Ped))&_IS_PED_IN_ANY_POLICE_VEHICLE;
		
	//opd_s _IS_PED_IN_ANY_SUB = { Addresses::Addresses_Natives::Peds_a::IS_PED_IN_ANY_SUB, TOC };
	//BOOL(*IS_PED_IN_ANY_SUB)(Ped ped) = (BOOL(*)(Ped))&_IS_PED_IN_ANY_SUB;
		
	//opd_s _IS_PED_IN_ANY_TAXI = { Addresses::Addresses_Natives::Peds_a::IS_PED_IN_ANY_TAXI, TOC };
	//BOOL(*IS_PED_IN_ANY_TAXI)(Ped ped) = (BOOL(*)(Ped))&_IS_PED_IN_ANY_TAXI;
		
	//opd_s _IS_PED_IN_ANY_TRAIN = { Addresses::Addresses_Natives::Peds_a::IS_PED_IN_ANY_TRAIN, TOC };
	//BOOL(*IS_PED_IN_ANY_TRAIN)(Ped ped) = (BOOL(*)(Ped))&_IS_PED_IN_ANY_TRAIN;
		
	//opd_s _IS_PED_IN_ANY_VEHICLE = { Addresses::Addresses_Natives::Peds_a::IS_PED_IN_ANY_VEHICLE, TOC };
	//BOOL(*IS_PED_IN_ANY_VEHICLE)(Ped ped) = (BOOL(*)(Ped))&_IS_PED_IN_ANY_VEHICLE;
		
	//opd_s _IS_PED_IN_FLYING_VEHICLE = { Addresses::Addresses_Natives::Peds_a::IS_PED_IN_FLYING_VEHICLE, TOC };
	//BOOL(*IS_PED_IN_FLYING_VEHICLE)(Ped ped) = (BOOL(*)(Ped))&_IS_PED_IN_FLYING_VEHICLE;
		
	//opd_s _IS_PED_IN_VEHICLE = { Addresses::Addresses_Natives::Peds_a::IS_PED_IN_VEHICLE, TOC };
	//BOOL(*IS_PED_IN_VEHICLE)(Ped ped) = (BOOL(*)(Ped))&_IS_PED_IN_VEHICLE;
		
	opd_s _IS_PED_ON_ANY_BIKE = { Addresses::Addresses_Natives::Peds_a::IS_PED_ON_ANY_BIKE, TOC };
	BOOL(*IS_PED_ON_ANY_BIKE)(Ped ped) = (BOOL(*)(Ped))&_IS_PED_ON_ANY_BIKE;

	//opd_s _GET_VEHICLE_PED_IS_USING = { Addresses::Addresses_Natives::Peds_a::GET_VEHICLE_PED_IS_USING, TOC };
	//int(*GET_VEHICLE_PED_IS_USING)(int PLAYER_ID) = (int(*)(int))&_GET_VEHICLE_PED_IS_USING;

	//opd_s _KNOCK_PED_OFF_VEHICLE = { Addresses::Addresses_Natives::Peds_a::KNOCK_PED_OFF_VEHICLE, TOC };
	//Ped(*KNOCK_PED_OFF_VEHICLE)(Ped ped) = (Ped(*)(Ped))&_KNOCK_PED_OFF_VEHICLE;

	opd_s _IS_VEHICLE_ON_ALL_WHEELS = { Addresses::Addresses_Natives::Vehicles_a::IS_VEHICLE_ON_ALL_WHEELS, TOC };
	BOOL(*IS_VEHICLE_ON_ALL_WHEELS)(Vehicle vehicle) = (BOOL(*)(Vehicle))&_IS_VEHICLE_ON_ALL_WHEELS;
	

	//---------------------------------------------------------------------------------------------//
	

	
	//---------------------------------------------------------------------------------------------//
	// Weather
	opd_s _SET_OVERRIDE_WEATHER = { Addresses::Addresses_Natives::Weather_a::SET_OVERRIDE_WEATHER, TOC };
	void(*SET_OVERRIDE_WEATHER)(const char*) = (void(*)(const char*))&_SET_OVERRIDE_WEATHER;
	
	opd_s _SET_WEATHER_TYPE_PERSIST = { Addresses::Addresses_Natives::Weather_a::SET_WEATHER_TYPE_PERSIST, TOC };
	void(*SET_WEATHER_TYPE_PERSIST)(char *weatherType) = (void(*)(char*))&_SET_WEATHER_TYPE_PERSIST;
	
	opd_s _SET_WEATHER_TYPE_NOW_PERSIST = { Addresses::Addresses_Natives::Weather_a::SET_WEATHER_TYPE_NOW_PERSIST, TOC };
	void(*SET_WEATHER_TYPE_NOW_PERSIST)(char *weatherType) = (void(*)(char*))&_SET_WEATHER_TYPE_NOW_PERSIST;
	
	opd_s _SET_WEATHER_TYPE_NOW = { Addresses::Addresses_Natives::Weather_a::SET_WEATHER_TYPE_NOW, TOC };
	void(*SET_WEATHER_TYPE_NOW)(char *weatherType) = (void(*)(char*))&_SET_WEATHER_TYPE_NOW;
	
	opd_s _CLEAR_WEATHER_TYPE_PERSIST = { Addresses::Addresses_Natives::Weather_a::CLEAR_WEATHER_TYPE_PERSIST, TOC };
	void(*CLEAR_WEATHER_TYPE_PERSIST)() = (void(*)())&_CLEAR_WEATHER_TYPE_PERSIST;
	
	opd_s _CLEAR_OVERRIDE_WEATHER = { Addresses::Addresses_Natives::Weather_a::CLEAR_OVERRIDE_WEATHER, TOC };
	void(*CLEAR_OVERRIDE_WEATHER)() = (void(*)())&_CLEAR_OVERRIDE_WEATHER;
	
	opd_s _SET_RANDOM_WEATHER_TYPE = { Addresses::Addresses_Natives::Weather_a::SET_RANDOM_WEATHER_TYPE, TOC };
	void(*SET_RANDOM_WEATHER_TYPE)() = (void(*)())&_SET_RANDOM_WEATHER_TYPE;
	//---------------------------------------------------------------------------------------------//
	


	//---------------------------------------------------------------------------------------------//
	// Time
	opd_s _SET_TIME_SCALE = { Addresses::Addresses_Natives::Time_a::SET_TIME_SCALE, TOC };
	void(*SET_TIME_SCALE)(float time) = (void(*)(float))&_SET_TIME_SCALE;

	opd_s _ADD_TO_CLOCK_TIME = { Addresses::Addresses_Natives::Time_a::ADD_TO_CLOCK_TIME, TOC };
	void(*ADD_TO_CLOCK_TIME)(Any p0, Any p1, Any p2) = (void(*)(Any, Any, Any))&_ADD_TO_CLOCK_TIME;

	opd_s _PAUSE_CLOCK = { Addresses::Addresses_Natives::Time_a::PAUSE_CLOCK, TOC };
	void(*PAUSE_CLOCK)(BOOL toggle) = (void(*)(BOOL))&_PAUSE_CLOCK;

	opd_s _SET_CLOCK_TIME = { Addresses::Addresses_Natives::Time_a::SET_CLOCK_TIME, TOC };
	void(*SET_CLOCK_TIME)(int hour, int minute, int second) = (void(*)(int, int, int))&_SET_CLOCK_TIME;
	

	//opd_s _PAUSE_CLOCK = { Addresses::Addresses_Natives::Time_a::PAUSE_CLOCK, TOC };
	//void(*PAUSE_CLOCK)(BOOL toggle) = (void(*)(BOOL))&_PAUSE_CLOCK;

	opd_s _GET_CLOCK_DAY_OF_MONTH = { Addresses::Addresses_Natives::Time_a::GET_CLOCK_DAY_OF_MONTH, TOC };
	Any(*GET_CLOCK_DAY_OF_MONTH)() = (Any(*)())&_GET_CLOCK_DAY_OF_MONTH;

	opd_s _GET_CLOCK_DAY_OF_WEEK = { Addresses::Addresses_Natives::Time_a::GET_CLOCK_DAY_OF_WEEK, TOC };
	Any(*GET_CLOCK_DAY_OF_WEEK)() = (Any(*)())&_GET_CLOCK_DAY_OF_WEEK;

	opd_s _GET_CLOCK_HOURS = { Addresses::Addresses_Natives::Time_a::GET_CLOCK_HOURS, TOC };
	Any(*GET_CLOCK_HOURS)() = (Any(*)())&_GET_CLOCK_HOURS;

	opd_s _GET_CLOCK_MINUTES = { Addresses::Addresses_Natives::Time_a::GET_CLOCK_MINUTES, TOC };
	Any(*GET_CLOCK_MINUTES)() = (Any(*)())&_GET_CLOCK_MINUTES;

	opd_s _GET_CLOCK_SECONDS = { Addresses::Addresses_Natives::Time_a::GET_CLOCK_SECONDS, TOC };
	Any(*GET_CLOCK_SECONDS)() = (Any(*)())&_GET_CLOCK_SECONDS;

	opd_s _GET_CLOCK_MONTH = { Addresses::Addresses_Natives::Time_a::GET_CLOCK_MONTH, TOC };
	Any(*GET_CLOCK_MONTH)() = (Any(*)())&_GET_CLOCK_MONTH;

	opd_s _GET_CLOCK_YEAR = { Addresses::Addresses_Natives::Time_a::GET_CLOCK_YEAR, TOC };
	Any(*GET_CLOCK_YEAR)() = (Any(*)())&_GET_CLOCK_YEAR;

	//opd_s _ADD_TO_CLOCK_TIME = { Addresses::Addresses_Natives::Time_a::ADD_TO_CLOCK_TIME, TOC };
	//void(*ADD_TO_CLOCK_TIME)(Any p0, Any p1, Any p2) = (void(*)(Any, Any, Any))&_ADD_TO_CLOCK_TIME;

	//opd_s _SET_CLOCK_DATE = { Addresses::Addresses_Natives::Time_a::SET_CLOCK_DATE, TOC };
	//void(*SET_CLOCK_DATE)(int day, int month, int year) = (void(*)(int, int, int))&_SET_CLOCK_DATE;
	//---------------------------------------------------------------------------------------------//

	
	
	//---------------------------------------------------------------------------------------------//
	// Vehicles

	opd_s _GET_VEHICLE_PED_IS_USING = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_PED_IS_USING, TOC };
	Vehicle(*GET_VEHICLE_PED_IS_USING)(Ped ped) = (Vehicle(*)(Ped))&_GET_VEHICLE_PED_IS_USING;

	opd_s _IS_ENTITY_A_VEHICLE = { Addresses::Addresses_Natives::Entity_a::IS_ENTITY_A_VEHICLE, TOC };
	int(*IS_ENTITY_A_VEHICLE)(int p1) = (int(*)(int))&_IS_ENTITY_A_VEHICLE;

	//opd_s _SET_VEHICLE_OUT_OF_CONTROL = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_OUT_OF_CONTROL, TOC };
	//int(*SET_VEHICLE_OUT_OF_CONTROL)(Vehicle vehicle, BOOL killDriver, BOOL explodeOnImpact) = (int(*)(Vehicle, BOOL, BOOL))&_SET_VEHICLE_OUT_OF_CONTROL;

	

	opd_s _CREATE_VEHICLE = { Addresses::Addresses_Natives::Vehicles_a::CREATE_VEHICLE, TOC };
	Vehicle(*CREATE_VEHICLE)(Hash modelHash, float x, float y, float z, float heading, BOOL networkHandle, BOOL vehiclehandle) = (Vehicle (*)(Hash, float, float, float, float, BOOL, BOOL))&_CREATE_VEHICLE;
	
	opd_s _CREATE_VEHICLE_ALT = { Addresses::Addresses_Natives::Vehicles_a::CREATE_VEHICLE, TOC };
	int(*CREATE_VEHICLE_ALT)(int carHash, float* getCords, float r0, bool fallsee, bool fallse) = (int(*)(int, float*, float, bool, bool))&_CREATE_VEHICLE_ALT;
	
	opd_s _CREATE_VEHICLE_ALT2 = { Addresses::Addresses_Natives::Vehicles_a::CREATE_VEHICLE, TOC };
	uint(*CREATE_VEHICLE_ALT2)(int carHash, Vec3* getCords, float r0, bool fallsee, bool fallse) = (uint(*)(int, Vec3*, float, bool, bool))&_CREATE_VEHICLE_ALT2;
	

	//opd_s _SET_VEHICLE_GRAVITY = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_GRAVITY, TOC };
	//void(*SET_VEHICLE_GRAVITY)(Vehicle vehicle, BOOL Toggle) = (void(*)(Vehicle vehicle, BOOL Toggle))&_SET_VEHICLE_GRAVITY;

	opd_s _SET_VEHICLE_FIXED = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_FIXED, TOC };
	void(*SET_VEHICLE_FIXED)(int VehicleID) = (void(*)(int))&_SET_VEHICLE_FIXED;

	opd_s _SET_VEHICLE_DEFORMATION_FIXED = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_DEFORMATION_FIXED, TOC };
	void(*SET_VEHICLE_DEFORMATION_FIXED)(Vehicle vehicle) = (void(*)(Vehicle))&_SET_VEHICLE_DEFORMATION_FIXED;
	
	// dirtLevel = 0 (clean) to 15 (dirty)
	opd_s _SET_VEHICLE_DIRT_LEVEL = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_DIRT_LEVEL, TOC };
	void(*SET_VEHICLE_DIRT_LEVEL)(Vehicle vehicle, float dirtLevel) = (void(*)(Vehicle, float))&_SET_VEHICLE_DIRT_LEVEL;

	opd_s _GET_VEHICLE_DIRT_LEVEL = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_DIRT_LEVEL, TOC };
	float(*GET_VEHICLE_DIRT_LEVEL)(Vehicle vehicle) = (float(*)(Vehicle))&_GET_VEHICLE_DIRT_LEVEL;

	//opd_s _IS_VEHICLE_SEAT_FREE = { Addresses::Addresses_Natives::Vehicles_a::IS_VEHICLE_SEAT_FREE, TOC };
	//BOOL(*IS_VEHICLE_SEAT_FREE)(Vehicle vehicle, int seatIndex) = (BOOL(*)(Vehicle, int))&_IS_VEHICLE_SEAT_FREE;

	//opd_s _GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS, TOC };
	//int(*GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS)(Vehicle vehicle) = (int(*)(Vehicle))&_GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS;

	opd_s _GET_VEHICLE_NUMBER_OF_PASSENGERS = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_NUMBER_OF_PASSENGERS, TOC };
	int(*GET_VEHICLE_NUMBER_OF_PASSENGERS)(Vehicle vehicle) = (int(*)(Vehicle))&_GET_VEHICLE_NUMBER_OF_PASSENGERS;

	opd_s _SET_VEHICLE_UNDRIVEABLE = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_UNDRIVEABLE, TOC };
	void(*SET_VEHICLE_UNDRIVEABLE)(Vehicle vehicle, BOOL state) = (void(*)(Vehicle, BOOL))&_SET_VEHICLE_UNDRIVEABLE;

	//opd_s _SET_VEHICLE_DOOR_BROKEN = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_DOOR_BROKEN, TOC };
	//void(*SET_VEHICLE_DOOR_BROKEN)(Vehicle vehicle, int doorIndex, BOOL isBroken) = (void(*)(Vehicle, int, BOOL))&_SET_VEHICLE_DOOR_BROKEN;

	//opd_s _SET_VEHICLE_IS_WANTED = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_IS_WANTED, TOC };
	//void(*SET_VEHICLE_IS_WANTED)(Vehicle p0, BOOL p1) = (void(*)(Vehicle, BOOL))&_SET_VEHICLE_IS_WANTED;

	//opd_s _SET_VEHICLE_IS_STOLEN = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_IS_STOLEN, TOC };
	//void(*SET_VEHICLE_IS_STOLEN)(Vehicle vehicle, BOOL isStolen) = (void(*)(Vehicle, BOOL))&_SET_VEHICLE_IS_STOLEN;

	

	//opd_s _SET_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME, TOC };
	//void(*SET_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME)(float multiplier) = (void(*)(float))&_SET_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME;

	//opd_s _SET_RANDOM_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME = { Addresses::Addresses_Natives::Vehicles_a::SET_RANDOM_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME, TOC };
	//void(*SET_RANDOM_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME)(float multiplier) = (void(*)(float))&_SET_RANDOM_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME;

	//opd_s _SET_RANDOM_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME = { Addresses::Addresses_Natives::Vehicles_a::SET_RANDOM_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME, TOC };
	//void(*SET_RANDOM_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME)() = (void(*)())&_SET_RANDOM_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME;

	//opd_s _SET_PARKED_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME = { Addresses::Addresses_Natives::Vehicles_a::SET_PARKED_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME, TOC };
	//void(*SET_PARKED_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME)(float multiplier) = (void(*)(float))&_SET_PARKED_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME;


	



	/*
	-1 being the driver seat.
	Use GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(vehicle) - 1 for last seat index.
	*/
	opd_s _IS_VEHICLE_SEAT_FREE = { Addresses::Addresses_Natives::Vehicles_a::IS_VEHICLE_SEAT_FREE, TOC };
	BOOL(*IS_VEHICLE_SEAT_FREE)(Vehicle vehicle, int seatIndex) = (BOOL(*)(Vehicle, int))&_IS_VEHICLE_SEAT_FREE;

	opd_s _GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS, TOC };
	int(*GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS)(Vehicle vehicle) = (int(*)(Vehicle))&_GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS;

	/*
	doorIndex:
	0 = Front Left Door
	1 = Front Right Door
	2 = Back Left Door
	3 = Back Right Door
	4 = Hood
	5 = Trunk
	6 = Trunk2
	*/
	//opd_s _SET_VEHICLE_DOOR_OPEN = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_DOOR_OPEN, TOC };
	//void(*SET_VEHICLE_DOOR_OPEN)(Vehicle vehicle, int doorIndex, BOOL loose, BOOL openInstantly) = (void(*)(Vehicle, int, BOOL, BOOL))&_SET_VEHICLE_DOOR_OPEN;

	//opd_s _SET_VEHICLE_DOORS_OPEN = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_DOORS_OPEN, TOC };
	//void(*SET_VEHICLE_DOORS_OPEN)(Vehicle vehicle, int doorIndex, BOOL loose, BOOL openInstantly) = (void(*)(Vehicle, int, BOOL, BOOL))&_SET_VEHICLE_DOORS_OPEN;

	//opd_s _SET_VEHICLE_DOOR_SHUT = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_DOOR_SHUT, TOC };
	//void(*SET_VEHICLE_DOOR_SHUT)(Vehicle vehicle, int doorIndex, BOOL closeInstantly) = (void(*)(Vehicle, int, BOOL))&_SET_VEHICLE_DOOR_SHUT;

	//opd_s _SET_VEHICLE_DOORS_SHUT = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_DOORS_SHUT, TOC };
	//void(*SET_VEHICLE_DOORS_SHUT)(Vehicle vehicle, BOOL closeInstantly) = (void(*)(Vehicle, BOOL))&_SET_VEHICLE_DOORS_SHUT;

	//opd_s _SET_VEHICLE_DOORS_LOCKED = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_DOORS_LOCKED, TOC };
	//void(*SET_VEHICLE_DOORS_LOCKED)(Vehicle hash, int doorLockStatus) = (void(*)(Vehicle, int))&_SET_VEHICLE_DOORS_LOCKED;

	/*
	We can see this being used in R* scripts such as "am_mp_property_int.ysc.c4":
	l_11A1 = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 1);
	...
	VEHICLE::SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS(l_11A1, 1);
	*/
	//opd_s _SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS, TOC };
	//void(*SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS)(Vehicle vehicle, BOOL toggle) = (void(*)(Vehicle, BOOL))&_SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS;

	//opd_s _SET_VEHICLE_DOORS_LOCKED_FOR_PLAYER = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_DOORS_LOCKED_FOR_PLAYER, TOC };
	//void(*SET_VEHICLE_DOORS_LOCKED_FOR_PLAYER)(Vehicle vehicle, Player player) = (void(*)(Vehicle, Player))&_SET_VEHICLE_DOORS_LOCKED_FOR_PLAYER;

	//opd_s _SET_VEHICLE_DOORS_LOCKED_FOR_TEAM = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_DOORS_LOCKED_FOR_TEAM, TOC };
	//void(*SET_VEHICLE_DOORS_LOCKED_FOR_TEAM)(Vehicle vehicle, int team, BOOL toggle) = (void(*)(Vehicle, int, BOOL))&_SET_VEHICLE_DOORS_LOCKED_FOR_TEAM;

	//opd_s _SET_VEHICLE_DOOR_LATCHED = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_DOOR_LATCHED, TOC };
	//void(*SET_VEHICLE_DOOR_LATCHED)(Any p0, Any p1, BOOL p2, BOOL p3, BOOL p4) = (void(*)(Any, Any, BOOL, BOOL, BOOL))&_SET_VEHICLE_DOOR_LATCHED;

	/*
	windowIndex:
	0 = Front Right Window
	1 = Front Left Window
	2 = Back Right Window
	3 = Back Left Window
	*/
	//opd_s _ROLL_DOWN_WINDOWS = { Addresses::Addresses_Natives::Vehicles_a::ROLL_DOWN_WINDOWS, TOC };
	//void(*ROLL_DOWN_WINDOWS)(Vehicle vehicle) = (void(*)(Vehicle vehicle))&_ROLL_DOWN_WINDOWS;

	//opd_s _ROLL_DOWN_WINDOW = { Addresses::Addresses_Natives::Vehicles_a::ROLL_DOWN_WINDOW, TOC };
	//void(*ROLL_DOWN_WINDOW)(Vehicle vehicle, int windowIndex) = (void(*)(Vehicle, int))&_ROLL_DOWN_WINDOW;

	//opd_s _ROLL_UP_WINDOW = { Addresses::Addresses_Natives::Vehicles_a::ROLL_UP_WINDOW, TOC };
	//void(*ROLL_UP_WINDOW)(Vehicle vehicle, int windowIndex) = (void(*)(Vehicle, int))&_ROLL_UP_WINDOW;

	opd_s _SMASH_VEHICLE_WINDOW = { Addresses::Addresses_Natives::Vehicles_a::SMASH_VEHICLE_WINDOW, TOC };
	void(*SMASH_VEHICLE_WINDOW)(Vehicle vehicle, int index) = (void(*)(Vehicle, int))&_SMASH_VEHICLE_WINDOW;

	//opd_s _FIX_VEHICLE_WINDOW = { Addresses::Addresses_Natives::Vehicles_a::FIX_VEHICLE_WINDOW, TOC };
	//void(*FIX_VEHICLE_WINDOW)(Vehicle vehicle, int index) = (void(*)(Vehicle, int))&_FIX_VEHICLE_WINDOW;

	opd_s _REMOVE_VEHICLE_WINDOW = { Addresses::Addresses_Natives::Vehicles_a::REMOVE_VEHICLE_WINDOW, TOC };
	void(*REMOVE_VEHICLE_WINDOW)(Vehicle vehicle, int windowIndex) = (void(*)(Vehicle, int))&_REMOVE_VEHICLE_WINDOW;



	opd_s _EXPLODE_VEHICLE = { Addresses::Addresses_Natives::Vehicles_a::EXPLODE_VEHICLE, TOC };
	void(*EXPLODE_VEHICLE)(Vehicle vehicle, BOOL isAudible, BOOL isInvisible) = (void(*)(Vehicle, BOOL, BOOL))&_EXPLODE_VEHICLE;




	



	/*
	the vehicle cant be a mission entity to delete,
	so call this before deleting
	SET_ENTITY_AS_MISSION_ENTITY(vehicle, false, true);
	*/
	opd_s _DELETE_VEHICLE = { Addresses::Addresses_Natives::Vehicles_a::DELETE_VEHICLE, TOC };
	void(*DELETE_VEHICLE)(Vehicle* vehicle) = (void(*)(Vehicle*))&_DELETE_VEHICLE;
	
	opd_s _DELETE_VEHICLE_UINT = { Addresses::Addresses_Natives::Vehicles_a::DELETE_VEHICLE, TOC };
	void(*DELETE_VEHICLE_UINT)(VehicleUint vehicle) = (void(*)(VehicleUint))&_DELETE_VEHICLE_UINT;

	opd_s _DELETE_VEHICLE_ALT = { Addresses::Addresses_Natives::Vehicles_a::DELETE_VEHICLE, TOC };
	void(*DELETE_VEHICLE_ALT)(int vehicle) = (void(*)(int))&_DELETE_VEHICLE_ALT;


	/*
	To burst tyres SET_VEHICLE_TYRE_BURST(vehicle, 0, true, 1000.0)
	to burst all tyres type it 8 times where p1 = 0 to 7
	*/
	opd_s _SET_VEHICLE_TYRE_BURST = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_TYRE_BURST, TOC };
	void(*SET_VEHICLE_TYRE_BURST)(Vehicle p0, BOOL p1, BOOL p2, float p3) = (void(*)(Vehicle, BOOL, BOOL, float))&_SET_VEHICLE_TYRE_BURST;






	// Vehicle Mod Stuff
	/*
	The vehicle must have a mod kit first.

	Any out of range ModIndex is stock.

	#Mod Type
	Spoilers - 0
	Front Bumper - 1
	Rear Bumper - 2
	Side Skirt - 3
	Exhaust - 4
	Frame - 5
	Grille - 6
	Hood - 7
	Fender - 8
	Right Fender - 9
	Roof - 10
	Engine - 11
	Brakes - 12
	Transmission - 13
	Horns - 14
	Suspension - 15
	Armor - 16
	Front Wheels - 23
	Back Wheels - 24 //only for motocycles

	Variation is only used for Wheels(23 and 24), setting to true will give the vehicle custom wheels
	*/
	opd_s _SET_VEHICLE_MOD = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_MOD, TOC };
	void(*SET_VEHICLE_MOD)(Vehicle vehicle, int modType, int modIndex, BOOL variation) = (void(*)(Vehicle, int, int, BOOL))&_SET_VEHICLE_MOD;

	//opd_s _GET_VEHICLE_MOD = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_MOD, TOC };
	//int(*GET_VEHICLE_MOD)(Vehicle vehicle, int modType) = (int(*)(Vehicle, int))&_GET_VEHICLE_MOD;

	//opd_s _GET_VEHICLE_MOD_VARIATION = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_MOD_VARIATION, TOC };
	//BOOL(*GET_VEHICLE_MOD_VARIATION)(Vehicle vehicle, int modType) = (BOOL(*)(Vehicle, int))&_GET_VEHICLE_MOD_VARIATION;

	//opd_s _GET_NUM_VEHICLE_MODS = { Addresses::Addresses_Natives::Vehicles_a::GET_NUM_VEHICLE_MODS, TOC };
	//int(*GET_NUM_VEHICLE_MODS)(Vehicle vehicle, int modType) = (int(*)(Vehicle, int))&_GET_NUM_VEHICLE_MODS;

	//opd_s _REMOVE_VEHICLE_MOD = { Addresses::Addresses_Natives::Vehicles_a::REMOVE_VEHICLE_MOD, TOC };
	//void(*REMOVE_VEHICLE_MOD)(Vehicle vehicle, int modType) = (void(*)(Vehicle, int))&_REMOVE_VEHICLE_MOD;

	opd_s _TOGGLE_VEHICLE_MOD = { Addresses::Addresses_Natives::Vehicles_a::TOGGLE_VEHICLE_MOD, TOC };
	int(*TOGGLE_VEHICLE_MOD)(Vehicle vehicle, int modType, BOOL toggle) = (int(*)(Vehicle, int, BOOL))&_TOGGLE_VEHICLE_MOD;

	//opd_s _IS_TOGGLE_MOD_ON = { Addresses::Addresses_Natives::Vehicles_a::IS_TOGGLE_MOD_ON, TOC };
	//BOOL(*IS_TOGGLE_MOD_ON)(Vehicle vehicle, int modType) = (BOOL(*)(Vehicle, int))&_IS_TOGGLE_MOD_ON;

	//opd_s _PRELOAD_VEHICLE_MOD = { Addresses::Addresses_Natives::Vehicles_a::PRELOAD_VEHICLE_MOD, TOC };
	//void(*PRELOAD_VEHICLE_MOD)(Any p0, Any p1, Any p2) = (void(*)(Any, Any, Any))&_PRELOAD_VEHICLE_MOD;
	
	//opd_s _HAS_PRELOAD_MODS_FINISHED = { Addresses::Addresses_Natives::Vehicles_a::HAS_PRELOAD_MODS_FINISHED, TOC };
	//BOOL(*HAS_PRELOAD_MODS_FINISHED)(Any p0) = (BOOL(*)(Any))&_HAS_PRELOAD_MODS_FINISHED;
	
	//opd_s _RELEASE_PRELOAD_MODS = { Addresses::Addresses_Natives::Vehicles_a::RELEASE_PRELOAD_MODS, TOC };
	//void(*RELEASE_PRELOAD_MODS)(Any p0) = (void(*)(Any))&_RELEASE_PRELOAD_MODS;

	

	opd_s _GET_VEHICLE_WHEEL_TYPE = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_WHEEL_TYPE, TOC };
	int(*GET_VEHICLE_WHEEL_TYPE)(Vehicle vehicle) = (int(*)(Vehicle))&_GET_VEHICLE_WHEEL_TYPE;

	opd_s _GET_VEHICLE_MOD_KIT = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_MOD_KIT, TOC };
	int(*GET_VEHICLE_MOD_KIT)(Vehicle vehicle) = (int(*)(Vehicle))&_GET_VEHICLE_MOD_KIT;

	opd_s _GET_VEHICLE_MOD_KIT_TYPE = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_MOD_KIT_TYPE, TOC };
	int(*GET_VEHICLE_MOD_KIT_TYPE)(Vehicle vehicle) = (int(*)(Vehicle))&_GET_VEHICLE_MOD_KIT_TYPE;

	// Set modkit to 0 to use other mods
	opd_s _SET_VEHICLE_MOD_KIT = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_MOD_KIT, TOC };
	void(*SET_VEHICLE_MOD_KIT)(Vehicle vehicle, int modKit) = (void(*)(Vehicle, int))&_SET_VEHICLE_MOD_KIT;

	opd_s _SET_VEHICLE_COLOURS = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_COLOURS, TOC };
	int(*SET_VEHICLE_COLOURS)(Vehicle vehicle, int colorPrimary, int colorSecondary) = (int(*)(Vehicle, int, int))&_SET_VEHICLE_COLOURS;

	
	opd_s _SET_VEHICLE_EXTRA_COLOURS = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_EXTRA_COLOURS, TOC };
	int(*SET_VEHICLE_EXTRA_COLOURS)(Vehicle vehicle, int pearlescentColor, int wheelColor) = (int(*)(Vehicle, int, int))&_SET_VEHICLE_EXTRA_COLOURS;

	//opd_s _SET_VEHICLE_CAN_BE_TARGETTED = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_CAN_BE_TARGETTED, TOC };
	//void(*SET_VEHICLE_CAN_BE_TARGETTED)(Vehicle vehicle, BOOL state) = (void(*)(Vehicle, BOOL))&_SET_VEHICLE_CAN_BE_TARGETTED;

	

	/*
	Sets a vehicle's license plate text. 8 chars maximum.

	Example:
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	char* plateText = "KING";
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, (plateText));
	*/
	opd_s _SET_VEHICLE_NUMBER_PLATE_TEXT = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_NUMBER_PLATE_TEXT, TOC };
	void(*SET_VEHICLE_NUMBER_PLATE_TEXT)(Vehicle vehicle, char *plateText) = (void(*)(Vehicle, char*))&_SET_VEHICLE_NUMBER_PLATE_TEXT;

	opd_s _GET_VEHICLE_NUMBER_PLATE_TEXT = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_NUMBER_PLATE_TEXT, TOC };
	char*(*GET_VEHICLE_NUMBER_PLATE_TEXT)(Vehicle vehicle) = (char*(*)(Vehicle))&_GET_VEHICLE_NUMBER_PLATE_TEXT;

	/*
	Plates:
	Blue/White - 0
	Yellow/black - 1
	Yellow/Blue - 2
	Blue/White2 - 3
	Blue/White3 - 4
	Yankton - 5
	*/
	opd_s _SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX, TOC };
	void(*SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX)(Vehicle vehicle, int plateIndex) = (void(*)(Vehicle, int))&_SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX;

	//opd_s _GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX, TOC };
	//int(*GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX)(Vehicle vehicle) = (int(*)(Vehicle))&_GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX;

	opd_s _SET_CAN_RESPRAY_VEHICLE = { Addresses::Addresses_Natives::Vehicles_a::SET_CAN_RESPRAY_VEHICLE, TOC };
	void(*SET_CAN_RESPRAY_VEHICLE)(Vehicle vehicle, BOOL state) = (void(*)(Vehicle, BOOL))&_SET_CAN_RESPRAY_VEHICLE;


	
	
	/*
	0: Sport
	1: Muscle
	2: Lowrider
	3: SUV
	4: Offroad
	5: Tuner
	6: Bike Wheels
	7: High End
	*/	
	opd_s _SET_VEHICLE_WHEEL_TYPE = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_WHEEL_TYPE, TOC };
	void(*SET_VEHICLE_WHEEL_TYPE)(Vehicle vehicle, int WheelType) = (void(*)(Vehicle, int))&_SET_VEHICLE_WHEEL_TYPE;

	opd_s _SET_VEHICLE_TYRES_CAN_BURST = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_TYRES_CAN_BURST, TOC };
	void(*SET_VEHICLE_TYRES_CAN_BURST)(Vehicle vehicle, int WheelType) = (void(*)(Vehicle, int))&_SET_VEHICLE_TYRES_CAN_BURST;

	opd_s _SET_VEHICLE_WHEELS_CAN_BREAK = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_WHEELS_CAN_BREAK, TOC };
	void(*SET_VEHICLE_WHEELS_CAN_BREAK)(Vehicle vehicle, BOOL enabled) = (void(*)(Vehicle, BOOL))&_SET_VEHICLE_WHEELS_CAN_BREAK;


	opd_s _SET_VEHICLE_TYRE_SMOKE_COLOR = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_TYRE_SMOKE_COLOR, TOC };
	void(*SET_VEHICLE_TYRE_SMOKE_COLOR)(Vehicle vehicle, int r, int g, int b) = (void(*)(Vehicle, int, int, int))&_SET_VEHICLE_TYRE_SMOKE_COLOR;

	//opd_s _GET_VEHICLE_TYRE_SMOKE_COLOR = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_TYRE_SMOKE_COLOR, TOC };
	//void(*GET_VEHICLE_TYRE_SMOKE_COLOR)(Vehicle vehicle, int r, int g, int b) = (void(*)(Vehicle, int, int, int))&_GET_VEHICLE_TYRE_SMOKE_COLOR;
	
	opd_s _SET_VEHICLE_STRONG = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_STRONG, TOC };
	void(*SET_VEHICLE_STRONG)(Vehicle vehicle, BOOL enabled) = (void(*)(Vehicle, BOOL))&_SET_VEHICLE_STRONG;


	


	/*
	Tint:
	None - 0
	Pure Black - 1
	Dark Smoke - 2
	Light Smoke - 3
	Stock - 4
	Limo - 5
	Green - 6
	*/
	opd_s _SET_VEHICLE_WINDOW_TINT = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_WINDOW_TINT, TOC };
	void(*SET_VEHICLE_WINDOW_TINT)(Vehicle vehicle, int tint) = (void(*)(Vehicle, int))&_SET_VEHICLE_WINDOW_TINT;

	//opd_s _GET_VEHICLE_WINDOW_TINT = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_WINDOW_TINT, TOC };
	//int(*GET_VEHICLE_WINDOW_TINT)(Vehicle vehicle) = (int(*)(Vehicle))&_GET_VEHICLE_WINDOW_TINT;

	//opd_s _GET_NUM_VEHICLE_WINDOW_TINTS = { Addresses::Addresses_Natives::Vehicles_a::GET_NUM_VEHICLE_WINDOW_TINTS, TOC };
	//int(*GET_NUM_VEHICLE_WINDOW_TINTS)() = (int(*)())&_GET_NUM_VEHICLE_WINDOW_TINTS;


	//opd_s _SET_AIR_DRAG_MULTIPLIER_FOR_PLAYERS_VEHICLE = { Addresses::Addresses_Natives::Vehicles_a::SET_AIR_DRAG_MULTIPLIER_FOR_PLAYERS_VEHICLE, TOC };
	//void(*SET_AIR_DRAG_MULTIPLIER_FOR_PLAYERS_VEHICLE)(Player player, float multiplier) = (void(*)(Player, float))&_SET_AIR_DRAG_MULTIPLIER_FOR_PLAYERS_VEHICLE;



	opd_s _SET_VEHICLE_FORWARD_SPEED = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_FORWARD_SPEED, TOC };
	void(*SET_VEHICLE_FORWARD_SPEED)(Vehicle vehicle, float speed) = (void(*)(Vehicle, float))&_SET_VEHICLE_FORWARD_SPEED;

	//opd_s _GET_VEHICLE_MAX_SPEED = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_MAX_SPEED, TOC };
	//float(*GET_VEHICLE_MAX_SPEED)(Hash modelHash) = (float(*)(Hash))&_GET_VEHICLE_MAX_SPEED;

	//opd_s _GET_VEHICLE_ACCELERATION = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_ACCELERATION, TOC };
	//float(*GET_VEHICLE_ACCELERATION)(Any p0) = (float(*)(Any))&_GET_VEHICLE_ACCELERATION;

	//opd_s _GET_VEHICLE_MAX_TRACTION = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_MAX_TRACTION, TOC };
	//float(*GET_VEHICLE_MAX_TRACTION)(Any p0) = (float(*)(Any))&_GET_VEHICLE_MAX_TRACTION;

	//opd_s _GET_VEHICLE_MAX_BRAKING = { Addresses::Addresses_Natives::Vehicles_a::GET_VEHICLE_MAX_BRAKING, TOC };
	//float(*GET_VEHICLE_MAX_BRAKING)(Any p0) = (float(*)(Any))&_GET_VEHICLE_MAX_BRAKING;



	/*
	<1.0 - Decreased torque
	=1.0 - Default torque
	>1.0 - Increased torque

	Negative values will cause the vehicle to go backwards instead of forwards while accelerating.
	*/
	//opd_s _SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER, TOC };
	//void(*SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER)(Vehicle vehicle, float value) = (void(*)(Vehicle, float))&_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER;

	
	//opd_s _SET_VEHICLE_ENGINE_POWER_MULTIPLIER = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_ENGINE_POWER_MULTIPLIER, TOC };
	//void(*SET_VEHICLE_ENGINE_POWER_MULTIPLIER)(Vehicle vehicle, float value) = (void(*)(Vehicle, float))&_SET_VEHICLE_ENGINE_POWER_MULTIPLIER;

	

	// Colors
	opd_s _SET_VEHICLE_CUSTOM_PRIMARY_COLOUR = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR, TOC };
	void(*SET_VEHICLE_CUSTOM_PRIMARY_COLOUR)(Vehicle vehicle, int r, int g, int b) = (void(*)(Vehicle, int, int, int))&_SET_VEHICLE_CUSTOM_PRIMARY_COLOUR;

	opd_s _SET_VEHICLE_CUSTOM_SECONDARY_COLOUR = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR, TOC };
	void(*SET_VEHICLE_CUSTOM_SECONDARY_COLOUR)(Vehicle vehicle, int r, int g, int b) = (void(*)(Vehicle, int, int, int))&_SET_VEHICLE_CUSTOM_SECONDARY_COLOUR;





	
	// Lighting

	/*
	Sets the turn signal enabled for a vehicle.
	Set turnSignal to 1 for left light, 0 for right light.
	*/
	opd_s _SET_VEHICLE_INDICATOR_LIGHTS = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_INDICATOR_LIGHTS, TOC };
	void(*SET_VEHICLE_INDICATOR_LIGHTS)(Vehicle vehicle, int turnSignal, BOOL toggle) = (void(*)(Vehicle, int, BOOL))&_SET_VEHICLE_INDICATOR_LIGHTS;
	
	//opd_s _SET_VEHICLE_INTERIORLIGHT = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_INTERIORLIGHT, TOC };
	//void(*SET_VEHICLE_INTERIORLIGHT)(Vehicle vehicle, BOOL Toggle) = (void(*)(Vehicle, BOOL))&_SET_VEHICLE_INTERIORLIGHT;

	/*
	multiplier = 0.0 no lights
	multiplier = 1.0 default game value
	*/
	opd_s _SET_VEHICLE_LIGHT_MULTIPLIER = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_LIGHT_MULTIPLIER, TOC };
	void(*SET_VEHICLE_LIGHT_MULTIPLIER)(Vehicle vehicle, float multiplier) = (void(*)(Vehicle, float))&_SET_VEHICLE_LIGHT_MULTIPLIER;

	//opd_s _SET_VEHICLE_SEARCHLIGHT = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_SEARCHLIGHT, TOC };
	//void(*SET_VEHICLE_SEARCHLIGHT)(Vehicle vehicle, BOOL p1, BOOL p2) = (void(*)(Vehicle, BOOL, BOOL))&_SET_VEHICLE_SEARCHLIGHT;


	

	

	// Convertible Stuff
	//opd_s _DOES_VEHICLE_HAVE_ROOF = { Addresses::Addresses_Natives::Vehicles_a::DOES_VEHICLE_HAVE_ROOF, TOC };
	//BOOL(*DOES_VEHICLE_HAVE_ROOF)(Vehicle vehicle) = (BOOL(*)(Vehicle))&_DOES_VEHICLE_HAVE_ROOF;

	//opd_s _IS_VEHICLE_A_CONVERTIBLE = { Addresses::Addresses_Natives::Vehicles_a::IS_VEHICLE_A_CONVERTIBLE, TOC };
	//BOOL(*IS_VEHICLE_A_CONVERTIBLE)(Vehicle vehicle, BOOL p1) = (BOOL(*)(Vehicle, BOOL))&_IS_VEHICLE_A_CONVERTIBLE;

	/*
	Roof State
	0 = Up
	1 = Opening (Also can be Hard Top)
	2 = Down
	3 = Closing
	*/
	//opd_s _GET_CONVERTIBLE_ROOF_STATE = { Addresses::Addresses_Natives::Vehicles_a::GET_CONVERTIBLE_ROOF_STATE, TOC };
	//int(*GET_CONVERTIBLE_ROOF_STATE)(Vehicle vehicle) = (int(*)(Vehicle))&_GET_CONVERTIBLE_ROOF_STATE;

	//opd_s _LOWER_CONVERTIBLE_ROOF = { Addresses::Addresses_Natives::Vehicles_a::LOWER_CONVERTIBLE_ROOF, TOC };
	//void(*LOWER_CONVERTIBLE_ROOF)(Vehicle vehicle, BOOL p1) = (void(*)(Vehicle, BOOL))&_LOWER_CONVERTIBLE_ROOF;

	//opd_s _RAISE_CONVERTIBLE_ROOF = { Addresses::Addresses_Natives::Vehicles_a::RAISE_CONVERTIBLE_ROOF, TOC };
	//void(*RAISE_CONVERTIBLE_ROOF)(Vehicle vehicle, BOOL p1) = (void(*)(Vehicle, BOOL))&_RAISE_CONVERTIBLE_ROOF;

	//opd_s _SET_CONVERTIBLE_ROOF = { Addresses::Addresses_Natives::Vehicles_a::SET_CONVERTIBLE_ROOF, TOC };
	//void(*SET_CONVERTIBLE_ROOF)(Vehicle vehicle, BOOL p1) = (void(*)(Vehicle, BOOL))&_SET_CONVERTIBLE_ROOF;



	//opd_s _SET_VEHICLE_BURNOUT = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_BURNOUT, TOC };
	//void(*SET_VEHICLE_BURNOUT)(Vehicle vehicle, BOOL toggle) = (void(*)(Vehicle, BOOL))&_SET_VEHICLE_BURNOUT;

	opd_s _SET_VEHICLE_ON_GROUND_PROPERLY = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_ON_GROUND_PROPERLY, TOC };
	BOOL(*SET_VEHICLE_ON_GROUND_PROPERLY)(Vehicle vehicle) = (BOOL(*)(Vehicle))&_SET_VEHICLE_ON_GROUND_PROPERLY;



	//opd_s _SET_VEHICLE_REDUCE_GRIP = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_REDUCE_GRIP, TOC };
	//void(*SET_VEHICLE_REDUCE_GRIP)(Vehicle vehicle, BOOL toggle) = (void(*)(Vehicle, BOOL))&_SET_VEHICLE_REDUCE_GRIP;

	//opd_s _SET_VEHICLE_NEEDS_TO_BE_HOTWIRED = { Addresses::Addresses_Natives::Vehicles_a::SET_VEHICLE_NEEDS_TO_BE_HOTWIRED, TOC };
	//void(*SET_VEHICLE_NEEDS_TO_BE_HOTWIRED)(Vehicle vehicle, BOOL toggle) = (void(*)(Vehicle, BOOL))&_SET_VEHICLE_NEEDS_TO_BE_HOTWIRED;

	

	// Known Unknowns


	//opd_s _JITTER_VEHICLE = { Addresses::Addresses_Natives::Vehicles_a::JITTER_VEHICLE, TOC };
	//void(*JITTER_VEHICLE)(Vehicle vehicle, BOOL p1, float yaw, float pitch, float roll) = (void(*)(Vehicle, BOOL, float, float, float))&_JITTER_VEHICLE;

	
	


	//---------------------------------------------------------------------------------------------//


	
	//---------------------------------------------------------------------------------------------//
	// Weapons
	opd_s _SET_EXPLOSIVE_AMMO_THIS_FRAME = { Addresses::Addresses_Natives::Weapons_a::SET_EXPLOSIVE_AMMO_THIS_FRAME, TOC };
	void(*SET_EXPLOSIVE_AMMO_THIS_FRAME)(Player player) = (void(*)(Player))&_SET_EXPLOSIVE_AMMO_THIS_FRAME;

	opd_s _SET_FIRE_AMMO_THIS_FRAME = { Addresses::Addresses_Natives::Weapons_a::SET_FIRE_AMMO_THIS_FRAME, TOC };
	void(*SET_FIRE_AMMO_THIS_FRAME)(Player player) = (void(*)(Player))&_SET_FIRE_AMMO_THIS_FRAME;

	opd_s _SET_EXPLOSIVE_MELEE_THIS_FRAME = { Addresses::Addresses_Natives::Weapons_a::SET_EXPLOSIVE_MELEE_THIS_FRAME, TOC };
	void(*SET_EXPLOSIVE_MELEE_THIS_FRAME)(Player player) = (void(*)(Player))&_SET_EXPLOSIVE_MELEE_THIS_FRAME;

	//opd_s _ENABLE_LASER_SIGHT_RENDERING = { Addresses::Addresses_Natives::Misc_a::ENABLE_LASER_SIGHT_RENDERING, TOC };
	//void(*ENABLE_LASER_SIGHT_RENDERING)(BOOL toggle) = (void(*)(BOOL))&_ENABLE_LASER_SIGHT_RENDERING;

	opd_s _SET_PED_INFINITE_AMMO_CLIP = { Addresses::Addresses_Natives::Weapons_a::SET_PED_INFINITE_AMMO_CLIP, TOC };
	void(*SET_PED_INFINITE_AMMO_CLIP)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_PED_INFINITE_AMMO_CLIP;
	
	opd_s _SET_PED_INFINITE_AMMO_CLIP_ALT = { Addresses::Addresses_Natives::Weapons_a::SET_PED_INFINITE_AMMO_CLIP, TOC };
	void(*SET_PED_INFINITE_AMMO_CLIP_ALT)(uint PLAYER_ID, bool Enabled) = (void(*)(uint, bool))&_SET_PED_INFINITE_AMMO_CLIP_ALT;
	
	opd_s _SET_PED_INFINITE_AMMO = { Addresses::Addresses_Natives::Weapons_a::SET_PED_INFINITE_AMMO, TOC };
	void(*SET_PED_INFINITE_AMMO)(Ped ped, BOOL toggle, Hash weaponHash) = (void(*)(Ped, BOOL, Hash))&_SET_PED_INFINITE_AMMO;
	
	opd_s _REMOVE_ALL_PED_WEAPONS = { Addresses::Addresses_Natives::Weapons_a::REMOVE_ALL_PED_WEAPONS, TOC };
	void(*REMOVE_ALL_PED_WEAPONS)(int p1) = (void(*)(int))&_REMOVE_ALL_PED_WEAPONS;

	opd_s _GIVE_DELAYED_WEAPON_TO_PED ={ Addresses::Addresses_Natives::Weapons_a::GIVE_DELAYED_WEAPON_TO_PED, TOC };
	void(*GIVE_DELAYED_WEAPON_TO_PED)(Ped ped, Hash weaponHash, int time, BOOL equipNow) = (void(*)(Ped, Hash, int, BOOL))&_GIVE_DELAYED_WEAPON_TO_PED;
	
	opd_s _SET_PED_GADGET = { Addresses::Addresses_Natives::Peds_a::SET_PED_GADGET, TOC };
	void(*SET_PED_GADGET)(Ped ped, Hash gadgetHash, BOOL p2) = (void(*)(Ped, Hash, BOOL))&_SET_PED_GADGET;

	opd_s _SET_ENABLE_HANDCUFFS = { Addresses::Addresses_Natives::Peds_a::SET_ENABLE_HANDCUFFS, TOC };
	void(*SET_ENABLE_HANDCUFFS)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_ENABLE_HANDCUFFS;

	//opd_s _SET_ENABLE_BOUND_ANKLES = { Addresses::Addresses_Natives::Peds_a::SET_ENABLE_BOUND_ANKLES, TOC };
	//void(*SET_ENABLE_BOUND_ANKLES)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_ENABLE_BOUND_ANKLES;

	//opd_s _SET_ENABLE_PED_ENVEFF_SCALE = { Addresses::Addresses_Natives::Peds_a::SET_ENABLE_PED_ENVEFF_SCALE, TOC };
	//void(*SET_ENABLE_PED_ENVEFF_SCALE)(Ped ped, BOOL toggle) = (void(*)(Ped, BOOL))&_SET_ENABLE_PED_ENVEFF_SCALE;

	//opd_s _SET_PED_PINNED_DOWN = { Addresses::Addresses_Natives::Peds_a::SET_PED_PINNED_DOWN, TOC };
	//Any(*SET_PED_PINNED_DOWN)(Any p0, Any p1, Any p2) = (Any(*)(Any, Any, Any))&_SET_PED_PINNED_DOWN;

	

	//---------------------------------------------------------------------------------------------//



	//---------------------------------------------------------------------------------------------//
	// Phone

	//0 - Default phone / Michael's phone
	//1 - Trevor's phone
	//2 - Franklin's phone
	//4 - Prologue phone

	opd_s _CREATE_MOBILE_PHONE = { Addresses::Addresses_Natives::Objects_a::Phone_a::CREATE_MOBILE_PHONE, TOC };
	void(*CREATE_MOBILE_PHONE)(int phoneType) = (void(*)(int))&_CREATE_MOBILE_PHONE;
	
	opd_s _DESTROY_MOBILE_PHONE = { Addresses::Addresses_Natives::Objects_a::Phone_a::DESTROY_MOBILE_PHONE, TOC };
	void(*DESTROY_MOBILE_PHONE)() = (void(*)())&_DESTROY_MOBILE_PHONE;
	
	//opd_s _GET_MOBILE_PHONE_POSITION = { Addresses::Addresses_Natives::Objects_a::Phone_a::GET_MOBILE_PHONE_POSITION, TOC };
	//void(*GET_MOBILE_PHONE_POSITION)(Vector3 *position) = (void(*)(Vector3*))&_GET_MOBILE_PHONE_POSITION;
	
	opd_s _SET_MOBILE_PHONE_POSITION = { Addresses::Addresses_Natives::Objects_a::Phone_a::SET_MOBILE_PHONE_POSITION, TOC };
	void(*SET_MOBILE_PHONE_POSITION)(float posX, float posY, float posZ) = (void(*)(float, float, float))&_SET_MOBILE_PHONE_POSITION;
	
	//opd_s _SET_MOBILE_PHONE_RADIO_STATE = { Addresses::Addresses_Natives::Objects_a::Phone_a::SET_MOBILE_PHONE_RADIO_STATE, TOC };
	//void(*SET_MOBILE_PHONE_RADIO_STATE)(float scale) = (void(*)(float))&_SET_MOBILE_PHONE_RADIO_STATE;
	
	//opd_s _GET_MOBILE_PHONE_ROTATION = { Addresses::Addresses_Natives::Objects_a::Phone_a::GET_MOBILE_PHONE_ROTATION, TOC };
	//void(*GET_MOBILE_PHONE_ROTATION)(Vector3 *position) = (void(*)(Vector3*))&_GET_MOBILE_PHONE_ROTATION;
	
	//opd_s _SET_MOBILE_PHONE_ROTATION = { Addresses::Addresses_Natives::Objects_a::Phone_a::SET_MOBILE_PHONE_ROTATION, TOC };
	//void(*SET_MOBILE_PHONE_ROTATION)(float rotX, float rotY, float rotZ, Any p3) = (void(*)(float, float, float, Any))&_SET_MOBILE_PHONE_ROTATION;
	
	opd_s _SET_MOBILE_PHONE_SCALE = { Addresses::Addresses_Natives::Objects_a::Phone_a::SET_MOBILE_PHONE_SCALE, TOC };
	void(*SET_MOBILE_PHONE_SCALE)(float scale) = (void(*)(float))&_SET_MOBILE_PHONE_SCALE;
	
	opd_s _TASK_USE_MOBILE_PHONE = { Addresses::Addresses_Natives::Objects_a::Phone_a::TASK_USE_MOBILE_PHONE, TOC };
	void(*TASK_USE_MOBILE_PHONE)(Ped ped, int p1) = (void(*)(Ped, int))&_TASK_USE_MOBILE_PHONE;
	
	//opd_s _TASK_USE_MOBILE_PHONE_TIMED = { Addresses::Addresses_Natives::Objects_a::Phone_a::TASK_USE_MOBILE_PHONE_TIMED, TOC };
	//void(*TASK_USE_MOBILE_PHONE_TIMED)(Any p0, Any p1) = (void(*)(Any, Any))&_TASK_USE_MOBILE_PHONE_TIMED;
	
	//opd_s _PRELOAD_SCRIPT_PHONE_CONVERSATION = { Addresses::Addresses_Natives::Objects_a::Phone_a::PRELOAD_SCRIPT_PHONE_CONVERSATION, TOC };
	//void(*PRELOAD_SCRIPT_PHONE_CONVERSATION)(BOOL p0, BOOL p1) = (void(*)(BOOL, BOOL))&_PRELOAD_SCRIPT_PHONE_CONVERSATION;
	
	//opd_s _START_SCRIPT_PHONE_CONVERSATION = { Addresses::Addresses_Natives::Objects_a::Phone_a::START_SCRIPT_PHONE_CONVERSATION, TOC };
	//void(*START_SCRIPT_PHONE_CONVERSATION)(BOOL p0, BOOL p1) = (void(*)(BOOL, BOOL))&_START_SCRIPT_PHONE_CONVERSATION;
	
	//opd_s _IS_MOBILE_PHONE_CALL_ONGOING = { Addresses::Addresses_Natives::Objects_a::Phone_a::IS_MOBILE_PHONE_CALL_ONGOING, TOC };
	//bool(*IS_MOBILE_PHONE_CALL_ONGOING)() = (bool(*)())&_IS_MOBILE_PHONE_CALL_ONGOING;
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
	// Clear Items
	opd_s _CLEAR_AREA = { Addresses::Addresses_Natives::Area_a::CLEAR_AREA, TOC };
	void(*CLEAR_AREA)(float p0, float p1, float p2, float p3, BOOL p4, BOOL p5, BOOL p6, BOOL p7) = (void(*)(float, float, float, float, BOOL, BOOL, BOOL, BOOL))&_CLEAR_AREA;
	
	opd_s _CLEAR_HD_AREA = { Addresses::Addresses_Natives::Area_a::CLEAR_HD_AREA, TOC };
	void(*CLEAR_HD_AREA)() = (void(*)())&_CLEAR_HD_AREA;

	//opd_s _CLEAR_PED_NON_CREATION_AREA = { Addresses::Addresses_Natives::Area_a::CLEAR_PED_NON_CREATION_AREA, TOC };
	//void(*CLEAR_PED_NON_CREATION_AREA)() = (void(*)())&_CLEAR_PED_NON_CREATION_AREA;

	// Maybe wrong function args and type??
	//opd_s _CLEAR_UNSYNCED_PROJECTILES = { Addresses::Addresses_Natives::Area_a::CLEAR_UNSYNCED_PROJECTILES, TOC };
	//void(*CLEAR_UNSYNCED_PROJECTILES)() = (void(*)())&_CLEAR_UNSYNCED_PROJECTILES;
	
	opd_s _DISPLAY_AREA_NAME = { Addresses::Addresses_Natives::Area_a::DISPLAY_AREA_NAME, TOC };
	void(*DISPLAY_AREA_NAME)(BOOL toggle) = (void(*)(BOOL))&_DISPLAY_AREA_NAME;
	
	opd_s _CLEAR_AREA_OF_VEHICLES = { Addresses::Addresses_Natives::Area_a::CLEAR_AREA_OF_VEHICLES, TOC };
	void(*CLEAR_AREA_OF_VEHICLES)(float x, float y, float z, float radius, BOOL p4, BOOL p5, BOOL p6, BOOL p7, BOOL p8) = (void(*)(float, float, float, float, BOOL, BOOL, BOOL, BOOL, BOOL))&_CLEAR_AREA_OF_VEHICLES;
	
	//opd_s _CLEAR_ANGLED_AREA_OF_VEHICLES = { Addresses::Addresses_Natives::Area_a::CLEAR_ANGLED_AREA_OF_VEHICLES, TOC };
	//void(*CLEAR_ANGLED_AREA_OF_VEHICLES)(float p0, float p1, float p2, float p3, float p4, float p5, float p6, BOOL p7, BOOL p8, BOOL p9, BOOL p10, BOOL p11) = (void(*)(float, float, float, float, float, float,  float, BOOL, BOOL, BOOL, BOOL, BOOL))&_CLEAR_ANGLED_AREA_OF_VEHICLES;
	
	opd_s _CLEAR_AREA_OF_OBJECTS = { Addresses::Addresses_Natives::Area_a::CLEAR_AREA_OF_OBJECTS, TOC };
	void(*CLEAR_AREA_OF_OBJECTS)(float x, float y, float z, float radius, BOOL unk) = (void(*)(float, float, float, float, BOOL))&_CLEAR_AREA_OF_OBJECTS;
	
	opd_s _CLEAR_AREA_OF_PEDS = { Addresses::Addresses_Natives::Area_a::CLEAR_AREA_OF_PEDS, TOC };
	void(*CLEAR_AREA_OF_PEDS)(float x, float y, float z, float radius, BOOL unk) = (void(*)(float, float, float, float, BOOL))&_CLEAR_AREA_OF_PEDS;
	
	opd_s _CLEAR_AREA_OF_COPS = { Addresses::Addresses_Natives::Area_a::CLEAR_AREA_OF_COPS, TOC };
	void(*CLEAR_AREA_OF_COPS)(float x, float y, float z, float radius, BOOL unk) = (void(*)(float, float, float, float, BOOL))&_CLEAR_AREA_OF_COPS;
	
	opd_s _CLEAR_AREA_OF_PROJECTILES = { Addresses::Addresses_Natives::Area_a::CLEAR_AREA_OF_PROJECTILES, TOC };
	void(*CLEAR_AREA_OF_PROJECTILES)(float x, float y, float z, float radius, BOOL unk) = (void(*)(float, float, float, float, BOOL))&_CLEAR_AREA_OF_PROJECTILES;


	// used with 1,2,8,64,128 in the scripts
	opd_s _FORCE_CLEANUP = { Addresses::Addresses_Natives::Area_a::FORCE_CLEANUP, TOC };
	void(*FORCE_CLEANUP)(int cleanupType) = (void(*)(int))&_FORCE_CLEANUP;


	//---------------------------------------------------------------------------------------------//



	

	
	//---------------------------------------------------------------------------------------------//
	// Objects
	
	opd_s _CREATE_OBJECT = { Addresses::Addresses_Natives::Objects_a::CREATE_OBJECT, TOC };
	Object(*CREATE_OBJECT)(Hash modelHash, float x, float y, float z, BOOL networkHandle, BOOL createHandle, BOOL dynamic) = (Object(*)(Hash, float, float, float, BOOL, BOOL, BOOL))&_CREATE_OBJECT;
	
	opd_s _CREATE_OBJECT_ALT = { Addresses::Addresses_Natives::Objects_a::CREATE_OBJECT, TOC };
	Object(*CREATE_OBJECT_ALT)(Hash modelHash, float* coords, BOOL networkHandle, BOOL createHandle, BOOL dynamic) = (Object(*)(Hash, float*, BOOL, BOOL, BOOL))&_CREATE_OBJECT_ALT;
	
	//opd_s _CREATE_OBJECT_NO_OFFSET = { Addresses::Addresses_Natives::Objects_a::CREATE_OBJECT_NO_OFFSET, TOC };
	//Object(*CREATE_OBJECT_NO_OFFSET)(Hash objectHash, float posX, float posY, float posZ, BOOL p4, BOOL p5, BOOL p6) = (Object(*)(Hash, float, float, float, BOOL, BOOL, BOOL))&_CREATE_OBJECT_NO_OFFSET;
	
	opd_s _DELETE_OBJECT = { Addresses::Addresses_Natives::Objects_a::DELETE_OBJECT, TOC };
	void(*DELETE_OBJECT)(Object* object) = (void(*)(Object*))&_DELETE_OBJECT;
	
	//opd_s _SLIDE_OBJECT = { Addresses::Addresses_Natives::Objects_a::SLIDE_OBJECT, TOC };
	//BOOL(*SLIDE_OBJECT)(Any p0, float p1, float p2, float p3, float p4, float p5, float p6, BOOL p7) = (BOOL(*)(Any, float, float, float, float, float, float, BOOL))&_SLIDE_OBJECT;
	
	opd_s _PLACE_OBJECT_ON_GROUND_PROPERLY = { Addresses::Addresses_Natives::Objects_a::PLACE_OBJECT_ON_GROUND_PROPERLY, TOC };
	BOOL(*PLACE_OBJECT_ON_GROUND_PROPERLY)(Object object) = (BOOL(*)(Object))&_PLACE_OBJECT_ON_GROUND_PROPERLY;
	
	
	//---------------------------------------------------------------------------------------------//

	


	//---------------------------------------------------------------------------------------------//
	// World

	//opd_s _SET_NUMBER_OF_PARKED_VEHICLES = { Addresses::Addresses_Natives::World_a::SET_NUMBER_OF_PARKED_VEHICLES, TOC };
	//void(*SET_NUMBER_OF_PARKED_VEHICLES)(int value) = (void(*)(int))&_SET_NUMBER_OF_PARKED_VEHICLES;


	// Check If IPL Location Active
	opd_s _IS_IPL_ACTIVE = { Addresses::Addresses_Natives::World_a::IS_IPL_ACTIVE, TOC };
	BOOL(*IS_IPL_ACTIVE)(char* iplName) = (BOOL(*)(char*))&_IS_IPL_ACTIVE;

	// Request IPL Location
	opd_s _REQUEST_IPL = { Addresses::Addresses_Natives::World_a::REQUEST_IPL, TOC };
	void(*REQUEST_IPL)(char* iplName) = (void(*)(char*))&_REQUEST_IPL;

	// Remove IPL Location
	opd_s _REMOVE_IPL = { Addresses::Addresses_Natives::World_a::REMOVE_IPL, TOC };
	void(*REMOVE_IPL)(char* iplName) = (void(*)(char*))&_REMOVE_IPL;


	
	// level can be from 0 to 3
	//opd_s _SET_GRAVITY_LEVEL = { Addresses::Addresses_Natives::World_a::SET_GRAVITY_LEVEL, TOC };
	//void(*SET_GRAVITY_LEVEL)(int level) = (void(*)(int))&_SET_GRAVITY_LEVEL;
	

	//opd_s _MODIFY_WATER = { Addresses::Addresses_Natives::World_a::MODIFY_WATER, TOC };
	//void(*MODIFY_WATER)(float x, float y, float z, float height) = (void(*)(float, float, float, float))&_MODIFY_WATER;
	

	//opd_s _REMOVE_ALL_COVER_BLOCKING_AREAS = { Addresses::Addresses_Natives::World_a::REMOVE_ALL_COVER_BLOCKING_AREAS, TOC };
	//void(*REMOVE_ALL_COVER_BLOCKING_AREAS)() = (void(*)())&_REMOVE_ALL_COVER_BLOCKING_AREAS;
	//---------------------------------------------------------------------------------------------//

	
	//---------------------------------------------------------------------------------------------//
	// System
	//opd_s _GET_ALLOCATED_STACK_SIZE = { Addresses::Addresses_Natives::System_a::GET_ALLOCATED_STACK_SIZE, TOC };
	//int(*GET_ALLOCATED_STACK_SIZE)() = (int(*)())&_GET_ALLOCATED_STACK_SIZE;
	
	//opd_s _TERMINATE_THREAD = { Addresses::Addresses_Natives::System_a::TERMINATE_THREAD, TOC };
	//void(*TERMINATE_THREAD)(int id) = (void(*)(int))&_TERMINATE_THREAD;
	
	//opd_s _TERMINATE_THIS_THREAD = { Addresses::Addresses_Natives::System_a::TERMINATE_THIS_THREAD, TOC };
	//void(*TERMINATE_THIS_THREAD)() = (void(*)())&_TERMINATE_THIS_THREAD;
	
	opd_s _GET_ID_OF_THIS_THREAD = { Addresses::Addresses_Natives::System_a::GET_ID_OF_THIS_THREAD, TOC };
	int(*GET_ID_OF_THIS_THREAD)() = (int(*)())&_GET_ID_OF_THIS_THREAD;

	//opd_s _IS_THREAD_ACTIVE = { Addresses::Addresses_Natives::System_a::IS_THREAD_ACTIVE, TOC };
	//BOOL(*IS_THREAD_ACTIVE)(int threadId) = (BOOL(*)(int))&_IS_THREAD_ACTIVE;

	//opd_s _SET_DEBUG_LINES_AND_SPHERES_DRAWING_ACTIVE = { Addresses::Addresses_Natives::System_a::SET_DEBUG_LINES_AND_SPHERES_DRAWING_ACTIVE, TOC };
	//void(*SET_DEBUG_LINES_AND_SPHERES_DRAWING_ACTIVE)(BOOL enabled) = (void(*)(BOOL))&_SET_DEBUG_LINES_AND_SPHERES_DRAWING_ACTIVE;
	

	//opd_s _GET_ALLOCATED_STACK_SIZE = { Addresses::Addresses_Natives::System_a::GET_ALLOCATED_STACK_SIZE, TOC };
	//int(*GET_ALLOCATED_STACK_SIZE)() = (int(*)())&_GET_ALLOCATED_STACK_SIZE;

	//opd_s __GET_FREE_STACK_SLOTS_COUNT = { Addresses::Addresses_Natives::System_a::_GET_FREE_STACK_SLOTS_COUNT, TOC };
	//int(*_GET_FREE_STACK_SLOTS_COUNT)(int stackSize) = (int(*)(int))&__GET_FREE_STACK_SLOTS_COUNT;

	//opd_s _SET_BIT = { Addresses::Addresses_Natives::System_a::SET_BIT, TOC };
	//void(*SET_BIT)(int *var, int bit) = (void(*)(int*, int))&_SET_BIT;

	opd_s _SET_BIT = { Addresses::Addresses_Natives::Misc_a::SET_BIT, TOC };
	void(*SET_BIT)(int var, int bit) = (void(*)(int, int))&_SET_BIT;

	//opd_s _GET_BITS_IN_RANGE = { Addresses::Addresses_Natives::System_a::GET_BITS_IN_RANGE, TOC };
	//void(*GET_BITS_IN_RANGE)(Any p0, Any p1, Any p2) = (void(*)(Any, Any, Any))&_GET_BITS_IN_RANGE;

	//opd_s _SET_BITS_IN_RANGE = { Addresses::Addresses_Natives::System_a::SET_BITS_IN_RANGE, TOC };
	//void(*SET_BITS_IN_RANGE)(Any *p0, Any p1, Any p2, Any p3) = (void(*)(Any*, Any, Any, Any))&_SET_BITS_IN_RANGE;

	//opd_s _CLEAR_BIT = { Addresses::Addresses_Natives::System_a::CLEAR_BIT, TOC };
	//void(*CLEAR_BIT)(int *var, int bit) = (void(*)(int*, int))&_CLEAR_BIT;

	opd_s _SET_CREDITS_ACTIVE = { Addresses::Addresses_Natives::System_a::SET_CREDITS_ACTIVE, TOC };
	void(*SET_CREDITS_ACTIVE)(BOOL toggle) = (void(*)(BOOL))&_SET_CREDITS_ACTIVE;

	//opd_s _PLAY_END_CREDITS_MUSIC = { Addresses::Addresses_Natives::System_a::PLAY_END_CREDITS_MUSIC, TOC };
	//void(*PLAY_END_CREDITS_MUSIC)(BOOL p0) = (void(*)(BOOL))&_PLAY_END_CREDITS_MUSIC;

	//opd_s _DO_SCREEN_FADE_OUT = { Addresses::Addresses_Natives::Misc_a::DO_SCREEN_FADE_OUT, TOC };
	//void(*DO_SCREEN_FADE_OUT)(int duration) = (void(*)(int))&_DO_SCREEN_FADE_OUT;

	//opd_s _DO_SCREEN_FADE_IN = { Addresses::Addresses_Natives::Misc_a::DO_SCREEN_FADE_IN, TOC };
	//void(*DO_SCREEN_FADE_IN)(int duration) = (void(*)(int))&_DO_SCREEN_FADE_IN;

	
	
	
	//---------------------------------------------------------------------------------------------//



	//---------------------------------------------------------------------------------------------//
	// Teleport
	opd_s _GET_CLOSEST_VEHICLE = { Addresses::Addresses_Natives::Teleport_a::GET_CLOSEST_VEHICLE, TOC };
	int(*GET_CLOSEST_VEHICLE)(float* coords, float unk, int unk2, int unk3) = (int(*)(float*, float, int, int))&_GET_CLOSEST_VEHICLE;
	
	opd_s _SET_PED_INTO_VEHICLE = { Addresses::Addresses_Natives::Teleport_a::SET_PED_INTO_VEHICLE, TOC };
	void(*SET_PED_INTO_VEHICLE)(int PedID, int VehID, int seat) = (void(*)(int, int, int))&_SET_PED_INTO_VEHICLE;
	//---------------------------------------------------------------------------------------------//
	

	
	//---------------------------------------------------------------------------------------------//
	// Math

	// Square Root
	//opd_s _SQRT = { Addresses::Addresses_Natives::Math_a::SQRT, TOC };
	//void(*SQRT)(float value) = (void(*)(float))&_SQRT;
	//---------------------------------------------------------------------------------------------//


	//---------------------------------------------------------------------------------------------//
	// Other Misc

	

	//opd_s _SET_SRL_TIME = { Addresses::Addresses_Natives::Misc_a::SET_SRL_TIME, TOC };
	//void(*SET_SRL_TIME)(float p0) = (void(*)(float))&_SET_SRL_TIME;

	//opd_s _BEGIN_SRL = { Addresses::Addresses_Natives::Misc_a::BEGIN_SRL, TOC };
	//void(*BEGIN_SRL)() = (void(*)())&_BEGIN_SRL;

	//opd_s _END_SRL = { Addresses::Addresses_Natives::Misc_a::END_SRL, TOC };
	//void(*END_SRL)() = (void(*)())&_END_SRL;
	
	//opd_s _PREFETCH_SRL = { Addresses::Addresses_Natives::Misc_a::PREFETCH_SRL, TOC };
	//void(*PREFETCH_SRL)(Any* p0) = (void(*)(Any*))&_PREFETCH_SRL;
	
	//opd_s _IS_SRL_LOADED = { Addresses::Addresses_Natives::Misc_a::IS_SRL_LOADED, TOC };
	//BOOL(*IS_SRL_LOADED)() = (BOOL(*)())&_IS_SRL_LOADED;
	


	// Bones
	opd_s _GET_PED_BONE_COORDS = { Addresses::Addresses_Natives::Peds_a::GET_PED_BONE_COORDS, TOC };
	Vector3(*GET_PED_BONE_COORDS)(Ped ped, int boneId, float offsetX, float offsetY, float offsetZ) = (Vector3(*)(Ped, int, float, float, float))&_GET_PED_BONE_COORDS;
	
	opd_s _GET_PED_BONE_INDEX = { Addresses::Addresses_Natives::Peds_a::GET_PED_BONE_INDEX, TOC };
	int(*GET_PED_BONE_INDEX)(Ped ped, int boneId) = (int(*)(Ped, int))&_GET_PED_BONE_INDEX;
	


	/*
	This function casts a ray from Point1 to Point2 and returns it's ray handle. A simple ray cast will 'shoot' a line from point A to point B, and return whether or not the ray reached it's destination or if it hit anything and if it did hit anything, will return the handle of what it hit (entity handle) and coordinates of where the ray reached.

	You can use _GET_RAYCAST_RESULT to get the result of the raycast

	Entity is an entity to ignore, such as the player.

	Flags are intersection bit flags. They tell the ray what to care about and what not to care about when casting. Passing -1 will intersect with everything, presumably.

	Flags:
	1: Intersect with map
	2: Intersect with mission entities? (includes train)
	4: Intersect with peds? (same as 8)
	8: Intersect with peds? (same as 4)
	10: vehicles
	16: Intersect with objects
	19: Unkown
	32: Unknown
	64: Unknown
	128: Unknown
	256: Intersect with vegetation (plants, coral. trees not included)
	512: Unknown
	*/
	//opd_s __CAST_RAY_POINT_TO_POINT = { Addresses::Addresses_Natives::Misc_a::_CAST_RAY_POINT_TO_POINT, TOC };
	//float(*_CAST_RAY_POINT_TO_POINT)(float startRange, float endRange) = (float(*)(float, float))&__CAST_RAY_POINT_TO_POINT;

	//opd_s _CAST_RAY_POINT_TO_POINT = { Addresses::Addresses_Natives::Misc_a::CAST_RAY_POINT_TO_POINT, TOC };
	//int(*CAST_RAY_POINT_TO_POINT)(float x1, float y1, float z1, float x2, float y2, float z2, int flags, Entity entity, int p8) = (int(*)(float, float, float, float, float, float, int, Entity, int))&_CAST_RAY_POINT_TO_POINT;

	/*
	_0x7EE9F5D83DD4F90E

	Returns a ray (?) going from x1, y1, z1 to x2, y2, z2.
	entity = 0 most of the time.
	p8 = 7 most of the time.

	Result of this function is passed to WORLDPROBE::0x3D87450E15D98694 as a first argument.
	*/



	


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

	

	// Coords Stuff
	//opd_s _GET_STREET_NAME_AT_COORD = { Addresses::Addresses_Natives::Misc_a::GET_STREET_NAME_AT_COORD, TOC };
	//void(*GET_STREET_NAME_AT_COORD)(float x, float y, float z, Hash *streetName, Hash *crossingRoad) = (void(*)(float, float, float, Hash*, Hash*))&_GET_STREET_NAME_AT_COORD;

	//opd_s _GENERATE_DIRECTIONS_TO_COORD = { Addresses::Addresses_Natives::Misc_a::GENERATE_DIRECTIONS_TO_COORD, TOC };
	//Any(*GENERATE_DIRECTIONS_TO_COORD)(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6) = (Any(*)(Any, Any, Any, Any, Any, Any, Any))&_GENERATE_DIRECTIONS_TO_COORD;
	
	


	 
	//opd_s __SET_BLACKOUT = { (Hash)0x1268615ACE24D504, TOC };
	//void(*_SET_BLACKOUT)(BOOL enable) = (void(*)(BOOL))&__SET_BLACKOUT;
	
	opd_s _SET_BLACKOUT = { Addresses::Addresses_Natives::Misc_a::SET_BLACKOUT, TOC };
	void(*SET_BLACKOUT)(BOOL enable) = (void(*)(BOOL))&_SET_BLACKOUT;
	
	//opd_s _DO_AUTO_SAVE = { Addresses::Addresses_Natives::Misc_a::DO_AUTO_SAVE, TOC };
	//void(*DO_AUTO_SAVE)() = (void(*)())&_DO_AUTO_SAVE;
	
	//opd_s _IS_AUTO_SAVE_IN_PROGRESS = { Addresses::Addresses_Natives::Misc_a::IS_AUTO_SAVE_IN_PROGRESS, TOC };
	//BOOL(*IS_AUTO_SAVE_IN_PROGRESS)() = (BOOL(*)())&_IS_AUTO_SAVE_IN_PROGRESS;
	
	//opd_s _STOP_ALL_ALARMS = { Addresses::Addresses_Natives::Misc_a::STOP_ALL_ALARMS, TOC };
	//void(*STOP_ALL_ALARMS)(BOOL p0) = (void(*)(BOOL))&_STOP_ALL_ALARMS;
	
	opd_s _STOP_CUTSCENE_IMMEDIATELY = { Addresses::Addresses_Natives::Misc_a::STOP_CUTSCENE_IMMEDIATELY, TOC };
	void(*STOP_CUTSCENE_IMMEDIATELY)() = (void(*)())&_STOP_CUTSCENE_IMMEDIATELY;

	//opd_s _IS_TENNIS_MODE = { Addresses::Addresses_Natives::Misc_a::IS_TENNIS_MODE, TOC };
	//void(*IS_TENNIS_MODE)(Any p0) = (void(*)(Any))&_IS_TENNIS_MODE;

	//opd_s _ENABLE_TENNIS_MODE = { Addresses::Addresses_Natives::Misc_a::ENABLE_TENNIS_MODE, TOC };
	//void(*ENABLE_TENNIS_MODE)(Ped ped, BOOL p0, BOOL p1) = (void(*)(Ped, BOOL, BOOL))&_ENABLE_TENNIS_MODE;

	//opd_s _SITTING_TV = { Addresses::Addresses_Natives::Misc_a::SITTING_TV, TOC };
	//void(*SITTING_TV)(Any p0) = (void(*)(Any))&_SITTING_TV;


	// Pause Game
	opd_s _SET_GAME_PAUSED = { Addresses::Addresses_Natives::System_a::SET_GAME_PAUSED, TOC };
	void(*SET_GAME_PAUSED)(BOOL toggle) = (void(*)(BOOL))&_SET_GAME_PAUSED;

	//opd_s _GET_PAUSE_MENU_STATE = { Addresses::Addresses_Natives::System_a::GET_PAUSE_MENU_STATE, TOC };
	//Any(*GET_PAUSE_MENU_STATE)() = (Any(*)())&_GET_PAUSE_MENU_STATE;
	
	//opd_s _IS_PAUSE_MENU_ACTIVE = { Addresses::Addresses_Natives::System_a::IS_PAUSE_MENU_ACTIVE, TOC };
	//BOOL(*IS_PAUSE_MENU_ACTIVE)() = (BOOL(*)())&_IS_PAUSE_MENU_ACTIVE;
	
	//opd_s _IS_PAUSE_MENU_RESTARTING = { Addresses::Addresses_Natives::System_a::IS_PAUSE_MENU_RESTARTING, TOC };
	//BOOL(*IS_PAUSE_MENU_RESTARTING)() = (BOOL(*)())&_IS_PAUSE_MENU_RESTARTING;
	
	//opd_s _CLEAR_PED_IN_PAUSE_MENU = { Addresses::Addresses_Natives::System_a::CLEAR_PED_IN_PAUSE_MENU, TOC };
	//void(*CLEAR_PED_IN_PAUSE_MENU)() = (void(*)())&_CLEAR_PED_IN_PAUSE_MENU;
	
	//opd_s _GIVE_PED_TO_PAUSE_MENU = { Addresses::Addresses_Natives::System_a::GIVE_PED_TO_PAUSE_MENU, TOC };
	//void(*GIVE_PED_TO_PAUSE_MENU)(Any p0, Any p1) = (void(*)(Any, Any))&_GIVE_PED_TO_PAUSE_MENU;
	

	
	// Mission Stuff
	opd_s _GET_MISSION_FLAG = { Addresses::Addresses_Natives::Mission_a::GET_MISSION_FLAG, TOC };
	BOOL(*GET_MISSION_FLAG)() = (BOOL(*)())&_GET_MISSION_FLAG;
	
	opd_s _SET_MISSION_FLAG = { Addresses::Addresses_Natives::Mission_a::SET_MISSION_FLAG, TOC };
	void(*SET_MISSION_FLAG)(BOOL p0) = (void(*)(BOOL))&_SET_MISSION_FLAG;

	//opd_s _IS_MISSION_COMPLETE_PLAYING = { Addresses::Addresses_Natives::Mission_a::IS_MISSION_COMPLETE_PLAYING, TOC };
	//BOOL(*IS_MISSION_COMPLETE_PLAYING)() = (BOOL(*)())&_IS_MISSION_COMPLETE_PLAYING;
	
	//opd_s _NETWORK_SET_MISSION_FINISHED = { Addresses::Addresses_Natives::Mission_a::NETWORK_SET_MISSION_FINISHED, TOC };
	//void(*NETWORK_SET_MISSION_FINISHED)() = (void(*)())&_NETWORK_SET_MISSION_FINISHED;



	
	opd_s _SET_TIMECYCLE_MODIFIER = { Addresses::Addresses_Natives::Player_a::SET_TIMECYCLE_MODIFIER, TOC };
	void(*SET_TIMECYCLE_MODIFIER)(const char *p1) = (void(*)(const char*))&_SET_TIMECYCLE_MODIFIER;

	opd_s _SET_TIMECYCLE_MODIFIER_STRENGTH = { Addresses::Addresses_Natives::Player_a::SET_TIMECYCLE_MODIFIER_STRENGTH, TOC };
	void(*SET_TIMECYCLE_MODIFIER_STRENGTH)(float p0) = (void(*)(float))&_SET_TIMECYCLE_MODIFIER_STRENGTH;

	opd_s _CLEAR_TIMECYCLE_MODIFIER = { Addresses::Addresses_Natives::Player_a::CLEAR_TIMECYCLE_MODIFIER, TOC };
	void(*CLEAR_TIMECYCLE_MODIFIER)() = (void(*)())&_CLEAR_TIMECYCLE_MODIFIER;


	//opd_s _PUSH_TIMECYCLE_MODIFIER = { Addresses::Addresses_Natives::Player_a::PUSH_TIMECYCLE_MODIFIER, TOC };
	//void(*PUSH_TIMECYCLE_MODIFIER)() = (void(*)())&_PUSH_TIMECYCLE_MODIFIER;

	//opd_s _POP_TIMECYCLE_MODIFIER = { Addresses::Addresses_Natives::Player_a::POP_TIMECYCLE_MODIFIER, TOC };
	//void(*POP_TIMECYCLE_MODIFIER)() = (void(*)())&_POP_TIMECYCLE_MODIFIER;

	

	opd_s _SHUTDOWN_AND_LAUNCH_SINGLE_PLAYER_GAME = { Addresses::Addresses_Natives::System_a::SHUTDOWN_AND_LAUNCH_SINGLE_PLAYER_GAME, TOC };
	void(*SHUTDOWN_AND_LAUNCH_SINGLE_PLAYER_GAME)() = (void(*)())&_SHUTDOWN_AND_LAUNCH_SINGLE_PLAYER_GAME;

	//opd_s _RESTART_SCRIPTED_CONVERSATION = { Addresses::Addresses_Natives::System_a::RESTART_SCRIPTED_CONVERSATION, TOC };
	//void(*RESTART_SCRIPTED_CONVERSATION)() = (void(*)())&_RESTART_SCRIPTED_CONVERSATION;

	//opd_s _PAUSE_SCRIPTED_CONVERSATION = { Addresses::Addresses_Natives::System_a::PAUSE_SCRIPTED_CONVERSATION, TOC };
	//void(*PAUSE_SCRIPTED_CONVERSATION)(BOOL p0) = (void(*)(BOOL))&_PAUSE_SCRIPTED_CONVERSATION;

	//opd_s _SHUTDOWN_LOADING_SCREEN = { Addresses::Addresses_Natives::System_a::SHUTDOWN_LOADING_SCREEN, TOC };
	//void(*SHUTDOWN_LOADING_SCREEN)() = (void(*)())&_SHUTDOWN_LOADING_SCREEN;

	// Skip Conversations
	opd_s _SKIP_TO_NEXT_SCRIPTED_CONVERSATION_LINE = { Addresses::Addresses_Natives::System_a::SKIP_TO_NEXT_SCRIPTED_CONVERSATION_LINE, TOC };
	void(*SKIP_TO_NEXT_SCRIPTED_CONVERSATION_LINE)() = (void(*)())&_SKIP_TO_NEXT_SCRIPTED_CONVERSATION_LINE;



	// Random Numbers (Not Using This)
	//opd_s _irand = { 0x000000, TOC };
	//int(*irand)(int min, int max) = (int(*)(int, int))&_irand;
	//---------------------------------------------------------------------------------------------//




	// Unknown Addresses For Future Use

	//void _TOGGLE_SNOW_VEHICLE_TRACKS(BOOL toggle) // 0x4CC7F0FEA5283FE0
	//void _TOGGLE_SNOW_PED_FOOT_TRACKS(BOOL toggle) // 0xAEEDAD1420C65CC0


	
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

	/*
	float* get_entity_coords_float(uint pedID)
	{
		entityCoords(0x10030000, pedID); //0x10030000 is free memory!
		return ReadFloat(0x10030000, 3);
	}
	*/

	/*
	float* TPToClient(int client)
	{
	entityCoords(0x10030000, GET_PLAYER_PED(client));
	return ReadFloat(0x10030000, 3);
	}
	*/
	
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


