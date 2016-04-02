#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "core.h"
#include "hud.h"
#include "includes.h"
#include "misc.h"

//#include "cell.h"


using namespace Hud;


/*
sys_pid_t sys_process_getpid(void)
{
   system_call_0(1);
   return_to_user_prog(sys_pid_t);
}
*/

/*
void GetParamSFO(uint8_t buffer)
{
     system_call_1(0x01E, sys_process_getpid(), buffer);
}
*/

/*
void SetMem(int address, byte buff[])
{
  *(int*)address = buff;
}
*/

/*
void DetachThread(int id)
{
    system_call(0x02D, sys_process_getpid(), id);
}
*/

/*
void GenerateRandomNumber(int buffer)
{
    system_call_3(0x361, sys_process_getpid(), sizeof(buffer), buffer);
}
*/

/*
void GetCID(uint8_t buffer)
{
   system_call_1(0x366, buffer);
}
*/



//Timer
class Timer
{
public:
	void Start();
	void Restart();
	system_time_t GetDifference();
private:
	system_time_t StartTime;
	bool Started;
	system_time_t Difference;
};

void Timer::Start()
{
	if (!Timer::Started)
	{
		Timer::StartTime = sys_time_get_system_time() / 1000;
		Started = true;
	}
}

void Timer::Restart()
{
	Timer::StartTime = sys_time_get_system_time() / 1000;
	Started = true;
}

system_time_t Timer::GetDifference()
{
	system_time_t CurrentTime = sys_time_get_system_time() / 1000;
	float LastTime = StartTime;
	Timer::Difference = CurrentTime - StartTime;
	return Timer::Difference;
}


//----------------------------------------------------------------------------
// Syscalls
#include <sys/syscall.h>

/*
system_call_[number of parameters]([syscall number], params, params, params, params)
system_call_3(379, 0x100, 0, 0);
*/
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// Msgdialog
#include <sysutil\sysutil_msgdialog.h>
#include <sysutil\sysutil_oskdialog.h>
#include <sysutil\sysutil_oskdialog_ext.h>

/*
void my_dialog2(int button, void *userdata)
{
switch(button)
{
case CELL_MSGDIALOG_BUTTON_OK:
case CELL_MSGDIALOG_BUTTON_NONE:
case CELL_MSGDIALOG_BUTTON_ESCAPE:
dialog_action = 1;
break;
default:
break;
}
}

cellMsgDialogOpen(1,"YOUR TEXT",my_dialog2,(void*) 0x0000aaab, NULL);
*/

/*
void SplashXmbMsg(int button, void *userdata)
{
    switch(button) {

		//int dialog_action;
		
        case CELL_MSGDIALOG_BUTTON_OK:
        case CELL_MSGDIALOG_BUTTON_NONE:
		case CELL_MSGDIALOG_BUTTON_ESCAPE:
            dialog_action = 1;
            break;
        default:
		    break;
    }
}
*/

//cellMsgDialogOpen(1, "Hello", SplashXmbMsg, (void*) 0x0000aaab, NULL);


//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// GetProcessId
//#include <sys/syscall.h>

/*
sys_pid_t sys_process_getpid(void)
{
system_call_0(1);
return_to_user_prog(sys_pid_t);
}
*/

//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// Sleep
#include <sys/sys_time.h>
/*
void sleep(second_t time)
{
sys_timer_sleep(time);
}
*/
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
// ExitThread
//#include <sys/syscall.h>

/*
int sys_ppu_thread_exit()
{
system_call_1(41, 0);
return_to_user_prog(int);
}
*/
//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
// CreateThread
//#include <sys/syscall.h>
#include <sys/ppu_thread.h>

/*
sys_ppu_thread_t id;
sys_ppu_thread_t create_thread(void (*entry)(uint64_t), int priority, size_t stacksize, const char* threadname)
{
if(sys_ppu_thread_create(&id, entry, 0, priority , stacksize, 0, threadname) != CELL_OK)
{
console_write("Thread creation failed\n");
}
else
{
console_write("Thread created\n");
}
return id;
}
*/
//----------------------------------------------------------------------------



//----------------------------------------------------------------------------
// ConsoleWrite
#include <string.h>
#include <sys/syscall.h>
#include <stdarg.h>
#include <stddef.h>
/*
int console_write(const char * s)
{
uint32_t len;
system_call_4(403, 0, (uint64_t) s, std::strlen(s), (uint64_t) &len);
return_to_user_prog(int);
}
*/
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//Web Function
// Add to Linker Dependencies
//$(SCE_PS3_ROOT)\target\ppu\lib\libhttp_stub.a
//$(SCE_PS3_ROOT)\target\ppu\lib\libhttp_util_stub.a
//$(SCE_PS3_ROOT)\target\ppu\lib\libnet_stub.a

/*
char response[255];
SendRequest("http://www.google.com/", response, 255);
*/
//----------------------------------------------------------------------------


// Read/Write File Variables
int fd;
uint64_t unk;

// Write File
void WriteFile(int dummy)
{
	//LicenseText = "Demo";
	LicenseText = "FN52L-9YXVP-17TRZ";
	LicenseFile = "/dev_hdd0/tmp/iLLiCiT.txt";

	//It has to be in some description of a folder (it can't be on the root of HDD0)
	if (cellFsOpen(LicenseFile, CELL_FS_O_CREAT|CELL_FS_O_WRONLY, &fd, NULL, 0) != CELL_FS_SUCCEEDED)
		return;

    cellFsWrite(fd, (const void*)LicenseText, strlen(LicenseText), &unk);
    cellFsClose(fd);
}


