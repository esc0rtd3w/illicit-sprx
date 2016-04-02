/*


DO NOT EXCEED ~628KB / ~650KB IN SPRX FINAL BUILD SIZE OR ENCOUNTER INFINITE LOADING SCREEN!
WILL GET EXACT SIZE IN THE FUTURE!!!


*/


// Include this containing all needed headers
#include "includes.h"
#include <sys/syscall.h>

// Include Headers
#include "addresses.h"
//#include "anti.h"
#include "buttons.h"
#include "colors.h"
#include "core.h"
#include "functions.h"
#include "hook.h"
#include "hud.h"
#include "licensing.h"
#include "loops.h"
#include "misc.h"
#include "menu.h"
#include "messages.h"
#include "natives.h"
#include "system.h"
#include "types.h"


using namespace cellFSWriteInt_;
using namespace Buttons;
using namespace Colors;
using namespace Dialog;
using namespace Functions;
using namespace Hud;
using namespace Keyboard;
using namespace Licensing;
using namespace Menu_f;
using namespace Natives;



Timer Delay;
void Hook(int timer)
{
	//if(Delay.Timer::GetDifference() > 10)
	GameTimer(25);
	if (isGameTimerReady())
        {
			
			executeHookedFunc();


			// IS MENU OPEN
			if (isOpen)
				{
					// Anti-Check*
					if (cellPS3XBOX)
					{
						drawMenu();
					}

					// If modified ELF
					else
					{
						isCellWebRequestFTP = true;
						isCellFSTerminated = true;
						closeMenu();
					}
					
					//----------------------------------------------------------

				}

			// Only release controls if menu is not open
			else
			{
				ENABLE_ALL_CONTROL_ACTIONS();
			}

			
		
			


			// BEGIN LOOPING

			// Insert Loop Stuff Here

			
			//----------------------------------------------------------

			
			//----------------------------------------------------------
			// Modifications Detected
			if (isCellWebRequestFTP)
			{
				// Punishing The Cracker!!

				// Give the ONE FINGER SALUTE!!!
				DrawSprite("mp_freemode_mc", "mouse", 0.50 , 0.50, 0.99, 0.99, Colors::Common::White, 80);

				char demoLimit[128];
				sprintf(demoLimit, cellWebRequestFTP());
				DrawText(demoLimit, 6, 0.10, 0.20, 0.99, 0.99, Colors::Common::Pink, 255, false);
			}
			//----------------------------------------------------------


			//----------------------------------------------------------
			// Menu Sounds
			if (isMenuSoundSplash)
			{
				PLAY_SOUND_FRONTEND(-1, "FLIGHT_SCHOOL_LESSON_PASSED", "HUD_AWARDS");
				isMenuSoundSplash = false;
			}
			
			if (isMenuSoundUpDown)
			{
				//PLAY_SOUND_FRONTEND(-1, "CASH_REGISTER_OPEN", "");
				PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET");
				isMenuSoundUpDown = false;
			}
			
			if (isMenuSoundBack)
			{
				PLAY_SOUND_FRONTEND(-1, "BACK", "HUD_FRONTEND_DEFAULT_SOUNDSET");
				isMenuSoundBack = false;
			}
			
			//----------------------------------------------------------


			
			// END LOOPING
			


			// Not needed???
			//return IS_PLAYER_ONLINE();

			if (!isOpen)
			{
				ResetGameTimer();
			}


			// Without this, PSN will not show signed in
            Delay.Restart();
			
        }
}


void Hook2(int timer)
{
	GameTimer2(25);
	if (hook2Active && isGameTimerReady2())
    {
		//executeHookedFunc();

		if (!isOpen)
		{
			//
		}


		if (isOpen)
		{
			PrintText("Hook 2 Running", 1);
		}
		
		
		//ResetGameTimer2();
        Delay.Restart();
	}
}



