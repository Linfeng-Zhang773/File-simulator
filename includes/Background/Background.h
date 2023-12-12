#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "../GUIcomponent/GUIcomponent.h"
class Background : public GUIComponent
{
private:
    sf::Sprite icon;
    static sf::Texture BackGroundFile;

public:
    Background();
    Background(sf::Vector2f pos);
    void setBackGroundPos(sf::Vector2f pos);
    void setBackGround();
    void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    
};

#endif