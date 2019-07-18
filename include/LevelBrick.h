#ifndef LEVELBRICK_H
#define LEVELBRICK_H

#include "GameObject.h"
#include "SpriteRenderer.h"
#include "BoxCollider.h"
class LevelBrick : public GameObject
{
    public:
        LevelBrick(sf::Vector2f pos, sf::Vector2f scale, const char* texture);
        void Update();
    protected:

    private:
};

#endif // LEVELBRICK_H
