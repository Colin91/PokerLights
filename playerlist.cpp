#include "playerlist.h"
#include "player.h"
#include <iostream>
#include <string>
using namespace std;

PlayerList::PlayerList(player *BK_In, int Size_In) // THE address of the FIRST index ARRAY[0] is passed.
:POINT(BK_In)
{
    LASTP = BK_In; // THIS ARRAY[0] stays fixed
    SIZE = Size_In;
    TOTAL = 0;
}


void PlayerList::PL_Add(player BK1_In)
{
    obj = BK1_In;
    POINT[TOTAL] = obj;
    TOTAL++;
}


player PlayerList::PL_getPlayer(int i_In)
{
     return POINT[i_In];
}

bool PlayerList::PL_Remove(int search_In)
{
    bool SWI;
    //searchIN = searchIN-1;
    if(TOTAL!=0)
    {
        for(int j=0;j<TOTAL;j++)
        {
             int Local = POINT[j].P_getIndex();

             if(Local == search_In)
             {
                POINT[search_In] = POINT[search_In+1];
                for(int p = search_In; p<TOTAL; p++)
                {
                    POINT[p] = POINT[p+1];
                }
             }
        }
        TOTAL--;
        SWI = true;

    }
    else
    {
        SWI = false;
    }
    return SWI;
}


bool PlayerList::PL_isEmpty()
{
    bool SWI;
    if(TOTAL==0)
    {
        SWI = true;
    }
    else
    {
        SWI = false;
    }
    return SWI;
}
bool PlayerList::PL_isFull()
{
    bool SWI;
    if(TOTAL == SIZE)
    {
        SWI = true;
    }
    else
    {
        SWI = false;
    }
    return SWI;

}


