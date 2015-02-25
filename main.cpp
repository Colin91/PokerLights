#include "cards.h"
#include "PokerTurns.h"
#include "Action.h"
#include "GameStatus.h"
#include "player.h"
#include "playerlist.h"
#include "PlayerStatus.h"
#include "PlayerStatusList.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

//make -f Program
void GS_PS_Test(GameStatus&,PlayerStatus&,PlayerStatusList&,PlayerList&);


int main()
{
	int Players;
	string PlayerName;
	int GameRound=0;
	int PlayerChips=1500;
	int LastPlayer;

	PlayerStatus PS;
	PlayerStatus PSs;
	GameStatus GS;
	player P;
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
    PlayerStatus *ListOfPlayerStatus = new PlayerStatus[Players];
    PlayerList PL(ListOfPlayers,Players);
    PlayerStatusList PSL(ListOfPlayerStatus,Players);


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
		PS.PS_setIndex(i);
    	PSL.PSL_Add(PS);
    }
  
    cout<<endl;
	Action A(GS,PSL,P);
    PokerTurns PT(GameRound,PL,PSL,GS,C,A); 
    PT.PT_Game_Init(Players,20);
    GS_PS_Test(GS,PS,PSL,PL);

	
    do
    {
        cout<<"ROUND_INIT"<<endl;
        cout<<"=================================================="<<endl;
    	PT.PT_Round_Init();
   		GS_PS_Test(GS,PS,PSL,PL);
			
    	cout<<"PRE_FLOP"<<endl;
    	cout<<"=================================================="<<endl;
    	PT.PT_PreFlop();
    	GS_PS_Test(GS,PS,PSL,PL);

    	cout<<"FLOP"<<endl;
    	cout<<"=================================================="<<endl;
    	PT.PT_Flop();
    	GS_PS_Test(GS,PS,PSL,PL);

    	cout<<"TURN"<<endl;
    	cout<<"=================================================="<<endl;
    	PT.PT_Turn();
    	GS_PS_Test(GS,PS,PSL,PL);

    	cout<<"RIVER"<<endl;
    	cout<<"=================================================="<<endl;
		PT.PT_River();
		GS_PS_Test(GS,PS,PSL,PL);

		PT.PT_Round_Result();
		GS_PS_Test(GS,PS,PSL,PL);
		LastPlayer = GS.GS_getIngameTotal();

    }while(LastPlayer!=1);
    



	return 0;
}

void GS_PS_Test(GameStatus &GS_In,PlayerStatus &PS_In,PlayerStatusList &PSL_In,PlayerList &PL_In)
{
    player P;
    GameStatus *GS = &GS_In;
    PlayerStatus *PS;
    PlayerStatus *PS_S;
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
    	//for(int j=0; j<11;j++)
    	//{
		    P = PL_In.PL_getPlayer(i);
		    name = P.P_getName();
		    PS = PSL_In.PSL_getPlayer(i);
		    
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
		    
		//}
    }

}
