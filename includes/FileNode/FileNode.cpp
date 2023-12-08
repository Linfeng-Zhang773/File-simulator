#include "FileNode.h"

FileNode::FileNode()
{ // default
}
FileNode::FileNode(FileItem item)
{
    this->data = item;
}
void FileNode::setData(const FileItem& data)
{
    this->data = data;
}
FileItem& FileNode::getData()
{
    return this->data;
}

void FileNode::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    data.addEventHandler(window, event);
    if (MouseEvents<FileItem>::mouseClicked(data, window))
    {
        isClicked = !isClicked;
    }
}
void FileNode::update()
{
    // do nothing
}
void FileNode::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(data);
}

bool FileNode::getClicked()
{
    return this->isClicked;
}

SnapShot& FileNode::getSnapshot() {}
void FileNode::applySnapshot(const SnapShot& snapshot) {}