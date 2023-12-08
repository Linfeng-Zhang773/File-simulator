#include "MenuBar.h"

// MenuBar::MenuBar()
// {
// }
// // MenuBar::MenuBar()
// // {
// // }
void MenuBar::addMenu(const Menu& menu)
{
    menuBar.push_back(menu);
}
void MenuBar::popMenu()
{
    menuBar.pop_back();
}
int MenuBar::size() const
{
    return menuBar.size();
}
const Menu& MenuBar::at(int i) const
{
    return menuBar[i];
}
Menu& MenuBar::at(int i)
{
    return menuBar[i];
}

void MenuBar::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for (int i = 0; i < menuBar.size(); ++i)
    {
        menuBar[i].draw(window, states);
    }
}
void MenuBar::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    for (int i = 0; i < menuBar.size(); ++i)
    {
        menuBar[i].addEventHandler(window, event);
    }
}
void MenuBar::update()
{
    for (int i = 0; i < menuBar.size(); ++i)
    {
        menuBar[i].update();
    }
}

SnapShot& MenuBar::getSnapshot() {}
void MenuBar::applySnapshot(const SnapShot& snapshot) {}