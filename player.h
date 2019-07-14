#ifndef PLAYER_H
#define PLAYER_H
#include "humanoid.h"
#include <QString>
#include <string>
using namespace std;

class player: public humanoid
{
public:


    player();

    void hit(int);
    void addHealth(int);
};

#endif // PLAYER_H
