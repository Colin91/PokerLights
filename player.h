#ifndef PLAYER_H
#define PLAYER_H
#include<string>


class player
{
    private:
        std::string P_Name;
        int P_Index;

    public:
        player();
        void P_setName(std::string);
        void P_setIndex(int);

        std::string P_getName();
        int P_getIndex();
};

#endif // PLAYER_H
