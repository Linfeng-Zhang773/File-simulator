#ifndef COMMANDHINTBUTTON
#define COMMANDHINTBUTTON
#include "../Box/Box.h"
#include "../Fonts/Fonts.h"
#include "../GUIcomponent/GUIcomponent.h"
#include "../Mouse/MouseEvents.h"
#include "../States/States.h"

#include <SFML/Graphics.hpp>
class CommandHintButton : public GUIComponent, public States
{
private:
    Box button;
    sf::Text show;
    sf::Text openCommand;
    sf::Text createCommand;
    sf::Text deleteCommand;
    sf::Text renameCommand;
    sf::Text moveCommand;
    sf::Text searchCommand;
    sf::Text saveCommand;

public:
    CommandHintButton();

    CommandHintButton(sf::Vector2f size, sf::Vector2f pos);

    const Box getbutton() const;

    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
   
    void setPosistion(const sf::Vector2f& pos);
};

#endif