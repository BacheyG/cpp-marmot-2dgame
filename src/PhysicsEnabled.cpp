#include "PhysicsEnabled.h"

PhysicsEnabled::PhysicsEnabled(float size) : V_SIZE{size}
{
    //ctor
}

void PhysicsEnabled::Update(){
    GameObject::Update();
    groundLevel = collider.get()->getBottomLimit();
    //zuhanas
    if (GetTransform().GetPosition().y < groundLevel - V_SIZE / 2 - MormotaConstants::EPSILON && !isOffGround){
        isOffGround = true;
        airTimer = GameTimer::getTimeStamp();
        verticalVelocity = 0;
    }
    if (isOffGround)
    {
        float dt = GameTimer::getTimeStamp() - airTimer;
        verticalVelocity -= (MormotaConstants::GRAVITY / 2) * dt * dt;
        GetTransform().Translate(0, -verticalVelocity);
        if (GetTransform().GetPosition().y > groundLevel - V_SIZE / 2)
        {
            isOffGround = false;
            GetTransform().SetPosition(GetTransform().GetPosition().x, groundLevel - V_SIZE / 2);
        }
    }
}
