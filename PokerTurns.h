#ifndef POKERTURNS_H
#define POKERTURN_H
#include "Action.h"
#include "cards.h"
#include "PlayerStatus.h"
#include "GameStatus.h"
#include "player.h"
#include "playerlist.h"

class PokerTurns
{

	private:
		int Round; // 1 - preflop, 2 - flop, 3 - turn, 4 - river
		int Game_Round; // For each player ; 8 Players = 8 Game Rounds
		PlayerList *P_In;
		PlayerStatus *PS_In;
		GameStatus *GS_In;
		Cards *C_In;
		Action *A_In;
		player P;
		int *GSA_In;
		int **PSA_In; //Array of addresses of pointers
	public:
		//RETURN updated remaining Players(Ingame total)
		PokerTurns(int,PlayerList&,PlayerStatus&,GameStatus&,Cards&,Action&,int&,int**);
		void PT_Game_Init(int,int);
		void PT_Round_Init();
		void PT_PreFlop();
		void PT_Flop();
		void PT_Turn();
		void PT_River();
		void PT_Round_Result();

		void PT_setRound(int);
		void PT_setGameRound(int);
		int PT_getRound();
		int PT_getGameRound();
		int RandomNumber();

};
#endif

