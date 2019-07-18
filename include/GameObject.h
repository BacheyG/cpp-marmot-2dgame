#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "GameComponent.h"
#include <memory>
#include "Transform.h"
#include <SFML/Graphics.hpp>
class Transform;
class GameComponent;
class GameObject
{
    public:
        GameObject();
        GameObject(sf::RenderWindow& window);
        virtual void Update();
        std::vector<std::shared_ptr<GameComponent>>& GetComponents();
        void AddComponent(std::shared_ptr<GameComponent> component);
        Transform& GetTransform();
        void AddWindow(sf::RenderWindow& window);
    protected:
        sf::RenderWindow* window;
    private:
        std::vector<std::shared_ptr<GameComponent>> components;
        std::shared_ptr<Transform> transform;
};

#endif // GAMEOBJECT_H
