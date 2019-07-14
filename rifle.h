#ifndef RIFLE_H
#define RIFLE_H
#include "basestats.h"
#include "loot.h"

class rifle: public loot, public basestats
{
public:
    rifle();
};

#endif // RIFLE_H
