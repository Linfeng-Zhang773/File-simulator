
#include "Application.h"

std::vector<GUIComponent*> Application::components;
void Application::addComponent(GUIComponent& component)
{
    components.push_back(&component);
}

void Application::run()
{
    sf::RenderWindow window({1220, 920}, "File Simulator");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            for (GUIComponent*& g : components)
                g->addEventHandler(window, event);
        }
        for (GUIComponent*& g : components)
        {
            g->update();
        }
        window.clear(sf::Color::Black);
        for (GUIComponent*& g : components)
        {
            window.draw(*g);
        }
        window.display();
    }
}
