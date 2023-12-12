#include "FileItem.h"

sf::Texture FileItem::textureFile = []() -> sf::Texture
{
    sf::Texture texture;
    texture.loadFromFile("assets/file.png");

    return texture;
}();

sf::Texture FileItem::textureFolder = []() -> sf::Texture
{
    sf::Texture texture;
    texture.loadFromFile("assets/folder.png");

    return texture;
}();

FileItem::FileItem() {}

FileItem::FileItem(bool fileOrFolder, std::string text, sf::Vector2f size, sf::Vector2f pos)
{
    if (fileOrFolder)
    {
        this->icon.setTexture(textureFolder);
        this->icon.setScale(0.03f, 0.03f);
    }
    else
    {
        this->icon.setTexture(textureFile);
        this->icon.setScale(0.05f, 0.05f);
    }

    this->icon.setPosition(pos);
    this->text.setString(text);
    this->text.setPosition({pos.x + 50, pos.y});
    this->text.setFont(Fonts::getFont(OPEN_SANS));
    this->text.setCharacterSize(26);
    this->text.setFillColor(sf::Color::Black);
    this->box.setSize(size);
    this->box.setPosition(pos);
}
void FileItem::setPos(sf::Vector2f pos)
{
    this->box.setPosition(pos);
    this->icon.setPosition(pos);
    this->text.setPosition({pos.x + 60, pos.y + 5});
}
void FileItem::setIcon(bool fileOrFolder)
{
    if (fileOrFolder)
    {
        this->icon.setTexture(textureFolder);
    }
    else
        this->icon.setTexture(textureFile);
}
void FileItem::setSize(sf::Vector2f size)
{
    this->box.setSize(size);
}
void FileItem::setText(std::string text)
{
    this->text.setString(text);
}
sf::Vector2f FileItem::getPos()
{
    return this->box.getPosition();
}
sf::Vector2f FileItem::getSize()
{
    return this->box.getSize();
}
std::string FileItem::getText()
{
    return this->text.getString();
}
void FileItem::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    if (MouseEvents<FileItem>::hovered(*this, window))
    {
        this->box.setFillColor(sf::Color::Blue);
    }
    else
    {
        this->box.setFillColor(sf::Color::White);
    }
}
void FileItem::update()
{
    // do nothing
}
void FileItem::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(this->box);
    window.draw(this->icon);
    window.draw(this->text);
}

