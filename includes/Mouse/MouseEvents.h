#ifndef MOSUEEVENTS_H
#define MOUSEEVENTS_H
#pragma once
#include <SFML/Graphics.hpp>
template <class T>
class MouseEvents
{

public:
    // returns true if the mouse clicks on the object
    static bool mouseClicked(T& object, sf::RenderWindow& window);

    // returns true if the mouse clicks anywhere in the window
    static bool mouseClicked(sf::RenderWindow& window, sf::Event event);

    // returns true if the mouse is hovered over the object
    static bool hovered(T& object, sf::RenderWindow& window);

    // this is what I used to determine if a double click or triple click occurred
    // you don't have to use this if you don't want to
};

template <typename T>
bool MouseEvents<T>::mouseClicked(T& object, sf::RenderWindow& window)
{
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return false;
    }

    sf::Vector2i mouseCoords({sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y});

    sf::Vector2f realCoords = window.mapPixelToCoords(mouseCoords);

    float mouseX = realCoords.x;
    float mouseY = realCoords.y;

    int objX = object.getBox().getPosition().x;
    int objY = object.getBox().getPosition().y;

    int Width = object.getBox().getPosition().x + object.getBox().getGlobalBounds().width;
    int Height = object.getBox().getPosition().y + object.getBox().getGlobalBounds().height;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseX < Width && mouseX > objX && mouseY < Height && mouseY > objY)
    {
        return true;
    }
    return false;
}

template <typename T>
// returns true if the mouse clicks anywhere in the window
bool MouseEvents<T>::mouseClicked(sf::RenderWindow& window, sf::Event event)
{
    if (!(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left))
    {
        return false;
    }
    sf::Vector2i mouseCoords({sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y});

    sf::Vector2f realCoords = window.mapPixelToCoords(mouseCoords);

    float mouseX = realCoords.x;
    float mouseY = realCoords.y;
    if (mouseX < 0 || mouseX > 720)
    {
        return false;
    }
    if (mouseY < 0 || mouseY > 420)
    {
        return false;
    }
    return true;
}

template <typename T>
// returns true if the mouse is hovered over the object
bool MouseEvents<T>::hovered(T& object, sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return false;
    }

    sf::Vector2i mouseCoords({sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y});

    sf::Vector2f realCoords = window.mapPixelToCoords(mouseCoords);

    float mouseX = realCoords.x;
    float mouseY = realCoords.y;

    int objX = object.getBox().getPosition().x;
    int objY = object.getBox().getPosition().y;

    int Width = object.getBox().getPosition().x + object.getBox().getGlobalBounds().width;
    int Height = object.getBox().getPosition().y + object.getBox().getGlobalBounds().height;

    if (mouseX < Width && mouseX > objX && mouseY < Height && mouseY > objY)
    {
        return true;
    }
    return false;
}

#endif