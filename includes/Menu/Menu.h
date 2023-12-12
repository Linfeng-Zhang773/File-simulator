#ifndef DROPDOWNMENU_H
#define DROPDOWNMENU_H
#pragma once
#include "../Fonts/Fonts.h"
#include "../GUIcomponent/GUIcomponent.h"
#include "../Item/Item.h"
#include "../ItemList/ItemList.h"
#include "../Mouse/MouseEvents.h"
#include "../TypingBox/typingBox.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
class Menu : public GUIComponent
{
private:
    void setSelectedOption(int i);

public:
    static std::string SELECTED_COLOR;
    static std::string SELECTED_FONT;
    static std::string SELECTED_SIZE;
    ItemList List;
    InputBox inputBox;
    Item item;
    bool isItemListVisible = false;
    // DropdownMenu();
    void addItem(const std::string& Name);
    void setBoxPosition(const sf::Vector2f& pos, std::string s = "Select");
    void chooseItem(const Item& item);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    void displayList(sf::RenderTarget& window) const;
    void setProperPosition();
    void changeSize(const sf::Vector2f& size);
};

#endif