#include "GameStatus.h"


GameStatus::GameStatus()
{


}

void GameStatus::GS_setPotSize(int GS_PotSize_In)
{
	GS_PotSize = GS_PotSize_In; 
}

void GameStatus::GS_setAddToPotSize(int GS_PotSize_In)
{
	GS_PotSize = GS_PotSize+GS_PotSize_In; //Accumulate
}

void GameStatus::GS_resetPotSize()
{
	GS_PotSize = 0;
}

void GameStatus::GS_setTurnPointer(int GS_Tp_In)
{
	GS_TurnPointer = GS_Tp_In;
}

void GameStatus::GS_setHighBet(int GS_HighBet_In)
{
	GS_HighBet = GS_HighBet_In;
}

void GameStatus::GS_setIngameTotal(int GS_Ingametotal_In)
{
	GS_Ingametotal = GS_Ingametotal_In;
}

void GameStatus::GS_setSmallBlind(int GS_SB_In)
{
	GS_SmallBlind = GS_SB_In;
}

void GameStatus::GS_setBigBlind(int GS_BB_In)
{
	GS_BigBlind = GS_BB_In;
}

void GameStatus::GS_setSidePot(int GS_SP_In)
{
	GS_SidePot = GS_SidePot + GS_SP_In;
}

void GameStatus::GS_resetSidePot()
{
	GS_SidePot = 0;
}

void GameStatus::GS_resetHighBet()
{
	GS_HighBet = 0;
}

void GameStatus::GS_setFlopC1(int GS_Flop_In)
{
    GS_Flop_C1 = GS_Flop_In;
}

void GameStatus::GS_setFlopC2(int GS_Flop_In)
{
    GS_Flop_C2 = GS_Flop_In;
}

void GameStatus::GS_setFlopC3(int GS_Flop_In)
{
    GS_Flop_C3 = GS_Flop_In;
}


void GameStatus::GS_setTurn(int GS_Turn_In)
{
	GS_Turn = GS_Turn_In;
}

void GameStatus::GS_setRiver(int GS_River_In)
{
	GS_River = GS_River_In;
}

void GameStatus::GS_setInroundTotal(int GS_Inroundtotal_In)
{
	GS_Inroundtotal = GS_Inroundtotal_In;
}

void GameStatus::GS_setNumberOfPlayers(int GS_NoOfPlayers_In)
{
	GS_TotalNoPlayers = GS_NoOfPlayers_In;
}

int GameStatus::GS_getInroundTotal()
{
	return GS_Inroundtotal;
}


int GameStatus::GS_getPotSize()
{
	return GS_PotSize;
}

int GameStatus::GS_getTurnPointer()
{
	return GS_TurnPointer;
}

int GameStatus::GS_getHighBet()
{
	return GS_HighBet;
}

int GameStatus::GS_getIngameTotal()
{
	return GS_Ingametotal;
}

int GameStatus::GS_getSmallBlind()
{
	return GS_SmallBlind;
}

int GameStatus::GS_getBigBlind()
{
	return GS_BigBlind;
}

int GameStatus::GS_getSidePot()
{
	return GS_SidePot;
}

int GameStatus::GS_getFlopC1()
{
	return GS_Flop_C1;
}

int GameStatus::GS_getFlopC2()
{
	return GS_Flop_C2;
}

int GameStatus::GS_getFlopC3()
{
	return GS_Flop_C3;
}


int GameStatus::GS_getTurn()
{
	return GS_Turn;
}

int GameStatus::GS_getRiver()
{
	return GS_River;
}

int GameStatus::GS_getNumberOfPlayers()
{
	return GS_TotalNoPlayers;
}



