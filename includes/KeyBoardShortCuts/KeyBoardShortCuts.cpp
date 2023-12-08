#include "KeyBoardShortCuts.h"

bool KeyBoardShortCuts::isUndo()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            return true;
        }
    }
    return false;
}

bool KeyBoardShortCuts::isCopy()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            return true;
        }
    }
    return false;
}
bool KeyBoardShortCuts::isPaste()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
        {
            return true;
        }
    }
    return false;
}