#ifndef FILETREE_H
#define FILETREE_H
#include "../FileNode/FileNode.h"
#include "../GUIcomponent/GUIcomponent.h"
#include <SFML/Graphics.hpp>
#include <string>

class FileTree : public GUIComponent
{
private:
    FileNode* root = nullptr;
    int level = 0;
    void push(FileNode*& root, std::string parent, std::string item, bool folderOrFile);
    void traverse(FileNode*& root, sf::RenderWindow& window, sf::Event event);

    inline void deleteTree(FileNode*& root)
    {
        if (root == nullptr) return;
        for (auto child : root->children) deleteTree(child);
        root->children.clear();
        delete root;
        root = nullptr;
    }

public:
    FileTree() = default;
    ~FileTree()
    {
        if (this->root == nullptr) return;
        deleteTree(this->root);
    }
    inline void reset()
    {
        this->level = 0;
        if (this->root == nullptr) return;
        deleteTree(this->root);
    }
    FileNode* findParent(FileNode* root, const std::string& parent, const std::string& data);
    void push(std::string parent, std::string item, bool folderOrFile);
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void drawTree(FileNode* theRoot, sf::RenderTarget& window, sf::RenderStates states) const;
    SnapShot& getSnapshot() override;
    void applySnapshot(const SnapShot& snapshot) override;
};

#endif