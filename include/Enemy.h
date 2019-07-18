#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
#include "GameTimer.h"
#include "BoxCollider.h"
#include "PhysicsEnabled.h"
#include "SpriteRenderer.h"
class Enemy : public PhysicsEnabled
{
    public:
        Enemy(float size);
    protected:
        std::shared_ptr<SpriteRenderer> sprite;
};

#endif // ENEMY_H
