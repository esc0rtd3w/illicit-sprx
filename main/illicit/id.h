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
		case 1327:
			modmenu = "~b~Menu: ~g~Plethora";break;
		case 1337:
			modmenu = "~b~Menu: ~g~Limbo";break;
		case 2027:
			modmenu = "~b~Menu: ~g~Limbo";break;
		default:
			char buf[5];
			snprintf(buf,sizeof(buf),"%i",armor);
			strcat(modmenu,buf);
			break;
	}
}

#endif
 