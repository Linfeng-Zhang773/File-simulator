#ifndef MULTITEXT_H
#define MULTITEXT_H
#include "../../includes/Letter/Letter.h"
#include "../../includes/TheIterator/TheIterator.h"
#include <list>
class MultiText : public sf::Drawable
{
private:
    std::list<Letter> text;

public:
    MultiText() = default;
    MultiText(const std::string& text);
    void push(char c);
    void push(std::string s);
    void push(const Letter& letter);
    int pop();
    inline void clear()
    {
        text.clear();
    }
    inline bool barExist()
    {
        if (this->text.empty()) return false;
        TheIterator iter;
        for (iter = TheIterator(text.begin()); iter != TheIterator(text.end()); ++iter)
        {
            Letter letter = *iter;
            if (letter.getString() == "|") return true;
        }
        return false;
    }
    inline void removeBar()
    {
        if (this->text.empty()) return;
        TheIterator iter;
        for (iter = TheIterator(text.begin()); iter != TheIterator(text.end()); ++iter)
        {
            Letter letter = *iter;
            if (letter.getString() == "|")
            {
                this->text.erase(iter.getIt());
                return;
            }
        }
    }
    inline const std::size_t size() const { return this->text.size(); }
    inline bool empty() const { return this->text.empty(); }
    TheIterator begin();
    TheIterator end();
    std::string getString();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
};
#endif