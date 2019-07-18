#include "GUI.h"

GUI::GUI(sf::Vector2f pos) : pos{pos}
{
    //ctor
}

void GUI::Update(){
    GameObject::Update();
    //GetTransform().SetPosition(pos.x + PlayerSingleton::getInstance().player->getScreenOffset() , pos.y);
}
