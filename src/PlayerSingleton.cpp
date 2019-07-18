#include "PlayerSingleton.h"

PlayerSingleton& PlayerSingleton::getInstance()
{
    static PlayerSingleton instance;
    return instance;
}
