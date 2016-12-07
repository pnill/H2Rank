#include "stdafx.h"
#include "H2Rank.h"
#include "hook.h"
#include "Structs.h"
#include <windows.h>
#include <stdio.h>


#pragma region Notused
H2RANK_API int nH2Rank=0;
H2RANK_API int fnH2Rank(void)
{
	return 42;
}
CH2Rank::CH2Rank()
{
	return;
}

#pragma endregion

#pragma region hook defines

typedef int(__stdcall *tjoinHook )(void *thisptr, int a2, const void* a3 );
tjoinHook pjoinHook;

typedef int(__stdcall *tRankHook )(void *thisptr, int a2, int a3 );
tRankHook pRankHook;

typedef int( __stdcall *tRankHookC )(void *thisptr, int a2, int a3 );
tRankHookC pRankHookC;

typedef int(__stdcall *tGameStatusUpdate )(void *thisptr, int a2, int a3, int a4 );
tGameStatusUpdate pGameStatusUpdate;

//typedef int(__stdcall *tPlayerQuit )( void* thisptr, int a2, char a3, int a4 );
//tPlayerQuit pPlayerQuit;

typedef int(__stdcall *tPlayerQuit )(void *thisptr, int a2, int a3 );
tPlayerQuit pPlayerQuit;

typedef int(__stdcall *tPlayerJoinAlt )(void *thisptr, int a2, int a3, int a4 );
tPlayerJoinAlt pPlayerJoinAlt;

#pragma endregion

#pragma region hooked functions

#pragma region oldquit
/*
int __stdcall PlayerQuit( void *thisptr, int PlayerSlot, char a3, int a4 )
{
	
	//printf("thisptr: %08X - a3: %08X - a4: %08X\r\n",thisptr,a3,a4);
	if( a3 == 1)
	{
		RankSystem.PlayerQuit( PlayerSlot );
	}

	return pPlayerQuit( thisptr, PlayerSlot, a3, a4 );
}*/
#pragma endregion

int __stdcall PlayerQuit( void *thisptr, int PlayerSlot, int a3 )
{
	printf("playerquit: %08X\r\n",a3);
	if( a3 == 9 || a3 == 2 || a3 == 1 )
	{
		RankSystem.PlayerQuit( PlayerSlot );
	}

	return pPlayerQuit( thisptr, PlayerSlot, a3 );
}

int __stdcall GameUpdateStatus (void *thisptr, int a2, int a3, int a4 )
{
	Server.GameStatus = a2;

	if( Server.GameStatus == 4 )
	{
		//Server.PGC_PlayerCount = *(DWORD*)(Base+0x49F6A0);
		
		RankSystem.CalculateXP();

		for( unsigned int i = 0; i < CurrentPlayers.size(); ++i )
		{
				RankSystem.CalculateRank( i );
		}
		
		RankSystem.CleanUp(); //Prevent memory leaks by removing players who've quit.

	}

	return pGameStatusUpdate( thisptr ,a2 ,a3 ,a4 );
}

int __stdcall RankHookC( void* thisptr, int a2, int a3 )
{
	int rank;

	int rankadd = 0;
	DWORD nRankAddress = RankAddress+(0x128*a2);
	rankadd = *(DWORD*)nRankAddress;

	__asm
	{
			mov edx,a3
			add edx,0x10
			add edx,0x7E
			mov eax,[edx]
			mov rank,eax
			mov eax,rankadd
			mov [edx],eax
			add edx,0x01
			mov [edx],0x01
	}

	return pRankHookC( thisptr, a2, a3 );
}

int __stdcall RankHook( void* thisptr, int a2, int a3 )
{
	int rank;
	int rankadd = 0;
	DWORD nRankAddress = RankAddress+(0x128*a2);
	rankadd = *(DWORD*)nRankAddress;
	
	__asm
	{
			mov edx, a3
			add edx,0x1C
			add edx,0x7E
			mov eax,[edx]
			mov rank,eax
			mov eax,rankadd
			mov [edx],eax
			add edx,0x01
			mov [edx],0x01
	}

	return pRankHook( thisptr, a2, a3 );
}


int __stdcall joinhook( void *thisptr, int a2, const void* a3 )
{
	int rank;
	int rankadd = 0;
	DWORD nRankAddress = RankAddress+(0x128*a2);
	rankadd = *(DWORD*)nRankAddress;

	RankPlayer* nRankPlayer = new RankPlayer(a2);

	__asm
	{
			mov edx,a3
			add edx,0x7E
			mov eax,[edx]
			mov rank,eax
			mov eax,rankadd
			mov [edx],eax
			add edx,0x01
			mov [edx],0x01
	}


	return pjoinHook( thisptr, a2, a3 );
}


#pragma endregion

void Intialize()
{
	SetConsoleTitle("Halo 2 Vista Dedicated Server - H2Rank Injected!");
	printf("\r\nH2Rank has been loaded into this server!\r\n");
	XPvsRankChart_Init();

#pragma region hook calls

	DWORD dwBack;

	DWORD PlayerQuitAddr = Base+0x1B79C6;
	pPlayerQuit = ( tPlayerQuit ) DetourClassFunc( (BYTE*)PlayerQuitAddr, (BYTE*)PlayerQuit, 14 );
	VirtualProtect( pPlayerQuit, 4, PAGE_EXECUTE_READWRITE, &dwBack );

	//DWORD PlayerQuitAddr = Base+0x1B7FB4;
	//pPlayerQuit = ( tPlayerQuit ) DetourClassFunc( (BYTE*)PlayerQuitAddr, (BYTE*)PlayerQuit, 12 );
	//VirtualProtect( pPlayerQuit, 4, PAGE_EXECUTE_READWRITE, &dwBack );
	
	DWORD RankHookCAddr = Base+0x19E5FF;
	pRankHookC = ( tRankHookC ) DetourClassFunc( (BYTE*)RankHookCAddr, (BYTE*)RankHookC, 13);
	VirtualProtect( pRankHookC, 4, PAGE_EXECUTE_READWRITE, &dwBack );

	DWORD RankHookAddr = Base+0x1A42AC;
	pRankHook = ( tRankHook ) DetourClassFunc( (BYTE*)RankHookAddr, (BYTE*)RankHook, 20 );
	VirtualProtect( pRankHook, 4, PAGE_EXECUTE_READWRITE, &dwBack );

	DWORD CallAddr = Base+0x19D2B6;
	pjoinHook = ( tjoinHook ) DetourClassFunc( (BYTE*)CallAddr, (BYTE*) joinhook, 23 );
	VirtualProtect( pjoinHook, 4, PAGE_EXECUTE_READWRITE, &dwBack );

	DWORD GameStatusUpdateAddr = Base+0x01BCC47;
	pGameStatusUpdate = ( tGameStatusUpdate ) DetourClassFunc( (BYTE*)GameStatusUpdateAddr, (BYTE*) GameUpdateStatus, 11 );
	VirtualProtect( pGameStatusUpdate, 4, PAGE_EXECUTE_READWRITE, &dwBack );

#pragma endregion

}
