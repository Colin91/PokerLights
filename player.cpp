#include "player.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

player::player()
{

}

void player::P_setName(string P_Name_In)
{
    P_Name=P_Name_In;
}

void player::P_setIndex(int P_Index_In)
{
    P_Index = P_Index_In;
}

string player::P_getName()
{
    return P_Name;
}

int player::P_getIndex()
{
    return P_Index;
}

