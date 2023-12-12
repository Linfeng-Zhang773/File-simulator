#ifndef FILENODE_H
#define FILENODE_H
#include "../FileItem/FileItem.h"
#include "../GUIcomponent/GUIcomponent.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <set>
#include <string>

class FileNode : public GUIComponent
{
private:
    // std::set<TreeNode*> children;
    FileItem data;
    bool isClicked = false;

public:
    FileNode();
    std::set<FileNode*> children;
    FileNode(FileItem item);
    void setData(const FileItem& data);
    FileItem& getData();
    bool getClicked();
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;

};

#endif