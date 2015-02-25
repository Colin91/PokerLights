#ifndef GAMESTATUS_H
#define GAMESTATUS_H

class GameStatus
{
	private:
		int GS_PotSize;
		int GS_TurnPointer;
		int GS_HighBet;
		int GS_Ingametotal;
		int GS_Inroundtotal;
		int GS_SmallBlind;
		int GS_BigBlind;
		int GS_SidePot;
		int GS_Flop_C1;
		int GS_Flop_C2;
		int GS_Flop_C3;
		int GS_Turn;
		int GS_River;
		int GS_TotalNoPlayers;

	public:
		GameStatus();
		void GS_setPotSize(int);
		void GS_setAddToPotSize(int);
		void GS_resetPotSize();
		void GS_setTurnPointer(int); //Check use, function might be redundant
		void GS_setBigBlind(int);
		void GS_setSmallBlind(int);
		void GS_setHighBet(int);
		void GS_setIngameTotal(int);
		void GS_setSidePot(int);
		void GS_resetSidePot();
		void GS_resetHighBet();
		void GS_setFlopC1(int);
		void GS_setFlopC2(int);
		void GS_setFlopC3(int);
		void GS_setTurn(int);
		void GS_setRiver(int);
		void GS_setNumberOfPlayers(int);
		void GS_setInroundTotal(int);
		void GS_setAddToSidePot(int);

		int GS_getPotSize();
		int GS_getTurnPointer();
		int GS_getHighBet();
		int GS_getIngameTotal();
		int GS_getSmallBlind();
		int GS_getBigBlind();
		int GS_getSidePot();
		int GS_getFlopC1();
		int GS_getFlopC2();
		int GS_getFlopC3();
		int GS_getTurn();
		int GS_getRiver();
		int GS_getNumberOfPlayers();
		int GS_getInroundTotal();

};

#endif
