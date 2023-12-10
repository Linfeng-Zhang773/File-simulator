#include "typingBox.h"
std::string TypingBox::content = "";

TypingBox::TypingBox(int fontSize, sf::Vector2f boxSize, sf::Vector2f position, sf::Color textColor, sf::Color boxColor, bool selected, bool isFileInput, std::string textString, bool needNewLine)
{
    isSelected = false;
    hasLimit = false;
    this->isFileInput = isFileInput;
    limit = 0;
    needLine = needNewLine;
    rectangle.setSize(boxSize);
    rectangle.setFillColor(boxColor);
    rectangle.setPosition(position);
    inputText.setCharacterSize(fontSize);
    inputText.setFillColor(textColor);
    inputText.setPosition(position);
    isSelected = selected;

    text = textString;
    initialTextLen = textString.length();

    if (isSelected)
        inputText.setString(text + "|");
    else
        inputText.setString(text);
}
void TypingBox::setColor(sf::Color color)
{
    this->inputText.setFillColor(color);
}

void TypingBox::setTextWithNoLimit(std::string str)
{
    text = str;
    inputText.setString(text);
}

void TypingBox::setText(std::string str)
{
    text = str;
    initialTextLen = str.length();
    inputText.setString(text);
}

void TypingBox::setFont(sf::Font& fonts)
{
    inputText.setFont(fonts);
}

void TypingBox::setPosition(sf::Vector2f point)
{
    inputText.setPosition(point);
}

void TypingBox::setLimit(bool flag)
{
    hasLimit = flag;
}

void TypingBox::setLimit(bool flag, int lim)
{
    hasLimit = flag;
    limit = lim - 1;
}

void TypingBox::setSelected(bool selected)
{
    isSelected = selected;

    std::string newT = "";
    if (!selected)
    {
        std::string t = text;
        for (int i = 0; i < t.length(); i++)
        {
            newT += t[i];
        }
        inputText.setString(newT);
        return;
    }
}

std::string TypingBox::getText()
{
    return text;
}

void TypingBox::typedOn(sf::Event& input)
{
    if (!isSelected) return;

    int charTyped = input.text.unicode;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::C)) return;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::V)) return;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::X)) return;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) return;

    if (charTyped < 128)
    {
        if (hasLimit)
        {

            if (text.length() <= limit)
            {
                inputLogic(charTyped);
            }

            else if (text.length() > limit && charTyped == DELETE_KEY)
            {
                deleteLastChar();
            }
        }

        else
        {
            inputLogic(charTyped);
        }
    }
}

void TypingBox::deleteLastChar()
{
    if (text.length() == initialTextLen) return;
    std::string t = text;
    std::string newT = "";
    for (int i = 0; i < t.length() - 1; i++)
    {
        newT += t[i];
    }
    text = newT;
    inputText.setString(text + "|");
}

void TypingBox::inputLogic(int charTyped)
{
    int CHAR_DIVIDE = 14;

    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
    {
        text += static_cast<char>(charTyped);
        if (needLine && (text.length() + 1) % (int(rectangle.getSize().x / CHAR_DIVIDE)) == 0) text += '\n';
    }

    if (charTyped == DELETE_KEY)
    {
        if (text.length() > 0)
        {
            deleteLastChar();
        }
    }

    std::string str = text + "|";
    inputText.setString(str);
}

void TypingBox::updateCursor(sf::RenderWindow& window, sf::Event& event)
{
    sf::Vector2i mouseCoords({sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y});

    sf::Vector2f realCoords = window.mapPixelToCoords(mouseCoords);

    float mouseX = realCoords.x;
    float mouseY = realCoords.y;

    int boxPosX = rectangle.getPosition().x;
    int boxPosY = rectangle.getPosition().y;

    int boxXPosWidth = rectangle.getPosition().x + rectangle.getGlobalBounds().width;
    int boxYPosHeight = rectangle.getPosition().y + rectangle.getGlobalBounds().height;

    bool clicked = event.type == sf::Event::MouseButtonPressed;
    if (mouseX < boxXPosWidth && mouseX > boxPosX && mouseY < boxYPosHeight && mouseY > boxPosY)
    {

        if (clicked)
        {
            this->setSelected(true);
            this->inputText.setString(this->getText() + "|");
            return;
        }
    }
    if (clicked || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) this->setSelected(false);
}

void TypingBox::clear()
{
    text = "";
    initialTextLen = text.length();
    inputText.setString(text);
}

// from the sf::Drawable class
void TypingBox::draw(sf::RenderTarget& window, sf::RenderStates states) const
{

    window.draw(rectangle);
    window.draw(inputText);
}

// from EventHandler
void TypingBox::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    if (event.type == sf::Event::TextEntered) this->typedOn(event);
    this->updateCursor(window, event);
}
void TypingBox::update()
{
    
    // enter from command line
    if (this->selected() && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !this->isFileInput)
    {
        // read the file, store the stuff in content
        TypingBox::content = "works";
        // type in cd dddd/file_1 and press enter then you do file operation(load the content, and then)
    }
    if (TypingBox::content.length() != 0 && this->isFileInput)
    {
        this->setTextWithNoLimit(content);
        TypingBox::content = "";
    }
}