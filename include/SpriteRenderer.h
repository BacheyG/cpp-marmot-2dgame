#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H
#include <SFML/Graphics.hpp>
#include "GameComponent.h"
class SpriteRenderer : public GameComponent
{
    public:
        SpriteRenderer();
        SpriteRenderer(const char* filename, sf::Vector2f scale, bool smooth = true);
        sf::Drawable* getDrawable() override;
        sf::Transformable* getTransformable() override;
        void AddGameObject(GameObject* g) override;
        void setTexture(const char* fname);
    protected:

    private:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Vector2f extraScale;
};

#endif // SPRITERENDERER_H
