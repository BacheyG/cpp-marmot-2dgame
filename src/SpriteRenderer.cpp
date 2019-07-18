#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer()
{
    //ctor
}

SpriteRenderer::SpriteRenderer(const char * filename, sf::Vector2f scale,  bool smooth) : extraScale{sf::Vector2f(1,1)}
{

    if (!texture.loadFromFile(filename))
    {
        // error...
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sf::Vector2u tx = texture.getSize();
    float x = scale.x / (float)tx.x;
    float y = scale.y / (float)tx.y;
    sprite.scale(x, y);
    extraScale = sf::Vector2f(x, y);
}

void SpriteRenderer::AddGameObject(GameObject * _g) {
    g = _g;
    GetGameObject()->GetTransform().SetDimensions(sf::Vector2f(texture.getSize().x * extraScale.x, texture.getSize().y * extraScale.y));
    GetGameObject()->GetTransform().SetExtraScale(extraScale);
}

void SpriteRenderer::setTexture(const char* fname){
    if (!texture.loadFromFile(fname))
    {
        // error...
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
}

sf::Drawable* SpriteRenderer::getDrawable(){
    return &sprite;
}

sf::Transformable* SpriteRenderer::getTransformable(){
    return &sprite;
}
