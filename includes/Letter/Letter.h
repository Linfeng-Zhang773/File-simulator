#ifndef LETTER_H
#define LETTER_H
#include "../Fonts/Fonts.h"
#include <SFML/Graphics.hpp>
class Letter : public sf::Text
{
public:
    Letter();
    Letter(char c);
    void setPosition(float x, float y)
    {
        sf::Text::setPosition({x, y});
    }
    int size()
    {
        return sf::Text::getCharacterSize();
    }
};
#endif