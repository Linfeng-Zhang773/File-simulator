#include "typingBox.h"
std::string TypingBox::content = "";
std::string TypingBox::filePathToSave = "";
std::string TypingBox::fileMetaPathToSave = "";
std::string TypingBox::fileContentToSave = "";
bool TypingBox::isFileOpen = false;

sf::Color TypingBox::color = sf::Color::Black;
int TypingBox::font_Size = 30;
fontEnum TypingBox::ENUM = OPEN_SANS;

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

    this->label.setString("");
    this->label.setCharacterSize(50);
    this->label.setFillColor(sf::Color::Red);
    this->label.setFont(Fonts::getFont(OPEN_SANS));
    this->label.setPosition({0, 0});

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

void TypingBox::setLabel(std::string s)
{
    this->label.setString(s);
}
void TypingBox::setLabelPos(sf::Vector2f pos)
{
    this->label.setPosition(pos);
}
void TypingBox::setFont(sf::Font& fonts)
{
    inputText.setFont(fonts);
}

void TypingBox::setPosition(sf::Vector2f point)
{
    inputText.setPosition(point);
}

void TypingBox::setCharacter(int size)
{
    inputText.setCharacterSize(size);
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
    int CHAR_DIVIDE = 17;

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
    if (this->isFileInput && !TypingBox::isFileOpen) return;
    window.draw(rectangle);
    window.draw(inputText);
    window.draw(label);
}

// from EventHandler
void TypingBox::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    if (event.type == sf::Event::TextEntered) this->typedOn(event);
    this->updateCursor(window, event);
}
void TypingBox::update()
{
    // use bunch of logics to detect every command and keeping updating
    //  enter from command line
    if (this->selected() && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !this->isFileInput)
    {
        std::vector<std::string> v2 = extractStrings(inputText.getString());

        // read the file, store the stuff in content
        // TypingBox::content = "works";
        // type in cd dddd/file_1 and press enter then you do file operation(load the content, and then)
        if (v2[0] == "cd")
        {
            std::string name = extractFileName(v2[1]);
            // std::cout << "filename is: " << name << std::endl;
            std::string path = "../../Files/" + name;
            // v2[1] is Directory_1/Directory_2/file_7
            //  cd Directory_1/Directory_2/file_7

            // std::cout << "filepath is: " << path << std::endl;
            // detect file_7(if doesn't exist, new window with error message)
            //  open file logic
            //  s = file_7 + ".txt"
            // passing s as filepath into std::string ReadFile(std::string filepath);
            // label.setString(file_7)
            // then read file7_metadata.txt(get all the metadata)
            // set to text.set(...)
            //  v2[1] is the filepath do logic
            TypingBox::isFileOpen = true;
            TypingBox::filePathToSave = path.substr(0, path.length() - 1) + ".txt";
            TypingBox::fileMetaPathToSave = path.substr(0, path.length() - 1) + "_meta.txt";
            OpenLogic(path);
        }
        if (v2[0] == "delete")
        {
            std::string name = extractFileName(v2[1]);
            // std::cout << "filename is: " << name << std::endl;
            std::string path = "../../Files/" + name;
            DeleteLogic(path, name);
        }
        if (v2[0] == "rename")
        {
            // rename filepath to name
            std::string filename = extractFileName(v2[1]);
            // std::cout << "filename is: " << name << std::endl;
            std::string path = "../../Files/" + filename;
            std::string newName = v2[3];
            RenameLogic(path, filename, newName);
        }
        if (v2[0] == "move")
        {
            // move filename to folder
            std::string filename = (v2[1]);
            std::string parentName = (v2[3]);
            MoveLogic(parentName, filename);
        }
        if (v2[0] == "save")
        {
            SaveLogic();
        }
        if (v2[0] == "search")
        {
            std::string filename = v2[1];
            SearchLogic(filename);
        }
        if (v2[0] == "create")
        {
            // command: create filename Under folder
            //          v2[0]    v2[1]   v2[2]  v2[3]
            std::string filename = v2[1];
            std::string parentname = v2[3];
            CreateLogic(parentname, filename);
        }
        else
        { // this means input command not match any commands
          //  do nothing
        }
        this->setTextWithNoLimit("");
    }
    if (TypingBox::content.length() != 0 && this->isFileInput)
    {
        this->setTextWithNoLimit(content);
        this->setColor(color);

        this->setCharacter(font_Size);
        TypingBox::content = "";
        this->setFont(Fonts::getFont(TypingBox::ENUM));
    }
    if (this->isFileInput) TypingBox::fileContentToSave = this->getText();
}

