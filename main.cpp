#include "cards.h"
#include "PokerTurns.h"
#include "Action.h"
#include "GameStatus.h"
#include "player.h"
#include "playerlist.h"
#include "PlayerStatus.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

//make -f Program
void GS_PS_Test(GameStatus&,PlayerStatus&,PlayerList&);


int main()
{
	int Players;
	string PlayerName;
	int GameRound=0;
	int PlayerChips=1500;
	int LastPlayer;

	PlayerStatus PS(1,PlayerChips,0,0);
	GameStatus GS;
	player P;
	Action A(GS,PS,P);
	Cards C;

    cout<<"_______________________________________________"<<endl;
	cout<<"======    =======     =   =    ======    ======"<<endl;
    cout<<"=    =    =     =     =  =     =         =    ="<<endl;
    cout<<"=    =    =     =     = =      =         =    ="<<endl;
    cout<<"======    =     =     ==       =         ======"<<endl;
    cout<<"=         =     =     ==       ======    ==    "<<endl;
    cout<<"=         =     =     = =      =         = =   "<<endl;
    cout<<"=         =     =     =  =     =         =  =  "<<endl;
    cout<<"=         =     =     =   =    =         =   = "<<endl;
    cout<<"=         =======     =    =   ======    =    ="<<endl;
    cout<<"_______________________________________________"<<endl;

    cout<<"Enter Number of Players: "<<endl;
    cin>>Players;
    string *ProxyName = new string[Players];
    int *ProxyIndex = new int[Players];
    player *ListOfPlayers = new player[Players];
    PlayerList PL(ListOfPlayers,Players);


    for(int i=0;i<Players;i++)
    {
    	cout<<"Enter Player Name :"<<endl;
    	cin.ignore();
    	getline(cin,PlayerName);
    	ProxyName[i]=PlayerName;
    	ProxyIndex[i]=i;
    	P.P_setName(ProxyName[i]);
    	P.P_setIndex(i);
    	PL.PL_Add(P);

    }

    int *GSA = new int[14];
    int PSA[Players][12];
    int **PPSA = new int*[Players];
	int CardArray[Players][8];
    int **PCardArray = new int*[Players];


	for(int a=0;a<Players;a++)
    {   
        for(int i=0;i<12;i++)
        {
            PSA[a][i] = 0;
            cout<<PSA[a][i];
        }
        cout<<endl;
        
        PPSA[a] = &PSA[a][0]; 
    }
    for(int i=0;i<Players;i++)
    {
        for(int j=0;j<8;j++)
        {
            CardArray[i][j]=0;
            PCardArray[i]=&CardArray[i][0];
        }
    }
    for(int i=0;i<14;i++)
    {
        GSA[i]=0;
        cout<<GSA[i];
    }
    cout<<endl;

    PokerTurns PT(GameRound,PL,PS,GS,C,A,*GSA,PPSA);
    PT.PT_Game_Init(Players,20);
    GS_PS_Test(GS,PS,PL);

    do
    {
        cout<<"ROUND_INIT"<<endl;
        cout<<"=================================================="<<endl;
    	PT.PT_Round_Init();
    	GS_PS_Test(GS,PS,PL);

    	cout<<"PRE_FLOP"<<endl;
    	cout<<"=================================================="<<endl;
    	PT.PT_PreFlop();
    	GS_PS_Test(GS,PS,PL);

    	cout<<"FLOP"<<endl;
    	cout<<"=================================================="<<endl;
    	PT.PT_Flop();

    	cout<<"TURN"<<endl;
    	cout<<"=================================================="<<endl;
    	PT.PT_Turn();

    	cout<<"RIVER"<<endl;
    	cout<<"=================================================="<<endl;
		PT.PT_River();

		PT.PT_Round_Result();
		LastPlayer = GS.GS_getIngameTotal();

    }while(LastPlayer!=1);



	return 0;
}

