

#ifndef INPUTBOX_H
#define INPUTBOX_H

#include "../Fonts/Fonts.h"
#include "../GUIcomponent/GUIComponent.h"
#include "../Item/Item.h"
#include "../States/States.h"

#include <SFML/Graphics.hpp>

class InputBox : public GUIComponent, public States
{
private:
    sf::RectangleShape box;
    sf::Text selectedText;

public:
    InputBox();
    InputBox(const sf::Vector2f& size, const sf::Vector2f& pos);
    void setItem(const Item& item);
    void applyItem(sf::RenderTarget& window) const;
    const sf::RectangleShape& getBox() const;
    /////Event Handler
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void setPosition(const sf::Vector2f& pos, std::string s = "Select");
    float getYpos();
    float getXpos();
    void setSize(const sf::Vector2f& size);
};

#endif // SFML_PROJECT_BOX_H
