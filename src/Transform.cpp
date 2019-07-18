#include "Transform.h"

Transform::Transform(GameObject* g) : gameObject{g}, position(sf::Vector2f(0,0)), scale(sf::Vector2f(1,1)), extraScale(sf::Vector2f(1,1)), dimensions(sf::Vector2f(0,0))
{

}

sf::Vector2f Transform::GetScale() const
{
    return scale;
}

sf::Vector2f Transform::GetPosition() const
{
    return position;
}

void Transform::SetPosition(float x, float y)
{
    position = sf::Vector2f(x, y);
    for (auto g : gameObject->GetComponents())
    {
        if (g.get()->getTransformable() != nullptr)
            g.get()->getTransformable()->setPosition(sf::Vector2f(x, y));
    }
}

void Transform::SetScale(float x, float y)
{
    scale = sf::Vector2f(x, y);
    for (auto g : gameObject->GetComponents())
    {
        if (g.get()->getTransformable() != nullptr)
            g.get()->getTransformable()->setScale(scale.x, scale.y);
    }
}

void Transform::SetExtraScale(sf::Vector2f es)
{
    extraScale = es;
}

sf::Vector2f Transform::GetExtraScale() const {
    return extraScale;
}

void Transform::SetOrigin(float x, float y)
{
    position += sf::Vector2f(x, y);
    for (auto g : gameObject->GetComponents())
    {
        if (g.get()->getTransformable() != nullptr)
            g.get()->getTransformable()->setOrigin(sf::Vector2f(x / extraScale.x, y / extraScale.y));
    }
}

void Transform::Translate (float x, float y)
{
    position += sf::Vector2f(x, y);
    for (auto g : gameObject->GetComponents())
    {
        if (g.get()->getTransformable() != nullptr)
            g.get()->getTransformable()->move(x, y);
    }
}

sf::Vector2f Transform::GetDimensions() const
{
    return dimensions;
}

void Transform::SetDimensions(sf::Vector2f d)
{
    dimensions = d;
}
