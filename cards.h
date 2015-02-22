#ifndef CARDS_H
#define CARDS_H
#include<string>

using namespace std;

class Cards
{
    private:
      int *C_INT_pointer;
      string *C_STRING_pointer;
      string *C_card_pointer01;
      int C_Total;
      int *C_HC;
      int *C_CT;

    public:
        Cards();
        void C_Rank(int);
        int C_Card(int,int);
        int C_Draw(int,int); //0to13 Return cards taken from Deck
        int C_get_Deck(); //Starts at 52, subtracts the cards withdrawn
        int C_Poker_Hands(int*,int);
        int C_getHighCard(int*,int);

};

#endif // CARDS_H


//eg, C_Draw(10,2,13,1) so Jack of Hearts and Ace of Spades
//    C_Card(10,2380) returns 23800
