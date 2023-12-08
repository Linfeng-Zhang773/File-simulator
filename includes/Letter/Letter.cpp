#include "Letter.h"

Letter::Letter() : sf::Text()
{
}

Letter::Letter(char c) : sf::Text()
{
    setFont(Fonts::getFont(OPEN_SANS));
    setString(std::string(1, c));
    setCharacterSize(40);
    setFillColor(sf::Color::Red);
}