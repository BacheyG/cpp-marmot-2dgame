#include "ColliderBank.h"

ColliderBank& ColliderBank::getInstance()
{
    static ColliderBank instance;
    return instance;
}
