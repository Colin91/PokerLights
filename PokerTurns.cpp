#include "PokerTurns.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


PokerTurns::PokerTurns(int Game_Round_In,PlayerList &PL,PlayerStatusList &PSL,GameStatus &GS,Cards &C,Action &A)
:Game_Round(Game_Round_In),P_In(&PL),PSL_In(&PSL),GS_In(&GS),C_In(&C),A_In(&A)
{
}

void PokerTurns::PT_Game_Init(int PT_NOP_In,int Big_Blind_In)
{
	int Blind_Counter=0;
	int Flag=0;
	int getIndex;
	PlayerStatus *PS,*PS1,*PS2;
	int chips=1500;
		 
	PT_setRound(0);
	PT_setGameRound(0);
	GS_In->GS_setPotSize(0);//(GSA_In[0]);
	GS_In->GS_setHighBet(0);
	GS_In->GS_setIngameTotal(PT_NOP_In);
	GS_In->GS_setSmallBlind(Big_Blind_In/2); //Check For Errors
	GS_In->GS_setBigBlind(Big_Blind_In);
	GS_In->GS_setSidePot(0);
	GS_In->GS_setFlopC1(0);
	GS_In->GS_setFlopC2(0);
	GS_In->GS_setFlopC3(0);
	GS_In->GS_setTurn(0);
	GS_In->GS_setRiver(0);
	GS_In->GS_setNumberOfPlayers(PT_NOP_In);
	GS_In->GS_setInroundTotal(0);
	
	PT_setGameRound(0);
	
	for(int i=0;i<PT_NOP_In;i++)
	{
		P = P_In->PL_getPlayer(i);
		getIndex = P.P_getIndex();
		
		PS = PSL_In->PSL_getPlayer(i);
	    PS->PS_setIndex(getIndex);
		PS->PS_setCards(0,0);
		PS->PS_setChips(1500);
		PS->PS_setRank(0);
		PS->PS_setIngame(1);//(PSA_In[i][4]);
		PS->PS_setBlind(0);
		PS->PS_setEOR(0);
		PS->PS_setAccBet(0);
		PS->PS_setInRound(0);
		PS->PS_setCurrentBet(0);
		PS->PS_setAllInFlag(0);
							
	}
	
	
}

void PokerTurns::PT_Round_Init()
{
	int Round_In=0;
	int getIndex;
	Round=Round_In;
	PlayerStatus *PS,*PS1,*PS2;
	
	int SB,BB,TotalBlinds;
	int Blind_Set=1;
	int PT_NOP = GS_In->GS_getIngameTotal();
	int GR = PT_getGameRound();
	int *PlayerHand = new int[7];
	int s=0;

	SB=GS_In->GS_getSmallBlind();
	BB=GS_In->GS_getBigBlind();
	TotalBlinds=SB+BB;

	GS_In->GS_setPotSize(SB+BB);
	GS_In->GS_setHighBet(TotalBlinds);

	for(int i=0;i<PT_NOP;i++)
	{
		P = P_In->PL_getPlayer(i);
		PS = PSL_In->PSL_getPlayer(i);
		getIndex = P.P_getIndex();
		PS->PS_setInRound(1);
		PS->PS_setBlind(Blind_Set);//(PSA_In[i][5]);
		PS->PS_setCurrentBet(0);
		PS->PS_setAccBet(0);
	}
	GS_In->GS_setInroundTotal(1);

	if(GR>PT_NOP)
	{
		GR=0;
		PT_setGameRound(GR);
		
	}

	if(PT_NOP>=3) //3 Player and more
	{
		for(int i=GR;i<PT_NOP;i++)
		{
			s=PS->PS_getIngame();
			PS = PSL_In->PSL_getPlayer(i);

			if(s==1)
			{
				if(Blind_Set<4)
				{
					if(Blind_Set==1)
					{
						PS->PS_setBlind(Blind_Set);
					}
					if(Blind_Set==2)
					{
						PS->PS_setCurrentBet(SB);
					}
					if(Blind_Set==3)
					{
						PS->PS_setCurrentBet(BB);
					}
					Blind_Set++;
				}
				if(Blind_Set>3)
				{
					i=PT_NOP;
				}

			    PS1 = PSL_In->PSL_getPlayer(PT_NOP-1);
			    PS2 = PSL_In->PSL_getPlayer(PT_NOP);				
								
				if((PS1->PS_getBlind()==1)&&(PS2->PS_getBlind()==2))
				{
					PS1 = PSL_In->PSL_getPlayer(0);
					PS1->PS_setBlind(3);
					Blind_Set=4;
					i=PT_NOP;
					s=0;
				}
				if(PS->PS_getBlind()==1)
				{
					Blind_Set=4;
					PS1 = PSL_In->PSL_getPlayer(0);
			   		PS2 = PSL_In->PSL_getPlayer(1);	
					PS1->PS_setBlind(2);
					PS2->PS_setBlind(3);
					i=PT_NOP;
					s=0;
				}
			}
		}
	}

	GR++;
	PT_setGameRound(GR);
	

}

