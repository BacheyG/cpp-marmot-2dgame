#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H
#include "Collider.h"
#include "ColliderBank.h"
#include "MormotaConstants.h"

class BoxCollider : public Collider
{
    public:
        BoxCollider(bool isEnemy = false, bool isStatic = false, sf::Vector2f mul = sf::Vector2f(1, 1));
        bool isColliding() override;
        float getBottomLimit() const;
        float getTopLimit() const;
        float getLeftLimit() const;
        float getRightLimit() const;
        void SetBottomLimit(float value);
        bool IsHitEnemy() const;
        sf::Vector2f getMultiply();
    protected:

    private:
        float leftLimit;
        float rightLimit;
        float topLimit;
        float bottomLimit;
        bool isHitEnemy = false;
        sf::Vector2f multiplyLimits;
};

#endif // BOXCOLLIDER_H
