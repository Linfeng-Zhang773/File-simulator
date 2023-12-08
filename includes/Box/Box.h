

#ifndef SFML_PROJECT_BOX_H
#define SFML_PROJECT_BOX_H

#include "../GUIcomponent/GUIcomponent.h"

#include "../States/States.h"

#include <SFML/Graphics.hpp>

class Box : public GUIComponent, public States
{
private:
    sf::RectangleShape box;

public:
    Box();
    Box(const sf::Vector2f& size);

    const sf::RectangleShape& getBox() const;
    /////Event Handler
    void setSize(sf::Vector2f size);
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    SnapShot& getSnapshot() override;
    void applySnapshot(const SnapShot& snapshot) override;
    void setPosistion(const sf::Vector2f& pos);
};

#endif // SFML_PROJECT_BOX_H
