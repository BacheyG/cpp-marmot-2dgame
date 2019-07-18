#ifndef GUI_H
#define GUI_H

#include "GameObject.h"
#include "PlayerSingleton.h"
class GUI : public GameObject
{
    public:
        GUI(sf::Vector2f pos);
        void Update() override;
    protected:
        sf::Vector2f pos;
    private:
};

#endif // GUI_H
