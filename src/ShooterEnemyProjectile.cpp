#include "ShooterEnemyProjectile.h"

ShooterEnemyProjectile::ShooterEnemyProjectile(sf::Vector2f pos, sf::Vector2f scale, const char* texture) : currDir{-1}, startPos{pos}
{
    sprite = std::make_shared<SpriteRenderer>(texture, scale);
    AddComponent(sprite);
    collider = std::make_shared<BoxCollider>(true, false);
    AddComponent(collider);
    GetTransform().SetOrigin(scale.x / 2, scale.y / 2);
    GetTransform().SetPosition(pos.x, pos.y);
}

void ShooterEnemyProjectile::setDir(float d){
    dir = d;
}

void ShooterEnemyProjectile::Reset(){
    TimeStamp = GameTimer::getTimeStamp();
    currDir = dir;
    GetTransform().SetPosition(startPos.x, startPos.y);
}

void ShooterEnemyProjectile::Update(){
    GameObject::Update();
    if (GameTimer::getTimeStamp() - TimeStamp > MormotaConstants::FIRE_RATE){
        Reset();
    }
    if (collider.get()->isColliding())
        GetTransform().SetPosition(0, MormotaConstants::BIG_NUMBER);
    GetTransform().Translate(MormotaConstants::PROJECTILE_VELOCITY * currDir * GameTimer::getDeltaTime(), 0);
}
