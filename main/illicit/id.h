#ifndef __ID_
#define __ID_

#include "hud.h"
#include "misc.h"
#include "natives.h"

//using namespace Hud;
using namespace Misc;
using namespace Natives;


// Support For Identifying Other Mod Menus By Community ID
// Source: http://www.nextgenupdate.com/forums/gta-5-scripts-codes/898332-all-sprx-developers-community-mod-menu-id-list.html

// Set iLLiCiT Community ID
int communityID = 5141;
void setModMenuID(){
	SET_PLAYER_MAX_ARMOUR(PlayerSelf(), communityID);
}

void checkModMenuID(){
	char *modmenu = "~b~Menu: ~r~Unknown value ~g~";
	int armor = GET_PLAYER_MAX_ARMOUR(GET_PLAYER_PED(PlayerSelected));
	switch(armor) {
		case 23:
			modmenu = "~b~Menu: ~g~Metropolis";break;
		case 28:
			modmenu = "~b~Menu: ~g~Jarvis";break;
		case 69:
			modmenu = "~b~Menu: ~g~Tesseract";break;
		case 71:
			modmenu = "~b~Menu: ~g~SPRX_K";break;
		case 88:
			modmenu = "~b~Menu: ~g~Pheonix";break;
		case 97:
			modmenu = "~b~Menu: ~g~Serendipity";break;
		case 337:
			modmenu = "~b~Menu: ~g~GenocideFreeze";break;
		case 420:
			modmenu = "~b~Menu: ~g~Glisten Is Gay";break;
		case 631:
			modmenu = "~b~Menu: ~g~GNXKS";break;
		case 666:
			modmenu = "~b~Menu: ~g~YetAnotherGTAMenu";break;
		case 1084:
			modmenu = "~b~Menu: ~g~BlueWindow";break;
		case 1234:
			modmenu = "~b~Menu: ~g~Lexicon";break;
		case 1327:
			modmenu = "~b~Menu: ~g~Independence";break;
		case 1337:
			modmenu = "~b~Menu: ~g~Plethora";break;
		case 1996:
			modmenu = "~b~Menu: ~g~Power SPRX";break;
		case 2000:
			modmenu = "~b~Menu: ~g~Ice";break;
		case 2001:
			modmenu = "~b~Menu: ~g~Project Eke";break;
		case 2027:
			modmenu = "~b~Menu: ~g~Limbo";break;
		case 4269:
			modmenu = "~b~Menu: ~g~Cojones SPRX";break;
		case 5141:
			modmenu = "~b~Menu: ~g~iLLiCiT";break;
		case 5759:
			modmenu = "~b~Menu: ~g~Trinity";break;
		case 7777:
			modmenu = "~b~Menu: ~g~Predator";break;
		default:
			char buf[32];
			snprintf(buf, sizeof(buf), "%i", armor);
			strcat(modmenu, buf);
			break;
	}
}

#endif
 