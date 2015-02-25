#ifndef PLAYERSTATUSLIST_H
#define PLAYERSTATUSLIST_H
#include "PlayerStatus.h"

class PlayerStatusList
{
    private:
        int SIZE;
        int TOTAL;
        PlayerStatus *POINT;
        PlayerStatus *LASTP;
        PlayerStatus ARRAY[];
        PlayerStatus obj;
        std::string s;

    public:
        PlayerStatusList(PlayerStatus*,int);
        void PSL_Add(PlayerStatus obj);
        bool PSL_Remove(int);
        bool PSL_isEmpty();
        bool PSL_isFull();
        PlayerStatus* PSL_getPlayer(int);

};
#endif