void TypingBox::OpenLogic(std::string filepath)
{
    FileReader fileReader;
    std::string newPath = filepath.substr(0, filepath.length() - 1) + ".txt";
    std::string msg = fileReader.ReadFile(newPath);
    if (msg == "error") return;
    TypingBox::content = msg;
    std::string metaPath = filepath.substr(0, filepath.length() - 1) + "_meta.txt";
    std::vector<std::string> metaData = fileReader.ReadMetaData(metaPath);
    if (metaData.empty()) return;
    // meta[0] color
    // meta[1] size
    // meta[2] font
    // meta[3] left/middle/right

    // std::cout << "metaData[0] now is" << metaData[0] << "11" << std::endl;

    if (metaData[0] == "Black")
    {
        // std::cout << "equal";
        TypingBox::color = sf::Color::Black;
    }
    else if (metaData[0] == "Blue")
    {
        TypingBox::color = sf::Color::Blue;
    }
    else if (metaData[0] == "Red")
    {
        TypingBox::color = sf::Color::Red;
    }
    if (metaData[1] == "20")
    {
        TypingBox::font_Size = 20;
    }
    else if (metaData[1] == "25")
    {
        TypingBox::font_Size = 25;
    }
    else if (metaData[1] == "30")
    {
        TypingBox::font_Size = 30;
    }
    if (metaData[2] == "Arial")
    {
        TypingBox::ENUM = OPEN_SANS;
    }
    else if (metaData[2] == "Comfortaa")
    {
        TypingBox::ENUM = COMFOR;
    }
    else if (metaData[2] == "TimesNewRoman")
    {
        TypingBox::ENUM = TIMES;
    }
}

void TypingBox::DeleteLogic(std::string filepath, std::string filename)
{
    FileReader FileReader2;
    std::string newPath = filepath.substr(0, filepath.length() - 1) + ".txt";
    std::vector<std::string> V = FileReader2.ReadInfoFile("../../Files/Pathinfo.txt");
    if (V.empty()) return;
    std::string metaPath = filepath.substr(0, filepath.length() - 1) + "_meta.txt";
    for (int i = 0; i < V.size(); ++i)
    {

        if (V[i].find(filename.substr(0, filename.length() - 1)) != std::string::npos)
        {
            V.erase(V.begin() + i);
        }
    }
    remove(newPath.c_str());
    remove(metaPath.c_str());
    FileReader2.ModifyInfoFile(V, "../../Files/Pathinfo.txt");
    BuildFileTree::setUp("../../Files/Pathinfo.txt");
    Application::removeFileTreeAndReAdd(BuildFileTree::getFileTree());
}

