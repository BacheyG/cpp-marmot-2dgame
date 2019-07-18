#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "ColliderBank.h"
#include "BoxCollider.h"
#include <cstring>
#include <fstream>
#include "Player.h"
#include "LevelBrick.h"
#include "ShooterEnemy.h"
#include "ShroomEnemy.h"
#include "GameObjectText.h"
class Scene
{
    public:
        Scene(sf::RenderWindow& w);
        void Add(std::shared_ptr<GameObject> g);
        void Update();
        void Load(const char* filename);
    protected:

    private:
        std::vector<std::shared_ptr<GameObject>> gameObjects;
        sf::RenderWindow& window;
};

#endif // SCENE_H
