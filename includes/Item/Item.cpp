#include "Item.h"

Item::Item(const std::string& name)
{
    text.setString(name);
    text.setFont(Fonts::getFont(OPEN_SANS));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    // text.setPosition(box.getPosition());
    box.setSize(sf::Vector2f(200, 40)); // Adjust size as needed
    box.setFillColor(sf::Color::White);
};
sf::Vector2f Item::getPosition()
{
    return this->box.getPosition();
}

void Item::Initialize(const std::string& name)
{

    text.setString(name);
    text.setFont(Fonts::getFont(OPEN_SANS));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    // text.setPosition(box.getPosition());
    box.setSize(sf::Vector2f(200, 40)); // Adjust size as needed
    box.setFillColor(sf::Color::White);
}

Item::Item() {}

sf::Text Item::getText()
{
    return this->text;
}

sf::RectangleShape Item::getBox()
{
    return this->box;
}

void Item::setSize(const sf::Vector2f& size)
{
    this->box.setSize(size);
}
// void Item::addEventHandler(sf::RenderWindow& window, sf::Event event)
// {

//     sf::Vector2f mpos = (sf::Vector2f)sf::Mouse::getPosition(window);
//     if (box.getGlobalBounds().contains(mpos))
//     {
//         enableState(HOVERED);
//     }
//     else
//     {
//         disableState(HOVERED);
//     }
// }

// void Item::update()
// {
//     if (checkState(HOVERED))
//     {
//         box.setFillColor(sf::Color::Blue);
//     }
//     else
//     {
//         box.setFillColor(sf::Color::White);
//     }
// }

// void Item::draw(sf::RenderTarget& window, sf::RenderStates states) const
// {
//     if (!checkState(HIDDEN))
//     {
//         window.draw(box);
//     }
// }