#ifndef GAMEOBJECTTEXT_H
#define GAMEOBJECTTEXT_H

#include "GUI.h"
#include "PlayerSingleton.h"
class GameObjectText : public GUI
{
    public:
        GameObjectText(sf::Vector2f pos, float size, const char* fontdir);
        void Update() override;
    protected:

    private:
        sf::Text text;
};

#endif // GAMEOBJECTTEXT_H