void TypingBox::RenameLogic(std::string filepath, std::string originalName, std::string newFileName)
{
    // get current parent first
    std::string newPath = filepath.substr(0, filepath.length()) + ".txt";
    std::string metaPath = filepath.substr(0, filepath.length()) + "_meta.txt";

    FileReader FileReader2;
    std::vector<std::string> V = FileReader2.ReadInfoFile("../../Files/Pathinfo.txt");
    if (V.empty()) return;
    std::string parent = "";
    int idx = 0;
    for (int i = 0; i < V.size(); ++i)
    {
        if (V[i].find(originalName.substr(0, originalName.length())) != std::string::npos)
        {
            V.erase(V.begin() + i);
            parent = V[i].substr(0, 11);
            idx = i;
            break;
        }
    }

    remove(newPath.c_str());
    remove(metaPath.c_str());
    std::string newPath2 = "../../Files/" + newFileName.substr(0, newFileName.length() - 1) + ".txt";
    std::string metaPath2 = "../../Files/" + newFileName.substr(0, newFileName.length() - 1) + "_meta.txt";
    // std::ofstream outputFile(newPath2);
    // if (outputFile.is_open())
    //     outputFile.close();
    // else
    //     std::cout << "error open:" << newPath2 << "\n";

    // outputFile.open(metaPath2);
    // if (outputFile.is_open())
    // {
    //     outputFile << "Black\n30\nComfortaa";
    //     outputFile.close();
    // }
    // else
    // {
    //     std::cout << "error open:" << metaPath2 << "\n";
    // }
    std::vector<std::string> METADATA = {"Black", "30", "Comfortaa"};
    FileReader2.createNewFile(newPath2);
    FileReader2.WriteMetaData(METADATA, metaPath2);

    V.insert(V.begin() + idx, parent + " " + newFileName.substr(0, newFileName.length() - 1) + " " + "false");
    FileReader2.ModifyInfoFile(V, "../../Files/Pathinfo.txt");
    BuildFileTree::setUp("../../Files/Pathinfo.txt");
    Application::removeFileTreeAndReAdd(BuildFileTree::getFileTree());
}

void TypingBox::MoveLogic(std::string parent, std::string filename)
{
    // for example: parent is Directory_1, filename is file_7
    FileReader FileReader2;
    int idx = 0;
    std::vector<std::string> V = FileReader2.ReadInfoFile("../../Files/Pathinfo.txt");
    if (V.empty()) return;
    for (int i = 0; i < V.size(); ++i)
    {
        if (V[i].find(filename) != std::string::npos)
        {
            // std::cout << "FOUND!" << std::endl;
            V.erase(V.begin() + i);
            idx = i;
            break;
        }
    }
    V.insert(V.begin() + idx, parent.substr(0, parent.length() - 1) + " " + filename + " " + "false");
    std::vector<std::string> sortedV = SortFileInfo(V);
    FileReader2.ModifyInfoFile(sortedV, "../../Files/Pathinfo.txt");
    BuildFileTree::setUp("../../Files/Pathinfo.txt");
    Application::removeFileTreeAndReAdd(BuildFileTree::getFileTree());
}

void TypingBox::SaveLogic()
{
    std::string toSaveContent = TypingBox::fileContentToSave;
    FileReader reader;
    reader.ModifyFile(toSaveContent, TypingBox::filePathToSave);
    std::vector<std::string> v = {Menu::SELECTED_COLOR, Menu::SELECTED_SIZE, Menu::SELECTED_FONT};
    reader.WriteMetaData(v, TypingBox::fileMetaPathToSave);
    TypingBox::filePathToSave = "";
    TypingBox::fileMetaPathToSave = "";
    TypingBox::isFileOpen = false;
}

void TypingBox::SearchLogic(std::string filename)
{
    std::vector<std::string> v = BuildFileTree::getFileTree().findAndStorePath(filename);
    for (auto x : v)
    {
        std::cout << x << "/";
        std::cout << std::endl;
    }
}

void TypingBox::CreateLogic(std::string parent, std::string file)
{
    FileReader FileReader2;
    int idx = 0;
    std::vector<std::string> V = FileReader2.ReadInfoFile("../../Files/Pathinfo.txt");
    if (V.empty()) return;
    V.push_back(parent.substr(0, parent.length() - 1) + " " + file + " " + "false");
    std::string newFilePath = "../../Files/" + file + ".txt";
    std::string newMetaDataPath = "../../Files/" + file + "_meta.txt";
    FileReader2.ModifyFile("default", newFilePath);
    std::vector<std::string> defaultMeta = {"Black", "30", "Comfortaa"};
    FileReader2.WriteMetaData(defaultMeta, newMetaDataPath);
    std::vector<std::string> sortedV = SortFileInfo(V);
    FileReader2.ModifyInfoFile(sortedV, "../../Files/Pathinfo.txt");
    BuildFileTree::setUp("../../Files/Pathinfo.txt");
    Application::removeFileTreeAndReAdd(BuildFileTree::getFileTree());
}