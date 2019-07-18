#include "GameComponent.h"

GameComponent::GameComponent()
{
    //ctor
}

void GameComponent::AddGameObject(GameObject* g){
    this->g = g;
}

GameObject* GameComponent::GetGameObject(){
    return g;
}

//sf::Drawable& getDrawable(){
//    return nullptr;
//}
