#ifndef GRENADE_H
#define GRENADE_H
#include "loot.h"
#include <QString>
class grenade: public loot
{
public:
    grenade();
    QString getName();
    QString getInformation();
};

#endif // GRENADE_H
