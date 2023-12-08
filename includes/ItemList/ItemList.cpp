#include "ItemList.h"
void ItemList::addItem(const Item& item)
{
    items.push_back(item);

}


int ItemList::size() const
{
    return items.size();
}

const Item& ItemList::at(int i) const
{
    return items[i];
}

Item& ItemList::at(int i)
{
    return items[i];
}
