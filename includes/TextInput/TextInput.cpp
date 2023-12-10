#include "TextInput.h"
bool TextInput::DrawFileInput = false;
std::string TextInput::current = "";
int TextInput::FontSize = 30;
fontEnum TextInput::ENUM = OPEN_SANS;
sf::Color TextInput::theColor = sf::Color::Black;
sf::Vector2f TextInput::thePos = {500, 300};
TextInput::TextInput(bool isFile, const sf::Vector2f& size, const sf::Vector2f& labelPosition, int count)
{
    // init box
    this->isFileInput = isFile;
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
    if (!isFileInput || (isFileInput && DrawFileInput))
    {
        this->box.draw(window, states);
        // mulText.draw(window, states);
        window.draw(this->text);
        window.draw(label);
    }
}

// from EventHandler
void TextInput::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    const int CHARACTER_SIZE = 26;
    this->count = num;
    // check box event handler
    this->box.addEventHandler(window, event);

    // check mouse first, if it's not hover, do nothing

    // // if not above, check if typing
    // if (this->count > MAX_CHARACTER_LIMIT + this->num) return;

    if (MouseEvents<Box>::hovered(box, window) && event.type == sf::Event::TextEntered && !(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)))
    {

        // // SnapShot snap(this->mulText.getString());
        // // HistoryNode node(snap, this);
        // History::pushHistory(node);
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
        if (mulText.size() > 0)
        {
            SnapShot snap(this->mulText.getString());
            HistoryNode node(snap, this);
            History::pushHistory(node);
            mulText.pop();
            // mulText.pop();
            this->count -= CHARACTER_SIZE;
        }
    }
    if (KeyBoardShortCuts::isUndo())
    {
        if (History::size() != 0)
        {
            std::string s = History::topHistory().snapshot.data;
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
    std::vector<std::string> v; //= extractWords(s);
    if (current.length() != 0 && isFileInput)
    {
        v = extractWords(current);
    }
    else
    {
        v = extractWords(s);
    }
    for (std::string word : v)
    {

        Letter l(word[0]);
        l.setFillColor(sf::Color::Black);

        l.setPosition(count / 1.5, this->box.getBox().getPosition().y);
        this->count += CHARACTER_SIZE;
        mulText.push(l);
    }
    // if (mulText.barExist())
    // {
    //     this->mulText.removeBar();
    // }
    // Letter l('|');
    // // set position
    // l.setFillColor(sf::Color::Red);

    // l.setPosition(count / 1.5, this->box.getBox().getPosition().y);
    // this->count += CHARACTER_SIZE;
    // mulText.push(l);
    // std::cout << s << std::endl;
    // std::string current = s;
    //=============================Logic about check commands==========================
    if (!isFileInput)
    {
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

                // v2[1] is Directory_1/Directory_2/file_7
                //  cd Directory_1/Directory_2/file_7
                std::string name = extractFileName(v2[1]);
                // std::cout << "filename is: " << name << std::endl;
                std::string path = "../../Files/" + name;
                // std::cout << "filepath is: " << path << std::endl;
                // detect file_7(if doesn't exist, new window with error message)
                //  open file logic
                //  s = file_7 + ".txt"
                // passing s as filepath into std::string ReadFile(std::string filepath);
                // label.setString(file_7)
                // then read file7_metadata.txt(get all the metadata)
                // set to text.set(...)
                //  v2[1] is the filepath do logic
                OpenLogic(path);
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
            else if (v2[0] == "save")
            {
                // save file modification logic
            }
            else
            {
                // command not match any, new window with error message
            }
        }
    }
    // std::cout << current << std::endl;
    if (isFileInput)
    {
        // mulText.clear();
        // for (int i = 0; i < current.length(); ++i)
        // {
        //     Letter l(current[i]);
        //     mulText.push(l);
        // }
        text.setString(TextInput::current + s);
        text.setFont(Fonts::getFont(TextInput::ENUM));
        text.setCharacterSize(TextInput::FontSize);
        text.setFillColor(TextInput::theColor);
        text.setPosition(TextInput::thePos);
    }
    else
    {
        this->text.setString(s);
        text.setFont(Fonts::getFont(OPEN_SANS));
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::Black);
        text.setPosition(this->box.getBox().getPosition());
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

void TextInput::OpenLogic(std::string filepath)
{
    DrawFileInput = true;
    FileReader fileReader;

    std::string newPath = filepath.substr(0, filepath.length() - 1) + ".txt";
    TextInput::current = fileReader.ReadFile(newPath);
    // std::string metaPath = filepath.substr(0, filepath.length() - 1) + "_meta.txt";
    // std::vector<std::string> metaData = fileReader.ReadMetaData(metaPath);
    // if(metaData[0]=="Black")
    // {

    // }
    // else if()
    // TextInput::current = fileReader.ReadFile(filepath);
    // getFilepath
    // FileReader to read file_7.txt
    // text.setString()
    // TextInput FileInput(true, true, {700, 500}, {500, 200}, 630);
    //   app.addComponent(FileInput);
}