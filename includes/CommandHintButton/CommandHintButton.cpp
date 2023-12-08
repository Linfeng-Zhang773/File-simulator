#include "CommandHintButton.h"

CommandHintButton::CommandHintButton() {}

CommandHintButton::CommandHintButton(sf::Vector2f size, sf::Vector2f pos)
{
    // sf::Text openCommand;
    // sf::Text deleteCommand;
    // sf::Text renameCommand;
    // sf::Text moveCommand;
    // sf::Text searchCommand;
    // sf::Text saveCommand;
    this->button.setSize(size);
    this->button.setPosistion(pos);

    this->show.setString("Show commands");
    this->show.setCharacterSize(20);
    this->show.setFont(Fonts::getFont(OPEN_SANS));
    this->show.setFillColor(sf::Color::Black);
    this->show.setPosition({pos.x + 5, pos.y + 5});

    this->openCommand.setString("How to Open file: cd filepath");
    this->openCommand.setCharacterSize(24);
    this->openCommand.setFont(Fonts::getFont(OPEN_SANS));
    this->openCommand.setFillColor(sf::Color::Green);
    this->openCommand.setPosition({pos.x, pos.y + 40});

    this->deleteCommand.setString("How to Delete file: delete filepath");
    this->deleteCommand.setCharacterSize(24);
    this->deleteCommand.setFont(Fonts::getFont(OPEN_SANS));
    this->deleteCommand.setFillColor(sf::Color::Green);
    this->deleteCommand.setPosition({pos.x, pos.y + 70});

    this->renameCommand.setString("How to Rename file: rename filepath");
    this->renameCommand.setCharacterSize(24);
    this->renameCommand.setFont(Fonts::getFont(OPEN_SANS));
    this->renameCommand.setFillColor(sf::Color::Green);
    this->renameCommand.setPosition({pos.x, pos.y + 100});

    this->moveCommand.setString("How to move file: move filepath");
    this->moveCommand.setCharacterSize(24);
    this->moveCommand.setFont(Fonts::getFont(OPEN_SANS));
    this->moveCommand.setFillColor(sf::Color::Green);
    this->moveCommand.setPosition({pos.x, pos.y + 130});

    this->searchCommand.setString("How to search file: search filename");
    this->searchCommand.setCharacterSize(24);
    this->searchCommand.setFont(Fonts::getFont(OPEN_SANS));
    this->searchCommand.setFillColor(sf::Color::Green);
    this->searchCommand.setPosition({pos.x, pos.y + 160});

    this->saveCommand.setString("How to save file: save to filepath");
    this->saveCommand.setCharacterSize(24);
    this->saveCommand.setFont(Fonts::getFont(OPEN_SANS));
    this->saveCommand.setFillColor(sf::Color::Green);
    this->saveCommand.setPosition({pos.x, pos.y + 190});
}

const Box CommandHintButton::getbutton() const
{
    return this->button;
}

void CommandHintButton::setPosistion(const sf::Vector2f& pos)
{
    this->button.setPosistion(pos);
    this->show.setPosition({pos.x + 5, pos.y + 5});
    this->openCommand.setPosition({pos.x + 20, pos.y + 20});
    this->deleteCommand.setPosition({pos.x + 40, pos.y + 40});
    this->renameCommand.setPosition({pos.x + 60, pos.y + 60});
    this->moveCommand.setPosition({pos.x + 80, pos.y + 80});
    this->searchCommand.setPosition({pos.x + 100, pos.y + 100});
    this->saveCommand.setPosition({pos.x + 120, pos.y + 120});
}
void CommandHintButton::addEventHandler(sf::RenderWindow& window, sf::Event event)
{

    if (MouseEvents<Box>::hovered(button, window))
    {
        enableState(HOVERED);
    }
    else
    {
        disableState(HOVERED);
    }
}
void CommandHintButton::update()
{
    this->button.update();
}
void CommandHintButton::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(this->button);
    window.draw(this->show);
    if (checkState(HOVERED))
    {
        window.draw(this->openCommand);
        window.draw(this->deleteCommand);
        window.draw(this->renameCommand);
        window.draw(this->moveCommand);
        window.draw(this->searchCommand);
        window.draw(this->saveCommand);
    }
}
SnapShot& CommandHintButton::getSnapshot() {}
void CommandHintButton::applySnapshot(const SnapShot& snapshot) {}
