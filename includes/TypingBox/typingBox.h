#ifndef TYPINGBOX_H
#define TYPINGBOX_H
// Text Input commponent
#include "../FileReader/FileReader.h"
#include "../GUIcomponent/GUIcomponent.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
// Define keys:
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class TypingBox : public GUIComponent
{
private:
    static std::string content;
    bool isFileInput;
    sf::Text inputText;
    std::string text;
    int initialTextLen;
    bool isSelected;
    bool hasLimit;
    bool needLine;
    int limit;
    sf::RectangleShape rectangle;

    void deleteLastChar();

    void inputLogic(int charTyped);

public:
    TypingBox() = default;
    TypingBox(int fontSize, sf::Vector2f boxSize, sf::Vector2f position, sf::Color textColor, sf::Color boxColor, bool selected, bool isFileInput, std::string textString = "", bool needNewLine = true);

    void setFont(sf::Font& fonts);

    void setPosition(sf::Vector2f point);

    void setLimit(bool flag);

    void setLimit(bool flag, int lim);

    void setSelected(bool selected);

    std::string getText();
    bool selected() { return this->isSelected; }
    void clear();
    void setColor(sf::Color color);
    sf::Text& getInputText() { return this->inputText; }

    void typedOn(sf::Event& input);
    void setText(std::string str);
    void setTextWithNoLimit(std::string str);
    void updateCursor(sf::RenderWindow& window, sf::Event& event);

    // from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;

    // from SnapshotInterface
    SnapShot& getSnapshot() override {}
    void applySnapshot(const SnapShot& snapshot) override {}
};

#endif