#ifndef __BUTTONS_H
#define __BUTTONS_H

#include "natives.h"

using namespace Natives;

namespace Buttons
{
	int Button_CROSS = 0xC1,
		Button_CIRCLE = 0xC3,
		Button_SQUARE = 0xC2,
		Button_TRIANGLE = 0xC0,
		//Button_BACK = 0xBF,
		Button_L1 = 0xC4,
		Button_L2 = 0xC6,
		Button_L3 = 0xC8,
		Button_R1 = 0xC5,
		Button_R2 = 0xC7,
		Button_R3 = 0xC9,
		Button_R3_Down = 0xBF,
		Dpad_Up = 0xCA,
		Dpad_Down = 0xCB,
		Dpad_Left = 0xCC,
		Dpad_Right = 0xCD;

		// Analog Sticks

		// Left Analog X-Axis (188 = INPUT_SCRIPT_LEFT_AXIS_X)
		// 0 = Fully left 
		// 127 = Centered 
		// 254 = Fully right
		int AnalogLeftXMaxLeft = GET_CONTROL_VALUE(0, 188);
		int AnalogLeftXCenter = GET_CONTROL_VALUE(127, 188);
		int AnalogLeftXMaxRight = GET_CONTROL_VALUE(254, 188);

		// Left Analog Y-Axis (189 = INPUT_SCRIPT_LEFT_AXIS_Y)
		// 0 = Fully up 
		// 127 = Centered 
		// 254 = Fully down
		int AnalogLeftYMaxUp = GET_CONTROL_VALUE(0, 189);
		int AnalogLeftYCenter = GET_CONTROL_VALUE(127, 189);
		int AnalogLeftYMaxDown = GET_CONTROL_VALUE(254, 189);

		// Right Analog X-Axis (190 = INPUT_SCRIPT_RIGHT_AXIS_X)
		// 0 = Fully left 
		// 127 = Centered 
		// 254 = Fully right
		int AnalogRightXMaxLeft = GET_CONTROL_VALUE(0, 190);
		int AnalogRightXCenter = GET_CONTROL_VALUE(127, 190);
		int AnalogRightXMaxRight = GET_CONTROL_VALUE(254, 190);

		// Right Analog Y-Axis (191 = INPUT_SCRIPT_RIGHT_AXIS_Y)
		// 0 = Fully up 
		// 127 = Centered 
		// 254 = Fully down
		int AnalogRightYMaxUp = GET_CONTROL_VALUE(0, 191);
		int AnalogRightYCenter = GET_CONTROL_VALUE(127, 191);
		int AnalogRightYMaxDown = GET_CONTROL_VALUE(254, 191);

	

	bool isPressed(int Button)
	{
		return IS_CONTROL_PRESSED(0, Button);
	}

	bool isJustPressed(int Button)
	{
		return IS_DISABLED_CONTROL_JUST_PRESSED(0, Button);
	}

	bool isReleased(int Button)
	{
		return IS_CONTROL_RELEASED(0, Button);
	}

	bool isJustReleased(int Button)
	{
		return IS_CONTROL_JUST_RELEASED(0, Button);
	}

	bool isDown(int Button)
	{
		return IS_DISABLED_CONTROL_PRESSED(0, Button);
	}


	// Toggle Button Controls
	void ToggleControls(int state, int input)
	{
		SET_INPUT_EXCLUSIVE(state, input);
		DISABLE_CONTROL_ACTION(state, input);
	}



	//-------------------------------------------------------------------------
	// Disable Controls
	void DisableControlsDpad()
	{
		SET_INPUT_EXCLUSIVE(0, Buttons::Dpad_Up);
		SET_INPUT_EXCLUSIVE(0, Buttons::Dpad_Down);
		SET_INPUT_EXCLUSIVE(0, Buttons::Dpad_Left);
		SET_INPUT_EXCLUSIVE(0, Buttons::Dpad_Right);

		DISABLE_CONTROL_ACTION(0, Buttons::Dpad_Up);
		DISABLE_CONTROL_ACTION(0, Buttons::Dpad_Down);
		DISABLE_CONTROL_ACTION(0, Buttons::Dpad_Left);
		DISABLE_CONTROL_ACTION(0, Buttons::Dpad_Right);
	}

	void DisableControlsThumbsticks()
	{
		//SET_INPUT_EXCLUSIVE(0, Buttons::Button_L3_Down);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_R3_Down);

		//DISABLE_CONTROL_ACTION(0, Buttons::Button_L3_Down);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_R3_Down);
	}

