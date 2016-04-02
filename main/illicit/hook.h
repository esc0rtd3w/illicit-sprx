#ifndef __HOOK_H
#define __HOOK_H

#include "natives.h"

using namespace Natives;
	
/*
//int WAIT(int millisecond, int second, int minute, int hour){
Any WAIT(Any milliseconds){


	//int ms = GET_GAME_TIMER() + 1;
	//int sec = GET_GAME_TIMER() + 1000;
	//int min = GET_GAME_TIMER() + 60000;
	//int hour = GET_GAME_TIMER() + 3600000;
		
	//int oneMillisecond = ms - GET_GAME_TIMER();
	//int oneSecond = sec - GET_GAME_TIMER();
	//int oneMinute = min - GET_GAME_TIMER();
	//int oneHour = hour - GET_GAME_TIMER();

	Any time = milliseconds - GET_GAME_TIMER();

	return time;
}
*/


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

/*
int strcmp2(const char* str1, const char* str2)
{
	int diff = 0;

	if (*(str1) == 0x00 || *(str2) == 0x00) { return -1; }

	for (int i = 0; i < 0x600; i++)
	{
		if (*(str1 + i) == 0x00 || *(str2 + i) == 0x00) { break; }
		if (*(str1 + i) != *(str2 + i)) { diff++; }
	}

	return diff;
}
*/

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

/*
int ShutdownPS3(void* destination, const void* source, size_t size)
{
	//lv2syscall4(379,0×100,0,0,0);

	system_call_4(379, 0×100, 0, 0, 0;
	__dcbst(destination);
	__sync();
	__isync();
	return_to_user_prog(int);
}
*/

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

/*
void PatchInJumpAlt(int Address, int Destination)
{
	int FuncBytes[4];
	Destination = *(int*)Destination;
	FuncBytes[0] = 0x3D600000 + ((Destination >> 16) & 0xFFFF);
	if (Destination & 0x8000) FuncBytes[0] += 1;
	FuncBytes[1] = 0x396B0000 + (Destination & 0xFFFF);
	FuncBytes[2] = 0x7D6903A6;
	FuncBytes[3] = 0x4E800420;
	Memcpy((void*)Address, FuncBytes, 4 * 4);
}
*/

/*
void PatchInJump3(int Address, int Destination, bool Linked)
{
	int FuncBytes[4];													// Use this data to copy over the address.
	Destination = *(int*)Destination;									// Get the actual destination address (pointer to void).
	FuncBytes[0] = 0x3D600000 + ((Destination >> 16) & 0xFFFF);			// lis %r11, dest>>16
	if (Destination & 0x8000)											// if bit 16 is 1...
		FuncBytes[0] += 1;
	FuncBytes[1] = 0x396B0000 + (Destination & 0xFFFF);					// addi %r11, %r11, dest&OxFFFF
	FuncBytes[2] = 0x7D6903A6;											// mtctr %r11
	FuncBytes[3] = 0x4E800420;											// bctr
	if (Linked)
		FuncBytes[3] += 1;												// bctrl
	write_process((void*)Address, FuncBytes, 4 * 4);
	//memcpy((void*)Address, FuncBytes, 4 * 4);
}
*/

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

/*
void hookFunctionStartAlt(int Address, int saveStub, int Destination)
{
	saveStub = *(int*)saveStub;
	int BranchtoAddress = Address + (4 * 4);
	int StubData[8];
	StubData[0] = 0x3D600000 + ((BranchtoAddress >> 16) & 0xFFFF);
	if (BranchtoAddress & 0x8000) StubData[0] += 1;
	StubData[1] = 0x396B0000 + (BranchtoAddress & 0xFFFF);
	StubData[2] = 0x7D6903A6;
	Memcpy(&StubData[3], (void*)Address, 4 * 4);
	StubData[7] = 0x4E800420;
	Memcpy((void*)saveStub, StubData, 8 * 4);
	PatchInJumpAlt(Address, Destination);
}
*/

/*
void Stub(...)
{
	__asm("li %r3, 0x3");
}
*/

/*
void is_player_online_Stub(int TimeId)
{
	__asm("li %r3, 0x3");
}
*/

/*
void IS_PLAYER_ONLINE_STUB(int TimeId)
{
	__asm("li %r3, 0x3");
}
*/

/*
int is_player_online_stub()
{
	if (*(char*)(0x22322A0) == 0)
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}
*/

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





// Other Hooks


/*
void HookMoneySpawn(int TimeId)
{
	if(!moneySpawning)
	{
		float* playerCoords = Vec3toFloat(GET_ENTITY_COORDS(GET_PLAYER_PED(SelectedPlayer), true));
		static Any prop_bag = GET_HASH_KEY("prop_money_bag_01");
		REQUEST_MODEL(prop_bag);
		if (HAS_MODEL_LOADED(prop_bag))
		{
			CREATE_AMBIENT_PICKUP(GET_HASH_KEY("PICKUP_MONEY_CASE"), playerCoords, 0, 40000, prop_bag, 0, 1);
			SET_MODEL_AS_NO_LONGER_NEEDED(prop_bag);
		}
	}
	else
	{
			
			
	}
}
*/


/*
void ShowTalkingPlayersTest()
{
	if(chat_thingy)
	{
		int i;
		float pos_y = 0.875;
		for(i = 16;i >= 0;i--)
		{
			if(i < 0) continue;
			if(!NETWORK_IS_PLAYER_ACTIVE(i)) continue;
			if(!NETWORK_IS_PLAYER_TALKING(i)) continue;
			if(NETWORK_IS_PLAYER_MUTED_BY_ME(i)) continue;
			DisplayText(get_player_name555(i), 4, 0.40f, 0.50f, 0.11f, 0.58f, 255, 0, 0, 255, true);
			pos_y -= 0.03;			
		}
	}
}
*/










/*

void PatchInJump(uint64_t Address, int Destination, bool Linked) 
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
	//memcpy((void*)Address, FuncBytes, 4 * 4); //Use for cex
	write_process((void*)Address, FuncBytes, 4 * 4);
}

void HookFunctionStart(int Address, int saveStub, int Destination)
{ //credits to Ethernet for the simplified version
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

*/

/*
int elapse;
void SystemTimer()
{
	unsigned long long Int64 = 0;
	clock_t startClock = clock();
	for(unsigned short i = 0; i < 1024; ++i)
	{
		for(unsigned short j = i; j > 0; --j)
		{
			Int64 += j + i;
		}
	}

	elapse = clock() - startClock;

	//return elapse;

}
*/


#endif

