#ifndef __TWEAK_H
#define __TWEAK_H


#include "menu.h"

//using namespace Menu;


namespace Tweak_Menu
{
	
	
	float x_Offset = .3;
	float y_Offset = .3;

	// Draw Text
	const char *dt_Text;
	int dt_Font;
	float dt_FloatX = 0.50 + x_Offset;
	float dt_FloatY;
	int dt_ScaleX;
	int dt_ScaleY;
	int dt_Color;
	int dt_Alpha;

	// DrawRect
	float dr_FloatX = 0.50 + x_Offset;
	float dr_FloatY;
	int dr_ScaleX;
	int dr_ScaleY;
	int dr_Color;
	int dr_Alpha;







};










#endif