void GS_PS_Test(GameStatus &GS_In,PlayerStatus &PS_In,PlayerList &PL_In)
{
    player P;
    GameStatus *GS = &GS_In;
    PlayerStatus *PS = &PS_In;
    string name;
    int GST[14];
    int PST[12];
    int CardArray[8];
    cout<<"-------------"<<endl;
    cout<<"GameStatus : "<<endl;
    cout<<"-------------"<<endl;
    GST[0] = GS->GS_getPotSize();
    GST[1] = GS->GS_getHighBet();
    GST[2] = GS->GS_getIngameTotal();
    GST[3] = GS->GS_getSmallBlind();
    GST[4] = GS->GS_getBigBlind();
    GST[5] = GS->GS_getSidePot();
    GST[6] = GS->GS_getFlopC1();
    GST[7] = GS->GS_getFlopC2();
    GST[8] = GS->GS_getFlopC3();
    GST[9] = GS->GS_getTurn();
    GST[10] = GS->GS_getRiver();
    GST[11] = GS->GS_getNumberOfPlayers();
    GST[12] = GS->GS_getInroundTotal();
    cout<<"PotSize  : "<< GST[0] << " , HighBet : "<<GST[1]<<" , IngameT : "<<GST[2]<< " , SmallBlind : "<<GST[3]<<endl;
    cout<<"BigBlind : "<< GST[4] << " , SidePot : "<<GST[5]<<" , FlopC1  : "<<GST[6]<< " , FlopC2     : "<<GST[7]<<endl;
    cout<<"FlopC3   : "<< GST[8] << " , Turn    : "<<GST[9]<<" , River   : "<<GST[10]<<" , NumberOfP  : "<<GST[11]<<endl;
    cout<<"InRoundT : "<< GST[12] <<endl;


    for(int i=0; i<GST[11];i++)
    {
        P = PL_In.PL_getPlayer(i);
        name = P.P_getName();
        cout<<"-------------"<<endl;
        cout<<"PlayerStatus : "<<name<<endl;
        cout<<"-------------"<<endl;
        PST[0] = PS->PS_getCard1();
        PST[1] = PS->PS_getCard2();
        PST[2] = PS->PS_getChips();
        PST[3] = PS->PS_getRank();
        PST[4] = PS->PS_getIngame();
        PST[5] = PS->PS_getBlind();
        PST[6] = PS->PS_getEOR();
        PST[7] = PS->PS_getAccBet();
        PST[8] = PS->PS_getInRound();
        PST[9] = PS->PS_getCurrentBet();
        PST[10] = PS->PS_getAllInFlag();
        CardArray[0] = PS->PS_getCardArray();

        cout<<"Card1   : "<< PST[0] << " , Card2   : "<<PST[1]<<" , Chips     : "<<PST[2]<< " , Rank   : "<<PST[3]<<endl;
        cout<<"InGame  : "<< PST[4] << " , Blind   : "<<PST[5]<<" , EOR       : "<<PST[6]<< " , AccBet : "<<PST[7]<<endl;
        cout<<"InRound : "<< PST[8] << " , CurrBet : "<<PST[9]<<" , AllInFlag : "<<PST[10]<<endl;
        cout<<"-------------"<<endl;
        cout<<"Card Array : "<<endl;
        cout<<"-------------"<<endl;
        cout<<"Card1  : "<<PS->PS_getCard1()<<endl;
        cout<<"Card2  : "<<PS->PS_getCard2()<<endl;
        cout<<"FlopC1 : "<<GS->GS_getFlopC1()<<endl;
        cout<<"FlopC2 : "<<GS->GS_getFlopC2()<<endl;
        cout<<"FlopC3 : "<<GS->GS_getFlopC3()<<endl;
        cout<<"Turn   : "<<GS->GS_getTurn()<<endl;
        cout<<"River  : "<<GS->GS_getRiver()<<endl;
        cout<<"Rank   : "<<PS->PS_getRank()<<endl;
        cout<<endl;
    }

}
