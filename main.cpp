
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "Player.h"
#include "LevelBrick.h"
#include "Scene.h"
#include "ShroomEnemy.h"
#include "MormotaConstants.h"
#include "ShooterEnemy.h"

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////

int main()
{
    GameTimer gameTimer;

    sf::RenderWindow window(sf::VideoMode(MormotaConstants::WINDOW_WIDTH, MormotaConstants::WINDOW_HEIGHT, 32), "Mormota Game",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    Scene gameScene(window);
    gameScene.Load("resources/level.txt");
    while (window.isOpen())
    {
        gameTimer.UpdateValues();
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Window closed or escape key pressed: exit
            if ((event.type == sf::Event::Closed) ||
                    ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }
        }

        window.clear(sf::Color(50, 200, 240));

        // Display things on screen
        gameScene.Update();
        window.display();
    }

    return EXIT_SUCCESS;
}
