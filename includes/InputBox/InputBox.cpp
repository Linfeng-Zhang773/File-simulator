
#include "InputBox.h"

InputBox::InputBox()
    : box({200, 40})
{
   
}

InputBox::InputBox(const sf::Vector2f& size, const sf::Vector2f& pos)
{
    this->box.setSize(size);
    this->box.setPosition(pos);
    this->selectedText.setString("select");
    selectedText.setFont(Fonts::getFont(OPEN_SANS));
    selectedText.setFillColor(sf::Color::Blue);
    this->selectedText.setCharacterSize(24);
    this->selectedText.setPosition(pos);
}

void InputBox::setItem(const Item& item)
{
    selectedText = item.text;
    selectedText.setFillColor(sf::Color::Blue);
    selectedText.setPosition({this->box.getPosition().x + 55, this->box.getPosition().y});
}
void InputBox::applyItem(sf::RenderTarget& window) const
{
    window.draw(selectedText);
}

void InputBox::addEventHandler(sf::RenderWindow& window, sf::Event event)
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

void InputBox::update()
{
}

void InputBox::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    if (!checkState(HIDDEN))
    {
        window.draw(box);
    }
}

const sf::RectangleShape& InputBox::getBox() const
{
    return this->box;
}

void InputBox::setPosition(const sf::Vector2f& pos,std::string s)
{
    this->box.setPosition(pos);
     this->selectedText.setString(s);
    selectedText.setFont(Fonts::getFont(OPEN_SANS));
    selectedText.setFillColor(sf::Color::Blue);
    this->selectedText.setCharacterSize(24);
    this->selectedText.setPosition(pos);
}
float InputBox::getYpos()
{
    return this->box.getPosition().y;
}

float InputBox::getXpos()
{
    return this->box.getPosition().x;
}

void InputBox::setSize(const sf::Vector2f& size)
{
    this->box.setSize(size);
}
