#ifndef KNIFE_H
#define KNIFE_H
#include "loot.h"
#include <QString>
class knife: public loot
{
public:
    knife();
    QString getName();
};

#endif // KNIFE_H
