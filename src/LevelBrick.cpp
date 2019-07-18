#include "LevelBrick.h"

LevelBrick::LevelBrick(sf::Vector2f pos, sf::Vector2f scale, const char* texture)
{
    AddComponent(std::make_shared<SpriteRenderer>(texture, scale));
    AddComponent(std::make_shared<BoxCollider>(false, true));
    GetTransform().SetOrigin(scale.x / 2, scale.y / 2);
    GetTransform().SetPosition(pos.x, pos.y);
}

void LevelBrick::Update(){
    GameObject::Update();

}
