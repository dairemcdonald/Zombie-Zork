#ifndef MONSTER_H
#define MONSTER_H
#include "humanoid.h"
#include <QString>
#include <string>
using namespace std;

class monster: public humanoid
{
public:
    monster();
    ~monster();
};

#endif // MONSTER_H
