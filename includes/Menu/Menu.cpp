#include "Menu.h"
void Menu::addItem(const std::string& Name)
{
    item.Initialize(Name);
    List.addItem(item);
    setProperPosition();
}

void Menu::chooseItem(const Item& item)
{
    inputBox.setItem(item);
}
void Menu::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    if (isItemListVisible)
    {
        displayList(window);
    }

    inputBox.draw(window, states);
    inputBox.applyItem(window);
}
void Menu::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    for (int i = 0; i < List.size(); ++i)
    {
        if (MouseEvents<Item>::mouseClicked(List.at(i), window))
        {
            chooseItem(List.at(i));
            isItemListVisible = false;
        }

        if (MouseEvents<Item>::hovered(List.at(i), window))
        {
            List.at(i).box.setFillColor(sf::Color::Blue); // Change color on hover
        }
        else
        {
            List.at(i).box.setFillColor(sf::Color::White); // Reset color
        }
    }
    this->inputBox.addEventHandler(window, event);

    // Toggle visibility of the ItemList when the input box is clicked
    if (MouseEvents<InputBox>::mouseClicked(this->inputBox, window)) //&& event.type == sf::Event::MouseButtonPressed)
    {
        isItemListVisible = !isItemListVisible;
    }
}
void Menu::update()
{

    this->inputBox.update();
}

void Menu::displayList(sf::RenderTarget& window) const
{
    for (int i = 0; i < List.size(); ++i)
    {

        window.draw(List.at(i).box);
        window.draw(List.at(i).text);
    }
}

void Menu::setBoxPosition(const sf::Vector2f& pos, std::string s)
{
    this->inputBox.setPosition(pos, s);
}

void Menu::setProperPosition()
{

    for (int i = 0; i < List.size(); ++i)
    {
        List.at(i).box.setPosition(inputBox.getXpos(), inputBox.getYpos() + (i + 1) * List.at(i).box.getSize().y);
        List.at(i).text.setPosition(inputBox.getXpos(), inputBox.getYpos() + (i + 1) * List.at(i).box.getSize().y);
    }
}

void Menu::changeSize(const sf::Vector2f& size)
{
    inputBox.setSize(size);
    for (int i = 0; i < List.size(); ++i)
    {
        // std::cout <<"666 " ;
        List.at(i).setSize(size);
    }
    // std::cout << List.size();
}

SnapShot& Menu::getSnapshot() {}
void Menu::applySnapshot(const SnapShot& snapshot) {}