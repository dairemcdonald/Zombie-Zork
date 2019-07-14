#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "monster.h"
#include <QString>
#include <string>
using namespace std;

class zombie: public monster
{
public:
    zombie();

    void head(int);
    void arms(int);
    void legs(int);
    void torso(int);

};

#endif // ZOMBIE_H
