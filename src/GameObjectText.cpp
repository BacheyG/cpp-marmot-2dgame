#include "GameObjectText.h"

GameObjectText::GameObjectText(sf::Vector2f pos, float size, const char* fontdir) : GUI{pos}
{
    sf::Font font;
    if (!font.loadFromFile(fontdir))
    {
        text.setFont(font);
    }
    else
    {
        printf("Error loading file.");
    }
    text.setCharacterSize(size);
    text.setPosition(pos);
    text.setFillColor(sf::Color::White);
    text.setString("");

}

void GameObjectText::Update()
{
    GUI::Update();
    if (PlayerSingleton::getInstance().player->IsGameOver())
    {
        text.setString("Game Over");
    }
}
