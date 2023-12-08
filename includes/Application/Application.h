

#ifndef SFML_PROJECT_APPLICATION_H
#define SFML_PROJECT_APPLICATION_H

#include "../GUIcomponent/GUIComponent.h"

class Application
{
private:
    static std::vector<GUIComponent*> components;

public:
    static void addComponent(GUIComponent& component);
    static void run();
};

#endif // SFML_PROJECT_APPLICATION_H
