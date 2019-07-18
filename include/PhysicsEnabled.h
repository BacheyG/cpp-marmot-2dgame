#ifndef PHYSICSENABLED_H
#define PHYSICSENABLED_H
#include "MormotaConstants.h"
#include "BoxCollider.h"
#include "GameTimer.h"
class BoxCollider;
class PhysicsEnabled : public GameObject
{
    public:
        PhysicsEnabled(float size);
        void Update() override;
    protected:
        std::shared_ptr<BoxCollider> collider;
        bool isOffGround = false;
        float airTimer;
        float verticalVelocity;
        float groundLevel;
        float V_SIZE;
    private:
};

#endif // PHYSICSENABLED_H
