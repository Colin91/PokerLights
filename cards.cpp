#include "cards.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

Cards::Cards()
{

}


int Cards::C_Card(int C_0_Num_In,int C_Flag_In) //C_Card is a function that accepts a Randomized no. from 1 to 52 and returns the RANK of the card if C_Flag_In=0 OR returns TYPE if C_Flag_In=1.
{

    int Fixed_No_1 = 13;
    int Fixed_No_2 = 26;
    int Fixed_No_3 = 39;
    int Flagging;
    int C_0_type;
    int C_0_rank;

    if(C_0_Num_In>=1&&C_0_Num_In<=13)
    {
        C_0_type = 1; //Spades
        C_0_rank = C_0_Num_In;

    }
    if(C_0_Num_In>=14&&C_0_Num_In<=26)
    {
        C_0_type = 2; //Hearts
        C_0_rank = (C_0_Num_In-Fixed_No_1);
    }
    if(C_0_Num_In>=27&&C_0_Num_In<=39)
    {
        C_0_type = 3; //Diamonds
        C_0_rank = (C_0_Num_In-Fixed_No_2);

    }
    if(C_0_Num_In>=40&&C_0_Num_In<=52)
    {
        C_0_type = 4; //Clubs
        C_0_rank = (C_0_Num_In-Fixed_No_3);
    }

    if(C_Flag_In==0)
    {
        Flagging = C_0_rank;
    }
    if(C_Flag_In==1)
    {
        Flagging = C_0_type;
    }
    return Flagging;

}

int Cards::C_Draw(int C_0_Num_In,int C_1_Num_In) //C_Draw is a function that multiplies the RANK of the first two cards drawn
{

    int C1 = C_Card(C_0_Num_In,0);
    int C2 = C_Card(C_1_Num_In,0);


    for(int i=C_0_Num_In;i<C_Total;i++)
    {
        C_card_pointer01[C_0_Num_In] = C_card_pointer01[C_0_Num_In+1];
    }
    C_Total = C_Total - 2;
    int C3 = C1*C2;
    return C3;

}

void Cards::C_Rank(int C)
{
    if(C==1)
    {
        cout<<"HighCard"<<endl;
    }
    if(C==2)
    {
        cout<<"Pair"<<endl;
    }
    if(C==3)
    {
        cout<<"Two Pair"<<endl;
    }
    if(C==4)
    {
        cout<<"Three Of a Kind"<<endl;
    }
    if(C==5)
    {
        cout<<"Straight"<<endl;
    }
    if(C==6)
    {
        cout<<"Flush"<<endl;
    }
    if(C==7)
    {
        cout<<"Full House"<<endl;
    }
    if(C==8)
    {
        cout<<"Four Of a Kind"<<endl;
    }
    if(C==9)
    {
        cout<<"Straight Flush"<<endl;
    }
    if(C==10)
    {
        cout<<"Royal Flush"<<endl;
    }

}

