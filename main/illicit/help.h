#ifndef __HELP_
#define __HELP_


#include "anti.h"
#include "hud.h"
#include "licensing.h"
#include "messages.h"
#include "misc.h"
#include "natives.h"


using namespace cellFSWriteInt_;
using namespace Dialog;
using namespace Hud;
using namespace Keyboard;
using namespace Licensing;
using namespace Misc;
using namespace Natives;



// Help
namespace Help_f
{

	// Help Context Menu
	const char* checkHelpContext(const char* text, const char* item)
	{
		//helpContextDisplay = text;
		//helpContextItem = item;

		char buffer[250];
		sprintf(buffer, "~b~%s\n~w~%s", text, item);
		return buffer;

	}

	/*
	//Other Help Crap
	void ShowHelp(int)
	{
		PrintText("~b~ CROSS = Select\nSQUARE = Back\nTRIANGLE = Help", 8000);
	}
	*/

	/*
	void HideHelp(int)
	{
		PrintText("", 1000);
	}
	*/

		
	// Help Menu Stuff

	void ShowCreditsText(int)
	{
		char creditsText[175];
		sprintf(creditsText, cellWriteIntRequest());
		msgdialog_mode = MODE_STRING_OK;
		Show(creditsText);
	}
	
	// Anti-Check*
	void ShowAboutText(int)
	{
		char aboutText[105];
		sprintf(aboutText, cellSendRequest());
		PrintText(aboutText, 10000);
	}
		
};



#endif


