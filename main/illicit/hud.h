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

	
	/*
	double Distance(float Pos1, float Pos2)
	{
		return sqrt(Pos1*Pos1 - Pos2*Pos2);
	}


	bool UpdateViewPos = false;

	float* getCurrentViewPos()
	{
		float* GAMEPLAY_CAM_ROT = Vec3toFloat(GET_GAMEPLAY_CAM_ROT(0));
		float F[2] = { GAMEPLAY_CAM_ROT[2], GAMEPLAY_CAM_ROT[0] };
		return F;
	}
	*/


	void Notify(char* text, int time)
	{
		//NOTIFICATION_TYPE("STRING");
		//NOTIFICATION_TEXT(text);
		//NOTIFICATION_SHOW(time, 1);
	}


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


	/*
	void DrawTextNoColor(const char *text, int font, float x, float y, float scaleX, float scaleY, bool centered)
	{
		SET_TEXT_FONT(font);
		SET_TEXT_SCALE(scaleX, scaleY);
		SET_TEXT_WRAP(0.0f, 1.0f);
		SET_TEXT_CENTRE(centered);
		SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
		SET_TEXT_OUTLINE();
		SET_TEXT_ENTRY("STRING");
		ADD_TEXT_COMPONENT_STRING(text);
		DRAW_TEXT(x, y);
	}
	*/

	void ColorText(ColorSet Color, int a)
	{
		SET_TEXT_COLOUR(Color.r, Color.g, Color.b, a);
	}

	/*
	void DrawTextShadow(const char *text, int font, float x, float y, float scaleX, float scaleY, ColorSet Color, int a, bool centered, int shadow1, int shadow2, int shadow3, int shadow4, int shadow5)
	{
		//BEGIN_TEXT_COMPONENT("STRING");
		SET_TEXT_FONT(font);
		SET_TEXT_SCALE(scaleX, scaleY);
		SET_TEXT_COLOUR(Color.r, Color.g, Color.b, a);
		SET_TEXT_WRAP(0.0f, 1.0f);
		SET_TEXT_CENTRE(centered);
		SET_TEXT_DROPSHADOW(shadow1, shadow2, shadow3, shadow4, shadow5);
		SET_TEXT_OUTLINE();
		SET_TEXT_ENTRY("STRING");
		ADD_TEXT_COMPONENT_STRING(text);
		DRAW_TEXT(x, y);
		//END_TEXT_COMPONENT();
	}
	*/
	

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


	/*
	// Draw Cursor
	float CurrentViewPos[2] = { .5, .5 };
	float CursorPosition[2] = { .5, .5 };
	void DrawCursor()
	{
		float* Forward = getCurrentViewPos();
		float cursorChange[2] = { Forward[0] - CurrentViewPos[0], Forward[1] - CurrentViewPos[1] };
		
		float Multiplier = 150;
		if(isDown(Button_L2)) Multiplier = 125;

		if(cursorChange[1] > .45*Multiplier) cursorChange[1] = .45*Multiplier;
		if(cursorChange[1] < -.45*Multiplier) cursorChange[1] = -.45*Multiplier;
		if(cursorChange[0] > .45*Multiplier) cursorChange[0] = .45*Multiplier;
		if(cursorChange[0] < -.45*Multiplier) cursorChange[0] = -.45*Multiplier;

		DRAW_RECT(.5 - cursorChange[0] / Multiplier, .5 - cursorChange[1] / Multiplier, .01, 0.14, 255, 0, 0, 255);
		
		CursorPosition[0] = .5 - cursorChange[0] / Multiplier;
		CursorPosition[1] = .5 - cursorChange[1] / Multiplier;
	}
	*/


	void PrintText(const char* Text, int Time = 1000)
	{
		//BEGIN_TEXT_COMPONENT("STRING");
		PRINT_TEXT_TYPE("STRING");
		ADD_TEXT_COMPONENT_STRING(Text);
		PRINT_TEXT_TIME(Time);
		//END_TEXT_COMPONENT();
	}

	/*
	void PrintInt(int Number, int Time = 1000)
	{
		//BEGIN_TEXT_COMPONENT("NUMBER");
		PRINT_TEXT_TYPE("NUMBER");
		ADD_TEXT_COMPONENT_INTEGER(Number);
		PRINT_TEXT_TIME(Time);
		//END_TEXT_COMPONENT();
	}
	*/

	/*
	const char* MenuArrow(int typeLeft1Right2, float size, ColorSet color, int alpha)
	{
		
		if (typeLeft1Right2 == 1)
		{
			// Draw a Left Arrow to the right of menu on current option
			//DrawText("1", 3, 0.820 + x_OffsetFollow, 0.173 + (0.045f*i), 0.60, 0.60, color, 255, true);
			DrawText("1", 3, 0.820 + x_OffsetFollow, 0.173 + (0.045f*i), size, size, color, alpha, true);
		}

		if (typeLeft1Right2 == 2)
		{
			// Draw a Right Arrow to the left of menu on current option
			//DrawText("2", 3, 0.409 + x_OffsetFollow, 0.173 + (0.045f*i), 0.60, 0.60, color, 255, true);
			DrawText("2", 3, 0.409 + x_OffsetFollow, 0.173 + (0.045f*i), size, size, color, alpha, true);
		}
	}

	
	const char* MenuHelpContext(const char* text, int font, float size, ColorSet color, int alpha)
	{
		DrawText(text, 6, 0.24 + x_OffsetFollow, 0.166 + (0.045f*i), size, size, color, alpha, false);
	}
	*/

	
	/*
	// Draw Overlay Items On Screen
	void HudOverlay(const char* text, int position, bool centered)
	{
		switch (position)
		{
			
			// Top Left Corner
			case 1:
				DrawText(text, 6, 0.02, 0, 0.40, 0.40, Colors::Common::Teal, 255, centered);
				break;

			// Top Center
			case 2:
				DrawText(text, 6, 0.50, 0, 0.40, 0.40, Colors::Common::Teal, 255, centered);
				break;

			// Top Right Corner
			case 3:
				DrawText(text, 6, 0.98, 0, 0.40, 0.40, Colors::Common::Teal, 255, centered);
				break;

			// Bottom Left Corner
			case 4:
				DrawText(text, 6, 0.02, 0.95, 0.40, 0.40, Colors::Common::Teal, 255, centered);
				break;

			// Bottom Center
			case 5:
				DrawText(text, 6, 0.50, 0.95, 0.40, 0.40, Colors::Common::Teal, 255, centered);
				break;

			// Bottom Right Corner
			case 6:
				DrawText(text, 6, 0.98, 0.95, 0.40, 0.40, Colors::Common::Teal, 255, centered);
				break;

			// Center Left
			case 7:
				DrawText(text, 6, 0.02, 0.50, 0.40, 0.40, Colors::Common::Teal, 255, centered);
				break;

			// Center Right
			case 8:
				DrawText(text, 6, 0.98, 0.50, 0.40, 0.40, Colors::Common::Teal, 255, centered);
				break;

			// Center Center
			case 9:
				DrawText(text, 6, 0.50, 0.50, 0.40, 0.40, Colors::Common::Teal, 255, centered);
				break;
		}

	}
	*/

};


#endif