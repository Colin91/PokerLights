#include "Action.h"
#include <iostream>
#include <string>

Action::Action(GameStatus &G_In,PlayerStatus &P_In,player &Pl_In)
:A_GS(&G_In),A_PS(&P_In),A_P(&Pl_In)
{

}

int Action::A_Call(int A_Index_In)
{
	int Return=0;
	int getChips = A_PS[A_Index_In].PS_getChips();
	int HBet = A_GS->GS_getHighBet();
	int CBet = A_PS[A_Index_In].PS_getCurrentBet();
	int ABet = A_PS[A_Index_In].PS_getAccBet();
	int Bet = HBet-CBet;
	int AH_Diff = ABet-HBet; // Check if AH_Diff is 0,Check() is valid (Call() is invalid return 0),if AH_Diff !=0 CAll() is valid

	if(AH_Diff!=0)
	{
		if(Bet<getChips)
		{
			A_PS[A_Index_In].PS_Deduct_Chips(Bet);
			A_PS[A_Index_In].PS_setAccBet(HBet);
			A_GS->GS_setPotSize(Bet);
			Return=1;
		}
		else if(Bet>=getChips&&getChips>0)
			 {
			 	 std::cout<<"Player : "<<A_P[A_Index_In].P_getName()<<" , is All in"<<std::endl;
			 	 A_PS[A_Index_In].PS_Deduct_Chips(getChips);
				 int PotSize = A_GS->GS_getPotSize();
				 A_GS->GS_setPotSize(getChips);
				 A_GS->GS_setSidePot(PotSize + getChips);
				 A_PS[A_Index_In].PS_setAllInFlag(1);
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
	int Return=0;
	int HBet = A_GS->GS_getHighBet();
	int ABet = A_PS[A_Index_In].PS_getAccBet();
	int Diff = ABet - HBet;

	if(Diff==0)
	{
		if(Diff==0)
		{
			A_PS[A_Index_In].PS_setEOR(1);
			Return=1;
		}
		else
		{
			A_PS[A_Index_In].PS_setEOR(0);
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
	int getChips = A_PS[A_Index_In].PS_getChips();
	int getHighestBet = A_GS->GS_getHighBet();

	if(A_Raise_In<getChips&&A_Raise_In>getHighestBet)
	{
		A_PS[A_Index_In].PS_Deduct_Chips(A_Raise_In);
		A_PS[A_Index_In].PS_setCurrentBet(A_Raise_In);
		A_PS[A_Index_In].PS_setAccBet(A_Raise_In);
		int AccBet = A_PS[A_Index_In].PS_getAccBet();
		A_GS->GS_setHighBet(AccBet);
		A_GS->GS_setPotSize(A_Raise_In);
		Return=1;
	}
	else if(A_Raise_In>getHighestBet&&getChips>0)
     	 {
     	 	std::cout<<"Player : "<<A_P[A_Index_In].P_getName()<<" , is All in"<<std::endl;
     	 	A_PS[A_Index_In].PS_Deduct_Chips(getChips);
			A_PS[A_Index_In].PS_setCurrentBet(getChips);
			A_PS[A_Index_In].PS_setAllInFlag(1);

			if(getChips>getHighestBet)
			{
				A_PS[A_Index_In].PS_setAccBet(getChips);
				int AccBet = A_PS[A_Index_In].PS_getAccBet();
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
	int inroundtotal = A_GS->GS_getInroundTotal();
	inroundtotal--;
	A_GS->GS_setInroundTotal(inroundtotal);
	A_PS[A_Index_In].PS_setInRound(0);

}






