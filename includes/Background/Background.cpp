#include "Background.h"

sf::Texture Background::BackGroundFile = []() -> sf::Texture
{
    sf::Texture texture;
    texture.loadFromFile("assets/classicWallpaper.jpg");

    return texture;
}();
Background::Background() {}
Background::Background(sf::Vector2f pos)
{
    this->icon.setTexture(BackGroundFile);
    this->icon.setScale(1.1f, 1.1f);
    this->icon.setPosition(pos);
}

void Background::setBackGroundPos(sf::Vector2f pos)
{
    this->icon.setPosition(pos);
}
void Background::setBackGround()
{
    this->icon.setTexture(BackGroundFile);
}
void Background::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    // nothing
}
void Background::update()
{
    // nothing
}
void Background::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(this->icon);
}
