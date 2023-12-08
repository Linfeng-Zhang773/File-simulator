#include "includes/Application/Application.h"
#include "includes/Background/Background.h"
#include "includes/CommandHintButton/CommandHintButton.h"
#include "includes/FileTree/FileTree.h"
#include "includes/InputBox/InputBox.h"
#include "includes/Menu/Menu.h"
#include "includes/MenuBar/MenuBar.h"
#include "includes/TextInput/TextInput.h"
#include <SFML/Graphics.hpp>
int main()
{
    Application app;
    Background wallpaper({0, 0});
    TextInput commandLine({800, 100}, {430, 850}, 670);
    TextInput FileInput({700, 500}, {500, 200}, 630);
    Menu color;
    Menu size;
    Menu Font;
    Menu position;
    CommandHintButton button({160, 30}, {50, 400});

    commandLine.setLabel("Command Line: ");
    commandLine.setLabelPosition({110, 850});
    color.addItem("Red");
    color.addItem("Blue");
    color.addItem("Yellow");
    color.addItem("Black");
    color.addItem("White");
    color.addItem("Green");

    color.setBoxPosition({400, 160}, "Color");
    color.setProperPosition();

    size.addItem("10");
    size.addItem("12");
    size.addItem("14");
    size.addItem("16");
    size.addItem("18");
    size.addItem("20");
    size.setBoxPosition({600, 160}, "Font Size");
    size.setProperPosition();

    Font.addItem("arial");
    Font.addItem("Times New Roman");
    Font.addItem("comfortaa");
    Font.addItem("Lexend");
    Font.addItem("Verdana");
    Font.setBoxPosition({800, 160}, "Fonts");
    Font.setProperPosition();

    position.addItem("left");
    position.addItem("Middle");
    position.addItem("Right");
    position.setBoxPosition({1000, 160}, "Position");
    position.setProperPosition();

    MenuBar fileMenu;
    fileMenu.addMenu(color);
    fileMenu.addMenu(size);
    fileMenu.addMenu(Font);
    fileMenu.addMenu(position);

    app.addComponent(wallpaper);
    app.addComponent(button);
    app.addComponent(commandLine);
    app.addComponent(FileInput);
    app.addComponent(fileMenu);
    FileTree fileTree;
    fileTree.push(" ", "Directory 1", true);
    fileTree.push("Directory 1", "file 1", false);
    // fileTree.push("222", "333", false); // still some bugs...===
    fileTree.push("Directory 1", "file 2", false);
    fileTree.push("Directory 1", "Directory 2", true);
    fileTree.push("Directory 2", "file 3", false);
    fileTree.push("Directory 2", "file 4", false);
    fileTree.push("Directory 2", "file 5", false);
    fileTree.push("Directory 2", "Directory 3", true);
    fileTree.push("Directory 3", "file 6", false);
    fileTree.push("Directory 3", "file 7", false);
    // TO DO: can not have multiple files???

    // FileItem item = {"assets/folder.png", "1111", {130, 50}, {0, 0}};
    // item.setPos({0, 0});
    // FileNode node(item);

    // FileItem item2 = {"assets/folder.png", "2222", {130, 50}, {100, 100}};
    // item2.setPos({100, 100});
    // FileNode node2(item2);

    app.addComponent(fileTree);
    // app.addComponent(node2);

    app.run();
}