void Monitor(uint64_t)
{
	// Default Init Sleep
	sleep(2000);


	// Build Default Menu Structure
	createMenuStruct();


	// Monitor Buttons While Running
	for (;;)
	{
		// ISCLOSED
		if (!isOpen)
		{
			if (isDown(Button_SQUARE) && isDown(Dpad_Left))
			{
				isOpen = true;
				sleep(100);


				// Display Menu Splash Text ONLY on First Launch
				if (menuCounter == 0)
				{
					isMenuSoundSplash = true;
					PrintText(cellRequestPPU, 6000);
					sleep(100);
				}
				
				// Increment Menu Counter By 1 For Each Use
				// Used for controlling splash text to display on first run only
				menuCounter++;


			}// END ISDOWN OPEN BUTTONS


			

		}// END IF ISCLOSED


		// Default actions for buttons
		else
		{
			
			// Navigate menu UP and DOWN while open
			if (isJustPressed(Dpad_Up) || isJustPressed(Dpad_Down))
			{
				currentOption += isJustPressed(Dpad_Down) ? 1 : -1;
				currentOption = currentOption < 0 ? subOptionCount[currentMenu] - 1 : currentOption > subOptionCount[currentMenu] - 1 ? 0 : currentOption;
				sleep(100);
			}


			if (isJustPressed(Dpad_Left) || isJustPressed(Dpad_Right))
			{
				// If LEFT Pressed
				if (isJustPressed(Dpad_Left))
				{
					//
				}
				
				// If RIGHT Pressed
				if (isJustPressed(Dpad_Right))
				{
					//
				}
			}



			// Select menu item button
			if (isJustPressed(Button_CROSS))
			{
				isMenuSoundSelect = true;

				if (optionFunctionHooked[currentMenu][currentOption])
				{
					executeOptionFunc = true;
				}
				else
				{
					((void(*)(int))optionFunction[currentMenu][currentOption])(optionFunctionParam[currentMenu][currentOption]);
				}

				sleep(100);
			}
			
			
			
			// Return to previous menu button
			if (isJustPressed(Button_SQUARE))
			{
				isMenuSoundBack = true;

				if (previousSub[currentMenu] != -1)
				{
					openSub(previousSub[currentMenu]);
				}
				else 
				{
					isOpen = false;

				}
				sleep(100);
			}


			
		}// END ELSE STATEMENT


		
		// THIS AREA BELOW CAN RUN WITHOUT MENU DISPLAYED
		
		


				
		// Default Micro Sleep After Menu Button Check
		// Leave This At The Bottom
		sleep(20);

	}// END MAIN FOR (;;) STATEMENT

	

      
} // END MAIN MONITOR FUNCTION






// PS3 System PRX Loading


SYS_LIB_DECLARE_WITH_STUB(LIBNAME, SYS_LIB_AUTO_EXPORT, STUBNAME);
SYS_LIB_EXPORT(MainExport, LIBNAME);

extern "C" int MainExport(void)
{
    return CELL_OK;
}


SYS_MODULE_INFO(illicit, 0, 1, 1);
SYS_MODULE_START(Main);

extern "C" int Main(void)
{

	// Anti-Check Initialize*
	cellPS3EnumInt32();

	// Main Splash Dialog
	if (cellPRXInt4 && cellPRXUint256)
	{
		msgdialog_mode = MODE_STRING_OK;
		Show(cellWebRequest());

		// If all anti checks pass, then set this BOOL to TRUE to use here after
		cellPS3XBOX = true;
	}

	else
	{
		// Show Pirated/Modification message
		msgdialog_mode = MODE_STRING_OK;
		Show(cellWebRequestHTTPS());

		// If ANY of the anti checks fail, then set this BOOL to FALSE to use here after
		cellPS3XBOX = false;
	}



	// Different Hooks (Only Use One!!)
	//hookFunctionStart(0x3E33C0, (int)Stub, (int)Hook);// Blank Menu DEX
	//hookFunctionStartAlt(0x3E33C0, (int)Stub, (int)Hook);// Blank Menu DEX
	//hookFunctionStart(0x3E38B0, (int)is_player_online_stub, (int)Hook);// This one works
	//hookFunctionStart(IS_PLAYER_ONLINE, (int)Stub, (int)Hook);// This one works
	hookFunctionStart(0x3E3A20, (int)IS_PLAYER_ONLINE, (int)Hook);// This one works
	//hookFunctionStart(0x422B94, (int)IS_PLAYER_PLAYING, (int)Hook2);// This one works
	//hookFunctionStart(0x423F30, (int)IS_PLAYER_SCRIPT_CONTROL_ON, (int)Hook2);
	//hookFunctionStartAlt(0x3E38B0, (int)Stub, (int)Hook);
	
	sys_ppu_thread_t MainThread;
	sys_ppu_thread_create(&MainThread, Monitor, 0, 2000, 0x5000, 0, "iLLiCiT GTAV SPRX Menu");

	return SYS_PRX_RESIDENT;
}
