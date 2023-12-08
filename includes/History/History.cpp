#include "History.h"

std::stack<HistoryNode> History::stack;
void History::pushHistory(const HistoryNode& snapshot)
{
    stack.push(snapshot);
}
HistoryNode& History::topHistory()
{
    return stack.top();
}
void History::popHistory()
{
    stack.pop();
}
void History::addEventHandler(sf::RenderWindow& window, sf::Event event)
{

    if (KeyBoardShortCuts::isUndo())
    {

        if (!stack.empty())
        {

            HistoryNode snapshot = stack.top();

            snapshot.component->applySnapshot(snapshot.snapshot);

            stack.pop();
        }
    }
}
