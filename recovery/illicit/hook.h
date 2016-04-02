#ifndef __HOOK_H
#define __HOOK_H

#include "natives.h"

using namespace Natives;
	


int Memcpy(void* destination, const void* source, size_t size)
{
	
	system_call_4(905, (uint64_t)sys_process_getpid(), (uint64_t)destination, size, (uint64_t)source);
	__dcbst(destination);
	__sync();
	__isync();
	return_to_user_prog(int);
}

bool cstrcmp(const char* s1, const char* s2)
{
	while(*s1 && (*s1==*s2))
		s1++,s2++;
	if(*(const unsigned char*)s1-*(const unsigned char*)s2 == 0)
		return true;
	else
		return false;
}


int console_write(const char * s)
{
	uint32_t len;
	system_call_4(403, 0, (uint64_t) s, std::strlen(s), (uint64_t) &len);
	return_to_user_prog(int);
}

int write_process(void* destination, const void* source, size_t size)
{
	system_call_4(905, (uint64_t)sys_process_getpid(), (uint64_t)destination, size, (uint64_t)source);
	return_to_user_prog(int);
}


void PatchInJump(int Address, int Destination, bool Linked)
{
	int FuncBytes[4];
	Destination = *(int*)Destination;
	FuncBytes[0] = 0x3D600000 + ((Destination >> 16) & 0xFFFF);
	if(Destination & 0x8000) FuncBytes[0] += 1;
	FuncBytes[1] = 0x396B0000 + (Destination & 0xFFFF);
	FuncBytes[2] = 0x7D6903A6;
	FuncBytes[3] = 0x4E800420;
	if(Linked)
	FuncBytes[3] += 1;
	//memcpy((void*)Address, FuncBytes, 4 * 4); //Use for CEX
	write_process((void*)Address, FuncBytes, 4 * 4);
}


void hookFunctionStart(int Address, int saveStub, int Destination)
{
	saveStub = *(int*)saveStub;
	int BranchtoAddress = Address + (4 * 4);
	int StubData[8];
	StubData[0] = 0x3D600000 + ((BranchtoAddress >> 16) & 0xFFFF);
	if (BranchtoAddress & 0x8000) StubData[0] += 1;
	StubData[1] = 0x396B0000 + (BranchtoAddress & 0xFFFF);
	StubData[2] = 0x7D6903A6;
	write_process(&StubData[3], (void*)Address, 4 * 4);
	StubData[7] = 0x4E800420;
	write_process((void*)saveStub, StubData, 8 * 4);
	PatchInJump(Address, Destination, false);
}


// Timer Control For Menu
bool newGameTimerTick = true;
int maxGameTimerCount;
void GameTimer(int tickTime) 
{
	if (newGameTimerTick)
	{
		maxGameTimerCount = GET_GAME_TIMER() + tickTime;
		newGameTimerTick = false;
	}
}

bool isGameTimerReady() 
{
	return GET_GAME_TIMER() > maxGameTimerCount;
}

void ResetGameTimer()
{
	newGameTimerTick = true;
}


bool newGameTimerTick2 = true;
int maxGameTimerCount2;
void GameTimer2(int tickTime) 
{
	if (newGameTimerTick2)
	{
		maxGameTimerCount2 = GET_GAME_TIMER() + tickTime;
		newGameTimerTick2 = false;
	}
}

bool isGameTimerReady2() 
{
	return GET_GAME_TIMER() > maxGameTimerCount2;
}

void ResetGameTimer2()
{
	newGameTimerTick2 = true;
}


#endif

