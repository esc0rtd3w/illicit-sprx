#ifndef __MESSAGES_H
#define __MESSAGES_H

#include "colors.h"
#include "hud.h"
#include "includes.h"
//#include "misc.h"

//using namespace Colors;
using namespace Hud;
//using namespace std;


//----------------------------------------------------------------------------
// System Messages

 
namespace Dialog
{
	bool Finished = false;
	bool YESNO = false; 
	struct opd_s
	{
		int32_t sub;
		int32_t toc;
	};

	int sys_ppu_thread_exit()
	{
		system_call_1(41, 0);
		return_to_user_prog(int);
	}

	int console_write(const char * s)
	{
		uint32_t len;
		system_call_4(403, 0, (uint64_t) s, std::strlen(s), (uint64_t) &len);
		return_to_user_prog(int);
	}

	enum 
	{
		MODE_IDLE = 0,
		MODE_ERRORCODE_DIALOG_TEST,
		MODE_STRING_OK,
		MODE_STRING_YESNO,
		MODE_STRING_DIALOG_3,
		MODE_STRING_DIALOG_4,
		MODE_STRING_DIALOG_5,
		MODE_CHECK_PROGRESSBAR_1,
		MODE_RUNNING,
		MODE_CHECK_TIMEOUT,
		MODE_TIMEOUT_NEXT,
		MODE_EXIT
	};
 
	static int msgdialog_mode = MODE_IDLE;
 
	static void cb_dialogText1( int button_type, void *userdata )
	{
		switch ( button_type ) 
		{ 
			case CELL_MSGDIALOG_BUTTON_OK:
				msgdialog_mode = MODE_EXIT;
				break;
		
			case CELL_MSGDIALOG_BUTTON_ESCAPE:
				msgdialog_mode = MODE_EXIT;
				break; 

			default:
				msgdialog_mode = MODE_EXIT;
				break;
		}
	}

	static void cb_dialogText2( int button_type, void *userdata )
	{
		switch ( button_type ) 
		{ 
			case CELL_MSGDIALOG_BUTTON_YES:
				YESNO = true;
				msgdialog_mode = MODE_EXIT;
				break;
 
			case CELL_MSGDIALOG_BUTTON_NO:
				msgdialog_mode = MODE_EXIT;
				break;
 
			case CELL_MSGDIALOG_BUTTON_ESCAPE:
				msgdialog_mode = MODE_EXIT;
				break;

			default:
				break;
		}
	}
 
	void ShowYESNO(char* msg)
	{
		int ret = 0;
		unsigned int type = CELL_MSGDIALOG_TYPE_SE_TYPE_NORMAL | CELL_MSGDIALOG_TYPE_BG_INVISIBLE  | CELL_MSGDIALOG_TYPE_BUTTON_TYPE_YESNO | CELL_MSGDIALOG_TYPE_DISABLE_CANCEL_ON | CELL_MSGDIALOG_TYPE_DEFAULT_CURSOR_YES;  
		switch ( msgdialog_mode )
		{
			case MODE_IDLE:
				break;
 
			case MODE_STRING_YESNO:
				cellMsgDialogOpen2(type, msg, cb_dialogText2, NULL, NULL);
				msgdialog_mode = MODE_RUNNING;
				break;
 
			case MODE_EXIT:
				cellMsgDialogClose((float)1);
				break;
 
			default:
				break; 
		}
	}

	void Show(char* msg)
	{       
		unsigned int type = CELL_MSGDIALOG_TYPE_SE_TYPE_ERROR | CELL_MSGDIALOG_TYPE_BG_INVISIBLE | CELL_MSGDIALOG_TYPE_BUTTON_TYPE_OK | CELL_MSGDIALOG_TYPE_DISABLE_CANCEL_ON | CELL_MSGDIALOG_TYPE_DEFAULT_CURSOR_OK;
		switch ( msgdialog_mode )
		{
			case MODE_IDLE:
				break;
 
			case MODE_STRING_OK:
				cellMsgDialogOpen2(type, msg, cb_dialogText1, NULL, NULL);
				msgdialog_mode = MODE_EXIT;
				break;
 
			case MODE_EXIT:
				cellMsgDialogClose((float)5);
				break;
 
			default:
				break; 
		} 
		while(Dialog::msgdialog_mode != Dialog::MODE_EXIT){}  //wait for the dialog to end :P
	}
 
	void End()
	{
		Finished = false;
		YESNO = false;
	}
}
 
 
 
namespace Keyboard
{
	