void PokerTurns::PT_PreFlop()
{
	PlayerStatus *PS,*PS1,*PS2;
	
    int players = GS_In->GS_getIngameTotal();
	int input,index;
	string name="";
	int Raise;
	int Return=0;


	int Card1,Card2;
	for(int k=0;k<players;k++)
	{
		PS = PSL_In->PSL_getPlayer(k);
		for(int j=0;j<2;j++)
		{
			Card1 = RandomNumber();
			Card2 = RandomNumber();
		}
		PS->PS_setCards(Card1,Card2);

	}

	for(int i=0;i<players;i++)
	{
		PS = PSL_In->PSL_getPlayer(i);
		if(PS->PS_getInRound()==1)
		{
			do
			{
			    P = P_In->PL_getPlayer(i);
			    index = P.P_getIndex();
			    name = P.P_getName();
			    std::cout<<"-------------------------------------- "<<std::endl;
				std::cout<<"Player : "<<index<<" , "<<name<<" choice "<<std::endl;
				std::cout<<"Enter Choice : ";
				std::cin>>input;
				std::cout<<endl;

				switch(input)
				{
					case 1 : //Call
						Return = A_In->A_Call(i);
						break;

					case 2 : //Raise
						std::cout<<"Enter Raise : ";
						std::cin>>Raise;
						std::cout<<std::endl;
						Return = A_In->A_Raise(i,Raise);
						break;

					case 3 : //Check
						Return = A_In->A_Check(i);
						cout<<"Ret"<<Return<<endl;
						break;

					case 4 : //Fold
						Return = A_In->A_Fold(i);
						break;
				}
                if(Return==1)
                {
                    Return = 0;
                }
			}while(Return!=0);

		}

	}
	PT_setRound(1);
	
}

void PokerTurns::PT_Flop()
{
	PlayerStatus *PS,*PS1,*PS2;
	int input;
	int Raise;
	int Return=0;
	int players = GS_In->GS_getIngameTotal();
	int index;
	string name="";

	int Card;
	Card = RandomNumber();
	GS_In->GS_setFlopC1(Card);
	Card = RandomNumber();
	GS_In->GS_setFlopC2(Card);
	Card = RandomNumber();
	GS_In->GS_setFlopC3(Card);

	for(int i=0;i<players;i++)
	{
		PS = PSL_In->PSL_getPlayer(i);
		if(PS->PS_getInRound()==1)
		{
			do
			{
			    P = P_In->PL_getPlayer(i);
                index = P.P_getIndex();
                name = P.P_getName();
				std::cout<<"Player : "<<index<<" , "<<name<<" choice "<<std::endl;
				std::cout<<"Enter Choice : ";
				std::cin>>input;
				std::cout<<endl;

				switch(input)
				{
					case 1 : //Call
						Return = A_In->A_Call(i);
						break;

					case 2 : //Raise
						std::cout<<"Enter Raise : ";
						std::cin>>Raise;
						std::cout<<std::endl;
						Return = A_In->A_Raise(i,Raise);
						break;

					case 3 : //Check
						Return = A_In->A_Check(i);
						break;

					case 4 : //Fold
						Return = A_In->A_Fold(i);
						break;
				}
                if(Return==1)
                {
                    Return = 0;
                }

			}while(Return!=0);
		}

	}
	PT_setRound((1)+1);
	

}

void PokerTurns::PT_Turn()
{
	PlayerStatus *PS,*PS1,*PS2;
	int input=0;
	int Raise=0;
	int Return=0;
	int players = GS_In->GS_getIngameTotal();
	int index;
	string name="";

	int Card;
	Card = RandomNumber();
	GS_In->GS_setTurn(Card);

	for(int i=0;i<players;i++)
	{
		PS = PSL_In->PSL_getPlayer(i);
		if(PS->PS_getInRound()==1)
		{
			do
			{
				P = P_In->PL_getPlayer(i);
                index = P.P_getIndex();
                name = P.P_getName();
				std::cout<<"Player : "<<index<<" , "<<name<<" choice "<<std::endl;
				std::cout<<"Enter Choice : ";
				std::cin>>input;
				std::cout<<endl;

				switch(input)
				{
					case 1 : //Call
						Return = A_In->A_Call(i);
						break;

					case 2 : //Raise
						std::cout<<"Enter Raise : ";
						std::cin>>Raise;
						std::cout<<std::endl;
						Return = A_In->A_Raise(i,Raise);
						break;

					case 3 : //Check
						Return = A_In->A_Check(i);
						break;

					case 4 : //Fold
						Return = A_In->A_Fold(i);
						break;
				}
				if(Return==1)
                {
                    Return = 0;
                }

			}while(Return!=0);
		}

	}
	PT_setRound(1+2);


}

