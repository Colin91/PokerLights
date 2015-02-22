#ifndef PLAYERLIST_H
#define PLAYERLIST_H
#include "player.h"

class PlayerList
{
    private:
        int SIZE;
        int TOTAL;
        player *POINT;
        player *LASTP;
        player ARRAY[];
        player obj;
        std::string s;

    public:
        PlayerList(player *POINT,int);
        void PL_Add(player obj);
        bool PL_Remove(int);
        bool PL_isEmpty();
        bool PL_isFull();
        player PL_getPlayer(int);



};
#endif // PLAYERLIST_H
