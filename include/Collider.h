#ifndef COLLIDER_H
#define COLLIDER_H
#include "GameComponent.h"
class Collider : public GameComponent
{
    public:
        Collider(bool isStatic, bool isEnemy);
        virtual bool isColliding();
        sf::Drawable* getDrawable() override;
        sf::Transformable* getTransformable() override;
        bool IsEnemy() const;
        bool IsStatic() const;
        void SetStatic(bool value);
    protected:
        bool isEnemy;
        bool isStatic;
    private:
};

#endif // COLLIDER_H
