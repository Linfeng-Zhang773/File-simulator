#ifndef ITEM_H
#define ITEM_H
#include "../Fonts/Fonts.h"
#include "../GUIcomponent/GUIComponent.h"
#include "../States/States.h"
#include <SFML/Graphics.hpp>
#include <string>
class Item // public GUIComponent, public States
{
public:
    sf::Text text;
    sf::RectangleShape box;

    Item(const std::string& name);
    Item();
    ~Item() = default;
    sf::Text getText();
    sf::RectangleShape getBox();
    sf::Vector2f getPosition();
    void Initialize(const std::string& name);
    void setSize(const sf::Vector2f& size);
    // void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    // void update() override;
    // void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
};
#endif