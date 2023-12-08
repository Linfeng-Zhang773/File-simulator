#ifndef HISTORYNODE_H
#define HISTORYNODE_H

#include "../GUIcomponent/GUIcomponent.h"
#include "../SnapShot/SnapShot.h"
struct HistoryNode
{
    SnapShot snapshot;
    GUIComponent* component;
    HistoryNode(SnapShot s = SnapShot(), GUIComponent* g = nullptr) : snapshot(s), component(g){}
};

#endif