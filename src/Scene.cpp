#include "Scene.h"

Scene::Scene(sf::RenderWindow& w) : window{w}
{
}

void Scene::Add(std::shared_ptr<GameObject> g)
{
    g->AddWindow(window);
    gameObjects.push_back(g);
}

void Scene::Update()
{
    for(std::shared_ptr<GameObject> g : gameObjects)
    {
        g->Update();
    }
    for (auto collider : ColliderBank::getInstance().colliders)
    {
        collider->isColliding();
    }
}

void Scene::Load(const char* filename)
{
    FILE * file = fopen(filename, "r");
    if( file == NULL )
    {
        printf("File loading failed...\n");
        return;
    }
    while( 1 )
    {

        char lineHeader[128];
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break;
        else
        {
            if ( strcmp( lineHeader, "brick" ) == 0 )
            {
                int posx, posy, sizex, sizey;
                char _filename[128];
                fscanf(file, "%d %d %d %d %s\n", &posx, &posy, &sizex, &sizey, _filename );
                Add(std::make_shared<LevelBrick>(sf::Vector2f(posx, posy), sf::Vector2f(sizex, sizey), _filename));
            }
            else if ( strcmp( lineHeader, "shroom" ) == 0 )
            {
                int posx, posy, sizex, sizey;
                char _filename[128];
                fscanf(file, "%d %d %d %d %s\n", &posx, &posy, &sizex, &sizey, _filename );
                Add(std::make_shared<ShroomEnemy>(sf::Vector2f(posx, posy), sf::Vector2f(sizex, sizey), _filename));
            }
            else if ( strcmp( lineHeader, "shooter" ) == 0 )
            {
                int posx, posy, sizex, sizey;
                char _filename[128];
                fscanf(file, "%d %d %d %d %s\n", &posx, &posy, &sizex, &sizey, _filename );
                Add( std::make_shared<ShooterEnemy>(sf::Vector2f(posx, posy), sf::Vector2f(sizex, sizey), _filename));
            }
        }
    }
    fclose(file);
    Add(std::make_shared<Player>());
    Add(std::make_shared<GameObjectText>(sf::Vector2f(400, 300), 40, "resources/sansation.ttf"));
}
