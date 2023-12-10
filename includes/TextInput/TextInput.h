#ifndef TEXTINPUT_H
#define TEXTINPUT_H
#include "../Box/Box.h"
#include "../FileReader/FileReader.h"
#include "../GUIcomponent/GUIcomponent.h"
#include "../Helpers/helpers.h"
#include "../History/History.h"
#include "../HistoryNode/HistoryNode.h"
#include "../KeyBoardShortCuts/KeyBoardShortCuts.h"
#include "../Mouse/MouseEvents.h"
#include "../MultiText/MultiText.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class TextInput : public GUIComponent
{
private:
    Box box;
    sf::Text text;
    sf::Text label;
    MultiText mulText;
    static const int MAX_CHARACTER_LIMIT = 720;
    int count;
    int num;
    sf::RectangleShape cursor;
    bool cursorVisible;
    sf::Clock cursorBlinkTimer;
    static bool DrawFileInput;
    bool isFileInput;

    static std::string current;
    static int FontSize;
    static fontEnum ENUM;
    static sf::Color theColor;
    static sf::Vector2f thePos;

public:
    TextInput() = default;
    TextInput(bool isFile, const sf::Vector2f& size, const sf::Vector2f& labelPosition, int count);
    ~TextInput() = default;

    // from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;

    // from SnapshotInterface
    SnapShot& getSnapshot() override;
    void applySnapshot(const SnapShot& snapshot) override;
    void setBoxPosistion(const sf::Vector2f& pos);
    void setLabel(std::string s);
    void setLabelSize(int size);
    void setLabelMargin(std::vector<float> margin);
    void setLabelPosition(const sf::Vector2f& pos);
    void setCount(int cos);

    void OpenLogic(std::string filepath);
};

#endif