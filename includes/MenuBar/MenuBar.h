#ifndef MENUBAR_H
#define MENUBAR_H
#include "../GUIcomponent/GUIcomponent.h"
#include "../Menu/Menu.h"
#include <vector>
class MenuBar : public GUIComponent
{
private:
    std::vector<Menu> menuBar;

public:
    MenuBar() = default;
    void addMenu(const Menu& menu);
    void popMenu();
    int size() const;
    const Menu& at(int i) const;
    Menu& at(int i);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    SnapShot& getSnapshot() override;
    void applySnapshot(const SnapShot& snapshot) override;
};

#endif