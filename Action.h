#ifndef ACTION_H
#define ACTION_H
#include "GameStatus.h"
#include "PlayerStatus.h"
#include "player.h"
#include "PlayerStatusList.h"

class Action
{
	private:
		player *A_P;
		PlayerStatusList *A_PS;
		GameStatus *A_GS;
		int *GSA_In;
		int **PSA_In;

	public:
		Action(GameStatus&,PlayerStatusList&,player&);
		int A_Call(int); //Highest Bet,Accumulated Bet
		int A_Check(int); //EndOfRound Flag ~ return 0 if EOR Flag = 0, 1 otherwise
		int A_Raise(int,int);//Accumulated Bet, Raise ~ return HighestBet
		int A_Fold(int);	//Ingame = 0;

};
#endif
