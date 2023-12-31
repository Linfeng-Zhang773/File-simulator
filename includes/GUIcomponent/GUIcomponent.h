

#ifndef SFML_PROJECT_GUICOMPONENT_H
#define SFML_PROJECT_GUICOMPONENT_H
#include "../States/States.h"
#include <SFML/Graphics.hpp>

class GUIComponent : public sf::Drawable//public SnapshotInterface
{
public:
    // from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

   
};

#endif // SFML_PROJECT_GUICOMPONENT_H
