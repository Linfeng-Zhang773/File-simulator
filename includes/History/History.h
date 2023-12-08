#ifndef HISTORY_H
#define HISTORY_H
#include "../HistoryNode/HistoryNode.h"
#include "../KeyBoardShortCuts/KeyBoardShortCuts.h"
#include <stack>
class History
{

private:
    static std::stack<HistoryNode> stack;

public:
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();
    inline static std::size_t size()
    {
        return stack.size();
    }
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
};
#endif