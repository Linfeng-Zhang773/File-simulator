#ifndef ITEMLIST_H
#define ITENLIST_H
#include "../InputBox/InputBox.h"
#include "../Item/Item.h"
#include <SFML/Graphics.hpp>
#include <vector>

class ItemList : public States
{
public:

    std::vector<Item> items;
    void addItem(const Item& item);
    int size() const;
    const Item& at(int i) const;
    Item& at(int i);
};

#endif