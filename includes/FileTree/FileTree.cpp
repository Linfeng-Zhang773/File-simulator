#include "FileTree.h"

void FileTree::traverse(FileNode*& root, sf::RenderWindow& window, sf::Event event)
{
    if (root == nullptr)
    {
        return;
    }

    root->addEventHandler(window, event);

    for (FileNode* child : root->children)
    {
        traverse(child, window, event);
    }
}

void FileTree::push(FileNode*& root, std::string parent, std::string item, bool folderOrFile)
{
    // Folder for true, file for false
    if (root == nullptr)
    {
        FileItem theItem("assets/folder.png", item, {230, 40}, {0, 0});
        root = new FileNode(theItem);
        return;
    }
    else
    {
        FileNode* node = findParent(root, parent, item);

        if (node == nullptr)
        {
            // std::cout << " did a return" << std::endl;
            return;
        }

        sf::Vector2f position = node->getData().getPos();
        // std::cout << "Pos x now is: " << position.x << "Pos Y now is: " << position.y << std::endl;
        int count = node->children.size();
        // std::cout << "the size of children" << count << std::endl;
        node->children.insert(new FileNode(FileItem(folderOrFile, item, {230, 40}, {position.x + 40 * (level + 1), position.y + 45 * (count + 1)})));
        if (folderOrFile)
        {
            this->level++;
        }
        // find parent and get the parent node

        // create a new node with FileItem(file or folder)
        // push the new created node into found parent node
    }
}

FileNode* FileTree::findParent(FileNode* root, const std::string& parent, const std::string& data)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    // std::cout << "now the parent is: " << root->getData().getText() << std::endl;
    // std::cout << " data: " << data;
    if (root->getData().getText() == parent)
    {
        return root;
    }

    for (FileNode* child : root->children)
    {
        FileNode* result = findParent(child, parent, data);
        if (result != nullptr)
        {
            return result;
        }
    }

    return nullptr;
}

void FileTree::push(std::string parent, std::string item, bool folderOrFile)
{

    this->push(this->root, parent, item, folderOrFile);
}
void FileTree::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    traverse(root, window, event);
}
void FileTree::update()
{
    for (FileNode* current : root->children)
    {
        current->update();
    }
}
void FileTree::draw(sf::RenderTarget& window, sf::RenderStates states) const
{

    if (root != nullptr)
    {
        window.draw(*root);
    }

    drawTree(root, window, states);
}

void FileTree::drawTree(FileNode* theRoot, sf::RenderTarget& window, sf::RenderStates states) const
{
    if (theRoot == nullptr)
    {
        return;
    }
    else
    {
        if (!theRoot->getClicked())
        {
            return;
        }
        for (FileNode* current : theRoot->children)
        {

            window.draw(*current);

            drawTree(current, window, states);
        }
    }
}

SnapShot& FileTree::getSnapshot() {}
void FileTree::applySnapshot(const SnapShot& snapshot) {}