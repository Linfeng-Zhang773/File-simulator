
#ifndef SFML_PROJECT_STATES_H
#define SFML_PROJECT_STATES_H

#include "statesEnum.h"
#include <map>

class States
{
private:
    std::map<statesEnum, bool> states;

public:
    States();
    bool checkState(statesEnum state) const;
    void enableState(statesEnum state);
    void disableState(statesEnum state);
    void toggleState(statesEnum state);
};

#endif // SFML_PROJECT_STATES_H
