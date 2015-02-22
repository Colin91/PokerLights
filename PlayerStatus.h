#ifndef PLAYERSTATUS_H
#define PLAYERSTATUS_H
#include "player.h"



class PlayerStatus : public player
{
	private:

		player PS;
		int PS_Ingame;
		int PS_InRound;
		int PS_Index;
		int PS_Chips;

		int PS_Card1,PS_Card2;
		int PS_Rank; // Card Hand Rank
		int PS_Blind; // 0-None, 1-Button, 2-SB, 3-BB // Equivalent of Initial Bet
		int PS_EOR; //End of Round, if = 1 ,Player has the right to check else not
		int PS_AccBet; //Accumulated Bet
		int PS_CurrentBet;
		int PS_AllIn_Flag;
		int PS_CardArray[7];

	public:

	 PlayerStatus(int,int,int,int);
	 void PS_setCards(int,int);
	 //void PS_setCard2(int);
	 void PS_setChips(int);
	 void PS_Add_Chips(int);
	 void PS_Deduct_Chips(int);
	 void PS_setRank(int);
	 void PS_setIngame(int); //Only used for players with 0 chips(Defeated Players)
	 void PS_setBlind(int);
	 void PS_setEOR(int);//1 or 0
	 void PS_setIndex(int);
	 void PS_setAccBet(int);
	 void PS_setAddAccBet(int);
	 void PS_setCurrentBet(int);
	 void PS_setInRound(int);
	 void PS_resetAccBet();
	 void PS_resetCurrentBet();
	 void PS_setAllInFlag(int);
	 void PS_setCardArray(int&);

	 int PS_getCard1();
	 int PS_getCard2();
	 int PS_getChips();
	 int PS_getRank();
	 int PS_getIngame();
	 int PS_getBlind();
	 int PS_getEOR();
	 int PS_getAccBet();
	 int PS_getInRound();
     int PS_getCurrentBet();
     int PS_getAllInFlag();
     int& PS_getCardArray();
     int PS_getIndex();
};
#endif

