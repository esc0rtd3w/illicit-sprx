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
		ColorSet White = { 255, 255, 255 };
		ColorSet Yellow = { 255, 255, 0 };
	};

	namespace Mixed
	{
		ColorSet Lime = {89, 255, 0};
		ColorSet Teal2 = {17, 199, 199};
	};

	namespace Dark
	{
		ColorSet DarkOrange = { 255, 55, 0 };
		ColorSet DarkYellow = { 255, 234, 0 };
	};

	namespace Light
	{
		ColorSet LightOrange = { 255, 175, 0 };
		ColorSet LightYellow = { 234, 255, 0 };
	};

};


#endif