	void DisableControlsButtons()
	{
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_CIRCLE);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_CROSS);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_SQUARE);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_TRIANGLE);

		DISABLE_CONTROL_ACTION(0, Buttons::Button_CIRCLE);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_CROSS);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_SQUARE);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_TRIANGLE);
	}

	void DisableControlsTriggers()
	{
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_L1);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_L2);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_L3);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_R1);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_R2);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_R3);

		DISABLE_CONTROL_ACTION(0, Buttons::Button_L1);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_L2);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_L3);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_R1);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_R2);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_R3);
	}

	void DisableControlsAll()
	{
		SET_INPUT_EXCLUSIVE(0, Buttons::Dpad_Up);
		SET_INPUT_EXCLUSIVE(0, Buttons::Dpad_Down);
		SET_INPUT_EXCLUSIVE(0, Buttons::Dpad_Left);
		SET_INPUT_EXCLUSIVE(0, Buttons::Dpad_Right);
		
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_R3_Down);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_CIRCLE);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_CROSS);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_SQUARE);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_TRIANGLE);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_L1);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_L2);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_L3);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_R1);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_R2);
		SET_INPUT_EXCLUSIVE(0, Buttons::Button_R3);

		DISABLE_CONTROL_ACTION(0, Buttons::Dpad_Up);
		DISABLE_CONTROL_ACTION(0, Buttons::Dpad_Down);
		DISABLE_CONTROL_ACTION(0, Buttons::Dpad_Left);
		DISABLE_CONTROL_ACTION(0, Buttons::Dpad_Right);
		
		DISABLE_CONTROL_ACTION(0, Buttons::Button_R3_Down);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_CIRCLE);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_CROSS);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_SQUARE);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_TRIANGLE);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_L1);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_L2);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_L3);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_R1);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_R2);
		DISABLE_CONTROL_ACTION(0, Buttons::Button_R3);
	}
	//-------------------------------------------------------------------------


	//-------------------------------------------------------------------------
	// Enable Controls
	void EnableControlsDpad()
	{
		SET_INPUT_EXCLUSIVE(1, Buttons::Dpad_Up);
		SET_INPUT_EXCLUSIVE(1, Buttons::Dpad_Down);
		SET_INPUT_EXCLUSIVE(1, Buttons::Dpad_Left);
		SET_INPUT_EXCLUSIVE(1, Buttons::Dpad_Right);

		DISABLE_CONTROL_ACTION(1, Buttons::Dpad_Up);
		DISABLE_CONTROL_ACTION(1, Buttons::Dpad_Down);
		DISABLE_CONTROL_ACTION(1, Buttons::Dpad_Left);
		DISABLE_CONTROL_ACTION(1, Buttons::Dpad_Right);
	}

	void EnableControlsThumbsticks()
	{
		//SET_INPUT_EXCLUSIVE(1, Buttons::Button_L3_Down);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_R3_Down);

		//DISABLE_CONTROL_ACTION(1, Buttons::Button_L3_Down);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_R3_Down);
	}

	void EnableControlsButtons()
	{
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_CIRCLE);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_CROSS);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_SQUARE);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_TRIANGLE);

		DISABLE_CONTROL_ACTION(1, Buttons::Button_CIRCLE);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_CROSS);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_SQUARE);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_TRIANGLE);
	}

	void EnableControlsTriggers()
	{
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_L1);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_L2);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_L3);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_R1);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_R2);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_R3);

		DISABLE_CONTROL_ACTION(1, Buttons::Button_L1);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_L2);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_L3);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_R1);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_R2);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_R3);
	}

	void EnableControlsAll()
	{
		SET_INPUT_EXCLUSIVE(1, Buttons::Dpad_Up);
		SET_INPUT_EXCLUSIVE(1, Buttons::Dpad_Down);
		SET_INPUT_EXCLUSIVE(1, Buttons::Dpad_Left);
		SET_INPUT_EXCLUSIVE(1, Buttons::Dpad_Right);
		
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_R3_Down);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_CIRCLE);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_CROSS);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_SQUARE);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_TRIANGLE);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_L1);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_L2);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_L3);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_R1);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_R2);
		SET_INPUT_EXCLUSIVE(1, Buttons::Button_R3);

		DISABLE_CONTROL_ACTION(1, Buttons::Dpad_Up);
		DISABLE_CONTROL_ACTION(1, Buttons::Dpad_Down);
		DISABLE_CONTROL_ACTION(1, Buttons::Dpad_Left);
		DISABLE_CONTROL_ACTION(1, Buttons::Dpad_Right);
		
		DISABLE_CONTROL_ACTION(1, Buttons::Button_R3_Down);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_CIRCLE);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_CROSS);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_SQUARE);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_TRIANGLE);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_L1);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_L2);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_L3);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_R1);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_R2);
		DISABLE_CONTROL_ACTION(1, Buttons::Button_R3);
	}
	//-------------------------------------------------------------------------





};


namespace Hotkeys
{
	

	//




};


#endif

