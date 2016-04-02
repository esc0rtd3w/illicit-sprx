#ifndef _HUD_H
#define _HUD_H

#include "includes.h"
//#include "menu.h"
//#include "misc.h"
#include "natives.h"

//using namespace Misc;
using namespace Natives;

// HUD
namespace Hud
{
	void DrawText(const char *text, int font, float x, float y, float scaleX, float scaleY, ColorSet Color, int a, bool centered)
	{
		//BEGIN_TEXT_COMPONENT("STRING");
		SET_TEXT_FONT(font);
		SET_TEXT_SCALE(scaleX, scaleY);
		SET_TEXT_COLOUR(Color.r, Color.g, Color.b, a);
		SET_TEXT_WRAP(0.0f, 1.0f);
		SET_TEXT_CENTRE(centered);
		SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
		SET_TEXT_OUTLINE();
		SET_TEXT_ENTRY("STRING");
		ADD_TEXT_COMPONENT_STRING(text);
		DRAW_TEXT(x, y);
		//END_TEXT_COMPONENT();
	}

	void ColorText(ColorSet Color, int a)
	{
		SET_TEXT_COLOUR(Color.r, Color.g, Color.b, a);
	}

	void DrawRect(float x, float y, float width, float height, ColorSet Color, int Alpha)
	{
		DRAW_RECT(x, y, width, height, Color.r, Color.g, Color.b, Alpha);
	}


	void DrawNotify(char* text, char* pic1, char* pic2, int icon, bool flash, char* sender, char* subject, int time)
	{
		NOTIFICATION_TYPE("STRING");
		ADD_TEXT_COMPONENT_STRING(text);
		//TIME_TO_DISPLAY(time);
		//SET_NOTIFICATION_MESSAGE("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", true, 4, text, "");
		SET_NOTIFICATION_MESSAGE(pic1, pic2, flash, icon, sender, subject);
		DRAW_NOTIFICATION(false, true);
	}


	// Draw Sprite On Screen
	void DrawSprite(char* textureDict, char* textureName, float x, float y, float scaleX, float scaleY, ColorSet Color, int alpha)
	{
		REQUEST_STREAMED_TEXTURE_DICT(textureDict, 0);
		if (HAS_STREAMED_TEXTURE_DICT_LOADED(textureDict)){
			Vec3 textureRes = GET_TEXTURE_RESOLUTION(textureDict, textureName);
			DRAW_SPRITE(textureDict, textureName, x, y, scaleX, scaleY, 0.0, Color.r, Color.g, Color.b, alpha);
		}
	}

	void PrintText(const char* Text, int Time = 1000)
	{
		//BEGIN_TEXT_COMPONENT("STRING");
		PRINT_TEXT_TYPE("STRING");
		ADD_TEXT_COMPONENT_STRING(Text);
		PRINT_TEXT_TIME(Time);
		//END_TEXT_COMPONENT();
	}

};


#endif