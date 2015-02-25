#include "PlayerStatusList.h"
#include <iostream>
#include <string>
using namespace std;

PlayerStatusList::PlayerStatusList(PlayerStatus *BK_In, int Size_In)
:POINT(BK_In)
{
    LASTP = BK_In; // THIS ARRAY[0] stays fixed
    SIZE = Size_In;
    TOTAL = 0;
 
}


void PlayerStatusList::PSL_Add(PlayerStatus BK1_In)
{
    POINT[TOTAL] = BK1_In;
    TOTAL++;
}


PlayerStatus* PlayerStatusList::PSL_getPlayer(int i_In)
{
     return &POINT[i_In];
}

bool PlayerStatusList::PSL_Remove(int search_In)
{
    bool SWI;
    if(TOTAL!=0)
    {
        for(int j=0;j<TOTAL;j++)
        {
             int Local = POINT[j].PS_getIndex();

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


bool PlayerStatusList::PSL_isEmpty()
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
bool PlayerStatusList::PSL_isFull()
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


