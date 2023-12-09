

#include "Box.h"

Box::Box()
    : Box({50, 50})
{
}

Box::Box(const sf::Vector2f& size) : box(size) {}

void Box::addEventHandler(sf::RenderWindow& window, sf::Event event)
{

    sf::Vector2f mpos = (sf::Vector2f)sf::Mouse::getPosition(window);
    if (box.getGlobalBounds().contains(mpos))
    {
        enableState(HOVERED);
    }
    else
    {
        disableState(HOVERED);
    }
}

void Box::setSize(sf::Vector2f size)
{
    this->box.setSize(size);
}
void Box::update()
{
    if (checkState(HOVERED))
    {
        box.setFillColor(sf::Color(230,230,250));
    }
    else
    {
        box.setFillColor(sf::Color::White);
    }
}

void Box::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    if (!checkState(HIDDEN))
    {
        window.draw(box);
    }
}

const sf::RectangleShape& Box::getBox() const
{
    return this->box;
}

void Box::setPosistion(const sf::Vector2f& pos)
{
    this->box.setPosition(pos);
}

SnapShot& Box::getSnapshot() {}
void Box::applySnapshot(const SnapShot& snapshot) {}