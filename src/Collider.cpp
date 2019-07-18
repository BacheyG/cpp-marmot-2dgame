#include "Collider.h"

Collider::Collider(bool isStatic, bool isEnemy) : isStatic{isStatic}, isEnemy{isEnemy}
{
}

bool Collider::isColliding(){
    return false;
}

sf::Drawable* Collider::getDrawable(){
    return nullptr;
}

sf::Transformable* Collider::getTransformable(){
    return nullptr;
}

bool Collider::IsEnemy() const{
    return isEnemy;
}

bool Collider::IsStatic() const{
    return isStatic;
}

void Collider::SetStatic(bool value){
    isStatic = value;
}
