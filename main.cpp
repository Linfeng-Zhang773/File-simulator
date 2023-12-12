#include "includes/Application/Application.h"
#include "includes/Background/Background.h"
#include "includes/BuildFileTree/BuildFileTree.h"
#include "includes/CommandHintButton/CommandHintButton.h"
#include "includes/FileReader/FileReader.h"
#include "includes/FileTree/FileTree.h"
#include "includes/Fonts/Fonts.h"
#include "includes/Helpers/helpers.h"
#include "includes/InputBox/InputBox.h"
#include "includes/Menu/Menu.h"
#include "includes/MenuBar/MenuBar.h"
#include "includes/TypingBox/typingBox.h"
#include <SFML/Graphics.hpp>
int main()
{
    // std::vector<std::string> lines = {
    //     "empty Directory_1 true",
    //     "Directory_1 file_1 false",
    //     "Directory_1 file_2 false",
    //     "Directory_1 Directory_2 true",
    //     "Directory_2 file_99 false",
    //     "Directory_2 file_4 false",
    //     "Directory_2 file_5 false",
    //     "Directory_2 Directory_3 true",
    //     "Directory_1 file_6 false",
    //     "Directory_3 file_7 false"};
    // std::vector<std::string> sortedLines = SortFileInfo(lines);
    // for (const auto& line : sortedLines)
    // {
    //     std::cout << line << std::endl;
    // }

    // test for string split
    //   std::string s = "cd filename filepat|h";
    //  std::vector<std::string> v = extractStrings(s);
    //  for (int i = 0; i < v.size(); ++i)
    //  {
    //      std::cout << v[i] << std::endl;
    //  }
    Background wallpaper({0, 0});
    // TextInput commandLine(false, {800, 100}, {430, 850}, 670);
    // TextInput FileInput(true, {700, 500}, {500, 300}, 630);
    TypingBox commandLine(30, sf::Vector2f(800, 100), sf::Vector2f(420, 850), sf::Color::White, sf::Color::Black, false, false, "", false);
    TypingBox fileInput(30, sf::Vector2f(650, 500), sf::Vector2f(580, 300), sf::Color::Red, sf::Color::White, false, true);
    commandLine.setLimit(false);
    commandLine.setFont(Fonts::getFont(OPEN_SANS));

    fileInput.setLimit(false);
    fileInput.setFont(Fonts::getFont(OPEN_SANS));
    commandLine.setLabel("Command: ");
    commandLine.setLabelPos({160, 850});

    fileInput.setLabel("File: ");
    fileInput.setLabelPos({470, 280});

    Menu color;
    Menu size;
    Menu Font;

    CommandHintButton button({160, 30}, {20, 400});

    // commandLine.setLabel("Command Line: ");
    // commandLine.setLabelPosition({110, 850});
    color.addItem("Red");
    color.addItem("Blue");
    color.addItem("Black");

    color.setBoxPosition({630, 0}, "Color");
    color.setProperPosition();

    size.addItem("20");
    size.addItem("25");
    size.addItem("30");
    size.setBoxPosition({830, 0}, "Font Size");
    size.setProperPosition();

    Font.addItem("Arial");
    Font.addItem("TimesNewRoman");
    Font.addItem("Comfortaa");
    Font.setBoxPosition({1030, 0}, "Fonts");
    Font.setProperPosition();

    MenuBar fileMenu;
    fileMenu.addMenu(color);
    fileMenu.addMenu(size);
    fileMenu.addMenu(Font);

    Application::addComponent(wallpaper);
    Application::addComponent(button);
    // app.addComponent(commandLine);

    Application::addComponent(fileMenu);
    Application::addComponent(commandLine);
    Application::addComponent(fileInput);
    // FileTree fileTree;
    // fileTree.push(" ", "Directory 1", true);
    // fileTree.push("Directory 1", "file 1", false);
    // // fileTree.push("222", "333", false); // still some bugs...===
    // fileTree.push("Directory 1", "file 2", false);
    // fileTree.push("Directory 1", "Directory 2", true);
    // fileTree.push("Directory 2", "file 3", false);
    // fileTree.push("Directory 2", "file 4", false);
    // fileTree.push("Directory 2", "file 5", false);
    // fileTree.push("Directory 2", "Directory 3", true);
    // fileTree.push("Directory 3", "file 6", false);
    // fileTree.push("Directory 3", "file 7", false);
    // TO DO: can not have multiple files???

    // FileItem item = {"assets/folder.png", "1111", {130, 50}, {0, 0}};
    // item.setPos({0, 0});
    // FileNode node(item);

    // FileItem item2 = {"assets/folder.png", "2222", {130, 50}, {100, 100}};
    // item2.setPos({100, 100});
    // FileNode node2(item2);
    BuildFileTree::setUp("../../Files/Pathinfo.txt");
    Application::addComponent(BuildFileTree::getFileTree());

    // app.addComponent(FileInput);
    // app.addComponent(node2);
    // FileReader fileReader;
    // std::string s = fileReader.ReadFile("../../Files/file_1.txt");
    // ../../Files/file_1.txt
    // std::cout << s << std::endl;
    Application::run();
}