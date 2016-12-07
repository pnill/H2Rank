#include <vector>
#include <map>
#include "StringUtil.h"

DWORD Base = (DWORD)GetModuleHandle("h2server.exe");
DWORD RankAddress = (DWORD)GetModuleHandle ("h2server.exe")+0x530ECA;

#pragma region XPData

struct range_
{
	int min;
	int max;
	range_( int Min, int Max )
	{
		min = Min;
		max = Max;
	}
};

struct range2_
{
	int hwin;//higher level wins
	int hloss;//higher level loses
	int lwin;//lower level wins
	int lloss;//lower level loses

	range2_( int Hwin, int Hloss, int Lwin, int Lloss )
	{
		hwin = Hwin;
		hloss = Hloss;
		lwin = Lwin;
		lloss = Lloss;
	}

};

struct range3_
{
	double win;
	double loss;

	range3_( double Win, double Loss )
	{
		win = Win;
		loss = Loss;
	}

};



std::map<int,range_*> XPvsRankChart;
std::map<int,range2_*> DifferenceChart;
std::map<int,range3_*> WinLossFacterChart;

void XPvsRankChart_Init()
{

	XPvsRankChart.insert ( std::pair<int,range_*>(1, new range_(0,0)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(1, new range_(1, 99)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(2, new range_(100, 199)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(3, new range_(200, 299)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(4, new range_(300, 399)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(5, new range_(400, 499)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(6, new range_(500, 599)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(7, new range_(600, 699)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(8, new range_(700, 799)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(9, new range_(800, 899)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(10, new range_(900, 999)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(11, new range_(1000, 1099)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(12, new range_(1100, 1199)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(13, new range_(1200, 1399)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(14, new range_(1400, 1599)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(15, new range_(1600, 1799)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(16, new range_(1800, 1999)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(17, new range_(2000, 2249)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(18, new range_(2250, 2499)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(19, new range_(2500, 2749)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(20, new range_(2750, 2999)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(21, new range_(3000, 3249)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(22, new range_(3250, 3499)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(23, new range_(3500, 3749)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(24, new range_(3750, 3999)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(25, new range_(4000, 4249)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(26, new range_(4250, 4499)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(27, new range_(4500, 4749)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(28, new range_(4750, 4999)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(29, new range_(5000, 5249)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(30, new range_(5250, 5499)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(31, new range_(5500, 5749)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(32, new range_(5750, 5999)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(33, new range_(6000, 6249)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(34, new range_(6250, 6499)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(35, new range_(6500, 6749)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(36, new range_(6750, 6999)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(37, new range_(7000, 7249)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(38, new range_(7250, 7499)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(39, new range_(7500, 7749)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(40, new range_(7750, 7999)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(41, new range_(8000, 8249)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(42, new range_(8250, 8499)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(43, new range_(8500, 8749)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(44, new range_(8750, 8999)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(45, new range_(9000, 9249)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(46, new range_(9250, 9499)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(47, new range_(9500, 9749)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(48, new range_(9750, 9999)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(49, new range_(10000, 10249)) );
	XPvsRankChart.insert ( std::pair<int,range_*>(50, new range_(10250, INT_MAX)) ); //Originally can go up to 1,000,000,000 XP)

	DifferenceChart.insert ( std::pair<int,range2_*>(0, new range2_(100, 100, 100, 100)) );
	DifferenceChart.insert ( std::pair<int,range2_*>(1, new range2_(92, 108, 108, 92)) );
	DifferenceChart.insert ( std::pair<int,range2_*>(2, new range2_(85, 115, 115, 85)) );
	DifferenceChart.insert ( std::pair<int,range2_*>(3, new range2_(79, 121, 121, 79)) );
	DifferenceChart.insert ( std::pair<int,range2_*>(4, new range2_(74, 126, 126, 74)) );
	DifferenceChart.insert ( std::pair<int,range2_*>(5, new range2_(70, 130, 130, 70)) );
	DifferenceChart.insert ( std::pair<int,range2_*>(6, new range2_(66, 134, 134, 66)) );
	DifferenceChart.insert ( std::pair<int,range2_*>(7, new range2_(63, 137, 137, 63)) );
	DifferenceChart.insert ( std::pair<int,range2_*>(8, new range2_(60, 140, 140, 60)) );
	DifferenceChart.insert ( std::pair<int,range2_*>(9, new range2_(58, 142, 142, 58)) );
	DifferenceChart.insert ( std::pair<int,range2_*>(10, new range2_(56, 144, 144, 56)) );
	DifferenceChart.insert ( std::pair<int,range2_*>(11, new range2_(54, 146, 146, 54)) );
	DifferenceChart.insert ( std::pair<int,range2_*>(12, new range2_(53, 147, 147, 53)) );
	DifferenceChart.insert ( std::pair<int,range2_*>(13, new range2_(52, 148, 148, 52)) );
	DifferenceChart.insert ( std::pair<int,range2_*>(14, new range2_(51, 149, 149, 51)) );
	DifferenceChart.insert ( std::pair<int,range2_*>(15, new range2_(50, 150, 150, 50)) );

	WinLossFacterChart.insert ( std::pair<int,range3_*>(0, new range3_(1, 0)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(1, new range3_(1, 0)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(2, new range3_(1, 0.025)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(3, new range3_(1, 0.05)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(4, new range3_(1, 0.075)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(5, new range3_(1, 0.1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(6, new range3_(1, 0.15)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(7, new range3_(1, 0.2)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(8, new range3_(1, 0.275)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(9, new range3_(1, 0.35)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(10, new range3_(1, 0.4)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(11, new range3_(1, 0.45)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(12, new range3_(1, 0.5)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(13, new range3_(1, 0.55)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(14, new range3_(1, 0.575)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(15, new range3_(1, 0.6)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(16, new range3_(1, 0.625)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(17, new range3_(1, 0.65)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(18, new range3_(1, 0.675)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(19, new range3_(1, 0.7)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(20, new range3_(1, 0.725)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(21, new range3_(1, 0.75)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(22, new range3_(1, 0.775)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(23, new range3_(1, 0.8)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(24, new range3_(1, 0.825)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(25, new range3_(1, 0.85)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(26, new range3_(1, 0.875)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(27, new range3_(1, 0.9)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(28, new range3_(1, 0.925)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(29, new range3_(1, 0.95)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(30, new range3_(1, 0.975)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(31, new range3_(1, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(32, new range3_(1, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(33, new range3_(1, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(34, new range3_(1, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(35, new range3_(1, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(36, new range3_(1, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(37, new range3_(1, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(38, new range3_(1, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(39, new range3_(1, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(40, new range3_(1, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(41, new range3_(1, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(42, new range3_(0.95, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(43, new range3_(0.9, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(44, new range3_(0.85, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(45, new range3_(0.8, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(46, new range3_(0.7, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(47, new range3_(0.65, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(48, new range3_(0.6, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(49, new range3_(0.55, 1)) );
	WinLossFacterChart.insert ( std::pair<int,range3_*>(50, new range3_(0.5, 1)) );
}

#pragma endregion

#pragma region H2Rank

class H2Rank
{
public:
	void PlayerQuit( int PlayerSlot );
	void CalculateXP();
	void CalculateRank( int PlayerSlot );
	void UpdateLevel( int PlayerSlot, WORD Level );
	void CleanUp();
	bool IsPlayerValid( int PlayerSlot );
};

#pragma endregion

#pragma region ServerData

struct ServerData{

public:

	char* ServerName;
	char* ServerPath;
	char* Match;

	int GameStatus;
	int PlayerCount;
	DWORD PGC_PlayerCount;
	bool TeamGame;

};



ServerData Server;
CStringUtil StringUtil;
H2Rank RankSystem;

#pragma endregion

#pragma region CPlayerData
class CPlayerData
{
public:
	int place;

};
#pragma endregion

#pragma region CPlayer
class CPlayer
{
public:
	WCHAR GamerTag[32]; 
	char unknown32[32]; 
	BYTE Primary_Armor_Color; 
	BYTE Secondary_Armor_Color;   
	BYTE Primary_Emblem_Color; 
	BYTE Secondary_Emblem_Color; 
	BYTE MPBiped;  
	BYTE Emblem_Foreground; 
	BYTE Emblem_BackGround; 
	BYTE Emblem_Toggle; 
	char unknown72[52];
	BYTE Team;   
	BYTE Handicap; 
	WORD Rank;
	char unknown128[1]; 
	BYTE Logo; 
	char unknown130[2]; 

};
#pragma endregion

#pragma region RankPlayer

class RankPlayer
{

public:
	char *GamerTag;
	WORD level;
	double xp;
	CPlayer* Player;
	CPlayerData* PlayerData;
	bool Quit;
	RankPlayer::RankPlayer( int PlayerSlot );

};

#pragma endregion

#pragma region Player Handling

std::vector<RankPlayer*> CurrentPlayers;

#pragma region RankPlayer Constructor
RankPlayer::RankPlayer( int PlayerSlot )
{

		CPlayer* nPlayer = (CPlayer*)( (Base+0x530E4C) + ( PlayerSlot * 0x128 ) );

		this->GamerTag = new char[32];
		memset(GamerTag,0x00,32);

		StringUtil.ConvertWideStringToAnsi( this->GamerTag, nPlayer->GamerTag );

		this->level = 49;
		//this->level = sql select 
		//this->xp = sql select

		this->Player = nPlayer;
		this->PlayerData = new CPlayerData;
		this->Quit = false;
		bool PlayerExisted = false;
		

		*(WORD*)(RankAddress+( 0x128 * PlayerSlot )) = this->level;

		

		std::vector<RankPlayer*>::iterator Rank_IT = CurrentPlayers.begin();

		while ( Rank_IT != CurrentPlayers.end() ) 
		{    
			RankPlayer* SelPlayer = (*Rank_IT);

			if( strstr( SelPlayer->GamerTag, this->GamerTag ) != NULL )
			{
				if( SelPlayer->Quit == true)
					printf("[H2Rank]: Player %s has re-joined the game\r\n", this->GamerTag );
				
				delete[] SelPlayer->PlayerData;
				delete[] SelPlayer;
				Rank_IT = CurrentPlayers.erase( Rank_IT );
				PlayerExisted = true;
			}

			if( Rank_IT == CurrentPlayers.end() || CurrentPlayers.size() == 0 )
			{
				break;
			}
				++Rank_IT;
		}



	

		CurrentPlayers.push_back( this );

		if( PlayerExisted == false )
		{
			printf("\r\n[H2Rank]: Player: %s has joined the game lvl: %i\r\n", this->GamerTag, this->level );
			printf("[H2Rank]: There are %i players in the game\r\n", CurrentPlayers.size() );
		}

}
#pragma endregion

#pragma region Cleanup

void H2Rank::CleanUp()
{
	std::vector<RankPlayer*>::iterator Rank_IT = CurrentPlayers.begin();
	
	while( Rank_IT != CurrentPlayers.end() )
	{
		RankPlayer* SelPlayer = (*Rank_IT);
			
			if( SelPlayer->Quit == true )
			{
				delete[] SelPlayer->PlayerData;
				delete[] SelPlayer;
				Rank_IT = CurrentPlayers.erase( Rank_IT );
			}

			if( Rank_IT == CurrentPlayers.end() || CurrentPlayers.size() == 0 )
			{
				break;
			}
			++Rank_IT;
	}

	/*for( Rank_IT = CurrentPlayers.begin(); Rank_IT < CurrentPlayers.end(); ++Rank_IT )
	{
		RankPlayer* SelPlayer = (*Rank_IT);

		if( SelPlayer->Quit == true )
		{
			delete[] SelPlayer->PlayerData;
			delete[] SelPlayer;
			Rank_IT = CurrentPlayers.erase( Rank_IT );
			break;
		}
	}*/

}

#pragma endregion

#pragma region PlayerQuit

void H2Rank::PlayerQuit( int PlayerSlot )
{

	CPlayer* nPlayer = (CPlayer*)( (Base+0x530E4C) + ( PlayerSlot * 0x128 ) );
	
	std::vector<RankPlayer*>::iterator Rank_IT;


	for( Rank_IT = CurrentPlayers.begin(); Rank_IT < CurrentPlayers.end(); ++Rank_IT )
	{
		RankPlayer* SelPlayer = (*Rank_IT);

		char* GamerTag = new char[32];
		memset(GamerTag,0x00,32);

		StringUtil.ConvertWideStringToAnsi( GamerTag, nPlayer->GamerTag );


		if( strstr( SelPlayer->GamerTag , GamerTag ) != NULL )
		{
			
				printf("[H2Rank]: Player %s has quit the game.\r\n", SelPlayer->GamerTag );
				printf("[H2Rank]: GameStatus: %i\r\n",Server.GameStatus );
				SelPlayer->Quit = true;

				if( Server.GameStatus == 1 || Server.GameStatus == 0 || Server.GameStatus == 4 )
				{

					delete[] SelPlayer->PlayerData;
					delete[] SelPlayer;
					delete[] GamerTag;
					CurrentPlayers.erase( Rank_IT );
					break;
				}

				
				delete[] GamerTag;
				break;
		}

		delete[] GamerTag;
	}

	

}

#pragma endregion

#pragma region Calculate XP

void H2Rank::CalculateXP()
{	
	Server.TeamGame = (BYTE*)0x30052BF;

	std::vector<RankPlayer*>::iterator Rank_IT;

	int i = 0;

	for( Rank_IT = CurrentPlayers.begin(); Rank_IT < CurrentPlayers.end(); ++Rank_IT )
	{
		RankPlayer* CurPlayer = (*Rank_IT);
		WCHAR *place = new WCHAR[8];
		memcpy(place, (WCHAR*)( ( Base+0x49F6B0 ) + ( 0x110 * i ) + 0xE0 ), 8);
		char* nPlace = new char[8];

		StringUtil.ConvertWideStringToAnsi( nPlace, place );
		std::string sPlace = nPlace;
		sPlace = sPlace.substr(0, sPlace.size()-2);
	
		CurPlayer->PlayerData->place = atoi( sPlace.c_str() );

		printf("[H2Rank]: Player %s was in place %i\r\n", CurPlayer->GamerTag,CurPlayer->PlayerData->place );
		
		++i;
		delete[] place;
		delete[] nPlace;
	}

	double BaseRate = CurrentPlayers.size() - 1;
	
	if( BaseRate == 0 )
	{
		BaseRate = 1;
	}

	double *XPGainTotal = new double[CurrentPlayers.size()];

	if( !Server.TeamGame )
	{
		std::vector<RankPlayer*>::iterator iPlayer;
		
		for( iPlayer = CurrentPlayers.begin(); iPlayer < CurrentPlayers.end(); ++iPlayer ) //++i
		{
			int i = 0;
			RankPlayer* lPlayer = (*iPlayer);

			std::vector<RankPlayer*>::iterator xPlayer;
			for( xPlayer = CurrentPlayers.begin(); xPlayer < CurrentPlayers.end(); ++xPlayer ) //++x
			{
				RankPlayer* pPlayer = (*xPlayer);

				if( lPlayer != pPlayer )
				{
					int Diff = abs( lPlayer->level - pPlayer->level );
					if( Diff > 15 )
					{
						Diff = 15;
					}

					if( lPlayer->level >= pPlayer->level )
					{
						if( lPlayer->PlayerData->place <= pPlayer->PlayerData->place )
						{
							//Higher Win
							double XPGain = DifferenceChart[Diff]->hwin;
							double tmp = WinLossFacterChart[lPlayer->level]->win;
							XPGainTotal[i] += XPGain * tmp;

						}else{
							//Higher loss
							double XPLoss = -DifferenceChart[Diff]->hloss;
							double tmp = WinLossFacterChart[lPlayer->level]->loss;
							XPGainTotal[i] += XPLoss * tmp;

						}
					}else{
						if( lPlayer->PlayerData->place <= pPlayer->PlayerData->place )
						{
							//Lower Win
							double XPGain = DifferenceChart[Diff]->lwin;
							double tmp = WinLossFacterChart[lPlayer->level]->win;
							XPGainTotal[i] += XPGain * tmp;

						}else{
							//Lower Loss
							double XPLoss = -DifferenceChart[Diff]->lloss;
							double tmp = WinLossFacterChart[lPlayer->level]->loss;
							XPGainTotal[i] += XPLoss * tmp;

						}

					}

				}
			}
			++i;
		}
		for( unsigned int i = 0; i < CurrentPlayers.size(); ++i )
		{
			XPGainTotal[i] /= BaseRate;
		}
	}
	else
	{
		for( unsigned int i = 0; i < CurrentPlayers.size(); ++i )
		{
			for( unsigned int x = 0; x < CurrentPlayers.size(); ++x )
			{

				if( CurrentPlayers[i]->Player->Team != CurrentPlayers[x]->Player->Team )
				{
					if( i != x )
					{
						int Diff = abs( CurrentPlayers[i]->level - CurrentPlayers[x]->level );
						if( Diff > 15 )
						{
							Diff = 15;
						}

						if( CurrentPlayers[i]->level >= CurrentPlayers[x]->level )
						{
							if( CurrentPlayers[i]->PlayerData->place <= CurrentPlayers[x]->PlayerData->place )
							{
								//Higher Win
								double XPGain = DifferenceChart[Diff]->hwin;
								double tmp = WinLossFacterChart[CurrentPlayers[i]->level]->win;
								XPGainTotal[i] += XPGain * tmp;

							}else{
								//Higher loss
								double XPLoss = -DifferenceChart[Diff]->hloss;
								double tmp = WinLossFacterChart[CurrentPlayers[i]->level]->loss;
								XPGainTotal[i] += XPLoss * tmp;
							}
						}else{
							if( CurrentPlayers[i]->PlayerData->place <= CurrentPlayers[x]->PlayerData->place )
							{
								//Lower Win
								double XPGain = DifferenceChart[Diff]->lwin;
								double tmp = WinLossFacterChart[CurrentPlayers[i]->level]->win;
								XPGainTotal[i] += XPGain * tmp;

							}else{
								//Lower Loss
								double XPLoss = -DifferenceChart[Diff]->lloss;
								double tmp = WinLossFacterChart[CurrentPlayers[i]->level]->loss;
								XPGainTotal[i] += XPLoss * tmp;

							}

						}
					}
				}

			}
		}
		
		for( unsigned int i = 0; i < CurrentPlayers.size(); ++i )
		{
			XPGainTotal[i] /= BaseRate;
		}
	}

	for (unsigned int i = 0; i < CurrentPlayers.size(); i++)
	{
		CurrentPlayers[i]->xp += XPGainTotal[i];
	}

}

#pragma endregion

#pragma region Calculate Rank

void H2Rank::CalculateRank( int PlayerSlot )
{
		std::vector<RankPlayer*>::iterator Rank_IT = CurrentPlayers.begin()+PlayerSlot;
		RankPlayer* CurPlayer = (*Rank_IT);

		for( int x = 0; x <= 51; x++ )
		{
			
			if( XPvsRankChart[x]->max >= CurPlayer->xp )
			{
				printf("[H2Rank]: PlayerXP(%i): %08X - %08X\r\n", PlayerSlot, &CurPlayer->xp, CurPlayer->xp );
				this->UpdateLevel( PlayerSlot, x );
				break;
			}
		}
}

#pragma endregion

#pragma region Player Valid Check

bool  H2Rank::IsPlayerValid( int PlayerSlot )
{


	WCHAR *GamerTag = new WCHAR[32];
	memcpy(GamerTag, (WCHAR*)( ( Base+0x49F6B0 ) + ( 0x110 * PlayerSlot ) ), 32);
	char* nGamerTag = new char[32];

	StringUtil.ConvertWideStringToAnsi( nGamerTag, GamerTag );


	printf("[H2Rank]: Checking if Player %s is valid\r\n", nGamerTag );

	std::vector<RankPlayer*>::iterator Rank_IT;
	for( Rank_IT = CurrentPlayers.begin(); Rank_IT < CurrentPlayers.end(); ++Rank_IT )
	{
		RankPlayer* SelPlayer = (*Rank_IT);
		if( strstr(SelPlayer->GamerTag, nGamerTag) !=NULL )
		{
			delete[] nGamerTag;
			delete[] GamerTag;
			return true;
		}

	}

	delete[] nGamerTag;
	delete[] GamerTag;

	return false;
}


#pragma endregion

#pragma region Update Level

void H2Rank::UpdateLevel( int PlayerSlot, WORD Level )
{
	if( IsPlayerValid( PlayerSlot ) )
	{
		//CurrentPlayers[PlayerSlot]->Player->Rank = Level;
		//CurrentPlayers[PlayerSlot]->Player->Rank_Update = 2;
		printf("[H2Rank]: UpdateLevel(%i,%i)\r\n",PlayerSlot,Level);

		*(WORD*)(RankAddress+( 0x128 * PlayerSlot )) = Level;
		
	}

	//SQL for updating players...

}

#pragma endregion

#pragma endregion

