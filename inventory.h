#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include "loot.h"
#include <vector>
#include <QString>
using namespace std;
using std::vector;
class inventory
{
    private:
    public:
        inventory();
        void addLoot(loot itemToAdd);
        QString getContents();
        vector <loot> itemsInInventory;
        void removeItem(QString);
        bool checkIfItemPresent(QString name);

};

#endif // INVENTORY_H
