#ifndef LOOT_H
#define LOOT_H
#include <QString>
#include <string>
using namespace std;
class loot
{
public:
    string itemname;
    string description;
    loot();
    QString getName();
    QString getDescription();

};

#endif // LOOT_H
