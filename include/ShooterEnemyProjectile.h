#ifndef SHOOTERENEMYPROJECTILE_H
#define SHOOTERENEMYPROJECTILE_H

#include "Enemy.h"
#include "SpriteRenderer.h"
#include "BoxCollider.h"
class ShooterEnemyProjectile : public GameObject
{
    public:
        ShooterEnemyProjectile(sf::Vector2f pos, sf::Vector2f scale, const char* texture);
        void setDir(float d);
        void Update() override;
        void Reset();
    protected:

    private:
        float dir;
        float currDir;
        float speed = 300;
        float TimeStamp;
        sf::Vector2f startPos;
        std::shared_ptr<BoxCollider> collider;
        std::shared_ptr<SpriteRenderer> sprite;
};

#endif // SHOOTERENEMYPROJECTILE_H
