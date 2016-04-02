#ifndef __TYPES_H
#define __TYPES_H

/*Alexander Blade*/

#pragma once

typedef int Random;
typedef int* RandomP;
typedef void* Void;
typedef int Any;
typedef Any* AnyP;
typedef unsigned int uint;
typedef int Hash;
//typedef unsigned int HashUINT;
typedef int BOOL;
typedef int Entity;
typedef int Player;
typedef int Client;
typedef int FireId;
typedef int Ped;
typedef int Vehicle;
typedef int* PlayerIntP;
typedef unsigned int PlayerUint;
typedef unsigned int VehicleUint;
typedef int Cam;
typedef int CarGenerator;
typedef int Group;
typedef int Train;
typedef int Pickup;
typedef int Object;
typedef unsigned int ObjectUint;
typedef int Weapon;
typedef int Interior;
typedef int Blip;
typedef int Texture;
typedef int TextureDict;
typedef int CoverPoint;
typedef int Camera;
typedef int TaskSequence;
typedef int ColourIndex;
typedef int Sphere;
typedef int ScrHandle;
typedef int playerPedID;
typedef float* playerPedIDFloat;
typedef int VehicleHandle;
typedef int Address;

// Animation Stuff
typedef char* Animation;
typedef char* AniType;
typedef char* AniState;
typedef char* Action;
typedef char* DanceMove;


typedef float vec;
typedef unsigned char byte;
typedef signed char sbyte;
typedef unsigned short ui16;
typedef signed short i16;
typedef unsigned int ui32;
typedef signed int i32;
typedef unsigned long long ui64;
typedef signed long long i64;
typedef char* string;
typedef struct{float x, y;}vec2;
typedef struct{float x, y, z;}vec3;
typedef struct{float x, y, z, w;}vec4;

/*
typedef char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long s64;
typedef unsigned long u64;
*/


typedef const char* Name;
//typedef int ChangeName;



typedef struct
{
	float x;
	float y;
	float z;
} Vector3;


typedef struct
{
	float* x;
	float* y;
	float* z;
} Vector3P;



typedef struct 
{
	float x;
	float y;
	float z;
	float r;
}CoordsRadius;



#endif