void PokerTurns::PT_River()
{
	PlayerStatus *PS,*PS1,*PS2;
	int Raise=0;
	int Return=0;
	int players = GS_In->GS_getIngameTotal();
	int index;
	string name;
	int input=0;

	int Card;
	Card = RandomNumber();
	GS_In->GS_setRiver(Card);


	for(int i=0;i<players;i++)
	{
		PS = PSL_In->PSL_getPlayer(i);
		if(PS->PS_getInRound()==1)
		{
			do
			{
				P = P_In->PL_getPlayer(i);
                index = P.P_getIndex();
                name = P.P_getName();
				std::cout<<"Player : "<<index<<" , "<<name<<" choice "<<std::endl;
				std::cout<<"Enter Choice : ";
				std::cin>>input;
				std::cout<<endl;

				switch(input)
				{
					case 1 : //Call
						Return = A_In->A_Call(i);
						break;

					case 2 : //Raise
						std::cout<<"Enter Raise : ";
						std::cin>>Raise;
						std::cout<<std::endl;
						Return = A_In->A_Raise(i,Raise);
						break;

					case 3 : //Check
						Return = A_In->A_Check(i);
						break;

					case 4 : //Fold
						Return = A_In->A_Fold(i);
						break;
				}
				if(Return==1)
                {
                    Return = 0;
                }

			}while(Return!=0);
		}

	}
	PT_setRound(1+3);


}

