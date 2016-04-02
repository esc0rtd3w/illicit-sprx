#ifndef __KEYBOARD_H
#define __KEYBOARD_H



#include "hud.h"
#include "misc.h"
#include "natives.h"

using namespace Hud;


/*
namespace Keyboard_OSK
{

	//char* resultOSK;
	int updateOSK;

	char* oskResult;
	char* GetKeyboardInput(int maxLength)
	{
		DISPLAY_ONSCREEN_KEYBOARD(0, "PM_NAME_CHALL", "", "", "", "", "", maxLength);
		
		sleep(500);
		while (true)
		{
			if (!UPDATE_ONSCREEN_KEYBOARD())
			{
				break;
				sleep(100);
			}
		}
		
		//oskResult = GET_ONSCREEN_KEYBOARD_RESULT();
		//return oskResult;
		return GET_ONSCREEN_KEYBOARD_RESULT();
	}


	void KeyboardDisplayTest(int dummy)
	{
		char* Response = GET_ONSCREEN_KEYBOARD_RESULT();
		DISPLAY_ONSCREEN_KEYBOARD(0, "PM_NAME_CHALL", "", "", "", "", "", 40);
		PrintText(Response, 3000);
	}


	
	// Onscreen Keyboard
	bool isKeyboardActiveNow = false;
	//char* resultOSK = GET_ONSCREEN_KEYBOARD_RESULT();
	bool isKeyboardActiveT = false;
	void ToggleKeyboard(int dummy)
	{
		isKeyboardActiveT = !isKeyboardActiveT;
		isKeyboardActive = isKeyboardActiveT;
		//MsgToggleDefault("On-Screen Keyboard", isKeyboardActiveT);
		//char keyTest[32];
		//sprintf(keyTest, GET_ONSCREEN_KEYBOARD_RESULT());
		//PrintText(keyTest, 3000);
	}


};

*/


#endif