// Read File
char str[200];
CellFsErrno readFile;
//char w[100], r[100], buf[200];
uint64_t sw, pos, sr, rd;
void ReadFile(int dummy)
{
	readFile = cellFsOpen(LicenseFile, CELL_FS_O_RDONLY, &fd, NULL, 0);

	if (readFile == 0)
	{
		cellFsRead(fd, str, sizeof(str), &sw);
		cellFsClose(fd);

		//PrintText(str, 3000);
		
	}
}




	/*

#pragma region Memonic
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
	//typedef enum:int{MEM_READ,MEM_WRITE}mem_s;
	#define VEC2_LEN 2
	#define VEC3_LEN 3
	#define VEC4_LEN 4
	#define BYTE_MAX 0x7F
	#define INT16_MAX 0x7FFF
	#define INT32_MAX 0x7FFFFFFF
	#define INT64_MAX 0x7FFFFFFFFFFFFFFF
	#define writeVec(address, len, startx) for(int i = 0, f = 0; i < len; i++, f += 4){*(vec*)((address)+f) = (startx)[i];}
	#define readVec(address, len, startx) for(int i = 0, f = 0; i < len; i++, f += 4){(startx)[i] = *(vec*)((address)+f);}
	#pragma endregion

namespace Data
{
	typedef enum : int {OR,XOR,AND,NAND,NOR,NOT,SHIFT_LEFT,SHIFT_RIGHT}bit;
	vec Single(i32 address, mem_s mem, vec value = 0.0)
	{
		if(mem)
			*(vec*)(address) = value;
			return 0.0;
		return *(vec*)(address);
	}
	double Double(i32 address, mem_s mem, double value = 0.00)
	{
		if(mem)
			*(double*)(address) = value;
			return 0.00;
		return *(double*)(address);
	}
	byte Byte(i32 address, mem_s mem, byte value = 00)
	{
		if(mem)
			*(byte*)(address) = value;
			return 00;
		return *(byte*)(address);
	}
	sbyte SByte(i32 address, mem_s mem, sbyte value = 0x00)
	{
		if(mem)
			*(sbyte*)(address)=value;
			return 0;
		return *(sbyte*)(address);
	}
	ui16 UInt16(i32 address, mem_s mem, ui16 value = 0x0000)
	{
		if(mem)
			*(ui16*)(address)=value;
			return 0x0000;
		return *(ui16*)(address);
	}
	i16 Int16(i32 address, mem_s mem, i16 value = 0x0000)
	{
		if(mem)
			*(i16*)(address)=value;
			return 0x0000;
		return *(i16*)(address);
	}
	ui32 UInt32(i32 address, mem_s mem, ui32 value = 0x00000000)
	{
		if(mem)
			*(ui32*)(address) = value;
			return 0x00000000;
		return *(ui32*)(address);
	}
	i32 Int32(i32 address, mem_s mem, i32 value = 0x00000000)
	{
		if(mem)
			*(i32*)(address) = value;
			return 0x00000000;
		return *(i32*)(address);
	}
	ui64 UInt64(i32 address, mem_s mem, ui64 value = 0x0000000000000000)
	{
		if(mem)
			*(ui64*)(address) = value;
			return 0x0000000000000000;
		return *(ui64*)(address);
	}	
	i64 Int64(i32 address, mem_s mem, i64 value = 0x0000000000000000)
	{
		if(mem)
			*(i64*)(address) = value;
			return 0x0000000000000000;
		return *(ui64*)(address);
	}
	string String(i32 address, mem_s mem, string value = "")
	{
		if(mem)
			strncpy((char*)(address), value, strlen(value));
			return "";
		return (char*)(address);
	}
	vec2 Vec2(i32 address, mem_s mem, vec2 value = *(vec2*)0)
	{
		if(mem&&value.x)
			writeVec(address, VEC2_LEN, &value.x);
			return *(vec2*)0;
		vec2 val;
		readVec(address,VEC2_LEN,&val.x)
		return val;
	}
	vec3 Vec3(i32 address, mem_s mem, vec3 value = *(vec3*)0)
	{
		if(mem&&value.x)
			writeVec(address, VEC3_LEN, &value.x);
			return *(vec3*)0;
		vec3 val;
		readVec(address,VEC3_LEN,&val.x)
		return val;
	}
	vec4 Vec4(i32 address, mem_s mem, vec4 value = *(vec4*)0)
	{
		if(mem&&value.x)
			writeVec(address, VEC4_LEN, &value.x);
			return *(vec4*)0;
		vec4 val;
		readVec(address,VEC4_LEN,&val.x)
		return val;
	}
	#pragma region Math ~ Single
	vec Add(i32 address, mem_s mem, vec value = 0.0)
	{
		if(mem&&value)
			*(float*)(address) += value;
			return 0.0;
		return *(float*)(address) + value;
	}
	vec Sub(i32 address, mem_s mem, vec value = 0.0)
	{
		if(value > *(vec*)(address)) printf("Basic Math error\n\targument value [%f] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(vec*)(address) -= value;
			return 0;
		return *(vec*)(address) - value;
	}
	vec Mul(i32 address, mem_s mem, vec value = 0.0)
	{
		if(mem&&value)
			*(vec*)(address) *= value;
			return 0;
		return *(vec*)(address) * value;
	}
	vec Div(i32 address, mem_s mem, vec value = 0.0)
	{
		if(value > *(vec*)(address)) printf("Basic Math error\n\targument value [%f] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(vec*)(address) /= value;
			return 0;
		return *(vec*)(address) / value;
	}
	vec R(i32 address, i32 len) //Get Remander
	{
		return (vec)(*(i32*)(address) % len);
	}
	#pragma endregion
	#pragma region Math ~ Double
	double Add(i32 address, mem_s mem, double value = 0.00)
	{
		if(mem&&value)
			*(double*)(address) += value;
			return 0.00;
		return *(double*)(address) + value;
	}
	double Sub(i32 address, mem_s mem, double value = 0.00)
	{
		if(value > *(double*)(address)) printf("Basic Math error\n\targument value [%f] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(double*)(address) -= value;
			return 0.00;
		return *(double*)(address) - value;
	}
	double Mul(i32 address, mem_s mem, double value = 0.0)
	{
		if(mem&&value)
			*(double*)(address) *= value;
			return 0;
		return *(double*)(address) * value;
	}
	double Div(i32 address, mem_s mem, double value = 0.00)
	{
		if(value > *(double*)(address)) printf("Basic Math error\n\targument value [%f] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(double*)(address) /= value;
			return 0;
		return *(double*)(address) / value;
	}
	double R(i32 address, double len) //Get Remander
	{
		return (double)(*(i32*)(address) % (int)floor(len));
	}
#pragma endregion
	#pragma region Math ~ Byte
	byte Add(i32 address, mem_s mem, byte value = 00)
	{
		if(mem&&value)
			*(byte*)(address) += value;
			return 00;
		return *(byte*)(address) + value;
	}
	byte Sub(i32 address, mem_s mem, byte value = 00)
	{
		if(value > *(byte*)(address)) printf("Basic Math error\n\targument value [%02X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(byte*)(address) -= value;
			return 00;
		return *(byte*)(address) - value;
	}
	byte Mul(i32 address, mem_s mem, byte value = 00)
	{
		if(mem&&value)
			*(byte*)(address) *= value;
			return 0;
		return *(byte*)(address) * value;
	}
	byte Div(i32 address, mem_s mem, byte value = 00)
	{
		if(value > *(byte*)(address)) printf("Basic Math error\n\targument value [%02X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(byte*)(address) /= value;
			return 0;
		return *(byte*)(address) / value;
	}
	byte R(i32 address, byte len) //Get Remander
	{
		return *(byte*)(address) % len;
	}
	sbyte Add(i32 address, mem_s mem, sbyte value = 00)
	{
		if(mem&&value)
			*(sbyte*)(address) += value;
			return 00;
		return *(sbyte*)(address) + value;
	}
	sbyte Sub(i32 address, mem_s mem, sbyte value = 00)
	{
		if(value > *(sbyte*)(address)) printf("Basic Math error\n\targument value [%02X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(sbyte*)(address) -= value;
			return 00;
		return *(sbyte*)(address) - value;
	}
	sbyte Mul(i32 address, mem_s mem, sbyte value = 00)
	{
		if(mem&&value)
			*(sbyte*)(address) *= value;
			return 0;
		return *(sbyte*)(address) * value;
	}
	sbyte Div(i32 address, mem_s mem, sbyte value = 00)
	{
		if(value > *(sbyte*)(address)) printf("Basic Math error\n\targument value [%02X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(sbyte*)(address) /= value;
			return 0;
		return *(sbyte*)(address) / value;
	}
	sbyte R(i32 address, sbyte len) //Get Remander
	{
		return *(sbyte*)(address) % len;
	}
	#pragma endregion
	#pragma region Math ~ Int16
	//unsigned
	ui16 Add(i32 address, mem_s mem, ui16 value = 0x0000)
	{
		if(mem&&value)
			*(ui16*)(address) += value;
			return 00;
		return *(ui16*)(address) + value;
	}
	ui16 Sub(i32 address, mem_s mem, ui16 value = 0x0000)
	{
		if(value > *(ui16*)(address)) printf("Basic Math error\n\targument value [%04X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(ui16*)(address) -= value;
			return 00;
		return *(ui16*)(address) - value;
	}
	ui16 Mul(i32 address, mem_s mem, ui16 value = 0x0000)
	{
		if(mem&&value)
			*(ui16*)(address) *= value;
			return 0;
		return *(ui16*)(address) * value;
	}
	ui16 Div(i32 address, mem_s mem, ui16 value = 0x000)
	{
		if(value > *(ui16*)(address)) printf("Basic Math error\n\targument value [%04X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(ui16*)(address) /= value;
			return 0;
		return *(ui16*)(address) / value;
	}
	ui16 R(i32 address, ui16 len) //Get Remander
	{
		return *(ui16*)(address) % len;
	}
	ui16 Bitwise(i32 address, bit bitop, mem_s mem, ui16 value=0x0000)//Bitwise(0x00001234, Data::bit::XOR, mem_s::MEM_WRITE, 0x1234);
	{
		switch(bitop)
		{
		case 0://OR
			if(mem&&value)
				*(ui16*)(address) |= value;
				return 0x0000;
			return *(ui16*)(address) | value;
		case 1://XOR
			if(mem&&value)
				*(ui16*)(address) ^= value;
				return 0x0000;
			return *(ui16*)(address) ^ value;
		case 2://AND
			if(mem&&value)
				*(ui16*)(address) &= value;
				return 0x0000;
			return *(ui16*)(address) & value;//got a bad feeling it's going to go logical :(
		case 3://NAND
			if(mem&&value)
				*(ui16*)(address) = (~*(ui16*)(address) & ~value);
				return 0x0000;
			return (~*(ui16*)(address) & ~value);
		case 4://NOR
			if(mem&&value)
				*(ui16*)(address) = (~*(ui16*)(address) | ~value);
				return 0x0000;
			return ~(*(ui16*)(address) | value);
		case 5://NOT
			if(mem&&value)
				*(ui16*)(address) = ~value;
				return 0x0000;
			if(mem)
				*(ui16*)(address) = ~*(ui16*)(address);
				return 0x0000;
			return ~*(ui16*)(address);
		case 6://SHIFT_LEFT
			//Use value argument as amount of bits
			if(mem&&value>=15)
				*(ui16*)(address) <<= ((!value ? 9 : value)&0xFF);
				return 0x0000;
			return (!(*(ui16*)(address) << (!value ? 9 : value)) ? 0 : *(ui16*)(address) << value);
		case 7://SHIFT_RIGHT
			if(mem&&value>=15)
				*(ui16*)(address) >>= ((!value ? 9 : value)&0xFF);
				return 0x0000;
			return (!(*(ui16*)(address) >> (!value ? 9 : value)) ? 0 : *(ui16*)(address) << value);

		}

	}
	//signed
	i16 Add(i32 address, mem_s mem, i16 value = 0x0000)
	{
		if(mem&&value)
			*(i16*)(address) += value;
			return 00;
		return *(i16*)(address) + value;
	}
	i16 Sub(i32 address, mem_s mem, i16 value = 0x0000)
	{
		if(value > *(i16*)(address)) printf("Basic Math error\n\targument value [%04X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(i16*)(address) -= value;
			return 00;
		return *(i16*)(address) - value;
	}
	i16 Mul(i32 address, mem_s mem, i16 value = 0x0000)
	{
		if(mem&&value)
			*(i16*)(address) *= value;
			return 0;
		return *(i16*)(address) * value;
	}
	i16 Div(i32 address, mem_s mem, i16 value = 0x000)
	{
		if(value > *(i16*)(address)) printf("Basic Math error\n\targument value [%04X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(i16*)(address) /= value;
			return 0;
		return *(i16*)(address) / value;
	}
	i16 R(i32 address, i16 len) //Get Remander
	{
		return *(i16*)(address) % len;
	}
	i16 Bitwise(i32 address, bit bitop, mem_s mem, i16 value=0x0000)//Bitwise(0x00001234, Data::bit::XOR, mem_s::MEM_WRITE, 0x1234);
	{
		switch(bitop)
		{
		case 0://OR
			if(mem&&value)
				*(i16*)(address) |= value;
				return 0x0000;
			return *(i16*)(address) | value;
		case 1://XOR
			if(mem&&value)
				*(i16*)(address) ^= value;
				return 0x0000;
			return *(i16*)(address) ^ value;
		case 2://AND
			if(mem&&value)
				*(i16*)(address) &= value;
				return 0x0000;
			return *(i16*)(address) & value;//got a bad feeling it's going to go logical :(
		case 3://NAND
			if(mem&&value)
				*(i16*)(address) = (~*(i16*)(address) & ~value);
				return 0x0000;
			return (~*(i16*)(address) & ~value);
		case 4://NOR
			if(mem&&value)
				*(i16*)(address) = (~*(i16*)(address) | ~value);
				return 0x0000;
			return ~(*(i16*)(address) | value);
		case 5://NOT
			if(mem&&value)
				*(i16*)(address) = ~value;
				return 0x0000;
			if(mem)
				*(i16*)(address) = ~*(i16*)(address);
				return 0x0000;
			return ~*(i16*)(address);
		case 6://SHIFT_LEFT
			//Use value argument as amount of bits
			if(mem&&value>=15)
				*(i16*)(address) <<= ((!value ? 9 : value)&0xFF);
				return 0x0000;
			return (!(*(i16*)(address) << (!value ? 9 : value)) ? 0 : *(i16*)(address) << value);
		case 7://SHIFT_RIGHT
			if(mem&&value>=15)
				*(i16*)(address) >>= ((!value ? 9 : value)&0xFF);
				return 0x0000;
			return (!(*(i16*)(address) >> (!value ? 9 : value)) ? 0 : *(i16*)(address) << value);

		}

	}
	#pragma endregion
	#pragma region Math ~ Int32
	//unsigned
	ui32 Add(i32 address, mem_s mem, ui32 value = 0x00000000)
	{
		if(mem&&value)
			*(ui32*)(address) += value;
			return 00;
		return *(ui32*)(address) + value;
	}
	ui32 Sub(i32 address, mem_s mem, ui32 value = 0x00000000)
	{
		if(value > *(ui32*)(address)) printf("Basic Math error\n\targument value [%08X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(ui32*)(address) -= value;
			return 00;
		return *(ui32*)(address) - value;
	}
	ui32 Mul(i32 address, mem_s mem, ui32 value = 0x00000000)
	{
		if(mem&&value)
			*(ui32*)(address) *= value;
			return 0;
		return *(ui32*)(address) * value;
	}
	ui32 Div(i32 address, mem_s mem, ui32 value = 0x00000000)
	{
		if(value > *(ui32*)(address)) printf("Basic Math error\n\targument value [%08X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(ui32*)(address) /= value;
			return 0;
		return *(ui32*)(address) / value;
	}
	ui32 R(i32 address, ui32 len) //Get Remander
	{
		return *(ui32*)(address) % len;
	}
	ui32 Bitwise(i32 address, bit bitop, mem_s mem, ui32 value=0x00000000)//Bitwise(0x00001234, Data::bit::XOR, mem_s::MEM_WRITE, 0x1234);
	{
		switch(bitop)
		{
		case 0://OR
			if(mem&&value)
				*(ui32*)(address) |= value;
				return 0x00000000;
			return *(ui32*)(address) | value;
		case 1://XOR
			if(mem&&value)
				*(ui32*)(address) ^= value;
				return 0x00000000;
			return *(ui32*)(address) ^ value;
		case 2://AND
			if(mem&&value)
				*(ui32*)(address) &= value;
				return 0x00000000;
			return *(ui32*)(address) & value;//got a bad feeling it's going to go logical :(
		case 3://NAND
			if(mem&&value)
				*(ui32*)(address) = (~*(ui32*)(address) & ~value);
				return 0x00000000;
			return (~*(ui32*)(address) & ~value);
		case 4://NOR
			if(mem&&value)
				*(ui32*)(address) = (~*(ui32*)(address) | ~value);
				return 0x00000000;
			return ~(*(ui32*)(address) | value);
		case 5://NOT
			if(mem&&value)
				*(ui32*)(address) = ~value;
				return 0x00000000;
			if(mem)
				*(ui32*)(address) = ~*(ui32*)(address);
				return 0x00000000;
			return ~*(ui32*)(address);
		case 6://SHIFT_LEFT
			//Use value argument as amount of bits
			if(mem&&value>=31)
				*(ui32*)(address) <<= ((!value ? 24 : value)&0xFFFFFF);
				return 0x00000000;
			return (!(*(ui32*)(address) << (!value ? 24 : value)) ? 0 : *(ui32*)(address) << value);
		case 7://SHIFT_RIGHT
			if(mem&&value>=31)
				*(ui32*)(address) >>= ((!value ? 24 : value)&0xFFFFFF);
				return 0x00000000;
			return (!(*(ui32*)(address) >> (!value ? 24 : value)) ? 0 : *(ui32*)(address) >> value);
		}
	}
	//signed
	i32 Add(i32 address, mem_s mem, i32 value = 0x00000000)
	{
		if(mem&&value)
			*(i32*)(address) += value;
			return 00;
		return *(i32*)(address) + value;
	}
	i32 Sub(i32 address, mem_s mem, i32 value = 0x00000000)
	{
		if(value > *(i32*)(address)) printf("Basic Math error\n\targument value [%08X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(i32*)(address) -= value;
			return 00;
		return *(i32*)(address) - value;
	}
	i32 Mul(i32 address, mem_s mem, i32 value = 0x00000000)
	{
		if(mem&&value)
			*(i32*)(address) *= value;
			return 0;
		return *(i32*)(address) * value;
	}
	i32 Div(i32 address, mem_s mem, i32 value = 0x00000000)
	{
		if(value > *(i32*)(address)) printf("Basic Math error\n\targument value [%08X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(i32*)(address) /= value;
			return 0;
		return *(i32*)(address) / value;
	}
	i32 R(i32 address, i32 len) //Get Remander
	{
		return *(i32*)(address) % len;
	}
	i32 Bitwise(i32 address, bit bitop, mem_s mem, i32 value=0x00000000)//Bitwise(0x00001234, Data::bit::XOR, mem_s::MEM_WRITE, 0x1234);
	{
		switch(bitop)
		{
		case 0://OR
			if(mem&&value)
				*(i32*)(address) |= value;
				return 0x00000000;
			return *(i32*)(address) | value;
		case 1://XOR
			if(mem&&value)
				*(i32*)(address) ^= value;
				return 0x00000000;
			return *(i32*)(address) ^ value;
		case 2://AND
			if(mem&&value)
				*(i32*)(address) &= value;
				return 0x00000000;
			return *(i32*)(address) & value;//got a bad feeling it's going to go logical :(
		case 3://NAND
			if(mem&&value)
				*(i32*)(address) = (~*(i32*)(address) & ~value);
				return 0x00000000;
			return (~*(i32*)(address) & ~value);
		case 4://NOR
			if(mem&&value)
				*(i32*)(address) = (~*(i32*)(address) | ~value);
				return 0x00000000;
			return ~(*(i32*)(address) | value);
		case 5://NOT
			if(mem&&value)
				*(i32*)(address) = ~value;
				return 0x00000000;
			if(mem)
				*(i32*)(address) = ~*(i32*)(address);
				return 0x00000000;
			return ~*(i32*)(address);
		case 6://SHIFT_LEFT
			//Use value argument as amount of bits
			if(mem&&value>=31)
				*(i32*)(address) <<= ((!value ? 24 : value)&0xFFFFFF);
				return 0x00000000;
			return (!(*(i32*)(address) << (!value ? 24 : value)) ? 0 : *(i32*)(address) << value);
		case 7://SHIFT_RIGHT
			if(mem&&value>=31)
				*(i32*)(address) >>= ((!value ? 24 : value)&0xFFFFFF);
				return 0x00000000;
			return (!(*(i32*)(address) >> (!value ? 24 : value)) ? 0 : *(i32*)(address) >> value);
		}
	}
	#pragma endregion
	#pragma region Math ~ Int64
	//unsigned
	ui64 Add(i32 address, mem_s mem, ui64 value = 0x0000000000000000)
	{
		if(mem&&value)
			*(ui64*)(address) += value;
			return 00;
		return *(ui64*)(address) + value;
	}
	ui64 Sub(i32 address, mem_s mem, ui64 value = 0x0000000000000000)
	{
		if(value > *(ui64*)(address)) printf("Basic Math error\n\targument value [%016X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(ui64*)(address) -= value;
			return 00;
		return *(ui64*)(address) - value;
	}
	ui64 Mul(i32 address, mem_s mem, ui64 value = 0x0000000000000000)
	{
		if(mem&&value)
			*(ui64*)(address) *= value;
			return 0;
		return *(ui64*)(address) * value;
	}
	ui64 Div(i32 address, mem_s mem, ui64 value = 0x0000000000000000)
	{
		if(value > *(ui64*)(address)) printf("Basic Math error\n\targument value [%016X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(ui64*)(address) /= value;
			return 0;
		return *(ui64*)(address) / value;
	}
	ui64 R(i32 address, ui64 len) //Get Remander
	{
		return *(ui64*)(address) % len;
	}
	ui64 Bitwise(i32 address, bit bitop, mem_s mem, ui64 value=0x0000000000000000)//Bitwise(0x00001234, Data::bit::XOR, mem_s::MEM_WRITE, 0x1234);
	{
		switch(bitop)
		{
		case 0://OR
			if(mem&&value)
				*(ui64*)(address) |= value;
				return 0x0000000000000000;
			return *(ui64*)(address) | value;
		case 1://XOR
			if(mem&&value)
				*(ui64*)(address) ^= value;
				return 0x0000000000000000;
			return *(ui64*)(address) ^ value;
		case 2://AND
			if(mem&&value)
				*(ui64*)(address) &= value;
				return 0x0000000000000000;
			return *(ui64*)(address) & value;//got a bad feeling it's going to go logical :(
		case 3://NAND
			if(mem&&value)
				*(ui64*)(address) = (~*(ui64*)(address) & ~value);
				return 0x0000000000000000;
			return (~*(ui64*)(address) & ~value);
		case 4://NOR
			if(mem&&value)
				*(ui64*)(address) = (~*(ui64*)(address) | ~value);
				return 0x0000000000000000;
			return ~(*(ui64*)(address) | value);
		case 5://NOT
			if(mem&&value)
				*(ui64*)(address) = ~value;
				return 0x0000000000000000;
			if(mem)
				*(ui64*)(address) = ~*(ui64*)(address);
				return 0x0000000000000000;
			return ~*(ui64*)(address);
		case 6://SHIFT_LEFT
			//Use value argument as amount of bits
			if(mem&&value>=31)
				*(ui64*)(address) <<= ((!value ? 52 : value)&0xFFFFFFFFFFFFFF);
				return 0x0000000000000000;
			return (!(*(ui64*)(address) << (!value ? 52 : value)) ? 0 : *(ui64*)(address) << value);
		case 7://SHIFT_RIGHT
			if(mem&&value>=31)
				*(ui64*)(address) >>= ((!value ? 52 : value)&0xFFFFFFFFFFFFFF);
				return 0x0000000000000000;
			return (!(*(ui64*)(address) >> (!value ? 52 : value)) ? 0 : *(ui64*)(address) >> value);
		}
	}
	//signed
	i64 Add(i32 address, mem_s mem, i64 value = 0x00000000)
	{
		if(mem&&value)
			*(i64*)(address) += value;
			return 00;
		return *(i64*)(address) + value;
	}
	i64 Sub(i32 address, mem_s mem, i64 value = 0x00000000)
	{
		if(value > *(i64*)(address)) printf("Basic Math error\n\targument value [%016X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(i64*)(address) -= value;
			return 00;
		return *(i64*)(address) - value;
	}
	i64 Mul(i32 address, mem_s mem, i64 value = 0x00000000)
	{
		if(mem&&value)
			*(i64*)(address) *= value;
			return 0;
		return *(i64*)(address) * value;
	}
	i64 Div(i32 address, mem_s mem, i64 value = 0x00000000)
	{
		if(value > *(i64*)(address)) printf("Basic Math error\n\targument value [%016X] must be less than the value inside address [%08X]\n", value, address); return 0;
		if(mem&&value)
			*(i64*)(address) /= value;
			return 0;
		return *(i64*)(address) / value;
	}
	i64 R(i32 address, i64 len) //Get Remander
	{
		return *(i64*)(address) % len;
	}
	i64 Bitwise(i32 address, bit bitop, mem_s mem, i64 value=0x0000000000000000)//Bitwise(0x00001234, Data::bit::XOR, mem_s::MEM_WRITE, 0x1234);
	{
		switch(bitop)
		{
		case 0://OR
			if(mem&&value)
				*(i64*)(address) |= value;
				return 0x0000000000000000;
			return *(i64*)(address) | value;
		case 1://XOR
			if(mem&&value)
				*(i64*)(address) ^= value;
				return 0x0000000000000000;
			return *(i64*)(address) ^ value;
		case 2://AND
			if(mem&&value)
				*(i64*)(address) &= value;
				return 0x0000000000000000;
			return *(i64*)(address) & value;//got a bad feeling it's going to go logical :(
		case 3://NAND
			if(mem&&value)
				*(i64*)(address) = (~*(i64*)(address) & ~value);
				return 0x0000000000000000;
			return (~*(i64*)(address) & ~value);
		case 4://NOR
			if(mem&&value)
				*(i64*)(address) = (~*(i64*)(address) | ~value);
				return 0x0000000000000000;
			return ~(*(i64*)(address) | value);
		case 5://NOT
			if(mem&&value)
				*(i64*)(address) = ~value;
				return 0x0000000000000000;
			if(mem)
				*(i64*)(address) = ~*(i64*)(address);
				return 0x0000000000000000;
			return ~*(i64*)(address);
		case 6://SHIFT_LEFT
			//Use value argument as amount of bits
			if(mem&&value>=31)
				*(i64*)(address) <<= ((!value ? 52 : value)&0xFFFFFFFFFFFFFF);
				return 0x0000000000000000;
			return (!(*(i64*)(address) << (!value ? 52 : value)) ? 0 : *(i64*)(address) << value);
		case 7://SHIFT_RIGHT
			if(mem&&value>=31)
				*(i64*)(address) >>= ((!value ? 52 : value)&0xFFFFFFFFFFFFFF);
				return 0x0000000000000000;
			return (!(*(i64*)(address) >> (!value ? 52 : value)) ? 0 : *(i64*)(address) >> value);
		}
	}
	#pragma endregion
};

*/








