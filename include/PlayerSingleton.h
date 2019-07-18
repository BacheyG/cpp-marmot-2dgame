#ifndef PLAYERSINGLETON_H
#define PLAYERSINGLETON_H

#include "Player.h"
class Player;
class PlayerSingleton
{
public:
    static PlayerSingleton& getInstance();
    Player* player;
protected:

private:
};

#endif // PLAYERSINGLETON_H
