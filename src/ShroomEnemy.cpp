#include "ShroomEnemy.h"

ShroomEnemy::ShroomEnemy(sf::Vector2f pos, sf::Vector2f scale, const char* texture) : Enemy{60}
{
    sprite = std::make_shared<SpriteRenderer>(texture, scale);
    AddComponent(sprite);
    collider = std::make_shared<BoxCollider>(true, false);
    AddComponent(collider);
    GetTransform().SetOrigin(scale.x / 2, scale.y / 2);
    GetTransform().SetPosition(pos.x, pos.y);
}


void ShroomEnemy::Update(){
    Enemy::Update();
    if (GetTransform().GetPosition().x - collider.get()->getLeftLimit() < 200)
    {
        dirAndSpeed = (float)fabs(dirAndSpeed);
    }
    if (collider.get()->getRightLimit() - GetTransform().GetPosition().x < 200)
    {
        dirAndSpeed = -(float)fabs(dirAndSpeed);
    }
    GetTransform().Translate(dirAndSpeed * GameTimer::getDeltaTime(), 0);
}