/*

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ppu-lv2.h>
#include <file.h>
#include <sys/stat.h>

#define SUCCESS 	0
#define FAILED	 	-1

//----------------------------------------
//LV1/2 UTILS
//----------------------------------------

#define SYSCALL_NOT_IMPL		0x3C60800160630003ULL
#define SYSCALL_NOT_IMPL2		0x4E800020

#define LV2_BEGIN_SEEK			0x8000000000000000ULL
#define LV2_END_SEEK			0x8000000000600000ULL

void lv1_poke(uint64_t addr, uint64_t val)
{
    lv2syscall2(9, addr, val);
}

uint64_t lv2_peek(uint64_t addr)
{
    lv2syscall1(6, addr);
	return_to_user_prog(uint64_t);
}

void lv2_poke(uint64_t addr, uint64_t val)
{
    lv2syscall2(7, addr, val);
}

int get_lv2_version()
{
	uint64_t toc = lv2_peek(0x8000000000003000ULL);
	switch(toc)
	{
		case 0x8000000000330540ULL:
			return 0x355C;
		break;
		case 0x800000000034AC80ULL:
			return 0x355D;
		break;
		case 0x8000000000346390ULL:
			return 0x421C;
		break;
		case 0x8000000000363E80ULL:
			return 0x421D;
		break;
		case 0x8000000000348200ULL:
			return 0x430C;
		break;
		case 0x8000000000365CA0ULL:
			return 0x430D;
		break;
		case 0x8000000000348210ULL:
			return 0x431C;
		break;
		case 0x80000000003487D0ULL:
			return 0x440C;
		break;
		case 0x80000000003487E0ULL:
			return 0x441C;
		break;
		case 0x80000000003665C0ULL:
			return 0x441D;
		break;
		case 0x8000000000366BD0ULL:
			return 0x446D;
		break;
		case 0x8000000000348DF0ULL:
			return 0x446C;
		break;
		case 0x800000000034B160ULL:
			return 0x450C;
		break;
		case 0x800000000036EC40ULL:
			return 0x450D;
		break;
		case 0x800000000034B2E0ULL:
			return 0x453C;
		break;
		case 0x8000000000370620ULL:
			return 0x453D;
		break;
		case 0x800000000034E620ULL:
			return 0x455C;
		break;
		case 0x80000000003738E0ULL:
			return 0x455D;
		break;
		case 0x800000000034F950ULL:
			return 0x460C;
		break;
		case 0x800000000034F960ULL:
			if(lv2_peek(0x800000000031EBA8ULL)==0x323031342F31312FULL) return 0x466C;
			else return 0x465C;
		break;
		case 0x8000000000375510ULL:
			if(lv2_peek(0x800000000031EBA8ULL)==0x323031342F31312FULL) return 0x466D;
			else return 0x465D;
		break;
		case 0x800000000034FB10ULL:
			return 0x470C;
		break;
		case 0x8000000000375850ULL:
			return 0x470D;
		break;
		case 0x800000000034FBB0ULL:
			return 0x475C;
		break;
		default:
			return 0;
		break;
	}
	return 0;
}

uint64_t get_syscall_table()
{
	int version = get_lv2_version();
	switch(version)
	{
		case 0x355C:
			return 0x8000000000346570ULL;
		break;
		case 0x355D:
			return 0x8000000000361578ULL;
		break;
		case 0x421C:
			return 0x800000000035BCA8ULL;
		break;
		case 0x421D:
			return 0x800000000037A1B0ULL;
		break;
		case 0x430C:
			return 0x800000000035DBE0ULL;
		break;
		case 0x430D:
			return 0x800000000037C068ULL;
		break;
		case 0x431C:
			return 0x800000000035DBE0ULL;
		break;
		case 0x440C:
			return 0x800000000035E260ULL;
		break;
		case 0x441C:
			return 0x800000000035E260ULL;
		break;
		case 0x441D:
			return 0x800000000037C9E8ULL;
		break;
		case 0x446C:
			return 0x800000000035E860ULL;
		break;
		case 0x446D:
			return 0x800000000037CFE8ULL;
		break;
		case 0x450C:
			return 0x800000000035F0D0ULL;
		break;
		case 0x450D:
			return 0x8000000000383658ULL;
		break;
		case 0x453C:
			return 0x800000000035F300ULL;
		break;
		case 0x453D:
			return 0x8000000000385108ULL;
		break;
		case 0x455C:
			return 0x8000000000362680ULL;
		break;
		case 0x455D:
			return 0x8000000000388488ULL;
		break;
		case 0x460C:
			return 0x8000000000363A18ULL;
		break;
		case 0x465C:
			return 0x8000000000363A18ULL;
		break;
		case 0x465D:
			return 0x800000000038A120ULL;
		break;
		case 0x466C:
			return 0x8000000000363A18ULL;
		break;
		case 0x466D:
			return 0x800000000038A120ULL;
		break;
		case 0x470C:
			return 0x8000000000363B60ULL;
		break;
		case 0x470D:
			return 0x800000000038A368ULL;
		break;
		case 0x475C:
			return 0x8000000000363BE0ULL;
		break;
		default:
			return 0;
		break;
	}
	return 0;
}

int install_syscall(int syscall_number, uint64_t *payload, uint32_t payload_size, uint64_t install_offset)
{
	uint64_t syscall_table = get_syscall_table();
	uint64_t payload_opd = install_offset + payload_size + 0x10;
	int i;	
	if(syscall_table)
	{
		for(i=0;i<(payload_size/8);i++) lv2_poke(install_offset+(i*8), payload[i]);
		lv2_poke(payload_opd, install_offset);
		lv2_poke(syscall_table + (8*syscall_number), payload_opd);
		return SUCCESS;
	}
	return FAILED;
}

void write_htab(void)
{
    uint64_t cont = 0;
    uint64_t reg5, reg6;
    uint32_t val;
    while(cont < 0x80) 
	{
        val = (cont << 7);
        reg5 = lv2_peek(0x800000000f000000ULL | ((uint64_t) val));
        reg6 = lv2_peek(0x800000000f000008ULL | ((uint64_t) val));
        reg6 = (reg6  & 0xff0000ULL) | 0x190ULL;
		lv2syscall8(10, 0, (cont << 3ULL), reg5, reg6, 0, 0, 0, 1);
        cont++;
    }
}

//----------------------------------------
//PRX LOADER
//----------------------------------------

#define SYSCALL8_OPCODE_GET_VERSION				0x7000
#define SYSCALL8_OPCODE_GET_MAMBA				0x7FFF
#define SYSCALL_OPCODE_LOAD_VSH_PLUGIN			0x1EE7
#define SYSCALL_OPCODE_UNLOAD_VSH_PLUGIN		0x364F
#define MAX_VSH_PLUGINS							7
#define BOOT_PLUGINS_FIRST_SLOT					1
#define PRX_PAYLOAD_PATH						"/dev_hdd0/game/PRXLOADER/USRDIR/payloads/payload_%X.bin"
#define PLUGINS_PATH							"/dev_hdd0/game/PRXLOADER/USRDIR/plugins.txt"

int syscall_1022_load_prx_module(uint32_t slot, char * path, void * arg, uint32_t arg_size) //PRX_LOADER PAYLOAD SYSCALL
{
    lv2syscall5(1022, SYSCALL_OPCODE_LOAD_VSH_PLUGIN, (uint64_t) slot, (uint64_t) path, (uint64_t) arg, (uint64_t) arg_size);
	return_to_user_prog(int);
}

int syscall_8_load_prx_module(uint32_t slot, char * path, void * arg, uint32_t arg_size) //COBRA_MAMBA SYSCALL
{
    lv2syscall5(8, SYSCALL_OPCODE_LOAD_VSH_PLUGIN, (uint64_t) slot, (uint64_t) path, (uint64_t) arg, (uint64_t) arg_size);
	return_to_user_prog(int);
}

int sys8_get_version(u32 *version)
{
    lv2syscall2(8, SYSCALL8_OPCODE_GET_VERSION, (u64)version);
    return_to_user_prog(int);
}

int sys8_get_mamba(void)
{
	lv2syscall1(8, SYSCALL8_OPCODE_GET_MAMBA);
    return_to_user_prog(int);
}

int is_cobra(void)
{
    u32 version = 0x99999999;
    if (sys8_get_version(&version) < 0)	return 0;
    if (version != 0x99999999 && sys8_get_mamba() != 0x666)	return SUCCESS;
    return FAILED;
}

int is_mamba(void)
{
	u32 version = 0x99999999;
    if (sys8_get_version(&version) < 0)	return 0;
    if (version != 0x99999999 && sys8_get_mamba() == 0x666)	return SUCCESS;
    return FAILED;
}
uint8_t * read_file(char *path, uint32_t * file_size, uint16_t round)
{
	uint8_t * buf;
	uint32_t size = 0;
	uint16_t rest;
	FILE * f = fopen(path, "rb");
	if(f)
	{
		size = fseek(f, 0, SEEK_END);
		size = ftell(f);
		fseek(f, 0, SEEK_SET);
		if(round)
		{
			rest = size % round;
			if(rest)
				size = size - rest + round;
		}
		buf = malloc(size);
		fread(buf, size, 1, f);
		fclose(f);
		*(file_size) = size;
		return buf;
	}
	else
	{
		*(file_size) = 0;
		return NULL;
	}
}

uint32_t load_all_prx(char * config_path, int use_payload)
{
	char line[256];
	int len;
	uint32_t slot = BOOT_PLUGINS_FIRST_SLOT;
	FILE * f = fopen(config_path,"r");
	if(!f) return 0;
	while(fgets(line, sizeof line, f) != NULL && slot < MAX_VSH_PLUGINS)
	{
		len = strlen(line);
		if(line[0] != '/' || len == 0) continue;
		if(line[len-1] == '\n') line[len-1] = 0;
		if(line[len-2] == '\r') line[len-2] = 0;
		if(use_payload == 0) syscall_8_load_prx_module(slot, line, 0, 0);
		else if(use_payload == 1) syscall_1022_load_prx_module(slot, line, 0, 0);
		slot++; 
	}
	fclose(f);
	return slot;
}

sysFSStat stat1;

int dir_exists(const char *path)
{
    int ret = sysLv2FsStat(path, &stat1);
    if(ret == SUCCESS && S_ISDIR(stat1.st_mode)) return SUCCESS;
    return FAILED;
}

int main()
{
	if (is_cobra() == SUCCESS)
	{
		{lv2syscall3(392, 0x1004, 0xa, 0x1b6); }
		return FAILED;
	}
	else if (is_mamba() == SUCCESS)
	{
		load_all_prx(PLUGINS_PATH, 0);
		{lv2syscall3(392, 0x1004, 0x4, 0x6); }
		return SUCCESS;
	}
	else
	{
		int lv2_version = get_lv2_version();
		if(!lv2_version)
		{
			{lv2syscall3(392, 0x1004, 0xa, 0x1b6); }
			return -1;
		}
		uint64_t * payload;
		uint32_t size;
		char payload_path[256];
		//Patch lv2 protection (rebug only, ps3ita?), No need if not fw 4.xx or 4.53 +
		if ((dir_exists("/dev_flash/rebug") == SUCCESS) || (dir_exists("/dev_flash/ps3ita") == SUCCESS) )
		{
			if((lv2_version > 0x355D) && (lv2_version <= 0x421D))
			{
				lv1_poke(0x370A28 +  0, 0x0000000000000001ULL);
				lv1_poke(0x370A28 +  8, 0xe0d251b556c59f05ULL);
				lv1_poke(0x370A28 + 16, 0xc232fcad552c80d7ULL);
				lv1_poke(0x370A28 + 24, 0x65140cd200000000ULL); 
			}
			else if((lv2_version > 0x421D) && (lv2_version < 0x453C)) 
			{
				lv1_poke(0x370AA8 +  0, 0x0000000000000001ULL);
				lv1_poke(0x370AA8 +  8, 0xe0d251b556c59f05ULL);
				lv1_poke(0x370AA8 + 16, 0xc232fcad552c80d7ULL);
				lv1_poke(0x370AA8 + 24, 0x65140cd200000000ULL); 
			}
		}	
		write_htab();
		sprintf(payload_path, PRX_PAYLOAD_PATH, lv2_version);
		payload = (uint64_t *) read_file(payload_path, &size, 8);
		if(payload == NULL)
		{
			free(payload);
			{lv2syscall3(392, 0x1004, 0xa, 0x1b6); }
			return FAILED;
		}
		if (install_syscall(1022, payload, size, 0x80000000007F0000ULL) == FAILED)
		{
			free(payload);
			{lv2syscall3(392, 0x1004, 0xa, 0x1b6); }
			return FAILED;
		}
		free(payload);
		lv2_poke(0x8000000000003D90ULL, 0x386000014E800020ULL); // /patch permission 4.xx, usually "fixed" by warez payload
		load_all_prx(PLUGINS_PATH, 1);
		{lv2syscall3(392, 0x1004, 0x7, 0x36); }
		return SUCCESS;
	}
}



*/