	enum
	{
		MODE_IDLE = 0,
		MODE_OPEN,
		MODE_RUNNING,
		MODE_CLOSE,
		MODE_ENTERED,
		MODE_CANCELED,
		SET_ABORT_TIMER,
		CHANGE_PANEL_MODE,
		CHANGE_SCALE,
		SET_CALLBACK,
		MODE_EXIT,
		START_DIALOG_TYPE,
		START_SEPARATE_TYPE_1,
		START_SEPARATE_TYPE_2,
	};

	static int oskdialog_mode = MODE_IDLE;
 
	int getkbLen(char* str)
	{
		int nullCount = 0;
		int i = 0; //num of chars..
		for(i = 0; i < 64;i++)
		{
			if(nullCount == 2){break;}
			if(*(str+i) == 0x00) 
			{ 
				nullCount++; 
			} 
			else 
			{
				nullCount = 0;
			}
		}
		return i;
	}

	void makekbStr(char* str,char* dest, int len)
	{
		int nulls = 0;
		for(int i = 0; i < len; i++)
		{
			if(*(str+i) == 0x00) 
			{
				nulls++; 
			}
			else 
			{
				*(dest+i-nulls) = *(str+i);
			}
		}
		*(dest+len+1-nulls) = 0x00;  //make sure its nulled...
	}
 
	static void sysutil_callback( uint64_t status, uint64_t param, void *userdata )
	{
		(void)param;
		(void)userdata;
		int ret = 0; 
		switch( status )
		{
			case CELL_SYSUTIL_OSKDIALOG_LOADED:
				break;

			case CELL_SYSUTIL_OSKDIALOG_FINISHED:
				oskdialog_mode = MODE_CLOSE;
				break;

			case CELL_SYSUTIL_OSKDIALOG_UNLOADED:
				break;

			case CELL_SYSUTIL_REQUEST_EXITGAME:
				oskdialog_mode = MODE_EXIT;
				break;

			case CELL_SYSUTIL_DRAWING_BEGIN:
				break;

			case CELL_SYSUTIL_DRAWING_END:
				break;

			case CELL_SYSUTIL_OSKDIALOG_INPUT_ENTERED:
				oskdialog_mode = MODE_ENTERED;
				break;

			case CELL_SYSUTIL_OSKDIALOG_INPUT_CANCELED:
				oskdialog_mode = MODE_CANCELED;
				break;

			case CELL_SYSUTIL_OSKDIALOG_INPUT_DEVICE_CHANGED:
				break;

			case CELL_SYSUTIL_OSKDIALOG_DISPLAY_CHANGED:
				break;

			case CELL_SYSUTIL_SYSTEM_MENU_CLOSE: 
				break;

			case CELL_SYSUTIL_SYSTEM_MENU_OPEN:
				break;

			default:
				break;
		}
	}

	int keyboard(char* dest, char* INIT_TEXT, char* MESSAGE)
	{
		#pragma region Declarations 
		int ret;
		CellOskDialogInputFieldInfo inputFieldInfo;
		inputFieldInfo.message = (uint16_t*)MESSAGE;
		inputFieldInfo.init_text = (uint16_t*)INIT_TEXT;
		inputFieldInfo.limit_length = CELL_OSKDIALOG_STRING_SIZE;
 
		CellOskDialogCallbackReturnParam OutputInfo;
		OutputInfo.result = CELL_OSKDIALOG_INPUT_FIELD_RESULT_OK;
		OutputInfo.numCharsResultString = 32;

		uint16_t Result_Text_Buffer[CELL_OSKDIALOG_STRING_SIZE + 1];
		OutputInfo.pResultString = Result_Text_Buffer;
 
		ret = cellOskDialogSetKeyLayoutOption (CELL_OSKDIALOG_10KEY_PANEL | CELL_OSKDIALOG_FULLKEY_PANEL);
  
		CellOskDialogPoint pos;
		pos.x = 0.0;  pos.y = 0.0;
		int32_t LayoutMode = CELL_OSKDIALOG_LAYOUTMODE_X_ALIGN_CENTER | CELL_OSKDIALOG_LAYOUTMODE_Y_ALIGN_TOP;
		ret = cellOskDialogSetLayoutMode( LayoutMode );
  
		CellOskDialogParam dialogParam;
		dialogParam.allowOskPanelFlg = CELL_OSKDIALOG_PANELMODE_KOREAN | CELL_OSKDIALOG_PANELMODE_ALPHABET | CELL_OSKDIALOG_PANELMODE_NUMERAL_FULL_WIDTH | CELL_OSKDIALOG_PANELMODE_NUMERAL | CELL_OSKDIALOG_PANELMODE_JAPANESE | CELL_OSKDIALOG_PANELMODE_JAPANESE_KATAKANA | CELL_OSKDIALOG_PANELMODE_ENGLISH;
		//E Panel to display first
		dialogParam.firstViewPanel = CELL_OSKDIALOG_PANELMODE_ALPHABET;
		// E Initial display position of the on-screen keyboard dialog
		dialogParam.controlPoint = pos;
		//E Prohibited operation flag(s) (ex. CELL_OSKDIALOG_NO_SPACE)
		dialogParam.prohibitFlgs = 0;
  
		#pragma endregion
 
		sys_timer_usleep( 16 * 1000 );
		ret = cellSysutilCheckCallback();
  
		if(oskdialog_mode == MODE_OPEN)
		{
			if(cellSysutilRegisterCallback( 0, sysutil_callback, NULL ) != 0) 
			{	
				Dialog::console_write("\nError: Couldn't register the keyboard.\n");
			}
			ret = cellOskDialogLoadAsync(SYS_MEMORY_CONTAINER_ID_INVALID, &dialogParam, &inputFieldInfo);
			oskdialog_mode = MODE_RUNNING;
		}
         
		if(oskdialog_mode == MODE_ENTERED )
		{
			ret = cellOskDialogGetInputText( &OutputInfo );
			oskdialog_mode = MODE_RUNNING;
		}
		if(oskdialog_mode == MODE_CLOSE )
		{
			ret = cellOskDialogUnloadAsync( &OutputInfo );
 
			int strLen = getkbLen((char*)(*(&OutputInfo.pResultString)));
			makekbStr((char*)(*(&OutputInfo.pResultString)),dest, strLen);
			inputFieldInfo.init_text = (uint16_t*)INIT_TEXT;      
			if(cellSysutilUnregisterCallback(0) != 0) 
			{
				Dialog::console_write("\nError: Couldn't unload the keyboard.\n");
			}
			oskdialog_mode = MODE_EXIT;
		}
 
		return 0;
	}


