#ifndef SHOOTERENEMY_H
#define SHOOTERENEMY_H

#include "GameObject.h"
#include "ShooterEnemyProjectile.h"
#include "Enemy.h"
#include "SpriteRenderer.h"
#include "BoxCollider.h"
#include "PlayerSingleton.h"
class ShooterEnemy : public Enemy
{
    public:
        ShooterEnemy(sf::Vector2f pos, sf::Vector2f scale, const char* texture);
        void Update() override;

    protected:

    private:
        std::shared_ptr<ShooterEnemyProjectile> bullet;
        float scaleX;
};

#endif // SHOOTERENEMY_H