/*
#include <cellstatus.h>
#include <sys/prx.h>

#include <sys/ppu_thread.h>
#include <sys/timer.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>

// Defines for command type
#define CALL		0x40201021 //if this is changed, the define for it in RSYS.dll must be changed too
#define SYSCALL		0x40201022 //if this is changed, the define for it in RSYS.dll must be changed too
#define EXPORT		0x40201023 //if this is changed, the define for it in RSYS.dll must be changed too
#define IMPORT		0x40201024 //if this is changed, the define for it in RSYS.dll must be changed too
#define WRITETLS	0x40201025 //if this is changed, the define for it in RSYS.dll must be changed too
#define READTLS		0x40201026 //if this is changed, the define for it in RSYS.dll must be changed too
#define CLOSE		0x40201027 //if this is changed, the define for it in RSYS.dll must be changed too

#define DB_PORT		4000  //if this is changed, the define for it in RSYS.dll must be changed too
#define PACK_SIZE	0x400 //if this is changed, the define for it in RSYS.dll must be changed too



struct importStub_s
{
	int16_t ssize;
	int16_t header1;
	int16_t header2;
	int16_t imports;
	int32_t zero1;
	int32_t zero2;
	const char* name;
	uint32_t* fnid;
	opd_s** stub;
	int32_t zero3;
	int32_t zero4;
	int32_t zero5;
	int32_t zero6;
}*imports;

struct exportStub_s
{
	int16_t ssize;
	int16_t header1;
	int16_t header2;
	int16_t exports;
	int32_t zero1;
	int32_t zero2;
	const char* name;
	uint32_t* fnid;
	opd_s** stub;
}*exports;

struct rsys_s
{
	opd_s target;// offset : 0x0
	uint64_t integers[8];// offset : 0x8
	double floats[13];// offset : 0x48
	int32_t stackCount;// offset : 0xB0
	uint64_t stack[0];// offset : 0xB4
}__attribute__((packed));

struct syscall_s
{
	uint64_t num;
	uint64_t registers[8];
};

struct moduleFnid_s
{
	uint32_t fnid;
	char module[0];
};

struct writeTls_s
{
	int32_t offset;
	int32_t value;
};

struct readTls_s
{
	int32_t offset;
};


inline opd_s * find_export(const char* module, uint32_t fnid)
{
	exportStub_s* temp = exports;//exports is initialized in rsys_thread
	while (temp->ssize == 0x1C00)
	{
		if (!strcmp(module, temp->name))
		{
			for (int16_t i = 0; i < temp->exports; i++)
			{
				if (temp->fnid[i] == fnid)
					return temp->stub[i];
			}
		}
		temp++;
	}
	return NULL;
}

inline opd_s * find_import(const char* module, uint32_t fnid)
{
	importStub_s* temp = imports;//imports is initialized in rsys_thread
	while (temp->ssize == 0x2C00)
	{
		if (!strcmp(module, temp->name))
		{
			for (int16_t i = 0; i < temp->imports; i++)
			{
				if (temp->fnid[i] == fnid)
					return temp->stub[i];
			}
		}
		temp++;
	}
	return NULL;
}

inline int slisten(int port, int backlog)
{
	int list_s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	sockaddr_in sa = { };

	sa.sin_family = AF_INET;
	sa.sin_port = htons(port);
	sa.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(list_s, (sockaddr*)&sa, sizeof(sa));
	listen(list_s, backlog);

	return list_s;
}

inline void sclose(int& socket)
{
	if (socket != -1)
	{
		shutdown(socket, SHUT_RDWR);
		socketclose(socket);
		socket = -1;
	}
}

inline void handle_call(int32_t socket, rsys_s* procedure)
{
	//allocate and clean stack + save socket and procedure into global registers if not inlined
	volatile char stack[PACK_SIZE/2] = { };

	register uint64_t stackCount;
	register uint64_t stackOffset;
	register uint64_t procOffset;
	register uint64_t stackValue;

	__asm__ volatile(
		"lwz %[stackCount], 0x8(%[procedure]);"
		"cmpwi %[stackCount], 0;"
		"ble 2f;" //f stands for forward. branch forward to label 2

		//store stack arguments
		"mtctr %[stackCount];"
		"li %[stackOffset], 0x70;"
		"li %[procOffset], 0xB4;"

		"1:;" // -> not naming labels to avoid errors when inlining function
		"ldx %[stackValue], %[procOffset], %[procedure];"
		"stdx %[stackValue], %[stackOffset], 1;"
		"addi %[stackOffset], %[stackOffset], 8;"
		"addi %[procOffset], %[procOffset], 8;"
		"bdnz 1b;" //branch backward to label 1

		"2:;"

		//load doubles into float registers
		"lfd 1, 0xC(%[procedure]);"
		"lfd 2, 0x14(%[procedure]);"
		"lfd 3, 0x1C(%[procedure]);"
		"lfd 4, 0x24(%[procedure]);"
		"lfd 5, 0x2C(%[procedure]);"
		"lfd 6, 0x34(%[procedure]);"
		"lfd 7, 0x3C(%[procedure]);"
		"lfd 8, 0x44(%[procedure]);"
		"lfd 9, 0x4C(%[procedure]);"
		"lfd 10, 0x54(%[procedure]);"
		"lfd 11, 0x5C(%[procedure]);"
		"lfd 12, 0x64(%[procedure]);"
		"lfd 13, 0x6C(%[procedure]);"

		//load integers into general registers
		"ld 3, 0x74(%[procedure]);"
		"ld 4, 0x7C(%[procedure]);"
		"ld 5, 0x84(%[procedure]);"
		"ld 6, 0x8C(%[procedure]);"
		"ld 7, 0x94(%[procedure]);"
		"ld 8, 0x9C(%[procedure]);"
		"ld 9, 0xA4(%[procedure]);"
		"ld 10, 0xAC(%[procedure]);"

		//branch to target
		"std 2, 0x28(1);"
		"lwz 2, 0x4(%[procedure]);"
		"lwz 11, 0x0(%[procedure]);"
		"mtctr 11;"
		"bctrl;"
		"ld 2, 0x28(1);"
		"std 3, -0x4(%[procedure]);"
		"stfd 1, 0x4(%[procedure]);"

		: [stackCount] "=r"(stackCount), [stackOffset] "=r"(stackOffset), [procOffset] "=r"(procOffset), [stackValue] "=r"(stackValue)
		: [procedure] "b"(procedure)
		);

	send(socket, (char*)((int32_t)procedure - 4), PACK_SIZE, 0); // sending packet to client which will then edit output parameters
}

inline uint64_t handle_syscall(uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6, uint64_t arg7, uint64_t arg8, uint64_t num)
{
	system_call_8(num, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
	return_to_user_prog(uint64_t);
}

inline void handle_export(int32_t socket, moduleFnid_s* exp)
{
	opd_s* function = find_export(exp->module, exp->fnid);
	if (function != NULL)
	{
		send(socket, function, sizeof(opd_s), 0);
	}
	else
	{
		opd_s empty = { };
		send(socket, &empty, sizeof(opd_s), 0);
	}
}

inline void handle_import(int conn_s, moduleFnid_s* imp)
{
	opd_s* function = find_import(imp->module, imp->fnid);
	if (function != NULL)
	{
		send(conn_s, function, sizeof(opd_s), 0);
	}
	else
	{
		opd_s empty = { };
		send(conn_s, &empty, sizeof(opd_s), 0);
	}
}

inline void handle_writetls(writeTls_s* write)
{
	register int32_t tls __asm__ ("13");
	*(int32_t*)(tls + write->offset) = write->value;
}

inline void handle_readtls(int32_t socket, readTls_s* read)
{
	register int32_t tls __asm__ ("13");
	int32_t value = *(int32_t*)(tls + read->offset);

	send(socket, &value, sizeof(int32_t), 0);
}

void rsys_thread(uint64_t arg)
{
	//find exports
	exportStub_s *temp_exp = *(exportStub_s**)((*(uint32_t*)0x1008C) + 0x984);
	while ((--temp_exp)->ssize == 0x1C00);
	exports = temp_exp+1;

	//find imports
	uint16_t *temp_imp = (uint16_t*)exports;
	while (*temp_imp++ != 0x2C00);
	imports = (importStub_s*)(temp_imp - 1);

	printf = (int(*)(const char*, ...))find_export("stdc", 0xC01D9F97);

	int32_t list_s = slisten(DB_PORT, 2);

	if (list_s > 0)
	{
		while (true)
		{
			int32_t _sock;
			if((_sock = accept(list_s, NULL, NULL)) > 0)
			{
				sys_ppu_thread_t id;
				sys_ppu_thread_create(&id, rsys_client, _sock, 3000, 0x2000, 0, "rsys_client");
			}
		}
	}
}

void rsys_client(uint64_t _socket)
{
	int32_t socket = (int32_t)_socket;

	printf("new client connected: 0x%08x\n", socket);

	char packet[PACK_SIZE] = { };

	uint32_t procedure = (uint32_t)packet + 4;
	send(socket, &procedure, sizeof(uint32_t), 0); //send start address of packet to client
	syscall_s* sc;

	while (true)
	{
		if (recv(socket, packet, PACK_SIZE, 0) > 0)
		{
			int32_t command = *(int32_t*)packet;
			switch (command)
			{
			case CALL:
				handle_call(socket, (rsys_s*)procedure);
				break;
			case SYSCALL:
				sc = (syscall_s*)procedure;
				*(uint64_t*)packet = handle_syscall(sc->registers[0], sc->registers[1], sc->registers[2], sc->registers[3], sc->registers[4], sc->registers[5], sc->registers[6], sc->registers[7], sc->num);
				send(socket, packet, PACK_SIZE, 0);
				break;
			case EXPORT:
				handle_export(socket, (moduleFnid_s*)procedure);
				break;
			case IMPORT:
				handle_import(socket, (moduleFnid_s*)procedure);
				break;
			case WRITETLS:
				handle_writetls((writeTls_s*)procedure);
				break;
			case READTLS:
				handle_readtls(socket, (readTls_s*)procedure);
				break;
			case CLOSE:
				printf("closing client: 0x%08x\n", socket);
				sclose(socket);
				ppu_thread_exit();
				break;
			}
		}
		sys_timer_usleep(1000);
	}
}

*/

#endif