	// Onscreen Keyboard
	//char* resultOSK = GET_ONSCREEN_KEYBOARD_RESULT();
	bool isKeyboardActiveT = false;
	void ToggleKeyboard()
	{
		isKeyboardActiveT = !isKeyboardActiveT;
		isKeyboardActive = isKeyboardActiveT;
		//MsgToggleDefault("On-Screen Keyboard", isKeyboardActiveT);
		//char keyTest[32];
		//sprintf(keyTest, GET_ONSCREEN_KEYBOARD_RESULT());
		//PrintText(keyTest, 3000);
	}

	
	//----------------------------------------------------


}


//----------------------------------------------------------------------------





//----------------------------------------------------------------------------
// In-Game Messages

// Player Is Not In A Vehicle
void MsgPlayerNotInVehicle()
{
	char message[32];
	//sprintf(message, "~r~%s Player Is Not In A Vehicle", NameCurrentFollow2);
	sprintf(message, "~r~Player Is Not In A Vehicle");
	PrintText(message, 3000);
}	


int textDisplayArgInt;
void MsgTalkDisplay(char* text1, char* text2, int player, int talkSlot)
{
	char msgHud[64];
	sprintf(msgHud, text1, text2, player);

	switch(talkSlot)
	{
		case 0: DrawText(msgHud, 6, 0.05, 0.04, 0.55, 0.55, Colors::Common::Yellow, 255, false);
			break;
		case 1: DrawText(msgHud, 6, 0.05, 0.08, 0.55, 0.55, Colors::Common::Purple, 255, false);
			break;
		case 2: DrawText(msgHud, 6, 0.05, 0.12, 0.55, 0.55, Colors::Common::Green, 255, false);
			break;
		case 3: DrawText(msgHud, 6, 0.05, 0.16, 0.55, 0.55, Colors::Common::Pink, 255, false);
			break;
		case 4: DrawText(msgHud, 6, 0.05, 0.20, 0.55, 0.55, Colors::Common::Orange, 255, false);
			break;
		case 5: DrawText(msgHud, 6, 0.05, 0.24, 0.55, 0.55, Colors::Common::Teal, 255, false);
			break;
		case 6: DrawText(msgHud, 6, 0.05, 0.28, 0.55, 0.55, Colors::Common::Yellow, 255, false);
			break;
		case 7: DrawText(msgHud, 6, 0.05, 0.32, 0.55, 0.55, Colors::Common::Purple, 255, false);
			break;
		case 8: DrawText(msgHud, 6, 0.05, 0.36, 0.55, 0.55, Colors::Common::Green, 255, false);
			break;
		case 9: DrawText(msgHud, 6, 0.05, 0.40, 0.55, 0.55, Colors::Common::Pink, 255, false);
			break;
		case 10: DrawText(msgHud, 6, 0.05, 0.44, 0.55, 0.55, Colors::Common::Orange, 255, false);
			break;
		case 11: DrawText(msgHud, 6, 0.05, 0.48, 0.55, 0.55, Colors::Common::Teal, 255, false);
			break;
		case 12: DrawText(msgHud, 6, 0.05, 0.52, 0.55, 0.55, Colors::Common::Yellow, 255, false);
			break;
		case 13: DrawText(msgHud, 6, 0.05, 0.56, 0.55, 0.55, Colors::Common::Orange, 255, false);
			break;
		case 14: DrawText(msgHud, 6, 0.05, 0.60, 0.55, 0.55, Colors::Common::Green, 255, false);
			break;
		case 15: DrawText(msgHud, 6, 0.05, 0.64, 0.55, 0.55, Colors::Common::Pink, 255, false);
			break;
	}
}


