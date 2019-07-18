#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class GameObject;
class GameComponent
{
    public:
        GameComponent();
        virtual sf::Drawable* getDrawable() = 0;
        virtual sf::Transformable* getTransformable() = 0;

        GameObject* GetGameObject();
        virtual void AddGameObject(GameObject* g);
    protected:
        GameObject* g;
    private:
};

#endif // GAMECOMPONENT_H
