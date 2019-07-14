#ifndef HUMANOID_H
#define HUMANOID_H
#include "basestats.h"

class humanoid: public basestats
{
private:
    int torsoChance;
    int headChance;
    int armsChance;
    int legsChance;


public:
    virtual void head(int);
    virtual void arms(int);
    virtual void legs(int);
    virtual void torso(int);
};

#endif // HUMANOID_H