int Cards::C_getHighCard(int *PT,int Cards_Poker)
{
    int C_CT[Cards_Poker]; //TYPE
    int C_HC[Cards_Poker]; //RANK
    int C_Temp;


    //the Card int object Pointer is pointing to the address of the Parameter

    if(Cards_Poker==2)
    {

        int C1 = C_Card(PT[0],0);
        int C2 = C_Card(PT[1],0);

        int CT1 = C_Card(PT[0],1);
        int CT2 = C_Card(PT[1],1);

        C_CT[0] = CT1;
        C_CT[1] = CT2;

        C_HC[0] = C1;
        C_HC[1] = C2;

    }

    if(Cards_Poker==5)
    {

        int C1 = C_Card(PT[0],0);
        int C2 = C_Card(PT[1],0);
        int C3 = C_Card(PT[2],0);
        int C4 = C_Card(PT[3],0);
        int C5 = C_Card(PT[4],0);

        int CT1 = C_Card(PT[0],1);
        int CT2 = C_Card(PT[1],1);
        int CT3 = C_Card(PT[2],1);
        int CT4 = C_Card(PT[3],1);
        int CT5 = C_Card(PT[4],1);

        C_CT[0] = CT1;
        C_CT[1] = CT2;
        C_CT[2] = CT3;
        C_CT[3] = CT4;
        C_CT[4] = CT5;

        C_HC[0] = C1;
        C_HC[1] = C2;
        C_HC[2] = C3;
        C_HC[3] = C4;
        C_HC[4] = C5;


    }


    if(Cards_Poker==6)
    {

        int C1 = C_Card(PT[0],0);
        int C2 = C_Card(PT[1],0);
        int C3 = C_Card(PT[2],0);
        int C4 = C_Card(PT[3],0);
        int C5 = C_Card(PT[4],0);
        int C6 = C_Card(PT[5],0);

        int CT1 = C_Card(PT[0],1);
        int CT2 = C_Card(PT[1],1);
        int CT3 = C_Card(PT[2],1);
        int CT4 = C_Card(PT[3],1);
        int CT5 = C_Card(PT[4],1);
        int CT6 = C_Card(PT[5],1);

        C_CT[0] = CT1;
        C_CT[1] = CT2;
        C_CT[2] = CT3;
        C_CT[3] = CT4;
        C_CT[4] = CT5;
        C_CT[5] = CT6;

        C_HC[0] = C1;
        C_HC[1] = C2;
        C_HC[2] = C3;
        C_HC[3] = C4;
        C_HC[4] = C5;
        C_HC[5] = C6;


    }


    if(Cards_Poker==7)
    {

        int C1 = C_Card(PT[0],0);
        int C2 = C_Card(PT[1],0);
        int C3 = C_Card(PT[2],0);
        int C4 = C_Card(PT[3],0);
        int C5 = C_Card(PT[4],0);
        int C6 = C_Card(PT[5],0);
        int C7 = C_Card(PT[6],0);

        int CT1 = C_Card(PT[0],1);
        int CT2 = C_Card(PT[1],1);
        int CT3 = C_Card(PT[2],1);
        int CT4 = C_Card(PT[3],1);
        int CT5 = C_Card(PT[4],1);
        int CT6 = C_Card(PT[5],1);
        int CT7 = C_Card(PT[6],1);

        C_CT[0] = CT1;
        C_CT[1] = CT2;
        C_CT[2] = CT3;
        C_CT[3] = CT4;
        C_CT[4] = CT5;
        C_CT[5] = CT6;
        C_CT[6] = CT7;

        C_HC[0] = C1;
        C_HC[1] = C2;
        C_HC[2] = C3;
        C_HC[3] = C4;
        C_HC[4] = C5;
        C_HC[5] = C6;
        C_HC[6] = C7;


    }


    for(int i=0;i<Cards_Poker;i++)
    {
        if(C_HC[i] > C_Temp)
        {
             C_Temp = C_HC[i];

        }

    }
    return C_Temp;

}



