#ifndef COLLIDERBANK_H
#define COLLIDERBANK_H
#include "BoxCollider.h"
class BoxCollider;
class ColliderBank
{
private:
    ColliderBank() = default;
public:
    static ColliderBank& getInstance();
    std::vector<BoxCollider*> colliders;
};

#endif // COLLIDERBANK_H
