#ifndef SHROOMENEMY_H
#define SHROOMENEMY_H

#include "GameObject.h"
#include "SpriteRenderer.h"
#include "Enemy.h"
#include "BoxCollider.h"
class ShroomEnemy : public Enemy
{
    public:
        ShroomEnemy(sf::Vector2f pos, sf::Vector2f scale, const char* texture);
        void Update() override;
    protected:

    private:
        float dirAndSpeed = 120;
};

#endif // SHROOMENEMY_H
