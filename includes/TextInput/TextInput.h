#ifndef TEXTINPUT_H
#define TEXTINPUT_H
#include "../Box/Box.h"
#include "../GUIcomponent/GUIcomponent.h"
#include "../Helpers/helpers.h"
#include "../History/History.h"
#include "../HistoryNode/HistoryNode.h"
#include "../KeyBoardShortCuts/KeyBoardShortCuts.h"
#include "../Mouse/MouseEvents.h"
#include "../MultiText/MultiText.h"
#include <SFML/Graphics.hpp>

class TextInput : public GUIComponent
{
private:
    Box box;
    sf::Text label;
    MultiText mulText;
    static const int MAX_CHARACTER_LIMIT = 720;
    int count;
    int num;
    sf::RectangleShape cursor;
    bool cursorVisible;
    sf::Clock cursorBlinkTimer;

public:
    TextInput() = default;
    TextInput(const sf::Vector2f& size, const sf::Vector2f& labelPosition, int count);
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
};

#endif