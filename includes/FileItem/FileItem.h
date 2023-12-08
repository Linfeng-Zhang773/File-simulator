#ifndef FILEITEM_H
#define FILEITEM_H
#include "../FontEnum/FontEnum.h"
#include "../Fonts/Fonts.h"
#include "../GUIcomponent/GUIcomponent.h"
#include "../Item/Item.h"
#include "../Mouse/MouseEvents.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class FileItem : public Item, public GUIComponent
{
private:
    sf::Sprite icon;
    static sf::Texture textureFile;
    static sf::Texture textureFolder;

public:
    FileItem();
    FileItem(bool fileOrFolder, std::string text, sf::Vector2f size, sf::Vector2f pos);
    void setPos(sf::Vector2f pos);
    void setIcon(bool fileOrFolder);
    void setSize(sf::Vector2f size);
    void setText(std::string text);
    sf::Vector2f getPos();
    sf::Vector2f getSize();
    std::string getText();
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    SnapShot& getSnapshot() override;
    void applySnapshot(const SnapShot& snapshot) override;
};

#endif