void PokerTurns::PT_Round_Result()
{
    PlayerStatus *PS,*PS1,*PS2;
	int PlayerIngame = GS_In->GS_getIngameTotal();
	int TotalPlayers = GS_In->GS_getNumberOfPlayers();
	int round = PT_getRound();
	int Pot = GS_In->GS_getPotSize();
	int Cards1 = TotalPlayers*2;
	int *PlayerHandRank = new int[7];//7 Cards + 1 for ingame + 1 for index
	int *PlayerHand = new int[7];
	int *TableCards = new int[5];
	int *Rank = new int[TotalPlayers];
	int CheckPlayers;
	int Counter=0;
	int PlayerRank;
	int Max,Chosen;
	int getChips;
	int ingametotal;


	for(int l=0;l<TotalPlayers;l++)
	{
		PS = PSL_In->PSL_getPlayer(l);
		getChips = PS->PS_getChips();
		if(getChips==0)
		{
			PS->PS_setIngame(0);
		}

	}

	for(int i=0;i<TotalPlayers;i++)
	{
		PS = PSL_In->PSL_getPlayer(i);
		for(int j=0;j<1;j++)
		{
			PlayerHandRank[0]=PS->PS_getCard1();
			PlayerHandRank[1]=PS->PS_getCard2();
			PlayerHandRank[2]=GS_In->GS_getFlopC1();
			PlayerHandRank[3]=GS_In->GS_getFlopC2();
			PlayerHandRank[4]=GS_In->GS_getFlopC3();
			PlayerHandRank[5]=GS_In->GS_getTurn();
			PlayerHandRank[6]=GS_In->GS_getRiver();

			PS->PS_setCardArray(PlayerHandRank[0]);

		}
	}

	if(PlayerIngame==1)
	{
		for(int i=0;i<TotalPlayers;i++)
		{
			PS = PSL_In->PSL_getPlayer(i);
			CheckPlayers = PS->PS_getInRound();
			if(CheckPlayers==1)
			{
				i=TotalPlayers;
				PS->PS_Add_Chips(Pot);
			}

		}
	}
	if(round==1&&PlayerIngame>1)
	{
		for(int i=0;i<TotalPlayers;i++)
		{
			PS = PSL_In->PSL_getPlayer(i);
			Rank[i] = C_In[i].C_Poker_Hands(PlayerHandRank,2);
			PlayerRank = Rank[i];
			PS->PS_setRank(PlayerRank);
		}
		do
		{
			for(int j=0;j<TotalPlayers;j++)
			{
				PS = PSL_In->PSL_getPlayer(j);
				Max = PS->PS_getRank();
				if(PS->PS_getRank()>Max)
				{
					Max = PS->PS_getRank();
					Chosen=j;
				}
			}
			PS = PSL_In->PSL_getPlayer(Chosen);
			if(PS->PS_getInRound()==0)
			{
				PS = PSL_In->PSL_getPlayer(Chosen);
				PlayerHand[0] = PS->PS_getCardArray();
				PlayerHand[0]=0;
				PlayerHand[1]=0;
				PlayerHand[2]=0;
				PlayerHand[3]=0;
				PlayerHand[4]=0;
				PlayerHand[5]=0;
				PlayerHand[6]=0;
				PS->PS_setCardArray(PlayerHand[0]);
			}

		}while(PS->PS_getInRound()==0);
		PS->PS_Add_Chips(Pot);
	}
	if(round==2&&PlayerIngame>1)
	{
		for(int i=0;i<TotalPlayers;i++)
		{
			PS = PSL_In->PSL_getPlayer(i);
			Rank[i] = C_In[i].C_Poker_Hands(PlayerHandRank,5);
			PlayerRank = Rank[i];
			PS->PS_setRank(PlayerRank);
		}
		do
		{
			for(int j=0;j<TotalPlayers;j++)
			{	
				PS = PSL_In->PSL_getPlayer(j);
				Max = PS->PS_getRank();
				if(PS->PS_getRank()>Max)
				{
					Max = PS->PS_getRank();
					Chosen=j;
				}
			}
			PS = PSL_In->PSL_getPlayer(Chosen);
			if(PS->PS_getInRound()==0)
			{
				PlayerHand[0] = PS->PS_getCardArray();
				PlayerHand[0]=0;
				PlayerHand[1]=0;
				PlayerHand[2]=0;
				PlayerHand[3]=0;
				PlayerHand[4]=0;
				PlayerHand[5]=0;
				PlayerHand[6]=0;
				PS->PS_setCardArray(PlayerHand[0]);
			}

		}while(PS->PS_getInRound()==0);
		PS->PS_Add_Chips(Pot);

	}
	if(round==3&&PlayerIngame>1)
	{
		for(int i=0;i<TotalPlayers;i++)
		{
			PS = PSL_In->PSL_getPlayer(i);
			Rank[i] = C_In[i].C_Poker_Hands(PlayerHandRank,6);
			PlayerRank = Rank[i];
			PS->PS_setRank(PlayerRank);
		}
		do
		{
			for(int j=0;j<TotalPlayers;j++)
			{
				PS = PSL_In->PSL_getPlayer(j);
				Max = PS->PS_getRank();
				if(PS->PS_getRank()>Max)
				{
					Max = PS->PS_getRank();
					Chosen=j;
				}
			}
			PS = PSL_In->PSL_getPlayer(Chosen);
			if(PS->PS_getInRound()==0)
			{
				PlayerHand[0] = PS->PS_getCardArray();
				PlayerHand[0]=0;
				PlayerHand[1]=0;
				PlayerHand[2]=0;
				PlayerHand[3]=0;
				PlayerHand[4]=0;
				PlayerHand[5]=0;
				PlayerHand[6]=0;
				PS->PS_setCardArray(PlayerHand[0]);
			}

		}while(PS->PS_getInRound()==0);
		PS->PS_Add_Chips(Pot);

	}
	if(round==4&&PlayerIngame>1)
	{
		for(int i=0;i<TotalPlayers;i++)
		{
			PS = PSL_In->PSL_getPlayer(i);
			Rank[i] = C_In[i].C_Poker_Hands(PlayerHandRank,7);
			PlayerRank = Rank[i];
			PS->PS_setRank(PlayerRank);
		}
		do
		{
			for(int j=0;j<TotalPlayers;j++)
			{
				PS = PSL_In->PSL_getPlayer(j);
				Max = PS->PS_getRank();
				if(PS->PS_getRank()>Max)
				{
					Max = PS->PS_getRank();
					Chosen=j;
				}
			}
			PS = PSL_In->PSL_getPlayer(Chosen);
			if(PS->PS_getInRound()==0)
			{
				PlayerHand[0] = PS->PS_getCardArray();
				PlayerHand[0]=0;
				PlayerHand[1]=0;
				PlayerHand[2]=0;
				PlayerHand[3]=0;
				PlayerHand[4]=0;
				PlayerHand[5]=0;
				PlayerHand[6]=0;
				PS->PS_setCardArray(PlayerHand[0]);
			}

		}while(PS->PS_getInRound()==0);
		PS->PS_Add_Chips(Pot);
	}
}


void PokerTurns::PT_setRound(int PT_Round_In)
{
	Round = PT_Round_In;
}

void PokerTurns::PT_setGameRound(int PT_GameRound_In)
{
	Game_Round = PT_GameRound_In;
}

int PokerTurns::PT_getRound()
{
	return Round;
}

int PokerTurns::PT_getGameRound()
{
	return Game_Round;
}

int PokerTurns::RandomNumber()
{
	int M_Max=52;
    int M_Min=1;
    int M_Random = (rand() % M_Max) + M_Min;
    return M_Random;


}

