//THE PARAMETER BELOW NEEDS TO BE AN ARRAY not INDIVIDUAL Numbers
int Cards::C_Poker_Hands(int *PT,int Cards_Poker) //2,8,23,31,44 (3S,9S,JH,6D,6C) after C_Card class 2,8,10,5,5 or 2,10,10,5,5
{

    int C_CT[Cards_Poker]; //TYPE
    int C_HC[Cards_Poker]; //RANK

	int C_FlushCard;
    int C_SmallCard;
    int C_HighCard;

    int C_Flag=0;
    int C_Flag_1=0;
    int C_Flag_2=0;
    int C_StraightHand[7];
    int C_Poker_R;
    int C_Temp=0;
    int C_Swaps;

    int Counter=0;
	int i=0;
	int SF_Flush=0;
	int SF_Straight=0;
	int Save_Value=0;

    //the Card int object Pointer is pointing to the address of the Parameter

    if(Cards_Poker==2)
    {

        int C1 = C_Card(PT[0],0);
        int C2 = C_Card(PT[1],0);

        int CT1 = C_Card(PT[0],1);
        int CT2 = C_Card(PT[1],1);

        C_CT[0] = CT1;
        C_CT[1] = CT2;

        C_HC[0] = C1;
        C_HC[1] = C2;

    }

    if(Cards_Poker==5)
    {

        int C1 = C_Card(PT[0],0);
        int C2 = C_Card(PT[1],0);
        int C3 = C_Card(PT[2],0);
        int C4 = C_Card(PT[3],0);
        int C5 = C_Card(PT[4],0);

        int CT1 = C_Card(PT[0],1);
        int CT2 = C_Card(PT[1],1);
        int CT3 = C_Card(PT[2],1);
        int CT4 = C_Card(PT[3],1);
        int CT5 = C_Card(PT[4],1);

        C_CT[0] = CT1;
        C_CT[1] = CT2;
        C_CT[2] = CT3;
        C_CT[3] = CT4;
        C_CT[4] = CT5;

        C_HC[0] = C1;
        C_HC[1] = C2;
        C_HC[2] = C3;
        C_HC[3] = C4;
        C_HC[4] = C5;


    }


    if(Cards_Poker==6)
    {

        int C1 = C_Card(PT[0],0);
        int C2 = C_Card(PT[1],0);
        int C3 = C_Card(PT[2],0);
        int C4 = C_Card(PT[3],0);
        int C5 = C_Card(PT[4],0);
        int C6 = C_Card(PT[5],0);

        int CT1 = C_Card(PT[0],1);
        int CT2 = C_Card(PT[1],1);
        int CT3 = C_Card(PT[2],1);
        int CT4 = C_Card(PT[3],1);
        int CT5 = C_Card(PT[4],1);
        int CT6 = C_Card(PT[5],1);

        C_CT[0] = CT1;
        C_CT[1] = CT2;
        C_CT[2] = CT3;
        C_CT[3] = CT4;
        C_CT[4] = CT5;
        C_CT[5] = CT6;

        C_HC[0] = C1;
        C_HC[1] = C2;
        C_HC[2] = C3;
        C_HC[3] = C4;
        C_HC[4] = C5;
        C_HC[5] = C6;


    }


    if(Cards_Poker==7)
    {

        int C1 = C_Card(PT[0],0);
        int C2 = C_Card(PT[1],0);
        int C3 = C_Card(PT[2],0);
        int C4 = C_Card(PT[3],0);
        int C5 = C_Card(PT[4],0);
        int C6 = C_Card(PT[5],0);
        int C7 = C_Card(PT[6],0);

        int CT1 = C_Card(PT[0],1);
        int CT2 = C_Card(PT[1],1);
        int CT3 = C_Card(PT[2],1);
        int CT4 = C_Card(PT[3],1);
        int CT5 = C_Card(PT[4],1);
        int CT6 = C_Card(PT[5],1);
        int CT7 = C_Card(PT[6],1);

        C_CT[0] = CT1;
        C_CT[1] = CT2;
        C_CT[2] = CT3;
        C_CT[3] = CT4;
        C_CT[4] = CT5;
        C_CT[5] = CT6;
        C_CT[6] = CT7;

        C_HC[0] = C1;
        C_HC[1] = C2;
        C_HC[2] = C3;
        C_HC[3] = C4;
        C_HC[4] = C5;
        C_HC[5] = C6;
        C_HC[6] = C7;


    }




	//Organize C_HC
    do
    {
        C_Swaps=0;
        for(i=0;i<Cards_Poker;i++)
        {
             if(C_HC[i]>C_HC[i+1]) //6>4 //Organizing descending order
             {
                 int C_Proxy = C_HC[i]; //Proxy==6
                 C_HC[i] = C_HC[i+1]; //Put 4 in 1st
                 C_HC[i+1] = C_Proxy; //Put 6 in 2nd
                 C_Swaps++;
                 C_Poker_R=1;

             }

        }

     }while(C_Swaps!=0);

	//Organize C_CT
    do
    {
        C_Swaps=0;
        for(i=0;i<Cards_Poker;i++)
        {
             if(C_CT[i]>C_CT[i+1]) //6>4 //Organizing from descending to ascending order
             {
                 int C_Proxy = C_CT[i]; //Proxy==6
                 C_CT[i] = C_CT[i+1]; //Put 4 in 1st
                 C_CT[i+1] = C_Proxy; //Put 6 in 2nd
                 C_Swaps++;
             }

        }

     }while(C_Swaps!=0);

    // ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    for(i=0;i<Cards_Poker;i++)
    {
        if(C_HC[i] > C_Temp)
        {
            C_Temp = C_HC[i];
            C_Poker_R=1;
        }

    }
    Counter=0;


    // ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//ONEPAIR
    for(i=0;i<Cards_Poker;i++)  // Use nCr combinatorics formula to formulate how many subsets needed from the larger set
    {
        if(C_HC[i]==C_HC[i+1])
        {
            C_Poker_R=2;
            i=Cards_Poker-1;

        }
    }

    // ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int C_TwoPair=0;
    int Proxy_Card;

	//TWOPAIR
    for(i=0;i<Cards_Poker;i++)  // Use nCr combinatorics formula to formulate how many subsets needed from the larger set
    {
        int C_Proxy=0;
        if((C_HC[i]==C_HC[i+1])&&(C_HC[i]!=C_Proxy))
        {
            C_TwoPair++;
            C_Proxy = C_HC[i];
        }

        if(C_TwoPair==2)
        {
            C_Poker_R=3;
        }
    }


    // ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//THREEPAIR
    for(i=2;i<Cards_Poker;i++)  // Use nCr combinatorics formula to formulate how many subsets needed from the larger set
    {
        if(C_HC[i-1]==C_HC[i])
        {
            if(C_HC[i-2]==C_HC[i])
            {
                C_Poker_R=4;
                i=Cards_Poker;
            }
        }

    }

    Proxy_Card = 0;

	//STRAIGHT
    for(i=1;i<Cards_Poker;i++)  // Use nCr combinatorics formula to formulate how many subsets needed from the larger set
    {
    	if(C_HC[i]!=(C_HC[i-1]+1))
    	{
    		Counter=0;
    	}
		if(C_HC[i]==(C_HC[i-1]+1))
		{
			Counter++;
			if(Counter==4)
			{
				C_Poker_R=5;
				i=Cards_Poker;
				SF_Straight=1;
			}

		}

		/*
        if((C_HC[i]!=(C_HC[i+1]-1))) //if consecutive values are not equal, straight counter = 0. For straight counter to accumulate it has to be in the following form ex: 4,5,5,5,5,5,10
        {
            Straight_Counter=0;

        }
        if((C_HC[i]==(C_HC[i+1]-1))&&C_HC[i]!=C_HC[i+1]) //First Condition: if the next is bigger than the current by 1. Second Condition: if the current value is not equal to the next(Straight does not count for same values)
        {
            Straight_Counter++;
            if(Straight_Counter==4)
            {
                C_Poker_R=5;
                i=Cards_Poker;
            }
        }
		*/

    }
    Counter=0;

	//FLUSH
    for(i=0;i<Cards_Poker;i++) //C_CT Flush_Counter
    {
        for(int y=1;y<Cards_Poker;y++)
        {
            if(C_CT[i]==C_CT[y]) //Organize suits
            {
                Counter++;
            }
        }
        if(Counter>=5)
        {
            C_Poker_R=6;
            i=Cards_Poker;
            SF_Flush=1;

        }
        Counter=0;
    }
    Counter=0;

	//FULLHOUSE
    for(i=0;i<Cards_Poker;i++)  // Use nCr combinatorics formula to formulate how many subsets needed from the larger set
    {
    	for(int k=1; k<Cards_Poker;k++)
    	{
    		if(C_HC[i]==C_HC[k])
    		{
    			Counter++;
    		}
    		if(Counter==2)
    		{
    			Save_Value=C_HC[i];
    			i=0;
    			k=1;
    			Counter=0;
    			k=Cards_Poker;
    		}
    	}

    	for(int s=1; s<Cards_Poker;s++)
    	{
    		if(C_HC[i]==C_HC[s]&&(C_HC[i]!=Save_Value))
    		{
    			Counter++;
    			if(Counter==1)
				{
					C_Poker_R=7;
					i=Cards_Poker;
					Counter=0;
					Save_Value=0;
				}
    		}
		}
    }


    //FOUROFAKIND
    for(i=3;i<Cards_Poker;i++)
    {
    	if(C_HC[i-1]==C_HC[i])
        {
            if(C_HC[i-2]==C_HC[i])
            {
            	if(C_HC[i-3]==C_HC[i])
            	{
                	C_Poker_R=8;
                	i=Cards_Poker;
            	}
            }
        }

    }


    //STRAIGHTFLUSH
    if(SF_Flush==1&&SF_Straight==1)
    {
    	C_Poker_R=9;
	}

    //ROYALFLUSH
    if((C_HC[4]==13||C_HC[5]==13||C_HC[6]==13)&&SF_Flush==1&&SF_Straight==1)
    {
    	C_Poker_R=10;
	}

    C_Rank(C_Poker_R);
    return C_Poker_R;
}




int Cards::C_get_Deck()
{
    return C_Total;
}


