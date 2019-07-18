#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>

class GameObject;
class Transform
{
    public:
        Transform(GameObject* g);
        void SetPosition(float x, float y);
        sf::Vector2f GetPosition() const;
        void Translate(float x, float y);
        sf::Vector2f GetScale() const;
        void SetScale(float x, float y);
        sf::Vector2f GetDimensions() const;
        void SetDimensions(sf::Vector2f d);
        sf::Vector2f GetExtraScale() const;
        void SetExtraScale(sf::Vector2f es);
        void SetOrigin(float x, float y);
        GameObject* gameObject;

    protected:

    private:
        sf::Vector2f position;
        sf::Vector2f scale;
        sf::Vector2f extraScale;
        sf::Vector2f dimensions;
};

#endif // TRANSFORM_H
