#include "GameObject.h"

GameObject::GameObject(){
    transform = std::make_shared<Transform>(this);
}

void GameObject::AddWindow(sf::RenderWindow& window){
    this->window = &window;
}

Transform& GameObject::GetTransform(){
    return *(transform.get());
}

void GameObject::Update(){
    for (auto g : GetComponents()){
        sf::Drawable* d = g.get()->getDrawable();
        if (d != nullptr)
            window->draw(*d);
    }
}

std::vector<std::shared_ptr<GameComponent>>& GameObject::GetComponents(){
    return components;
}

void GameObject::AddComponent(std::shared_ptr<GameComponent> component)
{
    component.get()->AddGameObject(this);
    components.push_back(component);
}
