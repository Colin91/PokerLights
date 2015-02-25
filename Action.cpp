#include "Action.h"
#include <iostream>
#include <string>

Action::Action(GameStatus &G_In,PlayerStatusList &P_In,player &Pl_In)
:A_GS(&G_In),A_PS(&P_In),A_P(&Pl_In)
{

}

int Action::A_Call(int A_Index_In)
{
	int Return=0;
	PlayerStatus *PS;
	PS = A_PS->PSL_getPlayer(A_Index_In);
	int getChips = PS->PS_getChips();
	int HBet = A_GS->GS_getHighBet();
	int CBet = PS->PS_getCurrentBet();
	int ABet = PS->PS_getAccBet();
	int Bet = HBet-CBet;
	int AH_Diff = HBet-ABet;
	std::cout<<"Bet"<<Bet<<std::endl;
	std::cout<<"AH_Diff"<<AH_Diff<<std::endl; 

	if(AH_Diff!=0)
	{
		if(Bet<getChips)
		{
			PS->PS_Deduct_Chips(Bet);
			PS->PS_setAccBet(HBet);
			A_GS->GS_setPotSize(Bet);
			Return=1;
		}
		else if(Bet>=getChips&&getChips>0)
			 {
			 	 std::cout<<"Player : "<<A_P[A_Index_In].P_getName()<<" , is All in"<<std::endl;
			 	 PS->PS_Deduct_Chips(getChips);
				 int PotSize = A_GS->GS_getPotSize();
				 A_GS->GS_setPotSize(getChips);
				 A_GS->GS_setSidePot(PotSize + getChips);
				 PS->PS_setAllInFlag(1);
				 Return=1;
			 }
	}
	else
	{
		std::cout<<"Invalid, Player must either Checks, Raise or Fold"<<std::endl;
		Return = 0;
	}


	return Return;

}

int Action::A_Check(int A_Index_In)
{
	PlayerStatus *PS;
	PS = A_PS->PSL_getPlayer(A_Index_In);
	int Return=0;
	int HBet = A_GS->GS_getHighBet();
	int ABet = PS->PS_getAccBet();
	int Diff = HBet - ABet;

	if(Diff==0)
	{
		if(Diff==0)
		{
			PS->PS_setEOR(1);
			Return=1;
		}
		else
		{
			PS->PS_setEOR(0);
			Return=1;
		}
	}
	else
	{
		std::cout<<"Invalid, Player must either Call, Raise or Fold"<<std::endl;
		Return=0;
	}

	return Return; // If return = 1, Check is valid. If return = 0 , Check is invalid (user must either Call,Raise or Fold)

}

int Action::A_Raise(int A_Index_In,int A_Raise_In) //Raise has to be greater than Call or greater than previous Raise
{
	int Return=0;
	PlayerStatus *PS;
	PS = A_PS->PSL_getPlayer(A_Index_In);
	int getChips = PS->PS_getChips();
	int getHighestBet = A_GS->GS_getHighBet();

	if(A_Raise_In<getChips&&A_Raise_In>getHighestBet)
	{
		PS->PS_Deduct_Chips(A_Raise_In);
		PS->PS_setCurrentBet(A_Raise_In);
		PS->PS_setAccBet(A_Raise_In);
		int AccBet = PS->PS_getAccBet();
		A_GS->GS_setHighBet(AccBet);
		A_GS->GS_setPotSize(A_Raise_In);
		Return=1;
	}
	else if(A_Raise_In>getHighestBet&&getChips>0)
     	 {
     	 	std::cout<<"Player : "<<A_P[A_Index_In].P_getName()<<" , is All in"<<std::endl;
     	 	PS->PS_Deduct_Chips(getChips);
			PS->PS_setCurrentBet(getChips);
			PS->PS_setAllInFlag(1);

			if(getChips>getHighestBet)
			{
				PS->PS_setAccBet(getChips);
				int AccBet = PS->PS_getAccBet();
				A_GS->GS_setHighBet(AccBet);
				A_GS->GS_setPotSize(getChips);
				int PotSize1 = A_GS->GS_getPotSize();
			 	A_GS->GS_setSidePot(PotSize1 + getChips);

			}
			else
			{
				A_GS->GS_setPotSize(getChips);
				int PotSize = A_GS->GS_getPotSize();
			 	A_GS->GS_setSidePot(PotSize + getChips);
			}

			Return=1;
		 }
	if(A_Raise_In<getHighestBet)
	{
		std::cout<<"Invalid, Raise must be greater than : "<<getHighestBet<<std::endl;
		Return=0;
	}
	return Return;

}

int Action::A_Fold(int A_Index_In)
{
	PlayerStatus *PS;
	PS = A_PS->PSL_getPlayer(A_Index_In);
	int inroundtotal = A_GS->GS_getInroundTotal();
	inroundtotal--;
	A_GS->GS_setInroundTotal(inroundtotal);
	PS->PS_setInRound(0);

}






