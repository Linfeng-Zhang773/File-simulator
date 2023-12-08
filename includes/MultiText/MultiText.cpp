#include "../../includes/MultiText/MultiText.h"

MultiText::MultiText(const std::string& text)
{
    for (int i = 0; i < text.size(); ++i)
    {
        char c = text[i];
        push(c);
    }
}

int MultiText::pop()
{
    Letter l = text.back();
    int size = l.size();
    text.pop_back();
    return size;
}

void MultiText::push(char c)
{
    text.push_back(Letter(c));
}
void MultiText::push(std::string s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        text.push_back(c);
    }
}
TheIterator MultiText::begin()
{
    return TheIterator(text.begin());
}

TheIterator MultiText::end()
{
    return TheIterator(text.end());
}

void MultiText::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    TheIterator iter;
    for (iter = TheIterator(text.begin()); iter != TheIterator(text.end()); ++iter)
    {
        Letter letter = *iter;
        window.draw(letter, states);
    }
}

void MultiText::push(const Letter& letter)
{
    text.push_back(letter);
}

std::string MultiText::getString()
{

    std::string s = "";
    TheIterator iter;
    for (iter = TheIterator(text.begin()); iter != TheIterator(text.end()); ++iter)
    {
        Letter letter = *iter;
        s += letter.getString();
    }
    return s;
}