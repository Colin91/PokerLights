#include "PlayerStatus.h"

//player P_Obj;

PlayerStatus::PlayerStatus()
{

}

void PlayerStatus::PS_setBlind(int Blind_In)
{
	PS_Blind = Blind_In;
}
void PlayerStatus::PS_setCards(int PS_Cards1_In,int PS_Cards2_In)
{
    PS_Card1 = PS_Cards1_In;
    PS_Card2 = PS_Cards2_In;
}
/*
void PlayerStatus::PS_setCard1(int PS_Cards1_In)
{
    PS_Card1 = PS_Cards1_In;
}

void PlayerStatus::PS_setCard2(int PS_Cards2_In)
{
    PS_Card2 = PS_Cards2_In;
}
*/

void PlayerStatus::PS_setChips(int PS_Chips_In)
{
    PS_Chips = PS_Chips_In;
}

void PlayerStatus::PS_Add_Chips(int PS_Chips_In)
{
	PS_Chips = PS_Chips + PS_Chips_In;
}

void PlayerStatus::PS_Deduct_Chips(int PS_Chips_In)
{
	PS_Chips = PS_Chips - PS_Chips_In;
}

void PlayerStatus::PS_setRank(int PS_Rank_In)
{
    PS_Rank = PS_Rank_In;
}

void PlayerStatus::PS_setIngame(int PS_Ingame_In)
{
	PS_Ingame = PS_Ingame_In;
}


void PlayerStatus::PS_setIndex(int PS_Index_In)
{
	PS_Index = PS_Index_In;
	//return PS_Index;
}

void PlayerStatus::PS_setEOR(int PS_EOR_In)
{
	PS_EOR = PS_EOR_In;
}

void PlayerStatus::PS_setAccBet(int PS_AccBet_In)
{
	PS_AccBet = PS_AccBet_In;
}

void PlayerStatus::PS_setAddAccBet(int PS_AccBet_In)
{
	PS_AccBet = PS_AccBet + PS_AccBet_In;
}

void PlayerStatus::PS_setInRound(int PS_InRound_In)
{
	PS_InRound = PS_InRound_In;
}
void PlayerStatus::PS_setCurrentBet(int PS_CurrBet_In)
{
	PS_CurrentBet = PS_CurrBet_In;
}

void PlayerStatus::PS_resetAccBet()
{
	PS_AccBet = 0;
}

void PlayerStatus::PS_resetCurrentBet()
{
	PS_CurrentBet = 0;
}

void PlayerStatus::PS_setAllInFlag(int PS_AllIn_In)
{
	PS_AllIn_Flag = PS_AllIn_In;
}

void PlayerStatus::PS_setCardArray(int &PS_CardArray_In)
{
	*PS_CardArray = PS_CardArray_In;
}

int PlayerStatus::PS_getBlind()
{
	return PS_Blind;
}

int PlayerStatus::PS_getCard1()
{
    return PS_Card1;
}
int PlayerStatus::PS_getCard2()
{
    return PS_Card2;
}

int PlayerStatus::PS_getChips()
{
    return PS_Chips;
}

int PlayerStatus::PS_getRank()
{
    return PS_Rank;
}

int PlayerStatus::PS_getEOR()
{
	return PS_EOR;
}

int PlayerStatus::PS_getAccBet()
{
	return PS_AccBet;
}

int PlayerStatus::PS_getInRound()
{
	return PS_InRound;
}

int PlayerStatus::PS_getIngame()
{
	return PS_Ingame;
}

int PlayerStatus::PS_getCurrentBet()
{
	return PS_CurrentBet;
}

int PlayerStatus::PS_getAllInFlag()
{
	return PS_AllIn_Flag;
}

int PlayerStatus::PS_getIndex()
{
	return PS_Index;
}

int& PlayerStatus::PS_getCardArray()
{
	return PS_CardArray[0];
}

