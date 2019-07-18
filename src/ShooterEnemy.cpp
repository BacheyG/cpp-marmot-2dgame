#include "ShooterEnemy.h"

ShooterEnemy::ShooterEnemy(sf::Vector2f pos, sf::Vector2f scale, const char* texture) : Enemy{60}
{
    sprite = std::make_shared<SpriteRenderer>(texture, scale);
    AddComponent(sprite);
    collider = std::make_shared<BoxCollider>(true, false);
    AddComponent(collider);
    GetTransform().SetOrigin(scale.x / 2, scale.y / 2);
    GetTransform().SetPosition(pos.x, pos.y);
    bullet = std::make_shared<ShooterEnemyProjectile>(pos, sf::Vector2f(30, 30), "resources/projectile.png");
    scaleX = GetTransform().GetScale().x * GetTransform().GetExtraScale().x;
}


void ShooterEnemy::Update()
{
    Enemy::Update();
    bullet.get()->AddWindow(*window);
    bullet.get()->Update();
    if (PlayerSingleton::getInstance().player)
    if (PlayerSingleton::getInstance().player->GetTransform().GetPosition().x > GetTransform().GetPosition().x){
        GetTransform().SetScale(scaleX, scaleX);
        bullet.get()->setDir(1);
    }
    else{
        GetTransform().SetScale(-scaleX, scaleX);
        bullet.get()->setDir(-1);
    }
}
