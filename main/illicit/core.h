#ifndef __CORE_H
#define __CORE_H


//#include "anti.h"


using namespace std;



// TOC BLES01807 TU 1.25
//#define TOC 0x1C75288

// TOC 1.26
//#define TOC 0x1809384

// TOC 1.26 Alternate
#define TOC 0x1C85330 


// 1.26 Native Table: 0x1E6FF38




#define VEC2_LEN 2
#define VEC3_LEN 3
#define VEC4_LEN 4
#define BYTE_MAX 0x7F
#define INT16_MAX 0x7FFF
#define INT32_MAX 0x7FFFFFFF
#define INT64_MAX 0x7FFFFFFFFFFFFFFF
#define writeVec(address, len, startx) for(int i = 0, f = 0; i < len; i++, f += 4){*(vec*)((address)+f) = (startx)[i];}
#define readVec(address, len, startx) for(int i = 0, f = 0; i < len; i++, f += 4){(startx)[i] = *(vec*)((address)+f);}


#define MOUNT_POINT					"/dev_hdd0/tmp"

#define null 0

//#define null ((void *)0)
//#define NULL ((void *)0)

typedef void *PVOID;
typedef unsigned long DWORD;
typedef char CHAR;
typedef unsigned char BYTE;
typedef int BOOL;
typedef float FLOAT;
typedef CHAR *PCHAR;
#define VOID void
#define CONST const
typedef unsigned short WORD;
typedef DWORD *PDWORD;

// Exectue Menu Option Once
bool executeOptionFunc;

// Execute Menu Option In Loop
bool executeOptionFuncLoop;
bool executeOptionFuncLoopStart;
bool executeOptionFuncLoopStop;

void sleep(usecond_t time)
{
	sys_timer_usleep(time * 1000);
}

int sys_ppu_thread_exit()
{
	system_call_1(41, 0);
	return_to_user_prog(int);
}

// Generic WAIT Timer without the freeze of sleep
void wait(int time)
{
	int waiter = time * 10000000;
	for (int w = 0; w <= waiter; w++);
}

struct opd_s
{
	int32_t sub, toc;
};



typedef struct RGBA
{
	float R, G, B, A;
};



struct Vec3
{
	float x, y, z;
};


struct Vector3V
{
	float x, y, z;
};


float Float[3];
float* Vec3toFloat(Vec3 Vec)
{
	Float[0] = Vec.x;
	Float[1] = Vec.y;
	Float[2] = Vec.z;
	return Float;
}

float FloatV[3];
float* Vector3toFloat(Vector3V Vec)
{
	FloatV[0] = Vec.x;
	FloatV[1] = Vec.y;
	FloatV[2] = Vec.z;
	return FloatV;
}






//int MainVersion = 0.4.6;
//int MainBuild = 20150808;

float floatArray[100];
float* ReadFloatValue(int address, int length)
{
for (int i = 0; i < length; i++)
{
floatArray[i] = *(float*)(address + (i * 0x04));
}
return floatArray;
}




#endif