// Default Message
void MsgDefault(char* text, int milliseconds)
{
	char msgDefault[250];
	sprintf(msgDefault, "%s", text);
	PrintText(msgDefault, milliseconds); 
}



// Default Toggle Text
char* toggleTextColor = "~w~";

char* toggleTextOn = "~g~ Enabled";
char* toggleTextOff = "~r~ Disabled";
char* toggleTextOnAlt = "~g~ Is Enabled";
char* toggleTextOffAlt = "~r~ Is Disabled";

char* toggleText;
bool toggleCurrent;
bool toggleCurrentT;

bool isToggleTextOn;
bool isToggleTextOff;


void MsgToggleDefault(char* toggleText, bool toggleState)
{
	 char msgToggle[100];
	 if (toggleState) 
	 {
		sprintf(msgToggle, "%s%s%s", toggleTextColor, toggleText, toggleTextOn);
	 } 
	 else 
	 {
		 sprintf(msgToggle, "%s%s%s", toggleTextColor, toggleText, toggleTextOff);
	 }

	 PrintText(msgToggle, 3000); 
}


void MsgToggleReverse(char* toggleText, bool toggleState)
{
	 char msgToggle[100];
	 if (toggleState) 
	 {
		sprintf(msgToggle, "%s%s%s", toggleTextColor, toggleText, toggleTextOff);
	 } 
	 else 
	 {
		 sprintf(msgToggle, "%s%s%s", toggleTextColor, toggleText, toggleTextOn);
	 }

	 PrintText(msgToggle, 3000); 
}


void MsgHelpWarning(int msg)
{
	char buffer[150];

	switch(msg)
	{
		case 1: sprintf(buffer, "~w~You can modify X, Y, Z drop coords with ~b~DPAD L and R\n~y~First Toggle The Coord In Menu");
			break;
		case 2: sprintf(buffer, "~w~You can select ~y~Next Player ~w~with ~b~DPAD R\n~w~Select ~y~Previous Player ~w~With ~b~DPAD L");
			break;
		case 3: sprintf(buffer, "~w~You can modify RP value with ~b~DPAD L and R\n~y~Do Not Use Too Fast or You May Freeze!");
			break;
		case 4: sprintf(buffer, "~w~Select Vehicle With ~b~X ~w~Button\nDelete Vehicle With ~r~O ~w~Button");
			break;
		case 5: sprintf(buffer, "~r~WARNING!!!\n~w~THE LOOPING PUNISHMENT OPTIONS MAY FREEZE UNEXPECTEDLY!!");
			break;
	}

	PrintText(buffer, 5000);
}


void MsgHelpWarningShort(int msg)
{
	char buffer[150];

	switch(msg)
	{
		case 1: sprintf(buffer, "~r~WARNING!!! ~w~\nTHIS OPTION MAY SEEM FROZEN\n~y~ALLOW UP TO 10 SECONDS TO PROCESS");
			break;
		case 2: sprintf(buffer, "~y~WARNING!!!\n~w~THIS OPTION IS ~r~NOT RECOMMENDED ~w~FOR ONLINE USE");
			break;
		case 3: sprintf(buffer, "~w~Increase ~y~DPAD RIGHT\n~w~Decrease ~y~DPAD LEFT\n~w~Toggle ~g~ON~w~/~r~OFF~w~ With ~b~X ~w~Button");
			break;
	}

	PrintText(buffer, 100);
}

/*
void MsgDpadAdjust(int msg)
{
	char buffer[150];

	switch(msg)
	{
		case 1: sprintf(buffer, "~w~%s: ~b~%i\n~w~Use ~y~DPAD L+R ~w~To Adjust", dpadAdjustType);
			break;
	}

	PrintText(buffer, 100);
}
*/	
//----------------------------------------------------------------------------


#endif


