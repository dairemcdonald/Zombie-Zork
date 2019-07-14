#include "inventory.h"
#include <string>
inventory::inventory()
{

}


void inventory::addLoot(loot itemToAdd)
{
     itemsInInventory.push_back(itemToAdd);
}

QString inventory::getContents()
{
    loot testing;
    QString results = "";
    for(int i = 0; i < itemsInInventory.size(); i++)
    {
        results += itemsInInventory[i].getName();
        results += "\n";
    }

    return results;
}

void inventory::removeItem(QString itemName)
{
    bool found;
    while(!found)
    {
        for(int i = 0; i < itemsInInventory.size(); i++)
        {
            if(itemsInInventory[i].getName() == itemName)
            {
                itemsInInventory.erase(itemsInInventory.begin()+ i);
                //cout << "\nItem removed";
                found = true;
            }
        }
    }
}
bool inventory::checkIfItemPresent(QString name)
{
    for(int i = 0; i < itemsInInventory.size(); i++)
    {
        if(itemsInInventory[i].getName() == name)
        {
            //cout << "\nItem removed";
            return true;
        }
    }
    return false;
}
