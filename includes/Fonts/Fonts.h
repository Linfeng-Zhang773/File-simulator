#ifndef FONTS_H
#define FONTS_H
#include "../FontEnum/FontEnum.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
class Fonts
{
private:
    static std::map<fontEnum, sf::Font> fonts;
    static void loadFont(fontEnum font);
    static std::string getFontPath(fontEnum font);

public:
    static sf::Font& getFont(fontEnum font);
};
#endif