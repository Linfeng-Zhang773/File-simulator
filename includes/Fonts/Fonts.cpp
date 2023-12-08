#include "Fonts.h"

std::map<fontEnum, sf::Font> Fonts::fonts;

void Fonts::loadFont(fontEnum font)
{
    fonts[font].loadFromFile(getFontPath(font));
}
std::string Fonts::getFontPath(fontEnum font)
{
    std::string f[] = {"assets/arial.ttf"};
    return f[font];
}
sf::Font& Fonts::getFont(fontEnum font)
{
    loadFont(font);
    return fonts[font];
}