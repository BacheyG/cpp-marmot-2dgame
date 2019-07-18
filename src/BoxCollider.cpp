#include "BoxCollider.h"

BoxCollider::BoxCollider( bool isEnemy, bool isStatic, sf::Vector2f mul) : Collider{isStatic, isEnemy}, bottomLimit{-MormotaConstants::BIG_NUMBER}, topLimit{MormotaConstants::BIG_NUMBER}, leftLimit{-MormotaConstants::BIG_NUMBER}, rightLimit{MormotaConstants::BIG_NUMBER}, multiplyLimits{mul}
{
    ColliderBank::getInstance().colliders.push_back(this);
}

float BoxCollider::getBottomLimit() const
{
    return bottomLimit;
}
float BoxCollider::getTopLimit() const
{
    return topLimit;
}
float BoxCollider::getLeftLimit() const
{
    return leftLimit;
}
float BoxCollider::getRightLimit() const
{
    return rightLimit;
}

sf::Vector2f BoxCollider::getMultiply()
{
    return multiplyLimits;
}

bool BoxCollider::IsHitEnemy() const{return isHitEnemy;}

void BoxCollider::SetBottomLimit(float value){
    bottomLimit = value;
}

bool BoxCollider::isColliding()
{
    bool hasCollided = false;
    if (IsStatic()) return false;
    //inicializálom
    leftLimit = -MormotaConstants::BIG_NUMBER;
    bottomLimit = MormotaConstants::BIG_NUMBER;
    rightLimit = MormotaConstants::BIG_NUMBER;
    topLimit = -MormotaConstants::BIG_NUMBER;
    isHitEnemy = false;
    for (BoxCollider* other : ColliderBank::getInstance().colliders)
    {
        //ha ugyanaz, hagyjuk
        if (other == this)
        {
            continue;
        }
        //Enemyk hagyják egymást békén
        if (IsEnemy() && other->IsEnemy())
            continue;
        sf::Vector2f otherPos = other->GetGameObject()->GetTransform().GetPosition();
        sf::Vector2f thisPos = GetGameObject()->GetTransform().GetPosition();
        sf::Vector2f otherDimension = other->GetGameObject()->GetTransform().GetDimensions();
        sf::Vector2f thisDimension = GetGameObject()->GetTransform().GetDimensions();
        float biasX = thisDimension.x * (1 - getMultiply().x);
        float biasY = thisDimension.y * (1 - getMultiply().y);
        thisDimension.x *= getMultiply().x;
        thisDimension.y *= getMultiply().y;
        otherDimension.x *= other->getMultiply().x;
        otherDimension.y *= other->getMultiply().y;

        //van-e ütközés
        if ((float)fabs(thisPos.x - otherPos.x) < (thisDimension.x + otherDimension.x) / 2 &&
                (float)fabs(thisPos.y - otherPos.y) < (thisDimension.y + otherDimension.y) / 2 )
        {
            if (other->IsEnemy()) isHitEnemy = true;
            //minden egyes irányba megnézzük van-e ütközés
            if (thisPos.x - thisDimension.x / 2 > otherPos.x - otherDimension.x / 2 &&
                    thisPos.x - thisDimension.x / 2 < otherPos.x + otherDimension.x / 2 &&
                    thisPos.y + thisDimension.y / 2 - 20 > otherPos.y - otherDimension.y / 2)
            {
                leftLimit = otherPos.x - otherDimension.x / 2 + biasX;
            }
            //else leftLimit = -999;
            if (thisPos.x + thisDimension.x / 2 > otherPos.x - otherDimension.y / 2 &&
                    thisPos.x + thisDimension.x / 2 < otherPos.x + otherDimension.y / 2 &&
                    thisPos.y + thisDimension.y / 2 - 20 > otherPos.y - otherDimension.y / 2)
            {
                rightLimit = otherPos.x - otherDimension.x / 2 - biasX;
            }
            //else rightLimit = 999;

            if (thisPos.y + thisDimension.y / 2 > otherPos.y - otherDimension.y / 2 &&
                    thisPos.y + thisDimension.y / 2 < otherPos.y + otherDimension.y / 2)
            {
                bottomLimit = otherPos.y - otherDimension.y / 2 + biasY;
            }
            //else bottomLimit = 999;

            if (thisPos.y - thisDimension.y / 2 > otherPos.y - otherDimension.y / 2 &&
                    thisPos.y - thisDimension.y / 2 < otherPos.y + otherDimension.y / 2)
            {
                topLimit = otherPos.y + otherDimension.y / 2 - biasY;
            }
            //else topLimit = -999;


            hasCollided = true;
        }
    }
    return hasCollided;
}
