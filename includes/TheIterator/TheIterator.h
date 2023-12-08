#ifndef THEITERATOR_H
#define THEITERATOR_H
#include "../../includes/Letter/Letter.h"
#include <list>
class TheIterator
{

private:
    std::list<Letter>::const_iterator iter;

public:
    TheIterator() {}
    TheIterator(std::list<Letter>::const_iterator it)
    {
        iter = it;
    }

    TheIterator& operator=(const TheIterator& rhs)
    {
        if (this != &rhs)
        {
            iter = rhs.iter;
        }
        return *this;
    }
    bool operator==(const TheIterator& rhs)
    {

        return iter == rhs.iter;
    }

    bool operator!=(const TheIterator& rhs) const
    {

        return iter != rhs.iter;
    }
    const std::list<Letter>::const_iterator& getIt() const { return this->iter; }
    TheIterator& operator++()
    {

        ++iter;
        return *this;
    }

    const Letter& operator*() const
    {

        return *iter;
    }
};

#endif