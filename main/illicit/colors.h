#ifndef __COLORS_H
#define __COLORS_H


typedef struct ColorSet
{
	float r, g, b;
};





namespace Colors
{

	namespace Common
	{
		ColorSet Black = { 0, 0, 0 };
		ColorSet Blue = { 0, 0, 255 };
		ColorSet Green = { 0, 255, 0 };
		ColorSet Orange = {255, 157, 0};
		ColorSet Pink = {255, 0, 187};
		ColorSet Purple = {255, 0, 255};
		ColorSet Red = { 255, 0, 0 };
		ColorSet Teal = {0, 255, 208};
		//ColorSet Teal = {0, 128, 128};// Real Teal
		ColorSet White = { 255, 255, 255 };
		ColorSet Yellow = { 255, 255, 0 };
	};

	namespace Mixed
	{
		ColorSet Aqua = { 0, 255, 255 };
		ColorSet Crimson = { 220, 20, 60 };
		ColorSet HotPink = { 255, 105, 180 };
		ColorSet Indigo = { 75, 0, 130 };
		ColorSet Lime = {89, 255, 0};
		ColorSet OrangeRed = {255, 69, 0};
		ColorSet Orchid = {218, 112, 214};
		ColorSet Teal2 = {17, 199, 199};
		ColorSet Turquoise = {64, 224, 208};
		ColorSet Salmon = {250, 128, 114};
		ColorSet SkyBlue = {135, 206, 235};
		ColorSet SpringGreen = {0, 255, 127};
	};

	namespace Dark
	{
		ColorSet DarkBlue = { 0, 0, 139 };
		ColorSet DarkOrange = { 255, 55, 0 };
		ColorSet DarkPink = { 255, 20, 147 };
		ColorSet DarkYellow = { 255, 234, 0 };
	};

	namespace Light
	{
		ColorSet LightBlue = { 173, 216, 230 };
		ColorSet LightCoral = { 240, 128, 128 };
		ColorSet LightOrange = { 255, 175, 0 };
		ColorSet LightPink = { 255, 182, 193 };
		ColorSet LightYellow = { 234, 255, 0 };
	};

};


#endif