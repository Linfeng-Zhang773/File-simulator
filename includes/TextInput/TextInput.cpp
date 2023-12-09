#include "TextInput.h"

TextInput::TextInput(const sf::Vector2f& size, const sf::Vector2f& labelPosition, int count)
{
    // init box
    this->box = Box(size);
    this->box.setPosistion(labelPosition);
    this->label.setFont(Fonts::getFont(OPEN_SANS));
    this->label.setCharacterSize(45);
    this->label.setFillColor(sf::Color::Yellow);
    this->label.setPosition(labelPosition);
    this->label.setString(" ");
    this->num = count;
    this->count = 0;
}

void TextInput::setBoxPosistion(const sf::Vector2f& pos)
{
    this->box.setPosistion(pos);
}

// from the sf::Drawable class
void TextInput::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    this->box.draw(window, states);
    mulText.draw(window, states);
    window.draw(label);
}

// from EventHandler
void TextInput::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    const int CHARACTER_SIZE = 26;
    this->count = num;
    // check box event handler
    this->box.addEventHandler(window, event);

    // check mouse first, if it's not hover, do nothing
    if (!MouseEvents<Box>::hovered(box, window))
    {
        return;
    }

    // // if not above, check if typing
    if (this->count > MAX_CHARACTER_LIMIT + this->num) return;
    if (event.type != sf::Event::TextEntered)
    {
        return;
    }
    if (event.type == sf::Event::TextEntered && !(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)))
    {

        SnapShot snap(this->mulText.getString());
        HistoryNode node(snap, this);
        History::pushHistory(node);
        char c = static_cast<char>(event.text.unicode);

        Letter letter(c);
        // letter.setPosition(count / 1.5, 0);

        letter.setCharacterSize(CHARACTER_SIZE);
        // this->count += size;
        letter.setFillColor(sf::Color::Black);
        mulText.push(c);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
    {
        if (mulText.size() > 1)
        {
            SnapShot snap(this->mulText.getString());
            HistoryNode node(snap, this);
            History::pushHistory(node);
            mulText.pop();
            mulText.pop();
            this->count -= CHARACTER_SIZE;
        }
    }
    if (KeyBoardShortCuts::isUndo())
    {
        // std::cout << "GO in" << std::endl;
        // std::cout << History::size() << std::endl;
        if (History::size() != 0)
        {
            std::string s = History::topHistory().snapshot.data;
            std::cout << s << std::endl;
            History::popHistory();
            mulText.clear();
            for (char c : s)
            {
                mulText.push(c);
            }
        }
    }

    std::string s = mulText.getString();
    mulText.clear();
    std::vector<std::string> v = extractWords(s);
    for (std::string word : v)
    {

        Letter l(word[0]);
        l.setFillColor(sf::Color::Black);

        l.setPosition(count / 1.5, this->box.getBox().getPosition().y);
        this->count += CHARACTER_SIZE;
        mulText.push(l);
    }
    if (mulText.barExist())
    {
        this->mulText.removeBar();
    }
    Letter l('|');
    // set position
    l.setFillColor(sf::Color::Red);

    l.setPosition(count / 1.5, this->box.getBox().getPosition().y);
    this->count += CHARACTER_SIZE;
    mulText.push(l);
    // std::cout << s << std::endl;

    //=============================Logic about check commands==========================
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        std::vector<std::string> v2 = extractStrings(s);
        // v2[0]=cd or ..., v2[1] = filepath
        //  for (int i = 0; i < v2.size(); ++i)
        //  {
        //      std::cout << v2[i] << std::endl;
        //  }
        if (v2[0] == "cd")
        {
            // open file logic
            // v2[1] is the filepath do logic
        }
        else if (v2[0] == "createUnder")
        {
            // create new file logic
        }
        else if (v2[0] == "delete")
        {
            // delete file logic
        }
        else if (v2[0] == "rename")
        {
            // rename file logic
        }
        else if (v2[0] == "move")
        {
            // move file logic
        }
        else if (v2[0] == "search")
        {
            // search filename logic
        }
        else
        {
            // save file modification logic
        }
    }
}
void TextInput::update()
{
    // if it's hovered, check if you trigger any keyboard shortcuts
    // should call the box update function, or other gui component's child classes' update function

    this->box.update();
}

void TextInput::setCount(int cos)
{
    this->count = cos;
}
void TextInput::setLabel(std::string s)
{
    this->label.setString(s);
}
void TextInput::setLabelSize(int size)
{
    this->label.setCharacterSize(size);
}
void TextInput::setLabelMargin(std::vector<float> margin)
{
    float X = this->label.getPosition().x + margin[3] - margin[1];
    float Y = this->label.getPosition().y + margin[0] - margin[2];
    this->label.setPosition({X, Y});
}
void TextInput::setLabelPosition(const sf::Vector2f& pos)
{
    this->label.setPosition(pos);
}
// from SnapshotInterface
SnapShot& TextInput::getSnapshot()
{
}
void TextInput::applySnapshot(const SnapShot& snapshot) {}