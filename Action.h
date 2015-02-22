#ifndef ACTION_H
#define ACTION_H
#include "GameStatus.h"
#include "PlayerStatus.h"
#include "player.h"

class Action
{
	private:
		player *A_P;
		PlayerStatus *A_PS;
		GameStatus *A_GS;

	public:
		Action(GameStatus&,PlayerStatus&,player&);
		int A_Call(int); //Highest Bet,Accumulated Bet
		int A_Check(int); //EndOfRound Flag ~ return 0 if EOR Flag = 0, 1 otherwise
		int A_Raise(int,int);//Accumulated Bet, Raise ~ return HighestBet
		int A_Fold(int);	//Ingame = 0;

};
#endif
